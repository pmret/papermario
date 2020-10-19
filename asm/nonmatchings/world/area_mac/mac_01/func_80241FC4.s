.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241FC4
/* 802844 80241FC4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 802848 80241FC8 AFB00010 */  sw        $s0, 0x10($sp)
/* 80284C 80241FCC 0080802D */  daddu     $s0, $a0, $zero
/* 802850 80241FD0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 802854 80241FD4 AFB10014 */  sw        $s1, 0x14($sp)
/* 802858 80241FD8 8E02000C */  lw        $v0, 0xc($s0)
/* 80285C 80241FDC 8C510000 */  lw        $s1, ($v0)
/* 802860 80241FE0 0C0B1EAF */  jal       get_variable
/* 802864 80241FE4 0220282D */   daddu    $a1, $s1, $zero
/* 802868 80241FE8 3C03FFF0 */  lui       $v1, 0xfff0
/* 80286C 80241FEC 3463FFFF */  ori       $v1, $v1, 0xffff
/* 802870 80241FF0 0200202D */  daddu     $a0, $s0, $zero
/* 802874 80241FF4 00431024 */  and       $v0, $v0, $v1
/* 802878 80241FF8 00021140 */  sll       $v0, $v0, 5
/* 80287C 80241FFC 3C068008 */  lui       $a2, %hi(gItemTable)
/* 802880 80242000 00C23021 */  addu      $a2, $a2, $v0
/* 802884 80242004 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* 802888 80242008 0C0B2026 */  jal       set_variable
/* 80288C 8024200C 0220282D */   daddu    $a1, $s1, $zero
/* 802890 80242010 8FBF0018 */  lw        $ra, 0x18($sp)
/* 802894 80242014 8FB10014 */  lw        $s1, 0x14($sp)
/* 802898 80242018 8FB00010 */  lw        $s0, 0x10($sp)
/* 80289C 8024201C 24020002 */  addiu     $v0, $zero, 2
/* 8028A0 80242020 03E00008 */  jr        $ra
/* 8028A4 80242024 27BD0020 */   addiu    $sp, $sp, 0x20
