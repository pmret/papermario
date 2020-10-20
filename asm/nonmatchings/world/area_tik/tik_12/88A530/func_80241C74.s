.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241C74
/* 88A844 80241C74 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 88A848 80241C78 AFB10014 */  sw        $s1, 0x14($sp)
/* 88A84C 80241C7C 0080882D */  daddu     $s1, $a0, $zero
/* 88A850 80241C80 AFBF0018 */  sw        $ra, 0x18($sp)
/* 88A854 80241C84 AFB00010 */  sw        $s0, 0x10($sp)
/* 88A858 80241C88 8E300148 */  lw        $s0, 0x148($s1)
/* 88A85C 80241C8C 0C00EABB */  jal       get_npc_unsafe
/* 88A860 80241C90 86040008 */   lh       $a0, 8($s0)
/* 88A864 80241C94 0040202D */  daddu     $a0, $v0, $zero
/* 88A868 80241C98 9482008E */  lhu       $v0, 0x8e($a0)
/* 88A86C 80241C9C 24030003 */  addiu     $v1, $zero, 3
/* 88A870 80241CA0 24420001 */  addiu     $v0, $v0, 1
/* 88A874 80241CA4 A482008E */  sh        $v0, 0x8e($a0)
/* 88A878 80241CA8 00021400 */  sll       $v0, $v0, 0x10
/* 88A87C 80241CAC 00021403 */  sra       $v0, $v0, 0x10
/* 88A880 80241CB0 14430003 */  bne       $v0, $v1, .L80241CC0
/* 88A884 80241CB4 00000000 */   nop      
/* 88A888 80241CB8 96020086 */  lhu       $v0, 0x86($s0)
/* 88A88C 80241CBC A48200A8 */  sh        $v0, 0xa8($a0)
.L80241CC0:
/* 88A890 80241CC0 8482008E */  lh        $v0, 0x8e($a0)
/* 88A894 80241CC4 8E030080 */  lw        $v1, 0x80($s0)
/* 88A898 80241CC8 0043102A */  slt       $v0, $v0, $v1
/* 88A89C 80241CCC 14400004 */  bnez      $v0, .L80241CE0
/* 88A8A0 80241CD0 00000000 */   nop      
/* 88A8A4 80241CD4 96020086 */  lhu       $v0, 0x86($s0)
/* 88A8A8 80241CD8 A48200A8 */  sh        $v0, 0xa8($a0)
/* 88A8AC 80241CDC AE200070 */  sw        $zero, 0x70($s1)
.L80241CE0:
/* 88A8B0 80241CE0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 88A8B4 80241CE4 8FB10014 */  lw        $s1, 0x14($sp)
/* 88A8B8 80241CE8 8FB00010 */  lw        $s0, 0x10($sp)
/* 88A8BC 80241CEC 03E00008 */  jr        $ra
/* 88A8C0 80241CF0 27BD0020 */   addiu    $sp, $sp, 0x20
