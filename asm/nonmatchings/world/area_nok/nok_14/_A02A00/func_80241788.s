.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241788
/* A03FC8 80241788 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A03FCC 8024178C AFB00010 */  sw        $s0, 0x10($sp)
/* A03FD0 80241790 0080802D */  daddu     $s0, $a0, $zero
/* A03FD4 80241794 AFBF0014 */  sw        $ra, 0x14($sp)
/* A03FD8 80241798 8E020148 */  lw        $v0, 0x148($s0)
/* A03FDC 8024179C 0C00EABB */  jal       get_npc_unsafe
/* A03FE0 802417A0 84440008 */   lh       $a0, 8($v0)
/* A03FE4 802417A4 0040202D */  daddu     $a0, $v0, $zero
/* A03FE8 802417A8 8482008E */  lh        $v0, 0x8e($a0)
/* A03FEC 802417AC 9483008E */  lhu       $v1, 0x8e($a0)
/* A03FF0 802417B0 18400005 */  blez      $v0, .L802417C8
/* A03FF4 802417B4 2462FFFF */   addiu    $v0, $v1, -1
/* A03FF8 802417B8 A482008E */  sh        $v0, 0x8e($a0)
/* A03FFC 802417BC 00021400 */  sll       $v0, $v0, 0x10
/* A04000 802417C0 1C400006 */  bgtz      $v0, .L802417DC
/* A04004 802417C4 00000000 */   nop      
.L802417C8:
/* A04008 802417C8 8482008C */  lh        $v0, 0x8c($a0)
/* A0400C 802417CC 14400003 */  bnez      $v0, .L802417DC
/* A04010 802417D0 2402000E */   addiu    $v0, $zero, 0xe
/* A04014 802417D4 A480008E */  sh        $zero, 0x8e($a0)
/* A04018 802417D8 AE020070 */  sw        $v0, 0x70($s0)
.L802417DC:
/* A0401C 802417DC 8FBF0014 */  lw        $ra, 0x14($sp)
/* A04020 802417E0 8FB00010 */  lw        $s0, 0x10($sp)
/* A04024 802417E4 03E00008 */  jr        $ra
/* A04028 802417E8 27BD0018 */   addiu    $sp, $sp, 0x18
