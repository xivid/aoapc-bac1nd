@echo off
:loop
echo making...
mk > input
echo test a...
a < input >output.a
echo test b...
b < input >output.b
fc output.a output.b > nul
if not errorlevel 1 goto loop
echo error!
pause