.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel SetOwnerID
/* 19C708 8026DE28 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 19C70C 8026DE2C AFB00010 */  sw    $s0, 0x10($sp)
/* 19C710 8026DE30 0080802D */  daddu $s0, $a0, $zero
/* 19C714 8026DE34 AFBF0014 */  sw    $ra, 0x14($sp)
/* 19C718 8026DE38 8E02000C */  lw    $v0, 0xc($s0)
/* 19C71C 8026DE3C 0C0B1EAF */  jal   get_variable
/* 19C720 8026DE40 8C450000 */   lw    $a1, ($v0)
/* 19C724 8026DE44 AE020148 */  sw    $v0, 0x148($s0)
/* 19C728 8026DE48 8FBF0014 */  lw    $ra, 0x14($sp)
/* 19C72C 8026DE4C 8FB00010 */  lw    $s0, 0x10($sp)
/* 19C730 8026DE50 24020002 */  addiu $v0, $zero, 2
/* 19C734 8026DE54 03E00008 */  jr    $ra
/* 19C738 8026DE58 27BD0018 */   addiu $sp, $sp, 0x18

