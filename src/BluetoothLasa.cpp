#include "BluetoothLasa.h"


BluetoothSerial SerialBT;

/*******************************************************************************************
 * Auteur : Vincent
 * 
 * Envoie la position et l'état du robot sous forme de structure via Bluetooth
 *
 * @param sPositionEtEtat (structure) structure contenant la position (x,y) et l'état du robot
 ******************************************************************************************/

void envoieEtatStruct(const sPositionEtEtat &pos) { // Prend la reférence d'une structure Position en paramètre
  SerialBT.write((uint8_t*)&pos, sizeof(sPositionEtEtat)); 
}

/*******************************************************************************************
 * Auteur : Vincent
 * 
 * Lit la position et l'état du robot sous forme de structure via Bluetooth et la copie dans la structure passée en paramètre
 *
 * @param sEtat (structure) structure contenant l'état du robot
 ******************************************************************************************/
bool recoieEtatStruct(sEtat &pos) {
  if (SerialBT.available() >= sizeof(sEtat)) {
    SerialBT.readBytes((uint8_t*)&pos, sizeof(sEtat));
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
    //Serial.println("Bluetooth déconnecté, tentative de reconnexion...");
    connexionBluetooth();
  
  }
}


/*******************************************************************************************
 * Auteur : Vincent
 * 
 * Envoie la position et l'état du robot sous forme de tableau via Bluetooth
 *
 * @param tab tableau contenant la position (x,y) et l'état du robot
 ******************************************************************************************/

void envoieEtat(uint8_t *tab) { // Prend la reférence d'une structure Position en paramètre
  SerialBT.write(0x24); // Envoie le caractère '$' pour indiquer le début de la trame
  SerialBT.write(tab, sizeof(tab)); 
}


/*******************************************************************************************
 * Auteur : Vincent
 * 
 * Lit la position et l'état du robot sous forme de tableau via Bluetooth
 *
 * @param tab tableau dans lequel la position et l'état du robot seront copiés
 ******************************************************************************************/
bool recoieEtat(uint8_t *tab)
{
  if (SerialBT.available() >= sizeof(tab))
  {
    if (SerialBT.read() == 0x24)
    {
      SerialBT.readBytes(tab, sizeof(tab));
      return true;
    }
  }
  return false;
}


  

