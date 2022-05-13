#include <Arduino.h>
#include <U8g2lib.h>

U8G2_SSD1322_NHD_128X64_F_4W_HW_SPI u8g2(U8G2_R0, /* cs=*/ 10, /* dc=*/ 9, /* reset=*/ 8);

void display_init() {

  u8g2.begin();

}

void drawStrCen(int x, int y, const char* str) {
  int center = u8g2.getStrWidth(str) / 2;
  u8g2.drawStr(x - center, y, str);
}

void dash_rpm() {

    u8g2.clearBuffer();					// clear the internal memory

    int width = map(ms.rpm, 0, 7000, 0, 128);
    char rpm[6];
    itoa(ms.rpm, rpm, 10);
    
    u8g2.setDrawColor(1);
    u8g2.drawBox(0, 0, width, 64);

    u8g2.setDrawColor(2);
    u8g2.setFontMode(1);
    u8g2.setFont(u8g2_font_inb38_mr);
    drawStrCen(64, 60, rpm);


    u8g2.sendBuffer();					// transfer internal memory to the display

}