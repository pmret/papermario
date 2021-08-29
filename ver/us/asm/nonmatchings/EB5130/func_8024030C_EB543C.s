.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024030C_EB543C
/* EB543C 8024030C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EB5440 80240310 AFBF0010 */  sw        $ra, 0x10($sp)
/* EB5444 80240314 8C82000C */  lw        $v0, 0xc($a0)
/* EB5448 80240318 3C068017 */  lui       $a2, %hi(D_80169B12)
/* EB544C 8024031C 84C69B12 */  lh        $a2, %lo(D_80169B12)($a2)
/* EB5450 80240320 0C0B551A */  jal       dead_evt_set_variable
/* EB5454 80240324 8C450000 */   lw       $a1, ($v0)
/* EB5458 80240328 8FBF0010 */  lw        $ra, 0x10($sp)
/* EB545C 8024032C 24020002 */  addiu     $v0, $zero, 2
/* EB5460 80240330 03E00008 */  jr        $ra
/* EB5464 80240334 27BD0018 */   addiu    $sp, $sp, 0x18
/* EB5468 80240338 00000000 */  nop
/* EB546C 8024033C 00000000 */  nop
