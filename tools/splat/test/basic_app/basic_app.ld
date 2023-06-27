SECTIONS
{
    __romPos = 0;
    _gp = 0x0;
    header_ROM_START = __romPos;
    header_VRAM = ADDR(.header);
    .header : AT(header_ROM_START) SUBALIGN(16)
    {
        header_DATA_START = .;
        build/header.o(.data);
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
        dummy_ipl3_DATA_START = .;
        build/dummy_ipl3.o(.data);
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
        boot_TEXT_START = .;
        build/main.o(.text);
        build/handwritten.o(.text);
        boot_TEXT_END = .;
        boot_TEXT_SIZE = ABSOLUTE(boot_TEXT_END - boot_TEXT_START);

        boot_DATA_START = .;
        build/main.o(.data);
        build/handwritten.o(.data);
        boot_DATA_END = .;
        boot_DATA_SIZE = ABSOLUTE(boot_DATA_END - boot_DATA_START);

        boot_RODATA_START = .;
        build/main.o(.rodata);
        build/handwritten.o(.rodata);
        boot_RODATA_END = .;
        boot_RODATA_SIZE = ABSOLUTE(boot_RODATA_END - boot_RODATA_START);
    }

    boot_bss_VRAM = ADDR(.boot_bss);
    .boot_bss (NOLOAD) : SUBALIGN(16)
    {
        boot_BSS_START = .;
        build/main.o(.bss);
        build/main.o(.scommon);
        build/main.o(COMMON);
        build/handwritten.o(.bss);
        build/handwritten.o(.scommon);
        build/handwritten.o(COMMON);
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
