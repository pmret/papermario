.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240AE4_C617F4
/* C617F4 80240AE4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C617F8 80240AE8 AFBF0010 */  sw        $ra, 0x10($sp)
/* C617FC 80240AEC 0C00EAD2 */  jal       get_npc_safe
/* C61800 80240AF0 8C84014C */   lw       $a0, 0x14c($a0)
/* C61804 80240AF4 0040182D */  daddu     $v1, $v0, $zero
/* C61808 80240AF8 846200A8 */  lh        $v0, 0xa8($v1)
/* C6180C 80240AFC C462003C */  lwc1      $f2, 0x3c($v1)
/* C61810 80240B00 906400A9 */  lbu       $a0, 0xa9($v1)
/* C61814 80240B04 44820000 */  mtc1      $v0, $f0
/* C61818 80240B08 00000000 */  nop       
/* C6181C 80240B0C 46800020 */  cvt.s.w   $f0, $f0
/* C61820 80240B10 46001081 */  sub.s     $f2, $f2, $f0
/* C61824 80240B14 A06400AB */  sb        $a0, 0xab($v1)
/* C61828 80240B18 E462003C */  swc1      $f2, 0x3c($v1)
/* C6182C 80240B1C 8FBF0010 */  lw        $ra, 0x10($sp)
/* C61830 80240B20 24020002 */  addiu     $v0, $zero, 2
/* C61834 80240B24 03E00008 */  jr        $ra
/* C61838 80240B28 27BD0018 */   addiu    $sp, $sp, 0x18
