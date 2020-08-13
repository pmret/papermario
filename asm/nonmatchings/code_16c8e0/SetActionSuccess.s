.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel SetActionSuccess
/* 197BA0 802692C0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 197BA4 802692C4 AFBF0010 */  sw    $ra, 0x10($sp)
/* 197BA8 802692C8 8C82000C */  lw    $v0, 0xc($a0)
/* 197BAC 802692CC 0C0B1EAF */  jal   get_variable
/* 197BB0 802692D0 8C450000 */   lw    $a1, ($v0)
/* 197BB4 802692D4 8FBF0010 */  lw    $ra, 0x10($sp)
/* 197BB8 802692D8 3C01800E */  lui   $at, 0x800e
/* 197BBC 802692DC A022C0F1 */  sb    $v0, -0x3f0f($at)
/* 197BC0 802692E0 24020002 */  addiu $v0, $zero, 2
/* 197BC4 802692E4 03E00008 */  jr    $ra
/* 197BC8 802692E8 27BD0018 */   addiu $sp, $sp, 0x18

/* 197BCC 802692EC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 197BD0 802692F0 AFBF0010 */  sw    $ra, 0x10($sp)
/* 197BD4 802692F4 8C82000C */  lw    $v0, 0xc($a0)
/* 197BD8 802692F8 0C0B1EAF */  jal   get_variable
/* 197BDC 802692FC 8C450000 */   lw    $a1, ($v0)
/* 197BE0 80269300 8FBF0010 */  lw    $ra, 0x10($sp)
/* 197BE4 80269304 3C01800E */  lui   $at, 0x800e
/* 197BE8 80269308 A022C0F3 */  sb    $v0, -0x3f0d($at)
/* 197BEC 8026930C 24020002 */  addiu $v0, $zero, 2
/* 197BF0 80269310 03E00008 */  jr    $ra
/* 197BF4 80269314 27BD0018 */   addiu $sp, $sp, 0x18

/* 197BF8 80269318 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 197BFC 8026931C AFBF0010 */  sw    $ra, 0x10($sp)
/* 197C00 80269320 8C82000C */  lw    $v0, 0xc($a0)
/* 197C04 80269324 3C06800E */  lui   $a2, 0x800e
/* 197C08 80269328 80C6C0F3 */  lb    $a2, -0x3f0d($a2)
/* 197C0C 8026932C 0C0B2026 */  jal   set_variable
/* 197C10 80269330 8C450000 */   lw    $a1, ($v0)
/* 197C14 80269334 8FBF0010 */  lw    $ra, 0x10($sp)
/* 197C18 80269338 24020002 */  addiu $v0, $zero, 2
/* 197C1C 8026933C 03E00008 */  jr    $ra
/* 197C20 80269340 27BD0018 */   addiu $sp, $sp, 0x18

/* 197C24 80269344 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 197C28 80269348 AFBF0010 */  sw    $ra, 0x10($sp)
/* 197C2C 8026934C 8C82000C */  lw    $v0, 0xc($a0)
/* 197C30 80269350 0C0B1EAF */  jal   get_variable
/* 197C34 80269354 8C450000 */   lw    $a1, ($v0)
/* 197C38 80269358 8FBF0010 */  lw    $ra, 0x10($sp)
/* 197C3C 8026935C 3C01802A */  lui   $at, 0x802a
/* 197C40 80269360 A422FC4C */  sh    $v0, -0x3b4($at)
/* 197C44 80269364 24020002 */  addiu $v0, $zero, 2
/* 197C48 80269368 03E00008 */  jr    $ra
/* 197C4C 8026936C 27BD0018 */   addiu $sp, $sp, 0x18

/* 197C50 80269370 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 197C54 80269374 AFBF0010 */  sw    $ra, 0x10($sp)
/* 197C58 80269378 8C82000C */  lw    $v0, 0xc($a0)
/* 197C5C 8026937C 3C06802A */  lui   $a2, 0x802a
/* 197C60 80269380 80C6FC3E */  lb    $a2, -0x3c2($a2)
/* 197C64 80269384 0C0B2026 */  jal   set_variable
/* 197C68 80269388 8C450000 */   lw    $a1, ($v0)
/* 197C6C 8026938C 8FBF0010 */  lw    $ra, 0x10($sp)
/* 197C70 80269390 24020002 */  addiu $v0, $zero, 2
/* 197C74 80269394 03E00008 */  jr    $ra
/* 197C78 80269398 27BD0018 */   addiu $sp, $sp, 0x18

/* 197C7C 8026939C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 197C80 802693A0 AFBF0018 */  sw    $ra, 0x18($sp)
/* 197C84 802693A4 AFB10014 */  sw    $s1, 0x14($sp)
/* 197C88 802693A8 AFB00010 */  sw    $s0, 0x10($sp)
/* 197C8C 802693AC 8C82000C */  lw    $v0, 0xc($a0)
/* 197C90 802693B0 3C11802A */  lui   $s1, 0x802a
/* 197C94 802693B4 2631FBE0 */  addiu $s1, $s1, -0x420
/* 197C98 802693B8 8C450000 */  lw    $a1, ($v0)
/* 197C9C 802693BC 0C0B1EAF */  jal   get_variable
/* 197CA0 802693C0 0220802D */   daddu $s0, $s1, $zero
/* 197CA4 802693C4 10400003 */  beqz  $v0, .L802693D4
/* 197CA8 802693C8 24020001 */   addiu $v0, $zero, 1
/* 197CAC 802693CC 0809A4F6 */  j     .L802693D8
/* 197CB0 802693D0 A222005E */   sb    $v0, 0x5e($s1)

.L802693D4:
/* 197CB4 802693D4 A200005E */  sb    $zero, 0x5e($s0)
.L802693D8:
/* 197CB8 802693D8 8FBF0018 */  lw    $ra, 0x18($sp)
/* 197CBC 802693DC 8FB10014 */  lw    $s1, 0x14($sp)
/* 197CC0 802693E0 8FB00010 */  lw    $s0, 0x10($sp)
/* 197CC4 802693E4 24020002 */  addiu $v0, $zero, 2
/* 197CC8 802693E8 03E00008 */  jr    $ra
/* 197CCC 802693EC 27BD0020 */   addiu $sp, $sp, 0x20

/* 197CD0 802693F0 3C02800E */  lui   $v0, 0x800e
/* 197CD4 802693F4 2442C070 */  addiu $v0, $v0, -0x3f90
/* 197CD8 802693F8 8C430000 */  lw    $v1, ($v0)
/* 197CDC 802693FC 2404BFFF */  addiu $a0, $zero, -0x4001
/* 197CE0 80269400 00641824 */  and   $v1, $v1, $a0
/* 197CE4 80269404 AC430000 */  sw    $v1, ($v0)
/* 197CE8 80269408 03E00008 */  jr    $ra
/* 197CEC 8026940C 24020002 */   addiu $v0, $zero, 2

