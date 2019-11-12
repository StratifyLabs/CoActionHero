cmake_minimum_required (VERSION 3.6)

if( ${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Darwin" )
  set(SOS_TOOLCHAIN_CMAKE_PATH /Applications/StratifyLabs-SDK/Tools/gcc/arm-none-eabi/cmake)
endif()
if( ${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Windows" )
	set(SOS_TOOLCHAIN_CMAKE_PATH C:/StratifyLabs-SDK/Tools/gcc/arm-none-eabi/cmake)
endif()
set(CMAKE_TOOLCHAIN_FILE ${SOS_TOOLCHAIN_CMAKE_PATH}/sos-bsp-toolchain.cmake)
include(${SOS_TOOLCHAIN_CMAKE_PATH}/sos-variables.cmake)

get_filename_component(SOS_NAME ${CMAKE_SOURCE_DIR} NAME)
project(${SOS_NAME} CXX C)

#Add sources to the project
set(SOURCES_PREFIX ${CMAKE_SOURCE_DIR}/src)
add_subdirectory(src)
list(APPEND SOS_KERNEL_SOURCELIST ${SOURCES} sl_settings.json)

#Change to boot sources
set(SOURCES "")
set(SOURCES_PREFIX ${CMAKE_SOURCE_DIR}/boot)
add_subdirectory(boot)
list(APPEND SOS_BOOT_SOURCELIST ${SOURCES})

set(SOS_ARCH v7m)
set(SOS_DEVICE lpc1759)
set(SOS_DEVICE_FAMILY lpc17xx)
set(SOS_HARDWARD_ID 0x00000001)
set(SOS_LIBRARIES jansson_kernel)

set(SOS_KERNEL_START_ADDRESS 0x40000)
set(SOS_BOOT_START_ADDRESS 0x0)
include(${SOS_TOOLCHAIN_CMAKE_PATH}/sos-bsp-std.cmake)
