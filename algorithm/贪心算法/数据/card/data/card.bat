@echo off
if "%1"=="" goto loop
copy card%1.in card.in >nul
echo Problem Test
echo Data %1
time<enter
card
time<enter
fc card.out card%1.out
del card.in
del card.out
pause
goto end
:loop
for %%i in (1 2 3 4 5) do call %0 %%i
:end
