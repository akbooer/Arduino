/**
 * The MySensors Arduino library handles the wireless radio link and protocol
 * between your home built sensors/actuators and HA controller of choice.
 * The sensors forms a self healing radio network with optional repeaters. Each
 * repeater and gateway builds a routing tables in EEPROM which keeps track of the
 * network topology allowing messages to be routed to nodes.
 *
 * Created by Henrik Ekblad <henrik.ekblad@mysensors.org>
 * Copyright (C) 2013-2015 Sensnology AB
 * Full contributor list: https://github.com/mysensors/Arduino/graphs/contributors
 *
 * Documentation: http://www.mysensors.org
 * Support Forum: http://forum.mysensors.org
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 */

#ifdef ARDUINO_ARCH_ESP8266

#ifndef MyHwESP8266_h
#define MyHwESP8266_h

#include "MyConfig.h"
#include "MyMessage.h"


#ifdef __cplusplus
#include <Arduino.h>
#include <SPI.h>
#endif

// Define these as macros to save valuable space

#define hwDigitalWrite(__pin, __value) (digitalWrite(__pin, __value))
#define hwInit() Serial.begin(BAUD_RATE)
#define hwWatchdogReset() wdt_reset()
#define hwReboot() wdt_enable(WDTO_15MS); while (1)
#define hwMillis() millis()

void hwReadConfigBlock(void* buf, void* adr, size_t length);
void hwWriteConfigBlock(void* buf, void* adr, size_t length);
void hwWriteConfig(int adr, uint8_t value);
uint8_t hwReadConfig(int adr);

enum period_t
{
	SLEEP_15Ms,
	SLEEP_30MS,
	SLEEP_60MS,
	SLEEP_120MS,
	SLEEP_250MS,
	SLEEP_500MS,
	SLEEP_1S,
	SLEEP_2S,
	SLEEP_4S,
	SLEEP_8S,
	SLEEP_FOREVER
};



void hwSleep(unsigned long ms);
bool hwSleep(uint8_t interrupt, uint8_t mode, unsigned long ms);
uint8_t hwSleep(uint8_t interrupt1, uint8_t mode1, uint8_t interrupt2, uint8_t mode2, unsigned long ms);
#ifdef MY_DEBUG
	void hwDebugPrint(const char *fmt, ... );
#endif

#endif // #ifdef ARDUINO_ARCH_ESP8266