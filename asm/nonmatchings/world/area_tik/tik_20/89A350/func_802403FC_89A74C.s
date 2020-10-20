.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403FC_89A74C
/* 89A74C 802403FC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 89A750 80240400 AFB10014 */  sw        $s1, 0x14($sp)
/* 89A754 80240404 0080882D */  daddu     $s1, $a0, $zero
/* 89A758 80240408 AFBF001C */  sw        $ra, 0x1c($sp)
/* 89A75C 8024040C AFB20018 */  sw        $s2, 0x18($sp)
/* 89A760 80240410 0C016AFA */  jal       get_current_map_header
/* 89A764 80240414 AFB00010 */   sw       $s0, 0x10($sp)
/* 89A768 80240418 0220202D */  daddu     $a0, $s1, $zero
/* 89A76C 8024041C 3C05FE36 */  lui       $a1, 0xfe36
/* 89A770 80240420 34A53C80 */  ori       $a1, $a1, 0x3c80
/* 89A774 80240424 0C0B1EAF */  jal       get_variable
/* 89A778 80240428 0040902D */   daddu    $s2, $v0, $zero
/* 89A77C 8024042C 0220202D */  daddu     $a0, $s1, $zero
/* 89A780 80240430 3C05FE36 */  lui       $a1, 0xfe36
/* 89A784 80240434 8E430014 */  lw        $v1, 0x14($s2)
/* 89A788 80240438 00028100 */  sll       $s0, $v0, 4
/* 89A78C 8024043C 02031821 */  addu      $v1, $s0, $v1
/* 89A790 80240440 C4600000 */  lwc1      $f0, ($v1)
/* 89A794 80240444 4600008D */  trunc.w.s $f2, $f0
/* 89A798 80240448 44061000 */  mfc1      $a2, $f2
/* 89A79C 8024044C 0C0B2026 */  jal       set_variable
/* 89A7A0 80240450 34A53C81 */   ori      $a1, $a1, 0x3c81
/* 89A7A4 80240454 0220202D */  daddu     $a0, $s1, $zero
/* 89A7A8 80240458 8E420014 */  lw        $v0, 0x14($s2)
/* 89A7AC 8024045C 3C05FE36 */  lui       $a1, 0xfe36
/* 89A7B0 80240460 02021021 */  addu      $v0, $s0, $v0
/* 89A7B4 80240464 C4400004 */  lwc1      $f0, 4($v0)
/* 89A7B8 80240468 4600008D */  trunc.w.s $f2, $f0
/* 89A7BC 8024046C 44061000 */  mfc1      $a2, $f2
/* 89A7C0 80240470 0C0B2026 */  jal       set_variable
/* 89A7C4 80240474 34A53C82 */   ori      $a1, $a1, 0x3c82
/* 89A7C8 80240478 0220202D */  daddu     $a0, $s1, $zero
/* 89A7CC 8024047C 8E420014 */  lw        $v0, 0x14($s2)
/* 89A7D0 80240480 3C05FE36 */  lui       $a1, 0xfe36
/* 89A7D4 80240484 02021021 */  addu      $v0, $s0, $v0
/* 89A7D8 80240488 C4400008 */  lwc1      $f0, 8($v0)
/* 89A7DC 8024048C 4600008D */  trunc.w.s $f2, $f0
/* 89A7E0 80240490 44061000 */  mfc1      $a2, $f2
/* 89A7E4 80240494 0C0B2026 */  jal       set_variable
/* 89A7E8 80240498 34A53C83 */   ori      $a1, $a1, 0x3c83
/* 89A7EC 8024049C 0220202D */  daddu     $a0, $s1, $zero
/* 89A7F0 802404A0 8E420014 */  lw        $v0, 0x14($s2)
/* 89A7F4 802404A4 3C05FE36 */  lui       $a1, 0xfe36
/* 89A7F8 802404A8 02028021 */  addu      $s0, $s0, $v0
/* 89A7FC 802404AC C600000C */  lwc1      $f0, 0xc($s0)
/* 89A800 802404B0 4600008D */  trunc.w.s $f2, $f0
/* 89A804 802404B4 44061000 */  mfc1      $a2, $f2
/* 89A808 802404B8 0C0B2026 */  jal       set_variable
/* 89A80C 802404BC 34A53C84 */   ori      $a1, $a1, 0x3c84
/* 89A810 802404C0 8FBF001C */  lw        $ra, 0x1c($sp)
/* 89A814 802404C4 8FB20018 */  lw        $s2, 0x18($sp)
/* 89A818 802404C8 8FB10014 */  lw        $s1, 0x14($sp)
/* 89A81C 802404CC 8FB00010 */  lw        $s0, 0x10($sp)
/* 89A820 802404D0 24020002 */  addiu     $v0, $zero, 2
/* 89A824 802404D4 03E00008 */  jr        $ra
/* 89A828 802404D8 27BD0020 */   addiu    $sp, $sp, 0x20
