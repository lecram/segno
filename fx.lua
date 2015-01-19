local fx = {}

local core  = require "core"
local osc   = require "osc"
local op    = require "op"
local dl    = require "dl"

-- Tremolo(input, frequency, {depth})
function fx.Tremolo(args)
    setmetatable(args, {__index=function() return {out=0.5} end})
    local input = args[1]
    local frq = args[2]
    local dpt = args.depth
    local lfo = osc.Sine(frq, dpt)
    local mul = op.Mul(input, lfo)
    local v = {out=0, frq=frq, dpt=dpt}
    local function tick()
        lfo.ofs.out = 1 - v.dpt.out
        lfo.amp.out = v.dpt.out
        lfo()
        mul()
        v.out = mul.out
    end
    return setmetatable(v, {__call=tick})
end

-- Flanger(input, frequency, {depth, tone, feedback, dry, wet})
function fx.Flanger(args)
    setmetatable(args, {__index=function() return {out=0.5} end})
    local input = args[1]
    local frq = args[2]
    local dpt = args.depth
    local ton = args.tone
    local fdb = args.feedback
    local dry = args.dry
    local wet = args.wet
    local lfo = osc.Sine(frq)
    local mul_dry = op.Mul(input, dry)
    local add_fb = op.Add(input)
    local dli = dl.DelayLineInterpolated(add_fb, lfo, 0.1*core.sec)
    local mul_wet = op.Mul(dli, wet)
    local mix = op.Add(mul_dry, mul_wet)
    local mul_fb = op.Mul(dli, fdb)
    add_fb.b = mul_fb
    local v = {out=0, frq=frq, dpt=dpt, ton=ton, fdb=fdb, dry=dry, wet=wet}
    local function tick()
        lfo.ofs.out = v.ton.out * -0.005 + 0.01
        lfo.amp.out = v.dpt.out * 0.005 * core.sec
        lfo()
        add_fb()
        dli()
        mul_fb()
        mul_dry()
        mul_wet()
        mix()
        v.out = mix.out
    end
    return setmetatable(v, {__call=tick})
end

return fx
