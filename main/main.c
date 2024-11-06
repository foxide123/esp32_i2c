#include "freertos/FreeRTOS.h"
#include "i2c_master_component.h"
#include "i2c_slave_read.h"
#include "i2c_slave_write.h"

void app_main(void)
{
    // Creating I2C task
    //xTaskCreate(i2c_slave_read_task, "i2c_slave_read_task", 4096, NULL, 5, NULL);
    xTaskCreate(i2c_slave_write_task, "i2c_slave_write_task", 4096, NULL, 5, NULL);
}
