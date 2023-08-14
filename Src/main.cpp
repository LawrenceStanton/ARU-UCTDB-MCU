#include "main.hpp"
#include "init.h"

#include "TC74.hpp"
#include "TC74_I2C.hpp"

I2C_HandleTypeDef hi2c1;

void SystemClock_Config(void);
void Error_Handler(void);

TC74_I2C tc74_i2c{hi2c1, TC74::I2C::DeviceAddress::A0};
TC74	 tc74{tc74_i2c};

int main(void) {
	HAL_Init();
	SystemClock_Config();

	MX_GPIO_Init();
	MX_I2C1_Init();

	while (true) {}
}

void Error_Handler(void) {
	__disable_irq();
	while (true) {}
}
