.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E54_B07854
/* B07854 80240E54 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B07858 80240E58 AFB00010 */  sw        $s0, 0x10($sp)
/* B0785C 80240E5C 0080802D */  daddu     $s0, $a0, $zero
/* B07860 80240E60 10A00003 */  beqz      $a1, .L80240E70
/* B07864 80240E64 AFBF0014 */   sw       $ra, 0x14($sp)
/* B07868 80240E68 240200FF */  addiu     $v0, $zero, 0xff
/* B0786C 80240E6C AE020074 */  sw        $v0, 0x74($s0)
.L80240E70:
/* B07870 80240E70 C6000074 */  lwc1      $f0, 0x74($s0)
/* B07874 80240E74 46800020 */  cvt.s.w   $f0, $f0
/* B07878 80240E78 44050000 */  mfc1      $a1, $f0
/* B0787C 80240E7C 0C04DF62 */  jal       func_80137D88
/* B07880 80240E80 24040001 */   addiu    $a0, $zero, 1
/* B07884 80240E84 8E020074 */  lw        $v0, 0x74($s0)
/* B07888 80240E88 14400003 */  bnez      $v0, .L80240E98
/* B0788C 80240E8C 2442FFF0 */   addiu    $v0, $v0, -0x10
/* B07890 80240E90 080903AA */  j         .L80240EA8
/* B07894 80240E94 24020002 */   addiu    $v0, $zero, 2
.L80240E98:
/* B07898 80240E98 1C400002 */  bgtz      $v0, .L80240EA4
/* B0789C 80240E9C AE020074 */   sw       $v0, 0x74($s0)
/* B078A0 80240EA0 AE000074 */  sw        $zero, 0x74($s0)
.L80240EA4:
/* B078A4 80240EA4 0000102D */  daddu     $v0, $zero, $zero
.L80240EA8:
/* B078A8 80240EA8 8FBF0014 */  lw        $ra, 0x14($sp)
/* B078AC 80240EAC 8FB00010 */  lw        $s0, 0x10($sp)
/* B078B0 80240EB0 03E00008 */  jr        $ra
/* B078B4 80240EB4 27BD0018 */   addiu    $sp, $sp, 0x18
