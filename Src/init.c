#include "init.h"

extern I2C_HandleTypeDef hi2c1;

void SystemClock_Config(void) {
	RCC_OscInitTypeDef		 RCC_OscInitStruct = {0};
	RCC_ClkInitTypeDef		 RCC_ClkInitStruct = {0};
	RCC_PeriphCLKInitTypeDef PeriphClkInit	   = {0};

	RCC_OscInitStruct.OscillatorType	  = RCC_OSCILLATORTYPE_HSI;
	RCC_OscInitStruct.HSIState			  = RCC_HSI_ON;
	RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	RCC_OscInitStruct.PLL.PLLState		  = RCC_PLL_NONE;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) { Error_Handler(); }

	RCC_ClkInitStruct.ClockType		 = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1;
	RCC_ClkInitStruct.SYSCLKSource	 = RCC_SYSCLKSOURCE_HSI;
	RCC_ClkInitStruct.AHBCLKDivider	 = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK) { Error_Handler(); }

	PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_I2C1;
	PeriphClkInit.I2c1ClockSelection   = RCC_I2C1CLKSOURCE_HSI;
	if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK) { Error_Handler(); }
}

void MX_GPIO_Init(void) {
	__HAL_RCC_GPIOB_CLK_ENABLE();
}

void MX_I2C1_Init(void) {
	hi2c1.Instance				= I2C1;
	hi2c1.Init.Timing			= 0x2000090E;
	hi2c1.Init.OwnAddress1		= 0;
	hi2c1.Init.AddressingMode	= I2C_ADDRESSINGMODE_7BIT;
	hi2c1.Init.DualAddressMode	= I2C_DUALADDRESS_DISABLE;
	hi2c1.Init.OwnAddress2		= 0;
	hi2c1.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
	hi2c1.Init.GeneralCallMode	= I2C_GENERALCALL_DISABLE;
	hi2c1.Init.NoStretchMode	= I2C_NOSTRETCH_DISABLE;
	if (HAL_I2C_Init(&hi2c1) != HAL_OK) { Error_Handler(); }

	if (HAL_I2CEx_ConfigAnalogFilter(&hi2c1, I2C_ANALOGFILTER_ENABLE) != HAL_OK) { Error_Handler(); }

	if (HAL_I2CEx_ConfigDigitalFilter(&hi2c1, 0) != HAL_OK) { Error_Handler(); }
}
