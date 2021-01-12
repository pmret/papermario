.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8027D4C8
/* 1ABDA8 8027D4C8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 1ABDAC 8027D4CC AFB3001C */  sw        $s3, 0x1c($sp)
/* 1ABDB0 8027D4D0 0080982D */  daddu     $s3, $a0, $zero
/* 1ABDB4 8027D4D4 AFBF0020 */  sw        $ra, 0x20($sp)
/* 1ABDB8 8027D4D8 AFB20018 */  sw        $s2, 0x18($sp)
/* 1ABDBC 8027D4DC AFB10014 */  sw        $s1, 0x14($sp)
/* 1ABDC0 8027D4E0 AFB00010 */  sw        $s0, 0x10($sp)
/* 1ABDC4 8027D4E4 8E72000C */  lw        $s2, 0xc($s3)
/* 1ABDC8 8027D4E8 8E450000 */  lw        $a1, ($s2)
/* 1ABDCC 8027D4EC 0C0B1EAF */  jal       get_variable
/* 1ABDD0 8027D4F0 26520004 */   addiu    $s2, $s2, 4
/* 1ABDD4 8027D4F4 0040802D */  daddu     $s0, $v0, $zero
/* 1ABDD8 8027D4F8 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 1ABDDC 8027D4FC 16020002 */  bne       $s0, $v0, .L8027D508
/* 1ABDE0 8027D500 00000000 */   nop
/* 1ABDE4 8027D504 8E700148 */  lw        $s0, 0x148($s3)
.L8027D508:
/* 1ABDE8 8027D508 8E450000 */  lw        $a1, ($s2)
/* 1ABDEC 8027D50C 26520004 */  addiu     $s2, $s2, 4
/* 1ABDF0 8027D510 0C0B1EAF */  jal       get_variable
/* 1ABDF4 8027D514 0260202D */   daddu    $a0, $s3, $zero
/* 1ABDF8 8027D518 0200202D */  daddu     $a0, $s0, $zero
/* 1ABDFC 8027D51C 0C09A75B */  jal       get_actor
/* 1ABE00 8027D520 0040802D */   daddu    $s0, $v0, $zero
/* 1ABE04 8027D524 0040202D */  daddu     $a0, $v0, $zero
/* 1ABE08 8027D528 0C099117 */  jal       get_actor_part
/* 1ABE0C 8027D52C 0200282D */   daddu    $a1, $s0, $zero
/* 1ABE10 8027D530 8E450000 */  lw        $a1, ($s2)
/* 1ABE14 8027D534 26520004 */  addiu     $s2, $s2, 4
/* 1ABE18 8027D538 0260202D */  daddu     $a0, $s3, $zero
/* 1ABE1C 8027D53C 0C0B1EAF */  jal       get_variable
/* 1ABE20 8027D540 0040882D */   daddu    $s1, $v0, $zero
/* 1ABE24 8027D544 0260202D */  daddu     $a0, $s3, $zero
/* 1ABE28 8027D548 8E450000 */  lw        $a1, ($s2)
/* 1ABE2C 8027D54C 0C0B1EAF */  jal       get_variable
/* 1ABE30 8027D550 0040802D */   daddu    $s0, $v0, $zero
/* 1ABE34 8027D554 A2220076 */  sb        $v0, 0x76($s1)
/* 1ABE38 8027D558 A2300075 */  sb        $s0, 0x75($s1)
/* 1ABE3C 8027D55C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 1ABE40 8027D560 8FB3001C */  lw        $s3, 0x1c($sp)
/* 1ABE44 8027D564 8FB20018 */  lw        $s2, 0x18($sp)
/* 1ABE48 8027D568 8FB10014 */  lw        $s1, 0x14($sp)
/* 1ABE4C 8027D56C 8FB00010 */  lw        $s0, 0x10($sp)
/* 1ABE50 8027D570 24020002 */  addiu     $v0, $zero, 2
/* 1ABE54 8027D574 03E00008 */  jr        $ra
/* 1ABE58 8027D578 27BD0028 */   addiu    $sp, $sp, 0x28
