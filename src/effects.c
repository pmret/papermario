#include "common.h"
#include "ld_addrs.h"

typedef s32 TlbEntry[0x1000 / 4];
typedef TlbEntry TlbMappablePage[15];

extern TlbMappablePage D_80197000;
extern EffectTableEntry gEffectTable[135];

#define EFFECT_LOADED 1

extern void* D_80059C80;
extern EffectGraphics gEffectGraphicsData[15];
extern EffectInstance* gEffectInstances[96];
extern s32 D_801A6000;

#define FX_MAIN(name) void name(s32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 x, f32 y, f32 z);

FX_MAIN(fx_1_main);
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
    { NULL, NULL, NULL, NULL, NULL, NULL }, // 0
    { fx_1_main, effect_1_ROM_START, effect_1_ROM_END, effect_1_VRAM, 0x00326410, 0x003278F0 }, // 1
    { NULL, NULL, NULL, NULL, NULL, NULL }, // 2
    { NULL, NULL, NULL, NULL, NULL, NULL }, // 3
    { NULL, NULL, NULL, NULL, NULL, NULL }, // 4
    { NULL, NULL, NULL, NULL, NULL, NULL }, // 5
    { fx_6_main, effect_6_ROM_START, effect_6_ROM_END, effect_6_VRAM, 0x00328EA0, 0x0032C110 }, // 6
    { fx_7_main, effect_7_ROM_START, effect_7_ROM_END, effect_7_VRAM, 0x00328EA0, 0x0032C110 }, // 7
    { fx_8_main, effect_8_ROM_START, effect_8_ROM_END, effect_8_VRAM, 0x0032CEC0, 0x0032DD10 }, // 8
    { fx_9_main, effect_9_ROM_START, effect_9_ROM_END, effect_9_VRAM, 0x0032CEC0, 0x0032DD10 }, // 9
    { fx_10_main, effect_10_ROM_START, effect_10_ROM_END, effect_10_VRAM, 0x0032EC50, 0x0032EE30 }, // 10
    { fx_11_main, effect_11_ROM_START, effect_11_ROM_END, effect_11_VRAM, 0x0032EC50, 0x0032EE30 }, // 11
    { fx_12_main, effect_12_ROM_START, effect_12_ROM_END, effect_12_VRAM, 0x0032FB50, 0x0032FE30 }, // 12
    { fx_13_main, effect_13_ROM_START, effect_13_ROM_END, effect_13_VRAM, 0x00330460, 0x00330910 }, // 13
    { fx_14_main, effect_14_ROM_START, effect_14_ROM_END, effect_14_VRAM, 0x00330F00, 0x00331940 }, // 14
    { fx_15_main, effect_15_ROM_START, effect_15_ROM_END, effect_15_VRAM, 0x003326A0, 0x00333EC0 }, // 15
    { fx_16_main, effect_16_ROM_START, effect_16_ROM_END, effect_16_VRAM, 0x00334C70, 0x00337240 }, // 16
    { fx_17_main, effect_17_ROM_START, effect_17_ROM_END, effect_17_VRAM, 0x00337FC0, 0x00339250 }, // 17
    { fx_18_main, effect_18_ROM_START, effect_18_ROM_END, effect_18_VRAM, 0x00339F60, 0x0033B180 }, // 18
    { fx_19_main, effect_19_ROM_START, effect_19_ROM_END, effect_19_VRAM, 0x0033BBD0, 0x0033CDF0 }, // 19
    { fx_20_main, effect_20_ROM_START, effect_20_ROM_END, effect_20_VRAM, 0x0033D610, 0x0033E8C0 }, // 20
    { fx_21_main, effect_21_ROM_START, effect_21_ROM_END, effect_21_VRAM, 0x0033F000, 0x0033FE80 }, // 21
    { fx_22_main, effect_22_ROM_START, effect_22_ROM_END, effect_22_VRAM, 0x00340880, 0x003419E0 }, // 22
    { fx_23_main, effect_23_ROM_START, effect_23_ROM_END, effect_23_VRAM, 0x00328EA0, 0x0032C110 }, // 23
    { fx_24_main, effect_24_ROM_START, effect_24_ROM_END, effect_24_VRAM, 0x00343040, 0x00343680 }, // 24
    { fx_25_main, effect_25_ROM_START, effect_25_ROM_END, effect_25_VRAM, 0x00343F70, 0x00344A10 }, // 25
    { fx_26_main, effect_26_ROM_START, effect_26_ROM_END, effect_26_VRAM, 0x003451E0, 0x003454E0 }, // 26
    { fx_27_main, effect_27_ROM_START, effect_27_ROM_END, effect_27_VRAM, 0x00345B40, 0x0034DD20 }, // 27
    { fx_28_main, effect_28_ROM_START, effect_28_ROM_END, effect_28_VRAM, 0x0034E770, 0x0034EC80 }, // 28
    { fx_29_main, effect_29_ROM_START, effect_29_ROM_END, effect_29_VRAM, 0x00328EA0, 0x0032C110 }, // 29
    { fx_30_main, effect_30_ROM_START, effect_30_ROM_END, effect_30_VRAM, 0x00350220, 0x00352440 }, // 30
    { fx_31_main, effect_31_ROM_START, effect_31_ROM_END, effect_31_VRAM, 0x00352CE0, 0x00353300 }, // 31
    { fx_32_main, effect_32_ROM_START, effect_32_ROM_END, effect_32_VRAM, 0x00353BB0, 0x003547A0 }, // 32
    { fx_33_main, effect_33_ROM_START, effect_33_ROM_END, effect_33_VRAM, 0x00343040, 0x00343680 }, // 33
    { fx_34_main, effect_34_ROM_START, effect_34_ROM_END, effect_34_VRAM, 0x00337FC0, 0x00339250 }, // 34
    { fx_35_main, effect_35_ROM_START, effect_35_ROM_END, effect_35_VRAM, 0x00356530, 0x00356980 }, // 35
    { fx_36_main, effect_36_ROM_START, effect_36_ROM_END, effect_36_VRAM, 0x003573A0, 0x003584C0 }, // 36
    { fx_37_main, effect_37_ROM_START, effect_37_ROM_END, effect_37_VRAM, 0x003593B0, 0x00359F20 }, // 37
    { fx_38_main, effect_38_ROM_START, effect_38_ROM_END, effect_38_VRAM, 0x0035A5E0, 0x0035B9D0 }, // 38
    { fx_39_main, effect_39_ROM_START, effect_39_ROM_END, effect_39_VRAM, 0x00328EA0, 0x0032C110 }, // 39
    { fx_40_main, effect_40_ROM_START, effect_40_ROM_END, effect_40_VRAM, 0x0035C550, 0x0035CA80 }, // 40
    { fx_41_main, effect_41_ROM_START, effect_41_ROM_END, effect_41_VRAM, 0x0035D510, 0x0035DA00 }, // 41
    { NULL, NULL, NULL, NULL, NULL, NULL }, // 42
    { fx_43_main, effect_43_ROM_START, effect_43_ROM_END, effect_43_VRAM, 0x0033D610, 0x0033E8C0 }, // 43
    { fx_44_main, effect_44_ROM_START, effect_44_ROM_END, effect_44_VRAM, 0x0035F0E0, 0x003602C0 }, // 44
    { fx_45_main, effect_45_ROM_START, effect_45_ROM_END, effect_45_VRAM, 0x00360A30, 0x00360F40 }, // 45
    { fx_46_main, effect_46_ROM_START, effect_46_ROM_END, effect_46_VRAM, 0x00361670, 0x003625C0 }, // 46
    { fx_47_main, effect_47_ROM_START, effect_47_ROM_END, effect_47_VRAM, 0x00362C50, 0x00363160 }, // 47
    { fx_48_main, effect_48_ROM_START, effect_48_ROM_END, effect_48_VRAM, 0x003638C0, 0x00364300 }, // 48
    { fx_49_main, effect_49_ROM_START, effect_49_ROM_END, effect_49_VRAM, 0x00364C00, 0x00364F10 }, // 49
    { fx_50_main, effect_50_ROM_START, effect_50_ROM_END, effect_50_VRAM, 0x003659B0, 0x00366030 }, // 50
    { fx_51_main, effect_51_ROM_START, effect_51_ROM_END, effect_51_VRAM, 0x00366D60, 0x0036A8D0 }, // 51
    { fx_52_main, effect_52_ROM_START, effect_52_ROM_END, effect_52_VRAM, 0x0036AEE0, 0x0036D020 }, // 52
    { fx_53_main, effect_53_ROM_START, effect_53_ROM_END, effect_53_VRAM, 0x0036DF90, 0x0036E1D0 }, // 53
    { fx_54_main, effect_54_ROM_START, effect_54_ROM_END, effect_54_VRAM, 0x0036ED60, 0x00372790 }, // 54
    { fx_55_main, effect_55_ROM_START, effect_55_ROM_END, effect_55_VRAM, 0x003733E0, 0x003740B0 }, // 55
    { fx_56_main, effect_56_ROM_START, effect_56_ROM_END, effect_56_VRAM, 0x00337FC0, 0x00339250 }, // 56
    { fx_57_main, effect_57_ROM_START, effect_57_ROM_END, effect_57_VRAM, 0x00375510, 0x00376460 }, // 57
    { fx_58_main, effect_58_ROM_START, effect_58_ROM_END, effect_58_VRAM, 0x00337FC0, 0x00339250 }, // 58
    { fx_59_main, effect_59_ROM_START, effect_59_ROM_END, effect_59_VRAM, 0x00377F80, 0x0037A3F0 }, // 59
    { fx_60_main, effect_60_ROM_START, effect_60_ROM_END, effect_60_VRAM, 0x0037ADD0, 0x0037C540 }, // 60
    { fx_61_main, effect_61_ROM_START, effect_61_ROM_END, effect_61_VRAM, 0x0037D180, 0x0037D490 }, // 61
    { fx_62_main, effect_62_ROM_START, effect_62_ROM_END, effect_62_VRAM, 0x0037D9D0, 0x0037F720 }, // 62
    { fx_63_main, effect_63_ROM_START, effect_63_ROM_END, effect_63_VRAM, 0x003803A0, 0x003812C0 }, // 63
    { fx_64_main, effect_64_ROM_START, effect_64_ROM_END, effect_64_VRAM, 0x00381E00, 0x00385640 }, // 64
    { fx_65_main, effect_65_ROM_START, effect_65_ROM_END, effect_65_VRAM, 0x003863B0, 0x003889D0 }, // 65
    { fx_66_main, effect_66_ROM_START, effect_66_ROM_END, effect_66_VRAM, 0x0037D9D0, 0x0037F720 }, // 66
    { fx_67_main, effect_67_ROM_START, effect_67_ROM_END, effect_67_VRAM, 0x0038A350, 0x0038ADF0 }, // 67
    { fx_68_main, effect_68_ROM_START, effect_68_ROM_END, effect_68_VRAM, 0x0038BBA0, 0x0038C5F0 }, // 68
    { fx_69_main, effect_69_ROM_START, effect_69_ROM_END, effect_69_VRAM, 0x0038D070, 0x0038DE00 }, // 69
    { fx_70_main, effect_70_ROM_START, effect_70_ROM_END, effect_70_VRAM, 0x0038E990, 0x0038EE60 }, // 70
    { fx_71_main, effect_71_ROM_START, effect_71_ROM_END, effect_71_VRAM, 0x0038F710, 0x0038F900 }, // 71
    { fx_72_main, effect_72_ROM_START, effect_72_ROM_END, effect_72_VRAM, 0x003903D0, 0x00391D30 }, // 72
    { fx_73_main, effect_73_ROM_START, effect_73_ROM_END, effect_73_VRAM, 0x00392440, 0x003928D0 }, // 73
    { fx_74_main, effect_74_ROM_START, effect_74_ROM_END, effect_74_VRAM, 0x003930A0, 0x00394280 }, // 74
    { fx_75_main, effect_75_ROM_START, effect_75_ROM_END, effect_75_VRAM, 0x00394670, 0x00395BB0 }, // 75
    { fx_76_main, effect_76_ROM_START, effect_76_ROM_END, effect_76_VRAM, 0x003960F0, 0x003965B0 }, // 76
    { fx_77_main, effect_77_ROM_START, effect_77_ROM_END, effect_77_VRAM, 0x00397040, 0x003981F0 }, // 77
    { fx_78_main, effect_78_ROM_START, effect_78_ROM_END, effect_78_VRAM, 0x00398BC0, 0x0039FF20 }, // 78
    { fx_79_main, effect_79_ROM_START, effect_79_ROM_END, effect_79_VRAM, 0x003A0D60, 0x003A2290 }, // 79
    { fx_80_main, effect_80_ROM_START, effect_80_ROM_END, effect_80_VRAM, 0x003A2440, 0x003A2990 }, // 80
    { fx_81_main, effect_81_ROM_START, effect_81_ROM_END, effect_81_VRAM, 0x003A33D0, 0x003A37E0 }, // 81
    { fx_82_main, effect_82_ROM_START, effect_82_ROM_END, effect_82_VRAM, 0x003A4320, 0x003A5550 }, // 82
    { fx_83_main, effect_83_ROM_START, effect_83_ROM_END, effect_83_VRAM, 0x003A5BE0, 0x003A70F0 }, // 83
    { fx_84_main, effect_84_ROM_START, effect_84_ROM_END, effect_84_VRAM, 0x003A77A0, 0x003AA920 }, // 84
    { fx_85_main, effect_85_ROM_START, effect_85_ROM_END, effect_85_VRAM, 0x003AB030, 0x003AEE20 }, // 85
    { fx_86_main, effect_86_ROM_START, effect_86_ROM_END, effect_86_VRAM, 0x003AF700, 0x003B2350 }, // 86
    { fx_87_main, effect_87_ROM_START, effect_87_ROM_END, effect_87_VRAM, 0x003B2D90, 0x003B3EB0 }, // 87
    { fx_88_main, effect_88_ROM_START, effect_88_ROM_END, effect_88_VRAM, 0x003B46A0, 0x003B4790 }, // 88
    { fx_89_main, effect_89_ROM_START, effect_89_ROM_END, effect_89_VRAM, 0x003B5340, 0x003B5CF0 }, // 89
    { fx_90_main, effect_90_ROM_START, effect_90_ROM_END, effect_90_VRAM, 0x003B6BF0, 0x003B7160 }, // 90
    { fx_91_main, effect_91_ROM_START, effect_91_ROM_END, effect_91_VRAM, 0x003B78D0, 0x003B7B80 }, // 91
    { fx_92_main, effect_92_ROM_START, effect_92_ROM_END, effect_92_VRAM, 0x003B8860, 0x003B8BD0 }, // 92
    { fx_93_main, effect_93_ROM_START, effect_93_ROM_END, effect_93_VRAM, 0x003B9A70, 0x003BA030 }, // 93
    { fx_94_main, effect_94_ROM_START, effect_94_ROM_END, effect_94_VRAM, 0x003BAEA0, 0x003BBF60 }, // 94
    { fx_95_main, effect_95_ROM_START, effect_95_ROM_END, effect_95_VRAM, 0x003BCA90, 0x003BCD60 }, // 95
    { fx_96_main, effect_96_ROM_START, effect_96_ROM_END, effect_96_VRAM, 0x003BD9A0, 0x003C11D0 }, // 96
    { fx_97_main, effect_97_ROM_START, effect_97_ROM_END, effect_97_VRAM, 0x003C1BA0, 0x003CADF0 }, // 97
    { fx_98_main, effect_98_ROM_START, effect_98_ROM_END, effect_98_VRAM, 0x003CB890, 0x003CC9E0 }, // 98
    { fx_99_main, effect_99_ROM_START, effect_99_ROM_END, effect_99_VRAM, 0x003CD6E0, 0x003CF3A0 }, // 99
    { fx_100_main, effect_100_ROM_START, effect_100_ROM_END, effect_100_VRAM, 0x003CFAF0, 0x003D0500 }, // 100
    { fx_101_main, effect_101_ROM_START, effect_101_ROM_END, effect_101_VRAM, 0x003D11E0, 0x003D1690 }, // 101
    { fx_102_main, effect_102_ROM_START, effect_102_ROM_END, effect_102_VRAM, 0x003D2580, 0x003D2AC0 }, // 102
    { fx_103_main, effect_103_ROM_START, effect_103_ROM_END, effect_103_VRAM, 0x003D3930, 0x003D3E20 }, // 103
    { fx_104_main, effect_104_ROM_START, effect_104_ROM_END, effect_104_VRAM, 0x003593B0, 0x00359F20 }, // 104
    { fx_105_main, effect_105_ROM_START, effect_105_ROM_END, effect_105_VRAM, 0x003D4E90, 0x003D5020 }, // 105
    { NULL, NULL, NULL, NULL, NULL, NULL }, // 106
    { fx_107_main, effect_107_ROM_START, effect_107_ROM_END, effect_107_VRAM, 0x003D5F30, 0x003D67C0 }, // 107
    { fx_108_main, effect_108_ROM_START, effect_108_ROM_END, effect_108_VRAM, 0x003D7040, 0x003D7240 }, // 108
    { fx_109_main, effect_109_ROM_START, effect_109_ROM_END, effect_109_VRAM, 0x003D7770, 0x003D7A70 }, // 109
    { fx_110_main, effect_110_ROM_START, effect_110_ROM_END, effect_110_VRAM, 0x003D80C0, 0x003D8720 }, // 110
    { fx_111_main, effect_111_ROM_START, effect_111_ROM_END, effect_111_VRAM, 0x003D9100, 0x003DB460 }, // 111
    { fx_112_main, effect_112_ROM_START, effect_112_ROM_END, effect_112_VRAM, 0x003DBF40, 0x003DC310 }, // 112
    { fx_113_main, effect_113_ROM_START, effect_113_ROM_END, effect_113_VRAM, 0x003DCD50, 0x003DE000 }, // 113
    { fx_114_main, effect_114_ROM_START, effect_114_ROM_END, effect_114_VRAM, 0x003DEE60, 0x003E0930 }, // 114
    { fx_115_main, effect_115_ROM_START, effect_115_ROM_END, effect_115_VRAM, 0x003E12D0, 0x003E1690 }, // 115
    { fx_116_main, effect_116_ROM_START, effect_116_ROM_END, effect_116_VRAM, 0x003E1CD0, 0x003E1EE0 }, // 116
    { fx_117_main, effect_117_ROM_START, effect_117_ROM_END, effect_117_VRAM, 0x003E2960, 0x003E43A0 }, // 117
    { NULL, NULL, NULL, NULL, NULL, NULL }, // 118
    { fx_119_main, effect_119_ROM_START, effect_119_ROM_END, effect_119_VRAM, 0x003E5350, 0x003E54C0 }, // 119
    { fx_120_main, effect_120_ROM_START, effect_120_ROM_END, effect_120_VRAM, 0x003E5F30, 0x003EB4E0 }, // 120
    { fx_121_main, effect_121_ROM_START, effect_121_ROM_END, effect_121_VRAM, 0x003EBE60, 0x003F83F0 }, // 121
    { fx_122_main, effect_122_ROM_START, effect_122_ROM_END, effect_122_VRAM, 0x003F8CC0, 0x003F9E50 }, // 122
    { fx_123_main, effect_123_ROM_START, effect_123_ROM_END, effect_123_VRAM, 0x003FA4B0, 0x003FEAE0 }, // 123
    { fx_124_main, effect_124_ROM_START, effect_124_ROM_END, effect_124_VRAM, 0x003FF250, 0x00402640 }, // 124
    { fx_125_main, effect_125_ROM_START, effect_125_ROM_END, effect_125_VRAM, 0x003FA4B0, 0x003FEAE0 }, // 125
    { fx_126_main, effect_126_ROM_START, effect_126_ROM_END, effect_126_VRAM, 0x00403BF0, 0x00404220 }, // 126
    { fx_127_main, effect_127_ROM_START, effect_127_ROM_END, effect_127_VRAM, 0x00404F40, 0x00406B40 }, // 127
    { fx_128_main, effect_128_ROM_START, effect_128_ROM_END, effect_128_VRAM, 0x00407080, 0x00409990 }, // 128
    { fx_129_main, effect_129_ROM_START, effect_129_ROM_END, effect_129_VRAM, 0x0040A1C0, 0x0040B3F0 }, // 129
    { fx_130_main, effect_130_ROM_START, effect_130_ROM_END, effect_130_VRAM, 0x0040BBA0, 0x0040C5A0 }, // 130
    { fx_131_main, effect_131_ROM_START, effect_131_ROM_END, effect_131_VRAM, 0x0040D290, 0x00412730 }, // 131
    { fx_132_main, effect_132_ROM_START, effect_132_ROM_END, effect_132_VRAM, 0x00337FC0, 0x00339250 }, // 132
    { fx_133_main, effect_133_ROM_START, effect_133_ROM_END, effect_133_VRAM, 0x00413FA0, 0x00414BA0 }, // 133
    { fx_134_main, effect_134_ROM_START, effect_134_ROM_END, effect_134_VRAM, 0x00415060, 0x00415D90 }, // 134
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
                if (!(effectGraphics->flags & FX_GRAPHICS_2)) {
                    effectGraphics->flags |= FX_GRAPHICS_2;
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
                if (effectGraphics->flags & FX_GRAPHICS_2) {
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
                                                G_SHADING_SMOOTH | G_CLIPPING | 0x0040F9FA);
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
        if ((curEffect->flags & EFFECT_LOADED) && (curEffect->effectIndex == effectIndex)) {
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
