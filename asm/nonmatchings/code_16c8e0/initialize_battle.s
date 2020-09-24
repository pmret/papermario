.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel initialize_battle
/* 16CA10 8023E130 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 16CA14 8023E134 AFB3001C */  sw        $s3, 0x1c($sp)
/* 16CA18 8023E138 3C138011 */  lui       $s3, 0x8011
/* 16CA1C 8023E13C 2673F290 */  addiu     $s3, $s3, -0xd70
/* 16CA20 8023E140 AFB40020 */  sw        $s4, 0x20($sp)
/* 16CA24 8023E144 3C14800B */  lui       $s4, 0x800b
/* 16CA28 8023E148 26942830 */  addiu     $s4, $s4, 0x2830
/* 16CA2C 8023E14C AFB10014 */  sw        $s1, 0x14($sp)
/* 16CA30 8023E150 2411000F */  addiu     $s1, $zero, 0xf
/* 16CA34 8023E154 3C06800E */  lui       $a2, 0x800e
/* 16CA38 8023E158 24C6C070 */  addiu     $a2, $a2, -0x3f90
/* 16CA3C 8023E15C 24C5003C */  addiu     $a1, $a2, 0x3c
/* 16CA40 8023E160 3C04800A */  lui       $a0, 0x800a
/* 16CA44 8023E164 2484A650 */  addiu     $a0, $a0, -0x59b0
/* 16CA48 8023E168 AFBF0024 */  sw        $ra, 0x24($sp)
/* 16CA4C 8023E16C AFB20018 */  sw        $s2, 0x18($sp)
/* 16CA50 8023E170 AFB00010 */  sw        $s0, 0x10($sp)
/* 16CA54 8023E174 ACC00000 */  sw        $zero, ($a2)
/* 16CA58 8023E178 ACC00004 */  sw        $zero, 4($a2)
/* 16CA5C 8023E17C ACC00000 */  sw        $zero, ($a2)
/* 16CA60 8023E180 8C820000 */  lw        $v0, ($a0)
/* 16CA64 8023E184 2403FFFF */  addiu     $v1, $zero, -1
/* 16CA68 8023E188 ACC30224 */  sw        $v1, 0x224($a2)
/* 16CA6C 8023E18C 2403FF7F */  addiu     $v1, $zero, -0x81
/* 16CA70 8023E190 3C01802A */  lui       $at, 0x802a
/* 16CA74 8023E194 AC22DA34 */  sw        $v0, -0x25cc($at)
/* 16CA78 8023E198 00431024 */  and       $v0, $v0, $v1
/* 16CA7C 8023E19C AC820000 */  sw        $v0, ($a0)
/* 16CA80 8023E1A0 00431024 */  and       $v0, $v0, $v1
/* 16CA84 8023E1A4 AC820000 */  sw        $v0, ($a0)
.L8023E1A8:
/* 16CA88 8023E1A8 ACA00330 */  sw        $zero, 0x330($a1)
/* 16CA8C 8023E1AC 2631FFFF */  addiu     $s1, $s1, -1
/* 16CA90 8023E1B0 0621FFFD */  bgez      $s1, .L8023E1A8
/* 16CA94 8023E1B4 24A5FFFC */   addiu    $a1, $a1, -4
/* 16CA98 8023E1B8 24110017 */  addiu     $s1, $zero, 0x17
/* 16CA9C 8023E1BC 24C2005C */  addiu     $v0, $a2, 0x5c
/* 16CAA0 8023E1C0 A0C00431 */  sb        $zero, 0x431($a2)
/* 16CAA4 8023E1C4 A0C00430 */  sb        $zero, 0x430($a2)
/* 16CAA8 8023E1C8 A0C00095 */  sb        $zero, 0x95($a2)
.L8023E1CC:
/* 16CAAC 8023E1CC AC4000E0 */  sw        $zero, 0xe0($v0)
/* 16CAB0 8023E1D0 2631FFFF */  addiu     $s1, $s1, -1
/* 16CAB4 8023E1D4 0621FFFD */  bgez      $s1, .L8023E1CC
/* 16CAB8 8023E1D8 2442FFFC */   addiu    $v0, $v0, -4
/* 16CABC 8023E1DC 0000882D */  daddu     $s1, $zero, $zero
/* 16CAC0 8023E1E0 2403FFFF */  addiu     $v1, $zero, -1
/* 16CAC4 8023E1E4 ACC000D8 */  sw        $zero, 0xd8($a2)
/* 16CAC8 8023E1E8 ACC000DC */  sw        $zero, 0xdc($a2)
/* 16CACC 8023E1EC 00D11021 */  addu      $v0, $a2, $s1
.L8023E1F0:
/* 16CAD0 8023E1F0 26310001 */  addiu     $s1, $s1, 1
/* 16CAD4 8023E1F4 A043004C */  sb        $v1, 0x4c($v0)
/* 16CAD8 8023E1F8 A043005C */  sb        $v1, 0x5c($v0)
/* 16CADC 8023E1FC 2A220010 */  slti      $v0, $s1, 0x10
/* 16CAE0 8023E200 5440FFFB */  bnel      $v0, $zero, .L8023E1F0
/* 16CAE4 8023E204 00D11021 */   addu     $v0, $a2, $s1
/* 16CAE8 8023E208 2411001B */  addiu     $s1, $zero, 0x1b
/* 16CAEC 8023E20C 00D11021 */  addu      $v0, $a2, $s1
.L8023E210:
/* 16CAF0 8023E210 A0400440 */  sb        $zero, 0x440($v0)
/* 16CAF4 8023E214 2631FFFF */  addiu     $s1, $s1, -1
/* 16CAF8 8023E218 0621FFFD */  bgez      $s1, .L8023E210
/* 16CAFC 8023E21C 2442FFFF */   addiu    $v0, $v0, -1
/* 16CB00 8023E220 3C028007 */  lui       $v0, 0x8007
/* 16CB04 8023E224 8C42419C */  lw        $v0, 0x419c($v0)
/* 16CB08 8023E228 9042007E */  lbu       $v0, 0x7e($v0)
/* 16CB0C 8023E22C 30420001 */  andi      $v0, $v0, 1
/* 16CB10 8023E230 10400009 */  beqz      $v0, .L8023E258
/* 16CB14 8023E234 2404FFBF */   addiu    $a0, $zero, -0x41
/* 16CB18 8023E238 3C03800E */  lui       $v1, 0x800e
/* 16CB1C 8023E23C 2463C070 */  addiu     $v1, $v1, -0x3f90
/* 16CB20 8023E240 8C620004 */  lw        $v0, 4($v1)
/* 16CB24 8023E244 34420040 */  ori       $v0, $v0, 0x40
/* 16CB28 8023E248 0C03A6D5 */  jal       increment_status_menu_disabled
/* 16CB2C 8023E24C AC620004 */   sw       $v0, 4($v1)
/* 16CB30 8023E250 0808F89B */  j         .L8023E26C
/* 16CB34 8023E254 00000000 */   nop      
.L8023E258:
/* 16CB38 8023E258 3C02800E */  lui       $v0, 0x800e
/* 16CB3C 8023E25C 2442C070 */  addiu     $v0, $v0, -0x3f90
/* 16CB40 8023E260 8C430004 */  lw        $v1, 4($v0)
/* 16CB44 8023E264 00641824 */  and       $v1, $v1, $a0
/* 16CB48 8023E268 AC430004 */  sw        $v1, 4($v0)
.L8023E26C:
/* 16CB4C 8023E26C 3C058024 */  lui       $a1, 0x8024
/* 16CB50 8023E270 24A5ED5C */  addiu     $a1, $a1, -0x12a4
/* 16CB54 8023E274 0C048C56 */  jal       bind_dynamic_entity_3
/* 16CB58 8023E278 0000202D */   daddu    $a0, $zero, $zero
/* 16CB5C 8023E27C 0C093B70 */  jal       func_8024EDC0
/* 16CB60 8023E280 0000882D */   daddu    $s1, $zero, $zero
/* 16CB64 8023E284 0C09A3A2 */  jal       func_80268E88
/* 16CB68 8023E288 00000000 */   nop      
/* 16CB6C 8023E28C 0C051FB1 */  jal       func_80147EC4
/* 16CB70 8023E290 24040001 */   addiu    $a0, $zero, 1
/* 16CB74 8023E294 3C048029 */  lui       $a0, 0x8029
/* 16CB78 8023E298 24841F80 */  addiu     $a0, $a0, 0x1f80
/* 16CB7C 8023E29C 0C050529 */  jal       create_icon
/* 16CB80 8023E2A0 00000000 */   nop      
/* 16CB84 8023E2A4 3C01802A */  lui       $at, 0x802a
/* 16CB88 8023E2A8 AC22EFBC */  sw        $v0, -0x1044($at)
/* 16CB8C 8023E2AC 0040202D */  daddu     $a0, $v0, $zero
/* 16CB90 8023E2B0 0C051280 */  jal       set_icon_flags
/* 16CB94 8023E2B4 24050080 */   addiu    $a1, $zero, 0x80
/* 16CB98 8023E2B8 3C12802A */  lui       $s2, 0x802a
/* 16CB9C 8023E2BC 2652EFC0 */  addiu     $s2, $s2, -0x1040
.L8023E2C0:
/* 16CBA0 8023E2C0 3C048008 */  lui       $a0, 0x8008
/* 16CBA4 8023E2C4 24840FF0 */  addiu     $a0, $a0, 0xff0
/* 16CBA8 8023E2C8 0C050529 */  jal       create_icon
/* 16CBAC 8023E2CC 26310001 */   addiu    $s1, $s1, 1
/* 16CBB0 8023E2D0 AE420000 */  sw        $v0, ($s2)
/* 16CBB4 8023E2D4 0040802D */  daddu     $s0, $v0, $zero
/* 16CBB8 8023E2D8 0200202D */  daddu     $a0, $s0, $zero
/* 16CBBC 8023E2DC 0C051280 */  jal       set_icon_flags
/* 16CBC0 8023E2E0 24050082 */   addiu    $a1, $zero, 0x82
/* 16CBC4 8023E2E4 0200202D */  daddu     $a0, $s0, $zero
/* 16CBC8 8023E2E8 0C051277 */  jal       func_801449DC
/* 16CBCC 8023E2EC 24050014 */   addiu    $a1, $zero, 0x14
/* 16CBD0 8023E2F0 2A22000A */  slti      $v0, $s1, 0xa
/* 16CBD4 8023E2F4 1440FFF2 */  bnez      $v0, .L8023E2C0
/* 16CBD8 8023E2F8 26520004 */   addiu    $s2, $s2, 4
/* 16CBDC 8023E2FC 0000882D */  daddu     $s1, $zero, $zero
/* 16CBE0 8023E300 3C12802A */  lui       $s2, 0x802a
/* 16CBE4 8023E304 2652EFE8 */  addiu     $s2, $s2, -0x1018
.L8023E308:
/* 16CBE8 8023E308 3C048010 */  lui       $a0, 0x8010
/* 16CBEC 8023E30C 24844BEC */  addiu     $a0, $a0, 0x4bec
/* 16CBF0 8023E310 0C050529 */  jal       create_icon
/* 16CBF4 8023E314 26310001 */   addiu    $s1, $s1, 1
/* 16CBF8 8023E318 AE420000 */  sw        $v0, ($s2)
/* 16CBFC 8023E31C 0040802D */  daddu     $s0, $v0, $zero
/* 16CC00 8023E320 0200202D */  daddu     $a0, $s0, $zero
/* 16CC04 8023E324 0C051280 */  jal       set_icon_flags
/* 16CC08 8023E328 24050082 */   addiu    $a1, $zero, 0x82
/* 16CC0C 8023E32C 0200202D */  daddu     $a0, $s0, $zero
/* 16CC10 8023E330 0C051277 */  jal       func_801449DC
/* 16CC14 8023E334 24050014 */   addiu    $a1, $zero, 0x14
/* 16CC18 8023E338 2A22000A */  slti      $v0, $s1, 0xa
/* 16CC1C 8023E33C 1440FFF2 */  bnez      $v0, .L8023E308
/* 16CC20 8023E340 26520004 */   addiu    $s2, $s2, 4
/* 16CC24 8023E344 0000882D */  daddu     $s1, $zero, $zero
/* 16CC28 8023E348 3C12802A */  lui       $s2, 0x802a
/* 16CC2C 8023E34C 2652F010 */  addiu     $s2, $s2, -0xff0
.L8023E350:
/* 16CC30 8023E350 3C048008 */  lui       $a0, 0x8008
/* 16CC34 8023E354 248410C8 */  addiu     $a0, $a0, 0x10c8
/* 16CC38 8023E358 0C050529 */  jal       create_icon
/* 16CC3C 8023E35C 26310001 */   addiu    $s1, $s1, 1
/* 16CC40 8023E360 AE420000 */  sw        $v0, ($s2)
/* 16CC44 8023E364 0040802D */  daddu     $s0, $v0, $zero
/* 16CC48 8023E368 0200202D */  daddu     $a0, $s0, $zero
/* 16CC4C 8023E36C 0C051280 */  jal       set_icon_flags
/* 16CC50 8023E370 24050082 */   addiu    $a1, $zero, 0x82
/* 16CC54 8023E374 0200202D */  daddu     $a0, $s0, $zero
/* 16CC58 8023E378 0C051277 */  jal       func_801449DC
/* 16CC5C 8023E37C 24050014 */   addiu    $a1, $zero, 0x14
/* 16CC60 8023E380 2A22000A */  slti      $v0, $s1, 0xa
/* 16CC64 8023E384 1440FFF2 */  bnez      $v0, .L8023E350
/* 16CC68 8023E388 26520004 */   addiu    $s2, $s2, 4
/* 16CC6C 8023E38C 3C028024 */  lui       $v0, 0x8024
/* 16CC70 8023E390 2442F088 */  addiu     $v0, $v0, -0xf78
/* 16CC74 8023E394 AE8201FC */  sw        $v0, 0x1fc($s4)
/* 16CC78 8023E398 966302A2 */  lhu       $v1, 0x2a2($s3)
/* 16CC7C 8023E39C 3C028024 */  lui       $v0, 0x8024
/* 16CC80 8023E3A0 2442FF84 */  addiu     $v0, $v0, -0x7c
/* 16CC84 8023E3A4 AE820200 */  sw        $v0, 0x200($s4)
/* 16CC88 8023E3A8 2C62270F */  sltiu     $v0, $v1, 0x270f
/* 16CC8C 8023E3AC 10400002 */  beqz      $v0, .L8023E3B8
/* 16CC90 8023E3B0 24620001 */   addiu    $v0, $v1, 1
/* 16CC94 8023E3B4 A66202A2 */  sh        $v0, 0x2a2($s3)
.L8023E3B8:
/* 16CC98 8023E3B8 3C02800E */  lui       $v0, 0x800e
/* 16CC9C 8023E3BC 8C42C074 */  lw        $v0, -0x3f8c($v0)
/* 16CCA0 8023E3C0 82630012 */  lb        $v1, 0x12($s3)
/* 16CCA4 8023E3C4 30420040 */  andi      $v0, $v0, 0x40
/* 16CCA8 8023E3C8 3C01802A */  lui       $at, 0x802a
/* 16CCAC 8023E3CC AC23DA30 */  sw        $v1, -0x25d0($at)
/* 16CCB0 8023E3D0 10400002 */  beqz      $v0, .L8023E3DC
/* 16CCB4 8023E3D4 2402000B */   addiu    $v0, $zero, 0xb
/* 16CCB8 8023E3D8 A2620012 */  sb        $v0, 0x12($s3)
.L8023E3DC:
/* 16CCBC 8023E3DC 8FBF0024 */  lw        $ra, 0x24($sp)
/* 16CCC0 8023E3E0 8FB40020 */  lw        $s4, 0x20($sp)
/* 16CCC4 8023E3E4 8FB3001C */  lw        $s3, 0x1c($sp)
/* 16CCC8 8023E3E8 8FB20018 */  lw        $s2, 0x18($sp)
/* 16CCCC 8023E3EC 8FB10014 */  lw        $s1, 0x14($sp)
/* 16CCD0 8023E3F0 8FB00010 */  lw        $s0, 0x10($sp)
/* 16CCD4 8023E3F4 03E00008 */  jr        $ra
/* 16CCD8 8023E3F8 27BD0028 */   addiu    $sp, $sp, 0x28
