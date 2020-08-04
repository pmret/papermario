.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel GetDistanceToGoal
/* 19D2DC 8026E9FC 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 19D2E0 8026EA00 AFB10014 */  sw    $s1, 0x14($sp)
/* 19D2E4 8026EA04 0080882D */  daddu $s1, $a0, $zero
/* 19D2E8 8026EA08 AFBF0018 */  sw    $ra, 0x18($sp)
/* 19D2EC 8026EA0C AFB00010 */  sw    $s0, 0x10($sp)
/* 19D2F0 8026EA10 8E30000C */  lw    $s0, 0xc($s1)
/* 19D2F4 8026EA14 8E050000 */  lw    $a1, ($s0)
/* 19D2F8 8026EA18 0C0B1EAF */  jal   get_variable
/* 19D2FC 8026EA1C 26100004 */   addiu $s0, $s0, 4
/* 19D300 8026EA20 0040202D */  daddu $a0, $v0, $zero
/* 19D304 8026EA24 2402FF81 */  addiu $v0, $zero, -0x7f
/* 19D308 8026EA28 14820002 */  bne   $a0, $v0, .L8026EA34
/* 19D30C 8026EA2C 8E100000 */   lw    $s0, ($s0)
/* 19D310 8026EA30 8E240148 */  lw    $a0, 0x148($s1)
.L8026EA34:
/* 19D314 8026EA34 0C09A75B */  jal   get_actor
/* 19D318 8026EA38 00000000 */   nop   
/* 19D31C 8026EA3C 8C460018 */  lw    $a2, 0x18($v0)
/* 19D320 8026EA40 C44C0144 */  lwc1  $f12, 0x144($v0)
/* 19D324 8026EA44 C44E014C */  lwc1  $f14, 0x14c($v0)
/* 19D328 8026EA48 0C00A7B5 */  jal   dist2D
/* 19D32C 8026EA4C 8C470020 */   lw    $a3, 0x20($v0)
/* 19D330 8026EA50 0220202D */  daddu $a0, $s1, $zero
/* 19D334 8026EA54 4600008D */  trunc.w.s $f2, $f0
/* 19D338 8026EA58 44061000 */  mfc1  $a2, $f2
/* 19D33C 8026EA5C 0C0B2026 */  jal   set_variable
/* 19D340 8026EA60 0200282D */   daddu $a1, $s0, $zero
/* 19D344 8026EA64 8FBF0018 */  lw    $ra, 0x18($sp)
/* 19D348 8026EA68 8FB10014 */  lw    $s1, 0x14($sp)
/* 19D34C 8026EA6C 8FB00010 */  lw    $s0, 0x10($sp)
/* 19D350 8026EA70 24020002 */  addiu $v0, $zero, 2
/* 19D354 8026EA74 03E00008 */  jr    $ra
/* 19D358 8026EA78 27BD0020 */   addiu $sp, $sp, 0x20

