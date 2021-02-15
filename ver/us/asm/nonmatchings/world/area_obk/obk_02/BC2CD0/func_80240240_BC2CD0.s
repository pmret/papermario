.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240240_BC2CD0
/* BC2CD0 80240240 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BC2CD4 80240244 AFB00010 */  sw        $s0, 0x10($sp)
/* BC2CD8 80240248 0080802D */  daddu     $s0, $a0, $zero
/* BC2CDC 8024024C AFBF0014 */  sw        $ra, 0x14($sp)
/* BC2CE0 80240250 C60C0088 */  lwc1      $f12, 0x88($s0)
/* BC2CE4 80240254 0C00A8BB */  jal       sin_deg
/* BC2CE8 80240258 46806320 */   cvt.s.w  $f12, $f12
/* BC2CEC 8024025C 3C014120 */  lui       $at, 0x4120
/* BC2CF0 80240260 44811000 */  mtc1      $at, $f2
/* BC2CF4 80240264 00000000 */  nop
/* BC2CF8 80240268 46020002 */  mul.s     $f0, $f0, $f2
/* BC2CFC 8024026C 00000000 */  nop
/* BC2D00 80240270 8E020088 */  lw        $v0, 0x88($s0)
/* BC2D04 80240274 24420006 */  addiu     $v0, $v0, 6
/* BC2D08 80240278 44826000 */  mtc1      $v0, $f12
/* BC2D0C 8024027C 00000000 */  nop
/* BC2D10 80240280 46806320 */  cvt.s.w   $f12, $f12
/* BC2D14 80240284 4600010D */  trunc.w.s $f4, $f0
/* BC2D18 80240288 0C00A6C9 */  jal       clamp_angle
/* BC2D1C 8024028C E6040084 */   swc1     $f4, 0x84($s0)
/* BC2D20 80240290 4600010D */  trunc.w.s $f4, $f0
/* BC2D24 80240294 E6040088 */  swc1      $f4, 0x88($s0)
/* BC2D28 80240298 8FBF0014 */  lw        $ra, 0x14($sp)
/* BC2D2C 8024029C 8FB00010 */  lw        $s0, 0x10($sp)
/* BC2D30 802402A0 24020002 */  addiu     $v0, $zero, 2
/* BC2D34 802402A4 03E00008 */  jr        $ra
/* BC2D38 802402A8 27BD0018 */   addiu    $sp, $sp, 0x18
/* BC2D3C 802402AC 00000000 */  nop
