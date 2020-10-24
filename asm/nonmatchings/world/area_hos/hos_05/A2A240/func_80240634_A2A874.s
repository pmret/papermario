.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240634_A2A874
/* A2A874 80240634 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A2A878 80240638 AFB10014 */  sw        $s1, 0x14($sp)
/* A2A87C 8024063C 0080882D */  daddu     $s1, $a0, $zero
/* A2A880 80240640 AFBF0018 */  sw        $ra, 0x18($sp)
/* A2A884 80240644 AFB00010 */  sw        $s0, 0x10($sp)
/* A2A888 80240648 8E30000C */  lw        $s0, 0xc($s1)
/* A2A88C 8024064C 8E050000 */  lw        $a1, ($s0)
/* A2A890 80240650 0C0B1EAF */  jal       get_variable
/* A2A894 80240654 26100004 */   addiu    $s0, $s0, 4
/* A2A898 80240658 0220202D */  daddu     $a0, $s1, $zero
/* A2A89C 8024065C 8E050000 */  lw        $a1, ($s0)
/* A2A8A0 80240660 0C0B210B */  jal       get_float_variable
/* A2A8A4 80240664 0040802D */   daddu    $s0, $v0, $zero
/* A2A8A8 80240668 00108080 */  sll       $s0, $s0, 2
/* A2A8AC 8024066C 02308821 */  addu      $s1, $s1, $s0
/* A2A8B0 80240670 4600008D */  trunc.w.s $f2, $f0
/* A2A8B4 80240674 E6220084 */  swc1      $f2, 0x84($s1)
/* A2A8B8 80240678 8FBF0018 */  lw        $ra, 0x18($sp)
/* A2A8BC 8024067C 8FB10014 */  lw        $s1, 0x14($sp)
/* A2A8C0 80240680 8FB00010 */  lw        $s0, 0x10($sp)
/* A2A8C4 80240684 24020002 */  addiu     $v0, $zero, 2
/* A2A8C8 80240688 03E00008 */  jr        $ra
/* A2A8CC 8024068C 27BD0020 */   addiu    $sp, $sp, 0x20
