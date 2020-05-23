#ifndef OLED_H
#define OLED_H
#include <stdint.h>
#include <stdio.h>
#include "stm32f0xx_hal.h"

/**********修改端口和引脚***********/
#define SCLK_GPIO_PORT GPIOA
#define SCLK_GPIO_PIN GPIO_PIN_8

#define SDA_GPIO_PORT GPIOB
#define SDA_GPIO_PIN GPIO_PIN_15

#define RST_GPIO_PORT GPIOB
#define RST_GPIO_PIN GPIO_PIN_14

#define DC_GPIO_PORT GPIOB
#define DC_GPIO_PIN GPIO_PIN_13

#define CS_GPIO_PORT GPIOB
#define CS_GPIO_PIN GPIO_PIN_12
/**********修改端口和引脚***********/

/**********修改端口输出函数**************/
#define OLED_SCLK_Clr() HAL_GPIO_WritePin(SCLK_GPIO_PORT, SCLK_GPIO_PIN, GPIO_PIN_RESET) //SCL
#define OLED_SCLK_Set() HAL_GPIO_WritePin(SCLK_GPIO_PORT, SCLK_GPIO_PIN, GPIO_PIN_SET)

#define OLED_SDIN_Clr() HAL_GPIO_WritePin(SDA_GPIO_PORT, SDA_GPIO_PIN, GPIO_PIN_RESET) //SDA
#define OLED_SDIN_Set() HAL_GPIO_WritePin(SDA_GPIO_PORT, SDA_GPIO_PIN, GPIO_PIN_SET)

#define OLED_RST_Clr() HAL_GPIO_WritePin(RST_GPIO_PORT, RST_GPIO_PIN, GPIO_PIN_RESET) //RES
#define OLED_RST_Set() HAL_GPIO_WritePin(RST_GPIO_PORT, RST_GPIO_PIN, GPIO_PIN_SET)

#define OLED_DC_Clr() HAL_GPIO_WritePin(DC_GPIO_PORT, DC_GPIO_PIN, GPIO_PIN_RESET) //DC
#define OLED_DC_Set() HAL_GPIO_WritePin(DC_GPIO_PORT, DC_GPIO_PIN, GPIO_PIN_SET)

#define OLED_CS_Clr() HAL_GPIO_WritePin(CS_GPIO_PORT, CS_GPIO_PIN, GPIO_PIN_RESET) //CS
#define OLED_CS_Set() HAL_GPIO_WritePin(CS_GPIO_PORT, CS_GPIO_PIN, GPIO_PIN_SET)
/**********修改端口输出函数**************/

#define OLED_CMD 0  //写命令
#define OLED_DATA 1 //写数据

#define X_WIDTH 128
#define Y_WIDTH 64

/* @brief: 推荐使用此宏来对oled进行输出
 * @param x: 坐标的 x 轴 取值 0-127
 * @param y: 坐标的 y 轴 取值 0-7
 * @param ... :用法同C语言一致
 * @example:  float a=1.2;
 *            oled_printf(0,0,"%.3f",a)
 */
#define oled_printf(x, y, ...)      \
    sprintf(oled_str, __VA_ARGS__); \
    OLED_Put_Str(x, y, (int8_t *)oled_str);

extern char oled_str[50];
void OLED_Clear(void);
void OLED_DisPlay_Off(void);
void OLED_DisPlay_On(void);
void OLED_Init(void);
void OLED_Fill(uint8_t dat);
void OLED_Put_Str(uint8_t x, uint8_t y, int8_t str[]);
void OLED_Put_Num(uint8_t x, uint8_t y, int16_t num);
void OLED_Put_Pic(uint16_t height, uint16_t width, uint8_t *pic, uint8_t threshold);

#endif