/* 19D35C 8026EA7C 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 19D360 8026EA80 AFB20018 */  sw    $s2, 0x18($sp)
/* 19D364 8026EA84 0080902D */  daddu $s2, $a0, $zero
/* 19D368 8026EA88 AFBF0020 */  sw    $ra, 0x20($sp)
/* 19D36C 8026EA8C AFB3001C */  sw    $s3, 0x1c($sp)
/* 19D370 8026EA90 AFB10014 */  sw    $s1, 0x14($sp)
/* 19D374 8026EA94 AFB00010 */  sw    $s0, 0x10($sp)
/* 19D378 8026EA98 8E50000C */  lw    $s0, 0xc($s2)
/* 19D37C 8026EA9C 8E050000 */  lw    $a1, ($s0)
/* 19D380 8026EAA0 0C0B1EAF */  jal   get_variable
/* 19D384 8026EAA4 26100004 */   addiu $s0, $s0, 4
/* 19D388 8026EAA8 0040882D */  daddu $s1, $v0, $zero
/* 19D38C 8026EAAC 8E050000 */  lw    $a1, ($s0)
/* 19D390 8026EAB0 26100004 */  addiu $s0, $s0, 4
/* 19D394 8026EAB4 0C0B1EAF */  jal   get_variable
/* 19D398 8026EAB8 0240202D */   daddu $a0, $s2, $zero
/* 19D39C 8026EABC 0240202D */  daddu $a0, $s2, $zero
/* 19D3A0 8026EAC0 8E050000 */  lw    $a1, ($s0)
/* 19D3A4 8026EAC4 0C0B1EAF */  jal   get_variable
/* 19D3A8 8026EAC8 0040802D */   daddu $s0, $v0, $zero
/* 19D3AC 8026EACC 0040982D */  daddu $s3, $v0, $zero
/* 19D3B0 8026EAD0 2402FF81 */  addiu $v0, $zero, -0x7f
/* 19D3B4 8026EAD4 16220002 */  bne   $s1, $v0, .L8026EAE0
/* 19D3B8 8026EAD8 00000000 */   nop   
/* 19D3BC 8026EADC 8E510148 */  lw    $s1, 0x148($s2)
.L8026EAE0:
/* 19D3C0 8026EAE0 0C09A75B */  jal   get_actor
/* 19D3C4 8026EAE4 0220202D */   daddu $a0, $s1, $zero
/* 19D3C8 8026EAE8 0040202D */  daddu $a0, $v0, $zero
/* 19D3CC 8026EAEC 0C099117 */  jal   get_actor_part
/* 19D3D0 8026EAF0 0200282D */   daddu $a1, $s0, $zero
/* 19D3D4 8026EAF4 0040202D */  daddu $a0, $v0, $zero
/* 19D3D8 8026EAF8 0C099B5B */  jal   func_80266D6C
/* 19D3DC 8026EAFC 0260282D */   daddu $a1, $s3, $zero
/* 19D3E0 8026EB00 8FBF0020 */  lw    $ra, 0x20($sp)
/* 19D3E4 8026EB04 8FB3001C */  lw    $s3, 0x1c($sp)
/* 19D3E8 8026EB08 8FB20018 */  lw    $s2, 0x18($sp)
/* 19D3EC 8026EB0C 8FB10014 */  lw    $s1, 0x14($sp)
/* 19D3F0 8026EB10 8FB00010 */  lw    $s0, 0x10($sp)
/* 19D3F4 8026EB14 24020002 */  addiu $v0, $zero, 2
/* 19D3F8 8026EB18 03E00008 */  jr    $ra
/* 19D3FC 8026EB1C 27BD0028 */   addiu $sp, $sp, 0x28

