.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400B4_AF1D14
/* AF1D14 802400B4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* AF1D18 802400B8 AFB00010 */  sw        $s0, 0x10($sp)
/* AF1D1C 802400BC 0080802D */  daddu     $s0, $a0, $zero
/* AF1D20 802400C0 AFBF0018 */  sw        $ra, 0x18($sp)
/* AF1D24 802400C4 AFB10014 */  sw        $s1, 0x14($sp)
/* AF1D28 802400C8 8E02000C */  lw        $v0, 0xc($s0)
/* AF1D2C 802400CC 8C510000 */  lw        $s1, ($v0)
/* AF1D30 802400D0 0C0B1EAF */  jal       get_variable
/* AF1D34 802400D4 0220282D */   daddu    $a1, $s1, $zero
/* AF1D38 802400D8 3C03FFF0 */  lui       $v1, 0xfff0
/* AF1D3C 802400DC 3463FFFF */  ori       $v1, $v1, 0xffff
/* AF1D40 802400E0 0200202D */  daddu     $a0, $s0, $zero
/* AF1D44 802400E4 00431024 */  and       $v0, $v0, $v1
/* AF1D48 802400E8 00021140 */  sll       $v0, $v0, 5
/* AF1D4C 802400EC 3C068008 */  lui       $a2, %hi(gItemTable)
/* AF1D50 802400F0 00C23021 */  addu      $a2, $a2, $v0
/* AF1D54 802400F4 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* AF1D58 802400F8 0C0B2026 */  jal       set_variable
/* AF1D5C 802400FC 0220282D */   daddu    $a1, $s1, $zero
/* AF1D60 80240100 8FBF0018 */  lw        $ra, 0x18($sp)
/* AF1D64 80240104 8FB10014 */  lw        $s1, 0x14($sp)
/* AF1D68 80240108 8FB00010 */  lw        $s0, 0x10($sp)
/* AF1D6C 8024010C 24020002 */  addiu     $v0, $zero, 2
/* AF1D70 80240110 03E00008 */  jr        $ra
/* AF1D74 80240114 27BD0020 */   addiu    $sp, $sp, 0x20
