.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400B0_98AAC0
/* 98AAC0 802400B0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 98AAC4 802400B4 AFB10014 */  sw        $s1, 0x14($sp)
/* 98AAC8 802400B8 0080882D */  daddu     $s1, $a0, $zero
/* 98AACC 802400BC AFBF0018 */  sw        $ra, 0x18($sp)
/* 98AAD0 802400C0 AFB00010 */  sw        $s0, 0x10($sp)
/* 98AAD4 802400C4 8E30000C */  lw        $s0, 0xc($s1)
/* 98AAD8 802400C8 8E050000 */  lw        $a1, ($s0)
/* 98AADC 802400CC 0C0B1EAF */  jal       get_variable
/* 98AAE0 802400D0 26100004 */   addiu    $s0, $s0, 4
/* 98AAE4 802400D4 3C03FFF0 */  lui       $v1, 0xfff0
/* 98AAE8 802400D8 3463FFFF */  ori       $v1, $v1, 0xffff
/* 98AAEC 802400DC 00431024 */  and       $v0, $v0, $v1
/* 98AAF0 802400E0 00021140 */  sll       $v0, $v0, 5
/* 98AAF4 802400E4 8E050000 */  lw        $a1, ($s0)
/* 98AAF8 802400E8 3C068008 */  lui       $a2, %hi(gItemTable)
/* 98AAFC 802400EC 00C23021 */  addu      $a2, $a2, $v0
/* 98AB00 802400F0 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* 98AB04 802400F4 0C0B2026 */  jal       set_variable
/* 98AB08 802400F8 0220202D */   daddu    $a0, $s1, $zero
/* 98AB0C 802400FC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 98AB10 80240100 8FB10014 */  lw        $s1, 0x14($sp)
/* 98AB14 80240104 8FB00010 */  lw        $s0, 0x10($sp)
/* 98AB18 80240108 24020002 */  addiu     $v0, $zero, 2
/* 98AB1C 8024010C 03E00008 */  jr        $ra
/* 98AB20 80240110 27BD0020 */   addiu    $sp, $sp, 0x20
/* 98AB24 80240114 00000000 */  nop
/* 98AB28 80240118 00000000 */  nop
/* 98AB2C 8024011C 00000000 */  nop
