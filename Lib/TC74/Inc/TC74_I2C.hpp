/**
 ******************************************************************************
 * @file			: TC74_I2C.hpp
 * @brief			: TC74 I2C Driver Interface Implementation
 * @author			: Lawrence Stanton
 ******************************************************************************
 */

#pragma once

#include "TC74.hpp"

#include "stm32f0xx_hal.h"

class TC74_I2C : public TC74::I2C {
private:
	I2C_HandleTypeDef &hi2c;

public:
	virtual optional<Register> read(MemoryAddress memoryAddress) noexcept override final;
	virtual optional<Register> write(MemoryAddress memoryAddress, Register data) noexcept override final;

	TC74_I2C(I2C_HandleTypeDef &hi2c, DeviceAddress deviceAddress) noexcept;
	virtual ~TC74_I2C() noexcept = default;
};
