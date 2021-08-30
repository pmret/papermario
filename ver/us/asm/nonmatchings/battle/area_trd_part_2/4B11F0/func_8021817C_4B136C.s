.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021817C_4B136C
/* 4B136C 8021817C 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 4B1370 80218180 AFB10034 */  sw        $s1, 0x34($sp)
/* 4B1374 80218184 0080882D */  daddu     $s1, $a0, $zero
/* 4B1378 80218188 AFBF0054 */  sw        $ra, 0x54($sp)
/* 4B137C 8021818C AFBE0050 */  sw        $fp, 0x50($sp)
/* 4B1380 80218190 AFB7004C */  sw        $s7, 0x4c($sp)
/* 4B1384 80218194 AFB60048 */  sw        $s6, 0x48($sp)
/* 4B1388 80218198 AFB50044 */  sw        $s5, 0x44($sp)
/* 4B138C 8021819C AFB40040 */  sw        $s4, 0x40($sp)
/* 4B1390 802181A0 AFB3003C */  sw        $s3, 0x3c($sp)
/* 4B1394 802181A4 AFB20038 */  sw        $s2, 0x38($sp)
/* 4B1398 802181A8 AFB00030 */  sw        $s0, 0x30($sp)
/* 4B139C 802181AC 8E30000C */  lw        $s0, 0xc($s1)
/* 4B13A0 802181B0 8E050000 */  lw        $a1, ($s0)
/* 4B13A4 802181B4 0C0B1EAF */  jal       evt_get_variable
/* 4B13A8 802181B8 26100004 */   addiu    $s0, $s0, 4
/* 4B13AC 802181BC 8E050000 */  lw        $a1, ($s0)
/* 4B13B0 802181C0 26100004 */  addiu     $s0, $s0, 4
/* 4B13B4 802181C4 0220202D */  daddu     $a0, $s1, $zero
/* 4B13B8 802181C8 0C0B1EAF */  jal       evt_get_variable
/* 4B13BC 802181CC 0040982D */   daddu    $s3, $v0, $zero
/* 4B13C0 802181D0 8E050000 */  lw        $a1, ($s0)
/* 4B13C4 802181D4 26100004 */  addiu     $s0, $s0, 4
/* 4B13C8 802181D8 0220202D */  daddu     $a0, $s1, $zero
/* 4B13CC 802181DC 0C0B1EAF */  jal       evt_get_variable
/* 4B13D0 802181E0 0040B02D */   daddu    $s6, $v0, $zero
/* 4B13D4 802181E4 8E050000 */  lw        $a1, ($s0)
/* 4B13D8 802181E8 26100004 */  addiu     $s0, $s0, 4
/* 4B13DC 802181EC 0220202D */  daddu     $a0, $s1, $zero
/* 4B13E0 802181F0 0C0B1EAF */  jal       evt_get_variable
/* 4B13E4 802181F4 0040A82D */   daddu    $s5, $v0, $zero
/* 4B13E8 802181F8 8E050000 */  lw        $a1, ($s0)
/* 4B13EC 802181FC 26100004 */  addiu     $s0, $s0, 4
/* 4B13F0 80218200 0220202D */  daddu     $a0, $s1, $zero
/* 4B13F4 80218204 0C0B1EAF */  jal       evt_get_variable
/* 4B13F8 80218208 0040A02D */   daddu    $s4, $v0, $zero
/* 4B13FC 8021820C 8E050000 */  lw        $a1, ($s0)
/* 4B1400 80218210 26100004 */  addiu     $s0, $s0, 4
/* 4B1404 80218214 0220202D */  daddu     $a0, $s1, $zero
/* 4B1408 80218218 0C0B1EAF */  jal       evt_get_variable
/* 4B140C 8021821C 0040902D */   daddu    $s2, $v0, $zero
/* 4B1410 80218220 8E050000 */  lw        $a1, ($s0)
/* 4B1414 80218224 26100004 */  addiu     $s0, $s0, 4
/* 4B1418 80218228 0220202D */  daddu     $a0, $s1, $zero
/* 4B141C 8021822C 0C0B1EAF */  jal       evt_get_variable
/* 4B1420 80218230 AFA20028 */   sw       $v0, 0x28($sp)
/* 4B1424 80218234 8E050000 */  lw        $a1, ($s0)
/* 4B1428 80218238 26100004 */  addiu     $s0, $s0, 4
/* 4B142C 8021823C 0220202D */  daddu     $a0, $s1, $zero
/* 4B1430 80218240 0C0B1EAF */  jal       evt_get_variable
/* 4B1434 80218244 0040F02D */   daddu    $fp, $v0, $zero
/* 4B1438 80218248 8E050000 */  lw        $a1, ($s0)
/* 4B143C 8021824C 26100004 */  addiu     $s0, $s0, 4
/* 4B1440 80218250 0220202D */  daddu     $a0, $s1, $zero
/* 4B1444 80218254 0C0B1EAF */  jal       evt_get_variable
/* 4B1448 80218258 0040B82D */   daddu    $s7, $v0, $zero
/* 4B144C 8021825C 0220202D */  daddu     $a0, $s1, $zero
/* 4B1450 80218260 8E050000 */  lw        $a1, ($s0)
/* 4B1454 80218264 0C0B1EAF */  jal       evt_get_variable
/* 4B1458 80218268 0040802D */   daddu    $s0, $v0, $zero
/* 4B145C 8021826C 0040182D */  daddu     $v1, $v0, $zero
/* 4B1460 80218270 24020002 */  addiu     $v0, $zero, 2
/* 4B1464 80218274 12620012 */  beq       $s3, $v0, .L802182C0
/* 4B1468 80218278 2A620003 */   slti     $v0, $s3, 3
/* 4B146C 8021827C 10400005 */  beqz      $v0, .L80218294
/* 4B1470 80218280 24020001 */   addiu    $v0, $zero, 1
/* 4B1474 80218284 12620008 */  beq       $s3, $v0, .L802182A8
/* 4B1478 80218288 32C400FF */   andi     $a0, $s6, 0xff
/* 4B147C 8021828C 080860C7 */  j         .L8021831C
/* 4B1480 80218290 00000000 */   nop
.L80218294:
/* 4B1484 80218294 24020003 */  addiu     $v0, $zero, 3
/* 4B1488 80218298 12620018 */  beq       $s3, $v0, .L802182FC
/* 4B148C 8021829C 32C400FF */   andi     $a0, $s6, 0xff
/* 4B1490 802182A0 080860C7 */  j         .L8021831C
/* 4B1494 802182A4 00000000 */   nop
.L802182A8:
/* 4B1498 802182A8 32A500FF */  andi      $a1, $s5, 0xff
/* 4B149C 802182AC 328600FF */  andi      $a2, $s4, 0xff
/* 4B14A0 802182B0 0C046F97 */  jal       set_background_color_blend
/* 4B14A4 802182B4 324700FF */   andi     $a3, $s2, 0xff
/* 4B14A8 802182B8 080860C7 */  j         .L8021831C
/* 4B14AC 802182BC 00000000 */   nop
.L802182C0:
/* 4B14B0 802182C0 32C400FF */  andi      $a0, $s6, 0xff
/* 4B14B4 802182C4 32A500FF */  andi      $a1, $s5, 0xff
/* 4B14B8 802182C8 328600FF */  andi      $a2, $s4, 0xff
/* 4B14BC 802182CC 324700FF */  andi      $a3, $s2, 0xff
/* 4B14C0 802182D0 93A2002B */  lbu       $v0, 0x2b($sp)
/* 4B14C4 802182D4 AFB0001C */  sw        $s0, 0x1c($sp)
/* 4B14C8 802182D8 AFA30020 */  sw        $v1, 0x20($sp)
/* 4B14CC 802182DC AFA20010 */  sw        $v0, 0x10($sp)
/* 4B14D0 802182E0 33C200FF */  andi      $v0, $fp, 0xff
/* 4B14D4 802182E4 AFA20014 */  sw        $v0, 0x14($sp)
/* 4B14D8 802182E8 32E200FF */  andi      $v0, $s7, 0xff
/* 4B14DC 802182EC 0C046FAD */  jal       set_model_fog_color_parameters
/* 4B14E0 802182F0 AFA20018 */   sw       $v0, 0x18($sp)
/* 4B14E4 802182F4 080860C7 */  j         .L8021831C
/* 4B14E8 802182F8 00000000 */   nop
.L802182FC:
/* 4B14EC 802182FC 32A500FF */  andi      $a1, $s5, 0xff
/* 4B14F0 80218300 328600FF */  andi      $a2, $s4, 0xff
/* 4B14F4 80218304 324700FF */  andi      $a3, $s2, 0xff
/* 4B14F8 80218308 93A2002B */  lbu       $v0, 0x2b($sp)
/* 4B14FC 8021830C AFA20010 */  sw        $v0, 0x10($sp)
/* 4B1500 80218310 33C200FF */  andi      $v0, $fp, 0xff
/* 4B1504 80218314 0C046FE6 */  jal       set_model_env_color_parameters
/* 4B1508 80218318 AFA20014 */   sw       $v0, 0x14($sp)
.L8021831C:
/* 4B150C 8021831C 8FBF0054 */  lw        $ra, 0x54($sp)
/* 4B1510 80218320 8FBE0050 */  lw        $fp, 0x50($sp)
/* 4B1514 80218324 8FB7004C */  lw        $s7, 0x4c($sp)
/* 4B1518 80218328 8FB60048 */  lw        $s6, 0x48($sp)
/* 4B151C 8021832C 8FB50044 */  lw        $s5, 0x44($sp)
/* 4B1520 80218330 8FB40040 */  lw        $s4, 0x40($sp)
/* 4B1524 80218334 8FB3003C */  lw        $s3, 0x3c($sp)
/* 4B1528 80218338 8FB20038 */  lw        $s2, 0x38($sp)
/* 4B152C 8021833C 8FB10034 */  lw        $s1, 0x34($sp)
/* 4B1530 80218340 8FB00030 */  lw        $s0, 0x30($sp)
/* 4B1534 80218344 24020002 */  addiu     $v0, $zero, 2
/* 4B1538 80218348 03E00008 */  jr        $ra
/* 4B153C 8021834C 27BD0058 */   addiu    $sp, $sp, 0x58
