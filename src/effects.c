#include "common.h"
#include "ld_addrs.h"

typedef s32 TlbEntry[0x1000 / 4];
typedef TlbEntry TlbMappablePage[15];

extern TlbMappablePage D_80197000;
<<<<<<< HEAD
extern EffectTableEntry gEffectTable[135];

#define EFFECT_LOADED 1

extern void* D_80059C80;
=======

#define EFFECT_LOADED 1

>>>>>>> misc-decomp
extern EffectGraphics gEffectGraphicsData[15];
extern EffectInstance* gEffectInstances[96];
extern s32 D_801A6000;

<<<<<<< HEAD
EffectTableEntry gEffectTable[] = {
    { 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 }, // 0
    { 0xE0002000, 0x003278F0, 0x00328110, 0xE0002000, 0x00326410, 0x003278F0 }, // 1
    { 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 }, // 2
    { 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 }, // 3
    { 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 }, // 4
    { 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 }, // 5
    { 0xE000C160, 0x00328110, 0x00328EA0, 0xE000C000, 0x00328EA0, 0x0032C110 }, // 6
    { 0xE000E000, 0x0032C110, 0x0032C7A0, 0xE000E000, 0x00328EA0, 0x0032C110 }, // 7
    { 0xE00101E8, 0x0032C7A0, 0x0032CEC0, 0xE0010000, 0x0032CEC0, 0x0032DD10 }, // 8
    { 0xE0012204, 0x0032DD10, 0x0032E490, 0xE0012000, 0x0032CEC0, 0x0032DD10 }, // 9
    { 0xE0014000, 0x0032E490, 0x0032EC50, 0xE0014000, 0x0032EC50, 0x0032EE30 }, // 10
    { 0xE0016000, 0x0032EE30, 0x0032F580, 0xE0016000, 0x0032EC50, 0x0032EE30 }, // 11
    { 0xE0018078, 0x0032F580, 0x0032FB50, 0xE0018000, 0x0032FB50, 0x0032FE30 }, // 12
    { 0xE001A000, 0x0032FE30, 0x00330460, 0xE001A000, 0x00330460, 0x00330910 }, // 13
    { 0xE001C000, 0x00330910, 0x00330F00, 0xE001C000, 0x00330F00, 0x00331940 }, // 14
    { 0xE001E000, 0x00331940, 0x003326A0, 0xE001E000, 0x003326A0, 0x00333EC0 }, // 15
    { 0xE00202CC, 0x00333EC0, 0x00334C70, 0xE0020000, 0x00334C70, 0x00337240 }, // 16
    { 0xE0022000, 0x00337240, 0x00337FC0, 0xE0022000, 0x00337FC0, 0x00339250 }, // 17
    { 0xE0024000, 0x00339250, 0x00339F60, 0xE0024000, 0x00339F60, 0x0033B180 }, // 18
    { 0xE0026000, 0x0033B180, 0x0033BBD0, 0xE0026000, 0x0033BBD0, 0x0033CDF0 }, // 19
    { 0xE0028000, 0x0033CDF0, 0x0033D610, 0xE0028000, 0x0033D610, 0x0033E8C0 }, // 20
    { 0xE002A000, 0x0033E8C0, 0x0033F000, 0xE002A000, 0x0033F000, 0x0033FE80 }, // 21
    { 0xE002C000, 0x0033FE80, 0x00340880, 0xE002C000, 0x00340880, 0x003419E0 }, // 22
    { 0xE002E000, 0x003419E0, 0x00342140, 0xE002E000, 0x00328EA0, 0x0032C110 }, // 23
    { 0xE0030000, 0x00342140, 0x00343040, 0xE0030000, 0x00343040, 0x00343680 }, // 24
    { 0xE0032000, 0x00343680, 0x00343F70, 0xE0032000, 0x00343F70, 0x00344A10 }, // 25
    { 0xE0034000, 0x00344A10, 0x003451E0, 0xE0034000, 0x003451E0, 0x003454E0 }, // 26
    { 0xE0036000, 0x003454E0, 0x00345B40, 0xE0036000, 0x00345B40, 0x0034DD20 }, // 27
    { 0xE0038000, 0x0034DD20, 0x0034E770, 0xE0038000, 0x0034E770, 0x0034EC80 }, // 28
    { 0xE003A000, 0x0034EC80, 0x0034F4C0, 0xE003A000, 0x00328EA0, 0x0032C110 }, // 29
    { 0xE003C000, 0x0034F4C0, 0x00350220, 0xE003C000, 0x00350220, 0x00352440 }, // 30
    { 0xE003E000, 0x00352440, 0x00352CE0, 0xE003E000, 0x00352CE0, 0x00353300 }, // 31
    { 0xE0040000, 0x00353300, 0x00353BB0, 0xE0040000, 0x00353BB0, 0x003547A0 }, // 32
    { 0xE0042000, 0x003547A0, 0x00354F60, 0xE0042000, 0x00343040, 0x00343680 }, // 33
    { 0xE0044000, 0x00354F60, 0x00355EE0, 0xE0044000, 0x00337FC0, 0x00339250 }, // 34
    { 0xE0046000, 0x00355EE0, 0x00356530, 0xE0046000, 0x00356530, 0x00356980 }, // 35
    { 0xE0048000, 0x00356980, 0x003573A0, 0xE0048000, 0x003573A0, 0x003584C0 }, // 36
    { 0xE004A000, 0x003584C0, 0x003593B0, 0xE004A000, 0x003593B0, 0x00359F20 }, // 37
    { 0xE004C000, 0x00359F20, 0x0035A5E0, 0xE004C000, 0x0035A5E0, 0x0035B9D0 }, // 38
    { 0xE004E000, 0x0035B9D0, 0x0035BFD0, 0xE004E000, 0x00328EA0, 0x0032C110 }, // 39
    { 0xE0050000, 0x0035BFD0, 0x0035C550, 0xE0050000, 0x0035C550, 0x0035CA80 }, // 40
    { 0xE0052000, 0x0035CA80, 0x0035D510, 0xE0052000, 0x0035D510, 0x0035DA00 }, // 41
    { 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 }, // 42
    { 0xE0056000, 0x0035DA00, 0x0035E920, 0xE0056000, 0x0033D610, 0x0033E8C0 }, // 43
    { 0xE0058000, 0x0035E920, 0x0035F0E0, 0xE0058000, 0x0035F0E0, 0x003602C0 }, // 44
    { 0xE005A000, 0x003602C0, 0x00360A30, 0xE005A000, 0x00360A30, 0x00360F40 }, // 45
    { 0xE005C000, 0x00360F40, 0x00361670, 0xE005C000, 0x00361670, 0x003625C0 }, // 46
    { 0xE005E000, 0x003625C0, 0x00362C50, 0xE005E000, 0x00362C50, 0x00363160 }, // 47
    { 0xE0060000, 0x00363160, 0x003638C0, 0xE0060000, 0x003638C0, 0x00364300 }, // 48
    { 0xE0062000, 0x00364300, 0x00364C00, 0xE0062000, 0x00364C00, 0x00364F10 }, // 49
    { 0xE0064000, 0x00364F10, 0x003659B0, 0xE0064000, 0x003659B0, 0x00366030 }, // 50
    { 0xE0066000, 0x00366030, 0x00366D60, 0xE0066000, 0x00366D60, 0x0036A8D0 }, // 51
    { 0xE0068000, 0x0036A8D0, 0x0036AEE0, 0xE0068000, 0x0036AEE0, 0x0036D020 }, // 52
    { 0xE006A1E8, 0x0036D020, 0x0036DF90, 0xE006A000, 0x0036DF90, 0x0036E1D0 }, // 53
    { 0xE006C000, 0x0036E1D0, 0x0036ED60, 0xE006C000, 0x0036ED60, 0x00372790 }, // 54
    { 0xE006E000, 0x00372790, 0x003733E0, 0xE006E000, 0x003733E0, 0x003740B0 }, // 55
    { 0xE0070000, 0x003740B0, 0x00374E50, 0xE0070000, 0x00337FC0, 0x00339250 }, // 56
    { 0xE0072000, 0x00374E50, 0x00375510, 0xE0072000, 0x00375510, 0x00376460 }, // 57
    { 0xE0074000, 0x00376460, 0x00377070, 0xE0074000, 0x00337FC0, 0x00339250 }, // 58
    { 0xE0076000, 0x00377070, 0x00377F80, 0xE0076000, 0x00377F80, 0x0037A3F0 }, // 59
    { 0xE0078000, 0x0037A3F0, 0x0037ADD0, 0xE0078000, 0x0037ADD0, 0x0037C540 }, // 60
    { 0xE007A000, 0x0037C540, 0x0037D180, 0xE007A000, 0x0037D180, 0x0037D490 }, // 61
    { 0xE007C000, 0x0037D490, 0x0037D9D0, 0xE007C000, 0x0037D9D0, 0x0037F720 }, // 62
    { 0xE007E000, 0x0037F720, 0x003803A0, 0xE007E000, 0x003803A0, 0x003812C0 }, // 63
    { 0xE0080000, 0x003812C0, 0x00381E00, 0xE0080000, 0x00381E00, 0x00385640 }, // 64
    { 0xE0082000, 0x00385640, 0x003863B0, 0xE0082000, 0x003863B0, 0x003889D0 }, // 65
    { 0xE0084084, 0x003889D0, 0x00389850, 0xE0084000, 0x0037D9D0, 0x0037F720 }, // 66
    { 0xE0086000, 0x00389850, 0x0038A350, 0xE0086000, 0x0038A350, 0x0038ADF0 }, // 67
    { 0xE008817C, 0x0038ADF0, 0x0038BBA0, 0xE0088000, 0x0038BBA0, 0x0038C5F0 }, // 68
    { 0xE008A188, 0x0038C5F0, 0x0038D070, 0xE008A000, 0x0038D070, 0x0038DE00 }, // 69
    { 0xE008C000, 0x0038DE00, 0x0038E990, 0xE008C000, 0x0038E990, 0x0038EE60 }, // 70
    { 0xE008E000, 0x0038EE60, 0x0038F710, 0xE008E000, 0x0038F710, 0x0038F900 }, // 71
    { 0xE0090000, 0x0038F900, 0x003903D0, 0xE0090000, 0x003903D0, 0x00391D30 }, // 72
    { 0xE0092000, 0x00391D30, 0x00392440, 0xE0092000, 0x00392440, 0x003928D0 }, // 73
    { 0xE0094000, 0x003928D0, 0x003930A0, 0xE0094000, 0x003930A0, 0x00394280 }, // 74
    { 0xE0096000, 0x00394280, 0x00394670, 0xE0096000, 0x00394670, 0x00395BB0 }, // 75
    { 0xE0098000, 0x00395BB0, 0x003960F0, 0xE0098000, 0x003960F0, 0x003965B0 }, // 76
    { 0xE009A000, 0x003965B0, 0x00397040, 0xE009A000, 0x00397040, 0x003981F0 }, // 77
    { 0xE009C000, 0x003981F0, 0x00398BC0, 0xE009C000, 0x00398BC0, 0x0039FF20 }, // 78
    { 0xE009E000, 0x0039FF20, 0x003A0D60, 0xE009E000, 0x003A0D60, 0x003A2290 }, // 79
    { 0xE00A0000, 0x003A2290, 0x003A2440, 0xE00A0000, 0x003A2440, 0x003A2990 }, // 80
    { 0xE00A2000, 0x003A2990, 0x003A33D0, 0xE00A2000, 0x003A33D0, 0x003A37E0 }, // 81
    { 0xE00A4000, 0x003A37E0, 0x003A4320, 0xE00A4000, 0x003A4320, 0x003A5550 }, // 82
    { 0xE00A6000, 0x003A5550, 0x003A5BE0, 0xE00A6000, 0x003A5BE0, 0x003A70F0 }, // 83
    { 0xE00A8000, 0x003A70F0, 0x003A77A0, 0xE00A8000, 0x003A77A0, 0x003AA920 }, // 84
    { 0xE00AA000, 0x003AA920, 0x003AB030, 0xE00AA000, 0x003AB030, 0x003AEE20 }, // 85
    { 0xE00AC000, 0x003AEE20, 0x003AF700, 0xE00AC000, 0x003AF700, 0x003B2350 }, // 86
    { 0xE00AE000, 0x003B2350, 0x003B2D90, 0xE00AE000, 0x003B2D90, 0x003B3EB0 }, // 87
    { 0xE00B0000, 0x003B3EB0, 0x003B46A0, 0xE00B0000, 0x003B46A0, 0x003B4790 }, // 88
    { 0xE00B2000, 0x003B4790, 0x003B5340, 0xE00B2000, 0x003B5340, 0x003B5CF0 }, // 89
    { 0xE00B4000, 0x003B5CF0, 0x003B6BF0, 0xE00B4000, 0x003B6BF0, 0x003B7160 }, // 90
    { 0xE00B6000, 0x003B7160, 0x003B78D0, 0xE00B6000, 0x003B78D0, 0x003B7B80 }, // 91
    { 0xE00B8000, 0x003B7B80, 0x003B8860, 0xE00B8000, 0x003B8860, 0x003B8BD0 }, // 92
    { 0xE00BA000, 0x003B8BD0, 0x003B9A70, 0xE00BA000, 0x003B9A70, 0x003BA030 }, // 93
    { 0xE00BC000, 0x003BA030, 0x003BAEA0, 0xE00BC000, 0x003BAEA0, 0x003BBF60 }, // 94
    { 0xE00BE000, 0x003BBF60, 0x003BCA90, 0xE00BE000, 0x003BCA90, 0x003BCD60 }, // 95
    { 0xE00C0000, 0x003BCD60, 0x003BD9A0, 0xE00C0000, 0x003BD9A0, 0x003C11D0 }, // 96
    { 0xE00C2000, 0x003C11D0, 0x003C1BA0, 0xE00C2000, 0x003C1BA0, 0x003CADF0 }, // 97
    { 0xE00C4000, 0x003CADF0, 0x003CB890, 0xE00C4000, 0x003CB890, 0x003CC9E0 }, // 98
    { 0xE00C6000, 0x003CC9E0, 0x003CD6E0, 0xE00C6000, 0x003CD6E0, 0x003CF3A0 }, // 99
    { 0xE00C8000, 0x003CF3A0, 0x003CFAF0, 0xE00C8000, 0x003CFAF0, 0x003D0500 }, // 100
    { 0xE00CA000, 0x003D0500, 0x003D11E0, 0xE00CA000, 0x003D11E0, 0x003D1690 }, // 101
    { 0xE00CC000, 0x003D1690, 0x003D2580, 0xE00CC000, 0x003D2580, 0x003D2AC0 }, // 102
    { 0xE00CE000, 0x003D2AC0, 0x003D3930, 0xE00CE000, 0x003D3930, 0x003D3E20 }, // 103
    { 0xE00D0000, 0x003D3E20, 0x003D4970, 0xE00D0000, 0x003593B0, 0x00359F20 }, // 104
    { 0xE00D2000, 0x003D4970, 0x003D4E90, 0xE00D2000, 0x003D4E90, 0x003D5020 }, // 105
    { 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 }, // 106
    { 0xE00D6000, 0x003D5020, 0x003D5F30, 0xE00D6000, 0x003D5F30, 0x003D67C0 }, // 107
    { 0xE00D8000, 0x003D67C0, 0x003D7040, 0xE00D8000, 0x003D7040, 0x003D7240 }, // 108
    { 0xE00DA000, 0x003D7240, 0x003D7770, 0xE00DA000, 0x003D7770, 0x003D7A70 }, // 109
    { 0xE00DC000, 0x003D7A70, 0x003D80C0, 0xE00DC000, 0x003D80C0, 0x003D8720 }, // 110
    { 0xE00DE000, 0x003D8720, 0x003D9100, 0xE00DE000, 0x003D9100, 0x003DB460 }, // 111
    { 0xE00E0000, 0x003DB460, 0x003DBF40, 0xE00E0000, 0x003DBF40, 0x003DC310 }, // 112
    { 0xE00E2000, 0x003DC310, 0x003DCD50, 0xE00E2000, 0x003DCD50, 0x003DE000 }, // 113
    { 0xE00E4000, 0x003DE000, 0x003DEE60, 0xE00E4000, 0x003DEE60, 0x003E0930 }, // 114
    { 0xE00E6000, 0x003E0930, 0x003E12D0, 0xE00E6000, 0x003E12D0, 0x003E1690 }, // 115
    { 0xE00E8000, 0x003E1690, 0x003E1CD0, 0xE00E8000, 0x003E1CD0, 0x003E1EE0 }, // 116
    { 0xE00EA000, 0x003E1EE0, 0x003E2960, 0xE00EA000, 0x003E2960, 0x003E43A0 }, // 117
    { 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 }, // 118
    { 0xE010A000, 0x003E43A0, 0x003E5350, 0xE010A000, 0x003E5350, 0x003E54C0 }, // 119
    { 0xE010C000, 0x003E54C0, 0x003E5F30, 0xE010C000, 0x003E5F30, 0x003EB4E0 }, // 120
    { 0xE010E32C, 0x003EB4E0, 0x003EBE60, 0xE010E000, 0x003EBE60, 0x003F83F0 }, // 121
    { 0xE0110000, 0x003F83F0, 0x003F8CC0, 0xE0110000, 0x003F8CC0, 0x003F9E50 }, // 122
    { 0xE0112000, 0x003F9E50, 0x003FA4B0, 0xE0112000, 0x003FA4B0, 0x003FEAE0 }, // 123
    { 0xE0114000, 0x003FEAE0, 0x003FF250, 0xE0114000, 0x003FF250, 0x00402640 }, // 124
    { 0xE0116000, 0x00402640, 0x00403400, 0xE0116000, 0x003FA4B0, 0x003FEAE0 }, // 125
    { 0xE0118000, 0x00403400, 0x00403BF0, 0xE0118000, 0x00403BF0, 0x00404220 }, // 126
    { 0xE011A000, 0x00404220, 0x00404F40, 0xE011A000, 0x00404F40, 0x00406B40 }, // 127
    { 0xE011C000, 0x00406B40, 0x00407080, 0xE011C000, 0x00407080, 0x00409990 }, // 128
    { 0xE011E000, 0x00409990, 0x0040A1C0, 0xE011E000, 0x0040A1C0, 0x0040B3F0 }, // 129
    { 0xE0120000, 0x0040B3F0, 0x0040BBA0, 0xE0120000, 0x0040BBA0, 0x0040C5A0 }, // 130
    { 0xE0122000, 0x0040C5A0, 0x0040D290, 0xE0122000, 0x0040D290, 0x00412730 }, // 131
    { 0xE0124000, 0x00412730, 0x00413360, 0xE0124000, 0x00337FC0, 0x00339250 }, // 132
    { 0xE0126000, 0x00413360, 0x00413FA0, 0xE0126000, 0x00413FA0, 0x00414BA0 }, // 133
    { 0xE0128000, 0x00414BA0, 0x00415060, 0xE0128000, 0x00415060, 0x00415D90 }, // 134
=======
#define FX_MAIN(name) void name(s32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 x, f32 y, f32 z);
#define FX_ENTRY(name, gfx_name) { fx_##name##_main, effect_##name##_ROM_START, effect_##name##_ROM_END, \
                                   effect_##name##_VRAM, gfx_name##_ROM_START, gfx_name##_ROM_END }

FX_MAIN(fx_1_main);
FX_MAIN(fx_6_main);
FX_MAIN(fx_7_main);
FX_MAIN(fx_8_main);
FX_MAIN(fx_9_main);
FX_MAIN(fx_10_main);
FX_MAIN(fx_11_main);
FX_MAIN(fx_12_main);
FX_MAIN(fx_13_main);
FX_MAIN(fx_14_main);
FX_MAIN(fx_15_main);
FX_MAIN(fx_16_main);
FX_MAIN(fx_17_main);
FX_MAIN(fx_18_main);
FX_MAIN(fx_19_main);
FX_MAIN(fx_20_main);
FX_MAIN(fx_21_main);
FX_MAIN(fx_22_main);
FX_MAIN(fx_23_main);
FX_MAIN(fx_24_main);
FX_MAIN(fx_25_main);
FX_MAIN(fx_26_main);
FX_MAIN(fx_27_main);
FX_MAIN(fx_28_main);
FX_MAIN(fx_29_main);
FX_MAIN(fx_30_main);
FX_MAIN(fx_31_main);
FX_MAIN(fx_32_main);
FX_MAIN(fx_33_main);
FX_MAIN(fx_34_main);
FX_MAIN(fx_35_main);
FX_MAIN(fx_36_main);
FX_MAIN(fx_37_main);
FX_MAIN(fx_38_main);
FX_MAIN(fx_39_main);
FX_MAIN(fx_40_main);
FX_MAIN(fx_41_main);
FX_MAIN(fx_43_main);
FX_MAIN(fx_44_main);
FX_MAIN(fx_45_main);
FX_MAIN(fx_46_main);
FX_MAIN(fx_47_main);
FX_MAIN(fx_48_main);
FX_MAIN(fx_49_main);
FX_MAIN(fx_50_main);
FX_MAIN(fx_51_main);
FX_MAIN(fx_52_main);
FX_MAIN(fx_53_main);
FX_MAIN(fx_54_main);
FX_MAIN(fx_55_main);
FX_MAIN(fx_56_main);
FX_MAIN(fx_57_main);
FX_MAIN(fx_58_main);
FX_MAIN(fx_59_main);
FX_MAIN(fx_60_main);
FX_MAIN(fx_61_main);
FX_MAIN(fx_62_main);
FX_MAIN(fx_63_main);
FX_MAIN(fx_64_main);
FX_MAIN(fx_65_main);
FX_MAIN(fx_66_main);
FX_MAIN(fx_67_main);
FX_MAIN(fx_68_main);
FX_MAIN(fx_69_main);
FX_MAIN(fx_70_main);
FX_MAIN(fx_71_main);
FX_MAIN(fx_72_main);
FX_MAIN(fx_73_main);
FX_MAIN(fx_74_main);
FX_MAIN(fx_75_main);
FX_MAIN(fx_76_main);
FX_MAIN(fx_77_main);
FX_MAIN(fx_78_main);
FX_MAIN(fx_79_main);
FX_MAIN(fx_80_main);
FX_MAIN(fx_81_main);
FX_MAIN(fx_82_main);
FX_MAIN(fx_83_main);
FX_MAIN(fx_84_main);
FX_MAIN(fx_85_main);
FX_MAIN(fx_86_main);
FX_MAIN(fx_87_main);
FX_MAIN(fx_88_main);
FX_MAIN(fx_89_main);
FX_MAIN(fx_90_main);
FX_MAIN(fx_91_main);
FX_MAIN(fx_92_main);
FX_MAIN(fx_93_main);
FX_MAIN(fx_94_main);
FX_MAIN(fx_95_main);
FX_MAIN(fx_96_main);
FX_MAIN(fx_97_main);
FX_MAIN(fx_98_main);
FX_MAIN(fx_99_main);
FX_MAIN(fx_100_main);
FX_MAIN(fx_101_main);
FX_MAIN(fx_102_main);
FX_MAIN(fx_103_main);
FX_MAIN(fx_104_main);
FX_MAIN(fx_105_main);
FX_MAIN(fx_107_main);
FX_MAIN(fx_108_main);
FX_MAIN(fx_109_main);
FX_MAIN(fx_110_main);
FX_MAIN(fx_111_main);
FX_MAIN(fx_112_main);
FX_MAIN(fx_113_main);
FX_MAIN(fx_114_main);
FX_MAIN(fx_115_main);
FX_MAIN(fx_116_main);
FX_MAIN(fx_117_main);
FX_MAIN(fx_119_main);
FX_MAIN(fx_120_main);
FX_MAIN(fx_121_main);
FX_MAIN(fx_122_main);
FX_MAIN(fx_123_main);
FX_MAIN(fx_124_main);
FX_MAIN(fx_125_main);
FX_MAIN(fx_126_main);
FX_MAIN(fx_127_main);
FX_MAIN(fx_128_main);
FX_MAIN(fx_129_main);
FX_MAIN(fx_130_main);
FX_MAIN(fx_131_main);
FX_MAIN(fx_132_main);
FX_MAIN(fx_133_main);
FX_MAIN(fx_134_main);

EffectTableEntry gEffectTable[] = {
    /* 0x00 */ {},
    /* 0x01 */ FX_ENTRY(1, _326410),
    /* 0x02 */ {},
    /* 0x03 */ {},
    /* 0x04 */ {},
    /* 0x05 */ {},
    /* 0x06 */ FX_ENTRY(6, _328EA0),
    /* 0x07 */ FX_ENTRY(7, _328EA0),
    /* 0x08 */ FX_ENTRY(8, _32CEC0),
    /* 0x09 */ FX_ENTRY(9, _32CEC0),
    /* 0x0A */ FX_ENTRY(10, _32EC50),
    /* 0x0B */ FX_ENTRY(11, _32EC50),
    /* 0x0C */ FX_ENTRY(12, _32FB50),
    /* 0x0D */ FX_ENTRY(13, _330460),
    /* 0x0E */ FX_ENTRY(14, _330F00),
    /* 0x0F */ FX_ENTRY(15, _3326A0),
    /* 0x10 */ FX_ENTRY(16, _334C70),
    /* 0x11 */ FX_ENTRY(17, _337FC0),
    /* 0x12 */ FX_ENTRY(18, _339F60),
    /* 0x13 */ FX_ENTRY(19, _33BBD0),
    /* 0x14 */ FX_ENTRY(20, _33D610),
    /* 0x15 */ FX_ENTRY(21, _33F000),
    /* 0x16 */ FX_ENTRY(22, _340880),
    /* 0x17 */ FX_ENTRY(23, _328EA0),
    /* 0x18 */ FX_ENTRY(24, _343040),
    /* 0x19 */ FX_ENTRY(25, _343F70),
    /* 0x1A */ FX_ENTRY(26, _3451E0),
    /* 0x1B */ FX_ENTRY(27, _345B40),
    /* 0x1C */ FX_ENTRY(28, _34E770),
    /* 0x1D */ FX_ENTRY(29, _328EA0),
    /* 0x1E */ FX_ENTRY(30, _350220),
    /* 0x1F */ FX_ENTRY(31, _352CE0),
    /* 0x20 */ FX_ENTRY(32, _353BB0),
    /* 0x21 */ FX_ENTRY(33, _343040),
    /* 0x22 */ FX_ENTRY(34, _337FC0),
    /* 0x23 */ FX_ENTRY(35, _356530),
    /* 0x24 */ FX_ENTRY(36, _3573A0),
    /* 0x25 */ FX_ENTRY(37, _3593B0),
    /* 0x26 */ FX_ENTRY(38, _35A5E0),
    /* 0x27 */ FX_ENTRY(39, _328EA0),
    /* 0x28 */ FX_ENTRY(40, _35C550),
    /* 0x29 */ FX_ENTRY(41, _35D510),
    /* 0x2A */ {},
    /* 0x2B */ FX_ENTRY(43, _33D610),
    /* 0x2C */ FX_ENTRY(44, _35F0E0),
    /* 0x2D */ FX_ENTRY(45, _360A30),
    /* 0x2E */ FX_ENTRY(46, _361670),
    /* 0x2F */ FX_ENTRY(47, _362C50),
    /* 0x30 */ FX_ENTRY(48, _3638C0),
    /* 0x31 */ FX_ENTRY(49, _364C00),
    /* 0x32 */ FX_ENTRY(50, _3659B0),
    /* 0x33 */ FX_ENTRY(51, _366D60),
    /* 0x34 */ FX_ENTRY(52, _36AEE0),
    /* 0x35 */ FX_ENTRY(53, _36DF90),
    /* 0x36 */ FX_ENTRY(54, _36ED60),
    /* 0x37 */ FX_ENTRY(55, _3733E0),
    /* 0x38 */ FX_ENTRY(56, _337FC0),
    /* 0x39 */ FX_ENTRY(57, _375510),
    /* 0x3A */ FX_ENTRY(58, _337FC0),
    /* 0x3B */ FX_ENTRY(59, _377F80),
    /* 0x3C */ FX_ENTRY(60, _37ADD0),
    /* 0x3D */ FX_ENTRY(61, _37D180),
    /* 0x3E */ FX_ENTRY(62, _37D9D0),
    /* 0x3F */ FX_ENTRY(63, _3803A0),
    /* 0x40 */ FX_ENTRY(64, _381E00),
    /* 0x41 */ FX_ENTRY(65, _3863B0),
    /* 0x42 */ FX_ENTRY(66, _37D9D0),
    /* 0x43 */ FX_ENTRY(67, _38A350),
    /* 0x44 */ FX_ENTRY(68, _38BBA0),
    /* 0x45 */ FX_ENTRY(69, _38D070),
    /* 0x46 */ FX_ENTRY(70, _38E990),
    /* 0x47 */ FX_ENTRY(71, _38F710),
    /* 0x48 */ FX_ENTRY(72, _3903D0),
    /* 0x49 */ FX_ENTRY(73, _392440),
    /* 0x4A */ FX_ENTRY(74, _3930A0),
    /* 0x4B */ FX_ENTRY(75, _394670),
    /* 0x4C */ FX_ENTRY(76, _3960F0),
    /* 0x4D */ FX_ENTRY(77, _397040),
    /* 0x4E */ FX_ENTRY(78, _398BC0),
    /* 0x4F */ FX_ENTRY(79, _3A0D60),
    /* 0x50 */ FX_ENTRY(80, _3A2440),
    /* 0x51 */ FX_ENTRY(81, _3A33D0),
    /* 0x52 */ FX_ENTRY(82, _3A4320),
    /* 0x53 */ FX_ENTRY(83, _3A5BE0),
    /* 0x54 */ FX_ENTRY(84, _3A77A0),
    /* 0x55 */ FX_ENTRY(85, _3AB030),
    /* 0x56 */ FX_ENTRY(86, _3AF700),
    /* 0x57 */ FX_ENTRY(87, _3B2D90),
    /* 0x58 */ FX_ENTRY(88, _3B46A0),
    /* 0x59 */ FX_ENTRY(89, _3B5340),
    /* 0x5A */ FX_ENTRY(90, _3B6BF0),
    /* 0x5B */ FX_ENTRY(91, _3B78D0),
    /* 0x5C */ FX_ENTRY(92, _3B8860),
    /* 0x5D */ FX_ENTRY(93, _3B9A70),
    /* 0x5E */ FX_ENTRY(94, _3BAEA0),
    /* 0x5F */ FX_ENTRY(95, _3BCA90),
    /* 0x60 */ FX_ENTRY(96, _3BD9A0),
    /* 0x61 */ FX_ENTRY(97, _3C1BA0),
    /* 0x62 */ FX_ENTRY(98, _3CB890),
    /* 0x63 */ FX_ENTRY(99, _3CD6E0),
    /* 0x64 */ FX_ENTRY(100, _3CFAF0),
    /* 0x65 */ FX_ENTRY(101, _3D11E0),
    /* 0x66 */ FX_ENTRY(102, _3D2580),
    /* 0x67 */ FX_ENTRY(103, _3D3930),
    /* 0x68 */ FX_ENTRY(104, _3593B0),
    /* 0x69 */ FX_ENTRY(105, _3D4E90),
    /* 0x6A */ {},
    /* 0x6B */ FX_ENTRY(107, _3D5F30),
    /* 0x6C */ FX_ENTRY(108, _3D7040),
    /* 0x6D */ FX_ENTRY(109, _3D7770),
    /* 0x6E */ FX_ENTRY(110, _3D80C0),
    /* 0x6F */ FX_ENTRY(111, _3D9100),
    /* 0x70 */ FX_ENTRY(112, _3DBF40),
    /* 0x71 */ FX_ENTRY(113, _3DCD50),
    /* 0x72 */ FX_ENTRY(114, _3DEE60),
    /* 0x73 */ FX_ENTRY(115, _3E12D0),
    /* 0x74 */ FX_ENTRY(116, _3E1CD0),
    /* 0x75 */ FX_ENTRY(117, _3E2960),
    /* 0x76 */ {},
    /* 0x77 */ FX_ENTRY(119, _3E5350),
    /* 0x78 */ FX_ENTRY(120, _3E5F30),
    /* 0x79 */ FX_ENTRY(121, _3EBE60),
    /* 0x7A */ FX_ENTRY(122, _3F8CC0),
    /* 0x7B */ FX_ENTRY(123, _3FA4B0),
    /* 0x7C */ FX_ENTRY(124, _3FF250),
    /* 0x7D */ FX_ENTRY(125, _3FA4B0),
    /* 0x7E */ FX_ENTRY(126, _403BF0),
    /* 0x7F */ FX_ENTRY(127, _404F40),
    /* 0x80 */ FX_ENTRY(128, _407080),
    /* 0x81 */ FX_ENTRY(129, _40A1C0),
    /* 0x82 */ FX_ENTRY(130, _40BBA0),
    /* 0x83 */ FX_ENTRY(131, _40D290),
    /* 0x84 */ FX_ENTRY(132, _337FC0),
    /* 0x85 */ FX_ENTRY(133, _413FA0),
    /* 0x86 */ FX_ENTRY(134, _415060),
>>>>>>> misc-decomp
};

s32 D_8007FEB8[] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000008, 0x00000005, 0x00000003, 0x00000004,
    0x0000000D, 0x0000003C, 0x00000000, 0x00000200, 0x00000000, 0x00000000,
    0x00000003, 0x00000000,
};

