cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(subscriber C CXX ASM)

add_executable(subscriber main.c 
    ../src/mqtt_comm.c
    ../src/wifi_conn.c
    ../src/xor_cipher.c
)

pico_set_program_name(subscriber "subscriber")
pico_set_program_version(subscriber "0.1")

pico_enable_stdio_uart(subscriber 0)
pico_enable_stdio_usb(subscriber 1)

target_link_libraries(subscriber
        pico_stdlib
        pico_cyw43_arch_lwip_threadsafe_background
        pico_lwip_mqtt
        pico_lwip
        pico_cyw43_driver
)

target_include_directories(subscriber PRIVATE
        ../src/include
)

pico_add_extra_outputs(subscriber)
