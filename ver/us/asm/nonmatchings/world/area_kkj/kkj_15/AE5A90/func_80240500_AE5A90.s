.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240500_AE5A90
/* AE5A90 80240500 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* AE5A94 80240504 AFB1002C */  sw        $s1, 0x2c($sp)
/* AE5A98 80240508 0080882D */  daddu     $s1, $a0, $zero
/* AE5A9C 8024050C AFBF0034 */  sw        $ra, 0x34($sp)
/* AE5AA0 80240510 AFB20030 */  sw        $s2, 0x30($sp)
/* AE5AA4 80240514 AFB00028 */  sw        $s0, 0x28($sp)
/* AE5AA8 80240518 8E30000C */  lw        $s0, 0xc($s1)
/* AE5AAC 8024051C 8E050000 */  lw        $a1, ($s0)
/* AE5AB0 80240520 0C0B1EAF */  jal       evt_get_variable
/* AE5AB4 80240524 26100004 */   addiu    $s0, $s0, 4
/* AE5AB8 80240528 8E050000 */  lw        $a1, ($s0)
/* AE5ABC 8024052C 26100004 */  addiu     $s0, $s0, 4
/* AE5AC0 80240530 0220202D */  daddu     $a0, $s1, $zero
/* AE5AC4 80240534 0C0B1EAF */  jal       evt_get_variable
/* AE5AC8 80240538 0040902D */   daddu    $s2, $v0, $zero
/* AE5ACC 8024053C 0220202D */  daddu     $a0, $s1, $zero
/* AE5AD0 80240540 8E050000 */  lw        $a1, ($s0)
/* AE5AD4 80240544 0C0B1EAF */  jal       evt_get_variable
/* AE5AD8 80240548 0040802D */   daddu    $s0, $v0, $zero
/* AE5ADC 8024054C 0000202D */  daddu     $a0, $zero, $zero
/* AE5AE0 80240550 24050005 */  addiu     $a1, $zero, 5
/* AE5AE4 80240554 44820000 */  mtc1      $v0, $f0
/* AE5AE8 80240558 00000000 */  nop
/* AE5AEC 8024055C 46800020 */  cvt.s.w   $f0, $f0
/* AE5AF0 80240560 44921000 */  mtc1      $s2, $f2
/* AE5AF4 80240564 00000000 */  nop
/* AE5AF8 80240568 468010A0 */  cvt.s.w   $f2, $f2
/* AE5AFC 8024056C 44061000 */  mfc1      $a2, $f2
/* AE5B00 80240570 44901000 */  mtc1      $s0, $f2
/* AE5B04 80240574 00000000 */  nop
/* AE5B08 80240578 468010A0 */  cvt.s.w   $f2, $f2
/* AE5B0C 8024057C E7A00010 */  swc1      $f0, 0x10($sp)
/* AE5B10 80240580 3C0138D1 */  lui       $at, 0x38d1
/* AE5B14 80240584 3421B717 */  ori       $at, $at, 0xb717
/* AE5B18 80240588 44810000 */  mtc1      $at, $f0
/* AE5B1C 8024058C 44071000 */  mfc1      $a3, $f2
/* AE5B20 80240590 240200FF */  addiu     $v0, $zero, 0xff
/* AE5B24 80240594 AFA20014 */  sw        $v0, 0x14($sp)
/* AE5B28 80240598 AFA20018 */  sw        $v0, 0x18($sp)
/* AE5B2C 8024059C AFA2001C */  sw        $v0, 0x1c($sp)
/* AE5B30 802405A0 AFA00024 */  sw        $zero, 0x24($sp)
/* AE5B34 802405A4 0C052055 */  jal       sprite_shading_set_light_source
/* AE5B38 802405A8 E7A00020 */   swc1     $f0, 0x20($sp)
/* AE5B3C 802405AC 8FBF0034 */  lw        $ra, 0x34($sp)
/* AE5B40 802405B0 8FB20030 */  lw        $s2, 0x30($sp)
/* AE5B44 802405B4 8FB1002C */  lw        $s1, 0x2c($sp)
/* AE5B48 802405B8 8FB00028 */  lw        $s0, 0x28($sp)
/* AE5B4C 802405BC 24020002 */  addiu     $v0, $zero, 2
/* AE5B50 802405C0 03E00008 */  jr        $ra
/* AE5B54 802405C4 27BD0038 */   addiu    $sp, $sp, 0x38
/* AE5B58 802405C8 00000000 */  nop
/* AE5B5C 802405CC 00000000 */  nop
