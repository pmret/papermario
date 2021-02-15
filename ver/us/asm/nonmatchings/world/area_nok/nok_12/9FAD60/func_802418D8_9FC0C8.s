.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802418D8_9FC0C8
/* 9FC0C8 802418D8 27BDFF98 */  addiu     $sp, $sp, -0x68
/* 9FC0CC 802418DC AFB40058 */  sw        $s4, 0x58($sp)
/* 9FC0D0 802418E0 0080A02D */  daddu     $s4, $a0, $zero
/* 9FC0D4 802418E4 AFBF0060 */  sw        $ra, 0x60($sp)
/* 9FC0D8 802418E8 AFB5005C */  sw        $s5, 0x5c($sp)
/* 9FC0DC 802418EC AFB30054 */  sw        $s3, 0x54($sp)
/* 9FC0E0 802418F0 AFB20050 */  sw        $s2, 0x50($sp)
/* 9FC0E4 802418F4 AFB1004C */  sw        $s1, 0x4c($sp)
/* 9FC0E8 802418F8 AFB00048 */  sw        $s0, 0x48($sp)
/* 9FC0EC 802418FC 8E910148 */  lw        $s1, 0x148($s4)
/* 9FC0F0 80241900 86240008 */  lh        $a0, 8($s1)
/* 9FC0F4 80241904 0C00EABB */  jal       get_npc_unsafe
/* 9FC0F8 80241908 00A0802D */   daddu    $s0, $a1, $zero
/* 9FC0FC 8024190C 8E83000C */  lw        $v1, 0xc($s4)
/* 9FC100 80241910 0280202D */  daddu     $a0, $s4, $zero
/* 9FC104 80241914 8C650000 */  lw        $a1, ($v1)
/* 9FC108 80241918 0C0B1EAF */  jal       get_variable
/* 9FC10C 8024191C 0040902D */   daddu    $s2, $v0, $zero
/* 9FC110 80241920 AFA00018 */  sw        $zero, 0x18($sp)
/* 9FC114 80241924 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 9FC118 80241928 8C630094 */  lw        $v1, 0x94($v1)
/* 9FC11C 8024192C AFA3001C */  sw        $v1, 0x1c($sp)
/* 9FC120 80241930 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 9FC124 80241934 8C630080 */  lw        $v1, 0x80($v1)
/* 9FC128 80241938 AFA30020 */  sw        $v1, 0x20($sp)
/* 9FC12C 8024193C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 9FC130 80241940 8C630088 */  lw        $v1, 0x88($v1)
/* 9FC134 80241944 AFA30024 */  sw        $v1, 0x24($sp)
/* 9FC138 80241948 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 9FC13C 8024194C 8C63008C */  lw        $v1, 0x8c($v1)
/* 9FC140 80241950 27B50018 */  addiu     $s5, $sp, 0x18
/* 9FC144 80241954 AFA30028 */  sw        $v1, 0x28($sp)
/* 9FC148 80241958 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 9FC14C 8024195C 3C014282 */  lui       $at, 0x4282
/* 9FC150 80241960 44810000 */  mtc1      $at, $f0
/* 9FC154 80241964 8C630090 */  lw        $v1, 0x90($v1)
/* 9FC158 80241968 0040982D */  daddu     $s3, $v0, $zero
/* 9FC15C 8024196C E7A00030 */  swc1      $f0, 0x30($sp)
/* 9FC160 80241970 A7A00034 */  sh        $zero, 0x34($sp)
/* 9FC164 80241974 16000005 */  bnez      $s0, .L8024198C
/* 9FC168 80241978 AFA3002C */   sw       $v1, 0x2c($sp)
/* 9FC16C 8024197C 8E2200B0 */  lw        $v0, 0xb0($s1)
/* 9FC170 80241980 30420004 */  andi      $v0, $v0, 4
/* 9FC174 80241984 10400044 */  beqz      $v0, .L80241A98
/* 9FC178 80241988 00000000 */   nop
.L8024198C:
/* 9FC17C 8024198C 2404F7FF */  addiu     $a0, $zero, -0x801
/* 9FC180 80241990 AE800070 */  sw        $zero, 0x70($s4)
/* 9FC184 80241994 A640008E */  sh        $zero, 0x8e($s2)
/* 9FC188 80241998 8E2200CC */  lw        $v0, 0xcc($s1)
/* 9FC18C 8024199C 8E430000 */  lw        $v1, ($s2)
/* 9FC190 802419A0 8C420000 */  lw        $v0, ($v0)
/* 9FC194 802419A4 00641824 */  and       $v1, $v1, $a0
/* 9FC198 802419A8 AE430000 */  sw        $v1, ($s2)
/* 9FC19C 802419AC AE420028 */  sw        $v0, 0x28($s2)
/* 9FC1A0 802419B0 8E2200D0 */  lw        $v0, 0xd0($s1)
/* 9FC1A4 802419B4 8C420098 */  lw        $v0, 0x98($v0)
/* 9FC1A8 802419B8 54400005 */  bnel      $v0, $zero, .L802419D0
/* 9FC1AC 802419BC 2402FDFF */   addiu    $v0, $zero, -0x201
/* 9FC1B0 802419C0 34620200 */  ori       $v0, $v1, 0x200
/* 9FC1B4 802419C4 2403FFF7 */  addiu     $v1, $zero, -9
/* 9FC1B8 802419C8 08090676 */  j         .L802419D8
/* 9FC1BC 802419CC 00431024 */   and      $v0, $v0, $v1
.L802419D0:
/* 9FC1C0 802419D0 00621024 */  and       $v0, $v1, $v0
/* 9FC1C4 802419D4 34420008 */  ori       $v0, $v0, 8
.L802419D8:
/* 9FC1C8 802419D8 AE420000 */  sw        $v0, ($s2)
/* 9FC1CC 802419DC 8E2200B0 */  lw        $v0, 0xb0($s1)
/* 9FC1D0 802419E0 30420004 */  andi      $v0, $v0, 4
/* 9FC1D4 802419E4 10400008 */  beqz      $v0, .L80241A08
/* 9FC1D8 802419E8 24020063 */   addiu    $v0, $zero, 0x63
/* 9FC1DC 802419EC AE820070 */  sw        $v0, 0x70($s4)
/* 9FC1E0 802419F0 AE800074 */  sw        $zero, 0x74($s4)
/* 9FC1E4 802419F4 8E2200B0 */  lw        $v0, 0xb0($s1)
/* 9FC1E8 802419F8 2403FFFB */  addiu     $v1, $zero, -5
/* 9FC1EC 802419FC 00431024 */  and       $v0, $v0, $v1
/* 9FC1F0 80241A00 0809068D */  j         .L80241A34
/* 9FC1F4 80241A04 AE2200B0 */   sw       $v0, 0xb0($s1)
.L80241A08:
/* 9FC1F8 80241A08 8E220000 */  lw        $v0, ($s1)
/* 9FC1FC 80241A0C 3C034000 */  lui       $v1, 0x4000
/* 9FC200 80241A10 00431024 */  and       $v0, $v0, $v1
/* 9FC204 80241A14 10400007 */  beqz      $v0, .L80241A34
/* 9FC208 80241A18 3C03BFFF */   lui      $v1, 0xbfff
/* 9FC20C 80241A1C 2402000C */  addiu     $v0, $zero, 0xc
/* 9FC210 80241A20 AE820070 */  sw        $v0, 0x70($s4)
/* 9FC214 80241A24 8E220000 */  lw        $v0, ($s1)
/* 9FC218 80241A28 3463FFFF */  ori       $v1, $v1, 0xffff
/* 9FC21C 80241A2C 00431024 */  and       $v0, $v0, $v1
/* 9FC220 80241A30 AE220000 */  sw        $v0, ($s1)
.L80241A34:
/* 9FC224 80241A34 27A50038 */  addiu     $a1, $sp, 0x38
/* 9FC228 80241A38 27A6003C */  addiu     $a2, $sp, 0x3c
/* 9FC22C 80241A3C C6400038 */  lwc1      $f0, 0x38($s2)
/* 9FC230 80241A40 864200A8 */  lh        $v0, 0xa8($s2)
/* 9FC234 80241A44 3C0142C8 */  lui       $at, 0x42c8
/* 9FC238 80241A48 44812000 */  mtc1      $at, $f4
/* 9FC23C 80241A4C 44823000 */  mtc1      $v0, $f6
/* 9FC240 80241A50 00000000 */  nop
/* 9FC244 80241A54 468031A0 */  cvt.s.w   $f6, $f6
/* 9FC248 80241A58 27A20044 */  addiu     $v0, $sp, 0x44
/* 9FC24C 80241A5C E7A00038 */  swc1      $f0, 0x38($sp)
/* 9FC250 80241A60 C640003C */  lwc1      $f0, 0x3c($s2)
/* 9FC254 80241A64 C6420040 */  lwc1      $f2, 0x40($s2)
/* 9FC258 80241A68 46060000 */  add.s     $f0, $f0, $f6
/* 9FC25C 80241A6C E7A40044 */  swc1      $f4, 0x44($sp)
/* 9FC260 80241A70 E7A20040 */  swc1      $f2, 0x40($sp)
/* 9FC264 80241A74 E7A0003C */  swc1      $f0, 0x3c($sp)
/* 9FC268 80241A78 AFA20010 */  sw        $v0, 0x10($sp)
/* 9FC26C 80241A7C 8E440080 */  lw        $a0, 0x80($s2)
/* 9FC270 80241A80 0C0372DF */  jal       func_800DCB7C
/* 9FC274 80241A84 27A70040 */   addiu    $a3, $sp, 0x40
/* 9FC278 80241A88 10400003 */  beqz      $v0, .L80241A98
/* 9FC27C 80241A8C 00000000 */   nop
/* 9FC280 80241A90 C7A0003C */  lwc1      $f0, 0x3c($sp)
/* 9FC284 80241A94 E640003C */  swc1      $f0, 0x3c($s2)
.L80241A98:
/* 9FC288 80241A98 8E830070 */  lw        $v1, 0x70($s4)
/* 9FC28C 80241A9C 2C620064 */  sltiu     $v0, $v1, 0x64
/* 9FC290 80241AA0 10400042 */  beqz      $v0, .L80241BAC
/* 9FC294 80241AA4 00031080 */   sll      $v0, $v1, 2
/* 9FC298 80241AA8 3C018024 */  lui       $at, %hi(jtbl_80245AE0_A002D0)
/* 9FC29C 80241AAC 00220821 */  addu      $at, $at, $v0
/* 9FC2A0 80241AB0 8C225AE0 */  lw        $v0, %lo(jtbl_80245AE0_A002D0)($at)
/* 9FC2A4 80241AB4 00400008 */  jr        $v0
/* 9FC2A8 80241AB8 00000000 */   nop
glabel L80241ABC_9FC2AC
/* 9FC2AC 80241ABC 0280202D */  daddu     $a0, $s4, $zero
/* 9FC2B0 80241AC0 0260282D */  daddu     $a1, $s3, $zero
/* 9FC2B4 80241AC4 0C090351 */  jal       func_80240D44_9FB534
/* 9FC2B8 80241AC8 02A0302D */   daddu    $a2, $s5, $zero
glabel L80241ACC_9FC2BC
/* 9FC2BC 80241ACC 0280202D */  daddu     $a0, $s4, $zero
/* 9FC2C0 80241AD0 0260282D */  daddu     $a1, $s3, $zero
/* 9FC2C4 80241AD4 0C0903A7 */  jal       func_80240E9C_9FB68C
/* 9FC2C8 80241AD8 02A0302D */   daddu    $a2, $s5, $zero
/* 9FC2CC 80241ADC 080906EB */  j         .L80241BAC
/* 9FC2D0 80241AE0 00000000 */   nop
glabel L80241AE4_9FC2D4
/* 9FC2D4 80241AE4 0280202D */  daddu     $a0, $s4, $zero
/* 9FC2D8 80241AE8 0260282D */  daddu     $a1, $s3, $zero
/* 9FC2DC 80241AEC 0C090451 */  jal       nok_12_UnkNpcAIFunc1
/* 9FC2E0 80241AF0 02A0302D */   daddu    $a2, $s5, $zero
glabel L80241AF4_9FC2E4
/* 9FC2E4 80241AF4 0280202D */  daddu     $a0, $s4, $zero
/* 9FC2E8 80241AF8 0260282D */  daddu     $a1, $s3, $zero
/* 9FC2EC 80241AFC 0C090481 */  jal       func_80241204_9FB9F4
/* 9FC2F0 80241B00 02A0302D */   daddu    $a2, $s5, $zero
/* 9FC2F4 80241B04 080906EB */  j         .L80241BAC
/* 9FC2F8 80241B08 00000000 */   nop
glabel L80241B0C_9FC2FC
/* 9FC2FC 80241B0C 0280202D */  daddu     $a0, $s4, $zero
/* 9FC300 80241B10 0260282D */  daddu     $a1, $s3, $zero
/* 9FC304 80241B14 0C0904F0 */  jal       func_802413C0_9FBBB0
/* 9FC308 80241B18 02A0302D */   daddu    $a2, $s5, $zero
/* 9FC30C 80241B1C 080906EB */  j         .L80241BAC
/* 9FC310 80241B20 00000000 */   nop
glabel L80241B24_9FC314
/* 9FC314 80241B24 0280202D */  daddu     $a0, $s4, $zero
/* 9FC318 80241B28 0260282D */  daddu     $a1, $s3, $zero
/* 9FC31C 80241B2C 0C09051D */  jal       nok_12_NpcJumpFunc2
/* 9FC320 80241B30 02A0302D */   daddu    $a2, $s5, $zero
glabel L80241B34_9FC324
/* 9FC324 80241B34 0280202D */  daddu     $a0, $s4, $zero
/* 9FC328 80241B38 0260282D */  daddu     $a1, $s3, $zero
/* 9FC32C 80241B3C 0C09053A */  jal       nok_12_NpcJumpFunc
/* 9FC330 80241B40 02A0302D */   daddu    $a2, $s5, $zero
/* 9FC334 80241B44 080906EB */  j         .L80241BAC
/* 9FC338 80241B48 00000000 */   nop
glabel L80241B4C_9FC33C
/* 9FC33C 80241B4C 0280202D */  daddu     $a0, $s4, $zero
/* 9FC340 80241B50 0260282D */  daddu     $a1, $s3, $zero
/* 9FC344 80241B54 0C090558 */  jal       func_80241560_9FBD50
/* 9FC348 80241B58 02A0302D */   daddu    $a2, $s5, $zero
glabel L80241B5C_9FC34C
/* 9FC34C 80241B5C 0280202D */  daddu     $a0, $s4, $zero
/* 9FC350 80241B60 0260282D */  daddu     $a1, $s3, $zero
/* 9FC354 80241B64 0C0905A4 */  jal       func_80241690_9FBE80
/* 9FC358 80241B68 02A0302D */   daddu    $a2, $s5, $zero
/* 9FC35C 80241B6C 080906EB */  j         .L80241BAC
/* 9FC360 80241B70 00000000 */   nop
glabel L80241B74_9FC364
/* 9FC364 80241B74 0280202D */  daddu     $a0, $s4, $zero
/* 9FC368 80241B78 0260282D */  daddu     $a1, $s3, $zero
/* 9FC36C 80241B7C 0C0905EC */  jal       nok_12_UnkNpcDurationFlagFunc
/* 9FC370 80241B80 02A0302D */   daddu    $a2, $s5, $zero
/* 9FC374 80241B84 080906EB */  j         .L80241BAC
/* 9FC378 80241B88 00000000 */   nop
glabel L80241B8C_9FC37C
/* 9FC37C 80241B8C 0280202D */  daddu     $a0, $s4, $zero
/* 9FC380 80241B90 0260282D */  daddu     $a1, $s3, $zero
/* 9FC384 80241B94 0C090606 */  jal       func_80241818_9FC008
/* 9FC388 80241B98 02A0302D */   daddu    $a2, $s5, $zero
/* 9FC38C 80241B9C 080906EB */  j         .L80241BAC
/* 9FC390 80241BA0 00000000 */   nop
glabel L80241BA4_9FC394
/* 9FC394 80241BA4 0C0129CF */  jal       func_8004A73C
/* 9FC398 80241BA8 0280202D */   daddu    $a0, $s4, $zero
.L80241BAC:
glabel L80241BAC_9FC39C
/* 9FC39C 80241BAC 8FBF0060 */  lw        $ra, 0x60($sp)
/* 9FC3A0 80241BB0 8FB5005C */  lw        $s5, 0x5c($sp)
/* 9FC3A4 80241BB4 8FB40058 */  lw        $s4, 0x58($sp)
/* 9FC3A8 80241BB8 8FB30054 */  lw        $s3, 0x54($sp)
/* 9FC3AC 80241BBC 8FB20050 */  lw        $s2, 0x50($sp)
/* 9FC3B0 80241BC0 8FB1004C */  lw        $s1, 0x4c($sp)
/* 9FC3B4 80241BC4 8FB00048 */  lw        $s0, 0x48($sp)
/* 9FC3B8 80241BC8 0000102D */  daddu     $v0, $zero, $zero
/* 9FC3BC 80241BCC 03E00008 */  jr        $ra
/* 9FC3C0 80241BD0 27BD0068 */   addiu    $sp, $sp, 0x68
