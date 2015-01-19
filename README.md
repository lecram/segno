segno
=====

Generic low-level audio synthesis and processing
------------------------------------------------

 segno is  a tool  inspired by  audio DSLs like  ChucK and  Faust, but
implemented as  a Lua library. The  goal is to provide  a flexible and
lightweight system for sound manipulation.

 The  main  difference  between  segno  and ChucK  is  that  in  segno
_all  parameters can  be modulated_.  This means  that all  sound unit
parameters works  as generic signal  inputs. For example, a  sine wave
unit have  parameters `frequency`, `amplitude`, `offset`  and `phase`.
In segno, you can  connect any of these inputs to  any output from any
other unit, which  enables the creation of more advanced  units from a
small set of elementary ones. This is also true in Faust.

 The main difference between segno and Faust is that segno is meant to
be used from within  a [general purpose language](http://www.lua.org).
This  makes  it   easier  to  extend  segno  and   integrate  it  with
other  systems. Lua  is a  simple,  embeddable language  with a  [fast
implementation](http://luajit.org).


This is a work in progress and there is no public documentation yet.

License
-------

segno is available under the MIT license. See the LICENSE file for more info.