/* 19D400 8026EB20 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 19D404 8026EB24 AFB20018 */  sw    $s2, 0x18($sp)
/* 19D408 8026EB28 0080902D */  daddu $s2, $a0, $zero
/* 19D40C 8026EB2C AFBF0020 */  sw    $ra, 0x20($sp)
/* 19D410 8026EB30 AFB3001C */  sw    $s3, 0x1c($sp)
/* 19D414 8026EB34 AFB10014 */  sw    $s1, 0x14($sp)
/* 19D418 8026EB38 AFB00010 */  sw    $s0, 0x10($sp)
/* 19D41C 8026EB3C 8E51000C */  lw    $s1, 0xc($s2)
/* 19D420 8026EB40 8E250000 */  lw    $a1, ($s1)
/* 19D424 8026EB44 0C0B1EAF */  jal   get_variable
/* 19D428 8026EB48 26310004 */   addiu $s1, $s1, 4
/* 19D42C 8026EB4C 0040802D */  daddu $s0, $v0, $zero
/* 19D430 8026EB50 8E250000 */  lw    $a1, ($s1)
/* 19D434 8026EB54 26310004 */  addiu $s1, $s1, 4
/* 19D438 8026EB58 0C0B1EAF */  jal   get_variable
/* 19D43C 8026EB5C 0240202D */   daddu $a0, $s2, $zero
/* 19D440 8026EB60 0040982D */  daddu $s3, $v0, $zero
/* 19D444 8026EB64 2402FF81 */  addiu $v0, $zero, -0x7f
/* 19D448 8026EB68 16020002 */  bne   $s0, $v0, .L8026EB74
/* 19D44C 8026EB6C 00000000 */   nop   
/* 19D450 8026EB70 8E500148 */  lw    $s0, 0x148($s2)
.L8026EB74:
/* 19D454 8026EB74 0C09A75B */  jal   get_actor
/* 19D458 8026EB78 0200202D */   daddu $a0, $s0, $zero
/* 19D45C 8026EB7C 0040202D */  daddu $a0, $v0, $zero
/* 19D460 8026EB80 0C099117 */  jal   get_actor_part
/* 19D464 8026EB84 0260282D */   daddu $a1, $s3, $zero
/* 19D468 8026EB88 8E250000 */  lw    $a1, ($s1)
/* 19D46C 8026EB8C 26310004 */  addiu $s1, $s1, 4
/* 19D470 8026EB90 8C5000C0 */  lw    $s0, 0xc0($v0)
/* 19D474 8026EB94 0C0B1EAF */  jal   get_variable
/* 19D478 8026EB98 0240202D */   daddu $a0, $s2, $zero
/* 19D47C 8026EB9C A6020740 */  sh    $v0, 0x740($s0)
/* 19D480 8026EBA0 8E250000 */  lw    $a1, ($s1)
/* 19D484 8026EBA4 26310004 */  addiu $s1, $s1, 4
/* 19D488 8026EBA8 0C0B1EAF */  jal   get_variable
/* 19D48C 8026EBAC 0240202D */   daddu $a0, $s2, $zero
/* 19D490 8026EBB0 A6020742 */  sh    $v0, 0x742($s0)
/* 19D494 8026EBB4 8E250000 */  lw    $a1, ($s1)
/* 19D498 8026EBB8 26310004 */  addiu $s1, $s1, 4
/* 19D49C 8026EBBC 0C0B1EAF */  jal   get_variable
/* 19D4A0 8026EBC0 0240202D */   daddu $a0, $s2, $zero
/* 19D4A4 8026EBC4 A6020744 */  sh    $v0, 0x744($s0)
/* 19D4A8 8026EBC8 8E250000 */  lw    $a1, ($s1)
/* 19D4AC 8026EBCC 0C0B1EAF */  jal   get_variable
/* 19D4B0 8026EBD0 0240202D */   daddu $a0, $s2, $zero
/* 19D4B4 8026EBD4 A6020746 */  sh    $v0, 0x746($s0)
/* 19D4B8 8026EBD8 8FBF0020 */  lw    $ra, 0x20($sp)
/* 19D4BC 8026EBDC 8FB3001C */  lw    $s3, 0x1c($sp)
/* 19D4C0 8026EBE0 8FB20018 */  lw    $s2, 0x18($sp)
/* 19D4C4 8026EBE4 8FB10014 */  lw    $s1, 0x14($sp)
/* 19D4C8 8026EBE8 8FB00010 */  lw    $s0, 0x10($sp)
/* 19D4CC 8026EBEC 24020002 */  addiu $v0, $zero, 2
/* 19D4D0 8026EBF0 03E00008 */  jr    $ra
/* 19D4D4 8026EBF4 27BD0028 */   addiu $sp, $sp, 0x28

