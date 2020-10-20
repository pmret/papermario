.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400B4_BCECA4
/* BCECA4 802400B4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BCECA8 802400B8 AFB00010 */  sw        $s0, 0x10($sp)
/* BCECAC 802400BC 0080802D */  daddu     $s0, $a0, $zero
/* BCECB0 802400C0 AFBF0018 */  sw        $ra, 0x18($sp)
/* BCECB4 802400C4 AFB10014 */  sw        $s1, 0x14($sp)
/* BCECB8 802400C8 8E02000C */  lw        $v0, 0xc($s0)
/* BCECBC 802400CC 8C510000 */  lw        $s1, ($v0)
/* BCECC0 802400D0 0C0B1EAF */  jal       get_variable
/* BCECC4 802400D4 0220282D */   daddu    $a1, $s1, $zero
/* BCECC8 802400D8 3C03FFF0 */  lui       $v1, 0xfff0
/* BCECCC 802400DC 3463FFFF */  ori       $v1, $v1, 0xffff
/* BCECD0 802400E0 0200202D */  daddu     $a0, $s0, $zero
/* BCECD4 802400E4 00431024 */  and       $v0, $v0, $v1
/* BCECD8 802400E8 00021140 */  sll       $v0, $v0, 5
/* BCECDC 802400EC 3C068008 */  lui       $a2, %hi(gItemTable)
/* BCECE0 802400F0 00C23021 */  addu      $a2, $a2, $v0
/* BCECE4 802400F4 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* BCECE8 802400F8 0C0B2026 */  jal       set_variable
/* BCECEC 802400FC 0220282D */   daddu    $a1, $s1, $zero
/* BCECF0 80240100 8FBF0018 */  lw        $ra, 0x18($sp)
/* BCECF4 80240104 8FB10014 */  lw        $s1, 0x14($sp)
/* BCECF8 80240108 8FB00010 */  lw        $s0, 0x10($sp)
/* BCECFC 8024010C 24020002 */  addiu     $v0, $zero, 2
/* BCED00 80240110 03E00008 */  jr        $ra
/* BCED04 80240114 27BD0020 */   addiu    $sp, $sp, 0x20
