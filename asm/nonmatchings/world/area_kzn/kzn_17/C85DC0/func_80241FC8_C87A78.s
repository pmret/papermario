.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241FC8_C87A78
/* C87A78 80241FC8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C87A7C 80241FCC AFB10014 */  sw        $s1, 0x14($sp)
/* C87A80 80241FD0 0080882D */  daddu     $s1, $a0, $zero
/* C87A84 80241FD4 AFBF0018 */  sw        $ra, 0x18($sp)
/* C87A88 80241FD8 AFB00010 */  sw        $s0, 0x10($sp)
/* C87A8C 80241FDC 8E300148 */  lw        $s0, 0x148($s1)
/* C87A90 80241FE0 0C00EABB */  jal       get_npc_unsafe
/* C87A94 80241FE4 86040008 */   lh       $a0, 8($s0)
/* C87A98 80241FE8 0040202D */  daddu     $a0, $v0, $zero
/* C87A9C 80241FEC 9482008E */  lhu       $v0, 0x8e($a0)
/* C87AA0 80241FF0 24030003 */  addiu     $v1, $zero, 3
/* C87AA4 80241FF4 24420001 */  addiu     $v0, $v0, 1
/* C87AA8 80241FF8 A482008E */  sh        $v0, 0x8e($a0)
/* C87AAC 80241FFC 00021400 */  sll       $v0, $v0, 0x10
/* C87AB0 80242000 00021403 */  sra       $v0, $v0, 0x10
/* C87AB4 80242004 14430003 */  bne       $v0, $v1, .L80242014
/* C87AB8 80242008 00000000 */   nop      
/* C87ABC 8024200C 96020086 */  lhu       $v0, 0x86($s0)
/* C87AC0 80242010 A48200A8 */  sh        $v0, 0xa8($a0)
.L80242014:
/* C87AC4 80242014 8482008E */  lh        $v0, 0x8e($a0)
/* C87AC8 80242018 8E030080 */  lw        $v1, 0x80($s0)
/* C87ACC 8024201C 0043102A */  slt       $v0, $v0, $v1
/* C87AD0 80242020 14400004 */  bnez      $v0, .L80242034
/* C87AD4 80242024 00000000 */   nop      
/* C87AD8 80242028 96020086 */  lhu       $v0, 0x86($s0)
/* C87ADC 8024202C A48200A8 */  sh        $v0, 0xa8($a0)
/* C87AE0 80242030 AE200070 */  sw        $zero, 0x70($s1)
.L80242034:
/* C87AE4 80242034 8FBF0018 */  lw        $ra, 0x18($sp)
/* C87AE8 80242038 8FB10014 */  lw        $s1, 0x14($sp)
/* C87AEC 8024203C 8FB00010 */  lw        $s0, 0x10($sp)
/* C87AF0 80242040 03E00008 */  jr        $ra
/* C87AF4 80242044 27BD0020 */   addiu    $sp, $sp, 0x20
