.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004A7B0
/* 25BB0 8004A7B0 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 25BB4 8004A7B4 AFB00030 */  sw        $s0, 0x30($sp)
/* 25BB8 8004A7B8 3C10800E */  lui       $s0, %hi(D_800D9228)
/* 25BBC 8004A7BC 26109228 */  addiu     $s0, $s0, %lo(D_800D9228)
/* 25BC0 8004A7C0 0200202D */  daddu     $a0, $s0, $zero
/* 25BC4 8004A7C4 3C05801B */  lui       $a1, %hi(D_801AA000)
/* 25BC8 8004A7C8 24A5A000 */  addiu     $a1, $a1, %lo(D_801AA000)
/* 25BCC 8004A7CC 3C060005 */  lui       $a2, 5
/* 25BD0 8004A7D0 24020001 */  addiu     $v0, $zero, 1
/* 25BD4 8004A7D4 AFBF003C */  sw        $ra, 0x3c($sp)
/* 25BD8 8004A7D8 AFB20038 */  sw        $s2, 0x38($sp)
/* 25BDC 8004A7DC AFB10034 */  sw        $s1, 0x34($sp)
/* 25BE0 8004A7E0 3C018008 */  lui       $at, %hi(D_80078150)
/* 25BE4 8004A7E4 A0228150 */  sb        $v0, %lo(D_80078150)($at)
/* 25BE8 8004A7E8 3C018008 */  lui       $at, %hi(D_80078140)
/* 25BEC 8004A7EC A0208140 */  sb        $zero, %lo(D_80078140)($at)
/* 25BF0 8004A7F0 0C015EF4 */  jal       func_80057BD0
/* 25BF4 8004A7F4 34C66000 */   ori      $a2, $a2, 0x6000
/* 25BF8 8004A7F8 24047D00 */  addiu     $a0, $zero, 0x7d00
/* 25BFC 8004A7FC 24020018 */  addiu     $v0, $zero, 0x18
/* 25C00 8004A800 AFA20018 */  sw        $v0, 0x18($sp)
/* 25C04 8004A804 24020004 */  addiu     $v0, $zero, 4
/* 25C08 8004A808 0C01854C */  jal       func_80061530
/* 25C0C 8004A80C AFA2001C */   sw       $v0, 0x1c($sp)
/* 25C10 8004A810 3C03800E */  lui       $v1, %hi(D_800DAA98)
/* 25C14 8004A814 8C63AA98 */  lw        $v1, %lo(D_800DAA98)($v1)
/* 25C18 8004A818 00620018 */  mult      $v1, $v0
/* 25C1C 8004A81C 00001812 */  mflo      $v1
/* 25C20 8004A820 2464003B */  addiu     $a0, $v1, 0x3b
/* 25C24 8004A824 3C038888 */  lui       $v1, 0x8888
/* 25C28 8004A828 34638889 */  ori       $v1, $v1, 0x8889
/* 25C2C 8004A82C 00830019 */  multu     $a0, $v1
/* 25C30 8004A830 0000882D */  daddu     $s1, $zero, $zero
/* 25C34 8004A834 3C12800A */  lui       $s2, %hi(D_800A1320)
/* 25C38 8004A838 26521320 */  addiu     $s2, $s2, %lo(D_800A1320)
/* 25C3C 8004A83C AFA20020 */  sw        $v0, 0x20($sp)
/* 25C40 8004A840 00001810 */  mfhi      $v1
/* 25C44 8004A844 3C02B216 */  lui       $v0, 0xb216
/* 25C48 8004A848 344242C9 */  ori       $v0, $v0, 0x42c9
/* 25C4C 8004A84C 00031942 */  srl       $v1, $v1, 5
/* 25C50 8004A850 00620019 */  multu     $v1, $v0
/* 25C54 8004A854 A3A00024 */  sb        $zero, 0x24($sp)
/* 25C58 8004A858 AFB0002C */  sw        $s0, 0x2c($sp)
/* 25C5C 8004A85C 3C028005 */  lui       $v0, %hi(func_8004AED4)
/* 25C60 8004A860 2442AED4 */  addiu     $v0, $v0, %lo(func_8004AED4)
/* 25C64 8004A864 AFA20028 */  sw        $v0, 0x28($sp)
/* 25C68 8004A868 00001810 */  mfhi      $v1
/* 25C6C 8004A86C 000319C2 */  srl       $v1, $v1, 7
/* 25C70 8004A870 24630001 */  addiu     $v1, $v1, 1
/* 25C74 8004A874 00031040 */  sll       $v0, $v1, 1
/* 25C78 8004A878 00431021 */  addu      $v0, $v0, $v1
/* 25C7C 8004A87C 000210C0 */  sll       $v0, $v0, 3
/* 25C80 8004A880 00431023 */  subu      $v0, $v0, $v1
/* 25C84 8004A884 000210C0 */  sll       $v0, $v0, 3
/* 25C88 8004A888 3C01800A */  lui       $at, %hi(D_800A1444)
/* 25C8C 8004A88C AC221444 */  sw        $v0, %lo(D_800A1444)($at)
/* 25C90 8004A890 2442FF48 */  addiu     $v0, $v0, -0xb8
/* 25C94 8004A894 3C01800A */  lui       $at, %hi(D_800A1448)
/* 25C98 8004A898 AC221448 */  sw        $v0, %lo(D_800A1448)($at)
.L8004A89C:
/* 25C9C 8004A89C 24050001 */  addiu     $a1, $zero, 1
/* 25CA0 8004A8A0 24064000 */  addiu     $a2, $zero, 0x4000
/* 25CA4 8004A8A4 8FA4002C */  lw        $a0, 0x2c($sp)
/* 25CA8 8004A8A8 0C015F10 */  jal       func_80057C40
/* 25CAC 8004A8AC 02258821 */   addu     $s1, $s1, $a1
/* 25CB0 8004A8B0 AE420000 */  sw        $v0, ($s2)
/* 25CB4 8004A8B4 2E220003 */  sltiu     $v0, $s1, 3
/* 25CB8 8004A8B8 1440FFF8 */  bnez      $v0, .L8004A89C
/* 25CBC 8004A8BC 26520004 */   addiu    $s2, $s2, 4
/* 25CC0 8004A8C0 0000882D */  daddu     $s1, $zero, $zero
/* 25CC4 8004A8C4 24090002 */  addiu     $t1, $zero, 2
/* 25CC8 8004A8C8 3C08800E */  lui       $t0, %hi(D_800D9760)
/* 25CCC 8004A8CC 25089760 */  addiu     $t0, $t0, %lo(D_800D9760)
/* 25CD0 8004A8D0 24070100 */  addiu     $a3, $zero, 0x100
/* 25CD4 8004A8D4 3C068007 */  lui       $a2, %hi(D_80073180)
/* 25CD8 8004A8D8 24C63180 */  addiu     $a2, $a2, %lo(D_80073180)
/* 25CDC 8004A8DC 3C058009 */  lui       $a1, %hi(D_80097A60)
/* 25CE0 8004A8E0 24A57A60 */  addiu     $a1, $a1, %lo(D_80097A60)
/* 25CE4 8004A8E4 24040800 */  addiu     $a0, $zero, 0x800
/* 25CE8 8004A8E8 3C03800A */  lui       $v1, %hi(D_800A1330)
/* 25CEC 8004A8EC 24631330 */  addiu     $v1, $v1, %lo(D_800A1330)
.L8004A8F0:
/* 25CF0 8004A8F0 AC600000 */  sw        $zero, ($v1)
/* 25CF4 8004A8F4 AC600054 */  sw        $zero, 0x54($v1)
/* 25CF8 8004A8F8 AC690010 */  sw        $t1, 0x10($v1)
/* 25CFC 8004A8FC AC680018 */  sw        $t0, 0x18($v1)
/* 25D00 8004A900 AC67001C */  sw        $a3, 0x1c($v1)
/* 25D04 8004A904 AC660020 */  sw        $a2, 0x20($v1)
/* 25D08 8004A908 AC650028 */  sw        $a1, 0x28($v1)
/* 25D0C 8004A90C AC64002C */  sw        $a0, 0x2c($v1)
/* 25D10 8004A910 AC600030 */  sw        $zero, 0x30($v1)
/* 25D14 8004A914 AC600034 */  sw        $zero, 0x34($v1)
/* 25D18 8004A918 AC600038 */  sw        $zero, 0x38($v1)
/* 25D1C 8004A91C AC60003C */  sw        $zero, 0x3c($v1)
/* 25D20 8004A920 AC600048 */  sw        $zero, 0x48($v1)
/* 25D24 8004A924 AC60004C */  sw        $zero, 0x4c($v1)
/* 25D28 8004A928 26310001 */  addiu     $s1, $s1, 1
/* 25D2C 8004A92C 2E220003 */  sltiu     $v0, $s1, 3
/* 25D30 8004A930 1440FFEF */  bnez      $v0, .L8004A8F0
/* 25D34 8004A934 24630058 */   addiu    $v1, $v1, 0x58
/* 25D38 8004A938 0000882D */  daddu     $s1, $zero, $zero
/* 25D3C 8004A93C 3C10800A */  lui       $s0, %hi(D_800A1438)
/* 25D40 8004A940 26101438 */  addiu     $s0, $s0, %lo(D_800A1438)
.L8004A944:
/* 25D44 8004A944 24050001 */  addiu     $a1, $zero, 1
/* 25D48 8004A948 02258821 */  addu      $s1, $s1, $a1
/* 25D4C 8004A94C 3C06800A */  lui       $a2, %hi(D_800A1444)
/* 25D50 8004A950 8CC61444 */  lw        $a2, %lo(D_800A1444)($a2)
/* 25D54 8004A954 8FA4002C */  lw        $a0, 0x2c($sp)
/* 25D58 8004A958 0C015F10 */  jal       func_80057C40
/* 25D5C 8004A95C 00063080 */   sll      $a2, $a2, 2
/* 25D60 8004A960 AE020000 */  sw        $v0, ($s0)
/* 25D64 8004A964 2E220003 */  sltiu     $v0, $s1, 3
/* 25D68 8004A968 1440FFF6 */  bnez      $v0, .L8004A944
/* 25D6C 8004A96C 26100004 */   addiu    $s0, $s0, 4
/* 25D70 8004A970 0000882D */  daddu     $s1, $zero, $zero
/* 25D74 8004A974 3C02800A */  lui       $v0, %hi(D_800A19F0)
/* 25D78 8004A978 244219F0 */  addiu     $v0, $v0, %lo(D_800A19F0)
/* 25D7C 8004A97C 0040802D */  daddu     $s0, $v0, $zero
/* 25D80 8004A980 26120014 */  addiu     $s2, $s0, 0x14
/* 25D84 8004A984 AE000004 */  sw        $zero, 4($s0)
/* 25D88 8004A988 AE000000 */  sw        $zero, ($s0)
.L8004A98C:
/* 25D8C 8004A98C 0240202D */  daddu     $a0, $s2, $zero
/* 25D90 8004A990 0C012C27 */  jal       func_8004B09C
/* 25D94 8004A994 0200282D */   daddu    $a1, $s0, $zero
/* 25D98 8004A998 24050001 */  addiu     $a1, $zero, 1
/* 25D9C 8004A99C 24060500 */  addiu     $a2, $zero, 0x500
/* 25DA0 8004A9A0 26520014 */  addiu     $s2, $s2, 0x14
/* 25DA4 8004A9A4 8FA4002C */  lw        $a0, 0x2c($sp)
/* 25DA8 8004A9A8 0C015F10 */  jal       func_80057C40
/* 25DAC 8004A9AC 02258821 */   addu     $s1, $s1, $a1
/* 25DB0 8004A9B0 AE020010 */  sw        $v0, 0x10($s0)
/* 25DB4 8004A9B4 2E220031 */  sltiu     $v0, $s1, 0x31
/* 25DB8 8004A9B8 1440FFF4 */  bnez      $v0, .L8004A98C
/* 25DBC 8004A9BC 26100014 */   addiu    $s0, $s0, 0x14
/* 25DC0 8004A9C0 24050001 */  addiu     $a1, $zero, 1
/* 25DC4 8004A9C4 8FA4002C */  lw        $a0, 0x2c($sp)
/* 25DC8 8004A9C8 0C015F10 */  jal       func_80057C40
/* 25DCC 8004A9CC 24060500 */   addiu    $a2, $zero, 0x500
/* 25DD0 8004A9D0 3C04800A */  lui       $a0, %hi(D_800A1450)
/* 25DD4 8004A9D4 24841450 */  addiu     $a0, $a0, %lo(D_800A1450)
/* 25DD8 8004A9D8 3C05800A */  lui       $a1, %hi(D_800A1468)
/* 25DDC 8004A9DC 24A51468 */  addiu     $a1, $a1, %lo(D_800A1468)
/* 25DE0 8004A9E0 00111880 */  sll       $v1, $s1, 2
/* 25DE4 8004A9E4 00711821 */  addu      $v1, $v1, $s1
/* 25DE8 8004A9E8 00031880 */  sll       $v1, $v1, 2
/* 25DEC 8004A9EC 3C01800A */  lui       $at, %hi(D_800A1A00)
/* 25DF0 8004A9F0 00230821 */  addu      $at, $at, $v1
/* 25DF4 8004A9F4 AC221A00 */  sw        $v0, %lo(D_800A1A00)($at)
/* 25DF8 8004A9F8 0C019554 */  jal       func_80065550
/* 25DFC 8004A9FC 24060032 */   addiu    $a2, $zero, 0x32
/* 25E00 8004AA00 3C04800C */  lui       $a0, %hi(D_800B9180)
/* 25E04 8004AA04 24849180 */  addiu     $a0, $a0, %lo(D_800B9180)
/* 25E08 8004AA08 3C028005 */  lui       $v0, %hi(func_8004AFD8)
/* 25E0C 8004AA0C 2442AFD8 */  addiu     $v0, $v0, %lo(func_8004AFD8)
/* 25E10 8004AA10 3C018008 */  lui       $at, %hi(D_80078144)
/* 25E14 8004AA14 AC228144 */  sw        $v0, %lo(D_80078144)($at)
/* 25E18 8004AA18 0C0157C0 */  jal       func_80055F00
/* 25E1C 8004AA1C 27A50018 */   addiu    $a1, $sp, 0x18
/* 25E20 8004AA20 8FA40020 */  lw        $a0, 0x20($sp)
/* 25E24 8004AA24 0C014AC3 */  jal       func_80052B0C
/* 25E28 8004AA28 00000000 */   nop
/* 25E2C 8004AA2C 3C10800A */  lui       $s0, %hi(D_8009ED68)
/* 25E30 8004AA30 2610ED68 */  addiu     $s0, $s0, %lo(D_8009ED68)
/* 25E34 8004AA34 0200202D */  daddu     $a0, $s0, $zero
/* 25E38 8004AA38 24050003 */  addiu     $a1, $zero, 3
/* 25E3C 8004AA3C 3C068005 */  lui       $a2, %hi(func_8004AAB8)
/* 25E40 8004AA40 24C6AAB8 */  addiu     $a2, $a2, %lo(func_8004AAB8)
/* 25E44 8004AA44 3C02800A */  lui       $v0, %hi(D_800A1320)
/* 25E48 8004AA48 24421320 */  addiu     $v0, $v0, %lo(D_800A1320)
/* 25E4C 8004AA4C AFA20010 */  sw        $v0, 0x10($sp)
/* 25E50 8004AA50 24020046 */  addiu     $v0, $zero, 0x46
/* 25E54 8004AA54 0000382D */  daddu     $a3, $zero, $zero
/* 25E58 8004AA58 0C01978C */  jal       func_80065E30
/* 25E5C 8004AA5C AFA20014 */   sw       $v0, 0x14($sp)
/* 25E60 8004AA60 0C0197FC */  jal       func_80065FF0
/* 25E64 8004AA64 0200202D */   daddu    $a0, $s0, $zero
/* 25E68 8004AA68 8FBF003C */  lw        $ra, 0x3c($sp)
/* 25E6C 8004AA6C 8FB20038 */  lw        $s2, 0x38($sp)
/* 25E70 8004AA70 8FB10034 */  lw        $s1, 0x34($sp)
/* 25E74 8004AA74 8FB00030 */  lw        $s0, 0x30($sp)
/* 25E78 8004AA78 03E00008 */  jr        $ra
/* 25E7C 8004AA7C 27BD0040 */   addiu    $sp, $sp, 0x40
