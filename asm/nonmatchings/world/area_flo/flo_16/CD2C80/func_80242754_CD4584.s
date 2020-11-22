.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242754_CD4584
/* CD4584 80242754 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* CD4588 80242758 AFB40040 */  sw        $s4, 0x40($sp)
/* CD458C 8024275C 0080A02D */  daddu     $s4, $a0, $zero
/* CD4590 80242760 AFBF0048 */  sw        $ra, 0x48($sp)
/* CD4594 80242764 AFB50044 */  sw        $s5, 0x44($sp)
/* CD4598 80242768 AFB3003C */  sw        $s3, 0x3c($sp)
/* CD459C 8024276C AFB20038 */  sw        $s2, 0x38($sp)
/* CD45A0 80242770 AFB10034 */  sw        $s1, 0x34($sp)
/* CD45A4 80242774 AFB00030 */  sw        $s0, 0x30($sp)
/* CD45A8 80242778 8E920148 */  lw        $s2, 0x148($s4)
/* CD45AC 8024277C 86440008 */  lh        $a0, 8($s2)
/* CD45B0 80242780 8E90000C */  lw        $s0, 0xc($s4)
/* CD45B4 80242784 0C00EABB */  jal       get_npc_unsafe
/* CD45B8 80242788 00A0882D */   daddu    $s1, $a1, $zero
/* CD45BC 8024278C 0280202D */  daddu     $a0, $s4, $zero
/* CD45C0 80242790 8E050000 */  lw        $a1, ($s0)
/* CD45C4 80242794 0C0B1EAF */  jal       get_variable
/* CD45C8 80242798 0040A82D */   daddu    $s5, $v0, $zero
/* CD45CC 8024279C AFA00010 */  sw        $zero, 0x10($sp)
/* CD45D0 802427A0 8E4300D0 */  lw        $v1, 0xd0($s2)
/* CD45D4 802427A4 8C630030 */  lw        $v1, 0x30($v1)
/* CD45D8 802427A8 AFA30014 */  sw        $v1, 0x14($sp)
/* CD45DC 802427AC 8E4300D0 */  lw        $v1, 0xd0($s2)
/* CD45E0 802427B0 8C63001C */  lw        $v1, 0x1c($v1)
/* CD45E4 802427B4 AFA30018 */  sw        $v1, 0x18($sp)
/* CD45E8 802427B8 8E4300D0 */  lw        $v1, 0xd0($s2)
/* CD45EC 802427BC 8C630024 */  lw        $v1, 0x24($v1)
/* CD45F0 802427C0 AFA3001C */  sw        $v1, 0x1c($sp)
/* CD45F4 802427C4 8E4300D0 */  lw        $v1, 0xd0($s2)
/* CD45F8 802427C8 8C630028 */  lw        $v1, 0x28($v1)
/* CD45FC 802427CC 27B30010 */  addiu     $s3, $sp, 0x10
/* CD4600 802427D0 AFA30020 */  sw        $v1, 0x20($sp)
/* CD4604 802427D4 8E4300D0 */  lw        $v1, 0xd0($s2)
/* CD4608 802427D8 3C0142F0 */  lui       $at, 0x42f0
/* CD460C 802427DC 44810000 */  mtc1      $at, $f0
/* CD4610 802427E0 8C63002C */  lw        $v1, 0x2c($v1)
/* CD4614 802427E4 0040802D */  daddu     $s0, $v0, $zero
/* CD4618 802427E8 E7A00028 */  swc1      $f0, 0x28($sp)
/* CD461C 802427EC A7A0002C */  sh        $zero, 0x2c($sp)
/* CD4620 802427F0 12200007 */  beqz      $s1, .L80242810
/* CD4624 802427F4 AFA30024 */   sw       $v1, 0x24($sp)
/* CD4628 802427F8 02A0202D */  daddu     $a0, $s5, $zero
/* CD462C 802427FC 0240282D */  daddu     $a1, $s2, $zero
/* CD4630 80242800 0280302D */  daddu     $a2, $s4, $zero
/* CD4634 80242804 0C09080E */  jal       func_80242038_CD3E68
/* CD4638 80242808 0200382D */   daddu    $a3, $s0, $zero
/* CD463C 8024280C AE800070 */  sw        $zero, 0x70($s4)
.L80242810:
/* CD4640 80242810 2402FFFE */  addiu     $v0, $zero, -2
/* CD4644 80242814 A2A200AB */  sb        $v0, 0xab($s5)
/* CD4648 80242818 8E4300B0 */  lw        $v1, 0xb0($s2)
/* CD464C 8024281C 30620004 */  andi      $v0, $v1, 4
/* CD4650 80242820 10400007 */  beqz      $v0, .L80242840
/* CD4654 80242824 00000000 */   nop      
/* CD4658 80242828 824200B4 */  lb        $v0, 0xb4($s2)
/* CD465C 8024282C 1440003A */  bnez      $v0, .L80242918
/* CD4660 80242830 0000102D */   daddu    $v0, $zero, $zero
/* CD4664 80242834 2402FFFB */  addiu     $v0, $zero, -5
/* CD4668 80242838 00621024 */  and       $v0, $v1, $v0
/* CD466C 8024283C AE4200B0 */  sw        $v0, 0xb0($s2)
.L80242840:
/* CD4670 80242840 8E830070 */  lw        $v1, 0x70($s4)
/* CD4674 80242844 2C620015 */  sltiu     $v0, $v1, 0x15
/* CD4678 80242848 10400032 */  beqz      $v0, .L80242914
/* CD467C 8024284C 00031080 */   sll      $v0, $v1, 2
/* CD4680 80242850 3C018024 */  lui       $at, 0x8024
/* CD4684 80242854 00220821 */  addu      $at, $at, $v0
/* CD4688 80242858 8C225450 */  lw        $v0, 0x5450($at)
/* CD468C 8024285C 00400008 */  jr        $v0
/* CD4690 80242860 00000000 */   nop      
/* CD4694 80242864 0280202D */  daddu     $a0, $s4, $zero
/* CD4698 80242868 0200282D */  daddu     $a1, $s0, $zero
/* CD469C 8024286C 0C090394 */  jal       func_80240E50_CD2C80
/* CD46A0 80242870 0260302D */   daddu    $a2, $s3, $zero
/* CD46A4 80242874 0280202D */  daddu     $a0, $s4, $zero
/* CD46A8 80242878 0200282D */  daddu     $a1, $s0, $zero
/* CD46AC 8024287C 0C090400 */  jal       func_80241000_CD2E30
/* CD46B0 80242880 0260302D */   daddu    $a2, $s3, $zero
/* CD46B4 80242884 08090A46 */  j         .L80242918
/* CD46B8 80242888 0000102D */   daddu    $v0, $zero, $zero
/* CD46BC 8024288C 0280202D */  daddu     $a0, $s4, $zero
/* CD46C0 80242890 0200282D */  daddu     $a1, $s0, $zero
/* CD46C4 80242894 0C09058A */  jal       UnkNpcAIFunc1
/* CD46C8 80242898 0260302D */   daddu    $a2, $s3, $zero
/* CD46CC 8024289C 0280202D */  daddu     $a0, $s4, $zero
/* CD46D0 802428A0 0200282D */  daddu     $a1, $s0, $zero
/* CD46D4 802428A4 0C0905BA */  jal       func_802416E8_CD3518
/* CD46D8 802428A8 0260302D */   daddu    $a2, $s3, $zero
/* CD46DC 802428AC 08090A46 */  j         .L80242918
/* CD46E0 802428B0 0000102D */   daddu    $v0, $zero, $zero
/* CD46E4 802428B4 0280202D */  daddu     $a0, $s4, $zero
/* CD46E8 802428B8 0200282D */  daddu     $a1, $s0, $zero
/* CD46EC 802428BC 0C09068B */  jal       UnkNpcAIFunc2
/* CD46F0 802428C0 0260302D */   daddu    $a2, $s3, $zero
/* CD46F4 802428C4 0280202D */  daddu     $a0, $s4, $zero
/* CD46F8 802428C8 0200282D */  daddu     $a1, $s0, $zero
/* CD46FC 802428CC 0C0906A9 */  jal       func_80241AA4_CD38D4
/* CD4700 802428D0 0260302D */   daddu    $a2, $s3, $zero
/* CD4704 802428D4 08090A46 */  j         .L80242918
/* CD4708 802428D8 0000102D */   daddu    $v0, $zero, $zero
/* CD470C 802428DC 0280202D */  daddu     $a0, $s4, $zero
/* CD4710 802428E0 0200282D */  daddu     $a1, $s0, $zero
/* CD4714 802428E4 0C0908D2 */  jal       func_80242348_CD4178
/* CD4718 802428E8 0260302D */   daddu    $a2, $s3, $zero
/* CD471C 802428EC 0280202D */  daddu     $a0, $s4, $zero
/* CD4720 802428F0 0200282D */  daddu     $a1, $s0, $zero
/* CD4724 802428F4 0C09091E */  jal       func_80242478_CD42A8
/* CD4728 802428F8 0260302D */   daddu    $a2, $s3, $zero
/* CD472C 802428FC 08090A46 */  j         .L80242918
/* CD4730 80242900 0000102D */   daddu    $v0, $zero, $zero
/* CD4734 80242904 0280202D */  daddu     $a0, $s4, $zero
/* CD4738 80242908 0200282D */  daddu     $a1, $s0, $zero
/* CD473C 8024290C 0C0909BE */  jal       func_802426F8_CD4528
/* CD4740 80242910 0260302D */   daddu    $a2, $s3, $zero
.L80242914:
/* CD4744 80242914 0000102D */  daddu     $v0, $zero, $zero
.L80242918:
/* CD4748 80242918 8FBF0048 */  lw        $ra, 0x48($sp)
/* CD474C 8024291C 8FB50044 */  lw        $s5, 0x44($sp)
/* CD4750 80242920 8FB40040 */  lw        $s4, 0x40($sp)
/* CD4754 80242924 8FB3003C */  lw        $s3, 0x3c($sp)
/* CD4758 80242928 8FB20038 */  lw        $s2, 0x38($sp)
/* CD475C 8024292C 8FB10034 */  lw        $s1, 0x34($sp)
/* CD4760 80242930 8FB00030 */  lw        $s0, 0x30($sp)
/* CD4764 80242934 03E00008 */  jr        $ra
/* CD4768 80242938 27BD0050 */   addiu    $sp, $sp, 0x50
/* CD476C 8024293C 00000000 */  nop       
