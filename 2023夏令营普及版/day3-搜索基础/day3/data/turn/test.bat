@echo off
if "%1"=="" goto loop
copy turn%1.in turn.in >nul
echo Problem Test
echo Data %1
time<enter
turn.exe
time<enter
fc turn.out turn%1.out
del turn.in
del turn.out
pause
goto end
:loop
for %%i in (0 1 2 3 4 5 6 7 8 9) do call %0 %%i
:end