/// Used for unbound function points in effect structs.
void stub_effect_delegate(EffectInstance* effectInst) {
}

void set_effect_pos_offset(EffectGraphics* effect, f32 x, f32 y, f32 z) {
    EffectInstanceData* instanceData = effect->freeDelay;

    instanceData->pos.x = x;
    instanceData->pos.y = y;
    instanceData->pos.z = z;
}

void clear_effect_data(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gEffectGraphicsData); i++) {
        gEffectGraphicsData[i].flags = 0;
    }

    for (i = 0; i < ARRAY_COUNT(gEffectInstances); i++) {
        gEffectInstances[i] = 0;
    }

    osUnmapTLBAll();
    osMapTLB(0x10, NULL, _325AD0_VRAM, (s32)&D_801A6000 & 0xFFFFFF, -1, -1);
    dma_copy(_325AD0_ROM_START, _325AD0_ROM_END, _325AD0_VRAM);
}

void func_80059D48(void) {
}

// The third loop is doing some negative reference bs
#ifdef NON_MATCHING
void update_effects(void) {
    EffectGraphics* effectGraphics;
    s32 i;

    if (!(gOverrideFlags & 0xC00)) {
        for (i = 0; i < ARRAY_COUNT(gEffectGraphicsData); i++) {
            effectGraphics = &gEffectGraphicsData[i];

            if (effectGraphics->flags & FX_GRAPHICS_ENABLED) {
<<<<<<< HEAD
                if (!(effectGraphics->flags & 2)) {
                    effectGraphics->flags |= 2;
=======
                if (!(effectGraphics->flags & FX_GRAPHICS_2)) {
                    effectGraphics->flags |= FX_GRAPHICS_2;
>>>>>>> misc-decomp
                    effectGraphics->freeDelay = 3;
                }
            }
        }

        for (i = 0; i < ARRAY_COUNT(gEffectInstances); i++) {
            EffectInstance* effectInstance = gEffectInstances[i];

            if (effectInstance != NULL && (effectInstance->flags & 1)) {
                effectInstance->effect->flags &= ~0x2;

                if (gGameStatusPtr->isBattle) {
                    if (effectInstance->flags & 4) {
                        effectInstance->effect->update(effectInstance);
                        effectInstance->flags |= 8;
                    }
                } else {
                    if (!(effectInstance->flags & 4)) {
                        effectInstance->effect->update(effectInstance);
                        effectInstance->flags |= 8;
                    }
                }
            }
        }

        for (i = 0; i < ARRAY_COUNT(gEffectGraphicsData); i++) {
            effectGraphics = &gEffectGraphicsData[i];

            if (effectGraphics->flags & FX_GRAPHICS_ENABLED) {
<<<<<<< HEAD
                if (effectGraphics->flags & 2) {
=======
                if (effectGraphics->flags & FX_GRAPHICS_2) {
>>>>>>> misc-decomp
                    if (effectGraphics->freeDelay != 0) {
                        effectGraphics->freeDelay--;
                    } else {
                        if (effectGraphics->data[0] != NULL) {
                            general_heap_free(effectGraphics->data);
                            effectGraphics->data[0] = NULL;
                        }
                        effectGraphics->flags = FX_GRAPHICS_DISABLED;
                        osUnmapTLB(i);
                    }
                }
            }
        }
    }
}
#else
INCLUDE_ASM(s32, "341d0", update_effects);
#endif

s32 render_effects_world(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gEffectInstances); i++) {
        if (gEffectInstances[i] != NULL && gEffectInstances[i]->flags & 1 && gEffectInstances[i]->flags & 8) {
            if (gGameStatusPtr->isBattle) {
                if (gEffectInstances[i]->flags & 4) {
                    gEffectInstances[i]->effect->renderWorld(gEffectInstances[i]);
                }
            } else {
                if (!(gEffectInstances[i]->flags & 4)) {
                    gEffectInstances[i]->effect->renderWorld(gEffectInstances[i]);
                }
            }
        }
    }
}

