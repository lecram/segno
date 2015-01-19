local osc = {}

function osc.Sine(frequency, amplitude, offset, phase)
    local amp = amplitude or {out=1}
    local ofs = offset or {out=0}
    local phs = phase or {out=0}
    local v = {out=0, ramp=0, frq=frequency, amp=amp, ofs=ofs, phs=phs}
    local function tick()
        v.ramp = v.ramp + v.frq.out
        v.ramp = v.ramp > 1 and v.ramp-1 or v.ramp
        v.out = math.sin(2*math.pi*(v.ramp+phs.out)) * amp.out + ofs.out
    end
    return setmetatable(v, {__call=tick})
end

function osc.Saw(frequency, amplitude, offset, phase)
    local amp = amplitude or {out=1}
    local ofs = offset or {out=0}
    local phs = phase or {out=0}
    local v = {out=0, ramp=0, frq=frequency, amp=amp, ofs=ofs, phs=phs}
    local function tick()
        v.ramp = v.ramp + v.frq.out
        v.ramp = v.ramp > 1 and v.ramp-1 or v.ramp
        local phased_ramp = v.ramp + phs.out
        phased_ramp = phased_ramp > 1 and phased_ramp-1 or phased_ramp
        if phased_ramp < 0.5 then
            v.out = 2 * phased_ramp
        else
            v.out = 2 * phased_ramp - 2
        end
        v.out = v.out * amp.out + ofs.out
    end
    return setmetatable(v, {__call=tick})
end

function osc.Triangle(frequency, amplitude, offset, phase)
    local amp = amplitude or {out=1}
    local ofs = offset or {out=0}
    local phs = phase or {out=0}
    local v = {out=0, ramp=0, frq=frequency, amp=amp, ofs=ofs, phs=phs}
    local function tick()
        v.ramp = v.ramp + v.frq.out
        v.ramp = v.ramp > 1 and v.ramp-1 or v.ramp
        local phased_ramp = v.ramp + phs.out
        phased_ramp = phased_ramp > 1 and phased_ramp-1 or phased_ramp
        if phased_ramp < 0.25 then
            v.out = 4 * phased_ramp
        elseif phased_ramp >= 0.75 then
            v.out = 4 * phased_ramp - 4
        else
            v.out = 4 * (0.5 - phased_ramp)
        end
        v.out = v.out * amp.out + ofs.out
    end
    return setmetatable(v, {__call=tick})
end

function osc.Square(frequency, amplitude, offset, phase)
    local amp = amplitude or {out=1}
    local ofs = offset or {out=0}
    local phs = phase or {out=0}
    local v = {out=0, ramp=0, frq=frequency, amp=amp, ofs=ofs, phs=phs}
    local function tick()
        v.ramp = v.ramp + v.frq.out
        v.ramp = v.ramp > 1 and v.ramp-1 or v.ramp
        local phased_ramp = v.ramp + phs.out
        phased_ramp = phased_ramp > 1 and phased_ramp-1 or phased_ramp
        v.out = phased_ramp < 0.5 and 1 or -1
        v.out = v.out * amp.out + ofs.out
    end
    return setmetatable(v, {__call=tick})
end

function osc.Impulse(frequency, amplitude, offset, phase)
    local amp = amplitude or {out=1}
    local ofs = offset or {out=0}
    local phs = phase or {out=0}
    local v = {out=0, ramp=0, last=0, frq=frequency, amp=amp, ofs=ofs, phs=phs}
    local function tick()
        v.ramp = v.ramp + v.frq.out
        v.ramp = v.ramp > 1 and v.ramp-1 or v.ramp
        local phased_ramp = v.ramp + phs.out
        phased_ramp = phased_ramp > 1 and phased_ramp-1 or phased_ramp
        v.out = phased_ramp < v.last and 1 or 0
        v.out = v.out * amp.out + ofs.out
        v.last = v.ramp
    end
    return setmetatable(v, {__call=tick})
end

return osc
