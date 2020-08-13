.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80130F70
/* 0C7670 80130F70 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0C7674 80130F74 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0C7678 80130F78 8C820000 */  lw    $v0, ($a0)
/* 0C767C 80130F7C 84830020 */  lh    $v1, 0x20($a0)
/* 0C7680 80130F80 34420040 */  ori   $v0, $v0, 0x40
/* 0C7684 80130F84 04600006 */  bltz  $v1, .L80130FA0
/* 0C7688 80130F88 AC820000 */   sw    $v0, ($a0)
/* 0C768C 80130F8C 0C044181 */  jal   get_shadow_by_index
/* 0C7690 80130F90 0060202D */   daddu $a0, $v1, $zero
/* 0C7694 80130F94 8C430000 */  lw    $v1, ($v0)
/* 0C7698 80130F98 34630001 */  ori   $v1, $v1, 1
/* 0C769C 80130F9C AC430000 */  sw    $v1, ($v0)
.L80130FA0:
/* 0C76A0 80130FA0 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0C76A4 80130FA4 03E00008 */  jr    $ra
/* 0C76A8 80130FA8 27BD0018 */   addiu $sp, $sp, 0x18

