.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240ECC_E1362C
/* E1362C 80240ECC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* E13630 80240ED0 AFB10014 */  sw        $s1, 0x14($sp)
/* E13634 80240ED4 0080882D */  daddu     $s1, $a0, $zero
/* E13638 80240ED8 0000202D */  daddu     $a0, $zero, $zero
/* E1363C 80240EDC AFBF0018 */  sw        $ra, 0x18($sp)
/* E13640 80240EE0 0C00FB3A */  jal       get_enemy
/* E13644 80240EE4 AFB00010 */   sw       $s0, 0x10($sp)
/* E13648 80240EE8 8E23000C */  lw        $v1, 0xc($s1)
/* E1364C 80240EEC 8C650000 */  lw        $a1, ($v1)
/* E13650 80240EF0 8C500080 */  lw        $s0, 0x80($v0)
/* E13654 80240EF4 0C0B1EAF */  jal       get_variable
/* E13658 80240EF8 0220202D */   daddu    $a0, $s1, $zero
/* E1365C 80240EFC 0220202D */  daddu     $a0, $s1, $zero
/* E13660 80240F00 3C05FE36 */  lui       $a1, 0xfe36
/* E13664 80240F04 00021840 */  sll       $v1, $v0, 1
/* E13668 80240F08 00621821 */  addu      $v1, $v1, $v0
/* E1366C 80240F0C 000318C0 */  sll       $v1, $v1, 3
/* E13670 80240F10 00621823 */  subu      $v1, $v1, $v0
/* E13674 80240F14 00031880 */  sll       $v1, $v1, 2
/* E13678 80240F18 02038021 */  addu      $s0, $s0, $v1
/* E1367C 80240F1C 8E060094 */  lw        $a2, 0x94($s0)
/* E13680 80240F20 0C0B2190 */  jal       set_float_variable
/* E13684 80240F24 34A53C85 */   ori      $a1, $a1, 0x3c85
/* E13688 80240F28 0220202D */  daddu     $a0, $s1, $zero
/* E1368C 80240F2C 3C05FE36 */  lui       $a1, 0xfe36
/* E13690 80240F30 8E060098 */  lw        $a2, 0x98($s0)
/* E13694 80240F34 0C0B2190 */  jal       set_float_variable
/* E13698 80240F38 34A53C86 */   ori      $a1, $a1, 0x3c86
/* E1369C 80240F3C 0220202D */  daddu     $a0, $s1, $zero
/* E136A0 80240F40 3C05FE36 */  lui       $a1, 0xfe36
/* E136A4 80240F44 8E06009C */  lw        $a2, 0x9c($s0)
/* E136A8 80240F48 0C0B2190 */  jal       set_float_variable
/* E136AC 80240F4C 34A53C87 */   ori      $a1, $a1, 0x3c87
/* E136B0 80240F50 0220202D */  daddu     $a0, $s1, $zero
/* E136B4 80240F54 3C05FE36 */  lui       $a1, 0xfe36
/* E136B8 80240F58 8E0600B8 */  lw        $a2, 0xb8($s0)
/* E136BC 80240F5C 0C0B2190 */  jal       set_float_variable
/* E136C0 80240F60 34A53C88 */   ori      $a1, $a1, 0x3c88
/* E136C4 80240F64 0220202D */  daddu     $a0, $s1, $zero
/* E136C8 80240F68 3C05FE36 */  lui       $a1, 0xfe36
/* E136CC 80240F6C 8E0600C4 */  lw        $a2, 0xc4($s0)
/* E136D0 80240F70 0C0B2190 */  jal       set_float_variable
/* E136D4 80240F74 34A53C89 */   ori      $a1, $a1, 0x3c89
/* E136D8 80240F78 8FBF0018 */  lw        $ra, 0x18($sp)
/* E136DC 80240F7C 8FB10014 */  lw        $s1, 0x14($sp)
/* E136E0 80240F80 8FB00010 */  lw        $s0, 0x10($sp)
/* E136E4 80240F84 24020002 */  addiu     $v0, $zero, 2
/* E136E8 80240F88 03E00008 */  jr        $ra
/* E136EC 80240F8C 27BD0020 */   addiu    $sp, $sp, 0x20
