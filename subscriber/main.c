#include <stdio.h>
#include "pico/stdlib.h"
#include "../include/mqtt_comm.h"
#include "../include/xor_cipher.h"

void on_message(char topic, const uint8_t *data, uint16_t len) {
    uint8_t decifrado[32];  // Ajuste o tamanho conforme sua necessidade

    xor_encrypt(data, decifrado, len, 42);  // Chave deve ser a mesma do publisher

    decifrado[len] = '\0';  // Garante fim de string

    printf("Mensagem recebida decifrada: %s\n", decifrado);
}

int main() {
    stdio_init_all();
    sleep_ms(3000);  // Aguarde o monitor serial

    printf("Inicializando subscriber...\n");

    connect_wifi();  // já definida no mqtt_comm.c

    // Inicia o cliente MQTT e define o callback
    mqtt_start(on_message);

    while (true) {
        tight_loop_contents();  // Deixe o código rodando
    }

    return 0;
}
