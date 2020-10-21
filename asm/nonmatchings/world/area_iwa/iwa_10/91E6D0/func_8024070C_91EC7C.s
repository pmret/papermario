.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024070C_91EC7C
/* 91EC7C 8024070C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 91EC80 80240710 AFBF0010 */  sw        $ra, 0x10($sp)
/* 91EC84 80240714 8C82000C */  lw        $v0, 0xc($a0)
/* 91EC88 80240718 0C0B1EAF */  jal       get_variable
/* 91EC8C 8024071C 8C450000 */   lw       $a1, ($v0)
/* 91EC90 80240720 0C03AC5A */  jal       func_800EB168
/* 91EC94 80240724 0040202D */   daddu    $a0, $v0, $zero
/* 91EC98 80240728 8FBF0010 */  lw        $ra, 0x10($sp)
/* 91EC9C 8024072C 24020002 */  addiu     $v0, $zero, 2
/* 91ECA0 80240730 03E00008 */  jr        $ra
/* 91ECA4 80240734 27BD0018 */   addiu    $sp, $sp, 0x18
