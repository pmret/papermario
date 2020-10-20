.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240934
/* A47894 80240934 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A47898 80240938 AFBF0010 */  sw        $ra, 0x10($sp)
/* A4789C 8024093C 0C00EAD2 */  jal       get_npc_safe
/* A478A0 80240940 8C84014C */   lw       $a0, 0x14c($a0)
/* A478A4 80240944 0040182D */  daddu     $v1, $v0, $zero
/* A478A8 80240948 846200A8 */  lh        $v0, 0xa8($v1)
/* A478AC 8024094C C462003C */  lwc1      $f2, 0x3c($v1)
/* A478B0 80240950 906400A9 */  lbu       $a0, 0xa9($v1)
/* A478B4 80240954 44820000 */  mtc1      $v0, $f0
/* A478B8 80240958 00000000 */  nop       
/* A478BC 8024095C 46800020 */  cvt.s.w   $f0, $f0
/* A478C0 80240960 46001081 */  sub.s     $f2, $f2, $f0
/* A478C4 80240964 A06400AB */  sb        $a0, 0xab($v1)
/* A478C8 80240968 E462003C */  swc1      $f2, 0x3c($v1)
/* A478CC 8024096C 8FBF0010 */  lw        $ra, 0x10($sp)
/* A478D0 80240970 24020002 */  addiu     $v0, $zero, 2
/* A478D4 80240974 03E00008 */  jr        $ra
/* A478D8 80240978 27BD0018 */   addiu    $sp, $sp, 0x18
