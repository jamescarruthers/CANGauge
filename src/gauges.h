#include "draw.h"

void bitGauge(int _x, int _y, int _value, int _bit, bool _onlyOn, const char* _title) {

  int bitTrue = _value >> _bit & 1;

  if (!_onlyOn || bitTrue) {

    u8g2.setDrawColor(1);

    u8g2.setFont(u8g2_font_profont10_mf);

    u8g2.drawStr(_x, _y, _title);

    if (bitTrue) {

      int w = u8g2.getStrWidth(_title);
      int h = u8g2.getAscent();
      u8g2.setDrawColor(2);
      u8g2.drawBox(_x-1, _y-h-1, w+1, h+2);

    }

  }

}

// shows a title but only when on
void bitGaugeOn(int _x, int _y, int _value, int _bit, const char* _title) {

  if (_value >> _bit & 1) {

  u8g2.setDrawColor(2);

  u8g2.setFontMode(1);

  u8g2.setFont(u8g2_font_profont12_mf);

  drawStrCen(_x, _y, _title);


  /*
  int w = u8g2.getStrWidth(_title);
  int h = u8g2.getAscent();
  u8g2.setDrawColor(2);
  u8g2.drawBox(_x-1, _y-h-1, w+1, h+2);
  */
    
  }

}


void gauge4232(int _x, int _y, float _v, gaugeDef _g, int topBot) {

  //top
  int valueY = _y + 19;
  int titleY = _y + 5;

  if (topBot) {
    // bottom
    valueY = _y + 32 - 20;
    titleY = _y + 32 - 5;
  }

  char value[8];
  dtostrf(_v, 0, _g.sigFigs, value);

  u8g2.setFontMode(0);

  u8g2.setFont(u8g2_font_pxplusibmvga8_mf);

  u8g2.setDrawColor(1);
  if (_v < _g.low || _v > _g.high) {
    u8g2.setDrawColor(0);
  }
  drawStrCen(_x + 21, valueY, value);

  u8g2.setDrawColor(1);
  u8g2.setFont(u8g2_font_helvR08_tf);
  drawStrCen(_x + 21, titleY, _g.title);


}


void radialGauge6432(int _x, int _y, float _v, gaugeDef _g) {

  int colFG = 1;

  if (_v < _g.low || _v > _g.high) {
    colFG = flash;
  }

  int x = _x + 32;
  int y = _y + 30;
  float angle = map(_v, _g.min, _g.max, 180, 360); //drawSegment uses raw angles — zero = west/to the right

  u8g2.setDrawColor(colFG);
  drawSegment(x, y, 28, 180, angle);

  u8g2.drawCircle(x, y, 28, U8G2_DRAW_UPPER_LEFT | U8G2_DRAW_UPPER_RIGHT);
  u8g2.drawCircle(x, y, 27, U8G2_DRAW_UPPER_LEFT | U8G2_DRAW_UPPER_RIGHT);
  u8g2.drawLine(x-28, y, x+28, y);
  u8g2.drawLine(x-28, y-1, x+28, y-1);


  char value[8];

  dtostrf(_v, 0, _g.sigFigs, value);

  u8g2.setDrawColor(2);
  u8g2.setFontMode(1);

  u8g2.setFont(u8g2_font_profont17_mf);
  drawStrCen(x, y - 15, value);

  u8g2.setFont(u8g2_font_profont11_mf);
  drawStrCen(x, y - 4, _g.title);

}