/* 19D4D8 8026EBF8 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 19D4DC 8026EBFC AFB20018 */  sw    $s2, 0x18($sp)
/* 19D4E0 8026EC00 0080902D */  daddu $s2, $a0, $zero
/* 19D4E4 8026EC04 AFBF0020 */  sw    $ra, 0x20($sp)
/* 19D4E8 8026EC08 AFB3001C */  sw    $s3, 0x1c($sp)
/* 19D4EC 8026EC0C AFB10014 */  sw    $s1, 0x14($sp)
/* 19D4F0 8026EC10 AFB00010 */  sw    $s0, 0x10($sp)
/* 19D4F4 8026EC14 8E51000C */  lw    $s1, 0xc($s2)
/* 19D4F8 8026EC18 8E250000 */  lw    $a1, ($s1)
/* 19D4FC 8026EC1C 0C0B1EAF */  jal   get_variable
/* 19D500 8026EC20 26310004 */   addiu $s1, $s1, 4
/* 19D504 8026EC24 0040802D */  daddu $s0, $v0, $zero
/* 19D508 8026EC28 8E250000 */  lw    $a1, ($s1)
/* 19D50C 8026EC2C 26310004 */  addiu $s1, $s1, 4
/* 19D510 8026EC30 0C0B1EAF */  jal   get_variable
/* 19D514 8026EC34 0240202D */   daddu $a0, $s2, $zero
/* 19D518 8026EC38 0040982D */  daddu $s3, $v0, $zero
/* 19D51C 8026EC3C 2402FF81 */  addiu $v0, $zero, -0x7f
/* 19D520 8026EC40 16020002 */  bne   $s0, $v0, .L8026EC4C
/* 19D524 8026EC44 00000000 */   nop   
/* 19D528 8026EC48 8E500148 */  lw    $s0, 0x148($s2)
.L8026EC4C:
/* 19D52C 8026EC4C 0C09A75B */  jal   get_actor
/* 19D530 8026EC50 0200202D */   daddu $a0, $s0, $zero
/* 19D534 8026EC54 0040202D */  daddu $a0, $v0, $zero
/* 19D538 8026EC58 0C099117 */  jal   get_actor_part
/* 19D53C 8026EC5C 0260282D */   daddu $a1, $s3, $zero
/* 19D540 8026EC60 8E250000 */  lw    $a1, ($s1)
/* 19D544 8026EC64 26310004 */  addiu $s1, $s1, 4
/* 19D548 8026EC68 8C5000C0 */  lw    $s0, 0xc0($v0)
/* 19D54C 8026EC6C 0C0B1EAF */  jal   get_variable
/* 19D550 8026EC70 0240202D */   daddu $a0, $s2, $zero
/* 19D554 8026EC74 A6020740 */  sh    $v0, 0x740($s0)
/* 19D558 8026EC78 8E250000 */  lw    $a1, ($s1)
/* 19D55C 8026EC7C 26310004 */  addiu $s1, $s1, 4
/* 19D560 8026EC80 0C0B1EAF */  jal   get_variable
/* 19D564 8026EC84 0240202D */   daddu $a0, $s2, $zero
/* 19D568 8026EC88 A6020742 */  sh    $v0, 0x742($s0)
/* 19D56C 8026EC8C 8E250000 */  lw    $a1, ($s1)
/* 19D570 8026EC90 26310004 */  addiu $s1, $s1, 4
/* 19D574 8026EC94 0C0B1EAF */  jal   get_variable
/* 19D578 8026EC98 0240202D */   daddu $a0, $s2, $zero
/* 19D57C 8026EC9C A6020744 */  sh    $v0, 0x744($s0)
/* 19D580 8026ECA0 8E250000 */  lw    $a1, ($s1)
/* 19D584 8026ECA4 26310004 */  addiu $s1, $s1, 4
/* 19D588 8026ECA8 0C0B1EAF */  jal   get_variable
/* 19D58C 8026ECAC 0240202D */   daddu $a0, $s2, $zero
/* 19D590 8026ECB0 A6020746 */  sh    $v0, 0x746($s0)
/* 19D594 8026ECB4 8E250000 */  lw    $a1, ($s1)
/* 19D598 8026ECB8 26310004 */  addiu $s1, $s1, 4
/* 19D59C 8026ECBC 0C0B1EAF */  jal   get_variable
/* 19D5A0 8026ECC0 0240202D */   daddu $a0, $s2, $zero
/* 19D5A4 8026ECC4 A6020748 */  sh    $v0, 0x748($s0)
/* 19D5A8 8026ECC8 8E250000 */  lw    $a1, ($s1)
/* 19D5AC 8026ECCC 26310004 */  addiu $s1, $s1, 4
/* 19D5B0 8026ECD0 0C0B1EAF */  jal   get_variable
/* 19D5B4 8026ECD4 0240202D */   daddu $a0, $s2, $zero
/* 19D5B8 8026ECD8 A602074A */  sh    $v0, 0x74a($s0)
/* 19D5BC 8026ECDC 8E250000 */  lw    $a1, ($s1)
/* 19D5C0 8026ECE0 26310004 */  addiu $s1, $s1, 4
/* 19D5C4 8026ECE4 0C0B1EAF */  jal   get_variable
/* 19D5C8 8026ECE8 0240202D */   daddu $a0, $s2, $zero
/* 19D5CC 8026ECEC A602074C */  sh    $v0, 0x74c($s0)
/* 19D5D0 8026ECF0 8E250000 */  lw    $a1, ($s1)
/* 19D5D4 8026ECF4 0C0B1EAF */  jal   get_variable
/* 19D5D8 8026ECF8 0240202D */   daddu $a0, $s2, $zero
/* 19D5DC 8026ECFC A602074E */  sh    $v0, 0x74e($s0)
/* 19D5E0 8026ED00 8FBF0020 */  lw    $ra, 0x20($sp)
/* 19D5E4 8026ED04 8FB3001C */  lw    $s3, 0x1c($sp)
/* 19D5E8 8026ED08 8FB20018 */  lw    $s2, 0x18($sp)
/* 19D5EC 8026ED0C 8FB10014 */  lw    $s1, 0x14($sp)
/* 19D5F0 8026ED10 8FB00010 */  lw    $s0, 0x10($sp)
/* 19D5F4 8026ED14 24020002 */  addiu $v0, $zero, 2
/* 19D5F8 8026ED18 03E00008 */  jr    $ra
/* 19D5FC 8026ED1C 27BD0028 */   addiu $sp, $sp, 0x28

