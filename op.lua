local op = {}

function op.Add(a, b)
    local v = {out=0, a=a, b=b}
    local function tick()
        v.out = v.a.out + v.b.out
    end
    return setmetatable(v, {__call=tick})
end

function op.Mul(a, b)
    local v = {out=0, a=a, b=b}
    local function tick()
        v.out = v.a.out * v.b.out
    end
    return setmetatable(v, {__call=tick})
end

return op
