/* C code produced by gperf version 3.0.3 */
/* Command-line: gperf -C -p -a -n -D -t -o -j 1 -k 2,3 -N getPin pinMap.h  */

#if !((' ' == 32) && ('!' == 33) && ('"' == 34) && ('#' == 35) \
      && ('%' == 37) && ('&' == 38) && ('\'' == 39) && ('(' == 40) \
      && (')' == 41) && ('*' == 42) && ('+' == 43) && (',' == 44) \
      && ('-' == 45) && ('.' == 46) && ('/' == 47) && ('0' == 48) \
      && ('1' == 49) && ('2' == 50) && ('3' == 51) && ('4' == 52) \
      && ('5' == 53) && ('6' == 54) && ('7' == 55) && ('8' == 56) \
      && ('9' == 57) && (':' == 58) && (';' == 59) && ('<' == 60) \
      && ('=' == 61) && ('>' == 62) && ('?' == 63) && ('A' == 65) \
      && ('B' == 66) && ('C' == 67) && ('D' == 68) && ('E' == 69) \
      && ('F' == 70) && ('G' == 71) && ('H' == 72) && ('I' == 73) \
      && ('J' == 74) && ('K' == 75) && ('L' == 76) && ('M' == 77) \
      && ('N' == 78) && ('O' == 79) && ('P' == 80) && ('Q' == 81) \
      && ('R' == 82) && ('S' == 83) && ('T' == 84) && ('U' == 85) \
      && ('V' == 86) && ('W' == 87) && ('X' == 88) && ('Y' == 89) \
      && ('Z' == 90) && ('[' == 91) && ('\\' == 92) && (']' == 93) \
      && ('^' == 94) && ('_' == 95) && ('a' == 97) && ('b' == 98) \
      && ('c' == 99) && ('d' == 100) && ('e' == 101) && ('f' == 102) \
      && ('g' == 103) && ('h' == 104) && ('i' == 105) && ('j' == 106) \
      && ('k' == 107) && ('l' == 108) && ('m' == 109) && ('n' == 110) \
      && ('o' == 111) && ('p' == 112) && ('q' == 113) && ('r' == 114) \
      && ('s' == 115) && ('t' == 116) && ('u' == 117) && ('v' == 118) \
      && ('w' == 119) && ('x' == 120) && ('y' == 121) && ('z' == 122) \
      && ('{' == 123) && ('|' == 124) && ('}' == 125) && ('~' == 126))
/* The character set is not based on ISO-646.  */
error "gperf generated tables don't work with this execution character set. Please report a bug to <bug-gnu-gperf@gnu.org>."
#endif

#line 1 "pinMap.h"

#include <stdio.h>
#include <string.h>
//gperf -C -p -a -n -D -t -o -j 1 -k 2,3 -N getPin pinMap.c
#line 6 "pinMap.h"
struct pin {
char *name;
char *ID;
int gpio;
char *mux;
int eeprom;
char *pwm;
};

#define TOTAL_KEYWORDS 96
#define MIN_WORD_LENGTH 4
#define MAX_WORD_LENGTH 5
#define MIN_HASH_VALUE 0
#define MAX_HASH_VALUE 2
/* maximum key range = 3, duplicates = 93 */

#ifdef __GNUC__
__inline
#else
#ifdef __cplusplus
inline
#endif
#endif
/*ARGSUSED*/
static unsigned int
hash (str, len)
     register const char *str;
     register unsigned int len;
{
  static const unsigned char asso_values[] =
    {
      3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
      3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
      3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
      3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
      3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
      3, 3, 3, 3, 3, 3, 2, 1, 3, 3,
      3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
      3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
      3, 3, 0, 0, 3, 3, 3, 3, 3, 3,
      3, 3, 3, 3, 3, 0, 3, 3, 3, 3,
      3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
      3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
      3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
      3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
      3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
      3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
      3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
      3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
      3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
      3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
      3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
      3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
      3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
      3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
      3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
      3, 3, 3, 3, 3, 3
    };
  return asso_values[(unsigned char)str[2]] + asso_values[(unsigned char)str[1]];
}