/* 19D600 8026ED20 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 19D604 8026ED24 AFB20018 */  sw    $s2, 0x18($sp)
/* 19D608 8026ED28 0080902D */  daddu $s2, $a0, $zero
/* 19D60C 8026ED2C AFBF0020 */  sw    $ra, 0x20($sp)
/* 19D610 8026ED30 AFB3001C */  sw    $s3, 0x1c($sp)
/* 19D614 8026ED34 AFB10014 */  sw    $s1, 0x14($sp)
/* 19D618 8026ED38 AFB00010 */  sw    $s0, 0x10($sp)
/* 19D61C 8026ED3C 8E50000C */  lw    $s0, 0xc($s2)
/* 19D620 8026ED40 8E050000 */  lw    $a1, ($s0)
/* 19D624 8026ED44 0C0B1EAF */  jal   get_variable
/* 19D628 8026ED48 26100004 */   addiu $s0, $s0, 4
/* 19D62C 8026ED4C 0040882D */  daddu $s1, $v0, $zero
/* 19D630 8026ED50 8E050000 */  lw    $a1, ($s0)
/* 19D634 8026ED54 26100004 */  addiu $s0, $s0, 4
/* 19D638 8026ED58 0C0B1EAF */  jal   get_variable
/* 19D63C 8026ED5C 0240202D */   daddu $a0, $s2, $zero
/* 19D640 8026ED60 0240202D */  daddu $a0, $s2, $zero
/* 19D644 8026ED64 8E050000 */  lw    $a1, ($s0)
/* 19D648 8026ED68 0C0B1EAF */  jal   get_variable
/* 19D64C 8026ED6C 0040802D */   daddu $s0, $v0, $zero
/* 19D650 8026ED70 0040982D */  daddu $s3, $v0, $zero
/* 19D654 8026ED74 2402FF81 */  addiu $v0, $zero, -0x7f
/* 19D658 8026ED78 16220002 */  bne   $s1, $v0, .L8026ED84
/* 19D65C 8026ED7C 00000000 */   nop   
/* 19D660 8026ED80 8E510148 */  lw    $s1, 0x148($s2)
.L8026ED84:
/* 19D664 8026ED84 0C09A75B */  jal   get_actor
/* 19D668 8026ED88 0220202D */   daddu $a0, $s1, $zero
/* 19D66C 8026ED8C 0040202D */  daddu $a0, $v0, $zero
/* 19D670 8026ED90 0C099117 */  jal   get_actor_part
/* 19D674 8026ED94 0200282D */   daddu $a1, $s0, $zero
/* 19D678 8026ED98 12600005 */  beqz  $s3, .L8026EDB0
/* 19D67C 8026ED9C 0040202D */   daddu $a0, $v0, $zero
/* 19D680 8026EDA0 8C820000 */  lw    $v0, ($a0)
/* 19D684 8026EDA4 3C030100 */  lui   $v1, 0x100
/* 19D688 8026EDA8 0809BB70 */  j     .L8026EDC0
/* 19D68C 8026EDAC 00431025 */   or    $v0, $v0, $v1

