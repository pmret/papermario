.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240BD4_B2D044
/* B2D044 80240BD4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B2D048 80240BD8 AFB00010 */  sw        $s0, 0x10($sp)
/* B2D04C 80240BDC 0080802D */  daddu     $s0, $a0, $zero
/* B2D050 80240BE0 AFBF0014 */  sw        $ra, 0x14($sp)
/* B2D054 80240BE4 8E020148 */  lw        $v0, 0x148($s0)
/* B2D058 80240BE8 0C00EABB */  jal       get_npc_unsafe
/* B2D05C 80240BEC 84440008 */   lh       $a0, 8($v0)
/* B2D060 80240BF0 0040202D */  daddu     $a0, $v0, $zero
/* B2D064 80240BF4 C482003C */  lwc1      $f2, 0x3c($a0)
/* B2D068 80240BF8 C480001C */  lwc1      $f0, 0x1c($a0)
/* B2D06C 80240BFC 46001080 */  add.s     $f2, $f2, $f0
/* B2D070 80240C00 C4840014 */  lwc1      $f4, 0x14($a0)
/* B2D074 80240C04 46040001 */  sub.s     $f0, $f0, $f4
/* B2D078 80240C08 C4840064 */  lwc1      $f4, 0x64($a0)
/* B2D07C 80240C0C 4602203C */  c.lt.s    $f4, $f2
/* B2D080 80240C10 E482003C */  swc1      $f2, 0x3c($a0)
/* B2D084 80240C14 45010009 */  bc1t      .L80240C3C
/* B2D088 80240C18 E480001C */   swc1     $f0, 0x1c($a0)
/* B2D08C 80240C1C 8C820000 */  lw        $v0, ($a0)
/* B2D090 80240C20 2403F7FF */  addiu     $v1, $zero, -0x801
/* B2D094 80240C24 E484003C */  swc1      $f4, 0x3c($a0)
/* B2D098 80240C28 AC80001C */  sw        $zero, 0x1c($a0)
/* B2D09C 80240C2C 00431024 */  and       $v0, $v0, $v1
/* B2D0A0 80240C30 AC820000 */  sw        $v0, ($a0)
/* B2D0A4 80240C34 2402000C */  addiu     $v0, $zero, 0xc
/* B2D0A8 80240C38 AE020070 */  sw        $v0, 0x70($s0)
.L80240C3C:
/* B2D0AC 80240C3C 8FBF0014 */  lw        $ra, 0x14($sp)
/* B2D0B0 80240C40 8FB00010 */  lw        $s0, 0x10($sp)
/* B2D0B4 80240C44 03E00008 */  jr        $ra
/* B2D0B8 80240C48 27BD0018 */   addiu    $sp, $sp, 0x18
