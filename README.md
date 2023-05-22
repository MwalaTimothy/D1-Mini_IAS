# Shield_D1-Mini_0.66-OLED_IAS
This sketches consists of application that connects and interacts with various IoT devices, enabling users to remotely control and monitor them. It includes features like real-time data collection, analysis, and automation, enhancing the overall functionality and convenience of IoT devices for users.

##Getting your device ready
To get your device to the IOTAppStory OTA project update service after flashing it with IAS Arduino code, you can follow these steps:

1. Ensure your device is connected to the same network as the computer you're using.

2. After flashing your device with the IAS Arduino code, it should create a Wi-Fi access point with the SSID "IAS-WIFI-XXXXXX" (where "XXXXXX" represents a unique identifier).

3. Connect your computer or mobile device to this Wi-Fi network.

4. Open a web browser and enter the IP address "192.168.4.1" in the address bar. This IP address is typically used by devices running in access point mode.

5. You should see the IOTAppStory OTA web interface on your browser, which allows you to configure and update your device.

6. On the web interface, you may need to provide the necessary credentials to log in. This could be a username and password, or an API key provided by the IOTAppStory OTA service.

7. Once you are logged in, you should be able to see your device listed in the interface. Select your device from the list.

8. In the device settings, you can configure various parameters such as the firmware version, description, and other metadata.

9. To update the firmware, you can either select a firmware file from your local computer or provide a link to the firmware file hosted online. 

10. After selecting or providing the firmware file, initiate the firmware update process. The device will download and install the new firmware over the air.

11. Monitor the update progress through the web interface or any logs provided by the IAS Arduino code.

12. Once the update is complete, your device should reboot and start running the new firmware.

Please note that the exact steps and interface may vary depending on the specific implementation of IAS Arduino code and the IOTAppStory OTA service. 

