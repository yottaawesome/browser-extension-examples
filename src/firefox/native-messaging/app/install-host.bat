:: Change HKLM to HKCU if you want to install to the current user.
:: %~dp0 is the directory containing this bat script and ends with a backslash.
REG ADD "HKLM\Software\Mozilla\NativeMessagingHosts\nativemessaging.example" /ve /t REG_SZ /d "%~dp0nmh.json" /f
