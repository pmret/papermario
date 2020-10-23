### Build Options ###

# Override these options in settings.mk or with `make SETTING=value'.

BASEROM = baserom.z64
TARGET = papermario
COMPARE = 1
NON_MATCHING = 0

-include settings.mk

# Fail early if baserom does not exist
ifeq ($(wildcard $(BASEROM)),)
$(error Baserom `$(BASEROM)' not found.)
endif


### Sources ###

include sources.mk


### Output ###

BUILD_DIR = build
ROM = $(TARGET).z64
ELF = $(BUILD_DIR)/$(TARGET).elf
LD_SCRIPT = $(TARGET).ld
LD_MAP = $(BUILD_DIR)/$(TARGET).map

ifdef ASSETS_FS
ASSETS_FS_OBJ = $(BUILD_DIR)/$(ASSETS_FS).o
endif


### Tools ###

PYTHON = python3
N64CKSUM = tools/n64crc
SPLAT_YAML = tools/splat.yaml
SPLAT = $(PYTHON) tools/n64splat/split.py $(BASEROM) $(SPLAT_YAML) .
YAY0COMPRESS = tools/Yay0compress
BUILD_ASSETS_FS := $(PYTHON) tools/build_assets_fs.py $(ASSETS_FS) $(BUILD_DIR)/$(ASSETS_FS)

ifndef EMULATOR
ifneq ($(shell command -v mupen64plus-gui),)
EMULATOR = mupen64plus-gui
else
EMULATOR = mupen64plus
endif
endif


### Compiler Options ###

CROSS = mips-linux-gnu-
AS = $(CROSS)as
OLD_AS = tools/mips-nintendo-nu64-as
CC = tools/cc1
CPP = cpp
LD = $(CROSS)ld
OBJCOPY = $(CROSS)objcopy

CPPFLAGS   = -Iinclude -Isrc -D _LANGUAGE_C -ffreestanding -DF3DEX_GBI_2
ASFLAGS    = -EB -Iinclude -march=vr4300 -mtune=vr4300
OLDASFLAGS = -EB -Iinclude -G 0
CFLAGS     = -O2 -quiet -G 0 -mcpu=vr4300 -mfix4300 -mips3 -mgp32 -mfp32 -Wimplicit -Wuninitialized -Wshadow
LDFLAGS    = -T undefined_syms.txt -T undefined_funcs.txt -T $(LD_SCRIPT) -Map $(LD_MAP) --no-check-sections


### Targets ###

clean:
	rm -rf $(BUILD_DIR)

setup: clean submodules split

submodules:
	git submodule update --init --recursive

split:
	rm -rf bin assets
	$(SPLAT) --modes ld bin Yay0 PaperMarioMapFS

split-all:
	rm -rf bin assets
	$(SPLAT) --modes all

test: $(ROM)
ifdef EMULATOR
	$(EMULATOR) $<
else
	@echo "N64 emulator not detected." && false
endif

$(LD_SCRIPT): $(SPLAT_YAML)
	$(SPLAT) --modes ld

$(ROM): $(BUILD_DIR)/$(TARGET).bin
	@cp $< $@
ifeq ($(COMPARE),1)
	@sha1sum -c checksum.sha1 || (echo 'The build succeeded, but did not match the base ROM. This is expected if you are making changes to the game. To skip this check, use "make COMPARE=0".' && false)
endif

$(BUILD_DIR)/$(TARGET).bin: $(BUILD_DIR)/$(TARGET).elf
	$(OBJCOPY) $< $@ -O binary

$(BUILD_DIR)/$(TARGET).elf: $(LD_SCRIPT) $(OBJECTS) $(ASSETS_FS_OBJ)
	$(LD) $(LDFLAGS) -o $@

# `make print-VARNAME' to print the value of $(VARNAME)
print-%: ; $(info $* is a $(flavor $*) variable set to [$($*)]) @true


### Object Targets (see sources.mk) ###

ifndef OBJECTS
$(warning OBJECTS is not defined by `sources.mk'.)
else

# C
$(filter %.c.o,$(OBJECTS)): $(BUILD_DIR)/%.c.o: %.c
	@mkdir -p $(shell dirname $@)
	cpp $(CPPFLAGS) $< | $(CC) $(CFLAGS) -o - | $(OLD_AS) $(OLDASFLAGS) - -o $@

# Assembly
$(filter %.s.o,$(OBJECTS)): $(BUILD_DIR)/%.s.o: %.s
	@mkdir -p $(shell dirname $@)
	$(AS) $(ASFLAGS) -o $@ $<

# Uncompressed data
$(filter %.bin.o,$(OBJECTS)): $(BUILD_DIR)/%.bin.o: %.bin
	@mkdir -p $(shell dirname $@)
	$(LD) -r -b binary -o $@ $<

# Compressed data
$(filter %.Yay0.o,$(OBJECTS)): $(BUILD_DIR)/%.Yay0.o: %.bin
	@mkdir -p $(shell dirname $@)
	$(YAY0COMPRESS) $< $(BUILD_DIR)/$*.Yay0
	$(LD) -r -b binary -o $@ $(BUILD_DIR)/$*.Yay0

endif


### Asset Filesystem (see sources.mk) ###

# Complain if ASSETS_FS_SOURCES is undefined but ASSETS_FS is.
ifndef ASSETS_FS_SOURCES
ifdef ASSETS_FS
$(warning ASSETS_FS_SOURCES is not defined by `sources.mk' but ASSETS_FS is.)
endif
else

$(BUILD_DIR)/$(ASSETS_FS)/%: $(ASSETS_FS)/%
	@mkdir -p $(shell dirname $@)
	@rm -f $@
	$(BUILD_ASSETS_FS) $*

$(ASSETS_FS_OBJ): $(ASSETS_FS).json $(foreach file,$(ASSETS_FS_SOURCES),$(BUILD_DIR)/$(file))
	$(BUILD_ASSETS_FS)
	$(LD) -r -b binary -o $@ $(BUILD_DIR)/$(ASSETS_FS).bin

endif


### Make Settings ###

.PHONY: clean test setup submodules split $(ROM)
.DEFAULT_GOAL := $(ROM)

# Remove built-in implicit rules to improve performance
MAKEFLAGS += --no-builtin-rules
