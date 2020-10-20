.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240548
/* 8699F8 80240548 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 8699FC 8024054C AFB00018 */  sw        $s0, 0x18($sp)
/* 869A00 80240550 0080802D */  daddu     $s0, $a0, $zero
/* 869A04 80240554 AFBF001C */  sw        $ra, 0x1c($sp)
/* 869A08 80240558 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 869A0C 8024055C 8E02000C */  lw        $v0, 0xc($s0)
/* 869A10 80240560 0C0B210B */  jal       get_float_variable
/* 869A14 80240564 8C450000 */   lw       $a1, ($v0)
/* 869A18 80240568 27A40010 */  addiu     $a0, $sp, 0x10
/* 869A1C 8024056C 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* 869A20 80240570 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* 869A24 80240574 44060000 */  mfc1      $a2, $f0
/* 869A28 80240578 C4400028 */  lwc1      $f0, 0x28($v0)
/* 869A2C 8024057C C4420030 */  lwc1      $f2, 0x30($v0)
/* 869A30 80240580 E7A00010 */  swc1      $f0, 0x10($sp)
/* 869A34 80240584 E7A20014 */  swc1      $f2, 0x14($sp)
/* 869A38 80240588 8C470080 */  lw        $a3, 0x80($v0)
/* 869A3C 8024058C C454002C */  lwc1      $f20, 0x2c($v0)
/* 869A40 80240590 0C00A7E7 */  jal       add_vec2D_polar
/* 869A44 80240594 27A50014 */   addiu    $a1, $sp, 0x14
/* 869A48 80240598 0200202D */  daddu     $a0, $s0, $zero
/* 869A4C 8024059C 3C05FE36 */  lui       $a1, 0xfe36
/* 869A50 802405A0 8FA60010 */  lw        $a2, 0x10($sp)
/* 869A54 802405A4 0C0B2190 */  jal       set_float_variable
/* 869A58 802405A8 34A53C80 */   ori      $a1, $a1, 0x3c80
/* 869A5C 802405AC 0200202D */  daddu     $a0, $s0, $zero
/* 869A60 802405B0 3C05FE36 */  lui       $a1, 0xfe36
/* 869A64 802405B4 4406A000 */  mfc1      $a2, $f20
/* 869A68 802405B8 0C0B2190 */  jal       set_float_variable
/* 869A6C 802405BC 34A53C81 */   ori      $a1, $a1, 0x3c81
/* 869A70 802405C0 0200202D */  daddu     $a0, $s0, $zero
/* 869A74 802405C4 3C05FE36 */  lui       $a1, 0xfe36
/* 869A78 802405C8 8FA60014 */  lw        $a2, 0x14($sp)
/* 869A7C 802405CC 0C0B2190 */  jal       set_float_variable
/* 869A80 802405D0 34A53C82 */   ori      $a1, $a1, 0x3c82
/* 869A84 802405D4 8FBF001C */  lw        $ra, 0x1c($sp)
/* 869A88 802405D8 8FB00018 */  lw        $s0, 0x18($sp)
/* 869A8C 802405DC D7B40020 */  ldc1      $f20, 0x20($sp)
/* 869A90 802405E0 24020002 */  addiu     $v0, $zero, 2
/* 869A94 802405E4 03E00008 */  jr        $ra
/* 869A98 802405E8 27BD0028 */   addiu    $sp, $sp, 0x28
/* 869A9C 802405EC 00000000 */  nop       
