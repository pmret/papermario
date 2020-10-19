.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241560_A61F30
/* A61F30 80241560 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A61F34 80241564 AFB10014 */  sw        $s1, 0x14($sp)
/* A61F38 80241568 0080882D */  daddu     $s1, $a0, $zero
/* A61F3C 8024156C AFBF0018 */  sw        $ra, 0x18($sp)
/* A61F40 80241570 AFB00010 */  sw        $s0, 0x10($sp)
/* A61F44 80241574 8E300148 */  lw        $s0, 0x148($s1)
/* A61F48 80241578 0C00EABB */  jal       get_npc_unsafe
/* A61F4C 8024157C 86040008 */   lh       $a0, 8($s0)
/* A61F50 80241580 0040202D */  daddu     $a0, $v0, $zero
/* A61F54 80241584 9482008E */  lhu       $v0, 0x8e($a0)
/* A61F58 80241588 24030003 */  addiu     $v1, $zero, 3
/* A61F5C 8024158C 24420001 */  addiu     $v0, $v0, 1
/* A61F60 80241590 A482008E */  sh        $v0, 0x8e($a0)
/* A61F64 80241594 00021400 */  sll       $v0, $v0, 0x10
/* A61F68 80241598 00021403 */  sra       $v0, $v0, 0x10
/* A61F6C 8024159C 14430003 */  bne       $v0, $v1, .L802415AC
/* A61F70 802415A0 00000000 */   nop      
/* A61F74 802415A4 96020086 */  lhu       $v0, 0x86($s0)
/* A61F78 802415A8 A48200A8 */  sh        $v0, 0xa8($a0)
.L802415AC:
/* A61F7C 802415AC 8482008E */  lh        $v0, 0x8e($a0)
/* A61F80 802415B0 8E030080 */  lw        $v1, 0x80($s0)
/* A61F84 802415B4 0043102A */  slt       $v0, $v0, $v1
/* A61F88 802415B8 14400004 */  bnez      $v0, .L802415CC
/* A61F8C 802415BC 00000000 */   nop      
/* A61F90 802415C0 96020086 */  lhu       $v0, 0x86($s0)
/* A61F94 802415C4 A48200A8 */  sh        $v0, 0xa8($a0)
/* A61F98 802415C8 AE200070 */  sw        $zero, 0x70($s1)
.L802415CC:
/* A61F9C 802415CC 8FBF0018 */  lw        $ra, 0x18($sp)
/* A61FA0 802415D0 8FB10014 */  lw        $s1, 0x14($sp)
/* A61FA4 802415D4 8FB00010 */  lw        $s0, 0x10($sp)
/* A61FA8 802415D8 03E00008 */  jr        $ra
/* A61FAC 802415DC 27BD0020 */   addiu    $sp, $sp, 0x20
