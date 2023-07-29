@echo off
if "%1"=="" goto loop
copy dry%1.in dry.in >nul
echo Problem Test
echo Data %1
time<enter
dry.exe
time<enter
fc dry.out dry%1.out
del dry.in
del dry.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
