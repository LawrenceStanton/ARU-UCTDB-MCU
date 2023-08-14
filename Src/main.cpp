#include "main.hpp"
#include "init.h"

I2C_HandleTypeDef hi2c1;

void SystemClock_Config(void);
void Error_Handler(void);

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
