# toolchain.cmake

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

# Caminho absoluto para o compilador
set(CMAKE_C_COMPILER "C:/Users/Lenovo/.pico-sdk/toolchain/13_3_Rel1/bin/arm-none-eabi-gcc.exe")
set(CMAKE_CXX_COMPILER "C:/Users/Lenovo/.pico-sdk/toolchain/13_3_Rel1/bin/arm-none-eabi-g++.exe")

# Opcional: especificar onde estão os utilitários extra
set(CMAKE_ASM_COMPILER ${CMAKE_C_COMPILER})

# Recomendado: para evitar mensagens do CMake sobre ambiente desconhecido
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)