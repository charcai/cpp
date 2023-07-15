@echo off
if "%1"=="" goto loop
copy title%1.in title.in >nul
echo Problem Test
echo Data %1
title.exe
fc title.out title%1.out
del title.in
del title.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 ) do call %0 %%i
:end
