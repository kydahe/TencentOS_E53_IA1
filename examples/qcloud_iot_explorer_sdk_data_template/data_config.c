/*-----------------data config start  -------------------*/ 
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#include "qcloud_iot_export.h"
#include "qcloud_iot_import.h"
#include "lite-utils.h"
#include "utils_timer.h"
#include "E53_IA1.h"
#include "tos_k.h"
#define TOTAL_PROPERTY_COUNT 5

static sDataPoint    sg_DataTemplate[TOTAL_PROPERTY_COUNT];

typedef struct _ProductDataDefine {
    TYPE_DEF_TEMPLATE_BOOL m_motor_power_switch;
    TYPE_DEF_TEMPLATE_BOOL m_light_power_switch;
    TYPE_DEF_TEMPLATE_INT m_luminance;
    TYPE_DEF_TEMPLATE_INT m_temperature;
	  TYPE_DEF_TEMPLATE_INT m_humidity;
} ProductDataDefine;

static   ProductDataDefine     sg_ProductData;
/*
static int read_brightness(void){
	  Init_E53_IA1();		
	  E53_IA1_Read_Data();	
	  return (int)E53_SC1_Data.Lux;
}*/

static void _init_data_template(void)
{
	  Init_E53_IA1();		
	  E53_IA1_Read_Data();	
	  
    sg_ProductData.m_motor_power_switch = 0;
    sg_DataTemplate[0].data_property.data = &sg_ProductData.m_motor_power_switch;
    sg_DataTemplate[0].data_property.key  = "motor_power_switch";
    sg_DataTemplate[0].data_property.type = TYPE_TEMPLATE_BOOL;
	
    sg_ProductData.m_light_power_switch = 0;
    sg_DataTemplate[1].data_property.data = &sg_ProductData.m_light_power_switch;
    sg_DataTemplate[1].data_property.key  = "light_power_switch";
    sg_DataTemplate[1].data_property.type = TYPE_TEMPLATE_BOOL;

    sg_ProductData.m_luminance = (int)E53_IA1_Data.Lux;
    sg_DataTemplate[2].data_property.data = &sg_ProductData.m_luminance;
    sg_DataTemplate[2].data_property.key  = "luminance";
    sg_DataTemplate[2].data_property.type = TYPE_TEMPLATE_INT;

    sg_ProductData.m_temperature = (int)E53_IA1_Data.Temperature;
    sg_DataTemplate[3].data_property.data = &sg_ProductData.m_temperature;
    sg_DataTemplate[3].data_property.key  = "temperature";
    sg_DataTemplate[3].data_property.type = TYPE_TEMPLATE_INT;
	
    sg_ProductData.m_humidity = (int)E53_IA1_Data.Humidity;
    sg_DataTemplate[4].data_property.data = &sg_ProductData.m_humidity;
    sg_DataTemplate[4].data_property.key  = "humidity";
    sg_DataTemplate[4].data_property.type = TYPE_TEMPLATE_INT;

};

/*
#define TOTAL_PROPERTY_COUNT 3

static sDataPoint    sg_DataTemplate[TOTAL_PROPERTY_COUNT];

typedef struct _ProductDataDefine {
    TYPE_DEF_TEMPLATE_BOOL m_beep;
    TYPE_DEF_TEMPLATE_FLOAT m_longtitude;
    TYPE_DEF_TEMPLATE_FLOAT m_latitude;
} ProductDataDefine;

static   ProductDataDefine     sg_ProductData;

//static E53_ST1_Data_TypeDef E53_ST1_Data;

static void read_location(float *longtitude, float *latitude){
	  Init_E53_ST1();	
		E53_ST1_Read_Data();
	  *longtitude = E53_ST1_Data.Longitude;
	  *latitude = E53_ST1_Data.Latitude;
}

static void _init_data_template(void)
{
    sg_ProductData.m_beep = 1;
    sg_DataTemplate[0].data_property.data = &sg_ProductData.m_beep;
    sg_DataTemplate[0].data_property.key  = "beep";
    sg_DataTemplate[0].data_property.type = TYPE_TEMPLATE_BOOL;

	  //Init_E53_ST1();	
		//E53_ST1_Read_Data();
	  sg_ProductData.m_longtitude = E53_ST1_Data.Longitude;
	  sg_ProductData.m_latitude = E53_ST1_Data.Latitude;
	  //read_location(&sg_ProductData.m_longtitude, &sg_ProductData.m_latitude);
    //sg_ProductData.m_color = 0;
    sg_DataTemplate[1].data_property.data = &sg_ProductData.m_longtitude;
    sg_DataTemplate[1].data_property.key  = "longitude";
    sg_DataTemplate[1].data_property.type = TYPE_TEMPLATE_FLOAT;

	  //sg_ProductData.m_brightness = 0;
    sg_DataTemplate[2].data_property.data = &sg_ProductData.m_latitude;
    sg_DataTemplate[2].data_property.key  = "latitude";
    sg_DataTemplate[2].data_property.type = TYPE_TEMPLATE_FLOAT;


};
*/
