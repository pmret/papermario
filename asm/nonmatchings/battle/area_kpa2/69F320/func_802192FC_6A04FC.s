.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802192FC_6A04FC
/* 6A04FC 802192FC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 6A0500 80219300 AFB00010 */  sw        $s0, 0x10($sp)
/* 6A0504 80219304 0080802D */  daddu     $s0, $a0, $zero
/* 6A0508 80219308 10A0000E */  beqz      $a1, .L80219344
/* 6A050C 8021930C AFBF0014 */   sw       $ra, 0x14($sp)
/* 6A0510 80219310 0C04760B */  jal       func_8011D82C
/* 6A0514 80219314 24040001 */   addiu    $a0, $zero, 1
/* 6A0518 80219318 0000202D */  daddu     $a0, $zero, $zero
/* 6A051C 8021931C 0080282D */  daddu     $a1, $a0, $zero
/* 6A0520 80219320 0080302D */  daddu     $a2, $a0, $zero
/* 6A0524 80219324 0080382D */  daddu     $a3, $a0, $zero
/* 6A0528 80219328 3C028015 */  lui       $v0, %hi(D_801512F0)
/* 6A052C 8021932C 8C4212F0 */  lw        $v0, %lo(D_801512F0)($v0)
/* 6A0530 80219330 24030001 */  addiu     $v1, $zero, 1
/* 6A0534 80219334 0C046F97 */  jal       set_background_color_blend
/* 6A0538 80219338 A0430000 */   sb       $v1, ($v0)
/* 6A053C 8021933C 24020014 */  addiu     $v0, $zero, 0x14
/* 6A0540 80219340 AE020070 */  sw        $v0, 0x70($s0)
.L80219344:
/* 6A0544 80219344 0000202D */  daddu     $a0, $zero, $zero
/* 6A0548 80219348 0080282D */  daddu     $a1, $a0, $zero
/* 6A054C 8021934C 0080302D */  daddu     $a2, $a0, $zero
/* 6A0550 80219350 8E030070 */  lw        $v1, 0x70($s0)
/* 6A0554 80219354 24020014 */  addiu     $v0, $zero, 0x14
/* 6A0558 80219358 00431023 */  subu      $v0, $v0, $v1
/* 6A055C 8021935C 00023880 */  sll       $a3, $v0, 2
/* 6A0560 80219360 00E23821 */  addu      $a3, $a3, $v0
/* 6A0564 80219364 00073840 */  sll       $a3, $a3, 1
/* 6A0568 80219368 0C046F97 */  jal       set_background_color_blend
/* 6A056C 8021936C 30E700FE */   andi     $a3, $a3, 0xfe
/* 6A0570 80219370 8E020070 */  lw        $v0, 0x70($s0)
/* 6A0574 80219374 2442FFFF */  addiu     $v0, $v0, -1
/* 6A0578 80219378 AE020070 */  sw        $v0, 0x70($s0)
/* 6A057C 8021937C 2C420001 */  sltiu     $v0, $v0, 1
/* 6A0580 80219380 8FBF0014 */  lw        $ra, 0x14($sp)
/* 6A0584 80219384 8FB00010 */  lw        $s0, 0x10($sp)
/* 6A0588 80219388 00021040 */  sll       $v0, $v0, 1
/* 6A058C 8021938C 03E00008 */  jr        $ra
/* 6A0590 80219390 27BD0018 */   addiu    $sp, $sp, 0x18
