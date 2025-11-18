#include "BluetoothLasa.h"
#include "sPrint.h"

void printPosition (positionEtEtat printPos){ // Imprime la position reçue
    Serial.print("Position reçue : ");
    Serial.print(printPos.x);
    Serial.print(", ");
    Serial.print(printPos.y);
    Serial.print(", ");
    Serial.print(printPos.etatJeu);
    Serial.print(", ");
    Serial.print(printPos.GelerAutreRobot);
}

void printEtat (etat printEtat){ // Imprime l'état reçu
    Serial.print("État reçu : ");
    Serial.print(printEtat.etatJeu);
    Serial.print(", ");
    Serial.print(printEtat.GelerAutreRobot);
}