# Homeassistant Configuration
This repository is a place to store my configuration for all of my smart home devices and automations using [Home Assistant][l-ha]. All files are edited manually using [Atom][l-atom] using the config in my Atom Config repo.

---

## Host Configuation
Most of the services are run using docker with the exception of PiHole. I plan to migrate to docker compose for ease of use and updating later.

- **Home Assistant:** Homeassistant is an automation platform for automation and control.
- **Mosquitto:** Mosquitto is a MQTT broker designed to be run on light hardware
- **InfluxDB:** InfluxDB is a time series database for backing up home-assistant states and exporting to Grafana.
- **Grafana:** Grafana is a time based data visualization tool for easily creating dashboards.
- **Portainer:** Portainer is used for docker container management on this host and another computer.
- **Unifi Controller:** Unifi is an enterprise network device line by Ubiquiti Networks used for communication. This controller is used for management.
- **Discord Bots:** Other discord bots are self hosted using discord.js and other npm packages.
- **PiHole:** PiHole is a network adblocker that redirects dns requests for blocked domains to itself and rejects the connections.

---

## Component Usage

#### Network

The network is composed of equipment from Ubiquiti's Unifi Line. The internet service we receive is 1 Gbps down and 50 Mbps up.

|Unifi Security Gateway|Unifi Switch 8-60W|Unifi AP AC Pro|Software Host (Toshiba Satellite A505-S6960)|
|----------------------|------------------|---------------|--------------------------------------------|
|![USG][i-network-usg]|![Unifi Switch][i-network-switch]|![Unifi AP][i-network-ap]|![Software Host][i-network-host]|

#### Text to Speech

Text to speech is composed of two apple tv devices and an echo dot 2nd generation using a custom component.

|Apple TV 2nd Generation|Apple TV 4K|Amazon Echo Dot 2nd Generation|
|-----------------------|-----------|------------------------------|
|![Apple TV 2][i-tts-appletv2]|![Apple TV 4K][i-tts-appletv4k]|![Amazon Echo Dot 2][i-tts-amazonechodot2]|

---

## Components

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
||Unifi Controller|[configuration.yaml](configuration.yaml)|
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
|Custom Component|Alexa Media|[configuration.yaml](configuration.yaml)|
||NWS Alerts|[config/sensor.yaml](config/sensor.yaml)|
||iAqualink|[configuration.yaml](configuration.yaml)|

[l-ha]: https://home-assistant.io
[l-atom]: https://atom.io
[i-network-usg]: documentation/images/network-usg.png "Unifi Security Gateway"
[i-network-switch]: documentation/images/network-switch8-60W.png "Unifi 8 Port 60W POE Switch"
[i-network-ap]: documentation/images/network-ap-ac-pro.png "Unifi AP AC Pro"
[i-network-host]: documentation/images/network-host.png "Toshiba Satellite A505-S6960"
[i-tts-appletv2]: documentation/images/tts-apple-tv-2.png "Apple TV 2nd Generation"
[i-tts-appletv4k]: documentation/images/tts-apple-tv-4k.png "Apple TV 4K Generation"
[i-tts-amazonechodot2]: documentation/images/tts-echo2.png "Amazon Echo Dot 2nd Generation"
