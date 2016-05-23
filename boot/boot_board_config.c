/*
 * bootloader_board_config.c
 *
 *  Created on: Apr 21, 2016
 *      Author: tgil
 */


#include <mcu/types.h>
#include <mcu/core.h>
#include <iface/dev/bootloader.h>

#include "link_transport.h"
#include "board_config.h"

const u32 _mcu_crp_value __attribute__ ((section(".crp_section"))) = 0x87654321;

#define STFY_SYSTEM_CLOCK 72000000
#define STFY_SYSTEM_OSC 12000000

const mcu_board_config_t mcu_board_config = {
		.core_osc_freq = STFY_SYSTEM_OSC,
		.core_cpu_freq = STFY_SYSTEM_CLOCK,
		.core_periph_freq = STFY_SYSTEM_CLOCK,
		.usb_max_packet_zero = MCU_CORE_USB_MAX_PACKET_ZERO_VALUE,
		.led.port = 2, .led.pin = 10
};

const bootloader_board_config_t boot_board_config = {
		.sw_req_loc = 0x10002000,
		.sw_req_value = 0x55AA55AA,
		.program_start_addr = 0x40000,
		.hw_req.port = 0, .hw_req.pin = 1,
		.flags = BOOT_BOARD_CONFIG_FLAG_LED_ACTIVE_HIGH,
		.link_transport_driver = &link_transport,
		.id = 1,
		.event = 0
};


extern void boot_main();

void _main(void){
	boot_main();
}
