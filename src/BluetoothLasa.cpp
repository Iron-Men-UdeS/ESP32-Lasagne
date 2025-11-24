#include "BluetoothLasa.h"


BluetoothSerial SerialBT;

/*******************************************************************************************
 * Auteur : Vincent
 * 
 * Envoie la position et l'état du robot sous forme de structure via Bluetooth
 *
 * @param positionEtEtat (structure) structure contenant la position (x,y) et l'état du robot
 ******************************************************************************************/

void envoieEtat(const positionEtEtat &pos) { // Prend la reférence d'une structure Position en paramètre
  SerialBT.write((uint8_t*)&pos, sizeof(positionEtEtat)); 
}

/*******************************************************************************************
 * Auteur : Vincent
 * 
 * Lit la position et l'état du robot sous forme de structure via Bluetooth et la copie dans la structure passée en paramètre
 *
 * @param Etat (structure) structure contenant l'état du robot
 ******************************************************************************************/
bool recoieEtat(etat &pos) {
  if (SerialBT.available() >= sizeof(etat)) {
    SerialBT.readBytes((uint8_t*)&pos, sizeof(etat));
    return true;
  }
  return false;
}

/*******************************************************************************************
 * Auteur : Vincent
 * 
 * Démarre le module Bluetooth en mode client
 ******************************************************************************************/
void setupBluetooth() // Initialisation du Bluetooth
{
  if (!SerialBT.begin("RobotLasagne_CLIENT", true)) {
    Serial.println("Erreur client!");
    while (1);
  }
}

/*******************************************************************************************
 * Auteur : Vincent
 * 
 * Établie la connexion bluetooth avec le périphérique "ESP32_Garfield"
 ******************************************************************************************/

void connexionBluetooth() // Connexion au périphérique Bluetooth "ESP32_Garfield"
{
  Serial.println("Robot B → Connexion à Robot A...");
  while (!SerialBT.connect("ESP32_Garfield")) {
    Serial.println("Tentative...");
    delay(1000);
  }
  Serial.println("Robot B connecté.");
}

/*******************************************************************************************
 * Auteur : Vincent
 * test si le Bluetooth est connecté et 
 * Établie la connexion bluetooth avec le périphérique "ESP32_Garfield" s'il n'est pas connecté
 ******************************************************************************************/
void testBluetooth() // Test de la connexion Bluetooth
{
  if (!SerialBT.connected()) {
    Serial.println("Bluetooth déconnecté, tentative de reconnexion...");
    connexionBluetooth();
  
  }
}






  

