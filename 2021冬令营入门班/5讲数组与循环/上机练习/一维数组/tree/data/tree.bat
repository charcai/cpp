@echo off
if "%1"=="" goto loop
copy tree%1.in tree.in >nul
echo Problem Test
echo Data %1
time<enter
tree
time<enter
fc tree.out tree%1.out
del tree.in
del tree.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
