.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241170_C3ED60
/* C3ED60 80241170 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* C3ED64 80241174 AFB20038 */  sw        $s2, 0x38($sp)
/* C3ED68 80241178 0080902D */  daddu     $s2, $a0, $zero
/* C3ED6C 8024117C AFBF0048 */  sw        $ra, 0x48($sp)
/* C3ED70 80241180 AFB50044 */  sw        $s5, 0x44($sp)
/* C3ED74 80241184 AFB40040 */  sw        $s4, 0x40($sp)
/* C3ED78 80241188 AFB3003C */  sw        $s3, 0x3c($sp)
/* C3ED7C 8024118C AFB10034 */  sw        $s1, 0x34($sp)
/* C3ED80 80241190 AFB00030 */  sw        $s0, 0x30($sp)
/* C3ED84 80241194 8E510148 */  lw        $s1, 0x148($s2)
/* C3ED88 80241198 86240008 */  lh        $a0, 8($s1)
/* C3ED8C 8024119C 0C00EABB */  jal       get_npc_unsafe
/* C3ED90 802411A0 00A0802D */   daddu    $s0, $a1, $zero
/* C3ED94 802411A4 8E43000C */  lw        $v1, 0xc($s2)
/* C3ED98 802411A8 0240202D */  daddu     $a0, $s2, $zero
/* C3ED9C 802411AC 8C650000 */  lw        $a1, ($v1)
/* C3EDA0 802411B0 0C0B1EAF */  jal       get_variable
/* C3EDA4 802411B4 0040A82D */   daddu    $s5, $v0, $zero
/* C3EDA8 802411B8 AFA00010 */  sw        $zero, 0x10($sp)
/* C3EDAC 802411BC 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C3EDB0 802411C0 8C630030 */  lw        $v1, 0x30($v1)
/* C3EDB4 802411C4 AFA30014 */  sw        $v1, 0x14($sp)
/* C3EDB8 802411C8 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C3EDBC 802411CC 8C63001C */  lw        $v1, 0x1c($v1)
/* C3EDC0 802411D0 AFA30018 */  sw        $v1, 0x18($sp)
/* C3EDC4 802411D4 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C3EDC8 802411D8 8C630024 */  lw        $v1, 0x24($v1)
/* C3EDCC 802411DC AFA3001C */  sw        $v1, 0x1c($sp)
/* C3EDD0 802411E0 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C3EDD4 802411E4 8C630028 */  lw        $v1, 0x28($v1)
/* C3EDD8 802411E8 27B40010 */  addiu     $s4, $sp, 0x10
/* C3EDDC 802411EC AFA30020 */  sw        $v1, 0x20($sp)
/* C3EDE0 802411F0 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C3EDE4 802411F4 3C014282 */  lui       $at, 0x4282
/* C3EDE8 802411F8 44810000 */  mtc1      $at, $f0
/* C3EDEC 802411FC 8C63002C */  lw        $v1, 0x2c($v1)
/* C3EDF0 80241200 0040982D */  daddu     $s3, $v0, $zero
/* C3EDF4 80241204 E7A00028 */  swc1      $f0, 0x28($sp)
/* C3EDF8 80241208 A7A0002C */  sh        $zero, 0x2c($sp)
/* C3EDFC 8024120C 16000005 */  bnez      $s0, .L80241224
/* C3EE00 80241210 AFA30024 */   sw       $v1, 0x24($sp)
/* C3EE04 80241214 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C3EE08 80241218 30420004 */  andi      $v0, $v0, 4
/* C3EE0C 8024121C 10400020 */  beqz      $v0, .L802412A0
/* C3EE10 80241220 00000000 */   nop      
.L80241224:
/* C3EE14 80241224 2404F7FF */  addiu     $a0, $zero, -0x801
/* C3EE18 80241228 AE400070 */  sw        $zero, 0x70($s2)
/* C3EE1C 8024122C A6A0008E */  sh        $zero, 0x8e($s5)
/* C3EE20 80241230 8E2200CC */  lw        $v0, 0xcc($s1)
/* C3EE24 80241234 8EA30000 */  lw        $v1, ($s5)
/* C3EE28 80241238 8C420000 */  lw        $v0, ($v0)
/* C3EE2C 8024123C 00641824 */  and       $v1, $v1, $a0
/* C3EE30 80241240 AEA30000 */  sw        $v1, ($s5)
/* C3EE34 80241244 AEA20028 */  sw        $v0, 0x28($s5)
/* C3EE38 80241248 8E2200D0 */  lw        $v0, 0xd0($s1)
/* C3EE3C 8024124C 8C420034 */  lw        $v0, 0x34($v0)
/* C3EE40 80241250 54400005 */  bnel      $v0, $zero, .L80241268
/* C3EE44 80241254 2402FDFF */   addiu    $v0, $zero, -0x201
/* C3EE48 80241258 34620200 */  ori       $v0, $v1, 0x200
/* C3EE4C 8024125C 2403FFF7 */  addiu     $v1, $zero, -9
/* C3EE50 80241260 0809049C */  j         .L80241270
/* C3EE54 80241264 00431024 */   and      $v0, $v0, $v1
.L80241268:
/* C3EE58 80241268 00621024 */  and       $v0, $v1, $v0
/* C3EE5C 8024126C 34420008 */  ori       $v0, $v0, 8
.L80241270:
/* C3EE60 80241270 AEA20000 */  sw        $v0, ($s5)
/* C3EE64 80241274 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C3EE68 80241278 30420004 */  andi      $v0, $v0, 4
/* C3EE6C 8024127C 10400007 */  beqz      $v0, .L8024129C
/* C3EE70 80241280 24020063 */   addiu    $v0, $zero, 0x63
/* C3EE74 80241284 AE420070 */  sw        $v0, 0x70($s2)
/* C3EE78 80241288 AE400074 */  sw        $zero, 0x74($s2)
/* C3EE7C 8024128C 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C3EE80 80241290 2403FFFB */  addiu     $v1, $zero, -5
/* C3EE84 80241294 00431024 */  and       $v0, $v0, $v1
/* C3EE88 80241298 AE2200B0 */  sw        $v0, 0xb0($s1)
.L8024129C:
/* C3EE8C 8024129C AE20006C */  sw        $zero, 0x6c($s1)
.L802412A0:
/* C3EE90 802412A0 8E420070 */  lw        $v0, 0x70($s2)
/* C3EE94 802412A4 2842001E */  slti      $v0, $v0, 0x1e
/* C3EE98 802412A8 10400009 */  beqz      $v0, .L802412D0
/* C3EE9C 802412AC 00000000 */   nop      
/* C3EEA0 802412B0 8E22006C */  lw        $v0, 0x6c($s1)
/* C3EEA4 802412B4 14400006 */  bnez      $v0, .L802412D0
/* C3EEA8 802412B8 00000000 */   nop      
/* C3EEAC 802412BC 0C090082 */  jal       func_80240208_C3DDF8
/* C3EEB0 802412C0 0240202D */   daddu    $a0, $s2, $zero
/* C3EEB4 802412C4 10400002 */  beqz      $v0, .L802412D0
/* C3EEB8 802412C8 2402001E */   addiu    $v0, $zero, 0x1e
/* C3EEBC 802412CC AE420070 */  sw        $v0, 0x70($s2)
.L802412D0:
/* C3EEC0 802412D0 8E430070 */  lw        $v1, 0x70($s2)
/* C3EEC4 802412D4 2C620064 */  sltiu     $v0, $v1, 0x64
/* C3EEC8 802412D8 10400048 */  beqz      $v0, .L802413FC
/* C3EECC 802412DC 00031080 */   sll      $v0, $v1, 2
/* C3EED0 802412E0 3C018024 */  lui       $at, 0x8024
/* C3EED4 802412E4 00220821 */  addu      $at, $at, $v0
/* C3EED8 802412E8 8C222030 */  lw        $v0, 0x2030($at)
/* C3EEDC 802412EC 00400008 */  jr        $v0
/* C3EEE0 802412F0 00000000 */   nop      
/* C3EEE4 802412F4 0240202D */  daddu     $a0, $s2, $zero
/* C3EEE8 802412F8 0260282D */  daddu     $a1, $s3, $zero
/* C3EEEC 802412FC 0C012568 */  jal       func_800495A0
/* C3EEF0 80241300 0280302D */   daddu    $a2, $s4, $zero
/* C3EEF4 80241304 0240202D */  daddu     $a0, $s2, $zero
/* C3EEF8 80241308 0260282D */  daddu     $a1, $s3, $zero
/* C3EEFC 8024130C 0C0125AE */  jal       func_800496B8
/* C3EF00 80241310 0280302D */   daddu    $a2, $s4, $zero
/* C3EF04 80241314 080904FF */  j         .L802413FC
/* C3EF08 80241318 00000000 */   nop      
/* C3EF0C 8024131C 0240202D */  daddu     $a0, $s2, $zero
/* C3EF10 80241320 0260282D */  daddu     $a1, $s3, $zero
/* C3EF14 80241324 0C0126D1 */  jal       func_80049B44
/* C3EF18 80241328 0280302D */   daddu    $a2, $s4, $zero
/* C3EF1C 8024132C 0240202D */  daddu     $a0, $s2, $zero
/* C3EF20 80241330 0260282D */  daddu     $a1, $s3, $zero
/* C3EF24 80241334 0C012701 */  jal       func_80049C04
/* C3EF28 80241338 0280302D */   daddu    $a2, $s4, $zero
/* C3EF2C 8024133C 080904FF */  j         .L802413FC
/* C3EF30 80241340 00000000 */   nop      
/* C3EF34 80241344 0240202D */  daddu     $a0, $s2, $zero
/* C3EF38 80241348 0260282D */  daddu     $a1, $s3, $zero
/* C3EF3C 8024134C 0C01278F */  jal       func_80049E3C
/* C3EF40 80241350 0280302D */   daddu    $a2, $s4, $zero
/* C3EF44 80241354 0240202D */  daddu     $a0, $s2, $zero
/* C3EF48 80241358 0260282D */  daddu     $a1, $s3, $zero
/* C3EF4C 8024135C 0C0127B3 */  jal       func_80049ECC
/* C3EF50 80241360 0280302D */   daddu    $a2, $s4, $zero
/* C3EF54 80241364 080904FF */  j         .L802413FC
/* C3EF58 80241368 00000000 */   nop      
/* C3EF5C 8024136C 0240202D */  daddu     $a0, $s2, $zero
/* C3EF60 80241370 0260282D */  daddu     $a1, $s3, $zero
/* C3EF64 80241374 0C0127DF */  jal       func_80049F7C
/* C3EF68 80241378 0280302D */   daddu    $a2, $s4, $zero
/* C3EF6C 8024137C 0240202D */  daddu     $a0, $s2, $zero
/* C3EF70 80241380 0260282D */  daddu     $a1, $s3, $zero
/* C3EF74 80241384 0C012849 */  jal       func_8004A124
/* C3EF78 80241388 0280302D */   daddu    $a2, $s4, $zero
/* C3EF7C 8024138C 080904FF */  j         .L802413FC
/* C3EF80 80241390 00000000 */   nop      
/* C3EF84 80241394 0240202D */  daddu     $a0, $s2, $zero
/* C3EF88 80241398 0260282D */  daddu     $a1, $s3, $zero
/* C3EF8C 8024139C 0C0128FA */  jal       func_8004A3E8
/* C3EF90 802413A0 0280302D */   daddu    $a2, $s4, $zero
/* C3EF94 802413A4 080904FF */  j         .L802413FC
/* C3EF98 802413A8 00000000 */   nop      
/* C3EF9C 802413AC 0C090000 */  jal       func_80240000_C3DBF0
/* C3EFA0 802413B0 0240202D */   daddu    $a0, $s2, $zero
/* C3EFA4 802413B4 0C09001B */  jal       func_8024006C_C3DC5C
/* C3EFA8 802413B8 0240202D */   daddu    $a0, $s2, $zero
/* C3EFAC 802413BC 8E430070 */  lw        $v1, 0x70($s2)
/* C3EFB0 802413C0 24020020 */  addiu     $v0, $zero, 0x20
/* C3EFB4 802413C4 1462000D */  bne       $v1, $v0, .L802413FC
/* C3EFB8 802413C8 00000000 */   nop      
/* C3EFBC 802413CC 0C090037 */  jal       func_802400DC_C3DCCC
/* C3EFC0 802413D0 0240202D */   daddu    $a0, $s2, $zero
/* C3EFC4 802413D4 8E430070 */  lw        $v1, 0x70($s2)
/* C3EFC8 802413D8 24020021 */  addiu     $v0, $zero, 0x21
/* C3EFCC 802413DC 14620007 */  bne       $v1, $v0, .L802413FC
/* C3EFD0 802413E0 00000000 */   nop      
/* C3EFD4 802413E4 0C09006D */  jal       func_802401B4_C3DDA4
/* C3EFD8 802413E8 0240202D */   daddu    $a0, $s2, $zero
/* C3EFDC 802413EC 080904FF */  j         .L802413FC
/* C3EFE0 802413F0 00000000 */   nop      
/* C3EFE4 802413F4 0C0129CF */  jal       func_8004A73C
/* C3EFE8 802413F8 0240202D */   daddu    $a0, $s2, $zero
.L802413FC:
/* C3EFEC 802413FC 8FBF0048 */  lw        $ra, 0x48($sp)
/* C3EFF0 80241400 8FB50044 */  lw        $s5, 0x44($sp)
/* C3EFF4 80241404 8FB40040 */  lw        $s4, 0x40($sp)
/* C3EFF8 80241408 8FB3003C */  lw        $s3, 0x3c($sp)
/* C3EFFC 8024140C 8FB20038 */  lw        $s2, 0x38($sp)
/* C3F000 80241410 8FB10034 */  lw        $s1, 0x34($sp)
/* C3F004 80241414 8FB00030 */  lw        $s0, 0x30($sp)
/* C3F008 80241418 0000102D */  daddu     $v0, $zero, $zero
/* C3F00C 8024141C 03E00008 */  jr        $ra
/* C3F010 80241420 27BD0050 */   addiu    $sp, $sp, 0x50
/* C3F014 80241424 00000000 */  nop       
/* C3F018 80241428 00000000 */  nop       
/* C3F01C 8024142C 00000000 */  nop       
