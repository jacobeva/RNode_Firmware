# RNode Firmware <img align="right" src="https://img.shields.io/badge/License-CC%20BY--NC--SA%204.0-lightgrey.svg"/>

This is the firmware for [RNode](https://unsigned.io/rnode), a very flexible LoRa-based communication device. RNode can functions as a:

- Network adapter for [Reticulum](https://github.com/markqvist/Reticulum)
- A general purpose long-range data radio
- LoRa interface for your computer (or any device with a USB or serial port)
- Generic [LoRa-based network adapter](https://unsigned.io/15-kilometre-ssh-link-with-rnode/) for your Linux devices
- [Packet sniffer](https://github.com/markqvist/LoRaMon) for LoRa networks
- LoRa development board
- A LoRa-based KISS-compatible TNC for amateur radio and AX.25 applications
- A flexible platform for experiementing with LoRa technology

To install this firmware on homebrew RNodes and other supported boards, please use the [RNode Config Utility](https://github.com/markqvist/rnodeconfigutil). It contains an auto-installer that allows you to install the RNode firmware on a variety of boards. For guides and tutorials on how to get started with making your own RNodes, visit [unsigned.io](https://unsigned.io).

![Devices Running RNode Firmware](https://github.com/markqvist/RNode_Firmware/raw/master/Documentation/rnfw_1.jpg)

## Get Started

You can download and flash the firmware to all the supported boards using the [RNode Config Utility](https://github.com/markqvist/rnodeconfigutil). All firmware releases are now handled and installed directly through the `rnodeconf` utility, which is inclueded in the `rns` package. It can be installed via `pip`:

```
# Install rnodeconf via rns package
pip install rns --upgrade

# Install the firmware on a board with the install guide
rnodeconf --autoinstall
```

## Current Status
The RNode firmware can be considered stable at this point. If you do find a bug or discover unintended behaviour, please report it as an issue here, so I can fix it!

## Supported Hardware

The RNode Firmware supports the following boards:

- The original RNode from [unsigned.io](https://unsigned.io/)
- Homebrew RNodes based on ATmega1284p boards
- Homebrew RNodes based on ATmega2560 boards
- Homebrew RNodes based on Adafruit Feather ESP32 boards
- Homebrew RNodes based on generic ESP32 boards
- LilyGO T-Beam v1.1 devices
- LilyGO LoRa32 v2.0 devices
- LilyGO LoRa32 v2.1 devices
- Heltec LoRa32 v2 devices

The original RNode from [unsigned.io](https://unsigned.io) is controlled by a powerful ATmega1284p MCU, and is fully Arduino compatible. You can use this firmware, or it can be programmed any way you like, either from the Arduino IDE, or using any of the available tools for AVR development. This firmware can also be edited and compiled directly from the Arduino IDE.

For adding RNode to your Arduino environment, please see [this post](https://unsigned.io/board-support-in-arduino-ide/).

For configuring an RNode with this firmware, please have a look at the [RNode Config Utility](https://github.com/markqvist/rnodeconfigutil).

## Operating Modes
RNode can operate in two modes, host-controlled (default) and TNC mode:

- When RNode is in host-controlled mode, it will stay in standby when powered on, until the host specifies frequency, bandwidth, transmit power and other required parameters. This mode can be enabled by using the -N option of this utility. In host-controlled mode, promiscuous mode can be activated to sniff any LoRa frames.

- When RNode is in TNC mode, it will configure itself on powerup and enable the radio immediately. This mode can be enabled by using the -T option of this utility (the utility will guide you through the settings if you don't specify them directly).

## USB and Serial Protocol
You can communicate with RNode either via the on-board USB connector, or using the serial pins on the board (labeled RX0 and TX0). RNode uses a standard FTDI USB chip, so it works out of the box without additional drivers in most operating systems.

All communications to and from the board uses [KISS framing](https://en.wikipedia.org/wiki/KISS_(TNC)) with a custom command set. RNode also does not use HDLC ports in the command byte, and as such uses the full 8 bits of the command byte is available for the actual command. Please see table below for supported commands.

| Command          | Byte | Description
| -----------------|------| -----------------------------------------------
| Data frame       | 0x00 | A data packet to or from the device
| Frequency        | 0x01 | Sets or queries the frequency
| Bandwidth        | 0x02 | Sets or queries the bandwidth
| TX Power         | 0x03 | Sets or queries the TX power
| Spreading Factor | 0x04 | Sets or queries the spreading factor
| Coding Rate      | 0x05 | Sets or queries the coding rate
| Radio State      | 0x06 | Sets or queries radio state
| Radio Lock       | 0x07 | Sets or queries the radio lock
| Device Detect    | 0x08 | Probe command for device detection
| Promiscuous      | 0x0E | Sets or queries promiscuous mode
| RX Stats         | 0x21 | Queries received bytes
| TX Stats         | 0x22 | Queries transmitted bytes
| Last RSSI        | 0x23 | Indicates RSSI of last packet received
| Blink            | 0x30 | Blinks LEDs
| Random           | 0x40 | Queries for a random number
| Firmware Version | 0x50 | Queries for installed firmware version
| ROM Read         | 0x51 | Read EEPROM byte
| ROM Write        | 0x52 | Write EEPROM byte
| TNC Mode         | 0x53 | Enables TNC mode
| Normal Mode      | 0x54 | Enables host-controlled mode
| ROM Erase        | 0x59 | Completely erases EEPROM
| Error            | 0x90 | Indicates an error

## Programming Libraries
Have a look in the "Libraries" folder for includes to let you easily use RNode in your own software.

Here's a Python example:

```python
from RNode import RNodeInterface

def gotPacket(data, rnode):
	print "Received a packet: "+data

rnode = RNodeInterface(
	callback = gotPacket,
	name = "My RNode",
	port = "/dev/ttyUSB0",
	frequency = 868000000,
	bandwidth = 125000,
	txpower = 2,
	sf = 7,
	cr = 5,
	loglevel = RNodeInterface.LOG_DEBUG)

rnode.send("Hello World!")
```

## Promiscuous Mode and LoRa Sniffing
RNode can be put into LoRa promiscuous mode, which will dump raw LoRa frames to the host. Raw LoRa frames can also be sent in this mode, and have the standard LoRa payload size of 255 bytes. To enable promiscuous mode send the "Promiscuous" command to the board, or use one of the programming libraries. You can also use the example program [LoRaMon](https://github.com/markqvist/LoRaMon) for an easy to use LoRa packet sniffer.

## Support RNode Development
You can help support the continued development of open, free and private communications systems by donating via one of the following channels:

- Monero:
  ```
  84FpY1QbxHcgdseePYNmhTHcrgMX4nFfBYtz2GKYToqHVVhJp8Eaw1Z1EedRnKD19b3B8NiLCGVxzKV17UMmmeEsCrPyA5w
  ```
- Ethereum
  ```
  0x81F7B979fEa6134bA9FD5c701b3501A2e61E897a
  ```
- Bitcoin
  ```
  3CPmacGm34qYvR6XWLVEJmi2aNe3PZqUuq
  ```
- Ko-Fi: https://ko-fi.com/markqvist

## License
Permission is hereby granted to use the RNode firmware in binary form, for any and all purposes, and to freely distribute binary copies of the firmware, so long as no payment or compensation is charged or received for such distribution or use.

If you want to charge money or receive compensation for providing this work to others, in any way or form, you must buy a license for doing so, which is cheap and easy.

Unless otherwise noted, this work is licensed under a [Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License][cc-by-nc-sa].

Prior versions of this work, until and including commit [fe5e6aab9c2ab8fe69ede7f1da04bcffff7d1ed7](https://github.com/markqvist/RNode_Firmware/commit/fe5e6aab9c2ab8fe69ede7f1da04bcffff7d1ed7) was licensed purely under MIT License.

If you want to use the RNode Firmware in commercial products, or build and sell RNodes, it is easy to do so by licensing the firmware commercially. I provide a range of convenient tools and resources for anyone who wants to build and sell RNodes, so just get in contact with me to get started.

<img src="https://licensebuttons.net/l/by-nc-sa/4.0/88x31.png" align="right">

[cc-by-nc-sa]: http://creativecommons.org/licenses/by-nc-sa/4.0/
[cc-by-nc-sa-image]: https://licensebuttons.net/l/by-nc-sa/4.0/88x31.png
[cc-by-nc-sa-shield]: https://img.shields.io/badge/License-CC%20BY--NC--SA%204.0-lightgrey.svg
