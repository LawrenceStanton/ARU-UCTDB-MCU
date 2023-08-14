/**
 ******************************************************************************
 * @file			: TC74.cpp
 * @brief			: Source for TC74.hpp
 * @author			: Lawrence Stanton
 ******************************************************************************
 */

#include "TC74_I2C.hpp"

using std::nullopt;

using Register		= TC74::I2C::Register;
using MemoryAddress = TC74::I2C::MemoryAddress;

optional<Register> TC74_I2C::read(MemoryAddress memoryAddress) noexcept {
	static_assert(sizeof(Register) == sizeof(uint8_t));
	uint8_t data = 0;

	auto status = HAL_I2C_Mem_Read(
		&this->hi2c, //
		static_cast<uint8_t>(this->deviceAddress) << 1,
		static_cast<uint8_t>(memoryAddress),
		sizeof(uint8_t),
		&data,
		sizeof(data),
		100
	);
	if (status != HAL_OK) return nullopt;
	else return Register(data);
}

optional<Register> TC74_I2C::write(MemoryAddress memoryAddress, Register data) noexcept {
	static_assert(sizeof(Register) == sizeof(uint8_t));
	auto status = HAL_I2C_Mem_Write(
		&this->hi2c, //
		static_cast<uint8_t>(this->deviceAddress) << 1,
		static_cast<uint8_t>(memoryAddress),
		sizeof(uint8_t),
		&data,
		sizeof(data),
		100
	);
	if (status != HAL_OK) return nullopt;
	else return data;
}

TC74_I2C::TC74_I2C(I2C_HandleTypeDef &hi2c, DeviceAddress deviceAddress) noexcept : hi2c(hi2c), I2C(deviceAddress) {}
