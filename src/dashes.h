void dashCrank() {

  guageBar6432(0, 0, ms.clt, GDclt);
  guageRadial6432(0, 32, ms.batt, GDbatt);
  gaugeRadialLine6464(128, 0, ms.rpm, GDrpm);

  guageBar6432(192, 0, ms.clt, GDclt);
  guageBar6432(192, 32, ms.clt, GDclt);

  //gaugeRadialLine6464(128, 0, ms.tps, GDtps);
  //gaugeRadialLine6464(192, 0, ms.afr1_old, GDafr);


}

void dashMini() {

  guageBar6432(0, 0, ms.rpm, GDrpm);
  guageBar6432(0, 32, ms.adv_deg, GDadv_deg);

  guageBar6432(64, 0, ms.map, GDmap);
  guageBar6432(64, 32, ms.mat, GDmat);

  guageBar6432(128, 0, ms.clt, GDclt);
  guageBar6432(128, 32, ms.tps, GDtps);

  guageBar6432(192, 0, ms.batt, GDbatt);
  guageBar6432(192, 32, ms.afr_1, GDafr);

}

void dashStandard() {

  gauge4232(0, 0, ms.mat, GDmat, 0);
  gauge4232(43, 0, ms.clt, GDclt, 0);
  gauge4232(86, 0, ms.rpm, GDrpm, 0);

  gauge4232(0, 32, ms.map, GDmap, 1);
  gauge4232(43, 32, ms.adv_deg, GDadv_deg, 1);
  gauge4232(86, 32, ms.afr_1, GDafr, 1);

  u8g2.setDrawColor(2);
  u8g2.drawBox(0, 0, 128, 10);
  u8g2.drawBox(0, 54, 128, 10);
  
}

void dashRace() {

  gaugeBar6420 (0, 0, ms.clt, GDclt);
  gaugeBar6420 (0, 22, ms.mat, GDmat);
  gaugeBarMid6420 (0, 44, ms.afr_1, GDafr);

  gaugeBar19264(64, 0, ms.rpm, GDrpmRace);

}

void dashTune() {

  gaugeBar6420 (0, 0, ms.clt, GDclt);
  gaugeBar6420 (0, 22, ms.mat, GDmat);
  gaugeBarMid6420 (0, 44, ms.afr_1, GDafr);

  gaugeTable(64,0, 192,64, ms.rpm,GDrpm, ms.map,GDmap);

}

void dashHistory() {

  gaugeHistory(2, 2, 60, 40, history1, 50, ms.clt, GDclt);
  gaugeText6420 (0, 44, ms.clt, GDclt);
  bitGauge(32, 16, ms.engine, engineBit_warmup, false, "WUE");

  gaugeHistory(64+2, 2, 60, 40, history2, 50, ms.map, GDmap);
  gaugeText6420 (64, 44, ms.map, GDmap);

  gaugeHistory(128+2, 2, 60, 40, history3, 50, ms.afr_1, GDafr);
  gaugeTextMid6420 (128, 44, ms.afr_1, GDafr);
  bitGauge(128+32, 16, ms.engine, engineBit_tpsAE, true, "AE");

  gaugeHistory(192+2, 2, 60, 40, history4, 50, ms.rpm, GDrpm);
  gaugeText6420 (192, 44, ms.rpm, GDrpm);
  bitGauge(192+32, 16, ms.engine, engineBit_crank, true, "CRANK");

}