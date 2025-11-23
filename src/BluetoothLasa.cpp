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
  if (!SerialBT.begin("RobotB_CLIENT", true)) {
    Serial.println("Erreur client!");
    while (1);
  }
}

void connexionBluetooth() // Connexion au périphérique Bluetooth "ESP32_Garfield"
{
  Serial.println("Robot B → Connexion à Robot A...");
  while (!SerialBT.connect("ESP32_Garfield")) {
    Serial.println("Tentative...");
    delay(1000);
  }
  Serial.println("Robot B connecté.");
}


void testBluetooth() // Test de la connexion Bluetooth
{
  if (!SerialBT.connected()) {
    Serial.println("Bluetooth déconnecté, tentative de reconnexion...");
    connexionBluetooth();
  
  }
}






  

