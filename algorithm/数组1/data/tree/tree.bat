@echo off
if "%1"=="" goto loop
copy tree%1.in tree.in >nul
echo Problem Test
echo Data %1
time<enter
tree.exe
time<enter
copy tree%1.out tree.ans >nul
fc tree.out tree.ans
del tree.in
del tree.out
del tree.ans
pause
goto quit
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:quit
