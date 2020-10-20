.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240DC4_B35994
/* B35994 80240DC4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B35998 80240DC8 AFB00010 */  sw        $s0, 0x10($sp)
/* B3599C 80240DCC 0080802D */  daddu     $s0, $a0, $zero
/* B359A0 80240DD0 AFBF0014 */  sw        $ra, 0x14($sp)
/* B359A4 80240DD4 8E020148 */  lw        $v0, 0x148($s0)
/* B359A8 80240DD8 0C00EABB */  jal       get_npc_unsafe
/* B359AC 80240DDC 84440008 */   lh       $a0, 8($v0)
/* B359B0 80240DE0 0040202D */  daddu     $a0, $v0, $zero
/* B359B4 80240DE4 C482003C */  lwc1      $f2, 0x3c($a0)
/* B359B8 80240DE8 C480001C */  lwc1      $f0, 0x1c($a0)
/* B359BC 80240DEC 46001080 */  add.s     $f2, $f2, $f0
/* B359C0 80240DF0 C4840014 */  lwc1      $f4, 0x14($a0)
/* B359C4 80240DF4 46040001 */  sub.s     $f0, $f0, $f4
/* B359C8 80240DF8 C4840064 */  lwc1      $f4, 0x64($a0)
/* B359CC 80240DFC 4602203C */  c.lt.s    $f4, $f2
/* B359D0 80240E00 E482003C */  swc1      $f2, 0x3c($a0)
/* B359D4 80240E04 45010009 */  bc1t      .L80240E2C
/* B359D8 80240E08 E480001C */   swc1     $f0, 0x1c($a0)
/* B359DC 80240E0C 8C820000 */  lw        $v0, ($a0)
/* B359E0 80240E10 2403F7FF */  addiu     $v1, $zero, -0x801
/* B359E4 80240E14 E484003C */  swc1      $f4, 0x3c($a0)
/* B359E8 80240E18 AC80001C */  sw        $zero, 0x1c($a0)
/* B359EC 80240E1C 00431024 */  and       $v0, $v0, $v1
/* B359F0 80240E20 AC820000 */  sw        $v0, ($a0)
/* B359F4 80240E24 2402000C */  addiu     $v0, $zero, 0xc
/* B359F8 80240E28 AE020070 */  sw        $v0, 0x70($s0)
.L80240E2C:
/* B359FC 80240E2C 8FBF0014 */  lw        $ra, 0x14($sp)
/* B35A00 80240E30 8FB00010 */  lw        $s0, 0x10($sp)
/* B35A04 80240E34 03E00008 */  jr        $ra
/* B35A08 80240E38 27BD0018 */   addiu    $sp, $sp, 0x18
