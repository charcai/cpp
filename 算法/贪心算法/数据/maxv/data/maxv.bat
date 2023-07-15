@echo off
if "%1"=="" goto loop
copy maxv%1.in maxv.in >nul
echo Problem Test
echo Data %1
time<enter
maxv
time<enter
fc maxv.out maxv%1.out
del maxv.in
del maxv.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
