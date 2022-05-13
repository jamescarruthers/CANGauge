void drawDotGrid(int _x, int _y, int _w, int _h, int _i) {

  for (int x = _x; x <= _x+_w; x = x + _i) {
    for (int y = _y; y <= _y+_h; y = y + _i) {
      u8g2.drawPixel(x, y);
    }
  }

}



void drawStrLeft(int x, int y, const char* str) {
  //int ycenter = u8g2.getAscent() / 2;
  u8g2.drawStr(x, y, str);
}

void drawStrCen(int x, int y, const char* str) {
  int xcenter = u8g2.getStrWidth(str) / 2;
  int ycenter = u8g2.getAscent() / 2;

  u8g2.drawStr(x - xcenter, y + ycenter, str);
}

void drawStrRight(int x, int y, const char* str) {
  int xright = u8g2.getStrWidth(str);
  //int ycenter = u8g2.getAscent() / 2;
  u8g2.drawStr(x - xright, y, str);
}


void drawBoxCen(int _x, int _y, int _w, int _h) {
  
  int x = _x - (_w/2);
  int y = _h - (_h/2);

  u8g2.drawBox(x, y, _w, _h);

}


void drawSegment(int x, int y, int radius, float from, float to) {

  //int circ = 2 * PI * radius;
  //int angAdd = circ * ((to-from)/360);

  float angleDiv = 1;

  for (float angle = from; angle < to; angle = angle + angleDiv) {
    float x0 = radius * cos(radians(angle));
    float y0 = radius * sin(radians(angle));
    float x1 = radius * cos(radians(angle+angleDiv));
    float y1 = radius * sin(radians(angle+angleDiv));

    u8g2.drawTriangle(x, y, x+x0, y+y0, x+x1, y+y1);
  }

}

void drawTicks(int _x, int _y, int _outerR, int _innerR, int _fromA, int _toA, float _fromV, float _toV, float _ticksFromV, float _ticksToV, float _tickSpacing) {

  for (float v = _ticksFromV; v <= _ticksToV; v = v + _tickSpacing) {
    
    float a = map (v, _fromV, _toV, _fromA, _toA);
    
    int x0 = _outerR * cos(radians(a));
    int y0 = _outerR * sin(radians(a));
    int x1 = _innerR * cos(radians(a));
    int y1 = _innerR * sin(radians(a));

    u8g2.drawLine(_x+x0, _y+y0, _x+x1, _y+y1);

  }

}

void drawPointer(int _x, int _y, int _r, int _fromA, int _toA, float _fromV, float _toV, float _v) {

  float angle = map(_v, _fromV, _toV, _fromA, _toA);

  float nx = _r * cos(radians(angle));
  float ny = _r * sin(radians(angle));
  
  float lx = 2 * cos(radians(angle-90));
  float ly = 2 * sin(radians(angle-90));
  
  float rx = 2 * cos(radians(angle+90));
  float ry = 2 * sin(radians(angle+90));

  float nbx = 6 * cos(radians(angle+180));
  float nby = 6 * sin(radians(angle+180));  
  
  u8g2.drawTriangle(_x+lx, _y+ly, _x+nx, _y+ny, _x+rx, _y+ry);
  u8g2.drawTriangle(_x+lx, _y+ly, _x+nbx, _y+nby, _x+rx, _y+ry);

  u8g2.drawLine(_x, _y, _x+nx, _y+ny);
  u8g2.drawLine(_x, _y, _x+nbx, _y+nby);

}



void draw4ptBox(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3) {

  u8g2.drawTriangle(x0, y0, x1, y1, x2, y2);
  u8g2.drawTriangle(x2, y2, x3, y3, x0, y0);

}