.L8026EDB0:
/* 19D690 8026EDB0 3C03FEFF */  lui   $v1, 0xfeff
/* 19D694 8026EDB4 8C820000 */  lw    $v0, ($a0)
/* 19D698 8026EDB8 3463FFFF */  ori   $v1, $v1, 0xffff
/* 19D69C 8026EDBC 00431024 */  and   $v0, $v0, $v1
.L8026EDC0:
/* 19D6A0 8026EDC0 AC820000 */  sw    $v0, ($a0)
/* 19D6A4 8026EDC4 8FBF0020 */  lw    $ra, 0x20($sp)
/* 19D6A8 8026EDC8 8FB3001C */  lw    $s3, 0x1c($sp)
/* 19D6AC 8026EDCC 8FB20018 */  lw    $s2, 0x18($sp)
/* 19D6B0 8026EDD0 8FB10014 */  lw    $s1, 0x14($sp)
/* 19D6B4 8026EDD4 8FB00010 */  lw    $s0, 0x10($sp)
/* 19D6B8 8026EDD8 24020002 */  addiu $v0, $zero, 2
/* 19D6BC 8026EDDC 03E00008 */  jr    $ra
/* 19D6C0 8026EDE0 27BD0028 */   addiu $sp, $sp, 0x28

/* 19D6C4 8026EDE4 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 19D6C8 8026EDE8 AFB20018 */  sw    $s2, 0x18($sp)
/* 19D6CC 8026EDEC 0080902D */  daddu $s2, $a0, $zero
/* 19D6D0 8026EDF0 AFBF0020 */  sw    $ra, 0x20($sp)
/* 19D6D4 8026EDF4 AFB3001C */  sw    $s3, 0x1c($sp)
/* 19D6D8 8026EDF8 AFB10014 */  sw    $s1, 0x14($sp)
/* 19D6DC 8026EDFC AFB00010 */  sw    $s0, 0x10($sp)
/* 19D6E0 8026EE00 8E50000C */  lw    $s0, 0xc($s2)
/* 19D6E4 8026EE04 8E050000 */  lw    $a1, ($s0)
/* 19D6E8 8026EE08 0C0B1EAF */  jal   get_variable
/* 19D6EC 8026EE0C 26100004 */   addiu $s0, $s0, 4
/* 19D6F0 8026EE10 0040882D */  daddu $s1, $v0, $zero
/* 19D6F4 8026EE14 8E050000 */  lw    $a1, ($s0)
/* 19D6F8 8026EE18 26100004 */  addiu $s0, $s0, 4
/* 19D6FC 8026EE1C 0C0B1EAF */  jal   get_variable
/* 19D700 8026EE20 0240202D */   daddu $a0, $s2, $zero
/* 19D704 8026EE24 0240202D */  daddu $a0, $s2, $zero
/* 19D708 8026EE28 8E050000 */  lw    $a1, ($s0)
/* 19D70C 8026EE2C 0C0B1EAF */  jal   get_variable
/* 19D710 8026EE30 0040802D */   daddu $s0, $v0, $zero
/* 19D714 8026EE34 0040982D */  daddu $s3, $v0, $zero
/* 19D718 8026EE38 2402FF81 */  addiu $v0, $zero, -0x7f
/* 19D71C 8026EE3C 16220002 */  bne   $s1, $v0, .L8026EE48
/* 19D720 8026EE40 00000000 */   nop   
/* 19D724 8026EE44 8E510148 */  lw    $s1, 0x148($s2)
.L8026EE48:
/* 19D728 8026EE48 0C09A75B */  jal   get_actor
/* 19D72C 8026EE4C 0220202D */   daddu $a0, $s1, $zero
/* 19D730 8026EE50 0040202D */  daddu $a0, $v0, $zero
/* 19D734 8026EE54 0C099117 */  jal   get_actor_part
/* 19D738 8026EE58 0200282D */   daddu $a1, $s0, $zero
/* 19D73C 8026EE5C 0040202D */  daddu $a0, $v0, $zero
/* 19D740 8026EE60 0C099BAA */  jal   func_80266EA8
/* 19D744 8026EE64 0260282D */   daddu $a1, $s3, $zero
/* 19D748 8026EE68 8FBF0020 */  lw    $ra, 0x20($sp)
/* 19D74C 8026EE6C 8FB3001C */  lw    $s3, 0x1c($sp)
/* 19D750 8026EE70 8FB20018 */  lw    $s2, 0x18($sp)
/* 19D754 8026EE74 8FB10014 */  lw    $s1, 0x14($sp)
/* 19D758 8026EE78 8FB00010 */  lw    $s0, 0x10($sp)
/* 19D75C 8026EE7C 24020002 */  addiu $v0, $zero, 2
/* 19D760 8026EE80 03E00008 */  jr    $ra
/* 19D764 8026EE84 27BD0028 */   addiu $sp, $sp, 0x28

