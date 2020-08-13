.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel GetPlayerHP
/* 1A2B14 80274234 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 1A2B18 80274238 AFBF0010 */  sw    $ra, 0x10($sp)
/* 1A2B1C 8027423C 8C82000C */  lw    $v0, 0xc($a0)
/* 1A2B20 80274240 3C068011 */  lui   $a2, 0x8011
/* 1A2B24 80274244 80C6F292 */  lb    $a2, -0xd6e($a2)
/* 1A2B28 80274248 0C0B2026 */  jal   set_variable
/* 1A2B2C 8027424C 8C450000 */   lw    $a1, ($v0)
/* 1A2B30 80274250 8FBF0010 */  lw    $ra, 0x10($sp)
/* 1A2B34 80274254 24020002 */  addiu $v0, $zero, 2
/* 1A2B38 80274258 03E00008 */  jr    $ra
/* 1A2B3C 8027425C 27BD0018 */   addiu $sp, $sp, 0x18

