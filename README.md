# oled-interfacing-with-arduino-uno-r4-wifi

A small demo project showing how to drive an SSD1306 I2C OLED display from an Arduino UNO R4 WiFi using PlatformIO and the Adafruit libraries.

## What this project does

- Initializes an SSD1306 I2C OLED and displays example text/graphics.
- Built with PlatformIO (Arduino framework) — see `platformio.ini` for the configured environment and libraries.
- Source code: `src/main.cpp`.

## Hardware required

- Arduino UNO R4 WiFi (or compatible board with labeled SDA/SCL pins)
- SSD1306-compatible I2C OLED module (commonly 128x64)
- Jumper wires and (optional) breadboard
- USB cable and a computer

Optional:
- Logic-level considerations (most modules accept 3.3V or 5V — check the module specs)

## Wiring (I2C)

- Connect the OLED module's SDA -> board SDA, SCL -> board SCL. Use the labeled SDA / SCL pins on the UNO R4 WiFi.
- Connect GND -> GND and VCC -> 3.3V or 5V depending on your module's requirements (see "Power notes" below).
- Many modules include onboard pull-up resistors for I2C — do not add extra pull-ups unless you know they're missing.
- If your board doesn't have dedicated SDA/SCL pins, consult the UNO R4 WiFi documentation for the correct pins to use.

## Software prerequisites

- PlatformIO (either the VS Code PlatformIO extension or PlatformIO Core installed via pip)
- Python (if installing PlatformIO Core via pip)
- USB drivers for your board (Windows Device Manager can show COM ports)
- The project is configured to use these libraries (via `platformio.ini`):
  - Adafruit GFX Library
  - Adafruit SSD1306

## Build & upload (PlatformIO on Windows PowerShell)

Open PowerShell in the project root (`C:\Users\UnK\CLionProjects\oled-interfacing-with-arduino-uno-r4-wifi`).

Build the project:

```powershell
pio run
```

Build and upload to the configured environment (`uno_r4_wifi`):

```powershell
pio run -e uno_r4_wifi -t upload
```

If you need to specify a different COM port or environment, update `platformio.ini` or use the `-p` flag when uploading.

Open the serial monitor (the project `platformio.ini` sets `monitor_speed = 9600` by default):

```powershell
pio device monitor -p COM5 -b 9600
```

Replace `COM5` with the actual COM port shown in Windows Device Manager.

## Where the code lives

- Main application: `src/main.cpp`
- Project configuration: `platformio.ini`
- Libraries are installed via the `lib_deps` entries in `platformio.ini` (Adafruit GFX and Adafruit SSD1306).

## Library dependencies

This project relies on:

- Adafruit GFX Library (graphics primitives and text rendering)
- Adafruit SSD1306 (SSD1306 driver)

These are already declared in `platformio.ini` under `lib_deps`.

If you need to change or update versions, edit `platformio.ini` or use PlatformIO's Library Manager.

## I2C address & power notes

- Common SSD1306 I2C addresses: `0x3C` or `0x3D`. Which address is used depends on the module's solder jumper or wiring.
- If the display is not detected or shows garbage, run an I2C scanner sketch (or use an existing I2C scanner) to detect the address.
- Power: many SSD1306 modules accept either 3.3V or 5V VCC, but you must confirm with your specific module. Supplying the wrong voltage can damage the module.

## Troubleshooting

- COM port not visible:
  - Check the USB cable (data vs power-only)
  - Open Windows Device Manager → Ports (COM & LPT) to find the assigned COM port
  - Install board drivers if required by the vendor

- Upload failures:
  - Confirm `upload_port` in `platformio.ini` (this project uses `COM5` by default)
  - Try resetting the board or pressing any bootloader/boot button required by the board
  - Ensure the correct environment (`uno_r4_wifi`) is used when invoking `pio run -e ... -t upload`

- No display / garbled output:
  - Verify SDA/SCL/GND/VCC wiring
  - Confirm the I2C address (0x3C/0x3D) and update the initialization in `src/main.cpp` if necessary
  - Check the library versions; try updating Adafruit libraries if you suspect a compatibility issue

- Serial monitor shows no output:
  - Confirm baud rate in the code matches the `pio device monitor` command
  - Ensure the correct COM port is selected

## Contributing

Contributions are welcome. To contribute:

- Open an issue to discuss significant changes or report bugs
- Send a pull request with a clear description of the change
- Keep changes small and focused; include tests or verification steps when applicable

## License

This repository does not currently include a license file. If you'd like to add one, a permissive option is the MIT License — add a `LICENSE` file to the project root with the chosen license text.

---

If you'd like, I can also:

- Add a `LICENSE` file (e.g., MIT) to the repository
- Add an example I2C scanner sketch in `src/` to help detect the display address
- Add a small wiring diagram image (you'd need to supply or approve one)

Tell me which of those (if any) you'd like me to add next.
