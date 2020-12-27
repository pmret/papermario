.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024219C_B4CC0C
/* B4CC0C 8024219C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* B4CC10 802421A0 AFB20038 */  sw        $s2, 0x38($sp)
/* B4CC14 802421A4 0080902D */  daddu     $s2, $a0, $zero
/* B4CC18 802421A8 AFBF0048 */  sw        $ra, 0x48($sp)
/* B4CC1C 802421AC AFB50044 */  sw        $s5, 0x44($sp)
/* B4CC20 802421B0 AFB40040 */  sw        $s4, 0x40($sp)
/* B4CC24 802421B4 AFB3003C */  sw        $s3, 0x3c($sp)
/* B4CC28 802421B8 AFB10034 */  sw        $s1, 0x34($sp)
/* B4CC2C 802421BC AFB00030 */  sw        $s0, 0x30($sp)
/* B4CC30 802421C0 8E510148 */  lw        $s1, 0x148($s2)
/* B4CC34 802421C4 86240008 */  lh        $a0, 8($s1)
/* B4CC38 802421C8 0C00EABB */  jal       get_npc_unsafe
/* B4CC3C 802421CC 00A0802D */   daddu    $s0, $a1, $zero
/* B4CC40 802421D0 8E43000C */  lw        $v1, 0xc($s2)
/* B4CC44 802421D4 0240202D */  daddu     $a0, $s2, $zero
/* B4CC48 802421D8 8C650000 */  lw        $a1, ($v1)
/* B4CC4C 802421DC 0C0B1EAF */  jal       get_variable
/* B4CC50 802421E0 0040A82D */   daddu    $s5, $v0, $zero
/* B4CC54 802421E4 AFA00010 */  sw        $zero, 0x10($sp)
/* B4CC58 802421E8 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B4CC5C 802421EC 8C630030 */  lw        $v1, 0x30($v1)
/* B4CC60 802421F0 AFA30014 */  sw        $v1, 0x14($sp)
/* B4CC64 802421F4 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B4CC68 802421F8 8C63001C */  lw        $v1, 0x1c($v1)
/* B4CC6C 802421FC AFA30018 */  sw        $v1, 0x18($sp)
/* B4CC70 80242200 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B4CC74 80242204 8C630024 */  lw        $v1, 0x24($v1)
/* B4CC78 80242208 AFA3001C */  sw        $v1, 0x1c($sp)
/* B4CC7C 8024220C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B4CC80 80242210 8C630028 */  lw        $v1, 0x28($v1)
/* B4CC84 80242214 27B40010 */  addiu     $s4, $sp, 0x10
/* B4CC88 80242218 AFA30020 */  sw        $v1, 0x20($sp)
/* B4CC8C 8024221C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B4CC90 80242220 3C014282 */  lui       $at, 0x4282
/* B4CC94 80242224 44810000 */  mtc1      $at, $f0
/* B4CC98 80242228 8C63002C */  lw        $v1, 0x2c($v1)
/* B4CC9C 8024222C 0040982D */  daddu     $s3, $v0, $zero
/* B4CCA0 80242230 E7A00028 */  swc1      $f0, 0x28($sp)
/* B4CCA4 80242234 A7A0002C */  sh        $zero, 0x2c($sp)
/* B4CCA8 80242238 16000005 */  bnez      $s0, .L80242250
/* B4CCAC 8024223C AFA30024 */   sw       $v1, 0x24($sp)
/* B4CCB0 80242240 8E2200B0 */  lw        $v0, 0xb0($s1)
/* B4CCB4 80242244 30420004 */  andi      $v0, $v0, 4
/* B4CCB8 80242248 10400020 */  beqz      $v0, .L802422CC
/* B4CCBC 8024224C 00000000 */   nop
.L80242250:
/* B4CCC0 80242250 2404F7FF */  addiu     $a0, $zero, -0x801
/* B4CCC4 80242254 AE400070 */  sw        $zero, 0x70($s2)
/* B4CCC8 80242258 A6A0008E */  sh        $zero, 0x8e($s5)
/* B4CCCC 8024225C 8E2200CC */  lw        $v0, 0xcc($s1)
/* B4CCD0 80242260 8EA30000 */  lw        $v1, ($s5)
/* B4CCD4 80242264 8C420000 */  lw        $v0, ($v0)
/* B4CCD8 80242268 00641824 */  and       $v1, $v1, $a0
/* B4CCDC 8024226C AEA30000 */  sw        $v1, ($s5)
/* B4CCE0 80242270 AEA20028 */  sw        $v0, 0x28($s5)
/* B4CCE4 80242274 8E2200D0 */  lw        $v0, 0xd0($s1)
/* B4CCE8 80242278 8C420034 */  lw        $v0, 0x34($v0)
/* B4CCEC 8024227C 54400005 */  bnel      $v0, $zero, .L80242294
/* B4CCF0 80242280 2402FDFF */   addiu    $v0, $zero, -0x201
/* B4CCF4 80242284 34620200 */  ori       $v0, $v1, 0x200
/* B4CCF8 80242288 2403FFF7 */  addiu     $v1, $zero, -9
/* B4CCFC 8024228C 080908A7 */  j         .L8024229C
/* B4CD00 80242290 00431024 */   and      $v0, $v0, $v1
.L80242294:
/* B4CD04 80242294 00621024 */  and       $v0, $v1, $v0
/* B4CD08 80242298 34420008 */  ori       $v0, $v0, 8
.L8024229C:
/* B4CD0C 8024229C AEA20000 */  sw        $v0, ($s5)
/* B4CD10 802422A0 8E2200B0 */  lw        $v0, 0xb0($s1)
/* B4CD14 802422A4 30420004 */  andi      $v0, $v0, 4
/* B4CD18 802422A8 10400007 */  beqz      $v0, .L802422C8
/* B4CD1C 802422AC 24020063 */   addiu    $v0, $zero, 0x63
/* B4CD20 802422B0 AE420070 */  sw        $v0, 0x70($s2)
/* B4CD24 802422B4 AE400074 */  sw        $zero, 0x74($s2)
/* B4CD28 802422B8 8E2200B0 */  lw        $v0, 0xb0($s1)
/* B4CD2C 802422BC 2403FFFB */  addiu     $v1, $zero, -5
/* B4CD30 802422C0 00431024 */  and       $v0, $v0, $v1
/* B4CD34 802422C4 AE2200B0 */  sw        $v0, 0xb0($s1)
.L802422C8:
/* B4CD38 802422C8 AE20006C */  sw        $zero, 0x6c($s1)
.L802422CC:
/* B4CD3C 802422CC 8E420070 */  lw        $v0, 0x70($s2)
/* B4CD40 802422D0 2842001E */  slti      $v0, $v0, 0x1e
/* B4CD44 802422D4 10400009 */  beqz      $v0, .L802422FC
/* B4CD48 802422D8 00000000 */   nop
/* B4CD4C 802422DC 8E22006C */  lw        $v0, 0x6c($s1)
/* B4CD50 802422E0 14400006 */  bnez      $v0, .L802422FC
/* B4CD54 802422E4 00000000 */   nop
/* B4CD58 802422E8 0C0906B5 */  jal       func_80241AD4_B4C544
/* B4CD5C 802422EC 0240202D */   daddu    $a0, $s2, $zero
/* B4CD60 802422F0 10400002 */  beqz      $v0, .L802422FC
/* B4CD64 802422F4 2402001E */   addiu    $v0, $zero, 0x1e
/* B4CD68 802422F8 AE420070 */  sw        $v0, 0x70($s2)
.L802422FC:
/* B4CD6C 802422FC 8E430070 */  lw        $v1, 0x70($s2)
/* B4CD70 80242300 2C620064 */  sltiu     $v0, $v1, 0x64
/* B4CD74 80242304 10400048 */  beqz      $v0, .L80242428
/* B4CD78 80242308 00031080 */   sll      $v0, $v1, 2
/* B4CD7C 8024230C 3C018024 */  lui       $at, %hi(D_80247C28)
/* B4CD80 80242310 00220821 */  addu      $at, $at, $v0
/* B4CD84 80242314 8C227C28 */  lw        $v0, %lo(D_80247C28)($at)
/* B4CD88 80242318 00400008 */  jr        $v0
/* B4CD8C 8024231C 00000000 */   nop
/* B4CD90 80242320 0240202D */  daddu     $a0, $s2, $zero
/* B4CD94 80242324 0260282D */  daddu     $a1, $s3, $zero
/* B4CD98 80242328 0C012568 */  jal       func_800495A0
/* B4CD9C 8024232C 0280302D */   daddu    $a2, $s4, $zero
/* B4CDA0 80242330 0240202D */  daddu     $a0, $s2, $zero
/* B4CDA4 80242334 0260282D */  daddu     $a1, $s3, $zero
/* B4CDA8 80242338 0C0125AE */  jal       func_800496B8
/* B4CDAC 8024233C 0280302D */   daddu    $a2, $s4, $zero
/* B4CDB0 80242340 0809090A */  j         .L80242428
/* B4CDB4 80242344 00000000 */   nop
/* B4CDB8 80242348 0240202D */  daddu     $a0, $s2, $zero
/* B4CDBC 8024234C 0260282D */  daddu     $a1, $s3, $zero
/* B4CDC0 80242350 0C0905AE */  jal       jan_05_UnkNpcAIFunc4
/* B4CDC4 80242354 0280302D */   daddu    $a2, $s4, $zero
/* B4CDC8 80242358 0240202D */  daddu     $a0, $s2, $zero
/* B4CDCC 8024235C 0260282D */  daddu     $a1, $s3, $zero
/* B4CDD0 80242360 0C0905C2 */  jal       func_80241708_B4C178
/* B4CDD4 80242364 0280302D */   daddu    $a2, $s4, $zero
/* B4CDD8 80242368 0809090A */  j         .L80242428
/* B4CDDC 8024236C 00000000 */   nop
/* B4CDE0 80242370 0240202D */  daddu     $a0, $s2, $zero
/* B4CDE4 80242374 0260282D */  daddu     $a1, $s3, $zero
/* B4CDE8 80242378 0C01278F */  jal       func_80049E3C
/* B4CDEC 8024237C 0280302D */   daddu    $a2, $s4, $zero
/* B4CDF0 80242380 0240202D */  daddu     $a0, $s2, $zero
/* B4CDF4 80242384 0260282D */  daddu     $a1, $s3, $zero
/* B4CDF8 80242388 0C0127B3 */  jal       func_80049ECC
/* B4CDFC 8024238C 0280302D */   daddu    $a2, $s4, $zero
/* B4CE00 80242390 0809090A */  j         .L80242428
/* B4CE04 80242394 00000000 */   nop
/* B4CE08 80242398 0240202D */  daddu     $a0, $s2, $zero
/* B4CE0C 8024239C 0260282D */  daddu     $a1, $s3, $zero
/* B4CE10 802423A0 0C0127DF */  jal       func_80049F7C
/* B4CE14 802423A4 0280302D */   daddu    $a2, $s4, $zero
/* B4CE18 802423A8 0240202D */  daddu     $a0, $s2, $zero
/* B4CE1C 802423AC 0260282D */  daddu     $a1, $s3, $zero
/* B4CE20 802423B0 0C012849 */  jal       func_8004A124
/* B4CE24 802423B4 0280302D */   daddu    $a2, $s4, $zero
/* B4CE28 802423B8 0809090A */  j         .L80242428
/* B4CE2C 802423BC 00000000 */   nop
/* B4CE30 802423C0 0240202D */  daddu     $a0, $s2, $zero
/* B4CE34 802423C4 0260282D */  daddu     $a1, $s3, $zero
/* B4CE38 802423C8 0C0128FA */  jal       func_8004A3E8
/* B4CE3C 802423CC 0280302D */   daddu    $a2, $s4, $zero
/* B4CE40 802423D0 0809090A */  j         .L80242428
/* B4CE44 802423D4 00000000 */   nop
/* B4CE48 802423D8 0C090633 */  jal       jan_05_UnkNpcAIFunc6
/* B4CE4C 802423DC 0240202D */   daddu    $a0, $s2, $zero
/* B4CE50 802423E0 0C09064E */  jal       jan_05_UnkNpcAIFunc7
/* B4CE54 802423E4 0240202D */   daddu    $a0, $s2, $zero
/* B4CE58 802423E8 8E430070 */  lw        $v1, 0x70($s2)
/* B4CE5C 802423EC 24020020 */  addiu     $v0, $zero, 0x20
/* B4CE60 802423F0 1462000D */  bne       $v1, $v0, .L80242428
/* B4CE64 802423F4 00000000 */   nop
/* B4CE68 802423F8 0C09066A */  jal       jan_05_UnkNpcAIFunc8
/* B4CE6C 802423FC 0240202D */   daddu    $a0, $s2, $zero
/* B4CE70 80242400 8E430070 */  lw        $v1, 0x70($s2)
/* B4CE74 80242404 24020021 */  addiu     $v0, $zero, 0x21
/* B4CE78 80242408 14620007 */  bne       $v1, $v0, .L80242428
/* B4CE7C 8024240C 00000000 */   nop
/* B4CE80 80242410 0C0906A0 */  jal       jan_05_UnkNpcAIFunc5
/* B4CE84 80242414 0240202D */   daddu    $a0, $s2, $zero
/* B4CE88 80242418 0809090A */  j         .L80242428
/* B4CE8C 8024241C 00000000 */   nop
/* B4CE90 80242420 0C0129CF */  jal       func_8004A73C
/* B4CE94 80242424 0240202D */   daddu    $a0, $s2, $zero
.L80242428:
/* B4CE98 80242428 8FBF0048 */  lw        $ra, 0x48($sp)
/* B4CE9C 8024242C 8FB50044 */  lw        $s5, 0x44($sp)
/* B4CEA0 80242430 8FB40040 */  lw        $s4, 0x40($sp)
/* B4CEA4 80242434 8FB3003C */  lw        $s3, 0x3c($sp)
/* B4CEA8 80242438 8FB20038 */  lw        $s2, 0x38($sp)
/* B4CEAC 8024243C 8FB10034 */  lw        $s1, 0x34($sp)
/* B4CEB0 80242440 8FB00030 */  lw        $s0, 0x30($sp)
/* B4CEB4 80242444 0000102D */  daddu     $v0, $zero, $zero
/* B4CEB8 80242448 03E00008 */  jr        $ra
/* B4CEBC 8024244C 27BD0050 */   addiu    $sp, $sp, 0x50
