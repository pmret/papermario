.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80244750_AA7470
.double 190.0

.section .text

glabel func_80240048_AA2D68
/* AA2D68 80240048 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* AA2D6C 8024004C AFB3002C */  sw        $s3, 0x2c($sp)
/* AA2D70 80240050 0080982D */  daddu     $s3, $a0, $zero
/* AA2D74 80240054 AFB00020 */  sw        $s0, 0x20($sp)
/* AA2D78 80240058 00A0802D */  daddu     $s0, $a1, $zero
/* AA2D7C 8024005C AFBF003C */  sw        $ra, 0x3c($sp)
/* AA2D80 80240060 AFB60038 */  sw        $s6, 0x38($sp)
/* AA2D84 80240064 AFB50034 */  sw        $s5, 0x34($sp)
/* AA2D88 80240068 AFB40030 */  sw        $s4, 0x30($sp)
/* AA2D8C 8024006C AFB20028 */  sw        $s2, 0x28($sp)
/* AA2D90 80240070 AFB10024 */  sw        $s1, 0x24($sp)
/* AA2D94 80240074 F7B40040 */  sdc1      $f20, 0x40($sp)
/* AA2D98 80240078 8E720148 */  lw        $s2, 0x148($s3)
/* AA2D9C 8024007C 0000A02D */  daddu     $s4, $zero, $zero
/* AA2DA0 80240080 86440008 */  lh        $a0, 8($s2)
/* AA2DA4 80240084 0C00EABB */  jal       get_npc_unsafe
/* AA2DA8 80240088 0280A82D */   daddu    $s5, $s4, $zero
/* AA2DAC 8024008C 8E63000C */  lw        $v1, 0xc($s3)
/* AA2DB0 80240090 0260202D */  daddu     $a0, $s3, $zero
/* AA2DB4 80240094 8C650000 */  lw        $a1, ($v1)
/* AA2DB8 80240098 0C0B1EAF */  jal       evt_get_variable
/* AA2DBC 8024009C 0040882D */   daddu    $s1, $v0, $zero
/* AA2DC0 802400A0 16000005 */  bnez      $s0, .L802400B8
/* AA2DC4 802400A4 0040B02D */   daddu    $s6, $v0, $zero
/* AA2DC8 802400A8 8E43006C */  lw        $v1, 0x6c($s2)
/* AA2DCC 802400AC 24020064 */  addiu     $v0, $zero, 0x64
/* AA2DD0 802400B0 14620011 */  bne       $v1, $v0, .L802400F8
/* AA2DD4 802400B4 00000000 */   nop
.L802400B8:
/* AA2DD8 802400B8 AE600070 */  sw        $zero, 0x70($s3)
/* AA2DDC 802400BC A620008E */  sh        $zero, 0x8e($s1)
/* AA2DE0 802400C0 8E4200B0 */  lw        $v0, 0xb0($s2)
/* AA2DE4 802400C4 34420008 */  ori       $v0, $v0, 8
/* AA2DE8 802400C8 AE4200B0 */  sw        $v0, 0xb0($s2)
/* AA2DEC 802400CC 8E420000 */  lw        $v0, ($s2)
/* AA2DF0 802400D0 3C030020 */  lui       $v1, 0x20
/* AA2DF4 802400D4 00431025 */  or        $v0, $v0, $v1
/* AA2DF8 802400D8 AE420000 */  sw        $v0, ($s2)
/* AA2DFC 802400DC 8E220000 */  lw        $v0, ($s1)
/* AA2E00 802400E0 3C030004 */  lui       $v1, 4
/* AA2E04 802400E4 00431025 */  or        $v0, $v0, $v1
/* AA2E08 802400E8 AE220000 */  sw        $v0, ($s1)
/* AA2E0C 802400EC 2402FFFF */  addiu     $v0, $zero, -1
/* AA2E10 802400F0 AE40006C */  sw        $zero, 0x6c($s2)
/* AA2E14 802400F4 AE420070 */  sw        $v0, 0x70($s2)
.L802400F8:
/* AA2E18 802400F8 8E4300B0 */  lw        $v1, 0xb0($s2)
/* AA2E1C 802400FC 30620004 */  andi      $v0, $v1, 4
/* AA2E20 80240100 10400007 */  beqz      $v0, .L80240120
/* AA2E24 80240104 00000000 */   nop
/* AA2E28 80240108 824200B4 */  lb        $v0, 0xb4($s2)
/* AA2E2C 8024010C 144000DC */  bnez      $v0, .L80240480
/* AA2E30 80240110 0000102D */   daddu    $v0, $zero, $zero
/* AA2E34 80240114 2402FFFB */  addiu     $v0, $zero, -5
/* AA2E38 80240118 00621024 */  and       $v0, $v1, $v0
/* AA2E3C 8024011C AE4200B0 */  sw        $v0, 0xb0($s2)
.L80240120:
/* AA2E40 80240120 8E630070 */  lw        $v1, 0x70($s3)
/* AA2E44 80240124 24100001 */  addiu     $s0, $zero, 1
/* AA2E48 80240128 1070001C */  beq       $v1, $s0, .L8024019C
/* AA2E4C 8024012C 28620002 */   slti     $v0, $v1, 2
/* AA2E50 80240130 50400005 */  beql      $v0, $zero, .L80240148
/* AA2E54 80240134 24020002 */   addiu    $v0, $zero, 2
/* AA2E58 80240138 10600009 */  beqz      $v1, .L80240160
/* AA2E5C 8024013C 0220202D */   daddu    $a0, $s1, $zero
/* AA2E60 80240140 0809011C */  j         .L80240470
/* AA2E64 80240144 00000000 */   nop
.L80240148:
/* AA2E68 80240148 10620057 */  beq       $v1, $v0, .L802402A8
/* AA2E6C 8024014C 24020003 */   addiu    $v0, $zero, 3
/* AA2E70 80240150 106200C1 */  beq       $v1, $v0, .L80240458
/* AA2E74 80240154 00000000 */   nop
/* AA2E78 80240158 0809011C */  j         .L80240470
/* AA2E7C 8024015C 00000000 */   nop
.L80240160:
/* AA2E80 80240160 3C01C47A */  lui       $at, 0xc47a
/* AA2E84 80240164 44810000 */  mtc1      $at, $f0
/* AA2E88 80240168 8E230000 */  lw        $v1, ($s1)
/* AA2E8C 8024016C 2402FBFF */  addiu     $v0, $zero, -0x401
/* AA2E90 80240170 AE200038 */  sw        $zero, 0x38($s1)
/* AA2E94 80240174 AE200040 */  sw        $zero, 0x40($s1)
/* AA2E98 80240178 AE200048 */  sw        $zero, 0x48($s1)
/* AA2E9C 8024017C A620008E */  sh        $zero, 0x8e($s1)
/* AA2EA0 80240180 34630002 */  ori       $v1, $v1, 2
/* AA2EA4 80240184 00621824 */  and       $v1, $v1, $v0
/* AA2EA8 80240188 E620003C */  swc1      $f0, 0x3c($s1)
/* AA2EAC 8024018C 0C00EAFF */  jal       disable_npc_shadow
/* AA2EB0 80240190 AE230000 */   sw       $v1, ($s1)
/* AA2EB4 80240194 AE40006C */  sw        $zero, 0x6c($s2)
/* AA2EB8 80240198 AE700070 */  sw        $s0, 0x70($s3)
.L8024019C:
/* AA2EBC 8024019C 8E43006C */  lw        $v1, 0x6c($s2)
/* AA2EC0 802401A0 24020002 */  addiu     $v0, $zero, 2
/* AA2EC4 802401A4 146200B2 */  bne       $v1, $v0, .L80240470
/* AA2EC8 802401A8 24020003 */   addiu    $v0, $zero, 3
/* AA2ECC 802401AC 8E440070 */  lw        $a0, 0x70($s2)
/* AA2ED0 802401B0 0C00FB3A */  jal       get_enemy
/* AA2ED4 802401B4 AE42006C */   sw       $v0, 0x6c($s2)
/* AA2ED8 802401B8 84440008 */  lh        $a0, 8($v0)
/* AA2EDC 802401BC 0C00EABB */  jal       get_npc_unsafe
/* AA2EE0 802401C0 00000000 */   nop
/* AA2EE4 802401C4 8E230000 */  lw        $v1, ($s1)
/* AA2EE8 802401C8 2404FFFD */  addiu     $a0, $zero, -3
/* AA2EEC 802401CC 00641824 */  and       $v1, $v1, $a0
/* AA2EF0 802401D0 AE230000 */  sw        $v1, ($s1)
/* AA2EF4 802401D4 C4400038 */  lwc1      $f0, 0x38($v0)
/* AA2EF8 802401D8 E6200038 */  swc1      $f0, 0x38($s1)
/* AA2EFC 802401DC C440003C */  lwc1      $f0, 0x3c($v0)
/* AA2F00 802401E0 3C014026 */  lui       $at, 0x4026
/* AA2F04 802401E4 44811800 */  mtc1      $at, $f3
/* AA2F08 802401E8 44801000 */  mtc1      $zero, $f2
/* AA2F0C 802401EC 46000021 */  cvt.d.s   $f0, $f0
/* AA2F10 802401F0 46220000 */  add.d     $f0, $f0, $f2
/* AA2F14 802401F4 46200020 */  cvt.s.d   $f0, $f0
/* AA2F18 802401F8 E620003C */  swc1      $f0, 0x3c($s1)
/* AA2F1C 802401FC C4400040 */  lwc1      $f0, 0x40($v0)
/* AA2F20 80240200 3C013FF0 */  lui       $at, 0x3ff0
/* AA2F24 80240204 44811800 */  mtc1      $at, $f3
/* AA2F28 80240208 44801000 */  mtc1      $zero, $f2
/* AA2F2C 8024020C 46000021 */  cvt.d.s   $f0, $f0
/* AA2F30 80240210 46220000 */  add.d     $f0, $f0, $f2
/* AA2F34 80240214 3C0641C8 */  lui       $a2, 0x41c8
/* AA2F38 80240218 46200020 */  cvt.s.d   $f0, $f0
/* AA2F3C 8024021C E6200040 */  swc1      $f0, 0x40($s1)
/* AA2F40 80240220 C440000C */  lwc1      $f0, 0xc($v0)
/* AA2F44 80240224 E620000C */  swc1      $f0, 0xc($s1)
/* AA2F48 80240228 C6C00018 */  lwc1      $f0, 0x18($s6)
/* AA2F4C 8024022C 26250040 */  addiu     $a1, $s1, 0x40
/* AA2F50 80240230 E6200018 */  swc1      $f0, 0x18($s1)
/* AA2F54 80240234 8E4200CC */  lw        $v0, 0xcc($s2)
/* AA2F58 80240238 8E27000C */  lw        $a3, 0xc($s1)
/* AA2F5C 8024023C 8C420008 */  lw        $v0, 8($v0)
/* AA2F60 80240240 26240038 */  addiu     $a0, $s1, 0x38
/* AA2F64 80240244 0C00A7E7 */  jal       add_vec2D_polar
/* AA2F68 80240248 AE220028 */   sw       $v0, 0x28($s1)
/* AA2F6C 8024024C C620000C */  lwc1      $f0, 0xc($s1)
/* AA2F70 80240250 3C014334 */  lui       $at, 0x4334
/* AA2F74 80240254 44811000 */  mtc1      $at, $f2
/* AA2F78 80240258 00000000 */  nop
/* AA2F7C 8024025C 4602003C */  c.lt.s    $f0, $f2
/* AA2F80 80240260 00000000 */  nop
/* AA2F84 80240264 45020002 */  bc1fl     .L80240270
/* AA2F88 80240268 AE200034 */   sw       $zero, 0x34($s1)
/* AA2F8C 8024026C E6220034 */  swc1      $f2, 0x34($s1)
.L80240270:
/* AA2F90 80240270 3C060001 */  lui       $a2, 1
/* AA2F94 80240274 34C60400 */  ori       $a2, $a2, 0x400
/* AA2F98 80240278 8E4200CC */  lw        $v0, 0xcc($s2)
/* AA2F9C 8024027C 0220202D */  daddu     $a0, $s1, $zero
/* AA2FA0 80240280 8C45000C */  lw        $a1, 0xc($v0)
/* AA2FA4 80240284 8E220000 */  lw        $v0, ($s1)
/* AA2FA8 80240288 2403012C */  addiu     $v1, $zero, 0x12c
/* AA2FAC 8024028C A623008E */  sh        $v1, 0x8e($s1)
/* AA2FB0 80240290 00461025 */  or        $v0, $v0, $a2
/* AA2FB4 80240294 AE220000 */  sw        $v0, ($s1)
/* AA2FB8 80240298 0C00EAE8 */  jal       enable_npc_shadow
/* AA2FBC 8024029C AE250028 */   sw       $a1, 0x28($s1)
/* AA2FC0 802402A0 24020002 */  addiu     $v0, $zero, 2
/* AA2FC4 802402A4 AE620070 */  sw        $v0, 0x70($s3)
.L802402A8:
/* AA2FC8 802402A8 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* AA2FCC 802402AC 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* AA2FD0 802402B0 C620003C */  lwc1      $f0, 0x3c($s1)
/* AA2FD4 802402B4 C442002C */  lwc1      $f2, 0x2c($v0)
/* AA2FD8 802402B8 46020001 */  sub.s     $f0, $f0, $f2
/* AA2FDC 802402BC 3C018024 */  lui       $at, %hi(D_80244750_AA7470)
/* AA2FE0 802402C0 D4224750 */  ldc1      $f2, %lo(D_80244750_AA7470)($at)
/* AA2FE4 802402C4 46000121 */  cvt.d.s   $f4, $f0
/* AA2FE8 802402C8 4624103C */  c.lt.d    $f2, $f4
/* AA2FEC 802402CC 00000000 */  nop
/* AA2FF0 802402D0 45030067 */  bc1tl     .L80240470
/* AA2FF4 802402D4 24150001 */   addiu    $s5, $zero, 1
/* AA2FF8 802402D8 3C01C05E */  lui       $at, 0xc05e
/* AA2FFC 802402DC 44810800 */  mtc1      $at, $f1
/* AA3000 802402E0 44800000 */  mtc1      $zero, $f0
/* AA3004 802402E4 00000000 */  nop
/* AA3008 802402E8 4620203C */  c.lt.d    $f4, $f0
/* AA300C 802402EC 00000000 */  nop
/* AA3010 802402F0 4503005F */  bc1tl     .L80240470
/* AA3014 802402F4 24150001 */   addiu    $s5, $zero, 1
/* AA3018 802402F8 27A40018 */  addiu     $a0, $sp, 0x18
/* AA301C 802402FC 8E260018 */  lw        $a2, 0x18($s1)
/* AA3020 80240300 8E27000C */  lw        $a3, 0xc($s1)
/* AA3024 80240304 C6200038 */  lwc1      $f0, 0x38($s1)
/* AA3028 80240308 C6220040 */  lwc1      $f2, 0x40($s1)
/* AA302C 8024030C 27A5001C */  addiu     $a1, $sp, 0x1c
/* AA3030 80240310 E7A00018 */  swc1      $f0, 0x18($sp)
/* AA3034 80240314 0C00A7E7 */  jal       add_vec2D_polar
/* AA3038 80240318 E7A2001C */   swc1     $f2, 0x1c($sp)
/* AA303C 8024031C C622000C */  lwc1      $f2, 0xc($s1)
/* AA3040 80240320 3C014334 */  lui       $at, 0x4334
/* AA3044 80240324 44810000 */  mtc1      $at, $f0
/* AA3048 80240328 00000000 */  nop
/* AA304C 8024032C 4600103C */  c.lt.s    $f2, $f0
/* AA3050 80240330 00000000 */  nop
/* AA3054 80240334 45000007 */  bc1f      .L80240354
/* AA3058 80240338 00000000 */   nop
/* AA305C 8024033C C7A20018 */  lwc1      $f2, 0x18($sp)
/* AA3060 80240340 C6400074 */  lwc1      $f0, 0x74($s2)
/* AA3064 80240344 46800020 */  cvt.s.w   $f0, $f0
/* AA3068 80240348 4602003E */  c.le.s    $f0, $f2
/* AA306C 8024034C 080900DA */  j         .L80240368
/* AA3070 80240350 00000000 */   nop
.L80240354:
/* AA3074 80240354 C7A20018 */  lwc1      $f2, 0x18($sp)
/* AA3078 80240358 C6400074 */  lwc1      $f0, 0x74($s2)
/* AA307C 8024035C 46800020 */  cvt.s.w   $f0, $f0
/* AA3080 80240360 4600103E */  c.le.s    $f2, $f0
/* AA3084 80240364 00000000 */  nop
.L80240368:
/* AA3088 80240368 45030001 */  bc1tl     .L80240370
/* AA308C 8024036C 24140001 */   addiu    $s4, $zero, 1
.L80240370:
/* AA3090 80240370 12800031 */  beqz      $s4, .L80240438
/* AA3094 80240374 0220202D */   daddu    $a0, $s1, $zero
/* AA3098 80240378 3C05B000 */  lui       $a1, 0xb000
/* AA309C 8024037C 8E4200CC */  lw        $v0, 0xcc($s2)
/* AA30A0 80240380 34A50018 */  ori       $a1, $a1, 0x18
/* AA30A4 80240384 8C42001C */  lw        $v0, 0x1c($v0)
/* AA30A8 80240388 0000302D */  daddu     $a2, $zero, $zero
/* AA30AC 8024038C 0C012530 */  jal       ai_enemy_play_sound
/* AA30B0 80240390 AE220028 */   sw       $v0, 0x28($s1)
/* AA30B4 80240394 C620003C */  lwc1      $f0, 0x3c($s1)
/* AA30B8 80240398 3C0140A0 */  lui       $at, 0x40a0
/* AA30BC 8024039C 4481A000 */  mtc1      $at, $f20
/* AA30C0 802403A0 00000000 */  nop
/* AA30C4 802403A4 46140000 */  add.s     $f0, $f0, $f20
/* AA30C8 802403A8 C6240040 */  lwc1      $f4, 0x40($s1)
/* AA30CC 802403AC 3C013D4C */  lui       $at, 0x3d4c
/* AA30D0 802403B0 3421CCCD */  ori       $at, $at, 0xcccd
/* AA30D4 802403B4 44811000 */  mtc1      $at, $f2
/* AA30D8 802403B8 44060000 */  mfc1      $a2, $f0
/* AA30DC 802403BC 3C013F80 */  lui       $at, 0x3f80
/* AA30E0 802403C0 44810000 */  mtc1      $at, $f0
/* AA30E4 802403C4 24020014 */  addiu     $v0, $zero, 0x14
/* AA30E8 802403C8 AFA20014 */  sw        $v0, 0x14($sp)
/* AA30EC 802403CC 46002100 */  add.s     $f4, $f4, $f0
/* AA30F0 802403D0 E7A20010 */  swc1      $f2, 0x10($sp)
/* AA30F4 802403D4 8E250038 */  lw        $a1, 0x38($s1)
/* AA30F8 802403D8 44072000 */  mfc1      $a3, $f4
/* AA30FC 802403DC 0C01C184 */  jal       playFX_24
/* AA3100 802403E0 0000202D */   daddu    $a0, $zero, $zero
/* AA3104 802403E4 C620003C */  lwc1      $f0, 0x3c($s1)
/* AA3108 802403E8 46140000 */  add.s     $f0, $f0, $f20
/* AA310C 802403EC C6240040 */  lwc1      $f4, 0x40($s1)
/* AA3110 802403F0 3C013F99 */  lui       $at, 0x3f99
/* AA3114 802403F4 3421999A */  ori       $at, $at, 0x999a
/* AA3118 802403F8 44811000 */  mtc1      $at, $f2
/* AA311C 802403FC 44060000 */  mfc1      $a2, $f0
/* AA3120 80240400 44800000 */  mtc1      $zero, $f0
/* AA3124 80240404 24020019 */  addiu     $v0, $zero, 0x19
/* AA3128 80240408 AFA20014 */  sw        $v0, 0x14($sp)
/* AA312C 8024040C 46002100 */  add.s     $f4, $f4, $f0
/* AA3130 80240410 E7A20010 */  swc1      $f2, 0x10($sp)
/* AA3134 80240414 8E250038 */  lw        $a1, 0x38($s1)
/* AA3138 80240418 44072000 */  mfc1      $a3, $f4
/* AA313C 8024041C 0C01C1CC */  jal       playFX_27
/* AA3140 80240420 0000202D */   daddu    $a0, $zero, $zero
/* AA3144 80240424 24020001 */  addiu     $v0, $zero, 1
/* AA3148 80240428 A622008E */  sh        $v0, 0x8e($s1)
/* AA314C 8024042C 24020003 */  addiu     $v0, $zero, 3
/* AA3150 80240430 08090112 */  j         .L80240448
/* AA3154 80240434 AE620070 */   sw       $v0, 0x70($s3)
.L80240438:
/* AA3158 80240438 8E250018 */  lw        $a1, 0x18($s1)
/* AA315C 8024043C 8E26000C */  lw        $a2, 0xc($s1)
/* AA3160 80240440 0C00EA95 */  jal       npc_move_heading
/* AA3164 80240444 0220202D */   daddu    $a0, $s1, $zero
.L80240448:
/* AA3168 80240448 8E630070 */  lw        $v1, 0x70($s3)
/* AA316C 8024044C 24020003 */  addiu     $v0, $zero, 3
/* AA3170 80240450 14620007 */  bne       $v1, $v0, .L80240470
/* AA3174 80240454 00000000 */   nop
.L80240458:
/* AA3178 80240458 9622008E */  lhu       $v0, 0x8e($s1)
/* AA317C 8024045C 2442FFFF */  addiu     $v0, $v0, -1
/* AA3180 80240460 A622008E */  sh        $v0, 0x8e($s1)
/* AA3184 80240464 00021400 */  sll       $v0, $v0, 0x10
/* AA3188 80240468 58400001 */  blezl     $v0, .L80240470
/* AA318C 8024046C 24150001 */   addiu    $s5, $zero, 1
.L80240470:
/* AA3190 80240470 12A00002 */  beqz      $s5, .L8024047C
/* AA3194 80240474 24020064 */   addiu    $v0, $zero, 0x64
/* AA3198 80240478 AE42006C */  sw        $v0, 0x6c($s2)
.L8024047C:
/* AA319C 8024047C 0000102D */  daddu     $v0, $zero, $zero
.L80240480:
/* AA31A0 80240480 8FBF003C */  lw        $ra, 0x3c($sp)
/* AA31A4 80240484 8FB60038 */  lw        $s6, 0x38($sp)
/* AA31A8 80240488 8FB50034 */  lw        $s5, 0x34($sp)
/* AA31AC 8024048C 8FB40030 */  lw        $s4, 0x30($sp)
/* AA31B0 80240490 8FB3002C */  lw        $s3, 0x2c($sp)
/* AA31B4 80240494 8FB20028 */  lw        $s2, 0x28($sp)
/* AA31B8 80240498 8FB10024 */  lw        $s1, 0x24($sp)
/* AA31BC 8024049C 8FB00020 */  lw        $s0, 0x20($sp)
/* AA31C0 802404A0 D7B40040 */  ldc1      $f20, 0x40($sp)
/* AA31C4 802404A4 03E00008 */  jr        $ra
/* AA31C8 802404A8 27BD0048 */   addiu    $sp, $sp, 0x48
