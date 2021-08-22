.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_100_main
/* 3CF3A0 E00C8000 27BDFF90 */  addiu     $sp, $sp, -0x70
/* 3CF3A4 E00C8004 F7B40040 */  sdc1      $f20, 0x40($sp)
/* 3CF3A8 E00C8008 4485A000 */  mtc1      $a1, $f20
/* 3CF3AC E00C800C F7B60048 */  sdc1      $f22, 0x48($sp)
/* 3CF3B0 E00C8010 4486B000 */  mtc1      $a2, $f22
/* 3CF3B4 E00C8014 F7B80050 */  sdc1      $f24, 0x50($sp)
/* 3CF3B8 E00C8018 4487C000 */  mtc1      $a3, $f24
/* 3CF3BC E00C801C F7BA0058 */  sdc1      $f26, 0x58($sp)
/* 3CF3C0 E00C8020 C7BA0080 */  lwc1      $f26, 0x80($sp)
/* 3CF3C4 E00C8024 F7BC0060 */  sdc1      $f28, 0x60($sp)
/* 3CF3C8 E00C8028 C7BC0084 */  lwc1      $f28, 0x84($sp)
/* 3CF3CC E00C802C AFB30034 */  sw        $s3, 0x34($sp)
/* 3CF3D0 E00C8030 0080982D */  daddu     $s3, $a0, $zero
/* 3CF3D4 E00C8034 F7BE0068 */  sdc1      $f30, 0x68($sp)
/* 3CF3D8 E00C8038 C7BE0088 */  lwc1      $f30, 0x88($sp)
/* 3CF3DC E00C803C 27A40010 */  addiu     $a0, $sp, 0x10
/* 3CF3E0 E00C8040 AFB1002C */  sw        $s1, 0x2c($sp)
/* 3CF3E4 E00C8044 8FB10090 */  lw        $s1, 0x90($sp)
/* 3CF3E8 E00C8048 3C02E00D */  lui       $v0, %hi(func_E00C8218)
/* 3CF3EC E00C804C 24428218 */  addiu     $v0, $v0, %lo(func_E00C8218)
/* 3CF3F0 E00C8050 AFA20018 */  sw        $v0, 0x18($sp)
/* 3CF3F4 E00C8054 3C02E00D */  lui       $v0, %hi(func_E00C8220)
/* 3CF3F8 E00C8058 24428220 */  addiu     $v0, $v0, %lo(func_E00C8220)
/* 3CF3FC E00C805C AFA2001C */  sw        $v0, 0x1c($sp)
/* 3CF400 E00C8060 3C02E00D */  lui       $v0, %hi(func_E00C8404)
/* 3CF404 E00C8064 24428404 */  addiu     $v0, $v0, %lo(func_E00C8404)
/* 3CF408 E00C8068 AFA20020 */  sw        $v0, 0x20($sp)
/* 3CF40C E00C806C 24020064 */  addiu     $v0, $zero, 0x64
/* 3CF410 E00C8070 AFBF0038 */  sw        $ra, 0x38($sp)
/* 3CF414 E00C8074 AFB20030 */  sw        $s2, 0x30($sp)
/* 3CF418 E00C8078 AFB00028 */  sw        $s0, 0x28($sp)
/* 3CF41C E00C807C AFA00010 */  sw        $zero, 0x10($sp)
/* 3CF420 E00C8080 AFA00024 */  sw        $zero, 0x24($sp)
/* 3CF424 E00C8084 0C080124 */  jal       func_E0200490
/* 3CF428 E00C8088 AFA20014 */   sw       $v0, 0x14($sp)
/* 3CF42C E00C808C 2404006C */  addiu     $a0, $zero, 0x6c
/* 3CF430 E00C8090 24030001 */  addiu     $v1, $zero, 1
/* 3CF434 E00C8094 0040902D */  daddu     $s2, $v0, $zero
/* 3CF438 E00C8098 0C08012C */  jal       func_E02004B0
/* 3CF43C E00C809C AE430008 */   sw       $v1, 8($s2)
/* 3CF440 E00C80A0 0040802D */  daddu     $s0, $v0, $zero
/* 3CF444 E00C80A4 16000003 */  bnez      $s0, .LE00C80B4
/* 3CF448 E00C80A8 AE42000C */   sw       $v0, 0xc($s2)
.LE00C80AC:
/* 3CF44C E00C80AC 0803202B */  j         .LE00C80AC
/* 3CF450 E00C80B0 00000000 */   nop
.LE00C80B4:
/* 3CF454 E00C80B4 AE130000 */  sw        $s3, ($s0)
/* 3CF458 E00C80B8 1E200003 */  bgtz      $s1, .LE00C80C8
/* 3CF45C E00C80BC AE00002C */   sw       $zero, 0x2c($s0)
/* 3CF460 E00C80C0 08032033 */  j         .LE00C80CC
/* 3CF464 E00C80C4 240203E8 */   addiu    $v0, $zero, 0x3e8
.LE00C80C8:
/* 3CF468 E00C80C8 2622003C */  addiu     $v0, $s1, 0x3c
.LE00C80CC:
/* 3CF46C E00C80CC AE020028 */  sw        $v0, 0x28($s0)
/* 3CF470 E00C80D0 240200FF */  addiu     $v0, $zero, 0xff
/* 3CF474 E00C80D4 44913000 */  mtc1      $s1, $f6
/* 3CF478 E00C80D8 00000000 */  nop
/* 3CF47C E00C80DC 468031A1 */  cvt.d.w   $f6, $f6
/* 3CF480 E00C80E0 4616E201 */  sub.s     $f8, $f28, $f22
/* 3CF484 E00C80E4 44912000 */  mtc1      $s1, $f4
/* 3CF488 E00C80E8 00000000 */  nop
/* 3CF48C E00C80EC 46802120 */  cvt.s.w   $f4, $f4
/* 3CF490 E00C80F0 3C01E00D */  lui       $at, %hi(D_E00C8730)
/* 3CF494 E00C80F4 D4208730 */  ldc1      $f0, %lo(D_E00C8730)($at)
/* 3CF498 E00C80F8 4618F081 */  sub.s     $f2, $f30, $f24
/* 3CF49C E00C80FC AE110068 */  sw        $s1, 0x68($s0)
/* 3CF4A0 E00C8100 AE02003C */  sw        $v0, 0x3c($s0)
/* 3CF4A4 E00C8104 46203182 */  mul.d     $f6, $f6, $f0
/* 3CF4A8 E00C8108 00000000 */  nop
/* 3CF4AC E00C810C E6140010 */  swc1      $f20, 0x10($s0)
/* 3CF4B0 E00C8110 E6160014 */  swc1      $f22, 0x14($s0)
/* 3CF4B4 E00C8114 E6180018 */  swc1      $f24, 0x18($s0)
/* 3CF4B8 E00C8118 E61A001C */  swc1      $f26, 0x1c($s0)
/* 3CF4BC E00C811C E61C0020 */  swc1      $f28, 0x20($s0)
/* 3CF4C0 E00C8120 E61E0024 */  swc1      $f30, 0x24($s0)
/* 3CF4C4 E00C8124 E6140004 */  swc1      $f20, 4($s0)
/* 3CF4C8 E00C8128 4614D001 */  sub.s     $f0, $f26, $f20
/* 3CF4CC E00C812C 46041083 */  div.s     $f2, $f2, $f4
/* 3CF4D0 E00C8130 E602004C */  swc1      $f2, 0x4c($s0)
/* 3CF4D4 E00C8134 44801000 */  mtc1      $zero, $f2
/* 3CF4D8 E00C8138 46040003 */  div.s     $f0, $f0, $f4
/* 3CF4DC E00C813C E6000044 */  swc1      $f0, 0x44($s0)
/* 3CF4E0 E00C8140 46044003 */  div.s     $f0, $f8, $f4
/* 3CF4E4 E00C8144 46000021 */  cvt.d.s   $f0, $f0
/* 3CF4E8 E00C8148 46260001 */  sub.d     $f0, $f0, $f6
/* 3CF4EC E00C814C E6160008 */  swc1      $f22, 8($s0)
/* 3CF4F0 E00C8150 E618000C */  swc1      $f24, 0xc($s0)
/* 3CF4F4 E00C8154 4602403C */  c.lt.s    $f8, $f2
/* 3CF4F8 E00C8158 46200020 */  cvt.s.d   $f0, $f0
/* 3CF4FC E00C815C 45000004 */  bc1f      .LE00C8170
/* 3CF500 E00C8160 E6000048 */   swc1     $f0, 0x48($s0)
/* 3CF504 E00C8164 24020001 */  addiu     $v0, $zero, 1
/* 3CF508 E00C8168 0803205D */  j         .LE00C8174
/* 3CF50C E00C816C AE020064 */   sw       $v0, 0x64($s0)
.LE00C8170:
/* 3CF510 E00C8170 AE000064 */  sw        $zero, 0x64($s0)
.LE00C8174:
/* 3CF514 E00C8174 24040168 */  addiu     $a0, $zero, 0x168
/* 3CF518 E00C8178 C7A0008C */  lwc1      $f0, 0x8c($sp)
/* 3CF51C E00C817C 24020046 */  addiu     $v0, $zero, 0x46
/* 3CF520 E00C8180 AE020030 */  sw        $v0, 0x30($s0)
/* 3CF524 E00C8184 240200B4 */  addiu     $v0, $zero, 0xb4
/* 3CF528 E00C8188 AE020034 */  sw        $v0, 0x34($s0)
/* 3CF52C E00C818C 24020078 */  addiu     $v0, $zero, 0x78
/* 3CF530 E00C8190 AE020038 */  sw        $v0, 0x38($s0)
/* 3CF534 E00C8194 0C080138 */  jal       func_E02004E0
/* 3CF538 E00C8198 E6000040 */   swc1     $f0, 0x40($s0)
/* 3CF53C E00C819C 2404000A */  addiu     $a0, $zero, 0xa
/* 3CF540 E00C81A0 44820000 */  mtc1      $v0, $f0
/* 3CF544 E00C81A4 00000000 */  nop
/* 3CF548 E00C81A8 46800020 */  cvt.s.w   $f0, $f0
/* 3CF54C E00C81AC 0C080138 */  jal       func_E02004E0
/* 3CF550 E00C81B0 E6000050 */   swc1     $f0, 0x50($s0)
/* 3CF554 E00C81B4 24430005 */  addiu     $v1, $v0, 5
/* 3CF558 E00C81B8 0240102D */  daddu     $v0, $s2, $zero
/* 3CF55C E00C81BC 44830000 */  mtc1      $v1, $f0
/* 3CF560 E00C81C0 00000000 */  nop
/* 3CF564 E00C81C4 46800020 */  cvt.s.w   $f0, $f0
/* 3CF568 E00C81C8 E6000054 */  swc1      $f0, 0x54($s0)
/* 3CF56C E00C81CC 3C013F80 */  lui       $at, 0x3f80
/* 3CF570 E00C81D0 44810000 */  mtc1      $at, $f0
/* 3CF574 E00C81D4 2403FFFF */  addiu     $v1, $zero, -1
/* 3CF578 E00C81D8 AE030060 */  sw        $v1, 0x60($s0)
/* 3CF57C E00C81DC E6000058 */  swc1      $f0, 0x58($s0)
/* 3CF580 E00C81E0 E600005C */  swc1      $f0, 0x5c($s0)
/* 3CF584 E00C81E4 8FBF0038 */  lw        $ra, 0x38($sp)
/* 3CF588 E00C81E8 8FB30034 */  lw        $s3, 0x34($sp)
/* 3CF58C E00C81EC 8FB20030 */  lw        $s2, 0x30($sp)
/* 3CF590 E00C81F0 8FB1002C */  lw        $s1, 0x2c($sp)
/* 3CF594 E00C81F4 8FB00028 */  lw        $s0, 0x28($sp)
/* 3CF598 E00C81F8 D7BE0068 */  ldc1      $f30, 0x68($sp)
/* 3CF59C E00C81FC D7BC0060 */  ldc1      $f28, 0x60($sp)
/* 3CF5A0 E00C8200 D7BA0058 */  ldc1      $f26, 0x58($sp)
/* 3CF5A4 E00C8204 D7B80050 */  ldc1      $f24, 0x50($sp)
/* 3CF5A8 E00C8208 D7B60048 */  ldc1      $f22, 0x48($sp)
/* 3CF5AC E00C820C D7B40040 */  ldc1      $f20, 0x40($sp)
/* 3CF5B0 E00C8210 03E00008 */  jr        $ra
/* 3CF5B4 E00C8214 27BD0070 */   addiu    $sp, $sp, 0x70
