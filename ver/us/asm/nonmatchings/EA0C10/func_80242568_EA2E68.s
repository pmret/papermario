.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242568_EA2E68
/* EA2E68 80242568 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EA2E6C 8024256C AFBF0010 */  sw        $ra, 0x10($sp)
/* EA2E70 80242570 0C00F94D */  jal       dead_get_npc_safe
/* EA2E74 80242574 8C84014C */   lw       $a0, 0x14c($a0)
/* EA2E78 80242578 0040182D */  daddu     $v1, $v0, $zero
/* EA2E7C 8024257C 846200A8 */  lh        $v0, 0xa8($v1)
/* EA2E80 80242580 C462003C */  lwc1      $f2, 0x3c($v1)
/* EA2E84 80242584 906400A9 */  lbu       $a0, 0xa9($v1)
/* EA2E88 80242588 44820000 */  mtc1      $v0, $f0
/* EA2E8C 8024258C 00000000 */  nop
/* EA2E90 80242590 46800020 */  cvt.s.w   $f0, $f0
/* EA2E94 80242594 46001081 */  sub.s     $f2, $f2, $f0
/* EA2E98 80242598 A06400AB */  sb        $a0, 0xab($v1)
/* EA2E9C 8024259C E462003C */  swc1      $f2, 0x3c($v1)
/* EA2EA0 802425A0 8FBF0010 */  lw        $ra, 0x10($sp)
/* EA2EA4 802425A4 24020002 */  addiu     $v0, $zero, 2
/* EA2EA8 802425A8 03E00008 */  jr        $ra
/* EA2EAC 802425AC 27BD0018 */   addiu    $sp, $sp, 0x18
