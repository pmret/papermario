.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802410D4_C2FC74
/* C2FC74 802410D4 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* C2FC78 802410D8 AFB20038 */  sw        $s2, 0x38($sp)
/* C2FC7C 802410DC 0080902D */  daddu     $s2, $a0, $zero
/* C2FC80 802410E0 AFBF0048 */  sw        $ra, 0x48($sp)
/* C2FC84 802410E4 AFB50044 */  sw        $s5, 0x44($sp)
/* C2FC88 802410E8 AFB40040 */  sw        $s4, 0x40($sp)
/* C2FC8C 802410EC AFB3003C */  sw        $s3, 0x3c($sp)
/* C2FC90 802410F0 AFB10034 */  sw        $s1, 0x34($sp)
/* C2FC94 802410F4 AFB00030 */  sw        $s0, 0x30($sp)
/* C2FC98 802410F8 8E510148 */  lw        $s1, 0x148($s2)
/* C2FC9C 802410FC 86240008 */  lh        $a0, 8($s1)
/* C2FCA0 80241100 0C00EABB */  jal       get_npc_unsafe
/* C2FCA4 80241104 00A0802D */   daddu    $s0, $a1, $zero
/* C2FCA8 80241108 8E43000C */  lw        $v1, 0xc($s2)
/* C2FCAC 8024110C 0240202D */  daddu     $a0, $s2, $zero
/* C2FCB0 80241110 8C650000 */  lw        $a1, ($v1)
/* C2FCB4 80241114 0C0B1EAF */  jal       get_variable
/* C2FCB8 80241118 0040A02D */   daddu    $s4, $v0, $zero
/* C2FCBC 8024111C AFA00010 */  sw        $zero, 0x10($sp)
/* C2FCC0 80241120 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C2FCC4 80241124 8C630030 */  lw        $v1, 0x30($v1)
/* C2FCC8 80241128 AFA30014 */  sw        $v1, 0x14($sp)
/* C2FCCC 8024112C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C2FCD0 80241130 8C63001C */  lw        $v1, 0x1c($v1)
/* C2FCD4 80241134 AFA30018 */  sw        $v1, 0x18($sp)
/* C2FCD8 80241138 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C2FCDC 8024113C 8C630024 */  lw        $v1, 0x24($v1)
/* C2FCE0 80241140 AFA3001C */  sw        $v1, 0x1c($sp)
/* C2FCE4 80241144 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C2FCE8 80241148 8C630028 */  lw        $v1, 0x28($v1)
/* C2FCEC 8024114C 27B50010 */  addiu     $s5, $sp, 0x10
/* C2FCF0 80241150 AFA30020 */  sw        $v1, 0x20($sp)
/* C2FCF4 80241154 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C2FCF8 80241158 3C014220 */  lui       $at, 0x4220
/* C2FCFC 8024115C 44810000 */  mtc1      $at, $f0
/* C2FD00 80241160 8C63002C */  lw        $v1, 0x2c($v1)
/* C2FD04 80241164 0040982D */  daddu     $s3, $v0, $zero
/* C2FD08 80241168 E7A00028 */  swc1      $f0, 0x28($sp)
/* C2FD0C 8024116C A7A0002C */  sh        $zero, 0x2c($sp)
/* C2FD10 80241170 16000005 */  bnez      $s0, .L80241188
/* C2FD14 80241174 AFA30024 */   sw       $v1, 0x24($sp)
/* C2FD18 80241178 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C2FD1C 8024117C 30420004 */  andi      $v0, $v0, 4
/* C2FD20 80241180 10400027 */  beqz      $v0, .L80241220
/* C2FD24 80241184 00000000 */   nop      
.L80241188:
/* C2FD28 80241188 2402001E */  addiu     $v0, $zero, 0x1e
/* C2FD2C 8024118C 2404F7FF */  addiu     $a0, $zero, -0x801
/* C2FD30 80241190 AE400070 */  sw        $zero, 0x70($s2)
/* C2FD34 80241194 A682008E */  sh        $v0, 0x8e($s4)
/* C2FD38 80241198 8E2300CC */  lw        $v1, 0xcc($s1)
/* C2FD3C 8024119C 8E820000 */  lw        $v0, ($s4)
/* C2FD40 802411A0 8C630028 */  lw        $v1, 0x28($v1)
/* C2FD44 802411A4 00441024 */  and       $v0, $v0, $a0
/* C2FD48 802411A8 AE820000 */  sw        $v0, ($s4)
/* C2FD4C 802411AC AE830028 */  sw        $v1, 0x28($s4)
/* C2FD50 802411B0 8E2200D0 */  lw        $v0, 0xd0($s1)
/* C2FD54 802411B4 AE20006C */  sw        $zero, 0x6c($s1)
/* C2FD58 802411B8 8C420034 */  lw        $v0, 0x34($v0)
/* C2FD5C 802411BC 14400006 */  bnez      $v0, .L802411D8
/* C2FD60 802411C0 2403FDFF */   addiu    $v1, $zero, -0x201
/* C2FD64 802411C4 8E820000 */  lw        $v0, ($s4)
/* C2FD68 802411C8 2403FFF7 */  addiu     $v1, $zero, -9
/* C2FD6C 802411CC 34420200 */  ori       $v0, $v0, 0x200
/* C2FD70 802411D0 08090479 */  j         .L802411E4
/* C2FD74 802411D4 00431024 */   and      $v0, $v0, $v1
.L802411D8:
/* C2FD78 802411D8 8E820000 */  lw        $v0, ($s4)
/* C2FD7C 802411DC 00431024 */  and       $v0, $v0, $v1
/* C2FD80 802411E0 34420008 */  ori       $v0, $v0, 8
.L802411E4:
/* C2FD84 802411E4 AE820000 */  sw        $v0, ($s4)
/* C2FD88 802411E8 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C2FD8C 802411EC 30420004 */  andi      $v0, $v0, 4
/* C2FD90 802411F0 10400007 */  beqz      $v0, .L80241210
/* C2FD94 802411F4 24020063 */   addiu    $v0, $zero, 0x63
/* C2FD98 802411F8 AE420070 */  sw        $v0, 0x70($s2)
/* C2FD9C 802411FC 24020028 */  addiu     $v0, $zero, 0x28
/* C2FDA0 80241200 AE420074 */  sw        $v0, 0x74($s2)
/* C2FDA4 80241204 8E2200CC */  lw        $v0, 0xcc($s1)
/* C2FDA8 80241208 8C420000 */  lw        $v0, ($v0)
/* C2FDAC 8024120C AE820028 */  sw        $v0, 0x28($s4)
.L80241210:
/* C2FDB0 80241210 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C2FDB4 80241214 2403FFFB */  addiu     $v1, $zero, -5
/* C2FDB8 80241218 00431024 */  and       $v0, $v0, $v1
/* C2FDBC 8024121C AE2200B0 */  sw        $v0, 0xb0($s1)
.L80241220:
/* C2FDC0 80241220 8E420070 */  lw        $v0, 0x70($s2)
/* C2FDC4 80241224 2442FFF6 */  addiu     $v0, $v0, -0xa
/* C2FDC8 80241228 2C420014 */  sltiu     $v0, $v0, 0x14
/* C2FDCC 8024122C 10400009 */  beqz      $v0, .L80241254
/* C2FDD0 80241230 00000000 */   nop      
/* C2FDD4 80241234 8E22006C */  lw        $v0, 0x6c($s1)
/* C2FDD8 80241238 14400006 */  bnez      $v0, .L80241254
/* C2FDDC 8024123C 00000000 */   nop      
/* C2FDE0 80241240 0C090082 */  jal       func_80240208_C2EDA8
/* C2FDE4 80241244 0240202D */   daddu    $a0, $s2, $zero
/* C2FDE8 80241248 10400002 */  beqz      $v0, .L80241254
/* C2FDEC 8024124C 2402001E */   addiu    $v0, $zero, 0x1e
/* C2FDF0 80241250 AE420070 */  sw        $v0, 0x70($s2)
.L80241254:
/* C2FDF4 80241254 8E430070 */  lw        $v1, 0x70($s2)
/* C2FDF8 80241258 2C620064 */  sltiu     $v0, $v1, 0x64
/* C2FDFC 8024125C 10400067 */  beqz      $v0, .L802413FC
/* C2FE00 80241260 00031080 */   sll      $v0, $v1, 2
/* C2FE04 80241264 3C018024 */  lui       $at, 0x8024
/* C2FE08 80241268 00220821 */  addu      $at, $at, $v0
/* C2FE0C 8024126C 8C2227B0 */  lw        $v0, 0x27b0($at)
/* C2FE10 80241270 00400008 */  jr        $v0
/* C2FE14 80241274 00000000 */   nop      
/* C2FE18 80241278 0240202D */  daddu     $a0, $s2, $zero
/* C2FE1C 8024127C 0260282D */  daddu     $a1, $s3, $zero
/* C2FE20 80241280 0C090234 */  jal       func_802408D0_C2F470
/* C2FE24 80241284 02A0302D */   daddu    $a2, $s5, $zero
/* C2FE28 80241288 080904FF */  j         .L802413FC
/* C2FE2C 8024128C 00000000 */   nop      
/* C2FE30 80241290 0240202D */  daddu     $a0, $s2, $zero
/* C2FE34 80241294 0260282D */  daddu     $a1, $s3, $zero
/* C2FE38 80241298 0C090256 */  jal       func_80240958_C2F4F8
/* C2FE3C 8024129C 02A0302D */   daddu    $a2, $s5, $zero
/* C2FE40 802412A0 080904FF */  j         .L802413FC
/* C2FE44 802412A4 00000000 */   nop      
/* C2FE48 802412A8 0240202D */  daddu     $a0, $s2, $zero
/* C2FE4C 802412AC 0260282D */  daddu     $a1, $s3, $zero
/* C2FE50 802412B0 0C090304 */  jal       func_80240C10_C2F7B0
/* C2FE54 802412B4 02A0302D */   daddu    $a2, $s5, $zero
/* C2FE58 802412B8 080904FF */  j         .L802413FC
/* C2FE5C 802412BC 00000000 */   nop      
/* C2FE60 802412C0 0240202D */  daddu     $a0, $s2, $zero
/* C2FE64 802412C4 0260282D */  daddu     $a1, $s3, $zero
/* C2FE68 802412C8 0C09031D */  jal       func_80240C74_C2F814
/* C2FE6C 802412CC 02A0302D */   daddu    $a2, $s5, $zero
/* C2FE70 802412D0 080904FF */  j         .L802413FC
/* C2FE74 802412D4 00000000 */   nop      
/* C2FE78 802412D8 0240202D */  daddu     $a0, $s2, $zero
/* C2FE7C 802412DC 0260282D */  daddu     $a1, $s3, $zero
/* C2FE80 802412E0 0C090347 */  jal       func_80240D1C_C2F8BC
/* C2FE84 802412E4 02A0302D */   daddu    $a2, $s5, $zero
/* C2FE88 802412E8 080904FF */  j         .L802413FC
/* C2FE8C 802412EC 00000000 */   nop      
/* C2FE90 802412F0 0240202D */  daddu     $a0, $s2, $zero
/* C2FE94 802412F4 0260282D */  daddu     $a1, $s3, $zero
/* C2FE98 802412F8 0C0127DF */  jal       func_80049F7C
/* C2FE9C 802412FC 02A0302D */   daddu    $a2, $s5, $zero
/* C2FEA0 80241300 8E430070 */  lw        $v1, 0x70($s2)
/* C2FEA4 80241304 2402000D */  addiu     $v0, $zero, 0xd
/* C2FEA8 80241308 1462003C */  bne       $v1, $v0, .L802413FC
/* C2FEAC 8024130C 00000000 */   nop      
/* C2FEB0 80241310 0240202D */  daddu     $a0, $s2, $zero
/* C2FEB4 80241314 0260282D */  daddu     $a1, $s3, $zero
/* C2FEB8 80241318 0C012849 */  jal       func_8004A124
/* C2FEBC 8024131C 02A0302D */   daddu    $a2, $s5, $zero
/* C2FEC0 80241320 080904FF */  j         .L802413FC
/* C2FEC4 80241324 00000000 */   nop      
/* C2FEC8 80241328 0240202D */  daddu     $a0, $s2, $zero
/* C2FECC 8024132C 0260282D */  daddu     $a1, $s3, $zero
/* C2FED0 80241330 0C0128FA */  jal       func_8004A3E8
/* C2FED4 80241334 02A0302D */   daddu    $a2, $s5, $zero
/* C2FED8 80241338 2402000F */  addiu     $v0, $zero, 0xf
/* C2FEDC 8024133C A682008E */  sh        $v0, 0x8e($s4)
/* C2FEE0 80241340 24020028 */  addiu     $v0, $zero, 0x28
/* C2FEE4 80241344 AE220088 */  sw        $v0, 0x88($s1)
/* C2FEE8 80241348 24020003 */  addiu     $v0, $zero, 3
/* C2FEEC 8024134C 080904FF */  j         .L802413FC
/* C2FEF0 80241350 AE420070 */   sw       $v0, 0x70($s2)
/* C2FEF4 80241354 0C090000 */  jal       UnkNpcAIFunc6
/* C2FEF8 80241358 0240202D */   daddu    $a0, $s2, $zero
/* C2FEFC 8024135C 8E430070 */  lw        $v1, 0x70($s2)
/* C2FF00 80241360 2402001F */  addiu     $v0, $zero, 0x1f
/* C2FF04 80241364 14620025 */  bne       $v1, $v0, .L802413FC
/* C2FF08 80241368 00000000 */   nop      
/* C2FF0C 8024136C 0C09001B */  jal       UnkNpcAIFunc7
/* C2FF10 80241370 0240202D */   daddu    $a0, $s2, $zero
/* C2FF14 80241374 8E430070 */  lw        $v1, 0x70($s2)
/* C2FF18 80241378 24020020 */  addiu     $v0, $zero, 0x20
/* C2FF1C 8024137C 1462001F */  bne       $v1, $v0, .L802413FC
/* C2FF20 80241380 00000000 */   nop      
/* C2FF24 80241384 0C090037 */  jal       func_802400DC_C2EC7C
/* C2FF28 80241388 0240202D */   daddu    $a0, $s2, $zero
/* C2FF2C 8024138C 080904FF */  j         .L802413FC
/* C2FF30 80241390 00000000 */   nop      
/* C2FF34 80241394 0C09006D */  jal       UnkNpcAIFunc5
/* C2FF38 80241398 0240202D */   daddu    $a0, $s2, $zero
/* C2FF3C 8024139C 080904FF */  j         .L802413FC
/* C2FF40 802413A0 00000000 */   nop      
/* C2FF44 802413A4 0240202D */  daddu     $a0, $s2, $zero
/* C2FF48 802413A8 0260282D */  daddu     $a1, $s3, $zero
/* C2FF4C 802413AC 0C090395 */  jal       func_80240E54_C2F9F4
/* C2FF50 802413B0 02A0302D */   daddu    $a2, $s5, $zero
/* C2FF54 802413B4 8E430070 */  lw        $v1, 0x70($s2)
/* C2FF58 802413B8 24020029 */  addiu     $v0, $zero, 0x29
/* C2FF5C 802413BC 1462000F */  bne       $v1, $v0, .L802413FC
/* C2FF60 802413C0 00000000 */   nop      
/* C2FF64 802413C4 0240202D */  daddu     $a0, $s2, $zero
/* C2FF68 802413C8 0260282D */  daddu     $a1, $s3, $zero
/* C2FF6C 802413CC 0C0903C0 */  jal       func_80240F00_C2FAA0
/* C2FF70 802413D0 02A0302D */   daddu    $a2, $s5, $zero
/* C2FF74 802413D4 080904FF */  j         .L802413FC
/* C2FF78 802413D8 00000000 */   nop      
/* C2FF7C 802413DC 0240202D */  daddu     $a0, $s2, $zero
/* C2FF80 802413E0 0260282D */  daddu     $a1, $s3, $zero
/* C2FF84 802413E4 0C09041E */  jal       func_80241078_C2FC18
/* C2FF88 802413E8 02A0302D */   daddu    $a2, $s5, $zero
/* C2FF8C 802413EC 080904FF */  j         .L802413FC
/* C2FF90 802413F0 00000000 */   nop      
/* C2FF94 802413F4 0C0129CF */  jal       func_8004A73C
/* C2FF98 802413F8 0240202D */   daddu    $a0, $s2, $zero
.L802413FC:
/* C2FF9C 802413FC 8FBF0048 */  lw        $ra, 0x48($sp)
/* C2FFA0 80241400 8FB50044 */  lw        $s5, 0x44($sp)
/* C2FFA4 80241404 8FB40040 */  lw        $s4, 0x40($sp)
/* C2FFA8 80241408 8FB3003C */  lw        $s3, 0x3c($sp)
/* C2FFAC 8024140C 8FB20038 */  lw        $s2, 0x38($sp)
/* C2FFB0 80241410 8FB10034 */  lw        $s1, 0x34($sp)
/* C2FFB4 80241414 8FB00030 */  lw        $s0, 0x30($sp)
/* C2FFB8 80241418 0000102D */  daddu     $v0, $zero, $zero
/* C2FFBC 8024141C 03E00008 */  jr        $ra
/* C2FFC0 80241420 27BD0050 */   addiu    $sp, $sp, 0x50
/* C2FFC4 80241424 00000000 */  nop       
/* C2FFC8 80241428 00000000 */  nop       
/* C2FFCC 8024142C 00000000 */  nop       
