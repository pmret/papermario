.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241AC8_D2D7F8
/* D2D7F8 80241AC8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D2D7FC 80241ACC AFB10014 */  sw        $s1, 0x14($sp)
/* D2D800 80241AD0 0080882D */  daddu     $s1, $a0, $zero
/* D2D804 80241AD4 AFBF0018 */  sw        $ra, 0x18($sp)
/* D2D808 80241AD8 AFB00010 */  sw        $s0, 0x10($sp)
/* D2D80C 80241ADC 8E300148 */  lw        $s0, 0x148($s1)
/* D2D810 80241AE0 0C00EABB */  jal       get_npc_unsafe
/* D2D814 80241AE4 86040008 */   lh       $a0, 8($s0)
/* D2D818 80241AE8 0040202D */  daddu     $a0, $v0, $zero
/* D2D81C 80241AEC 9482008E */  lhu       $v0, 0x8e($a0)
/* D2D820 80241AF0 2442FFFF */  addiu     $v0, $v0, -1
/* D2D824 80241AF4 A482008E */  sh        $v0, 0x8e($a0)
/* D2D828 80241AF8 00021400 */  sll       $v0, $v0, 0x10
/* D2D82C 80241AFC 8E030098 */  lw        $v1, 0x98($s0)
/* D2D830 80241B00 00021403 */  sra       $v0, $v0, 0x10
/* D2D834 80241B04 0062182A */  slt       $v1, $v1, $v0
/* D2D838 80241B08 14600005 */  bnez      $v1, .L80241B20
/* D2D83C 80241B0C 3C03E0EF */   lui      $v1, 0xe0ef
/* D2D840 80241B10 8E020000 */  lw        $v0, ($s0)
/* D2D844 80241B14 3463FFFF */  ori       $v1, $v1, 0xffff
/* D2D848 80241B18 00431024 */  and       $v0, $v0, $v1
/* D2D84C 80241B1C AE020000 */  sw        $v0, ($s0)
.L80241B20:
/* D2D850 80241B20 8482008E */  lh        $v0, 0x8e($a0)
/* D2D854 80241B24 14400007 */  bnez      $v0, .L80241B44
/* D2D858 80241B28 00000000 */   nop
/* D2D85C 80241B2C 8E0200CC */  lw        $v0, 0xcc($s0)
/* D2D860 80241B30 8C420028 */  lw        $v0, 0x28($v0)
/* D2D864 80241B34 A480008E */  sh        $zero, 0x8e($a0)
/* D2D868 80241B38 AC820028 */  sw        $v0, 0x28($a0)
/* D2D86C 80241B3C 2402000C */  addiu     $v0, $zero, 0xc
/* D2D870 80241B40 AE220070 */  sw        $v0, 0x70($s1)
.L80241B44:
/* D2D874 80241B44 8FBF0018 */  lw        $ra, 0x18($sp)
/* D2D878 80241B48 8FB10014 */  lw        $s1, 0x14($sp)
/* D2D87C 80241B4C 8FB00010 */  lw        $s0, 0x10($sp)
/* D2D880 80241B50 03E00008 */  jr        $ra
/* D2D884 80241B54 27BD0020 */   addiu    $sp, $sp, 0x20
