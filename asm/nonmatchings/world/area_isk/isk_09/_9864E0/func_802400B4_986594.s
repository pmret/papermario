.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400B4_986594
/* 986594 802400B4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 986598 802400B8 AFB00010 */  sw        $s0, 0x10($sp)
/* 98659C 802400BC 0080802D */  daddu     $s0, $a0, $zero
/* 9865A0 802400C0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 9865A4 802400C4 AFB10014 */  sw        $s1, 0x14($sp)
/* 9865A8 802400C8 8E02000C */  lw        $v0, 0xc($s0)
/* 9865AC 802400CC 8C510000 */  lw        $s1, ($v0)
/* 9865B0 802400D0 0C0B1EAF */  jal       get_variable
/* 9865B4 802400D4 0220282D */   daddu    $a1, $s1, $zero
/* 9865B8 802400D8 3C03FFF0 */  lui       $v1, 0xfff0
/* 9865BC 802400DC 3463FFFF */  ori       $v1, $v1, 0xffff
/* 9865C0 802400E0 0200202D */  daddu     $a0, $s0, $zero
/* 9865C4 802400E4 00431024 */  and       $v0, $v0, $v1
/* 9865C8 802400E8 00021140 */  sll       $v0, $v0, 5
/* 9865CC 802400EC 3C068008 */  lui       $a2, %hi(gItemTable)
/* 9865D0 802400F0 00C23021 */  addu      $a2, $a2, $v0
/* 9865D4 802400F4 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* 9865D8 802400F8 0C0B2026 */  jal       set_variable
/* 9865DC 802400FC 0220282D */   daddu    $a1, $s1, $zero
/* 9865E0 80240100 8FBF0018 */  lw        $ra, 0x18($sp)
/* 9865E4 80240104 8FB10014 */  lw        $s1, 0x14($sp)
/* 9865E8 80240108 8FB00010 */  lw        $s0, 0x10($sp)
/* 9865EC 8024010C 24020002 */  addiu     $v0, $zero, 2
/* 9865F0 80240110 03E00008 */  jr        $ra
/* 9865F4 80240114 27BD0020 */   addiu    $sp, $sp, 0x20
