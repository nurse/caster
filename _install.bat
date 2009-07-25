@echo off
set ACCHELPER=lib\AccHelper\AccHelper.dll

if "%1"=="uninstall" goto :uninstall

:install
regsvr32 /s /u %ACCHELPER%
regsvr32 %ACCHELPER%
goto :exit

:uninstall
regsvr32 /u %ACCHELPER%
goto :exit

:exit
