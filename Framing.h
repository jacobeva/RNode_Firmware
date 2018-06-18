#ifndef FRAMING_H
	#define FRAMING_H

	#define FEND			0xC0
	#define FESC			0xDB
	#define TFEND			0xDC
	#define TFESC			0xDD

	#define CMD_UNKNOWN		0xFE
	#define CMD_DATA		0x00
	#define CMD_FREQUENCY	0x01
	#define CMD_BANDWIDTH	0x02
	#define CMD_TXPOWER		0x03
	#define CMD_SF			0x04
	#define CMD_RADIO_STATE 0x05
	#define CMD_RADIO_LOCK	0x06
	#define CMD_READY		0x0F

	#define CMD_STAT_RX		0x21
	#define CMD_STAT_TX		0x22
	#define CMD_STAT_RSSI	0x23
	#define CMD_BLINK		0x30
	#define CMD_RANDOM		0x40

	#define CMD_INFO_READ	0x50
	#define CMD_INFO_WRITE	0x51
	#define CMD_CONF_READ	0x52
	#define CMD_CONF_WRITE	0x53

	#define RADIO_STATE_OFF 0x00
	#define RADIO_STATE_ON	0x01

	#define CMD_ERROR		0x90
	#define ERROR_INITRADIO 0x01
	#define ERROR_TXFAILED	0x02

	#define NIBBLE_SEQ		0xF0
	#define NIBBLE_FLAGS	0x0F
	#define FLAG_SPLIT		0x01
	#define SEQ_UNSET		0xFF

	// Serial framing variables
	size_t frame_len;
	bool IN_FRAME = false;
	bool ESCAPE = false;
	uint8_t command = CMD_UNKNOWN;

#endif

/*
Frequency 433.200		0xc00119d21b80c0
Bandwidth 20.800		0xc00200005140c0
TX Power 8dbm			0xc00308c0
SF 7					0xc00407c0

All:					0xc00119d21b80c00200005140c00308c00407c0

Radio on 				0xc00501c0

Config+on 				0xc00119d21b80c00200005140c00308c00407c00501c0


		c1 = self.bandwidth >> 24
		c2 = self.bandwidth >> 16 & 0xFF
		c3 = self.bandwidth >> 8 & 0xFF
		c4 = self.bandwidth & 0xFF
		data = KISS.escape(chr(c1)+chr(c2)+chr(c3)+chr(c4))


*/