.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240530_CDCBD0
/* CDCBD0 80240530 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CDCBD4 80240534 AFB00010 */  sw        $s0, 0x10($sp)
/* CDCBD8 80240538 0080802D */  daddu     $s0, $a0, $zero
/* CDCBDC 8024053C AFBF0014 */  sw        $ra, 0x14($sp)
/* CDCBE0 80240540 C60C0084 */  lwc1      $f12, 0x84($s0)
/* CDCBE4 80240544 46806320 */  cvt.s.w   $f12, $f12
/* CDCBE8 80240548 C6020090 */  lwc1      $f2, 0x90($s0)
/* CDCBEC 8024054C 468010A0 */  cvt.s.w   $f2, $f2
/* CDCBF0 80240550 44061000 */  mfc1      $a2, $f2
/* CDCBF4 80240554 C6020098 */  lwc1      $f2, 0x98($s0)
/* CDCBF8 80240558 468010A0 */  cvt.s.w   $f2, $f2
/* CDCBFC 8024055C 44071000 */  mfc1      $a3, $f2
/* CDCC00 80240560 C60E008C */  lwc1      $f14, 0x8c($s0)
/* CDCC04 80240564 0C00A720 */  jal       atan2
/* CDCC08 80240568 468073A0 */   cvt.s.w  $f14, $f14
/* CDCC0C 8024056C 4600008D */  trunc.w.s $f2, $f0
/* CDCC10 80240570 E60200AC */  swc1      $f2, 0xac($s0)
/* CDCC14 80240574 8FBF0014 */  lw        $ra, 0x14($sp)
/* CDCC18 80240578 8FB00010 */  lw        $s0, 0x10($sp)
/* CDCC1C 8024057C 24020002 */  addiu     $v0, $zero, 2
/* CDCC20 80240580 03E00008 */  jr        $ra
/* CDCC24 80240584 27BD0018 */   addiu    $sp, $sp, 0x18
/* CDCC28 80240588 00000000 */  nop       
/* CDCC2C 8024058C 00000000 */  nop       
