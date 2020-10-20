.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802404F8_9C58D8
/* 9C58D8 802404F8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9C58DC 802404FC AFB00010 */  sw        $s0, 0x10($sp)
/* 9C58E0 80240500 0080802D */  daddu     $s0, $a0, $zero
/* 9C58E4 80240504 AFBF0014 */  sw        $ra, 0x14($sp)
/* 9C58E8 80240508 8E020148 */  lw        $v0, 0x148($s0)
/* 9C58EC 8024050C 0C00EABB */  jal       get_npc_unsafe
/* 9C58F0 80240510 84440008 */   lh       $a0, 8($v0)
/* 9C58F4 80240514 9443008E */  lhu       $v1, 0x8e($v0)
/* 9C58F8 80240518 2463FFFF */  addiu     $v1, $v1, -1
/* 9C58FC 8024051C A443008E */  sh        $v1, 0x8e($v0)
/* 9C5900 80240520 00031C00 */  sll       $v1, $v1, 0x10
/* 9C5904 80240524 14600002 */  bnez      $v1, .L80240530
/* 9C5908 80240528 2402000F */   addiu    $v0, $zero, 0xf
/* 9C590C 8024052C AE020070 */  sw        $v0, 0x70($s0)
.L80240530:
/* 9C5910 80240530 8FBF0014 */  lw        $ra, 0x14($sp)
/* 9C5914 80240534 8FB00010 */  lw        $s0, 0x10($sp)
/* 9C5918 80240538 03E00008 */  jr        $ra
/* 9C591C 8024053C 27BD0018 */   addiu    $sp, $sp, 0x18
