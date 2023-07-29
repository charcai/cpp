@echo off
if "%1"=="" goto loop
echo TEST
echo Test%1
copy barn%1.in barn.in >nul
time <enter
barn
time <enter
fc barn%1.out barn.out
pause
del barn.in
del barn.out
goto end
:loop
  for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end