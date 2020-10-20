.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802404A8_B209E8
/* B209E8 802404A8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B209EC 802404AC AFB00010 */  sw        $s0, 0x10($sp)
/* B209F0 802404B0 0080802D */  daddu     $s0, $a0, $zero
/* B209F4 802404B4 AFBF0018 */  sw        $ra, 0x18($sp)
/* B209F8 802404B8 AFB10014 */  sw        $s1, 0x14($sp)
/* B209FC 802404BC 8E02000C */  lw        $v0, 0xc($s0)
/* B20A00 802404C0 8C510000 */  lw        $s1, ($v0)
/* B20A04 802404C4 0C0B1EAF */  jal       get_variable
/* B20A08 802404C8 0220282D */   daddu    $a1, $s1, $zero
/* B20A0C 802404CC 3C03FFF0 */  lui       $v1, 0xfff0
/* B20A10 802404D0 3463FFFF */  ori       $v1, $v1, 0xffff
/* B20A14 802404D4 0200202D */  daddu     $a0, $s0, $zero
/* B20A18 802404D8 00431024 */  and       $v0, $v0, $v1
/* B20A1C 802404DC 00021140 */  sll       $v0, $v0, 5
/* B20A20 802404E0 3C068008 */  lui       $a2, %hi(gItemTable)
/* B20A24 802404E4 00C23021 */  addu      $a2, $a2, $v0
/* B20A28 802404E8 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* B20A2C 802404EC 0C0B2026 */  jal       set_variable
/* B20A30 802404F0 0220282D */   daddu    $a1, $s1, $zero
/* B20A34 802404F4 8FBF0018 */  lw        $ra, 0x18($sp)
/* B20A38 802404F8 8FB10014 */  lw        $s1, 0x14($sp)
/* B20A3C 802404FC 8FB00010 */  lw        $s0, 0x10($sp)
/* B20A40 80240500 24020002 */  addiu     $v0, $zero, 2
/* B20A44 80240504 03E00008 */  jr        $ra
/* B20A48 80240508 27BD0020 */   addiu    $sp, $sp, 0x20
