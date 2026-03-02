#
# CMakeLists.txt
#
#  Created on: 02 mar. 2026
#      Author: Ludo
#

# Minimum CMake version.
cmake_minimum_required(VERSION 3.23)

# Project creation.
project(dinfox-registers)

# Build mode.
if(NOT DEFINED BUILD_MODE)
    set(BUILD_MODE "STATIC")
endif()

# Create library.
add_library(${PROJECT_NAME} ${BUILD_MODE})

# Static library.
if(${BUILD_MODE} STREQUAL STATIC)

    # Macro to convert options to variables.
    macro(add_compilation_flag FLAG_NAME FLAG_DESCRIPTION FLAG_DEFAULT_VALUE)
        option(FLAG_NAME FLAG_DESCRIPTION FLAG_DEFAULT_VALUE)
        set(${FLAG_NAME} ${FLAG_DEFAULT_VALUE} CACHE STRING ${FLAG_DESCRIPTION})
        list(APPEND COMPILATION_FLAGS_LIST ${FLAG_NAME})
    endmacro()
    
    # Compilation flags.
    add_compilation_flag(DINFOX_REGISTERS_DEFAULT_TIMEOUT_MS "Default registers access timeout in milliseconds." 200)
    
    # Remove OFF flags from list and keep flags set to value 0.
    foreach(FLAG ${COMPILATION_FLAGS_LIST})
        if((NOT ${FLAG} STREQUAL OFF) AND (NOT ${FLAG} STREQUAL ON))
            set(${FLAG} "(${${FLAG}})")
        endif()
    endforeach()   
    
    # Create flags file.
    configure_file(dinfox_registers_flags.h.in dinfox_registers_flags.h @ONLY)
    
    # Fixed compilation flags of dependencies.
    if(${BUILD_MODE} STREQUAL STATIC)
        target_compile_definitions(${PROJECT_NAME}
            PRIVATE
                EMBEDDED_UTILS_DISABLE_FLAGS_FILE
                UNA_LIB_DISABLE_FLAGS_FILE
        )
    endif()
    
    # Dependencies folders.
    target_include_directories(${PROJECT_NAME}
        PUBLIC
            ${CMAKE_CURRENT_BINARY_DIR}
            ${TYPES_PATH}
            ${EMBEDDED_UTILS_PATH}/inc
            ${UNA_LIB_PATH}/inc
    )
    
    # Print archive size.
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD 
        COMMAND ${CMAKE_SIZE_UTIL} -t lib${PROJECT_NAME}.a
    )
    
endif()

# Source files list.
target_sources(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/bcm_registers.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/bpsm_registers.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/ddrm_registers.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/dmm_registers.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/gpsm_registers.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/lvrm_registers.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/mpmcm_registers.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/rrm_registers.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/sm_registers.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/uhfm_registers.c
)

# Header files folder.
target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/inc
)