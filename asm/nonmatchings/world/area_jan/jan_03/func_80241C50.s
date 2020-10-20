.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241C50
/* B36820 80241C50 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B36824 80241C54 AFB00010 */  sw        $s0, 0x10($sp)
/* B36828 80241C58 0080802D */  daddu     $s0, $a0, $zero
/* B3682C 80241C5C AFBF0018 */  sw        $ra, 0x18($sp)
/* B36830 80241C60 AFB10014 */  sw        $s1, 0x14($sp)
/* B36834 80241C64 8E02000C */  lw        $v0, 0xc($s0)
/* B36838 80241C68 8C510000 */  lw        $s1, ($v0)
/* B3683C 80241C6C 0C0B1EAF */  jal       get_variable
/* B36840 80241C70 0220282D */   daddu    $a1, $s1, $zero
/* B36844 80241C74 3C03FFF0 */  lui       $v1, 0xfff0
/* B36848 80241C78 3463FFFF */  ori       $v1, $v1, 0xffff
/* B3684C 80241C7C 0200202D */  daddu     $a0, $s0, $zero
/* B36850 80241C80 00431024 */  and       $v0, $v0, $v1
/* B36854 80241C84 00021140 */  sll       $v0, $v0, 5
/* B36858 80241C88 3C068008 */  lui       $a2, %hi(gItemTable)
/* B3685C 80241C8C 00C23021 */  addu      $a2, $a2, $v0
/* B36860 80241C90 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* B36864 80241C94 0C0B2026 */  jal       set_variable
/* B36868 80241C98 0220282D */   daddu    $a1, $s1, $zero
/* B3686C 80241C9C 8FBF0018 */  lw        $ra, 0x18($sp)
/* B36870 80241CA0 8FB10014 */  lw        $s1, 0x14($sp)
/* B36874 80241CA4 8FB00010 */  lw        $s0, 0x10($sp)
/* B36878 80241CA8 24020002 */  addiu     $v0, $zero, 2
/* B3687C 80241CAC 03E00008 */  jr        $ra
/* B36880 80241CB0 27BD0020 */   addiu    $sp, $sp, 0x20
