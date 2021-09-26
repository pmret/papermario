.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802406CC_EA0FCC
/* EA0FCC 802406CC 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* EA0FD0 802406D0 AFB40028 */  sw        $s4, 0x28($sp)
/* EA0FD4 802406D4 0080A02D */  daddu     $s4, $a0, $zero
/* EA0FD8 802406D8 AFBF002C */  sw        $ra, 0x2c($sp)
/* EA0FDC 802406DC AFB30024 */  sw        $s3, 0x24($sp)
/* EA0FE0 802406E0 AFB20020 */  sw        $s2, 0x20($sp)
/* EA0FE4 802406E4 AFB1001C */  sw        $s1, 0x1c($sp)
/* EA0FE8 802406E8 AFB00018 */  sw        $s0, 0x18($sp)
/* EA0FEC 802406EC 8E910148 */  lw        $s1, 0x148($s4)
/* EA0FF0 802406F0 86240008 */  lh        $a0, 8($s1)
/* EA0FF4 802406F4 0C00F92F */  jal       dead_get_npc_unsafe
/* EA0FF8 802406F8 00A0802D */   daddu    $s0, $a1, $zero
/* EA0FFC 802406FC 0040902D */  daddu     $s2, $v0, $zero
/* EA1000 80240700 C6400038 */  lwc1      $f0, 0x38($s2)
/* EA1004 80240704 E6200108 */  swc1      $f0, 0x108($s1)
/* EA1008 80240708 C640003C */  lwc1      $f0, 0x3c($s2)
/* EA100C 8024070C E620010C */  swc1      $f0, 0x10c($s1)
/* EA1010 80240710 3C0138D1 */  lui       $at, 0x38d1
/* EA1014 80240714 3421B717 */  ori       $at, $at, 0xb717
/* EA1018 80240718 44810000 */  mtc1      $at, $f0
/* EA101C 8024071C C6420040 */  lwc1      $f2, 0x40($s2)
/* EA1020 80240720 E6200114 */  swc1      $f0, 0x114($s1)
/* EA1024 80240724 E6200118 */  swc1      $f0, 0x118($s1)
/* EA1028 80240728 16000005 */  bnez      $s0, .L80240740
/* EA102C 8024072C E6220110 */   swc1     $f2, 0x110($s1)
/* EA1030 80240730 8E2200B0 */  lw        $v0, 0xb0($s1)
/* EA1034 80240734 30420004 */  andi      $v0, $v0, 4
/* EA1038 80240738 10400015 */  beqz      $v0, .L80240790
/* EA103C 8024073C 00000000 */   nop
.L80240740:
/* EA1040 80240740 AE800070 */  sw        $zero, 0x70($s4)
/* EA1044 80240744 8E420000 */  lw        $v0, ($s2)
/* EA1048 80240748 3C031F30 */  lui       $v1, 0x1f30
/* EA104C 8024074C A640008E */  sh        $zero, 0x8e($s2)
/* EA1050 80240750 34420102 */  ori       $v0, $v0, 0x102
/* EA1054 80240754 AE420000 */  sw        $v0, ($s2)
/* EA1058 80240758 8E220000 */  lw        $v0, ($s1)
/* EA105C 8024075C 3C01C47A */  lui       $at, 0xc47a
/* EA1060 80240760 44810000 */  mtc1      $at, $f0
/* EA1064 80240764 00431025 */  or        $v0, $v0, $v1
/* EA1068 80240768 AE220000 */  sw        $v0, ($s1)
/* EA106C 8024076C AE400038 */  sw        $zero, 0x38($s2)
/* EA1070 80240770 E640003C */  swc1      $f0, 0x3c($s2)
/* EA1074 80240774 AE400040 */  sw        $zero, 0x40($s2)
/* EA1078 80240778 8E2300B0 */  lw        $v1, 0xb0($s1)
/* EA107C 8024077C 30620004 */  andi      $v0, $v1, 4
/* EA1080 80240780 10400003 */  beqz      $v0, .L80240790
/* EA1084 80240784 2402FFFB */   addiu    $v0, $zero, -5
/* EA1088 80240788 00621024 */  and       $v0, $v1, $v0
/* EA108C 8024078C AE2200B0 */  sw        $v0, 0xb0($s1)
.L80240790:
/* EA1090 80240790 8E930070 */  lw        $s3, 0x70($s4)
/* EA1094 80240794 12600005 */  beqz      $s3, .L802407AC
/* EA1098 80240798 24020001 */   addiu    $v0, $zero, 1
/* EA109C 8024079C 12620048 */  beq       $s3, $v0, .L802408C0
/* EA10A0 802407A0 00000000 */   nop
/* EA10A4 802407A4 0809024D */  j         .L80240934
/* EA10A8 802407A8 00000000 */   nop
.L802407AC:
/* EA10AC 802407AC 86240008 */  lh        $a0, 8($s1)
/* EA10B0 802407B0 0C010ABD */  jal       dead_get_enemy
/* EA10B4 802407B4 2484FFFF */   addiu    $a0, $a0, -1
/* EA10B8 802407B8 0040802D */  daddu     $s0, $v0, $zero
/* EA10BC 802407BC 0C00F92F */  jal       dead_get_npc_unsafe
/* EA10C0 802407C0 86040008 */   lh       $a0, 8($s0)
/* EA10C4 802407C4 24030001 */  addiu     $v1, $zero, 1
/* EA10C8 802407C8 0040982D */  daddu     $s3, $v0, $zero
/* EA10CC 802407CC A2230007 */  sb        $v1, 7($s1)
/* EA10D0 802407D0 8E03006C */  lw        $v1, 0x6c($s0)
/* EA10D4 802407D4 24020003 */  addiu     $v0, $zero, 3
/* EA10D8 802407D8 14620056 */  bne       $v1, $v0, .L80240934
/* EA10DC 802407DC 00000000 */   nop
/* EA10E0 802407E0 8E2500A8 */  lw        $a1, 0xa8($s1)
/* EA10E4 802407E4 10A00003 */  beqz      $a1, .L802407F4
/* EA10E8 802407E8 0260202D */   daddu    $a0, $s3, $zero
/* EA10EC 802407EC 0C013600 */  jal       dead_ai_enemy_play_sound
/* EA10F0 802407F0 0000302D */   daddu    $a2, $zero, $zero
.L802407F4:
/* EA10F4 802407F4 27A40010 */  addiu     $a0, $sp, 0x10
/* EA10F8 802407F8 C6280070 */  lwc1      $f8, 0x70($s1)
/* EA10FC 802407FC 46804220 */  cvt.s.w   $f8, $f8
/* EA1100 80240800 C6620034 */  lwc1      $f2, 0x34($s3)
/* EA1104 80240804 3C014387 */  lui       $at, 0x4387
/* EA1108 80240808 44810000 */  mtc1      $at, $f0
/* EA110C 8024080C 44064000 */  mfc1      $a2, $f8
/* EA1110 80240810 46020001 */  sub.s     $f0, $f0, $f2
/* EA1114 80240814 C6660038 */  lwc1      $f6, 0x38($s3)
/* EA1118 80240818 C6640040 */  lwc1      $f4, 0x40($s3)
/* EA111C 8024081C 44070000 */  mfc1      $a3, $f0
/* EA1120 80240820 27A50014 */  addiu     $a1, $sp, 0x14
/* EA1124 80240824 E7A60010 */  swc1      $f6, 0x10($sp)
/* EA1128 80240828 0C00ACA3 */  jal       dead_add_vec2D_polar
/* EA112C 8024082C E7A40014 */   swc1     $f4, 0x14($sp)
/* EA1130 80240830 C7A00010 */  lwc1      $f0, 0x10($sp)
/* EA1134 80240834 4600020D */  trunc.w.s $f8, $f0
/* EA1138 80240838 44024000 */  mfc1      $v0, $f8
/* EA113C 8024083C E6400038 */  swc1      $f0, 0x38($s2)
/* EA1140 80240840 A6220010 */  sh        $v0, 0x10($s1)
/* EA1144 80240844 C660003C */  lwc1      $f0, 0x3c($s3)
/* EA1148 80240848 C622006C */  lwc1      $f2, 0x6c($s1)
/* EA114C 8024084C 468010A0 */  cvt.s.w   $f2, $f2
/* EA1150 80240850 46020000 */  add.s     $f0, $f0, $f2
/* EA1154 80240854 3C038010 */  lui       $v1, %hi(dead_gPlayerStatusPtr)
/* EA1158 80240858 8C63FC90 */  lw        $v1, %lo(dead_gPlayerStatusPtr)($v1)
/* EA115C 8024085C E640003C */  swc1      $f0, 0x3c($s2)
/* EA1160 80240860 C7A20014 */  lwc1      $f2, 0x14($sp)
/* EA1164 80240864 4600020D */  trunc.w.s $f8, $f0
/* EA1168 80240868 44024000 */  mfc1      $v0, $f8
/* EA116C 8024086C 00000000 */  nop
/* EA1170 80240870 A6220012 */  sh        $v0, 0x12($s1)
/* EA1174 80240874 4600120D */  trunc.w.s $f8, $f2
/* EA1178 80240878 44024000 */  mfc1      $v0, $f8
/* EA117C 8024087C E6420040 */  swc1      $f2, 0x40($s2)
/* EA1180 80240880 A6220014 */  sh        $v0, 0x14($s1)
/* EA1184 80240884 8C660028 */  lw        $a2, 0x28($v1)
/* EA1188 80240888 8C670030 */  lw        $a3, 0x30($v1)
/* EA118C 8024088C C64C0038 */  lwc1      $f12, 0x38($s2)
/* EA1190 80240890 0C00ABDC */  jal       fio_validate_header_checksums
/* EA1194 80240894 C64E0040 */   lwc1     $f14, 0x40($s2)
/* EA1198 80240898 3C03E0EF */  lui       $v1, 0xe0ef
/* EA119C 8024089C E640000C */  swc1      $f0, 0xc($s2)
/* EA11A0 802408A0 8E220000 */  lw        $v0, ($s1)
/* EA11A4 802408A4 3463FFFF */  ori       $v1, $v1, 0xffff
/* EA11A8 802408A8 00431024 */  and       $v0, $v0, $v1
/* EA11AC 802408AC AE220000 */  sw        $v0, ($s1)
/* EA11B0 802408B0 24020001 */  addiu     $v0, $zero, 1
/* EA11B4 802408B4 A640008E */  sh        $zero, 0x8e($s2)
/* EA11B8 802408B8 0809024D */  j         .L80240934
/* EA11BC 802408BC AE820070 */   sw       $v0, 0x70($s4)
.L802408C0:
/* EA11C0 802408C0 86240008 */  lh        $a0, 8($s1)
/* EA11C4 802408C4 0C010ABD */  jal       dead_get_enemy
/* EA11C8 802408C8 2484FFFF */   addiu    $a0, $a0, -1
/* EA11CC 802408CC 0040802D */  daddu     $s0, $v0, $zero
/* EA11D0 802408D0 0C00F92F */  jal       dead_get_npc_unsafe
/* EA11D4 802408D4 86040008 */   lh       $a0, 8($s0)
/* EA11D8 802408D8 9642008E */  lhu       $v0, 0x8e($s2)
/* EA11DC 802408DC 24420001 */  addiu     $v0, $v0, 1
/* EA11E0 802408E0 A642008E */  sh        $v0, 0x8e($s2)
/* EA11E4 802408E4 00021400 */  sll       $v0, $v0, 0x10
/* EA11E8 802408E8 8E23007C */  lw        $v1, 0x7c($s1)
/* EA11EC 802408EC 00021403 */  sra       $v0, $v0, 0x10
/* EA11F0 802408F0 0043102A */  slt       $v0, $v0, $v1
/* EA11F4 802408F4 50400001 */  beql      $v0, $zero, .L802408FC
/* EA11F8 802408F8 A2200007 */   sb       $zero, 7($s1)
.L802408FC:
/* EA11FC 802408FC 8E03006C */  lw        $v1, 0x6c($s0)
/* EA1200 80240900 24020004 */  addiu     $v0, $zero, 4
/* EA1204 80240904 1462000B */  bne       $v1, $v0, .L80240934
/* EA1208 80240908 3C021F10 */   lui      $v0, 0x1f10
/* EA120C 8024090C 8E230000 */  lw        $v1, ($s1)
/* EA1210 80240910 3C01C47A */  lui       $at, 0xc47a
/* EA1214 80240914 44810000 */  mtc1      $at, $f0
/* EA1218 80240918 00621825 */  or        $v1, $v1, $v0
/* EA121C 8024091C AE230000 */  sw        $v1, ($s1)
/* EA1220 80240920 AE400038 */  sw        $zero, 0x38($s2)
/* EA1224 80240924 E640003C */  swc1      $f0, 0x3c($s2)
/* EA1228 80240928 AE400040 */  sw        $zero, 0x40($s2)
/* EA122C 8024092C A2330007 */  sb        $s3, 7($s1)
/* EA1230 80240930 AE800070 */  sw        $zero, 0x70($s4)
.L80240934:
/* EA1234 80240934 82220007 */  lb        $v0, 7($s1)
/* EA1238 80240938 10400007 */  beqz      $v0, .L80240958
/* EA123C 8024093C 00000000 */   nop
/* EA1240 80240940 3C0140E0 */  lui       $at, 0x40e0
/* EA1244 80240944 44810000 */  mtc1      $at, $f0
/* EA1248 80240948 3C013F80 */  lui       $at, 0x3f80
/* EA124C 8024094C 44811000 */  mtc1      $at, $f2
/* EA1250 80240950 E6200114 */  swc1      $f0, 0x114($s1)
/* EA1254 80240954 E6220118 */  swc1      $f2, 0x118($s1)
.L80240958:
/* EA1258 80240958 8FBF002C */  lw        $ra, 0x2c($sp)
/* EA125C 8024095C 8FB40028 */  lw        $s4, 0x28($sp)
/* EA1260 80240960 8FB30024 */  lw        $s3, 0x24($sp)
/* EA1264 80240964 8FB20020 */  lw        $s2, 0x20($sp)
/* EA1268 80240968 8FB1001C */  lw        $s1, 0x1c($sp)
/* EA126C 8024096C 8FB00018 */  lw        $s0, 0x18($sp)
/* EA1270 80240970 0000102D */  daddu     $v0, $zero, $zero
/* EA1274 80240974 03E00008 */  jr        $ra
/* EA1278 80240978 27BD0030 */   addiu    $sp, $sp, 0x30
