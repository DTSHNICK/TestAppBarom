#ifndef INC_BMP280_HPP_
#define INC_BMP280_HPP_

#include "IBarometer.hpp"

class BMP280 : public IBarometer {
private:
	constexpr static uint8_t BMP280_I2C_ADDRESS{0x76};
	constexpr static uint8_t BMP280_REG_ID{0xD0};
	constexpr static uint8_t BMP280_REG_RESET{0xE0};
	constexpr static uint8_t BMP280_REG_CTRL_MEAS{0xF4};
	constexpr static uint8_t BMP280_REG_CONFIG{0xF5};
	constexpr static uint8_t BMP280_REG_PRESS_MSB{0xF7};
	constexpr static uint8_t BMP280_REG_TEMP_MSB{0xFA};

	bool is_register_alive{false};
	uint32_t readData(uint8_t reg);
public:
	BMP280(I2C_HandleTypeDef const& hi2c1);

	void init() override;
	uint32_t readTemperature() override;
	uint32_t readPreasure() override;
};




#endif /* INC_BMP280_HPP_ */
