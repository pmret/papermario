.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E34_CF3A04
/* CF3A04 80240E34 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CF3A08 80240E38 AFB00010 */  sw        $s0, 0x10($sp)
/* CF3A0C 80240E3C 0080802D */  daddu     $s0, $a0, $zero
/* CF3A10 80240E40 AFBF0014 */  sw        $ra, 0x14($sp)
/* CF3A14 80240E44 8E020148 */  lw        $v0, 0x148($s0)
/* CF3A18 80240E48 0C00EABB */  jal       get_npc_unsafe
/* CF3A1C 80240E4C 84440008 */   lh       $a0, 8($v0)
/* CF3A20 80240E50 0040202D */  daddu     $a0, $v0, $zero
/* CF3A24 80240E54 8482008E */  lh        $v0, 0x8e($a0)
/* CF3A28 80240E58 9483008E */  lhu       $v1, 0x8e($a0)
/* CF3A2C 80240E5C 18400005 */  blez      $v0, .L80240E74
/* CF3A30 80240E60 2462FFFF */   addiu    $v0, $v1, -1
/* CF3A34 80240E64 A482008E */  sh        $v0, 0x8e($a0)
/* CF3A38 80240E68 00021400 */  sll       $v0, $v0, 0x10
/* CF3A3C 80240E6C 1C400006 */  bgtz      $v0, .L80240E88
/* CF3A40 80240E70 00000000 */   nop      
.L80240E74:
/* CF3A44 80240E74 8482008C */  lh        $v0, 0x8c($a0)
/* CF3A48 80240E78 14400003 */  bnez      $v0, .L80240E88
/* CF3A4C 80240E7C 2402000E */   addiu    $v0, $zero, 0xe
/* CF3A50 80240E80 A480008E */  sh        $zero, 0x8e($a0)
/* CF3A54 80240E84 AE020070 */  sw        $v0, 0x70($s0)
.L80240E88:
/* CF3A58 80240E88 8FBF0014 */  lw        $ra, 0x14($sp)
/* CF3A5C 80240E8C 8FB00010 */  lw        $s0, 0x10($sp)
/* CF3A60 80240E90 03E00008 */  jr        $ra
/* CF3A64 80240E94 27BD0018 */   addiu    $sp, $sp, 0x18
