For %%A in ("%1") do (
rem %%~nA means get the file name only
	echo file name only: %%~nA
	%%~nA < %%~nA.test)
pause
