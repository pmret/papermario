.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021A288_4B3478
/* 4B3478 8021A288 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 4B347C 8021A28C AFB00010 */  sw        $s0, 0x10($sp)
/* 4B3480 8021A290 0080802D */  daddu     $s0, $a0, $zero
/* 4B3484 8021A294 AFBF0018 */  sw        $ra, 0x18($sp)
/* 4B3488 8021A298 AFB10014 */  sw        $s1, 0x14($sp)
/* 4B348C 8021A29C 8E040148 */  lw        $a0, 0x148($s0)
/* 4B3490 8021A2A0 0C09A75B */  jal       get_actor
/* 4B3494 8021A2A4 8E11000C */   lw       $s1, 0xc($s0)
/* 4B3498 8021A2A8 0200202D */  daddu     $a0, $s0, $zero
/* 4B349C 8021A2AC 8E250000 */  lw        $a1, ($s1)
/* 4B34A0 8021A2B0 0C0B1EAF */  jal       get_variable
/* 4B34A4 8021A2B4 0040802D */   daddu    $s0, $v0, $zero
/* 4B34A8 8021A2B8 A20201F0 */  sb        $v0, 0x1f0($s0)
/* 4B34AC 8021A2BC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 4B34B0 8021A2C0 8FB10014 */  lw        $s1, 0x14($sp)
/* 4B34B4 8021A2C4 8FB00010 */  lw        $s0, 0x10($sp)
/* 4B34B8 8021A2C8 24020002 */  addiu     $v0, $zero, 2
/* 4B34BC 8021A2CC 03E00008 */  jr        $ra
/* 4B34C0 8021A2D0 27BD0020 */   addiu    $sp, $sp, 0x20
/* 4B34C4 8021A2D4 00000000 */  nop
/* 4B34C8 8021A2D8 00000000 */  nop
/* 4B34CC 8021A2DC 00000000 */  nop
