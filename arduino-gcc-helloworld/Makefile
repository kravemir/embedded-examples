### VARIABLES ###

# device options
MCU=-mmcu=atmega2560
CPU_SPEED=-DF_CPU=16000000UL
TTY_PORT=/dev/ttyACM1

# environment variables
ARDUINO_CORE_DIR = /usr/share/arduino/hardware/arduino/cores/arduino
ARDUINO_VARIANT_DIR = /usr/share/arduino/hardware/arduino/variants/mega
CXX=avr-gcc


### BUILD CONFIGURATION ###

# basic options
OBJ_DIR=obj
BIN_DIR=bin

# Arduino options
ARDUINO_OBJ_DIR=obj/arduino

ARDUINO_SRCS += $(wildcard $(ARDUINO_CORE_DIR)/*.c)
ARDUINO_SRCS += $(filter-out $(ARDUINO_CORE_DIR)/main.cpp, $(wildcard $(ARDUINO_CORE_DIR)/*.cpp))
ARDUINO_OBJS = $(ARDUINO_SRCS:$(ARDUINO_CORE_DIR)/%=$(ARDUINO_OBJ_DIR)/%.o)
ARDUINO_INCLUDES = -I$(ARDUINO_CORE_DIR) -I$(ARDUINO_VARIANT_DIR)

# program options
SRCS=main.cpp
OBJS=$(SRCS:%.cpp=obj/%.o)

PROGRAM_ELF=$(BIN_DIR)/program.elf
PROGRAM_HEX=$(BIN_DIR)/program.hex

CXX_FLAGS=$(MCU) $(CPU_SPEED) -Os -w $(ARDUINO_INCLUDES)


### RULES ###

all: $(PROGRAM_HEX)

upload: $(PROGRAM_HEX)
	avrdude -p m2560 -c wiring -P $(TTY_PORT) -b 115200 -F -U flash:w:$(PROGRAM_HEX)

$(PROGRAM_HEX): $(PROGRAM_ELF)
	avr-objcopy -O ihex $< $@

$(PROGRAM_ELF): $(OBJS) $(ARDUINO_OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXX_FLAGS) -o $@ $(OBJS) $(ARDUINO_OBJS)

# arduino objects
$(ARDUINO_OBJ_DIR)/%.o: $(ARDUINO_CORE_DIR)/%
	@mkdir -p $(ARDUINO_OBJ_DIR)
	$(CXX) $(CXX_FLAGS) -c -o $@ $<

# program objects
obj/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXX_FLAGS) -c -o $@ $<

clean:
	rm -rf obj bin
