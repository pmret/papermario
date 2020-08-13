.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_802D2D30
/* 0F76E0 802D2D30 27BDFFF8 */  addiu $sp, $sp, -8
/* 0F76E4 802D2D34 0080602D */  daddu $t4, $a0, $zero
/* 0F76E8 802D2D38 00A0682D */  daddu $t5, $a1, $zero
/* 0F76EC 802D2D3C 00E0582D */  daddu $t3, $a3, $zero
/* 0F76F0 802D2D40 3C08800A */  lui   $t0, 0x800a
/* 0F76F4 802D2D44 2508A66C */  addiu $t0, $t0, -0x5994
/* 0F76F8 802D2D48 3C02E700 */  lui   $v0, 0xe700
/* 0F76FC 802D2D4C AFB00000 */  sw    $s0, ($sp)
/* 0F7700 802D2D50 8D070000 */  lw    $a3, ($t0)
/* 0F7704 802D2D54 97B9001A */  lhu   $t9, 0x1a($sp)
/* 0F7708 802D2D58 97B0001E */  lhu   $s0, 0x1e($sp)
/* 0F770C 802D2D5C 97AF0022 */  lhu   $t7, 0x22($sp)
/* 0F7710 802D2D60 97B80026 */  lhu   $t8, 0x26($sp)
/* 0F7714 802D2D64 00E0182D */  daddu $v1, $a3, $zero
/* 0F7718 802D2D68 24E70008 */  addiu $a3, $a3, 8
/* 0F771C 802D2D6C AD070000 */  sw    $a3, ($t0)
/* 0F7720 802D2D70 AC620000 */  sw    $v0, ($v1)
/* 0F7724 802D2D74 AC600004 */  sw    $zero, 4($v1)
/* 0F7728 802D2D78 316300FF */  andi  $v1, $t3, 0xff
/* 0F772C 802D2D7C 240200FF */  addiu $v0, $zero, 0xff
/* 0F7730 802D2D80 1462000A */  bne   $v1, $v0, .L802D2DAC
/* 0F7734 802D2D84 00C0702D */   daddu $t6, $a2, $zero
/* 0F7738 802D2D88 3C04FCFF */  lui   $a0, 0xfcff
/* 0F773C 802D2D8C 3484FFFF */  ori   $a0, $a0, 0xffff
/* 0F7740 802D2D90 3C03FFFD */  lui   $v1, 0xfffd
/* 0F7744 802D2D94 3463FCFE */  ori   $v1, $v1, 0xfcfe
/* 0F7748 802D2D98 24E20008 */  addiu $v0, $a3, 8
/* 0F774C 802D2D9C AD020000 */  sw    $v0, ($t0)
/* 0F7750 802D2DA0 ACE40000 */  sw    $a0, ($a3)
/* 0F7754 802D2DA4 080B4B7B */  j     .L802D2DEC
/* 0F7758 802D2DA8 ACE30004 */   sw    $v1, 4($a3)

