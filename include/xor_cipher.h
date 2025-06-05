#ifndef XOR_CIPHER_H
#define XOR_CIPHER_H
#include <stdint.h>
#include <stddef.h>
#include "lwip/def.h"
void xor_encrypt(const uint8_t *input, uint8_t *output, size_t len, uint8_t key);
void mqtt_incoming_publish_cb(void *arg, const char *topic, u32_t tot_len);
void mqtt_incoming_data_cb(void *arg, const u8_t *data, u16_t len, u8_t flags);
#endif