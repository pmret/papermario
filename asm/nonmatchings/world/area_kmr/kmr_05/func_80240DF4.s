.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240DF4
/* 8CEE64 80240DF4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8CEE68 80240DF8 AFB00010 */  sw        $s0, 0x10($sp)
/* 8CEE6C 80240DFC 0080802D */  daddu     $s0, $a0, $zero
/* 8CEE70 80240E00 AFBF0014 */  sw        $ra, 0x14($sp)
/* 8CEE74 80240E04 8E020148 */  lw        $v0, 0x148($s0)
/* 8CEE78 80240E08 0C00EABB */  jal       get_npc_unsafe
/* 8CEE7C 80240E0C 84440008 */   lh       $a0, 8($v0)
/* 8CEE80 80240E10 0040202D */  daddu     $a0, $v0, $zero
/* 8CEE84 80240E14 8482008E */  lh        $v0, 0x8e($a0)
/* 8CEE88 80240E18 9483008E */  lhu       $v1, 0x8e($a0)
/* 8CEE8C 80240E1C 18400005 */  blez      $v0, .L80240E34
/* 8CEE90 80240E20 2462FFFF */   addiu    $v0, $v1, -1
/* 8CEE94 80240E24 A482008E */  sh        $v0, 0x8e($a0)
/* 8CEE98 80240E28 00021400 */  sll       $v0, $v0, 0x10
/* 8CEE9C 80240E2C 1C400006 */  bgtz      $v0, .L80240E48
/* 8CEEA0 80240E30 00000000 */   nop      
.L80240E34:
/* 8CEEA4 80240E34 8482008C */  lh        $v0, 0x8c($a0)
/* 8CEEA8 80240E38 14400003 */  bnez      $v0, .L80240E48
/* 8CEEAC 80240E3C 2402000E */   addiu    $v0, $zero, 0xe
/* 8CEEB0 80240E40 A480008E */  sh        $zero, 0x8e($a0)
/* 8CEEB4 80240E44 AE020070 */  sw        $v0, 0x70($s0)
.L80240E48:
/* 8CEEB8 80240E48 8FBF0014 */  lw        $ra, 0x14($sp)
/* 8CEEBC 80240E4C 8FB00010 */  lw        $s0, 0x10($sp)
/* 8CEEC0 80240E50 03E00008 */  jr        $ra
/* 8CEEC4 80240E54 27BD0018 */   addiu    $sp, $sp, 0x18
