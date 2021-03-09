.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024061C_D18DFC
/* D18DFC 8024061C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* D18E00 80240620 AFB20038 */  sw        $s2, 0x38($sp)
/* D18E04 80240624 0080902D */  daddu     $s2, $a0, $zero
/* D18E08 80240628 AFBF0048 */  sw        $ra, 0x48($sp)
/* D18E0C 8024062C AFB50044 */  sw        $s5, 0x44($sp)
/* D18E10 80240630 AFB40040 */  sw        $s4, 0x40($sp)
/* D18E14 80240634 AFB3003C */  sw        $s3, 0x3c($sp)
/* D18E18 80240638 AFB10034 */  sw        $s1, 0x34($sp)
/* D18E1C 8024063C AFB00030 */  sw        $s0, 0x30($sp)
/* D18E20 80240640 8E510148 */  lw        $s1, 0x148($s2)
/* D18E24 80240644 86240008 */  lh        $a0, 8($s1)
/* D18E28 80240648 0C00EABB */  jal       get_npc_unsafe
/* D18E2C 8024064C 00A0802D */   daddu    $s0, $a1, $zero
/* D18E30 80240650 8E43000C */  lw        $v1, 0xc($s2)
/* D18E34 80240654 0240202D */  daddu     $a0, $s2, $zero
/* D18E38 80240658 8C650000 */  lw        $a1, ($v1)
/* D18E3C 8024065C 0C0B1EAF */  jal       get_variable
/* D18E40 80240660 0040A82D */   daddu    $s5, $v0, $zero
/* D18E44 80240664 AFA00010 */  sw        $zero, 0x10($sp)
/* D18E48 80240668 8E2300D0 */  lw        $v1, 0xd0($s1)
/* D18E4C 8024066C 8C630030 */  lw        $v1, 0x30($v1)
/* D18E50 80240670 AFA30014 */  sw        $v1, 0x14($sp)
/* D18E54 80240674 8E2300D0 */  lw        $v1, 0xd0($s1)
/* D18E58 80240678 8C63001C */  lw        $v1, 0x1c($v1)
/* D18E5C 8024067C AFA30018 */  sw        $v1, 0x18($sp)
/* D18E60 80240680 8E2300D0 */  lw        $v1, 0xd0($s1)
/* D18E64 80240684 8C630024 */  lw        $v1, 0x24($v1)
/* D18E68 80240688 AFA3001C */  sw        $v1, 0x1c($sp)
/* D18E6C 8024068C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* D18E70 80240690 8C630028 */  lw        $v1, 0x28($v1)
/* D18E74 80240694 27B40010 */  addiu     $s4, $sp, 0x10
/* D18E78 80240698 AFA30020 */  sw        $v1, 0x20($sp)
/* D18E7C 8024069C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* D18E80 802406A0 3C014282 */  lui       $at, 0x4282
/* D18E84 802406A4 44810000 */  mtc1      $at, $f0
/* D18E88 802406A8 8C63002C */  lw        $v1, 0x2c($v1)
/* D18E8C 802406AC 0040982D */  daddu     $s3, $v0, $zero
/* D18E90 802406B0 E7A00028 */  swc1      $f0, 0x28($sp)
/* D18E94 802406B4 A7A0002C */  sh        $zero, 0x2c($sp)
/* D18E98 802406B8 16000005 */  bnez      $s0, .L802406D0
/* D18E9C 802406BC AFA30024 */   sw       $v1, 0x24($sp)
/* D18EA0 802406C0 8E2200B0 */  lw        $v0, 0xb0($s1)
/* D18EA4 802406C4 30420004 */  andi      $v0, $v0, 4
/* D18EA8 802406C8 10400020 */  beqz      $v0, .L8024074C
/* D18EAC 802406CC 00000000 */   nop
.L802406D0:
/* D18EB0 802406D0 2404F7FF */  addiu     $a0, $zero, -0x801
/* D18EB4 802406D4 AE400070 */  sw        $zero, 0x70($s2)
/* D18EB8 802406D8 A6A0008E */  sh        $zero, 0x8e($s5)
/* D18EBC 802406DC 8E2200CC */  lw        $v0, 0xcc($s1)
/* D18EC0 802406E0 8EA30000 */  lw        $v1, ($s5)
/* D18EC4 802406E4 8C420000 */  lw        $v0, ($v0)
/* D18EC8 802406E8 00641824 */  and       $v1, $v1, $a0
/* D18ECC 802406EC AEA30000 */  sw        $v1, ($s5)
/* D18ED0 802406F0 AEA20028 */  sw        $v0, 0x28($s5)
/* D18ED4 802406F4 8E2200D0 */  lw        $v0, 0xd0($s1)
/* D18ED8 802406F8 8C420034 */  lw        $v0, 0x34($v0)
/* D18EDC 802406FC 54400005 */  bnel      $v0, $zero, .L80240714
/* D18EE0 80240700 2402FDFF */   addiu    $v0, $zero, -0x201
/* D18EE4 80240704 34620200 */  ori       $v0, $v1, 0x200
/* D18EE8 80240708 2403FFF7 */  addiu     $v1, $zero, -9
/* D18EEC 8024070C 080901C7 */  j         .L8024071C
/* D18EF0 80240710 00431024 */   and      $v0, $v0, $v1
.L80240714:
/* D18EF4 80240714 00621024 */  and       $v0, $v1, $v0
/* D18EF8 80240718 34420008 */  ori       $v0, $v0, 8
.L8024071C:
/* D18EFC 8024071C AEA20000 */  sw        $v0, ($s5)
/* D18F00 80240720 8E2200B0 */  lw        $v0, 0xb0($s1)
/* D18F04 80240724 30420004 */  andi      $v0, $v0, 4
/* D18F08 80240728 10400007 */  beqz      $v0, .L80240748
/* D18F0C 8024072C 24020063 */   addiu    $v0, $zero, 0x63
/* D18F10 80240730 AE420070 */  sw        $v0, 0x70($s2)
/* D18F14 80240734 AE400074 */  sw        $zero, 0x74($s2)
/* D18F18 80240738 8E2200B0 */  lw        $v0, 0xb0($s1)
/* D18F1C 8024073C 2403FFFB */  addiu     $v1, $zero, -5
/* D18F20 80240740 00431024 */  and       $v0, $v0, $v1
/* D18F24 80240744 AE2200B0 */  sw        $v0, 0xb0($s1)
.L80240748:
/* D18F28 80240748 AE20006C */  sw        $zero, 0x6c($s1)
.L8024074C:
/* D18F2C 8024074C 8E420070 */  lw        $v0, 0x70($s2)
/* D18F30 80240750 2842001E */  slti      $v0, $v0, 0x1e
/* D18F34 80240754 10400009 */  beqz      $v0, .L8024077C
/* D18F38 80240758 00000000 */   nop
/* D18F3C 8024075C 8E22006C */  lw        $v0, 0x6c($s1)
/* D18F40 80240760 14400006 */  bnez      $v0, .L8024077C
/* D18F44 80240764 00000000 */   nop
/* D18F48 80240768 0C090082 */  jal       func_80240208_D189E8
/* D18F4C 8024076C 0240202D */   daddu    $a0, $s2, $zero
/* D18F50 80240770 10400002 */  beqz      $v0, .L8024077C
/* D18F54 80240774 2402001E */   addiu    $v0, $zero, 0x1e
/* D18F58 80240778 AE420070 */  sw        $v0, 0x70($s2)
.L8024077C:
/* D18F5C 8024077C 8E430070 */  lw        $v1, 0x70($s2)
/* D18F60 80240780 2C620064 */  sltiu     $v0, $v1, 0x64
/* D18F64 80240784 10400048 */  beqz      $v0, L802408A8_D19088
/* D18F68 80240788 00031080 */   sll      $v0, $v1, 2
/* D18F6C 8024078C 3C018024 */  lui       $at, %hi(jtbl_802474E8_D1FCC8)
/* D18F70 80240790 00220821 */  addu      $at, $at, $v0
/* D18F74 80240794 8C2274E8 */  lw        $v0, %lo(jtbl_802474E8_D1FCC8)($at)
/* D18F78 80240798 00400008 */  jr        $v0
/* D18F7C 8024079C 00000000 */   nop
glabel L802407A0_D18F80
/* D18F80 802407A0 0240202D */  daddu     $a0, $s2, $zero
/* D18F84 802407A4 0260282D */  daddu     $a1, $s3, $zero
/* D18F88 802407A8 0C012568 */  jal       func_800495A0
/* D18F8C 802407AC 0280302D */   daddu    $a2, $s4, $zero
glabel L802407B0_D18F90
/* D18F90 802407B0 0240202D */  daddu     $a0, $s2, $zero
/* D18F94 802407B4 0260282D */  daddu     $a1, $s3, $zero
/* D18F98 802407B8 0C0125AE */  jal       func_800496B8
/* D18F9C 802407BC 0280302D */   daddu    $a2, $s4, $zero
/* D18FA0 802407C0 0809022A */  j         L802408A8_D19088
/* D18FA4 802407C4 00000000 */   nop
glabel L802407C8_D18FA8
/* D18FA8 802407C8 0240202D */  daddu     $a0, $s2, $zero
/* D18FAC 802407CC 0260282D */  daddu     $a1, $s3, $zero
/* D18FB0 802407D0 0C0126D1 */  jal       base_UnkNpcAIFunc1
/* D18FB4 802407D4 0280302D */   daddu    $a2, $s4, $zero
glabel L802407D8_D18FB8
/* D18FB8 802407D8 0240202D */  daddu     $a0, $s2, $zero
/* D18FBC 802407DC 0260282D */  daddu     $a1, $s3, $zero
/* D18FC0 802407E0 0C012701 */  jal       func_80049C04
/* D18FC4 802407E4 0280302D */   daddu    $a2, $s4, $zero
/* D18FC8 802407E8 0809022A */  j         L802408A8_D19088
/* D18FCC 802407EC 00000000 */   nop
glabel L802407F0_D18FD0
/* D18FD0 802407F0 0240202D */  daddu     $a0, $s2, $zero
/* D18FD4 802407F4 0260282D */  daddu     $a1, $s3, $zero
/* D18FD8 802407F8 0C01278F */  jal       func_80049E3C
/* D18FDC 802407FC 0280302D */   daddu    $a2, $s4, $zero
glabel L80240800_D18FE0
/* D18FE0 80240800 0240202D */  daddu     $a0, $s2, $zero
/* D18FE4 80240804 0260282D */  daddu     $a1, $s3, $zero
/* D18FE8 80240808 0C0127B3 */  jal       func_80049ECC
/* D18FEC 8024080C 0280302D */   daddu    $a2, $s4, $zero
/* D18FF0 80240810 0809022A */  j         L802408A8_D19088
/* D18FF4 80240814 00000000 */   nop
glabel L80240818_D18FF8
/* D18FF8 80240818 0240202D */  daddu     $a0, $s2, $zero
/* D18FFC 8024081C 0260282D */  daddu     $a1, $s3, $zero
/* D19000 80240820 0C0127DF */  jal       func_80049F7C
/* D19004 80240824 0280302D */   daddu    $a2, $s4, $zero
glabel L80240828_D19008
/* D19008 80240828 0240202D */  daddu     $a0, $s2, $zero
/* D1900C 8024082C 0260282D */  daddu     $a1, $s3, $zero
/* D19010 80240830 0C012849 */  jal       func_8004A124
/* D19014 80240834 0280302D */   daddu    $a2, $s4, $zero
/* D19018 80240838 0809022A */  j         L802408A8_D19088
/* D1901C 8024083C 00000000 */   nop
glabel L80240840_D19020
/* D19020 80240840 0240202D */  daddu     $a0, $s2, $zero
/* D19024 80240844 0260282D */  daddu     $a1, $s3, $zero
/* D19028 80240848 0C0128FA */  jal       func_8004A3E8
/* D1902C 8024084C 0280302D */   daddu    $a2, $s4, $zero
/* D19030 80240850 0809022A */  j         L802408A8_D19088
/* D19034 80240854 00000000 */   nop
glabel L80240858_D19038
/* D19038 80240858 0C090000 */  jal       sam_05_UnkNpcAIFunc6
/* D1903C 8024085C 0240202D */   daddu    $a0, $s2, $zero
glabel L80240860_D19040
/* D19040 80240860 0C09001B */  jal       sam_05_UnkNpcAIFunc7
/* D19044 80240864 0240202D */   daddu    $a0, $s2, $zero
/* D19048 80240868 8E430070 */  lw        $v1, 0x70($s2)
/* D1904C 8024086C 24020020 */  addiu     $v0, $zero, 0x20
/* D19050 80240870 1462000D */  bne       $v1, $v0, L802408A8_D19088
/* D19054 80240874 00000000 */   nop
glabel L80240878_D19058
/* D19058 80240878 0C090037 */  jal       sam_05_UnkNpcAIFunc8
/* D1905C 8024087C 0240202D */   daddu    $a0, $s2, $zero
/* D19060 80240880 8E430070 */  lw        $v1, 0x70($s2)
/* D19064 80240884 24020021 */  addiu     $v0, $zero, 0x21
/* D19068 80240888 14620007 */  bne       $v1, $v0, L802408A8_D19088
/* D1906C 8024088C 00000000 */   nop
glabel L80240890_D19070
/* D19070 80240890 0C09006D */  jal       sam_05_UnkNpcAIFunc5
/* D19074 80240894 0240202D */   daddu    $a0, $s2, $zero
/* D19078 80240898 0809022A */  j         L802408A8_D19088
/* D1907C 8024089C 00000000 */   nop
glabel L802408A0_D19080
/* D19080 802408A0 0C0129CF */  jal       func_8004A73C
/* D19084 802408A4 0240202D */   daddu    $a0, $s2, $zero
glabel L802408A8_D19088
/* D19088 802408A8 8FBF0048 */  lw        $ra, 0x48($sp)
/* D1908C 802408AC 8FB50044 */  lw        $s5, 0x44($sp)
/* D19090 802408B0 8FB40040 */  lw        $s4, 0x40($sp)
/* D19094 802408B4 8FB3003C */  lw        $s3, 0x3c($sp)
/* D19098 802408B8 8FB20038 */  lw        $s2, 0x38($sp)
/* D1909C 802408BC 8FB10034 */  lw        $s1, 0x34($sp)
/* D190A0 802408C0 8FB00030 */  lw        $s0, 0x30($sp)
/* D190A4 802408C4 0000102D */  daddu     $v0, $zero, $zero
/* D190A8 802408C8 03E00008 */  jr        $ra
/* D190AC 802408CC 27BD0050 */   addiu    $sp, $sp, 0x50
