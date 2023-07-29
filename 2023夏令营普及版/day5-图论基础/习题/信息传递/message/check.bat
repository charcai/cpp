@echo off
if "%1"=="" goto loop
copy message%1.in message.in >nul
echo Problem Test
echo Data %1
time<enter
message.exe<message.in>message.out
time<enter
fc message.out message%1.ans
del message.in
del message.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
