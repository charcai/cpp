@echo off
if "%1"=="" goto loop
copy speech%1.in speech.in >nul
echo Problem Test
echo Data %1
time<enter
speech.exe
time<enter
fc speech.out speech%1.out
del speech.in
del speech.out
pause
goto end
:loop
for %%i in (1 2 3 4 5) do call %0 %%i
:end
