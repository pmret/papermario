.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024137C_CD865C
/* CD865C 8024137C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* CD8660 80241380 AFB40040 */  sw        $s4, 0x40($sp)
/* CD8664 80241384 0080A02D */  daddu     $s4, $a0, $zero
/* CD8668 80241388 AFBF0048 */  sw        $ra, 0x48($sp)
/* CD866C 8024138C AFB50044 */  sw        $s5, 0x44($sp)
/* CD8670 80241390 AFB3003C */  sw        $s3, 0x3c($sp)
/* CD8674 80241394 AFB20038 */  sw        $s2, 0x38($sp)
/* CD8678 80241398 AFB10034 */  sw        $s1, 0x34($sp)
/* CD867C 8024139C AFB00030 */  sw        $s0, 0x30($sp)
/* CD8680 802413A0 8E920148 */  lw        $s2, 0x148($s4)
/* CD8684 802413A4 86440008 */  lh        $a0, 8($s2)
/* CD8688 802413A8 8E90000C */  lw        $s0, 0xc($s4)
/* CD868C 802413AC 0C00EABB */  jal       get_npc_unsafe
/* CD8690 802413B0 00A0882D */   daddu    $s1, $a1, $zero
/* CD8694 802413B4 0280202D */  daddu     $a0, $s4, $zero
/* CD8698 802413B8 8E050000 */  lw        $a1, ($s0)
/* CD869C 802413BC 0C0B1EAF */  jal       get_variable
/* CD86A0 802413C0 0040A82D */   daddu    $s5, $v0, $zero
/* CD86A4 802413C4 AFA00010 */  sw        $zero, 0x10($sp)
/* CD86A8 802413C8 8E4300D0 */  lw        $v1, 0xd0($s2)
/* CD86AC 802413CC 8C630030 */  lw        $v1, 0x30($v1)
/* CD86B0 802413D0 AFA30014 */  sw        $v1, 0x14($sp)
/* CD86B4 802413D4 8E4300D0 */  lw        $v1, 0xd0($s2)
/* CD86B8 802413D8 8C63001C */  lw        $v1, 0x1c($v1)
/* CD86BC 802413DC AFA30018 */  sw        $v1, 0x18($sp)
/* CD86C0 802413E0 8E4300D0 */  lw        $v1, 0xd0($s2)
/* CD86C4 802413E4 8C630024 */  lw        $v1, 0x24($v1)
/* CD86C8 802413E8 AFA3001C */  sw        $v1, 0x1c($sp)
/* CD86CC 802413EC 8E4300D0 */  lw        $v1, 0xd0($s2)
/* CD86D0 802413F0 8C630028 */  lw        $v1, 0x28($v1)
/* CD86D4 802413F4 27B30010 */  addiu     $s3, $sp, 0x10
/* CD86D8 802413F8 AFA30020 */  sw        $v1, 0x20($sp)
/* CD86DC 802413FC 8E4300D0 */  lw        $v1, 0xd0($s2)
/* CD86E0 80241400 3C0142F0 */  lui       $at, 0x42f0
/* CD86E4 80241404 44810000 */  mtc1      $at, $f0
/* CD86E8 80241408 8C63002C */  lw        $v1, 0x2c($v1)
/* CD86EC 8024140C 0040802D */  daddu     $s0, $v0, $zero
/* CD86F0 80241410 E7A00028 */  swc1      $f0, 0x28($sp)
/* CD86F4 80241414 A7A0002C */  sh        $zero, 0x2c($sp)
/* CD86F8 80241418 12200006 */  beqz      $s1, .L80241434
/* CD86FC 8024141C AFA30024 */   sw       $v1, 0x24($sp)
/* CD8700 80241420 02A0202D */  daddu     $a0, $s5, $zero
/* CD8704 80241424 0240282D */  daddu     $a1, $s2, $zero
/* CD8708 80241428 0280302D */  daddu     $a2, $s4, $zero
/* CD870C 8024142C 0C090496 */  jal       func_80241258_CD8538
/* CD8710 80241430 0200382D */   daddu    $a3, $s0, $zero
.L80241434:
/* CD8714 80241434 2402FFFE */  addiu     $v0, $zero, -2
/* CD8718 80241438 A2A200AB */  sb        $v0, 0xab($s5)
/* CD871C 8024143C 8E4300B0 */  lw        $v1, 0xb0($s2)
/* CD8720 80241440 30620004 */  andi      $v0, $v1, 4
/* CD8724 80241444 10400007 */  beqz      $v0, .L80241464
/* CD8728 80241448 00000000 */   nop      
/* CD872C 8024144C 824200B4 */  lb        $v0, 0xb4($s2)
/* CD8730 80241450 1440003C */  bnez      $v0, .L80241544
/* CD8734 80241454 0000102D */   daddu    $v0, $zero, $zero
/* CD8738 80241458 2402FFFB */  addiu     $v0, $zero, -5
/* CD873C 8024145C 00621024 */  and       $v0, $v1, $v0
/* CD8740 80241460 AE4200B0 */  sw        $v0, 0xb0($s2)
.L80241464:
/* CD8744 80241464 8E830070 */  lw        $v1, 0x70($s4)
/* CD8748 80241468 2C62000F */  sltiu     $v0, $v1, 0xf
/* CD874C 8024146C 10400034 */  beqz      $v0, .L80241540
/* CD8750 80241470 00031080 */   sll      $v0, $v1, 2
/* CD8754 80241474 3C018024 */  lui       $at, 0x8024
/* CD8758 80241478 00220821 */  addu      $at, $at, $v0
/* CD875C 8024147C 8C225318 */  lw        $v0, 0x5318($at)
/* CD8760 80241480 00400008 */  jr        $v0
/* CD8764 80241484 00000000 */   nop      
/* CD8768 80241488 0280202D */  daddu     $a0, $s4, $zero
/* CD876C 8024148C 0200282D */  daddu     $a1, $s0, $zero
/* CD8770 80241490 0C09001C */  jal       func_80240070_CD7350
/* CD8774 80241494 0260302D */   daddu    $a2, $s3, $zero
/* CD8778 80241498 0280202D */  daddu     $a0, $s4, $zero
/* CD877C 8024149C 0200282D */  daddu     $a1, $s0, $zero
/* CD8780 802414A0 0C090088 */  jal       func_80240220_CD7500
/* CD8784 802414A4 0260302D */   daddu    $a2, $s3, $zero
/* CD8788 802414A8 08090551 */  j         .L80241544
/* CD878C 802414AC 0000102D */   daddu    $v0, $zero, $zero
/* CD8790 802414B0 0280202D */  daddu     $a0, $s4, $zero
/* CD8794 802414B4 0200282D */  daddu     $a1, $s0, $zero
/* CD8798 802414B8 0C090212 */  jal       func_80240848_CD7B28
/* CD879C 802414BC 0260302D */   daddu    $a2, $s3, $zero
/* CD87A0 802414C0 0280202D */  daddu     $a0, $s4, $zero
/* CD87A4 802414C4 0200282D */  daddu     $a1, $s0, $zero
/* CD87A8 802414C8 0C090242 */  jal       func_80240908_CD7BE8
/* CD87AC 802414CC 0260302D */   daddu    $a2, $s3, $zero
/* CD87B0 802414D0 08090551 */  j         .L80241544
/* CD87B4 802414D4 0000102D */   daddu    $v0, $zero, $zero
/* CD87B8 802414D8 0280202D */  daddu     $a0, $s4, $zero
/* CD87BC 802414DC 0200282D */  daddu     $a1, $s0, $zero
/* CD87C0 802414E0 0C090313 */  jal       func_80240C4C_CD7F2C
/* CD87C4 802414E4 0260302D */   daddu    $a2, $s3, $zero
/* CD87C8 802414E8 0280202D */  daddu     $a0, $s4, $zero
/* CD87CC 802414EC 0200282D */  daddu     $a1, $s0, $zero
/* CD87D0 802414F0 0C090331 */  jal       func_80240CC4_CD7FA4
/* CD87D4 802414F4 0260302D */   daddu    $a2, $s3, $zero
/* CD87D8 802414F8 08090551 */  j         .L80241544
/* CD87DC 802414FC 0000102D */   daddu    $v0, $zero, $zero
/* CD87E0 80241500 0280202D */  daddu     $a0, $s4, $zero
/* CD87E4 80241504 0200282D */  daddu     $a1, $s0, $zero
/* CD87E8 80241508 0C09034C */  jal       func_80240D30_CD8010
/* CD87EC 8024150C 0260302D */   daddu    $a2, $s3, $zero
/* CD87F0 80241510 08090551 */  j         .L80241544
/* CD87F4 80241514 0000102D */   daddu    $v0, $zero, $zero
/* CD87F8 80241518 0280202D */  daddu     $a0, $s4, $zero
/* CD87FC 8024151C 0200282D */  daddu     $a1, $s0, $zero
/* CD8800 80241520 0C090399 */  jal       func_80240E64_CD8144
/* CD8804 80241524 0260302D */   daddu    $a2, $s3, $zero
/* CD8808 80241528 08090551 */  j         .L80241544
/* CD880C 8024152C 0000102D */   daddu    $v0, $zero, $zero
/* CD8810 80241530 0280202D */  daddu     $a0, $s4, $zero
/* CD8814 80241534 0200282D */  daddu     $a1, $s0, $zero
/* CD8818 80241538 0C0903B2 */  jal       func_80240EC8_CD81A8
/* CD881C 8024153C 0260302D */   daddu    $a2, $s3, $zero
.L80241540:
/* CD8820 80241540 0000102D */  daddu     $v0, $zero, $zero
.L80241544:
/* CD8824 80241544 8FBF0048 */  lw        $ra, 0x48($sp)
/* CD8828 80241548 8FB50044 */  lw        $s5, 0x44($sp)
/* CD882C 8024154C 8FB40040 */  lw        $s4, 0x40($sp)
/* CD8830 80241550 8FB3003C */  lw        $s3, 0x3c($sp)
/* CD8834 80241554 8FB20038 */  lw        $s2, 0x38($sp)
/* CD8838 80241558 8FB10034 */  lw        $s1, 0x34($sp)
/* CD883C 8024155C 8FB00030 */  lw        $s0, 0x30($sp)
/* CD8840 80241560 03E00008 */  jr        $ra
/* CD8844 80241564 27BD0050 */   addiu    $sp, $sp, 0x50
