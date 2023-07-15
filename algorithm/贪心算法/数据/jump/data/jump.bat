@echo off
if "%1"=="" goto loop
copy jump%1.in jump.in >nul
echo Problem Test
echo Data %1
time<enter
jump
time<enter
fc jump.out jump%1.out
del jump.in
del jump.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