void render_effects_UI(void) {
    s32 cond = TRUE;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gEffectInstances); i++) {
        EffectInstance* effectInstance = gEffectInstances[i];

        if (effectInstance != NULL) {
            if (effectInstance->flags & 1) {
                if (effectInstance->flags & 8) {
                    void (*renderUI)(EffectInstance* effectInst);

                    if (gGameStatusPtr->isBattle && !(effectInstance->flags & 4)) {
                        continue;
                    }

                    if (!gGameStatusPtr->isBattle && effectInstance->flags & 4) {
                        continue;
                    }

                    renderUI = effectInstance->effect->renderUI;
                    if (renderUI != stub_effect_delegate) {
                        if (cond) {
                            Camera* camera = &gCameras[gCurrentCameraID];

                            gDPPipeSync(gMasterGfxPos++);
                            gSPViewport(gMasterGfxPos++, &camera->viewport);
                            gSPClearGeometryMode(gMasterGfxPos++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG |
                                                G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD |
<<<<<<< HEAD
                                                G_SHADING_SMOOTH | G_CLIPPING | 0x0040F9FA);
=======
                                                G_SHADING_SMOOTH | G_CLIPPING | 0x40F9FA);
>>>>>>> misc-decomp
                            gSPSetGeometryMode(gMasterGfxPos++, G_ZBUFFER | G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH);
                            gDPSetScissor(gMasterGfxPos++, G_SC_NON_INTERLACE,
                                              camera->viewportStartX,
                                              camera->viewportStartY,
                                              camera->viewportStartX + camera->viewportW,
                                              camera->viewportStartY + camera->viewportH);
                            gSPClipRatio(gMasterGfxPos++, FRUSTRATIO_2);

                            cond = FALSE;
                            if (!(camera->flags & 0x10)) {
                                gSPPerspNormalize(gMasterGfxPos++, camera->perspNorm);
                                gSPMatrix(gMasterGfxPos++, &gDisplayContext->camPerspMatrix[gCurrentCameraID],
                                          G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
                            }
                        }

                        renderUI(effectInstance);
                    }
                }
            }
        }
    }
}

