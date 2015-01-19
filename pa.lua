local pa = {}

function pa.Ramp(step)
    local v = {out=0, step=step}
    local function tick()
        v.out = v.out + v.step.out
        v.out = v.out >= 1 and v.out-1 or v.out
    end
    return setmetatable(v, {__call=tick})
end

return pa
