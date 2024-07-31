#include "BMP280.hpp"
#include <iostream>

BMP280::BMP280(I2C_HandleTypeDef const& hi2c1): IBarometer(hi2c1, BMP280_I2C_ADDRESS){}

void BMP280::init(){
	// Check ID
	uint8_t id = readRegister(BMP280_REG_ID);
	if (id != 0x58) {
		is_register_alive = false;
		return;
	}
	// Reset
	writeRegister(BMP280_REG_RESET, 0xB6);
	HAL_Delay(100);

	// Config
	writeRegister(BMP280_REG_CTRL_MEAS, 0x27);
	writeRegister(BMP280_REG_CONFIG, 0xA0);
	is_register_alive = true;
}

uint32_t BMP280::readData(uint8_t reg) {
	if (!is_register_alive) {
		std::cout << "Device isn't init. Fail";
		return 0U;
	}
    uint8_t data[3];
    HAL_I2C_Mem_Read(&hi2c1_, BMP280_I2C_ADDRESS, reg, 1, data, 3, HAL_MAX_DELAY);

    int32_t result = (int32_t)(((uint32_t)(data[0] << 12)) | ((uint32_t)(data[1] << 4)) | ((uint32_t)(data[2] >> 4)));
    return result;
}

uint32_t BMP280::readPreasure() {
    return readData(BMP280_REG_PRESS_MSB);
}

uint32_t BMP280::readTemperature() {
    return readData(BMP280_REG_TEMP_MSB);
}




