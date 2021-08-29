.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel GetActorAttackBoost
/* 19E4E4 8026FC04 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 19E4E8 8026FC08 AFB10014 */  sw        $s1, 0x14($sp)
/* 19E4EC 8026FC0C 0080882D */  daddu     $s1, $a0, $zero
/* 19E4F0 8026FC10 AFBF0018 */  sw        $ra, 0x18($sp)
/* 19E4F4 8026FC14 AFB00010 */  sw        $s0, 0x10($sp)
/* 19E4F8 8026FC18 8E30000C */  lw        $s0, 0xc($s1)
/* 19E4FC 8026FC1C 8E050000 */  lw        $a1, ($s0)
/* 19E500 8026FC20 0C0B1EAF */  jal       evt_get_variable
/* 19E504 8026FC24 26100004 */   addiu    $s0, $s0, 4
/* 19E508 8026FC28 0040202D */  daddu     $a0, $v0, $zero
/* 19E50C 8026FC2C 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 19E510 8026FC30 14820002 */  bne       $a0, $v0, .L8026FC3C
/* 19E514 8026FC34 00000000 */   nop
/* 19E518 8026FC38 8E240148 */  lw        $a0, 0x148($s1)
.L8026FC3C:
/* 19E51C 8026FC3C 0C09A75B */  jal       get_actor
/* 19E520 8026FC40 8E100000 */   lw       $s0, ($s0)
/* 19E524 8026FC44 0220202D */  daddu     $a0, $s1, $zero
/* 19E528 8026FC48 80460221 */  lb        $a2, 0x221($v0)
/* 19E52C 8026FC4C 0C0B2026 */  jal       evt_set_variable
/* 19E530 8026FC50 0200282D */   daddu    $a1, $s0, $zero
/* 19E534 8026FC54 8FBF0018 */  lw        $ra, 0x18($sp)
/* 19E538 8026FC58 8FB10014 */  lw        $s1, 0x14($sp)
/* 19E53C 8026FC5C 8FB00010 */  lw        $s0, 0x10($sp)
/* 19E540 8026FC60 24020002 */  addiu     $v0, $zero, 2
/* 19E544 8026FC64 03E00008 */  jr        $ra
/* 19E548 8026FC68 27BD0020 */   addiu    $sp, $sp, 0x20
