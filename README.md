# Edge AI Workshop (ESP8266 Hands-On)

> **Edge AI Workshop**  
> Hands-on activity material for the ESP8266 session.

---

## What's In Here

```
edge-ai-workshop/
├── esp8266_wifi_scanner/
│   └── esp8266_wifi_scanner.ino
├── esp8266_web_server/
│   └── esp8266_web_server.ino
└── README.md
```

---

## Prerequisites

Complete these before the workshop. Everything is free.

| Step | What | Link |
|------|------|------|
| 1 | CH340C USB Driver | Download |
| 2 | Arduino IDE 2.x | [Download](https://www.arduino.cc/en/software) |
| 3 | ESP8266 Board URL | `http://arduino.esp8266.com/stable/package_esp8266com_index.json` |
| 4 | ESP8266 Board Package | Install via Arduino Board Manager (search: `esp8266`) |

### Arduino IDE Configuration

- **Board:** `NodeMCU 1.0 (ESP-12E Module)`
- **Upload Speed:** `115200`
- **Baud Rate:** `9600`

---

## Activity 1 — WiFi Scanner

**File:** `esp8266_wifi_scanner/esp8266_wifi_scanner.ino`

Your board scans every wireless network in range and prints them to Serial Monitor with signal strength (RSSI).

### Upload & Run

1. Open `esp8266_wifi_scanner.ino` in Arduino IDE
2. Click **Upload** (→)
3. Open **Tools → Serial Monitor**, set baud to `9600`
4. Press **RST** on the board
5. Watch every network in the room appear

### What You'll See

```
--- Networks Found ---
Airtel_sam     RSSI: -67
Anon              RSSI: -62
Airtel_neon  RSSI: -91
--- Networks Found ---
...
```

> **RSSI** = signal strength. Closer to 0 = stronger signal. `-30` is excellent, `-90` is barely there.

---

## Activity 2 — Edge Web Server

**File:** `esp8266_web_server/esp8266_web_server.ino`

Your board connects to a WiFi hotspot, hosts a webpage on port 80, and serves a live network scan to any browser that connects to it.

### Before Uploading

Open the sketch and set your hotspot credentials:

```cpp
const char* ssid     = "WorkshopNet";
const char* password = "00000000";
```

### Upload & Run

1. Open `esp8266_web_server.ino` in Arduino IDE
2. Click **Upload** (→)
3. Open **Tools → Serial Monitor**, set baud to `9600`
4. Press **RST** on the board — you'll see:
   ```
   .....
   IP: x.x.x.x
   ```
5. Type that IP into any browser on the same hotspot
6. See your board's live network scan as a webpage

### The Fun Part

Give your IP to the person sitting next to you.  
Open their IP on your phone.  
You're now reading data served directly from the chip in their hand.

---

## What's Actually Happening

```
Your Phone (browser)
      │
      │  HTTP GET  x.x.x.x
      ▼
ESP8266 Board
      │
      ├── WiFi.scanNetworks()    → scans the room
      ├── builds HTML string     → formats the results
      └── server.send(200, ...)  → sends it back to your phone
```

No cloud. No server. No API. The chip is the infrastructure.

---

## Troubleshooting

| Problem | Fix |
|---------|-----|
| Board not detected | Install CH340C driver, try a different USB cable (some are charge-only) |
| Upload fails | Check board selection: `NodeMCU 1.0 (ESP-12E Module)` and correct COM port |
| Garbage in Serial Monitor | Baud rate mismatch. Set to exactly `9600` |
| Serial Monitor blank after upload | Press RST on the board with Serial Monitor already open |
| Can't reach the IP in browser | Make sure your phone and the ESP are on the same hotspot |
| No networks found | Toggle airplane mode off on nearby phones to seed some networks |

---

**Built** for the Edge AI Workshop series.  
