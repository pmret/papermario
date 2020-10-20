.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E24_C3B834
/* C3B834 80240E24 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C3B838 80240E28 AFB00010 */  sw        $s0, 0x10($sp)
/* C3B83C 80240E2C 0080802D */  daddu     $s0, $a0, $zero
/* C3B840 80240E30 AFBF0014 */  sw        $ra, 0x14($sp)
/* C3B844 80240E34 8E020148 */  lw        $v0, 0x148($s0)
/* C3B848 80240E38 0C00EABB */  jal       get_npc_unsafe
/* C3B84C 80240E3C 84440008 */   lh       $a0, 8($v0)
/* C3B850 80240E40 0040182D */  daddu     $v1, $v0, $zero
/* C3B854 80240E44 8462008C */  lh        $v0, 0x8c($v1)
/* C3B858 80240E48 14400009 */  bnez      $v0, .L80240E70
/* C3B85C 80240E4C 00000000 */   nop      
/* C3B860 80240E50 9462008E */  lhu       $v0, 0x8e($v1)
/* C3B864 80240E54 2442FFFF */  addiu     $v0, $v0, -1
/* C3B868 80240E58 A462008E */  sh        $v0, 0x8e($v1)
/* C3B86C 80240E5C 00021400 */  sll       $v0, $v0, 0x10
/* C3B870 80240E60 1C400003 */  bgtz      $v0, .L80240E70
/* C3B874 80240E64 00000000 */   nop      
/* C3B878 80240E68 A460008E */  sh        $zero, 0x8e($v1)
/* C3B87C 80240E6C AE000070 */  sw        $zero, 0x70($s0)
.L80240E70:
/* C3B880 80240E70 8FBF0014 */  lw        $ra, 0x14($sp)
/* C3B884 80240E74 8FB00010 */  lw        $s0, 0x10($sp)
/* C3B888 80240E78 03E00008 */  jr        $ra
/* C3B88C 80240E7C 27BD0018 */   addiu    $sp, $sp, 0x18
