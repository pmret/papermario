.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240EA4_9C6284
/* 9C6284 80240EA4 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 9C6288 80240EA8 AFB10024 */  sw        $s1, 0x24($sp)
/* 9C628C 80240EAC 0080882D */  daddu     $s1, $a0, $zero
/* 9C6290 80240EB0 3C05F840 */  lui       $a1, 0xf840
/* 9C6294 80240EB4 AFBF0044 */  sw        $ra, 0x44($sp)
/* 9C6298 80240EB8 AFBE0040 */  sw        $fp, 0x40($sp)
/* 9C629C 80240EBC AFB7003C */  sw        $s7, 0x3c($sp)
/* 9C62A0 80240EC0 AFB60038 */  sw        $s6, 0x38($sp)
/* 9C62A4 80240EC4 AFB50034 */  sw        $s5, 0x34($sp)
/* 9C62A8 80240EC8 AFB40030 */  sw        $s4, 0x30($sp)
/* 9C62AC 80240ECC AFB3002C */  sw        $s3, 0x2c($sp)
/* 9C62B0 80240ED0 AFB20028 */  sw        $s2, 0x28($sp)
/* 9C62B4 80240ED4 AFB00020 */  sw        $s0, 0x20($sp)
/* 9C62B8 80240ED8 8E3E0148 */  lw        $fp, 0x148($s1)
/* 9C62BC 80240EDC 0C0B1EAF */  jal       get_variable
/* 9C62C0 80240EE0 34A56268 */   ori      $a1, $a1, 0x6268
/* 9C62C4 80240EE4 0040802D */  daddu     $s0, $v0, $zero
/* 9C62C8 80240EE8 0220202D */  daddu     $a0, $s1, $zero
/* 9C62CC 80240EEC 3C05F840 */  lui       $a1, 0xf840
/* 9C62D0 80240EF0 0C0B1EAF */  jal       get_variable
/* 9C62D4 80240EF4 34A56269 */   ori      $a1, $a1, 0x6269
/* 9C62D8 80240EF8 0040B82D */  daddu     $s7, $v0, $zero
/* 9C62DC 80240EFC 0220202D */  daddu     $a0, $s1, $zero
/* 9C62E0 80240F00 3C05F5DE */  lui       $a1, 0xf5de
/* 9C62E4 80240F04 0C0B1EAF */  jal       get_variable
/* 9C62E8 80240F08 34A502DE */   ori      $a1, $a1, 0x2de
/* 9C62EC 80240F0C 0040B02D */  daddu     $s6, $v0, $zero
/* 9C62F0 80240F10 0220202D */  daddu     $a0, $s1, $zero
/* 9C62F4 80240F14 3C05F5DE */  lui       $a1, 0xf5de
/* 9C62F8 80240F18 0C0B1EAF */  jal       get_variable
/* 9C62FC 80240F1C 34A502DF */   ori      $a1, $a1, 0x2df
/* 9C6300 80240F20 0040A82D */  daddu     $s5, $v0, $zero
/* 9C6304 80240F24 93D3006D */  lbu       $s3, 0x6d($fp)
/* 9C6308 80240F28 32C2FFFF */  andi      $v0, $s6, 0xffff
/* 9C630C 80240F2C A7B30010 */  sh        $s3, 0x10($sp)
/* 9C6310 80240F30 93D2006E */  lbu       $s2, 0x6e($fp)
/* 9C6314 80240F34 93C7006F */  lbu       $a3, 0x6f($fp)
/* 9C6318 80240F38 3274FFFF */  andi      $s4, $s3, 0xffff
/* 9C631C 80240F3C 12820003 */  beq       $s4, $v0, .L80240F4C
/* 9C6320 80240F40 A7A7001E */   sh       $a3, 0x1e($sp)
/* 9C6324 80240F44 0000B82D */  daddu     $s7, $zero, $zero
/* 9C6328 80240F48 02E0802D */  daddu     $s0, $s7, $zero
.L80240F4C:
/* 9C632C 80240F4C 3202FFFF */  andi      $v0, $s0, 0xffff
/* 9C6330 80240F50 14400016 */  bnez      $v0, .L80240FAC
/* 9C6334 80240F54 0220202D */   daddu    $a0, $s1, $zero
/* 9C6338 80240F58 0C00A67F */  jal       rand_int
/* 9C633C 80240F5C 24040064 */   addiu    $a0, $zero, 0x64
/* 9C6340 80240F60 2842001E */  slti      $v0, $v0, 0x1e
/* 9C6344 80240F64 10400011 */  beqz      $v0, .L80240FAC
/* 9C6348 80240F68 0220202D */   daddu    $a0, $s1, $zero
/* 9C634C 80240F6C 0C00A67F */  jal       rand_int
/* 9C6350 80240F70 2644FFFF */   addiu    $a0, $s2, -1
/* 9C6354 80240F74 0040A82D */  daddu     $s5, $v0, $zero
/* 9C6358 80240F78 0260B02D */  daddu     $s6, $s3, $zero
/* 9C635C 80240F7C 0220202D */  daddu     $a0, $s1, $zero
/* 9C6360 80240F80 3C05F5DE */  lui       $a1, 0xf5de
/* 9C6364 80240F84 34A502DE */  ori       $a1, $a1, 0x2de
/* 9C6368 80240F88 0C0B2026 */  jal       set_variable
/* 9C636C 80240F8C 0280302D */   daddu    $a2, $s4, $zero
/* 9C6370 80240F90 0220202D */  daddu     $a0, $s1, $zero
/* 9C6374 80240F94 3C05F5DE */  lui       $a1, 0xf5de
/* 9C6378 80240F98 34A502DF */  ori       $a1, $a1, 0x2df
/* 9C637C 80240F9C 0C0B2026 */  jal       set_variable
/* 9C6380 80240FA0 32A6FFFF */   andi     $a2, $s5, 0xffff
/* 9C6384 80240FA4 24100001 */  addiu     $s0, $zero, 1
/* 9C6388 80240FA8 0220202D */  daddu     $a0, $s1, $zero
.L80240FAC:
/* 9C638C 80240FAC 3C05F840 */  lui       $a1, 0xf840
/* 9C6390 80240FB0 34A56268 */  ori       $a1, $a1, 0x6268
/* 9C6394 80240FB4 0C0B2026 */  jal       set_variable
/* 9C6398 80240FB8 3206FFFF */   andi     $a2, $s0, 0xffff
/* 9C639C 80240FBC 0220202D */  daddu     $a0, $s1, $zero
/* 9C63A0 80240FC0 3C05F840 */  lui       $a1, 0xf840
/* 9C63A4 80240FC4 34A56269 */  ori       $a1, $a1, 0x6269
/* 9C63A8 80240FC8 0C0B2026 */  jal       set_variable
/* 9C63AC 80240FCC 32E6FFFF */   andi     $a2, $s7, 0xffff
/* 9C63B0 80240FD0 0000202D */  daddu     $a0, $zero, $zero
/* 9C63B4 80240FD4 3C05F5DE */  lui       $a1, 0xf5de
/* 9C63B8 80240FD8 0C0B1EAF */  jal       get_variable
/* 9C63BC 80240FDC 34A502E0 */   ori      $a1, $a1, 0x2e0
/* 9C63C0 80240FE0 0000202D */  daddu     $a0, $zero, $zero
/* 9C63C4 80240FE4 3C05F5DE */  lui       $a1, 0xf5de
/* 9C63C8 80240FE8 34A50180 */  ori       $a1, $a1, 0x180
/* 9C63CC 80240FEC 0C0B1EAF */  jal       get_variable
/* 9C63D0 80240FF0 0040802D */   daddu    $s0, $v0, $zero
/* 9C63D4 80240FF4 0040282D */  daddu     $a1, $v0, $zero
/* 9C63D8 80240FF8 0000182D */  daddu     $v1, $zero, $zero
/* 9C63DC 80240FFC 3C068024 */  lui       $a2, 0x8024
/* 9C63E0 80241000 24C65FE8 */  addiu     $a2, $a2, 0x5fe8
/* 9C63E4 80241004 00C0202D */  daddu     $a0, $a2, $zero
.L80241008:
/* 9C63E8 80241008 8C820000 */  lw        $v0, ($a0)
/* 9C63EC 8024100C 00A2102A */  slt       $v0, $a1, $v0
/* 9C63F0 80241010 14400006 */  bnez      $v0, .L8024102C
/* 9C63F4 80241014 000310C0 */   sll      $v0, $v1, 3
/* 9C63F8 80241018 24630001 */  addiu     $v1, $v1, 1
/* 9C63FC 8024101C 28620008 */  slti      $v0, $v1, 8
/* 9C6400 80241020 1440FFF9 */  bnez      $v0, .L80241008
/* 9C6404 80241024 24840008 */   addiu    $a0, $a0, 8
/* 9C6408 80241028 000310C0 */  sll       $v0, $v1, 3
.L8024102C:
/* 9C640C 8024102C 00461021 */  addu      $v0, $v0, $a2
/* 9C6410 80241030 8C420004 */  lw        $v0, 4($v0)
/* 9C6414 80241034 97A30010 */  lhu       $v1, 0x10($sp)
/* 9C6418 80241038 0202202A */  slt       $a0, $s0, $v0
/* 9C641C 8024103C 32C2FFFF */  andi      $v0, $s6, 0xffff
/* 9C6420 80241040 14620008 */  bne       $v1, $v0, .L80241064
/* 9C6424 80241044 32A2FFFF */   andi     $v0, $s5, 0xffff
/* 9C6428 80241048 97A7001E */  lhu       $a3, 0x1e($sp)
/* 9C642C 8024104C 14E20005 */  bne       $a3, $v0, .L80241064
/* 9C6430 80241050 32E2FFFF */   andi     $v0, $s7, 0xffff
/* 9C6434 80241054 14400003 */  bnez      $v0, .L80241064
/* 9C6438 80241058 00000000 */   nop      
/* 9C643C 8024105C 14800008 */  bnez      $a0, .L80241080
/* 9C6440 80241060 24020001 */   addiu    $v0, $zero, 1
.L80241064:
/* 9C6444 80241064 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 9C6448 80241068 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 9C644C 8024106C 80420075 */  lb        $v0, 0x75($v0)
/* 9C6450 80241070 10400005 */  beqz      $v0, .L80241088
/* 9C6454 80241074 00000000 */   nop      
/* 9C6458 80241078 10800003 */  beqz      $a0, .L80241088
/* 9C645C 8024107C 24020001 */   addiu    $v0, $zero, 1
.L80241080:
/* 9C6460 80241080 08090425 */  j         .L80241094
/* 9C6464 80241084 AE220084 */   sw       $v0, 0x84($s1)
.L80241088:
/* 9C6468 80241088 0C00F9EB */  jal       kill_enemy
/* 9C646C 8024108C 03C0202D */   daddu    $a0, $fp, $zero
/* 9C6470 80241090 AE200084 */  sw        $zero, 0x84($s1)
.L80241094:
/* 9C6474 80241094 8FBF0044 */  lw        $ra, 0x44($sp)
/* 9C6478 80241098 8FBE0040 */  lw        $fp, 0x40($sp)
/* 9C647C 8024109C 8FB7003C */  lw        $s7, 0x3c($sp)
/* 9C6480 802410A0 8FB60038 */  lw        $s6, 0x38($sp)
/* 9C6484 802410A4 8FB50034 */  lw        $s5, 0x34($sp)
/* 9C6488 802410A8 8FB40030 */  lw        $s4, 0x30($sp)
/* 9C648C 802410AC 8FB3002C */  lw        $s3, 0x2c($sp)
/* 9C6490 802410B0 8FB20028 */  lw        $s2, 0x28($sp)
/* 9C6494 802410B4 8FB10024 */  lw        $s1, 0x24($sp)
/* 9C6498 802410B8 8FB00020 */  lw        $s0, 0x20($sp)
/* 9C649C 802410BC 24020002 */  addiu     $v0, $zero, 2
/* 9C64A0 802410C0 03E00008 */  jr        $ra
/* 9C64A4 802410C4 27BD0048 */   addiu    $sp, $sp, 0x48
