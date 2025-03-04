#ifndef BSP_CPP_INTERFACES_I2C_BUS_HPP
#define BSP_CPP_INTERFACES_I2C_BUS_HPP

#include <cstdint>
#include <cstddef>
#include "i2c_types.hpp"

namespace cms::bsp::interface {

/**
 * An I2C Bus interface, normally for a bus master.
 * This interface is not normally used by higher level code.
 * Instead, a BSP or application should create an I2CDevice object for application use,
 * which in turn uses an I2CBus object adhering to this interface.
 */
class I2CBus
{
public:
    enum class Id
    {
        BUS_1,
        BUS_2,
        BUS_3,
        BUS_4,
        BUS_5,
        BUS_6,
        BUS_7,
        BUS_8,
        BUS_9
    };


    /**
     * Minimal Synchronous initialization behavior. No actual I2C transactions.
     * No blocking.
     * @param id :  the abstracted ID for this particular bus object.
     * @return: true: success.  false, some error.
     */
    virtual bool Init(Id id) = 0;

    virtual Id GetId() = 0;

    /**
     *
     * @param addr
     * @param writeBuffer
     * @param bufferLength
     * @param callback
     * @param context
     * @return
     */
    virtual bool WriteAsync(I2CDeviceAddress addr,
                            const uint8_t *writeBuffer,
                            size_t bufferLength,
                            I2CBusCallback callback,
                            void *context) = 0;

    /**
     *
     * @param addr
     * @param buffer
     * @param bufferLength
     * @param callback
     * @param context
     * @return
     */
    virtual bool ReadAsync(I2CDeviceAddress addr,
                           uint8_t *buffer,
                           size_t bufferLength,
                           I2CBusCallback callback,
                           void *context) = 0;
};

} // namespace cms::bsp::interface

#endif //BSP_CPP_INTERFACES_I2C_BUS_HPP
