#define  I2C_SLAVE_SCL_IO GPIO_NUM_22
#define  I2C_SLAVE_SDA_IO GPIO_NUM_21

#define DATA_LENGTH 32
#define I2C_SLAVE_SCL_IO GPIO_NUM_22
#define I2C_SLAVE_SDA_IO GPIO_NUM_21
#define I2C_SLAVE_ADDR 0x69
#define TEST_I2C_PORT I2C_NUM_0
#define TAG "I2C Slave Component"

void i2c_slave_write_task(void *arg);