EffectInstance* func_8005A2BC(EffectBlueprint* effectBp) {
    EffectInstance* newEffectInst;
    EffectGraphics* curEffect;
    s32 i;

    // Search for an unused instance
    for (i = 0; i < ARRAY_COUNT(gEffectInstances); i++) {
        if (gEffectInstances[i] == NULL) {
            break;
        }
    }

    ASSERT(i < ARRAY_COUNT(gEffectInstances));

    // Allocate space for the new instance
    gEffectInstances[i] = newEffectInst = general_heap_malloc(sizeof(EffectInstance));
    ASSERT(newEffectInst != NULL);

    curEffect = &gEffectGraphicsData[0];
    newEffectInst->effectIndex = effectBp->effectIndex;
    newEffectInst->flags = 1;

    // Look for a loaded effect of the proper index
    for (i = 0; i < ARRAY_COUNT(gEffectGraphicsData); i++) {
        if ((curEffect->flags & EFFECT_LOADED) && (curEffect->effectIndex == effectBp->effectIndex)) {
            break;
        }
        curEffect++;
    }

    ASSERT(i < ARRAY_COUNT(gEffectGraphicsData));

    // If this is the first new instance of the effect, initialize the function pointers
    if (curEffect->instanceCounter == 0) {
        curEffect->update = effectBp->update;
        if (curEffect->update == NULL) {
            curEffect->renderWorld = stub_effect_delegate;
        }

        curEffect->renderWorld = effectBp->renderWorld;
        if (curEffect->renderUI == NULL) {
            curEffect->renderUI = stub_effect_delegate;
        }

        curEffect->renderUI = effectBp->unk_14;
        if (curEffect->renderUI == NULL) {
            curEffect->renderUI = stub_effect_delegate;
        }
    }

    curEffect->instanceCounter++;
    newEffectInst->effect = curEffect;

    if (effectBp->init != NULL) {
        effectBp->init(newEffectInst);
    }

    if (gGameStatusPtr->isBattle) {
        newEffectInst->flags |= 4;
    }
    return newEffectInst;
}

