SHELL=/bin/bash -o pipefail

################ Target Executable and Sources ###############

# BUILD_DIR is location where all build artifacts are placed
BUILD_DIR = build

WORLD_AREAS := $(foreach dir, $(wildcard src/world/*), $(dir:src/world/%=%))

SRC_DIRS := src src/os src/os/nusys $(foreach area,$(WORLD_AREAS),src/world/$(area))
ASM_DIRS := asm asm/os
INCLUDE_DIRS := include include/PR src
DATA_DIRS := bin bin/world $(foreach area,$(WORLD_AREAS),bin/world/$(area))
YAY0_DIRS := bin/Yay0
ASSETS_FS_DIRS := assets/fs

# Source code files
C_FILES := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
S_FILES := $(foreach dir,$(ASM_DIRS),$(wildcard $(dir)/*.s))
ifdef PM_HEADER_REBUILD
	H_FILES := $(foreach dir,$(INCLUDE_DIRS),$(wildcard $(dir)/*.h))
endif
DATA_FILES := $(foreach dir,$(DATA_DIRS),$(wildcard $(dir)/*.bin))
YAY0_FILES := $(foreach dir,$(YAY0_DIRS),$(wildcard $(dir)/*.bin))
ASSETS_FS_FILES := $(foreach dir,$(ASSETS_FS_DIRS),$(wildcard $(dir)/*.*))

# Object files
O_FILES := $(foreach file,$(C_FILES),$(BUILD_DIR)/$(file:.c=.o)) \
		   $(foreach file,$(S_FILES),$(BUILD_DIR)/$(file:.s=.o)) \
		   $(foreach file,$(DATA_FILES),$(BUILD_DIR)/$(file:.bin=.o)) \
		   $(foreach dir,$(ASSETS_FS_DIRS),$(BUILD_DIR)/$(dir).o) \
		   $(foreach file,$(YAY0_FILES),$(BUILD_DIR)/$(file:.bin=.Yay0.o))

####################### Tools #########################

TOOLS = tools
N64CKSUM = $(TOOLS)/n64crc
SPLAT = ./$(TOOLS)/n64splat/split.py baserom.z64 $(TOOLS)/splat.yaml .

##################### Compiler Options #######################
CROSS = mips-linux-gnu-
AS = $(CROSS)as
OLD_AS = $(TOOLS)/mips-nintendo-nu64-as
CC = $(TOOLS)/cc1
LD = $(CROSS)ld
OBJDUMP = $(CROSS)objdump
OBJCOPY = $(CROSS)objcopy

TARGET = papermario

CPPFLAGS   = -Iinclude -Isrc -D _LANGUAGE_C -ffreestanding -DF3DEX_GBI_2
ASFLAGS    = -EB -Iinclude -march=vr4300 -mtune=vr4300
OLDASFLAGS = -EB -Iinclude -G 0
CFLAGS     = -O2 -quiet -G 0 -mcpu=vr4300 -mfix4300 -mips3 -mgp32 -mfp32
LDFLAGS    = -T undefined_syms.txt -T undefined_funcs.txt -T $(LD_SCRIPT) -Map $(BUILD_DIR)/papermario.map --no-check-sections

######################## Targets #############################

$(foreach dir,$(SRC_DIRS) $(ASM_DIRS) $(DATA_DIRS) $(ASSETS_FS_DIRS) ,$(shell mkdir -p build/$(dir)))

default: all

LD_SCRIPT = $(TARGET).ld

all: $(TARGET).ld $(BUILD_DIR) $(TARGET).z64 verify

clean:
	rm -rf $(BUILD_DIR) $(TARGET).z64

submodules:
	git submodule update --init --recursive

split:
	rm -rf $(DATA_DIRS) && $(SPLAT) --modes ld bin Yay0 PaperMarioMapFS

split-all:
	rm -rf $(DATA_DIRS) && $(SPLAT) --modes all

setup: clean submodules split
	make -C $(TOOLS)

print-% : ; $(info $* is a $(flavor $*) variable set to [$($*)]) @true

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: %.s
	$(AS) $(ASFLAGS) -o $@ $<

$(BUILD_DIR)/%.o: %.c $(H_FILES)
	cpp $(CPPFLAGS) $< | $(CC) $(CFLAGS) -o - | $(OLD_AS) $(OLDASFLAGS) - -o $@

$(BUILD_DIR)/%.o: %.bin
	$(LD) -r -b binary -o $@ $<

$(BUILD_DIR)/assets/fs/%: $(ASSETS_FS_FILES)
	$(TOOLS)/build_assets_fs.py $*

$(BUILD_DIR)/assets/fs.bin: assets/fs.json $(TOOLS)/build_assets_fs.py $(foreach file,$(ASSETS_FS_FILES),build/$(file))
	$(TOOLS)/build_assets_fs.py

$(BUILD_DIR)/assets/fs.o: $(BUILD_DIR)/assets/fs.bin
	$(LD) -r -b binary -o $@ $<

$(BUILD_DIR)/%.Yay0.o: %.bin
	mkdir -p build/bin/Yay0
	$(TOOLS)/Yay0compress $< $<.Yay0
	$(LD) -r -b binary -o $@ $<.Yay0

$(LD_SCRIPT): $(TOOLS)/splat.yaml
	$(SPLAT) --modes ld

$(BUILD_DIR)/$(TARGET).elf: $(O_FILES) $(LD_SCRIPT)
	@$(LD) $(LDFLAGS) -o $@ $(O_FILES)

$(BUILD_DIR)/$(TARGET).bin: $(BUILD_DIR)/$(TARGET).elf
	$(OBJCOPY) $< $@ -O binary

# final z64 updates checksum
$(TARGET).z64: $(BUILD_DIR)/$(TARGET).bin
	@cp $< $@
	$(N64CKSUM) $@

verify: $(TARGET).z64
	sha1sum -c checksum.sha1

.PHONY: all clean default
