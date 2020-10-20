.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A14_8905B4
/* 8905B4 80240A14 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8905B8 80240A18 AFB00010 */  sw        $s0, 0x10($sp)
/* 8905BC 80240A1C 0080802D */  daddu     $s0, $a0, $zero
/* 8905C0 80240A20 AFBF0018 */  sw        $ra, 0x18($sp)
/* 8905C4 80240A24 AFB10014 */  sw        $s1, 0x14($sp)
/* 8905C8 80240A28 8E02000C */  lw        $v0, 0xc($s0)
/* 8905CC 80240A2C 8C510000 */  lw        $s1, ($v0)
/* 8905D0 80240A30 0C0B1EAF */  jal       get_variable
/* 8905D4 80240A34 0220282D */   daddu    $a1, $s1, $zero
/* 8905D8 80240A38 3C03FFF0 */  lui       $v1, 0xfff0
/* 8905DC 80240A3C 3463FFFF */  ori       $v1, $v1, 0xffff
/* 8905E0 80240A40 0200202D */  daddu     $a0, $s0, $zero
/* 8905E4 80240A44 00431024 */  and       $v0, $v0, $v1
/* 8905E8 80240A48 00021140 */  sll       $v0, $v0, 5
/* 8905EC 80240A4C 3C068008 */  lui       $a2, %hi(gItemTable)
/* 8905F0 80240A50 00C23021 */  addu      $a2, $a2, $v0
/* 8905F4 80240A54 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* 8905F8 80240A58 0C0B2026 */  jal       set_variable
/* 8905FC 80240A5C 0220282D */   daddu    $a1, $s1, $zero
/* 890600 80240A60 8FBF0018 */  lw        $ra, 0x18($sp)
/* 890604 80240A64 8FB10014 */  lw        $s1, 0x14($sp)
/* 890608 80240A68 8FB00010 */  lw        $s0, 0x10($sp)
/* 89060C 80240A6C 24020002 */  addiu     $v0, $zero, 2
/* 890610 80240A70 03E00008 */  jr        $ra
/* 890614 80240A74 27BD0020 */   addiu    $sp, $sp, 0x20
