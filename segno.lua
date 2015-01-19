local segno = {}
segno.core = require "core"
segno.pa   = require "pa"
segno.pac  = require "pac"
segno.osc  = require "osc"
segno.op   = require "op"
segno.dl   = require "dl"
segno.fx   = require "fx"
segno.file = require "file"
return segno

-- TODO
--  * add envelopes (ADSR, etc);
--  * add events;
--  * add JACK real-time audio API;
--  * add more effects;
--  * implement tick sequence automation (is it possible?);
