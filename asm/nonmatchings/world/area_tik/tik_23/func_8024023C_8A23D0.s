.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024023C_8A260C
/* 8A260C 8024023C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 8A2610 80240240 AFB00018 */  sw        $s0, 0x18($sp)
/* 8A2614 80240244 0080802D */  daddu     $s0, $a0, $zero
/* 8A2618 80240248 AFBF001C */  sw        $ra, 0x1c($sp)
/* 8A261C 8024024C F7B40020 */  sdc1      $f20, 0x20($sp)
/* 8A2620 80240250 8E02000C */  lw        $v0, 0xc($s0)
/* 8A2624 80240254 0C0B210B */  jal       get_float_variable
/* 8A2628 80240258 8C450000 */   lw       $a1, ($v0)
/* 8A262C 8024025C 27A40010 */  addiu     $a0, $sp, 0x10
/* 8A2630 80240260 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* 8A2634 80240264 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* 8A2638 80240268 44060000 */  mfc1      $a2, $f0
/* 8A263C 8024026C C4400028 */  lwc1      $f0, 0x28($v0)
/* 8A2640 80240270 C4420030 */  lwc1      $f2, 0x30($v0)
/* 8A2644 80240274 E7A00010 */  swc1      $f0, 0x10($sp)
/* 8A2648 80240278 E7A20014 */  swc1      $f2, 0x14($sp)
/* 8A264C 8024027C 8C470080 */  lw        $a3, 0x80($v0)
/* 8A2650 80240280 C454002C */  lwc1      $f20, 0x2c($v0)
/* 8A2654 80240284 0C00A7E7 */  jal       add_vec2D_polar
/* 8A2658 80240288 27A50014 */   addiu    $a1, $sp, 0x14
/* 8A265C 8024028C 0200202D */  daddu     $a0, $s0, $zero
/* 8A2660 80240290 3C05FE36 */  lui       $a1, 0xfe36
/* 8A2664 80240294 8FA60010 */  lw        $a2, 0x10($sp)
/* 8A2668 80240298 0C0B2190 */  jal       set_float_variable
/* 8A266C 8024029C 34A53C80 */   ori      $a1, $a1, 0x3c80
/* 8A2670 802402A0 0200202D */  daddu     $a0, $s0, $zero
/* 8A2674 802402A4 3C05FE36 */  lui       $a1, 0xfe36
/* 8A2678 802402A8 4406A000 */  mfc1      $a2, $f20
/* 8A267C 802402AC 0C0B2190 */  jal       set_float_variable
/* 8A2680 802402B0 34A53C81 */   ori      $a1, $a1, 0x3c81
/* 8A2684 802402B4 0200202D */  daddu     $a0, $s0, $zero
/* 8A2688 802402B8 3C05FE36 */  lui       $a1, 0xfe36
/* 8A268C 802402BC 8FA60014 */  lw        $a2, 0x14($sp)
/* 8A2690 802402C0 0C0B2190 */  jal       set_float_variable
/* 8A2694 802402C4 34A53C82 */   ori      $a1, $a1, 0x3c82
/* 8A2698 802402C8 8FBF001C */  lw        $ra, 0x1c($sp)
/* 8A269C 802402CC 8FB00018 */  lw        $s0, 0x18($sp)
/* 8A26A0 802402D0 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 8A26A4 802402D4 24020002 */  addiu     $v0, $zero, 2
/* 8A26A8 802402D8 03E00008 */  jr        $ra
/* 8A26AC 802402DC 27BD0028 */   addiu    $sp, $sp, 0x28
