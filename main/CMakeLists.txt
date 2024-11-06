idf_component_register(SRCS "main.c" "../components/i2c_slave_component/src/i2c_slave_read.c" "../components/i2c_slave_component/src/i2c_slave_write.c" 
                    INCLUDE_DIRS "."
                    REQUIRES i2c_master_component i2c_slave_component driver freertos)