#ifndef LWIPOPTS_H
#define LWIPOPTS_H

#define NO_SYS              1
#define LWIP_SOCKET         0
#define LWIP_NETCONN        0
#define LWIP_IPV4           1
#define LWIP_IPV6           0
#define LWIP_DNS            0
#define LWIP_ICMP           1
#define LWIP_TCP            1
#define LWIP_UDP            1
#define MEM_SIZE            1600
#define MEMP_NUM_SYS_TIMEOUT   (LWIP_NUM_SYS_TIMEOUT_INTERNAL + 1)
#define MQTT_REQ_MAX_IN_FLIGHT  (5)

#endif /* LWIPOPTS_H */
