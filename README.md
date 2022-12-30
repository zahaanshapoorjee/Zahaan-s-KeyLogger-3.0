# Zahaan-s-Keylogger-3.0
Zahaan's Keylogger 3.0 is a Keylogger written in C++ to be used **FOR EDUCATIONAL PURPOSES ONLY**, usage of Zahaan's Keylogger 3.0 for attacking targets without prior mutual consent is illegal. The developer assumes no liability and is not responsible for any misuse or damage caused by this program.

**DO NOT RUN THIS ON YOUR COMPUTER IT IS A PAIN IN THE A$$ TO GET RID OFF**

**Liability Disclaimer**<br>
To the maximum extent permitted by applicable law, Zahaan Shapoorjee and/or affiliates who have submitted content to Zahaan Shapoorjee, shall not be liable for any indirect, incidental, special, consequential or punitive damages, or any loss of profits or revenue, whether incurred directly or indirectly, or any loss of data, use, goodwill, or other intangible losses, resulting from (i) your access to this resource and/or inability to access this resource; (ii) any conduct or content of any third party referenced by this resource, including without limitation, any defamatory, offensive or illegal conduct or other users or third parties; (iii) any content obtained from this resource

**FEATURES**<br>
1) Completely Undetectable by any Anti-Virus and all files move themselves to a hidden folder which the target cannot see.
2) Gives information about the target such as IP Address, location, network provider, etc. 
3) Logs all key inputs with their exact date and time, including special cases such as 123, abc, [SHIFT], !@#, etc.
4) Periodically emails the log files to email address of your choice along with System information, date, time, IP Address, Geolocation, etc.
5) Persistence - The places itself hidden in the startup folder and runs on the target's computer even after system restart.
6) Gives information about the target's PC such as processor type, number of processors, page size, OEM ID, etc.
7) Disguised under the alias "Windows Update.exe" but you can change this based on your target.

**THIS IS NOT MEANT TO BE USED MALICIOUSLY AND I HIGHLY RECOMMEND YOU DO NOT RUN THE SCRIPT ON YOUR PC**

**Set-Up**<br>
1) Edit "mailSender.vbs", put in the email and password from which you would like to send the logs, as well as to who you would like the logs to be emailed - Instructions for the same are provided in the comments of the file.
2) Edit "start.vbs" and change the argument for WScript.Sleep(<arg>), 1000=1 second so change it according to how often you want to recieve logs.
3) Change the name of "Zahaan's Keylogger.bat" to any alias (Eg: WindowsUpdate.bat, SteamUpdate.bat, ChromeUpdate.bat)
4) Place the folder on the target's PC (With their consent, **OBVIOUSLY**), and run the .bat file and your job is done.
 

