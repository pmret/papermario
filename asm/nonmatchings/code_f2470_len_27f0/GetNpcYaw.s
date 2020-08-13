.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel GetNpcYaw
/* 0F33C0 802CEA10 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F33C4 802CEA14 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F33C8 802CEA18 0080882D */  daddu $s1, $a0, $zero
/* 0F33CC 802CEA1C AFBF0018 */  sw    $ra, 0x18($sp)
/* 0F33D0 802CEA20 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F33D4 802CEA24 8E30000C */  lw    $s0, 0xc($s1)
/* 0F33D8 802CEA28 8E050000 */  lw    $a1, ($s0)
/* 0F33DC 802CEA2C 0C0B1EAF */  jal   get_variable
/* 0F33E0 802CEA30 26100004 */   addiu $s0, $s0, 4
/* 0F33E4 802CEA34 0220202D */  daddu $a0, $s1, $zero
/* 0F33E8 802CEA38 8E100000 */  lw    $s0, ($s0)
/* 0F33EC 802CEA3C 0C0B36B0 */  jal   func_802CDAC0
/* 0F33F0 802CEA40 0040282D */   daddu $a1, $v0, $zero
/* 0F33F4 802CEA44 5040000A */  beql  $v0, $zero, .L802CEA70
/* 0F33F8 802CEA48 24020002 */   addiu $v0, $zero, 2
/* 0F33FC 802CEA4C C44C000C */  lwc1  $f12, 0xc($v0)
/* 0F3400 802CEA50 0C00A6C9 */  jal   clamp_angle
/* 0F3404 802CEA54 00000000 */   nop   
/* 0F3408 802CEA58 0220202D */  daddu $a0, $s1, $zero
/* 0F340C 802CEA5C 4600008D */  trunc.w.s $f2, $f0
/* 0F3410 802CEA60 44061000 */  mfc1  $a2, $f2
/* 0F3414 802CEA64 0C0B2026 */  jal   set_variable
/* 0F3418 802CEA68 0200282D */   daddu $a1, $s0, $zero
/* 0F341C 802CEA6C 24020002 */  addiu $v0, $zero, 2
.L802CEA70:
/* 0F3420 802CEA70 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0F3424 802CEA74 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F3428 802CEA78 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F342C 802CEA7C 03E00008 */  jr    $ra
/* 0F3430 802CEA80 27BD0020 */   addiu $sp, $sp, 0x20