void gaugeRadial6464(int _x, int _y, float _v, gaugeDef _g) {

  int colFG = 1;
  int colBG = 0;

  if (_v < _g.low || _v > _g.high) {
    colFG = flash;
    colBG = !flash;
  }

  int x = _x + 32;
  int y = _y + 32;

  u8g2.setDrawColor(colBG);
  u8g2.drawDisc(x, y , 30);

  u8g2.setDrawColor(colFG);

  drawPointer(x, y, 28, 135, 405, _g.min, _g.max, _v);

  //u8g2.drawCircle(x, y, 28);
  //u8g2.drawCircle(x, y, 27);

  //drawTicks(x, y, 30, 135, 405, _g.min, _g.max, _g.majorTicks, 0);
  drawTicks(x, y, 30, 26, 135, 405, _g.min, _g.max, _g.min, _g.max, _g.majorTicks);
  drawTicks(x, y, 30, 26, 135, 405, _g.min, _g.max, _g.high, _g.max, 10);
  drawTicks(x, y, 30, 26, 135, 405, _g.min, _g.max, _g.min, _g.low, 10);

  char value[8];
  dtostrf(_v, 0, _g.sigFigs, value);

  u8g2.setDrawColor(2);
  u8g2.setFontMode(1);

  u8g2.setFont(u8g2_font_profont12_mf);
  drawStrCen(x, y + 32 - 10, value);

  u8g2.setFont(u8g2_font_profont11_mf);
  drawStrCen(x, y + 32 - 20, _g.title);
 
}



void guageRadial6432(int _x, int _y, float _v, gaugeDef _g) {

  int colFG = 1;
  int colBG = 0;

  if (_v < _g.low || _v > _g.high) {
    colFG = flash;
    colBG = !flash;
  }

  int x = _x + 32;
  int y = _y + 24;
  float angle = map(_v, _g.min, _g.max, 135, 405); //drawSegment uses raw angles — zero = west/to the right

  u8g2.setDrawColor(colBG);
  u8g2.drawDisc(x, y , 20, U8G2_DRAW_UPPER_LEFT | U8G2_DRAW_UPPER_RIGHT);

  u8g2.setDrawColor(colFG);

  drawPointer(x, y, 20, 180, 360, _g.min, _g.max, _v);

  //u8g2.drawCircle(x, y, 28);
  //u8g2.drawCircle(x, y, 27);

  drawTicks(x, y, 20, 16, 180, 360, _g.min, _g.max, _g.min, _g.max, _g.majorTicks);

  char value[8];
  dtostrf(_v, 0, _g.sigFigs, value);

  u8g2.setDrawColor(2);
  u8g2.setFontMode(1);

  u8g2.setFont(u8g2_font_profont12_mf);
  drawStrCen(x, y + 32 - 10, value);

  u8g2.setFont(u8g2_font_profont11_mf);
  drawStrCen(x, y + 32 - 20, _g.title);
 
}

void gaugeRadialLine6464 (int _x, int _y, float _v, gaugeDef _g) {

  int colFG = 1;
  int colBG = 0;

  if (_v < _g.low || _v > _g.high) {
    colFG = flash;
    colBG = !flash;
  }

  int x = _x + 32;
  int y = _y + 32;

  u8g2.setDrawColor(colFG);

  //full bar
  if (_v > _g.high) {
    drawTicks(x, y, 30, 26, 45, 360-45, _g.min, _g.max, _g.min, _v, 6);
  }

  drawTicks(x, y, 30, 22, 45, 360-45, _g.min, _g.max, _v-100, _v+100, 6);

  //drawTicks(x, y, 30, 45, 360-45, _g.min, _g.max, _g.high, _g.max, 6);

  u8g2.setDrawColor(1);
  drawTicks(x, y, 30, 26, 45, 360-45, _g.min, _g.max, _g.min, _g.max, _g.majorTicks);
  drawTicks(x, y, 30, 29, 45, 360-45, _g.min, _g.max, _g.min, _g.max, _g.minorTicks);

  char value[8];
  dtostrf(_v, 0, _g.sigFigs, value);

  u8g2.setFont(u8g2_font_profont12_mf);
  drawStrCen(x, y - 8, value);

  u8g2.setFont(u8g2_font_profont11_mf);
  drawStrCen(x, y + 8, _g.title);

  }



