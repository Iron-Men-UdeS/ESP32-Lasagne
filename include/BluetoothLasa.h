#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include <BluetoothSerial.h>

extern BluetoothSerial SerialBT;

struct positionEtEtat {
  float x;
  float y;
  int etatJeu;
  bool GelerAutreRobot;
};

struct etat {
  int etatJeu;
  bool GelerAutreRobot;
};

void envoieEtat(const positionEtEtat &pos);
bool recoieEtat(etat &pos);
void setupBluetooth();
void testBluetooth();
void connexionBluetooth();


#endif
