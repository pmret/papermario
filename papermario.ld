SECTIONS
{
    /* 0x0 0-40 (len 40) */
    .text_0 0x0 : AT(0x0) {
        build/asm/header.o(.text_0);
    }

    /* 0xA4000040 40-1000 (len FC0) */
    .text_40 0xA4000040 : AT(0x40) {
        build/asm/boot.o(.text_40);
        build/bin/bootcode_font.o(.data);
    }

    /* 0x80025C00 1000-759B0 (len 749B0) */
    .text_1000 0x80025C00 : AT(0x1000) {
        build/src/code_1000_len_60.o(.text);
        build/src/code_1060_len_310.o(.text);
        build/src/code_1370_len_7d0.o(.text);
        build/src/code_1b40_len_20b0.o(.text);
        build/src/code_3bf0_len_6f0.o(.text);
        build/src/code_42e0_len_1f60.o(.text);
        build/src/code_6000.o(.text);
        build/src/code_6240_len_c00.o(.text);
        build/src/code_6e40_len_500.o(.text);
        build/src/code_7340_len_b00.o(.text);
        build/src/os/code_7e40_len_3f0.o(.text);
        build/src/code_8230_len_1ae0.o(.text);
        build/src/code_9d10_len_1080.o(.text);
        build/src/code_ad90_len_2880.o(.text);
        build/src/code_d610_len_1330.o(.text);
        build/src/code_e940_len_290.o(.text);
        build/src/code_ebd0_len_6a0.o(.text);
        build/src/code_f270_len_1190.o(.text);
        build/src/code_10400_len_d30.o(.text);
        build/src/code_11130_len_c0.o(.text);
        build/src/code_111f0_len_860.o(.text);
        build/src/code_11a50_len_7a0.o(.text);
        build/src/code_121f0_len_1290.o(.text);
        build/src/code_13480_len_3f0.o(.text);
        build/src/code_13870_len_6980.o(.text);
        build/src/code_1a1f0_len_5390.o(.text);
        build/src/code_1f580_len_1940.o(.text);
        build/src/code_20ec0_len_5040.o(.text);
        build/src/code_25f00_len_940.o(.text);
        build/src/code_26840_len_20d0.o(.text);
        build/src/code_28910_len_5090.o(.text);
        build/src/code_2d9a0_len_890.o(.text);
        build/src/code_2e230_len_2190.o(.text);
        build/src/code_303c0_len_3e10.o(.text);
        build/src/code_341d0_len_20d0.o(.text);
        build/src/code_362a0_len_2f70.o(.text);
        build/src/code_39210_len_aa0.o(.text);
        build/src/os/code_39cb0_len_100.o(.text);
        build/src/os/code_39db0_len_8a0.o(.text);
        build/src/os/code_3a650_len_40.o(.text);
        build/src/os/code_3a690_len_40.o(.text);
        build/src/os/code_3a6d0_len_20.o(.text);
        build/src/os/code_3a6f0_len_110.o(.text);
        build/src/os/code_3a800_len_30.o(.text);
        build/src/os/code_3a830_len_20.o(.text);
        build/src/os/code_3a850_le_a40.o(.text);
        build/src/os/code_3b290_len_100.o(.text);
        build/src/os/code_3b390_len_110.o(.text);
        build/src/os/code_3b4a0_len_270.o(.text);
        build/src/os/code_3b710_len_40.o(.text);
        build/src/code_3b750_len_20.o(.text);
        build/src/os/code_3b770_len_80.o(.text);
        build/src/os/code_3b7f0_len_120.o(.text);
        build/src/os/code_3b910_len_410.o(.text);
        build/src/os/code_3bd20_len_c0.o(.text);
        build/src/os/code_3bde0_len_3e0.o(.text);
        build/src/os/code_3c1c0_len_60.o(.text);
        build/src/os/code_3c220_len_a0.o(.text);
        build/src/os/code_3c2c0_len_50.o(.text);
        build/src/os/code_3c310_len_180.o(.text);
        build/src/os/code_3c490_len_3c0.o(.text);
        build/src/os/code_3c850_len_f0.o(.text);
        build/src/os/code_3c940_len_140.o(.text);
        build/src/os/code_3ca80_len_a0.o(.text);
        build/src/os/code_3cb20_len_130.o(.text);
        build/src/os/code_3cc50_len_80.o(.text);
        build/src/os/code_3ccd0_len_30.o(.text);
        build/src/os/code_3cd00_len_5f0.o(.text);
        build/src/os/code_3d2f0_len_10.o(.text);
        build/src/os/code_3d300_len_30.o(.text);
        build/src/os/code_3d330_len_990.o(.text);
        build/src/os/code_3dcc0_len_a60.o(.text);
        build/src/os/code_3e720_len_5f0.o(.text);
        build/src/guOrtho.o(.text);
        build/src/os/code_3ef90_len_600.o(.text);
        build/src/os/code_3f310_len_3c0.o(.text);
        build/src/os/code_3f6d0_len_320.o(.text);
        build/src/os/code_3f9f0_len_60.o(.text);
        build/src/os/code_3fa50_len_f60.o(.text);
        build/src/os/code_409b0_len_140.o(.text);
        build/src/os/code_40af0_len_130.o(.text);
        build/src/os/code_40c20_len_1f0.o(.text);
        build/src/os/code_40e10_len_240.o(.text);
        build/src/os/code_41050_len_120.o(.text);
        build/src/os/code_41170_len_f0.o(.text);
        build/src/os/osCreateThread.o(.text);
        build/src/os/osGetThreadPri.o(.text);
        build/src/os/code_41350_len_d0.o(.text);
        build/src/os/code_41420_len_120.o(.text);
        build/src/os/code_41540_len_c0.o(.text);
        build/src/os/code_41600_len_40.o(.text);
        build/src/os/code_41640_len_50.o(.text);
        build/src/os/code_41690_len_10.o(.text);
        build/src/os/code_416a0_len_90.o(.text);
        build/src/os/code_41730_len_20.o(.text);
        build/src/os/code_41750_len_450.o(.text);
        build/src/os/code_41ba0_len_c0.o(.text);
        build/src/os/code_41c60_len_c0.o(.text);
        build/src/os/code_41d20_len_40.o(.text);
        build/src/os/code_41d60_len_50.o(.text);
        build/src/os/code_41db0_len_40.o(.text);
        build/src/os/code_41df0_len_40.o(.text);
        build/src/os/code_41e30_len_40.o(.text);
        build/src/os/code_41e70_len_340.o(.text);
        build/src/os/code_421b0_len_60.o(.text);
        build/src/os/code_42210_len_50.o(.text);
        build/src/os/code_42260_len_170.o(.text);
        build/src/os/code_423d0_len_50.o(.text);
        build/src/os/code_42420_len_50.o(.text);
        build/src/os/code_42470_len_310.o(.text);
        build/src/os/code_42780_len_120.o(.text);
        build/src/os/guMtxIdentF.o(.text);
        build/src/os/code_42900_len_80.o(.text);
        build/src/os/code_42980_len_80.o(.text);
        build/src/os/code_42a00_len_100.o(.text);
        build/src/os/code_42b00_len_c0.o(.text);
        build/src/os/code_42bc0_len_60.o(.text);
        build/src/os/code_42c20_len_e0.o(.text);
        build/src/os/code_42d00_len_60.o(.text);
        build/src/os/code_42d60_len_80.o(.text);
        build/src/os/code_42de0_len_90.o(.text);
        build/src/os/code_42e70_len_390.o(.text);
        build/src/os/code_43200_len_7c0.o(.text);
        build/src/os/code_439c0_len_220.o(.text);
        build/src/os/code_43be0_len_5e0.o(.text);
        build/src/os/code_441c0_len_1c0.o(.text);
        build/src/os/code_44380_len_4e0.o(.text);
        build/src/os/code_44860_len_60.o(.text);
        build/src/os/code_448c0_len_210.o(.text);
        build/src/os/code_44ad0_len_70.o(.text);
        build/src/os/code_44b40_len_a90.o(.text);
        build/src/os/code_455d0_len_1f0.o(.text);
        build/src/os/code_457c0_len_270.o(.text);
        build/src/os/code_45a30_len_20.o(.text);
        build/src/os/code_45a50_len_3a0.o(.text);
        build/src/os/code_45df0_len_970.o(.text);
        build/src/os/code_46760_len_90.o(.text);
        build/src/os/code_467f0_len_90.o(.text);
        build/src/os/code_46880_len_260.o(.text);
        build/src/os/code_46ae0_len_170.o(.text);
        build/src/os/code_46c50_len_20.o(.text);
        build/src/os/code_46c70_len_e00.o(.text);
        build/src/os/code_47a70_len_10.o(.text);
        build/src/os/code_47a80_len_10.o(.text);
        build/src/os/code_47a90_len_50.o(.text);
        build/src/os/code_47ae0_len_e0.o(.text);
        build/src/os/code_47bc0_len_50.o(.text);
        build/src/os/code_47c10_len_50.o(.text);
        build/src/os/code_47c60_len_f0.o(.text);
        build/src/os/code_47d50_len_e0.o(.text);
        build/src/os/code_47e30_len_60.o(.text);
        build/src/os/code_47e90_len_110.o(.text);
        build/src/os/code_47fa0_len_20.o(.text);
        build/src/os/code_47fc0_len_60.o(.text);
        build/src/os/code_48020_len_a00.o(.text);
        build/src/os/code_48a20_len_1c0.o(.text);
        build/src/os/code_48be0_len_20.o(.text);
        build/src/os/code_48c00_len_5c0.o(.text);
        build/src/os/code_491c0_len_f80.o(.text);
        build/src/os/code_49C70.o(.text);
        build/src/os/code_4a140_len_70.o(.text);
        build/src/os/code_4a1b0_len_40.o(.text);
        build/src/os/code_4a1f0_len_170.o(.text);
        build/src/os/code_4a360_len_930.o(.text);
        build/src/os/code_4ac90_len_3910.o(.text);
        build/bin/code_4E5A0.o(.data);
    }

    /* 0x800DC500 759B0-A5DD0 (len 30420) */
    .text_759B0 0x800DC500 : AT(0x759B0) {
        build/src/code_759b0_len_61b0.o(.text);
        build/src/code_7bb60_len_41b0.o(.text);
        build/src/code_7fd10_len_b40.o(.text);
        build/src/code_80850_len_3060.o(.text);
        build/src/code_838b0_len_5900.o(.text);
        build/src/code_891b0_len_fb0.o(.text);
        build/src/code_8a160_len_700.o(.text);
        build/src/code_8a860_len_3f30.o(.text);
        build/src/code_8e790_len_2850.o(.text);
        build/bin/code_90FE0.o(.data);
    }

    /* 0x8010F6D0 A5DD0-E79B0 (len 41BE0) */
    .text_A5DD0 0x8010F6D0 : AT(0xA5DD0) {
        build/src/code_a5dd0_len_114e0.o(.text);
        build/src/code_b72b0_len_15ed0.o(.text);
        build/src/code_cd180_len_38f0.o(.text);
        build/src/code_d0a70_len_4fe0.o(.text);
        build/src/code_d5a50_len_5fd0.o(.text);
        build/src/code_dba20_len_350.o(.text);
        build/src/code_dbd70_len_700.o(.text);
        build/src/code_dc470_len_14c0.o(.text);
        build/src/code_dd930_len_1c0.o(.text);
        build/src/code_ddaf0_len_c50.o(.text);
        build/src/code_de740_len_23f0.o(.text);
        build/src/code_e0b30_len_b80.o(.text);
        build/bin/code_E16B0.o(.data);
        build/src/code_dc470_len_14c0.o(.data);
        build/bin/code_E5830.o(.data);
    }

    /* 0x802C3000 E79B0-FEE30 (len 17480) */
    .text_E79B0 0x802C3000 : AT(0xE79B0) {
        build/src/code_e79b0_len_1920.o(.text);
        build/src/code_e92d0_len_5da0.o(.text);
        build/src/code_ef070_len_3400.o(.text);
        build/src/code_f2470_len_27f0.o(.text);
        build/src/code_f4c60_len_4300.o(.text);
        build/src/code_F5750.o(.text);
        build/src/code_f8f60_len_1560.o(.text);
        build/src/code_fa4c0_len_3bf0.o(.text);
        build/src/code_fe0b0_len_5a0.o(.text);
        build/bin/code_FE650.o(.data);
    }

    /* 0x802DBD40 FEE30-102610 (len 37E0) */
    .text_FEE30 0x802DBD40 : AT(0xFEE30) {
        build/src/code_fee30_len_2d60.o(.text);
        build/src/code_101b90_len_8f0.o(.text);
        build/bin/code_102480.o(.data);
    }

    /* 0x802E0D90 102610-10A9F0 (len 83E0) */
    .text_102610 0x802E0D90 : AT(0x102610) {
        build/src/code_102610_len_2330.o(.text);
        build/src/code_104940_len_dc0.o(.text);
        build/src/code_105700_len_2130.o(.text);
        build/src/code_107830_len_e70.o(.text);
        build/src/code_1086a0_len_fc0.o(.text);
        build/src/code_109660_len_1270.o(.text);
        build/src/code_10A8D0.o(.text);
    }

    /* 0x00000000 10A9F0-131340 [26950] */
    .data_10A9F0 0x10A9F0 : AT(0x10A9F0) {
        build/bin/10A9F0.o(.data);
    }

    /* 0x00000000 131340-135EE0 [4BA0] */
    .data_131340 0x131340 : AT(0x131340) {
        build/bin/131340.o(.data);
    }

    /* 0x80242BA0 135EE0-163400 (len 2D520) */
    .text_135EE0 0x80242BA0 : AT(0x135EE0) {
        build/src/code_135EE0.o(.text);
        build/bin/code_1422A0.o(.data);
    }

    /* 0x80242BA0 163400-16C8E0 (len 94E0) */
    .text_163400 0x80242BA0 : AT(0x163400) {
        build/src/code_163400.o(.text);
        build/src/code_167570.o(.text);
        build/src/code_168590.o(.text);
        build/src/code_169BE0.o(.text);
        build/bin/code_16A3E0.o(.data);
    }

    /* 0x8023E000 16C8E0-1CC310 (len 5FA30) */
    .text_16C8E0 0x8023E000 : AT(0x16C8E0) {
        build/src/code_16c8e0.o(.text);
        build/bin/code_1AF2C0.o(.data);
    }

    /* 0x00000000 1CC310-3169F0 [14A6E0] */
    .data_1CC310 0x1CC310 : AT(0x1CC310) {
        build/bin/1CC310.o(.data);
    }

    /* 0x80200000 3169F0-316C00 (len 210) */
    .text_3169F0 0x80200000 : AT(0x3169F0) {
        build/src/code_3169f0.o(.text);
        build/src/code_316a70.o(.text);
    }

    /* 0x00000000 316C00-316D90 [190] */
    .data_316C00 0x316C00 : AT(0x316C00) {
        build/bin/316C00.o(.data);
    }

    /* 0x802AE000 316D90-316F30 (len 1A0) */
    .text_316D90 0x802AE000 : AT(0x316D90) {
        build/src/code_316d90.o(.text);
    }

    /* 0x802B2000 316F30-317020 (len F0) */
    .text_316F30 0x802B2000 : AT(0x316F30) {
        build/src/code_316f30.o(.text);
    }

    /* 0x00000000 317020-415D90 [FED70] */
    .data_317020 0x317020 : AT(0x317020) {
        build/bin/317020.o(.data);
    }

    /* 0x802A1000 415D90-4200C0 (len A330) */
    .text_415D90 0x802A1000 : AT(0x415D90) {
        build/src/code_415D90.o(.text);
    }

    /* 0x00000000 4200C0-7E0E80 [3C0DC0] */
    .data_4200C0 0x4200C0 : AT(0x4200C0) {
        build/bin/4200C0.o(.data);
    }

    /* 0x80280000 7E0E80-7E4D00 (len 3E80) */
    .text_7E0E80 0x80280000 : AT(0x7E0E80) {
        build/src/code_7e0e80.o(.text);
        build/src/code_7E2AA0.o(.text);
        build/src/code_7E3700.o(.text);
    }

    /* 0x00000000 7E4D00-E20EB0 [63C1B0] */
    .data_7E4D00 0x7E4D00 : AT(0x7E4D00) {
        build/bin/7E4D00.o(.data);
    }

    /* 0x802B7000 E20EB0-E215C0 (len 710) */
    .text_E20EB0 0x802B7000 : AT(0xE20EB0) {
        build/src/code_e20eb0.o(.text);
    }

    /* 0x00000000 E215C0-F007C0 [DF200] */
    .data_E215C0 0xE215C0 : AT(0xE215C0) {
        build/bin/E215C0.o(.data);
    }

    /* 0x00000000 F007C0-F02160 [19A0] */
    .data_Battle_Fanfare_02 0xF007C0 : AT(0xF007C0) {
        build/bin/Battle_Fanfare_02.o(.data);
    }

    /* 0x00000000 F02160-F03740 [15E0] */
    .data_Hey_You_03 0xF02160 : AT(0xF02160) {
        build/bin/Hey_You_03.o(.data);
    }

    /* 0x00000000 F03740-F043F0 [CB0] */
    .data_The_Goomba_King_s_Decree_07 0xF03740 : AT(0xF03740) {
        build/bin/The_Goomba_King_s_Decree_07.o(.data);
    }

    /* 0x00000000 F043F0-F073C0 [2FD0] */
    .data_Attack_of_the_Koopa_Bros_08 0xF043F0 : AT(0xF043F0) {
        build/bin/Attack_of_the_Koopa_Bros_08.o(.data);
    }

    /* 0x00000000 F073C0-F08D40 [1980] */
    .data_Trojan_Bowser_09 0xF073C0 : AT(0xF073C0) {
        build/bin/Trojan_Bowser_09.o(.data);
    }

    /* 0x00000000 F08D40-F09600 [8C0] */
    .data_Chomp_Attack_0A 0xF08D40 : AT(0xF08D40) {
        build/bin/Chomp_Attack_0A.o(.data);
    }

    /* 0x00000000 F09600-F0A550 [F50] */
    .data_Ghost_Gulping_0B 0xF09600 : AT(0xF09600) {
        build/bin/Ghost_Gulping_0B.o(.data);
    }

    /* 0x00000000 F0A550-F0BAE0 [1590] */
    .data_Keeping_Pace_0C 0xF0A550 : AT(0xF0A550) {
        build/bin/Keeping_Pace_0C.o(.data);
    }

    /* 0x00000000 F0BAE0-F0DEC0 [23E0] */
    .data_Go_Mario_Go_0D 0xF0BAE0 : AT(0xF0BAE0) {
        build/bin/Go_Mario_Go_0D.o(.data);
    }

    /* 0x00000000 F0DEC0-F0FD20 [1E60] */
    .data_Huffin_and_Puffin_0E 0xF0DEC0 : AT(0xF0DEC0) {
        build/bin/Huffin_and_Puffin_0E.o(.data);
    }

    /* 0x00000000 F0FD20-F110D0 [13B0] */
    .data_Freeze_0F 0xF0FD20 : AT(0xF0FD20) {
        build/bin/Freeze_0F.o(.data);
    }

    /* 0x00000000 F110D0-F116C0 [5F0] */
    .data_Winning_a_Battle_8B 0xF110D0 : AT(0xF110D0) {
        build/bin/Winning_a_Battle_8B.o(.data);
    }

    /* 0x00000000 F116C0-F12320 [C60] */
    .data_Winning_a_Battle_and_Level_Up_8E 0xF116C0 : AT(0xF116C0) {
        build/bin/Winning_a_Battle_and_Level_Up_8E.o(.data);
    }

    /* 0x00000000 F12320-F13C20 [1900] */
    .data_Jr_Troopa_Battle_04 0xF12320 : AT(0xF12320) {
        build/bin/Jr_Troopa_Battle_04.o(.data);
    }

    /* 0x00000000 F13C20-F15F40 [2320] */
    .data_Final_Bowser_Battle_interlude_05 0xF13C20 : AT(0xF13C20) {
        build/bin/Final_Bowser_Battle_interlude_05.o(.data);
    }

    /* 0x00000000 F15F40-F16F80 [1040] */
    .data_Master_Battle_2C 0xF15F40 : AT(0xF15F40) {
        build/bin/Master_Battle_2C.o(.data);
    }

    /* 0x00000000 F16F80-F171D0 [250] */
    .data_Game_Over_87 0xF16F80 : AT(0xF16F80) {
        build/bin/Game_Over_87.o(.data);
    }

    /* 0x00000000 F171D0-F17370 [1A0] */
    .data_Resting_at_the_Toad_House_88 0xF171D0 : AT(0xF171D0) {
        build/bin/Resting_at_the_Toad_House_88.o(.data);
    }

    /* 0x00000000 F17370-F17570 [200] */
    .data_Running_around_the_Heart_Pillar_in_Ch1_84 0xF17370 : AT(0xF17370) {
        build/bin/Running_around_the_Heart_Pillar_in_Ch1_84.o(.data);
    }

    /* 0x00000000 F17570-F18940 [13D0] */
    .data_Tutankoopa_s_Warning_45 0xF17570 : AT(0xF17570) {
        build/bin/Tutankoopa_s_Warning_45.o(.data);
    }

    /* 0x00000000 F18940-F193D0 [A90] */
    .data_Kammy_Koopa_s_Theme_46 0xF18940 : AT(0xF18940) {
        build/bin/Kammy_Koopa_s_Theme_46.o(.data);
    }

    /* 0x00000000 F193D0-F19BC0 [7F0] */
    .data_Jr_Troopa_s_Theme_47 0xF193D0 : AT(0xF193D0) {
        build/bin/Jr_Troopa_s_Theme_47.o(.data);
    }

    /* 0x00000000 F19BC0-F1A6F0 [B30] */
    .data_Goomba_King_s_Theme_50 0xF19BC0 : AT(0xF19BC0) {
        build/bin/Goomba_King_s_Theme_50.o(.data);
    }

    /* 0x00000000 F1A6F0-F1ABD0 [4E0] */
    .data_Koopa_Bros_Defeated_51 0xF1A6F0 : AT(0xF1A6F0) {
        build/bin/Koopa_Bros_Defeated_51.o(.data);
    }

    /* 0x00000000 F1ABD0-F1C810 [1C40] */
    .data_Koopa_Bros_Theme_52 0xF1ABD0 : AT(0xF1ABD0) {
        build/bin/Koopa_Bros_Theme_52.o(.data);
    }

    /* 0x00000000 F1C810-F1DBF0 [13E0] */
    .data_Tutankoopa_s_Warning_2_53 0xF1C810 : AT(0xF1C810) {
        build/bin/Tutankoopa_s_Warning_2_53.o(.data);
    }

    /* 0x00000000 F1DBF0-F1F2E0 [16F0] */
    .data_Tutankoopa_s_Theme_54 0xF1DBF0 : AT(0xF1DBF0) {
        build/bin/Tutankoopa_s_Theme_54.o(.data);
    }

    /* 0x00000000 F1F2E0-F20FF0 [1D10] */
    .data_Tubba_Blubba_s_Theme_55 0xF1F2E0 : AT(0xF1F2E0) {
        build/bin/Tubba_Blubba_s_Theme_55.o(.data);
    }

    /* 0x00000000 F20FF0-F21780 [790] */
    .data_General_Guy_s_Theme_56 0xF20FF0 : AT(0xF20FF0) {
        build/bin/General_Guy_s_Theme_56.o(.data);
    }

    /* 0x00000000 F21780-F22A00 [1280] */
    .data_Lava_Piranha_s_Theme_57 0xF21780 : AT(0xF21780) {
        build/bin/Lava_Piranha_s_Theme_57.o(.data);
    }

    /* 0x00000000 F22A00-F23A00 [1000] */
    .data_Huff_N_Puff_s_Theme_58 0xF22A00 : AT(0xF22A00) {
        build/bin/Huff_N_Puff_s_Theme_58.o(.data);
    }

    /* 0x00000000 F23A00-F24810 [E10] */
    .data_Crystal_King_s_Theme_59 0xF23A00 : AT(0xF23A00) {
        build/bin/Crystal_King_s_Theme_59.o(.data);
    }

    /* 0x00000000 F24810-F25240 [A30] */
    .data_Blooper_s_Theme_5A 0xF24810 : AT(0xF24810) {
        build/bin/Blooper_s_Theme_5A.o(.data);
    }

    /* 0x00000000 F25240-F26260 [1020] */
    .data_Midboss_Theme_5B 0xF25240 : AT(0xF25240) {
        build/bin/Midboss_Theme_5B.o(.data);
    }

    /* 0x00000000 F26260-F27840 [15E0] */
    .data_Monstar_s_Theme_5C 0xF26260 : AT(0xF26260) {
        build/bin/Monstar_s_Theme_5C.o(.data);
    }

    /* 0x00000000 F27840-F27E20 [5E0] */
    .data_Moustafa_s_Theme_86 0xF27840 : AT(0xF27840) {
        build/bin/Moustafa_s_Theme_86.o(.data);
    }

    /* 0x00000000 F27E20-F28E20 [1000] */
    .data_Fuzzy_Searching_Minigame_85 0xF27E20 : AT(0xF27E20) {
        build/bin/Fuzzy_Searching_Minigame_85.o(.data);
    }

    /* 0x00000000 F28E20-F29AC0 [CA0] */
    .data_Phonograph_in_Mansion_44 0xF28E20 : AT(0xF28E20) {
        build/bin/Phonograph_in_Mansion_44.o(.data);
    }

    /* 0x00000000 F29AC0-F2E130 [4670] */
    .data_Toad_Town_00 0xF29AC0 : AT(0xF29AC0) {
        build/bin/Toad_Town_00.o(.data);
    }

    /* 0x00000000 F2E130-F2EF90 [E60] */
    .data_Bill_Blaster_Theme_48 0xF2E130 : AT(0xF2E130) {
        build/bin/Bill_Blaster_Theme_48.o(.data);
    }

    /* 0x00000000 F2EF90-F30590 [1600] */
    .data_Monty_Mole_Theme_in_Flower_Fields_49 0xF2EF90 : AT(0xF2EF90) {
        build/bin/Monty_Mole_Theme_in_Flower_Fields_49.o(.data);
    }

    /* 0x00000000 F30590-F318B0 [1320] */
    .data_Shy_Guys_in_Toad_Town_4A 0xF30590 : AT(0xF30590) {
        build/bin/Shy_Guys_in_Toad_Town_4A.o(.data);
    }

    /* 0x00000000 F318B0-F32220 [970] */
    .data_Whale_s_Problem_4C 0xF318B0 : AT(0xF318B0) {
        build/bin/Whale_s_Problem_4C.o(.data);
    }

    /* 0x00000000 F32220-F33060 [E40] */
    .data_Toad_Town_Sewers_4B 0xF32220 : AT(0xF32220) {
        build/bin/Toad_Town_Sewers_4B.o(.data);
    }

    /* 0x00000000 F33060-F33AA0 [A40] */
    .data_Unused_Theme_4D 0xF33060 : AT(0xF33060) {
        build/bin/Unused_Theme_4D.o(.data);
    }

    /* 0x00000000 F33AA0-F33F10 [470] */
    .data_Mario_s_House_Prologue_3E 0xF33AA0 : AT(0xF33AA0) {
        build/bin/Mario_s_House_Prologue_3E.o(.data);
    }

    /* 0x00000000 F33F10-F354E0 [15D0] */
    .data_Peach_s_Party_3F 0xF33F10 : AT(0xF33F10) {
        build/bin/Peach_s_Party_3F.o(.data);
    }

    /* 0x00000000 F354E0-F35ED0 [9F0] */
    .data_Goomba_Village_01 0xF354E0 : AT(0xF354E0) {
        build/bin/Goomba_Village_01.o(.data);
    }

    /* 0x00000000 F35ED0-F36690 [7C0] */
    .data_Pleasant_Path_11 0xF35ED0 : AT(0xF35ED0) {
        build/bin/Pleasant_Path_11.o(.data);
    }

    /* 0x00000000 F36690-F379E0 [1350] */
    .data_Fuzzy_s_Took_My_Shell_12 0xF36690 : AT(0xF36690) {
        build/bin/Fuzzy_s_Took_My_Shell_12.o(.data);
    }

    /* 0x00000000 F379E0-F38570 [B90] */
    .data_Koopa_Village_13 0xF379E0 : AT(0xF379E0) {
        build/bin/Koopa_Village_13.o(.data);
    }

    /* 0x00000000 F38570-F39160 [BF0] */
    .data_Koopa_Bros_Fortress_14 0xF38570 : AT(0xF38570) {
        build/bin/Koopa_Bros_Fortress_14.o(.data);
    }

    /* 0x00000000 F39160-F3A0D0 [F70] */
    .data_Dry_Dry_Ruins_18 0xF39160 : AT(0xF39160) {
        build/bin/Dry_Dry_Ruins_18.o(.data);
    }

    /* 0x00000000 F3A0D0-F3A450 [380] */
    .data_Dry_Dry_Ruins_Mystery_19 0xF3A0D0 : AT(0xF3A0D0) {
        build/bin/Dry_Dry_Ruins_Mystery_19.o(.data);
    }

    /* 0x00000000 F3A450-F3AF20 [AD0] */
    .data_Mt_Rugged_16 0xF3A450 : AT(0xF3A450) {
        build/bin/Mt_Rugged_16.o(.data);
    }

    /* 0x00000000 F3AF20-F3C130 [1210] */
    .data_Dry_Dry_Desert_Oasis_17 0xF3AF20 : AT(0xF3AF20) {
        build/bin/Dry_Dry_Desert_Oasis_17.o(.data);
    }

    /* 0x00000000 F3C130-F3CCC0 [B90] */
    .data_Dry_Dry_Outpost_15 0xF3C130 : AT(0xF3C130) {
        build/bin/Dry_Dry_Outpost_15.o(.data);
    }

    /* 0x00000000 F3CCC0-F3E130 [1470] */
    .data_Forever_Forest_1A 0xF3CCC0 : AT(0xF3CCC0) {
        build/bin/Forever_Forest_1A.o(.data);
    }

    /* 0x00000000 F3E130-F3F3E0 [12B0] */
    .data_Boo_s_Mansion_1B 0xF3E130 : AT(0xF3E130) {
        build/bin/Boo_s_Mansion_1B.o(.data);
    }

    /* 0x00000000 F3F3E0-F40F00 [1B20] */
    .data_Bow_s_Theme_1C 0xF3F3E0 : AT(0xF3F3E0) {
        build/bin/Bow_s_Theme_1C.o(.data);
    }

    /* 0x00000000 F40F00-F42F30 [2030] */
    .data_Gusty_Gulch_Adventure_1D 0xF40F00 : AT(0xF40F00) {
        build/bin/Gusty_Gulch_Adventure_1D.o(.data);
    }

    /* 0x00000000 F42F30-F45500 [25D0] */
    .data_Tubba_Blubba_s_Castle_1E 0xF42F30 : AT(0xF42F30) {
        build/bin/Tubba_Blubba_s_Castle_1E.o(.data);
    }

    /* 0x00000000 F45500-F465E0 [10E0] */
    .data_The_Castle_Crumbles_1F 0xF45500 : AT(0xF45500) {
        build/bin/The_Castle_Crumbles_1F.o(.data);
    }

    /* 0x00000000 F465E0-F474A0 [EC0] */
    .data_Shy_Guy_s_Toy_Box_20 0xF465E0 : AT(0xF465E0) {
        build/bin/Shy_Guy_s_Toy_Box_20.o(.data);
    }

    /* 0x00000000 F474A0-F47E10 [970] */
    .data_Toy_Train_Travel_21 0xF474A0 : AT(0xF474A0) {
        build/bin/Toy_Train_Travel_21.o(.data);
    }

    /* 0x00000000 F47E10-F48410 [600] */
    .data_Big_Lantern_Ghost_s_Theme_22 0xF47E10 : AT(0xF47E10) {
        build/bin/Big_Lantern_Ghost_s_Theme_22.o(.data);
    }

    /* 0x00000000 F48410-F4A880 [2470] */
    .data_Jade_Jungle_24 0xF48410 : AT(0xF48410) {
        build/bin/Jade_Jungle_24.o(.data);
    }

    /* 0x00000000 F4A880-F4BC00 [1380] */
    .data_Deep_Jungle_25 0xF4A880 : AT(0xF4A880) {
        build/bin/Deep_Jungle_25.o(.data);
    }

    /* 0x00000000 F4BC00-F4E690 [2A90] */
    .data_Lavalava_Island_26 0xF4BC00 : AT(0xF4BC00) {
        build/bin/Lavalava_Island_26.o(.data);
    }

    /* 0x00000000 F4E690-F50A00 [2370] */
    .data_Search_for_the_Fearsome_5_27 0xF4E690 : AT(0xF4E690) {
        build/bin/Search_for_the_Fearsome_5_27.o(.data);
    }

    /* 0x00000000 F50A00-F52520 [1B20] */
    .data_Raphael_the_Raven_28 0xF50A00 : AT(0xF50A00) {
        build/bin/Raphael_the_Raven_28.o(.data);
    }

    /* 0x00000000 F52520-F55C80 [3760] */
    .data_Hot_Times_in_Mt_Lavalava_29 0xF52520 : AT(0xF52520) {
        build/bin/Hot_Times_in_Mt_Lavalava_29.o(.data);
    }

    /* 0x00000000 F55C80-F58ED0 [3250] */
    .data_Escape_from_Mt_Lavalava_2A 0xF55C80 : AT(0xF55C80) {
        build/bin/Escape_from_Mt_Lavalava_2A.o(.data);
    }

    /* 0x00000000 F58ED0-F592B0 [3E0] */
    .data_Cloudy_Climb_32 0xF58ED0 : AT(0xF58ED0) {
        build/bin/Cloudy_Climb_32.o(.data);
    }

    /* 0x00000000 F592B0-F5AFF0 [1D40] */
    .data_Puff_Puff_Machine_33 0xF592B0 : AT(0xF592B0) {
        build/bin/Puff_Puff_Machine_33.o(.data);
    }

    /* 0x00000000 F5AFF0-F5C8D0 [18E0] */
    .data_Flower_Fields_30 0xF5AFF0 : AT(0xF5AFF0) {
        build/bin/Flower_Fields_30.o(.data);
    }

    /* 0x00000000 F5C8D0-F5DF40 [1670] */
    .data_Flower_Fields_Sunny_31 0xF5C8D0 : AT(0xF5C8D0) {
        build/bin/Flower_Fields_Sunny_31.o(.data);
    }

    /* 0x00000000 F5DF40-F5F500 [15C0] */
    .data_Sun_s_Tower_34 0xF5DF40 : AT(0xF5DF40) {
        build/bin/Sun_s_Tower_34.o(.data);
    }

    /* 0x00000000 F5F500-F61700 [2200] */
    .data_Sun_s_Celebration_35 0xF5F500 : AT(0xF5F500) {
        build/bin/Sun_s_Celebration_35.o(.data);
    }

    /* 0x00000000 F61700-F62E50 [1750] */
    .data_Shiver_City_38 0xF61700 : AT(0xF61700) {
        build/bin/Shiver_City_38.o(.data);
    }

    /* 0x00000000 F62E50-F64220 [13D0] */
    .data_Detective_Mario_39 0xF62E50 : AT(0xF62E50) {
        build/bin/Detective_Mario_39.o(.data);
    }

    /* 0x00000000 F64220-F64CB0 [A90] */
    .data_Snow_Road_3A 0xF64220 : AT(0xF64220) {
        build/bin/Snow_Road_3A.o(.data);
    }

    /* 0x00000000 F64CB0-F65B30 [E80] */
    .data_Over_Shiver_Mountain_3B 0xF64CB0 : AT(0xF64CB0) {
        build/bin/Over_Shiver_Mountain_3B.o(.data);
    }

    /* 0x00000000 F65B30-F66690 [B60] */
    .data_Starborn_Valley_3C 0xF65B30 : AT(0xF65B30) {
        build/bin/Starborn_Valley_3C.o(.data);
    }

    /* 0x00000000 F66690-F66B70 [4E0] */
    .data_Sanctuary_3D 0xF66690 : AT(0xF66690) {
        build/bin/Sanctuary_3D.o(.data);
    }

    /* 0x00000000 F66B70-F67F80 [1410] */
    .data_Crystal_Palace_37 0xF66B70 : AT(0xF66B70) {
        build/bin/Crystal_Palace_37.o(.data);
    }

    /* 0x00000000 F67F80-F69640 [16C0] */
    .data_Star_Haven_60 0xF67F80 : AT(0xF67F80) {
        build/bin/Star_Haven_60.o(.data);
    }

    /* 0x00000000 F69640-F6A050 [A10] */
    .data_Shooting_Star_Summit_61 0xF69640 : AT(0xF69640) {
        build/bin/Shooting_Star_Summit_61.o(.data);
    }

    /* 0x00000000 F6A050-F6C270 [2220] */
    .data_Legendary_Star_Ship_62 0xF6A050 : AT(0xF6A050) {
        build/bin/Legendary_Star_Ship_62.o(.data);
    }

    /* 0x00000000 F6C270-F6CED0 [C60] */
    .data_Star_Sanctuary_63 0xF6C270 : AT(0xF6C270) {
        build/bin/Star_Sanctuary_63.o(.data);
    }

    /* 0x00000000 F6CED0-F6EE40 [1F70] */
    .data_Bowser_s_Castle_-_Caves_65 0xF6CED0 : AT(0xF6CED0) {
        build/bin/Bowser_s_Castle_-_Caves_65.o(.data);
    }

    /* 0x00000000 F6EE40-F73390 [4550] */
    .data_Bowser_s_Castle_64 0xF6EE40 : AT(0xF6EE40) {
        build/bin/Bowser_s_Castle_64.o(.data);
    }

    /* 0x00000000 F73390-F751F0 [1E60] */
    .data_Star_Elevator_2B 0xF73390 : AT(0xF73390) {
        build/bin/Star_Elevator_2B.o(.data);
    }

    /* 0x00000000 F751F0-F759C0 [7D0] */
    .data_Goomba_Bros_Defeated_7E 0xF751F0 : AT(0xF751F0) {
        build/bin/Goomba_Bros_Defeated_7E.o(.data);
    }

    /* 0x00000000 F759C0-F77200 [1840] */
    .data_Farewell_Twink_70 0xF759C0 : AT(0xF759C0) {
        build/bin/Farewell_Twink_70.o(.data);
    }

    /* 0x00000000 F77200-F77680 [480] */
    .data_Peach_Cooking_71 0xF77200 : AT(0xF77200) {
        build/bin/Peach_Cooking_71.o(.data);
    }

    /* 0x00000000 F77680-F78600 [F80] */
    .data_Gourmet_Guy_72 0xF77680 : AT(0xF77680) {
        build/bin/Gourmet_Guy_72.o(.data);
    }

    /* 0x00000000 F78600-F79070 [A70] */
    .data_Hope_on_the_Balcony_Peach_1_73 0xF78600 : AT(0xF78600) {
        build/bin/Hope_on_the_Balcony_Peach_1_73.o(.data);
    }

    /* 0x00000000 F79070-F7A0C0 [1050] */
    .data_Peach_s_Theme_2_74 0xF79070 : AT(0xF79070) {
        build/bin/Peach_s_Theme_2_74.o(.data);
    }

    /* 0x00000000 F7A0C0-F7AA40 [980] */
    .data_Peach_Sneaking_75 0xF7A0C0 : AT(0xF7A0C0) {
        build/bin/Peach_Sneaking_75.o(.data);
    }

    /* 0x00000000 F7AA40-F7AD90 [350] */
    .data_Peach_Captured_76 0xF7AA40 : AT(0xF7AA40) {
        build/bin/Peach_Captured_76.o(.data);
    }

    /* 0x00000000 F7AD90-F7BEA0 [1110] */
    .data_Quiz_Show_Intro_77 0xF7AD90 : AT(0xF7AD90) {
        build/bin/Quiz_Show_Intro_77.o(.data);
    }

    /* 0x00000000 F7BEA0-F7C780 [8E0] */
    .data_Unconscious_Mario_78 0xF7BEA0 : AT(0xF7BEA0) {
        build/bin/Unconscious_Mario_78.o(.data);
    }

    /* 0x00000000 F7C780-F7DC00 [1480] */
    .data_Petunia_s_Theme_89 0xF7C780 : AT(0xF7C780) {
        build/bin/Petunia_s_Theme_89.o(.data);
    }

    /* 0x00000000 F7DC00-F7E190 [590] */
    .data_Flower_Fields_Door_appears_8A 0xF7DC00 : AT(0xF7DC00) {
        build/bin/Flower_Fields_Door_appears_8A.o(.data);
    }

    /* 0x00000000 F7E190-F7EE20 [C90] */
    .data_Beanstalk_7B 0xF7E190 : AT(0xF7E190) {
        build/bin/Beanstalk_7B.o(.data);
    }

    /* 0x00000000 F7EE20-F80230 [1410] */
    .data_Lakilester_s_Theme_7D 0xF7EE20 : AT(0xF7EE20) {
        build/bin/Lakilester_s_Theme_7D.o(.data);
    }

    /* 0x00000000 F80230-F81260 [1030] */
    .data_The_Sun_s_Back_7F 0xF80230 : AT(0xF80230) {
        build/bin/The_Sun_s_Back_7F.o(.data);
    }

    /* 0x00000000 F81260-F82460 [1200] */
    .data_Shiver_City_in_Crisis_79 0xF81260 : AT(0xF81260) {
        build/bin/Shiver_City_in_Crisis_79.o(.data);
    }

    /* 0x00000000 F82460-F82D00 [8A0] */
    .data_Solved_Shiver_City_Mystery_7A 0xF82460 : AT(0xF82460) {
        build/bin/Solved_Shiver_City_Mystery_7A.o(.data);
    }

    /* 0x00000000 F82D00-F83DC0 [10C0] */
    .data_Merlon_s_Spell_7C 0xF82D00 : AT(0xF82D00) {
        build/bin/Merlon_s_Spell_7C.o(.data);
    }

    /* 0x00000000 F83DC0-F85590 [17D0] */
    .data_Bowser_s_Theme_66 0xF83DC0 : AT(0xF83DC0) {
        build/bin/Bowser_s_Theme_66.o(.data);
    }

    /* 0x00000000 F85590-F860E0 [B50] */
    .data_Train_Travel_80 0xF85590 : AT(0xF85590) {
        build/bin/Train_Travel_80.o(.data);
    }

    /* 0x00000000 F860E0-F87000 [F20] */
    .data_Whale_Trip_81 0xF860E0 : AT(0xF860E0) {
        build/bin/Whale_Trip_81.o(.data);
    }

    /* 0x00000000 F87000-F87610 [610] */
    .data_Chanterelle_s_Song_8C 0xF87000 : AT(0xF87000) {
        build/bin/Chanterelle_s_Song_8C.o(.data);
    }

    /* 0x00000000 F87610-F88B30 [1520] */
    .data_Boo_s_Game_8D 0xF87610 : AT(0xF87610) {
        build/bin/Boo_s_Game_8D.o(.data);
    }

    /* 0x00000000 F88B30-F89570 [A40] */
    .data_Dry_Dry_Ruins_rises_up_83 0xF88B30 : AT(0xF88B30) {
        build/bin/Dry_Dry_Ruins_rises_up_83.o(.data);
    }

    /* 0x00000000 F89570-F8AAF0 [1580] */
    .data_End_of_Chapter_40 0xF89570 : AT(0xF89570) {
        build/bin/End_of_Chapter_40.o(.data);
    }

    /* 0x00000000 F8AAF0-F8B820 [D30] */
    .data_Beginning_of_Chapter_41 0xF8AAF0 : AT(0xF8AAF0) {
        build/bin/Beginning_of_Chapter_41.o(.data);
    }

    /* 0x00000000 F8B820-F8BD90 [570] */
    .data_Hammer_and_Jump_Upgrade_42 0xF8B820 : AT(0xF8B820) {
        build/bin/Hammer_and_Jump_Upgrade_42.o(.data);
    }

    /* 0x00000000 F8BD90-F8C360 [5D0] */
    .data_Found_Baby_Yoshi_s_4E 0xF8BD90 : AT(0xF8BD90) {
        build/bin/Found_Baby_Yoshi_s_4E.o(.data);
    }

    /* 0x00000000 F8C360-F8D110 [DB0] */
    .data_New_Partner_JAP_96 0xF8C360 : AT(0xF8C360) {
        build/bin/New_Partner_JAP_96.o(.data);
    }

    /* 0x00000000 F8D110-F8D3E0 [2D0] */
    .data_Unused_YI_Fanfare_4F 0xF8D110 : AT(0xF8D110) {
        build/bin/Unused_YI_Fanfare_4F.o(.data);
    }

    /* 0x00000000 F8D3E0-F90880 [34A0] */
    .data_Unused_YI_Fanfare_2_5D 0xF8D3E0 : AT(0xF8D3E0) {
        build/bin/Unused_YI_Fanfare_2_5D.o(.data);
    }

    /* 0x00000000 F90880-F92A50 [21D0] */
    .data_Peach_s_Castle_inside_Bubble_5E 0xF90880 : AT(0xF90880) {
        build/bin/Peach_s_Castle_inside_Bubble_5E.o(.data);
    }

    /* 0x00000000 F92A50-F95510 [2AC0] */
    .data_Angry_Bowser_67 0xF92A50 : AT(0xF92A50) {
        build/bin/Angry_Bowser_67.o(.data);
    }

    /* 0x00000000 F95510-F96280 [D70] */
    .data_Bowser_s_Castle_explodes_5F 0xF95510 : AT(0xF95510) {
        build/bin/Bowser_s_Castle_explodes_5F.o(.data);
    }

    /* 0x00000000 F96280-F98520 [22A0] */
    .data_Peach_s_Wish_68 0xF96280 : AT(0xF96280) {
        build/bin/Peach_s_Wish_68.o(.data);
    }

    /* 0x00000000 F98520-F98F90 [A70] */
    .data_File_Select_69 0xF98520 : AT(0xF98520) {
        build/bin/File_Select_69.o(.data);
    }

    /* 0x00000000 F98F90-F9B830 [28A0] */
    .data_Title_Screen_6A 0xF98F90 : AT(0xF98F90) {
        build/bin/Title_Screen_6A.o(.data);
    }

    /* 0x00000000 F9B830-F9D3B0 [1B80] */
    .data_Peach_s_Castle_in_Crisis_6B 0xF9B830 : AT(0xF9B830) {
        build/bin/Peach_s_Castle_in_Crisis_6B.o(.data);
    }

    /* 0x00000000 F9D3B0-F9D690 [2E0] */
    .data_Mario_falls_from_Bowser_s_Castle_6C 0xF9D3B0 : AT(0xF9D3B0) {
        build/bin/Mario_falls_from_Bowser_s_Castle_6C.o(.data);
    }

    /* 0x00000000 F9D690-F9EF30 [18A0] */
    .data_Peach_s_Arrival_6D 0xF9D690 : AT(0xF9D690) {
        build/bin/Peach_s_Arrival_6D.o(.data);
    }

    /* 0x00000000 F9EF30-F9FA30 [B00] */
    .data_Star_Rod_Recovered_6F 0xF9EF30 : AT(0xF9EF30) {
        build/bin/Star_Rod_Recovered_6F.o(.data);
    }

    /* 0x00000000 F9FA30-FA08A0 [E70] */
    .data_Mario_s_House_94 0xF9FA30 : AT(0xF9FA30) {
        build/bin/Mario_s_House_94.o(.data);
    }

    /* 0x00000000 FA08A0-FA3C60 [33C0] */
    .data_Bowser_s_Attacks_95 0xFA08A0 : AT(0xFA08A0) {
        build/bin/Bowser_s_Attacks_95.o(.data);
    }

    /* 0x00000000 FA3C60-FA85F0 [4990] */
    .data_End_Parade_1_90 0xFA3C60 : AT(0xFA3C60) {
        build/bin/End_Parade_1_90.o(.data);
    }

    /* 0x00000000 FA85F0-FABE90 [38A0] */
    .data_End_Parade_2_91 0xFA85F0 : AT(0xFA85F0) {
        build/bin/End_Parade_2_91.o(.data);
    }

    /* 0x00000000 FABE90-FACC80 [DF0] */
    .data_The_End_6E 0xFABE90 : AT(0xFABE90) {
        build/bin/The_End_6E.o(.data);
    }

    /* 0x00000000 FACC80-FAD210 [590] */
    .data_Koopa_Radio_Station_2D 0xFACC80 : AT(0xFACC80) {
        build/bin/Koopa_Radio_Station_2D.o(.data);
    }

    /* 0x00000000 FAD210-FAD8F0 [6E0] */
    .data_The_End_Low_Frequency__2E 0xFAD210 : AT(0xFAD210) {
        build/bin/The_End_Low_Frequency__2E.o(.data);
    }

    /* 0x00000000 FAD8F0-FADE70 [580] */
    .data_SMW_Remix_2F 0xFAD8F0 : AT(0xFAD8F0) {
        build/bin/SMW_Remix_2F.o(.data);
    }

    /* 0x00000000 FADE70-FAE860 [9F0] */
    .data_New_Partner_82 0xFADE70 : AT(0xFADE70) {
        build/bin/New_Partner_82.o(.data);
    }

    /* 0x00000000 FAE860-19E09A8 [A32148] */
    .data_FAE860 0xFAE860 : AT(0xFAE860) {
        build/bin/FAE860.o(.data);
    }

    /* 0x00000000 19E09A8-19E1390 [9E8] */
    .data_Yay0_19e09a8_len_1206 0x19E09A8 : AT(0x19E09A8) {
        build/bin/Yay0_19e09a8_len_1206.o(.data);
    }

    /* 0x00000000 19E1390-19E1888 [4F8] */
    .data_Yay0_19e1390_len_806 0x19E1390 : AT(0x19E1390) {
        build/bin/Yay0_19e1390_len_806.o(.data);
    }

    /* 0x00000000 19E1888-19E2330 [AA8] */
    .data_Yay0_19e1888_len_2324 0x19E1888 : AT(0x19E1888) {
        build/bin/Yay0_19e1888_len_2324.o(.data);
    }

    /* 0x00000000 19E2330-19E2DE0 [AB0] */
    .data_Yay0_19e2330_len_cc0 0x19E2330 : AT(0x19E2330) {
        build/bin/Yay0_19e2330_len_cc0.o(.data);
    }

    /* 0x00000000 19E2DE0-19E3208 [428] */
    .data_Yay0_19e2de0_len_1206 0x19E2DE0 : AT(0x19E2DE0) {
        build/bin/Yay0_19e2de0_len_1206.o(.data);
    }

    /* 0x00000000 19E3208-19E3BA8 [9A0] */
    .data_Yay0_19e3208_len_9a6 0x19E3208 : AT(0x19E3208) {
        build/bin/Yay0_19e3208_len_9a6.o(.data);
    }

    /* 0x00000000 19E3BA8-19E3FD8 [430] */
    .data_Yay0_19e3ba8_len_456 0x19E3BA8 : AT(0x19E3BA8) {
        build/bin/Yay0_19e3ba8_len_456.o(.data);
    }

    /* 0x00000000 19E3FD8-19E4828 [850] */
    .data_Yay0_19e3fd8_len_4024 0x19E3FD8 : AT(0x19E3FD8) {
        build/bin/Yay0_19e3fd8_len_4024.o(.data);
    }

    /* 0x00000000 19E4828-19E4BE0 [3B8] */
    .data_Yay0_19e4828_len_3c0 0x19E4828 : AT(0x19E4828) {
        build/bin/Yay0_19e4828_len_3c0.o(.data);
    }

    /* 0x00000000 19E4BE0-19E5758 [B78] */
    .data_Yay0_19e4be0_len_1416 0x19E4BE0 : AT(0x19E4BE0) {
        build/bin/Yay0_19e4be0_len_1416.o(.data);
    }

    /* 0x00000000 19E5758-19E5950 [1F8] */
    .data_Yay0_19e5758_len_802 0x19E5758 : AT(0x19E5758) {
        build/bin/Yay0_19e5758_len_802.o(.data);
    }

    /* 0x00000000 19E5950-19E62A0 [950] */
    .data_Yay0_19e5950_len_22a0 0x19E5950 : AT(0x19E5950) {
        build/bin/Yay0_19e5950_len_22a0.o(.data);
    }

    /* 0x00000000 19E62A0-19E67B2 [512] */
    .data_Yay0_19e62a0_len_512 0x19E62A0 : AT(0x19E62A0) {
        build/bin/Yay0_19e62a0_len_512.o(.data);
    }

    /* 0x00000000 19E67B2-19E6B60 [3AE] */
    .data_19E67B2 0x19E67B2 : AT(0x19E67B2) {
        build/bin/19E67B2.o(.data);
    }

    /* 0x00000000 19E6B60-19E7528 [9C8] */
    .data_Yay0_19e6b60_len_1406 0x19E6B60 : AT(0x19E6B60) {
        build/bin/Yay0_19e6b60_len_1406.o(.data);
    }

    /* 0x00000000 19E7528-19E9778 [2250] */
    .data_Yay0_19e7528_len_8256 0x19E7528 : AT(0x19E7528) {
        build/bin/Yay0_19e7528_len_8256.o(.data);
    }

    /* 0x00000000 19E9778-19EAF38 [17C0] */
    .data_Yay0_19e9778_len_2800 0x19E9778 : AT(0x19E9778) {
        build/bin/Yay0_19e9778_len_2800.o(.data);
    }

    /* 0x00000000 19EAF38-19EC4E0 [15A8] */
    .data_Yay0_19eaf38_len_40c0 0x19EAF38 : AT(0x19EAF38) {
        build/bin/Yay0_19eaf38_len_40c0.o(.data);
    }

    /* 0x00000000 19EC4E0-19EDD30 [1850] */
    .data_Yay0_19ec4e0_len_1910 0x19EC4E0 : AT(0x19EC4E0) {
        build/bin/Yay0_19ec4e0_len_1910.o(.data);
    }

    /* 0x00000000 19EDD30-19EEB18 [DE8] */
    .data_Yay0_19edd30_len_2204 0x19EDD30 : AT(0x19EDD30) {
        build/bin/Yay0_19edd30_len_2204.o(.data);
    }

    /* 0x00000000 19EEB18-19F0070 [1558] */
    .data_Yay0_19eeb18_len_10062 0x19EEB18 : AT(0x19EEB18) {
        build/bin/Yay0_19eeb18_len_10062.o(.data);
    }

    /* 0x00000000 19F0070-19F15A0 [1530] */
    .data_Yay0_19f0070_len_158c 0x19F0070 : AT(0x19F0070) {
        build/bin/Yay0_19f0070_len_158c.o(.data);
    }

    /* 0x00000000 19F15A0-19F26D8 [1138] */
    .data_Yay0_19f15a0_len_2252 0x19F15A0 : AT(0x19F15A0) {
        build/bin/Yay0_19f15a0_len_2252.o(.data);
    }

    /* 0x00000000 19F26D8-19F5390 [2CB8] */
    .data_Yay0_19f26d8_len_5102 0x19F26D8 : AT(0x19F26D8) {
        build/bin/Yay0_19f26d8_len_5102.o(.data);
    }

    /* 0x00000000 19F5390-19F7398 [2008] */
    .data_Yay0_19f5390_len_2002 0x19F5390 : AT(0x19F5390) {
        build/bin/Yay0_19f5390_len_2002.o(.data);
    }

    /* 0x00000000 19F7398-19FA128 [2D90] */
    .data_Yay0_19f7398_len_8024 0x19F7398 : AT(0x19F7398) {
        build/bin/Yay0_19f7398_len_8024.o(.data);
    }

    /* 0x00000000 19FA128-19FCAE8 [29C0] */
    .data_Yay0_19fa128_len_4ac6 0x19FA128 : AT(0x19FA128) {
        build/bin/Yay0_19fa128_len_4ac6.o(.data);
    }

    /* 0x00000000 19FCAE8-19FED70 [2288] */
    .data_Yay0_19fcae8_len_2502 0x19FCAE8 : AT(0x19FCAE8) {
        build/bin/Yay0_19fcae8_len_2502.o(.data);
    }

    /* 0x00000000 19FED70-1A00958 [1BE8] */
    .data_Yay0_19fed70_len_200004 0x19FED70 : AT(0x19FED70) {
        build/bin/Yay0_19fed70_len_200004.o(.data);
    }

    /* 0x00000000 1A00958-1A02D00 [23A8] */
    .data_Yay0_1a00958_len_24a2 0x1A00958 : AT(0x1A00958) {
        build/bin/Yay0_1a00958_len_24a2.o(.data);
    }

    /* 0x00000000 1A02D00-1A04400 [1700] */
    .data_Yay0_1a02d00_len_4000 0x1A02D00 : AT(0x1A02D00) {
        build/bin/Yay0_1a02d00_len_4000.o(.data);
    }

    /* 0x00000000 1A04400-1A05550 [1150] */
    .data_Yay0_1a04400_len_114c 0x1A04400 : AT(0x1A04400) {
        build/bin/Yay0_1a04400_len_114c.o(.data);
    }

    /* 0x00000000 1A05550-1A06390 [E40] */
    .data_Yay0_1a05550_len_2280 0x1A05550 : AT(0x1A05550) {
        build/bin/Yay0_1a05550_len_2280.o(.data);
    }

    /* 0x00000000 1A06390-1A06F98 [C08] */
    .data_Yay0_1a06390_len_c04 0x1A06390 : AT(0x1A06390) {
        build/bin/Yay0_1a06390_len_c04.o(.data);
    }

    /* 0x00000000 1A06F98-1A07B68 [BD0] */
    .data_Yay0_1a06f98_len_1066 0x1A06F98 : AT(0x1A06F98) {
        build/bin/Yay0_1a06f98_len_1066.o(.data);
    }

    /* 0x00000000 1A07B68-1A0A0A0 [2538] */
    .data_Yay0_1a07b68_len_8092 0x1A07B68 : AT(0x1A07B68) {
        build/bin/Yay0_1a07b68_len_8092.o(.data);
    }

    /* 0x00000000 1A0A0A0-1A0ACC8 [C28] */
    .data_Yay0_1a0a0a0_len_c46 0x1A0A0A0 : AT(0x1A0A0A0) {
        build/bin/Yay0_1a0a0a0_len_c46.o(.data);
    }

    /* 0x00000000 1A0ACC8-1A0B780 [AB8] */
    .data_Yay0_1a0acc8_len_1300 0x1A0ACC8 : AT(0x1A0ACC8) {
        build/bin/Yay0_1a0acc8_len_1300.o(.data);
    }

    /* 0x00000000 1A0B780-1A0BBE0 [460] */
    .data_Yay0_1a0b780_len_85c 0x1A0B780 : AT(0x1A0B780) {
        build/bin/Yay0_1a0b780_len_85c.o(.data);
    }

    /* 0x00000000 1A0BBE0-1A0C000 [420] */
    .data_Yay0_1a0bbe0_len_4000 0x1A0BBE0 : AT(0x1A0BBE0) {
        build/bin/Yay0_1a0bbe0_len_4000.o(.data);
    }

    /* 0x00000000 1A0C000-1A0C438 [438] */
    .data_Yay0_1a0c000_len_438 0x1A0C000 : AT(0x1A0C000) {
        build/bin/Yay0_1a0c000_len_438.o(.data);
    }

    /* 0x00000000 1A0C438-1A0C860 [428] */
    .data_Yay0_1a0c438_len_842 0x1A0C438 : AT(0x1A0C438) {
        build/bin/Yay0_1a0c438_len_842.o(.data);
    }

    /* 0x00000000 1A0C860-1A0D1E8 [988] */
    .data_Yay0_1a0c860_len_1186 0x1A0C860 : AT(0x1A0C860) {
        build/bin/Yay0_1a0c860_len_1186.o(.data);
    }

    /* 0x00000000 1A0D1E8-1A0D5B0 [3C8] */
    .data_Yay0_1a0d1e8_len_406 0x1A0D1E8 : AT(0x1A0D1E8) {
        build/bin/Yay0_1a0d1e8_len_406.o(.data);
    }

    /* 0x00000000 1A0D5B0-1A0D970 [3C0] */
    .data_Yay0_1a0d5b0_len_840 0x1A0D5B0 : AT(0x1A0D5B0) {
        build/bin/Yay0_1a0d5b0_len_840.o(.data);
    }

    /* 0x00000000 1A0D970-1A0EF00 [1590] */
    .data_Yay0_1a0d970_len_268e 0x1A0D970 : AT(0x1A0D970) {
        build/bin/Yay0_1a0d970_len_268e.o(.data);
    }

    /* 0x00000000 1A0EF00-1A13920 [4A20] */
    .data_Yay0_1a0ef00_len_11020 0x1A0EF00 : AT(0x1A0EF00) {
        build/bin/Yay0_1a0ef00_len_11020.o(.data);
    }

    /* 0x00000000 1A13920-1A15850 [1F30] */
    .data_Yay0_1a13920_len_404c 0x1A13920 : AT(0x1A13920) {
        build/bin/Yay0_1a13920_len_404c.o(.data);
    }

    /* 0x00000000 1A15850-1A183F8 [2BA8] */
    .data_Yay0_1a15850_len_83a4 0x1A15850 : AT(0x1A15850) {
        build/bin/Yay0_1a15850_len_83a4.o(.data);
    }

    /* 0x00000000 1A183F8-1A1A608 [2210] */
    .data_Yay0_1a183f8_len_2404 0x1A183F8 : AT(0x1A183F8) {
        build/bin/Yay0_1a183f8_len_2404.o(.data);
    }

    /* 0x00000000 1A1A608-1A1C5E8 [1FE0] */
    .data_Yay0_1a1a608_len_41e2 0x1A1A608 : AT(0x1A1A608) {
        build/bin/Yay0_1a1a608_len_41e2.o(.data);
    }

    /* 0x00000000 1A1C5E8-1A1D6D0 [10E8] */
    .data_Yay0_1a1c5e8_len_1202 0x1A1C5E8 : AT(0x1A1C5E8) {
        build/bin/Yay0_1a1c5e8_len_1202.o(.data);
    }

    /* 0x00000000 1A1D6D0-1A1E478 [DA8] */
    .data_Yay0_1a1d6d0_len_2028 0x1A1D6D0 : AT(0x1A1D6D0) {
        build/bin/Yay0_1a1d6d0_len_2028.o(.data);
    }

    /* 0x00000000 1A1E478-1A1F370 [EF8] */
    .data_Yay0_1a1e478_len_1306 0x1A1E478 : AT(0x1A1E478) {
        build/bin/Yay0_1a1e478_len_1306.o(.data);
    }

    /* 0x00000000 1A1F370-1A226B0 [3340] */
    .data_Yay0_1a1f370_len_2048c 0x1A1F370 : AT(0x1A1F370) {
        build/bin/Yay0_1a1f370_len_2048c.o(.data);
    }

    /* 0x00000000 1A226B0-1A249B8 [2308] */
    .data_Yay0_1a226b0_len_4908 0x1A226B0 : AT(0x1A226B0) {
        build/bin/Yay0_1a226b0_len_4908.o(.data);
    }

    /* 0x00000000 1A249B8-1A25E78 [14C0] */
    .data_Yay0_1a249b8_len_1644 0x1A249B8 : AT(0x1A249B8) {
        build/bin/Yay0_1a249b8_len_1644.o(.data);
    }

    /* 0x00000000 1A25E78-1A27FF0 [2178] */
    .data_Yay0_1a25e78_len_2186 0x1A25E78 : AT(0x1A25E78) {
        build/bin/Yay0_1a25e78_len_2186.o(.data);
    }

    /* 0x00000000 1A27FF0-1A28BE0 [BF0] */
    .data_Yay0_1a27ff0_len_800a 0x1A27FF0 : AT(0x1A27FF0) {
        build/bin/Yay0_1a27ff0_len_800a.o(.data);
    }

    /* 0x00000000 1A28BE0-1A29680 [AA0] */
    .data_Yay0_1a28be0_len_1400 0x1A28BE0 : AT(0x1A28BE0) {
        build/bin/Yay0_1a28be0_len_1400.o(.data);
    }

    /* 0x00000000 1A29680-1A2BC68 [25E8] */
    .data_Yay0_1a29680_len_2862 0x1A29680 : AT(0x1A29680) {
        build/bin/Yay0_1a29680_len_2862.o(.data);
    }

    /* 0x00000000 1A2BC68-1A2E120 [24B8] */
    .data_Yay0_1a2bc68_len_4112 0x1A2BC68 : AT(0x1A2BC68) {
        build/bin/Yay0_1a2bc68_len_4112.o(.data);
    }

    /* 0x00000000 1A2E120-1A2F3F8 [12D8] */
    .data_Yay0_1a2e120_len_12d8 0x1A2E120 : AT(0x1A2E120) {
        build/bin/Yay0_1a2e120_len_12d8.o(.data);
    }

    /* 0x00000000 1A2F3F8-1A31D18 [2920] */
    .data_Yay0_1a2f3f8_len_10c06 0x1A2F3F8 : AT(0x1A2F3F8) {
        build/bin/Yay0_1a2f3f8_len_10c06.o(.data);
    }

    /* 0x00000000 1A31D18-1A33AB0 [1D98] */
    .data_Yay0_1a31d18_len_22a6 0x1A31D18 : AT(0x1A31D18) {
        build/bin/Yay0_1a31d18_len_22a6.o(.data);
    }

    /* 0x00000000 1A33AB0-1A35BB8 [2108] */
    .data_Yay0_1a33ab0_len_4106 0x1A33AB0 : AT(0x1A33AB0) {
        build/bin/Yay0_1a33ab0_len_4106.o(.data);
    }

    /* 0x00000000 1A35BB8-1A369A8 [DF0] */
    .data_Yay0_1a35bb8_len_2006 0x1A35BB8 : AT(0x1A35BB8) {
        build/bin/Yay0_1a35bb8_len_2006.o(.data);
    }

    /* 0x00000000 1A369A8-1A39600 [2C58] */
    .data_Yay0_1a369a8_len_9600 0x1A369A8 : AT(0x1A369A8) {
        build/bin/Yay0_1a369a8_len_9600.o(.data);
    }

    /* 0x00000000 1A39600-1A3B018 [1A18] */
    .data_Yay0_1a39600_len_2014 0x1A39600 : AT(0x1A39600) {
        build/bin/Yay0_1a39600_len_2014.o(.data);
    }

    /* 0x00000000 1A3B018-1A3C310 [12F8] */
    .data_Yay0_1a3b018_len_4300 0x1A3B018 : AT(0x1A3B018) {
        build/bin/Yay0_1a3b018_len_4300.o(.data);
    }

    /* 0x00000000 1A3C310-1A3FCC8 [39B8] */
    .data_Yay0_1a3c310_len_3cc2 0x1A3C310 : AT(0x1A3C310) {
        build/bin/Yay0_1a3c310_len_3cc2.o(.data);
    }

    /* 0x00000000 1A3FCC8-1A423D8 [2710] */
    .data_Yay0_1a3fcc8_len_40314 0x1A3FCC8 : AT(0x1A3FCC8) {
        build/bin/Yay0_1a3fcc8_len_40314.o(.data);
    }

    /* 0x00000000 1A423D8-1A449C0 [25E8] */
    .data_Yay0_1a423d8_len_4822 0x1A423D8 : AT(0x1A423D8) {
        build/bin/Yay0_1a423d8_len_4822.o(.data);
    }

    /* 0x00000000 1A449C0-1A46568 [1BA8] */
    .data_Yay0_1a449c0_len_2422 0x1A449C0 : AT(0x1A449C0) {
        build/bin/Yay0_1a449c0_len_2422.o(.data);
    }

    /* 0x00000000 1A46568-1A49340 [2DD8] */
    .data_Yay0_1a46568_len_9212 0x1A46568 : AT(0x1A46568) {
        build/bin/Yay0_1a46568_len_9212.o(.data);
    }

    /* 0x00000000 1A49340-1A4AC88 [1948] */
    .data_Yay0_1a49340_len_2c88 0x1A49340 : AT(0x1A49340) {
        build/bin/Yay0_1a49340_len_2c88.o(.data);
    }

    /* 0x00000000 1A4AC88-1A4D7E8 [2B60] */
    .data_Yay0_1a4ac88_len_5362 0x1A4AC88 : AT(0x1A4AC88) {
        build/bin/Yay0_1a4ac88_len_5362.o(.data);
    }

    /* 0x00000000 1A4D7E8-1A4E028 [840] */
    .data_Yay0_1a4d7e8_len_2006 0x1A4D7E8 : AT(0x1A4D7E8) {
        build/bin/Yay0_1a4d7e8_len_2006.o(.data);
    }

    /* 0x00000000 1A4E028-1A4FA60 [1A38] */
    .data_Yay0_1a4e028_len_1a56 0x1A4E028 : AT(0x1A4E028) {
        build/bin/Yay0_1a4e028_len_1a56.o(.data);
    }

    /* 0x00000000 1A4FA60-1A531D0 [3770] */
    .data_Yay0_1a4fa60_len_10190 0x1A4FA60 : AT(0x1A4FA60) {
        build/bin/Yay0_1a4fa60_len_10190.o(.data);
    }

    /* 0x00000000 1A531D0-1A53D48 [B78] */
    .data_Yay0_1a531d0_len_c08 0x1A531D0 : AT(0x1A531D0) {
        build/bin/Yay0_1a531d0_len_c08.o(.data);
    }

    /* 0x00000000 1A53D48-1A56C80 [2F38] */
    .data_Yay0_1a53d48_len_4032 0x1A53D48 : AT(0x1A53D48) {
        build/bin/Yay0_1a53d48_len_4032.o(.data);
    }

    /* 0x00000000 1A56C80-1A58F58 [22D8] */
    .data_Yay0_1a56c80_len_8358 0x1A56C80 : AT(0x1A56C80) {
        build/bin/Yay0_1a56c80_len_8358.o(.data);
    }

    /* 0x00000000 1A58F58-1A5A5A8 [1650] */
    .data_Yay0_1a58f58_len_20a4 0x1A58F58 : AT(0x1A58F58) {
        build/bin/Yay0_1a58f58_len_20a4.o(.data);
    }

    /* 0x00000000 1A5A5A8-1A62B40 [8598] */
    .data_Yay0_1a5a5a8_len_20a14 0x1A5A5A8 : AT(0x1A5A5A8) {
        build/bin/Yay0_1a5a5a8_len_20a14.o(.data);
    }

    /* 0x00000000 1A62B40-1A641F8 [16B8] */
    .data_Yay0_1a62b40_len_40b6 0x1A62B40 : AT(0x1A62B40) {
        build/bin/Yay0_1a62b40_len_40b6.o(.data);
    }

    /* 0x00000000 1A641F8-1A666F0 [24F8] */
    .data_Yay0_1a641f8_len_2602 0x1A641F8 : AT(0x1A641F8) {
        build/bin/Yay0_1a641f8_len_2602.o(.data);
    }

    /* 0x00000000 1A666F0-1A68870 [2180] */
    .data_Yay0_1a666f0_len_8800 0x1A666F0 : AT(0x1A666F0) {
        build/bin/Yay0_1a666f0_len_8800.o(.data);
    }

    /* 0x00000000 1A68870-1A6C630 [3DC0] */
    .data_Yay0_1a68870_len_460a 0x1A68870 : AT(0x1A68870) {
        build/bin/Yay0_1a68870_len_460a.o(.data);
    }

    /* 0x00000000 1A6C630-1A6D5A0 [F70] */
    .data_Yay0_1a6c630_len_118c 0x1A6C630 : AT(0x1A6C630) {
        build/bin/Yay0_1a6c630_len_118c.o(.data);
    }

    /* 0x00000000 1A6D5A0-1A6EF50 [19B0] */
    .data_Yay0_1a6d5a0_len_2a4c 0x1A6D5A0 : AT(0x1A6D5A0) {
        build/bin/Yay0_1a6d5a0_len_2a4c.o(.data);
    }

    /* 0x00000000 1A6EF50-1A70FF0 [20A0] */
    .data_Yay0_1a6ef50_len_100ae 0x1A6EF50 : AT(0x1A6EF50) {
        build/bin/Yay0_1a6ef50_len_100ae.o(.data);
    }

    /* 0x00000000 1A70FF0-1A74FC0 [3FD0] */
    .data_Yay0_1a70ff0_len_4000 0x1A70FF0 : AT(0x1A70FF0) {
        build/bin/Yay0_1a70ff0_len_4000.o(.data);
    }

    /* 0x00000000 1A74FC0-1A78A40 [3A80] */
    .data_Yay0_1a74fc0_len_803a 0x1A74FC0 : AT(0x1A74FC0) {
        build/bin/Yay0_1a74fc0_len_803a.o(.data);
    }

    /* 0x00000000 1A78A40-1A79900 [EC0] */
    .data_Yay0_1a78a40_len_1100 0x1A78A40 : AT(0x1A78A40) {
        build/bin/Yay0_1a78a40_len_1100.o(.data);
    }

    /* 0x00000000 1A79900-1A7D798 [3E98] */
    .data_Yay0_1a79900_len_4698 0x1A79900 : AT(0x1A79900) {
        build/bin/Yay0_1a79900_len_4698.o(.data);
    }

    /* 0x00000000 1A7D798-1A7EEA0 [1708] */
    .data_Yay0_1a7d798_len_2804 0x1A7D798 : AT(0x1A7D798) {
        build/bin/Yay0_1a7d798_len_2804.o(.data);
    }

    /* 0x00000000 1A7EEA0-1A7EFD8 [138] */
    .data_Yay0_1a7eea0_len_158 0x1A7EEA0 : AT(0x1A7EEA0) {
        build/bin/Yay0_1a7eea0_len_158.o(.data);
    }

    /* 0x00000000 1A7EFD8-1A83450 [4478] */
    .data_Yay0_1a7efd8_len_81002 0x1A7EFD8 : AT(0x1A7EFD8) {
        build/bin/Yay0_1a7efd8_len_81002.o(.data);
    }

    /* 0x00000000 1A83450-1A85668 [2218] */
    .data_Yay0_1a83450_len_4226 0x1A83450 : AT(0x1A83450) {
        build/bin/Yay0_1a83450_len_4226.o(.data);
    }

    /* 0x00000000 1A85668-1A87958 [22F0] */
    .data_Yay0_1a85668_len_2910 0x1A85668 : AT(0x1A85668) {
        build/bin/Yay0_1a85668_len_2910.o(.data);
    }

    /* 0x00000000 1A87958-1A8BF98 [4640] */
    .data_Yay0_1a87958_len_8680 0x1A87958 : AT(0x1A87958) {
        build/bin/Yay0_1a87958_len_8680.o(.data);
    }

    /* 0x00000000 1A8BF98-1A8FE28 [3E90] */
    .data_Yay0_1a8bf98_len_4020 0x1A8BF98 : AT(0x1A8BF98) {
        build/bin/Yay0_1a8bf98_len_4020.o(.data);
    }

    /* 0x00000000 1A8FE28-1A93EA0 [4078] */
    .data_Yay0_1a8fe28_len_10096 0x1A8FE28 : AT(0x1A8FE28) {
        build/bin/Yay0_1a8fe28_len_10096.o(.data);
    }

    /* 0x00000000 1A93EA0-1A94188 [2E8] */
    .data_Yay0_1a93ea0_len_4102 0x1A93EA0 : AT(0x1A93EA0) {
        build/bin/Yay0_1a93ea0_len_4102.o(.data);
    }

    /* 0x00000000 1A94188-1A94480 [2F8] */
    .data_Yay0_1a94188_len_476 0x1A94188 : AT(0x1A94188) {
        build/bin/Yay0_1a94188_len_476.o(.data);
    }

    /* 0x00000000 1A94480-1A946A8 [228] */
    .data_Yay0_1a94480_len_226 0x1A94480 : AT(0x1A94480) {
        build/bin/Yay0_1a94480_len_226.o(.data);
    }

    /* 0x00000000 1A946A8-1A94A00 [358] */
    .data_Yay0_1a946a8_len_956 0x1A946A8 : AT(0x1A946A8) {
        build/bin/Yay0_1a946a8_len_956.o(.data);
    }

    /* 0x00000000 1A94A00-1A94C58 [258] */
    .data_Yay0_1a94a00_len_456 0x1A94A00 : AT(0x1A94A00) {
        build/bin/Yay0_1a94a00_len_456.o(.data);
    }

    /* 0x00000000 1A94C58-1A98D98 [4140] */
    .data_Yay0_1a94c58_len_8184 0x1A94C58 : AT(0x1A94C58) {
        build/bin/Yay0_1a94c58_len_8184.o(.data);
    }

    /* 0x00000000 1A98D98-1A9BA80 [2CE8] */
    .data_Yay0_1a98d98_len_3264 0x1A98D98 : AT(0x1A98D98) {
        build/bin/Yay0_1a98d98_len_3264.o(.data);
    }

    /* 0x00000000 1A9BA80-1A9DB68 [20E8] */
    .data_Yay0_1a9ba80_len_4168 0x1A9BA80 : AT(0x1A9BA80) {
        build/bin/Yay0_1a9ba80_len_4168.o(.data);
    }

    /* 0x00000000 1A9DB68-1AA0048 [24E0] */
    .data_Yay0_1a9db68_len_20004 0x1A9DB68 : AT(0x1A9DB68) {
        build/bin/Yay0_1a9db68_len_20004.o(.data);
    }

    /* 0x00000000 1AA0048-1AA0698 [650] */
    .data_Yay0_1aa0048_len_692 0x1AA0048 : AT(0x1AA0048) {
        build/bin/Yay0_1aa0048_len_692.o(.data);
    }

    /* 0x00000000 1AA0698-1AA1008 [970] */
    .data_Yay0_1aa0698_len_1000 0x1AA0698 : AT(0x1AA0698) {
        build/bin/Yay0_1aa0698_len_1000.o(.data);
    }

    /* 0x00000000 1AA1008-1AA6D58 [5D50] */
    .data_Yay0_1aa1008_len_6d54 0x1AA1008 : AT(0x1AA1008) {
        build/bin/Yay0_1aa1008_len_6d54.o(.data);
    }

    /* 0x00000000 1AA6D58-1AAD600 [68A8] */
    .data_Yay0_1aa6d58_len_90a4 0x1AA6D58 : AT(0x1AA6D58) {
        build/bin/Yay0_1aa6d58_len_90a4.o(.data);
    }

    /* 0x00000000 1AAD600-1AB1BF0 [45F0] */
    .data_Yay0_1aad600_len_109f0 0x1AAD600 : AT(0x1AAD600) {
        build/bin/Yay0_1aad600_len_109f0.o(.data);
    }

    /* 0x00000000 1AB1BF0-1AB2368 [778] */
    .data_Yay0_1ab1bf0_len_2004 0x1AB1BF0 : AT(0x1AB1BF0) {
        build/bin/Yay0_1ab1bf0_len_2004.o(.data);
    }

    /* 0x00000000 1AB2368-1ABA290 [7F28] */
    .data_Yay0_1ab2368_len_8086 0x1AB2368 : AT(0x1AB2368) {
        build/bin/Yay0_1ab2368_len_8086.o(.data);
    }

    /* 0x00000000 1ABA290-1AC14A8 [7218] */
    .data_Yay0_1aba290_len_41422 0x1ABA290 : AT(0x1ABA290) {
        build/bin/Yay0_1aba290_len_41422.o(.data);
    }

    /* 0x00000000 1AC14A8-1AC3910 [2468] */
    .data_Yay0_1ac14a8_len_2902 0x1AC14A8 : AT(0x1AC14A8) {
        build/bin/Yay0_1ac14a8_len_2902.o(.data);
    }

    /* 0x00000000 1AC3910-1ACBC98 [8388] */
    .data_Yay0_1ac3910_len_8488 0x1AC3910 : AT(0x1AC3910) {
        build/bin/Yay0_1ac3910_len_8488.o(.data);
    }

    /* 0x00000000 1ACBC98-1ACE058 [23C0] */
    .data_Yay0_1acbc98_len_4042 0x1ACBC98 : AT(0x1ACBC98) {
        build/bin/Yay0_1acbc98_len_4042.o(.data);
    }

    /* 0x00000000 1ACE058-1ACF910 [18B8] */
    .data_Yay0_1ace058_len_1902 0x1ACE058 : AT(0x1ACE058) {
        build/bin/Yay0_1ace058_len_1902.o(.data);
    }

    /* 0x00000000 1ACF910-1AD06D8 [DC8] */
    .data_Yay0_1acf910_len_106c8 0x1ACF910 : AT(0x1ACF910) {
        build/bin/Yay0_1acf910_len_106c8.o(.data);
    }

    /* 0x00000000 1AD06D8-1AD0B98 [4C0] */
    .data_Yay0_1ad06d8_len_904 0x1AD06D8 : AT(0x1AD06D8) {
        build/bin/Yay0_1ad06d8_len_904.o(.data);
    }

    /* 0x00000000 1AD0B98-1AD1E90 [12F8] */
    .data_Yay0_1ad0b98_len_1400 0x1AD0B98 : AT(0x1AD0B98) {
        build/bin/Yay0_1ad0b98_len_1400.o(.data);
    }

    /* 0x00000000 1AD1E90-1AD2348 [4B8] */
    .data_Yay0_1ad1e90_len_2146 0x1AD1E90 : AT(0x1AD1E90) {
        build/bin/Yay0_1ad1e90_len_2146.o(.data);
    }

    /* 0x00000000 1AD2348-1AD27F8 [4B0] */
    .data_Yay0_1ad2348_len_4b2 0x1AD2348 : AT(0x1AD2348) {
        build/bin/Yay0_1ad2348_len_4b2.o(.data);
    }

    /* 0x00000000 1AD27F8-1AD28A8 [B0] */
    .data_Yay0_1ad27f8_len_800 0x1AD27F8 : AT(0x1AD27F8) {
        build/bin/Yay0_1ad27f8_len_800.o(.data);
    }

    /* 0x00000000 1AD28A8-1AD44F0 [1C48] */
    .data_Yay0_1ad28a8_len_4446 0x1AD28A8 : AT(0x1AD28A8) {
        build/bin/Yay0_1ad28a8_len_4446.o(.data);
    }

    /* 0x00000000 1AD44F0-1AD4758 [268] */
    .data_Yay0_1ad44f0_len_304 0x1AD44F0 : AT(0x1AD44F0) {
        build/bin/Yay0_1ad44f0_len_304.o(.data);
    }

    /* 0x00000000 1AD4758-1AD57C0 [1068] */
    .data_Yay0_1ad4758_len_1080 0x1AD4758 : AT(0x1AD4758) {
        build/bin/Yay0_1ad4758_len_1080.o(.data);
    }

    /* 0x00000000 1AD57C0-1AD9D50 [4590] */
    .data_Yay0_1ad57c0_len_880c 0x1AD57C0 : AT(0x1AD57C0) {
        build/bin/Yay0_1ad57c0_len_880c.o(.data);
    }

    /* 0x00000000 1AD9D50-1ADA498 [748] */
    .data_Yay0_1ad9d50_len_2082 0x1AD9D50 : AT(0x1AD9D50) {
        build/bin/Yay0_1ad9d50_len_2082.o(.data);
    }

    /* 0x00000000 1ADA498-1ADCFC0 [2B28] */
    .data_Yay0_1ada498_len_4b26 0x1ADA498 : AT(0x1ADA498) {
        build/bin/Yay0_1ada498_len_4b26.o(.data);
    }

    /* 0x00000000 1ADCFC0-1AE2168 [51A8] */
    .data_Yay0_1adcfc0_len_22024 0x1ADCFC0 : AT(0x1ADCFC0) {
        build/bin/Yay0_1adcfc0_len_22024.o(.data);
    }

    /* 0x00000000 1AE2168-1AE2EA0 [D38] */
    .data_Yay0_1ae2168_len_e96 0x1AE2168 : AT(0x1AE2168) {
        build/bin/Yay0_1ae2168_len_e96.o(.data);
    }

    /* 0x00000000 1AE2EA0-1AE6A58 [3BB8] */
    .data_Yay0_1ae2ea0_len_4058 0x1AE2EA0 : AT(0x1AE2EA0) {
        build/bin/Yay0_1ae2ea0_len_4058.o(.data);
    }

    /* 0x00000000 1AE6A58-1AEB778 [4D20] */
    .data_Yay0_1ae6a58_len_9524 0x1AE6A58 : AT(0x1AE6A58) {
        build/bin/Yay0_1ae6a58_len_9524.o(.data);
    }

    /* 0x00000000 1AEB778-1AF4958 [91E0] */
    .data_Yay0_1aeb778_len_14802 0x1AEB778 : AT(0x1AEB778) {
        build/bin/Yay0_1aeb778_len_14802.o(.data);
    }

    /* 0x00000000 1AF4958-1AFCB18 [81C0] */
    .data_Yay0_1af4958_len_8202 0x1AF4958 : AT(0x1AF4958) {
        build/bin/Yay0_1af4958_len_8202.o(.data);
    }

    /* 0x00000000 1AFCB18-1AFF748 [2C30] */
    .data_Yay0_1afcb18_len_3442 0x1AFCB18 : AT(0x1AFCB18) {
        build/bin/Yay0_1afcb18_len_3442.o(.data);
    }

    /* 0x00000000 1AFF748-1B00640 [EF8] */
    .data_Yay0_1aff748_len_100000 0x1AFF748 : AT(0x1AFF748) {
        build/bin/Yay0_1aff748_len_100000.o(.data);
    }

    /* 0x00000000 1B00640-1B01390 [D50] */
    .data_Yay0_1b00640_len_118a 0x1B00640 : AT(0x1B00640) {
        build/bin/Yay0_1b00640_len_118a.o(.data);
    }

    /* 0x00000000 1B01390-1B01C08 [878] */
    .data_Yay0_1b01390_len_c04 0x1B01390 : AT(0x1B01390) {
        build/bin/Yay0_1b01390_len_c04.o(.data);
    }

    /* 0x00000000 1B01C08-1B02128 [520] */
    .data_Yay0_1b01c08_len_2120 0x1B01C08 : AT(0x1B01C08) {
        build/bin/Yay0_1b01c08_len_2120.o(.data);
    }

    /* 0x00000000 1B02128-1B02970 [848] */
    .data_Yay0_1b02128_len_844 0x1B02128 : AT(0x1B02128) {
        build/bin/Yay0_1b02128_len_844.o(.data);
    }

    /* 0x00000000 1B02970-1B03118 [7A8] */
    .data_Yay0_1b02970_len_1004 0x1B02970 : AT(0x1B02970) {
        build/bin/Yay0_1b02970_len_1004.o(.data);
    }

    /* 0x00000000 1B03118-1B03C18 [B00] */
    .data_Yay0_1b03118_len_c04 0x1B03118 : AT(0x1B03118) {
        build/bin/Yay0_1b03118_len_c04.o(.data);
    }

    /* 0x00000000 1B03C18-1B045E8 [9D0] */
    .data_Yay0_1b03c18_len_41e2 0x1B03C18 : AT(0x1B03C18) {
        build/bin/Yay0_1b03c18_len_41e2.o(.data);
    }

    /* 0x00000000 1B045E8-1B04FC0 [9D8] */
    .data_Yay0_1b045e8_len_a12 0x1B045E8 : AT(0x1B045E8) {
        build/bin/Yay0_1b045e8_len_a12.o(.data);
    }

    /* 0x00000000 1B04FC0-1B05998 [9D8] */
    .data_Yay0_1b04fc0_len_1012 0x1B04FC0 : AT(0x1B04FC0) {
        build/bin/Yay0_1b04fc0_len_1012.o(.data);
    }

    /* 0x00000000 1B05998-1B06C88 [12F0] */
    .data_Yay0_1b05998_len_2400 0x1B05998 : AT(0x1B05998) {
        build/bin/Yay0_1b05998_len_2400.o(.data);
    }

    /* 0x00000000 1B06C88-1B07C48 [FC0] */
    .data_Yay0_1b06c88_len_1046 0x1B06C88 : AT(0x1B06C88) {
        build/bin/Yay0_1b06c88_len_1046.o(.data);
    }

    /* 0x00000000 1B07C48-1B09440 [17F8] */
    .data_Yay0_1b07c48_len_8034 0x1B07C48 : AT(0x1B07C48) {
        build/bin/Yay0_1b07c48_len_8034.o(.data);
    }

    /* 0x00000000 1B09440-1B0B290 [1E50] */
    .data_Yay0_1b09440_len_228e 0x1B09440 : AT(0x1B09440) {
        build/bin/Yay0_1b09440_len_228e.o(.data);
    }

    /* 0x00000000 1B0B290-1B0B9A0 [710] */
    .data_Yay0_1b0b290_len_90c 0x1B0B290 : AT(0x1B0B290) {
        build/bin/Yay0_1b0b290_len_90c.o(.data);
    }

    /* 0x00000000 1B0B9A0-1B0C548 [BA8] */
    .data_Yay0_1b0b9a0_len_4448 0x1B0B9A0 : AT(0x1B0B9A0) {
        build/bin/Yay0_1b0b9a0_len_4448.o(.data);
    }

    /* 0x00000000 1B0C548-1B0CAC0 [578] */
    .data_Yay0_1b0c548_len_ab4 0x1B0C548 : AT(0x1B0C548) {
        build/bin/Yay0_1b0c548_len_ab4.o(.data);
    }

    /* 0x00000000 1B0CAC0-1B0D130 [670] */
    .data_Yay0_1b0cac0_len_1130 0x1B0CAC0 : AT(0x1B0CAC0) {
        build/bin/Yay0_1b0cac0_len_1130.o(.data);
    }

    /* 0x00000000 1B0D130-1B0EB80 [1A50] */
    .data_Yay0_1b0d130_len_2a4c 0x1B0D130 : AT(0x1B0D130) {
        build/bin/Yay0_1b0d130_len_2a4c.o(.data);
    }

    /* 0x00000000 1B0EB80-1B10CC0 [2140] */
    .data_Yay0_1b0eb80_len_1043e 0x1B0EB80 : AT(0x1B0EB80) {
        build/bin/Yay0_1b0eb80_len_1043e.o(.data);
    }

    /* 0x00000000 1B10CC0-1B129A0 [1CE0] */
    .data_Yay0_1b10cc0_len_2120 0x1B10CC0 : AT(0x1B10CC0) {
        build/bin/Yay0_1b10cc0_len_2120.o(.data);
    }

    /* 0x00000000 1B129A0-1B13548 [BA8] */
    .data_Yay0_1b129a0_len_1444 0x1B129A0 : AT(0x1B129A0) {
        build/bin/Yay0_1b129a0_len_1444.o(.data);
    }

    /* 0x00000000 1B13548-1B16420 [2ED8] */
    .data_Yay0_1b13548_len_4016 0x1B13548 : AT(0x1B13548) {
        build/bin/Yay0_1b13548_len_4016.o(.data);
    }

    /* 0x00000000 1B16420-1B17128 [D08] */
    .data_Yay0_1b16420_len_1104 0x1B16420 : AT(0x1B16420) {
        build/bin/Yay0_1b16420_len_1104.o(.data);
    }

    /* 0x00000000 1B17128-1B17840 [718] */
    .data_Yay0_1b17128_len_814 0x1B17128 : AT(0x1B17128) {
        build/bin/Yay0_1b17128_len_814.o(.data);
    }

    /* 0x00000000 1B17840-1B19318 [1AD8] */
    .data_Yay0_1b17840_len_8316 0x1B17840 : AT(0x1B17840) {
        build/bin/Yay0_1b17840_len_8316.o(.data);
    }

    /* 0x00000000 1B19318-1B1A030 [D18] */
    .data_Yay0_1b19318_len_2020 0x1B19318 : AT(0x1B19318) {
        build/bin/Yay0_1b19318_len_2020.o(.data);
    }

    /* 0x00000000 1B1A030-1B1B8C8 [1898] */
    .data_Yay0_1b1a030_len_18c6 0x1B1A030 : AT(0x1B1A030) {
        build/bin/Yay0_1b1a030_len_18c6.o(.data);
    }

    /* 0x00000000 1B1B8C8-1B1BC88 [3C0] */
    .data_Yay0_1b1b8c8_len_402 0x1B1B8C8 : AT(0x1B1B8C8) {
        build/bin/Yay0_1b1b8c8_len_402.o(.data);
    }

    /* 0x00000000 1B1BC88-1B1C7A0 [B18] */
    .data_Yay0_1b1bc88_len_4316 0x1B1BC88 : AT(0x1B1BC88) {
        build/bin/Yay0_1b1bc88_len_4316.o(.data);
    }

    /* 0x00000000 1B1C7A0-1B1CD28 [588] */
    .data_Yay0_1b1c7a0_len_808 0x1B1C7A0 : AT(0x1B1C7A0) {
        build/bin/Yay0_1b1c7a0_len_808.o(.data);
    }

    /* 0x00000000 1B1CD28-1B21C48 [4F20] */
    .data_Yay0_1b1cd28_len_21040 0x1B1CD28 : AT(0x1B1CD28) {
        build/bin/Yay0_1b1cd28_len_21040.o(.data);
    }

    /* 0x00000000 1B21C48-1B23290 [1648] */
    .data_Yay0_1b21c48_len_2290 0x1B21C48 : AT(0x1B21C48) {
        build/bin/Yay0_1b21c48_len_2290.o(.data);
    }

    /* 0x00000000 1B23290-1B253E0 [2150] */
    .data_Yay0_1b23290_len_414c 0x1B23290 : AT(0x1B23290) {
        build/bin/Yay0_1b23290_len_414c.o(.data);
    }

    /* 0x00000000 1B253E0-1B26660 [1280] */
    .data_Yay0_1b253e0_len_241c 0x1B253E0 : AT(0x1B253E0) {
        build/bin/Yay0_1b253e0_len_241c.o(.data);
    }

    /* 0x00000000 1B26660-1B283F8 [1D98] */
    .data_Yay0_1b26660_len_8192 0x1B26660 : AT(0x1B26660) {
        build/bin/Yay0_1b26660_len_8192.o(.data);
    }

    /* 0x00000000 1B283F8-1B29C60 [1868] */
    .data_Yay0_1b283f8_len_1c02 0x1B283F8 : AT(0x1B283F8) {
        build/bin/Yay0_1b283f8_len_1c02.o(.data);
    }

    /* 0x00000000 1B29C60-1B2A688 [A28] */
    .data_Yay0_1b29c60_len_2284 0x1B29C60 : AT(0x1B29C60) {
        build/bin/Yay0_1b29c60_len_2284.o(.data);
    }

    /* 0x00000000 1B2A688-1B2B3E8 [D60] */
    .data_Yay0_1b2a688_len_1166 0x1B2A688 : AT(0x1B2A688) {
        build/bin/Yay0_1b2a688_len_1166.o(.data);
    }

    /* 0x00000000 1B2B3E8-1B2C8D8 [14F0] */
    .data_Yay0_1b2b3e8_len_4810 0x1B2B3E8 : AT(0x1B2B3E8) {
        build/bin/Yay0_1b2b3e8_len_4810.o(.data);
    }

    /* 0x00000000 1B2C8D8-1B2D7B0 [ED8] */
    .data_Yay0_1b2c8d8_len_1722 0x1B2C8D8 : AT(0x1B2C8D8) {
        build/bin/Yay0_1b2c8d8_len_1722.o(.data);
    }

    /* 0x00000000 1B2D7B0-1B2E328 [B78] */
    .data_Yay0_1b2d7b0_len_2006 0x1B2D7B0 : AT(0x1B2D7B0) {
        build/bin/Yay0_1b2d7b0_len_2006.o(.data);
    }

    /* 0x00000000 1B2E328-1B2ED60 [A38] */
    .data_Yay0_1b2e328_len_c52 0x1B2E328 : AT(0x1B2E328) {
        build/bin/Yay0_1b2e328_len_c52.o(.data);
    }

    /* 0x00000000 1B2ED60-1B2FA18 [CB8] */
    .data_Yay0_1b2ed60_len_1218 0x1B2ED60 : AT(0x1B2ED60) {
        build/bin/Yay0_1b2ed60_len_1218.o(.data);
    }

    /* 0x00000000 1B2FA18-1B31A18 [2000] */
    .data_Yay0_1b2fa18_len_10002 0x1B2FA18 : AT(0x1B2FA18) {
        build/bin/Yay0_1b2fa18_len_10002.o(.data);
    }

    /* 0x00000000 1B31A18-1B33000 [15E8] */
    .data_Yay0_1b31a18_len_25e2 0x1B31A18 : AT(0x1B31A18) {
        build/bin/Yay0_1b31a18_len_25e2.o(.data);
    }

    /* 0x00000000 1B33000-1B34098 [1098] */
    .data_Yay0_1b33000_len_4096 0x1B33000 : AT(0x1B33000) {
        build/bin/Yay0_1b33000_len_4096.o(.data);
    }

    /* 0x00000000 1B34098-1B34928 [890] */
    .data_Yay0_1b34098_len_920 0x1B34098 : AT(0x1B34098) {
        build/bin/Yay0_1b34098_len_920.o(.data);
    }

    /* 0x00000000 1B34928-1B34C00 [2D8] */
    .data_Yay0_1b34928_len_2d4 0x1B34928 : AT(0x1B34928) {
        build/bin/Yay0_1b34928_len_2d4.o(.data);
    }

    /* 0x00000000 1B34C00-1B35480 [880] */
    .data_Yay0_1b34c00_len_107e 0x1B34C00 : AT(0x1B34C00) {
        build/bin/Yay0_1b34c00_len_107e.o(.data);
    }

    /* 0x00000000 1B35480-1B36440 [FC0] */
    .data_Yay0_1b35480_len_2040 0x1B35480 : AT(0x1B35480) {
        build/bin/Yay0_1b35480_len_2040.o(.data);
    }

    /* 0x00000000 1B36440-1B38748 [2308] */
    .data_Yay0_1b36440_len_8306 0x1B36440 : AT(0x1B36440) {
        build/bin/Yay0_1b36440_len_8306.o(.data);
    }

    /* 0x00000000 1B38748-1B39A98 [1350] */
    .data_Yay0_1b38748_len_1894 0x1B38748 : AT(0x1B38748) {
        build/bin/Yay0_1b38748_len_1894.o(.data);
    }

    /* 0x00000000 1B39A98-1B3A2E8 [850] */
    .data_Yay0_1b39a98_len_2062 0x1B39A98 : AT(0x1B39A98) {
        build/bin/Yay0_1b39a98_len_2062.o(.data);
    }

    /* 0x00000000 1B3A2E8-1B3A818 [530] */
    .data_Yay0_1b3a2e8_len_816 0x1B3A2E8 : AT(0x1B3A2E8) {
        build/bin/Yay0_1b3a2e8_len_816.o(.data);
    }

    /* 0x00000000 1B3A818-1B3C488 [1C70] */
    .data_Yay0_1b3a818_len_4482 0x1B3A818 : AT(0x1B3A818) {
        build/bin/Yay0_1b3a818_len_4482.o(.data);
    }

    /* 0x00000000 1B3C488-1B3CAC8 [640] */
    .data_Yay0_1b3c488_len_a44 0x1B3C488 : AT(0x1B3C488) {
        build/bin/Yay0_1b3c488_len_a44.o(.data);
    }

    /* 0x00000000 1B3CAC8-1B3D0A0 [5D8] */
    .data_Yay0_1b3cac8_len_1012 0x1B3CAC8 : AT(0x1B3CAC8) {
        build/bin/Yay0_1b3cac8_len_1012.o(.data);
    }

    /* 0x00000000 1B3D0A0-1B3D920 [880] */
    .data_Yay0_1b3d0a0_len_91a 0x1B3D0A0 : AT(0x1B3D0A0) {
        build/bin/Yay0_1b3d0a0_len_91a.o(.data);
    }

    /* 0x00000000 1B3D920-1B3F060 [1740] */
    .data_Yay0_1b3d920_len_205c 0x1B3D920 : AT(0x1B3D920) {
        build/bin/Yay0_1b3d920_len_205c.o(.data);
    }

    /* 0x00000000 1B3F060-1B40048 [FE8] */
    .data_Yay0_1b3f060_len_40008 0x1B3F060 : AT(0x1B3F060) {
        build/bin/Yay0_1b3f060_len_40008.o(.data);
    }

    /* 0x00000000 1B40048-1B40720 [6D8] */
    .data_Yay0_1b40048_len_714 0x1B40048 : AT(0x1B40048) {
        build/bin/Yay0_1b40048_len_714.o(.data);
    }

    /* 0x00000000 1B40720-1B49570 [8E50] */
    .data_Yay0_1b40720_len_904e 0x1B40720 : AT(0x1B40720) {
        build/bin/Yay0_1b40720_len_904e.o(.data);
    }

    /* 0x00000000 1B49570-1B4C3E8 [2E78] */
    .data_Yay0_1b49570_len_4288 0x1B49570 : AT(0x1B49570) {
        build/bin/Yay0_1b49570_len_4288.o(.data);
    }

    /* 0x00000000 1B4C3E8-1B4DEA0 [1AB8] */
    .data_Yay0_1b4c3e8_len_1c12 0x1B4C3E8 : AT(0x1B4C3E8) {
        build/bin/Yay0_1b4c3e8_len_1c12.o(.data);
    }

    /* 0x00000000 1B4DEA0-1B4FD98 [1EF8] */
    .data_Yay0_1b4dea0_len_2116 0x1B4DEA0 : AT(0x1B4DEA0) {
        build/bin/Yay0_1b4dea0_len_2116.o(.data);
    }

    /* 0x00000000 1B4FD98-1B50CD8 [F40] */
    .data_Yay0_1b4fd98_len_10040 0x1B4FD98 : AT(0x1B4FD98) {
        build/bin/Yay0_1b4fd98_len_10040.o(.data);
    }

    /* 0x00000000 1B50CD8-1B51B08 [E30] */
    .data_Yay0_1b50cd8_len_1302 0x1B50CD8 : AT(0x1B50CD8) {
        build/bin/Yay0_1b50cd8_len_1302.o(.data);
    }

    /* 0x00000000 1B51B08-1B54258 [2750] */
    .data_Yay0_1b51b08_len_4052 0x1B51B08 : AT(0x1B51B08) {
        build/bin/Yay0_1b51b08_len_4052.o(.data);
    }

    /* 0x00000000 1B54258-1B580A0 [3E48] */
    .data_Yay0_1b54258_len_8082 0x1B54258 : AT(0x1B54258) {
        build/bin/Yay0_1b54258_len_8082.o(.data);
    }

    /* 0x00000000 1B580A0-1B5A248 [21A8] */
    .data_Yay0_1b580a0_len_2242 0x1B580A0 : AT(0x1B580A0) {
        build/bin/Yay0_1b580a0_len_2242.o(.data);
    }

    /* 0x00000000 1B5A248-1B5BB88 [1940] */
    .data_Yay0_1b5a248_len_1980 0x1B5A248 : AT(0x1B5A248) {
        build/bin/Yay0_1b5a248_len_1980.o(.data);
    }

    /* 0x00000000 1B5BB88-1B5CC90 [1108] */
    .data_Yay0_1b5bb88_len_4406 0x1B5BB88 : AT(0x1B5BB88) {
        build/bin/Yay0_1b5bb88_len_4406.o(.data);
    }

    /* 0x00000000 1B5CC90-1B5E968 [1CD8] */
    .data_Yay0_1b5cc90_len_2168 0x1B5CC90 : AT(0x1B5CC90) {
        build/bin/Yay0_1b5cc90_len_2168.o(.data);
    }

    /* 0x00000000 1B5E968-1B5ED88 [420] */
    .data_Yay0_1b5e968_len_482 0x1B5E968 : AT(0x1B5E968) {
        build/bin/Yay0_1b5e968_len_482.o(.data);
    }

    /* 0x00000000 1B5ED88-1B608C0 [1B38] */
    .data_Yay0_1b5ed88_len_20040 0x1B5ED88 : AT(0x1B5ED88) {
        build/bin/Yay0_1b5ed88_len_20040.o(.data);
    }

    /* 0x00000000 1B608C0-1B625F8 [1D38] */
    .data_Yay0_1b608c0_len_2534 0x1B608C0 : AT(0x1B608C0) {
        build/bin/Yay0_1b608c0_len_2534.o(.data);
    }

    /* 0x00000000 1B625F8-1B633D0 [DD8] */
    .data_Yay0_1b625f8_len_1202 0x1B625F8 : AT(0x1B625F8) {
        build/bin/Yay0_1b625f8_len_1202.o(.data);
    }

    /* 0x00000000 1B633D0-1B64878 [14A8] */
    .data_Yay0_1b633d0_len_4824 0x1B633D0 : AT(0x1B633D0) {
        build/bin/Yay0_1b633d0_len_4824.o(.data);
    }

    /* 0x00000000 1B64878-1B657E0 [F68] */
    .data_Yay0_1b64878_len_1786 0x1B64878 : AT(0x1B64878) {
        build/bin/Yay0_1b64878_len_1786.o(.data);
    }

    /* 0x00000000 1B657E0-1B65A08 [228] */
    .data_Yay0_1b657e0_len_808 0x1B657E0 : AT(0x1B657E0) {
        build/bin/Yay0_1b657e0_len_808.o(.data);
    }

    /* 0x00000000 1B65A08-1B65E50 [448] */
    .data_Yay0_1b65a08_len_444 0x1B65A08 : AT(0x1B65A08) {
        build/bin/Yay0_1b65a08_len_444.o(.data);
    }

    /* 0x00000000 1B65E50-1B66238 [3E8] */
    .data_Yay0_1b65e50_len_2024 0x1B65E50 : AT(0x1B65E50) {
        build/bin/Yay0_1b65e50_len_2024.o(.data);
    }

    /* 0x00000000 1B66238-1B69580 [3348] */
    .data_Yay0_1b66238_len_9542 0x1B66238 : AT(0x1B66238) {
        build/bin/Yay0_1b66238_len_9542.o(.data);
    }

    /* 0x00000000 1B69580-1B6C318 [2D98] */
    .data_Yay0_1b69580_len_4218 0x1B69580 : AT(0x1B69580) {
        build/bin/Yay0_1b69580_len_4218.o(.data);
    }

    /* 0x00000000 1B6C318-1B6DD98 [1A80] */
    .data_Yay0_1b6c318_len_1c80 0x1B6C318 : AT(0x1B6C318) {
        build/bin/Yay0_1b6c318_len_1c80.o(.data);
    }

    /* 0x00000000 1B6DD98-1B6F150 [13B8] */
    .data_Yay0_1b6dd98_len_2046 0x1B6DD98 : AT(0x1B6DD98) {
        build/bin/Yay0_1b6dd98_len_2046.o(.data);
    }

    /* 0x00000000 1B6F150-1B71618 [24C8] */
    .data_Yay0_1b6f150_len_10608 0x1B6F150 : AT(0x1B6F150) {
        build/bin/Yay0_1b6f150_len_10608.o(.data);
    }

    /* 0x00000000 1B71618-1B72890 [1278] */
    .data_Yay0_1b71618_len_2882 0x1B71618 : AT(0x1B71618) {
        build/bin/Yay0_1b71618_len_2882.o(.data);
    }

    /* 0x00000000 1B72890-1B73B08 [1278] */
    .data_Yay0_1b72890_len_1302 0x1B72890 : AT(0x1B72890) {
        build/bin/Yay0_1b72890_len_1302.o(.data);
    }

    /* 0x00000000 1B73B08-1B747B8 [CB0] */
    .data_Yay0_1b73b08_len_44b0 0x1B73B08 : AT(0x1B73B08) {
        build/bin/Yay0_1b73b08_len_44b0.o(.data);
    }

    /* 0x00000000 1B747B8-1B76E30 [2678] */
    .data_Yay0_1b747b8_len_2800 0x1B747B8 : AT(0x1B747B8) {
        build/bin/Yay0_1b747b8_len_2800.o(.data);
    }

    /* 0x00000000 1B76E30-1B78EC0 [2090] */
    .data_Yay0_1b76e30_len_808a 0x1B76E30 : AT(0x1B76E30) {
        build/bin/Yay0_1b76e30_len_808a.o(.data);
    }

    /* 0x00000000 1B78EC0-1B79A20 [B60] */
    .data_Yay0_1b78ec0_len_101c 0x1B78EC0 : AT(0x1B78EC0) {
        build/bin/Yay0_1b78ec0_len_101c.o(.data);
    }

    /* 0x00000000 1B79A20-1B79F08 [4E8] */
    .data_Yay0_1b79a20_len_508 0x1B79A20 : AT(0x1B79A20) {
        build/bin/Yay0_1b79a20_len_508.o(.data);
    }

    /* 0x00000000 1B79F08-1B7AA08 [B00] */
    .data_Yay0_1b79f08_len_2004 0x1B79F08 : AT(0x1B79F08) {
        build/bin/Yay0_1b79f08_len_2004.o(.data);
    }

    /* 0x00000000 1B7AA08-1B7B008 [600] */
    .data_Yay0_1b7aa08_len_1000 0x1B7AA08 : AT(0x1B7AA08) {
        build/bin/Yay0_1b7aa08_len_1000.o(.data);
    }

    /* 0x00000000 1B7B008-1B7BB50 [B48] */
    .data_Yay0_1b7b008_len_b44 0x1B7B008 : AT(0x1B7B008) {
        build/bin/Yay0_1b7b008_len_b44.o(.data);
    }

    /* 0x00000000 1B7BB50-1B7EC68 [3118] */
    .data_Yay0_1b7bb50_len_4424 0x1B7BB50 : AT(0x1B7BB50) {
        build/bin/Yay0_1b7bb50_len_4424.o(.data);
    }

    /* 0x00000000 1B7EC68-1B7FF48 [12E0] */
    .data_Yay0_1b7ec68_len_1300 0x1B7EC68 : AT(0x1B7EC68) {
        build/bin/Yay0_1b7ec68_len_1300.o(.data);
    }

    /* 0x00000000 1B7FF48-1B81E88 [1F40] */
    .data_Yay0_1b7ff48_len_80086 0x1B7FF48 : AT(0x1B7FF48) {
        build/bin/Yay0_1b7ff48_len_80086.o(.data);
    }

    /* 0x00000000 1B81E88-1B82058 [1D0] */
    .data_Yay0_1b81e88_len_2050 0x1B81E88 : AT(0x1B81E88) {
        build/bin/Yay0_1b81e88_len_2050.o(.data);
    }

    /* 0x00000000 1B82058-1B82202 [1AA] */
    .data_Yay0_1b82058_len_202 0x1B82058 : AT(0x1B82058) {
        build/bin/Yay0_1b82058_len_202.o(.data);
    }

    /* 0x00000000 1B82202-1E40000 [2BDDFE] */
    .data_1B82202 0x1B82202 : AT(0x1B82202) {
        build/bin/1B82202.o(.data);
    }

    /* 0x00000000 1E40000-27FEE22 [9BEE22] */
    .data_map_assets.fs 0x1E40000 : AT(0x1E40000) {
        build/bin/map_assets.fs.o(.data);
    }

    /* 0x00000000 27FEE22-2800000 [11DE] */
    .data_27FEE22 0x27FEE22 : AT(0x27FEE22) {
        build/bin/27FEE22.o(.data);
    }

}