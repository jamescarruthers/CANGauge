
long lastStim;

void stimulator() {

  //simulate 100Hz

  if (micros() - lastStim > 10000) {

  ms.rpm = 4000 + (sin(radians(frame/4)) * 3500);
  ms.adv_deg = 30 + (sin(radians(frame)) * 20);

  ms.map = 50 + (cos(radians(frame/4)) * 50);
  ms.mat = 20 + (sin(radians(frame/10)) * 20);
  ms.clt = 50 + (cos(radians(frame/10)) * 50);

  ms.tps = 50 + (sin(radians(frame)) * 50);

  ms.batt = 13 + (cos(radians(frame)) * 3);

  ms.afr_1 = 14.7 + (sin(radians(frame)) * 2);
  

  if (millis() % 2000 > 1000) {
    ms.engine = 0;
  } else {
    ms.engine = 0b11111111;
  }

  lastStim = micros();

  }

}