@echo off

set PROGRAM="%~1"

%PROGRAM% > nul
if NOT ERRORLEVEL 1 goto err

%PROGRAM% test-data\input1.txt "%TEMP%\output1.txt" 1231234 cat || goto err
fc "%TEMP%\output1.txt" test-data\input1.txt > nul

%PROGRAM% test-data\input3.txt "%TEMP%\output3.txt" mama papa || goto err
fc "%TEMP%\output3.txt" test-data\input3.txt > nul

%PROGRAM% test-data\input4.txt "%TEMP%\output4.txt" 123 999 || goto err
fc "%TEMP%\output4.txt" test-data\input4.txt > nul

%PROGRAM% test-data\input2.txt "%TEMP%\output2.txt" 1231234 9 || goto err
fc "%TEMP%\output2.txt" test-data\input2.txt > nul

echo OK
exit /B 0 

:err
echo Program testing failed
exit /B 1