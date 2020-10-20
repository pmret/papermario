.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D30_DE31C0
/* DE31C0 80240D30 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* DE31C4 80240D34 AFB10014 */  sw        $s1, 0x14($sp)
/* DE31C8 80240D38 0080882D */  daddu     $s1, $a0, $zero
/* DE31CC 80240D3C AFBF0024 */  sw        $ra, 0x24($sp)
/* DE31D0 80240D40 AFB40020 */  sw        $s4, 0x20($sp)
/* DE31D4 80240D44 AFB3001C */  sw        $s3, 0x1c($sp)
/* DE31D8 80240D48 AFB20018 */  sw        $s2, 0x18($sp)
/* DE31DC 80240D4C AFB00010 */  sw        $s0, 0x10($sp)
/* DE31E0 80240D50 F7BC0048 */  sdc1      $f28, 0x48($sp)
/* DE31E4 80240D54 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* DE31E8 80240D58 F7B80038 */  sdc1      $f24, 0x38($sp)
/* DE31EC 80240D5C F7B60030 */  sdc1      $f22, 0x30($sp)
/* DE31F0 80240D60 F7B40028 */  sdc1      $f20, 0x28($sp)
/* DE31F4 80240D64 8E30000C */  lw        $s0, 0xc($s1)
/* DE31F8 80240D68 8E130000 */  lw        $s3, ($s0)
/* DE31FC 80240D6C 26100004 */  addiu     $s0, $s0, 4
/* DE3200 80240D70 0C0B1EAF */  jal       get_variable
/* DE3204 80240D74 0260282D */   daddu    $a1, $s3, $zero
/* DE3208 80240D78 4482E000 */  mtc1      $v0, $f28
/* DE320C 80240D7C 00000000 */  nop       
/* DE3210 80240D80 4680E720 */  cvt.s.w   $f28, $f28
/* DE3214 80240D84 8E140000 */  lw        $s4, ($s0)
/* DE3218 80240D88 26100004 */  addiu     $s0, $s0, 4
/* DE321C 80240D8C 0220202D */  daddu     $a0, $s1, $zero
/* DE3220 80240D90 0C0B1EAF */  jal       get_variable
/* DE3224 80240D94 0280282D */   daddu    $a1, $s4, $zero
/* DE3228 80240D98 4482D000 */  mtc1      $v0, $f26
/* DE322C 80240D9C 00000000 */  nop       
/* DE3230 80240DA0 4680D6A0 */  cvt.s.w   $f26, $f26
/* DE3234 80240DA4 8E100000 */  lw        $s0, ($s0)
/* DE3238 80240DA8 0220202D */  daddu     $a0, $s1, $zero
/* DE323C 80240DAC 0C0B1EAF */  jal       get_variable
/* DE3240 80240DB0 0200282D */   daddu    $a1, $s0, $zero
/* DE3244 80240DB4 4482C000 */  mtc1      $v0, $f24
/* DE3248 80240DB8 00000000 */  nop       
/* DE324C 80240DBC 4680C620 */  cvt.s.w   $f24, $f24
/* DE3250 80240DC0 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* DE3254 80240DC4 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* DE3258 80240DC8 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* DE325C 80240DCC 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* DE3260 80240DD0 C64200A8 */  lwc1      $f2, 0xa8($s2)
/* DE3264 80240DD4 44800000 */  mtc1      $zero, $f0
/* DE3268 80240DD8 00031080 */  sll       $v0, $v1, 2
/* DE326C 80240DDC 00431021 */  addu      $v0, $v0, $v1
/* DE3270 80240DE0 00021080 */  sll       $v0, $v0, 2
/* DE3274 80240DE4 00431023 */  subu      $v0, $v0, $v1
/* DE3278 80240DE8 000218C0 */  sll       $v1, $v0, 3
/* DE327C 80240DEC 00431021 */  addu      $v0, $v0, $v1
/* DE3280 80240DF0 000210C0 */  sll       $v0, $v0, 3
/* DE3284 80240DF4 46001032 */  c.eq.s    $f2, $f0
/* DE3288 80240DF8 3C01800B */  lui       $at, 0x800b
/* DE328C 80240DFC 00220821 */  addu      $at, $at, $v0
/* DE3290 80240E00 C4361DEC */  lwc1      $f22, 0x1dec($at)
/* DE3294 80240E04 45000005 */  bc1f      .L80240E1C
/* DE3298 80240E08 00000000 */   nop      
/* DE329C 80240E0C 3C0142C8 */  lui       $at, 0x42c8
/* DE32A0 80240E10 44810000 */  mtc1      $at, $f0
/* DE32A4 80240E14 0809038B */  j         .L80240E2C
/* DE32A8 80240E18 4600B581 */   sub.s    $f22, $f22, $f0
.L80240E1C:
/* DE32AC 80240E1C 3C0142C8 */  lui       $at, 0x42c8
/* DE32B0 80240E20 44810000 */  mtc1      $at, $f0
/* DE32B4 80240E24 00000000 */  nop       
/* DE32B8 80240E28 4600B580 */  add.s     $f22, $f22, $f0
.L80240E2C:
/* DE32BC 80240E2C 0C00A6C9 */  jal       clamp_angle
/* DE32C0 80240E30 4600B306 */   mov.s    $f12, $f22
/* DE32C4 80240E34 46000586 */  mov.s     $f22, $f0
/* DE32C8 80240E38 3C014170 */  lui       $at, 0x4170
/* DE32CC 80240E3C 4481A000 */  mtc1      $at, $f20
/* DE32D0 80240E40 0C00A8BB */  jal       sin_deg
/* DE32D4 80240E44 4600B306 */   mov.s    $f12, $f22
/* DE32D8 80240E48 46140002 */  mul.s     $f0, $f0, $f20
/* DE32DC 80240E4C 00000000 */  nop       
/* DE32E0 80240E50 864200B0 */  lh        $v0, 0xb0($s2)
/* DE32E4 80240E54 3C013F00 */  lui       $at, 0x3f00
/* DE32E8 80240E58 44812000 */  mtc1      $at, $f4
/* DE32EC 80240E5C 44821000 */  mtc1      $v0, $f2
/* DE32F0 80240E60 00000000 */  nop       
/* DE32F4 80240E64 468010A0 */  cvt.s.w   $f2, $f2
/* DE32F8 80240E68 46041082 */  mul.s     $f2, $f2, $f4
/* DE32FC 80240E6C 00000000 */  nop       
/* DE3300 80240E70 4600E700 */  add.s     $f28, $f28, $f0
/* DE3304 80240E74 4602D680 */  add.s     $f26, $f26, $f2
/* DE3308 80240E78 0C00A8D4 */  jal       cos_deg
/* DE330C 80240E7C 4600B306 */   mov.s    $f12, $f22
/* DE3310 80240E80 46140002 */  mul.s     $f0, $f0, $f20
/* DE3314 80240E84 00000000 */  nop       
/* DE3318 80240E88 0220202D */  daddu     $a0, $s1, $zero
/* DE331C 80240E8C 0260282D */  daddu     $a1, $s3, $zero
/* DE3320 80240E90 4600E18D */  trunc.w.s $f6, $f28
/* DE3324 80240E94 44063000 */  mfc1      $a2, $f6
/* DE3328 80240E98 0C0B2026 */  jal       set_variable
/* DE332C 80240E9C 4600C601 */   sub.s    $f24, $f24, $f0
/* DE3330 80240EA0 0220202D */  daddu     $a0, $s1, $zero
/* DE3334 80240EA4 4600D18D */  trunc.w.s $f6, $f26
/* DE3338 80240EA8 44063000 */  mfc1      $a2, $f6
/* DE333C 80240EAC 0C0B2026 */  jal       set_variable
/* DE3340 80240EB0 0280282D */   daddu    $a1, $s4, $zero
/* DE3344 80240EB4 0220202D */  daddu     $a0, $s1, $zero
/* DE3348 80240EB8 4600C18D */  trunc.w.s $f6, $f24
/* DE334C 80240EBC 44063000 */  mfc1      $a2, $f6
/* DE3350 80240EC0 0C0B2026 */  jal       set_variable
/* DE3354 80240EC4 0200282D */   daddu    $a1, $s0, $zero
/* DE3358 80240EC8 8FBF0024 */  lw        $ra, 0x24($sp)
/* DE335C 80240ECC 8FB40020 */  lw        $s4, 0x20($sp)
/* DE3360 80240ED0 8FB3001C */  lw        $s3, 0x1c($sp)
/* DE3364 80240ED4 8FB20018 */  lw        $s2, 0x18($sp)
/* DE3368 80240ED8 8FB10014 */  lw        $s1, 0x14($sp)
/* DE336C 80240EDC 8FB00010 */  lw        $s0, 0x10($sp)
/* DE3370 80240EE0 D7BC0048 */  ldc1      $f28, 0x48($sp)
/* DE3374 80240EE4 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* DE3378 80240EE8 D7B80038 */  ldc1      $f24, 0x38($sp)
/* DE337C 80240EEC D7B60030 */  ldc1      $f22, 0x30($sp)
/* DE3380 80240EF0 D7B40028 */  ldc1      $f20, 0x28($sp)
/* DE3384 80240EF4 24020002 */  addiu     $v0, $zero, 2
/* DE3388 80240EF8 03E00008 */  jr        $ra
/* DE338C 80240EFC 27BD0050 */   addiu    $sp, $sp, 0x50
