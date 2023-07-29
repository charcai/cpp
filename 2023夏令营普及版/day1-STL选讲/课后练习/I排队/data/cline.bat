@echo off
if "%1"=="" goto loop
copy cline%1.in cline.in >nul
echo Problem Test
echo Data %1
time<enter
cline
time<enter
fc cline.out cline%1.out
del cline.in
del cline.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
