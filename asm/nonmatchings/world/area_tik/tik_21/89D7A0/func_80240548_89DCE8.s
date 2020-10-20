.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240548_89DCE8
/* 89DCE8 80240548 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 89DCEC 8024054C AFB00018 */  sw        $s0, 0x18($sp)
/* 89DCF0 80240550 0080802D */  daddu     $s0, $a0, $zero
/* 89DCF4 80240554 AFBF001C */  sw        $ra, 0x1c($sp)
/* 89DCF8 80240558 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 89DCFC 8024055C 8E02000C */  lw        $v0, 0xc($s0)
/* 89DD00 80240560 0C0B210B */  jal       get_float_variable
/* 89DD04 80240564 8C450000 */   lw       $a1, ($v0)
/* 89DD08 80240568 27A40010 */  addiu     $a0, $sp, 0x10
/* 89DD0C 8024056C 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* 89DD10 80240570 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* 89DD14 80240574 44060000 */  mfc1      $a2, $f0
/* 89DD18 80240578 C4400028 */  lwc1      $f0, 0x28($v0)
/* 89DD1C 8024057C C4420030 */  lwc1      $f2, 0x30($v0)
/* 89DD20 80240580 E7A00010 */  swc1      $f0, 0x10($sp)
/* 89DD24 80240584 E7A20014 */  swc1      $f2, 0x14($sp)
/* 89DD28 80240588 8C470080 */  lw        $a3, 0x80($v0)
/* 89DD2C 8024058C C454002C */  lwc1      $f20, 0x2c($v0)
/* 89DD30 80240590 0C00A7E7 */  jal       add_vec2D_polar
/* 89DD34 80240594 27A50014 */   addiu    $a1, $sp, 0x14
/* 89DD38 80240598 0200202D */  daddu     $a0, $s0, $zero
/* 89DD3C 8024059C 3C05FE36 */  lui       $a1, 0xfe36
/* 89DD40 802405A0 8FA60010 */  lw        $a2, 0x10($sp)
/* 89DD44 802405A4 0C0B2190 */  jal       set_float_variable
/* 89DD48 802405A8 34A53C80 */   ori      $a1, $a1, 0x3c80
/* 89DD4C 802405AC 0200202D */  daddu     $a0, $s0, $zero
/* 89DD50 802405B0 3C05FE36 */  lui       $a1, 0xfe36
/* 89DD54 802405B4 4406A000 */  mfc1      $a2, $f20
/* 89DD58 802405B8 0C0B2190 */  jal       set_float_variable
/* 89DD5C 802405BC 34A53C81 */   ori      $a1, $a1, 0x3c81
/* 89DD60 802405C0 0200202D */  daddu     $a0, $s0, $zero
/* 89DD64 802405C4 3C05FE36 */  lui       $a1, 0xfe36
/* 89DD68 802405C8 8FA60014 */  lw        $a2, 0x14($sp)
/* 89DD6C 802405CC 0C0B2190 */  jal       set_float_variable
/* 89DD70 802405D0 34A53C82 */   ori      $a1, $a1, 0x3c82
/* 89DD74 802405D4 8FBF001C */  lw        $ra, 0x1c($sp)
/* 89DD78 802405D8 8FB00018 */  lw        $s0, 0x18($sp)
/* 89DD7C 802405DC D7B40020 */  ldc1      $f20, 0x20($sp)
/* 89DD80 802405E0 24020002 */  addiu     $v0, $zero, 2
/* 89DD84 802405E4 03E00008 */  jr        $ra
/* 89DD88 802405E8 27BD0028 */   addiu    $sp, $sp, 0x28
