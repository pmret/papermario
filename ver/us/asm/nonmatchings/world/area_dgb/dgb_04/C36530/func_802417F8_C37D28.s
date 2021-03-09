.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802417F8_C37D28
/* C37D28 802417F8 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* C37D2C 802417FC AFB40040 */  sw        $s4, 0x40($sp)
/* C37D30 80241800 0080A02D */  daddu     $s4, $a0, $zero
/* C37D34 80241804 AFBF0044 */  sw        $ra, 0x44($sp)
/* C37D38 80241808 AFB3003C */  sw        $s3, 0x3c($sp)
/* C37D3C 8024180C AFB20038 */  sw        $s2, 0x38($sp)
/* C37D40 80241810 AFB10034 */  sw        $s1, 0x34($sp)
/* C37D44 80241814 AFB00030 */  sw        $s0, 0x30($sp)
/* C37D48 80241818 8E930148 */  lw        $s3, 0x148($s4)
/* C37D4C 8024181C 00A0802D */  daddu     $s0, $a1, $zero
/* C37D50 80241820 86640008 */  lh        $a0, 8($s3)
/* C37D54 80241824 0C00EABB */  jal       get_npc_unsafe
/* C37D58 80241828 00C0882D */   daddu    $s1, $a2, $zero
/* C37D5C 8024182C 3C048000 */  lui       $a0, 0x8000
/* C37D60 80241830 0040902D */  daddu     $s2, $v0, $zero
/* C37D64 80241834 C6400040 */  lwc1      $f0, 0x40($s2)
/* C37D68 80241838 34840011 */  ori       $a0, $a0, 0x11
/* C37D6C 8024183C E7A00010 */  swc1      $f0, 0x10($sp)
/* C37D70 80241840 8E460038 */  lw        $a2, 0x38($s2)
/* C37D74 80241844 8E47003C */  lw        $a3, 0x3c($s2)
/* C37D78 80241848 0C05267B */  jal       func_801499EC
/* C37D7C 8024184C 24050002 */   addiu    $a1, $zero, 2
/* C37D80 80241850 0220202D */  daddu     $a0, $s1, $zero
/* C37D84 80241854 24020001 */  addiu     $v0, $zero, 1
/* C37D88 80241858 AFA20010 */  sw        $v0, 0x10($sp)
/* C37D8C 8024185C 8E060024 */  lw        $a2, 0x24($s0)
/* C37D90 80241860 8E070028 */  lw        $a3, 0x28($s0)
/* C37D94 80241864 0C01242D */  jal       func_800490B4
/* C37D98 80241868 0260282D */   daddu    $a1, $s3, $zero
/* C37D9C 8024186C 1440000B */  bnez      $v0, .L8024189C
/* C37DA0 80241870 3C04FFDF */   lui      $a0, 0xffdf
/* C37DA4 80241874 8E62006C */  lw        $v0, 0x6c($s3)
/* C37DA8 80241878 2403FEFF */  addiu     $v1, $zero, -0x101
/* C37DAC 8024187C 00431024 */  and       $v0, $v0, $v1
/* C37DB0 80241880 AE62006C */  sw        $v0, 0x6c($s3)
/* C37DB4 80241884 8E420000 */  lw        $v0, ($s2)
/* C37DB8 80241888 3484FFFF */  ori       $a0, $a0, 0xffff
/* C37DBC 8024188C AE400048 */  sw        $zero, 0x48($s2)
/* C37DC0 80241890 00441024 */  and       $v0, $v0, $a0
/* C37DC4 80241894 0809069B */  j         .L80241A6C
/* C37DC8 80241898 AE420000 */   sw       $v0, ($s2)
.L8024189C:
/* C37DCC 8024189C 3C10800F */  lui       $s0, %hi(gPlayerStatusPtr)
/* C37DD0 802418A0 26107B30 */  addiu     $s0, $s0, %lo(gPlayerStatusPtr)
/* C37DD4 802418A4 C6440048 */  lwc1      $f4, 0x48($s2)
/* C37DD8 802418A8 3C0141C8 */  lui       $at, 0x41c8
/* C37DDC 802418AC 44810000 */  mtc1      $at, $f0
/* C37DE0 802418B0 8E020000 */  lw        $v0, ($s0)
/* C37DE4 802418B4 46002100 */  add.s     $f4, $f4, $f0
/* C37DE8 802418B8 C4420028 */  lwc1      $f2, 0x28($v0)
/* C37DEC 802418BC 3C014000 */  lui       $at, 0x4000
/* C37DF0 802418C0 44810000 */  mtc1      $at, $f0
/* C37DF4 802418C4 E6420038 */  swc1      $f2, 0x38($s2)
/* C37DF8 802418C8 C4420030 */  lwc1      $f2, 0x30($v0)
/* C37DFC 802418CC 46001080 */  add.s     $f2, $f2, $f0
/* C37E00 802418D0 3C018024 */  lui       $at, %hi(D_80244448_C3A978)
/* C37E04 802418D4 D4264448 */  ldc1      $f6, %lo(D_80244448_C3A978)($at)
/* C37E08 802418D8 46002021 */  cvt.d.s   $f0, $f4
/* C37E0C 802418DC 4620303C */  c.lt.d    $f6, $f0
/* C37E10 802418E0 E6440048 */  swc1      $f4, 0x48($s2)
/* C37E14 802418E4 45000004 */  bc1f      .L802418F8
/* C37E18 802418E8 E6420040 */   swc1     $f2, 0x40($s2)
/* C37E1C 802418EC 46260001 */  sub.d     $f0, $f0, $f6
/* C37E20 802418F0 46200020 */  cvt.s.d   $f0, $f0
/* C37E24 802418F4 E6400048 */  swc1      $f0, 0x48($s2)
.L802418F8:
/* C37E28 802418F8 3C02B60B */  lui       $v0, 0xb60b
/* C37E2C 802418FC C6400048 */  lwc1      $f0, 0x48($s2)
/* C37E30 80241900 344260B7 */  ori       $v0, $v0, 0x60b7
/* C37E34 80241904 4600020D */  trunc.w.s $f8, $f0
/* C37E38 80241908 44044000 */  mfc1      $a0, $f8
/* C37E3C 8024190C 00000000 */  nop
/* C37E40 80241910 00820018 */  mult      $a0, $v0
/* C37E44 80241914 00041FC3 */  sra       $v1, $a0, 0x1f
/* C37E48 80241918 00004010 */  mfhi      $t0
/* C37E4C 8024191C 01041021 */  addu      $v0, $t0, $a0
/* C37E50 80241920 000211C3 */  sra       $v0, $v0, 7
/* C37E54 80241924 00431023 */  subu      $v0, $v0, $v1
/* C37E58 80241928 00021840 */  sll       $v1, $v0, 1
/* C37E5C 8024192C 00621821 */  addu      $v1, $v1, $v0
/* C37E60 80241930 00031100 */  sll       $v0, $v1, 4
/* C37E64 80241934 00431023 */  subu      $v0, $v0, $v1
/* C37E68 80241938 00021080 */  sll       $v0, $v0, 2
/* C37E6C 8024193C 00822023 */  subu      $a0, $a0, $v0
/* C37E70 80241940 00042400 */  sll       $a0, $a0, 0x10
/* C37E74 80241944 0C00A4F5 */  jal       cosine
/* C37E78 80241948 00042403 */   sra      $a0, $a0, 0x10
/* C37E7C 8024194C 3C014260 */  lui       $at, 0x4260
/* C37E80 80241950 44811000 */  mtc1      $at, $f2
/* C37E84 80241954 00000000 */  nop
/* C37E88 80241958 46020002 */  mul.s     $f0, $f0, $f2
/* C37E8C 8024195C 00000000 */  nop
/* C37E90 80241960 24050006 */  addiu     $a1, $zero, 6
/* C37E94 80241964 3C01437F */  lui       $at, 0x437f
/* C37E98 80241968 44811000 */  mtc1      $at, $f2
/* C37E9C 8024196C 240200FF */  addiu     $v0, $zero, 0xff
/* C37EA0 80241970 46001081 */  sub.s     $f2, $f2, $f0
/* C37EA4 80241974 AFA20014 */  sw        $v0, 0x14($sp)
/* C37EA8 80241978 AFA00018 */  sw        $zero, 0x18($sp)
/* C37EAC 8024197C 4600120D */  trunc.w.s $f8, $f2
/* C37EB0 80241980 44064000 */  mfc1      $a2, $f8
/* C37EB4 80241984 00000000 */  nop
/* C37EB8 80241988 AFA60010 */  sw        $a2, 0x10($sp)
/* C37EBC 8024198C 8E440024 */  lw        $a0, 0x24($s2)
/* C37EC0 80241990 0C0B7A25 */  jal       func_802DE894
/* C37EC4 80241994 00C0382D */   daddu    $a3, $a2, $zero
/* C37EC8 80241998 27A50020 */  addiu     $a1, $sp, 0x20
/* C37ECC 8024199C 27A60024 */  addiu     $a2, $sp, 0x24
/* C37ED0 802419A0 8E020000 */  lw        $v0, ($s0)
/* C37ED4 802419A4 3C01447A */  lui       $at, 0x447a
/* C37ED8 802419A8 44810000 */  mtc1      $at, $f0
/* C37EDC 802419AC C4420028 */  lwc1      $f2, 0x28($v0)
/* C37EE0 802419B0 C444002C */  lwc1      $f4, 0x2c($v0)
/* C37EE4 802419B4 C4460030 */  lwc1      $f6, 0x30($v0)
/* C37EE8 802419B8 27A2002C */  addiu     $v0, $sp, 0x2c
/* C37EEC 802419BC E7A0002C */  swc1      $f0, 0x2c($sp)
/* C37EF0 802419C0 E7A20020 */  swc1      $f2, 0x20($sp)
/* C37EF4 802419C4 E7A40024 */  swc1      $f4, 0x24($sp)
/* C37EF8 802419C8 E7A60028 */  swc1      $f6, 0x28($sp)
/* C37EFC 802419CC AFA20010 */  sw        $v0, 0x10($sp)
/* C37F00 802419D0 8E440080 */  lw        $a0, 0x80($s2)
/* C37F04 802419D4 0C0372DF */  jal       func_800DCB7C
/* C37F08 802419D8 27A70028 */   addiu    $a3, $sp, 0x28
/* C37F0C 802419DC C644003C */  lwc1      $f4, 0x3c($s2)
/* C37F10 802419E0 C7A00024 */  lwc1      $f0, 0x24($sp)
/* C37F14 802419E4 46002001 */  sub.s     $f0, $f4, $f0
/* C37F18 802419E8 3C014038 */  lui       $at, 0x4038
/* C37F1C 802419EC 44811800 */  mtc1      $at, $f3
/* C37F20 802419F0 44801000 */  mtc1      $zero, $f2
/* C37F24 802419F4 46000005 */  abs.s     $f0, $f0
/* C37F28 802419F8 46000021 */  cvt.d.s   $f0, $f0
/* C37F2C 802419FC 4620103C */  c.lt.d    $f2, $f0
/* C37F30 80241A00 00000000 */  nop
/* C37F34 80241A04 45000008 */  bc1f      .L80241A28
/* C37F38 80241A08 3C03FFDF */   lui      $v1, 0xffdf
/* C37F3C 80241A0C 3C018024 */  lui       $at, %hi(D_80244450_C3A980)
/* C37F40 80241A10 D4224450 */  ldc1      $f2, %lo(D_80244450_C3A980)($at)
/* C37F44 80241A14 46002021 */  cvt.d.s   $f0, $f4
/* C37F48 80241A18 46220001 */  sub.d     $f0, $f0, $f2
/* C37F4C 80241A1C 46200020 */  cvt.s.d   $f0, $f0
/* C37F50 80241A20 0809069D */  j         .L80241A74
/* C37F54 80241A24 E640003C */   swc1     $f0, 0x3c($s2)
.L80241A28:
/* C37F58 80241A28 8E420000 */  lw        $v0, ($s2)
/* C37F5C 80241A2C 3463FFFF */  ori       $v1, $v1, 0xffff
/* C37F60 80241A30 AE400048 */  sw        $zero, 0x48($s2)
/* C37F64 80241A34 00431024 */  and       $v0, $v0, $v1
/* C37F68 80241A38 AE420000 */  sw        $v0, ($s2)
/* C37F6C 80241A3C 3C038011 */  lui       $v1, %hi(D_8010EBB0+0x3)
/* C37F70 80241A40 8063EBB3 */  lb        $v1, %lo(D_8010EBB0+0x3)($v1)
/* C37F74 80241A44 24020009 */  addiu     $v0, $zero, 9
/* C37F78 80241A48 10620009 */  beq       $v1, $v0, .L80241A70
/* C37F7C 80241A4C 24020010 */   addiu    $v0, $zero, 0x10
/* C37F80 80241A50 0C03805E */  jal       disable_player_input
/* C37F84 80241A54 00000000 */   nop
/* C37F88 80241A58 0C03BD8A */  jal       func_800EF628
/* C37F8C 80241A5C 00000000 */   nop
/* C37F90 80241A60 24020014 */  addiu     $v0, $zero, 0x14
/* C37F94 80241A64 0809069C */  j         .L80241A70
/* C37F98 80241A68 A640008E */   sh       $zero, 0x8e($s2)
.L80241A6C:
/* C37F9C 80241A6C 24020010 */  addiu     $v0, $zero, 0x10
.L80241A70:
/* C37FA0 80241A70 AE820070 */  sw        $v0, 0x70($s4)
.L80241A74:
/* C37FA4 80241A74 8FBF0044 */  lw        $ra, 0x44($sp)
/* C37FA8 80241A78 8FB40040 */  lw        $s4, 0x40($sp)
/* C37FAC 80241A7C 8FB3003C */  lw        $s3, 0x3c($sp)
/* C37FB0 80241A80 8FB20038 */  lw        $s2, 0x38($sp)
/* C37FB4 80241A84 8FB10034 */  lw        $s1, 0x34($sp)
/* C37FB8 80241A88 8FB00030 */  lw        $s0, 0x30($sp)
/* C37FBC 80241A8C 03E00008 */  jr        $ra
/* C37FC0 80241A90 27BD0048 */   addiu    $sp, $sp, 0x48
