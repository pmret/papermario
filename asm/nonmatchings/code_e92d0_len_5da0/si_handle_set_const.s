.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel si_handle_set_const
/* 0EA140 802C5790 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0EA144 802C5794 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0EA148 802C5798 8C82000C */  lw    $v0, 0xc($a0)
/* 0EA14C 802C579C 8C450000 */  lw    $a1, ($v0)
/* 0EA150 802C57A0 0C0B2026 */  jal   set_variable
/* 0EA154 802C57A4 8C460004 */   lw    $a2, 4($v0)
/* 0EA158 802C57A8 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0EA15C 802C57AC 24020002 */  addiu $v0, $zero, 2
/* 0EA160 802C57B0 03E00008 */  jr    $ra
/* 0EA164 802C57B4 27BD0018 */   addiu $sp, $sp, 0x18

