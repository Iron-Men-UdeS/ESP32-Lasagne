#include <Arduino.h>
#include "BluetoothLasa.h"
#include "sPrint.h"
void setup() {
// Serial.begin(115200);
//   void setupBluetooth();
//   Serial.println("Robot Lasagne prêt (client).");
//   void connexionBluetooth();
// }

 Serial.begin(115200);
 setupBluetooth();
 connexionBluetooth();

  // if (!SerialBT.begin("RobotB_CLIENT", true)) {
  //   Serial.println("Erreur client!");
  //   while (1);
  // }

  // Serial.println("Robot B → Connexion à Robot A...");
  // while (!SerialBT.connect("ESP32_Garfield")) {
  //   Serial.println("Tentative...");
  //   delay(1000);
  // }
  // Serial.println("Robot B connecté.");

}


void loop() {
  positionEtEtat MonEtat = { 1.0f, 0.5f, 0, false }; // Exemple d'état de la lasagne à envoyer
 
  // Réception
  etat etatGarfield;
  
  if (recoieEtat(etatGarfield)) {
    printEtat(etatGarfield);
  //  Serial.print("État reçue : ");
  //   Serial.print(etatGarfield.etatJeu);
  //   Serial.print(", ");
  //   Serial.print(etatGarfield.GelerAutreRobot);
    envoieEtat(MonEtat);
    Serial.println("\nLasagne enyoyé position à Garfield.");

  }
   testBluetooth();
   
}

