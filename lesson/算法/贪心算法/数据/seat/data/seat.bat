@echo off
if "%1"=="" goto loop
copy seat%1.in seat.in >nul
echo Problem Test
echo Data %1
time<enter
seat
time<enter
fc seat.out seat%1.out
del seat.in
del seat.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
