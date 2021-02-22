.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802193B8_4B25A8
/* 4B25A8 802193B8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 4B25AC 802193BC AFB10014 */  sw        $s1, 0x14($sp)
/* 4B25B0 802193C0 0080882D */  daddu     $s1, $a0, $zero
/* 4B25B4 802193C4 AFBF0020 */  sw        $ra, 0x20($sp)
/* 4B25B8 802193C8 AFB3001C */  sw        $s3, 0x1c($sp)
/* 4B25BC 802193CC AFB20018 */  sw        $s2, 0x18($sp)
/* 4B25C0 802193D0 AFB00010 */  sw        $s0, 0x10($sp)
/* 4B25C4 802193D4 8E30000C */  lw        $s0, 0xc($s1)
/* 4B25C8 802193D8 8E050000 */  lw        $a1, ($s0)
/* 4B25CC 802193DC 0C0B1EAF */  jal       get_variable
/* 4B25D0 802193E0 26100004 */   addiu    $s0, $s0, 4
/* 4B25D4 802193E4 8E050000 */  lw        $a1, ($s0)
/* 4B25D8 802193E8 26100004 */  addiu     $s0, $s0, 4
/* 4B25DC 802193EC 0220202D */  daddu     $a0, $s1, $zero
/* 4B25E0 802193F0 0C0B1EAF */  jal       get_variable
/* 4B25E4 802193F4 0040982D */   daddu    $s3, $v0, $zero
/* 4B25E8 802193F8 8E050000 */  lw        $a1, ($s0)
/* 4B25EC 802193FC 26100004 */  addiu     $s0, $s0, 4
/* 4B25F0 80219400 0220202D */  daddu     $a0, $s1, $zero
/* 4B25F4 80219404 0C0B1EAF */  jal       get_variable
/* 4B25F8 80219408 0040902D */   daddu    $s2, $v0, $zero
/* 4B25FC 8021940C 0220202D */  daddu     $a0, $s1, $zero
/* 4B2600 80219410 8E050000 */  lw        $a1, ($s0)
/* 4B2604 80219414 0C0B1EAF */  jal       get_variable
/* 4B2608 80219418 0040802D */   daddu    $s0, $v0, $zero
/* 4B260C 8021941C 24040006 */  addiu     $a0, $zero, 6
/* 4B2610 80219420 3C058023 */  lui       $a1, %hi(D_80236560)
/* 4B2614 80219424 24A56560 */  addiu     $a1, $a1, %lo(D_80236560)
/* 4B2618 80219428 44930000 */  mtc1      $s3, $f0
/* 4B261C 8021942C 00000000 */  nop
/* 4B2620 80219430 46800020 */  cvt.s.w   $f0, $f0
/* 4B2624 80219434 E4A00028 */  swc1      $f0, 0x28($a1)
/* 4B2628 80219438 44920000 */  mtc1      $s2, $f0
/* 4B262C 8021943C 00000000 */  nop
/* 4B2630 80219440 46800020 */  cvt.s.w   $f0, $f0
/* 4B2634 80219444 0040382D */  daddu     $a3, $v0, $zero
/* 4B2638 80219448 3C014120 */  lui       $at, 0x4120
/* 4B263C 8021944C 44811000 */  mtc1      $at, $f2
/* 4B2640 80219450 3C063F80 */  lui       $a2, 0x3f80
/* 4B2644 80219454 46020001 */  sub.s     $f0, $f0, $f2
/* 4B2648 80219458 44901000 */  mtc1      $s0, $f2
/* 4B264C 8021945C 00000000 */  nop
/* 4B2650 80219460 468010A0 */  cvt.s.w   $f2, $f2
/* 4B2654 80219464 E4A20030 */  swc1      $f2, 0x30($a1)
/* 4B2658 80219468 0C01C4B4 */  jal       func_800712D0
/* 4B265C 8021946C E4A0002C */   swc1     $f0, 0x2c($a1)
/* 4B2660 80219470 8FBF0020 */  lw        $ra, 0x20($sp)
/* 4B2664 80219474 8FB3001C */  lw        $s3, 0x1c($sp)
/* 4B2668 80219478 8FB20018 */  lw        $s2, 0x18($sp)
/* 4B266C 8021947C 8FB10014 */  lw        $s1, 0x14($sp)
/* 4B2670 80219480 8FB00010 */  lw        $s0, 0x10($sp)
/* 4B2674 80219484 24020002 */  addiu     $v0, $zero, 2
/* 4B2678 80219488 03E00008 */  jr        $ra
/* 4B267C 8021948C 27BD0028 */   addiu    $sp, $sp, 0x28
