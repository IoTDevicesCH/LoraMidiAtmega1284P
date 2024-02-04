# LoraMidi Atmega1284P
Special and small Lora(WAN) board using an Atmega1284P chip, RFM95 module, TPL5010 timer with optional watchdog function and switched GND pins. 

<a href="https://www.tindie.com/stores/iotdevices/"><img src="https://d2ss6ovg47m0r5.cloudfront.net/badges/tindie-smalls.png" alt="I sell on Tindie" width="200" height="55"></a>

## Specialities about this board
- Arduino compatible
- Atmega1284P @ 8MHz with 128KB flash and 16KB RAM, easy replacement for Atmega328p boards
- Small form factor, 36.4mm lenght, 31.4mm width
- TPS782 low quiescent 500nA regulator
- RFM95 can be soldered to the bottom side
- Wire antenna, helical antenna, SMA antenna support
- TPL5010 can be used to wakeup the Atmega, with optional watchdog function
- Voltage divider on board, enabled through two MOSFET driven by pin 0
- I2C and 1-Wire pullups on board
- Input pin for interrupts with pullup resistor on board
- Two GND pins can be powered on/off through a MOSFET driven by pin 15 to power on/off external peripherals

## Board version 2.3
### Powering the board
Maximum input voltage on UREG pin: 5.5V<br>
Recommended minimum input voltage on UREG pin: 3.4V<br>
LDO maximum current: 150mA<br>
VCC on this board is 3.3V<br>
To power the board through VCC it is recommended to cut the trace from the LDO to VCC to reduce power consumption. See in the solder jumper section how to disable the LDO.<br>
### Sleep current without TPL5010 and RFM95, powered through the LDO:
Sleep current with WDT disabled and attached interrupt (1 minute average): approx 570nA<br>
Sleep current with WDT enabled (1 minute average): approx 6.1μA
### Sleep current with TPL5010 and without RFM95, powered through the LDO:
Sleep current with WDT disabled and TPL5010 attached as interrupt: approx 610nA
### Sleep current with TPL5010 and RFM95, powered through the LDO:
Sleep current with TPL5010 and RFM95, powered through the LDO: approx 1.5μA
### Sleep current with TPL5010 and without RFM95, powered through VCC (LDO disabled):
Sleep current with WDT disabled and TPL5010 attached as interrupt: approx 200nA

## Pinout
![Pinout](/docs/images/pinout.png?raw=true "Pinout")<br>
The following pullups/pulldowns are already included on the board for easy usage:<br>
- Pin 1 / 1 Wire / 4.7K pullup
- Pin 16 / SDA, 4.7K pullup
- Pin 17 / SCL, 4.7K pullup
- Pin 4 / Interrupt / 10K pullup
<br>

## LMIC Pinmap
	#LMIC Pinmap
	const lmic_pinmap lmic_pins = {
		.nss = 14,
		.rxtx = LMIC_UNUSED_PIN,
		.rst = 13,
		.dio = {10, 11, 12},
	};


## Solder jumpers
The board has four solder jumpers.
### LDO on/off
- Top side, SJ1, closed = LDO on, open = LDO off
### Voltage divider UREG/VCC selection
- Bottom side, SJ2, left + middle connected = measure UREG, right + middle connected = measure VCC
### TPL5010 on/off
- Bottom side, SJ3, closed = TPL5010 powered, open = TPL5010 not powered
### TPL5010 WDT functionality on/off
- Bottom side, SJ4, closed = TPL5010 WDT on, open = TPL5010 WDT off
<br><br>![Solderjumpers](/docs/images/solderjumpers.png?raw=true "Solderjumpers")<br>

## TPL5010 configuration
The TPL5010 provides selectable timing intervals through resistor(s). On the bottom side, R14, R15 and VR1 are wired in parallel.<br>
To set a fixed time interval, populate either one or both R14 and R15 resistors with the desired value resistors.<br>
To set a variable time interval, don't populate R14 and R15 but populate VR1 with a trimmpotentiometer.<br>
R14 and R15 are 0805 in size, the trimmpotentiometer pads are suited for the TC33X-2 line from Bourns.<br>
Please check the datasheet on page 14 and 15 of the TPL5010 for the available timing intervals: https://www.ti.com/lit/ds/symlink/tpl5010.pdf<br>

## How to get started
- Install current version of Arduino IDE
- Add the following additional board manager for Atmega1284P support from MightyCore: https://mcudude.github.io/MightyCore/package_MCUdude_MightyCore_index.json
  - Install version 2.2.2, starting with version 3.0.0, a new bootloader (Urboot) is used. Currently boards are still shipped with Optiboot bootloader
- Select the following settings in your Arduino IDE
  - Board: Atmega1284
  - Bootloader: Yes (UART0)
  - Pinout: Standard pinout
  - Clock: External 8 MHz
  - Compiler LTO: LTO disabled
  - EEPROM: EEPROM retained
  - Variant: 1284P
  - BOD: BOD Disabled
![Arduino Settings](/docs/images/arduinoSettings.png?raw=true "Arduino Settings")
With the above settings you will be able to upload code through an FTDI adapter as with any other Arduino, like the MiniPro.

## More accurate supply voltage measurement
If you want a more accurate reading of the supply voltage, use the AREF value from the sticker on the board.

## Device pictures
# Device
![Device](/docs/images/LoraMidi_1284P_device.jpg?raw=true "Device")

# Top view
![Top view](/docs/images/LoraMidi_1284P_topview.jpg?raw=true "Top view")

# Bottom view
![Bottom view](/docs/images/LoraMidi_1284P_bottomview.jpg?raw=true "Bottom view")

# Measurements
![Height](/docs/images/LoraMidi_1284P_height.jpg?raw=true "Height")<br>
![Width](/docs/images/LoraMidi_1284P_width.jpg?raw=true "Width")
