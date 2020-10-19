.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403B4_9A4A04
/* 9A4A04 802403B4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9A4A08 802403B8 AFB10014 */  sw        $s1, 0x14($sp)
/* 9A4A0C 802403BC 0080882D */  daddu     $s1, $a0, $zero
/* 9A4A10 802403C0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 9A4A14 802403C4 AFB00010 */  sw        $s0, 0x10($sp)
/* 9A4A18 802403C8 8E300148 */  lw        $s0, 0x148($s1)
/* 9A4A1C 802403CC 0C00EABB */  jal       get_npc_unsafe
/* 9A4A20 802403D0 86040008 */   lh       $a0, 8($s0)
/* 9A4A24 802403D4 0040202D */  daddu     $a0, $v0, $zero
/* 9A4A28 802403D8 9482008E */  lhu       $v0, 0x8e($a0)
/* 9A4A2C 802403DC 24030003 */  addiu     $v1, $zero, 3
/* 9A4A30 802403E0 24420001 */  addiu     $v0, $v0, 1
/* 9A4A34 802403E4 A482008E */  sh        $v0, 0x8e($a0)
/* 9A4A38 802403E8 00021400 */  sll       $v0, $v0, 0x10
/* 9A4A3C 802403EC 00021403 */  sra       $v0, $v0, 0x10
/* 9A4A40 802403F0 14430003 */  bne       $v0, $v1, .L80240400
/* 9A4A44 802403F4 00000000 */   nop      
/* 9A4A48 802403F8 96020086 */  lhu       $v0, 0x86($s0)
/* 9A4A4C 802403FC A48200A8 */  sh        $v0, 0xa8($a0)
.L80240400:
/* 9A4A50 80240400 8482008E */  lh        $v0, 0x8e($a0)
/* 9A4A54 80240404 8E030080 */  lw        $v1, 0x80($s0)
/* 9A4A58 80240408 0043102A */  slt       $v0, $v0, $v1
/* 9A4A5C 8024040C 14400004 */  bnez      $v0, .L80240420
/* 9A4A60 80240410 00000000 */   nop      
/* 9A4A64 80240414 96020086 */  lhu       $v0, 0x86($s0)
/* 9A4A68 80240418 A48200A8 */  sh        $v0, 0xa8($a0)
/* 9A4A6C 8024041C AE200070 */  sw        $zero, 0x70($s1)
.L80240420:
/* 9A4A70 80240420 8FBF0018 */  lw        $ra, 0x18($sp)
/* 9A4A74 80240424 8FB10014 */  lw        $s1, 0x14($sp)
/* 9A4A78 80240428 8FB00010 */  lw        $s0, 0x10($sp)
/* 9A4A7C 8024042C 03E00008 */  jr        $ra
/* 9A4A80 80240430 27BD0020 */   addiu    $sp, $sp, 0x20
