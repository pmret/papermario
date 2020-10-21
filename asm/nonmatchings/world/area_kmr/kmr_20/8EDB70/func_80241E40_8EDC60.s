.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241E40_8EDC60
/* 8EDC60 80241E40 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8EDC64 80241E44 AFB10014 */  sw        $s1, 0x14($sp)
/* 8EDC68 80241E48 0080882D */  daddu     $s1, $a0, $zero
/* 8EDC6C 80241E4C AFBF001C */  sw        $ra, 0x1c($sp)
/* 8EDC70 80241E50 AFB20018 */  sw        $s2, 0x18($sp)
/* 8EDC74 80241E54 0C016AFA */  jal       get_current_map_header
/* 8EDC78 80241E58 AFB00010 */   sw       $s0, 0x10($sp)
/* 8EDC7C 80241E5C 0220202D */  daddu     $a0, $s1, $zero
/* 8EDC80 80241E60 3C05FE36 */  lui       $a1, 0xfe36
/* 8EDC84 80241E64 34A53C80 */  ori       $a1, $a1, 0x3c80
/* 8EDC88 80241E68 0C0B1EAF */  jal       get_variable
/* 8EDC8C 80241E6C 0040902D */   daddu    $s2, $v0, $zero
/* 8EDC90 80241E70 0220202D */  daddu     $a0, $s1, $zero
/* 8EDC94 80241E74 3C05FE36 */  lui       $a1, 0xfe36
/* 8EDC98 80241E78 8E430014 */  lw        $v1, 0x14($s2)
/* 8EDC9C 80241E7C 00028100 */  sll       $s0, $v0, 4
/* 8EDCA0 80241E80 02031821 */  addu      $v1, $s0, $v1
/* 8EDCA4 80241E84 C4600000 */  lwc1      $f0, ($v1)
/* 8EDCA8 80241E88 4600008D */  trunc.w.s $f2, $f0
/* 8EDCAC 80241E8C 44061000 */  mfc1      $a2, $f2
/* 8EDCB0 80241E90 0C0B2026 */  jal       set_variable
/* 8EDCB4 80241E94 34A53C81 */   ori      $a1, $a1, 0x3c81
/* 8EDCB8 80241E98 0220202D */  daddu     $a0, $s1, $zero
/* 8EDCBC 80241E9C 8E420014 */  lw        $v0, 0x14($s2)
/* 8EDCC0 80241EA0 3C05FE36 */  lui       $a1, 0xfe36
/* 8EDCC4 80241EA4 02021021 */  addu      $v0, $s0, $v0
/* 8EDCC8 80241EA8 C4400004 */  lwc1      $f0, 4($v0)
/* 8EDCCC 80241EAC 4600008D */  trunc.w.s $f2, $f0
/* 8EDCD0 80241EB0 44061000 */  mfc1      $a2, $f2
/* 8EDCD4 80241EB4 0C0B2026 */  jal       set_variable
/* 8EDCD8 80241EB8 34A53C82 */   ori      $a1, $a1, 0x3c82
/* 8EDCDC 80241EBC 0220202D */  daddu     $a0, $s1, $zero
/* 8EDCE0 80241EC0 8E420014 */  lw        $v0, 0x14($s2)
/* 8EDCE4 80241EC4 3C05FE36 */  lui       $a1, 0xfe36
/* 8EDCE8 80241EC8 02021021 */  addu      $v0, $s0, $v0
/* 8EDCEC 80241ECC C4400008 */  lwc1      $f0, 8($v0)
/* 8EDCF0 80241ED0 4600008D */  trunc.w.s $f2, $f0
/* 8EDCF4 80241ED4 44061000 */  mfc1      $a2, $f2
/* 8EDCF8 80241ED8 0C0B2026 */  jal       set_variable
/* 8EDCFC 80241EDC 34A53C83 */   ori      $a1, $a1, 0x3c83
/* 8EDD00 80241EE0 0220202D */  daddu     $a0, $s1, $zero
/* 8EDD04 80241EE4 8E420014 */  lw        $v0, 0x14($s2)
/* 8EDD08 80241EE8 3C05FE36 */  lui       $a1, 0xfe36
/* 8EDD0C 80241EEC 02028021 */  addu      $s0, $s0, $v0
/* 8EDD10 80241EF0 C600000C */  lwc1      $f0, 0xc($s0)
/* 8EDD14 80241EF4 4600008D */  trunc.w.s $f2, $f0
/* 8EDD18 80241EF8 44061000 */  mfc1      $a2, $f2
/* 8EDD1C 80241EFC 0C0B2026 */  jal       set_variable
/* 8EDD20 80241F00 34A53C84 */   ori      $a1, $a1, 0x3c84
/* 8EDD24 80241F04 8FBF001C */  lw        $ra, 0x1c($sp)
/* 8EDD28 80241F08 8FB20018 */  lw        $s2, 0x18($sp)
/* 8EDD2C 80241F0C 8FB10014 */  lw        $s1, 0x14($sp)
/* 8EDD30 80241F10 8FB00010 */  lw        $s0, 0x10($sp)
/* 8EDD34 80241F14 24020002 */  addiu     $v0, $zero, 2
/* 8EDD38 80241F18 03E00008 */  jr        $ra
/* 8EDD3C 80241F1C 27BD0020 */   addiu    $sp, $sp, 0x20
