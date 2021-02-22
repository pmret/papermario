.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802424B0_EF4AC0
/* EF4AC0 802424B0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EF4AC4 802424B4 AFB10014 */  sw        $s1, 0x14($sp)
/* EF4AC8 802424B8 0080882D */  daddu     $s1, $a0, $zero
/* EF4ACC 802424BC AFBF0018 */  sw        $ra, 0x18($sp)
/* EF4AD0 802424C0 AFB00010 */  sw        $s0, 0x10($sp)
/* EF4AD4 802424C4 8E300148 */  lw        $s0, 0x148($s1)
/* EF4AD8 802424C8 0C00F92F */  jal       func_8003E4BC
/* EF4ADC 802424CC 86040008 */   lh       $a0, 8($s0)
/* EF4AE0 802424D0 0040202D */  daddu     $a0, $v0, $zero
/* EF4AE4 802424D4 9482008E */  lhu       $v0, 0x8e($a0)
/* EF4AE8 802424D8 24030003 */  addiu     $v1, $zero, 3
/* EF4AEC 802424DC 24420001 */  addiu     $v0, $v0, 1
/* EF4AF0 802424E0 A482008E */  sh        $v0, 0x8e($a0)
/* EF4AF4 802424E4 00021400 */  sll       $v0, $v0, 0x10
/* EF4AF8 802424E8 00021403 */  sra       $v0, $v0, 0x10
/* EF4AFC 802424EC 14430003 */  bne       $v0, $v1, .L802424FC
/* EF4B00 802424F0 00000000 */   nop
/* EF4B04 802424F4 96020086 */  lhu       $v0, 0x86($s0)
/* EF4B08 802424F8 A48200A8 */  sh        $v0, 0xa8($a0)
.L802424FC:
/* EF4B0C 802424FC 8482008E */  lh        $v0, 0x8e($a0)
/* EF4B10 80242500 8E030080 */  lw        $v1, 0x80($s0)
/* EF4B14 80242504 0043102A */  slt       $v0, $v0, $v1
/* EF4B18 80242508 14400004 */  bnez      $v0, .L8024251C
/* EF4B1C 8024250C 00000000 */   nop
/* EF4B20 80242510 96020086 */  lhu       $v0, 0x86($s0)
/* EF4B24 80242514 A48200A8 */  sh        $v0, 0xa8($a0)
/* EF4B28 80242518 AE200070 */  sw        $zero, 0x70($s1)
.L8024251C:
/* EF4B2C 8024251C 8FBF0018 */  lw        $ra, 0x18($sp)
/* EF4B30 80242520 8FB10014 */  lw        $s1, 0x14($sp)
/* EF4B34 80242524 8FB00010 */  lw        $s0, 0x10($sp)
/* EF4B38 80242528 03E00008 */  jr        $ra
/* EF4B3C 8024252C 27BD0020 */   addiu    $sp, $sp, 0x20
