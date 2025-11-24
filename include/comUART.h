#ifndef COMMUART_H
#define COMMUART_H

#include <Arduino.h>

    void litUART(uint8_t *trame, uint8_t sizeTrame);
    void initUART1(void);
    void envoieTrame(uint8_t *trame);

#endif
