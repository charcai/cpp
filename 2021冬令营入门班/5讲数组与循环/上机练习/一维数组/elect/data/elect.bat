@echo off
if "%1"=="" goto loop
copy elect%1.in elect.in >nul
echo Problem Test
echo Data %1
time<enter
elect
time<enter
fc elect.out elect%1.out
del elect.in
del elect.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
