# Arduino Environmental Sensor
![Version](/img/VERSION.png)
| Version | In Work            |
| ------- | ------------------ |
|  0.0.1 | :white_check_mark: |

| Version  | Supported |
| ------------- | ------------- |
|  0.0.1  | :white_check_mark: |

![FEATURES](/img/FEATURES.png)

|   | 
| ------------- | 
| Is operated by serial monitor commands. |
| Saves temperature and humidity to sd card. |
| Reads temperature and humidity last saved in file on sd card. |

![INFO](/img/INFO.png)

|  Requirements | 
| ------------- | 
| SD Card Reader |
| SD Card |
| DHT11 Temperature and Humidity Sensor |
| Arduino Uno |

|  Wiring | 
| ------------- | 
| SD Card Reader: |
| MOSI - pin 11 on Arduino Uno |
| MISO - pin 12 on Arduino Uno |
| CLK - pin 13 on Arduino Uno |
| CS - pin 4 used here on your SD card shield |
| DHT11 Temperature and Humidity Sensor: |
| Signal pin on Temperature and Humidity Sensor - pin 7 digital on Arduino Uno |

|  Commands | Description of command |
| --------- | ---------------------- | 
| s1        | Displays humidity and temperature. |
| save s1   | Saves humidity and temperature to memory card. |
| read s1   | Reads humidity and temperature file from memory card. |
| init sd   | This is recommended for new memory cards. |
