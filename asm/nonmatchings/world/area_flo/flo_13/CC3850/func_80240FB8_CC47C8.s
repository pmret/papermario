.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240FB8_CC47C8
/* CC47C8 80240FB8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CC47CC 80240FBC AFB00010 */  sw        $s0, 0x10($sp)
/* CC47D0 80240FC0 0080802D */  daddu     $s0, $a0, $zero
/* CC47D4 80240FC4 AFBF0014 */  sw        $ra, 0x14($sp)
/* CC47D8 80240FC8 8E020148 */  lw        $v0, 0x148($s0)
/* CC47DC 80240FCC 0C00EABB */  jal       get_npc_unsafe
/* CC47E0 80240FD0 84440008 */   lh       $a0, 8($v0)
/* CC47E4 80240FD4 0040202D */  daddu     $a0, $v0, $zero
/* CC47E8 80240FD8 8482008E */  lh        $v0, 0x8e($a0)
/* CC47EC 80240FDC 9483008E */  lhu       $v1, 0x8e($a0)
/* CC47F0 80240FE0 18400005 */  blez      $v0, .L80240FF8
/* CC47F4 80240FE4 2462FFFF */   addiu    $v0, $v1, -1
/* CC47F8 80240FE8 A482008E */  sh        $v0, 0x8e($a0)
/* CC47FC 80240FEC 00021400 */  sll       $v0, $v0, 0x10
/* CC4800 80240FF0 1C400006 */  bgtz      $v0, .L8024100C
/* CC4804 80240FF4 00000000 */   nop      
.L80240FF8:
/* CC4808 80240FF8 8482008C */  lh        $v0, 0x8c($a0)
/* CC480C 80240FFC 14400003 */  bnez      $v0, .L8024100C
/* CC4810 80241000 2402000E */   addiu    $v0, $zero, 0xe
/* CC4814 80241004 A480008E */  sh        $zero, 0x8e($a0)
/* CC4818 80241008 AE020070 */  sw        $v0, 0x70($s0)
.L8024100C:
/* CC481C 8024100C 8FBF0014 */  lw        $ra, 0x14($sp)
/* CC4820 80241010 8FB00010 */  lw        $s0, 0x10($sp)
/* CC4824 80241014 03E00008 */  jr        $ra
/* CC4828 80241018 27BD0018 */   addiu    $sp, $sp, 0x18
