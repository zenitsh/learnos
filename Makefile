TARGET = mykernel

COMPILER_PREFIX = riscv64-elf-

INCLUDE_DIRS = -I ./include
LINKER_FILE = -T linker.ld

BUILD_DIR = ./build

CC = $(COMPILER_PREFIX)gcc $(INCLUDE_DIRS) -c -nostdlib -nodefaultlibs -fno-builtin -mcmodel=medany -g

AS = $(COMPILER_PREFIX)as -c

LD = $(COMPILER_PREFIX)ld $(LINKER_FILE) -g

OBJCOPY = $(COMPILER_PREFIX)objcopy --strip-all -O binary

C_SOURCES = $(wildcard ./kernel/*.c ./lib/*.c)
AS_SOURCES = $(wildcard ./bootloader/*.s)

OBJECTS = $(patsubst %.c, %.o, $(C_SOURCES))
OBJECTS += $(patsubst %.s, %.o, $(AS_SOURCES))

.PHONY :
all : $(OBJECTS)
	$(LD) $(OBJECTS) -o $(BUILD_DIR)/$(TARGET)
	$(OBJCOPY) $(BUILD_BIR)/$(TARGET) $(BUILD_DIR)/$(TARGET).bin

.PHONY :
clean :
	rm $(OBJECTS)

%.o : %.s
	$(AS) $^ -o $@

%.o : %.c
	$(CC) $^ -o $@

%(TARGET) : %(OBJECTS)