#ifdef __GNUC__
__inline
#ifdef __GNUC_STDC_INLINE__
__attribute__ ((__gnu_inline__))
#endif
#endif
const struct pin *
getPin (str, len)
     register const char *str;
     register unsigned int len;
{
  static const struct pin wordlist[] =
    {
#line 32 "pinMap.h"
      {"USR2", "USR2", 55, "gpmc_a7", -1, NULL},
#line 35 "pinMap.h"
      {"USR1", "USR1", 54, "gpmc_a6", -1, NULL},
#line 34 "pinMap.h"
      {"USR0", "USR0", 53, "gpmc_a5", -1, NULL},
#line 33 "pinMap.h"
      {"USR3", "USR3", 56, "gpmc_a8", -1, NULL},
#line 15 "pinMap.h"
      {"P9_38", "AIN3", -1, NULL, 70, NULL},
#line 94 "pinMap.h"
      {"P9_20", "I2C2_SDA", 12, "uart1_ctsn", 10, NULL},
#line 93 "pinMap.h"
      {"P9_21", "UART2_TXD", 3, "spi0_d0", 1, NULL},
#line 92 "pinMap.h"
      {"P9_22", "UART2_RXD", 2, "spi0_sclk", 0, NULL},
#line 91 "pinMap.h"
      {"P9_23", "GPIO1_17", 49, "gpmc_a1", 33, NULL},
#line 90 "pinMap.h"
      {"P9_24", "UART1_TXD", 15, "uart1_txd", 12, NULL},
#line 89 "pinMap.h"
      {"P9_25", "GPIO3_21", 88, "mcasp0_ahclkx", 66, NULL},
#line 88 "pinMap.h"
      {"P9_26", "UART1_RXD", 14, "uart1_rxd", 11, NULL},
#line 87 "pinMap.h"
      {"P9_27", "GPIO3_19", 86, "mcasp0_fsr", 64, NULL},
#line 86 "pinMap.h"
      {"P9_28", "SPI1_CS0", 84, "mcasp0_ahclkr", 63, NULL},
#line 85 "pinMap.h"
      {"P9_29", "SPI1_D0", 82, "mcasp0_fsx", 61, NULL},
#line 84 "pinMap.h"
      {"P9_19", "I2C2_SCL", 13, "uart1_rtsn", 9, NULL},
#line 83 "pinMap.h"
      {"P9_18", "I2C1_SDA", 4, "spi0_d1", 2, NULL},
#line 82 "pinMap.h"
      {"P9_15", "GPIO1_16", 48, "gpmc_a0", 32, NULL},
#line 81 "pinMap.h"
      {"P9_14", "EHRPWM1A", 50, "gpmc_a2", 34, "ehrpwm.1:0"},
#line 80 "pinMap.h"
      {"P9_17", "I2C1_SCL", 5, "spi0_cs0", 3, NULL},
#line 79 "pinMap.h"
      {"P9_16", "EHRPWM1B", 51, "gpmc_a3", 35, "ehrpwm.1:1"},
#line 78 "pinMap.h"
      {"P9_11", "UART4_RXD", 30, "gpmc_wait0", 18, NULL},
#line 77 "pinMap.h"
      {"P9_10", "SYS_RESETn", -1, NULL, -1, NULL},
#line 76 "pinMap.h"
      {"P9_13", "UART4_TXD", 31, "gpmc_wpn", 19, NULL},
#line 75 "pinMap.h"
      {"P9_12", "GPIO1_28", 60, "gpmc_ben1", 36, NULL},
#line 74 "pinMap.h"
      {"P9_7", "SYS_5V", -1, NULL, -1, NULL},
#line 73 "pinMap.h"
      {"P9_6", "VDD_5V", -1, NULL, -1, NULL},
#line 72 "pinMap.h"
      {"P9_5", "VDD_5V", -1, NULL, -1, NULL},
#line 71 "pinMap.h"
      {"P9_4", "VDD_3V3", -1, NULL, -1, NULL},
#line 70 "pinMap.h"
      {"P9_3", "VDD_3V3", -1, NULL, -1, NULL},
#line 69 "pinMap.h"
      {"P9_2", "DGND", -1, NULL, -1, NULL},
#line 68 "pinMap.h"
      {"P9_1", "DGND", -1, NULL, -1, NULL},
#line 67 "pinMap.h"
      {"P9_9", "PWR_BUT", -1, NULL, -1, NULL},
#line 66 "pinMap.h"
      {"P9_8", "SYS_5V", -1, NULL, -1, NULL},
#line 31 "pinMap.h"
      {"P9_42", "GPIO0_7", 7, "ecap0_in_pwm0_out", 4, NULL},
#line 30 "pinMap.h"
      {"P9_43", "DGND", -1, NULL, -1, NULL},
#line 29 "pinMap.h"
      {"P9_40", "AIN1", -1, NULL, 68, NULL},
#line 28 "pinMap.h"
      {"P9_41", "CLKOUT2", 20, "xdma_event_intr1", 13, NULL},
#line 27 "pinMap.h"
      {"P9_46", "DGND", -1, NULL, -1, NULL},
#line 26 "pinMap.h"
      {"P9_44", "DGND", -1, NULL, -1, NULL},
#line 25 "pinMap.h"
      {"P9_45", "DGND", -1, NULL, -1, NULL},
#line 24 "pinMap.h"
      {"P9_37", "AIN2", -1, NULL, 69, NULL},
#line 23 "pinMap.h"
      {"P9_36", "AIN5", -1, NULL, 72, NULL},
#line 22 "pinMap.h"
      {"P9_35", "AIN6", -1, NULL, 73, NULL},
#line 21 "pinMap.h"
      {"P9_34", "GNDA_ADC", -1, NULL, -1, NULL},
#line 20 "pinMap.h"
      {"P9_33", "AIN4", -1, NULL, 71, NULL},
#line 19 "pinMap.h"
      {"P9_32", "VDD_ADC", -1, NULL, -1, NULL},
#line 18 "pinMap.h"
      {"P9_31", "SPI1_SCLK", 81, "mcasp0_aclkx", 65, NULL},
#line 17 "pinMap.h"
      {"P9_30", "SPI1_D1", 83, "mcasp0_axr0", 62, NULL},
#line 16 "pinMap.h"
      {"P9_39", "AIN0", -1, NULL, 67, NULL},
#line 36 "pinMap.h"
      {"P8_19", "EHRPWM2A", 22, "gpmc_ad8", 14, NULL},
#line 110 "pinMap.h"
      {"P8_8", "TIMER7", 67, "gpmc_oen_ren", 44, NULL},
#line 109 "pinMap.h"
      {"P8_9", "TIMER5", 69, "gpmc_ben0_cle", 42, NULL},
#line 108 "pinMap.h"
      {"P8_6", "GPIO1_3", 35, "gpmc_ad3", 23, NULL},
#line 107 "pinMap.h"
      {"P8_7", "TIMER4", 66, "gpmc_advn_ale", 41, NULL},
#line 106 "pinMap.h"
      {"P8_4", "GPIO1_7", 39, "gpmc_ad7", 27, NULL},
#line 105 "pinMap.h"
      {"P8_5", "GPIO1_2", 34, "gpmc_ad2", 22, NULL},
#line 104 "pinMap.h"
      {"P8_2", "DGND", -1, NULL, -1, NULL},
#line 103 "pinMap.h"
      {"P8_3", "GPIO1_6", 38, "gpmc_ad6", 26, NULL},
#line 102 "pinMap.h"
      {"P8_1", "DGND", -1, NULL, -1, NULL},
#line 101 "pinMap.h"
      {"P8_41", "GPIO2_10", 74, "lcd_data4", 49, NULL},
#line 100 "pinMap.h"
      {"P8_40", "GPIO2_13", 77, "lcd_data7", 52, NULL},
#line 99 "pinMap.h"
      {"P8_43", "GPIO2_8", 72, "lcd_data2", 47, NULL},
#line 98 "pinMap.h"
      {"P8_42", "GPIO2_11", 75, "lcd_data5", 50, NULL},
#line 97 "pinMap.h"
      {"P8_45", "GPIO2_6", 70, "lcd_data0", 45, NULL},
#line 96 "pinMap.h"
      {"P8_44", "GPIO2_9", 73, "lcd_data3", 48, NULL},
#line 95 "pinMap.h"
      {"P8_46", "GPIO2_7", 71, "lcd_data1", 46, NULL},
#line 65 "pinMap.h"
      {"P8_29", "GPIO2_23", 87, "lcd_hsync", 58, NULL},
#line 64 "pinMap.h"
      {"P8_28", "GPIO2_24", 88, "lcd_pclk", 59, NULL},
#line 63 "pinMap.h"
      {"P8_27", "GPIO2_22", 86, "lcd_vsync", 57, NULL},
#line 62 "pinMap.h"
      {"P8_26", "GPIO1_29", 61, "gpmc_csn0", 37, NULL},
#line 61 "pinMap.h"
      {"P8_25", "GPIO1_0", 32, "gpmc_ad0", 20, NULL},
#line 60 "pinMap.h"
      {"P8_24", "GPIO1_1", 33, "gpmc_ad1", 21, NULL},
#line 59 "pinMap.h"
      {"P8_23", "GPIO1_4", 36, "gpmc_ad4", 24, NULL},
#line 58 "pinMap.h"
      {"P8_22", "GPIO1_5", 37, "gpmc_ad5", 25, NULL},
#line 57 "pinMap.h"
      {"P8_21", "GPIO1_30", 62, "gpmc_csn1", 38, NULL},
#line 56 "pinMap.h"
      {"P8_20", "GPIO1_31", 63, "gpmc_csn2", 39, NULL},
#line 55 "pinMap.h"
      {"P8_38", "UART5_RXD", 79, "lcd_data9", 54, NULL},
#line 54 "pinMap.h"
      {"P8_39", "GPIO2_12", 76, "lcd_data6", 51, NULL},
#line 53 "pinMap.h"
      {"P8_30", "GPIO2_25", 89, "lcd_ac_bias_en", 60, NULL},
#line 52 "pinMap.h"
      {"P8_31", "UART5_CTSN", 10, "lcd_data14", 7, NULL},
#line 51 "pinMap.h"
      {"P8_32", "UART5_RTSN", 11, "lcd_data15", 8, NULL},
#line 50 "pinMap.h"
      {"P8_33", "UART4_RTSN", 9, "lcd_data13", 6, NULL},
#line 49 "pinMap.h"
      {"P8_34", "UART3_RTSN", 81, "lcd_data11", 56, NULL},
#line 48 "pinMap.h"
      {"P8_35", "UART4_CTSN", 8, "lcd_data12", 5, NULL},
#line 47 "pinMap.h"
      {"P8_36", "UART3_CTSN", 80, "lcd_data10", 55, NULL},
#line 46 "pinMap.h"
      {"P8_37", "UART5_TXD", 78, "lcd_data8", 53, NULL},
#line 45 "pinMap.h"
      {"P8_16", "GPIO1_14", 46, "gpmc_ad14", 30, NULL},
#line 44 "pinMap.h"
      {"P8_17", "GPIO0_27", 27, "gpmc_ad11", 17, NULL},
#line 43 "pinMap.h"
      {"P8_14", "GPIO0_26", 26, "gpmc_ad10", 16, NULL},
#line 42 "pinMap.h"
      {"P8_15", "GPIO1_15", 47, "gpmc_ad15", 31, NULL},
#line 41 "pinMap.h"
      {"P8_12", "GPIO1_12", 44, "gpmc_ad12", 28, NULL},
#line 40 "pinMap.h"
      {"P8_13", "EHRPWM2B", 23, "gpmc_ad9", 15, NULL},
#line 39 "pinMap.h"
      {"P8_10", "TIMER6", 68, "gpmc_wen", 43, NULL},
#line 38 "pinMap.h"
      {"P8_11", "GPIO1_13", 45, "gpmc_ad13", 29, NULL},
#line 37 "pinMap.h"
      {"P8_18", "GPIO2_1", 65, "gpmc_clk", 40, NULL}
    };

  static const short lookup[] =
    {
      -104, -102, -100,  -46,  -46,  -92,  -46,  -96,
        -4
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      register int key = hash (str, len);

      if (key <= MAX_HASH_VALUE && key >= 0)
        {
          register int index = lookup[key];

          if (index >= 0)
            {
              register const char *s = wordlist[index].name;

              if (*str == *s && !strcmp (str + 1, s + 1))
                return &wordlist[index];
            }
          else if (index < -TOTAL_KEYWORDS)
            {
              register int offset = - 1 - TOTAL_KEYWORDS - index;
              register const struct pin *wordptr = &wordlist[TOTAL_KEYWORDS + lookup[offset]];
              register const struct pin *wordendptr = wordptr + -lookup[offset + 1];

              while (wordptr < wordendptr)
                {
                  register const char *s = wordptr->name;

                  if (*str == *s && !strcmp (str + 1, s + 1))
                    return wordptr;
                  wordptr++;
                }
            }
        }
    }
  return 0;
}
#line 111 "pinMap.h"

