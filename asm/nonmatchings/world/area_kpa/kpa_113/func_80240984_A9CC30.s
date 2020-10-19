.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240984_A9D5B4
/* A9D5B4 80240984 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A9D5B8 80240988 AFBF0010 */  sw        $ra, 0x10($sp)
/* A9D5BC 8024098C 0C00EAD2 */  jal       get_npc_safe
/* A9D5C0 80240990 8C84014C */   lw       $a0, 0x14c($a0)
/* A9D5C4 80240994 0040182D */  daddu     $v1, $v0, $zero
/* A9D5C8 80240998 846200A8 */  lh        $v0, 0xa8($v1)
/* A9D5CC 8024099C C462003C */  lwc1      $f2, 0x3c($v1)
/* A9D5D0 802409A0 906400A9 */  lbu       $a0, 0xa9($v1)
/* A9D5D4 802409A4 44820000 */  mtc1      $v0, $f0
/* A9D5D8 802409A8 00000000 */  nop       
/* A9D5DC 802409AC 46800020 */  cvt.s.w   $f0, $f0
/* A9D5E0 802409B0 46001081 */  sub.s     $f2, $f2, $f0
/* A9D5E4 802409B4 A06400AB */  sb        $a0, 0xab($v1)
/* A9D5E8 802409B8 E462003C */  swc1      $f2, 0x3c($v1)
/* A9D5EC 802409BC 8FBF0010 */  lw        $ra, 0x10($sp)
/* A9D5F0 802409C0 24020002 */  addiu     $v0, $zero, 2
/* A9D5F4 802409C4 03E00008 */  jr        $ra
/* A9D5F8 802409C8 27BD0018 */   addiu    $sp, $sp, 0x18
