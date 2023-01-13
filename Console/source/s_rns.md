[title]: <> (Reticulum)
## Reticulum
The cryptographic networking stack for building resilient networks anywhere. This packages requires you have `python` and `pip` installed on your computer. This should come as standard on most operating systems released since 2020.

### Local Installation
If you do not have access to the Internet, or would prefer to install Reticulum directly from this RNode, you can use the following instructions.

- Download the [{PKG_rns}]({ASSET_PATH}{PKG_rns}) package from this RNode and unzip it
- Install it with the command `pip install {PKG_NAME_rns}`
- Verify the installed Reticulum version by running `rnstatus --version`

### Online Installation
If you are connected to the Internet, you can try to install the latest version of Reticulum via the `pip` package manager.

- Install Reticulum by running the command `pip install rns`
- Verify the installed Reticulum version by running `rnstatus --version`

### Dependencies
If the installation has problems resolving dependencies, you can try to install the `python-cryptography`, `python-netifaces` and `python-pyserial` packages from your systems package manager, if they are locally available. If this is not possible, you please read the [Getting Started section of the Reticulum Manual]({ASSET_PATH}m/gettingstartedfast.html) for more detailed information. Specifically the [Pure-Python Reticulum]({ASSET_PATH}m/gettingstartedfast.html#pure-python-reticulum) section may be of use.