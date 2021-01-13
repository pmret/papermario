.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240050_AB9300
/* AB9300 80240050 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* AB9304 80240054 AFB00010 */  sw        $s0, 0x10($sp)
/* AB9308 80240058 0080802D */  daddu     $s0, $a0, $zero
/* AB930C 8024005C AFBF0018 */  sw        $ra, 0x18($sp)
/* AB9310 80240060 AFB10014 */  sw        $s1, 0x14($sp)
/* AB9314 80240064 8E11000C */  lw        $s1, 0xc($s0)
/* AB9318 80240068 0C0B1EAF */  jal       get_variable
/* AB931C 8024006C 8E250000 */   lw       $a1, ($s1)
/* AB9320 80240070 44826000 */  mtc1      $v0, $f12
/* AB9324 80240074 00000000 */  nop
/* AB9328 80240078 0C00A8BB */  jal       sin_deg
/* AB932C 8024007C 46806320 */   cvt.s.w  $f12, $f12
/* AB9330 80240080 3C0141A0 */  lui       $at, 0x41a0
/* AB9334 80240084 44811000 */  mtc1      $at, $f2
/* AB9338 80240088 00000000 */  nop
/* AB933C 8024008C 46020002 */  mul.s     $f0, $f0, $f2
/* AB9340 80240090 00000000 */  nop
/* AB9344 80240094 8E250000 */  lw        $a1, ($s1)
/* AB9348 80240098 4600010D */  trunc.w.s $f4, $f0
/* AB934C 8024009C 44062000 */  mfc1      $a2, $f4
/* AB9350 802400A0 0C0B2026 */  jal       set_variable
/* AB9354 802400A4 0200202D */   daddu    $a0, $s0, $zero
/* AB9358 802400A8 8FBF0018 */  lw        $ra, 0x18($sp)
/* AB935C 802400AC 8FB10014 */  lw        $s1, 0x14($sp)
/* AB9360 802400B0 8FB00010 */  lw        $s0, 0x10($sp)
/* AB9364 802400B4 24020002 */  addiu     $v0, $zero, 2
/* AB9368 802400B8 03E00008 */  jr        $ra
/* AB936C 802400BC 27BD0020 */   addiu    $sp, $sp, 0x20
