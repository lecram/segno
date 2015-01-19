local ffi = require "ffi"
ffi.cdef[[
typedef struct SNDFILE_tag SNDFILE;
typedef int64_t sf_count_t;
struct SF_INFO {
    sf_count_t frames;
    int samplerate, channels, format, sections, seekable;
};
typedef struct SF_INFO SF_INFO;
enum {
    SF_FORMAT_WAV       = 0x010000,
    SF_FORMAT_FLAC      = 0x170000,
    SF_FORMAT_OGG       = 0x200000,
    SF_FORMAT_PCM_16    = 0x0002,
};
enum {
    SFM_READ    = 0x10,
    SFM_WRITE   = 0x20,
};
SNDFILE *sf_open(const char *path, int mode, SF_INFO *sfinfo);
sf_count_t sf_read_double(SNDFILE *sndfile, double *ptr, sf_count_t items);
sf_count_t sf_write_double(SNDFILE *sndfile, const double *ptr, sf_count_t items);
int sf_close(SNDFILE *sndfile);
]]

local sf = ffi.load("sndfile")

local buffer_size = 1024

local Reader1 = {}
Reader1.__index = Reader1

local function ReaderMono(path)
    local buffer = ffi.new("double[?]", buffer_size)
    local sfinfo = ffi.new("SF_INFO")
    local file = sf.sf_open(path, sf.SFM_READ, sfinfo)
    local n = sf.sf_read_double(file, buffer, buffer_size)
    local out, eof
    if n > 0 then
        out = buffer[0]
        eof = false
    else
        out = 0
        eof = true
    end
    local t = {file=file, buffer=buffer, index=1, out=out, eof=eof, n=n}
    t.sample_rate = sfinfo.samplerate
    return setmetatable(t, Reader1)
end

function Reader1:read()
    if self.eof then return end
    if self.index == self.n then
        if self.n == buffer_size then
            self.n = sf.sf_read_double(self.file, self.buffer, buffer_size)
            if self.n > 0 then
                self.out = self.buffer[0]
            else
                self:close()
            end
            self.index = 1
        else
            self:close()
        end
    else
        self.out = self.buffer[self.index]
        self.index = self.index + 1
    end
end
Reader1.__call = Reader1.read

function Reader1:close()
    self.out = 0
    self.eof = true
    sf.sf_close(self.file)
end

local Reader2 = {}
Reader2.__index = Reader2

local function ReaderStereo(path)
    local buffer = ffi.new("double[?]", buffer_size)
    local sfinfo = ffi.new("SF_INFO")
    local file = sf.sf_open(path, sf.SFM_READ, sfinfo)
    local n = sf.sf_read_double(file, buffer, buffer_size)
    local left, right, eof
    if n > 0 then
        left, right = buffer[0], buffer[1]
        eof = false
    else
        left, right = 0, 0
        eof = true
    end
    local t = {file=file, buffer=buffer, index=2, left=left, right=right, eof=eof, n=n}
    t.sample_rate = sfinfo.samplerate
    return setmetatable(t, Reader2)
end

function Reader2:read()
    if self.eof then return end
    if self.index == self.n then
        if self.n == buffer_size then
            self.n = sf.sf_read_double(self.file, self.buffer, buffer_size)
            if self.n > 0 then
                self.left, self.right = self.buffer[0], self.buffer[1]
            else
                self:close()
            end
            self.index = 2
        else
            self:close()
        end
    else
        self.left, self.right = self.buffer[self.index], self.buffer[self.index+1]
        self.index = self.index + 2
    end
end
Reader2.__call = Reader2.read

function Reader2:close()
    self.left, self.right = 0, 0
    self.eof = true
    sf.sf_close(self.file)
end

local Writer1 = {}
Writer1.__index = Writer1

local function WriterMono(path, sample_rate, input)
    local buffer = ffi.new("double[?]", buffer_size)
    local sfinfo = ffi.new("SF_INFO", {
        samplerate=sample_rate,
        channels=1,
        format=bit.bor(sf.SF_FORMAT_FLAC, sf.SF_FORMAT_PCM_16),
    })
    local file = sf.sf_open(path, sf.SFM_WRITE, sfinfo)
    local t = {file=file, buffer=buffer, index=0, input=input}
    return setmetatable(t, Writer1)
end

function Writer1:write()
    self.buffer[self.index] = self.input.out
    self.index = self.index + 1
    if self.index == buffer_size then
        sf.sf_write_double(self.file, self.buffer, buffer_size)
        self.index = 0
    end
end
Writer1.__call = Writer1.write

function Writer1:close()
    sf.sf_write_double(self.file, self.buffer, self.index)
    sf.sf_close(self.file)
end

local Writer2 = {}
Writer2.__index = Writer2

local function WriterStereo(path, sample_rate, left, right)
    local buffer = ffi.new("double[?]", buffer_size)
    local sfinfo = ffi.new("SF_INFO", {
        samplerate=sample_rate,
        channels=2,
        format=bit.bor(sf.SF_FORMAT_FLAC, sf.SF_FORMAT_PCM_16),
    })
    local file = sf.sf_open(path, sf.SFM_WRITE, sfinfo)
    local t = {file=file, buffer=buffer, index=0, left=left, right=right}
    return setmetatable(t, Writer2)
end

function Writer2:write()
    self.buffer[self.index]   = self.left.out
    self.buffer[self.index+1] = self.right.out
    self.index = self.index + 2
    if self.index == buffer_size then
        sf.sf_write_double(self.file, self.buffer, buffer_size)
        self.index = 0
    end
end
Writer2.__call = Writer2.write

function Writer2:close()
    sf.sf_write_double(self.file, self.buffer, self.index)
    sf.sf_close(self.file)
end

local function open(path, mode, channels, sample_rate)
    mode = mode or "r"
    channels = channels or 2
    sample_rate = sample_rate or 48000
    if mode == "r" then
        if channels == 1 then
            return open_r1(path)
        elseif channels == 2 then
            return open_r2(path)
        else
            error(("invalid number of channels: %d"):format(channels))
        end
    elseif mode == "w" then
        if channels == 1 then
            return open_w1(path, sample_rate)
        elseif channels == 2 then
            return open_w2(path, sample_rate)
        else
            error(("invalid number of channels: %d"):format(channels))
        end
    else
        error(("invalid file mode: %s"):format(mode))
    end
end

return {
    ReaderMono=ReaderMono, ReaderStereo=ReaderStereo,
    WriterMono=WriterMono, WriterStereo=WriterStereo
}
