rem %1 : Dev C++ working directory : e.g. D:\Tools\Dev-Cpp Portable
rem %2 : e.g hw6-1 (w/o the file extension)
@echo off
For %%A in ("%2") do (
rem %%~nA means get the file name only
	rem echo file name only: %%~nA
	%1MinGW64\bin\g++ -std=c++11 %%~nA.cpp -o %%~nA
	%%~nA < %%~nA.test)
pause
