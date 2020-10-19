.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241114_CB6114
/* CB6114 80241114 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CB6118 80241118 AFB00010 */  sw        $s0, 0x10($sp)
/* CB611C 8024111C 0080802D */  daddu     $s0, $a0, $zero
/* CB6120 80241120 AFBF0014 */  sw        $ra, 0x14($sp)
/* CB6124 80241124 8E020148 */  lw        $v0, 0x148($s0)
/* CB6128 80241128 0C00EABB */  jal       get_npc_unsafe
/* CB612C 8024112C 84440008 */   lh       $a0, 8($v0)
/* CB6130 80241130 0040202D */  daddu     $a0, $v0, $zero
/* CB6134 80241134 8482008E */  lh        $v0, 0x8e($a0)
/* CB6138 80241138 9483008E */  lhu       $v1, 0x8e($a0)
/* CB613C 8024113C 18400005 */  blez      $v0, .L80241154
/* CB6140 80241140 2462FFFF */   addiu    $v0, $v1, -1
/* CB6144 80241144 A482008E */  sh        $v0, 0x8e($a0)
/* CB6148 80241148 00021400 */  sll       $v0, $v0, 0x10
/* CB614C 8024114C 1C400006 */  bgtz      $v0, .L80241168
/* CB6150 80241150 00000000 */   nop      
.L80241154:
/* CB6154 80241154 8482008C */  lh        $v0, 0x8c($a0)
/* CB6158 80241158 14400003 */  bnez      $v0, .L80241168
/* CB615C 8024115C 2402000E */   addiu    $v0, $zero, 0xe
/* CB6160 80241160 A480008E */  sh        $zero, 0x8e($a0)
/* CB6164 80241164 AE020070 */  sw        $v0, 0x70($s0)
.L80241168:
/* CB6168 80241168 8FBF0014 */  lw        $ra, 0x14($sp)
/* CB616C 8024116C 8FB00010 */  lw        $s0, 0x10($sp)
/* CB6170 80241170 03E00008 */  jr        $ra
/* CB6174 80241174 27BD0018 */   addiu    $sp, $sp, 0x18
