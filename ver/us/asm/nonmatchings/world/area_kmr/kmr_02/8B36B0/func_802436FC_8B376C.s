.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel kmr_02_UnkFunc42
/* 8B376C 802436FC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8B3770 80243700 AFB00010 */  sw        $s0, 0x10($sp)
/* 8B3774 80243704 0080802D */  daddu     $s0, $a0, $zero
/* 8B3778 80243708 AFBF0014 */  sw        $ra, 0x14($sp)
/* 8B377C 8024370C C60C0084 */  lwc1      $f12, 0x84($s0)
/* 8B3780 80243710 46806320 */  cvt.s.w   $f12, $f12
/* 8B3784 80243714 C6020090 */  lwc1      $f2, 0x90($s0)
/* 8B3788 80243718 468010A0 */  cvt.s.w   $f2, $f2
/* 8B378C 8024371C 44061000 */  mfc1      $a2, $f2
/* 8B3790 80243720 C6020098 */  lwc1      $f2, 0x98($s0)
/* 8B3794 80243724 468010A0 */  cvt.s.w   $f2, $f2
/* 8B3798 80243728 44071000 */  mfc1      $a3, $f2
/* 8B379C 8024372C C60E008C */  lwc1      $f14, 0x8c($s0)
/* 8B37A0 80243730 0C00A720 */  jal       atan2
/* 8B37A4 80243734 468073A0 */   cvt.s.w  $f14, $f14
/* 8B37A8 80243738 4600008D */  trunc.w.s $f2, $f0
/* 8B37AC 8024373C E60200AC */  swc1      $f2, 0xac($s0)
/* 8B37B0 80243740 8FBF0014 */  lw        $ra, 0x14($sp)
/* 8B37B4 80243744 8FB00010 */  lw        $s0, 0x10($sp)
/* 8B37B8 80243748 24020002 */  addiu     $v0, $zero, 2
/* 8B37BC 8024374C 03E00008 */  jr        $ra
/* 8B37C0 80243750 27BD0018 */   addiu    $sp, $sp, 0x18
/* 8B37C4 80243754 00000000 */  nop
/* 8B37C8 80243758 00000000 */  nop
/* 8B37CC 8024375C 00000000 */  nop
