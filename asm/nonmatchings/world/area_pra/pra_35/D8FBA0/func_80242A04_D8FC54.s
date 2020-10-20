.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242A04_D8FC54
/* D8FC54 80242A04 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D8FC58 80242A08 AFB00010 */  sw        $s0, 0x10($sp)
/* D8FC5C 80242A0C 0080802D */  daddu     $s0, $a0, $zero
/* D8FC60 80242A10 AFBF0018 */  sw        $ra, 0x18($sp)
/* D8FC64 80242A14 AFB10014 */  sw        $s1, 0x14($sp)
/* D8FC68 80242A18 8E02000C */  lw        $v0, 0xc($s0)
/* D8FC6C 80242A1C 8C510000 */  lw        $s1, ($v0)
/* D8FC70 80242A20 0C0B1EAF */  jal       get_variable
/* D8FC74 80242A24 0220282D */   daddu    $a1, $s1, $zero
/* D8FC78 80242A28 3C03FFF0 */  lui       $v1, 0xfff0
/* D8FC7C 80242A2C 3463FFFF */  ori       $v1, $v1, 0xffff
/* D8FC80 80242A30 0200202D */  daddu     $a0, $s0, $zero
/* D8FC84 80242A34 00431024 */  and       $v0, $v0, $v1
/* D8FC88 80242A38 00021140 */  sll       $v0, $v0, 5
/* D8FC8C 80242A3C 3C068008 */  lui       $a2, %hi(gItemTable)
/* D8FC90 80242A40 00C23021 */  addu      $a2, $a2, $v0
/* D8FC94 80242A44 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* D8FC98 80242A48 0C0B2026 */  jal       set_variable
/* D8FC9C 80242A4C 0220282D */   daddu    $a1, $s1, $zero
/* D8FCA0 80242A50 8FBF0018 */  lw        $ra, 0x18($sp)
/* D8FCA4 80242A54 8FB10014 */  lw        $s1, 0x14($sp)
/* D8FCA8 80242A58 8FB00010 */  lw        $s0, 0x10($sp)
/* D8FCAC 80242A5C 24020002 */  addiu     $v0, $zero, 2
/* D8FCB0 80242A60 03E00008 */  jr        $ra
/* D8FCB4 80242A64 27BD0020 */   addiu    $sp, $sp, 0x20
