.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241844_C72CC4
/* C72CC4 80241844 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C72CC8 80241848 AFB00010 */  sw        $s0, 0x10($sp)
/* C72CCC 8024184C 0080802D */  daddu     $s0, $a0, $zero
/* C72CD0 80241850 AFBF0014 */  sw        $ra, 0x14($sp)
/* C72CD4 80241854 8E020148 */  lw        $v0, 0x148($s0)
/* C72CD8 80241858 0C00EABB */  jal       get_npc_unsafe
/* C72CDC 8024185C 84440008 */   lh       $a0, 8($v0)
/* C72CE0 80241860 0040202D */  daddu     $a0, $v0, $zero
/* C72CE4 80241864 8482008E */  lh        $v0, 0x8e($a0)
/* C72CE8 80241868 9483008E */  lhu       $v1, 0x8e($a0)
/* C72CEC 8024186C 18400005 */  blez      $v0, .L80241884
/* C72CF0 80241870 2462FFFF */   addiu    $v0, $v1, -1
/* C72CF4 80241874 A482008E */  sh        $v0, 0x8e($a0)
/* C72CF8 80241878 00021400 */  sll       $v0, $v0, 0x10
/* C72CFC 8024187C 1C400006 */  bgtz      $v0, .L80241898
/* C72D00 80241880 00000000 */   nop      
.L80241884:
/* C72D04 80241884 8482008C */  lh        $v0, 0x8c($a0)
/* C72D08 80241888 14400003 */  bnez      $v0, .L80241898
/* C72D0C 8024188C 2402000E */   addiu    $v0, $zero, 0xe
/* C72D10 80241890 A480008E */  sh        $zero, 0x8e($a0)
/* C72D14 80241894 AE020070 */  sw        $v0, 0x70($s0)
.L80241898:
/* C72D18 80241898 8FBF0014 */  lw        $ra, 0x14($sp)
/* C72D1C 8024189C 8FB00010 */  lw        $s0, 0x10($sp)
/* C72D20 802418A0 03E00008 */  jr        $ra
/* C72D24 802418A4 27BD0018 */   addiu    $sp, $sp, 0x18
