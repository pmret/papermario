.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_interp_text_scroll_EE1DD8
/* EE1DD8 80243418 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EE1DDC 8024341C AFB00010 */  sw        $s0, 0x10($sp)
/* EE1DE0 80243420 0080802D */  daddu     $s0, $a0, $zero
/* EE1DE4 80243424 AFBF0014 */  sw        $ra, 0x14($sp)
/* EE1DE8 80243428 C60C0084 */  lwc1      $f12, 0x84($s0)
/* EE1DEC 8024342C 46806320 */  cvt.s.w   $f12, $f12
/* EE1DF0 80243430 C6020090 */  lwc1      $f2, 0x90($s0)
/* EE1DF4 80243434 468010A0 */  cvt.s.w   $f2, $f2
/* EE1DF8 80243438 44061000 */  mfc1      $a2, $f2
/* EE1DFC 8024343C C6020098 */  lwc1      $f2, 0x98($s0)
/* EE1E00 80243440 468010A0 */  cvt.s.w   $f2, $f2
/* EE1E04 80243444 44071000 */  mfc1      $a3, $f2
/* EE1E08 80243448 C60E008C */  lwc1      $f14, 0x8c($s0)
/* EE1E0C 8024344C 0C00ABDC */  jal       fio_validate_header_checksums
/* EE1E10 80243450 468073A0 */   cvt.s.w  $f14, $f14
/* EE1E14 80243454 4600008D */  trunc.w.s $f2, $f0
/* EE1E18 80243458 E60200AC */  swc1      $f2, 0xac($s0)
/* EE1E1C 8024345C 8FBF0014 */  lw        $ra, 0x14($sp)
/* EE1E20 80243460 8FB00010 */  lw        $s0, 0x10($sp)
/* EE1E24 80243464 24020002 */  addiu     $v0, $zero, 2
/* EE1E28 80243468 03E00008 */  jr        $ra
/* EE1E2C 8024346C 27BD0018 */   addiu    $sp, $sp, 0x18
