.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel GetDistanceToGoal
/* 19D2DC 8026E9FC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 19D2E0 8026EA00 AFB10014 */  sw        $s1, 0x14($sp)
/* 19D2E4 8026EA04 0080882D */  daddu     $s1, $a0, $zero
/* 19D2E8 8026EA08 AFBF0018 */  sw        $ra, 0x18($sp)
/* 19D2EC 8026EA0C AFB00010 */  sw        $s0, 0x10($sp)
/* 19D2F0 8026EA10 8E30000C */  lw        $s0, 0xc($s1)
/* 19D2F4 8026EA14 8E050000 */  lw        $a1, ($s0)
/* 19D2F8 8026EA18 0C0B1EAF */  jal       get_variable
/* 19D2FC 8026EA1C 26100004 */   addiu    $s0, $s0, 4
/* 19D300 8026EA20 0040202D */  daddu     $a0, $v0, $zero
/* 19D304 8026EA24 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 19D308 8026EA28 14820002 */  bne       $a0, $v0, .L8026EA34
/* 19D30C 8026EA2C 8E100000 */   lw       $s0, ($s0)
/* 19D310 8026EA30 8E240148 */  lw        $a0, 0x148($s1)
.L8026EA34:
/* 19D314 8026EA34 0C09A75B */  jal       get_actor
/* 19D318 8026EA38 00000000 */   nop
/* 19D31C 8026EA3C 8C460018 */  lw        $a2, 0x18($v0)
/* 19D320 8026EA40 C44C0144 */  lwc1      $f12, 0x144($v0)
/* 19D324 8026EA44 C44E014C */  lwc1      $f14, 0x14c($v0)
/* 19D328 8026EA48 0C00A7B5 */  jal       dist2D
/* 19D32C 8026EA4C 8C470020 */   lw       $a3, 0x20($v0)
/* 19D330 8026EA50 0220202D */  daddu     $a0, $s1, $zero
/* 19D334 8026EA54 4600008D */  trunc.w.s $f2, $f0
/* 19D338 8026EA58 44061000 */  mfc1      $a2, $f2
/* 19D33C 8026EA5C 0C0B2026 */  jal       set_variable
/* 19D340 8026EA60 0200282D */   daddu    $a1, $s0, $zero
/* 19D344 8026EA64 8FBF0018 */  lw        $ra, 0x18($sp)
/* 19D348 8026EA68 8FB10014 */  lw        $s1, 0x14($sp)
/* 19D34C 8026EA6C 8FB00010 */  lw        $s0, 0x10($sp)
/* 19D350 8026EA70 24020002 */  addiu     $v0, $zero, 2
/* 19D354 8026EA74 03E00008 */  jr        $ra
/* 19D358 8026EA78 27BD0020 */   addiu    $sp, $sp, 0x20
