% m@yiyi 2018.11.6 %
@echo off

call ..\se.bat

%~d0
cd %~dp0
cl *.cpp /Ox /Ot /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /EHsc /MD /W3 /c
rc %~n0.rc
link *.obj ../bo/xSeal.obj *.res /out:%~n0.exe /OPT:NOWIN98 /SUBSYSTEM:WINDOWS /MACHINE:X86 /Release
%~n0.exe

pause