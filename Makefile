# Makefile to rebuild SM64 split image

SHELL=/bin/bash -o pipefail

################ Target Executable and Sources ###############

# BUILD_DIR is location where all build artifacts are placed
BUILD_DIR = build

SRC_DIRS := src src/os src/os/nusys
ASM_DIRS := asm asm/os
INCLUDE_DIRS := include include/PR src
DATA_DIRS := bin

# Source code files
C_FILES := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
S_FILES := $(foreach dir,$(ASM_DIRS),$(wildcard $(dir)/*.s))
ifdef PM_HEADER_REBUILD
	H_FILES := $(foreach dir,$(INCLUDE_DIRS),$(wildcard $(dir)/*.h))
endif
DATA_FILES := $(foreach dir,$(DATA_DIRS),$(wildcard $(dir)/*.bin))

# Object files
O_FILES := $(foreach file,$(C_FILES),$(BUILD_DIR)/$(file:.c=.o)) \
           $(foreach file,$(S_FILES),$(BUILD_DIR)/$(file:.s=.o)) \
           $(foreach file,$(DATA_FILES),$(BUILD_DIR)/$(file:.bin=.o)) \


####################### Other Tools #########################

# N64 tools
TOOLS_DIR = tools
MIO0TOOL = $(TOOLS_DIR)/mio0
N64CKSUM = $(TOOLS_DIR)/n64crc

##################### Compiler Options #######################
CROSS = mips-linux-gnu-
CROSS_IRIX = mips-sgi-irix5-
AS = $(CROSS)as
OLD_AS = $(TOOLS_DIR)/mips-nintendo-nu64-as
CC = $(TOOLS_DIR)/cc1
LD = $(CROSS)ld
OBJDUMP = $(CROSS)objdump
OBJCOPY = $(CROSS)objcopy

TARGET = papermario

CPPFLAGS   = -Iinclude -D _LANGUAGE_C -ffreestanding -DF3DEX_GBI_2
ASFLAGS    = -EB -Iinclude -march=vr4300 -mtune=vr4300
OLDASFLAGS = -EB -Iinclude -G 0
CFLAGS     = -O2 -quiet -G 0 -mcpu=vr4300 -mfix4300 -mips3 -mgp32 -mfp32
LDFLAGS    = -T undefined_syms.txt -T $(LD_SCRIPT) -Map $(BUILD_DIR)/papermario.map --no-check-sections

######################## Targets #############################

$(foreach dir,$(SRC_DIRS) $(ASM_DIRS) $(DATA_DIRS) ,$(shell mkdir -p build/$(dir)))

default: all

LD_SCRIPT = $(TARGET).ld

all: $(TARGET).ld $(BUILD_DIR) $(TARGET).z64 verify

clean:
	rm -rf $(BUILD_DIR) $(TARGET).z64

submodules:
	git submodule update --init --recursive

split:
	rm -rf $(DATA_DIRS) && ./tools/n64splat/split.py baserom.z64 tools/splat.yaml . --modes ld bin

$(TARGET).ld: tools/splat.yaml
	./tools/n64splat/split.py baserom.z64 tools/splat.yaml . --modes ld

setup: clean submodules split

print-% : ; $(info $* is a $(flavor $*) variable set to [$($*)]) @true

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/$(TARGET).elf: $(O_FILES) $(LD_SCRIPT)
	@$(LD) $(LDFLAGS) -o $@ $(O_FILES)

$(BUILD_DIR)/%.o: %.s
	$(AS) $(ASFLAGS) -o $@ $<

$(BUILD_DIR)/%.o: %.c $(H_FILES)
	cpp $(CPPFLAGS) $< | $(CC) $(CFLAGS) -o - | $(OLD_AS) $(OLDASFLAGS) - -o $@

$(BUILD_DIR)/%.o: %.bin
	$(LD) -r -b binary -o $@ $<

$(BUILD_DIR)/$(TARGET).bin: $(BUILD_DIR)/$(TARGET).elf
	$(OBJCOPY) $< $@ -O binary

# final z64 updates checksum
$(TARGET).z64: $(BUILD_DIR)/$(TARGET).bin
	@cp $< $@
	$(N64CKSUM) $@

verify: $(TARGET).z64
	sha1sum -c checksum.sha1

.PHONY: all clean default
