.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800539A8
/* 2EDA8 800539A8 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 2EDAC 800539AC AFB20028 */  sw        $s2, 0x28($sp)
/* 2EDB0 800539B0 3C12800A */  lui       $s2, %hi(D_8009A5A0)
/* 2EDB4 800539B4 8E52A5A0 */  lw        $s2, %lo(D_8009A5A0)($s2)
/* 2EDB8 800539B8 AFB60038 */  sw        $s6, 0x38($sp)
/* 2EDBC 800539BC 0080B02D */  daddu     $s6, $a0, $zero
/* 2EDC0 800539C0 AFB3002C */  sw        $s3, 0x2c($sp)
/* 2EDC4 800539C4 00C0982D */  daddu     $s3, $a2, $zero
/* 2EDC8 800539C8 AFBF0044 */  sw        $ra, 0x44($sp)
/* 2EDCC 800539CC AFBE0040 */  sw        $fp, 0x40($sp)
/* 2EDD0 800539D0 AFB7003C */  sw        $s7, 0x3c($sp)
/* 2EDD4 800539D4 AFB50034 */  sw        $s5, 0x34($sp)
/* 2EDD8 800539D8 AFB40030 */  sw        $s4, 0x30($sp)
/* 2EDDC 800539DC AFB10024 */  sw        $s1, 0x24($sp)
/* 2EDE0 800539E0 AFB00020 */  sw        $s0, 0x20($sp)
/* 2EDE4 800539E4 AFA5004C */  sw        $a1, 0x4c($sp)
/* 2EDE8 800539E8 8E420030 */  lw        $v0, 0x30($s2)
/* 2EDEC 800539EC 02C2102B */  sltu      $v0, $s6, $v0
/* 2EDF0 800539F0 10400038 */  beqz      $v0, .L80053AD4
/* 2EDF4 800539F4 00A0B82D */   daddu    $s7, $a1, $zero
/* 2EDF8 800539F8 24050010 */  addiu     $a1, $zero, 0x10
/* 2EDFC 800539FC 8E43002C */  lw        $v1, 0x2c($s2)
/* 2EE00 80053A00 001610C0 */  sll       $v0, $s6, 3
/* 2EE04 80053A04 0062A021 */  addu      $s4, $v1, $v0
/* 2EE08 80053A08 96840000 */  lhu       $a0, ($s4)
/* 2EE0C 80053A0C 0C01504B */  jal       func_8005412C
/* 2EE10 80053A10 03A53021 */   addu     $a2, $sp, $a1
/* 2EE14 80053A14 14400030 */  bnez      $v0, .L80053AD8
/* 2EE18 80053A18 00000000 */   nop
/* 2EE1C 80053A1C 0C0135F6 */  jal       func_8004D7D8
/* 2EE20 80053A20 0260202D */   daddu    $a0, $s3, $zero
/* 2EE24 80053A24 1440002C */  bnez      $v0, .L80053AD8
/* 2EE28 80053A28 240200C9 */   addiu    $v0, $zero, 0xc9
/* 2EE2C 80053A2C 3C0200FF */  lui       $v0, 0xff
/* 2EE30 80053A30 3442FFFF */  ori       $v0, $v0, 0xffff
/* 2EE34 80053A34 02E0282D */  daddu     $a1, $s7, $zero
/* 2EE38 80053A38 0000802D */  daddu     $s0, $zero, $zero
/* 2EE3C 80053A3C 3C1500FF */  lui       $s5, 0xff
/* 2EE40 80053A40 36B5FFFF */  ori       $s5, $s5, 0xffff
/* 2EE44 80053A44 241E0030 */  addiu     $fp, $zero, 0x30
/* 2EE48 80053A48 0280882D */  daddu     $s1, $s4, $zero
/* 2EE4C 80053A4C 8FA60014 */  lw        $a2, 0x14($sp)
/* 2EE50 80053A50 8FA40010 */  lw        $a0, 0x10($sp)
/* 2EE54 80053A54 0C0152AC */  jal       func_80054AB0
/* 2EE58 80053A58 00C23024 */   and      $a2, $a2, $v0
.L80053A5C:
/* 2EE5C 80053A5C 96220002 */  lhu       $v0, 2($s1)
/* 2EE60 80053A60 50400012 */  beql      $v0, $zero, .L80053AAC
/* 2EE64 80053A64 26100001 */   addiu    $s0, $s0, 1
/* 2EE68 80053A68 8E440020 */  lw        $a0, 0x20($s2)
/* 2EE6C 80053A6C 000210C0 */  sll       $v0, $v0, 3
/* 2EE70 80053A70 00822021 */  addu      $a0, $a0, $v0
/* 2EE74 80053A74 8C820000 */  lw        $v0, ($a0)
/* 2EE78 80053A78 8E43001C */  lw        $v1, 0x1c($s2)
/* 2EE7C 80053A7C 00551024 */  and       $v0, $v0, $s5
/* 2EE80 80053A80 00431821 */  addu      $v1, $v0, $v1
/* 2EE84 80053A84 AFA30018 */  sw        $v1, 0x18($sp)
/* 2EE88 80053A88 8C820004 */  lw        $v0, 4($a0)
/* 2EE8C 80053A8C AFA2001C */  sw        $v0, 0x1c($sp)
/* 2EE90 80053A90 00021602 */  srl       $v0, $v0, 0x18
/* 2EE94 80053A94 545E0005 */  bnel      $v0, $fp, .L80053AAC
/* 2EE98 80053A98 26100001 */   addiu    $s0, $s0, 1
/* 2EE9C 80053A9C 0060202D */  daddu     $a0, $v1, $zero
/* 2EEA0 80053AA0 0C01523F */  jal       func_800548FC
/* 2EEA4 80053AA4 0200282D */   daddu    $a1, $s0, $zero
/* 2EEA8 80053AA8 26100001 */  addiu     $s0, $s0, 1
.L80053AAC:
/* 2EEAC 80053AAC 2A020003 */  slti      $v0, $s0, 3
/* 2EEB0 80053AB0 1440FFEA */  bnez      $v0, .L80053A5C
/* 2EEB4 80053AB4 26310002 */   addiu    $s1, $s1, 2
/* 2EEB8 80053AB8 96820000 */  lhu       $v0, ($s4)
/* 2EEBC 80053ABC AE760028 */  sw        $s6, 0x28($s3)
/* 2EEC0 80053AC0 8FA7004C */  lw        $a3, 0x4c($sp)
/* 2EEC4 80053AC4 AE670064 */  sw        $a3, 0x64($s3)
/* 2EEC8 80053AC8 AE620024 */  sw        $v0, 0x24($s3)
/* 2EECC 80053ACC 08014EB6 */  j         .L80053AD8
/* 2EED0 80053AD0 8EE20008 */   lw       $v0, 8($s7)
.L80053AD4:
/* 2EED4 80053AD4 24020097 */  addiu     $v0, $zero, 0x97
.L80053AD8:
/* 2EED8 80053AD8 8FBF0044 */  lw        $ra, 0x44($sp)
/* 2EEDC 80053ADC 8FBE0040 */  lw        $fp, 0x40($sp)
/* 2EEE0 80053AE0 8FB7003C */  lw        $s7, 0x3c($sp)
/* 2EEE4 80053AE4 8FB60038 */  lw        $s6, 0x38($sp)
/* 2EEE8 80053AE8 8FB50034 */  lw        $s5, 0x34($sp)
/* 2EEEC 80053AEC 8FB40030 */  lw        $s4, 0x30($sp)
/* 2EEF0 80053AF0 8FB3002C */  lw        $s3, 0x2c($sp)
/* 2EEF4 80053AF4 8FB20028 */  lw        $s2, 0x28($sp)
/* 2EEF8 80053AF8 8FB10024 */  lw        $s1, 0x24($sp)
/* 2EEFC 80053AFC 8FB00020 */  lw        $s0, 0x20($sp)
/* 2EF00 80053B00 03E00008 */  jr        $ra
/* 2EF04 80053B04 27BD0048 */   addiu    $sp, $sp, 0x48
