#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "lwip/apps/mqtt.h"

uint32_t ultima_timestamp_recebida = 0;

void xor_encrypt(const uint8_t *input, uint8_t *output, size_t len, uint8_t key) {
    for (size_t i = 0; i < len; ++i) {
        output[i] = input[i] ^ key;
    }
}

void mqtt_incoming_publish_cb(void *arg, const char *topic, u32_t tot_len) {
    printf("Mensagem recebida no tópico: %s (len: %lu)\n", topic, tot_len);
}

void mqtt_incoming_data_cb(void *arg, const u8_t *data, u16_t len, u8_t flags) {
    char payload[128];

    if (len >= sizeof(payload)) len = sizeof(payload) - 1; // evita overflow
    memcpy(payload, data, len);
    payload[len] = '\0'; // garante que seja uma string

    printf("Conteúdo recebido: \"%s\"\n", payload);

    // Tenta converter a string para float
    float valor;
    if (sscanf(payload, "%f", &valor) == 1) {
        printf("Temperatura convertida: %.2f °C\n", valor);
    } else {
        printf("Erro no parse da mensagem!\n");
    }
}