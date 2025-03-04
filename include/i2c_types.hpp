#ifndef BSP_CPP_INTERFACES_I2C_TYPES_HPP
#define BSP_CPP_INTERFACES_I2C_TYPES_HPP

#include <cstdint>

namespace cms::bsp::interface {

enum class I2CTransactionStatus
{
    SUCCESS = 0,
    FAILED
};

using I2CBusCallback = void (*)(I2CTransactionStatus status, void *userData);

using I2CDeviceAddress = uint8_t;

} // namespace cms::bsp::interface

#endif //BSP_CPP_INTERFACES_I2C_TYPES_HPP
