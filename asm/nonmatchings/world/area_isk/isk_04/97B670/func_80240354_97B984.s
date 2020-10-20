.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240354_97B984
/* 97B984 80240354 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 97B988 80240358 AFB10014 */  sw        $s1, 0x14($sp)
/* 97B98C 8024035C 0080882D */  daddu     $s1, $a0, $zero
/* 97B990 80240360 AFBF0018 */  sw        $ra, 0x18($sp)
/* 97B994 80240364 AFB00010 */  sw        $s0, 0x10($sp)
/* 97B998 80240368 8E300148 */  lw        $s0, 0x148($s1)
/* 97B99C 8024036C 0C00EABB */  jal       get_npc_unsafe
/* 97B9A0 80240370 86040008 */   lh       $a0, 8($s0)
/* 97B9A4 80240374 0040202D */  daddu     $a0, $v0, $zero
/* 97B9A8 80240378 9482008E */  lhu       $v0, 0x8e($a0)
/* 97B9AC 8024037C 24030003 */  addiu     $v1, $zero, 3
/* 97B9B0 80240380 24420001 */  addiu     $v0, $v0, 1
/* 97B9B4 80240384 A482008E */  sh        $v0, 0x8e($a0)
/* 97B9B8 80240388 00021400 */  sll       $v0, $v0, 0x10
/* 97B9BC 8024038C 00021403 */  sra       $v0, $v0, 0x10
/* 97B9C0 80240390 14430003 */  bne       $v0, $v1, .L802403A0
/* 97B9C4 80240394 00000000 */   nop      
/* 97B9C8 80240398 96020086 */  lhu       $v0, 0x86($s0)
/* 97B9CC 8024039C A48200A8 */  sh        $v0, 0xa8($a0)
.L802403A0:
/* 97B9D0 802403A0 8482008E */  lh        $v0, 0x8e($a0)
/* 97B9D4 802403A4 8E030080 */  lw        $v1, 0x80($s0)
/* 97B9D8 802403A8 0043102A */  slt       $v0, $v0, $v1
/* 97B9DC 802403AC 14400004 */  bnez      $v0, .L802403C0
/* 97B9E0 802403B0 00000000 */   nop      
/* 97B9E4 802403B4 96020086 */  lhu       $v0, 0x86($s0)
/* 97B9E8 802403B8 A48200A8 */  sh        $v0, 0xa8($a0)
/* 97B9EC 802403BC AE200070 */  sw        $zero, 0x70($s1)
.L802403C0:
/* 97B9F0 802403C0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 97B9F4 802403C4 8FB10014 */  lw        $s1, 0x14($sp)
/* 97B9F8 802403C8 8FB00010 */  lw        $s0, 0x10($sp)
/* 97B9FC 802403CC 03E00008 */  jr        $ra
/* 97BA00 802403D0 27BD0020 */   addiu    $sp, $sp, 0x20
