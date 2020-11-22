.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024061C_C4FB2C
/* C4FB2C 8024061C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* C4FB30 80240620 AFB20038 */  sw        $s2, 0x38($sp)
/* C4FB34 80240624 0080902D */  daddu     $s2, $a0, $zero
/* C4FB38 80240628 AFBF0048 */  sw        $ra, 0x48($sp)
/* C4FB3C 8024062C AFB50044 */  sw        $s5, 0x44($sp)
/* C4FB40 80240630 AFB40040 */  sw        $s4, 0x40($sp)
/* C4FB44 80240634 AFB3003C */  sw        $s3, 0x3c($sp)
/* C4FB48 80240638 AFB10034 */  sw        $s1, 0x34($sp)
/* C4FB4C 8024063C AFB00030 */  sw        $s0, 0x30($sp)
/* C4FB50 80240640 8E510148 */  lw        $s1, 0x148($s2)
/* C4FB54 80240644 86240008 */  lh        $a0, 8($s1)
/* C4FB58 80240648 0C00EABB */  jal       get_npc_unsafe
/* C4FB5C 8024064C 00A0802D */   daddu    $s0, $a1, $zero
/* C4FB60 80240650 8E43000C */  lw        $v1, 0xc($s2)
/* C4FB64 80240654 0240202D */  daddu     $a0, $s2, $zero
/* C4FB68 80240658 8C650000 */  lw        $a1, ($v1)
/* C4FB6C 8024065C 0C0B1EAF */  jal       get_variable
/* C4FB70 80240660 0040A82D */   daddu    $s5, $v0, $zero
/* C4FB74 80240664 AFA00010 */  sw        $zero, 0x10($sp)
/* C4FB78 80240668 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C4FB7C 8024066C 8C630030 */  lw        $v1, 0x30($v1)
/* C4FB80 80240670 AFA30014 */  sw        $v1, 0x14($sp)
/* C4FB84 80240674 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C4FB88 80240678 8C63001C */  lw        $v1, 0x1c($v1)
/* C4FB8C 8024067C AFA30018 */  sw        $v1, 0x18($sp)
/* C4FB90 80240680 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C4FB94 80240684 8C630024 */  lw        $v1, 0x24($v1)
/* C4FB98 80240688 AFA3001C */  sw        $v1, 0x1c($sp)
/* C4FB9C 8024068C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C4FBA0 80240690 8C630028 */  lw        $v1, 0x28($v1)
/* C4FBA4 80240694 27B40010 */  addiu     $s4, $sp, 0x10
/* C4FBA8 80240698 AFA30020 */  sw        $v1, 0x20($sp)
/* C4FBAC 8024069C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C4FBB0 802406A0 3C014282 */  lui       $at, 0x4282
/* C4FBB4 802406A4 44810000 */  mtc1      $at, $f0
/* C4FBB8 802406A8 8C63002C */  lw        $v1, 0x2c($v1)
/* C4FBBC 802406AC 0040982D */  daddu     $s3, $v0, $zero
/* C4FBC0 802406B0 E7A00028 */  swc1      $f0, 0x28($sp)
/* C4FBC4 802406B4 A7A0002C */  sh        $zero, 0x2c($sp)
/* C4FBC8 802406B8 16000005 */  bnez      $s0, .L802406D0
/* C4FBCC 802406BC AFA30024 */   sw       $v1, 0x24($sp)
/* C4FBD0 802406C0 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C4FBD4 802406C4 30420004 */  andi      $v0, $v0, 4
/* C4FBD8 802406C8 10400020 */  beqz      $v0, .L8024074C
/* C4FBDC 802406CC 00000000 */   nop      
.L802406D0:
/* C4FBE0 802406D0 2404F7FF */  addiu     $a0, $zero, -0x801
/* C4FBE4 802406D4 AE400070 */  sw        $zero, 0x70($s2)
/* C4FBE8 802406D8 A6A0008E */  sh        $zero, 0x8e($s5)
/* C4FBEC 802406DC 8E2200CC */  lw        $v0, 0xcc($s1)
/* C4FBF0 802406E0 8EA30000 */  lw        $v1, ($s5)
/* C4FBF4 802406E4 8C420000 */  lw        $v0, ($v0)
/* C4FBF8 802406E8 00641824 */  and       $v1, $v1, $a0
/* C4FBFC 802406EC AEA30000 */  sw        $v1, ($s5)
/* C4FC00 802406F0 AEA20028 */  sw        $v0, 0x28($s5)
/* C4FC04 802406F4 8E2200D0 */  lw        $v0, 0xd0($s1)
/* C4FC08 802406F8 8C420034 */  lw        $v0, 0x34($v0)
/* C4FC0C 802406FC 54400005 */  bnel      $v0, $zero, .L80240714
/* C4FC10 80240700 2402FDFF */   addiu    $v0, $zero, -0x201
/* C4FC14 80240704 34620200 */  ori       $v0, $v1, 0x200
/* C4FC18 80240708 2403FFF7 */  addiu     $v1, $zero, -9
/* C4FC1C 8024070C 080901C7 */  j         .L8024071C
/* C4FC20 80240710 00431024 */   and      $v0, $v0, $v1
.L80240714:
/* C4FC24 80240714 00621024 */  and       $v0, $v1, $v0
/* C4FC28 80240718 34420008 */  ori       $v0, $v0, 8
.L8024071C:
/* C4FC2C 8024071C AEA20000 */  sw        $v0, ($s5)
/* C4FC30 80240720 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C4FC34 80240724 30420004 */  andi      $v0, $v0, 4
/* C4FC38 80240728 10400007 */  beqz      $v0, .L80240748
/* C4FC3C 8024072C 24020063 */   addiu    $v0, $zero, 0x63
/* C4FC40 80240730 AE420070 */  sw        $v0, 0x70($s2)
/* C4FC44 80240734 AE400074 */  sw        $zero, 0x74($s2)
/* C4FC48 80240738 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C4FC4C 8024073C 2403FFFB */  addiu     $v1, $zero, -5
/* C4FC50 80240740 00431024 */  and       $v0, $v0, $v1
/* C4FC54 80240744 AE2200B0 */  sw        $v0, 0xb0($s1)
.L80240748:
/* C4FC58 80240748 AE20006C */  sw        $zero, 0x6c($s1)
.L8024074C:
/* C4FC5C 8024074C 8E420070 */  lw        $v0, 0x70($s2)
/* C4FC60 80240750 2842001E */  slti      $v0, $v0, 0x1e
/* C4FC64 80240754 10400009 */  beqz      $v0, .L8024077C
/* C4FC68 80240758 00000000 */   nop      
/* C4FC6C 8024075C 8E22006C */  lw        $v0, 0x6c($s1)
/* C4FC70 80240760 14400006 */  bnez      $v0, .L8024077C
/* C4FC74 80240764 00000000 */   nop      
/* C4FC78 80240768 0C090082 */  jal       func_80240208_C4F718
/* C4FC7C 8024076C 0240202D */   daddu    $a0, $s2, $zero
/* C4FC80 80240770 10400002 */  beqz      $v0, .L8024077C
/* C4FC84 80240774 2402001E */   addiu    $v0, $zero, 0x1e
/* C4FC88 80240778 AE420070 */  sw        $v0, 0x70($s2)
.L8024077C:
/* C4FC8C 8024077C 8E430070 */  lw        $v1, 0x70($s2)
/* C4FC90 80240780 2C620064 */  sltiu     $v0, $v1, 0x64
/* C4FC94 80240784 10400048 */  beqz      $v0, .L802408A8
/* C4FC98 80240788 00031080 */   sll      $v0, $v1, 2
/* C4FC9C 8024078C 3C018024 */  lui       $at, 0x8024
/* C4FCA0 80240790 00220821 */  addu      $at, $at, $v0
/* C4FCA4 80240794 8C222CF8 */  lw        $v0, 0x2cf8($at)
/* C4FCA8 80240798 00400008 */  jr        $v0
/* C4FCAC 8024079C 00000000 */   nop      
/* C4FCB0 802407A0 0240202D */  daddu     $a0, $s2, $zero
/* C4FCB4 802407A4 0260282D */  daddu     $a1, $s3, $zero
/* C4FCB8 802407A8 0C012568 */  jal       func_800495A0
/* C4FCBC 802407AC 0280302D */   daddu    $a2, $s4, $zero
/* C4FCC0 802407B0 0240202D */  daddu     $a0, $s2, $zero
/* C4FCC4 802407B4 0260282D */  daddu     $a1, $s3, $zero
/* C4FCC8 802407B8 0C0125AE */  jal       func_800496B8
/* C4FCCC 802407BC 0280302D */   daddu    $a2, $s4, $zero
/* C4FCD0 802407C0 0809022A */  j         .L802408A8
/* C4FCD4 802407C4 00000000 */   nop      
/* C4FCD8 802407C8 0240202D */  daddu     $a0, $s2, $zero
/* C4FCDC 802407CC 0260282D */  daddu     $a1, $s3, $zero
/* C4FCE0 802407D0 0C0126D1 */  jal       func_80049B44
/* C4FCE4 802407D4 0280302D */   daddu    $a2, $s4, $zero
/* C4FCE8 802407D8 0240202D */  daddu     $a0, $s2, $zero
/* C4FCEC 802407DC 0260282D */  daddu     $a1, $s3, $zero
/* C4FCF0 802407E0 0C012701 */  jal       func_80049C04
/* C4FCF4 802407E4 0280302D */   daddu    $a2, $s4, $zero
/* C4FCF8 802407E8 0809022A */  j         .L802408A8
/* C4FCFC 802407EC 00000000 */   nop      
/* C4FD00 802407F0 0240202D */  daddu     $a0, $s2, $zero
/* C4FD04 802407F4 0260282D */  daddu     $a1, $s3, $zero
/* C4FD08 802407F8 0C01278F */  jal       func_80049E3C
/* C4FD0C 802407FC 0280302D */   daddu    $a2, $s4, $zero
/* C4FD10 80240800 0240202D */  daddu     $a0, $s2, $zero
/* C4FD14 80240804 0260282D */  daddu     $a1, $s3, $zero
/* C4FD18 80240808 0C0127B3 */  jal       func_80049ECC
/* C4FD1C 8024080C 0280302D */   daddu    $a2, $s4, $zero
/* C4FD20 80240810 0809022A */  j         .L802408A8
/* C4FD24 80240814 00000000 */   nop      
/* C4FD28 80240818 0240202D */  daddu     $a0, $s2, $zero
/* C4FD2C 8024081C 0260282D */  daddu     $a1, $s3, $zero
/* C4FD30 80240820 0C0127DF */  jal       func_80049F7C
/* C4FD34 80240824 0280302D */   daddu    $a2, $s4, $zero
/* C4FD38 80240828 0240202D */  daddu     $a0, $s2, $zero
/* C4FD3C 8024082C 0260282D */  daddu     $a1, $s3, $zero
/* C4FD40 80240830 0C012849 */  jal       func_8004A124
/* C4FD44 80240834 0280302D */   daddu    $a2, $s4, $zero
/* C4FD48 80240838 0809022A */  j         .L802408A8
/* C4FD4C 8024083C 00000000 */   nop      
/* C4FD50 80240840 0240202D */  daddu     $a0, $s2, $zero
/* C4FD54 80240844 0260282D */  daddu     $a1, $s3, $zero
/* C4FD58 80240848 0C0128FA */  jal       func_8004A3E8
/* C4FD5C 8024084C 0280302D */   daddu    $a2, $s4, $zero
/* C4FD60 80240850 0809022A */  j         .L802408A8
/* C4FD64 80240854 00000000 */   nop      
/* C4FD68 80240858 0C090000 */  jal       UnkNpcAIFunc6
/* C4FD6C 8024085C 0240202D */   daddu    $a0, $s2, $zero
/* C4FD70 80240860 0C09001B */  jal       func_8024006C_C4F57C
/* C4FD74 80240864 0240202D */   daddu    $a0, $s2, $zero
/* C4FD78 80240868 8E430070 */  lw        $v1, 0x70($s2)
/* C4FD7C 8024086C 24020020 */  addiu     $v0, $zero, 0x20
/* C4FD80 80240870 1462000D */  bne       $v1, $v0, .L802408A8
/* C4FD84 80240874 00000000 */   nop      
/* C4FD88 80240878 0C090037 */  jal       func_802400DC_C4F5EC
/* C4FD8C 8024087C 0240202D */   daddu    $a0, $s2, $zero
/* C4FD90 80240880 8E430070 */  lw        $v1, 0x70($s2)
/* C4FD94 80240884 24020021 */  addiu     $v0, $zero, 0x21
/* C4FD98 80240888 14620007 */  bne       $v1, $v0, .L802408A8
/* C4FD9C 8024088C 00000000 */   nop      
/* C4FDA0 80240890 0C09006D */  jal       UnkNpcAIFunc5
/* C4FDA4 80240894 0240202D */   daddu    $a0, $s2, $zero
/* C4FDA8 80240898 0809022A */  j         .L802408A8
/* C4FDAC 8024089C 00000000 */   nop      
/* C4FDB0 802408A0 0C0129CF */  jal       func_8004A73C
/* C4FDB4 802408A4 0240202D */   daddu    $a0, $s2, $zero
.L802408A8:
/* C4FDB8 802408A8 8FBF0048 */  lw        $ra, 0x48($sp)
/* C4FDBC 802408AC 8FB50044 */  lw        $s5, 0x44($sp)
/* C4FDC0 802408B0 8FB40040 */  lw        $s4, 0x40($sp)
/* C4FDC4 802408B4 8FB3003C */  lw        $s3, 0x3c($sp)
/* C4FDC8 802408B8 8FB20038 */  lw        $s2, 0x38($sp)
/* C4FDCC 802408BC 8FB10034 */  lw        $s1, 0x34($sp)
/* C4FDD0 802408C0 8FB00030 */  lw        $s0, 0x30($sp)
/* C4FDD4 802408C4 0000102D */  daddu     $v0, $zero, $zero
/* C4FDD8 802408C8 03E00008 */  jr        $ra
/* C4FDDC 802408CC 27BD0050 */   addiu    $sp, $sp, 0x50
