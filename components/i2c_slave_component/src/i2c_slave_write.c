#include "driver/i2c_slave.h"
#include "driver/i2c.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "i2c_slave_write.h"

void i2c_slave_write_task(void *arg)
{

    esp_err_t ret;
    uint8_t *data_wr = (uint8_t *) malloc(DATA_LENGTH);

    i2c_slave_config_t i2c_slv_config = {
        .addr_bit_len = I2C_ADDR_BIT_LEN_7,
        .clk_source = I2C_CLK_SRC_DEFAULT,
        .i2c_port = TEST_I2C_PORT,
        .send_buf_depth = 256,
        .scl_io_num = I2C_SLAVE_SCL_IO,
        .sda_io_num = I2C_SLAVE_SDA_IO,
        .slave_addr = I2C_SLAVE_ADDR,
    };

    i2c_slave_dev_handle_t i2c_slave_dev_handle;
    ESP_ERROR_CHECK(i2c_new_slave_device(&i2c_slv_config, &i2c_slave_dev_handle));
    for (int i = 0; i < DATA_LENGTH; i++) {
        data_wr[i] = i;
    }

    while (1)
    {
        ret = i2c_slave_transmit(i2c_slave_dev_handle, data_wr, DATA_LENGTH, 10000);
         if (ret == ESP_OK) {
            ESP_LOGI(TAG, "Data transmitted successfully");
        } else {
            ESP_LOGE(TAG, "Error transmitting data: %s", esp_err_to_name(ret));
            free(data_wr);
        }
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}