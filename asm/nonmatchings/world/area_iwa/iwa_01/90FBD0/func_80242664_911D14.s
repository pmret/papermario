.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242664_911D14
/* 911D14 80242664 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 911D18 80242668 AFB10014 */  sw        $s1, 0x14($sp)
/* 911D1C 8024266C 0080882D */  daddu     $s1, $a0, $zero
/* 911D20 80242670 AFBF0018 */  sw        $ra, 0x18($sp)
/* 911D24 80242674 AFB00010 */  sw        $s0, 0x10($sp)
/* 911D28 80242678 8E220148 */  lw        $v0, 0x148($s1)
/* 911D2C 8024267C 0C00EABB */  jal       get_npc_unsafe
/* 911D30 80242680 84440008 */   lh       $a0, 8($v0)
/* 911D34 80242684 0040802D */  daddu     $s0, $v0, $zero
/* 911D38 80242688 9602008E */  lhu       $v0, 0x8e($s0)
/* 911D3C 8024268C 2442FFFF */  addiu     $v0, $v0, -1
/* 911D40 80242690 A602008E */  sh        $v0, 0x8e($s0)
/* 911D44 80242694 00021400 */  sll       $v0, $v0, 0x10
/* 911D48 80242698 1C40000F */  bgtz      $v0, .L802426D8
/* 911D4C 8024269C 00000000 */   nop      
/* 911D50 802426A0 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 911D54 802426A4 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 911D58 802426A8 C60C0038 */  lwc1      $f12, 0x38($s0)
/* 911D5C 802426AC C60E0040 */  lwc1      $f14, 0x40($s0)
/* 911D60 802426B0 8C460028 */  lw        $a2, 0x28($v0)
/* 911D64 802426B4 0C00A720 */  jal       atan2
/* 911D68 802426B8 8C470030 */   lw       $a3, 0x30($v0)
/* 911D6C 802426BC 2402001A */  addiu     $v0, $zero, 0x1a
/* 911D70 802426C0 A60200A8 */  sh        $v0, 0xa8($s0)
/* 911D74 802426C4 24020018 */  addiu     $v0, $zero, 0x18
/* 911D78 802426C8 A60200A6 */  sh        $v0, 0xa6($s0)
/* 911D7C 802426CC 24020004 */  addiu     $v0, $zero, 4
/* 911D80 802426D0 E600000C */  swc1      $f0, 0xc($s0)
/* 911D84 802426D4 AE220070 */  sw        $v0, 0x70($s1)
.L802426D8:
/* 911D88 802426D8 8FBF0018 */  lw        $ra, 0x18($sp)
/* 911D8C 802426DC 8FB10014 */  lw        $s1, 0x14($sp)
/* 911D90 802426E0 8FB00010 */  lw        $s0, 0x10($sp)
/* 911D94 802426E4 03E00008 */  jr        $ra
/* 911D98 802426E8 27BD0020 */   addiu    $sp, $sp, 0x20
