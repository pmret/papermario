.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240530_EF7FB0
/* EF7FB0 80240530 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EF7FB4 80240534 AFB00010 */  sw        $s0, 0x10($sp)
/* EF7FB8 80240538 0080802D */  daddu     $s0, $a0, $zero
/* EF7FBC 8024053C AFBF0014 */  sw        $ra, 0x14($sp)
/* EF7FC0 80240540 C60C0084 */  lwc1      $f12, 0x84($s0)
/* EF7FC4 80240544 46806320 */  cvt.s.w   $f12, $f12
/* EF7FC8 80240548 C6020090 */  lwc1      $f2, 0x90($s0)
/* EF7FCC 8024054C 468010A0 */  cvt.s.w   $f2, $f2
/* EF7FD0 80240550 44061000 */  mfc1      $a2, $f2
/* EF7FD4 80240554 C6020098 */  lwc1      $f2, 0x98($s0)
/* EF7FD8 80240558 468010A0 */  cvt.s.w   $f2, $f2
/* EF7FDC 8024055C 44071000 */  mfc1      $a3, $f2
/* EF7FE0 80240560 C60E008C */  lwc1      $f14, 0x8c($s0)
/* EF7FE4 80240564 0C00ABDC */  jal       fio_validate_header_checksums
/* EF7FE8 80240568 468073A0 */   cvt.s.w  $f14, $f14
/* EF7FEC 8024056C 4600008D */  trunc.w.s $f2, $f0
/* EF7FF0 80240570 E60200AC */  swc1      $f2, 0xac($s0)
/* EF7FF4 80240574 8FBF0014 */  lw        $ra, 0x14($sp)
/* EF7FF8 80240578 8FB00010 */  lw        $s0, 0x10($sp)
/* EF7FFC 8024057C 24020002 */  addiu     $v0, $zero, 2
/* EF8000 80240580 03E00008 */  jr        $ra
/* EF8004 80240584 27BD0018 */   addiu    $sp, $sp, 0x18
/* EF8008 80240588 00000000 */  nop
/* EF800C 8024058C 00000000 */  nop
