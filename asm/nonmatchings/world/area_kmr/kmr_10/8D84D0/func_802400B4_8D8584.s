.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400B4_8D8584
/* 8D8584 802400B4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8D8588 802400B8 AFB00010 */  sw        $s0, 0x10($sp)
/* 8D858C 802400BC 0080802D */  daddu     $s0, $a0, $zero
/* 8D8590 802400C0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 8D8594 802400C4 AFB10014 */  sw        $s1, 0x14($sp)
/* 8D8598 802400C8 8E02000C */  lw        $v0, 0xc($s0)
/* 8D859C 802400CC 8C510000 */  lw        $s1, ($v0)
/* 8D85A0 802400D0 0C0B1EAF */  jal       get_variable
/* 8D85A4 802400D4 0220282D */   daddu    $a1, $s1, $zero
/* 8D85A8 802400D8 3C03FFF0 */  lui       $v1, 0xfff0
/* 8D85AC 802400DC 3463FFFF */  ori       $v1, $v1, 0xffff
/* 8D85B0 802400E0 0200202D */  daddu     $a0, $s0, $zero
/* 8D85B4 802400E4 00431024 */  and       $v0, $v0, $v1
/* 8D85B8 802400E8 00021140 */  sll       $v0, $v0, 5
/* 8D85BC 802400EC 3C068008 */  lui       $a2, %hi(gItemTable)
/* 8D85C0 802400F0 00C23021 */  addu      $a2, $a2, $v0
/* 8D85C4 802400F4 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* 8D85C8 802400F8 0C0B2026 */  jal       set_variable
/* 8D85CC 802400FC 0220282D */   daddu    $a1, $s1, $zero
/* 8D85D0 80240100 8FBF0018 */  lw        $ra, 0x18($sp)
/* 8D85D4 80240104 8FB10014 */  lw        $s1, 0x14($sp)
/* 8D85D8 80240108 8FB00010 */  lw        $s0, 0x10($sp)
/* 8D85DC 8024010C 24020002 */  addiu     $v0, $zero, 2
/* 8D85E0 80240110 03E00008 */  jr        $ra
/* 8D85E4 80240114 27BD0020 */   addiu    $sp, $sp, 0x20
