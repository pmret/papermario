.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C18
/* A491D8 80240C18 27BDFC78 */  addiu     $sp, $sp, -0x388
/* A491DC 80240C1C AFB60378 */  sw        $s6, 0x378($sp)
/* A491E0 80240C20 0080B02D */  daddu     $s6, $a0, $zero
/* A491E4 80240C24 AFBF037C */  sw        $ra, 0x37c($sp)
/* A491E8 80240C28 AFB50374 */  sw        $s5, 0x374($sp)
/* A491EC 80240C2C AFB40370 */  sw        $s4, 0x370($sp)
/* A491F0 80240C30 AFB3036C */  sw        $s3, 0x36c($sp)
/* A491F4 80240C34 AFB20368 */  sw        $s2, 0x368($sp)
/* A491F8 80240C38 AFB10364 */  sw        $s1, 0x364($sp)
/* A491FC 80240C3C AFB00360 */  sw        $s0, 0x360($sp)
/* A49200 80240C40 F7B40380 */  sdc1      $f20, 0x380($sp)
/* A49204 80240C44 8ED20148 */  lw        $s2, 0x148($s6)
/* A49208 80240C48 86440008 */  lh        $a0, 8($s2)
/* A4920C 80240C4C 0C00EABB */  jal       get_npc_unsafe
/* A49210 80240C50 00A0802D */   daddu    $s0, $a1, $zero
/* A49214 80240C54 86440008 */  lh        $a0, 8($s2)
/* A49218 80240C58 0040882D */  daddu     $s1, $v0, $zero
/* A4921C 80240C5C 0C00FB3A */  jal       get_enemy
/* A49220 80240C60 2484FFFF */   addiu    $a0, $a0, -1
/* A49224 80240C64 84440008 */  lh        $a0, 8($v0)
/* A49228 80240C68 0C00EABB */  jal       get_npc_unsafe
/* A4922C 80240C6C 0000A82D */   daddu    $s5, $zero, $zero
/* A49230 80240C70 27B30020 */  addiu     $s3, $sp, 0x20
/* A49234 80240C74 16000005 */  bnez      $s0, .L80240C8C
/* A49238 80240C78 0040A02D */   daddu    $s4, $v0, $zero
/* A4923C 80240C7C 8E4200B0 */  lw        $v0, 0xb0($s2)
/* A49240 80240C80 30420004 */  andi      $v0, $v0, 4
/* A49244 80240C84 10400018 */  beqz      $v0, .L80240CE8
/* A49248 80240C88 00000000 */   nop      
.L80240C8C:
/* A4924C 80240C8C 3C030024 */  lui       $v1, 0x24
/* A49250 80240C90 34630102 */  ori       $v1, $v1, 0x102
/* A49254 80240C94 3C041620 */  lui       $a0, 0x1620
/* A49258 80240C98 AEC00070 */  sw        $zero, 0x70($s6)
/* A4925C 80240C9C 8E220000 */  lw        $v0, ($s1)
/* A49260 80240CA0 34840040 */  ori       $a0, $a0, 0x40
/* A49264 80240CA4 A620008E */  sh        $zero, 0x8e($s1)
/* A49268 80240CA8 00431025 */  or        $v0, $v0, $v1
/* A4926C 80240CAC AE220000 */  sw        $v0, ($s1)
/* A49270 80240CB0 8E420000 */  lw        $v0, ($s2)
/* A49274 80240CB4 3C013ECC */  lui       $at, 0x3ecc
/* A49278 80240CB8 3421CCCD */  ori       $at, $at, 0xcccd
/* A4927C 80240CBC 44810000 */  mtc1      $at, $f0
/* A49280 80240CC0 00441025 */  or        $v0, $v0, $a0
/* A49284 80240CC4 AE420000 */  sw        $v0, ($s2)
/* A49288 80240CC8 E6200054 */  swc1      $f0, 0x54($s1)
/* A4928C 80240CCC E6200058 */  swc1      $f0, 0x58($s1)
/* A49290 80240CD0 8E4300B0 */  lw        $v1, 0xb0($s2)
/* A49294 80240CD4 30620004 */  andi      $v0, $v1, 4
/* A49298 80240CD8 10400003 */  beqz      $v0, .L80240CE8
/* A4929C 80240CDC 2402FFFB */   addiu    $v0, $zero, -5
/* A492A0 80240CE0 00621024 */  and       $v0, $v1, $v0
/* A492A4 80240CE4 AE4200B0 */  sw        $v0, 0xb0($s2)
.L80240CE8:
/* A492A8 80240CE8 8EC30070 */  lw        $v1, 0x70($s6)
/* A492AC 80240CEC 2C620005 */  sltiu     $v0, $v1, 5
/* A492B0 80240CF0 10400101 */  beqz      $v0, .L802410F8
/* A492B4 80240CF4 00031080 */   sll      $v0, $v1, 2
/* A492B8 80240CF8 3C018024 */  lui       $at, 0x8024
/* A492BC 80240CFC 00220821 */  addu      $at, $at, $v0
/* A492C0 80240D00 8C223900 */  lw        $v0, 0x3900($at)
/* A492C4 80240D04 00400008 */  jr        $v0
/* A492C8 80240D08 00000000 */   nop      
/* A492CC 80240D0C 3C01C47A */  lui       $at, 0xc47a
/* A492D0 80240D10 44810000 */  mtc1      $at, $f0
/* A492D4 80240D14 24020014 */  addiu     $v0, $zero, 0x14
/* A492D8 80240D18 AE400078 */  sw        $zero, 0x78($s2)
/* A492DC 80240D1C A62200A6 */  sh        $v0, 0xa6($s1)
/* A492E0 80240D20 A62200A8 */  sh        $v0, 0xa8($s1)
/* A492E4 80240D24 24020001 */  addiu     $v0, $zero, 1
/* A492E8 80240D28 AE200038 */  sw        $zero, 0x38($s1)
/* A492EC 80240D2C AE200040 */  sw        $zero, 0x40($s1)
/* A492F0 80240D30 E620003C */  swc1      $f0, 0x3c($s1)
/* A492F4 80240D34 AE40006C */  sw        $zero, 0x6c($s2)
/* A492F8 80240D38 AEC20070 */  sw        $v0, 0x70($s6)
/* A492FC 80240D3C 8E50006C */  lw        $s0, 0x6c($s2)
/* A49300 80240D40 24020001 */  addiu     $v0, $zero, 1
/* A49304 80240D44 160200EC */  bne       $s0, $v0, .L802410F8
/* A49308 80240D48 24150002 */   addiu    $s5, $zero, 2
/* A4930C 80240D4C AE55006C */  sw        $s5, 0x6c($s2)
/* A49310 80240D50 C6800038 */  lwc1      $f0, 0x38($s4)
/* A49314 80240D54 E6600038 */  swc1      $f0, 0x38($s3)
/* A49318 80240D58 C680003C */  lwc1      $f0, 0x3c($s4)
/* A4931C 80240D5C E660003C */  swc1      $f0, 0x3c($s3)
/* A49320 80240D60 C6800040 */  lwc1      $f0, 0x40($s4)
/* A49324 80240D64 E6600040 */  swc1      $f0, 0x40($s3)
/* A49328 80240D68 C6820034 */  lwc1      $f2, 0x34($s4)
/* A4932C 80240D6C 3C014387 */  lui       $at, 0x4387
/* A49330 80240D70 44810000 */  mtc1      $at, $f0
/* A49334 80240D74 00000000 */  nop       
/* A49338 80240D78 46020001 */  sub.s     $f0, $f0, $f2
/* A4933C 80240D7C C6480074 */  lwc1      $f8, 0x74($s2)
/* A49340 80240D80 46804220 */  cvt.s.w   $f8, $f8
/* A49344 80240D84 44054000 */  mfc1      $a1, $f8
/* A49348 80240D88 44060000 */  mfc1      $a2, $f0
/* A4934C 80240D8C 0C00EA95 */  jal       npc_move_heading
/* A49350 80240D90 0260202D */   daddu    $a0, $s3, $zero
/* A49354 80240D94 C6600038 */  lwc1      $f0, 0x38($s3)
/* A49358 80240D98 E6200038 */  swc1      $f0, 0x38($s1)
/* A4935C 80240D9C C680003C */  lwc1      $f0, 0x3c($s4)
/* A49360 80240DA0 C6420070 */  lwc1      $f2, 0x70($s2)
/* A49364 80240DA4 468010A0 */  cvt.s.w   $f2, $f2
/* A49368 80240DA8 46020000 */  add.s     $f0, $f0, $f2
/* A4936C 80240DAC 3C014024 */  lui       $at, 0x4024
/* A49370 80240DB0 4481A800 */  mtc1      $at, $f21
/* A49374 80240DB4 4480A000 */  mtc1      $zero, $f20
/* A49378 80240DB8 E620003C */  swc1      $f0, 0x3c($s1)
/* A4937C 80240DBC C6600040 */  lwc1      $f0, 0x40($s3)
/* A49380 80240DC0 E6200040 */  swc1      $f0, 0x40($s1)
/* A49384 80240DC4 A2500007 */  sb        $s0, 7($s2)
/* A49388 80240DC8 C6200038 */  lwc1      $f0, 0x38($s1)
/* A4938C 80240DCC 3C014066 */  lui       $at, 0x4066
/* A49390 80240DD0 34216666 */  ori       $at, $at, 0x6666
/* A49394 80240DD4 44811000 */  mtc1      $at, $f2
/* A49398 80240DD8 4600020D */  trunc.w.s $f8, $f0
/* A4939C 80240DDC 44024000 */  mfc1      $v0, $f8
/* A493A0 80240DE0 00000000 */  nop       
/* A493A4 80240DE4 A6420010 */  sh        $v0, 0x10($s2)
/* A493A8 80240DE8 C620003C */  lwc1      $f0, 0x3c($s1)
/* A493AC 80240DEC 3C13800F */  lui       $s3, %hi(gPlayerStatusPtr)
/* A493B0 80240DF0 26737B30 */  addiu     $s3, $s3, %lo(gPlayerStatusPtr)
/* A493B4 80240DF4 4600020D */  trunc.w.s $f8, $f0
/* A493B8 80240DF8 44024000 */  mfc1      $v0, $f8
/* A493BC 80240DFC 00000000 */  nop       
/* A493C0 80240E00 A6420012 */  sh        $v0, 0x12($s2)
/* A493C4 80240E04 C6200040 */  lwc1      $f0, 0x40($s1)
/* A493C8 80240E08 8E630000 */  lw        $v1, ($s3)
/* A493CC 80240E0C 4600020D */  trunc.w.s $f8, $f0
/* A493D0 80240E10 44024000 */  mfc1      $v0, $f8
/* A493D4 80240E14 00000000 */  nop       
/* A493D8 80240E18 A6420014 */  sh        $v0, 0x14($s2)
/* A493DC 80240E1C E6220018 */  swc1      $f2, 0x18($s1)
/* A493E0 80240E20 C460002C */  lwc1      $f0, 0x2c($v1)
/* A493E4 80240E24 C6220038 */  lwc1      $f2, 0x38($s1)
/* A493E8 80240E28 46000021 */  cvt.d.s   $f0, $f0
/* A493EC 80240E2C 46340000 */  add.d     $f0, $f0, $f20
/* A493F0 80240E30 C4640028 */  lwc1      $f4, 0x28($v1)
/* A493F4 80240E34 44806000 */  mtc1      $zero, $f12
/* A493F8 80240E38 46041081 */  sub.s     $f2, $f2, $f4
/* A493FC 80240E3C C62E003C */  lwc1      $f14, 0x3c($s1)
/* A49400 80240E40 46200020 */  cvt.s.d   $f0, $f0
/* A49404 80240E44 46001085 */  abs.s     $f2, $f2
/* A49408 80240E48 44070000 */  mfc1      $a3, $f0
/* A4940C 80240E4C 44061000 */  mfc1      $a2, $f2
/* A49410 80240E50 0C00A720 */  jal       atan2
/* A49414 80240E54 00000000 */   nop      
/* A49418 80240E58 3C018024 */  lui       $at, 0x8024
/* A4941C 80240E5C D4223918 */  ldc1      $f2, 0x3918($at)
/* A49420 80240E60 46000021 */  cvt.d.s   $f0, $f0
/* A49424 80240E64 46220001 */  sub.d     $f0, $f0, $f2
/* A49428 80240E68 46200020 */  cvt.s.d   $f0, $f0
/* A4942C 80240E6C 4600020D */  trunc.w.s $f8, $f0
/* A49430 80240E70 44044000 */  mfc1      $a0, $f8
/* A49434 80240E74 00000000 */  nop       
/* A49438 80240E78 00042400 */  sll       $a0, $a0, 0x10
/* A4943C 80240E7C 0C00A4F5 */  jal       cosine
/* A49440 80240E80 00042403 */   sra      $a0, $a0, 0x10
/* A49444 80240E84 C6220018 */  lwc1      $f2, 0x18($s1)
/* A49448 80240E88 46020002 */  mul.s     $f0, $f0, $f2
/* A4944C 80240E8C 00000000 */  nop       
/* A49450 80240E90 C62C0038 */  lwc1      $f12, 0x38($s1)
/* A49454 80240E94 C62E0040 */  lwc1      $f14, 0x40($s1)
/* A49458 80240E98 8E620000 */  lw        $v0, ($s3)
/* A4945C 80240E9C E620001C */  swc1      $f0, 0x1c($s1)
/* A49460 80240EA0 8C460028 */  lw        $a2, 0x28($v0)
/* A49464 80240EA4 0C00A720 */  jal       atan2
/* A49468 80240EA8 8C470030 */   lw       $a3, 0x30($v0)
/* A4946C 80240EAC 8E620000 */  lw        $v0, ($s3)
/* A49470 80240EB0 E620000C */  swc1      $f0, 0xc($s1)
/* A49474 80240EB4 C440002C */  lwc1      $f0, 0x2c($v0)
/* A49478 80240EB8 46000021 */  cvt.d.s   $f0, $f0
/* A4947C 80240EBC 46340000 */  add.d     $f0, $f0, $f20
/* A49480 80240EC0 46200020 */  cvt.s.d   $f0, $f0
/* A49484 80240EC4 E7A00010 */  swc1      $f0, 0x10($sp)
/* A49488 80240EC8 C4400030 */  lwc1      $f0, 0x30($v0)
/* A4948C 80240ECC E7A00014 */  swc1      $f0, 0x14($sp)
/* A49490 80240ED0 C62C0038 */  lwc1      $f12, 0x38($s1)
/* A49494 80240ED4 C62E003C */  lwc1      $f14, 0x3c($s1)
/* A49498 80240ED8 8E260040 */  lw        $a2, 0x40($s1)
/* A4949C 80240EDC 0C00A7CB */  jal       dist3D
/* A494A0 80240EE0 8C470028 */   lw       $a3, 0x28($v0)
/* A494A4 80240EE4 C6220018 */  lwc1      $f2, 0x18($s1)
/* A494A8 80240EE8 46020003 */  div.s     $f0, $f0, $f2
/* A494AC 80240EEC 4600020D */  trunc.w.s $f8, $f0
/* A494B0 80240EF0 44104000 */  mfc1      $s0, $f8
/* A494B4 80240EF4 00000000 */  nop       
/* A494B8 80240EF8 5A000001 */  blezl     $s0, .L80240F00
/* A494BC 80240EFC 24100001 */   addiu    $s0, $zero, 1
.L80240F00:
/* A494C0 80240F00 8E620000 */  lw        $v0, ($s3)
/* A494C4 80240F04 C624003C */  lwc1      $f4, 0x3c($s1)
/* A494C8 80240F08 3C014120 */  lui       $at, 0x4120
/* A494CC 80240F0C 44811000 */  mtc1      $at, $f2
/* A494D0 80240F10 C4400028 */  lwc1      $f0, 0x28($v0)
/* A494D4 80240F14 E7A00010 */  swc1      $f0, 0x10($sp)
/* A494D8 80240F18 C440002C */  lwc1      $f0, 0x2c($v0)
/* A494DC 80240F1C 46020000 */  add.s     $f0, $f0, $f2
/* A494E0 80240F20 3C014160 */  lui       $at, 0x4160
/* A494E4 80240F24 44811000 */  mtc1      $at, $f2
/* A494E8 80240F28 00000000 */  nop       
/* A494EC 80240F2C 46022100 */  add.s     $f4, $f4, $f2
/* A494F0 80240F30 46020000 */  add.s     $f0, $f0, $f2
/* A494F4 80240F34 44062000 */  mfc1      $a2, $f4
/* A494F8 80240F38 E7A00014 */  swc1      $f0, 0x14($sp)
/* A494FC 80240F3C C4400030 */  lwc1      $f0, 0x30($v0)
/* A49500 80240F40 AFB0001C */  sw        $s0, 0x1c($sp)
/* A49504 80240F44 E7A00018 */  swc1      $f0, 0x18($sp)
/* A49508 80240F48 8E250038 */  lw        $a1, 0x38($s1)
/* A4950C 80240F4C 8E270040 */  lw        $a3, 0x40($s1)
/* A49510 80240F50 0C01BFD4 */  jal       func_8006FF50
/* A49514 80240F54 0000202D */   daddu    $a0, $zero, $zero
/* A49518 80240F58 AE420078 */  sw        $v0, 0x78($s2)
/* A4951C 80240F5C A630008E */  sh        $s0, 0x8e($s1)
/* A49520 80240F60 0809043E */  j         .L802410F8
/* A49524 80240F64 AED50070 */   sw       $s5, 0x70($s6)
/* A49528 80240F68 9622008E */  lhu       $v0, 0x8e($s1)
/* A4952C 80240F6C 2442FFFF */  addiu     $v0, $v0, -1
/* A49530 80240F70 A622008E */  sh        $v0, 0x8e($s1)
/* A49534 80240F74 00021400 */  sll       $v0, $v0, 0x10
/* A49538 80240F78 58400001 */  blezl     $v0, .L80240F80
/* A4953C 80240F7C 24150014 */   addiu    $s5, $zero, 0x14
.L80240F80:
/* A49540 80240F80 16A0000A */  bnez      $s5, .L80240FAC
/* A49544 80240F84 00000000 */   nop      
/* A49548 80240F88 8E250018 */  lw        $a1, 0x18($s1)
/* A4954C 80240F8C 8E26000C */  lw        $a2, 0xc($s1)
/* A49550 80240F90 0C00EA95 */  jal       npc_move_heading
/* A49554 80240F94 0220202D */   daddu    $a0, $s1, $zero
/* A49558 80240F98 C620003C */  lwc1      $f0, 0x3c($s1)
/* A4955C 80240F9C C622001C */  lwc1      $f2, 0x1c($s1)
/* A49560 80240FA0 46020000 */  add.s     $f0, $f0, $f2
/* A49564 80240FA4 0809043E */  j         .L802410F8
/* A49568 80240FA8 E620003C */   swc1     $f0, 0x3c($s1)
.L80240FAC:
/* A4956C 80240FAC 862200A8 */  lh        $v0, 0xa8($s1)
/* A49570 80240FB0 3C013FE0 */  lui       $at, 0x3fe0
/* A49574 80240FB4 44810800 */  mtc1      $at, $f1
/* A49578 80240FB8 44800000 */  mtc1      $zero, $f0
/* A4957C 80240FBC 44821000 */  mtc1      $v0, $f2
/* A49580 80240FC0 00000000 */  nop       
/* A49584 80240FC4 468010A1 */  cvt.d.w   $f2, $f2
/* A49588 80240FC8 46201082 */  mul.d     $f2, $f2, $f0
/* A4958C 80240FCC 00000000 */  nop       
/* A49590 80240FD0 C620003C */  lwc1      $f0, 0x3c($s1)
/* A49594 80240FD4 AE20001C */  sw        $zero, 0x1c($s1)
/* A49598 80240FD8 46000021 */  cvt.d.s   $f0, $f0
/* A4959C 80240FDC 46220001 */  sub.d     $f0, $f0, $f2
/* A495A0 80240FE0 AE200018 */  sw        $zero, 0x18($s1)
/* A495A4 80240FE4 24020003 */  addiu     $v0, $zero, 3
/* A495A8 80240FE8 46200020 */  cvt.s.d   $f0, $f0
/* A495AC 80240FEC E620003C */  swc1      $f0, 0x3c($s1)
/* A495B0 80240FF0 AE42006C */  sw        $v0, 0x6c($s2)
/* A495B4 80240FF4 24020004 */  addiu     $v0, $zero, 4
/* A495B8 80240FF8 A620008E */  sh        $zero, 0x8e($s1)
/* A495BC 80240FFC 0809043E */  j         .L802410F8
/* A495C0 80241000 AEC20070 */   sw       $v0, 0x70($s6)
/* A495C4 80241004 9622008E */  lhu       $v0, 0x8e($s1)
/* A495C8 80241008 24420001 */  addiu     $v0, $v0, 1
/* A495CC 8024100C A622008E */  sh        $v0, 0x8e($s1)
/* A495D0 80241010 00021400 */  sll       $v0, $v0, 0x10
/* A495D4 80241014 00021C03 */  sra       $v1, $v0, 0x10
/* A495D8 80241018 28620007 */  slti      $v0, $v1, 7
/* A495DC 8024101C 10400027 */  beqz      $v0, .L802410BC
/* A495E0 80241020 24020007 */   addiu    $v0, $zero, 7
/* A495E4 80241024 8622008E */  lh        $v0, 0x8e($s1)
/* A495E8 80241028 3C01401C */  lui       $at, 0x401c
/* A495EC 8024102C 44810800 */  mtc1      $at, $f1
/* A495F0 80241030 44800000 */  mtc1      $zero, $f0
/* A495F4 80241034 44822000 */  mtc1      $v0, $f4
/* A495F8 80241038 00000000 */  nop       
/* A495FC 8024103C 46802120 */  cvt.s.w   $f4, $f4
/* A49600 80241040 46002121 */  cvt.d.s   $f4, $f4
/* A49604 80241044 46202102 */  mul.d     $f4, $f4, $f0
/* A49608 80241048 00000000 */  nop       
/* A4960C 8024104C 44821000 */  mtc1      $v0, $f2
/* A49610 80241050 00000000 */  nop       
/* A49614 80241054 468010A0 */  cvt.s.w   $f2, $f2
/* A49618 80241058 460010A1 */  cvt.d.s   $f2, $f2
/* A4961C 8024105C 46201082 */  mul.d     $f2, $f2, $f0
/* A49620 80241060 00000000 */  nop       
/* A49624 80241064 C620003C */  lwc1      $f0, 0x3c($s1)
/* A49628 80241068 3C01400C */  lui       $at, 0x400c
/* A4962C 8024106C 44813800 */  mtc1      $at, $f7
/* A49630 80241070 44803000 */  mtc1      $zero, $f6
/* A49634 80241074 46000021 */  cvt.d.s   $f0, $f0
/* A49638 80241078 46260001 */  sub.d     $f0, $f0, $f6
/* A4963C 8024107C 3C014034 */  lui       $at, 0x4034
/* A49640 80241080 44813800 */  mtc1      $at, $f7
/* A49644 80241084 44803000 */  mtc1      $zero, $f6
/* A49648 80241088 00000000 */  nop       
/* A4964C 8024108C 46262100 */  add.d     $f4, $f4, $f6
/* A49650 80241090 46200020 */  cvt.s.d   $f0, $f0
/* A49654 80241094 E620003C */  swc1      $f0, 0x3c($s1)
/* A49658 80241098 46261080 */  add.d     $f2, $f2, $f6
/* A4965C 8024109C 4620220D */  trunc.w.d $f8, $f4
/* A49660 802410A0 44024000 */  mfc1      $v0, $f8
/* A49664 802410A4 00000000 */  nop       
/* A49668 802410A8 A62200A6 */  sh        $v0, 0xa6($s1)
/* A4966C 802410AC 4620120D */  trunc.w.d $f8, $f2
/* A49670 802410B0 44024000 */  mfc1      $v0, $f8
/* A49674 802410B4 0809043E */  j         .L802410F8
/* A49678 802410B8 A62200A8 */   sh       $v0, 0xa8($s1)
.L802410BC:
/* A4967C 802410BC 1462000A */  bne       $v1, $v0, .L802410E8
/* A49680 802410C0 28620010 */   slti     $v0, $v1, 0x10
/* A49684 802410C4 3C01C47A */  lui       $at, 0xc47a
/* A49688 802410C8 44810000 */  mtc1      $at, $f0
/* A4968C 802410CC 24020014 */  addiu     $v0, $zero, 0x14
/* A49690 802410D0 AE200038 */  sw        $zero, 0x38($s1)
/* A49694 802410D4 AE200040 */  sw        $zero, 0x40($s1)
/* A49698 802410D8 A62200A6 */  sh        $v0, 0xa6($s1)
/* A4969C 802410DC A62200A8 */  sh        $v0, 0xa8($s1)
/* A496A0 802410E0 0809043E */  j         .L802410F8
/* A496A4 802410E4 E620003C */   swc1     $f0, 0x3c($s1)
.L802410E8:
/* A496A8 802410E8 14400003 */  bnez      $v0, .L802410F8
/* A496AC 802410EC 00000000 */   nop      
/* A496B0 802410F0 AE40006C */  sw        $zero, 0x6c($s2)
/* A496B4 802410F4 AEC00070 */  sw        $zero, 0x70($s6)
.L802410F8:
/* A496B8 802410F8 8FBF037C */  lw        $ra, 0x37c($sp)
/* A496BC 802410FC 8FB60378 */  lw        $s6, 0x378($sp)
/* A496C0 80241100 8FB50374 */  lw        $s5, 0x374($sp)
/* A496C4 80241104 8FB40370 */  lw        $s4, 0x370($sp)
/* A496C8 80241108 8FB3036C */  lw        $s3, 0x36c($sp)
/* A496CC 8024110C 8FB20368 */  lw        $s2, 0x368($sp)
/* A496D0 80241110 8FB10364 */  lw        $s1, 0x364($sp)
/* A496D4 80241114 8FB00360 */  lw        $s0, 0x360($sp)
/* A496D8 80241118 D7B40380 */  ldc1      $f20, 0x380($sp)
/* A496DC 8024111C 0000102D */  daddu     $v0, $zero, $zero
/* A496E0 80241120 03E00008 */  jr        $ra
/* A496E4 80241124 27BD0388 */   addiu    $sp, $sp, 0x388
