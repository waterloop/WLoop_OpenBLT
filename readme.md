# WLoop OpenBLT

Waterloop's port(s) of OpenBLT, to be used on our G6 pod.

## Project File Structure

OpenBLT is included as a submodule in this repo. Our ports are included in the root directory of this
repository (one directory per device).

Inside of each port, there will be a "Boot" and a "TestProgram" directory. The "Boot" directory contains
the source code of the OpenBLT port, and the "TestProgram" directory contains a program to test the OpenBLT
port on.

## Building

First and foremost, the submodules must be pulled:

```bash
git submodule update --init --recursive
```

Each "main" subdirectory has its own makefile. For example, lets build OpenBLT for an STM32G431KBT
Nucleo Board:

```bash
cd ./g431_nucleo/Boot
make
```

Building the test program is done similarly:

```bash
cd ./g431_nucleo/TestProgram
make
```

To build the host utility `BootCommander`, which is used to actually provide the FW update via
OpenBLT, you may run the following script:

```bash
./utils/build_boot_commander.sh
```

`BootCommander` has some dependencies, which will first need to be installed:

```bash
sudo apt install cmake build-essential libusb-1.0-0 libusb-1.0-0-dev
```

## Flashing Firmware Using BootCommander and OpenBLT

For this section, we will be using the `./g431_nucleo` as an example.

```bash
# Build BootCommander (if you haven't already)
./utils/build_boot_commander.sh

# Build OpenBLT for the G431 Nucleo
cd ./g431_nucleo/Boot
make

# Flash OpenBLT onto the device...
make flash

# Build the test program...
cd ../TestProgram
make

# Now, flash the test program with BootCommander (over UART)
cd ../../
./utils/BootCommander \
    -s=xcp \
    -t=xcp_rs232 \
    -d=/dev/serial/by-id/usb-STMicroelectronics_STLINK-V3_002900233331511034333834-if02 \
    ./g431_nucleo/TestProgram/build/openblt_test_program.srec

# NOTE: the -d flag will be different for everyone, it is the path to the UART <==> USB
#       device that you have connected to the device (for example, /dev/ttyUSB0)
```


## Developing for this Repo

### Intellisense and Autocomplete
Intellisense and autocomplete are available through the `clangd` language server. It is supported on
most modern editors.

If you use VSCode, there exists an
[extension](https://marketplace.visualstudio.com/items?itemName=llvm-vs-code-extensions.vscode-clangd)
for it.

`clangd` is already installed on your [vagrant VMs](https://github.com/waterloop/firmware-vagrant).
It is also easily installed through apt and brew if you like.

`clangd` uses the auto-generated file `compile_commands.json` to provide intellisense and autocomplete.
This file is gitignored in this repository, so you will need to generate it yourself if you want
intellisense. This can be easily done using `bear`, which is pre-installed on your vagrant VMs.

```
bear -- make
```

