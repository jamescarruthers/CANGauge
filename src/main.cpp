#include <Arduino.h>
#include <FlexCAN_T4.h>
#include <MegaCAN.h>
#include <U8g2lib.h>

// Teensy stuff
extern "C" uint32_t set_arm_clock(uint32_t frequency);
extern float tempmonGetTemp(void);

// setup CAN on pins 22/23
FlexCAN_T4<CAN1, RX_SIZE_256, TX_SIZE_16> can;
void decodeCAN(const CAN_message_t &msg);

// MegaSquirt variables decoding
/*
MegaCAN MSCAN;
MegaCAN_broadcast_message_t ms;
const uint32_t baseID = 1520;
*/


// choose which display
//U8G2_SSD1322_NHD_128X64_F_4W_HW_SPI u8g2(U8G2_R0, /* cs=*/ 10, /* dc=*/ 9, /* reset=*/ 8);
U8G2_SSD1322_NHD_256X64_F_4W_HW_SPI u8g2(U8G2_R0, /* cs=*/ 10, /* dc=*/ 9, /* reset=*/ 8);

bool update = false;

int frame = 0;
int flash = 0;


// some handy maths
#include "maths.h"

// megasquirt decodes CAN frames and turns them in to variables
#include "megasquirt.h"
MSData ms;

// stimulator provides a test enivronment for when away from the vehicle
// use stimulator() to animate values
#include "stimulator.h"

// gauge definitions sets up templates for variables - titles, minimum, maximum etc
#include "gaugeDefinitions.h"

// gauges contains a number of template gauges of different sizes
#include "gauges.h"

// dashes is where you pull together gauges and lay them out
#include "dashes.h"

//#include "starfield.h"


void setup() {

  // lower frequency for heat saving?
  set_arm_clock(300000000);

  Serial.begin(115200);

  // setup CAN
  can.begin();
  can.setBaudRate(500000);
  can.enableFIFO();
  can.enableFIFOInterrupt();
  can.onReceive(decodeCAN);

  // setup display
  u8g2.begin();
  //  u8g2.setBusClock(35000000);
  u8g2.setBusClock(20000000);
  u8g2.setContrast(255);
  u8g2.setFlipMode(1);

  //initStars();

}

void loop() {

  frame++;

  if (millis() % 200 > 100) {
    flash = 0;
  } else {
    flash = 1;
  }

  //stimulator();

  if (update) {

    update = false;

    //update display stuff
    //Serial.println(ms.rpm);

  }

  u8g2.clearBuffer();					// clear the internal memory
  //long stopwatch = micros();

if (ms.rpm < 500) {
  dashCrank();
} else {
  dashStandard();
}

  //u8g2.setFont(u8g2_font_profont17_mf);
  //radialGauge(64, 0, 64, 32, ms.rpm, 0, "RPM", 0, 7200);

  //u8g2.setFont(u8g2_font_profont17_mf);
  //radialGauge(0, 0, 64, 32, ms.afr1_old, 1, "AFR", 9.7, 19.7);

  //radialGauge6432(0, 0, ms.rpm, 0, "RPM", 0, 7200, 0, 5000);
  //radialGauge6432(0, 32, ms.rpm, 0, "RPM", 0, 7200, 0, 5000);
  //radialGauge6464(64, 0, ms.afr1_old, 1, "AFR", 9.7, 19.7, 13, 16.4);

  //drawDotGrid(0, 0, 256, 64, 32);

  //dashStandard();
  //dashCrank();
  //dashMini();
  //dashRace();
  //dashTune();
  //dashHistory();

  //drawTicks(32, 32, 28, 135, 405, 9.7, 19.7, 0.5);

  //gauge4232(43, 0, ms.afr1_old, 1, "AFR", 9.7, 19.7, 13, 16.4);
  //gauge4232(43, 32, ms.rpm, 0, "RPM", 0, 7200, 0, 5000);
  //gauge4232(86, 0, ms.afr1_old, 1, "AFR", 9.7, 19.7, 13, 16.4);
  //gauge4232(86, 32, ms.rpm, 0, "RPM", 0, 7200, 0, 5000);

  //triangleGauge6432(0, 0, ms.afr1_old, 1, "AFR", 9.7, 19.7, 13, 16.4);

  //historyGauge6464(0, 0, ms.afr1_old, 1, "AFR", 9.7, 19.7, 13, 16.4, adv_deg);

  //bitGauge(10, 10, ms.engine, engineBit_tpsAE, "CRANK");

  //u8g2.setDrawColor(1);
  //drawStars(0, 0, 128, 64);

  u8g2.sendBuffer();					// transfer internal memory to the display

  //stopwatch = micros() - stopwatch;

  //Serial.println(stopwatch/1000.0);

  //Serial.println(tempmonGetTemp());

  // no CAN received warning
  // temp warning


}

void decodeCAN(const CAN_message_t &msg) {

  //MSCAN.getBCastData(msg.id, msg.buf, ms);

  processMSData(msg.id, msg.buf, ms);
  update = true;

}

