.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802410D4_C47CB4
/* C47CB4 802410D4 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* C47CB8 802410D8 AFB20038 */  sw        $s2, 0x38($sp)
/* C47CBC 802410DC 0080902D */  daddu     $s2, $a0, $zero
/* C47CC0 802410E0 AFBF0048 */  sw        $ra, 0x48($sp)
/* C47CC4 802410E4 AFB50044 */  sw        $s5, 0x44($sp)
/* C47CC8 802410E8 AFB40040 */  sw        $s4, 0x40($sp)
/* C47CCC 802410EC AFB3003C */  sw        $s3, 0x3c($sp)
/* C47CD0 802410F0 AFB10034 */  sw        $s1, 0x34($sp)
/* C47CD4 802410F4 AFB00030 */  sw        $s0, 0x30($sp)
/* C47CD8 802410F8 8E510148 */  lw        $s1, 0x148($s2)
/* C47CDC 802410FC 86240008 */  lh        $a0, 8($s1)
/* C47CE0 80241100 0C00EABB */  jal       get_npc_unsafe
/* C47CE4 80241104 00A0802D */   daddu    $s0, $a1, $zero
/* C47CE8 80241108 8E43000C */  lw        $v1, 0xc($s2)
/* C47CEC 8024110C 0240202D */  daddu     $a0, $s2, $zero
/* C47CF0 80241110 8C650000 */  lw        $a1, ($v1)
/* C47CF4 80241114 0C0B1EAF */  jal       get_variable
/* C47CF8 80241118 0040A02D */   daddu    $s4, $v0, $zero
/* C47CFC 8024111C AFA00010 */  sw        $zero, 0x10($sp)
/* C47D00 80241120 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C47D04 80241124 8C630030 */  lw        $v1, 0x30($v1)
/* C47D08 80241128 AFA30014 */  sw        $v1, 0x14($sp)
/* C47D0C 8024112C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C47D10 80241130 8C63001C */  lw        $v1, 0x1c($v1)
/* C47D14 80241134 AFA30018 */  sw        $v1, 0x18($sp)
/* C47D18 80241138 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C47D1C 8024113C 8C630024 */  lw        $v1, 0x24($v1)
/* C47D20 80241140 AFA3001C */  sw        $v1, 0x1c($sp)
/* C47D24 80241144 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C47D28 80241148 8C630028 */  lw        $v1, 0x28($v1)
/* C47D2C 8024114C 27B50010 */  addiu     $s5, $sp, 0x10
/* C47D30 80241150 AFA30020 */  sw        $v1, 0x20($sp)
/* C47D34 80241154 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C47D38 80241158 3C014220 */  lui       $at, 0x4220
/* C47D3C 8024115C 44810000 */  mtc1      $at, $f0
/* C47D40 80241160 8C63002C */  lw        $v1, 0x2c($v1)
/* C47D44 80241164 0040982D */  daddu     $s3, $v0, $zero
/* C47D48 80241168 E7A00028 */  swc1      $f0, 0x28($sp)
/* C47D4C 8024116C A7A0002C */  sh        $zero, 0x2c($sp)
/* C47D50 80241170 16000005 */  bnez      $s0, .L80241188
/* C47D54 80241174 AFA30024 */   sw       $v1, 0x24($sp)
/* C47D58 80241178 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C47D5C 8024117C 30420004 */  andi      $v0, $v0, 4
/* C47D60 80241180 10400027 */  beqz      $v0, .L80241220
/* C47D64 80241184 00000000 */   nop      
.L80241188:
/* C47D68 80241188 2402001E */  addiu     $v0, $zero, 0x1e
/* C47D6C 8024118C 2404F7FF */  addiu     $a0, $zero, -0x801
/* C47D70 80241190 AE400070 */  sw        $zero, 0x70($s2)
/* C47D74 80241194 A682008E */  sh        $v0, 0x8e($s4)
/* C47D78 80241198 8E2300CC */  lw        $v1, 0xcc($s1)
/* C47D7C 8024119C 8E820000 */  lw        $v0, ($s4)
/* C47D80 802411A0 8C630028 */  lw        $v1, 0x28($v1)
/* C47D84 802411A4 00441024 */  and       $v0, $v0, $a0
/* C47D88 802411A8 AE820000 */  sw        $v0, ($s4)
/* C47D8C 802411AC AE830028 */  sw        $v1, 0x28($s4)
/* C47D90 802411B0 8E2200D0 */  lw        $v0, 0xd0($s1)
/* C47D94 802411B4 AE20006C */  sw        $zero, 0x6c($s1)
/* C47D98 802411B8 8C420034 */  lw        $v0, 0x34($v0)
/* C47D9C 802411BC 14400006 */  bnez      $v0, .L802411D8
/* C47DA0 802411C0 2403FDFF */   addiu    $v1, $zero, -0x201
/* C47DA4 802411C4 8E820000 */  lw        $v0, ($s4)
/* C47DA8 802411C8 2403FFF7 */  addiu     $v1, $zero, -9
/* C47DAC 802411CC 34420200 */  ori       $v0, $v0, 0x200
/* C47DB0 802411D0 08090479 */  j         .L802411E4
/* C47DB4 802411D4 00431024 */   and      $v0, $v0, $v1
.L802411D8:
/* C47DB8 802411D8 8E820000 */  lw        $v0, ($s4)
/* C47DBC 802411DC 00431024 */  and       $v0, $v0, $v1
/* C47DC0 802411E0 34420008 */  ori       $v0, $v0, 8
.L802411E4:
/* C47DC4 802411E4 AE820000 */  sw        $v0, ($s4)
/* C47DC8 802411E8 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C47DCC 802411EC 30420004 */  andi      $v0, $v0, 4
/* C47DD0 802411F0 10400007 */  beqz      $v0, .L80241210
/* C47DD4 802411F4 24020063 */   addiu    $v0, $zero, 0x63
/* C47DD8 802411F8 AE420070 */  sw        $v0, 0x70($s2)
/* C47DDC 802411FC 24020028 */  addiu     $v0, $zero, 0x28
/* C47DE0 80241200 AE420074 */  sw        $v0, 0x74($s2)
/* C47DE4 80241204 8E2200CC */  lw        $v0, 0xcc($s1)
/* C47DE8 80241208 8C420000 */  lw        $v0, ($v0)
/* C47DEC 8024120C AE820028 */  sw        $v0, 0x28($s4)
.L80241210:
/* C47DF0 80241210 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C47DF4 80241214 2403FFFB */  addiu     $v1, $zero, -5
/* C47DF8 80241218 00431024 */  and       $v0, $v0, $v1
/* C47DFC 8024121C AE2200B0 */  sw        $v0, 0xb0($s1)
.L80241220:
/* C47E00 80241220 8E420070 */  lw        $v0, 0x70($s2)
/* C47E04 80241224 2442FFF6 */  addiu     $v0, $v0, -0xa
/* C47E08 80241228 2C420014 */  sltiu     $v0, $v0, 0x14
/* C47E0C 8024122C 10400009 */  beqz      $v0, .L80241254
/* C47E10 80241230 00000000 */   nop      
/* C47E14 80241234 8E22006C */  lw        $v0, 0x6c($s1)
/* C47E18 80241238 14400006 */  bnez      $v0, .L80241254
/* C47E1C 8024123C 00000000 */   nop      
/* C47E20 80241240 0C090082 */  jal       func_80240208_C46DE8
/* C47E24 80241244 0240202D */   daddu    $a0, $s2, $zero
/* C47E28 80241248 10400002 */  beqz      $v0, .L80241254
/* C47E2C 8024124C 2402001E */   addiu    $v0, $zero, 0x1e
/* C47E30 80241250 AE420070 */  sw        $v0, 0x70($s2)
.L80241254:
/* C47E34 80241254 8E430070 */  lw        $v1, 0x70($s2)
/* C47E38 80241258 2C620064 */  sltiu     $v0, $v1, 0x64
/* C47E3C 8024125C 10400067 */  beqz      $v0, .L802413FC
/* C47E40 80241260 00031080 */   sll      $v0, $v1, 2
/* C47E44 80241264 3C018024 */  lui       $at, 0x8024
/* C47E48 80241268 00220821 */  addu      $at, $at, $v0
/* C47E4C 8024126C 8C225530 */  lw        $v0, 0x5530($at)
/* C47E50 80241270 00400008 */  jr        $v0
/* C47E54 80241274 00000000 */   nop      
/* C47E58 80241278 0240202D */  daddu     $a0, $s2, $zero
/* C47E5C 8024127C 0260282D */  daddu     $a1, $s3, $zero
/* C47E60 80241280 0C090234 */  jal       func_802408D0_C474B0
/* C47E64 80241284 02A0302D */   daddu    $a2, $s5, $zero
/* C47E68 80241288 080904FF */  j         .L802413FC
/* C47E6C 8024128C 00000000 */   nop      
/* C47E70 80241290 0240202D */  daddu     $a0, $s2, $zero
/* C47E74 80241294 0260282D */  daddu     $a1, $s3, $zero
/* C47E78 80241298 0C090256 */  jal       func_80240958_C47538
/* C47E7C 8024129C 02A0302D */   daddu    $a2, $s5, $zero
/* C47E80 802412A0 080904FF */  j         .L802413FC
/* C47E84 802412A4 00000000 */   nop      
/* C47E88 802412A8 0240202D */  daddu     $a0, $s2, $zero
/* C47E8C 802412AC 0260282D */  daddu     $a1, $s3, $zero
/* C47E90 802412B0 0C090304 */  jal       func_80240C10_C477F0
/* C47E94 802412B4 02A0302D */   daddu    $a2, $s5, $zero
/* C47E98 802412B8 080904FF */  j         .L802413FC
/* C47E9C 802412BC 00000000 */   nop      
/* C47EA0 802412C0 0240202D */  daddu     $a0, $s2, $zero
/* C47EA4 802412C4 0260282D */  daddu     $a1, $s3, $zero
/* C47EA8 802412C8 0C09031D */  jal       func_80240C74_C47854
/* C47EAC 802412CC 02A0302D */   daddu    $a2, $s5, $zero
/* C47EB0 802412D0 080904FF */  j         .L802413FC
/* C47EB4 802412D4 00000000 */   nop      
/* C47EB8 802412D8 0240202D */  daddu     $a0, $s2, $zero
/* C47EBC 802412DC 0260282D */  daddu     $a1, $s3, $zero
/* C47EC0 802412E0 0C090347 */  jal       func_80240D1C_C478FC
/* C47EC4 802412E4 02A0302D */   daddu    $a2, $s5, $zero
/* C47EC8 802412E8 080904FF */  j         .L802413FC
/* C47ECC 802412EC 00000000 */   nop      
/* C47ED0 802412F0 0240202D */  daddu     $a0, $s2, $zero
/* C47ED4 802412F4 0260282D */  daddu     $a1, $s3, $zero
/* C47ED8 802412F8 0C0127DF */  jal       func_80049F7C
/* C47EDC 802412FC 02A0302D */   daddu    $a2, $s5, $zero
/* C47EE0 80241300 8E430070 */  lw        $v1, 0x70($s2)
/* C47EE4 80241304 2402000D */  addiu     $v0, $zero, 0xd
/* C47EE8 80241308 1462003C */  bne       $v1, $v0, .L802413FC
/* C47EEC 8024130C 00000000 */   nop      
/* C47EF0 80241310 0240202D */  daddu     $a0, $s2, $zero
/* C47EF4 80241314 0260282D */  daddu     $a1, $s3, $zero
/* C47EF8 80241318 0C012849 */  jal       func_8004A124
/* C47EFC 8024131C 02A0302D */   daddu    $a2, $s5, $zero
/* C47F00 80241320 080904FF */  j         .L802413FC
/* C47F04 80241324 00000000 */   nop      
/* C47F08 80241328 0240202D */  daddu     $a0, $s2, $zero
/* C47F0C 8024132C 0260282D */  daddu     $a1, $s3, $zero
/* C47F10 80241330 0C0128FA */  jal       func_8004A3E8
/* C47F14 80241334 02A0302D */   daddu    $a2, $s5, $zero
/* C47F18 80241338 2402000F */  addiu     $v0, $zero, 0xf
/* C47F1C 8024133C A682008E */  sh        $v0, 0x8e($s4)
/* C47F20 80241340 24020028 */  addiu     $v0, $zero, 0x28
/* C47F24 80241344 AE220088 */  sw        $v0, 0x88($s1)
/* C47F28 80241348 24020003 */  addiu     $v0, $zero, 3
/* C47F2C 8024134C 080904FF */  j         .L802413FC
/* C47F30 80241350 AE420070 */   sw       $v0, 0x70($s2)
/* C47F34 80241354 0C090000 */  jal       UnkNpcAIFunc6
/* C47F38 80241358 0240202D */   daddu    $a0, $s2, $zero
/* C47F3C 8024135C 8E430070 */  lw        $v1, 0x70($s2)
/* C47F40 80241360 2402001F */  addiu     $v0, $zero, 0x1f
/* C47F44 80241364 14620025 */  bne       $v1, $v0, .L802413FC
/* C47F48 80241368 00000000 */   nop      
/* C47F4C 8024136C 0C09001B */  jal       UnkNpcAIFunc7
/* C47F50 80241370 0240202D */   daddu    $a0, $s2, $zero
/* C47F54 80241374 8E430070 */  lw        $v1, 0x70($s2)
/* C47F58 80241378 24020020 */  addiu     $v0, $zero, 0x20
/* C47F5C 8024137C 1462001F */  bne       $v1, $v0, .L802413FC
/* C47F60 80241380 00000000 */   nop      
/* C47F64 80241384 0C090037 */  jal       func_802400DC_C46CBC
/* C47F68 80241388 0240202D */   daddu    $a0, $s2, $zero
/* C47F6C 8024138C 080904FF */  j         .L802413FC
/* C47F70 80241390 00000000 */   nop      
/* C47F74 80241394 0C09006D */  jal       UnkNpcAIFunc5
/* C47F78 80241398 0240202D */   daddu    $a0, $s2, $zero
/* C47F7C 8024139C 080904FF */  j         .L802413FC
/* C47F80 802413A0 00000000 */   nop      
/* C47F84 802413A4 0240202D */  daddu     $a0, $s2, $zero
/* C47F88 802413A8 0260282D */  daddu     $a1, $s3, $zero
/* C47F8C 802413AC 0C090395 */  jal       func_80240E54_C47A34
/* C47F90 802413B0 02A0302D */   daddu    $a2, $s5, $zero
/* C47F94 802413B4 8E430070 */  lw        $v1, 0x70($s2)
/* C47F98 802413B8 24020029 */  addiu     $v0, $zero, 0x29
/* C47F9C 802413BC 1462000F */  bne       $v1, $v0, .L802413FC
/* C47FA0 802413C0 00000000 */   nop      
/* C47FA4 802413C4 0240202D */  daddu     $a0, $s2, $zero
/* C47FA8 802413C8 0260282D */  daddu     $a1, $s3, $zero
/* C47FAC 802413CC 0C0903C0 */  jal       func_80240F00_C47AE0
/* C47FB0 802413D0 02A0302D */   daddu    $a2, $s5, $zero
/* C47FB4 802413D4 080904FF */  j         .L802413FC
/* C47FB8 802413D8 00000000 */   nop      
/* C47FBC 802413DC 0240202D */  daddu     $a0, $s2, $zero
/* C47FC0 802413E0 0260282D */  daddu     $a1, $s3, $zero
/* C47FC4 802413E4 0C09041E */  jal       func_80241078_C47C58
/* C47FC8 802413E8 02A0302D */   daddu    $a2, $s5, $zero
/* C47FCC 802413EC 080904FF */  j         .L802413FC
/* C47FD0 802413F0 00000000 */   nop      
/* C47FD4 802413F4 0C0129CF */  jal       func_8004A73C
/* C47FD8 802413F8 0240202D */   daddu    $a0, $s2, $zero
.L802413FC:
/* C47FDC 802413FC 8FBF0048 */  lw        $ra, 0x48($sp)
/* C47FE0 80241400 8FB50044 */  lw        $s5, 0x44($sp)
/* C47FE4 80241404 8FB40040 */  lw        $s4, 0x40($sp)
/* C47FE8 80241408 8FB3003C */  lw        $s3, 0x3c($sp)
/* C47FEC 8024140C 8FB20038 */  lw        $s2, 0x38($sp)
/* C47FF0 80241410 8FB10034 */  lw        $s1, 0x34($sp)
/* C47FF4 80241414 8FB00030 */  lw        $s0, 0x30($sp)
/* C47FF8 80241418 0000102D */  daddu     $v0, $zero, $zero
/* C47FFC 8024141C 03E00008 */  jr        $ra
/* C48000 80241420 27BD0050 */   addiu    $sp, $sp, 0x50
