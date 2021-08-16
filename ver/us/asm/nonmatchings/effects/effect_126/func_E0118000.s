.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0118000
/* 403400 E0118000 27BDFF90 */  addiu     $sp, $sp, -0x70
/* 403404 E0118004 F7B80050 */  sdc1      $f24, 0x50($sp)
/* 403408 E0118008 4485C000 */  mtc1      $a1, $f24
/* 40340C E011800C F7BA0058 */  sdc1      $f26, 0x58($sp)
/* 403410 E0118010 4486D000 */  mtc1      $a2, $f26
/* 403414 E0118014 F7BC0060 */  sdc1      $f28, 0x60($sp)
/* 403418 E0118018 4487E000 */  mtc1      $a3, $f28
/* 40341C E011801C AFB1002C */  sw        $s1, 0x2c($sp)
/* 403420 E0118020 0080882D */  daddu     $s1, $a0, $zero
/* 403424 E0118024 F7BE0068 */  sdc1      $f30, 0x68($sp)
/* 403428 E0118028 C7BE0080 */  lwc1      $f30, 0x80($sp)
/* 40342C E011802C 27A40010 */  addiu     $a0, $sp, 0x10
/* 403430 E0118030 AFB00028 */  sw        $s0, 0x28($sp)
/* 403434 E0118034 8FB00084 */  lw        $s0, 0x84($sp)
/* 403438 E0118038 3C02E012 */  lui       $v0, %hi(func_E01182EC)
/* 40343C E011803C 244282EC */  addiu     $v0, $v0, %lo(func_E01182EC)
/* 403440 E0118040 AFA20018 */  sw        $v0, 0x18($sp)
/* 403444 E0118044 3C02E012 */  lui       $v0, %hi(func_E01182F4)
/* 403448 E0118048 244282F4 */  addiu     $v0, $v0, %lo(func_E01182F4)
/* 40344C E011804C AFA2001C */  sw        $v0, 0x1c($sp)
/* 403450 E0118050 3C02E012 */  lui       $v0, %hi(func_E0118454)
/* 403454 E0118054 24428454 */  addiu     $v0, $v0, %lo(func_E0118454)
/* 403458 E0118058 AFA20020 */  sw        $v0, 0x20($sp)
/* 40345C E011805C 2402007E */  addiu     $v0, $zero, 0x7e
/* 403460 E0118060 AFBF0038 */  sw        $ra, 0x38($sp)
/* 403464 E0118064 AFB30034 */  sw        $s3, 0x34($sp)
/* 403468 E0118068 AFB20030 */  sw        $s2, 0x30($sp)
/* 40346C E011806C F7B60048 */  sdc1      $f22, 0x48($sp)
/* 403470 E0118070 F7B40040 */  sdc1      $f20, 0x40($sp)
/* 403474 E0118074 AFA00010 */  sw        $zero, 0x10($sp)
/* 403478 E0118078 AFA00024 */  sw        $zero, 0x24($sp)
/* 40347C E011807C 0C080124 */  jal       func_E0200490
/* 403480 E0118080 AFA20014 */   sw       $v0, 0x14($sp)
/* 403484 E0118084 24040168 */  addiu     $a0, $zero, 0x168
/* 403488 E0118088 24030006 */  addiu     $v1, $zero, 6
/* 40348C E011808C 0040982D */  daddu     $s3, $v0, $zero
/* 403490 E0118090 0C08012C */  jal       func_E02004B0
/* 403494 E0118094 AE630008 */   sw       $v1, 8($s3)
/* 403498 E0118098 0040182D */  daddu     $v1, $v0, $zero
/* 40349C E011809C 14600003 */  bnez      $v1, .LE01180AC
/* 4034A0 E01180A0 AE62000C */   sw       $v0, 0xc($s3)
.LE01180A4:
/* 4034A4 E01180A4 08046029 */  j         .LE01180A4
/* 4034A8 E01180A8 00000000 */   nop
.LE01180AC:
/* 4034AC E01180AC AC710000 */  sw        $s1, ($v1)
/* 4034B0 E01180B0 1E000004 */  bgtz      $s0, .LE01180C4
/* 4034B4 E01180B4 AC600020 */   sw       $zero, 0x20($v1)
/* 4034B8 E01180B8 240203E8 */  addiu     $v0, $zero, 0x3e8
/* 4034BC E01180BC 08046032 */  j         .LE01180C8
/* 4034C0 E01180C0 AC62001C */   sw       $v0, 0x1c($v1)
.LE01180C4:
/* 4034C4 E01180C4 AC70001C */  sw        $s0, 0x1c($v1)
.LE01180C8:
/* 4034C8 E01180C8 240200FF */  addiu     $v0, $zero, 0xff
/* 4034CC E01180CC A4620032 */  sh        $v0, 0x32($v1)
/* 4034D0 E01180D0 8E620008 */  lw        $v0, 8($s3)
/* 4034D4 E01180D4 18400077 */  blez      $v0, .LE01182B4
/* 4034D8 E01180D8 0000882D */   daddu    $s1, $zero, $zero
/* 4034DC E01180DC 241200FF */  addiu     $s2, $zero, 0xff
/* 4034E0 E01180E0 24700028 */  addiu     $s0, $v1, 0x28
/* 4034E4 E01180E4 3C013FE0 */  lui       $at, 0x3fe0
/* 4034E8 E01180E8 4481B800 */  mtc1      $at, $f23
/* 4034EC E01180EC 4480B000 */  mtc1      $zero, $f22
/* 4034F0 E01180F0 3C01E012 */  lui       $at, %hi(D_E01187D0)
/* 4034F4 E01180F4 D43487D0 */  ldc1      $f20, %lo(D_E01187D0)($at)
.LE01180F8:
/* 4034F8 E01180F8 2404000A */  addiu     $a0, $zero, 0xa
/* 4034FC E01180FC E618FFDC */  swc1      $f24, -0x24($s0)
/* 403500 E0118100 E61AFFE0 */  swc1      $f26, -0x20($s0)
/* 403504 E0118104 0C080138 */  jal       func_E02004E0
/* 403508 E0118108 E61CFFE4 */   swc1     $f28, -0x1c($s0)
/* 40350C E011810C 2442FFFB */  addiu     $v0, $v0, -5
/* 403510 E0118110 44820000 */  mtc1      $v0, $f0
/* 403514 E0118114 00000000 */  nop
/* 403518 E0118118 46800021 */  cvt.d.w   $f0, $f0
/* 40351C E011811C 46360002 */  mul.d     $f0, $f0, $f22
/* 403520 E0118120 00000000 */  nop
/* 403524 E0118124 24040005 */  addiu     $a0, $zero, 5
/* 403528 E0118128 46200020 */  cvt.s.d   $f0, $f0
/* 40352C E011812C 0C080138 */  jal       func_E02004E0
/* 403530 E0118130 E600FFE8 */   swc1     $f0, -0x18($s0)
/* 403534 E0118134 24420001 */  addiu     $v0, $v0, 1
/* 403538 E0118138 3C01E012 */  lui       $at, %hi(D_E01187D8)
/* 40353C E011813C D42287D8 */  ldc1      $f2, %lo(D_E01187D8)($at)
/* 403540 E0118140 44820000 */  mtc1      $v0, $f0
/* 403544 E0118144 00000000 */  nop
/* 403548 E0118148 46800021 */  cvt.d.w   $f0, $f0
/* 40354C E011814C 46220002 */  mul.d     $f0, $f0, $f2
/* 403550 E0118150 00000000 */  nop
/* 403554 E0118154 2404000A */  addiu     $a0, $zero, 0xa
/* 403558 E0118158 46200020 */  cvt.s.d   $f0, $f0
/* 40355C E011815C 0C080138 */  jal       func_E02004E0
/* 403560 E0118160 E600FFEC */   swc1     $f0, -0x14($s0)
/* 403564 E0118164 2442FFFB */  addiu     $v0, $v0, -5
/* 403568 E0118168 44820000 */  mtc1      $v0, $f0
/* 40356C E011816C 00000000 */  nop
/* 403570 E0118170 46800021 */  cvt.d.w   $f0, $f0
/* 403574 E0118174 46360002 */  mul.d     $f0, $f0, $f22
/* 403578 E0118178 00000000 */  nop
/* 40357C E011817C 240400FF */  addiu     $a0, $zero, 0xff
/* 403580 E0118180 E61EFFFC */  swc1      $f30, -4($s0)
/* 403584 E0118184 46200020 */  cvt.s.d   $f0, $f0
/* 403588 E0118188 0C080138 */  jal       func_E02004E0
/* 40358C E011818C E600FFF0 */   swc1     $f0, -0x10($s0)
/* 403590 E0118190 A602000C */  sh        $v0, 0xc($s0)
/* 403594 E0118194 8604000C */  lh        $a0, 0xc($s0)
/* 403598 E0118198 A6020004 */  sh        $v0, 4($s0)
/* 40359C E011819C 0C080138 */  jal       func_E02004E0
/* 4035A0 E01181A0 02442023 */   subu     $a0, $s2, $a0
/* 4035A4 E01181A4 9603000C */  lhu       $v1, 0xc($s0)
/* 4035A8 E01181A8 A602000E */  sh        $v0, 0xe($s0)
/* 4035AC E01181AC A6020006 */  sh        $v0, 6($s0)
/* 4035B0 E01181B0 02421023 */  subu      $v0, $s2, $v0
/* 4035B4 E01181B4 00431023 */  subu      $v0, $v0, $v1
/* 4035B8 E01181B8 A6020010 */  sh        $v0, 0x10($s0)
/* 4035BC E01181BC A6020008 */  sh        $v0, 8($s0)
/* 4035C0 E01181C0 96020004 */  lhu       $v0, 4($s0)
/* 4035C4 E01181C4 96030006 */  lhu       $v1, 6($s0)
/* 4035C8 E01181C8 244200A8 */  addiu     $v0, $v0, 0xa8
/* 4035CC E01181CC A6020004 */  sh        $v0, 4($s0)
/* 4035D0 E01181D0 96020008 */  lhu       $v0, 8($s0)
/* 4035D4 E01181D4 246300A8 */  addiu     $v1, $v1, 0xa8
/* 4035D8 E01181D8 A6030006 */  sh        $v1, 6($s0)
/* 4035DC E01181DC 86030004 */  lh        $v1, 4($s0)
/* 4035E0 E01181E0 244200A8 */  addiu     $v0, $v0, 0xa8
/* 4035E4 E01181E4 28630100 */  slti      $v1, $v1, 0x100
/* 4035E8 E01181E8 14600002 */  bnez      $v1, .LE01181F4
/* 4035EC E01181EC A6020008 */   sh       $v0, 8($s0)
/* 4035F0 E01181F0 A6120004 */  sh        $s2, 4($s0)
.LE01181F4:
/* 4035F4 E01181F4 86020006 */  lh        $v0, 6($s0)
/* 4035F8 E01181F8 28420100 */  slti      $v0, $v0, 0x100
/* 4035FC E01181FC 50400001 */  beql      $v0, $zero, .LE0118204
/* 403600 E0118200 A6120006 */   sh       $s2, 6($s0)
.LE0118204:
/* 403604 E0118204 86020008 */  lh        $v0, 8($s0)
/* 403608 E0118208 28420100 */  slti      $v0, $v0, 0x100
/* 40360C E011820C 50400001 */  beql      $v0, $zero, .LE0118214
/* 403610 E0118210 A6120008 */   sh       $s2, 8($s0)
.LE0118214:
/* 403614 E0118214 8602000C */  lh        $v0, 0xc($s0)
/* 403618 E0118218 44822000 */  mtc1      $v0, $f4
/* 40361C E011821C 00000000 */  nop
/* 403620 E0118220 46802121 */  cvt.d.w   $f4, $f4
/* 403624 E0118224 46342102 */  mul.d     $f4, $f4, $f20
/* 403628 E0118228 00000000 */  nop
/* 40362C E011822C 8602000E */  lh        $v0, 0xe($s0)
/* 403630 E0118230 44821000 */  mtc1      $v0, $f2
/* 403634 E0118234 00000000 */  nop
/* 403638 E0118238 468010A1 */  cvt.d.w   $f2, $f2
/* 40363C E011823C 46341082 */  mul.d     $f2, $f2, $f20
/* 403640 E0118240 00000000 */  nop
/* 403644 E0118244 86020010 */  lh        $v0, 0x10($s0)
/* 403648 E0118248 44820000 */  mtc1      $v0, $f0
/* 40364C E011824C 00000000 */  nop
/* 403650 E0118250 46800021 */  cvt.d.w   $f0, $f0
/* 403654 E0118254 46340002 */  mul.d     $f0, $f0, $f20
/* 403658 E0118258 00000000 */  nop
/* 40365C E011825C 24040167 */  addiu     $a0, $zero, 0x167
/* 403660 E0118260 26310001 */  addiu     $s1, $s1, 1
/* 403664 E0118264 4620218D */  trunc.w.d $f6, $f4
/* 403668 E0118268 44023000 */  mfc1      $v0, $f6
/* 40366C E011826C 00000000 */  nop
/* 403670 E0118270 A602000C */  sh        $v0, 0xc($s0)
/* 403674 E0118274 4620118D */  trunc.w.d $f6, $f2
/* 403678 E0118278 44023000 */  mfc1      $v0, $f6
/* 40367C E011827C 00000000 */  nop
/* 403680 E0118280 A602000E */  sh        $v0, 0xe($s0)
/* 403684 E0118284 4620018D */  trunc.w.d $f6, $f0
/* 403688 E0118288 44023000 */  mfc1      $v0, $f6
/* 40368C E011828C 0C080138 */  jal       func_E02004E0
/* 403690 E0118290 A6020010 */   sh       $v0, 0x10($s0)
/* 403694 E0118294 44820000 */  mtc1      $v0, $f0
/* 403698 E0118298 00000000 */  nop
/* 40369C E011829C 46800020 */  cvt.s.w   $f0, $f0
/* 4036A0 E01182A0 E6000000 */  swc1      $f0, ($s0)
/* 4036A4 E01182A4 8E620008 */  lw        $v0, 8($s3)
/* 4036A8 E01182A8 0222102A */  slt       $v0, $s1, $v0
/* 4036AC E01182AC 1440FF92 */  bnez      $v0, .LE01180F8
/* 4036B0 E01182B0 2610003C */   addiu    $s0, $s0, 0x3c
.LE01182B4:
/* 4036B4 E01182B4 0260102D */  daddu     $v0, $s3, $zero
/* 4036B8 E01182B8 8FBF0038 */  lw        $ra, 0x38($sp)
/* 4036BC E01182BC 8FB30034 */  lw        $s3, 0x34($sp)
/* 4036C0 E01182C0 8FB20030 */  lw        $s2, 0x30($sp)
/* 4036C4 E01182C4 8FB1002C */  lw        $s1, 0x2c($sp)
/* 4036C8 E01182C8 8FB00028 */  lw        $s0, 0x28($sp)
/* 4036CC E01182CC D7BE0068 */  ldc1      $f30, 0x68($sp)
/* 4036D0 E01182D0 D7BC0060 */  ldc1      $f28, 0x60($sp)
/* 4036D4 E01182D4 D7BA0058 */  ldc1      $f26, 0x58($sp)
/* 4036D8 E01182D8 D7B80050 */  ldc1      $f24, 0x50($sp)
/* 4036DC E01182DC D7B60048 */  ldc1      $f22, 0x48($sp)
/* 4036E0 E01182E0 D7B40040 */  ldc1      $f20, 0x40($sp)
/* 4036E4 E01182E4 03E00008 */  jr        $ra
/* 4036E8 E01182E8 27BD0070 */   addiu    $sp, $sp, 0x70
