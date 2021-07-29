.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_802455F8_DB78B8
.double 0.09

glabel D_80245600_DB78C0
.byte 0x3F, 0xB7, 0x0A, 0x3D, 0x70, 0xA3, 0xD7, 0x0A

.section .text

glabel func_80240C04_DB2EC4
/* DB2EC4 80240C04 27BDFF80 */  addiu     $sp, $sp, -0x80
/* DB2EC8 80240C08 AFB3004C */  sw        $s3, 0x4c($sp)
/* DB2ECC 80240C0C 0080982D */  daddu     $s3, $a0, $zero
/* DB2ED0 80240C10 AFBF0058 */  sw        $ra, 0x58($sp)
/* DB2ED4 80240C14 AFB50054 */  sw        $s5, 0x54($sp)
/* DB2ED8 80240C18 AFB40050 */  sw        $s4, 0x50($sp)
/* DB2EDC 80240C1C AFB20048 */  sw        $s2, 0x48($sp)
/* DB2EE0 80240C20 AFB10044 */  sw        $s1, 0x44($sp)
/* DB2EE4 80240C24 AFB00040 */  sw        $s0, 0x40($sp)
/* DB2EE8 80240C28 F7BA0078 */  sdc1      $f26, 0x78($sp)
/* DB2EEC 80240C2C F7B80070 */  sdc1      $f24, 0x70($sp)
/* DB2EF0 80240C30 F7B60068 */  sdc1      $f22, 0x68($sp)
/* DB2EF4 80240C34 F7B40060 */  sdc1      $f20, 0x60($sp)
/* DB2EF8 80240C38 8E710148 */  lw        $s1, 0x148($s3)
/* DB2EFC 80240C3C 00A0902D */  daddu     $s2, $a1, $zero
/* DB2F00 80240C40 86240008 */  lh        $a0, 8($s1)
/* DB2F04 80240C44 0C00EABB */  jal       get_npc_unsafe
/* DB2F08 80240C48 00C0A82D */   daddu    $s5, $a2, $zero
/* DB2F0C 80240C4C 0040802D */  daddu     $s0, $v0, $zero
/* DB2F10 80240C50 0000A02D */  daddu     $s4, $zero, $zero
/* DB2F14 80240C54 C624007C */  lwc1      $f4, 0x7c($s1)
/* DB2F18 80240C58 46802120 */  cvt.s.w   $f4, $f4
/* DB2F1C 80240C5C C6220088 */  lwc1      $f2, 0x88($s1)
/* DB2F20 80240C60 468010A0 */  cvt.s.w   $f2, $f2
/* DB2F24 80240C64 460010A1 */  cvt.d.s   $f2, $f2
/* DB2F28 80240C68 46002121 */  cvt.d.s   $f4, $f4
/* DB2F2C 80240C6C C600003C */  lwc1      $f0, 0x3c($s0)
/* DB2F30 80240C70 3C014059 */  lui       $at, 0x4059
/* DB2F34 80240C74 44813800 */  mtc1      $at, $f7
/* DB2F38 80240C78 44803000 */  mtc1      $zero, $f6
/* DB2F3C 80240C7C 46000021 */  cvt.d.s   $f0, $f0
/* DB2F40 80240C80 46260002 */  mul.d     $f0, $f0, $f6
/* DB2F44 80240C84 00000000 */  nop
/* DB2F48 80240C88 24020001 */  addiu     $v0, $zero, 1
/* DB2F4C 80240C8C 8E24006C */  lw        $a0, 0x6c($s1)
/* DB2F50 80240C90 46261083 */  div.d     $f2, $f2, $f6
/* DB2F54 80240C94 462010A0 */  cvt.s.d   $f2, $f2
/* DB2F58 80240C98 46262103 */  div.d     $f4, $f4, $f6
/* DB2F5C 80240C9C 46202520 */  cvt.s.d   $f20, $f4
/* DB2F60 80240CA0 30830011 */  andi      $v1, $a0, 0x11
/* DB2F64 80240CA4 4620020D */  trunc.w.d $f8, $f0
/* DB2F68 80240CA8 E628007C */  swc1      $f8, 0x7c($s1)
/* DB2F6C 80240CAC C6200078 */  lwc1      $f0, 0x78($s1)
/* DB2F70 80240CB0 46800020 */  cvt.s.w   $f0, $f0
/* DB2F74 80240CB4 46000021 */  cvt.d.s   $f0, $f0
/* DB2F78 80240CB8 46260003 */  div.d     $f0, $f0, $f6
/* DB2F7C 80240CBC 462006A0 */  cvt.s.d   $f26, $f0
/* DB2F80 80240CC0 C6200070 */  lwc1      $f0, 0x70($s1)
/* DB2F84 80240CC4 46800020 */  cvt.s.w   $f0, $f0
/* DB2F88 80240CC8 46000021 */  cvt.d.s   $f0, $f0
/* DB2F8C 80240CCC 46260003 */  div.d     $f0, $f0, $f6
/* DB2F90 80240CD0 462005A0 */  cvt.s.d   $f22, $f0
/* DB2F94 80240CD4 14620025 */  bne       $v1, $v0, .L80240D6C
/* DB2F98 80240CD8 4602D600 */   add.s    $f24, $f26, $f2
/* DB2F9C 80240CDC 8E020000 */  lw        $v0, ($s0)
/* DB2FA0 80240CE0 30420008 */  andi      $v0, $v0, 8
/* DB2FA4 80240CE4 10400009 */  beqz      $v0, .L80240D0C
/* DB2FA8 80240CE8 27A50028 */   addiu    $a1, $sp, 0x28
/* DB2FAC 80240CEC C600003C */  lwc1      $f0, 0x3c($s0)
/* DB2FB0 80240CF0 4600C001 */  sub.s     $f0, $f24, $f0
/* DB2FB4 80240CF4 4600B03C */  c.lt.s    $f22, $f0
/* DB2FB8 80240CF8 00000000 */  nop
/* DB2FBC 80240CFC 4500001B */  bc1f      .L80240D6C
/* DB2FC0 80240D00 34820010 */   ori      $v0, $a0, 0x10
/* DB2FC4 80240D04 0809035B */  j         .L80240D6C
/* DB2FC8 80240D08 AE22006C */   sw       $v0, 0x6c($s1)
.L80240D0C:
/* DB2FCC 80240D0C 27A6002C */  addiu     $a2, $sp, 0x2c
/* DB2FD0 80240D10 C6000038 */  lwc1      $f0, 0x38($s0)
/* DB2FD4 80240D14 C602003C */  lwc1      $f2, 0x3c($s0)
/* DB2FD8 80240D18 C6040040 */  lwc1      $f4, 0x40($s0)
/* DB2FDC 80240D1C 3C01447A */  lui       $at, 0x447a
/* DB2FE0 80240D20 44813000 */  mtc1      $at, $f6
/* DB2FE4 80240D24 27A20034 */  addiu     $v0, $sp, 0x34
/* DB2FE8 80240D28 E7A00028 */  swc1      $f0, 0x28($sp)
/* DB2FEC 80240D2C E7A2002C */  swc1      $f2, 0x2c($sp)
/* DB2FF0 80240D30 E7A40030 */  swc1      $f4, 0x30($sp)
/* DB2FF4 80240D34 E7A60034 */  swc1      $f6, 0x34($sp)
/* DB2FF8 80240D38 AFA20010 */  sw        $v0, 0x10($sp)
/* DB2FFC 80240D3C 8E040080 */  lw        $a0, 0x80($s0)
/* DB3000 80240D40 0C0372DF */  jal       npc_raycast_down_sides
/* DB3004 80240D44 27A70030 */   addiu    $a3, $sp, 0x30
/* DB3008 80240D48 C7A00034 */  lwc1      $f0, 0x34($sp)
/* DB300C 80240D4C 4600D001 */  sub.s     $f0, $f26, $f0
/* DB3010 80240D50 4600B03C */  c.lt.s    $f22, $f0
/* DB3014 80240D54 00000000 */  nop
/* DB3018 80240D58 45000004 */  bc1f      .L80240D6C
/* DB301C 80240D5C 00000000 */   nop
/* DB3020 80240D60 8E22006C */  lw        $v0, 0x6c($s1)
/* DB3024 80240D64 34420010 */  ori       $v0, $v0, 0x10
/* DB3028 80240D68 AE22006C */  sw        $v0, 0x6c($s1)
.L80240D6C:
/* DB302C 80240D6C 8E22006C */  lw        $v0, 0x6c($s1)
/* DB3030 80240D70 24030011 */  addiu     $v1, $zero, 0x11
/* DB3034 80240D74 30420011 */  andi      $v0, $v0, 0x11
/* DB3038 80240D78 14430039 */  bne       $v0, $v1, .L80240E60
/* DB303C 80240D7C 00000000 */   nop
/* DB3040 80240D80 8E020000 */  lw        $v0, ($s0)
/* DB3044 80240D84 30420008 */  andi      $v0, $v0, 8
/* DB3048 80240D88 1040000A */  beqz      $v0, .L80240DB4
/* DB304C 80240D8C 4600C106 */   mov.s    $f4, $f24
/* DB3050 80240D90 4614C081 */  sub.s     $f2, $f24, $f20
/* DB3054 80240D94 3C018024 */  lui       $at, %hi(D_802455F8_DB78B8)
/* DB3058 80240D98 D42055F8 */  ldc1      $f0, %lo(D_802455F8_DB78B8)($at)
/* DB305C 80240D9C 460010A1 */  cvt.d.s   $f2, $f2
/* DB3060 80240DA0 46201082 */  mul.d     $f2, $f2, $f0
/* DB3064 80240DA4 00000000 */  nop
/* DB3068 80240DA8 4600A021 */  cvt.d.s   $f0, $f20
/* DB306C 80240DAC 08090386 */  j         .L80240E18
/* DB3070 80240DB0 46220000 */   add.d    $f0, $f0, $f2
.L80240DB4:
/* DB3074 80240DB4 27A50028 */  addiu     $a1, $sp, 0x28
/* DB3078 80240DB8 27A6002C */  addiu     $a2, $sp, 0x2c
/* DB307C 80240DBC C6000038 */  lwc1      $f0, 0x38($s0)
/* DB3080 80240DC0 C6020040 */  lwc1      $f2, 0x40($s0)
/* DB3084 80240DC4 3C01447A */  lui       $at, 0x447a
/* DB3088 80240DC8 44812000 */  mtc1      $at, $f4
/* DB308C 80240DCC 27A20034 */  addiu     $v0, $sp, 0x34
/* DB3090 80240DD0 E7B4002C */  swc1      $f20, 0x2c($sp)
/* DB3094 80240DD4 E7A00028 */  swc1      $f0, 0x28($sp)
/* DB3098 80240DD8 E7A20030 */  swc1      $f2, 0x30($sp)
/* DB309C 80240DDC E7A40034 */  swc1      $f4, 0x34($sp)
/* DB30A0 80240DE0 AFA20010 */  sw        $v0, 0x10($sp)
/* DB30A4 80240DE4 8E040080 */  lw        $a0, 0x80($s0)
/* DB30A8 80240DE8 0C0372DF */  jal       npc_raycast_down_sides
/* DB30AC 80240DEC 27A70030 */   addiu    $a3, $sp, 0x30
/* DB30B0 80240DF0 C7A4002C */  lwc1      $f4, 0x2c($sp)
/* DB30B4 80240DF4 461A2100 */  add.s     $f4, $f4, $f26
/* DB30B8 80240DF8 46142081 */  sub.s     $f2, $f4, $f20
/* DB30BC 80240DFC 3C018024 */  lui       $at, %hi(D_80245600_DB78C0)
/* DB30C0 80240E00 D4205600 */  ldc1      $f0, %lo(D_80245600_DB78C0)($at)
/* DB30C4 80240E04 460010A1 */  cvt.d.s   $f2, $f2
/* DB30C8 80240E08 46201082 */  mul.d     $f2, $f2, $f0
/* DB30CC 80240E0C 00000000 */  nop
/* DB30D0 80240E10 4600A021 */  cvt.d.s   $f0, $f20
/* DB30D4 80240E14 46220000 */  add.d     $f0, $f0, $f2
.L80240E18:
/* DB30D8 80240E18 46200020 */  cvt.s.d   $f0, $f0
/* DB30DC 80240E1C E600003C */  swc1      $f0, 0x3c($s0)
/* DB30E0 80240E20 C600003C */  lwc1      $f0, 0x3c($s0)
/* DB30E4 80240E24 46002001 */  sub.s     $f0, $f4, $f0
/* DB30E8 80240E28 3C013FF0 */  lui       $at, 0x3ff0
/* DB30EC 80240E2C 44811800 */  mtc1      $at, $f3
/* DB30F0 80240E30 44801000 */  mtc1      $zero, $f2
/* DB30F4 80240E34 46000005 */  abs.s     $f0, $f0
/* DB30F8 80240E38 46000021 */  cvt.d.s   $f0, $f0
/* DB30FC 80240E3C 4622003C */  c.lt.d    $f0, $f2
/* DB3100 80240E40 00000000 */  nop
/* DB3104 80240E44 45000036 */  bc1f      .L80240F20
/* DB3108 80240E48 2403FFEF */   addiu    $v1, $zero, -0x11
/* DB310C 80240E4C E604003C */  swc1      $f4, 0x3c($s0)
/* DB3110 80240E50 8E22006C */  lw        $v0, 0x6c($s1)
/* DB3114 80240E54 00431024 */  and       $v0, $v0, $v1
/* DB3118 80240E58 080903C8 */  j         .L80240F20
/* DB311C 80240E5C AE22006C */   sw       $v0, 0x6c($s1)
.L80240E60:
/* DB3120 80240E60 8E220070 */  lw        $v0, 0x70($s1)
/* DB3124 80240E64 1840002E */  blez      $v0, .L80240F20
/* DB3128 80240E68 00000000 */   nop
/* DB312C 80240E6C C62C0074 */  lwc1      $f12, 0x74($s1)
/* DB3130 80240E70 0C00A8BB */  jal       sin_deg
/* DB3134 80240E74 46806320 */   cvt.s.w  $f12, $f12
/* DB3138 80240E78 8E020000 */  lw        $v0, ($s0)
/* DB313C 80240E7C 30420008 */  andi      $v0, $v0, 8
/* DB3140 80240E80 10400003 */  beqz      $v0, .L80240E90
/* DB3144 80240E84 46000506 */   mov.s    $f20, $f0
/* DB3148 80240E88 080903B4 */  j         .L80240ED0
/* DB314C 80240E8C 0000102D */   daddu    $v0, $zero, $zero
.L80240E90:
/* DB3150 80240E90 27A50028 */  addiu     $a1, $sp, 0x28
/* DB3154 80240E94 27A6002C */  addiu     $a2, $sp, 0x2c
/* DB3158 80240E98 C6000038 */  lwc1      $f0, 0x38($s0)
/* DB315C 80240E9C C602003C */  lwc1      $f2, 0x3c($s0)
/* DB3160 80240EA0 C6040040 */  lwc1      $f4, 0x40($s0)
/* DB3164 80240EA4 3C01447A */  lui       $at, 0x447a
/* DB3168 80240EA8 44813000 */  mtc1      $at, $f6
/* DB316C 80240EAC 27A20034 */  addiu     $v0, $sp, 0x34
/* DB3170 80240EB0 E7A00028 */  swc1      $f0, 0x28($sp)
/* DB3174 80240EB4 E7A2002C */  swc1      $f2, 0x2c($sp)
/* DB3178 80240EB8 E7A40030 */  swc1      $f4, 0x30($sp)
/* DB317C 80240EBC E7A60034 */  swc1      $f6, 0x34($sp)
/* DB3180 80240EC0 AFA20010 */  sw        $v0, 0x10($sp)
/* DB3184 80240EC4 8E040080 */  lw        $a0, 0x80($s0)
/* DB3188 80240EC8 0C0372DF */  jal       npc_raycast_down_sides
/* DB318C 80240ECC 27A70030 */   addiu    $a3, $sp, 0x30
.L80240ED0:
/* DB3190 80240ED0 10400007 */  beqz      $v0, .L80240EF0
/* DB3194 80240ED4 00000000 */   nop
/* DB3198 80240ED8 4616A082 */  mul.s     $f2, $f20, $f22
/* DB319C 80240EDC 00000000 */  nop
/* DB31A0 80240EE0 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* DB31A4 80240EE4 461A0000 */  add.s     $f0, $f0, $f26
/* DB31A8 80240EE8 080903BF */  j         .L80240EFC
/* DB31AC 80240EEC 46020000 */   add.s    $f0, $f0, $f2
.L80240EF0:
/* DB31B0 80240EF0 4616A002 */  mul.s     $f0, $f20, $f22
/* DB31B4 80240EF4 00000000 */  nop
/* DB31B8 80240EF8 4600C000 */  add.s     $f0, $f24, $f0
.L80240EFC:
/* DB31BC 80240EFC E600003C */  swc1      $f0, 0x3c($s0)
/* DB31C0 80240F00 8E220074 */  lw        $v0, 0x74($s1)
/* DB31C4 80240F04 2442000A */  addiu     $v0, $v0, 0xa
/* DB31C8 80240F08 44826000 */  mtc1      $v0, $f12
/* DB31CC 80240F0C 00000000 */  nop
/* DB31D0 80240F10 0C00A6C9 */  jal       clamp_angle
/* DB31D4 80240F14 46806320 */   cvt.s.w  $f12, $f12
/* DB31D8 80240F18 4600020D */  trunc.w.s $f8, $f0
/* DB31DC 80240F1C E6280074 */  swc1      $f8, 0x74($s1)
.L80240F20:
/* DB31E0 80240F20 8E220090 */  lw        $v0, 0x90($s1)
/* DB31E4 80240F24 1C40004A */  bgtz      $v0, .L80241050
/* DB31E8 80240F28 2442FFFF */   addiu    $v0, $v0, -1
/* DB31EC 80240F2C 8E430014 */  lw        $v1, 0x14($s2)
/* DB31F0 80240F30 04600048 */  bltz      $v1, .L80241054
/* DB31F4 80240F34 00000000 */   nop
/* DB31F8 80240F38 8E620074 */  lw        $v0, 0x74($s3)
/* DB31FC 80240F3C 1C400042 */  bgtz      $v0, .L80241048
/* DB3200 80240F40 2442FFFF */   addiu    $v0, $v0, -1
/* DB3204 80240F44 AE630074 */  sw        $v1, 0x74($s3)
/* DB3208 80240F48 860200A8 */  lh        $v0, 0xa8($s0)
/* DB320C 80240F4C C602003C */  lwc1      $f2, 0x3c($s0)
/* DB3210 80240F50 44820000 */  mtc1      $v0, $f0
/* DB3214 80240F54 00000000 */  nop
/* DB3218 80240F58 46800020 */  cvt.s.w   $f0, $f0
/* DB321C 80240F5C 46001080 */  add.s     $f2, $f2, $f0
/* DB3220 80240F60 3C014024 */  lui       $at, 0x4024
/* DB3224 80240F64 44810800 */  mtc1      $at, $f1
/* DB3228 80240F68 44800000 */  mtc1      $zero, $f0
/* DB322C 80240F6C 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* DB3230 80240F70 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* DB3234 80240F74 460010A1 */  cvt.d.s   $f2, $f2
/* DB3238 80240F78 46201080 */  add.d     $f2, $f2, $f0
/* DB323C 80240F7C C440002C */  lwc1      $f0, 0x2c($v0)
/* DB3240 80240F80 46000021 */  cvt.d.s   $f0, $f0
/* DB3244 80240F84 4622003C */  c.lt.d    $f0, $f2
/* DB3248 80240F88 00000000 */  nop
/* DB324C 80240F8C 4500002C */  bc1f      .L80241040
/* DB3250 80240F90 02A0202D */   daddu    $a0, $s5, $zero
/* DB3254 80240F94 AFA00010 */  sw        $zero, 0x10($sp)
/* DB3258 80240F98 8E46000C */  lw        $a2, 0xc($s2)
/* DB325C 80240F9C 8E470010 */  lw        $a3, 0x10($s2)
/* DB3260 80240FA0 0C01242D */  jal       func_800490B4
/* DB3264 80240FA4 0220282D */   daddu    $a1, $s1, $zero
/* DB3268 80240FA8 10400025 */  beqz      $v0, .L80241040
/* DB326C 80240FAC 0000202D */   daddu    $a0, $zero, $zero
/* DB3270 80240FB0 0200282D */  daddu     $a1, $s0, $zero
/* DB3274 80240FB4 0000302D */  daddu     $a2, $zero, $zero
/* DB3278 80240FB8 2412000C */  addiu     $s2, $zero, 0xc
/* DB327C 80240FBC 860300A8 */  lh        $v1, 0xa8($s0)
/* DB3280 80240FC0 3C013F80 */  lui       $at, 0x3f80
/* DB3284 80240FC4 44810000 */  mtc1      $at, $f0
/* DB3288 80240FC8 3C014000 */  lui       $at, 0x4000
/* DB328C 80240FCC 44811000 */  mtc1      $at, $f2
/* DB3290 80240FD0 3C01C1A0 */  lui       $at, 0xc1a0
/* DB3294 80240FD4 44812000 */  mtc1      $at, $f4
/* DB3298 80240FD8 44834000 */  mtc1      $v1, $f8
/* DB329C 80240FDC 00000000 */  nop
/* DB32A0 80240FE0 46804220 */  cvt.s.w   $f8, $f8
/* DB32A4 80240FE4 44074000 */  mfc1      $a3, $f8
/* DB32A8 80240FE8 27A20038 */  addiu     $v0, $sp, 0x38
/* DB32AC 80240FEC AFB2001C */  sw        $s2, 0x1c($sp)
/* DB32B0 80240FF0 AFA20020 */  sw        $v0, 0x20($sp)
/* DB32B4 80240FF4 E7A00010 */  swc1      $f0, 0x10($sp)
/* DB32B8 80240FF8 E7A20014 */  swc1      $f2, 0x14($sp)
/* DB32BC 80240FFC 0C01BFA4 */  jal       fx_emote
/* DB32C0 80241000 E7A40018 */   swc1     $f4, 0x18($sp)
/* DB32C4 80241004 0200202D */  daddu     $a0, $s0, $zero
/* DB32C8 80241008 240502F4 */  addiu     $a1, $zero, 0x2f4
/* DB32CC 8024100C C480003C */  lwc1      $f0, 0x3c($a0)
/* DB32D0 80241010 3C060020 */  lui       $a2, 0x20
/* DB32D4 80241014 0C012530 */  jal       ai_enemy_play_sound
/* DB32D8 80241018 E4800064 */   swc1     $f0, 0x64($a0)
/* DB32DC 8024101C 8E220018 */  lw        $v0, 0x18($s1)
/* DB32E0 80241020 9442002A */  lhu       $v0, 0x2a($v0)
/* DB32E4 80241024 30420001 */  andi      $v0, $v0, 1
/* DB32E8 80241028 10400003 */  beqz      $v0, .L80241038
/* DB32EC 8024102C 2402000A */   addiu    $v0, $zero, 0xa
/* DB32F0 80241030 0809047E */  j         .L802411F8
/* DB32F4 80241034 AE620070 */   sw       $v0, 0x70($s3)
.L80241038:
/* DB32F8 80241038 0809047E */  j         .L802411F8
/* DB32FC 8024103C AE720070 */   sw       $s2, 0x70($s3)
.L80241040:
/* DB3300 80241040 8E620074 */  lw        $v0, 0x74($s3)
/* DB3304 80241044 2442FFFF */  addiu     $v0, $v0, -1
.L80241048:
/* DB3308 80241048 08090415 */  j         .L80241054
/* DB330C 8024104C AE620074 */   sw       $v0, 0x74($s3)
.L80241050:
/* DB3310 80241050 AE220090 */  sw        $v0, 0x90($s1)
.L80241054:
/* DB3314 80241054 8E2300D0 */  lw        $v1, 0xd0($s1)
/* DB3318 80241058 C6000040 */  lwc1      $f0, 0x40($s0)
/* DB331C 8024105C C4620000 */  lwc1      $f2, ($v1)
/* DB3320 80241060 468010A0 */  cvt.s.w   $f2, $f2
/* DB3324 80241064 C4640008 */  lwc1      $f4, 8($v1)
/* DB3328 80241068 46802120 */  cvt.s.w   $f4, $f4
/* DB332C 8024106C E7A00010 */  swc1      $f0, 0x10($sp)
/* DB3330 80241070 8E2200D0 */  lw        $v0, 0xd0($s1)
/* DB3334 80241074 44051000 */  mfc1      $a1, $f2
/* DB3338 80241078 C440000C */  lwc1      $f0, 0xc($v0)
/* DB333C 8024107C 46800020 */  cvt.s.w   $f0, $f0
/* DB3340 80241080 E7A00014 */  swc1      $f0, 0x14($sp)
/* DB3344 80241084 8E2200D0 */  lw        $v0, 0xd0($s1)
/* DB3348 80241088 44062000 */  mfc1      $a2, $f4
/* DB334C 8024108C C4400010 */  lwc1      $f0, 0x10($v0)
/* DB3350 80241090 46800020 */  cvt.s.w   $f0, $f0
/* DB3354 80241094 E7A00018 */  swc1      $f0, 0x18($sp)
/* DB3358 80241098 8C640018 */  lw        $a0, 0x18($v1)
/* DB335C 8024109C 0C0123F5 */  jal       is_point_within_region
/* DB3360 802410A0 8E070038 */   lw       $a3, 0x38($s0)
/* DB3364 802410A4 1040001A */  beqz      $v0, .L80241110
/* DB3368 802410A8 00000000 */   nop
/* DB336C 802410AC 8E060038 */  lw        $a2, 0x38($s0)
/* DB3370 802410B0 8E2200D0 */  lw        $v0, 0xd0($s1)
/* DB3374 802410B4 8E070040 */  lw        $a3, 0x40($s0)
/* DB3378 802410B8 C44C0000 */  lwc1      $f12, ($v0)
/* DB337C 802410BC 46806320 */  cvt.s.w   $f12, $f12
/* DB3380 802410C0 C44E0008 */  lwc1      $f14, 8($v0)
/* DB3384 802410C4 0C00A7B5 */  jal       dist2D
/* DB3388 802410C8 468073A0 */   cvt.s.w  $f14, $f14
/* DB338C 802410CC C6020018 */  lwc1      $f2, 0x18($s0)
/* DB3390 802410D0 4600103C */  c.lt.s    $f2, $f0
/* DB3394 802410D4 00000000 */  nop
/* DB3398 802410D8 4500000D */  bc1f      .L80241110
/* DB339C 802410DC E7A00034 */   swc1     $f0, 0x34($sp)
/* DB33A0 802410E0 C60C0038 */  lwc1      $f12, 0x38($s0)
/* DB33A4 802410E4 8E2200D0 */  lw        $v0, 0xd0($s1)
/* DB33A8 802410E8 C60E0040 */  lwc1      $f14, 0x40($s0)
/* DB33AC 802410EC C4480000 */  lwc1      $f8, ($v0)
/* DB33B0 802410F0 46804220 */  cvt.s.w   $f8, $f8
/* DB33B4 802410F4 44064000 */  mfc1      $a2, $f8
/* DB33B8 802410F8 C4480008 */  lwc1      $f8, 8($v0)
/* DB33BC 802410FC 46804220 */  cvt.s.w   $f8, $f8
/* DB33C0 80241100 44074000 */  mfc1      $a3, $f8
/* DB33C4 80241104 0C00A720 */  jal       atan2
/* DB33C8 80241108 24140001 */   addiu    $s4, $zero, 1
/* DB33CC 8024110C E600000C */  swc1      $f0, 0xc($s0)
.L80241110:
/* DB33D0 80241110 8E2200D0 */  lw        $v0, 0xd0($s1)
/* DB33D4 80241114 8C43000C */  lw        $v1, 0xc($v0)
/* DB33D8 80241118 8C420010 */  lw        $v0, 0x10($v0)
/* DB33DC 8024111C 00621825 */  or        $v1, $v1, $v0
/* DB33E0 80241120 00741825 */  or        $v1, $v1, $s4
/* DB33E4 80241124 10600008 */  beqz      $v1, .L80241148
/* DB33E8 80241128 00000000 */   nop
/* DB33EC 8024112C 8602008C */  lh        $v0, 0x8c($s0)
/* DB33F0 80241130 14400031 */  bnez      $v0, .L802411F8
/* DB33F4 80241134 00000000 */   nop
/* DB33F8 80241138 8E050018 */  lw        $a1, 0x18($s0)
/* DB33FC 8024113C 8E06000C */  lw        $a2, 0xc($s0)
/* DB3400 80241140 0C00EA95 */  jal       npc_move_heading
/* DB3404 80241144 0200202D */   daddu    $a0, $s0, $zero
.L80241148:
/* DB3408 80241148 C600003C */  lwc1      $f0, 0x3c($s0)
/* DB340C 8024114C 3C014059 */  lui       $at, 0x4059
/* DB3410 80241150 44811800 */  mtc1      $at, $f3
/* DB3414 80241154 44801000 */  mtc1      $zero, $f2
/* DB3418 80241158 46000021 */  cvt.d.s   $f0, $f0
/* DB341C 8024115C 46220002 */  mul.d     $f0, $f0, $f2
/* DB3420 80241160 00000000 */  nop
/* DB3424 80241164 4620020D */  trunc.w.d $f8, $f0
/* DB3428 80241168 E628007C */  swc1      $f8, 0x7c($s1)
/* DB342C 8024116C 8E420004 */  lw        $v0, 4($s2)
/* DB3430 80241170 18400021 */  blez      $v0, .L802411F8
/* DB3434 80241174 00000000 */   nop
/* DB3438 80241178 8602008E */  lh        $v0, 0x8e($s0)
/* DB343C 8024117C 9603008E */  lhu       $v1, 0x8e($s0)
/* DB3440 80241180 18400005 */  blez      $v0, .L80241198
/* DB3444 80241184 2462FFFF */   addiu    $v0, $v1, -1
/* DB3448 80241188 A602008E */  sh        $v0, 0x8e($s0)
/* DB344C 8024118C 00021400 */  sll       $v0, $v0, 0x10
/* DB3450 80241190 1C400019 */  bgtz      $v0, .L802411F8
/* DB3454 80241194 00000000 */   nop
.L80241198:
/* DB3458 80241198 240403E8 */  addiu     $a0, $zero, 0x3e8
/* DB345C 8024119C 24020002 */  addiu     $v0, $zero, 2
/* DB3460 802411A0 0C00A67F */  jal       rand_int
/* DB3464 802411A4 AE620070 */   sw       $v0, 0x70($s3)
/* DB3468 802411A8 3C035555 */  lui       $v1, 0x5555
/* DB346C 802411AC 34635556 */  ori       $v1, $v1, 0x5556
/* DB3470 802411B0 00430018 */  mult      $v0, $v1
/* DB3474 802411B4 000227C3 */  sra       $a0, $v0, 0x1f
/* DB3478 802411B8 00004010 */  mfhi      $t0
/* DB347C 802411BC 01042023 */  subu      $a0, $t0, $a0
/* DB3480 802411C0 00041840 */  sll       $v1, $a0, 1
/* DB3484 802411C4 00641821 */  addu      $v1, $v1, $a0
/* DB3488 802411C8 00431023 */  subu      $v0, $v0, $v1
/* DB348C 802411CC 24430002 */  addiu     $v1, $v0, 2
/* DB3490 802411D0 AE630074 */  sw        $v1, 0x74($s3)
/* DB3494 802411D4 8E42002C */  lw        $v0, 0x2c($s2)
/* DB3498 802411D8 58400007 */  blezl     $v0, .L802411F8
/* DB349C 802411DC AE600070 */   sw       $zero, 0x70($s3)
/* DB34A0 802411E0 8E420008 */  lw        $v0, 8($s2)
/* DB34A4 802411E4 18400003 */  blez      $v0, .L802411F4
/* DB34A8 802411E8 28620003 */   slti     $v0, $v1, 3
/* DB34AC 802411EC 10400002 */  beqz      $v0, .L802411F8
/* DB34B0 802411F0 00000000 */   nop
.L802411F4:
/* DB34B4 802411F4 AE600070 */  sw        $zero, 0x70($s3)
.L802411F8:
/* DB34B8 802411F8 8FBF0058 */  lw        $ra, 0x58($sp)
/* DB34BC 802411FC 8FB50054 */  lw        $s5, 0x54($sp)
/* DB34C0 80241200 8FB40050 */  lw        $s4, 0x50($sp)
/* DB34C4 80241204 8FB3004C */  lw        $s3, 0x4c($sp)
/* DB34C8 80241208 8FB20048 */  lw        $s2, 0x48($sp)
/* DB34CC 8024120C 8FB10044 */  lw        $s1, 0x44($sp)
/* DB34D0 80241210 8FB00040 */  lw        $s0, 0x40($sp)
/* DB34D4 80241214 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* DB34D8 80241218 D7B80070 */  ldc1      $f24, 0x70($sp)
/* DB34DC 8024121C D7B60068 */  ldc1      $f22, 0x68($sp)
/* DB34E0 80241220 D7B40060 */  ldc1      $f20, 0x60($sp)
/* DB34E4 80241224 03E00008 */  jr        $ra
/* DB34E8 80241228 27BD0080 */   addiu    $sp, $sp, 0x80