void remove_effect(EffectInstance* effectInstsance) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gEffectInstances); i++) {
        if (gEffectInstances[i] == effectInstsance) {
            break;
        }
    }

    ASSERT(i < ARRAY_COUNT(gEffectInstances));

    if (effectInstsance->data == NULL) {
        general_heap_free(effectInstsance);
        gEffectInstances[i] = NULL;
    } else {
        general_heap_free(effectInstsance->data);
        general_heap_free(effectInstsance);
        gEffectInstances[i] = NULL;
    }
}

void remove_all_effects(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gEffectInstances); i++) {
        EffectInstance* effect = gEffectInstances[i];

        if (effect != NULL && effect->flags & 4) {
            if (effect->data != NULL) {
                general_heap_free(effect->data);
            }
            general_heap_free(effect);
            gEffectInstances[i] = NULL;
        }
    }
}

s32 load_effect(s32 effectIndex) {
    EffectTableEntry* effectEntry = &gEffectTable[effectIndex];
    EffectGraphics* curEffect;
    TlbMappablePage* tlbMappablePages;
    s32 i;

    // Look for a loaded effect matching the desired index
    for (i = 0, curEffect = &gEffectGraphicsData[0]; i < ARRAY_COUNT(gEffectGraphicsData); i++) {
<<<<<<< HEAD
        if ((curEffect->flags & EFFECT_LOADED) && (curEffect->effectIndex == effectIndex)) {
=======
        if (curEffect->flags & EFFECT_LOADED && curEffect->effectIndex == effectIndex) {
>>>>>>> misc-decomp
            break;
        }
        curEffect++;
    }

    // If an effect was found within the table, initialize it and return
    if (i < ARRAY_COUNT(gEffectGraphicsData)) {
        curEffect->effectIndex = effectIndex;
        curEffect->instanceCounter = 0;
        curEffect->flags = EFFECT_LOADED;
        return 1;
    }

    // If a loaded effect wasn't found, look for the first empty space
    for (i = 0, curEffect = &gEffectGraphicsData[0]; i < ARRAY_COUNT(gEffectGraphicsData); i++) {
        if (!(curEffect->flags & EFFECT_LOADED)) {
            break;
        }
        curEffect++;
    }

    // If no empty space was found, panic
    ASSERT(i < ARRAY_COUNT(gEffectGraphicsData));

    // Map space for the effect
    tlbMappablePages = &D_80197000;
    osMapTLB(i, 0, effectEntry->dmaDest, (s32)((*tlbMappablePages)[i]) & 0xFFFFFF, -1, -1);

    // Copy the effect into the newly mapped space
    dma_copy(effectEntry->dmaStart, effectEntry->dmaEnd, effectEntry->dmaDest);

    // If there's extra data the effect normally loads, allocate space and copy into the new space
    if (effectEntry->graphicsDmaStart != NULL) {
        void* effectDataBuf = general_heap_malloc(effectEntry->graphicsDmaEnd - effectEntry->graphicsDmaStart);
        curEffect->data = effectDataBuf;
        ASSERT(effectDataBuf != NULL);
        dma_copy(effectEntry->graphicsDmaStart, effectEntry->graphicsDmaEnd, curEffect->data);
    }

    // Initialize the newly loaded effect data
    curEffect->effectIndex = effectIndex;
    curEffect->instanceCounter = 0;
    curEffect->flags = EFFECT_LOADED;
    return 1;
}
