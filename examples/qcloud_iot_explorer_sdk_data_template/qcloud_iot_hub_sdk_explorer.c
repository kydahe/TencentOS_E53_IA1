#include "tos_k.h"
//#include "bc35_28_95_lwm2m.h"
#include "mcu_init.h"
#include "sal_module_wrapper.h"
#include "cmsis_os.h"

/* 用户根据自己的底层通信链路来配置此宏
 * 如果是基于以太网lwip的链路，这里应该定义 USE_LWIP
 * 如果是基于模组的通信链路，这里应该定义相应的模组宏，如使用ESP8266则定义 USE_ESP8266
 * */
#define USE_ESP8266

#ifdef USE_LWIP
#include "lwip/api.h"
#include "lwip/sockets.h"
#include "lwip/err.h"
#include "lwip/sys.h"
#endif

#ifdef USE_ESP8266
#include "esp8266.h"
#endif
int socket_id = 1;
void application_entry(void *arg)
{
#ifdef USE_LWIP
    dns_init();
    MX_LWIP_Init();
#endif

#ifdef USE_ESP8266
    extern int esp8266_sal_init(hal_uart_port_t uart_port);
    extern int esp8266_join_ap(const char *ssid, const char *pwd);
    esp8266_sal_init(HAL_UART_PORT_0);
    esp8266_join_ap("xxxx", "xxxxx"); //need to modify
#endif

#ifdef USE_NB_BC35
    extern int bc35_28_95_sal_lwm2m_init(hal_uart_port_t uart_port);
    bc35_28_95_sal_lwm2m_init(HAL_UART_PORT_0);
	  //socket_id = tos_sal_module_connect("49.4.85.232","5683",TOS_SAL_PROTO_UDP);
	  socket_id = tos_sal_module_connect("111.230.127.136", "5684", TOS_SAL_PROTO_UDP);
    if(socket_id !=-1){
        printf("connect to cloud success! fd: %d\n", socket_id);	
    }
	  else{
        printf("connect to cloud failed!\n");
	  }
#endif

    data_template_light_thread();

    while (1) {
        printf("This is a tencent cloud sdk data template demo!\r\n");
        tos_task_delay(1000);
    }
}

