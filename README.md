# Pico-Pong
Pong for the Raspberry Pi Pico 


# Compiling Games

If you want to make the installation as simple as possible just follow the steps below (you can simply cut and paste these commands into your terminal):

**Step 1.** Create a new directory in your home directory to keep everything tidily in one place:

```bash
cd ~
mkdir pico
cd pico
```

**Step 2.** Install the Pico SDK and examples:

```bash
git clone -b master https://github.com/raspberrypi/pico-sdk.git

# Set the PICO_SDK_PATH environment variable to where you just cloned the repo.
export PICO_SDK_PATH=/path/to/pico-sdk

cd pico-sdk
git submodule update --init
cd ..

**Step 3.** Install the toolchain needed to build Pico projects.


**Debian Linux**
```bash
sudo apt update
sudo apt install cmake gcc-arm-none-eabi build-essential
```

**macos** (Using Homebrew)
```bash
# Install cmake
brew install cmake

# Install the arm eabi toolchain
brew tap ArmMbed/homebrew-formulae
brew install arm-none-eabi-gcc

# The equivalent to build-essential on linux, you probably already have this.
xcode-select --install
```

**Step 4.** Install the Pimoroni Pico libraries:

```bash
git clone https://github.com/pimoroni/pimoroni-pico.git
cd pimoroni-pico
mkdir build
```

And you're done. Everything is installed and ready to go.

To build the ever expanding Pong style games:

```
cd build
cmake ..
make
```
Inside `pong` will be one directory per product, each of which contain at least one `.uf2` file that can be flashed directly onto your Pico.
