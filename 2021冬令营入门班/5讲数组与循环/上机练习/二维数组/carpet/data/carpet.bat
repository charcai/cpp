@echo off
if "%1"=="" goto loop
copy carpet%1.in carpet.in >nul
echo Problem Test
echo Data %1
time<enter
carpet
time<enter
fc carpet.out carpet%1.ans
del carpet.in
del carpet.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
