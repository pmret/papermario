.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219490_4B2680
/* 4B2680 80219490 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4B2684 80219494 AFB00010 */  sw        $s0, 0x10($sp)
/* 4B2688 80219498 0080802D */  daddu     $s0, $a0, $zero
/* 4B268C 8021949C AFBF0014 */  sw        $ra, 0x14($sp)
/* 4B2690 802194A0 0C09A75B */  jal       get_actor
/* 4B2694 802194A4 24040200 */   addiu    $a0, $zero, 0x200
/* 4B2698 802194A8 0040202D */  daddu     $a0, $v0, $zero
/* 4B269C 802194AC 10800004 */  beqz      $a0, .L802194C0
/* 4B26A0 802194B0 00000000 */   nop
/* 4B26A4 802194B4 8C82008C */  lw        $v0, 0x8c($a0)
/* 4B26A8 802194B8 10500019 */  beq       $v0, $s0, .L80219520
/* 4B26AC 802194BC 0080102D */   daddu    $v0, $a0, $zero
.L802194C0:
/* 4B26B0 802194C0 0C09A75B */  jal       get_actor
/* 4B26B4 802194C4 24040201 */   addiu    $a0, $zero, 0x201
/* 4B26B8 802194C8 0040202D */  daddu     $a0, $v0, $zero
/* 4B26BC 802194CC 10800004 */  beqz      $a0, .L802194E0
/* 4B26C0 802194D0 00000000 */   nop
/* 4B26C4 802194D4 8C82008C */  lw        $v0, 0x8c($a0)
/* 4B26C8 802194D8 10500011 */  beq       $v0, $s0, .L80219520
/* 4B26CC 802194DC 0080102D */   daddu    $v0, $a0, $zero
.L802194E0:
/* 4B26D0 802194E0 0C09A75B */  jal       get_actor
/* 4B26D4 802194E4 24040202 */   addiu    $a0, $zero, 0x202
/* 4B26D8 802194E8 0040202D */  daddu     $a0, $v0, $zero
/* 4B26DC 802194EC 10800004 */  beqz      $a0, .L80219500
/* 4B26E0 802194F0 00000000 */   nop
/* 4B26E4 802194F4 8C82008C */  lw        $v0, 0x8c($a0)
/* 4B26E8 802194F8 10500009 */  beq       $v0, $s0, .L80219520
/* 4B26EC 802194FC 0080102D */   daddu    $v0, $a0, $zero
.L80219500:
/* 4B26F0 80219500 0C09A75B */  jal       get_actor
/* 4B26F4 80219504 24040203 */   addiu    $a0, $zero, 0x203
/* 4B26F8 80219508 0040202D */  daddu     $a0, $v0, $zero
/* 4B26FC 8021950C 50800004 */  beql      $a0, $zero, .L80219520
/* 4B2700 80219510 0000102D */   daddu    $v0, $zero, $zero
/* 4B2704 80219514 8C83008C */  lw        $v1, 0x8c($a0)
/* 4B2708 80219518 54700001 */  bnel      $v1, $s0, .L80219520
/* 4B270C 8021951C 0000102D */   daddu    $v0, $zero, $zero
.L80219520:
/* 4B2710 80219520 8FBF0014 */  lw        $ra, 0x14($sp)
/* 4B2714 80219524 8FB00010 */  lw        $s0, 0x10($sp)
/* 4B2718 80219528 03E00008 */  jr        $ra
/* 4B271C 8021952C 27BD0018 */   addiu    $sp, $sp, 0x18