.L802D2DAC:
/* 0F775C 802D2DAC 3C05E200 */  lui   $a1, 0xe200
/* 0F7760 802D2DB0 34A5001C */  ori   $a1, $a1, 0x1c
/* 0F7764 802D2DB4 3C030050 */  lui   $v1, 0x50
/* 0F7768 802D2DB8 34634240 */  ori   $v1, $v1, 0x4240
/* 0F776C 802D2DBC 3C06FCFF */  lui   $a2, 0xfcff
/* 0F7770 802D2DC0 34C6FFFF */  ori   $a2, $a2, 0xffff
/* 0F7774 802D2DC4 3C04FFFD */  lui   $a0, 0xfffd
/* 0F7778 802D2DC8 3484F6FB */  ori   $a0, $a0, 0xf6fb
/* 0F777C 802D2DCC 24E20008 */  addiu $v0, $a3, 8
/* 0F7780 802D2DD0 AD020000 */  sw    $v0, ($t0)
/* 0F7784 802D2DD4 24E20010 */  addiu $v0, $a3, 0x10
/* 0F7788 802D2DD8 ACE50000 */  sw    $a1, ($a3)
/* 0F778C 802D2DDC ACE30004 */  sw    $v1, 4($a3)
/* 0F7790 802D2DE0 AD020000 */  sw    $v0, ($t0)
/* 0F7794 802D2DE4 ACE60008 */  sw    $a2, 8($a3)
/* 0F7798 802D2DE8 ACE4000C */  sw    $a0, 0xc($a3)
.L802D2DEC:
/* 0F779C 802D2DEC 3C09E200 */  lui   $t1, 0xe200
/* 0F77A0 802D2DF0 3529001C */  ori   $t1, $t1, 0x1c
/* 0F77A4 802D2DF4 3C070F0A */  lui   $a3, 0xf0a
/* 0F77A8 802D2DF8 34E77008 */  ori   $a3, $a3, 0x7008
/* 0F77AC 802D2DFC 3C0AFCFF */  lui   $t2, 0xfcff
/* 0F77B0 802D2E00 354AFFFF */  ori   $t2, $t2, 0xffff
/* 0F77B4 802D2E04 3C08FFFC */  lui   $t0, 0xfffc
/* 0F77B8 802D2E08 3C06800A */  lui   $a2, 0x800a
/* 0F77BC 802D2E0C 24C6A66C */  addiu $a2, $a2, -0x5994
/* 0F77C0 802D2E10 3508F279 */  ori   $t0, $t0, 0xf279
/* 0F77C4 802D2E14 3C02FA00 */  lui   $v0, 0xfa00
/* 0F77C8 802D2E18 8CC50000 */  lw    $a1, ($a2)
/* 0F77CC 802D2E1C 000C1E00 */  sll   $v1, $t4, 0x18
/* 0F77D0 802D2E20 00A0202D */  daddu $a0, $a1, $zero
/* 0F77D4 802D2E24 24A50008 */  addiu $a1, $a1, 8
/* 0F77D8 802D2E28 ACC50000 */  sw    $a1, ($a2)
/* 0F77DC 802D2E2C AC820000 */  sw    $v0, ($a0)
/* 0F77E0 802D2E30 31A200FF */  andi  $v0, $t5, 0xff
/* 0F77E4 802D2E34 00021400 */  sll   $v0, $v0, 0x10
/* 0F77E8 802D2E38 00621825 */  or    $v1, $v1, $v0
/* 0F77EC 802D2E3C 31C200FF */  andi  $v0, $t6, 0xff
/* 0F77F0 802D2E40 00021200 */  sll   $v0, $v0, 8
/* 0F77F4 802D2E44 00621825 */  or    $v1, $v1, $v0
/* 0F77F8 802D2E48 316200FF */  andi  $v0, $t3, 0xff
/* 0F77FC 802D2E4C 00621825 */  or    $v1, $v1, $v0
/* 0F7800 802D2E50 24A20008 */  addiu $v0, $a1, 8
/* 0F7804 802D2E54 AC830004 */  sw    $v1, 4($a0)
/* 0F7808 802D2E58 31E403FF */  andi  $a0, $t7, 0x3ff
/* 0F780C 802D2E5C 00042380 */  sll   $a0, $a0, 0xe
/* 0F7810 802D2E60 ACC20000 */  sw    $v0, ($a2)
/* 0F7814 802D2E64 330203FF */  andi  $v0, $t8, 0x3ff
/* 0F7818 802D2E68 00021080 */  sll   $v0, $v0, 2
/* 0F781C 802D2E6C 3C03F600 */  lui   $v1, 0xf600
/* 0F7820 802D2E70 00431025 */  or    $v0, $v0, $v1
/* 0F7824 802D2E74 00822025 */  or    $a0, $a0, $v0
/* 0F7828 802D2E78 332303FF */  andi  $v1, $t9, 0x3ff
/* 0F782C 802D2E7C 00031B80 */  sll   $v1, $v1, 0xe
/* 0F7830 802D2E80 320203FF */  andi  $v0, $s0, 0x3ff
/* 0F7834 802D2E84 00021080 */  sll   $v0, $v0, 2
/* 0F7838 802D2E88 00621825 */  or    $v1, $v1, $v0
/* 0F783C 802D2E8C 24A20010 */  addiu $v0, $a1, 0x10
/* 0F7840 802D2E90 ACA40000 */  sw    $a0, ($a1)
/* 0F7844 802D2E94 ACA30004 */  sw    $v1, 4($a1)
/* 0F7848 802D2E98 ACC20000 */  sw    $v0, ($a2)
/* 0F784C 802D2E9C 3C02E700 */  lui   $v0, 0xe700
/* 0F7850 802D2EA0 ACA20008 */  sw    $v0, 8($a1)
/* 0F7854 802D2EA4 24A20018 */  addiu $v0, $a1, 0x18
/* 0F7858 802D2EA8 ACA0000C */  sw    $zero, 0xc($a1)
/* 0F785C 802D2EAC ACC20000 */  sw    $v0, ($a2)
/* 0F7860 802D2EB0 24A20020 */  addiu $v0, $a1, 0x20
/* 0F7864 802D2EB4 ACA90010 */  sw    $t1, 0x10($a1)
/* 0F7868 802D2EB8 ACA70014 */  sw    $a3, 0x14($a1)
/* 0F786C 802D2EBC ACC20000 */  sw    $v0, ($a2)
/* 0F7870 802D2EC0 ACAA0018 */  sw    $t2, 0x18($a1)
/* 0F7874 802D2EC4 ACA8001C */  sw    $t0, 0x1c($a1)
/* 0F7878 802D2EC8 8FB00000 */  lw    $s0, ($sp)
/* 0F787C 802D2ECC 03E00008 */  jr    $ra
/* 0F7880 802D2ED0 27BD0008 */   addiu $sp, $sp, 8

