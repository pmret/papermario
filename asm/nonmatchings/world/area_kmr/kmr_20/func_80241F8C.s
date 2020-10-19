.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241F8C
/* 8EDDAC 80241F8C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 8EDDB0 80241F90 AFB00018 */  sw        $s0, 0x18($sp)
/* 8EDDB4 80241F94 0080802D */  daddu     $s0, $a0, $zero
/* 8EDDB8 80241F98 AFBF001C */  sw        $ra, 0x1c($sp)
/* 8EDDBC 80241F9C F7B40020 */  sdc1      $f20, 0x20($sp)
/* 8EDDC0 80241FA0 8E02000C */  lw        $v0, 0xc($s0)
/* 8EDDC4 80241FA4 0C0B210B */  jal       get_float_variable
/* 8EDDC8 80241FA8 8C450000 */   lw       $a1, ($v0)
/* 8EDDCC 80241FAC 27A40010 */  addiu     $a0, $sp, 0x10
/* 8EDDD0 80241FB0 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* 8EDDD4 80241FB4 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* 8EDDD8 80241FB8 44060000 */  mfc1      $a2, $f0
/* 8EDDDC 80241FBC C4400028 */  lwc1      $f0, 0x28($v0)
/* 8EDDE0 80241FC0 C4420030 */  lwc1      $f2, 0x30($v0)
/* 8EDDE4 80241FC4 E7A00010 */  swc1      $f0, 0x10($sp)
/* 8EDDE8 80241FC8 E7A20014 */  swc1      $f2, 0x14($sp)
/* 8EDDEC 80241FCC 8C470080 */  lw        $a3, 0x80($v0)
/* 8EDDF0 80241FD0 C454002C */  lwc1      $f20, 0x2c($v0)
/* 8EDDF4 80241FD4 0C00A7E7 */  jal       add_vec2D_polar
/* 8EDDF8 80241FD8 27A50014 */   addiu    $a1, $sp, 0x14
/* 8EDDFC 80241FDC 0200202D */  daddu     $a0, $s0, $zero
/* 8EDE00 80241FE0 3C05FE36 */  lui       $a1, 0xfe36
/* 8EDE04 80241FE4 8FA60010 */  lw        $a2, 0x10($sp)
/* 8EDE08 80241FE8 0C0B2190 */  jal       set_float_variable
/* 8EDE0C 80241FEC 34A53C80 */   ori      $a1, $a1, 0x3c80
/* 8EDE10 80241FF0 0200202D */  daddu     $a0, $s0, $zero
/* 8EDE14 80241FF4 3C05FE36 */  lui       $a1, 0xfe36
/* 8EDE18 80241FF8 4406A000 */  mfc1      $a2, $f20
/* 8EDE1C 80241FFC 0C0B2190 */  jal       set_float_variable
/* 8EDE20 80242000 34A53C81 */   ori      $a1, $a1, 0x3c81
/* 8EDE24 80242004 0200202D */  daddu     $a0, $s0, $zero
/* 8EDE28 80242008 3C05FE36 */  lui       $a1, 0xfe36
/* 8EDE2C 8024200C 8FA60014 */  lw        $a2, 0x14($sp)
/* 8EDE30 80242010 0C0B2190 */  jal       set_float_variable
/* 8EDE34 80242014 34A53C82 */   ori      $a1, $a1, 0x3c82
/* 8EDE38 80242018 8FBF001C */  lw        $ra, 0x1c($sp)
/* 8EDE3C 8024201C 8FB00018 */  lw        $s0, 0x18($sp)
/* 8EDE40 80242020 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 8EDE44 80242024 24020002 */  addiu     $v0, $zero, 2
/* 8EDE48 80242028 03E00008 */  jr        $ra
/* 8EDE4C 8024202C 27BD0028 */   addiu    $sp, $sp, 0x28
