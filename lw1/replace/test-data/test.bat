set PROGRAM="%~1"

%PROGRAM% > nul
if NOT ERRORLEVEL 1 goto err

%PROGRAM% input2.txt "%TEMP%\output2.txt" 1231234 cat
if ERRORLEVEL 1 goto err
fc.exe input2.txt "%DIR%\output2.txt"

%PROGRAM% input3.txt "%TEMP%\output3.txt" o ooooo
if ERRORLEVEL 1 goto err
fc.exe input3.txt "%DIR%\output3.txt"

%PROGRAM% input1.txt "%TEMP%\output4.txt" "" ""
if ERRORLEVEL 1 goto err
fc.exe input4.txt "%DIR%\output4.txt"

%PROGRAM% input4.txt "%TEMP%\output4.txt" 1231234 cat
if ERRORLEVEL 1 goto err

echo OK

:err
echo Program testing failed
