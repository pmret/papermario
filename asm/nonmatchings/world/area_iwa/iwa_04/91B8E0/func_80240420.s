.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240420
/* 91BD00 80240420 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 91BD04 80240424 AFB10014 */  sw        $s1, 0x14($sp)
/* 91BD08 80240428 0080882D */  daddu     $s1, $a0, $zero
/* 91BD0C 8024042C AFBF0018 */  sw        $ra, 0x18($sp)
/* 91BD10 80240430 AFB00010 */  sw        $s0, 0x10($sp)
/* 91BD14 80240434 8E220148 */  lw        $v0, 0x148($s1)
/* 91BD18 80240438 0C00EABB */  jal       get_npc_unsafe
/* 91BD1C 8024043C 84440008 */   lh       $a0, 8($v0)
/* 91BD20 80240440 0040802D */  daddu     $s0, $v0, $zero
/* 91BD24 80240444 9602008E */  lhu       $v0, 0x8e($s0)
/* 91BD28 80240448 2442FFFF */  addiu     $v0, $v0, -1
/* 91BD2C 8024044C A602008E */  sh        $v0, 0x8e($s0)
/* 91BD30 80240450 00021400 */  sll       $v0, $v0, 0x10
/* 91BD34 80240454 1C40000F */  bgtz      $v0, .L80240494
/* 91BD38 80240458 00000000 */   nop      
/* 91BD3C 8024045C 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 91BD40 80240460 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 91BD44 80240464 C60C0038 */  lwc1      $f12, 0x38($s0)
/* 91BD48 80240468 C60E0040 */  lwc1      $f14, 0x40($s0)
/* 91BD4C 8024046C 8C460028 */  lw        $a2, 0x28($v0)
/* 91BD50 80240470 0C00A720 */  jal       atan2
/* 91BD54 80240474 8C470030 */   lw       $a3, 0x30($v0)
/* 91BD58 80240478 2402001A */  addiu     $v0, $zero, 0x1a
/* 91BD5C 8024047C A60200A8 */  sh        $v0, 0xa8($s0)
/* 91BD60 80240480 24020018 */  addiu     $v0, $zero, 0x18
/* 91BD64 80240484 A60200A6 */  sh        $v0, 0xa6($s0)
/* 91BD68 80240488 24020004 */  addiu     $v0, $zero, 4
/* 91BD6C 8024048C E600000C */  swc1      $f0, 0xc($s0)
/* 91BD70 80240490 AE220070 */  sw        $v0, 0x70($s1)
.L80240494:
/* 91BD74 80240494 8FBF0018 */  lw        $ra, 0x18($sp)
/* 91BD78 80240498 8FB10014 */  lw        $s1, 0x14($sp)
/* 91BD7C 8024049C 8FB00010 */  lw        $s0, 0x10($sp)
/* 91BD80 802404A0 03E00008 */  jr        $ra
/* 91BD84 802404A4 27BD0020 */   addiu    $sp, $sp, 0x20
