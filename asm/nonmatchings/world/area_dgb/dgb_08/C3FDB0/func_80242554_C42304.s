.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242554_C42304
/* C42304 80242554 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C42308 80242558 AFB00010 */  sw        $s0, 0x10($sp)
/* C4230C 8024255C 0080802D */  daddu     $s0, $a0, $zero
/* C42310 80242560 AFBF0014 */  sw        $ra, 0x14($sp)
/* C42314 80242564 8E020148 */  lw        $v0, 0x148($s0)
/* C42318 80242568 0C00EABB */  jal       get_npc_unsafe
/* C4231C 8024256C 84440008 */   lh       $a0, 8($v0)
/* C42320 80242570 0040202D */  daddu     $a0, $v0, $zero
/* C42324 80242574 8482008E */  lh        $v0, 0x8e($a0)
/* C42328 80242578 9483008E */  lhu       $v1, 0x8e($a0)
/* C4232C 8024257C 18400005 */  blez      $v0, .L80242594
/* C42330 80242580 2462FFFF */   addiu    $v0, $v1, -1
/* C42334 80242584 A482008E */  sh        $v0, 0x8e($a0)
/* C42338 80242588 00021400 */  sll       $v0, $v0, 0x10
/* C4233C 8024258C 1C400006 */  bgtz      $v0, .L802425A8
/* C42340 80242590 00000000 */   nop      
.L80242594:
/* C42344 80242594 8482008C */  lh        $v0, 0x8c($a0)
/* C42348 80242598 14400003 */  bnez      $v0, .L802425A8
/* C4234C 8024259C 2402000E */   addiu    $v0, $zero, 0xe
/* C42350 802425A0 A480008E */  sh        $zero, 0x8e($a0)
/* C42354 802425A4 AE020070 */  sw        $v0, 0x70($s0)
.L802425A8:
/* C42358 802425A8 8FBF0014 */  lw        $ra, 0x14($sp)
/* C4235C 802425AC 8FB00010 */  lw        $s0, 0x10($sp)
/* C42360 802425B0 03E00008 */  jr        $ra
/* C42364 802425B4 27BD0018 */   addiu    $sp, $sp, 0x18
