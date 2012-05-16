%{
#include <stdio.h>
#include <string.h>
//gperf -C -p -a -n -D -t -o -j 1 -k 2,3 -N getPin pinMap.c
%}
struct pin {
char *name;
char *ID;
int gpio;
char *mux;
int eeprom;
char *pwm;
};
%%
P9_38, "AIN3", -1, NULL, 70, NULL
P9_39, "AIN0", -1, NULL, 67, NULL
P9_30, "SPI1_D1", 83, "mcasp0_axr0", 62, NULL
P9_31, "SPI1_SCLK", 81, "mcasp0_aclkx", 65, NULL
P9_32, "VDD_ADC", -1, NULL, -1, NULL
P9_33, "AIN4", -1, NULL, 71, NULL
P9_34, "GNDA_ADC", -1, NULL, -1, NULL
P9_35, "AIN6", -1, NULL, 73, NULL
P9_36, "AIN5", -1, NULL, 72, NULL
P9_37, "AIN2", -1, NULL, 69, NULL
P9_45, "DGND", -1, NULL, -1, NULL
P9_44, "DGND", -1, NULL, -1, NULL
P9_46, "DGND", -1, NULL, -1, NULL
P9_41, "CLKOUT2", 20, "xdma_event_intr1", 13, NULL
P9_40, "AIN1", -1, NULL, 68, NULL
P9_43, "DGND", -1, NULL, -1, NULL
P9_42, "GPIO0_7", 7, "ecap0_in_pwm0_out", 4, NULL
USR2, "USR2", 55, "gpmc_a7", -1, NULL
USR3, "USR3", 56, "gpmc_a8", -1, NULL
USR0, "USR0", 53, "gpmc_a5", -1, NULL
USR1, "USR1", 54, "gpmc_a6", -1, NULL
P8_19, "EHRPWM2A", 22, "gpmc_ad8", 14, NULL
P8_18, "GPIO2_1", 65, "gpmc_clk", 40, NULL
P8_11, "GPIO1_13", 45, "gpmc_ad13", 29, NULL
P8_10, "TIMER6", 68, "gpmc_wen", 43, NULL
P8_13, "EHRPWM2B", 23, "gpmc_ad9", 15, NULL
P8_12, "GPIO1_12", 44, "gpmc_ad12", 28, NULL
P8_15, "GPIO1_15", 47, "gpmc_ad15", 31, NULL
P8_14, "GPIO0_26", 26, "gpmc_ad10", 16, NULL
P8_17, "GPIO0_27", 27, "gpmc_ad11", 17, NULL
P8_16, "GPIO1_14", 46, "gpmc_ad14", 30, NULL
P8_37, "UART5_TXD", 78, "lcd_data8", 53, NULL
P8_36, "UART3_CTSN", 80, "lcd_data10", 55, NULL
P8_35, "UART4_CTSN", 8, "lcd_data12", 5, NULL
P8_34, "UART3_RTSN", 81, "lcd_data11", 56, NULL
P8_33, "UART4_RTSN", 9, "lcd_data13", 6, NULL
P8_32, "UART5_RTSN", 11, "lcd_data15", 8, NULL
P8_31, "UART5_CTSN", 10, "lcd_data14", 7, NULL
P8_30, "GPIO2_25", 89, "lcd_ac_bias_en", 60, NULL
P8_39, "GPIO2_12", 76, "lcd_data6", 51, NULL
P8_38, "UART5_RXD", 79, "lcd_data9", 54, NULL
P8_20, "GPIO1_31", 63, "gpmc_csn2", 39, NULL
P8_21, "GPIO1_30", 62, "gpmc_csn1", 38, NULL
P8_22, "GPIO1_5", 37, "gpmc_ad5", 25, NULL
P8_23, "GPIO1_4", 36, "gpmc_ad4", 24, NULL
P8_24, "GPIO1_1", 33, "gpmc_ad1", 21, NULL
P8_25, "GPIO1_0", 32, "gpmc_ad0", 20, NULL
P8_26, "GPIO1_29", 61, "gpmc_csn0", 37, NULL
P8_27, "GPIO2_22", 86, "lcd_vsync", 57, NULL
P8_28, "GPIO2_24", 88, "lcd_pclk", 59, NULL
P8_29, "GPIO2_23", 87, "lcd_hsync", 58, NULL
P9_8, "SYS_5V", -1, NULL, -1, NULL
P9_9, "PWR_BUT", -1, NULL, -1, NULL
P9_1, "DGND", -1, NULL, -1, NULL
P9_2, "DGND", -1, NULL, -1, NULL
P9_3, "VDD_3V3", -1, NULL, -1, NULL
P9_4, "VDD_3V3", -1, NULL, -1, NULL
P9_5, "VDD_5V", -1, NULL, -1, NULL
P9_6, "VDD_5V", -1, NULL, -1, NULL
P9_7, "SYS_5V", -1, NULL, -1, NULL
P9_12, "GPIO1_28", 60, "gpmc_ben1", 36, NULL
P9_13, "UART4_TXD", 31, "gpmc_wpn", 19, NULL
P9_10, "SYS_RESETn", -1, NULL, -1, NULL
P9_11, "UART4_RXD", 30, "gpmc_wait0", 18, NULL
P9_16, "EHRPWM1B", 51, "gpmc_a3", 35, "ehrpwm.1:1"
P9_17, "I2C1_SCL", 5, "spi0_cs0", 3, NULL
P9_14, "EHRPWM1A", 50, "gpmc_a2", 34, "ehrpwm.1:0"
P9_15, "GPIO1_16", 48, "gpmc_a0", 32, NULL
P9_18, "I2C1_SDA", 4, "spi0_d1", 2, NULL
P9_19, "I2C2_SCL", 13, "uart1_rtsn", 9, NULL
P9_29, "SPI1_D0", 82, "mcasp0_fsx", 61, NULL
P9_28, "SPI1_CS0", 84, "mcasp0_ahclkr", 63, NULL
P9_27, "GPIO3_19", 86, "mcasp0_fsr", 64, NULL
P9_26, "UART1_RXD", 14, "uart1_rxd", 11, NULL
P9_25, "GPIO3_21", 88, "mcasp0_ahclkx", 66, NULL
P9_24, "UART1_TXD", 15, "uart1_txd", 12, NULL
P9_23, "GPIO1_17", 49, "gpmc_a1", 33, NULL
P9_22, "UART2_RXD", 2, "spi0_sclk", 0, NULL
P9_21, "UART2_TXD", 3, "spi0_d0", 1, NULL
P9_20, "I2C2_SDA", 12, "uart1_ctsn", 10, NULL
P8_46, "GPIO2_7", 71, "lcd_data1", 46, NULL
P8_44, "GPIO2_9", 73, "lcd_data3", 48, NULL
P8_45, "GPIO2_6", 70, "lcd_data0", 45, NULL
P8_42, "GPIO2_11", 75, "lcd_data5", 50, NULL
P8_43, "GPIO2_8", 72, "lcd_data2", 47, NULL
P8_40, "GPIO2_13", 77, "lcd_data7", 52, NULL
P8_41, "GPIO2_10", 74, "lcd_data4", 49, NULL
P8_1, "DGND", -1, NULL, -1, NULL
P8_3, "GPIO1_6", 38, "gpmc_ad6", 26, NULL
P8_2, "DGND", -1, NULL, -1, NULL
P8_5, "GPIO1_2", 34, "gpmc_ad2", 22, NULL
P8_4, "GPIO1_7", 39, "gpmc_ad7", 27, NULL
P8_7, "TIMER4", 66, "gpmc_advn_ale", 41, NULL
P8_6, "GPIO1_3", 35, "gpmc_ad3", 23, NULL
P8_9, "TIMER5", 69, "gpmc_ben0_cle", 42, NULL
P8_8, "TIMER7", 67, "gpmc_oen_ren", 44, NULL
%%
