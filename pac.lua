local pac = {}

function pac.Sine(pa)
    local v = {out=0, pa=pa}
    local function tick()
        v.out = math.sin(2*math.pi*v.pa.out)
    end
    return setmetatable(v, {__call=tick})
end

function pac.Saw(pa)
    local v = {out=0, pa=pa}
    local function tick()
        v.out = v.pa.out < 0.5 and 2*v.pa.out or 2*v.pa.out-2
    end
    return setmetatable(v, {__call=tick})
end

function pac.Triangle(pa)
    local v = {out=0, pa=pa}
    local function tick()
        v.out = v.pa.out < 0.25 and 4*v.pa.out or
               (v.pa.out >= 0.75 and 4*v.pa.out-4 or 4*(0.5-v.pa.out))
    end
    return setmetatable(v, {__call=tick})
end

function pac.Square(pa)
    local v = {out=0, pa=pa}
    local function tick()
        v.out = v.pa.out < 0.5 and 1 or -1
    end
    return setmetatable(v, {__call=tick})
end

function pac.Impulse(pa)
    local v = {out=1, last=0, pa=pa}
    local function tick()
        v.out = v.pa.out < v.last and 1 or 0
        v.last = v.pa.out
    end
    return setmetatable(v, {__call=tick})
end

return pac
