
@echo off
 
::���ʱ��������λ����
set _interval=5
 
::��Ҫ�ػ��Ľ�������
set _processName=QtMyDaemon
 
::��Ҫ�ػ��Ľ�����������
set _processCmd=QtMyDaemon.exe
::set _processCmd=socket�����.exe
::��Ҫ�ػ��Ľ���Ԥ�������������ʱ�䣬��λ����
set _processTimeout=1
 
::�����û�����һ����Administrator 
set _username=adminstrator
 
:LOOP
set /a isAlive=false
::tasklist /FI "username eq %_username%" | find /C "%_processName%" > temp.txt 
tasklist | find /C "%_processName%" > temp.txt
set /p num= < temp.txt
del /F temp.txt
 
if "%num%" == "0" ( 
start %_processCmd% | echo start %_processName% at %time% 
choice /D y /t %_processTimeout% > nul
)
 
if "%num%" NEQ "0" echo %_processName% is running 
choice /D y /t %_interval% >nul
goto LOOP