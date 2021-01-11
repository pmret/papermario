.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241114_ED1104
/* ED1104 80241114 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* ED1108 80241118 AFB00010 */  sw        $s0, 0x10($sp)
/* ED110C 8024111C 0080802D */  daddu     $s0, $a0, $zero
/* ED1110 80241120 AFBF0014 */  sw        $ra, 0x14($sp)
/* ED1114 80241124 8E020148 */  lw        $v0, 0x148($s0)
/* ED1118 80241128 0C00F92F */  jal       func_8003E4BC
/* ED111C 8024112C 84440008 */   lh       $a0, 8($v0)
/* ED1120 80241130 0040202D */  daddu     $a0, $v0, $zero
/* ED1124 80241134 8482008E */  lh        $v0, 0x8e($a0)
/* ED1128 80241138 9483008E */  lhu       $v1, 0x8e($a0)
/* ED112C 8024113C 18400005 */  blez      $v0, .L80241154
/* ED1130 80241140 2462FFFF */   addiu    $v0, $v1, -1
/* ED1134 80241144 A482008E */  sh        $v0, 0x8e($a0)
/* ED1138 80241148 00021400 */  sll       $v0, $v0, 0x10
/* ED113C 8024114C 1C400006 */  bgtz      $v0, .L80241168
/* ED1140 80241150 00000000 */   nop      
.L80241154:
/* ED1144 80241154 8482008C */  lh        $v0, 0x8c($a0)
/* ED1148 80241158 14400003 */  bnez      $v0, .L80241168
/* ED114C 8024115C 2402000E */   addiu    $v0, $zero, 0xe
/* ED1150 80241160 A480008E */  sh        $zero, 0x8e($a0)
/* ED1154 80241164 AE020070 */  sw        $v0, 0x70($s0)
.L80241168:
/* ED1158 80241168 8FBF0014 */  lw        $ra, 0x14($sp)
/* ED115C 8024116C 8FB00010 */  lw        $s0, 0x10($sp)
/* ED1160 80241170 03E00008 */  jr        $ra
/* ED1164 80241174 27BD0018 */   addiu    $sp, $sp, 0x18
