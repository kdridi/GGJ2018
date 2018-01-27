RMDIR /S /Q build
MKDIR build

CD build
"..\vendor\cmake-3.10.2-win64-x64\bin\cmake.exe" .. -G "Visual Studio 15 2017 Win64"
"c:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\IDE\devenv.exe" /build Debug "myproject.sln" /project "myproject.vcxproj"

COPY Debug\myproject.exe ..\target

CD ..