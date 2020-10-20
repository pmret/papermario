.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F44_B850C4
/* B850C4 80240F44 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B850C8 80240F48 AFB00010 */  sw        $s0, 0x10($sp)
/* B850CC 80240F4C 0080802D */  daddu     $s0, $a0, $zero
/* B850D0 80240F50 AFBF0018 */  sw        $ra, 0x18($sp)
/* B850D4 80240F54 AFB10014 */  sw        $s1, 0x14($sp)
/* B850D8 80240F58 8E02000C */  lw        $v0, 0xc($s0)
/* B850DC 80240F5C 8C510000 */  lw        $s1, ($v0)
/* B850E0 80240F60 0C0B1EAF */  jal       get_variable
/* B850E4 80240F64 0220282D */   daddu    $a1, $s1, $zero
/* B850E8 80240F68 3C03FFF0 */  lui       $v1, 0xfff0
/* B850EC 80240F6C 3463FFFF */  ori       $v1, $v1, 0xffff
/* B850F0 80240F70 0200202D */  daddu     $a0, $s0, $zero
/* B850F4 80240F74 00431024 */  and       $v0, $v0, $v1
/* B850F8 80240F78 00021140 */  sll       $v0, $v0, 5
/* B850FC 80240F7C 3C068008 */  lui       $a2, %hi(gItemTable)
/* B85100 80240F80 00C23021 */  addu      $a2, $a2, $v0
/* B85104 80240F84 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* B85108 80240F88 0C0B2026 */  jal       set_variable
/* B8510C 80240F8C 0220282D */   daddu    $a1, $s1, $zero
/* B85110 80240F90 8FBF0018 */  lw        $ra, 0x18($sp)
/* B85114 80240F94 8FB10014 */  lw        $s1, 0x14($sp)
/* B85118 80240F98 8FB00010 */  lw        $s0, 0x10($sp)
/* B8511C 80240F9C 24020002 */  addiu     $v0, $zero, 2
/* B85120 80240FA0 03E00008 */  jr        $ra
/* B85124 80240FA4 27BD0020 */   addiu    $sp, $sp, 0x20
