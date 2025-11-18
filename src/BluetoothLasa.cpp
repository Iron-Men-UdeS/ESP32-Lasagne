#include "BluetoothLasa.h"


BluetoothSerial SerialBT;



void envoieEtat(const positionEtEtat &pos) { // Prend la reférence d'une structure Position en paramètre
  SerialBT.write((uint8_t*)&pos, sizeof(positionEtEtat)); 
}

bool recoieEtat(etat &pos) {
  if (SerialBT.available() >= sizeof(etat)) {
    SerialBT.readBytes((uint8_t*)&pos, sizeof(etat));
    return true;
  }
  return false;
}

void setupBluetooth() // Initialisation du Bluetooth
{
  SerialBT.begin("ESP32_Lasagne"); // Nom du périphérique Bluetooth
}

void connexionBluetooth() // Connexion au périphérique Bluetooth "ESP32_Garfield"
{
  //Serial.println("Robot lasagne → Connexion à Robot Garfield...");
  while (!SerialBT.connect("ESP32_Garfield")) {
    //Serial.println("Tentative...");
    delay(2000);
  }
}

void testBluetooth() // Test de la connexion Bluetooth
{
  if (!SerialBT.connected()) {
    Serial.println("Bluetooth déconnecté, tentative de reconnexion...");
    connexionBluetooth();
  
  }
}
