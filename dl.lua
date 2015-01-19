local dl = {}

local ffi = require "ffi"

function dl.DelayLine(input, delay, max_delay)
    max_delay = math.floor((max_delay or delay.out) + 0.5) + 1
    local buffer = ffi.new("double[?]", max_delay)
    local v = {out=0, buffer=buffer, index=0, size=max_delay, delay=delay}
    local function tick()
        v.buffer[v.index] = input.out
        v.out = v.buffer[(v.index - math.floor(v.delay.out + 0.5)) % v.size]
        v.index = (v.index + 1) % v.size
    end
    return setmetatable(v, {__call=tick})
end

function dl.DelayLineInterpolated(input, delay, max_delay)
    max_delay = math.floor((max_delay or delay.out) + 0.5) + 2
    local buffer = ffi.new("double[?]", max_delay)
    local v = {out=0, buffer=buffer, index=0, size=max_delay, delay=delay}
    local function tick()
        v.buffer[v.index] = input.out
        local index_a = (v.index - math.ceil(v.delay.out)) % v.size
        local index_b = (index_a - 1) % v.size
        local balance = v.delay.out - math.floor(v.delay.out)
        v.out = v.buffer[index_a] * (1-balance) + v.buffer[index_b] * balance
        v.index = (v.index + 1) % v.size
    end
    return setmetatable(v, {__call=tick})
end

return dl
