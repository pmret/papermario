.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241848_DB3B08
/* DB3B08 80241848 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* DB3B0C 8024184C AFB00010 */  sw        $s0, 0x10($sp)
/* DB3B10 80241850 0080802D */  daddu     $s0, $a0, $zero
/* DB3B14 80241854 AFBF0014 */  sw        $ra, 0x14($sp)
/* DB3B18 80241858 8E020148 */  lw        $v0, 0x148($s0)
/* DB3B1C 8024185C 0C00EABB */  jal       get_npc_unsafe
/* DB3B20 80241860 84440008 */   lh       $a0, 8($v0)
/* DB3B24 80241864 0040202D */  daddu     $a0, $v0, $zero
/* DB3B28 80241868 8482008E */  lh        $v0, 0x8e($a0)
/* DB3B2C 8024186C 9483008E */  lhu       $v1, 0x8e($a0)
/* DB3B30 80241870 18400005 */  blez      $v0, .L80241888
/* DB3B34 80241874 2462FFFF */   addiu    $v0, $v1, -1
/* DB3B38 80241878 A482008E */  sh        $v0, 0x8e($a0)
/* DB3B3C 8024187C 00021400 */  sll       $v0, $v0, 0x10
/* DB3B40 80241880 1C400006 */  bgtz      $v0, .L8024189C
/* DB3B44 80241884 00000000 */   nop      
.L80241888:
/* DB3B48 80241888 8482008C */  lh        $v0, 0x8c($a0)
/* DB3B4C 8024188C 14400003 */  bnez      $v0, .L8024189C
/* DB3B50 80241890 2402000E */   addiu    $v0, $zero, 0xe
/* DB3B54 80241894 A480008E */  sh        $zero, 0x8e($a0)
/* DB3B58 80241898 AE020070 */  sw        $v0, 0x70($s0)
.L8024189C:
/* DB3B5C 8024189C 8FBF0014 */  lw        $ra, 0x14($sp)
/* DB3B60 802418A0 8FB00010 */  lw        $s0, 0x10($sp)
/* DB3B64 802418A4 03E00008 */  jr        $ra
/* DB3B68 802418A8 27BD0018 */   addiu    $sp, $sp, 0x18
