.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802409F4_BC8854
/* BC8854 802409F4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BC8858 802409F8 AFB00010 */  sw        $s0, 0x10($sp)
/* BC885C 802409FC 0080802D */  daddu     $s0, $a0, $zero
/* BC8860 80240A00 AFBF0018 */  sw        $ra, 0x18($sp)
/* BC8864 80240A04 AFB10014 */  sw        $s1, 0x14($sp)
/* BC8868 80240A08 8E02000C */  lw        $v0, 0xc($s0)
/* BC886C 80240A0C 8C510000 */  lw        $s1, ($v0)
/* BC8870 80240A10 0C0B1EAF */  jal       get_variable
/* BC8874 80240A14 0220282D */   daddu    $a1, $s1, $zero
/* BC8878 80240A18 3C03FFF0 */  lui       $v1, 0xfff0
/* BC887C 80240A1C 3463FFFF */  ori       $v1, $v1, 0xffff
/* BC8880 80240A20 0200202D */  daddu     $a0, $s0, $zero
/* BC8884 80240A24 00431024 */  and       $v0, $v0, $v1
/* BC8888 80240A28 00021140 */  sll       $v0, $v0, 5
/* BC888C 80240A2C 3C068008 */  lui       $a2, %hi(gItemTable)
/* BC8890 80240A30 00C23021 */  addu      $a2, $a2, $v0
/* BC8894 80240A34 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* BC8898 80240A38 0C0B2026 */  jal       set_variable
/* BC889C 80240A3C 0220282D */   daddu    $a1, $s1, $zero
/* BC88A0 80240A40 8FBF0018 */  lw        $ra, 0x18($sp)
/* BC88A4 80240A44 8FB10014 */  lw        $s1, 0x14($sp)
/* BC88A8 80240A48 8FB00010 */  lw        $s0, 0x10($sp)
/* BC88AC 80240A4C 24020002 */  addiu     $v0, $zero, 2
/* BC88B0 80240A50 03E00008 */  jr        $ra
/* BC88B4 80240A54 27BD0020 */   addiu    $sp, $sp, 0x20
