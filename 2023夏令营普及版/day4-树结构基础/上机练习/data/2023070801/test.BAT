@echo off
if "%1"=="" goto loop
copy depth%1.in depth.in >nul
echo Problem Test
echo Data %1
time<enter
depth.exe
time<enter
fc depth.out depth%1.out
del depth.in
del depth.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7) do call %0 %%i
:end
