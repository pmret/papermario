.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400B4_AFDBF4
/* AFDBF4 802400B4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* AFDBF8 802400B8 AFB00010 */  sw        $s0, 0x10($sp)
/* AFDBFC 802400BC 0080802D */  daddu     $s0, $a0, $zero
/* AFDC00 802400C0 AFBF0018 */  sw        $ra, 0x18($sp)
/* AFDC04 802400C4 AFB10014 */  sw        $s1, 0x14($sp)
/* AFDC08 802400C8 8E02000C */  lw        $v0, 0xc($s0)
/* AFDC0C 802400CC 8C510000 */  lw        $s1, ($v0)
/* AFDC10 802400D0 0C0B1EAF */  jal       get_variable
/* AFDC14 802400D4 0220282D */   daddu    $a1, $s1, $zero
/* AFDC18 802400D8 3C03FFF0 */  lui       $v1, 0xfff0
/* AFDC1C 802400DC 3463FFFF */  ori       $v1, $v1, 0xffff
/* AFDC20 802400E0 0200202D */  daddu     $a0, $s0, $zero
/* AFDC24 802400E4 00431024 */  and       $v0, $v0, $v1
/* AFDC28 802400E8 00021140 */  sll       $v0, $v0, 5
/* AFDC2C 802400EC 3C068008 */  lui       $a2, %hi(gItemTable)
/* AFDC30 802400F0 00C23021 */  addu      $a2, $a2, $v0
/* AFDC34 802400F4 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* AFDC38 802400F8 0C0B2026 */  jal       set_variable
/* AFDC3C 802400FC 0220282D */   daddu    $a1, $s1, $zero
/* AFDC40 80240100 8FBF0018 */  lw        $ra, 0x18($sp)
/* AFDC44 80240104 8FB10014 */  lw        $s1, 0x14($sp)
/* AFDC48 80240108 8FB00010 */  lw        $s0, 0x10($sp)
/* AFDC4C 8024010C 24020002 */  addiu     $v0, $zero, 2
/* AFDC50 80240110 03E00008 */  jr        $ra
/* AFDC54 80240114 27BD0020 */   addiu    $sp, $sp, 0x20
