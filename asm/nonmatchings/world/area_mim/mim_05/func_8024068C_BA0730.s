.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024068C_BA0DBC
/* BA0DBC 8024068C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* BA0DC0 80240690 AFB20038 */  sw        $s2, 0x38($sp)
/* BA0DC4 80240694 0080902D */  daddu     $s2, $a0, $zero
/* BA0DC8 80240698 AFBF0048 */  sw        $ra, 0x48($sp)
/* BA0DCC 8024069C AFB50044 */  sw        $s5, 0x44($sp)
/* BA0DD0 802406A0 AFB40040 */  sw        $s4, 0x40($sp)
/* BA0DD4 802406A4 AFB3003C */  sw        $s3, 0x3c($sp)
/* BA0DD8 802406A8 AFB10034 */  sw        $s1, 0x34($sp)
/* BA0DDC 802406AC AFB00030 */  sw        $s0, 0x30($sp)
/* BA0DE0 802406B0 8E510148 */  lw        $s1, 0x148($s2)
/* BA0DE4 802406B4 86240008 */  lh        $a0, 8($s1)
/* BA0DE8 802406B8 0C00EABB */  jal       get_npc_unsafe
/* BA0DEC 802406BC 00A0802D */   daddu    $s0, $a1, $zero
/* BA0DF0 802406C0 8E43000C */  lw        $v1, 0xc($s2)
/* BA0DF4 802406C4 0240202D */  daddu     $a0, $s2, $zero
/* BA0DF8 802406C8 8C650000 */  lw        $a1, ($v1)
/* BA0DFC 802406CC 0C0B1EAF */  jal       get_variable
/* BA0E00 802406D0 0040A82D */   daddu    $s5, $v0, $zero
/* BA0E04 802406D4 AFA00010 */  sw        $zero, 0x10($sp)
/* BA0E08 802406D8 8E2300D0 */  lw        $v1, 0xd0($s1)
/* BA0E0C 802406DC 8C630030 */  lw        $v1, 0x30($v1)
/* BA0E10 802406E0 AFA30014 */  sw        $v1, 0x14($sp)
/* BA0E14 802406E4 8E2300D0 */  lw        $v1, 0xd0($s1)
/* BA0E18 802406E8 8C63001C */  lw        $v1, 0x1c($v1)
/* BA0E1C 802406EC AFA30018 */  sw        $v1, 0x18($sp)
/* BA0E20 802406F0 8E2300D0 */  lw        $v1, 0xd0($s1)
/* BA0E24 802406F4 8C630024 */  lw        $v1, 0x24($v1)
/* BA0E28 802406F8 AFA3001C */  sw        $v1, 0x1c($sp)
/* BA0E2C 802406FC 8E2300D0 */  lw        $v1, 0xd0($s1)
/* BA0E30 80240700 8C630028 */  lw        $v1, 0x28($v1)
/* BA0E34 80240704 27B40010 */  addiu     $s4, $sp, 0x10
/* BA0E38 80240708 AFA30020 */  sw        $v1, 0x20($sp)
/* BA0E3C 8024070C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* BA0E40 80240710 3C014282 */  lui       $at, 0x4282
/* BA0E44 80240714 44810000 */  mtc1      $at, $f0
/* BA0E48 80240718 8C63002C */  lw        $v1, 0x2c($v1)
/* BA0E4C 8024071C 0040982D */  daddu     $s3, $v0, $zero
/* BA0E50 80240720 E7A00028 */  swc1      $f0, 0x28($sp)
/* BA0E54 80240724 A7A0002C */  sh        $zero, 0x2c($sp)
/* BA0E58 80240728 16000005 */  bnez      $s0, .L80240740
/* BA0E5C 8024072C AFA30024 */   sw       $v1, 0x24($sp)
/* BA0E60 80240730 8E2200B0 */  lw        $v0, 0xb0($s1)
/* BA0E64 80240734 30420004 */  andi      $v0, $v0, 4
/* BA0E68 80240738 10400020 */  beqz      $v0, .L802407BC
/* BA0E6C 8024073C 00000000 */   nop      
.L80240740:
/* BA0E70 80240740 2404F7FF */  addiu     $a0, $zero, -0x801
/* BA0E74 80240744 AE400070 */  sw        $zero, 0x70($s2)
/* BA0E78 80240748 A6A0008E */  sh        $zero, 0x8e($s5)
/* BA0E7C 8024074C 8E2200CC */  lw        $v0, 0xcc($s1)
/* BA0E80 80240750 8EA30000 */  lw        $v1, ($s5)
/* BA0E84 80240754 8C420000 */  lw        $v0, ($v0)
/* BA0E88 80240758 00641824 */  and       $v1, $v1, $a0
/* BA0E8C 8024075C AEA30000 */  sw        $v1, ($s5)
/* BA0E90 80240760 AEA20028 */  sw        $v0, 0x28($s5)
/* BA0E94 80240764 8E2200D0 */  lw        $v0, 0xd0($s1)
/* BA0E98 80240768 8C420034 */  lw        $v0, 0x34($v0)
/* BA0E9C 8024076C 54400005 */  bnel      $v0, $zero, .L80240784
/* BA0EA0 80240770 2402FDFF */   addiu    $v0, $zero, -0x201
/* BA0EA4 80240774 34620200 */  ori       $v0, $v1, 0x200
/* BA0EA8 80240778 2403FFF7 */  addiu     $v1, $zero, -9
/* BA0EAC 8024077C 080901E3 */  j         .L8024078C
/* BA0EB0 80240780 00431024 */   and      $v0, $v0, $v1
.L80240784:
/* BA0EB4 80240784 00621024 */  and       $v0, $v1, $v0
/* BA0EB8 80240788 34420008 */  ori       $v0, $v0, 8
.L8024078C:
/* BA0EBC 8024078C AEA20000 */  sw        $v0, ($s5)
/* BA0EC0 80240790 8E2200B0 */  lw        $v0, 0xb0($s1)
/* BA0EC4 80240794 30420004 */  andi      $v0, $v0, 4
/* BA0EC8 80240798 10400007 */  beqz      $v0, .L802407B8
/* BA0ECC 8024079C 24020063 */   addiu    $v0, $zero, 0x63
/* BA0ED0 802407A0 AE420070 */  sw        $v0, 0x70($s2)
/* BA0ED4 802407A4 AE400074 */  sw        $zero, 0x74($s2)
/* BA0ED8 802407A8 8E2200B0 */  lw        $v0, 0xb0($s1)
/* BA0EDC 802407AC 2403FFFB */  addiu     $v1, $zero, -5
/* BA0EE0 802407B0 00431024 */  and       $v0, $v0, $v1
/* BA0EE4 802407B4 AE2200B0 */  sw        $v0, 0xb0($s1)
.L802407B8:
/* BA0EE8 802407B8 AE20006C */  sw        $zero, 0x6c($s1)
.L802407BC:
/* BA0EEC 802407BC 8E420070 */  lw        $v0, 0x70($s2)
/* BA0EF0 802407C0 2842001E */  slti      $v0, $v0, 0x1e
/* BA0EF4 802407C4 10400009 */  beqz      $v0, .L802407EC
/* BA0EF8 802407C8 00000000 */   nop      
/* BA0EFC 802407CC 8E22006C */  lw        $v0, 0x6c($s1)
/* BA0F00 802407D0 14400006 */  bnez      $v0, .L802407EC
/* BA0F04 802407D4 00000000 */   nop      
/* BA0F08 802407D8 0C09009E */  jal       func_80240278
/* BA0F0C 802407DC 0240202D */   daddu    $a0, $s2, $zero
/* BA0F10 802407E0 10400002 */  beqz      $v0, .L802407EC
/* BA0F14 802407E4 2402001E */   addiu    $v0, $zero, 0x1e
/* BA0F18 802407E8 AE420070 */  sw        $v0, 0x70($s2)
.L802407EC:
/* BA0F1C 802407EC 8E430070 */  lw        $v1, 0x70($s2)
/* BA0F20 802407F0 2C620064 */  sltiu     $v0, $v1, 0x64
/* BA0F24 802407F4 10400048 */  beqz      $v0, .L80240918
/* BA0F28 802407F8 00031080 */   sll      $v0, $v1, 2
/* BA0F2C 802407FC 3C018024 */  lui       $at, 0x8024
/* BA0F30 80240800 00220821 */  addu      $at, $at, $v0
/* BA0F34 80240804 8C223E88 */  lw        $v0, 0x3e88($at)
/* BA0F38 80240808 00400008 */  jr        $v0
/* BA0F3C 8024080C 00000000 */   nop      
/* BA0F40 80240810 0240202D */  daddu     $a0, $s2, $zero
/* BA0F44 80240814 0260282D */  daddu     $a1, $s3, $zero
/* BA0F48 80240818 0C012568 */  jal       func_800495A0
/* BA0F4C 8024081C 0280302D */   daddu    $a2, $s4, $zero
/* BA0F50 80240820 0240202D */  daddu     $a0, $s2, $zero
/* BA0F54 80240824 0260282D */  daddu     $a1, $s3, $zero
/* BA0F58 80240828 0C0125AE */  jal       func_800496B8
/* BA0F5C 8024082C 0280302D */   daddu    $a2, $s4, $zero
/* BA0F60 80240830 08090246 */  j         .L80240918
/* BA0F64 80240834 00000000 */   nop      
/* BA0F68 80240838 0240202D */  daddu     $a0, $s2, $zero
/* BA0F6C 8024083C 0260282D */  daddu     $a1, $s3, $zero
/* BA0F70 80240840 0C0126D1 */  jal       func_80049B44
/* BA0F74 80240844 0280302D */   daddu    $a2, $s4, $zero
/* BA0F78 80240848 0240202D */  daddu     $a0, $s2, $zero
/* BA0F7C 8024084C 0260282D */  daddu     $a1, $s3, $zero
/* BA0F80 80240850 0C012701 */  jal       func_80049C04
/* BA0F84 80240854 0280302D */   daddu    $a2, $s4, $zero
/* BA0F88 80240858 08090246 */  j         .L80240918
/* BA0F8C 8024085C 00000000 */   nop      
/* BA0F90 80240860 0240202D */  daddu     $a0, $s2, $zero
/* BA0F94 80240864 0260282D */  daddu     $a1, $s3, $zero
/* BA0F98 80240868 0C01278F */  jal       func_80049E3C
/* BA0F9C 8024086C 0280302D */   daddu    $a2, $s4, $zero
/* BA0FA0 80240870 0240202D */  daddu     $a0, $s2, $zero
/* BA0FA4 80240874 0260282D */  daddu     $a1, $s3, $zero
/* BA0FA8 80240878 0C0127B3 */  jal       func_80049ECC
/* BA0FAC 8024087C 0280302D */   daddu    $a2, $s4, $zero
/* BA0FB0 80240880 08090246 */  j         .L80240918
/* BA0FB4 80240884 00000000 */   nop      
/* BA0FB8 80240888 0240202D */  daddu     $a0, $s2, $zero
/* BA0FBC 8024088C 0260282D */  daddu     $a1, $s3, $zero
/* BA0FC0 80240890 0C0127DF */  jal       func_80049F7C
/* BA0FC4 80240894 0280302D */   daddu    $a2, $s4, $zero
/* BA0FC8 80240898 0240202D */  daddu     $a0, $s2, $zero
/* BA0FCC 8024089C 0260282D */  daddu     $a1, $s3, $zero
/* BA0FD0 802408A0 0C012849 */  jal       func_8004A124
/* BA0FD4 802408A4 0280302D */   daddu    $a2, $s4, $zero
/* BA0FD8 802408A8 08090246 */  j         .L80240918
/* BA0FDC 802408AC 00000000 */   nop      
/* BA0FE0 802408B0 0240202D */  daddu     $a0, $s2, $zero
/* BA0FE4 802408B4 0260282D */  daddu     $a1, $s3, $zero
/* BA0FE8 802408B8 0C0128FA */  jal       func_8004A3E8
/* BA0FEC 802408BC 0280302D */   daddu    $a2, $s4, $zero
/* BA0FF0 802408C0 08090246 */  j         .L80240918
/* BA0FF4 802408C4 00000000 */   nop      
/* BA0FF8 802408C8 0C09001C */  jal       func_80240070
/* BA0FFC 802408CC 0240202D */   daddu    $a0, $s2, $zero
/* BA1000 802408D0 0C090037 */  jal       func_802400DC
/* BA1004 802408D4 0240202D */   daddu    $a0, $s2, $zero
/* BA1008 802408D8 8E430070 */  lw        $v1, 0x70($s2)
/* BA100C 802408DC 24020020 */  addiu     $v0, $zero, 0x20
/* BA1010 802408E0 1462000D */  bne       $v1, $v0, .L80240918
/* BA1014 802408E4 00000000 */   nop      
/* BA1018 802408E8 0C090053 */  jal       func_8024014C
/* BA101C 802408EC 0240202D */   daddu    $a0, $s2, $zero
/* BA1020 802408F0 8E430070 */  lw        $v1, 0x70($s2)
/* BA1024 802408F4 24020021 */  addiu     $v0, $zero, 0x21
/* BA1028 802408F8 14620007 */  bne       $v1, $v0, .L80240918
/* BA102C 802408FC 00000000 */   nop      
/* BA1030 80240900 0C090089 */  jal       func_80240224
/* BA1034 80240904 0240202D */   daddu    $a0, $s2, $zero
/* BA1038 80240908 08090246 */  j         .L80240918
/* BA103C 8024090C 00000000 */   nop      
/* BA1040 80240910 0C0129CF */  jal       func_8004A73C
/* BA1044 80240914 0240202D */   daddu    $a0, $s2, $zero
.L80240918:
/* BA1048 80240918 8FBF0048 */  lw        $ra, 0x48($sp)
/* BA104C 8024091C 8FB50044 */  lw        $s5, 0x44($sp)
/* BA1050 80240920 8FB40040 */  lw        $s4, 0x40($sp)
/* BA1054 80240924 8FB3003C */  lw        $s3, 0x3c($sp)
/* BA1058 80240928 8FB20038 */  lw        $s2, 0x38($sp)
/* BA105C 8024092C 8FB10034 */  lw        $s1, 0x34($sp)
/* BA1060 80240930 8FB00030 */  lw        $s0, 0x30($sp)
/* BA1064 80240934 0000102D */  daddu     $v0, $zero, $zero
/* BA1068 80240938 03E00008 */  jr        $ra
/* BA106C 8024093C 27BD0050 */   addiu    $sp, $sp, 0x50
