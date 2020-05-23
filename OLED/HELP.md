# 128 * 64 OLED 库
> 本库提供了`0.96吋`OLED 的操作库，相比官方提供的例程，本库更加易用

## 使用说明

用户使用前需要修改`oled.h`头文件中相关的的定义。大体如下：
1. 修改端口和引脚    
   ```c
   /**********修改端口和引脚***********/
    #define SCLK_GPIO_PORT GPIOA
    #define SCLK_GPIO_PIN GPIO_PIN_8
   ```
2. 修改GPIO操作函数
   ```c
   #define OLED_SCLK_Clr() HAL_GPIO_WritePin(SCLK_GPIO_PORT, SCLK_GPIO_PIN, GPIO_PIN_RESET) //SCL
   #define OLED_SCLK_Set() HAL_GPIO_WritePin(SCLK_GPIO_PORT, SCLK_GPIO_PIN, GPIO_PIN_SET)
   ```
3. 初始化GPIO
   用户需要配置OLED相关的GPIO为 `开漏上拉输出`


## 用户函数列表

```c
void OLED_Init(void);
```
该函数对OLED进行了初始化。   
**注意：** 这里只对OLED初始化。OLED相关的引脚需要手动配置成 `开漏上拉输出`
<br>

```c
void OLED_DisPlay_On(void);
void OLED_DisPlay_Off(void);
```
这两个函数可以控制OLED的打开和关闭

<br>

```c
void OLED_Clear(void);
```
该函数可以用于清屏

<br>

```c
void OLED_Fill(uint8_t dat);
```
该函数用于向OLED填充。参数可以是`0x01` 或者 `0x00`

<br>

```c
#define oled_printf(x, y, ...)
```
该宏于 `oled.h` 中定义。与 C 语言用法相同。   
`x` 为横坐标 取值为 0-127 `y` 为纵坐标 取值为 0-7
后面就是C语言的用法。
> 示例: float a=1.2;   
> oled_printf(0,0,"%.3f",a)

推荐使用该宏对OLED输出，可以提供很大的便利

<br>

```c
void OLED_Put_Str(uint8_t x, uint8_t y, int8_t str[])
```
该函数向OLED显示字符串。  
`x` 为横坐标 取值为 0-127 `y` 为纵坐标 取值为 0-7    
`str` 为需要显示的字符串


<br>

```c
void OLED_Put_Num(uint8_t x, uint8_t y, int16_t num)
```
该函数向OLED显示数字。  
`x` 为横坐标 取值为 0-127 `y` 为纵坐标 取值为 0-7    
`num` 为需要显示的数字


<br>

```c
void OLED_Put_Pic(uint16_t height, uint16_t width, uint8_t *pic, uint8_t threshold)

```
该函数向OLED显示图片。  
`height` 为图像高度 `y` 图像宽度   
`pic` 为图像数组起始地址
`threshold`为阈值。大于该阈值的点会被点亮    