void guageBar6432 (int _x, int _y, float _v, gaugeDef _g) {

  int colFG = 1;
  int colBG = 0;

  if (_v < _g.low || _v > _g.high) {
    colFG = flash;
    colBG = !flash;
  }

  _v = constrain(_v, _g.min, _g.max);

  int barLength = map(_v, _g.min, _g.max, 0, 58);

  u8g2.setDrawColor(colFG);
  u8g2.drawBox(_x + 4, _y + 18, barLength, 10);
  
  u8g2.setDrawColor(2);
  int lowPos = map(_g.low, _g.min, _g.max, 0, 58);
  u8g2.drawLine(_x + 4 + lowPos, _y + 18, _x + 4 + lowPos, _y + 18 + 9);

  u8g2.setDrawColor(2);
  int highPos = map(_g.high, _g.min, _g.max, 0, 58);
  u8g2.drawLine(_x + 4 + highPos, _y + 18, _x + 4 + highPos, _y + 18 + 9);

  u8g2.setDrawColor(1);
  u8g2.drawFrame(_x + 4, _y + 18, 58, 10);

  char value[8];
  dtostrf(_v, 0, _g.sigFigs, value);

  //strcat(value, _g.units);

  u8g2.setFont(u8g2_font_profont10_mf);
  drawStrLeft(_x + 4, _y + 16 - 2, _g.title);

  u8g2.setFont(u8g2_font_profont15_mf);
  drawStrRight(_x + 64 - 2, _y + 16 - 2, value);

}

void gaugeBar19264 (int _x, int _y, float _v, gaugeDef _g) {

  // move colFG and colBG to global variables
  int colFG = 1;
  int colBG = 0;

  if (_v < _g.low || _v > _g.high) {
    colFG = flash;
    colBG = !flash;
  }

  int barLength = map(_v, _g.min, _g.max, 2, 190);

  u8g2.setDrawColor(colFG);
  u8g2.drawBox(_x, _y+2, barLength, 60);

  u8g2.setDrawColor(1);
  u8g2.drawFrame(_x+2, _y+2, 190, 60);

  for (float ix = _g.min; ix <= _g.max; ix+=_g.majorTicks) {

    int xpos = map(ix, _g.min, _g.max, 2, 190);
    u8g2.setDrawColor(2);
    u8g2.drawLine(_x+xpos, _y+3, _x+xpos, _y+2+58);

  }


  char value[8];
  dtostrf(_v/100, 0, 0, value);

  u8g2.setFont(u8g2_font_7Segments_26x42_mn);
  u8g2.setFontMode(1);
  u8g2.setDrawColor(2);
  drawStrCen(_x + 96, 32, value);

}

void gaugeBar6420 (int _x, int _y, float _v, gaugeDef _g) {

  _v = constrain(_v, _g.min, _g.max);

  // move colFG and colBG to global variables
  int colFG = 1;
  int colBG = 0;

  if (_v < _g.low || _v > _g.high) {
    colFG = flash;
    colBG = !flash;
  }

  int barLength = map(_v, _g.min, _g.max, 2, 62);
  u8g2.setDrawColor(colFG);
  u8g2.drawBox(_x+2, _y+2, barLength, 16);

  u8g2.setDrawColor(1);
  u8g2.drawFrame(_x+2, _y+2, 62, 16);


  char value[8];
  dtostrf(_v, 0, _g.sigFigs, value);

  //strcat(value, _g.units);


  u8g2.setDrawColor(2);
  u8g2.setFontMode(1);

  u8g2.setFont(u8g2_font_profont11_mf);
  drawStrLeft(_x + 5, _y + 15, _g.title);

  u8g2.setFont(u8g2_font_profont15_mf);
  drawStrRight(_x + 64 - 2, _y + 15, value);

}


