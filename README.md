# LoraMidi Atmega1284P
Small Lora(WAN) board using an Atmega1284P chip and RFM95 module

## Board version 1.0
### Powering the board
Maximum input voltage on RAW pin: 5.5V<br>
Recommended minimum input voltage on RAW pin: 3.4V<br>
LDO maximum current: 150mA<br>
VCC on this board is 3.3V<br>
With board version 1.0 it is not recommended to power the board through VCC if running from batteries<br>
### Sleep current ‘as is’ (without RFM95 or peripherals):
Sleep current with WDT disabled and attached interrupt (1 minute average): 510nA<br>
Sleep current with WDT enabled (1 minute average): 5.8μA

## Pinout
![Pinout](/docs/images/pinout.png?raw=true "Pinout")<br>
The following pullups/pulldowns are already included on the board for easy usage:<br>
- Pin 1 / 1 Wire / 4.7K pullup
- Pin 16 / SDA, 4.7K pullup
- Pin 17 / SCL, 4.7K pullup
- Pin A2 / Interrupt / 10K pullup

## How to get started
- Install current version of Arduino IDE
- Add the following additional board manager for Atmega1284P support from MightyCore: https://mcudude.github.io/MightyCore/package_MCUdude_MightyCore_index.json
- Select the following settings in your Arduino IDE
  - Board: Atmega1284
  - Bootloader: Yes (UART0)
  - Pinout: Standard pinout
  - Clock: External 8 MHz
  - Compiler LTO: LTO disabled
  - EEPROM: EEPROM retained
  - Variant: 1284P
  - BOD: BOD Disabled
 
 ![Arduino Settings](/docs/images/arduinoSettings.png?raw=true "Arduino Settings")<br>
 With the above settings you will be able to upload code through an FTDI adapter as with any other Arduino, like the MiniPro.
