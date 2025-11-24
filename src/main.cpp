#include <Arduino.h>
#include "BluetoothLasa.h"
#include "sPrint.h"


positionEtEtat MonEtat = { 1.0f, 0.5f, 0, false }; // Exemple d'état de la lasagne à envoyer
 
  
etat etatGarfield; // Structure pour recevoir l'état de Garfield

void setup() {
 Serial.begin(115200);
 setupBluetooth();
 connexionBluetooth();
}


void loop() {

  
  if (recoieEtat(etatGarfield)) {  //Enregistre l'état reçu dans la structure etatGarfield et envoie son état et position
    printEtat(etatGarfield);

    envoieEtat(MonEtat);
    Serial.println("\nLasagne enyoyé position à Garfield.");

  }
   testBluetooth();
   
}

