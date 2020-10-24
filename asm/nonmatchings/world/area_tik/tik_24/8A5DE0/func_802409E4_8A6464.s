.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802409E4_8A6464
/* 8A6464 802409E4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8A6468 802409E8 AFB10014 */  sw        $s1, 0x14($sp)
/* 8A646C 802409EC 0080882D */  daddu     $s1, $a0, $zero
/* 8A6470 802409F0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 8A6474 802409F4 AFB00010 */  sw        $s0, 0x10($sp)
/* 8A6478 802409F8 8E300148 */  lw        $s0, 0x148($s1)
/* 8A647C 802409FC 0C00EABB */  jal       get_npc_unsafe
/* 8A6480 80240A00 86040008 */   lh       $a0, 8($s0)
/* 8A6484 80240A04 0040202D */  daddu     $a0, $v0, $zero
/* 8A6488 80240A08 9482008E */  lhu       $v0, 0x8e($a0)
/* 8A648C 80240A0C 24030003 */  addiu     $v1, $zero, 3
/* 8A6490 80240A10 24420001 */  addiu     $v0, $v0, 1
/* 8A6494 80240A14 A482008E */  sh        $v0, 0x8e($a0)
/* 8A6498 80240A18 00021400 */  sll       $v0, $v0, 0x10
/* 8A649C 80240A1C 00021403 */  sra       $v0, $v0, 0x10
/* 8A64A0 80240A20 14430003 */  bne       $v0, $v1, .L80240A30
/* 8A64A4 80240A24 00000000 */   nop      
/* 8A64A8 80240A28 96020086 */  lhu       $v0, 0x86($s0)
/* 8A64AC 80240A2C A48200A8 */  sh        $v0, 0xa8($a0)
.L80240A30:
/* 8A64B0 80240A30 8482008E */  lh        $v0, 0x8e($a0)
/* 8A64B4 80240A34 8E030080 */  lw        $v1, 0x80($s0)
/* 8A64B8 80240A38 0043102A */  slt       $v0, $v0, $v1
/* 8A64BC 80240A3C 14400004 */  bnez      $v0, .L80240A50
/* 8A64C0 80240A40 00000000 */   nop      
/* 8A64C4 80240A44 96020086 */  lhu       $v0, 0x86($s0)
/* 8A64C8 80240A48 A48200A8 */  sh        $v0, 0xa8($a0)
/* 8A64CC 80240A4C AE200070 */  sw        $zero, 0x70($s1)
.L80240A50:
/* 8A64D0 80240A50 8FBF0018 */  lw        $ra, 0x18($sp)
/* 8A64D4 80240A54 8FB10014 */  lw        $s1, 0x14($sp)
/* 8A64D8 80240A58 8FB00010 */  lw        $s0, 0x10($sp)
/* 8A64DC 80240A5C 03E00008 */  jr        $ra
/* 8A64E0 80240A60 27BD0020 */   addiu    $sp, $sp, 0x20
