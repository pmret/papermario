.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_85_main
/* 3AA920 E00AA000 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 3AA924 E00AA004 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 3AA928 E00AA008 4485A000 */  mtc1      $a1, $f20
/* 3AA92C E00AA00C AFB1002C */  sw        $s1, 0x2c($sp)
/* 3AA930 E00AA010 0080882D */  daddu     $s1, $a0, $zero
/* 3AA934 E00AA014 F7B60040 */  sdc1      $f22, 0x40($sp)
/* 3AA938 E00AA018 4486B000 */  mtc1      $a2, $f22
/* 3AA93C E00AA01C 27A40010 */  addiu     $a0, $sp, 0x10
/* 3AA940 E00AA020 F7B80048 */  sdc1      $f24, 0x48($sp)
/* 3AA944 E00AA024 4487C000 */  mtc1      $a3, $f24
/* 3AA948 E00AA028 3C02E00B */  lui       $v0, %hi(fx_85_init)
/* 3AA94C E00AA02C 2442A104 */  addiu     $v0, $v0, %lo(fx_85_init)
/* 3AA950 E00AA030 AFA20018 */  sw        $v0, 0x18($sp)
/* 3AA954 E00AA034 3C02E00B */  lui       $v0, %hi(fx_85_update)
/* 3AA958 E00AA038 2442A10C */  addiu     $v0, $v0, %lo(fx_85_update)
/* 3AA95C E00AA03C AFA2001C */  sw        $v0, 0x1c($sp)
/* 3AA960 E00AA040 3C02E00B */  lui       $v0, %hi(fx_85_render)
/* 3AA964 E00AA044 2442A3C0 */  addiu     $v0, $v0, %lo(fx_85_render)
/* 3AA968 E00AA048 AFA20020 */  sw        $v0, 0x20($sp)
/* 3AA96C E00AA04C 24020055 */  addiu     $v0, $zero, 0x55
/* 3AA970 E00AA050 AFBF0030 */  sw        $ra, 0x30($sp)
/* 3AA974 E00AA054 AFB00028 */  sw        $s0, 0x28($sp)
/* 3AA978 E00AA058 AFA00010 */  sw        $zero, 0x10($sp)
/* 3AA97C E00AA05C AFA00024 */  sw        $zero, 0x24($sp)
/* 3AA980 E00AA060 0C080124 */  jal       shim_create_effect_instance
/* 3AA984 E00AA064 AFA20014 */   sw       $v0, 0x14($sp)
/* 3AA988 E00AA068 24040048 */  addiu     $a0, $zero, 0x48
/* 3AA98C E00AA06C 24030001 */  addiu     $v1, $zero, 1
/* 3AA990 E00AA070 0040802D */  daddu     $s0, $v0, $zero
/* 3AA994 E00AA074 0C08012C */  jal       shim_general_heap_malloc
/* 3AA998 E00AA078 AE030008 */   sw       $v1, 8($s0)
/* 3AA99C E00AA07C 0040202D */  daddu     $a0, $v0, $zero
/* 3AA9A0 E00AA080 14800003 */  bnez      $a0, .LE00AA090
/* 3AA9A4 E00AA084 AE02000C */   sw       $v0, 0xc($s0)
.LE00AA088:
/* 3AA9A8 E00AA088 0802A822 */  j         .LE00AA088
/* 3AA9AC E00AA08C 00000000 */   nop
.LE00AA090:
/* 3AA9B0 E00AA090 0200102D */  daddu     $v0, $s0, $zero
/* 3AA9B4 E00AA094 3C014248 */  lui       $at, 0x4248
/* 3AA9B8 E00AA098 44810000 */  mtc1      $at, $f0
/* 3AA9BC E00AA09C 3C0141F0 */  lui       $at, 0x41f0
/* 3AA9C0 E00AA0A0 44811000 */  mtc1      $at, $f2
/* 3AA9C4 E00AA0A4 240303E8 */  addiu     $v1, $zero, 0x3e8
/* 3AA9C8 E00AA0A8 AC830004 */  sw        $v1, 4($a0)
/* 3AA9CC E00AA0AC 240300FF */  addiu     $v1, $zero, 0xff
/* 3AA9D0 E00AA0B0 AC910000 */  sw        $s1, ($a0)
/* 3AA9D4 E00AA0B4 AC830024 */  sw        $v1, 0x24($a0)
/* 3AA9D8 E00AA0B8 E494000C */  swc1      $f20, 0xc($a0)
/* 3AA9DC E00AA0BC E4940018 */  swc1      $f20, 0x18($a0)
/* 3AA9E0 E00AA0C0 E4960010 */  swc1      $f22, 0x10($a0)
/* 3AA9E4 E00AA0C4 E496001C */  swc1      $f22, 0x1c($a0)
/* 3AA9E8 E00AA0C8 E4980014 */  swc1      $f24, 0x14($a0)
/* 3AA9EC E00AA0CC E4980020 */  swc1      $f24, 0x20($a0)
/* 3AA9F0 E00AA0D0 AC800008 */  sw        $zero, 8($a0)
/* 3AA9F4 E00AA0D4 AC80002C */  sw        $zero, 0x2c($a0)
/* 3AA9F8 E00AA0D8 AC800030 */  sw        $zero, 0x30($a0)
/* 3AA9FC E00AA0DC E4800034 */  swc1      $f0, 0x34($a0)
/* 3AAA00 E00AA0E0 E4820038 */  swc1      $f2, 0x38($a0)
/* 3AAA04 E00AA0E4 8FBF0030 */  lw        $ra, 0x30($sp)
/* 3AAA08 E00AA0E8 8FB1002C */  lw        $s1, 0x2c($sp)
/* 3AAA0C E00AA0EC 8FB00028 */  lw        $s0, 0x28($sp)
/* 3AAA10 E00AA0F0 D7B80048 */  ldc1      $f24, 0x48($sp)
/* 3AAA14 E00AA0F4 D7B60040 */  ldc1      $f22, 0x40($sp)
/* 3AAA18 E00AA0F8 D7B40038 */  ldc1      $f20, 0x38($sp)
/* 3AAA1C E00AA0FC 03E00008 */  jr        $ra
/* 3AAA20 E00AA100 27BD0050 */   addiu    $sp, $sp, 0x50
