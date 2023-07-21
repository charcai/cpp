@echo off
if "%1"=="" goto loop
copy nba%1.in nba.in >nul
echo Problem Test
echo Data %1
time<enter
nba
time<enter
fc nba.out nba%1.out
del nba.in
del nba.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
