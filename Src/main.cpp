#include "main.hpp"
#include "init.h"

void SystemClock_Config(void);
void Error_Handler(void);

int main(void) {
	HAL_Init();
	SystemClock_Config();

	while (true) {}
}

void Error_Handler(void) {
	__disable_irq();
	while (true) {}
}
