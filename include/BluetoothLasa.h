#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include <BluetoothSerial.h>

extern BluetoothSerial SerialBT;

struct sPositionEtEtat {
  float x;
  float y;
  int etatJeu;
  bool GelerAutreRobot;
};

struct sEtat {
  int etatJeu;
  bool GelerAutreRobot;
};

bool recoieEtat(uint8_t *tab);
void envoieEtat(uint8_t *tab);
void envoieEtatStruct(const sPositionEtEtat &pos);
bool recoieEtatStruct(sEtat &pos);
void setupBluetooth();
void testBluetooth();
void connexionBluetooth();


#endif
