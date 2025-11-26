#include "BluetoothLasa.h"
#include "sPrint.h"

/*******************************************************************************************
 * Auteur : Vincent
 * 
 * Imprime la position et l'état reçue
 ******************************************************************************************/

void printPosition (sPositionEtEtat printPos){ // Imprime la position reçue
    Serial.print("Position reçue : ");
    Serial.print(printPos.x);
    Serial.print(", ");
    Serial.print(printPos.y);
    Serial.print(", ");
    Serial.print(printPos.etatJeu);
    Serial.print(", ");
    Serial.print(printPos.GelerAutreRobot);
}


/*******************************************************************************************
 * Auteur : Vincent
 * 
 * Imprime la l'état reçu
 ******************************************************************************************/
void printEtat (sEtat printEtat){ // Imprime l'état reçu
    Serial.print("État reçu : ");
    Serial.print(printEtat.etatJeu);
    Serial.print(", ");
    Serial.print(printEtat.GelerAutreRobot);
}