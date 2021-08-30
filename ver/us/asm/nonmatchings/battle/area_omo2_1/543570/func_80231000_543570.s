.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80231000_543570
/* 543570 80231000 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 543574 80231004 AFB3001C */  sw        $s3, 0x1c($sp)
/* 543578 80231008 0080982D */  daddu     $s3, $a0, $zero
/* 54357C 8023100C AFBF0020 */  sw        $ra, 0x20($sp)
/* 543580 80231010 AFB20018 */  sw        $s2, 0x18($sp)
/* 543584 80231014 AFB10014 */  sw        $s1, 0x14($sp)
/* 543588 80231018 AFB00010 */  sw        $s0, 0x10($sp)
/* 54358C 8023101C 8E71000C */  lw        $s1, 0xc($s3)
/* 543590 80231020 8E250000 */  lw        $a1, ($s1)
/* 543594 80231024 0C0B1EAF */  jal       evt_get_variable
/* 543598 80231028 26310004 */   addiu    $s1, $s1, 4
/* 54359C 8023102C 0040802D */  daddu     $s0, $v0, $zero
/* 5435A0 80231030 8E250000 */  lw        $a1, ($s1)
/* 5435A4 80231034 26310004 */  addiu     $s1, $s1, 4
/* 5435A8 80231038 0C0B1EAF */  jal       evt_get_variable
/* 5435AC 8023103C 0260202D */   daddu    $a0, $s3, $zero
/* 5435B0 80231040 0040902D */  daddu     $s2, $v0, $zero
/* 5435B4 80231044 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 5435B8 80231048 16020002 */  bne       $s0, $v0, .L80231054
/* 5435BC 8023104C 00000000 */   nop
/* 5435C0 80231050 8E700148 */  lw        $s0, 0x148($s3)
.L80231054:
/* 5435C4 80231054 0C09A75B */  jal       get_actor
/* 5435C8 80231058 0200202D */   daddu    $a0, $s0, $zero
/* 5435CC 8023105C 0040202D */  daddu     $a0, $v0, $zero
/* 5435D0 80231060 0C099117 */  jal       get_actor_part
/* 5435D4 80231064 0240282D */   daddu    $a1, $s2, $zero
/* 5435D8 80231068 8E250000 */  lw        $a1, ($s1)
/* 5435DC 8023106C 26310004 */  addiu     $s1, $s1, 4
/* 5435E0 80231070 0040802D */  daddu     $s0, $v0, $zero
/* 5435E4 80231074 92060073 */  lbu       $a2, 0x73($s0)
/* 5435E8 80231078 0C0B2026 */  jal       evt_set_variable
/* 5435EC 8023107C 0260202D */   daddu    $a0, $s3, $zero
/* 5435F0 80231080 8E250000 */  lw        $a1, ($s1)
/* 5435F4 80231084 92060072 */  lbu       $a2, 0x72($s0)
/* 5435F8 80231088 0C0B2026 */  jal       evt_set_variable
/* 5435FC 8023108C 0260202D */   daddu    $a0, $s3, $zero
/* 543600 80231090 8FBF0020 */  lw        $ra, 0x20($sp)
/* 543604 80231094 8FB3001C */  lw        $s3, 0x1c($sp)
/* 543608 80231098 8FB20018 */  lw        $s2, 0x18($sp)
/* 54360C 8023109C 8FB10014 */  lw        $s1, 0x14($sp)
/* 543610 802310A0 8FB00010 */  lw        $s0, 0x10($sp)
/* 543614 802310A4 24020002 */  addiu     $v0, $zero, 2
/* 543618 802310A8 03E00008 */  jr        $ra
/* 54361C 802310AC 27BD0028 */   addiu    $sp, $sp, 0x28
