@echo off
if "%1"=="" goto loop
copy sortque%1.in sortque.in >nul
echo Problem Test
echo Data %1
time<enter
sortque
time<enter
fc sortque.out sortque%1.out
del sortque.in
del sortque.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
