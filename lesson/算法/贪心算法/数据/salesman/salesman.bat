@echo off
if "%1"=="" goto loop
copy salesman%1.in salesman.in >nul
echo Problem Test
echo Data %1
time<enter
salesman
time<enter
fc salesman.out salesman%1.out
del salesman.in
del salesman.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
