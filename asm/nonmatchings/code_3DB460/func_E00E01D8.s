.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00E01D8
/* 3DB638 E00E01D8 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* 3DB63C E00E01DC AFB20020 */  sw        $s2, 0x20($sp)
/* 3DB640 E00E01E0 0080902D */  daddu     $s2, $a0, $zero
/* 3DB644 E00E01E4 AFBF0028 */  sw        $ra, 0x28($sp)
/* 3DB648 E00E01E8 AFB30024 */  sw        $s3, 0x24($sp)
/* 3DB64C E00E01EC AFB1001C */  sw        $s1, 0x1c($sp)
/* 3DB650 E00E01F0 AFB00018 */  sw        $s0, 0x18($sp)
/* 3DB654 E00E01F4 F7BE0058 */  sdc1      $f30, 0x58($sp)
/* 3DB658 E00E01F8 F7BC0050 */  sdc1      $f28, 0x50($sp)
/* 3DB65C E00E01FC F7BA0048 */  sdc1      $f26, 0x48($sp)
/* 3DB660 E00E0200 F7B80040 */  sdc1      $f24, 0x40($sp)
/* 3DB664 E00E0204 F7B60038 */  sdc1      $f22, 0x38($sp)
/* 3DB668 E00E0208 F7B40030 */  sdc1      $f20, 0x30($sp)
/* 3DB66C E00E020C 8E430000 */  lw        $v1, ($s2)
/* 3DB670 E00E0210 8E44000C */  lw        $a0, 0xc($s2)
/* 3DB674 E00E0214 30620010 */  andi      $v0, $v1, 0x10
/* 3DB678 E00E0218 10400005 */  beqz      $v0, .LE00E0230
/* 3DB67C E00E021C 2402FFEF */   addiu    $v0, $zero, -0x11
/* 3DB680 E00E0220 00621024 */  and       $v0, $v1, $v0
/* 3DB684 E00E0224 AE420000 */  sw        $v0, ($s2)
/* 3DB688 E00E0228 24020010 */  addiu     $v0, $zero, 0x10
/* 3DB68C E00E022C AC820018 */  sw        $v0, 0x18($a0)
.LE00E0230:
/* 3DB690 E00E0230 8C830018 */  lw        $v1, 0x18($a0)
/* 3DB694 E00E0234 286203E8 */  slti      $v0, $v1, 0x3e8
/* 3DB698 E00E0238 10400002 */  beqz      $v0, .LE00E0244
/* 3DB69C E00E023C 2462FFFF */   addiu    $v0, $v1, -1
/* 3DB6A0 E00E0240 AC820018 */  sw        $v0, 0x18($a0)
.LE00E0244:
/* 3DB6A4 E00E0244 3C030004 */  lui       $v1, 4
/* 3DB6A8 E00E0248 8C82001C */  lw        $v0, 0x1c($a0)
/* 3DB6AC E00E024C 3463F1A0 */  ori       $v1, $v1, 0xf1a0
/* 3DB6B0 E00E0250 24420001 */  addiu     $v0, $v0, 1
/* 3DB6B4 E00E0254 0062182A */  slt       $v1, $v1, $v0
/* 3DB6B8 E00E0258 10600003 */  beqz      $v1, .LE00E0268
/* 3DB6BC E00E025C AC82001C */   sw       $v0, 0x1c($a0)
/* 3DB6C0 E00E0260 24020100 */  addiu     $v0, $zero, 0x100
/* 3DB6C4 E00E0264 AC82001C */  sw        $v0, 0x1c($a0)
.LE00E0268:
/* 3DB6C8 E00E0268 8C830018 */  lw        $v1, 0x18($a0)
/* 3DB6CC E00E026C 04610005 */  bgez      $v1, .LE00E0284
/* 3DB6D0 E00E0270 28620010 */   slti     $v0, $v1, 0x10
/* 3DB6D4 E00E0274 0C080128 */  jal       func_E02004A0
/* 3DB6D8 E00E0278 0240202D */   daddu    $a0, $s2, $zero
/* 3DB6DC E00E027C 0803815F */  j         .LE00E057C
/* 3DB6E0 E00E0280 00000000 */   nop      
.LE00E0284:
/* 3DB6E4 E00E0284 8C85001C */  lw        $a1, 0x1c($a0)
/* 3DB6E8 E00E0288 10400002 */  beqz      $v0, .LE00E0294
/* 3DB6EC E00E028C 00031100 */   sll      $v0, $v1, 4
/* 3DB6F0 E00E0290 AC82002C */  sw        $v0, 0x2c($a0)
.LE00E0294:
/* 3DB6F4 E00E0294 28A20010 */  slti      $v0, $a1, 0x10
/* 3DB6F8 E00E0298 10400003 */  beqz      $v0, .LE00E02A8
/* 3DB6FC E00E029C 00051100 */   sll      $v0, $a1, 4
/* 3DB700 E00E02A0 2442000F */  addiu     $v0, $v0, 0xf
/* 3DB704 E00E02A4 AC82002C */  sw        $v0, 0x2c($a0)
.LE00E02A8:
/* 3DB708 E00E02A8 C4980010 */  lwc1      $f24, 0x10($a0)
/* 3DB70C E00E02AC C49E0014 */  lwc1      $f30, 0x14($a0)
/* 3DB710 E00E02B0 C49C0068 */  lwc1      $f28, 0x68($a0)
/* 3DB714 E00E02B4 C49A006C */  lwc1      $f26, 0x6c($a0)
/* 3DB718 E00E02B8 E7BA0010 */  swc1      $f26, 0x10($sp)
/* 3DB71C E00E02BC 8E420008 */  lw        $v0, 8($s2)
/* 3DB720 E00E02C0 24110001 */  addiu     $s1, $zero, 1
/* 3DB724 E00E02C4 0222102A */  slt       $v0, $s1, $v0
/* 3DB728 E00E02C8 104000AC */  beqz      $v0, .LE00E057C
/* 3DB72C E00E02CC 24840070 */   addiu    $a0, $a0, 0x70
/* 3DB730 E00E02D0 3C13E00E */  lui       $s3, %hi(D_E00E0A48)
/* 3DB734 E00E02D4 26730A48 */  addiu     $s3, $s3, %lo(D_E00E0A48)
/* 3DB738 E00E02D8 2490004C */  addiu     $s0, $a0, 0x4c
/* 3DB73C E00E02DC 3C01E00E */  lui       $at, %hi(D_E00E0AC0)
/* 3DB740 E00E02E0 D4340AC0 */  ldc1      $f20, %lo(D_E00E0AC0)($at)
/* 3DB744 E00E02E4 3C01E00E */  lui       $at, %hi(D_E00E0AC8)
/* 3DB748 E00E02E8 D4360AC8 */  ldc1      $f22, %lo(D_E00E0AC8)($at)
.LE00E02EC:
/* 3DB74C E00E02EC 8E020018 */  lw        $v0, 0x18($s0)
/* 3DB750 E00E02F0 24420001 */  addiu     $v0, $v0, 1
/* 3DB754 E00E02F4 AE020018 */  sw        $v0, 0x18($s0)
/* 3DB758 E00E02F8 2842001E */  slti      $v0, $v0, 0x1e
/* 3DB75C E00E02FC 50400001 */  beql      $v0, $zero, .LE00E0304
/* 3DB760 E00E0300 AE000018 */   sw       $zero, 0x18($s0)
.LE00E0304:
/* 3DB764 E00E0304 8E020018 */  lw        $v0, 0x18($s0)
/* 3DB768 E00E0308 04420098 */  bltzl     $v0, .LE00E056C
/* 3DB76C E00E030C 26310001 */   addiu    $s1, $s1, 1
/* 3DB770 E00E0310 14400058 */  bnez      $v0, .LE00E0474
/* 3DB774 E00E0314 00000000 */   nop      
/* 3DB778 E00E0318 4600C68D */  trunc.w.s $f26, $f24
/* 3DB77C E00E031C 4404D000 */  mfc1      $a0, $f26
/* 3DB780 E00E0320 0C080138 */  jal       func_E02004E0
/* 3DB784 E00E0324 00000000 */   nop      
/* 3DB788 E00E0328 3C013FE0 */  lui       $at, 0x3fe0
/* 3DB78C E00E032C 44810800 */  mtc1      $at, $f1
/* 3DB790 E00E0330 44800000 */  mtc1      $zero, $f0
/* 3DB794 E00E0334 4600C0A1 */  cvt.d.s   $f2, $f24
/* 3DB798 E00E0338 46201082 */  mul.d     $f2, $f2, $f0
/* 3DB79C E00E033C 00000000 */  nop       
/* 3DB7A0 E00E0340 44820000 */  mtc1      $v0, $f0
/* 3DB7A4 E00E0344 00000000 */  nop       
/* 3DB7A8 E00E0348 46800021 */  cvt.d.w   $f0, $f0
/* 3DB7AC E00E034C 46220001 */  sub.d     $f0, $f0, $f2
/* 3DB7B0 E00E0350 4600F68D */  trunc.w.s $f26, $f30
/* 3DB7B4 E00E0354 4404D000 */  mfc1      $a0, $f26
/* 3DB7B8 E00E0358 46200020 */  cvt.s.d   $f0, $f0
/* 3DB7BC E00E035C 0C080138 */  jal       func_E02004E0
/* 3DB7C0 E00E0360 E600FFB8 */   swc1     $f0, -0x48($s0)
/* 3DB7C4 E00E0364 24040014 */  addiu     $a0, $zero, 0x14
/* 3DB7C8 E00E0368 44820000 */  mtc1      $v0, $f0
/* 3DB7CC E00E036C 00000000 */  nop       
/* 3DB7D0 E00E0370 46800020 */  cvt.s.w   $f0, $f0
/* 3DB7D4 E00E0374 E600FFBC */  swc1      $f0, -0x44($s0)
/* 3DB7D8 E00E0378 0C080138 */  jal       func_E02004E0
/* 3DB7DC E00E037C AE00FFC0 */   sw       $zero, -0x40($s0)
/* 3DB7E0 E00E0380 2442FFF6 */  addiu     $v0, $v0, -0xa
/* 3DB7E4 E00E0384 44820000 */  mtc1      $v0, $f0
/* 3DB7E8 E00E0388 00000000 */  nop       
/* 3DB7EC E00E038C 46800020 */  cvt.s.w   $f0, $f0
/* 3DB7F0 E00E0390 46000021 */  cvt.d.s   $f0, $f0
/* 3DB7F4 E00E0394 46340002 */  mul.d     $f0, $f0, $f20
/* 3DB7F8 E00E0398 00000000 */  nop       
/* 3DB7FC E00E039C 24040028 */  addiu     $a0, $zero, 0x28
/* 3DB800 E00E03A0 46200020 */  cvt.s.d   $f0, $f0
/* 3DB804 E00E03A4 0C080138 */  jal       func_E02004E0
/* 3DB808 E00E03A8 E600FFF8 */   swc1     $f0, -8($s0)
/* 3DB80C E00E03AC 2442FFFF */  addiu     $v0, $v0, -1
/* 3DB810 E00E03B0 44820000 */  mtc1      $v0, $f0
/* 3DB814 E00E03B4 00000000 */  nop       
/* 3DB818 E00E03B8 46800020 */  cvt.s.w   $f0, $f0
/* 3DB81C E00E03BC 461C0002 */  mul.s     $f0, $f0, $f28
/* 3DB820 E00E03C0 00000000 */  nop       
/* 3DB824 E00E03C4 46000021 */  cvt.d.s   $f0, $f0
/* 3DB828 E00E03C8 46340002 */  mul.d     $f0, $f0, $f20
/* 3DB82C E00E03CC 00000000 */  nop       
/* 3DB830 E00E03D0 24040014 */  addiu     $a0, $zero, 0x14
/* 3DB834 E00E03D4 AE000000 */  sw        $zero, ($s0)
/* 3DB838 E00E03D8 46200020 */  cvt.s.d   $f0, $f0
/* 3DB83C E00E03DC 0C080138 */  jal       func_E02004E0
/* 3DB840 E00E03E0 E600FFFC */   swc1     $f0, -4($s0)
/* 3DB844 E00E03E4 2442FFF6 */  addiu     $v0, $v0, -0xa
/* 3DB848 E00E03E8 44820000 */  mtc1      $v0, $f0
/* 3DB84C E00E03EC 00000000 */  nop       
/* 3DB850 E00E03F0 46800020 */  cvt.s.w   $f0, $f0
/* 3DB854 E00E03F4 46000021 */  cvt.d.s   $f0, $f0
/* 3DB858 E00E03F8 46340002 */  mul.d     $f0, $f0, $f20
/* 3DB85C E00E03FC 00000000 */  nop       
/* 3DB860 E00E0400 2404001E */  addiu     $a0, $zero, 0x1e
/* 3DB864 E00E0404 46200020 */  cvt.s.d   $f0, $f0
/* 3DB868 E00E0408 0C080138 */  jal       func_E02004E0
/* 3DB86C E00E040C E6000004 */   swc1     $f0, 4($s0)
/* 3DB870 E00E0410 2442FFFF */  addiu     $v0, $v0, -1
/* 3DB874 E00E0414 C7BA0010 */  lwc1      $f26, 0x10($sp)
/* 3DB878 E00E0418 44820000 */  mtc1      $v0, $f0
/* 3DB87C E00E041C 00000000 */  nop       
/* 3DB880 E00E0420 46800020 */  cvt.s.w   $f0, $f0
/* 3DB884 E00E0424 461A0002 */  mul.s     $f0, $f0, $f26
/* 3DB888 E00E0428 00000000 */  nop       
/* 3DB88C E00E042C 46000021 */  cvt.d.s   $f0, $f0
/* 3DB890 E00E0430 46340002 */  mul.d     $f0, $f0, $f20
/* 3DB894 E00E0434 00000000 */  nop       
/* 3DB898 E00E0438 2404000F */  addiu     $a0, $zero, 0xf
/* 3DB89C E00E043C AE00000C */  sw        $zero, 0xc($s0)
/* 3DB8A0 E00E0440 46200020 */  cvt.s.d   $f0, $f0
/* 3DB8A4 E00E0444 0C080138 */  jal       func_E02004E0
/* 3DB8A8 E00E0448 E6000008 */   swc1     $f0, 8($s0)
/* 3DB8AC E00E044C 2404000F */  addiu     $a0, $zero, 0xf
/* 3DB8B0 E00E0450 44820000 */  mtc1      $v0, $f0
/* 3DB8B4 E00E0454 00000000 */  nop       
/* 3DB8B8 E00E0458 46800020 */  cvt.s.w   $f0, $f0
/* 3DB8BC E00E045C 0C080138 */  jal       func_E02004E0
/* 3DB8C0 E00E0460 E6000010 */   swc1     $f0, 0x10($s0)
/* 3DB8C4 E00E0464 44820000 */  mtc1      $v0, $f0
/* 3DB8C8 E00E0468 00000000 */  nop       
/* 3DB8CC E00E046C 46800020 */  cvt.s.w   $f0, $f0
/* 3DB8D0 E00E0470 E6000014 */  swc1      $f0, 0x14($s0)
.LE00E0474:
/* 3DB8D4 E00E0474 C610FFF8 */  lwc1      $f16, -8($s0)
/* 3DB8D8 E00E0478 C60A0004 */  lwc1      $f10, 4($s0)
/* 3DB8DC E00E047C 46105281 */  sub.s     $f10, $f10, $f16
/* 3DB8E0 E00E0480 460052A1 */  cvt.d.s   $f10, $f10
/* 3DB8E4 E00E0484 46365282 */  mul.d     $f10, $f10, $f22
/* 3DB8E8 E00E0488 00000000 */  nop       
/* 3DB8EC E00E048C C60EFFFC */  lwc1      $f14, -4($s0)
/* 3DB8F0 E00E0490 C60C0008 */  lwc1      $f12, 8($s0)
/* 3DB8F4 E00E0494 460E6301 */  sub.s     $f12, $f12, $f14
/* 3DB8F8 E00E0498 46006321 */  cvt.d.s   $f12, $f12
/* 3DB8FC E00E049C 46366302 */  mul.d     $f12, $f12, $f22
/* 3DB900 E00E04A0 00000000 */  nop       
/* 3DB904 E00E04A4 C6060000 */  lwc1      $f6, ($s0)
/* 3DB908 E00E04A8 C608000C */  lwc1      $f8, 0xc($s0)
/* 3DB90C E00E04AC 46064201 */  sub.s     $f8, $f8, $f6
/* 3DB910 E00E04B0 46004221 */  cvt.d.s   $f8, $f8
/* 3DB914 E00E04B4 46364202 */  mul.d     $f8, $f8, $f22
/* 3DB918 E00E04B8 00000000 */  nop       
/* 3DB91C E00E04BC 8E020018 */  lw        $v0, 0x18($s0)
/* 3DB920 E00E04C0 C600FFB8 */  lwc1      $f0, -0x48($s0)
/* 3DB924 E00E04C4 C612FFBC */  lwc1      $f18, -0x44($s0)
/* 3DB928 E00E04C8 00021080 */  sll       $v0, $v0, 2
/* 3DB92C E00E04CC 00531021 */  addu      $v0, $v0, $s3
/* 3DB930 E00E04D0 46008086 */  mov.s     $f2, $f16
/* 3DB934 E00E04D4 C4440000 */  lwc1      $f4, ($v0)
/* 3DB938 E00E04D8 46020000 */  add.s     $f0, $f0, $f2
/* 3DB93C E00E04DC C6020010 */  lwc1      $f2, 0x10($s0)
/* 3DB940 E00E04E0 46008421 */  cvt.d.s   $f16, $f16
/* 3DB944 E00E04E4 E604FFF4 */  swc1      $f4, -0xc($s0)
/* 3DB948 E00E04E8 E600FFB8 */  swc1      $f0, -0x48($s0)
/* 3DB94C E00E04EC 46007006 */  mov.s     $f0, $f14
/* 3DB950 E00E04F0 46009480 */  add.s     $f18, $f18, $f0
/* 3DB954 E00E04F4 C604FFC0 */  lwc1      $f4, -0x40($s0)
/* 3DB958 E00E04F8 46003006 */  mov.s     $f0, $f6
/* 3DB95C E00E04FC 46002100 */  add.s     $f4, $f4, $f0
/* 3DB960 E00E0500 3C01E00E */  lui       $at, %hi(D_E00E0AD0)
/* 3DB964 E00E0504 D4200AD0 */  ldc1      $f0, %lo(D_E00E0AD0)($at)
/* 3DB968 E00E0508 460010A1 */  cvt.d.s   $f2, $f2
/* 3DB96C E00E050C 46201080 */  add.d     $f2, $f2, $f0
/* 3DB970 E00E0510 C6000014 */  lwc1      $f0, 0x14($s0)
/* 3DB974 E00E0514 460073A1 */  cvt.d.s   $f14, $f14
/* 3DB978 E00E0518 E604FFC0 */  swc1      $f4, -0x40($s0)
/* 3DB97C E00E051C 3C01E00E */  lui       $at, %hi(D_E00E0AD8)
/* 3DB980 E00E0520 D4240AD8 */  ldc1      $f4, %lo(D_E00E0AD8)($at)
/* 3DB984 E00E0524 46000021 */  cvt.d.s   $f0, $f0
/* 3DB988 E00E0528 46240000 */  add.d     $f0, $f0, $f4
/* 3DB98C E00E052C 460031A1 */  cvt.d.s   $f6, $f6
/* 3DB990 E00E0530 E612FFBC */  swc1      $f18, -0x44($s0)
/* 3DB994 E00E0534 462A8400 */  add.d     $f16, $f16, $f10
/* 3DB998 E00E0538 462010A0 */  cvt.s.d   $f2, $f2
/* 3DB99C E00E053C E6020010 */  swc1      $f2, 0x10($s0)
/* 3DB9A0 E00E0540 462C7380 */  add.d     $f14, $f14, $f12
/* 3DB9A4 E00E0544 46200020 */  cvt.s.d   $f0, $f0
/* 3DB9A8 E00E0548 E6000014 */  swc1      $f0, 0x14($s0)
/* 3DB9AC E00E054C 46283180 */  add.d     $f6, $f6, $f8
/* 3DB9B0 E00E0550 46208420 */  cvt.s.d   $f16, $f16
/* 3DB9B4 E00E0554 462073A0 */  cvt.s.d   $f14, $f14
/* 3DB9B8 E00E0558 462031A0 */  cvt.s.d   $f6, $f6
/* 3DB9BC E00E055C E610FFF8 */  swc1      $f16, -8($s0)
/* 3DB9C0 E00E0560 E60EFFFC */  swc1      $f14, -4($s0)
/* 3DB9C4 E00E0564 E6060000 */  swc1      $f6, ($s0)
/* 3DB9C8 E00E0568 26310001 */  addiu     $s1, $s1, 1
.LE00E056C:
/* 3DB9CC E00E056C 8E420008 */  lw        $v0, 8($s2)
/* 3DB9D0 E00E0570 0222102A */  slt       $v0, $s1, $v0
/* 3DB9D4 E00E0574 1440FF5D */  bnez      $v0, .LE00E02EC
/* 3DB9D8 E00E0578 26100070 */   addiu    $s0, $s0, 0x70
.LE00E057C:
/* 3DB9DC E00E057C 8FBF0028 */  lw        $ra, 0x28($sp)
/* 3DB9E0 E00E0580 8FB30024 */  lw        $s3, 0x24($sp)
/* 3DB9E4 E00E0584 8FB20020 */  lw        $s2, 0x20($sp)
/* 3DB9E8 E00E0588 8FB1001C */  lw        $s1, 0x1c($sp)
/* 3DB9EC E00E058C 8FB00018 */  lw        $s0, 0x18($sp)
/* 3DB9F0 E00E0590 D7BE0058 */  ldc1      $f30, 0x58($sp)
/* 3DB9F4 E00E0594 D7BC0050 */  ldc1      $f28, 0x50($sp)
/* 3DB9F8 E00E0598 D7BA0048 */  ldc1      $f26, 0x48($sp)
/* 3DB9FC E00E059C D7B80040 */  ldc1      $f24, 0x40($sp)
/* 3DBA00 E00E05A0 D7B60038 */  ldc1      $f22, 0x38($sp)
/* 3DBA04 E00E05A4 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 3DBA08 E00E05A8 03E00008 */  jr        $ra
/* 3DBA0C E00E05AC 27BD0060 */   addiu    $sp, $sp, 0x60
