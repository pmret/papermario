.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel iwa_10_UnkFunc39
/* 91ED70 80240800 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 91ED74 80240804 AFBF0010 */  sw        $ra, 0x10($sp)
/* 91ED78 80240808 8C82000C */  lw        $v0, 0xc($a0)
/* 91ED7C 8024080C 0C0B1EAF */  jal       get_variable
/* 91ED80 80240810 8C450000 */   lw       $a1, ($v0)
/* 91ED84 80240814 0040202D */  daddu     $a0, $v0, $zero
/* 91ED88 80240818 8C830000 */  lw        $v1, ($a0)
/* 91ED8C 8024081C 34630010 */  ori       $v1, $v1, 0x10
/* 91ED90 80240820 AC830000 */  sw        $v1, ($a0)
/* 91ED94 80240824 8FBF0010 */  lw        $ra, 0x10($sp)
/* 91ED98 80240828 24020002 */  addiu     $v0, $zero, 2
/* 91ED9C 8024082C 03E00008 */  jr        $ra
/* 91EDA0 80240830 27BD0018 */   addiu    $sp, $sp, 0x18
