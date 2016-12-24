rem Change the leading tabs to spaces in all .cpp
rem g++ -std=c++11 %1.cpp -o %1.exe
For %%A in (*.cpp) do (
	TabToSpaces %%A
	del %%A
	ren %%A.out %%A
	rem pause
)

