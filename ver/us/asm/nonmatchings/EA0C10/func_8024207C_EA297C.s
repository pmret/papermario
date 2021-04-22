.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024207C_EA297C
/* EA297C 8024207C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EA2980 80242080 AFB10014 */  sw        $s1, 0x14($sp)
/* EA2984 80242084 0080882D */  daddu     $s1, $a0, $zero
/* EA2988 80242088 AFBF0018 */  sw        $ra, 0x18($sp)
/* EA298C 8024208C AFB00010 */  sw        $s0, 0x10($sp)
/* EA2990 80242090 8E300148 */  lw        $s0, 0x148($s1)
/* EA2994 80242094 0C00F92F */  jal       func_8003E4BC
/* EA2998 80242098 86040008 */   lh       $a0, 8($s0)
/* EA299C 8024209C 0040202D */  daddu     $a0, $v0, $zero
/* EA29A0 802420A0 9482008E */  lhu       $v0, 0x8e($a0)
/* EA29A4 802420A4 24030003 */  addiu     $v1, $zero, 3
/* EA29A8 802420A8 24420001 */  addiu     $v0, $v0, 1
/* EA29AC 802420AC A482008E */  sh        $v0, 0x8e($a0)
/* EA29B0 802420B0 00021400 */  sll       $v0, $v0, 0x10
/* EA29B4 802420B4 00021403 */  sra       $v0, $v0, 0x10
/* EA29B8 802420B8 14430003 */  bne       $v0, $v1, .L802420C8
/* EA29BC 802420BC 00000000 */   nop
/* EA29C0 802420C0 96020086 */  lhu       $v0, 0x86($s0)
/* EA29C4 802420C4 A48200A8 */  sh        $v0, 0xa8($a0)
.L802420C8:
/* EA29C8 802420C8 8482008E */  lh        $v0, 0x8e($a0)
/* EA29CC 802420CC 8E030080 */  lw        $v1, 0x80($s0)
/* EA29D0 802420D0 0043102A */  slt       $v0, $v0, $v1
/* EA29D4 802420D4 14400004 */  bnez      $v0, .L802420E8
/* EA29D8 802420D8 00000000 */   nop
/* EA29DC 802420DC 96020086 */  lhu       $v0, 0x86($s0)
/* EA29E0 802420E0 A48200A8 */  sh        $v0, 0xa8($a0)
/* EA29E4 802420E4 AE200070 */  sw        $zero, 0x70($s1)
.L802420E8:
/* EA29E8 802420E8 8FBF0018 */  lw        $ra, 0x18($sp)
/* EA29EC 802420EC 8FB10014 */  lw        $s1, 0x14($sp)
/* EA29F0 802420F0 8FB00010 */  lw        $s0, 0x10($sp)
/* EA29F4 802420F4 03E00008 */  jr        $ra
/* EA29F8 802420F8 27BD0020 */   addiu    $sp, $sp, 0x20
