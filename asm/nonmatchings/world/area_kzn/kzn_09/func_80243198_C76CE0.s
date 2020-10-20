.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243198_C79E78
/* C79E78 80243198 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C79E7C 8024319C AFBF0010 */  sw        $ra, 0x10($sp)
/* C79E80 802431A0 0C00EAD2 */  jal       get_npc_safe
/* C79E84 802431A4 8C84014C */   lw       $a0, 0x14c($a0)
/* C79E88 802431A8 0040182D */  daddu     $v1, $v0, $zero
/* C79E8C 802431AC 846200A8 */  lh        $v0, 0xa8($v1)
/* C79E90 802431B0 C462003C */  lwc1      $f2, 0x3c($v1)
/* C79E94 802431B4 906400A9 */  lbu       $a0, 0xa9($v1)
/* C79E98 802431B8 44820000 */  mtc1      $v0, $f0
/* C79E9C 802431BC 00000000 */  nop       
/* C79EA0 802431C0 46800020 */  cvt.s.w   $f0, $f0
/* C79EA4 802431C4 46001081 */  sub.s     $f2, $f2, $f0
/* C79EA8 802431C8 A06400AB */  sb        $a0, 0xab($v1)
/* C79EAC 802431CC E462003C */  swc1      $f2, 0x3c($v1)
/* C79EB0 802431D0 8FBF0010 */  lw        $ra, 0x10($sp)
/* C79EB4 802431D4 24020002 */  addiu     $v0, $zero, 2
/* C79EB8 802431D8 03E00008 */  jr        $ra
/* C79EBC 802431DC 27BD0018 */   addiu    $sp, $sp, 0x18
