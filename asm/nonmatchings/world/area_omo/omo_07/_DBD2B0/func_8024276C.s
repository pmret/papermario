.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024276C
/* DBFA1C 8024276C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* DBFA20 80242770 AFB00010 */  sw        $s0, 0x10($sp)
/* DBFA24 80242774 0080802D */  daddu     $s0, $a0, $zero
/* DBFA28 80242778 AFBF0014 */  sw        $ra, 0x14($sp)
/* DBFA2C 8024277C 8E020148 */  lw        $v0, 0x148($s0)
/* DBFA30 80242780 0C00EABB */  jal       get_npc_unsafe
/* DBFA34 80242784 84440008 */   lh       $a0, 8($v0)
/* DBFA38 80242788 0040202D */  daddu     $a0, $v0, $zero
/* DBFA3C 8024278C 8482008E */  lh        $v0, 0x8e($a0)
/* DBFA40 80242790 9483008E */  lhu       $v1, 0x8e($a0)
/* DBFA44 80242794 18400005 */  blez      $v0, .L802427AC
/* DBFA48 80242798 2462FFFF */   addiu    $v0, $v1, -1
/* DBFA4C 8024279C A482008E */  sh        $v0, 0x8e($a0)
/* DBFA50 802427A0 00021400 */  sll       $v0, $v0, 0x10
/* DBFA54 802427A4 1C400006 */  bgtz      $v0, .L802427C0
/* DBFA58 802427A8 00000000 */   nop      
.L802427AC:
/* DBFA5C 802427AC 8482008C */  lh        $v0, 0x8c($a0)
/* DBFA60 802427B0 14400003 */  bnez      $v0, .L802427C0
/* DBFA64 802427B4 2402000E */   addiu    $v0, $zero, 0xe
/* DBFA68 802427B8 A480008E */  sh        $zero, 0x8e($a0)
/* DBFA6C 802427BC AE020070 */  sw        $v0, 0x70($s0)
.L802427C0:
/* DBFA70 802427C0 8FBF0014 */  lw        $ra, 0x14($sp)
/* DBFA74 802427C4 8FB00010 */  lw        $s0, 0x10($sp)
/* DBFA78 802427C8 03E00008 */  jr        $ra
/* DBFA7C 802427CC 27BD0018 */   addiu    $sp, $sp, 0x18
