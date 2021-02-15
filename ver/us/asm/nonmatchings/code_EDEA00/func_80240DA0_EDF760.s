.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240DA0_EDF760
/* EDF760 80240DA0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EDF764 80240DA4 AFB20018 */  sw        $s2, 0x18($sp)
/* EDF768 80240DA8 0080902D */  daddu     $s2, $a0, $zero
/* EDF76C 80240DAC AFBF001C */  sw        $ra, 0x1c($sp)
/* EDF770 80240DB0 AFB10014 */  sw        $s1, 0x14($sp)
/* EDF774 80240DB4 AFB00010 */  sw        $s0, 0x10($sp)
/* EDF778 80240DB8 8E510148 */  lw        $s1, 0x148($s2)
/* EDF77C 80240DBC 0C00F92F */  jal       func_8003E4BC
/* EDF780 80240DC0 86240008 */   lh       $a0, 8($s1)
/* EDF784 80240DC4 0040802D */  daddu     $s0, $v0, $zero
/* EDF788 80240DC8 3C028010 */  lui       $v0, %hi(D_800FFC90)
/* EDF78C 80240DCC 8C42FC90 */  lw        $v0, %lo(D_800FFC90)($v0)
/* EDF790 80240DD0 C60C0038 */  lwc1      $f12, 0x38($s0)
/* EDF794 80240DD4 C60E0040 */  lwc1      $f14, 0x40($s0)
/* EDF798 80240DD8 A600008E */  sh        $zero, 0x8e($s0)
/* EDF79C 80240DDC 8C460028 */  lw        $a2, 0x28($v0)
/* EDF7A0 80240DE0 0C00ABDC */  jal       fio_validate_header_checksums
/* EDF7A4 80240DE4 8C470030 */   lw       $a3, 0x30($v0)
/* EDF7A8 80240DE8 E600000C */  swc1      $f0, 0xc($s0)
/* EDF7AC 80240DEC 8E2200CC */  lw        $v0, 0xcc($s1)
/* EDF7B0 80240DF0 8C420020 */  lw        $v0, 0x20($v0)
/* EDF7B4 80240DF4 AE020028 */  sw        $v0, 0x28($s0)
/* EDF7B8 80240DF8 2402000B */  addiu     $v0, $zero, 0xb
/* EDF7BC 80240DFC AE420070 */  sw        $v0, 0x70($s2)
/* EDF7C0 80240E00 8FBF001C */  lw        $ra, 0x1c($sp)
/* EDF7C4 80240E04 8FB20018 */  lw        $s2, 0x18($sp)
/* EDF7C8 80240E08 8FB10014 */  lw        $s1, 0x14($sp)
/* EDF7CC 80240E0C 8FB00010 */  lw        $s0, 0x10($sp)
/* EDF7D0 80240E10 03E00008 */  jr        $ra
/* EDF7D4 80240E14 27BD0020 */   addiu    $sp, $sp, 0x20
