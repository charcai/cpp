@echo off
if "%1"=="" goto loop
copy delque%1.in delque.in >nul
echo Problem Test
echo Data %1
time<enter
delque
time<enter
fc delque.out delque%1.out
del delque.in
del delque.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
