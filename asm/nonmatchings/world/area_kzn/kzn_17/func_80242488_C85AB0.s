.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242488_C87F38
/* C87F38 80242488 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C87F3C 8024248C AFBF0010 */  sw        $ra, 0x10($sp)
/* C87F40 80242490 0C00EAD2 */  jal       get_npc_safe
/* C87F44 80242494 8C84014C */   lw       $a0, 0x14c($a0)
/* C87F48 80242498 0040182D */  daddu     $v1, $v0, $zero
/* C87F4C 8024249C 846200A8 */  lh        $v0, 0xa8($v1)
/* C87F50 802424A0 C462003C */  lwc1      $f2, 0x3c($v1)
/* C87F54 802424A4 906400A9 */  lbu       $a0, 0xa9($v1)
/* C87F58 802424A8 44820000 */  mtc1      $v0, $f0
/* C87F5C 802424AC 00000000 */  nop       
/* C87F60 802424B0 46800020 */  cvt.s.w   $f0, $f0
/* C87F64 802424B4 46001081 */  sub.s     $f2, $f2, $f0
/* C87F68 802424B8 A06400AB */  sb        $a0, 0xab($v1)
/* C87F6C 802424BC E462003C */  swc1      $f2, 0x3c($v1)
/* C87F70 802424C0 8FBF0010 */  lw        $ra, 0x10($sp)
/* C87F74 802424C4 24020002 */  addiu     $v0, $zero, 2
/* C87F78 802424C8 03E00008 */  jr        $ra
/* C87F7C 802424CC 27BD0018 */   addiu    $sp, $sp, 0x18
