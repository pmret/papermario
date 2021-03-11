.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_8014F940
.double 0.95

glabel D_8014F948
.double 250.0

.section .text

glabel func_80112344
/* A8A44 80112344 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* A8A48 80112348 AFB10034 */  sw        $s1, 0x34($sp)
/* A8A4C 8011234C 0080882D */  daddu     $s1, $a0, $zero
/* A8A50 80112350 AFBF0038 */  sw        $ra, 0x38($sp)
/* A8A54 80112354 AFB00030 */  sw        $s0, 0x30($sp)
/* A8A58 80112358 0C044181 */  jal       get_shadow_by_index
/* A8A5C 8011235C 86240016 */   lh       $a0, 0x16($s1)
/* A8A60 80112360 0040802D */  daddu     $s0, $v0, $zero
/* A8A64 80112364 5200009B */  beql      $s0, $zero, .L801125D4
/* A8A68 80112368 AE20006C */   sw       $zero, 0x6c($s1)
/* A8A6C 8011236C 9222000B */  lbu       $v0, 0xb($s1)
/* A8A70 80112370 2C4200FF */  sltiu     $v0, $v0, 0xff
/* A8A74 80112374 10400005 */  beqz      $v0, .L8011238C
/* A8A78 80112378 3C030080 */   lui      $v1, 0x80
/* A8A7C 8011237C 9222000B */  lbu       $v0, 0xb($s1)
/* A8A80 80112380 00021042 */  srl       $v0, $v0, 1
/* A8A84 80112384 080448E9 */  j         .L801123A4
/* A8A88 80112388 A2020005 */   sb       $v0, 5($s0)
.L8011238C:
/* A8A8C 8011238C 8E020000 */  lw        $v0, ($s0)
/* A8A90 80112390 00431024 */  and       $v0, $v0, $v1
/* A8A94 80112394 10400002 */  beqz      $v0, .L801123A0
/* A8A98 80112398 24040080 */   addiu    $a0, $zero, 0x80
/* A8A9C 8011239C 240400A0 */  addiu     $a0, $zero, 0xa0
.L801123A0:
/* A8AA0 801123A0 A2040005 */  sb        $a0, 5($s0)
.L801123A4:
/* A8AA4 801123A4 8E220000 */  lw        $v0, ($s1)
/* A8AA8 801123A8 30420004 */  andi      $v0, $v0, 4
/* A8AAC 801123AC 1440000A */  bnez      $v0, .L801123D8
/* A8AB0 801123B0 27A40018 */   addiu    $a0, $sp, 0x18
/* A8AB4 801123B4 8E030000 */  lw        $v1, ($s0)
/* A8AB8 801123B8 3C020040 */  lui       $v0, 0x40
/* A8ABC 801123BC 00621024 */  and       $v0, $v1, $v0
/* A8AC0 801123C0 10400084 */  beqz      $v0, .L801125D4
/* A8AC4 801123C4 3C02FFBF */   lui      $v0, 0xffbf
/* A8AC8 801123C8 3442FFFF */  ori       $v0, $v0, 0xffff
/* A8ACC 801123CC 00621024 */  and       $v0, $v1, $v0
/* A8AD0 801123D0 AE020000 */  sw        $v0, ($s0)
/* A8AD4 801123D4 27A40018 */  addiu     $a0, $sp, 0x18
.L801123D8:
/* A8AD8 801123D8 27A20028 */  addiu     $v0, $sp, 0x28
/* A8ADC 801123DC 27A5001C */  addiu     $a1, $sp, 0x1c
/* A8AE0 801123E0 27A60020 */  addiu     $a2, $sp, 0x20
/* A8AE4 801123E4 C6200048 */  lwc1      $f0, 0x48($s1)
/* A8AE8 801123E8 C622004C */  lwc1      $f2, 0x4c($s1)
/* A8AEC 801123EC C6240050 */  lwc1      $f4, 0x50($s1)
/* A8AF0 801123F0 27A70024 */  addiu     $a3, $sp, 0x24
/* A8AF4 801123F4 E7A00018 */  swc1      $f0, 0x18($sp)
/* A8AF8 801123F8 E7A2001C */  swc1      $f2, 0x1c($sp)
/* A8AFC 801123FC E7A40020 */  swc1      $f4, 0x20($sp)
/* A8B00 80112400 AFA20010 */  sw        $v0, 0x10($sp)
/* A8B04 80112404 27A2002C */  addiu     $v0, $sp, 0x2c
/* A8B08 80112408 0C04497A */  jal       func_801125E8
/* A8B0C 8011240C AFA20014 */   sw       $v0, 0x14($sp)
/* A8B10 80112410 1440000A */  bnez      $v0, .L8011243C
/* A8B14 80112414 00000000 */   nop
/* A8B18 80112418 C7A2002C */  lwc1      $f2, 0x2c($sp)
/* A8B1C 8011241C 3C0146FF */  lui       $at, 0x46ff
/* A8B20 80112420 3421FE00 */  ori       $at, $at, 0xfe00
/* A8B24 80112424 44810000 */  mtc1      $at, $f0
/* A8B28 80112428 00000000 */  nop
/* A8B2C 8011242C 46001032 */  c.eq.s    $f2, $f0
/* A8B30 80112430 00000000 */  nop
/* A8B34 80112434 45030001 */  bc1tl     .L8011243C
/* A8B38 80112438 AFA0002C */   sw       $zero, 0x2c($sp)
.L8011243C:
/* A8B3C 8011243C 8E020000 */  lw        $v0, ($s0)
/* A8B40 80112440 C7A8002C */  lwc1      $f8, 0x2c($sp)
/* A8B44 80112444 30420200 */  andi      $v0, $v0, 0x200
/* A8B48 80112448 10400012 */  beqz      $v0, .L80112494
/* A8B4C 8011244C 00000000 */   nop
/* A8B50 80112450 8622000C */  lh        $v0, 0xc($s1)
/* A8B54 80112454 3C014354 */  lui       $at, 0x4354
/* A8B58 80112458 34218000 */  ori       $at, $at, 0x8000
/* A8B5C 8011245C 44811000 */  mtc1      $at, $f2
/* A8B60 80112460 44820000 */  mtc1      $v0, $f0
/* A8B64 80112464 00000000 */  nop
/* A8B68 80112468 46800020 */  cvt.s.w   $f0, $f0
/* A8B6C 8011246C 46020003 */  div.s     $f0, $f0, $f2
/* A8B70 80112470 E600001C */  swc1      $f0, 0x1c($s0)
/* A8B74 80112474 86220010 */  lh        $v0, 0x10($s1)
/* A8B78 80112478 E7A2002C */  swc1      $f2, 0x2c($sp)
/* A8B7C 8011247C 44820000 */  mtc1      $v0, $f0
/* A8B80 80112480 00000000 */  nop
/* A8B84 80112484 46800020 */  cvt.s.w   $f0, $f0
/* A8B88 80112488 46020003 */  div.s     $f0, $f0, $f2
/* A8B8C 8011248C 08044944 */  j         .L80112510
/* A8B90 80112490 E6000024 */   swc1     $f0, 0x24($s0)
.L80112494:
/* A8B94 80112494 3C014316 */  lui       $at, 0x4316
/* A8B98 80112498 44810000 */  mtc1      $at, $f0
/* A8B9C 8011249C 3C018015 */  lui       $at, %hi(D_8014F940)
/* A8BA0 801124A0 D422F940 */  ldc1      $f2, %lo(D_8014F940)($at)
/* A8BA4 801124A4 46004003 */  div.s     $f0, $f8, $f0
/* A8BA8 801124A8 46000021 */  cvt.d.s   $f0, $f0
/* A8BAC 801124AC 46220000 */  add.d     $f0, $f0, $f2
/* A8BB0 801124B0 3C018015 */  lui       $at, %hi(D_8014F948)
/* A8BB4 801124B4 D422F948 */  ldc1      $f2, %lo(D_8014F948)($at)
/* A8BB8 801124B8 46220002 */  mul.d     $f0, $f0, $f2
/* A8BBC 801124BC 00000000 */  nop
/* A8BC0 801124C0 8622000C */  lh        $v0, 0xc($s1)
/* A8BC4 801124C4 C6240054 */  lwc1      $f4, 0x54($s1)
/* A8BC8 801124C8 44821000 */  mtc1      $v0, $f2
/* A8BCC 801124CC 00000000 */  nop
/* A8BD0 801124D0 468010A0 */  cvt.s.w   $f2, $f2
/* A8BD4 801124D4 46200020 */  cvt.s.d   $f0, $f0
/* A8BD8 801124D8 46001083 */  div.s     $f2, $f2, $f0
/* A8BDC 801124DC 46041082 */  mul.s     $f2, $f2, $f4
/* A8BE0 801124E0 00000000 */  nop
/* A8BE4 801124E4 E602001C */  swc1      $f2, 0x1c($s0)
/* A8BE8 801124E8 86220010 */  lh        $v0, 0x10($s1)
/* A8BEC 801124EC C624005C */  lwc1      $f4, 0x5c($s1)
/* A8BF0 801124F0 44821000 */  mtc1      $v0, $f2
/* A8BF4 801124F4 00000000 */  nop
/* A8BF8 801124F8 468010A0 */  cvt.s.w   $f2, $f2
/* A8BFC 801124FC 46001083 */  div.s     $f2, $f2, $f0
/* A8C00 80112500 46041082 */  mul.s     $f2, $f2, $f4
/* A8C04 80112504 00000000 */  nop
/* A8C08 80112508 E7A0002C */  swc1      $f0, 0x2c($sp)
/* A8C0C 8011250C E6020024 */  swc1      $f2, 0x24($s0)
.L80112510:
/* A8C10 80112510 C6200048 */  lwc1      $f0, 0x48($s1)
/* A8C14 80112514 E6000010 */  swc1      $f0, 0x10($s0)
/* A8C18 80112518 C7A6001C */  lwc1      $f6, 0x1c($sp)
/* A8C1C 8011251C C6200050 */  lwc1      $f0, 0x50($s1)
/* A8C20 80112520 C7A20024 */  lwc1      $f2, 0x24($sp)
/* A8C24 80112524 C7A40028 */  lwc1      $f4, 0x28($sp)
/* A8C28 80112528 E6060014 */  swc1      $f6, 0x14($s0)
/* A8C2C 8011252C E6000018 */  swc1      $f0, 0x18($s0)
/* A8C30 80112530 E626006C */  swc1      $f6, 0x6c($s1)
/* A8C34 80112534 E6020028 */  swc1      $f2, 0x28($s0)
/* A8C38 80112538 E6040030 */  swc1      $f4, 0x30($s0)
/* A8C3C 8011253C C6200064 */  lwc1      $f0, 0x64($s1)
/* A8C40 80112540 E600002C */  swc1      $f0, 0x2c($s0)
/* A8C44 80112544 C620004C */  lwc1      $f0, 0x4c($s1)
/* A8C48 80112548 4606003C */  c.lt.s    $f0, $f6
/* A8C4C 8011254C 00000000 */  nop
/* A8C50 80112550 45000009 */  bc1f      .L80112578
/* A8C54 80112554 3C034000 */   lui      $v1, 0x4000
/* A8C58 80112558 3C014120 */  lui       $at, 0x4120
/* A8C5C 8011255C 44810000 */  mtc1      $at, $f0
/* A8C60 80112560 8E020000 */  lw        $v0, ($s0)
/* A8C64 80112564 46003000 */  add.s     $f0, $f6, $f0
/* A8C68 80112568 00431025 */  or        $v0, $v0, $v1
/* A8C6C 8011256C AE020000 */  sw        $v0, ($s0)
/* A8C70 80112570 08044963 */  j         .L8011258C
/* A8C74 80112574 E620004C */   swc1     $f0, 0x4c($s1)
.L80112578:
/* A8C78 80112578 3C03BFFF */  lui       $v1, 0xbfff
/* A8C7C 8011257C 8E020000 */  lw        $v0, ($s0)
/* A8C80 80112580 3463FFFF */  ori       $v1, $v1, 0xffff
/* A8C84 80112584 00431024 */  and       $v0, $v0, $v1
/* A8C88 80112588 AE020000 */  sw        $v0, ($s0)
.L8011258C:
/* A8C8C 8011258C 2404FFFE */  addiu     $a0, $zero, -2
/* A8C90 80112590 8E030000 */  lw        $v1, ($s0)
/* A8C94 80112594 96220002 */  lhu       $v0, 2($s1)
/* A8C98 80112598 00641824 */  and       $v1, $v1, $a0
/* A8C9C 8011259C 30420001 */  andi      $v0, $v0, 1
/* A8CA0 801125A0 00621825 */  or        $v1, $v1, $v0
/* A8CA4 801125A4 AE030000 */  sw        $v1, ($s0)
/* A8CA8 801125A8 8E220000 */  lw        $v0, ($s1)
/* A8CAC 801125AC 30420400 */  andi      $v0, $v0, 0x400
/* A8CB0 801125B0 14400008 */  bnez      $v0, .L801125D4
/* A8CB4 801125B4 00000000 */   nop
/* A8CB8 801125B8 44800000 */  mtc1      $zero, $f0
/* A8CBC 801125BC 00000000 */  nop
/* A8CC0 801125C0 46004032 */  c.eq.s    $f8, $f0
/* A8CC4 801125C4 00000000 */  nop
/* A8CC8 801125C8 45000002 */  bc1f      .L801125D4
/* A8CCC 801125CC 34620001 */   ori      $v0, $v1, 1
/* A8CD0 801125D0 AE020000 */  sw        $v0, ($s0)
.L801125D4:
/* A8CD4 801125D4 8FBF0038 */  lw        $ra, 0x38($sp)
/* A8CD8 801125D8 8FB10034 */  lw        $s1, 0x34($sp)
/* A8CDC 801125DC 8FB00030 */  lw        $s0, 0x30($sp)
/* A8CE0 801125E0 03E00008 */  jr        $ra
/* A8CE4 801125E4 27BD0040 */   addiu    $sp, $sp, 0x40
