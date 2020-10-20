.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242134
/* 88AD04 80242134 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 88AD08 80242138 AFBF0010 */  sw        $ra, 0x10($sp)
/* 88AD0C 8024213C 0C00EAD2 */  jal       get_npc_safe
/* 88AD10 80242140 8C84014C */   lw       $a0, 0x14c($a0)
/* 88AD14 80242144 0040182D */  daddu     $v1, $v0, $zero
/* 88AD18 80242148 846200A8 */  lh        $v0, 0xa8($v1)
/* 88AD1C 8024214C C462003C */  lwc1      $f2, 0x3c($v1)
/* 88AD20 80242150 906400A9 */  lbu       $a0, 0xa9($v1)
/* 88AD24 80242154 44820000 */  mtc1      $v0, $f0
/* 88AD28 80242158 00000000 */  nop       
/* 88AD2C 8024215C 46800020 */  cvt.s.w   $f0, $f0
/* 88AD30 80242160 46001081 */  sub.s     $f2, $f2, $f0
/* 88AD34 80242164 A06400AB */  sb        $a0, 0xab($v1)
/* 88AD38 80242168 E462003C */  swc1      $f2, 0x3c($v1)
/* 88AD3C 8024216C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 88AD40 80242170 24020002 */  addiu     $v0, $zero, 2
/* 88AD44 80242174 03E00008 */  jr        $ra
/* 88AD48 80242178 27BD0018 */   addiu    $sp, $sp, 0x18
