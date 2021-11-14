.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel D_802453F8_CD7228
.double 0.09

dlabel D_80245400_CD7230
.double 0.09

.section .text

glabel flo_16_func_80241000_CD2E30
/* CD2E30 80241000 27BDFF80 */  addiu     $sp, $sp, -0x80
/* CD2E34 80241004 AFB3004C */  sw        $s3, 0x4c($sp)
/* CD2E38 80241008 0080982D */  daddu     $s3, $a0, $zero
/* CD2E3C 8024100C AFBF0058 */  sw        $ra, 0x58($sp)
/* CD2E40 80241010 AFB50054 */  sw        $s5, 0x54($sp)
/* CD2E44 80241014 AFB40050 */  sw        $s4, 0x50($sp)
/* CD2E48 80241018 AFB20048 */  sw        $s2, 0x48($sp)
/* CD2E4C 8024101C AFB10044 */  sw        $s1, 0x44($sp)
/* CD2E50 80241020 AFB00040 */  sw        $s0, 0x40($sp)
/* CD2E54 80241024 F7BA0078 */  sdc1      $f26, 0x78($sp)
/* CD2E58 80241028 F7B80070 */  sdc1      $f24, 0x70($sp)
/* CD2E5C 8024102C F7B60068 */  sdc1      $f22, 0x68($sp)
/* CD2E60 80241030 F7B40060 */  sdc1      $f20, 0x60($sp)
/* CD2E64 80241034 8E710148 */  lw        $s1, 0x148($s3)
/* CD2E68 80241038 00A0902D */  daddu     $s2, $a1, $zero
/* CD2E6C 8024103C 86240008 */  lh        $a0, 8($s1)
/* CD2E70 80241040 0C00EABB */  jal       get_npc_unsafe
/* CD2E74 80241044 00C0A82D */   daddu    $s5, $a2, $zero
/* CD2E78 80241048 0040802D */  daddu     $s0, $v0, $zero
/* CD2E7C 8024104C 0000A02D */  daddu     $s4, $zero, $zero
/* CD2E80 80241050 C624007C */  lwc1      $f4, 0x7c($s1)
/* CD2E84 80241054 46802120 */  cvt.s.w   $f4, $f4
/* CD2E88 80241058 C6220088 */  lwc1      $f2, 0x88($s1)
/* CD2E8C 8024105C 468010A0 */  cvt.s.w   $f2, $f2
/* CD2E90 80241060 460010A1 */  cvt.d.s   $f2, $f2
/* CD2E94 80241064 46002121 */  cvt.d.s   $f4, $f4
/* CD2E98 80241068 C600003C */  lwc1      $f0, 0x3c($s0)
/* CD2E9C 8024106C 3C014059 */  lui       $at, 0x4059
/* CD2EA0 80241070 44813800 */  mtc1      $at, $f7
/* CD2EA4 80241074 44803000 */  mtc1      $zero, $f6
/* CD2EA8 80241078 46000021 */  cvt.d.s   $f0, $f0
/* CD2EAC 8024107C 46260002 */  mul.d     $f0, $f0, $f6
/* CD2EB0 80241080 00000000 */  nop
/* CD2EB4 80241084 24020001 */  addiu     $v0, $zero, 1
/* CD2EB8 80241088 8E24006C */  lw        $a0, 0x6c($s1)
/* CD2EBC 8024108C 46261083 */  div.d     $f2, $f2, $f6
/* CD2EC0 80241090 462010A0 */  cvt.s.d   $f2, $f2
/* CD2EC4 80241094 46262103 */  div.d     $f4, $f4, $f6
/* CD2EC8 80241098 46202520 */  cvt.s.d   $f20, $f4
/* CD2ECC 8024109C 30830011 */  andi      $v1, $a0, 0x11
/* CD2ED0 802410A0 4620020D */  trunc.w.d $f8, $f0
/* CD2ED4 802410A4 E628007C */  swc1      $f8, 0x7c($s1)
/* CD2ED8 802410A8 C6200078 */  lwc1      $f0, 0x78($s1)
/* CD2EDC 802410AC 46800020 */  cvt.s.w   $f0, $f0
/* CD2EE0 802410B0 46000021 */  cvt.d.s   $f0, $f0
/* CD2EE4 802410B4 46260003 */  div.d     $f0, $f0, $f6
/* CD2EE8 802410B8 462006A0 */  cvt.s.d   $f26, $f0
/* CD2EEC 802410BC C6200070 */  lwc1      $f0, 0x70($s1)
/* CD2EF0 802410C0 46800020 */  cvt.s.w   $f0, $f0
/* CD2EF4 802410C4 46000021 */  cvt.d.s   $f0, $f0
/* CD2EF8 802410C8 46260003 */  div.d     $f0, $f0, $f6
/* CD2EFC 802410CC 462005A0 */  cvt.s.d   $f22, $f0
/* CD2F00 802410D0 14620025 */  bne       $v1, $v0, .L80241168
/* CD2F04 802410D4 4602D600 */   add.s    $f24, $f26, $f2
/* CD2F08 802410D8 8E020000 */  lw        $v0, ($s0)
/* CD2F0C 802410DC 30420008 */  andi      $v0, $v0, 8
/* CD2F10 802410E0 10400009 */  beqz      $v0, .L80241108
/* CD2F14 802410E4 27A50028 */   addiu    $a1, $sp, 0x28
/* CD2F18 802410E8 C600003C */  lwc1      $f0, 0x3c($s0)
/* CD2F1C 802410EC 4600C001 */  sub.s     $f0, $f24, $f0
/* CD2F20 802410F0 4600B03C */  c.lt.s    $f22, $f0
/* CD2F24 802410F4 00000000 */  nop
/* CD2F28 802410F8 4500001B */  bc1f      .L80241168
/* CD2F2C 802410FC 34820010 */   ori      $v0, $a0, 0x10
/* CD2F30 80241100 0809045A */  j         .L80241168
/* CD2F34 80241104 AE22006C */   sw       $v0, 0x6c($s1)
.L80241108:
/* CD2F38 80241108 27A6002C */  addiu     $a2, $sp, 0x2c
/* CD2F3C 8024110C C6000038 */  lwc1      $f0, 0x38($s0)
/* CD2F40 80241110 C602003C */  lwc1      $f2, 0x3c($s0)
/* CD2F44 80241114 C6040040 */  lwc1      $f4, 0x40($s0)
/* CD2F48 80241118 3C01447A */  lui       $at, 0x447a
/* CD2F4C 8024111C 44813000 */  mtc1      $at, $f6
/* CD2F50 80241120 27A20034 */  addiu     $v0, $sp, 0x34
/* CD2F54 80241124 E7A00028 */  swc1      $f0, 0x28($sp)
/* CD2F58 80241128 E7A2002C */  swc1      $f2, 0x2c($sp)
/* CD2F5C 8024112C E7A40030 */  swc1      $f4, 0x30($sp)
/* CD2F60 80241130 E7A60034 */  swc1      $f6, 0x34($sp)
/* CD2F64 80241134 AFA20010 */  sw        $v0, 0x10($sp)
/* CD2F68 80241138 8E040080 */  lw        $a0, 0x80($s0)
/* CD2F6C 8024113C 0C0372DF */  jal       npc_raycast_down_sides
/* CD2F70 80241140 27A70030 */   addiu    $a3, $sp, 0x30
/* CD2F74 80241144 C7A00034 */  lwc1      $f0, 0x34($sp)
/* CD2F78 80241148 4600D001 */  sub.s     $f0, $f26, $f0
/* CD2F7C 8024114C 4600B03C */  c.lt.s    $f22, $f0
/* CD2F80 80241150 00000000 */  nop
/* CD2F84 80241154 45000004 */  bc1f      .L80241168
/* CD2F88 80241158 00000000 */   nop
/* CD2F8C 8024115C 8E22006C */  lw        $v0, 0x6c($s1)
/* CD2F90 80241160 34420010 */  ori       $v0, $v0, 0x10
/* CD2F94 80241164 AE22006C */  sw        $v0, 0x6c($s1)
.L80241168:
/* CD2F98 80241168 8E22006C */  lw        $v0, 0x6c($s1)
/* CD2F9C 8024116C 24030011 */  addiu     $v1, $zero, 0x11
/* CD2FA0 80241170 30420011 */  andi      $v0, $v0, 0x11
/* CD2FA4 80241174 14430039 */  bne       $v0, $v1, .L8024125C
/* CD2FA8 80241178 00000000 */   nop
/* CD2FAC 8024117C 8E020000 */  lw        $v0, ($s0)
/* CD2FB0 80241180 30420008 */  andi      $v0, $v0, 8
/* CD2FB4 80241184 1040000A */  beqz      $v0, .L802411B0
/* CD2FB8 80241188 4600C106 */   mov.s    $f4, $f24
/* CD2FBC 8024118C 4614C081 */  sub.s     $f2, $f24, $f20
/* CD2FC0 80241190 3C018024 */  lui       $at, %hi(D_802453F8_CD7228)
/* CD2FC4 80241194 D42053F8 */  ldc1      $f0, %lo(D_802453F8_CD7228)($at)
/* CD2FC8 80241198 460010A1 */  cvt.d.s   $f2, $f2
/* CD2FCC 8024119C 46201082 */  mul.d     $f2, $f2, $f0
/* CD2FD0 802411A0 00000000 */  nop
/* CD2FD4 802411A4 4600A021 */  cvt.d.s   $f0, $f20
/* CD2FD8 802411A8 08090485 */  j         .L80241214
/* CD2FDC 802411AC 46220000 */   add.d    $f0, $f0, $f2
.L802411B0:
/* CD2FE0 802411B0 27A50028 */  addiu     $a1, $sp, 0x28
/* CD2FE4 802411B4 27A6002C */  addiu     $a2, $sp, 0x2c
/* CD2FE8 802411B8 C6000038 */  lwc1      $f0, 0x38($s0)
/* CD2FEC 802411BC C6020040 */  lwc1      $f2, 0x40($s0)
/* CD2FF0 802411C0 3C01447A */  lui       $at, 0x447a
/* CD2FF4 802411C4 44812000 */  mtc1      $at, $f4
/* CD2FF8 802411C8 27A20034 */  addiu     $v0, $sp, 0x34
/* CD2FFC 802411CC E7B4002C */  swc1      $f20, 0x2c($sp)
/* CD3000 802411D0 E7A00028 */  swc1      $f0, 0x28($sp)
/* CD3004 802411D4 E7A20030 */  swc1      $f2, 0x30($sp)
/* CD3008 802411D8 E7A40034 */  swc1      $f4, 0x34($sp)
/* CD300C 802411DC AFA20010 */  sw        $v0, 0x10($sp)
/* CD3010 802411E0 8E040080 */  lw        $a0, 0x80($s0)
/* CD3014 802411E4 0C0372DF */  jal       npc_raycast_down_sides
/* CD3018 802411E8 27A70030 */   addiu    $a3, $sp, 0x30
/* CD301C 802411EC C7A4002C */  lwc1      $f4, 0x2c($sp)
/* CD3020 802411F0 461A2100 */  add.s     $f4, $f4, $f26
/* CD3024 802411F4 46142081 */  sub.s     $f2, $f4, $f20
/* CD3028 802411F8 3C018024 */  lui       $at, %hi(D_80245400_CD7230)
/* CD302C 802411FC D4205400 */  ldc1      $f0, %lo(D_80245400_CD7230)($at)
/* CD3030 80241200 460010A1 */  cvt.d.s   $f2, $f2
/* CD3034 80241204 46201082 */  mul.d     $f2, $f2, $f0
/* CD3038 80241208 00000000 */  nop
/* CD303C 8024120C 4600A021 */  cvt.d.s   $f0, $f20
/* CD3040 80241210 46220000 */  add.d     $f0, $f0, $f2
.L80241214:
/* CD3044 80241214 46200020 */  cvt.s.d   $f0, $f0
/* CD3048 80241218 E600003C */  swc1      $f0, 0x3c($s0)
/* CD304C 8024121C C600003C */  lwc1      $f0, 0x3c($s0)
/* CD3050 80241220 46002001 */  sub.s     $f0, $f4, $f0
/* CD3054 80241224 3C013FF0 */  lui       $at, 0x3ff0
/* CD3058 80241228 44811800 */  mtc1      $at, $f3
/* CD305C 8024122C 44801000 */  mtc1      $zero, $f2
/* CD3060 80241230 46000005 */  abs.s     $f0, $f0
/* CD3064 80241234 46000021 */  cvt.d.s   $f0, $f0
/* CD3068 80241238 4622003C */  c.lt.d    $f0, $f2
/* CD306C 8024123C 00000000 */  nop
/* CD3070 80241240 45000036 */  bc1f      .L8024131C
/* CD3074 80241244 2403FFEF */   addiu    $v1, $zero, -0x11
/* CD3078 80241248 E604003C */  swc1      $f4, 0x3c($s0)
/* CD307C 8024124C 8E22006C */  lw        $v0, 0x6c($s1)
/* CD3080 80241250 00431024 */  and       $v0, $v0, $v1
/* CD3084 80241254 080904C7 */  j         .L8024131C
/* CD3088 80241258 AE22006C */   sw       $v0, 0x6c($s1)
.L8024125C:
/* CD308C 8024125C 8E220070 */  lw        $v0, 0x70($s1)
/* CD3090 80241260 1840002E */  blez      $v0, .L8024131C
/* CD3094 80241264 00000000 */   nop
/* CD3098 80241268 C62C0074 */  lwc1      $f12, 0x74($s1)
/* CD309C 8024126C 0C00A8BB */  jal       sin_deg
/* CD30A0 80241270 46806320 */   cvt.s.w  $f12, $f12
/* CD30A4 80241274 8E020000 */  lw        $v0, ($s0)
/* CD30A8 80241278 30420008 */  andi      $v0, $v0, 8
/* CD30AC 8024127C 10400003 */  beqz      $v0, .L8024128C
/* CD30B0 80241280 46000506 */   mov.s    $f20, $f0
/* CD30B4 80241284 080904B3 */  j         .L802412CC
/* CD30B8 80241288 0000102D */   daddu    $v0, $zero, $zero
.L8024128C:
/* CD30BC 8024128C 27A50028 */  addiu     $a1, $sp, 0x28
/* CD30C0 80241290 27A6002C */  addiu     $a2, $sp, 0x2c
/* CD30C4 80241294 C6000038 */  lwc1      $f0, 0x38($s0)
/* CD30C8 80241298 C602003C */  lwc1      $f2, 0x3c($s0)
/* CD30CC 8024129C C6040040 */  lwc1      $f4, 0x40($s0)
/* CD30D0 802412A0 3C01447A */  lui       $at, 0x447a
/* CD30D4 802412A4 44813000 */  mtc1      $at, $f6
/* CD30D8 802412A8 27A20034 */  addiu     $v0, $sp, 0x34
/* CD30DC 802412AC E7A00028 */  swc1      $f0, 0x28($sp)
/* CD30E0 802412B0 E7A2002C */  swc1      $f2, 0x2c($sp)
/* CD30E4 802412B4 E7A40030 */  swc1      $f4, 0x30($sp)
/* CD30E8 802412B8 E7A60034 */  swc1      $f6, 0x34($sp)
/* CD30EC 802412BC AFA20010 */  sw        $v0, 0x10($sp)
/* CD30F0 802412C0 8E040080 */  lw        $a0, 0x80($s0)
/* CD30F4 802412C4 0C0372DF */  jal       npc_raycast_down_sides
/* CD30F8 802412C8 27A70030 */   addiu    $a3, $sp, 0x30
.L802412CC:
/* CD30FC 802412CC 10400007 */  beqz      $v0, .L802412EC
/* CD3100 802412D0 00000000 */   nop
/* CD3104 802412D4 4616A082 */  mul.s     $f2, $f20, $f22
/* CD3108 802412D8 00000000 */  nop
/* CD310C 802412DC C7A0002C */  lwc1      $f0, 0x2c($sp)
/* CD3110 802412E0 461A0000 */  add.s     $f0, $f0, $f26
/* CD3114 802412E4 080904BE */  j         .L802412F8
/* CD3118 802412E8 46020000 */   add.s    $f0, $f0, $f2
.L802412EC:
/* CD311C 802412EC 4616A002 */  mul.s     $f0, $f20, $f22
/* CD3120 802412F0 00000000 */  nop
/* CD3124 802412F4 4600C000 */  add.s     $f0, $f24, $f0
.L802412F8:
/* CD3128 802412F8 E600003C */  swc1      $f0, 0x3c($s0)
/* CD312C 802412FC 8E220074 */  lw        $v0, 0x74($s1)
/* CD3130 80241300 2442000A */  addiu     $v0, $v0, 0xa
/* CD3134 80241304 44826000 */  mtc1      $v0, $f12
/* CD3138 80241308 00000000 */  nop
/* CD313C 8024130C 0C00A6C9 */  jal       clamp_angle
/* CD3140 80241310 46806320 */   cvt.s.w  $f12, $f12
/* CD3144 80241314 4600020D */  trunc.w.s $f8, $f0
/* CD3148 80241318 E6280074 */  swc1      $f8, 0x74($s1)
.L8024131C:
/* CD314C 8024131C 8E220090 */  lw        $v0, 0x90($s1)
/* CD3150 80241320 1C40004A */  bgtz      $v0, .L8024144C
/* CD3154 80241324 2442FFFF */   addiu    $v0, $v0, -1
/* CD3158 80241328 8E430014 */  lw        $v1, 0x14($s2)
/* CD315C 8024132C 04600048 */  bltz      $v1, .L80241450
/* CD3160 80241330 00000000 */   nop
/* CD3164 80241334 8E620074 */  lw        $v0, 0x74($s3)
/* CD3168 80241338 1C400042 */  bgtz      $v0, .L80241444
/* CD316C 8024133C 2442FFFF */   addiu    $v0, $v0, -1
/* CD3170 80241340 AE630074 */  sw        $v1, 0x74($s3)
/* CD3174 80241344 860200A8 */  lh        $v0, 0xa8($s0)
/* CD3178 80241348 C602003C */  lwc1      $f2, 0x3c($s0)
/* CD317C 8024134C 44820000 */  mtc1      $v0, $f0
/* CD3180 80241350 00000000 */  nop
/* CD3184 80241354 46800020 */  cvt.s.w   $f0, $f0
/* CD3188 80241358 46001080 */  add.s     $f2, $f2, $f0
/* CD318C 8024135C 3C014024 */  lui       $at, 0x4024
/* CD3190 80241360 44810800 */  mtc1      $at, $f1
/* CD3194 80241364 44800000 */  mtc1      $zero, $f0
/* CD3198 80241368 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* CD319C 8024136C 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* CD31A0 80241370 460010A1 */  cvt.d.s   $f2, $f2
/* CD31A4 80241374 46201080 */  add.d     $f2, $f2, $f0
/* CD31A8 80241378 C440002C */  lwc1      $f0, 0x2c($v0)
/* CD31AC 8024137C 46000021 */  cvt.d.s   $f0, $f0
/* CD31B0 80241380 4622003C */  c.lt.d    $f0, $f2
/* CD31B4 80241384 00000000 */  nop
/* CD31B8 80241388 4500002C */  bc1f      .L8024143C
/* CD31BC 8024138C 02A0202D */   daddu    $a0, $s5, $zero
/* CD31C0 80241390 AFA00010 */  sw        $zero, 0x10($sp)
/* CD31C4 80241394 8E46000C */  lw        $a2, 0xc($s2)
/* CD31C8 80241398 8E470010 */  lw        $a3, 0x10($s2)
/* CD31CC 8024139C 0C01242D */  jal       func_800490B4
/* CD31D0 802413A0 0220282D */   daddu    $a1, $s1, $zero
/* CD31D4 802413A4 10400025 */  beqz      $v0, .L8024143C
/* CD31D8 802413A8 0000202D */   daddu    $a0, $zero, $zero
/* CD31DC 802413AC 0200282D */  daddu     $a1, $s0, $zero
/* CD31E0 802413B0 0000302D */  daddu     $a2, $zero, $zero
/* CD31E4 802413B4 2412000C */  addiu     $s2, $zero, 0xc
/* CD31E8 802413B8 860300A8 */  lh        $v1, 0xa8($s0)
/* CD31EC 802413BC 3C013F80 */  lui       $at, 0x3f80
/* CD31F0 802413C0 44810000 */  mtc1      $at, $f0
/* CD31F4 802413C4 3C014000 */  lui       $at, 0x4000
/* CD31F8 802413C8 44811000 */  mtc1      $at, $f2
/* CD31FC 802413CC 3C01C1A0 */  lui       $at, 0xc1a0
/* CD3200 802413D0 44812000 */  mtc1      $at, $f4
/* CD3204 802413D4 44834000 */  mtc1      $v1, $f8
/* CD3208 802413D8 00000000 */  nop
/* CD320C 802413DC 46804220 */  cvt.s.w   $f8, $f8
/* CD3210 802413E0 44074000 */  mfc1      $a3, $f8
/* CD3214 802413E4 27A20038 */  addiu     $v0, $sp, 0x38
/* CD3218 802413E8 AFB2001C */  sw        $s2, 0x1c($sp)
/* CD321C 802413EC AFA20020 */  sw        $v0, 0x20($sp)
/* CD3220 802413F0 E7A00010 */  swc1      $f0, 0x10($sp)
/* CD3224 802413F4 E7A20014 */  swc1      $f2, 0x14($sp)
/* CD3228 802413F8 0C01BFA4 */  jal       fx_emote
/* CD322C 802413FC E7A40018 */   swc1     $f4, 0x18($sp)
/* CD3230 80241400 0200202D */  daddu     $a0, $s0, $zero
/* CD3234 80241404 240502F4 */  addiu     $a1, $zero, 0x2f4
/* CD3238 80241408 C480003C */  lwc1      $f0, 0x3c($a0)
/* CD323C 8024140C 3C060020 */  lui       $a2, 0x20
/* CD3240 80241410 0C012530 */  jal       ai_enemy_play_sound
/* CD3244 80241414 E4800064 */   swc1     $f0, 0x64($a0)
/* CD3248 80241418 8E220018 */  lw        $v0, 0x18($s1)
/* CD324C 8024141C 9442002A */  lhu       $v0, 0x2a($v0)
/* CD3250 80241420 30420001 */  andi      $v0, $v0, 1
/* CD3254 80241424 10400003 */  beqz      $v0, .L80241434
/* CD3258 80241428 2402000A */   addiu    $v0, $zero, 0xa
/* CD325C 8024142C 0809057D */  j         .L802415F4
/* CD3260 80241430 AE620070 */   sw       $v0, 0x70($s3)
.L80241434:
/* CD3264 80241434 0809057D */  j         .L802415F4
/* CD3268 80241438 AE720070 */   sw       $s2, 0x70($s3)
.L8024143C:
/* CD326C 8024143C 8E620074 */  lw        $v0, 0x74($s3)
/* CD3270 80241440 2442FFFF */  addiu     $v0, $v0, -1
.L80241444:
/* CD3274 80241444 08090514 */  j         .L80241450
/* CD3278 80241448 AE620074 */   sw       $v0, 0x74($s3)
.L8024144C:
/* CD327C 8024144C AE220090 */  sw        $v0, 0x90($s1)
.L80241450:
/* CD3280 80241450 8E2300D0 */  lw        $v1, 0xd0($s1)
/* CD3284 80241454 C6000040 */  lwc1      $f0, 0x40($s0)
/* CD3288 80241458 C4620000 */  lwc1      $f2, ($v1)
/* CD328C 8024145C 468010A0 */  cvt.s.w   $f2, $f2
/* CD3290 80241460 C4640008 */  lwc1      $f4, 8($v1)
/* CD3294 80241464 46802120 */  cvt.s.w   $f4, $f4
/* CD3298 80241468 E7A00010 */  swc1      $f0, 0x10($sp)
/* CD329C 8024146C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* CD32A0 80241470 44051000 */  mfc1      $a1, $f2
/* CD32A4 80241474 C440000C */  lwc1      $f0, 0xc($v0)
/* CD32A8 80241478 46800020 */  cvt.s.w   $f0, $f0
/* CD32AC 8024147C E7A00014 */  swc1      $f0, 0x14($sp)
/* CD32B0 80241480 8E2200D0 */  lw        $v0, 0xd0($s1)
/* CD32B4 80241484 44062000 */  mfc1      $a2, $f4
/* CD32B8 80241488 C4400010 */  lwc1      $f0, 0x10($v0)
/* CD32BC 8024148C 46800020 */  cvt.s.w   $f0, $f0
/* CD32C0 80241490 E7A00018 */  swc1      $f0, 0x18($sp)
/* CD32C4 80241494 8C640018 */  lw        $a0, 0x18($v1)
/* CD32C8 80241498 0C0123F5 */  jal       is_point_within_region
/* CD32CC 8024149C 8E070038 */   lw       $a3, 0x38($s0)
/* CD32D0 802414A0 1040001A */  beqz      $v0, .L8024150C
/* CD32D4 802414A4 00000000 */   nop
/* CD32D8 802414A8 8E060038 */  lw        $a2, 0x38($s0)
/* CD32DC 802414AC 8E2200D0 */  lw        $v0, 0xd0($s1)
/* CD32E0 802414B0 8E070040 */  lw        $a3, 0x40($s0)
/* CD32E4 802414B4 C44C0000 */  lwc1      $f12, ($v0)
/* CD32E8 802414B8 46806320 */  cvt.s.w   $f12, $f12
/* CD32EC 802414BC C44E0008 */  lwc1      $f14, 8($v0)
/* CD32F0 802414C0 0C00A7B5 */  jal       dist2D
/* CD32F4 802414C4 468073A0 */   cvt.s.w  $f14, $f14
/* CD32F8 802414C8 C6020018 */  lwc1      $f2, 0x18($s0)
/* CD32FC 802414CC 4600103C */  c.lt.s    $f2, $f0
/* CD3300 802414D0 00000000 */  nop
/* CD3304 802414D4 4500000D */  bc1f      .L8024150C
/* CD3308 802414D8 E7A00034 */   swc1     $f0, 0x34($sp)
/* CD330C 802414DC C60C0038 */  lwc1      $f12, 0x38($s0)
/* CD3310 802414E0 8E2200D0 */  lw        $v0, 0xd0($s1)
/* CD3314 802414E4 C60E0040 */  lwc1      $f14, 0x40($s0)
/* CD3318 802414E8 C4480000 */  lwc1      $f8, ($v0)
/* CD331C 802414EC 46804220 */  cvt.s.w   $f8, $f8
/* CD3320 802414F0 44064000 */  mfc1      $a2, $f8
/* CD3324 802414F4 C4480008 */  lwc1      $f8, 8($v0)
/* CD3328 802414F8 46804220 */  cvt.s.w   $f8, $f8
/* CD332C 802414FC 44074000 */  mfc1      $a3, $f8
/* CD3330 80241500 0C00A720 */  jal       atan2
/* CD3334 80241504 24140001 */   addiu    $s4, $zero, 1
/* CD3338 80241508 E600000C */  swc1      $f0, 0xc($s0)
.L8024150C:
/* CD333C 8024150C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* CD3340 80241510 8C43000C */  lw        $v1, 0xc($v0)
/* CD3344 80241514 8C420010 */  lw        $v0, 0x10($v0)
/* CD3348 80241518 00621825 */  or        $v1, $v1, $v0
/* CD334C 8024151C 00741825 */  or        $v1, $v1, $s4
/* CD3350 80241520 10600008 */  beqz      $v1, .L80241544
/* CD3354 80241524 00000000 */   nop
/* CD3358 80241528 8602008C */  lh        $v0, 0x8c($s0)
/* CD335C 8024152C 14400031 */  bnez      $v0, .L802415F4
/* CD3360 80241530 00000000 */   nop
/* CD3364 80241534 8E050018 */  lw        $a1, 0x18($s0)
/* CD3368 80241538 8E06000C */  lw        $a2, 0xc($s0)
/* CD336C 8024153C 0C00EA95 */  jal       npc_move_heading
/* CD3370 80241540 0200202D */   daddu    $a0, $s0, $zero
.L80241544:
/* CD3374 80241544 C600003C */  lwc1      $f0, 0x3c($s0)
/* CD3378 80241548 3C014059 */  lui       $at, 0x4059
/* CD337C 8024154C 44811800 */  mtc1      $at, $f3
/* CD3380 80241550 44801000 */  mtc1      $zero, $f2
/* CD3384 80241554 46000021 */  cvt.d.s   $f0, $f0
/* CD3388 80241558 46220002 */  mul.d     $f0, $f0, $f2
/* CD338C 8024155C 00000000 */  nop
/* CD3390 80241560 4620020D */  trunc.w.d $f8, $f0
/* CD3394 80241564 E628007C */  swc1      $f8, 0x7c($s1)
/* CD3398 80241568 8E420004 */  lw        $v0, 4($s2)
/* CD339C 8024156C 18400021 */  blez      $v0, .L802415F4
/* CD33A0 80241570 00000000 */   nop
/* CD33A4 80241574 8602008E */  lh        $v0, 0x8e($s0)
/* CD33A8 80241578 9603008E */  lhu       $v1, 0x8e($s0)
/* CD33AC 8024157C 18400005 */  blez      $v0, .L80241594
/* CD33B0 80241580 2462FFFF */   addiu    $v0, $v1, -1
/* CD33B4 80241584 A602008E */  sh        $v0, 0x8e($s0)
/* CD33B8 80241588 00021400 */  sll       $v0, $v0, 0x10
/* CD33BC 8024158C 1C400019 */  bgtz      $v0, .L802415F4
/* CD33C0 80241590 00000000 */   nop
.L80241594:
/* CD33C4 80241594 240403E8 */  addiu     $a0, $zero, 0x3e8
/* CD33C8 80241598 24020002 */  addiu     $v0, $zero, 2
/* CD33CC 8024159C 0C00A67F */  jal       rand_int
/* CD33D0 802415A0 AE620070 */   sw       $v0, 0x70($s3)
/* CD33D4 802415A4 3C035555 */  lui       $v1, 0x5555
/* CD33D8 802415A8 34635556 */  ori       $v1, $v1, 0x5556
/* CD33DC 802415AC 00430018 */  mult      $v0, $v1
/* CD33E0 802415B0 000227C3 */  sra       $a0, $v0, 0x1f
/* CD33E4 802415B4 00004010 */  mfhi      $t0
/* CD33E8 802415B8 01042023 */  subu      $a0, $t0, $a0
/* CD33EC 802415BC 00041840 */  sll       $v1, $a0, 1
/* CD33F0 802415C0 00641821 */  addu      $v1, $v1, $a0
/* CD33F4 802415C4 00431023 */  subu      $v0, $v0, $v1
/* CD33F8 802415C8 24430002 */  addiu     $v1, $v0, 2
/* CD33FC 802415CC AE630074 */  sw        $v1, 0x74($s3)
/* CD3400 802415D0 8E42002C */  lw        $v0, 0x2c($s2)
/* CD3404 802415D4 58400007 */  blezl     $v0, .L802415F4
/* CD3408 802415D8 AE600070 */   sw       $zero, 0x70($s3)
/* CD340C 802415DC 8E420008 */  lw        $v0, 8($s2)
/* CD3410 802415E0 18400003 */  blez      $v0, .L802415F0
/* CD3414 802415E4 28620003 */   slti     $v0, $v1, 3
/* CD3418 802415E8 10400002 */  beqz      $v0, .L802415F4
/* CD341C 802415EC 00000000 */   nop
.L802415F0:
/* CD3420 802415F0 AE600070 */  sw        $zero, 0x70($s3)
.L802415F4:
/* CD3424 802415F4 8FBF0058 */  lw        $ra, 0x58($sp)
/* CD3428 802415F8 8FB50054 */  lw        $s5, 0x54($sp)
/* CD342C 802415FC 8FB40050 */  lw        $s4, 0x50($sp)
/* CD3430 80241600 8FB3004C */  lw        $s3, 0x4c($sp)
/* CD3434 80241604 8FB20048 */  lw        $s2, 0x48($sp)
/* CD3438 80241608 8FB10044 */  lw        $s1, 0x44($sp)
/* CD343C 8024160C 8FB00040 */  lw        $s0, 0x40($sp)
/* CD3440 80241610 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* CD3444 80241614 D7B80070 */  ldc1      $f24, 0x70($sp)
/* CD3448 80241618 D7B60068 */  ldc1      $f22, 0x68($sp)
/* CD344C 8024161C D7B40060 */  ldc1      $f20, 0x60($sp)
/* CD3450 80241620 03E00008 */  jr        $ra
/* CD3454 80241624 27BD0080 */   addiu    $sp, $sp, 0x80
