.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021900C_5B24BC
/* 5B24BC 8021900C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 5B24C0 80219010 AFB3001C */  sw        $s3, 0x1c($sp)
/* 5B24C4 80219014 0080982D */  daddu     $s3, $a0, $zero
/* 5B24C8 80219018 AFBF0020 */  sw        $ra, 0x20($sp)
/* 5B24CC 8021901C AFB20018 */  sw        $s2, 0x18($sp)
/* 5B24D0 80219020 AFB10014 */  sw        $s1, 0x14($sp)
/* 5B24D4 80219024 AFB00010 */  sw        $s0, 0x10($sp)
/* 5B24D8 80219028 8E70000C */  lw        $s0, 0xc($s3)
/* 5B24DC 8021902C 8E050000 */  lw        $a1, ($s0)
/* 5B24E0 80219030 0C0B1EAF */  jal       get_variable
/* 5B24E4 80219034 26100004 */   addiu    $s0, $s0, 4
/* 5B24E8 80219038 0040882D */  daddu     $s1, $v0, $zero
/* 5B24EC 8021903C 8E050000 */  lw        $a1, ($s0)
/* 5B24F0 80219040 26100004 */  addiu     $s0, $s0, 4
/* 5B24F4 80219044 0C0B1EAF */  jal       get_variable
/* 5B24F8 80219048 0260202D */   daddu    $a0, $s3, $zero
/* 5B24FC 8021904C 0040902D */  daddu     $s2, $v0, $zero
/* 5B2500 80219050 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 5B2504 80219054 16220002 */  bne       $s1, $v0, .L80219060
/* 5B2508 80219058 00000000 */   nop
/* 5B250C 8021905C 8E710148 */  lw        $s1, 0x148($s3)
.L80219060:
/* 5B2510 80219060 0C09A75B */  jal       get_actor
/* 5B2514 80219064 0220202D */   daddu    $a0, $s1, $zero
/* 5B2518 80219068 0040202D */  daddu     $a0, $v0, $zero
/* 5B251C 8021906C 0C099117 */  jal       get_actor_part
/* 5B2520 80219070 0240282D */   daddu    $a1, $s2, $zero
/* 5B2524 80219074 8C440078 */  lw        $a0, 0x78($v0)
/* 5B2528 80219078 0C099791 */  jal       lookup_defense
/* 5B252C 8021907C 24050001 */   addiu    $a1, $zero, 1
/* 5B2530 80219080 0260202D */  daddu     $a0, $s3, $zero
/* 5B2534 80219084 8E050000 */  lw        $a1, ($s0)
/* 5B2538 80219088 0C0B2026 */  jal       set_variable
/* 5B253C 8021908C 0040302D */   daddu    $a2, $v0, $zero
/* 5B2540 80219090 8FBF0020 */  lw        $ra, 0x20($sp)
/* 5B2544 80219094 8FB3001C */  lw        $s3, 0x1c($sp)
/* 5B2548 80219098 8FB20018 */  lw        $s2, 0x18($sp)
/* 5B254C 8021909C 8FB10014 */  lw        $s1, 0x14($sp)
/* 5B2550 802190A0 8FB00010 */  lw        $s0, 0x10($sp)
/* 5B2554 802190A4 24020002 */  addiu     $v0, $zero, 2
/* 5B2558 802190A8 03E00008 */  jr        $ra
/* 5B255C 802190AC 27BD0028 */   addiu    $sp, $sp, 0x28
