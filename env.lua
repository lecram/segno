local env = {}

function env.ADSR(input, atack, decay, sustain, release)
    local v = {out=0, input=input, a=atack, d=decay, s=sustain, r=release}
    local function tick()
        local sustime = v.dur.out - v.a.out - v.d.out - v.r.out
        local level
        if v.cur < v.a.out then
            level = v.cur / v.a.out
        elseif v.cur < v.a.out + v.d.out then
            level = 1 - (v.cur - v.a.out) / v.d.out * (1 - v.s.out)
        elseif v.cur < v.a.out + v.d.out + sustime then
            level = v.s.out
        else
            level = (v.dur.out - v.cur) / v.r.out * v.s.out
        end
        v.out = input.out * level
        v.cur = v.cur < v.dur.out and v.cur + 1 or 0
    end
    function v:note(duration)
        self.dur = duration
        self.cur = 0
    end
    return setmetatable(v, {__call=tick})
end

return env
