/gpio_driver:	sudo insmod gpio_driver.ko
		sudo mknod /dev/gpio_driver c 240 0

		sudo chmod a+rw /dev/gpio_driver
		ls -l /dev/gpio_driver

/gpio_driver_test_app/bin/Release:	./gpio_driver_test_app

/gpio_driver_user_app/bin/Release:	./gpio_driver_test_app
	