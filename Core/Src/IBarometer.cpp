#include "IBarometer.hpp"

IBarometer::IBarometer(I2C_HandleTypeDef const& hi2c1, uint16_t address):
	address_{address},
	hi2c1_{hi2c1}
{
	init();
}

void IBarometer::writeRegister(uint16_t reg, uint8_t value) {
    HAL_I2C_Mem_Write(&hi2c1_, address_, reg, 1, &value, 1, HAL_MAX_DELAY);
}

uint8_t IBarometer::readRegister(uint16_t reg){
    uint8_t value;
    HAL_I2C_Mem_Read(&hi2c1_, address_, reg, 1, &value, 1, HAL_MAX_DELAY);
    return value;
}

