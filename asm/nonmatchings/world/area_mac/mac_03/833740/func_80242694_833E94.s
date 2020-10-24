.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242694_833E94
/* 833E94 80242694 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 833E98 80242698 AFB40020 */  sw        $s4, 0x20($sp)
/* 833E9C 8024269C 0080A02D */  daddu     $s4, $a0, $zero
/* 833EA0 802426A0 3C05FD05 */  lui       $a1, 0xfd05
/* 833EA4 802426A4 34A50F82 */  ori       $a1, $a1, 0xf82
/* 833EA8 802426A8 AFBF002C */  sw        $ra, 0x2c($sp)
/* 833EAC 802426AC AFB60028 */  sw        $s6, 0x28($sp)
/* 833EB0 802426B0 AFB50024 */  sw        $s5, 0x24($sp)
/* 833EB4 802426B4 AFB3001C */  sw        $s3, 0x1c($sp)
/* 833EB8 802426B8 AFB20018 */  sw        $s2, 0x18($sp)
/* 833EBC 802426BC AFB10014 */  sw        $s1, 0x14($sp)
/* 833EC0 802426C0 0C0B1EAF */  jal       get_variable
/* 833EC4 802426C4 AFB00010 */   sw       $s0, 0x10($sp)
/* 833EC8 802426C8 0040982D */  daddu     $s3, $v0, $zero
/* 833ECC 802426CC 24120001 */  addiu     $s2, $zero, 1
/* 833ED0 802426D0 3C16F5DE */  lui       $s6, 0xf5de
/* 833ED4 802426D4 36D6019E */  ori       $s6, $s6, 0x19e
/* 833ED8 802426D8 3C15F5DE */  lui       $s5, 0xf5de
/* 833EDC 802426DC 36B5019D */  ori       $s5, $s5, 0x19d
/* 833EE0 802426E0 0000882D */  daddu     $s1, $zero, $zero
.L802426E4:
/* 833EE4 802426E4 0280202D */  daddu     $a0, $s4, $zero
/* 833EE8 802426E8 0C0B1EAF */  jal       get_variable
/* 833EEC 802426EC 02562821 */   addu     $a1, $s2, $s6
/* 833EF0 802426F0 0280202D */  daddu     $a0, $s4, $zero
/* 833EF4 802426F4 02552821 */  addu      $a1, $s2, $s5
/* 833EF8 802426F8 0040802D */  daddu     $s0, $v0, $zero
/* 833EFC 802426FC 0C0B2026 */  jal       set_variable
/* 833F00 80242700 0200302D */   daddu    $a2, $s0, $zero
/* 833F04 80242704 8E63000C */  lw        $v1, 0xc($s3)
/* 833F08 80242708 00121080 */  sll       $v0, $s2, 2
/* 833F0C 8024270C 00621021 */  addu      $v0, $v1, $v0
/* 833F10 80242710 C4400034 */  lwc1      $f0, 0x34($v0)
/* 833F14 80242714 C4420060 */  lwc1      $f2, 0x60($v0)
/* 833F18 80242718 C444008C */  lwc1      $f4, 0x8c($v0)
/* 833F1C 8024271C C44600B8 */  lwc1      $f6, 0xb8($v0)
/* 833F20 80242720 02431821 */  addu      $v1, $s2, $v1
/* 833F24 80242724 A07000E3 */  sb        $s0, 0xe3($v1)
/* 833F28 80242728 8E62000C */  lw        $v0, 0xc($s3)
/* 833F2C 8024272C 00511021 */  addu      $v0, $v0, $s1
/* 833F30 80242730 E4400034 */  swc1      $f0, 0x34($v0)
/* 833F34 80242734 8E62000C */  lw        $v0, 0xc($s3)
/* 833F38 80242738 00511021 */  addu      $v0, $v0, $s1
/* 833F3C 8024273C E4420060 */  swc1      $f2, 0x60($v0)
/* 833F40 80242740 8E62000C */  lw        $v0, 0xc($s3)
/* 833F44 80242744 00511021 */  addu      $v0, $v0, $s1
/* 833F48 80242748 E444008C */  swc1      $f4, 0x8c($v0)
/* 833F4C 8024274C 8E62000C */  lw        $v0, 0xc($s3)
/* 833F50 80242750 00511021 */  addu      $v0, $v0, $s1
/* 833F54 80242754 E44600B8 */  swc1      $f6, 0xb8($v0)
/* 833F58 80242758 8E63000C */  lw        $v1, 0xc($s3)
/* 833F5C 8024275C 26520001 */  addiu     $s2, $s2, 1
/* 833F60 80242760 00711821 */  addu      $v1, $v1, $s1
/* 833F64 80242764 8C620008 */  lw        $v0, 8($v1)
/* 833F68 80242768 34420001 */  ori       $v0, $v0, 1
/* 833F6C 8024276C AC620008 */  sw        $v0, 8($v1)
/* 833F70 80242770 2A42000A */  slti      $v0, $s2, 0xa
/* 833F74 80242774 1440FFDB */  bnez      $v0, .L802426E4
/* 833F78 80242778 26310004 */   addiu    $s1, $s1, 4
/* 833F7C 8024277C 0280202D */  daddu     $a0, $s4, $zero
/* 833F80 80242780 3C05F5DE */  lui       $a1, 0xf5de
/* 833F84 80242784 34A5019D */  ori       $a1, $a1, 0x19d
/* 833F88 80242788 8E62000C */  lw        $v0, 0xc($s3)
/* 833F8C 8024278C 24060009 */  addiu     $a2, $zero, 9
/* 833F90 80242790 8C43002C */  lw        $v1, 0x2c($v0)
/* 833F94 80242794 2407FFFE */  addiu     $a3, $zero, -2
/* 833F98 80242798 00671824 */  and       $v1, $v1, $a3
/* 833F9C 8024279C 0C0B2026 */  jal       set_variable
/* 833FA0 802427A0 AC43002C */   sw       $v1, 0x2c($v0)
/* 833FA4 802427A4 8FBF002C */  lw        $ra, 0x2c($sp)
/* 833FA8 802427A8 8FB60028 */  lw        $s6, 0x28($sp)
/* 833FAC 802427AC 8FB50024 */  lw        $s5, 0x24($sp)
/* 833FB0 802427B0 8FB40020 */  lw        $s4, 0x20($sp)
/* 833FB4 802427B4 8FB3001C */  lw        $s3, 0x1c($sp)
/* 833FB8 802427B8 8FB20018 */  lw        $s2, 0x18($sp)
/* 833FBC 802427BC 8FB10014 */  lw        $s1, 0x14($sp)
/* 833FC0 802427C0 8FB00010 */  lw        $s0, 0x10($sp)
/* 833FC4 802427C4 24020002 */  addiu     $v0, $zero, 2
/* 833FC8 802427C8 03E00008 */  jr        $ra
/* 833FCC 802427CC 27BD0030 */   addiu    $sp, $sp, 0x30
