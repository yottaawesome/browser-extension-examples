# Chrome native messaging example (Windows)

## Introduction

This demonstrates how to achieve communication between a Chrome extension and a native C++ client on the Windows platform. The source code contained in this example is based on ForrestFeng's [ChromeExtension](https://github.com/ForrestFeng/ChromeExtension) repo, the [native messaging Chrome documentation](https://developer.chrome.com/extensions/nativeMessaging), and the Chromium's repo's own [native messaging example](https://github.com/chromium/chromium/tree/master/chrome/common/extensions/docs/examples/api/nativeMessaging).

## Using this source code

1. Run the `install-host.bat` batch file from an elevated command prompt or PowerShell window.
2. Open the `cpp-host.sln` in Visual Studio and build the solution.
3. Install the unpacked extension in `app` from your Chrome's `chrome://extensions/` window.
4. Open `chrome://apps/` in Chrome, click the `Native Messaging Example` and interact with the app.
5. To uninstall the extension, run the `uninstall-host.bat` file from an elevated command prompt or PowerShell window.

## Additional resources

* [Another client example](https://github.com/Mandar-Shinde/Google-Chrome-Native-Messaging).