void gaugeBarMid6420 (int _x, int _y, float _v, gaugeDef _g) {

  _v = constrain(_v, _g.min, _g.max);

  // move colFG and colBG to global variables
  int colFG = 1;
  int colBG = 0;

  if (_v < _g.low || _v > _g.high) {
    colFG = flash;
    colBG = !flash;
  }

  int barLength = map(_v, _g.min, _g.max, -30, 30);
  u8g2.setDrawColor(colFG);

  if (barLength > 0) {
    u8g2.drawBox(_x+2+32, _y+2, barLength, 16);
  } else {
    barLength = abs(barLength);
    u8g2.drawBox(_x+2+32-barLength, _y+2, barLength, 16);
  }


  u8g2.setDrawColor(1);
  u8g2.drawFrame(_x+2, _y+2, 60, 16);


  char value[8];
  dtostrf(_v, 0, _g.sigFigs, value);

  u8g2.setDrawColor(2);
  u8g2.setFontMode(1);

  u8g2.setFont(u8g2_font_profont11_mf);
  drawStrLeft(_x + 5, _y + 15, _g.title);

  u8g2.setFont(u8g2_font_profont15_mf);
  drawStrRight(_x + 64 - 4, _y + 15, value);

}

void gaugeTable(int _x, int _y, int _w, int _h, float _v1, gaugeDef _g1, float _v2, gaugeDef _g2) {

  _v1 = constrain(_v1, _g1.min, _g1.max);
  _v2 = constrain(_v2, _g2.min, _g2.max);


/*
  for (float ix = _g1.min; ix <= _g1.max; ix+=_g1.majorTicks) {
    for (float iy = _g2.min; iy <= _g2.max; iy+=_g2.majorTicks) {

      int xpixel = map(ix, _g1.min, _g1.max, 16, _w-2);
      int ypixel = map(iy, _g2.min, _g2.max, _h-12, 6);
      u8g2.drawPixel(_x+xpixel, _y+ypixel);

    }
  }
*/

  int Lmargin = 16;
  int Rmargin = 8;
  int Tmargin = 3;
  int Bmargin = 9;

  for (float ix = _g1.min; ix <= _g1.max; ix+=_g1.majorTicks) {
    int xpixel = map(ix, _g1.min, _g1.max, Lmargin, _w-Rmargin);
    u8g2.drawLine(_x + xpixel, _y+Tmargin, _x + xpixel, _y+_h-Bmargin);
  }

  for (float iy = _g2.min; iy <= _g2.max; iy+=_g2.majorTicks) {
    int ypixel = map(iy, _g2.min, _g2.max, _h-Bmargin, Tmargin);
    u8g2.drawLine(_x + Lmargin, _y+ypixel, _x + _w - Rmargin, _y+ypixel);
  }

  int x = map(_v1, _g1.min, _g1.max, Lmargin, _w-Rmargin);
  int y = map(_v2, _g2.min, _g2.max, _h-Bmargin, Tmargin);

  /*
  u8g2.setDrawColor(2);
  u8g2.drawDisc(_x+x, _y+y, 4);
  u8g2.setDrawColor(1);
  u8g2.drawDisc(_x+x, _y+y, 2);
  */

  int cSize = 6;
  u8g2.setDrawColor(1);
  u8g2.drawTriangle(_x+x, _y+y-cSize, _x+x+cSize, _y+y, _x+x-cSize, _y+y);
  u8g2.drawTriangle(_x+x, _y+y+cSize, _x+x+cSize, _y+y, _x+x-cSize, _y+y);

  char v1[8];
  dtostrf(_v1, 0, _g1.sigFigs, v1);

  char v2[8];
  dtostrf(_v2, 0, _g2.sigFigs, v2);

  x = max(x, 42);
  y = min(y, 42);

  u8g2.setFont(u8g2_font_profont10_mf);
  u8g2.setDrawColor(2);

  /* moving version
  drawStrCen(_x+8, _y+y, v2);
  drawStrCen(_x+x, _y+64-3, v1);
  */

  drawStrCen(_x+8, _y+(_h/2)-3, v2);
  drawStrCen(_x+(_w/2)+5, _y+64-3, v1);

  drawStrLeft(_x+Lmargin, _y+_h, _g1.title);
  drawStrCen(_x+8, _y+_h-12, _g2.title);

}

