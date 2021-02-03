.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241C90_CF9800
/* CF9800 80241C90 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CF9804 80241C94 AFB00010 */  sw        $s0, 0x10($sp)
/* CF9808 80241C98 3C108025 */  lui       $s0, %hi(D_8024D8F0_D05460)
/* CF980C 80241C9C 2610D8F0 */  addiu     $s0, $s0, %lo(D_8024D8F0_D05460)
/* CF9810 80241CA0 AFBF0018 */  sw        $ra, 0x18($sp)
/* CF9814 80241CA4 AFB10014 */  sw        $s1, 0x14($sp)
/* CF9818 80241CA8 8E020000 */  lw        $v0, ($s0)
/* CF981C 80241CAC 14400010 */  bnez      $v0, .L80241CF0
/* CF9820 80241CB0 0080882D */   daddu    $s1, $a0, $zero
/* CF9824 80241CB4 0C00AB39 */  jal       heap_malloc
/* CF9828 80241CB8 24040040 */   addiu    $a0, $zero, 0x40
/* CF982C 80241CBC AE020000 */  sw        $v0, ($s0)
/* CF9830 80241CC0 0000182D */  daddu     $v1, $zero, $zero
/* CF9834 80241CC4 0040282D */  daddu     $a1, $v0, $zero
/* CF9838 80241CC8 0220202D */  daddu     $a0, $s1, $zero
.L80241CCC:
/* CF983C 80241CCC 8C820084 */  lw        $v0, 0x84($a0)
/* CF9840 80241CD0 24840004 */  addiu     $a0, $a0, 4
/* CF9844 80241CD4 24630001 */  addiu     $v1, $v1, 1
/* CF9848 80241CD8 ACA20000 */  sw        $v0, ($a1)
/* CF984C 80241CDC 28620010 */  slti      $v0, $v1, 0x10
/* CF9850 80241CE0 1440FFFA */  bnez      $v0, .L80241CCC
/* CF9854 80241CE4 24A50004 */   addiu    $a1, $a1, 4
/* CF9858 80241CE8 0809074B */  j         .L80241D2C
/* CF985C 80241CEC 00000000 */   nop
.L80241CF0:
/* CF9860 80241CF0 0000182D */  daddu     $v1, $zero, $zero
/* CF9864 80241CF4 0040282D */  daddu     $a1, $v0, $zero
/* CF9868 80241CF8 0220202D */  daddu     $a0, $s1, $zero
.L80241CFC:
/* CF986C 80241CFC 8CA20000 */  lw        $v0, ($a1)
/* CF9870 80241D00 24A50004 */  addiu     $a1, $a1, 4
/* CF9874 80241D04 24630001 */  addiu     $v1, $v1, 1
/* CF9878 80241D08 AC820084 */  sw        $v0, 0x84($a0)
/* CF987C 80241D0C 28620010 */  slti      $v0, $v1, 0x10
/* CF9880 80241D10 1440FFFA */  bnez      $v0, .L80241CFC
/* CF9884 80241D14 24840004 */   addiu    $a0, $a0, 4
/* CF9888 80241D18 3C108025 */  lui       $s0, %hi(D_8024D8F0_D05460)
/* CF988C 80241D1C 2610D8F0 */  addiu     $s0, $s0, %lo(D_8024D8F0_D05460)
/* CF9890 80241D20 0C00AB4B */  jal       heap_free
/* CF9894 80241D24 8E040000 */   lw       $a0, ($s0)
/* CF9898 80241D28 AE000000 */  sw        $zero, ($s0)
.L80241D2C:
/* CF989C 80241D2C 8FBF0018 */  lw        $ra, 0x18($sp)
/* CF98A0 80241D30 8FB10014 */  lw        $s1, 0x14($sp)
/* CF98A4 80241D34 8FB00010 */  lw        $s0, 0x10($sp)
/* CF98A8 80241D38 24020002 */  addiu     $v0, $zero, 2
/* CF98AC 80241D3C 03E00008 */  jr        $ra
/* CF98B0 80241D40 27BD0020 */   addiu    $sp, $sp, 0x20
