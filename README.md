![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

![6DOF IMU Click](http://www.mikroe.com/img/development-tools/accessory-boards/click/6dof-imu/gallery/6dof_click_02.png)

---
[Product Page](http://www.mikroe.com/click/6dof-imu/)

[Manual Page](docs.mikroe.com/6_DOF_IMU_click)

---

### General Description

6DOF IMU click is a mikroBUS™ add-on board that carries ST’s LSM6D33 IC, which is 6-axis inertial measurement unit comprising a 3-axis gyroscope and a 3-axis accelerometer. The chip is a highly accurate 6 DOF inertial measurement unit with long-term stable operation over a wide range of temperatures. It’s high robustness to mechanical shock makes is suitable for designing reliable platform stabilization systems, for example in cameras and drones. The board communicates with the target MCU either through I2C or SPI interfaces (along with an additional INT pin).
---

### Example

#### Configuration
* MCU:             STM32F107VC
* Dev.Board:       EasyMx Pro v7
* Oscillator:      72 Mhz internal
* Ext. Modules:    3G click
* SW:              MikroC PRO for ARM 4.7.4

```
#include <stdint.h>
#include "6dof_hw.h"
#include "6dof_hal.h"
#include "6dof_api.h"

void ExtInt() iv IVT_INT_EXTI15_10 ics ICS_AUTO {
  EXTI_PR.B10 = 1;                     // clear flag
  GPIOE_ODR = ~GPIOE_IDR;              // Togle PORTE
}

void main()
{
   GPIO_Digital_Input( &GPIOD_BASE, _GPIO_PINMASK_10 );
   GPIO_Digital_Output(&GPIOE_BASE, _GPIO_PINMASK_ALL); // Set PORTA as digital output

  RCC_APB2ENR.AFIOEN = 1;              // Enable clock for alternate pin functions
  AFIO_EXTICR3 = 0x0300;               // PD10 as External interrupt
  EXTI_RTSR = 0x00000400;              // Set interrupt on Rising edge
  EXTI_IMR |= 0x00000400;              // Set mask
  NVIC_IntEnable(IVT_INT_EXTI15_10);   // Enable External interrupt

  EnableInterrupts();                  // Enables the processor interrupt.

  delay_ms(2000);

   I2C1_Init_Advanced( 100000, &_GPIO_MODULE_I2C1_PB67 );
   delay_ms(200);
   dof6_init ( 0x6B );
   delay_ms(1000);
   delay_ms(1000);
   GPIOA_ODR = ~GPIOA_ODR;
   delay_ms(1000);
   GPIOA_ODR = ~GPIOA_ODR;
   delay_ms(1000);
   GPIOA_ODR = ~GPIOA_ODR;
   delay_ms(1000);
   GPIOA_ODR = 0;

  dof6_accel_configure(HZ_416, true,true, true, ACL_RANGE_2G);
  dof6_gyro_configure(HZ_416, true,true, true, DPS_1000);


  dof6_configure_double_tap_interrupt(1,true,12,3,3,15);
  dof6_configure_free_fall_interrupt(1, true, 6,3);
  dof6_configure_tilt_interrupt ( true, 1 );


while(1)
{}


}
```