# CoActionHero

CoAction Hero Board Support Package


## Installing Stratify OS using the legacy (CoactionOS bootloader)

Stratify OS can be installed on CoAction Hero boards with the original bootloader. The original bootloader isn't compatible with the latest protocols so care must be taken.

First the bootloader must be invoked manually by shorting (with metal tweezers for example) the `BOOT` pads on the board while resetting (or power cycling the board). When the bootloader is successfully invoked, the green LED will flash quickly about 5 times.

Once the bootloader is running, the following command will install Stratify OS.

```
sl conn.connect:path=<path to serial port>,legacy cloud.install:id=6iCy0pM3JrmGLIVOPVZv
```

The `<path to serial port>` must be specified. If there is a problem executing any commands, the bootloader needs to be manually re-invoked between each attempt.

Once Stratify OS is installed, all protocols for applications will work as expected. However, anything the works with the bootloader will require the steps mentioned. For example, `sl os.install` will not work unless it is done after manually invoking the bootloader and then running:

```
sl conn.connect:path=<path to serial port>,legacy os.install
```

### Install Hello World

Once Stratify OS is installed, you can try installing and running Blinky with:

```
sl cloud.install:id=8PtMwYjOghdeUpMxPmyl,run,terminal
```

`ctrl+c` will exit the terminal (blinky will keep running).
