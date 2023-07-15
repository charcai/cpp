@echo off
if "%1"=="" goto loop
copy money%1.in money.in >nul
echo Problem Test
echo Data %1
money
fc money.out money%1.ans
del money.in
del money.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20) do call %0 %%i
:end
