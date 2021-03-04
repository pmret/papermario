.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802411B4_B35D84
/* B35D84 802411B4 27BDFF98 */  addiu     $sp, $sp, -0x68
/* B35D88 802411B8 AFB40058 */  sw        $s4, 0x58($sp)
/* B35D8C 802411BC 0080A02D */  daddu     $s4, $a0, $zero
/* B35D90 802411C0 AFBF0060 */  sw        $ra, 0x60($sp)
/* B35D94 802411C4 AFB5005C */  sw        $s5, 0x5c($sp)
/* B35D98 802411C8 AFB30054 */  sw        $s3, 0x54($sp)
/* B35D9C 802411CC AFB20050 */  sw        $s2, 0x50($sp)
/* B35DA0 802411D0 AFB1004C */  sw        $s1, 0x4c($sp)
/* B35DA4 802411D4 AFB00048 */  sw        $s0, 0x48($sp)
/* B35DA8 802411D8 8E910148 */  lw        $s1, 0x148($s4)
/* B35DAC 802411DC 86240008 */  lh        $a0, 8($s1)
/* B35DB0 802411E0 0C00EABB */  jal       get_npc_unsafe
/* B35DB4 802411E4 00A0802D */   daddu    $s0, $a1, $zero
/* B35DB8 802411E8 8E83000C */  lw        $v1, 0xc($s4)
/* B35DBC 802411EC 0280202D */  daddu     $a0, $s4, $zero
/* B35DC0 802411F0 8C650000 */  lw        $a1, ($v1)
/* B35DC4 802411F4 0C0B1EAF */  jal       get_variable
/* B35DC8 802411F8 0040902D */   daddu    $s2, $v0, $zero
/* B35DCC 802411FC AFA00018 */  sw        $zero, 0x18($sp)
/* B35DD0 80241200 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B35DD4 80241204 8C630094 */  lw        $v1, 0x94($v1)
/* B35DD8 80241208 AFA3001C */  sw        $v1, 0x1c($sp)
/* B35DDC 8024120C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B35DE0 80241210 8C630080 */  lw        $v1, 0x80($v1)
/* B35DE4 80241214 AFA30020 */  sw        $v1, 0x20($sp)
/* B35DE8 80241218 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B35DEC 8024121C 8C630088 */  lw        $v1, 0x88($v1)
/* B35DF0 80241220 AFA30024 */  sw        $v1, 0x24($sp)
/* B35DF4 80241224 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B35DF8 80241228 8C63008C */  lw        $v1, 0x8c($v1)
/* B35DFC 8024122C 27B50018 */  addiu     $s5, $sp, 0x18
/* B35E00 80241230 AFA30028 */  sw        $v1, 0x28($sp)
/* B35E04 80241234 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B35E08 80241238 3C014282 */  lui       $at, 0x4282
/* B35E0C 8024123C 44810000 */  mtc1      $at, $f0
/* B35E10 80241240 8C630090 */  lw        $v1, 0x90($v1)
/* B35E14 80241244 0040982D */  daddu     $s3, $v0, $zero
/* B35E18 80241248 E7A00030 */  swc1      $f0, 0x30($sp)
/* B35E1C 8024124C A7A00034 */  sh        $zero, 0x34($sp)
/* B35E20 80241250 16000005 */  bnez      $s0, .L80241268
/* B35E24 80241254 AFA3002C */   sw       $v1, 0x2c($sp)
/* B35E28 80241258 8E2200B0 */  lw        $v0, 0xb0($s1)
/* B35E2C 8024125C 30420004 */  andi      $v0, $v0, 4
/* B35E30 80241260 10400044 */  beqz      $v0, .L80241374
/* B35E34 80241264 00000000 */   nop
.L80241268:
/* B35E38 80241268 2404F7FF */  addiu     $a0, $zero, -0x801
/* B35E3C 8024126C AE800070 */  sw        $zero, 0x70($s4)
/* B35E40 80241270 A640008E */  sh        $zero, 0x8e($s2)
/* B35E44 80241274 8E2200CC */  lw        $v0, 0xcc($s1)
/* B35E48 80241278 8E430000 */  lw        $v1, ($s2)
/* B35E4C 8024127C 8C420000 */  lw        $v0, ($v0)
/* B35E50 80241280 00641824 */  and       $v1, $v1, $a0
/* B35E54 80241284 AE430000 */  sw        $v1, ($s2)
/* B35E58 80241288 AE420028 */  sw        $v0, 0x28($s2)
/* B35E5C 8024128C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* B35E60 80241290 8C420098 */  lw        $v0, 0x98($v0)
/* B35E64 80241294 54400005 */  bnel      $v0, $zero, .L802412AC
/* B35E68 80241298 2402FDFF */   addiu    $v0, $zero, -0x201
/* B35E6C 8024129C 34620200 */  ori       $v0, $v1, 0x200
/* B35E70 802412A0 2403FFF7 */  addiu     $v1, $zero, -9
/* B35E74 802412A4 080904AD */  j         .L802412B4
/* B35E78 802412A8 00431024 */   and      $v0, $v0, $v1
.L802412AC:
/* B35E7C 802412AC 00621024 */  and       $v0, $v1, $v0
/* B35E80 802412B0 34420008 */  ori       $v0, $v0, 8
.L802412B4:
/* B35E84 802412B4 AE420000 */  sw        $v0, ($s2)
/* B35E88 802412B8 8E2200B0 */  lw        $v0, 0xb0($s1)
/* B35E8C 802412BC 30420004 */  andi      $v0, $v0, 4
/* B35E90 802412C0 10400008 */  beqz      $v0, .L802412E4
/* B35E94 802412C4 24020063 */   addiu    $v0, $zero, 0x63
/* B35E98 802412C8 AE820070 */  sw        $v0, 0x70($s4)
/* B35E9C 802412CC AE800074 */  sw        $zero, 0x74($s4)
/* B35EA0 802412D0 8E2200B0 */  lw        $v0, 0xb0($s1)
/* B35EA4 802412D4 2403FFFB */  addiu     $v1, $zero, -5
/* B35EA8 802412D8 00431024 */  and       $v0, $v0, $v1
/* B35EAC 802412DC 080904C4 */  j         .L80241310
/* B35EB0 802412E0 AE2200B0 */   sw       $v0, 0xb0($s1)
.L802412E4:
/* B35EB4 802412E4 8E220000 */  lw        $v0, ($s1)
/* B35EB8 802412E8 3C034000 */  lui       $v1, 0x4000
/* B35EBC 802412EC 00431024 */  and       $v0, $v0, $v1
/* B35EC0 802412F0 10400007 */  beqz      $v0, .L80241310
/* B35EC4 802412F4 3C03BFFF */   lui      $v1, 0xbfff
/* B35EC8 802412F8 2402000C */  addiu     $v0, $zero, 0xc
/* B35ECC 802412FC AE820070 */  sw        $v0, 0x70($s4)
/* B35ED0 80241300 8E220000 */  lw        $v0, ($s1)
/* B35ED4 80241304 3463FFFF */  ori       $v1, $v1, 0xffff
/* B35ED8 80241308 00431024 */  and       $v0, $v0, $v1
/* B35EDC 8024130C AE220000 */  sw        $v0, ($s1)
.L80241310:
/* B35EE0 80241310 27A50038 */  addiu     $a1, $sp, 0x38
/* B35EE4 80241314 27A6003C */  addiu     $a2, $sp, 0x3c
/* B35EE8 80241318 C6400038 */  lwc1      $f0, 0x38($s2)
/* B35EEC 8024131C 864200A8 */  lh        $v0, 0xa8($s2)
/* B35EF0 80241320 3C0142C8 */  lui       $at, 0x42c8
/* B35EF4 80241324 44812000 */  mtc1      $at, $f4
/* B35EF8 80241328 44823000 */  mtc1      $v0, $f6
/* B35EFC 8024132C 00000000 */  nop
/* B35F00 80241330 468031A0 */  cvt.s.w   $f6, $f6
/* B35F04 80241334 27A20044 */  addiu     $v0, $sp, 0x44
/* B35F08 80241338 E7A00038 */  swc1      $f0, 0x38($sp)
/* B35F0C 8024133C C640003C */  lwc1      $f0, 0x3c($s2)
/* B35F10 80241340 C6420040 */  lwc1      $f2, 0x40($s2)
/* B35F14 80241344 46060000 */  add.s     $f0, $f0, $f6
/* B35F18 80241348 E7A40044 */  swc1      $f4, 0x44($sp)
/* B35F1C 8024134C E7A20040 */  swc1      $f2, 0x40($sp)
/* B35F20 80241350 E7A0003C */  swc1      $f0, 0x3c($sp)
/* B35F24 80241354 AFA20010 */  sw        $v0, 0x10($sp)
/* B35F28 80241358 8E440080 */  lw        $a0, 0x80($s2)
/* B35F2C 8024135C 0C0372DF */  jal       func_800DCB7C
/* B35F30 80241360 27A70040 */   addiu    $a3, $sp, 0x40
/* B35F34 80241364 10400003 */  beqz      $v0, .L80241374
/* B35F38 80241368 00000000 */   nop
/* B35F3C 8024136C C7A0003C */  lwc1      $f0, 0x3c($sp)
/* B35F40 80241370 E640003C */  swc1      $f0, 0x3c($s2)
.L80241374:
/* B35F44 80241374 8E830070 */  lw        $v1, 0x70($s4)
/* B35F48 80241378 2C620064 */  sltiu     $v0, $v1, 0x64
/* B35F4C 8024137C 10400042 */  beqz      $v0, L80241488_B36058
/* B35F50 80241380 00031080 */   sll      $v0, $v1, 2
/* B35F54 80241384 3C018025 */  lui       $at, %hi(jtbl_8024FA00_B445D0)
/* B35F58 80241388 00220821 */  addu      $at, $at, $v0
/* B35F5C 8024138C 8C22FA00 */  lw        $v0, %lo(jtbl_8024FA00_B445D0)($at)
/* B35F60 80241390 00400008 */  jr        $v0
/* B35F64 80241394 00000000 */   nop
glabel L80241398_B35F68
/* B35F68 80241398 0280202D */  daddu     $a0, $s4, $zero
/* B35F6C 8024139C 0260282D */  daddu     $a1, $s3, $zero
/* B35F70 802413A0 0C090188 */  jal       func_80240620_B351F0
/* B35F74 802413A4 02A0302D */   daddu    $a2, $s5, $zero
glabel L802413A8_B35F78
/* B35F78 802413A8 0280202D */  daddu     $a0, $s4, $zero
/* B35F7C 802413AC 0260282D */  daddu     $a1, $s3, $zero
/* B35F80 802413B0 0C0901DE */  jal       func_80240778_B35348
/* B35F84 802413B4 02A0302D */   daddu    $a2, $s5, $zero
/* B35F88 802413B8 08090522 */  j         L80241488_B36058
/* B35F8C 802413BC 00000000 */   nop
glabel L802413C0_B35F90
/* B35F90 802413C0 0280202D */  daddu     $a0, $s4, $zero
/* B35F94 802413C4 0260282D */  daddu     $a1, $s3, $zero
/* B35F98 802413C8 0C090288 */  jal       jan_03_UnkNpcAIFunc1
/* B35F9C 802413CC 02A0302D */   daddu    $a2, $s5, $zero
glabel L802413D0_B35FA0
/* B35FA0 802413D0 0280202D */  daddu     $a0, $s4, $zero
/* B35FA4 802413D4 0260282D */  daddu     $a1, $s3, $zero
/* B35FA8 802413D8 0C0902B8 */  jal       func_80240AE0_B356B0
/* B35FAC 802413DC 02A0302D */   daddu    $a2, $s5, $zero
/* B35FB0 802413E0 08090522 */  j         L80241488_B36058
/* B35FB4 802413E4 00000000 */   nop
glabel L802413E8_B35FB8
/* B35FB8 802413E8 0280202D */  daddu     $a0, $s4, $zero
/* B35FBC 802413EC 0260282D */  daddu     $a1, $s3, $zero
/* B35FC0 802413F0 0C090327 */  jal       func_80240C9C_B3586C
/* B35FC4 802413F4 02A0302D */   daddu    $a2, $s5, $zero
/* B35FC8 802413F8 08090522 */  j         L80241488_B36058
/* B35FCC 802413FC 00000000 */   nop
glabel L80241400_B35FD0
/* B35FD0 80241400 0280202D */  daddu     $a0, $s4, $zero
/* B35FD4 80241404 0260282D */  daddu     $a1, $s3, $zero
/* B35FD8 80241408 0C090354 */  jal       jan_03_NpcJumpFunc2
/* B35FDC 8024140C 02A0302D */   daddu    $a2, $s5, $zero
glabel L80241410_B35FE0
/* B35FE0 80241410 0280202D */  daddu     $a0, $s4, $zero
/* B35FE4 80241414 0260282D */  daddu     $a1, $s3, $zero
/* B35FE8 80241418 0C090371 */  jal       jan_03_NpcJumpFunc
/* B35FEC 8024141C 02A0302D */   daddu    $a2, $s5, $zero
/* B35FF0 80241420 08090522 */  j         L80241488_B36058
/* B35FF4 80241424 00000000 */   nop
glabel L80241428_B35FF8
/* B35FF8 80241428 0280202D */  daddu     $a0, $s4, $zero
/* B35FFC 8024142C 0260282D */  daddu     $a1, $s3, $zero
/* B36000 80241430 0C09038F */  jal       jan_03_UnkNpcAIFunc13
/* B36004 80241434 02A0302D */   daddu    $a2, $s5, $zero
glabel L80241438_B36008
/* B36008 80241438 0280202D */  daddu     $a0, $s4, $zero
/* B3600C 8024143C 0260282D */  daddu     $a1, $s3, $zero
/* B36010 80241440 0C0903DB */  jal       func_80240F6C_B35B3C
/* B36014 80241444 02A0302D */   daddu    $a2, $s5, $zero
/* B36018 80241448 08090522 */  j         L80241488_B36058
/* B3601C 8024144C 00000000 */   nop
glabel L80241450_B36020
/* B36020 80241450 0280202D */  daddu     $a0, $s4, $zero
/* B36024 80241454 0260282D */  daddu     $a1, $s3, $zero
/* B36028 80241458 0C090423 */  jal       jan_03_UnkNpcDurationFlagFunc
/* B3602C 8024145C 02A0302D */   daddu    $a2, $s5, $zero
/* B36030 80241460 08090522 */  j         L80241488_B36058
/* B36034 80241464 00000000 */   nop
glabel L80241468_B36038
/* B36038 80241468 0280202D */  daddu     $a0, $s4, $zero
/* B3603C 8024146C 0260282D */  daddu     $a1, $s3, $zero
/* B36040 80241470 0C09043D */  jal       func_802410F4_B35CC4
/* B36044 80241474 02A0302D */   daddu    $a2, $s5, $zero
/* B36048 80241478 08090522 */  j         L80241488_B36058
/* B3604C 8024147C 00000000 */   nop
glabel L80241480_B36050
/* B36050 80241480 0C0129CF */  jal       func_8004A73C
/* B36054 80241484 0280202D */   daddu    $a0, $s4, $zero
glabel L80241488_B36058
/* B36058 80241488 8FBF0060 */  lw        $ra, 0x60($sp)
/* B3605C 8024148C 8FB5005C */  lw        $s5, 0x5c($sp)
/* B36060 80241490 8FB40058 */  lw        $s4, 0x58($sp)
/* B36064 80241494 8FB30054 */  lw        $s3, 0x54($sp)
/* B36068 80241498 8FB20050 */  lw        $s2, 0x50($sp)
/* B3606C 8024149C 8FB1004C */  lw        $s1, 0x4c($sp)
/* B36070 802414A0 8FB00048 */  lw        $s0, 0x48($sp)
/* B36074 802414A4 0000102D */  daddu     $v0, $zero, $zero
/* B36078 802414A8 03E00008 */  jr        $ra
/* B3607C 802414AC 27BD0068 */   addiu    $sp, $sp, 0x68
