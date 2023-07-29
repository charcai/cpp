@echo off
if "%1"=="" goto loop
echo TEST
echo Test%1
copy milk%1.in milk.in >nul
time <enter
milk
time <enter
fc milk%1.out milk.out
pause
del milk.in
del milk.out
goto end
:loop
  for %%i in (1 2 3 4 5 6 7 8) do call %0 %%i
:end