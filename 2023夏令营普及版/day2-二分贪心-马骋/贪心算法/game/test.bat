@echo off
if "%1"=="" goto loop
copy game%1.in game.in >nul
echo Problem Test
echo Data %1
time<enter
game.exe
time<enter
fc game.out game%1.out
del game.in
del game.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
