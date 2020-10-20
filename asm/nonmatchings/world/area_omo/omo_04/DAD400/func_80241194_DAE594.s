.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241194_DAE594
/* DAE594 80241194 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* DAE598 80241198 AFB00010 */  sw        $s0, 0x10($sp)
/* DAE59C 8024119C 0080802D */  daddu     $s0, $a0, $zero
/* DAE5A0 802411A0 AFBF0014 */  sw        $ra, 0x14($sp)
/* DAE5A4 802411A4 8E020148 */  lw        $v0, 0x148($s0)
/* DAE5A8 802411A8 0C00EABB */  jal       get_npc_unsafe
/* DAE5AC 802411AC 84440008 */   lh       $a0, 8($v0)
/* DAE5B0 802411B0 0040202D */  daddu     $a0, $v0, $zero
/* DAE5B4 802411B4 8482008E */  lh        $v0, 0x8e($a0)
/* DAE5B8 802411B8 9483008E */  lhu       $v1, 0x8e($a0)
/* DAE5BC 802411BC 18400005 */  blez      $v0, .L802411D4
/* DAE5C0 802411C0 2462FFFF */   addiu    $v0, $v1, -1
/* DAE5C4 802411C4 A482008E */  sh        $v0, 0x8e($a0)
/* DAE5C8 802411C8 00021400 */  sll       $v0, $v0, 0x10
/* DAE5CC 802411CC 1C400006 */  bgtz      $v0, .L802411E8
/* DAE5D0 802411D0 00000000 */   nop      
.L802411D4:
/* DAE5D4 802411D4 8482008C */  lh        $v0, 0x8c($a0)
/* DAE5D8 802411D8 14400003 */  bnez      $v0, .L802411E8
/* DAE5DC 802411DC 2402000E */   addiu    $v0, $zero, 0xe
/* DAE5E0 802411E0 A480008E */  sh        $zero, 0x8e($a0)
/* DAE5E4 802411E4 AE020070 */  sw        $v0, 0x70($s0)
.L802411E8:
/* DAE5E8 802411E8 8FBF0014 */  lw        $ra, 0x14($sp)
/* DAE5EC 802411EC 8FB00010 */  lw        $s0, 0x10($sp)
/* DAE5F0 802411F0 03E00008 */  jr        $ra
/* DAE5F4 802411F4 27BD0018 */   addiu    $sp, $sp, 0x18
