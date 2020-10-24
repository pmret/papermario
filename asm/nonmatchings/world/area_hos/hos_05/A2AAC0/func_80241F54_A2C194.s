.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241F54_A2C194
/* A2C194 80241F54 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A2C198 80241F58 AFB00010 */  sw        $s0, 0x10($sp)
/* A2C19C 80241F5C 00A0802D */  daddu     $s0, $a1, $zero
/* A2C1A0 80241F60 AFBF0014 */  sw        $ra, 0x14($sp)
/* A2C1A4 80241F64 0C0B36B0 */  jal       resolve_npc
/* A2C1A8 80241F68 24050009 */   addiu    $a1, $zero, 9
/* A2C1AC 80241F6C 12000011 */  beqz      $s0, .L80241FB4
/* A2C1B0 80241F70 0040282D */   daddu    $a1, $v0, $zero
/* A2C1B4 80241F74 3C01C311 */  lui       $at, 0xc311
/* A2C1B8 80241F78 44810000 */  mtc1      $at, $f0
/* A2C1BC 80241F7C 3C0142A8 */  lui       $at, 0x42a8
/* A2C1C0 80241F80 44811000 */  mtc1      $at, $f2
/* A2C1C4 80241F84 E4A00038 */  swc1      $f0, 0x38($a1)
/* A2C1C8 80241F88 46000106 */  mov.s     $f4, $f0
/* A2C1CC 80241F8C E4A20040 */  swc1      $f2, 0x40($a1)
/* A2C1D0 80241F90 3C0142B4 */  lui       $at, 0x42b4
/* A2C1D4 80241F94 44811000 */  mtc1      $at, $f2
/* A2C1D8 80241F98 C4A60040 */  lwc1      $f6, 0x40($a1)
/* A2C1DC 80241F9C 3C014313 */  lui       $at, 0x4313
/* A2C1E0 80241FA0 44810000 */  mtc1      $at, $f0
/* A2C1E4 80241FA4 E4A4006C */  swc1      $f4, 0x6c($a1)
/* A2C1E8 80241FA8 E4A2000C */  swc1      $f2, 0xc($a1)
/* A2C1EC 80241FAC E4A0003C */  swc1      $f0, 0x3c($a1)
/* A2C1F0 80241FB0 E4A60074 */  swc1      $f6, 0x74($a1)
.L80241FB4:
/* A2C1F4 80241FB4 3C048025 */  lui       $a0, 0x8025
/* A2C1F8 80241FB8 24849A48 */  addiu     $a0, $a0, -0x65b8
/* A2C1FC 80241FBC 8C830000 */  lw        $v1, ($a0)
/* A2C200 80241FC0 2462FFD8 */  addiu     $v0, $v1, -0x28
/* A2C204 80241FC4 3042001E */  andi      $v0, $v0, 0x1e
/* A2C208 80241FC8 3C018025 */  lui       $at, 0x8025
/* A2C20C 80241FCC 00220821 */  addu      $at, $at, $v0
/* A2C210 80241FD0 84229A4C */  lh        $v0, -0x65b4($at)
/* A2C214 80241FD4 3C013DCC */  lui       $at, 0x3dcc
/* A2C218 80241FD8 3421CCCD */  ori       $at, $at, 0xcccd
/* A2C21C 80241FDC 44810000 */  mtc1      $at, $f0
/* A2C220 80241FE0 44821000 */  mtc1      $v0, $f2
/* A2C224 80241FE4 00000000 */  nop       
/* A2C228 80241FE8 468010A0 */  cvt.s.w   $f2, $f2
/* A2C22C 80241FEC 46001082 */  mul.s     $f2, $f2, $f0
/* A2C230 80241FF0 00000000 */  nop       
/* A2C234 80241FF4 C4A0003C */  lwc1      $f0, 0x3c($a1)
/* A2C238 80241FF8 24630001 */  addiu     $v1, $v1, 1
/* A2C23C 80241FFC 46020000 */  add.s     $f0, $f0, $f2
/* A2C240 80242000 286207D0 */  slti      $v0, $v1, 0x7d0
/* A2C244 80242004 AC830000 */  sw        $v1, ($a0)
/* A2C248 80242008 E4A0003C */  swc1      $f0, 0x3c($a1)
/* A2C24C 8024200C E4A00070 */  swc1      $f0, 0x70($a1)
/* A2C250 80242010 8FBF0014 */  lw        $ra, 0x14($sp)
/* A2C254 80242014 8FB00010 */  lw        $s0, 0x10($sp)
/* A2C258 80242018 38420001 */  xori      $v0, $v0, 1
/* A2C25C 8024201C 03E00008 */  jr        $ra
/* A2C260 80242020 27BD0018 */   addiu    $sp, $sp, 0x18
