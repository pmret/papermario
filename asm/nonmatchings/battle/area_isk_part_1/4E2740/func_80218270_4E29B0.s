.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218270_4E29B0
/* 4E29B0 80218270 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 4E29B4 80218274 AFB40020 */  sw        $s4, 0x20($sp)
/* 4E29B8 80218278 24140003 */  addiu     $s4, $zero, 3
/* 4E29BC 8021827C AFB20018 */  sw        $s2, 0x18($sp)
/* 4E29C0 80218280 AFBF0024 */  sw        $ra, 0x24($sp)
/* 4E29C4 80218284 AFB3001C */  sw        $s3, 0x1c($sp)
/* 4E29C8 80218288 AFB10014 */  sw        $s1, 0x14($sp)
/* 4E29CC 8021828C AFB00010 */  sw        $s0, 0x10($sp)
/* 4E29D0 80218290 F7BE0050 */  sdc1      $f30, 0x50($sp)
/* 4E29D4 80218294 F7BC0048 */  sdc1      $f28, 0x48($sp)
/* 4E29D8 80218298 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* 4E29DC 8021829C F7B80038 */  sdc1      $f24, 0x38($sp)
/* 4E29E0 802182A0 F7B60030 */  sdc1      $f22, 0x30($sp)
/* 4E29E4 802182A4 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 4E29E8 802182A8 8C840148 */  lw        $a0, 0x148($a0)
/* 4E29EC 802182AC 3C0140E0 */  lui       $at, 0x40e0
/* 4E29F0 802182B0 4481A000 */  mtc1      $at, $f20
/* 4E29F4 802182B4 3C013F19 */  lui       $at, 0x3f19
/* 4E29F8 802182B8 3421999A */  ori       $at, $at, 0x999a
/* 4E29FC 802182BC 4481F000 */  mtc1      $at, $f30
/* 4E2A00 802182C0 3C014040 */  lui       $at, 0x4040
/* 4E2A04 802182C4 4481E000 */  mtc1      $at, $f28
/* 4E2A08 802182C8 0C09A75B */  jal       get_actor
/* 4E2A0C 802182CC 0000902D */   daddu    $s2, $zero, $zero
/* 4E2A10 802182D0 24040180 */  addiu     $a0, $zero, 0x180
/* 4E2A14 802182D4 0C00AB39 */  jal       heap_malloc
/* 4E2A18 802182D8 0040982D */   daddu    $s3, $v0, $zero
/* 4E2A1C 802182DC 0040882D */  daddu     $s1, $v0, $zero
/* 4E2A20 802182E0 26300008 */  addiu     $s0, $s1, 8
/* 4E2A24 802182E4 C67A014C */  lwc1      $f26, 0x14c($s3)
/* 4E2A28 802182E8 C6620144 */  lwc1      $f2, 0x144($s3)
/* 4E2A2C 802182EC 3C014028 */  lui       $at, 0x4028
/* 4E2A30 802182F0 44810800 */  mtc1      $at, $f1
/* 4E2A34 802182F4 44800000 */  mtc1      $zero, $f0
/* 4E2A38 802182F8 460010A1 */  cvt.d.s   $f2, $f2
/* 4E2A3C 802182FC 46201080 */  add.d     $f2, $f2, $f0
/* 4E2A40 80218300 C6600148 */  lwc1      $f0, 0x148($s3)
/* 4E2A44 80218304 3C014014 */  lui       $at, 0x4014
/* 4E2A48 80218308 44812800 */  mtc1      $at, $f5
/* 4E2A4C 8021830C 44802000 */  mtc1      $zero, $f4
/* 4E2A50 80218310 46000021 */  cvt.d.s   $f0, $f0
/* 4E2A54 80218314 46240000 */  add.d     $f0, $f0, $f4
/* 4E2A58 80218318 AE710078 */  sw        $s1, 0x78($s3)
/* 4E2A5C 8021831C 46201620 */  cvt.s.d   $f24, $f2
/* 4E2A60 80218320 462005A0 */  cvt.s.d   $f22, $f0
.L80218324:
/* 4E2A64 80218324 0260202D */  daddu     $a0, $s3, $zero
/* 4E2A68 80218328 02922821 */  addu      $a1, $s4, $s2
/* 4E2A6C 8021832C E614001C */  swc1      $f20, 0x1c($s0)
/* 4E2A70 80218330 E6140024 */  swc1      $f20, 0x24($s0)
/* 4E2A74 80218334 E6140020 */  swc1      $f20, 0x20($s0)
/* 4E2A78 80218338 E6380000 */  swc1      $f24, ($s1)
/* 4E2A7C 8021833C E616FFFC */  swc1      $f22, -4($s0)
/* 4E2A80 80218340 E61A0000 */  swc1      $f26, ($s0)
/* 4E2A84 80218344 AE000014 */  sw        $zero, 0x14($s0)
/* 4E2A88 80218348 E61E0018 */  swc1      $f30, 0x18($s0)
/* 4E2A8C 8021834C E61C000C */  swc1      $f28, 0xc($s0)
/* 4E2A90 80218350 0C099117 */  jal       get_actor_part
/* 4E2A94 80218354 AE000010 */   sw       $zero, 0x10($s0)
/* 4E2A98 80218358 C6200000 */  lwc1      $f0, ($s1)
/* 4E2A9C 8021835C 26520001 */  addiu     $s2, $s2, 1
/* 4E2AA0 80218360 E440002C */  swc1      $f0, 0x2c($v0)
/* 4E2AA4 80218364 C600FFFC */  lwc1      $f0, -4($s0)
/* 4E2AA8 80218368 26310030 */  addiu     $s1, $s1, 0x30
/* 4E2AAC 8021836C E4400030 */  swc1      $f0, 0x30($v0)
/* 4E2AB0 80218370 C6000000 */  lwc1      $f0, ($s0)
/* 4E2AB4 80218374 E4400034 */  swc1      $f0, 0x34($v0)
/* 4E2AB8 80218378 2A420008 */  slti      $v0, $s2, 8
/* 4E2ABC 8021837C 1440FFE9 */  bnez      $v0, .L80218324
/* 4E2AC0 80218380 26100030 */   addiu    $s0, $s0, 0x30
/* 4E2AC4 80218384 8FBF0024 */  lw        $ra, 0x24($sp)
/* 4E2AC8 80218388 8FB40020 */  lw        $s4, 0x20($sp)
/* 4E2ACC 8021838C 8FB3001C */  lw        $s3, 0x1c($sp)
/* 4E2AD0 80218390 8FB20018 */  lw        $s2, 0x18($sp)
/* 4E2AD4 80218394 8FB10014 */  lw        $s1, 0x14($sp)
/* 4E2AD8 80218398 8FB00010 */  lw        $s0, 0x10($sp)
/* 4E2ADC 8021839C D7BE0050 */  ldc1      $f30, 0x50($sp)
/* 4E2AE0 802183A0 D7BC0048 */  ldc1      $f28, 0x48($sp)
/* 4E2AE4 802183A4 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* 4E2AE8 802183A8 D7B80038 */  ldc1      $f24, 0x38($sp)
/* 4E2AEC 802183AC D7B60030 */  ldc1      $f22, 0x30($sp)
/* 4E2AF0 802183B0 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 4E2AF4 802183B4 24020002 */  addiu     $v0, $zero, 2
/* 4E2AF8 802183B8 03E00008 */  jr        $ra
/* 4E2AFC 802183BC 27BD0058 */   addiu    $sp, $sp, 0x58
