.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240EB8
/* B078B8 80240EB8 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* B078BC 80240EBC AFB00028 */  sw        $s0, 0x28($sp)
/* B078C0 80240EC0 0080802D */  daddu     $s0, $a0, $zero
/* B078C4 80240EC4 AFBF002C */  sw        $ra, 0x2c($sp)
/* B078C8 80240EC8 C6020084 */  lwc1      $f2, 0x84($s0)
/* B078CC 80240ECC 468010A0 */  cvt.s.w   $f2, $f2
/* B078D0 80240ED0 C6040088 */  lwc1      $f4, 0x88($s0)
/* B078D4 80240ED4 46802120 */  cvt.s.w   $f4, $f4
/* B078D8 80240ED8 C606008C */  lwc1      $f6, 0x8c($s0)
/* B078DC 80240EDC 468031A0 */  cvt.s.w   $f6, $f6
/* B078E0 80240EE0 C6000090 */  lwc1      $f0, 0x90($s0)
/* B078E4 80240EE4 46800020 */  cvt.s.w   $f0, $f0
/* B078E8 80240EE8 27A20020 */  addiu     $v0, $sp, 0x20
/* B078EC 80240EEC E7A00010 */  swc1      $f0, 0x10($sp)
/* B078F0 80240EF0 8E030094 */  lw        $v1, 0x94($s0)
/* B078F4 80240EF4 44051000 */  mfc1      $a1, $f2
/* B078F8 80240EF8 44062000 */  mfc1      $a2, $f4
/* B078FC 80240EFC 44073000 */  mfc1      $a3, $f6
/* B07900 80240F00 0000202D */  daddu     $a0, $zero, $zero
/* B07904 80240F04 AFA20018 */  sw        $v0, 0x18($sp)
/* B07908 80240F08 0C01C28C */  jal       func_80070A30
/* B0790C 80240F0C AFA30014 */   sw       $v1, 0x14($sp)
/* B07910 80240F10 8FA20020 */  lw        $v0, 0x20($sp)
/* B07914 80240F14 AE020084 */  sw        $v0, 0x84($s0)
/* B07918 80240F18 8FBF002C */  lw        $ra, 0x2c($sp)
/* B0791C 80240F1C 8FB00028 */  lw        $s0, 0x28($sp)
/* B07920 80240F20 24020002 */  addiu     $v0, $zero, 2
/* B07924 80240F24 03E00008 */  jr        $ra
/* B07928 80240F28 27BD0030 */   addiu    $sp, $sp, 0x30
