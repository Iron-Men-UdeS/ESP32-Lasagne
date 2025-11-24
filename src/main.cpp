#include <Arduino.h>
#include "BluetoothLasa.h"
#include "sPrint.h"
#include "comUART.h"


sPositionEtEtat MonEtat = { 1.0f, 0.5f, 0, false }; // Exemple d'état de la lasagne à envoyer
sEtat etatGarfield; // Structure pour recevoir l'état de Garfield

uint8_t tabGarfield[2]={0,0};
uint8_t tabLasagne[4]={0,0,0,0};

void setup() {
 Serial.begin(115200);
 setupBluetooth();
 connexionBluetooth();
}


void loop() {

  
  if (recoieEtat(tabGarfield)) {  //Enregistre l'état reçu dans la structure etatGarfield et envoie son état et position
    Serial.print("Etat reçu : ");
    Serial.print(tabGarfield[0]);
    Serial.print(", ");
    Serial.print(tabGarfield[1]);
    

    envoieEtat(tabLasagne);
    Serial.println("\nLasagne enyoyé position à Garfield.");

  }
   testBluetooth();

litUART(tabLasagne, sizeof(tabLasagne +2)); // lit la position de Garfield via UART
envoieTrame(tabGarfield); // envoie l'état de la lasagne via UART
Serial.print("Lecture de Lasagne via UART : ");
Serial.print(tabLasagne[0]);
Serial.print(", "); 
Serial.println(tabLasagne[1]);
Serial.print(", "); 
Serial.println(tabLasagne[2]);
Serial.print(", "); 
Serial.println(tabLasagne[3]);
Serial.println("Etat de Garfield transmise via UART");

}

