# Homeassistant Configuration
These are my basic config files for the home automation platform [homeassistant][l-ha].

---

### Components
|Categories|Component use|Files used in|
|----------|-------------|-------------|
|Alarm|Manual Alarm Control Panel with MQTT Support|[config/alarm.yaml](config/alarm.yaml)|
|Automation|Automation|[config/automations.yaml](config/automations.yaml)|
||Scripts|[config/scripts.yaml](config/scripts.yaml)|
|Binary Sensor|MQTT Binary Sensor|[config/binary_sensor.yaml](config/binary_sensor.yaml)|
||Template Binary Sensor|[config/binary_sensor.yaml](config/binary_sensor.yaml)|
|Camera|Raspberry Pi Camera|[config/camera.yaml](config/camera.yaml)
|Environment|Sun|[configuration.yaml](configuration.yaml)|
||Moon|[config/sensor.yaml](config/sensor.yaml)|
|Frontend|Config|[configuration.yaml](configuration.yaml)|
||Panel iFrame| [config/iframe.yaml](config/iframe.yaml)|
|Geolocation|USGS Earthquakes|[config/geo_location.yaml](config/geo_location.yaml)|
|History|History|[configuration.yaml](configuration.yaml)|
||InfluxDB|[configuration.yaml](configuration.yaml)|
||Logbook|[configuration.yaml](configuration.yaml)|
||Recorder|[configuration.yaml](configuration.yaml)|
|Hub|iOS|[config/ios.yaml](config/ios.yaml)|
||MQTT|[configuration.yaml](configuration.yaml)|
|Intent|Shopping List|[configuration.yaml](configuration.yaml)|
|Light|Light Switch| [config/light.yaml](config/light.yaml)|
|Media Player|Apple TV|[configuration.yaml](configuration.yaml)|
||DirecTV|[config/media_player.yaml](config/media_player.yaml)|
|Multimedia|Apple TV|[configuration.yaml](configuration.yaml)|
|Network|Certificate Expiry|[config/sensor.yaml](config/sensor.yaml)|
||DuckDNS|[configuration.yaml](configuration.yaml)|
|Notifications|iOS|[config/ios.yaml](config/ios.yaml)|
||Pushbullet|[config/notify.yaml](config/notify.yaml)|
|Organization|Group|[config/groups.yaml](config/groups.yaml)|
||Zone|[config/zone.yaml](config/zone.yaml)|
|Presence Detection|Bluetooth LE Tracker|[config/device_tracker.yaml](config/device_tracker.yaml)|
||Bluetooth Tracker|[config/device_tracker.yaml](config/device_tracker.yaml)|
||NMAP|[config/device_tracker.yaml](config/device_tracker.yaml)|
|Remote|Apple TV|[configuration.yaml](configuration.yaml)|
|Sensor|iOS|[config/ios.yaml](config/ios.yaml)|
||MQTT Sensor|[config/sensor.yaml](config/sensor.yaml)|
||Speedtest.net|[config/sensor.yaml](config/sensor.yaml)|
|Switch|MQTT Switch|[config/switch.yaml](config/switch.yaml)|
|TTS|Google TTS|[config/tts.yaml](config/tts.yaml)|
||Pico TTS|[config/tts.yaml](config/tts.yaml)|
|Utility|Uptime Sensor|[config/sensor.yaml](config/sensor.yaml)|
|Weather|Dark Sky Weather|[configuration.yaml](configuration.yaml)|

[l-ha]: https://home-assistant.io
