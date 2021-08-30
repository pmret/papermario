.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240020_AB62B0
/* AB62B0 80240020 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* AB62B4 80240024 AFB00010 */  sw        $s0, 0x10($sp)
/* AB62B8 80240028 0080802D */  daddu     $s0, $a0, $zero
/* AB62BC 8024002C AFBF0018 */  sw        $ra, 0x18($sp)
/* AB62C0 80240030 AFB10014 */  sw        $s1, 0x14($sp)
/* AB62C4 80240034 8E11000C */  lw        $s1, 0xc($s0)
/* AB62C8 80240038 0C0B1EAF */  jal       evt_get_variable
/* AB62CC 8024003C 8E250000 */   lw       $a1, ($s1)
/* AB62D0 80240040 44826000 */  mtc1      $v0, $f12
/* AB62D4 80240044 00000000 */  nop
/* AB62D8 80240048 0C00A8BB */  jal       sin_deg
/* AB62DC 8024004C 46806320 */   cvt.s.w  $f12, $f12
/* AB62E0 80240050 3C0141A0 */  lui       $at, 0x41a0
/* AB62E4 80240054 44811000 */  mtc1      $at, $f2
/* AB62E8 80240058 00000000 */  nop
/* AB62EC 8024005C 46020002 */  mul.s     $f0, $f0, $f2
/* AB62F0 80240060 00000000 */  nop
/* AB62F4 80240064 8E250000 */  lw        $a1, ($s1)
/* AB62F8 80240068 4600010D */  trunc.w.s $f4, $f0
/* AB62FC 8024006C 44062000 */  mfc1      $a2, $f4
/* AB6300 80240070 0C0B2026 */  jal       evt_set_variable
/* AB6304 80240074 0200202D */   daddu    $a0, $s0, $zero
/* AB6308 80240078 8FBF0018 */  lw        $ra, 0x18($sp)
/* AB630C 8024007C 8FB10014 */  lw        $s1, 0x14($sp)
/* AB6310 80240080 8FB00010 */  lw        $s0, 0x10($sp)
/* AB6314 80240084 24020002 */  addiu     $v0, $zero, 2
/* AB6318 80240088 03E00008 */  jr        $ra
/* AB631C 8024008C 27BD0020 */   addiu    $sp, $sp, 0x20
