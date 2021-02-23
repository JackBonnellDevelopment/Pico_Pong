add_executable(
  classic_pong
  demo.cpp
  image_data.cpp
)

# Pull in pico libraries that we need
target_link_libraries(classic_pong pico_stdlib hardware_spi hardware_pwm hardware_dma pico_display)

# create map/bin/hex file etc.
pico_add_extra_outputs(classic_pong)