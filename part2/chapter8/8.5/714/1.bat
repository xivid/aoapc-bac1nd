@echo off
:loop
mk > input
714 <input > output.a
my <input >output.b
fc output.a output.b
if not errorlevel 1 goto loop
pause