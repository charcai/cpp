@echo off
if "%1"=="" goto loop
copy boarding%1.in boarding.in >nul
echo Problem Test
echo Data %1
boarding
fc boarding.out boarding%1.out
del boarding.in
del boarding.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8) do call %0 %%i
:end
