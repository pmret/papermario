.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel flo_13_UnkFunc42
/* CC6B78 80243368 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CC6B7C 8024336C AFB00010 */  sw        $s0, 0x10($sp)
/* CC6B80 80243370 0080802D */  daddu     $s0, $a0, $zero
/* CC6B84 80243374 AFBF0014 */  sw        $ra, 0x14($sp)
/* CC6B88 80243378 C60C0084 */  lwc1      $f12, 0x84($s0)
/* CC6B8C 8024337C 46806320 */  cvt.s.w   $f12, $f12
/* CC6B90 80243380 C6020090 */  lwc1      $f2, 0x90($s0)
/* CC6B94 80243384 468010A0 */  cvt.s.w   $f2, $f2
/* CC6B98 80243388 44061000 */  mfc1      $a2, $f2
/* CC6B9C 8024338C C6020098 */  lwc1      $f2, 0x98($s0)
/* CC6BA0 80243390 468010A0 */  cvt.s.w   $f2, $f2
/* CC6BA4 80243394 44071000 */  mfc1      $a3, $f2
/* CC6BA8 80243398 C60E008C */  lwc1      $f14, 0x8c($s0)
/* CC6BAC 8024339C 0C00A720 */  jal       atan2
/* CC6BB0 802433A0 468073A0 */   cvt.s.w  $f14, $f14
/* CC6BB4 802433A4 4600008D */  trunc.w.s $f2, $f0
/* CC6BB8 802433A8 E60200AC */  swc1      $f2, 0xac($s0)
/* CC6BBC 802433AC 8FBF0014 */  lw        $ra, 0x14($sp)
/* CC6BC0 802433B0 8FB00010 */  lw        $s0, 0x10($sp)
/* CC6BC4 802433B4 24020002 */  addiu     $v0, $zero, 2
/* CC6BC8 802433B8 03E00008 */  jr        $ra
/* CC6BCC 802433BC 27BD0018 */   addiu    $sp, $sp, 0x18
