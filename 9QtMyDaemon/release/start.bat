@echo off
start %cd%\QtMyDaemon.exe   %启动程序%
setlocal EnableDelayedExpansion 
reg add "HKLM\Software\Microsoft\Windows\CurrentVersion\Run" /v "QtMyDaemon" /t REG_SZ /d "%cd%\QtMyDaemon.exe" /f   %将程序写进注册表,开机自启动%
echo Register successfully.
pause>nul %>nul的作用是不显示请按任意键继续%