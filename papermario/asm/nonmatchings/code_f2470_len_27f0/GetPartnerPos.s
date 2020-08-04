.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel GetPartnerPos
/* 0F3DE8 802CF438 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0F3DEC 802CF43C AFB10014 */  sw    $s1, 0x14($sp)
/* 0F3DF0 802CF440 0080882D */  daddu $s1, $a0, $zero
/* 0F3DF4 802CF444 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0F3DF8 802CF448 AFB40020 */  sw    $s4, 0x20($sp)
/* 0F3DFC 802CF44C AFB3001C */  sw    $s3, 0x1c($sp)
/* 0F3E00 802CF450 AFB20018 */  sw    $s2, 0x18($sp)
/* 0F3E04 802CF454 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F3E08 802CF458 8E22000C */  lw    $v0, 0xc($s1)
/* 0F3E0C 802CF45C 8C520000 */  lw    $s2, ($v0)
/* 0F3E10 802CF460 24420004 */  addiu $v0, $v0, 4
/* 0F3E14 802CF464 8C530000 */  lw    $s3, ($v0)
/* 0F3E18 802CF468 8C540004 */  lw    $s4, 4($v0)
/* 0F3E1C 802CF46C 0C00EABB */  jal   get_npc_unsafe
/* 0F3E20 802CF470 2404FFFC */   addiu $a0, $zero, -4
/* 0F3E24 802CF474 0040802D */  daddu $s0, $v0, $zero
/* 0F3E28 802CF478 12000012 */  beqz  $s0, .L802CF4C4
/* 0F3E2C 802CF47C 0220202D */   daddu $a0, $s1, $zero
/* 0F3E30 802CF480 C6000038 */  lwc1  $f0, 0x38($s0)
/* 0F3E34 802CF484 4600008D */  trunc.w.s $f2, $f0
/* 0F3E38 802CF488 44061000 */  mfc1  $a2, $f2
/* 0F3E3C 802CF48C 0C0B2026 */  jal   set_variable
/* 0F3E40 802CF490 0240282D */   daddu $a1, $s2, $zero
/* 0F3E44 802CF494 0220202D */  daddu $a0, $s1, $zero
/* 0F3E48 802CF498 C600003C */  lwc1  $f0, 0x3c($s0)
/* 0F3E4C 802CF49C 4600008D */  trunc.w.s $f2, $f0
/* 0F3E50 802CF4A0 44061000 */  mfc1  $a2, $f2
/* 0F3E54 802CF4A4 0C0B2026 */  jal   set_variable
/* 0F3E58 802CF4A8 0260282D */   daddu $a1, $s3, $zero
/* 0F3E5C 802CF4AC 0220202D */  daddu $a0, $s1, $zero
/* 0F3E60 802CF4B0 C6000040 */  lwc1  $f0, 0x40($s0)
/* 0F3E64 802CF4B4 4600008D */  trunc.w.s $f2, $f0
/* 0F3E68 802CF4B8 44061000 */  mfc1  $a2, $f2
/* 0F3E6C 802CF4BC 0C0B2026 */  jal   set_variable
/* 0F3E70 802CF4C0 0280282D */   daddu $a1, $s4, $zero
.L802CF4C4:
/* 0F3E74 802CF4C4 24020002 */  addiu $v0, $zero, 2
/* 0F3E78 802CF4C8 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0F3E7C 802CF4CC 8FB40020 */  lw    $s4, 0x20($sp)
/* 0F3E80 802CF4D0 8FB3001C */  lw    $s3, 0x1c($sp)
/* 0F3E84 802CF4D4 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F3E88 802CF4D8 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F3E8C 802CF4DC 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F3E90 802CF4E0 03E00008 */  jr    $ra
/* 0F3E94 802CF4E4 27BD0028 */   addiu $sp, $sp, 0x28

