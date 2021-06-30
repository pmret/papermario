.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_8010BF30
.word L800E6DD8_80288, L800E6F14_803C4, L800E6FC8_80478, L800E7044_804F4, L800E7090_80540, L800E726C_8071C, L800E726C_8071C, L800E726C_8071C, L800E726C_8071C, L800E726C_8071C, L800E7208_806B8, 0

.section .text

glabel check_input_open_menus
/* 80194 800E6CE4 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 80198 800E6CE8 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* 8019C 800E6CEC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 801A0 800E6CF0 AFB3001C */  sw        $s3, 0x1c($sp)
/* 801A4 800E6CF4 3C138011 */  lui       $s3, %hi(D_8010EBB0)
/* 801A8 800E6CF8 2673EBB0 */  addiu     $s3, $s3, %lo(D_8010EBB0)
/* 801AC 800E6CFC AFB40020 */  sw        $s4, 0x20($sp)
/* 801B0 800E6D00 3C148011 */  lui       $s4, %hi(gPlayerStatus)
/* 801B4 800E6D04 2694EFC8 */  addiu     $s4, $s4, %lo(gPlayerStatus)
/* 801B8 800E6D08 AFBF0024 */  sw        $ra, 0x24($sp)
/* 801BC 800E6D0C AFB20018 */  sw        $s2, 0x18($sp)
/* 801C0 800E6D10 AFB10014 */  sw        $s1, 0x14($sp)
/* 801C4 800E6D14 AFB00010 */  sw        $s0, 0x10($sp)
/* 801C8 800E6D18 80620078 */  lb        $v0, 0x78($v1)
/* 801CC 800E6D1C 3C128011 */  lui       $s2, %hi(D_8010C9C8)
/* 801D0 800E6D20 2652C9C8 */  addiu     $s2, $s2, %lo(D_8010C9C8)
/* 801D4 800E6D24 14400151 */  bnez      $v0, L800E726C_8071C
/* 801D8 800E6D28 00000000 */   nop
/* 801DC 800E6D2C 9062007E */  lbu       $v0, 0x7e($v1)
/* 801E0 800E6D30 30420001 */  andi      $v0, $v0, 1
/* 801E4 800E6D34 1440014D */  bnez      $v0, L800E726C_8071C
/* 801E8 800E6D38 0000202D */   daddu    $a0, $zero, $zero
/* 801EC 800E6D3C 3C05F5DE */  lui       $a1, 0xf5de
/* 801F0 800E6D40 0C0B1EAF */  jal       get_variable
/* 801F4 800E6D44 34A50180 */   ori      $a1, $a1, 0x180
/* 801F8 800E6D48 2403FF80 */  addiu     $v1, $zero, -0x80
/* 801FC 800E6D4C 10430147 */  beq       $v0, $v1, L800E726C_8071C
/* 80200 800E6D50 00000000 */   nop
/* 80204 800E6D54 82620000 */  lb        $v0, ($s3)
/* 80208 800E6D58 1040000A */  beqz      $v0, .L800E6D84
/* 8020C 800E6D5C 00000000 */   nop
/* 80210 800E6D60 92620003 */  lbu       $v0, 3($s3)
/* 80214 800E6D64 2442FFF9 */  addiu     $v0, $v0, -7
/* 80218 800E6D68 2C420003 */  sltiu     $v0, $v0, 3
/* 8021C 800E6D6C 10400005 */  beqz      $v0, .L800E6D84
/* 80220 800E6D70 0000202D */   daddu    $a0, $zero, $zero
/* 80224 800E6D74 8E710008 */  lw        $s1, 8($s3)
/* 80228 800E6D78 8E70000C */  lw        $s0, 0xc($s3)
/* 8022C 800E6D7C 08039B65 */  j         .L800E6D94
/* 80230 800E6D80 3C05F5DE */   lui      $a1, 0xf5de
.L800E6D84:
/* 80234 800E6D84 8E9100DC */  lw        $s1, 0xdc($s4)
/* 80238 800E6D88 8E9000E0 */  lw        $s0, 0xe0($s4)
/* 8023C 800E6D8C 0000202D */  daddu     $a0, $zero, $zero
/* 80240 800E6D90 3C05F5DE */  lui       $a1, 0xf5de
.L800E6D94:
/* 80244 800E6D94 0C0B1EAF */  jal       get_variable
/* 80248 800E6D98 34A50180 */   ori      $a1, $a1, 0x180
/* 8024C 800E6D9C 28420060 */  slti      $v0, $v0, 0x60
/* 80250 800E6DA0 14400003 */  bnez      $v0, .L800E6DB0
/* 80254 800E6DA4 2402FFFC */   addiu    $v0, $zero, -4
/* 80258 800E6DA8 02228824 */  and       $s1, $s1, $v0
/* 8025C 800E6DAC 02028024 */  and       $s0, $s0, $v0
.L800E6DB0:
/* 80260 800E6DB0 3C038011 */  lui       $v1, %hi(D_8010CD00)
/* 80264 800E6DB4 8463CD00 */  lh        $v1, %lo(D_8010CD00)($v1)
/* 80268 800E6DB8 2C62000B */  sltiu     $v0, $v1, 0xb
/* 8026C 800E6DBC 1040012B */  beqz      $v0, L800E726C_8071C
/* 80270 800E6DC0 00031080 */   sll      $v0, $v1, 2
/* 80274 800E6DC4 3C018011 */  lui       $at, %hi(jtbl_8010BF30)
/* 80278 800E6DC8 00220821 */  addu      $at, $at, $v0
/* 8027C 800E6DCC 8C22BF30 */  lw        $v0, %lo(jtbl_8010BF30)($at)
/* 80280 800E6DD0 00400008 */  jr        $v0
/* 80284 800E6DD4 00000000 */   nop
glabel L800E6DD8_80288
/* 80288 800E6DD8 0220202D */  daddu     $a0, $s1, $zero
/* 8028C 800E6DDC 0C039A77 */  jal       can_pause
/* 80290 800E6DE0 0200282D */   daddu    $a1, $s0, $zero
/* 80294 800E6DE4 10400121 */  beqz      $v0, L800E726C_8071C
/* 80298 800E6DE8 24020001 */   addiu    $v0, $zero, 1
/* 8029C 800E6DEC 3C038011 */  lui       $v1, %hi(D_8010CCF8)
/* 802A0 800E6DF0 2463CCF8 */  addiu     $v1, $v1, %lo(D_8010CCF8)
/* 802A4 800E6DF4 A4620000 */  sh        $v0, ($v1)
/* 802A8 800E6DF8 32020001 */  andi      $v0, $s0, 1
/* 802AC 800E6DFC 54400001 */  bnel      $v0, $zero, .L800E6E04
/* 802B0 800E6E00 A4600000 */   sh       $zero, ($v1)
.L800E6E04:
/* 802B4 800E6E04 32021000 */  andi      $v0, $s0, 0x1000
/* 802B8 800E6E08 10400002 */  beqz      $v0, .L800E6E14
/* 802BC 800E6E0C 24020002 */   addiu    $v0, $zero, 2
/* 802C0 800E6E10 A4620000 */  sh        $v0, ($v1)
.L800E6E14:
/* 802C4 800E6E14 3C018011 */  lui       $at, %hi(D_8010C9C0)
/* 802C8 800E6E18 A420C9C0 */  sh        $zero, %lo(D_8010C9C0)($at)
.L800E6E1C:
/* 802CC 800E6E1C 3C038011 */  lui       $v1, %hi(D_8010CCF8)
/* 802D0 800E6E20 8463CCF8 */  lh        $v1, %lo(D_8010CCF8)($v1)
/* 802D4 800E6E24 10600005 */  beqz      $v1, .L800E6E3C
/* 802D8 800E6E28 24020001 */   addiu    $v0, $zero, 1
/* 802DC 800E6E2C 1062001F */  beq       $v1, $v0, .L800E6EAC
/* 802E0 800E6E30 00000000 */   nop
/* 802E4 800E6E34 08039BB2 */  j         .L800E6EC8
/* 802E8 800E6E38 00000000 */   nop
.L800E6E3C:
/* 802EC 800E6E3C 8E820000 */  lw        $v0, ($s4)
/* 802F0 800E6E40 30420040 */  andi      $v0, $v0, 0x40
/* 802F4 800E6E44 10400009 */  beqz      $v0, .L800E6E6C
/* 802F8 800E6E48 00000000 */   nop
/* 802FC 800E6E4C 0C05272D */  jal       sfx_play_sound
/* 80300 800E6E50 2404021D */   addiu    $a0, $zero, 0x21d
/* 80304 800E6E54 3C028011 */  lui       $v0, %hi(D_8010C9C0)
/* 80308 800E6E58 8442C9C0 */  lh        $v0, %lo(D_8010C9C0)($v0)
/* 8030C 800E6E5C 10400103 */  beqz      $v0, L800E726C_8071C
/* 80310 800E6E60 00000000 */   nop
/* 80314 800E6E64 08039C72 */  j         .L800E71C8
/* 80318 800E6E68 00000000 */   nop
.L800E6E6C:
/* 8031C 800E6E6C 0C039ADE */  jal       setup_partner_popup
/* 80320 800E6E70 0240202D */   daddu    $a0, $s2, $zero
/* 80324 800E6E74 104000FD */  beqz      $v0, L800E726C_8071C
/* 80328 800E6E78 24030001 */   addiu    $v1, $zero, 1
/* 8032C 800E6E7C AE420324 */  sw        $v0, 0x324($s2)
/* 80330 800E6E80 3C028011 */  lui       $v0, %hi(gPlayerData)
/* 80334 800E6E84 2442F290 */  addiu     $v0, $v0, %lo(gPlayerData)
/* 80338 800E6E88 80420012 */  lb        $v0, 0x12($v0)
/* 8033C 800E6E8C AE430318 */  sw        $v1, 0x318($s2)
/* 80340 800E6E90 00021080 */  sll       $v0, $v0, 2
/* 80344 800E6E94 3C018009 */  lui       $at, %hi(D_8008EEF0)
/* 80348 800E6E98 00220821 */  addu      $at, $at, $v0
/* 8034C 800E6E9C 8C22EEF0 */  lw        $v0, %lo(D_8008EEF0)($at)
/* 80350 800E6EA0 2442FFFF */  addiu     $v0, $v0, -1
/* 80354 800E6EA4 08039BB2 */  j         .L800E6EC8
/* 80358 800E6EA8 AE420328 */   sw       $v0, 0x328($s2)
.L800E6EAC:
/* 8035C 800E6EAC 0C039B11 */  jal       setup_item_popup
/* 80360 800E6EB0 0240202D */   daddu    $a0, $s2, $zero
/* 80364 800E6EB4 104000ED */  beqz      $v0, L800E726C_8071C
/* 80368 800E6EB8 00000000 */   nop
/* 8036C 800E6EBC AE400318 */  sw        $zero, 0x318($s2)
/* 80370 800E6EC0 AE420324 */  sw        $v0, 0x324($s2)
/* 80374 800E6EC4 AE400328 */  sw        $zero, 0x328($s2)
.L800E6EC8:
/* 80378 800E6EC8 8E820000 */  lw        $v0, ($s4)
/* 8037C 800E6ECC 34420020 */  ori       $v0, $v0, 0x20
/* 80380 800E6ED0 0C03805E */  jal       disable_player_input
/* 80384 800E6ED4 AE820000 */   sw       $v0, ($s4)
/* 80388 800E6ED8 0C03BD8A */  jal       partner_disable_input
/* 8038C 800E6EDC 00000000 */   nop
/* 80390 800E6EE0 24020003 */  addiu     $v0, $zero, 3
/* 80394 800E6EE4 3C018011 */  lui       $at, %hi(D_8010CCFA)
/* 80398 800E6EE8 A422CCFA */  sh        $v0, %lo(D_8010CCFA)($at)
/* 8039C 800E6EEC 92820015 */  lbu       $v0, 0x15($s4)
/* 803A0 800E6EF0 24030001 */  addiu     $v1, $zero, 1
/* 803A4 800E6EF4 3C018011 */  lui       $at, %hi(D_8010CD00)
/* 803A8 800E6EF8 A423CD00 */  sh        $v1, %lo(D_8010CD00)($at)
/* 803AC 800E6EFC 00021600 */  sll       $v0, $v0, 0x18
/* 803B0 800E6F00 00021603 */  sra       $v0, $v0, 0x18
/* 803B4 800E6F04 3C018011 */  lui       $at, %hi(D_8010CCFE)
/* 803B8 800E6F08 A422CCFE */  sh        $v0, %lo(D_8010CCFE)($at)
/* 803BC 800E6F0C 08039C9B */  j         L800E726C_8071C
/* 803C0 800E6F10 00000000 */   nop
glabel L800E6F14_803C4
/* 803C4 800E6F14 0C039A41 */  jal       func_800E6904
/* 803C8 800E6F18 00000000 */   nop
/* 803CC 800E6F1C 1040000B */  beqz      $v0, .L800E6F4C
/* 803D0 800E6F20 00000000 */   nop
/* 803D4 800E6F24 0C04D07A */  jal       is_picking_up_item
/* 803D8 800E6F28 00000000 */   nop
/* 803DC 800E6F2C 14400007 */  bnez      $v0, .L800E6F4C
/* 803E0 800E6F30 00000000 */   nop
/* 803E4 800E6F34 3C028011 */  lui       $v0, %hi(D_8010CCFE)
/* 803E8 800E6F38 8442CCFE */  lh        $v0, %lo(D_8010CCFE)($v0)
/* 803EC 800E6F3C 82830015 */  lb        $v1, 0x15($s4)
/* 803F0 800E6F40 0043102A */  slt       $v0, $v0, $v1
/* 803F4 800E6F44 10400010 */  beqz      $v0, .L800E6F88
/* 803F8 800E6F48 00000000 */   nop
.L800E6F4C:
/* 803FC 800E6F4C 8E820000 */  lw        $v0, ($s4)
/* 80400 800E6F50 2403FFDF */  addiu     $v1, $zero, -0x21
/* 80404 800E6F54 00431024 */  and       $v0, $v0, $v1
/* 80408 800E6F58 0C038069 */  jal       enable_player_input
/* 8040C 800E6F5C AE820000 */   sw       $v0, ($s4)
/* 80410 800E6F60 0C03BD80 */  jal       partner_enable_input
/* 80414 800E6F64 00000000 */   nop
/* 80418 800E6F68 3C028011 */  lui       $v0, %hi(D_8010C9C0)
/* 8041C 800E6F6C 8442C9C0 */  lh        $v0, %lo(D_8010C9C0)($v0)
/* 80420 800E6F70 3C018011 */  lui       $at, %hi(D_8010CD00)
/* 80424 800E6F74 A420CD00 */  sh        $zero, %lo(D_8010CD00)($at)
/* 80428 800E6F78 104000BC */  beqz      $v0, L800E726C_8071C
/* 8042C 800E6F7C 00000000 */   nop
/* 80430 800E6F80 08039C72 */  j         .L800E71C8
/* 80434 800E6F84 00000000 */   nop
.L800E6F88:
/* 80438 800E6F88 3C038011 */  lui       $v1, %hi(D_8010CCFA)
/* 8043C 800E6F8C 2463CCFA */  addiu     $v1, $v1, %lo(D_8010CCFA)
/* 80440 800E6F90 94620000 */  lhu       $v0, ($v1)
/* 80444 800E6F94 2442FFFF */  addiu     $v0, $v0, -1
/* 80448 800E6F98 A4620000 */  sh        $v0, ($v1)
/* 8044C 800E6F9C 00021400 */  sll       $v0, $v0, 0x10
/* 80450 800E6FA0 144000B2 */  bnez      $v0, L800E726C_8071C
/* 80454 800E6FA4 24040002 */   addiu    $a0, $zero, 2
/* 80458 800E6FA8 3C02800A */  lui       $v0, %hi(gOverrideFlags)
/* 8045C 800E6FAC 2442A650 */  addiu     $v0, $v0, %lo(gOverrideFlags)
/* 80460 800E6FB0 8C430000 */  lw        $v1, ($v0)
/* 80464 800E6FB4 3C018011 */  lui       $at, %hi(D_8010CD00)
/* 80468 800E6FB8 A424CD00 */  sh        $a0, %lo(D_8010CD00)($at)
/* 8046C 800E6FBC 34630040 */  ori       $v1, $v1, 0x40
/* 80470 800E6FC0 08039C9B */  j         L800E726C_8071C
/* 80474 800E6FC4 AC430000 */   sw       $v1, ($v0)
glabel L800E6FC8_80478
/* 80478 800E6FC8 3C038011 */  lui       $v1, %hi(D_8010CCF8)
/* 8047C 800E6FCC 8463CCF8 */  lh        $v1, %lo(D_8010CCF8)($v1)
/* 80480 800E6FD0 24020002 */  addiu     $v0, $zero, 2
/* 80484 800E6FD4 1462000C */  bne       $v1, $v0, .L800E7008
/* 80488 800E6FD8 00000000 */   nop
/* 8048C 800E6FDC 0C00CD3C */  jal       set_game_mode
/* 80490 800E6FE0 2404000A */   addiu    $a0, $zero, 0xa
/* 80494 800E6FE4 0C05272D */  jal       sfx_play_sound
/* 80498 800E6FE8 240400C5 */   addiu    $a0, $zero, 0xc5
/* 8049C 800E6FEC 2402000A */  addiu     $v0, $zero, 0xa
/* 804A0 800E6FF0 3C018011 */  lui       $at, %hi(D_8010CCFA)
/* 804A4 800E6FF4 A422CCFA */  sh        $v0, %lo(D_8010CCFA)($at)
/* 804A8 800E6FF8 3C018011 */  lui       $at, %hi(D_8010CD00)
/* 804AC 800E6FFC A422CD00 */  sh        $v0, %lo(D_8010CD00)($at)
/* 804B0 800E7000 08039C9B */  j         L800E726C_8071C
/* 804B4 800E7004 00000000 */   nop
.L800E7008:
/* 804B8 800E7008 0C03D390 */  jal       create_popup_menu
/* 804BC 800E700C 0240202D */   daddu    $a0, $s2, $zero
/* 804C0 800E7010 0C009C22 */  jal       set_time_freeze_mode
/* 804C4 800E7014 24040003 */   addiu    $a0, $zero, 3
/* 804C8 800E7018 82620000 */  lb        $v0, ($s3)
/* 804CC 800E701C 14400003 */  bnez      $v0, .L800E702C
/* 804D0 800E7020 00000000 */   nop
/* 804D4 800E7024 0C039769 */  jal       set_action_state
/* 804D8 800E7028 0000202D */   daddu    $a0, $zero, $zero
.L800E702C:
/* 804DC 800E702C 3C038011 */  lui       $v1, %hi(D_8010CD00)
/* 804E0 800E7030 2463CD00 */  addiu     $v1, $v1, %lo(D_8010CD00)
/* 804E4 800E7034 94620000 */  lhu       $v0, ($v1)
/* 804E8 800E7038 24420001 */  addiu     $v0, $v0, 1
/* 804EC 800E703C 08039C9B */  j         L800E726C_8071C
/* 804F0 800E7040 A4620000 */   sh       $v0, ($v1)
glabel L800E7044_804F4
/* 804F4 800E7044 2402FFFF */  addiu     $v0, $zero, -1
/* 804F8 800E7048 8643032C */  lh        $v1, 0x32c($s2)
/* 804FC 800E704C 10620087 */  beq       $v1, $v0, L800E726C_8071C
/* 80500 800E7050 9644032C */   lhu      $a0, 0x32c($s2)
/* 80504 800E7054 3C018011 */  lui       $at, %hi(D_8010CCFC)
/* 80508 800E7058 A424CCFC */  sh        $a0, %lo(D_8010CCFC)($at)
/* 8050C 800E705C 10600083 */  beqz      $v1, L800E726C_8071C
/* 80510 800E7060 00000000 */   nop
/* 80514 800E7064 0C03C4EC */  jal       hide_popup_menu
/* 80518 800E7068 00000000 */   nop
/* 8051C 800E706C 3C028011 */  lui       $v0, %hi(D_8010CD00)
/* 80520 800E7070 2442CD00 */  addiu     $v0, $v0, %lo(D_8010CD00)
/* 80524 800E7074 94430000 */  lhu       $v1, ($v0)
/* 80528 800E7078 2404000F */  addiu     $a0, $zero, 0xf
/* 8052C 800E707C 3C018011 */  lui       $at, %hi(D_8010CCFA)
/* 80530 800E7080 A424CCFA */  sh        $a0, %lo(D_8010CCFA)($at)
/* 80534 800E7084 24630001 */  addiu     $v1, $v1, 1
/* 80538 800E7088 08039C9B */  j         L800E726C_8071C
/* 8053C 800E708C A4430000 */   sh       $v1, ($v0)
glabel L800E7090_80540
/* 80540 800E7090 3C038011 */  lui       $v1, %hi(D_8010CCFA)
/* 80544 800E7094 2463CCFA */  addiu     $v1, $v1, %lo(D_8010CCFA)
/* 80548 800E7098 94620000 */  lhu       $v0, ($v1)
/* 8054C 800E709C 2442FFFF */  addiu     $v0, $v0, -1
/* 80550 800E70A0 A4620000 */  sh        $v0, ($v1)
/* 80554 800E70A4 00021400 */  sll       $v0, $v0, 0x10
/* 80558 800E70A8 14400070 */  bnez      $v0, L800E726C_8071C
/* 8055C 800E70AC 00000000 */   nop
/* 80560 800E70B0 0C03C54E */  jal       destroy_popup_menu
/* 80564 800E70B4 00000000 */   nop
/* 80568 800E70B8 3C018011 */  lui       $at, %hi(D_8010CD00)
/* 8056C 800E70BC A420CD00 */  sh        $zero, %lo(D_8010CD00)($at)
/* 80570 800E70C0 0C038069 */  jal       enable_player_input
/* 80574 800E70C4 00000000 */   nop
/* 80578 800E70C8 0C03BD80 */  jal       partner_enable_input
/* 8057C 800E70CC 00000000 */   nop
/* 80580 800E70D0 3C108011 */  lui       $s0, %hi(D_8010CCFC)
/* 80584 800E70D4 2610CCFC */  addiu     $s0, $s0, %lo(D_8010CCFC)
/* 80588 800E70D8 86030000 */  lh        $v1, ($s0)
/* 8058C 800E70DC 2402FFFE */  addiu     $v0, $zero, -2
/* 80590 800E70E0 1462001B */  bne       $v1, $v0, .L800E7150
/* 80594 800E70E4 00000000 */   nop
/* 80598 800E70E8 0C039ADE */  jal       setup_partner_popup
/* 8059C 800E70EC 0240202D */   daddu    $a0, $s2, $zero
/* 805A0 800E70F0 10400005 */  beqz      $v0, .L800E7108
/* 805A4 800E70F4 240200FF */   addiu    $v0, $zero, 0xff
/* 805A8 800E70F8 0C039B11 */  jal       setup_item_popup
/* 805AC 800E70FC 0240202D */   daddu    $a0, $s2, $zero
/* 805B0 800E7100 14400003 */  bnez      $v0, .L800E7110
/* 805B4 800E7104 240200FF */   addiu    $v0, $zero, 0xff
.L800E7108:
/* 805B8 800E7108 08039C54 */  j         .L800E7150
/* 805BC 800E710C A6020000 */   sh       $v0, ($s0)
.L800E7110:
/* 805C0 800E7110 3C048011 */  lui       $a0, %hi(D_8010CCF8)
/* 805C4 800E7114 2484CCF8 */  addiu     $a0, $a0, %lo(D_8010CCF8)
/* 805C8 800E7118 84830000 */  lh        $v1, ($a0)
/* 805CC 800E711C 10600005 */  beqz      $v1, .L800E7134
/* 805D0 800E7120 24020001 */   addiu    $v0, $zero, 1
/* 805D4 800E7124 10620006 */  beq       $v1, $v0, .L800E7140
/* 805D8 800E7128 24020001 */   addiu    $v0, $zero, 1
/* 805DC 800E712C 08039C51 */  j         .L800E7144
/* 805E0 800E7130 00000000 */   nop
.L800E7134:
/* 805E4 800E7134 24020001 */  addiu     $v0, $zero, 1
/* 805E8 800E7138 08039C51 */  j         .L800E7144
/* 805EC 800E713C A4820000 */   sh       $v0, ($a0)
.L800E7140:
/* 805F0 800E7140 A4800000 */  sh        $zero, ($a0)
.L800E7144:
/* 805F4 800E7144 3C018011 */  lui       $at, %hi(D_8010C9C0)
/* 805F8 800E7148 08039B87 */  j         .L800E6E1C
/* 805FC 800E714C A422C9C0 */   sh       $v0, %lo(D_8010C9C0)($at)
.L800E7150:
/* 80600 800E7150 3C038011 */  lui       $v1, %hi(D_8010CCFC)
/* 80604 800E7154 8463CCFC */  lh        $v1, %lo(D_8010CCFC)($v1)
/* 80608 800E7158 240200FF */  addiu     $v0, $zero, 0xff
/* 8060C 800E715C 1062001A */  beq       $v1, $v0, .L800E71C8
/* 80610 800E7160 00000000 */   nop
/* 80614 800E7164 3C048011 */  lui       $a0, %hi(D_8010CCF8)
/* 80618 800E7168 8484CCF8 */  lh        $a0, %lo(D_8010CCF8)($a0)
/* 8061C 800E716C 10800005 */  beqz      $a0, .L800E7184
/* 80620 800E7170 24020001 */   addiu    $v0, $zero, 1
/* 80624 800E7174 1082000A */  beq       $a0, $v0, .L800E71A0
/* 80628 800E7178 2462FFFF */   addiu    $v0, $v1, -1
/* 8062C 800E717C 08039C72 */  j         .L800E71C8
/* 80630 800E7180 00000000 */   nop
.L800E7184:
/* 80634 800E7184 2462FFFF */  addiu     $v0, $v1, -1
/* 80638 800E7188 00021080 */  sll       $v0, $v0, 2
/* 8063C 800E718C 02421021 */  addu      $v0, $s2, $v0
/* 80640 800E7190 0C03AC5A */  jal       switch_to_partner
/* 80644 800E7194 8C440108 */   lw       $a0, 0x108($v0)
/* 80648 800E7198 08039C72 */  j         .L800E71C8
/* 8064C 800E719C 00000000 */   nop
.L800E71A0:
/* 80650 800E71A0 00021080 */  sll       $v0, $v0, 2
/* 80654 800E71A4 02421021 */  addu      $v0, $s2, $v0
/* 80658 800E71A8 0C03A900 */  jal       use_consumable
/* 8065C 800E71AC 8C440108 */   lw       $a0, 0x108($v0)
/* 80660 800E71B0 3C04800A */  lui       $a0, %hi(gOverrideFlags)
/* 80664 800E71B4 2484A650 */  addiu     $a0, $a0, %lo(gOverrideFlags)
/* 80668 800E71B8 8C820000 */  lw        $v0, ($a0)
/* 8066C 800E71BC 3C030020 */  lui       $v1, 0x20
/* 80670 800E71C0 00431025 */  or        $v0, $v0, $v1
/* 80674 800E71C4 AC820000 */  sw        $v0, ($a0)
.L800E71C8:
/* 80678 800E71C8 0C039A18 */  jal       func_800E6860
/* 8067C 800E71CC 00000000 */   nop
/* 80680 800E71D0 0000202D */  daddu     $a0, $zero, $zero
/* 80684 800E71D4 2403FFDF */  addiu     $v1, $zero, -0x21
/* 80688 800E71D8 8E820000 */  lw        $v0, ($s4)
/* 8068C 800E71DC 3C05800A */  lui       $a1, %hi(gOverrideFlags)
/* 80690 800E71E0 24A5A650 */  addiu     $a1, $a1, %lo(gOverrideFlags)
/* 80694 800E71E4 00431024 */  and       $v0, $v0, $v1
/* 80698 800E71E8 AE820000 */  sw        $v0, ($s4)
/* 8069C 800E71EC 8CA20000 */  lw        $v0, ($a1)
/* 806A0 800E71F0 2403FFBF */  addiu     $v1, $zero, -0x41
/* 806A4 800E71F4 00431024 */  and       $v0, $v0, $v1
/* 806A8 800E71F8 0C009C22 */  jal       set_time_freeze_mode
/* 806AC 800E71FC ACA20000 */   sw       $v0, ($a1)
/* 806B0 800E7200 08039C9B */  j         L800E726C_8071C
/* 806B4 800E7204 00000000 */   nop
glabel L800E7208_806B8
/* 806B8 800E7208 3C038011 */  lui       $v1, %hi(D_8010CCFA)
/* 806BC 800E720C 2463CCFA */  addiu     $v1, $v1, %lo(D_8010CCFA)
/* 806C0 800E7210 94620000 */  lhu       $v0, ($v1)
/* 806C4 800E7214 2442FFFF */  addiu     $v0, $v0, -1
/* 806C8 800E7218 A4620000 */  sh        $v0, ($v1)
/* 806CC 800E721C 00021400 */  sll       $v0, $v0, 0x10
/* 806D0 800E7220 14400012 */  bnez      $v0, L800E726C_8071C
/* 806D4 800E7224 00000000 */   nop
/* 806D8 800E7228 0C039A18 */  jal       func_800E6860
/* 806DC 800E722C 00000000 */   nop
/* 806E0 800E7230 2403FFDF */  addiu     $v1, $zero, -0x21
/* 806E4 800E7234 8E820000 */  lw        $v0, ($s4)
/* 806E8 800E7238 3C04800A */  lui       $a0, %hi(gOverrideFlags)
/* 806EC 800E723C 2484A650 */  addiu     $a0, $a0, %lo(gOverrideFlags)
/* 806F0 800E7240 3C018011 */  lui       $at, %hi(D_8010CD00)
/* 806F4 800E7244 A420CD00 */  sh        $zero, %lo(D_8010CD00)($at)
/* 806F8 800E7248 00431024 */  and       $v0, $v0, $v1
/* 806FC 800E724C AE820000 */  sw        $v0, ($s4)
/* 80700 800E7250 8C820000 */  lw        $v0, ($a0)
/* 80704 800E7254 2403FFBF */  addiu     $v1, $zero, -0x41
/* 80708 800E7258 00431024 */  and       $v0, $v0, $v1
/* 8070C 800E725C 0C038069 */  jal       enable_player_input
/* 80710 800E7260 AC820000 */   sw       $v0, ($a0)
/* 80714 800E7264 0C03BD80 */  jal       partner_enable_input
/* 80718 800E7268 00000000 */   nop
glabel L800E726C_8071C
/* 8071C 800E726C 8FBF0024 */  lw        $ra, 0x24($sp)
/* 80720 800E7270 8FB40020 */  lw        $s4, 0x20($sp)
/* 80724 800E7274 8FB3001C */  lw        $s3, 0x1c($sp)
/* 80728 800E7278 8FB20018 */  lw        $s2, 0x18($sp)
/* 8072C 800E727C 8FB10014 */  lw        $s1, 0x14($sp)
/* 80730 800E7280 8FB00010 */  lw        $s0, 0x10($sp)
/* 80734 800E7284 03E00008 */  jr        $ra
/* 80738 800E7288 27BD0028 */   addiu    $sp, $sp, 0x28
