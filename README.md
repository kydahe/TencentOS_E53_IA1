# TencentOS_E53_IA1

2020/04/22 

## 基于TencentOS的智能环境监测系统


1 使用keil打开
 TencentOS_E53_IA1/board/TencentOS_tiny_EVB_MX/KEIL/qcloud_iot_explorer_sdk_data_template/TencentOS_tiny.uvprojx 

2 修改qcloud_iot_hub_sdk_exlorer.c中的WiFi信息（name, password）

3 修改HAL_Device_tencentos_tiny.c中的产品信息和设备信息（product ID、device name、device secret）

4 编译烧录
