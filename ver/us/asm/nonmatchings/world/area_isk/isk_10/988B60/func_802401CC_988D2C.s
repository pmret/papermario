.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802401CC_988D2C
/* 988D2C 802401CC 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 988D30 802401D0 AFB5002C */  sw        $s5, 0x2c($sp)
/* 988D34 802401D4 0080A82D */  daddu     $s5, $a0, $zero
/* 988D38 802401D8 AFBE0038 */  sw        $fp, 0x38($sp)
/* 988D3C 802401DC 3C1E8011 */  lui       $fp, %hi(gPlayerData)
/* 988D40 802401E0 27DEF290 */  addiu     $fp, $fp, %lo(gPlayerData)
/* 988D44 802401E4 AFBF003C */  sw        $ra, 0x3c($sp)
/* 988D48 802401E8 AFB70034 */  sw        $s7, 0x34($sp)
/* 988D4C 802401EC AFB60030 */  sw        $s6, 0x30($sp)
/* 988D50 802401F0 AFB40028 */  sw        $s4, 0x28($sp)
/* 988D54 802401F4 AFB30024 */  sw        $s3, 0x24($sp)
/* 988D58 802401F8 AFB20020 */  sw        $s2, 0x20($sp)
/* 988D5C 802401FC AFB1001C */  sw        $s1, 0x1c($sp)
/* 988D60 80240200 10A0004F */  beqz      $a1, .L80240340
/* 988D64 80240204 AFB00018 */   sw       $s0, 0x18($sp)
/* 988D68 80240208 0C00AB39 */  jal       heap_malloc
/* 988D6C 8024020C 24040330 */   addiu    $a0, $zero, 0x330
/* 988D70 80240210 0040982D */  daddu     $s3, $v0, $zero
/* 988D74 80240214 0000B02D */  daddu     $s6, $zero, $zero
/* 988D78 80240218 02C0902D */  daddu     $s2, $s6, $zero
/* 988D7C 8024021C 3C148024 */  lui       $s4, %hi(isk_10_SuperBlockDataB)
/* 988D80 80240220 26941108 */  addiu     $s4, $s4, %lo(isk_10_SuperBlockDataB)
/* 988D84 80240224 0260882D */  daddu     $s1, $s3, $zero
/* 988D88 80240228 8EA200B4 */  lw        $v0, 0xb4($s5)
/* 988D8C 8024022C 3C038024 */  lui       $v1, %hi(isk_10_SuperBlockDataA)
/* 988D90 80240230 24631100 */  addiu     $v1, $v1, %lo(isk_10_SuperBlockDataA)
/* 988D94 80240234 AEB30078 */  sw        $s3, 0x78($s5)
/* 988D98 80240238 00021027 */  nor       $v0, $zero, $v0
/* 988D9C 8024023C 0002BFC2 */  srl       $s7, $v0, 0x1f
/* 988DA0 80240240 00171080 */  sll       $v0, $s7, 2
/* 988DA4 80240244 00431021 */  addu      $v0, $v0, $v1
/* 988DA8 80240248 AFA20010 */  sw        $v0, 0x10($sp)
.L8024024C:
/* 988DAC 8024024C 86900000 */  lh        $s0, ($s4)
/* 988DB0 80240250 001010C0 */  sll       $v0, $s0, 3
/* 988DB4 80240254 03C21021 */  addu      $v0, $fp, $v0
/* 988DB8 80240258 90420014 */  lbu       $v0, 0x14($v0)
/* 988DBC 8024025C 5040002E */  beql      $v0, $zero, .L80240318
/* 988DC0 80240260 26520001 */   addiu    $s2, $s2, 1
/* 988DC4 80240264 00101100 */  sll       $v0, $s0, 4
/* 988DC8 80240268 3C068009 */  lui       $a2, %hi(gPartnerPopupProperties)
/* 988DCC 8024026C 24C6EF20 */  addiu     $a2, $a2, %lo(gPartnerPopupProperties)
/* 988DD0 80240270 00461021 */  addu      $v0, $v0, $a2
/* 988DD4 80240274 0200202D */  daddu     $a0, $s0, $zero
/* 988DD8 80240278 AE300108 */  sw        $s0, 0x108($s1)
/* 988DDC 8024027C 8C420000 */  lw        $v0, ($v0)
/* 988DE0 80240280 02E0282D */  daddu     $a1, $s7, $zero
/* 988DE4 80240284 0C090035 */  jal       isk_10_UnkFunc37
/* 988DE8 80240288 AE220084 */   sw       $v0, 0x84($s1)
/* 988DEC 8024028C 0040202D */  daddu     $a0, $v0, $zero
/* 988DF0 80240290 04800011 */  bltz      $a0, .L802402D8
/* 988DF4 80240294 00101080 */   sll      $v0, $s0, 2
/* 988DF8 80240298 3C06800F */  lui       $a2, %hi(wPartnerHudScripts)
/* 988DFC 8024029C 24C67F00 */  addiu     $a2, $a2, %lo(wPartnerHudScripts)
/* 988E00 802402A0 00461021 */  addu      $v0, $v0, $a2
/* 988E04 802402A4 8C430000 */  lw        $v1, ($v0)
/* 988E08 802402A8 24020001 */  addiu     $v0, $zero, 1
/* 988E0C 802402AC AE22018C */  sw        $v0, 0x18c($s1)
/* 988E10 802402B0 00041080 */  sll       $v0, $a0, 2
/* 988E14 802402B4 3C068024 */  lui       $a2, %hi(isk_10_SuperBlockDataC)
/* 988E18 802402B8 24C61118 */  addiu     $a2, $a2, %lo(isk_10_SuperBlockDataC)
/* 988E1C 802402BC AE230000 */  sw        $v1, ($s1)
/* 988E20 802402C0 001218C0 */  sll       $v1, $s2, 3
/* 988E24 802402C4 00431021 */  addu      $v0, $v0, $v1
/* 988E28 802402C8 00461021 */  addu      $v0, $v0, $a2
/* 988E2C 802402CC 8C420000 */  lw        $v0, ($v0)
/* 988E30 802402D0 080900BF */  j         .L802402FC
/* 988E34 802402D4 AE220294 */   sw       $v0, 0x294($s1)
.L802402D8:
/* 988E38 802402D8 3C06800F */  lui       $a2, %hi(wDisabledPartnerHudScripts)
/* 988E3C 802402DC 24C67F40 */  addiu     $a2, $a2, %lo(wDisabledPartnerHudScripts)
/* 988E40 802402E0 00461021 */  addu      $v0, $v0, $a2
/* 988E44 802402E4 8C420000 */  lw        $v0, ($v0)
/* 988E48 802402E8 AE20018C */  sw        $zero, 0x18c($s1)
/* 988E4C 802402EC AE220000 */  sw        $v0, ($s1)
/* 988E50 802402F0 8FA60010 */  lw        $a2, 0x10($sp)
/* 988E54 802402F4 8CC20000 */  lw        $v0, ($a2)
/* 988E58 802402F8 AE220294 */  sw        $v0, 0x294($s1)
.L802402FC:
/* 988E5C 802402FC 001010C0 */  sll       $v0, $s0, 3
/* 988E60 80240300 03C21021 */  addu      $v0, $fp, $v0
/* 988E64 80240304 80420015 */  lb        $v0, 0x15($v0)
/* 988E68 80240308 26D60001 */  addiu     $s6, $s6, 1
/* 988E6C 8024030C AE220210 */  sw        $v0, 0x210($s1)
/* 988E70 80240310 26310004 */  addiu     $s1, $s1, 4
/* 988E74 80240314 26520001 */  addiu     $s2, $s2, 1
.L80240318:
/* 988E78 80240318 2A420008 */  slti      $v0, $s2, 8
/* 988E7C 8024031C 1440FFCB */  bnez      $v0, .L8024024C
/* 988E80 80240320 26940002 */   addiu    $s4, $s4, 2
/* 988E84 80240324 0260202D */  daddu     $a0, $s3, $zero
/* 988E88 80240328 24020004 */  addiu     $v0, $zero, 4
/* 988E8C 8024032C AC820318 */  sw        $v0, 0x318($a0)
/* 988E90 80240330 AC960324 */  sw        $s6, 0x324($a0)
/* 988E94 80240334 0C03D390 */  jal       create_popup_menu
/* 988E98 80240338 AC800328 */   sw       $zero, 0x328($a0)
/* 988E9C 8024033C AEA00070 */  sw        $zero, 0x70($s5)
.L80240340:
/* 988EA0 80240340 8EA20070 */  lw        $v0, 0x70($s5)
/* 988EA4 80240344 8EB30078 */  lw        $s3, 0x78($s5)
/* 988EA8 80240348 14400008 */  bnez      $v0, .L8024036C
/* 988EAC 8024034C 24420001 */   addiu    $v0, $v0, 1
/* 988EB0 80240350 8662032C */  lh        $v0, 0x32c($s3)
/* 988EB4 80240354 10400009 */  beqz      $v0, .L8024037C
/* 988EB8 80240358 AEA20074 */   sw       $v0, 0x74($s5)
/* 988EBC 8024035C 0C03C4EC */  jal       hide_popup_menu
/* 988EC0 80240360 00000000 */   nop
/* 988EC4 80240364 8EA20070 */  lw        $v0, 0x70($s5)
/* 988EC8 80240368 24420001 */  addiu     $v0, $v0, 1
.L8024036C:
/* 988ECC 8024036C AEA20070 */  sw        $v0, 0x70($s5)
/* 988ED0 80240370 2842000F */  slti      $v0, $v0, 0xf
/* 988ED4 80240374 10400003 */  beqz      $v0, .L80240384
/* 988ED8 80240378 00000000 */   nop
.L8024037C:
/* 988EDC 8024037C 080900FB */  j         .L802403EC
/* 988EE0 80240380 0000102D */   daddu    $v0, $zero, $zero
.L80240384:
/* 988EE4 80240384 0C03C54E */  jal       destroy_popup_menu
/* 988EE8 80240388 00000000 */   nop
/* 988EEC 8024038C 8EA30074 */  lw        $v1, 0x74($s5)
/* 988EF0 80240390 240200FF */  addiu     $v0, $zero, 0xff
/* 988EF4 80240394 10620010 */  beq       $v1, $v0, .L802403D8
/* 988EF8 80240398 2462FFFF */   addiu    $v0, $v1, -1
/* 988EFC 8024039C 00021080 */  sll       $v0, $v0, 2
/* 988F00 802403A0 02621021 */  addu      $v0, $s3, $v0
/* 988F04 802403A4 8C420108 */  lw        $v0, 0x108($v0)
/* 988F08 802403A8 00021100 */  sll       $v0, $v0, 4
/* 988F0C 802403AC 3C038009 */  lui       $v1, %hi(gPartnerPopupProperties)
/* 988F10 802403B0 00621821 */  addu      $v1, $v1, $v0
/* 988F14 802403B4 8C63EF20 */  lw        $v1, %lo(gPartnerPopupProperties)($v1)
/* 988F18 802403B8 8EA20074 */  lw        $v0, 0x74($s5)
/* 988F1C 802403BC 2442FFFF */  addiu     $v0, $v0, -1
/* 988F20 802403C0 00021080 */  sll       $v0, $v0, 2
/* 988F24 802403C4 02621021 */  addu      $v0, $s3, $v0
/* 988F28 802403C8 AEA30084 */  sw        $v1, 0x84($s5)
/* 988F2C 802403CC 8C420108 */  lw        $v0, 0x108($v0)
/* 988F30 802403D0 080900F8 */  j         .L802403E0
/* 988F34 802403D4 AEA20088 */   sw       $v0, 0x88($s5)
.L802403D8:
/* 988F38 802403D8 2402FFFF */  addiu     $v0, $zero, -1
/* 988F3C 802403DC AEA20084 */  sw        $v0, 0x84($s5)
.L802403E0:
/* 988F40 802403E0 0C00AB4B */  jal       heap_free
/* 988F44 802403E4 8EA40078 */   lw       $a0, 0x78($s5)
/* 988F48 802403E8 24020002 */  addiu     $v0, $zero, 2
.L802403EC:
/* 988F4C 802403EC 8FBF003C */  lw        $ra, 0x3c($sp)
/* 988F50 802403F0 8FBE0038 */  lw        $fp, 0x38($sp)
/* 988F54 802403F4 8FB70034 */  lw        $s7, 0x34($sp)
/* 988F58 802403F8 8FB60030 */  lw        $s6, 0x30($sp)
/* 988F5C 802403FC 8FB5002C */  lw        $s5, 0x2c($sp)
/* 988F60 80240400 8FB40028 */  lw        $s4, 0x28($sp)
/* 988F64 80240404 8FB30024 */  lw        $s3, 0x24($sp)
/* 988F68 80240408 8FB20020 */  lw        $s2, 0x20($sp)
/* 988F6C 8024040C 8FB1001C */  lw        $s1, 0x1c($sp)
/* 988F70 80240410 8FB00018 */  lw        $s0, 0x18($sp)
/* 988F74 80240414 03E00008 */  jr        $ra
/* 988F78 80240418 27BD0040 */   addiu    $sp, $sp, 0x40
