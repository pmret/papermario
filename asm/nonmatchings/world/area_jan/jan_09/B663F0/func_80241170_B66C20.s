.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241170_B66C20
/* B66C20 80241170 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* B66C24 80241174 AFB20038 */  sw        $s2, 0x38($sp)
/* B66C28 80241178 0080902D */  daddu     $s2, $a0, $zero
/* B66C2C 8024117C AFBF0048 */  sw        $ra, 0x48($sp)
/* B66C30 80241180 AFB50044 */  sw        $s5, 0x44($sp)
/* B66C34 80241184 AFB40040 */  sw        $s4, 0x40($sp)
/* B66C38 80241188 AFB3003C */  sw        $s3, 0x3c($sp)
/* B66C3C 8024118C AFB10034 */  sw        $s1, 0x34($sp)
/* B66C40 80241190 AFB00030 */  sw        $s0, 0x30($sp)
/* B66C44 80241194 8E510148 */  lw        $s1, 0x148($s2)
/* B66C48 80241198 86240008 */  lh        $a0, 8($s1)
/* B66C4C 8024119C 0C00EABB */  jal       get_npc_unsafe
/* B66C50 802411A0 00A0802D */   daddu    $s0, $a1, $zero
/* B66C54 802411A4 8E43000C */  lw        $v1, 0xc($s2)
/* B66C58 802411A8 0240202D */  daddu     $a0, $s2, $zero
/* B66C5C 802411AC 8C650000 */  lw        $a1, ($v1)
/* B66C60 802411B0 0C0B1EAF */  jal       get_variable
/* B66C64 802411B4 0040A82D */   daddu    $s5, $v0, $zero
/* B66C68 802411B8 AFA00010 */  sw        $zero, 0x10($sp)
/* B66C6C 802411BC 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B66C70 802411C0 8C630030 */  lw        $v1, 0x30($v1)
/* B66C74 802411C4 AFA30014 */  sw        $v1, 0x14($sp)
/* B66C78 802411C8 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B66C7C 802411CC 8C63001C */  lw        $v1, 0x1c($v1)
/* B66C80 802411D0 AFA30018 */  sw        $v1, 0x18($sp)
/* B66C84 802411D4 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B66C88 802411D8 8C630024 */  lw        $v1, 0x24($v1)
/* B66C8C 802411DC AFA3001C */  sw        $v1, 0x1c($sp)
/* B66C90 802411E0 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B66C94 802411E4 8C630028 */  lw        $v1, 0x28($v1)
/* B66C98 802411E8 27B40010 */  addiu     $s4, $sp, 0x10
/* B66C9C 802411EC AFA30020 */  sw        $v1, 0x20($sp)
/* B66CA0 802411F0 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B66CA4 802411F4 3C014282 */  lui       $at, 0x4282
/* B66CA8 802411F8 44810000 */  mtc1      $at, $f0
/* B66CAC 802411FC 8C63002C */  lw        $v1, 0x2c($v1)
/* B66CB0 80241200 0040982D */  daddu     $s3, $v0, $zero
/* B66CB4 80241204 E7A00028 */  swc1      $f0, 0x28($sp)
/* B66CB8 80241208 A7A0002C */  sh        $zero, 0x2c($sp)
/* B66CBC 8024120C 16000005 */  bnez      $s0, .L80241224
/* B66CC0 80241210 AFA30024 */   sw       $v1, 0x24($sp)
/* B66CC4 80241214 8E2200B0 */  lw        $v0, 0xb0($s1)
/* B66CC8 80241218 30420004 */  andi      $v0, $v0, 4
/* B66CCC 8024121C 10400020 */  beqz      $v0, .L802412A0
/* B66CD0 80241220 00000000 */   nop      
.L80241224:
/* B66CD4 80241224 2404F7FF */  addiu     $a0, $zero, -0x801
/* B66CD8 80241228 AE400070 */  sw        $zero, 0x70($s2)
/* B66CDC 8024122C A6A0008E */  sh        $zero, 0x8e($s5)
/* B66CE0 80241230 8E2200CC */  lw        $v0, 0xcc($s1)
/* B66CE4 80241234 8EA30000 */  lw        $v1, ($s5)
/* B66CE8 80241238 8C420000 */  lw        $v0, ($v0)
/* B66CEC 8024123C 00641824 */  and       $v1, $v1, $a0
/* B66CF0 80241240 AEA30000 */  sw        $v1, ($s5)
/* B66CF4 80241244 AEA20028 */  sw        $v0, 0x28($s5)
/* B66CF8 80241248 8E2200D0 */  lw        $v0, 0xd0($s1)
/* B66CFC 8024124C 8C420034 */  lw        $v0, 0x34($v0)
/* B66D00 80241250 54400005 */  bnel      $v0, $zero, .L80241268
/* B66D04 80241254 2402FDFF */   addiu    $v0, $zero, -0x201
/* B66D08 80241258 34620200 */  ori       $v0, $v1, 0x200
/* B66D0C 8024125C 2403FFF7 */  addiu     $v1, $zero, -9
/* B66D10 80241260 0809049C */  j         .L80241270
/* B66D14 80241264 00431024 */   and      $v0, $v0, $v1
.L80241268:
/* B66D18 80241268 00621024 */  and       $v0, $v1, $v0
/* B66D1C 8024126C 34420008 */  ori       $v0, $v0, 8
.L80241270:
/* B66D20 80241270 AEA20000 */  sw        $v0, ($s5)
/* B66D24 80241274 8E2200B0 */  lw        $v0, 0xb0($s1)
/* B66D28 80241278 30420004 */  andi      $v0, $v0, 4
/* B66D2C 8024127C 10400007 */  beqz      $v0, .L8024129C
/* B66D30 80241280 24020063 */   addiu    $v0, $zero, 0x63
/* B66D34 80241284 AE420070 */  sw        $v0, 0x70($s2)
/* B66D38 80241288 AE400074 */  sw        $zero, 0x74($s2)
/* B66D3C 8024128C 8E2200B0 */  lw        $v0, 0xb0($s1)
/* B66D40 80241290 2403FFFB */  addiu     $v1, $zero, -5
/* B66D44 80241294 00431024 */  and       $v0, $v0, $v1
/* B66D48 80241298 AE2200B0 */  sw        $v0, 0xb0($s1)
.L8024129C:
/* B66D4C 8024129C AE20006C */  sw        $zero, 0x6c($s1)
.L802412A0:
/* B66D50 802412A0 8E420070 */  lw        $v0, 0x70($s2)
/* B66D54 802412A4 2842001E */  slti      $v0, $v0, 0x1e
/* B66D58 802412A8 10400009 */  beqz      $v0, .L802412D0
/* B66D5C 802412AC 00000000 */   nop      
/* B66D60 802412B0 8E22006C */  lw        $v0, 0x6c($s1)
/* B66D64 802412B4 14400006 */  bnez      $v0, .L802412D0
/* B66D68 802412B8 00000000 */   nop      
/* B66D6C 802412BC 0C090357 */  jal       func_80240D5C_B6680C
/* B66D70 802412C0 0240202D */   daddu    $a0, $s2, $zero
/* B66D74 802412C4 10400002 */  beqz      $v0, .L802412D0
/* B66D78 802412C8 2402001E */   addiu    $v0, $zero, 0x1e
/* B66D7C 802412CC AE420070 */  sw        $v0, 0x70($s2)
.L802412D0:
/* B66D80 802412D0 8E430070 */  lw        $v1, 0x70($s2)
/* B66D84 802412D4 2C620064 */  sltiu     $v0, $v1, 0x64
/* B66D88 802412D8 10400048 */  beqz      $v0, .L802413FC
/* B66D8C 802412DC 00031080 */   sll      $v0, $v1, 2
/* B66D90 802412E0 3C018024 */  lui       $at, 0x8024
/* B66D94 802412E4 00220821 */  addu      $at, $at, $v0
/* B66D98 802412E8 8C2265C0 */  lw        $v0, 0x65c0($at)
/* B66D9C 802412EC 00400008 */  jr        $v0
/* B66DA0 802412F0 00000000 */   nop      
/* B66DA4 802412F4 0240202D */  daddu     $a0, $s2, $zero
/* B66DA8 802412F8 0260282D */  daddu     $a1, $s3, $zero
/* B66DAC 802412FC 0C012568 */  jal       func_800495A0
/* B66DB0 80241300 0280302D */   daddu    $a2, $s4, $zero
/* B66DB4 80241304 0240202D */  daddu     $a0, $s2, $zero
/* B66DB8 80241308 0260282D */  daddu     $a1, $s3, $zero
/* B66DBC 8024130C 0C0125AE */  jal       func_800496B8
/* B66DC0 80241310 0280302D */   daddu    $a2, $s4, $zero
/* B66DC4 80241314 080904FF */  j         .L802413FC
/* B66DC8 80241318 00000000 */   nop      
/* B66DCC 8024131C 0240202D */  daddu     $a0, $s2, $zero
/* B66DD0 80241320 0260282D */  daddu     $a1, $s3, $zero
/* B66DD4 80241324 0C0126D1 */  jal       func_80049B44
/* B66DD8 80241328 0280302D */   daddu    $a2, $s4, $zero
/* B66DDC 8024132C 0240202D */  daddu     $a0, $s2, $zero
/* B66DE0 80241330 0260282D */  daddu     $a1, $s3, $zero
/* B66DE4 80241334 0C012701 */  jal       func_80049C04
/* B66DE8 80241338 0280302D */   daddu    $a2, $s4, $zero
/* B66DEC 8024133C 080904FF */  j         .L802413FC
/* B66DF0 80241340 00000000 */   nop      
/* B66DF4 80241344 0240202D */  daddu     $a0, $s2, $zero
/* B66DF8 80241348 0260282D */  daddu     $a1, $s3, $zero
/* B66DFC 8024134C 0C01278F */  jal       func_80049E3C
/* B66E00 80241350 0280302D */   daddu    $a2, $s4, $zero
/* B66E04 80241354 0240202D */  daddu     $a0, $s2, $zero
/* B66E08 80241358 0260282D */  daddu     $a1, $s3, $zero
/* B66E0C 8024135C 0C0127B3 */  jal       func_80049ECC
/* B66E10 80241360 0280302D */   daddu    $a2, $s4, $zero
/* B66E14 80241364 080904FF */  j         .L802413FC
/* B66E18 80241368 00000000 */   nop      
/* B66E1C 8024136C 0240202D */  daddu     $a0, $s2, $zero
/* B66E20 80241370 0260282D */  daddu     $a1, $s3, $zero
/* B66E24 80241374 0C0127DF */  jal       func_80049F7C
/* B66E28 80241378 0280302D */   daddu    $a2, $s4, $zero
/* B66E2C 8024137C 0240202D */  daddu     $a0, $s2, $zero
/* B66E30 80241380 0260282D */  daddu     $a1, $s3, $zero
/* B66E34 80241384 0C012849 */  jal       func_8004A124
/* B66E38 80241388 0280302D */   daddu    $a2, $s4, $zero
/* B66E3C 8024138C 080904FF */  j         .L802413FC
/* B66E40 80241390 00000000 */   nop      
/* B66E44 80241394 0240202D */  daddu     $a0, $s2, $zero
/* B66E48 80241398 0260282D */  daddu     $a1, $s3, $zero
/* B66E4C 8024139C 0C0128FA */  jal       func_8004A3E8
/* B66E50 802413A0 0280302D */   daddu    $a2, $s4, $zero
/* B66E54 802413A4 080904FF */  j         .L802413FC
/* B66E58 802413A8 00000000 */   nop      
/* B66E5C 802413AC 0C0902D5 */  jal       UnkNpcAIFunc6
/* B66E60 802413B0 0240202D */   daddu    $a0, $s2, $zero
/* B66E64 802413B4 0C0902F0 */  jal       UnkNpcAIFunc7
/* B66E68 802413B8 0240202D */   daddu    $a0, $s2, $zero
/* B66E6C 802413BC 8E430070 */  lw        $v1, 0x70($s2)
/* B66E70 802413C0 24020020 */  addiu     $v0, $zero, 0x20
/* B66E74 802413C4 1462000D */  bne       $v1, $v0, .L802413FC
/* B66E78 802413C8 00000000 */   nop      
/* B66E7C 802413CC 0C09030C */  jal       func_80240C30_B666E0
/* B66E80 802413D0 0240202D */   daddu    $a0, $s2, $zero
/* B66E84 802413D4 8E430070 */  lw        $v1, 0x70($s2)
/* B66E88 802413D8 24020021 */  addiu     $v0, $zero, 0x21
/* B66E8C 802413DC 14620007 */  bne       $v1, $v0, .L802413FC
/* B66E90 802413E0 00000000 */   nop      
/* B66E94 802413E4 0C090342 */  jal       UnkNpcAIFunc5
/* B66E98 802413E8 0240202D */   daddu    $a0, $s2, $zero
/* B66E9C 802413EC 080904FF */  j         .L802413FC
/* B66EA0 802413F0 00000000 */   nop      
/* B66EA4 802413F4 0C0129CF */  jal       func_8004A73C
/* B66EA8 802413F8 0240202D */   daddu    $a0, $s2, $zero
.L802413FC:
/* B66EAC 802413FC 8FBF0048 */  lw        $ra, 0x48($sp)
/* B66EB0 80241400 8FB50044 */  lw        $s5, 0x44($sp)
/* B66EB4 80241404 8FB40040 */  lw        $s4, 0x40($sp)
/* B66EB8 80241408 8FB3003C */  lw        $s3, 0x3c($sp)
/* B66EBC 8024140C 8FB20038 */  lw        $s2, 0x38($sp)
/* B66EC0 80241410 8FB10034 */  lw        $s1, 0x34($sp)
/* B66EC4 80241414 8FB00030 */  lw        $s0, 0x30($sp)
/* B66EC8 80241418 0000102D */  daddu     $v0, $zero, $zero
/* B66ECC 8024141C 03E00008 */  jr        $ra
/* B66ED0 80241420 27BD0050 */   addiu    $sp, $sp, 0x50
