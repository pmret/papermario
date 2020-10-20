.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400B4_C4DFA4
/* C4DFA4 802400B4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C4DFA8 802400B8 AFB00010 */  sw        $s0, 0x10($sp)
/* C4DFAC 802400BC 0080802D */  daddu     $s0, $a0, $zero
/* C4DFB0 802400C0 AFBF0018 */  sw        $ra, 0x18($sp)
/* C4DFB4 802400C4 AFB10014 */  sw        $s1, 0x14($sp)
/* C4DFB8 802400C8 8E02000C */  lw        $v0, 0xc($s0)
/* C4DFBC 802400CC 8C510000 */  lw        $s1, ($v0)
/* C4DFC0 802400D0 0C0B1EAF */  jal       get_variable
/* C4DFC4 802400D4 0220282D */   daddu    $a1, $s1, $zero
/* C4DFC8 802400D8 3C03FFF0 */  lui       $v1, 0xfff0
/* C4DFCC 802400DC 3463FFFF */  ori       $v1, $v1, 0xffff
/* C4DFD0 802400E0 0200202D */  daddu     $a0, $s0, $zero
/* C4DFD4 802400E4 00431024 */  and       $v0, $v0, $v1
/* C4DFD8 802400E8 00021140 */  sll       $v0, $v0, 5
/* C4DFDC 802400EC 3C068008 */  lui       $a2, %hi(gItemTable)
/* C4DFE0 802400F0 00C23021 */  addu      $a2, $a2, $v0
/* C4DFE4 802400F4 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* C4DFE8 802400F8 0C0B2026 */  jal       set_variable
/* C4DFEC 802400FC 0220282D */   daddu    $a1, $s1, $zero
/* C4DFF0 80240100 8FBF0018 */  lw        $ra, 0x18($sp)
/* C4DFF4 80240104 8FB10014 */  lw        $s1, 0x14($sp)
/* C4DFF8 80240108 8FB00010 */  lw        $s0, 0x10($sp)
/* C4DFFC 8024010C 24020002 */  addiu     $v0, $zero, 2
/* C4E000 80240110 03E00008 */  jr        $ra
/* C4E004 80240114 27BD0020 */   addiu    $sp, $sp, 0x20
