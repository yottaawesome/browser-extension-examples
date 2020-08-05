# Firefox native messaging example (Windows)

## Introduction

This demonstrates how to achieve communication between a Firefox extension and a native C++ client on the Windows platform. The source code contained in this example is based on the [native messaging Firefox documentation](https://developer.mozilla.org/en-US/docs/Mozilla/Add-ons/WebExtensions/Native_messaging), and the MDN's own [native messaging example](https://github.com/mdn/webextensions-examples/tree/master/native-messaging).

## Using this source code

1. Run the `install-host.bat` batch file from an elevated command prompt or PowerShell window.
2. Open the `cpp-host.sln` in Visual Studio and build the solution.
3. Install the extension in Firefox's [About:Debugging](about:debugging#/runtime/this-firefox) window.
4. Click on `Inspect` for the `Native messaging example` add-on in Firefox and then click the envelope icon in the top right of the Firefox window.
5. To uninstall the extension, run the `uninstall-host.bat` file from an elevated command prompt or PowerShell window.
