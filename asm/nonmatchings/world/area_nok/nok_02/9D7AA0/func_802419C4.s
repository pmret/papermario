.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802419C4
/* 9D89E4 802419C4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9D89E8 802419C8 AFB00010 */  sw        $s0, 0x10($sp)
/* 9D89EC 802419CC 0080802D */  daddu     $s0, $a0, $zero
/* 9D89F0 802419D0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 9D89F4 802419D4 AFB10014 */  sw        $s1, 0x14($sp)
/* 9D89F8 802419D8 8E02000C */  lw        $v0, 0xc($s0)
/* 9D89FC 802419DC 8C510000 */  lw        $s1, ($v0)
/* 9D8A00 802419E0 0C0B1EAF */  jal       get_variable
/* 9D8A04 802419E4 0220282D */   daddu    $a1, $s1, $zero
/* 9D8A08 802419E8 3C03FFF0 */  lui       $v1, 0xfff0
/* 9D8A0C 802419EC 3463FFFF */  ori       $v1, $v1, 0xffff
/* 9D8A10 802419F0 0200202D */  daddu     $a0, $s0, $zero
/* 9D8A14 802419F4 00431024 */  and       $v0, $v0, $v1
/* 9D8A18 802419F8 00021140 */  sll       $v0, $v0, 5
/* 9D8A1C 802419FC 3C068008 */  lui       $a2, %hi(gItemTable)
/* 9D8A20 80241A00 00C23021 */  addu      $a2, $a2, $v0
/* 9D8A24 80241A04 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* 9D8A28 80241A08 0C0B2026 */  jal       set_variable
/* 9D8A2C 80241A0C 0220282D */   daddu    $a1, $s1, $zero
/* 9D8A30 80241A10 8FBF0018 */  lw        $ra, 0x18($sp)
/* 9D8A34 80241A14 8FB10014 */  lw        $s1, 0x14($sp)
/* 9D8A38 80241A18 8FB00010 */  lw        $s0, 0x10($sp)
/* 9D8A3C 80241A1C 24020002 */  addiu     $v0, $zero, 2
/* 9D8A40 80241A20 03E00008 */  jr        $ra
/* 9D8A44 80241A24 27BD0020 */   addiu    $sp, $sp, 0x20
