.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240814_97BE44
/* 97BE44 80240814 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 97BE48 80240818 AFBF0010 */  sw        $ra, 0x10($sp)
/* 97BE4C 8024081C 0C00EAD2 */  jal       get_npc_safe
/* 97BE50 80240820 8C84014C */   lw       $a0, 0x14c($a0)
/* 97BE54 80240824 0040182D */  daddu     $v1, $v0, $zero
/* 97BE58 80240828 846200A8 */  lh        $v0, 0xa8($v1)
/* 97BE5C 8024082C C462003C */  lwc1      $f2, 0x3c($v1)
/* 97BE60 80240830 906400A9 */  lbu       $a0, 0xa9($v1)
/* 97BE64 80240834 44820000 */  mtc1      $v0, $f0
/* 97BE68 80240838 00000000 */  nop       
/* 97BE6C 8024083C 46800020 */  cvt.s.w   $f0, $f0
/* 97BE70 80240840 46001081 */  sub.s     $f2, $f2, $f0
/* 97BE74 80240844 A06400AB */  sb        $a0, 0xab($v1)
/* 97BE78 80240848 E462003C */  swc1      $f2, 0x3c($v1)
/* 97BE7C 8024084C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 97BE80 80240850 24020002 */  addiu     $v0, $zero, 2
/* 97BE84 80240854 03E00008 */  jr        $ra
/* 97BE88 80240858 27BD0018 */   addiu    $sp, $sp, 0x18
