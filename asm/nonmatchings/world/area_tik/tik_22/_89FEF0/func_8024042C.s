.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024042C
/* 8A02EC 8024042C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8A02F0 80240430 AFB10014 */  sw        $s1, 0x14($sp)
/* 8A02F4 80240434 0080882D */  daddu     $s1, $a0, $zero
/* 8A02F8 80240438 AFBF001C */  sw        $ra, 0x1c($sp)
/* 8A02FC 8024043C AFB20018 */  sw        $s2, 0x18($sp)
/* 8A0300 80240440 0C016AFA */  jal       get_current_map_header
/* 8A0304 80240444 AFB00010 */   sw       $s0, 0x10($sp)
/* 8A0308 80240448 0220202D */  daddu     $a0, $s1, $zero
/* 8A030C 8024044C 3C05FE36 */  lui       $a1, 0xfe36
/* 8A0310 80240450 34A53C80 */  ori       $a1, $a1, 0x3c80
/* 8A0314 80240454 0C0B1EAF */  jal       get_variable
/* 8A0318 80240458 0040902D */   daddu    $s2, $v0, $zero
/* 8A031C 8024045C 0220202D */  daddu     $a0, $s1, $zero
/* 8A0320 80240460 3C05FE36 */  lui       $a1, 0xfe36
/* 8A0324 80240464 8E430014 */  lw        $v1, 0x14($s2)
/* 8A0328 80240468 00028100 */  sll       $s0, $v0, 4
/* 8A032C 8024046C 02031821 */  addu      $v1, $s0, $v1
/* 8A0330 80240470 C4600000 */  lwc1      $f0, ($v1)
/* 8A0334 80240474 4600008D */  trunc.w.s $f2, $f0
/* 8A0338 80240478 44061000 */  mfc1      $a2, $f2
/* 8A033C 8024047C 0C0B2026 */  jal       set_variable
/* 8A0340 80240480 34A53C81 */   ori      $a1, $a1, 0x3c81
/* 8A0344 80240484 0220202D */  daddu     $a0, $s1, $zero
/* 8A0348 80240488 8E420014 */  lw        $v0, 0x14($s2)
/* 8A034C 8024048C 3C05FE36 */  lui       $a1, 0xfe36
/* 8A0350 80240490 02021021 */  addu      $v0, $s0, $v0
/* 8A0354 80240494 C4400004 */  lwc1      $f0, 4($v0)
/* 8A0358 80240498 4600008D */  trunc.w.s $f2, $f0
/* 8A035C 8024049C 44061000 */  mfc1      $a2, $f2
/* 8A0360 802404A0 0C0B2026 */  jal       set_variable
/* 8A0364 802404A4 34A53C82 */   ori      $a1, $a1, 0x3c82
/* 8A0368 802404A8 0220202D */  daddu     $a0, $s1, $zero
/* 8A036C 802404AC 8E420014 */  lw        $v0, 0x14($s2)
/* 8A0370 802404B0 3C05FE36 */  lui       $a1, 0xfe36
/* 8A0374 802404B4 02021021 */  addu      $v0, $s0, $v0
/* 8A0378 802404B8 C4400008 */  lwc1      $f0, 8($v0)
/* 8A037C 802404BC 4600008D */  trunc.w.s $f2, $f0
/* 8A0380 802404C0 44061000 */  mfc1      $a2, $f2
/* 8A0384 802404C4 0C0B2026 */  jal       set_variable
/* 8A0388 802404C8 34A53C83 */   ori      $a1, $a1, 0x3c83
/* 8A038C 802404CC 0220202D */  daddu     $a0, $s1, $zero
/* 8A0390 802404D0 8E420014 */  lw        $v0, 0x14($s2)
/* 8A0394 802404D4 3C05FE36 */  lui       $a1, 0xfe36
/* 8A0398 802404D8 02028021 */  addu      $s0, $s0, $v0
/* 8A039C 802404DC C600000C */  lwc1      $f0, 0xc($s0)
/* 8A03A0 802404E0 4600008D */  trunc.w.s $f2, $f0
/* 8A03A4 802404E4 44061000 */  mfc1      $a2, $f2
/* 8A03A8 802404E8 0C0B2026 */  jal       set_variable
/* 8A03AC 802404EC 34A53C84 */   ori      $a1, $a1, 0x3c84
/* 8A03B0 802404F0 8FBF001C */  lw        $ra, 0x1c($sp)
/* 8A03B4 802404F4 8FB20018 */  lw        $s2, 0x18($sp)
/* 8A03B8 802404F8 8FB10014 */  lw        $s1, 0x14($sp)
/* 8A03BC 802404FC 8FB00010 */  lw        $s0, 0x10($sp)
/* 8A03C0 80240500 24020002 */  addiu     $v0, $zero, 2
/* 8A03C4 80240504 03E00008 */  jr        $ra
/* 8A03C8 80240508 27BD0020 */   addiu    $sp, $sp, 0x20
