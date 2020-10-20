.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802418A8
/* A087A8 802418A8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A087AC 802418AC AFB00010 */  sw        $s0, 0x10($sp)
/* A087B0 802418B0 0080802D */  daddu     $s0, $a0, $zero
/* A087B4 802418B4 AFBF0014 */  sw        $ra, 0x14($sp)
/* A087B8 802418B8 8E020148 */  lw        $v0, 0x148($s0)
/* A087BC 802418BC 0C00EABB */  jal       get_npc_unsafe
/* A087C0 802418C0 84440008 */   lh       $a0, 8($v0)
/* A087C4 802418C4 0040202D */  daddu     $a0, $v0, $zero
/* A087C8 802418C8 8482008E */  lh        $v0, 0x8e($a0)
/* A087CC 802418CC 9483008E */  lhu       $v1, 0x8e($a0)
/* A087D0 802418D0 18400005 */  blez      $v0, .L802418E8
/* A087D4 802418D4 2462FFFF */   addiu    $v0, $v1, -1
/* A087D8 802418D8 A482008E */  sh        $v0, 0x8e($a0)
/* A087DC 802418DC 00021400 */  sll       $v0, $v0, 0x10
/* A087E0 802418E0 1C400006 */  bgtz      $v0, .L802418FC
/* A087E4 802418E4 00000000 */   nop      
.L802418E8:
/* A087E8 802418E8 8482008C */  lh        $v0, 0x8c($a0)
/* A087EC 802418EC 14400003 */  bnez      $v0, .L802418FC
/* A087F0 802418F0 2402000E */   addiu    $v0, $zero, 0xe
/* A087F4 802418F4 A480008E */  sh        $zero, 0x8e($a0)
/* A087F8 802418F8 AE020070 */  sw        $v0, 0x70($s0)
.L802418FC:
/* A087FC 802418FC 8FBF0014 */  lw        $ra, 0x14($sp)
/* A08800 80241900 8FB00010 */  lw        $s0, 0x10($sp)
/* A08804 80241904 03E00008 */  jr        $ra
/* A08808 80241908 27BD0018 */   addiu    $sp, $sp, 0x18
