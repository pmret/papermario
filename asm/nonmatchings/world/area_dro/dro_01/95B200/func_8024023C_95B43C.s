.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024023C_95B43C
/* 95B43C 8024023C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 95B440 80240240 AFB00018 */  sw        $s0, 0x18($sp)
/* 95B444 80240244 0080802D */  daddu     $s0, $a0, $zero
/* 95B448 80240248 AFBF001C */  sw        $ra, 0x1c($sp)
/* 95B44C 8024024C F7B40020 */  sdc1      $f20, 0x20($sp)
/* 95B450 80240250 8E02000C */  lw        $v0, 0xc($s0)
/* 95B454 80240254 0C0B210B */  jal       get_float_variable
/* 95B458 80240258 8C450000 */   lw       $a1, ($v0)
/* 95B45C 8024025C 27A40010 */  addiu     $a0, $sp, 0x10
/* 95B460 80240260 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* 95B464 80240264 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* 95B468 80240268 44060000 */  mfc1      $a2, $f0
/* 95B46C 8024026C C4400028 */  lwc1      $f0, 0x28($v0)
/* 95B470 80240270 C4420030 */  lwc1      $f2, 0x30($v0)
/* 95B474 80240274 E7A00010 */  swc1      $f0, 0x10($sp)
/* 95B478 80240278 E7A20014 */  swc1      $f2, 0x14($sp)
/* 95B47C 8024027C 8C470080 */  lw        $a3, 0x80($v0)
/* 95B480 80240280 C454002C */  lwc1      $f20, 0x2c($v0)
/* 95B484 80240284 0C00A7E7 */  jal       add_vec2D_polar
/* 95B488 80240288 27A50014 */   addiu    $a1, $sp, 0x14
/* 95B48C 8024028C 0200202D */  daddu     $a0, $s0, $zero
/* 95B490 80240290 3C05FE36 */  lui       $a1, 0xfe36
/* 95B494 80240294 8FA60010 */  lw        $a2, 0x10($sp)
/* 95B498 80240298 0C0B2190 */  jal       set_float_variable
/* 95B49C 8024029C 34A53C80 */   ori      $a1, $a1, 0x3c80
/* 95B4A0 802402A0 0200202D */  daddu     $a0, $s0, $zero
/* 95B4A4 802402A4 3C05FE36 */  lui       $a1, 0xfe36
/* 95B4A8 802402A8 4406A000 */  mfc1      $a2, $f20
/* 95B4AC 802402AC 0C0B2190 */  jal       set_float_variable
/* 95B4B0 802402B0 34A53C81 */   ori      $a1, $a1, 0x3c81
/* 95B4B4 802402B4 0200202D */  daddu     $a0, $s0, $zero
/* 95B4B8 802402B8 3C05FE36 */  lui       $a1, 0xfe36
/* 95B4BC 802402BC 8FA60014 */  lw        $a2, 0x14($sp)
/* 95B4C0 802402C0 0C0B2190 */  jal       set_float_variable
/* 95B4C4 802402C4 34A53C82 */   ori      $a1, $a1, 0x3c82
/* 95B4C8 802402C8 8FBF001C */  lw        $ra, 0x1c($sp)
/* 95B4CC 802402CC 8FB00018 */  lw        $s0, 0x18($sp)
/* 95B4D0 802402D0 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 95B4D4 802402D4 24020002 */  addiu     $v0, $zero, 2
/* 95B4D8 802402D8 03E00008 */  jr        $ra
/* 95B4DC 802402DC 27BD0028 */   addiu    $sp, $sp, 0x28
