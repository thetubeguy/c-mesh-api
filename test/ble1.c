#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define LOG_MODULE_NAME "Test"
#define MAX_LOG_LEVEL INFO_LOG_LEVEL
#include "logger.h"

#include "wpc.h"



/*static bool setInitialState(app_role_t role,
                            app_addr_t id,
                            net_addr_t network_add,
                            net_channel_t network_channel,
                            bool start)
{

    
    WPC_stop_stack();
    // Wait for stack to stop
    usleep(3 * 1000 * 1000);

    if (WPC_set_node_address(id) != APP_RES_OK)
        return false;

    if (WPC_set_role(role) != APP_RES_OK)
        return false;

    if (WPC_set_network_address(network_add) != APP_RES_OK)
        return false;

    if (WPC_set_network_channel(network_channel) != APP_RES_OK)
        return false;

    if (start && (WPC_start_stack() != APP_RES_OK))
        return false;

    return true;
}*/

int main(){

	char * port_name = "/dev/serial/by-id/usb-FTDI_2611086021011_WE_USB_Plug_82001112-if00-port0";
	unsigned long bitrate = DEFAULT_BITRATE;

	if (WPC_initialize(port_name, bitrate) != APP_RES_OK)
        	return -1;
    
//	if(setInitialState(APP_ROLE_SINK,25,7,39,1) != APP_RES_OK)
//		return -1;
		
	const unsigned char data[] = {0x61,0x62,0x63,0x64,0x65};
		
	WPC_send_data(data, 0x05, 0xaa, 0x02, 0x01, 0x01, 0x01, NULL, 0);
	return 0;
}
