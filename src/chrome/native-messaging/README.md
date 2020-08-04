# Chrome native messaging example

## Introduction

The C++ client is based on ForrestFeng's [ChromeExtension](https://github.com/ForrestFeng/ChromeExtension) repo, the [native messaging Chrome documentation](https://developer.chrome.com/extensions/nativeMessaging), and the Chromium's repo's own [native messaging example](https://github.com/chromium/chromium/tree/master/chrome/common/extensions/docs/examples/api/nativeMessaging).

## Using this source code

1. Run the `install-host.bat` from an elevated command prompt or PowerShell window.
2. Open the `cpp-host.sln` in Visual Studio and build the solution.
3. Install the unpacked extension in `app` from your Chrome's `chrome://extensions/` window.
4. Open `chrome://apps/` in Chrome, click the `Native Messaging Example` and interact with the app.
