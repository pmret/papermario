# Makefile to rebuild SM64 split image

SHELL=/bin/bash -o pipefail

################ Target Executable and Sources ###############

# BUILD_DIR is location where all build artifacts are placed
BUILD_DIR = build

SRC_DIRS := src
ASM_DIRS := asm
DATA_DIRS := bin
COMPRESSED_DIRS := yay0
MAP_DIRS := Map_Assets.FS
BGM_DIRS := bgm

# Source code files
C_FILES := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
S_FILES := $(foreach dir,$(ASM_DIRS),$(wildcard $(dir)/*.s))
DATA_FILES := $(foreach dir,$(DATA_DIRS),$(wildcard $(dir)/*.bin))
COMPRESSED_FILES := $(foreach dir,$(COMPRESSED_DIRS),$(wildcard $(dir)/*.yay0)) 
MAP_FILES := $(foreach dir,$(MAP_DIRS),$(wildcard $(dir)/*.FS)) 
BGM_FILES := $(foreach dir,$(BGM_DIRS),$(wildcard $(dir)/*.bgm))

# Object files
O_FILES := $(foreach file,$(C_FILES),$(BUILD_DIR)/$(file:.c=.o)) \
           $(foreach file,$(S_FILES),$(BUILD_DIR)/$(file:.s=.o)) \
           $(foreach file,$(DATA_FILES),$(BUILD_DIR)/$(file:.bin=.o)) \
           $(foreach file,$(COMPRESSED_FILES),$(BUILD_DIR)/$(file:.yay0=.yay0.o)) \
           $(foreach file,$(MAP_FILES),$(BUILD_DIR)/$(file:.FS=.FS.o)) \
           $(foreach file,$(BGM_FILES),$(BUILD_DIR)/$(file:.bgm=.bgm.o))

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
LD = $(CROSS_IRIX)ld
OBJDUMP = $(CROSS)objdump
OBJCOPY = $(CROSS)objcopy

ASFLAGS = -EB -march=vr4300 -mtune=vr4300
CFLAGS  = -O2 -quiet
LDFLAGS = -T undefined_syms.txt -T $(LD_SCRIPT) -Map $(BUILD_DIR)/papermario.map --no-check-sections

######################## Targets #############################

$(foreach dir,$(SRC_DIRS) $(ASM_DIRS) $(DATA_DIRS) $(COMPRESSED_DIRS) $(MAP_DIRS) $(BGM_DIRS),$(shell mkdir -p build/$(dir)))

default: all

TARGET = papermario
LD_SCRIPT = $(TARGET).ld

all: fix_asm $(BUILD_DIR) $(TARGET).z64 verify

clean:
	rm -rf build
	rm -f papermario.z64

print-% : ; $(info $* is a $(flavor $*) variable set to [$($*)]) @true

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

$(BUILD_DIR)/$(TARGET).elf: $(O_FILES) $(LD_SCRIPT)
	@$(LD) $(LDFLAGS) -o $@ $(O_FILES)

$(BUILD_DIR)/%.o: %.s
	$(AS) $(ASFLAGS) -o $@ $<

$(BUILD_DIR)/%.o: %.c
	cpp $< | $(CC) $(CFLAGS) -o - | $(OLD_AS) - -o $@

$(BUILD_DIR)/%.o: %.bin
	$(LD) -r -b binary -o $@ $<

$(BUILD_DIR)/%.yay0.o: %.yay0
	$(LD) -r -b binary -o $@ $<

$(BUILD_DIR)/%.FS.o: %.FS
	$(LD) -r -b binary -o $@ $<

$(BUILD_DIR)/%.bgm.o: %.bgm
	$(LD) -r -b binary -o $@ $<

$(BUILD_DIR)/$(TARGET).bin: $(BUILD_DIR)/$(TARGET).elf
	$(OBJCOPY) $< $@ -O binary

# final z64 updates checksum
$(TARGET).z64: $(BUILD_DIR)/$(TARGET).bin
	@cp $< $@
	$(N64CKSUM) $@

fix_asm:
	@./fix_asm.py

verify: $(TARGET).z64
	sha1sum -c checksum.sha1

.PHONY: all clean default diff test
