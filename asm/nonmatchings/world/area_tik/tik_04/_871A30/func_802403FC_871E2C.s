.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403FC_871E2C
/* 871E2C 802403FC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 871E30 80240400 AFB10014 */  sw        $s1, 0x14($sp)
/* 871E34 80240404 0080882D */  daddu     $s1, $a0, $zero
/* 871E38 80240408 AFBF001C */  sw        $ra, 0x1c($sp)
/* 871E3C 8024040C AFB20018 */  sw        $s2, 0x18($sp)
/* 871E40 80240410 0C016AFA */  jal       get_current_map_header
/* 871E44 80240414 AFB00010 */   sw       $s0, 0x10($sp)
/* 871E48 80240418 0220202D */  daddu     $a0, $s1, $zero
/* 871E4C 8024041C 3C05FE36 */  lui       $a1, 0xfe36
/* 871E50 80240420 34A53C80 */  ori       $a1, $a1, 0x3c80
/* 871E54 80240424 0C0B1EAF */  jal       get_variable
/* 871E58 80240428 0040902D */   daddu    $s2, $v0, $zero
/* 871E5C 8024042C 0220202D */  daddu     $a0, $s1, $zero
/* 871E60 80240430 3C05FE36 */  lui       $a1, 0xfe36
/* 871E64 80240434 8E430014 */  lw        $v1, 0x14($s2)
/* 871E68 80240438 00028100 */  sll       $s0, $v0, 4
/* 871E6C 8024043C 02031821 */  addu      $v1, $s0, $v1
/* 871E70 80240440 C4600000 */  lwc1      $f0, ($v1)
/* 871E74 80240444 4600008D */  trunc.w.s $f2, $f0
/* 871E78 80240448 44061000 */  mfc1      $a2, $f2
/* 871E7C 8024044C 0C0B2026 */  jal       set_variable
/* 871E80 80240450 34A53C81 */   ori      $a1, $a1, 0x3c81
/* 871E84 80240454 0220202D */  daddu     $a0, $s1, $zero
/* 871E88 80240458 8E420014 */  lw        $v0, 0x14($s2)
/* 871E8C 8024045C 3C05FE36 */  lui       $a1, 0xfe36
/* 871E90 80240460 02021021 */  addu      $v0, $s0, $v0
/* 871E94 80240464 C4400004 */  lwc1      $f0, 4($v0)
/* 871E98 80240468 4600008D */  trunc.w.s $f2, $f0
/* 871E9C 8024046C 44061000 */  mfc1      $a2, $f2
/* 871EA0 80240470 0C0B2026 */  jal       set_variable
/* 871EA4 80240474 34A53C82 */   ori      $a1, $a1, 0x3c82
/* 871EA8 80240478 0220202D */  daddu     $a0, $s1, $zero
/* 871EAC 8024047C 8E420014 */  lw        $v0, 0x14($s2)
/* 871EB0 80240480 3C05FE36 */  lui       $a1, 0xfe36
/* 871EB4 80240484 02021021 */  addu      $v0, $s0, $v0
/* 871EB8 80240488 C4400008 */  lwc1      $f0, 8($v0)
/* 871EBC 8024048C 4600008D */  trunc.w.s $f2, $f0
/* 871EC0 80240490 44061000 */  mfc1      $a2, $f2
/* 871EC4 80240494 0C0B2026 */  jal       set_variable
/* 871EC8 80240498 34A53C83 */   ori      $a1, $a1, 0x3c83
/* 871ECC 8024049C 0220202D */  daddu     $a0, $s1, $zero
/* 871ED0 802404A0 8E420014 */  lw        $v0, 0x14($s2)
/* 871ED4 802404A4 3C05FE36 */  lui       $a1, 0xfe36
/* 871ED8 802404A8 02028021 */  addu      $s0, $s0, $v0
/* 871EDC 802404AC C600000C */  lwc1      $f0, 0xc($s0)
/* 871EE0 802404B0 4600008D */  trunc.w.s $f2, $f0
/* 871EE4 802404B4 44061000 */  mfc1      $a2, $f2
/* 871EE8 802404B8 0C0B2026 */  jal       set_variable
/* 871EEC 802404BC 34A53C84 */   ori      $a1, $a1, 0x3c84
/* 871EF0 802404C0 8FBF001C */  lw        $ra, 0x1c($sp)
/* 871EF4 802404C4 8FB20018 */  lw        $s2, 0x18($sp)
/* 871EF8 802404C8 8FB10014 */  lw        $s1, 0x14($sp)
/* 871EFC 802404CC 8FB00010 */  lw        $s0, 0x10($sp)
/* 871F00 802404D0 24020002 */  addiu     $v0, $zero, 2
/* 871F04 802404D4 03E00008 */  jr        $ra
/* 871F08 802404D8 27BD0020 */   addiu    $sp, $sp, 0x20
