.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218404_608EB4
/* 608EB4 80218404 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 608EB8 80218408 AFB10014 */  sw        $s1, 0x14($sp)
/* 608EBC 8021840C 0080882D */  daddu     $s1, $a0, $zero
/* 608EC0 80218410 AFBF001C */  sw        $ra, 0x1c($sp)
/* 608EC4 80218414 AFB20018 */  sw        $s2, 0x18($sp)
/* 608EC8 80218418 AFB00010 */  sw        $s0, 0x10($sp)
/* 608ECC 8021841C F7B80030 */  sdc1      $f24, 0x30($sp)
/* 608ED0 80218420 F7B60028 */  sdc1      $f22, 0x28($sp)
/* 608ED4 80218424 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 608ED8 80218428 8E30000C */  lw        $s0, 0xc($s1)
/* 608EDC 8021842C 8E050000 */  lw        $a1, ($s0)
/* 608EE0 80218430 0C0B1EAF */  jal       get_variable
/* 608EE4 80218434 26100004 */   addiu    $s0, $s0, 4
/* 608EE8 80218438 8E050000 */  lw        $a1, ($s0)
/* 608EEC 8021843C 26100004 */  addiu     $s0, $s0, 4
/* 608EF0 80218440 0220202D */  daddu     $a0, $s1, $zero
/* 608EF4 80218444 0C0B1EAF */  jal       get_variable
/* 608EF8 80218448 0040902D */   daddu    $s2, $v0, $zero
/* 608EFC 8021844C 8E050000 */  lw        $a1, ($s0)
/* 608F00 80218450 26100004 */  addiu     $s0, $s0, 4
/* 608F04 80218454 4482C000 */  mtc1      $v0, $f24
/* 608F08 80218458 00000000 */  nop       
/* 608F0C 8021845C 4680C620 */  cvt.s.w   $f24, $f24
/* 608F10 80218460 0C0B1EAF */  jal       get_variable
/* 608F14 80218464 0220202D */   daddu    $a0, $s1, $zero
/* 608F18 80218468 8E050000 */  lw        $a1, ($s0)
/* 608F1C 8021846C 26100004 */  addiu     $s0, $s0, 4
/* 608F20 80218470 4482B000 */  mtc1      $v0, $f22
/* 608F24 80218474 00000000 */  nop       
/* 608F28 80218478 4680B5A0 */  cvt.s.w   $f22, $f22
/* 608F2C 8021847C 0C0B1EAF */  jal       get_variable
/* 608F30 80218480 0220202D */   daddu    $a0, $s1, $zero
/* 608F34 80218484 8E050000 */  lw        $a1, ($s0)
/* 608F38 80218488 4482A000 */  mtc1      $v0, $f20
/* 608F3C 8021848C 00000000 */  nop       
/* 608F40 80218490 4680A520 */  cvt.s.w   $f20, $f20
/* 608F44 80218494 0C0B210B */  jal       get_float_variable
/* 608F48 80218498 0220202D */   daddu    $a0, $s1, $zero
/* 608F4C 8021849C 8E42000C */  lw        $v0, 0xc($s2)
/* 608F50 802184A0 E4580004 */  swc1      $f24, 4($v0)
/* 608F54 802184A4 8E42000C */  lw        $v0, 0xc($s2)
/* 608F58 802184A8 E4560008 */  swc1      $f22, 8($v0)
/* 608F5C 802184AC 8E42000C */  lw        $v0, 0xc($s2)
/* 608F60 802184B0 E454000C */  swc1      $f20, 0xc($v0)
/* 608F64 802184B4 8E43000C */  lw        $v1, 0xc($s2)
/* 608F68 802184B8 E4600038 */  swc1      $f0, 0x38($v1)
/* 608F6C 802184BC 8FBF001C */  lw        $ra, 0x1c($sp)
/* 608F70 802184C0 8FB20018 */  lw        $s2, 0x18($sp)
/* 608F74 802184C4 8FB10014 */  lw        $s1, 0x14($sp)
/* 608F78 802184C8 8FB00010 */  lw        $s0, 0x10($sp)
/* 608F7C 802184CC D7B80030 */  ldc1      $f24, 0x30($sp)
/* 608F80 802184D0 D7B60028 */  ldc1      $f22, 0x28($sp)
/* 608F84 802184D4 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 608F88 802184D8 24020002 */  addiu     $v0, $zero, 2
/* 608F8C 802184DC 03E00008 */  jr        $ra
/* 608F90 802184E0 27BD0038 */   addiu    $sp, $sp, 0x38
