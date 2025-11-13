#include "SerialArduino.h"


/*******************************************************************************************
 * Auteur : Alexandre Dionne
 *
 * Envoie une trame sur le port UART
 *
 * @param trame (Tableau uint8_t) Trame a evoyer
 ******************************************************************************************/
void envoieTrame(uint8_t *trame)
{
    uint8_t somme;
    for(int i = 0; i < (sizeof(trame)); i++)
    {
        somme = somme + trame[i];
    }
    Serial.write(0x24);
    Serial.write(trame, sizeof(trame));
    Serial.write(somme);
}

/*******************************************************************************************
 * Auteur : Alexandre Dionne
 *
 * Initialise le port UART de l'ESP32
 *
 ******************************************************************************************/
void initUart(void)
{
    Serial.begin(115200);
}