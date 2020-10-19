.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240548_89A898
/* 89A898 80240548 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 89A89C 8024054C AFB00018 */  sw        $s0, 0x18($sp)
/* 89A8A0 80240550 0080802D */  daddu     $s0, $a0, $zero
/* 89A8A4 80240554 AFBF001C */  sw        $ra, 0x1c($sp)
/* 89A8A8 80240558 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 89A8AC 8024055C 8E02000C */  lw        $v0, 0xc($s0)
/* 89A8B0 80240560 0C0B210B */  jal       get_float_variable
/* 89A8B4 80240564 8C450000 */   lw       $a1, ($v0)
/* 89A8B8 80240568 27A40010 */  addiu     $a0, $sp, 0x10
/* 89A8BC 8024056C 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* 89A8C0 80240570 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* 89A8C4 80240574 44060000 */  mfc1      $a2, $f0
/* 89A8C8 80240578 C4400028 */  lwc1      $f0, 0x28($v0)
/* 89A8CC 8024057C C4420030 */  lwc1      $f2, 0x30($v0)
/* 89A8D0 80240580 E7A00010 */  swc1      $f0, 0x10($sp)
/* 89A8D4 80240584 E7A20014 */  swc1      $f2, 0x14($sp)
/* 89A8D8 80240588 8C470080 */  lw        $a3, 0x80($v0)
/* 89A8DC 8024058C C454002C */  lwc1      $f20, 0x2c($v0)
/* 89A8E0 80240590 0C00A7E7 */  jal       add_vec2D_polar
/* 89A8E4 80240594 27A50014 */   addiu    $a1, $sp, 0x14
/* 89A8E8 80240598 0200202D */  daddu     $a0, $s0, $zero
/* 89A8EC 8024059C 3C05FE36 */  lui       $a1, 0xfe36
/* 89A8F0 802405A0 8FA60010 */  lw        $a2, 0x10($sp)
/* 89A8F4 802405A4 0C0B2190 */  jal       set_float_variable
/* 89A8F8 802405A8 34A53C80 */   ori      $a1, $a1, 0x3c80
/* 89A8FC 802405AC 0200202D */  daddu     $a0, $s0, $zero
/* 89A900 802405B0 3C05FE36 */  lui       $a1, 0xfe36
/* 89A904 802405B4 4406A000 */  mfc1      $a2, $f20
/* 89A908 802405B8 0C0B2190 */  jal       set_float_variable
/* 89A90C 802405BC 34A53C81 */   ori      $a1, $a1, 0x3c81
/* 89A910 802405C0 0200202D */  daddu     $a0, $s0, $zero
/* 89A914 802405C4 3C05FE36 */  lui       $a1, 0xfe36
/* 89A918 802405C8 8FA60014 */  lw        $a2, 0x14($sp)
/* 89A91C 802405CC 0C0B2190 */  jal       set_float_variable
/* 89A920 802405D0 34A53C82 */   ori      $a1, $a1, 0x3c82
/* 89A924 802405D4 8FBF001C */  lw        $ra, 0x1c($sp)
/* 89A928 802405D8 8FB00018 */  lw        $s0, 0x18($sp)
/* 89A92C 802405DC D7B40020 */  ldc1      $f20, 0x20($sp)
/* 89A930 802405E0 24020002 */  addiu     $v0, $zero, 2
/* 89A934 802405E4 03E00008 */  jr        $ra
/* 89A938 802405E8 27BD0028 */   addiu    $sp, $sp, 0x28