/* 0F7884 802D2ED4 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0F7888 802D2ED8 308400FF */  andi  $a0, $a0, 0xff
/* 0F788C 802D2EDC 30A500FF */  andi  $a1, $a1, 0xff
/* 0F7890 802D2EE0 30C600FF */  andi  $a2, $a2, 0xff
/* 0F7894 802D2EE4 8FA20038 */  lw    $v0, 0x38($sp)
/* 0F7898 802D2EE8 8FA8003C */  lw    $t0, 0x3c($sp)
/* 0F789C 802D2EEC 8FA30040 */  lw    $v1, 0x40($sp)
/* 0F78A0 802D2EF0 8FA90044 */  lw    $t1, 0x44($sp)
/* 0F78A4 802D2EF4 30E700FF */  andi  $a3, $a3, 0xff
/* 0F78A8 802D2EF8 AFBF0020 */  sw    $ra, 0x20($sp)
/* 0F78AC 802D2EFC 00431821 */  addu  $v1, $v0, $v1
/* 0F78B0 802D2F00 01094821 */  addu  $t1, $t0, $t1
/* 0F78B4 802D2F04 3042FFFF */  andi  $v0, $v0, 0xffff
/* 0F78B8 802D2F08 3108FFFF */  andi  $t0, $t0, 0xffff
/* 0F78BC 802D2F0C 3063FFFF */  andi  $v1, $v1, 0xffff
/* 0F78C0 802D2F10 3129FFFF */  andi  $t1, $t1, 0xffff
/* 0F78C4 802D2F14 AFA20010 */  sw    $v0, 0x10($sp)
/* 0F78C8 802D2F18 AFA80014 */  sw    $t0, 0x14($sp)
/* 0F78CC 802D2F1C AFA30018 */  sw    $v1, 0x18($sp)
/* 0F78D0 802D2F20 0C0B4B4C */  jal   func_802D2D30
/* 0F78D4 802D2F24 AFA9001C */   sw    $t1, 0x1c($sp)
/* 0F78D8 802D2F28 8FBF0020 */  lw    $ra, 0x20($sp)
/* 0F78DC 802D2F2C 03E00008 */  jr    $ra
/* 0F78E0 802D2F30 27BD0028 */   addiu $sp, $sp, 0x28

