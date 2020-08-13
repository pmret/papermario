.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel GetOwnerID
/* 19C6E0 8026DE00 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 19C6E4 8026DE04 AFBF0010 */  sw    $ra, 0x10($sp)
/* 19C6E8 8026DE08 8C82000C */  lw    $v0, 0xc($a0)
/* 19C6EC 8026DE0C 8C860148 */  lw    $a2, 0x148($a0)
/* 19C6F0 8026DE10 0C0B2026 */  jal   set_variable
/* 19C6F4 8026DE14 8C450000 */   lw    $a1, ($v0)
/* 19C6F8 8026DE18 8FBF0010 */  lw    $ra, 0x10($sp)
/* 19C6FC 8026DE1C 24020002 */  addiu $v0, $zero, 2
/* 19C700 8026DE20 03E00008 */  jr    $ra
/* 19C704 8026DE24 27BD0018 */   addiu $sp, $sp, 0x18

