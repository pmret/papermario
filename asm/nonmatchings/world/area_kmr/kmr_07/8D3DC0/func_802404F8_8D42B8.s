.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802404F8_8D42B8
/* 8D42B8 802404F8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8D42BC 802404FC AFB00010 */  sw        $s0, 0x10($sp)
/* 8D42C0 80240500 0080802D */  daddu     $s0, $a0, $zero
/* 8D42C4 80240504 AFBF0014 */  sw        $ra, 0x14($sp)
/* 8D42C8 80240508 8E020148 */  lw        $v0, 0x148($s0)
/* 8D42CC 8024050C 0C00EABB */  jal       get_npc_unsafe
/* 8D42D0 80240510 84440008 */   lh       $a0, 8($v0)
/* 8D42D4 80240514 9443008E */  lhu       $v1, 0x8e($v0)
/* 8D42D8 80240518 2463FFFF */  addiu     $v1, $v1, -1
/* 8D42DC 8024051C A443008E */  sh        $v1, 0x8e($v0)
/* 8D42E0 80240520 00031C00 */  sll       $v1, $v1, 0x10
/* 8D42E4 80240524 14600002 */  bnez      $v1, .L80240530
/* 8D42E8 80240528 2402000F */   addiu    $v0, $zero, 0xf
/* 8D42EC 8024052C AE020070 */  sw        $v0, 0x70($s0)
.L80240530:
/* 8D42F0 80240530 8FBF0014 */  lw        $ra, 0x14($sp)
/* 8D42F4 80240534 8FB00010 */  lw        $s0, 0x10($sp)
/* 8D42F8 80240538 03E00008 */  jr        $ra
/* 8D42FC 8024053C 27BD0018 */   addiu    $sp, $sp, 0x18
