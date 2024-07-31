#ifndef SRC_IBAROMETER_HPP_
#define SRC_IBAROMETER_HPP_

#include "stm32f7xx_hal.h"
#include "stm32f7xx_hal_i2c.h"

class IBarometer {
private:
	uint16_t address_;
protected:
	I2C_HandleTypeDef hi2c1_;

	void writeRegister(uint16_t reg, uint8_t value);
	uint8_t readRegister(uint16_t reg);
public:
	IBarometer(I2C_HandleTypeDef const& hi2c1, uint16_t address);
	virtual void init();
	virtual uint32_t readTemperature();
	virtual uint32_t readPreasure();
};

#endif /* SRC_IBAROMETER_HPP_ */