typedef struct history {

  float value[256];
  int position;
  long lastTime;

} history;

history history1;
history history2;
history history3;
history history4;

void gaugeHistory (int _x, int _y, int _w, int _h, history &_history, int _sampleTime, float _v, gaugeDef _g) {

  u8g2.setDrawColor(1);

  for (float iy = _g.min; iy <= _g.max; iy+=_g.majorTicks) {
    int ypixel = map(iy, _g.min, _g.max, _h, 0);
    u8g2.drawLine(_x, _y+ypixel, _x + 2, _y+ypixel);
    u8g2.drawLine(_x+_w, _y+ypixel, _x + _w - 2, _y+ypixel);
  }

  if ((millis() - _history.lastTime) > _sampleTime) {
    _history.position++;
    if (_history.position == _w) { _history.position = 0; }
    _history.value[_history.position] = _v;
    _history.lastTime = millis();
  }

  for (int x = 0; x < _w; x++) {

    int pos = ((_history.position-x) + _w) % _w;
    int y = map(_history.value[pos], _g.min, _g.max, _h, 0);
    
    if (_history.value[pos] > _g.min && _history.value[pos] < _g.max) {
      //u8g2.drawPixel(_x+(_w-x), _y+y);
      u8g2.drawBox(_x+(_w-x), _y+y, 2, 2);
    }

  }

}


void gaugeText6420 (int _x, int _y, float _v, gaugeDef _g) {

  // move colFG and colBG to global variables
  int colFG = 1;
  int colBG = 0;

  if (_v < _g.low || _v > _g.high) {
    colFG = flash;
    colBG = !flash;
  }

  char value[8];
  dtostrf(_v, 0, _g.sigFigs, value);

  u8g2.setDrawColor(1);
  u8g2.setFontMode(1);

  u8g2.setFont(u8g2_font_profont15_mf);
  drawStrRight(_x + 64 - 2, _y + 12, value);

  u8g2.setDrawColor(colFG);

  u8g2.setFont(u8g2_font_profont15_mf);
  drawStrLeft(_x + 2, _y + 12, _g.title);

  _v = constrain(_v, _g.min, _g.max);

  u8g2.drawLine(_x+2, _y+18, _x+62, _y+18);

  int barLength = map(_v, _g.min, _g.max, 2, 62);
  u8g2.setDrawColor(colFG);
  u8g2.drawBox(_x+2, _y+14, barLength, 4);

}





void gaugeTextMid6420 (int _x, int _y, float _v, gaugeDef _g) {

  // move colFG and colBG to global variables
  int colFG = 1;
  int colBG = 0;

  if (_v < _g.low || _v > _g.high) {
    colFG = flash;
    colBG = !flash;
  }

  char value[8];
  dtostrf(_v, 0, _g.sigFigs, value);

  u8g2.setDrawColor(1);
  u8g2.setFontMode(1);

  u8g2.setFont(u8g2_font_profont15_mf);
  drawStrRight(_x + 64 - 2, _y + 12, value);

  u8g2.setDrawColor(colFG);

  u8g2.setFont(u8g2_font_profont15_mf);
  drawStrLeft(_x + 2, _y + 12, _g.title);

  _v = constrain(_v, _g.min, _g.max);

  int barLength = map(_v, _g.min, _g.max, -30, 30);
  u8g2.setDrawColor(colFG);

  u8g2.drawLine(_x+2, _y+18, _x+62, _y+18);

  if (barLength > 0) {
    u8g2.drawBox(_x+32, _y+14, barLength, 4);
  } else {
    barLength = abs(barLength);
    u8g2.drawBox(_x+32-barLength, _y+14, barLength, 4);
  }
  //u8g2.drawBox(_x+2, _y+14, barLength, 4);

}
