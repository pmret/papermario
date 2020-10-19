.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242424_C33904
/* C33904 80242424 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C33908 80242428 AFB00010 */  sw        $s0, 0x10($sp)
/* C3390C 8024242C 0080802D */  daddu     $s0, $a0, $zero
/* C33910 80242430 AFBF0014 */  sw        $ra, 0x14($sp)
/* C33914 80242434 8E020148 */  lw        $v0, 0x148($s0)
/* C33918 80242438 0C00EABB */  jal       get_npc_unsafe
/* C3391C 8024243C 84440008 */   lh       $a0, 8($v0)
/* C33920 80242440 0040182D */  daddu     $v1, $v0, $zero
/* C33924 80242444 8462008C */  lh        $v0, 0x8c($v1)
/* C33928 80242448 14400009 */  bnez      $v0, .L80242470
/* C3392C 8024244C 00000000 */   nop      
/* C33930 80242450 9462008E */  lhu       $v0, 0x8e($v1)
/* C33934 80242454 2442FFFF */  addiu     $v0, $v0, -1
/* C33938 80242458 A462008E */  sh        $v0, 0x8e($v1)
/* C3393C 8024245C 00021400 */  sll       $v0, $v0, 0x10
/* C33940 80242460 1C400003 */  bgtz      $v0, .L80242470
/* C33944 80242464 00000000 */   nop      
/* C33948 80242468 A460008E */  sh        $zero, 0x8e($v1)
/* C3394C 8024246C AE000070 */  sw        $zero, 0x70($s0)
.L80242470:
/* C33950 80242470 8FBF0014 */  lw        $ra, 0x14($sp)
/* C33954 80242474 8FB00010 */  lw        $s0, 0x10($sp)
/* C33958 80242478 03E00008 */  jr        $ra
/* C3395C 8024247C 27BD0018 */   addiu    $sp, $sp, 0x18
