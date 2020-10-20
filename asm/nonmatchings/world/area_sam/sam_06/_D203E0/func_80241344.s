.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241344
/* D211D4 80241344 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D211D8 80241348 AFB00010 */  sw        $s0, 0x10($sp)
/* D211DC 8024134C 0080802D */  daddu     $s0, $a0, $zero
/* D211E0 80241350 AFBF0014 */  sw        $ra, 0x14($sp)
/* D211E4 80241354 8E020148 */  lw        $v0, 0x148($s0)
/* D211E8 80241358 0C00EABB */  jal       get_npc_unsafe
/* D211EC 8024135C 84440008 */   lh       $a0, 8($v0)
/* D211F0 80241360 0040202D */  daddu     $a0, $v0, $zero
/* D211F4 80241364 8482008E */  lh        $v0, 0x8e($a0)
/* D211F8 80241368 9483008E */  lhu       $v1, 0x8e($a0)
/* D211FC 8024136C 18400005 */  blez      $v0, .L80241384
/* D21200 80241370 2462FFFF */   addiu    $v0, $v1, -1
/* D21204 80241374 A482008E */  sh        $v0, 0x8e($a0)
/* D21208 80241378 00021400 */  sll       $v0, $v0, 0x10
/* D2120C 8024137C 1C400006 */  bgtz      $v0, .L80241398
/* D21210 80241380 00000000 */   nop      
.L80241384:
/* D21214 80241384 8482008C */  lh        $v0, 0x8c($a0)
/* D21218 80241388 14400003 */  bnez      $v0, .L80241398
/* D2121C 8024138C 2402000E */   addiu    $v0, $zero, 0xe
/* D21220 80241390 A480008E */  sh        $zero, 0x8e($a0)
/* D21224 80241394 AE020070 */  sw        $v0, 0x70($s0)
.L80241398:
/* D21228 80241398 8FBF0014 */  lw        $ra, 0x14($sp)
/* D2122C 8024139C 8FB00010 */  lw        $s0, 0x10($sp)
/* D21230 802413A0 03E00008 */  jr        $ra
/* D21234 802413A4 27BD0018 */   addiu    $sp, $sp, 0x18
