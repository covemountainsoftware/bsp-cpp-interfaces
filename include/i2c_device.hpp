#ifndef BSP_CPP_INTERFACES_I2C_DEVICE_HPP
#define BSP_CPP_INTERFACES_I2C_DEVICE_HPP

#include "i2c_bus.hpp"

namespace cms::bsp::interface {

/**
 * An I2C Bus interface, normally for a bus master.
 * This interface is not normally used by higher level code.
 * Instead, a BSP or application should create an I2CDevice object for application use,
 * which in turn uses an I2CBus object adhering to this interface.
 */
class I2CDevice
{
public:
    /**
     * Minimal Synchronous initialization behavior. No actual I2C transactions.
     * No blocking.
     * @param addr :  the device address for this particular device.
     * @return: true: success.  false, some error.
     */
    virtual bool Init(I2CDeviceAddress addr) = 0;

    virtual I2CDeviceAddress GetDeviceAddress() = 0;

    virtual I2CBus::Id GetBusId() = 0;

    /**
     * Non-blocking, async, write to the target I2C Device
     * @param writeBuffer
     * @param bufferLength
     * @param callback
     * @param context
     * @return
     */
    virtual bool WriteAsync(const uint8_t *writeBuffer,
                            size_t bufferLength,
                            I2CBusCallback callback,
                            void *context) = 0;

    /**
     * Non-blocking, async, read from the target I2C Device
     * @param buffer
     * @param bufferLength
     * @param callback
     * @param context
     * @return
     */
    virtual bool ReadAsync(uint8_t *buffer,
                           size_t bufferLength,
                           I2CBusCallback callback,
                           void *context) = 0;
};

} //namespace

#endif //BSP_CPP_INTERFACES_I2C_DEVICE_HPP
