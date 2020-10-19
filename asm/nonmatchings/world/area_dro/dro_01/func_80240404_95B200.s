.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240404_95B604
/* 95B604 80240404 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 95B608 80240408 AFB10034 */  sw        $s1, 0x34($sp)
/* 95B60C 8024040C 0080882D */  daddu     $s1, $a0, $zero
/* 95B610 80240410 AFBF0054 */  sw        $ra, 0x54($sp)
/* 95B614 80240414 AFBE0050 */  sw        $fp, 0x50($sp)
/* 95B618 80240418 AFB7004C */  sw        $s7, 0x4c($sp)
/* 95B61C 8024041C AFB60048 */  sw        $s6, 0x48($sp)
/* 95B620 80240420 AFB50044 */  sw        $s5, 0x44($sp)
/* 95B624 80240424 AFB40040 */  sw        $s4, 0x40($sp)
/* 95B628 80240428 AFB3003C */  sw        $s3, 0x3c($sp)
/* 95B62C 8024042C AFB20038 */  sw        $s2, 0x38($sp)
/* 95B630 80240430 AFB00030 */  sw        $s0, 0x30($sp)
/* 95B634 80240434 8E30000C */  lw        $s0, 0xc($s1)
/* 95B638 80240438 8E050000 */  lw        $a1, ($s0)
/* 95B63C 8024043C 0C0B1EAF */  jal       get_variable
/* 95B640 80240440 26100004 */   addiu    $s0, $s0, 4
/* 95B644 80240444 8E050000 */  lw        $a1, ($s0)
/* 95B648 80240448 26100004 */  addiu     $s0, $s0, 4
/* 95B64C 8024044C 0220202D */  daddu     $a0, $s1, $zero
/* 95B650 80240450 0C0B1EAF */  jal       get_variable
/* 95B654 80240454 0040982D */   daddu    $s3, $v0, $zero
/* 95B658 80240458 8E050000 */  lw        $a1, ($s0)
/* 95B65C 8024045C 26100004 */  addiu     $s0, $s0, 4
/* 95B660 80240460 0220202D */  daddu     $a0, $s1, $zero
/* 95B664 80240464 0C0B1EAF */  jal       get_variable
/* 95B668 80240468 0040B02D */   daddu    $s6, $v0, $zero
/* 95B66C 8024046C 8E050000 */  lw        $a1, ($s0)
/* 95B670 80240470 26100004 */  addiu     $s0, $s0, 4
/* 95B674 80240474 0220202D */  daddu     $a0, $s1, $zero
/* 95B678 80240478 0C0B1EAF */  jal       get_variable
/* 95B67C 8024047C 0040A82D */   daddu    $s5, $v0, $zero
/* 95B680 80240480 8E050000 */  lw        $a1, ($s0)
/* 95B684 80240484 26100004 */  addiu     $s0, $s0, 4
/* 95B688 80240488 0220202D */  daddu     $a0, $s1, $zero
/* 95B68C 8024048C 0C0B1EAF */  jal       get_variable
/* 95B690 80240490 0040A02D */   daddu    $s4, $v0, $zero
/* 95B694 80240494 8E050000 */  lw        $a1, ($s0)
/* 95B698 80240498 26100004 */  addiu     $s0, $s0, 4
/* 95B69C 8024049C 0220202D */  daddu     $a0, $s1, $zero
/* 95B6A0 802404A0 0C0B1EAF */  jal       get_variable
/* 95B6A4 802404A4 0040902D */   daddu    $s2, $v0, $zero
/* 95B6A8 802404A8 8E050000 */  lw        $a1, ($s0)
/* 95B6AC 802404AC 26100004 */  addiu     $s0, $s0, 4
/* 95B6B0 802404B0 0220202D */  daddu     $a0, $s1, $zero
/* 95B6B4 802404B4 0C0B1EAF */  jal       get_variable
/* 95B6B8 802404B8 AFA20028 */   sw       $v0, 0x28($sp)
/* 95B6BC 802404BC 8E050000 */  lw        $a1, ($s0)
/* 95B6C0 802404C0 26100004 */  addiu     $s0, $s0, 4
/* 95B6C4 802404C4 0220202D */  daddu     $a0, $s1, $zero
/* 95B6C8 802404C8 0C0B1EAF */  jal       get_variable
/* 95B6CC 802404CC 0040F02D */   daddu    $fp, $v0, $zero
/* 95B6D0 802404D0 8E050000 */  lw        $a1, ($s0)
/* 95B6D4 802404D4 26100004 */  addiu     $s0, $s0, 4
/* 95B6D8 802404D8 0220202D */  daddu     $a0, $s1, $zero
/* 95B6DC 802404DC 0C0B1EAF */  jal       get_variable
/* 95B6E0 802404E0 0040B82D */   daddu    $s7, $v0, $zero
/* 95B6E4 802404E4 0220202D */  daddu     $a0, $s1, $zero
/* 95B6E8 802404E8 8E050000 */  lw        $a1, ($s0)
/* 95B6EC 802404EC 0C0B1EAF */  jal       get_variable
/* 95B6F0 802404F0 0040802D */   daddu    $s0, $v0, $zero
/* 95B6F4 802404F4 0040182D */  daddu     $v1, $v0, $zero
/* 95B6F8 802404F8 24020002 */  addiu     $v0, $zero, 2
/* 95B6FC 802404FC 12620012 */  beq       $s3, $v0, .L80240548
/* 95B700 80240500 2A620003 */   slti     $v0, $s3, 3
/* 95B704 80240504 10400005 */  beqz      $v0, .L8024051C
/* 95B708 80240508 24020001 */   addiu    $v0, $zero, 1
/* 95B70C 8024050C 12620008 */  beq       $s3, $v0, .L80240530
/* 95B710 80240510 32C400FF */   andi     $a0, $s6, 0xff
/* 95B714 80240514 08090169 */  j         .L802405A4
/* 95B718 80240518 00000000 */   nop      
.L8024051C:
/* 95B71C 8024051C 24020003 */  addiu     $v0, $zero, 3
/* 95B720 80240520 12620018 */  beq       $s3, $v0, .L80240584
/* 95B724 80240524 32C400FF */   andi     $a0, $s6, 0xff
/* 95B728 80240528 08090169 */  j         .L802405A4
/* 95B72C 8024052C 00000000 */   nop      
.L80240530:
/* 95B730 80240530 32A500FF */  andi      $a1, $s5, 0xff
/* 95B734 80240534 328600FF */  andi      $a2, $s4, 0xff
/* 95B738 80240538 0C046F97 */  jal       set_background_color_blend
/* 95B73C 8024053C 324700FF */   andi     $a3, $s2, 0xff
/* 95B740 80240540 08090169 */  j         .L802405A4
/* 95B744 80240544 00000000 */   nop      
.L80240548:
/* 95B748 80240548 32C400FF */  andi      $a0, $s6, 0xff
/* 95B74C 8024054C 32A500FF */  andi      $a1, $s5, 0xff
/* 95B750 80240550 328600FF */  andi      $a2, $s4, 0xff
/* 95B754 80240554 324700FF */  andi      $a3, $s2, 0xff
/* 95B758 80240558 93A2002B */  lbu       $v0, 0x2b($sp)
/* 95B75C 8024055C AFB0001C */  sw        $s0, 0x1c($sp)
/* 95B760 80240560 AFA30020 */  sw        $v1, 0x20($sp)
/* 95B764 80240564 AFA20010 */  sw        $v0, 0x10($sp)
/* 95B768 80240568 33C200FF */  andi      $v0, $fp, 0xff
/* 95B76C 8024056C AFA20014 */  sw        $v0, 0x14($sp)
/* 95B770 80240570 32E200FF */  andi      $v0, $s7, 0xff
/* 95B774 80240574 0C046FAD */  jal       func_8011BEB4
/* 95B778 80240578 AFA20018 */   sw       $v0, 0x18($sp)
/* 95B77C 8024057C 08090169 */  j         .L802405A4
/* 95B780 80240580 00000000 */   nop      
.L80240584:
/* 95B784 80240584 32A500FF */  andi      $a1, $s5, 0xff
/* 95B788 80240588 328600FF */  andi      $a2, $s4, 0xff
/* 95B78C 8024058C 324700FF */  andi      $a3, $s2, 0xff
/* 95B790 80240590 93A2002B */  lbu       $v0, 0x2b($sp)
/* 95B794 80240594 AFA20010 */  sw        $v0, 0x10($sp)
/* 95B798 80240598 33C200FF */  andi      $v0, $fp, 0xff
/* 95B79C 8024059C 0C046FE6 */  jal       func_8011BF98
/* 95B7A0 802405A0 AFA20014 */   sw       $v0, 0x14($sp)
.L802405A4:
/* 95B7A4 802405A4 8FBF0054 */  lw        $ra, 0x54($sp)
/* 95B7A8 802405A8 8FBE0050 */  lw        $fp, 0x50($sp)
/* 95B7AC 802405AC 8FB7004C */  lw        $s7, 0x4c($sp)
/* 95B7B0 802405B0 8FB60048 */  lw        $s6, 0x48($sp)
/* 95B7B4 802405B4 8FB50044 */  lw        $s5, 0x44($sp)
/* 95B7B8 802405B8 8FB40040 */  lw        $s4, 0x40($sp)
/* 95B7BC 802405BC 8FB3003C */  lw        $s3, 0x3c($sp)
/* 95B7C0 802405C0 8FB20038 */  lw        $s2, 0x38($sp)
/* 95B7C4 802405C4 8FB10034 */  lw        $s1, 0x34($sp)
/* 95B7C8 802405C8 8FB00030 */  lw        $s0, 0x30($sp)
/* 95B7CC 802405CC 24020002 */  addiu     $v0, $zero, 2
/* 95B7D0 802405D0 03E00008 */  jr        $ra
/* 95B7D4 802405D4 27BD0058 */   addiu    $sp, $sp, 0x58
/* 95B7D8 802405D8 00000000 */  nop       
/* 95B7DC 802405DC 00000000 */  nop       
