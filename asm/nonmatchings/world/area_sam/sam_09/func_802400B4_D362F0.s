.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400B4_D363A4
/* D363A4 802400B4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D363A8 802400B8 AFB00010 */  sw        $s0, 0x10($sp)
/* D363AC 802400BC 0080802D */  daddu     $s0, $a0, $zero
/* D363B0 802400C0 AFBF0018 */  sw        $ra, 0x18($sp)
/* D363B4 802400C4 AFB10014 */  sw        $s1, 0x14($sp)
/* D363B8 802400C8 8E02000C */  lw        $v0, 0xc($s0)
/* D363BC 802400CC 8C510000 */  lw        $s1, ($v0)
/* D363C0 802400D0 0C0B1EAF */  jal       get_variable
/* D363C4 802400D4 0220282D */   daddu    $a1, $s1, $zero
/* D363C8 802400D8 3C03FFF0 */  lui       $v1, 0xfff0
/* D363CC 802400DC 3463FFFF */  ori       $v1, $v1, 0xffff
/* D363D0 802400E0 0200202D */  daddu     $a0, $s0, $zero
/* D363D4 802400E4 00431024 */  and       $v0, $v0, $v1
/* D363D8 802400E8 00021140 */  sll       $v0, $v0, 5
/* D363DC 802400EC 3C068008 */  lui       $a2, %hi(gItemTable)
/* D363E0 802400F0 00C23021 */  addu      $a2, $a2, $v0
/* D363E4 802400F4 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* D363E8 802400F8 0C0B2026 */  jal       set_variable
/* D363EC 802400FC 0220282D */   daddu    $a1, $s1, $zero
/* D363F0 80240100 8FBF0018 */  lw        $ra, 0x18($sp)
/* D363F4 80240104 8FB10014 */  lw        $s1, 0x14($sp)
/* D363F8 80240108 8FB00010 */  lw        $s0, 0x10($sp)
/* D363FC 8024010C 24020002 */  addiu     $v0, $zero, 2
/* D36400 80240110 03E00008 */  jr        $ra
/* D36404 80240114 27BD0020 */   addiu    $sp, $sp, 0x20
