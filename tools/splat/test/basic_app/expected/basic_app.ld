SECTIONS
{
    __romPos = 0;
    _gp = 0x0;
    header_ROM_START = __romPos;
    header_VRAM = ADDR(.header);
    .header : AT(header_ROM_START) SUBALIGN(16)
    {
        FILL(0x00000000);
        header_DATA_START = .;
        header_s = .;
        build/split/asm/header.s.o(.data);
        header_DATA_END = .;
        header_DATA_SIZE = ABSOLUTE(header_DATA_END - header_DATA_START);
    }
    __romPos += SIZEOF(.header);
    header_ROM_END = __romPos;
    header_VRAM_END = .;

    dummy_ipl3_ROM_START = __romPos;
    dummy_ipl3_VRAM = ADDR(.dummy_ipl3);
    .dummy_ipl3 0xA4000040 : AT(dummy_ipl3_ROM_START) SUBALIGN(16)
    {
        FILL(0x00000000);
        dummy_ipl3_DATA_START = .;
        dummy_ipl3_bin = .;
        build/split/assets/dummy_ipl3.bin.o(.data);
        dummy_ipl3_DATA_END = .;
        dummy_ipl3_DATA_SIZE = ABSOLUTE(dummy_ipl3_DATA_END - dummy_ipl3_DATA_START);
    }
    __romPos += SIZEOF(.dummy_ipl3);
    __romPos = ALIGN(__romPos, 16);
    dummy_ipl3_ROM_END = __romPos;
    dummy_ipl3_VRAM_END = .;

    boot_ROM_START = __romPos;
    boot_VRAM = ADDR(.boot);
    .boot 0x80000400 : AT(boot_ROM_START) SUBALIGN(16)
    {
        FILL(0x00000000);
        boot_TEXT_START = .;
        build/split/src/main.c.o(.text);
        build/split/asm/handwritten.s.o(.text);
        boot_TEXT_END = .;
        boot_TEXT_SIZE = ABSOLUTE(boot_TEXT_END - boot_TEXT_START);
        boot_DATA_START = .;
        main_data__s = .;
        build/split/asm/data/main.data.s.o(.data);
        boot_DATA_END = .;
        boot_DATA_SIZE = ABSOLUTE(boot_DATA_END - boot_DATA_START);
        boot_RODATA_START = .;
        build/split/asm/data/main.rodata.s.o(.rodata);
        boot_RODATA_END = .;
        boot_RODATA_SIZE = ABSOLUTE(boot_RODATA_END - boot_RODATA_START);
    }
    boot_bss_VRAM = ADDR(.boot_bss);
    .boot_bss (NOLOAD) : SUBALIGN(16)
    {
        FILL(0x00000000);
        boot_BSS_START = .;
        build/split/asm/data/main.bss.s.o(.bss);
        boot_BSS_END = .;
        boot_BSS_SIZE = ABSOLUTE(boot_BSS_END - boot_BSS_START);
    }
    __romPos += SIZEOF(.boot);
    __romPos = ALIGN(__romPos, 16);
    boot_ROM_END = __romPos;
    boot_VRAM_END = .;

    /DISCARD/ :
    {
        *(*);
    }
}
