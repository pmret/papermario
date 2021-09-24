.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00BC374
/* 3BA3A4 E00BC374 27BDFF08 */  addiu     $sp, $sp, -0xf8
/* 3BA3A8 E00BC378 0080482D */  daddu     $t1, $a0, $zero
/* 3BA3AC E00BC37C 3C0ADB06 */  lui       $t2, 0xdb06
/* 3BA3B0 E00BC380 354A0024 */  ori       $t2, $t2, 0x24
/* 3BA3B4 E00BC384 27A40010 */  addiu     $a0, $sp, 0x10
/* 3BA3B8 E00BC388 AFB400B0 */  sw        $s4, 0xb0($sp)
/* 3BA3BC E00BC38C 3C140001 */  lui       $s4, 1
/* 3BA3C0 E00BC390 36941630 */  ori       $s4, $s4, 0x1630
/* 3BA3C4 E00BC394 AFB100A4 */  sw        $s1, 0xa4($sp)
/* 3BA3C8 E00BC398 3C11800A */  lui       $s1, %hi(gMasterGfxPos)
/* 3BA3CC E00BC39C 2631A66C */  addiu     $s1, $s1, %lo(gMasterGfxPos)
/* 3BA3D0 E00BC3A0 3C013DCC */  lui       $at, 0x3dcc
/* 3BA3D4 E00BC3A4 3421CCCD */  ori       $at, $at, 0xcccd
/* 3BA3D8 E00BC3A8 44810000 */  mtc1      $at, $f0
/* 3BA3DC E00BC3AC 3C02E700 */  lui       $v0, 0xe700
/* 3BA3E0 E00BC3B0 AFBF00C4 */  sw        $ra, 0xc4($sp)
/* 3BA3E4 E00BC3B4 AFBE00C0 */  sw        $fp, 0xc0($sp)
/* 3BA3E8 E00BC3B8 AFB700BC */  sw        $s7, 0xbc($sp)
/* 3BA3EC E00BC3BC AFB600B8 */  sw        $s6, 0xb8($sp)
/* 3BA3F0 E00BC3C0 AFB500B4 */  sw        $s5, 0xb4($sp)
/* 3BA3F4 E00BC3C4 AFB300AC */  sw        $s3, 0xac($sp)
/* 3BA3F8 E00BC3C8 AFB200A8 */  sw        $s2, 0xa8($sp)
/* 3BA3FC E00BC3CC AFB000A0 */  sw        $s0, 0xa0($sp)
/* 3BA400 E00BC3D0 F7BE00F0 */  sdc1      $f30, 0xf0($sp)
/* 3BA404 E00BC3D4 F7BC00E8 */  sdc1      $f28, 0xe8($sp)
/* 3BA408 E00BC3D8 F7BA00E0 */  sdc1      $f26, 0xe0($sp)
/* 3BA40C E00BC3DC F7B800D8 */  sdc1      $f24, 0xd8($sp)
/* 3BA410 E00BC3E0 F7B600D0 */  sdc1      $f22, 0xd0($sp)
/* 3BA414 E00BC3E4 F7B400C8 */  sdc1      $f20, 0xc8($sp)
/* 3BA418 E00BC3E8 8E280000 */  lw        $t0, ($s1)
/* 3BA41C E00BC3EC 8D35000C */  lw        $s5, 0xc($t1)
/* 3BA420 E00BC3F0 0100182D */  daddu     $v1, $t0, $zero
/* 3BA424 E00BC3F4 44050000 */  mfc1      $a1, $f0
/* 3BA428 E00BC3F8 25080008 */  addiu     $t0, $t0, 8
/* 3BA42C E00BC3FC AE280000 */  sw        $t0, ($s1)
/* 3BA430 E00BC400 8EB7002C */  lw        $s7, 0x2c($s5)
/* 3BA434 E00BC404 8EB3003C */  lw        $s3, 0x3c($s5)
/* 3BA438 E00BC408 8EB60000 */  lw        $s6, ($s5)
/* 3BA43C E00BC40C C6B0004C */  lwc1      $f16, 0x4c($s5)
/* 3BA440 E00BC410 00A0302D */  daddu     $a2, $a1, $zero
/* 3BA444 E00BC414 00A0382D */  daddu     $a3, $a1, $zero
/* 3BA448 E00BC418 E7B00094 */  swc1      $f16, 0x94($sp)
/* 3BA44C E00BC41C AC620000 */  sw        $v0, ($v1)
/* 3BA450 E00BC420 AC600004 */  sw        $zero, 4($v1)
/* 3BA454 E00BC424 AD0A0000 */  sw        $t2, ($t0)
/* 3BA458 E00BC428 8D230010 */  lw        $v1, 0x10($t1)
/* 3BA45C E00BC42C 25020008 */  addiu     $v0, $t0, 8
/* 3BA460 E00BC430 AE220000 */  sw        $v0, ($s1)
/* 3BA464 E00BC434 8C62001C */  lw        $v0, 0x1c($v1)
/* 3BA468 E00BC438 3C038000 */  lui       $v1, 0x8000
/* 3BA46C E00BC43C 00431021 */  addu      $v0, $v0, $v1
/* 3BA470 E00BC440 0C080110 */  jal       shim_guScaleF
/* 3BA474 E00BC444 AD020004 */   sw       $v0, 4($t0)
/* 3BA478 E00BC448 27A40010 */  addiu     $a0, $sp, 0x10
/* 3BA47C E00BC44C 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* 3BA480 E00BC450 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* 3BA484 E00BC454 3C12800A */  lui       $s2, %hi(gDisplayContext)
/* 3BA488 E00BC458 2652A674 */  addiu     $s2, $s2, %lo(gDisplayContext)
/* 3BA48C E00BC45C 96050000 */  lhu       $a1, ($s0)
/* 3BA490 E00BC460 8E420000 */  lw        $v0, ($s2)
/* 3BA494 E00BC464 00052980 */  sll       $a1, $a1, 6
/* 3BA498 E00BC468 00B42821 */  addu      $a1, $a1, $s4
/* 3BA49C E00BC46C 0C080118 */  jal       shim_guMtxF2L
/* 3BA4A0 E00BC470 00452821 */   addu     $a1, $v0, $a1
/* 3BA4A4 E00BC474 3C03DA38 */  lui       $v1, 0xda38
/* 3BA4A8 E00BC478 34630002 */  ori       $v1, $v1, 2
/* 3BA4AC E00BC47C 327300FF */  andi      $s3, $s3, 0xff
/* 3BA4B0 E00BC480 8E260000 */  lw        $a2, ($s1)
/* 3BA4B4 E00BC484 96020000 */  lhu       $v0, ($s0)
/* 3BA4B8 E00BC488 00C0202D */  daddu     $a0, $a2, $zero
/* 3BA4BC E00BC48C 24C60008 */  addiu     $a2, $a2, 8
/* 3BA4C0 E00BC490 AE260000 */  sw        $a2, ($s1)
/* 3BA4C4 E00BC494 AC830000 */  sw        $v1, ($a0)
/* 3BA4C8 E00BC498 24430001 */  addiu     $v1, $v0, 1
/* 3BA4CC E00BC49C 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3BA4D0 E00BC4A0 00021180 */  sll       $v0, $v0, 6
/* 3BA4D4 E00BC4A4 A6030000 */  sh        $v1, ($s0)
/* 3BA4D8 E00BC4A8 8E430000 */  lw        $v1, ($s2)
/* 3BA4DC E00BC4AC 00541021 */  addu      $v0, $v0, $s4
/* 3BA4E0 E00BC4B0 00621821 */  addu      $v1, $v1, $v0
/* 3BA4E4 E00BC4B4 24C20008 */  addiu     $v0, $a2, 8
/* 3BA4E8 E00BC4B8 AC830004 */  sw        $v1, 4($a0)
/* 3BA4EC E00BC4BC AE220000 */  sw        $v0, ($s1)
/* 3BA4F0 E00BC4C0 3C02FA00 */  lui       $v0, 0xfa00
/* 3BA4F4 E00BC4C4 ACC20000 */  sw        $v0, ($a2)
/* 3BA4F8 E00BC4C8 92A20033 */  lbu       $v0, 0x33($s5)
/* 3BA4FC E00BC4CC 92A40037 */  lbu       $a0, 0x37($s5)
/* 3BA500 E00BC4D0 92A5003B */  lbu       $a1, 0x3b($s5)
/* 3BA504 E00BC4D4 24C30010 */  addiu     $v1, $a2, 0x10
/* 3BA508 E00BC4D8 AE230000 */  sw        $v1, ($s1)
/* 3BA50C E00BC4DC 3C03FB00 */  lui       $v1, 0xfb00
/* 3BA510 E00BC4E0 ACC30008 */  sw        $v1, 8($a2)
/* 3BA514 E00BC4E4 00021600 */  sll       $v0, $v0, 0x18
/* 3BA518 E00BC4E8 00042400 */  sll       $a0, $a0, 0x10
/* 3BA51C E00BC4EC 00441025 */  or        $v0, $v0, $a0
/* 3BA520 E00BC4F0 00052A00 */  sll       $a1, $a1, 8
/* 3BA524 E00BC4F4 00451025 */  or        $v0, $v0, $a1
/* 3BA528 E00BC4F8 00531025 */  or        $v0, $v0, $s3
/* 3BA52C E00BC4FC ACC20004 */  sw        $v0, 4($a2)
/* 3BA530 E00BC500 92A20043 */  lbu       $v0, 0x43($s5)
/* 3BA534 E00BC504 92A40047 */  lbu       $a0, 0x47($s5)
/* 3BA538 E00BC508 92A5004B */  lbu       $a1, 0x4b($s5)
/* 3BA53C E00BC50C 24C30018 */  addiu     $v1, $a2, 0x18
/* 3BA540 E00BC510 AE230000 */  sw        $v1, ($s1)
/* 3BA544 E00BC514 3C03DE00 */  lui       $v1, 0xde00
/* 3BA548 E00BC518 ACC30010 */  sw        $v1, 0x10($a2)
/* 3BA54C E00BC51C 3C030900 */  lui       $v1, 0x900
/* 3BA550 E00BC520 24631000 */  addiu     $v1, $v1, 0x1000
/* 3BA554 E00BC524 ACC30014 */  sw        $v1, 0x14($a2)
/* 3BA558 E00BC528 00021600 */  sll       $v0, $v0, 0x18
/* 3BA55C E00BC52C 00042400 */  sll       $a0, $a0, 0x10
/* 3BA560 E00BC530 00441025 */  or        $v0, $v0, $a0
/* 3BA564 E00BC534 00052A00 */  sll       $a1, $a1, 8
/* 3BA568 E00BC538 00451025 */  or        $v0, $v0, $a1
/* 3BA56C E00BC53C 34420080 */  ori       $v0, $v0, 0x80
/* 3BA570 E00BC540 ACC2000C */  sw        $v0, 0xc($a2)
/* 3BA574 E00BC544 24020002 */  addiu     $v0, $zero, 2
/* 3BA578 E00BC548 12C20011 */  beq       $s6, $v0, .LE00BC590
/* 3BA57C E00BC54C 26E4FFFF */   addiu    $a0, $s7, -1
/* 3BA580 E00BC550 2882000B */  slti      $v0, $a0, 0xb
/* 3BA584 E00BC554 10400009 */  beqz      $v0, .LE00BC57C
/* 3BA588 E00BC558 00161080 */   sll      $v0, $s6, 2
/* 3BA58C E00BC55C 00041840 */  sll       $v1, $a0, 1
/* 3BA590 E00BC560 00641821 */  addu      $v1, $v1, $a0
/* 3BA594 E00BC564 3C01E00C */  lui       $at, %hi(D_E00BCE40)
/* 3BA598 E00BC568 00220821 */  addu      $at, $at, $v0
/* 3BA59C E00BC56C 8C22CE40 */  lw        $v0, %lo(D_E00BCE40)($at)
/* 3BA5A0 E00BC570 000318C0 */  sll       $v1, $v1, 3
/* 3BA5A4 E00BC574 0802F184 */  j         .LE00BC610
/* 3BA5A8 E00BC578 00439021 */   addu     $s2, $v0, $v1
.LE00BC57C:
/* 3BA5AC E00BC57C 3C01E00C */  lui       $at, %hi(D_E00BCE40)
/* 3BA5B0 E00BC580 00220821 */  addu      $at, $at, $v0
/* 3BA5B4 E00BC584 8C22CE40 */  lw        $v0, %lo(D_E00BCE40)($at)
/* 3BA5B8 E00BC588 0802F184 */  j         .LE00BC610
/* 3BA5BC E00BC58C 245200F0 */   addiu    $s2, $v0, 0xf0
.LE00BC590:
/* 3BA5C0 E00BC590 28820008 */  slti      $v0, $a0, 8
/* 3BA5C4 E00BC594 10400007 */  beqz      $v0, .LE00BC5B4
/* 3BA5C8 E00BC598 00041040 */   sll      $v0, $a0, 1
/* 3BA5CC E00BC59C 00441021 */  addu      $v0, $v0, $a0
/* 3BA5D0 E00BC5A0 3C03E00C */  lui       $v1, %hi(D_E00BCE40)
/* 3BA5D4 E00BC5A4 8C63CE40 */  lw        $v1, %lo(D_E00BCE40)($v1)
/* 3BA5D8 E00BC5A8 000210C0 */  sll       $v0, $v0, 3
/* 3BA5DC E00BC5AC 0802F184 */  j         .LE00BC610
/* 3BA5E0 E00BC5B0 00629021 */   addu     $s2, $v1, $v0
.LE00BC5B4:
/* 3BA5E4 E00BC5B4 28820024 */  slti      $v0, $a0, 0x24
/* 3BA5E8 E00BC5B8 10400012 */  beqz      $v0, .LE00BC604
/* 3BA5EC E00BC5BC 3C022AAA */   lui      $v0, 0x2aaa
/* 3BA5F0 E00BC5C0 3442AAAB */  ori       $v0, $v0, 0xaaab
/* 3BA5F4 E00BC5C4 00820018 */  mult      $a0, $v0
/* 3BA5F8 E00BC5C8 00041FC3 */  sra       $v1, $a0, 0x1f
/* 3BA5FC E00BC5CC 00007010 */  mfhi      $t6
/* 3BA600 E00BC5D0 01C31823 */  subu      $v1, $t6, $v1
/* 3BA604 E00BC5D4 00031040 */  sll       $v0, $v1, 1
/* 3BA608 E00BC5D8 00431021 */  addu      $v0, $v0, $v1
/* 3BA60C E00BC5DC 00021040 */  sll       $v0, $v0, 1
/* 3BA610 E00BC5E0 00821023 */  subu      $v0, $a0, $v0
/* 3BA614 E00BC5E4 00021840 */  sll       $v1, $v0, 1
/* 3BA618 E00BC5E8 00621821 */  addu      $v1, $v1, $v0
/* 3BA61C E00BC5EC 000318C0 */  sll       $v1, $v1, 3
/* 3BA620 E00BC5F0 3C02E00C */  lui       $v0, %hi(D_E00BCE40)
/* 3BA624 E00BC5F4 8C42CE40 */  lw        $v0, %lo(D_E00BCE40)($v0)
/* 3BA628 E00BC5F8 24630030 */  addiu     $v1, $v1, 0x30
/* 3BA62C E00BC5FC 0802F184 */  j         .LE00BC610
/* 3BA630 E00BC600 00439021 */   addu     $s2, $v0, $v1
.LE00BC604:
/* 3BA634 E00BC604 3C02E00C */  lui       $v0, %hi(D_E00BCE40)
/* 3BA638 E00BC608 8C42CE40 */  lw        $v0, %lo(D_E00BCE40)($v0)
/* 3BA63C E00BC60C 245200F0 */  addiu     $s2, $v0, 0xf0
.LE00BC610:
/* 3BA640 E00BC610 0000982D */  daddu     $s3, $zero, $zero
/* 3BA644 E00BC614 02A0882D */  daddu     $s1, $s5, $zero
/* 3BA648 E00BC618 3C013DBA */  lui       $at, 0x3dba
/* 3BA64C E00BC61C 34212E8C */  ori       $at, $at, 0x2e8c
/* 3BA650 E00BC620 4481F000 */  mtc1      $at, $f30
.LE00BC624:
/* 3BA654 E00BC624 3C058888 */  lui       $a1, 0x8888
/* 3BA658 E00BC628 34A58889 */  ori       $a1, $a1, 0x8889
/* 3BA65C E00BC62C 02771823 */  subu      $v1, $s3, $s7
/* 3BA660 E00BC630 00031080 */  sll       $v0, $v1, 2
/* 3BA664 E00BC634 00431021 */  addu      $v0, $v0, $v1
/* 3BA668 E00BC638 8EA40110 */  lw        $a0, 0x110($s5)
/* 3BA66C E00BC63C 00021040 */  sll       $v0, $v0, 1
/* 3BA670 E00BC640 00822021 */  addu      $a0, $a0, $v0
/* 3BA674 E00BC644 00850018 */  mult      $a0, $a1
/* 3BA678 E00BC648 C6B8001C */  lwc1      $f24, 0x1c($s5)
/* 3BA67C E00BC64C C6A00010 */  lwc1      $f0, 0x10($s5)
/* 3BA680 E00BC650 4600C601 */  sub.s     $f24, $f24, $f0
/* 3BA684 E00BC654 461EC602 */  mul.s     $f24, $f24, $f30
/* 3BA688 E00BC658 00000000 */  nop
/* 3BA68C E00BC65C C6B60020 */  lwc1      $f22, 0x20($s5)
/* 3BA690 E00BC660 C6A00014 */  lwc1      $f0, 0x14($s5)
/* 3BA694 E00BC664 4600B581 */  sub.s     $f22, $f22, $f0
/* 3BA698 E00BC668 461EB582 */  mul.s     $f22, $f22, $f30
/* 3BA69C E00BC66C 00000000 */  nop
/* 3BA6A0 E00BC670 02538021 */  addu      $s0, $s2, $s3
/* 3BA6A4 E00BC674 000417C3 */  sra       $v0, $a0, 0x1f
/* 3BA6A8 E00BC678 00007010 */  mfhi      $t6
/* 3BA6AC E00BC67C 01C41821 */  addu      $v1, $t6, $a0
/* 3BA6B0 E00BC680 00031983 */  sra       $v1, $v1, 6
/* 3BA6B4 E00BC684 00621823 */  subu      $v1, $v1, $v0
/* 3BA6B8 E00BC688 00031100 */  sll       $v0, $v1, 4
/* 3BA6BC E00BC68C 00431023 */  subu      $v0, $v0, $v1
/* 3BA6C0 E00BC690 000210C0 */  sll       $v0, $v0, 3
/* 3BA6C4 E00BC694 00822023 */  subu      $a0, $a0, $v0
/* 3BA6C8 E00BC698 2484FFC4 */  addiu     $a0, $a0, -0x3c
/* 3BA6CC E00BC69C 4484E000 */  mtc1      $a0, $f28
/* 3BA6D0 E00BC6A0 00000000 */  nop
/* 3BA6D4 E00BC6A4 4680E720 */  cvt.s.w   $f28, $f28
/* 3BA6D8 E00BC6A8 92020000 */  lbu       $v0, ($s0)
/* 3BA6DC E00BC6AC 4482D000 */  mtc1      $v0, $f26
/* 3BA6E0 E00BC6B0 00000000 */  nop
/* 3BA6E4 E00BC6B4 4680D6A0 */  cvt.s.w   $f26, $f26
/* 3BA6E8 E00BC6B8 0C080140 */  jal       shim_sin_deg
/* 3BA6EC E00BC6BC 4600E306 */   mov.s    $f12, $f28
/* 3BA6F0 E00BC6C0 461A0502 */  mul.s     $f20, $f0, $f26
/* 3BA6F4 E00BC6C4 00000000 */  nop
/* 3BA6F8 E00BC6C8 3C01E00C */  lui       $at, %hi(D_E00BCE58)
/* 3BA6FC E00BC6CC D430CE58 */  ldc1      $f16, %lo(D_E00BCE58)($at)
/* 3BA700 E00BC6D0 4600A521 */  cvt.d.s   $f20, $f20
/* 3BA704 E00BC6D4 4630A502 */  mul.d     $f20, $f20, $f16
/* 3BA708 E00BC6D8 00000000 */  nop
/* 3BA70C E00BC6DC 4600E306 */  mov.s     $f12, $f28
/* 3BA710 E00BC6E0 0C080144 */  jal       shim_cos_deg
/* 3BA714 E00BC6E4 4620A520 */   cvt.s.d  $f20, $f20
/* 3BA718 E00BC6E8 461A0002 */  mul.s     $f0, $f0, $f26
/* 3BA71C E00BC6EC 00000000 */  nop
/* 3BA720 E00BC6F0 3C01E00C */  lui       $at, %hi(D_E00BCE60)
/* 3BA724 E00BC6F4 D430CE60 */  ldc1      $f16, %lo(D_E00BCE60)($at)
/* 3BA728 E00BC6F8 46000021 */  cvt.d.s   $f0, $f0
/* 3BA72C E00BC6FC 46300002 */  mul.d     $f0, $f0, $f16
/* 3BA730 E00BC700 00000000 */  nop
/* 3BA734 E00BC704 4614B182 */  mul.s     $f6, $f22, $f20
/* 3BA738 E00BC708 00000000 */  nop
/* 3BA73C E00BC70C C6A2001C */  lwc1      $f2, 0x1c($s5)
/* 3BA740 E00BC710 C6A40010 */  lwc1      $f4, 0x10($s5)
/* 3BA744 E00BC714 46041081 */  sub.s     $f2, $f2, $f4
/* 3BA748 E00BC718 44935000 */  mtc1      $s3, $f10
/* 3BA74C E00BC71C 00000000 */  nop
/* 3BA750 E00BC720 468052A0 */  cvt.s.w   $f10, $f10
/* 3BA754 E00BC724 460A1082 */  mul.s     $f2, $f2, $f10
/* 3BA758 E00BC728 00000000 */  nop
/* 3BA75C E00BC72C 461E1082 */  mul.s     $f2, $f2, $f30
/* 3BA760 E00BC730 00000000 */  nop
/* 3BA764 E00BC734 46200020 */  cvt.s.d   $f0, $f0
/* 3BA768 E00BC738 4600C202 */  mul.s     $f8, $f24, $f0
/* 3BA76C E00BC73C 00000000 */  nop
/* 3BA770 E00BC740 4614C602 */  mul.s     $f24, $f24, $f20
/* 3BA774 E00BC744 00000000 */  nop
/* 3BA778 E00BC748 46022100 */  add.s     $f4, $f4, $f2
/* 3BA77C E00BC74C 46064201 */  sub.s     $f8, $f8, $f6
/* 3BA780 E00BC750 46082100 */  add.s     $f4, $f4, $f8
/* 3BA784 E00BC754 4600B582 */  mul.s     $f22, $f22, $f0
/* 3BA788 E00BC758 00000000 */  nop
/* 3BA78C E00BC75C E6240050 */  swc1      $f4, 0x50($s1)
/* 3BA790 E00BC760 C6A20020 */  lwc1      $f2, 0x20($s5)
/* 3BA794 E00BC764 C6A40014 */  lwc1      $f4, 0x14($s5)
/* 3BA798 E00BC768 46041081 */  sub.s     $f2, $f2, $f4
/* 3BA79C E00BC76C 460A1082 */  mul.s     $f2, $f2, $f10
/* 3BA7A0 E00BC770 00000000 */  nop
/* 3BA7A4 E00BC774 461E1082 */  mul.s     $f2, $f2, $f30
/* 3BA7A8 E00BC778 00000000 */  nop
/* 3BA7AC E00BC77C 4616C600 */  add.s     $f24, $f24, $f22
/* 3BA7B0 E00BC780 46022100 */  add.s     $f4, $f4, $f2
/* 3BA7B4 E00BC784 46182100 */  add.s     $f4, $f4, $f24
/* 3BA7B8 E00BC788 E6240080 */  swc1      $f4, 0x80($s1)
/* 3BA7BC E00BC78C C6A00024 */  lwc1      $f0, 0x24($s5)
/* 3BA7C0 E00BC790 C6A20018 */  lwc1      $f2, 0x18($s5)
/* 3BA7C4 E00BC794 46020001 */  sub.s     $f0, $f0, $f2
/* 3BA7C8 E00BC798 460A0002 */  mul.s     $f0, $f0, $f10
/* 3BA7CC E00BC79C 00000000 */  nop
/* 3BA7D0 E00BC7A0 461E0002 */  mul.s     $f0, $f0, $f30
/* 3BA7D4 E00BC7A4 00000000 */  nop
/* 3BA7D8 E00BC7A8 46001080 */  add.s     $f2, $f2, $f0
/* 3BA7DC E00BC7AC 44808000 */  mtc1      $zero, $f16
/* 3BA7E0 E00BC7B0 00000000 */  nop
/* 3BA7E4 E00BC7B4 46101080 */  add.s     $f2, $f2, $f16
/* 3BA7E8 E00BC7B8 E62200B0 */  swc1      $f2, 0xb0($s1)
/* 3BA7EC E00BC7BC 9202000C */  lbu       $v0, 0xc($s0)
/* 3BA7F0 E00BC7C0 3C01E00C */  lui       $at, %hi(D_E00BCE68)
/* 3BA7F4 E00BC7C4 D422CE68 */  ldc1      $f2, %lo(D_E00BCE68)($at)
/* 3BA7F8 E00BC7C8 44820000 */  mtc1      $v0, $f0
/* 3BA7FC E00BC7CC 00000000 */  nop
/* 3BA800 E00BC7D0 46800020 */  cvt.s.w   $f0, $f0
/* 3BA804 E00BC7D4 46000021 */  cvt.d.s   $f0, $f0
/* 3BA808 E00BC7D8 46220002 */  mul.d     $f0, $f0, $f2
/* 3BA80C E00BC7DC 00000000 */  nop
/* 3BA810 E00BC7E0 26730001 */  addiu     $s3, $s3, 1
/* 3BA814 E00BC7E4 2A62000C */  slti      $v0, $s3, 0xc
/* 3BA818 E00BC7E8 46200020 */  cvt.s.d   $f0, $f0
/* 3BA81C E00BC7EC E62000E0 */  swc1      $f0, 0xe0($s1)
/* 3BA820 E00BC7F0 1440FF8C */  bnez      $v0, .LE00BC624
/* 3BA824 E00BC7F4 26310004 */   addiu    $s1, $s1, 4
/* 3BA828 E00BC7F8 0000982D */  daddu     $s3, $zero, $zero
/* 3BA82C E00BC7FC 0260F02D */  daddu     $fp, $s3, $zero
/* 3BA830 E00BC800 0260B82D */  daddu     $s7, $s3, $zero
/* 3BA834 E00BC804 0260B02D */  daddu     $s6, $s3, $zero
/* 3BA838 E00BC808 02A0902D */  daddu     $s2, $s5, $zero
/* 3BA83C E00BC80C 46008706 */  mov.s     $f28, $f16
/* 3BA840 E00BC810 3C04800A */  lui       $a0, %hi(gMasterGfxPos)
/* 3BA844 E00BC814 2484A66C */  addiu     $a0, $a0, %lo(gMasterGfxPos)
/* 3BA848 E00BC818 3C0143B4 */  lui       $at, 0x43b4
/* 3BA84C E00BC81C 4481F000 */  mtc1      $at, $f30
/* 3BA850 E00BC820 3C02DE01 */  lui       $v0, 0xde01
/* 3BA854 E00BC824 AFA00098 */  sw        $zero, 0x98($sp)
/* 3BA858 E00BC828 8C830000 */  lw        $v1, ($a0)
/* 3BA85C E00BC82C 3C014120 */  lui       $at, 0x4120
/* 3BA860 E00BC830 4481D000 */  mtc1      $at, $f26
/* 3BA864 E00BC834 246E0008 */  addiu     $t6, $v1, 8
/* 3BA868 E00BC838 01C0A02D */  daddu     $s4, $t6, $zero
/* 3BA86C E00BC83C 24710016 */  addiu     $s1, $v1, 0x16
/* 3BA870 E00BC840 AFAE0090 */  sw        $t6, 0x90($sp)
/* 3BA874 E00BC844 AC620000 */  sw        $v0, ($v1)
/* 3BA878 E00BC848 24620188 */  addiu     $v0, $v1, 0x188
/* 3BA87C E00BC84C AC620004 */  sw        $v0, 4($v1)
/* 3BA880 E00BC850 AC820000 */  sw        $v0, ($a0)
.LE00BC854:
/* 3BA884 E00BC854 1660000D */  bnez      $s3, .LE00BC88C
/* 3BA888 E00BC858 2402000B */   addiu    $v0, $zero, 0xb
/* 3BA88C E00BC85C 3C014100 */  lui       $at, 0x4100
/* 3BA890 E00BC860 4481C000 */  mtc1      $at, $f24
/* 3BA894 E00BC864 C6AC0084 */  lwc1      $f12, 0x84($s5)
/* 3BA898 E00BC868 8EA60080 */  lw        $a2, 0x80($s5)
/* 3BA89C E00BC86C C6A00050 */  lwc1      $f0, 0x50($s5)
/* 3BA8A0 E00BC870 C6AE0054 */  lwc1      $f14, 0x54($s5)
/* 3BA8A4 E00BC874 46000007 */  neg.s     $f0, $f0
/* 3BA8A8 E00BC878 44070000 */  mfc1      $a3, $f0
/* 3BA8AC E00BC87C 0C080148 */  jal       shim_atan2
/* 3BA8B0 E00BC880 46007387 */   neg.s    $f14, $f14
/* 3BA8B4 E00BC884 0802F25B */  j         .LE00BC96C
/* 3BA8B8 E00BC888 46000587 */   neg.s    $f22, $f0
.LE00BC88C:
/* 3BA8BC E00BC88C 3C014100 */  lui       $at, 0x4100
/* 3BA8C0 E00BC890 4481C000 */  mtc1      $at, $f24
/* 3BA8C4 E00BC894 16620005 */  bne       $s3, $v0, .LE00BC8AC
/* 3BA8C8 E00BC898 26620001 */   addiu    $v0, $s3, 1
/* 3BA8CC E00BC89C 3C01C2B4 */  lui       $at, 0xc2b4
/* 3BA8D0 E00BC8A0 4481B000 */  mtc1      $at, $f22
/* 3BA8D4 E00BC8A4 0802F25B */  j         .LE00BC96C
/* 3BA8D8 E00BC8A8 00000000 */   nop
.LE00BC8AC:
/* 3BA8DC E00BC8AC 00021080 */  sll       $v0, $v0, 2
/* 3BA8E0 E00BC8B0 02A21021 */  addu      $v0, $s5, $v0
/* 3BA8E4 E00BC8B4 C44C0080 */  lwc1      $f12, 0x80($v0)
/* 3BA8E8 E00BC8B8 8E460080 */  lw        $a2, 0x80($s2)
/* 3BA8EC E00BC8BC C6400050 */  lwc1      $f0, 0x50($s2)
/* 3BA8F0 E00BC8C0 C44E0050 */  lwc1      $f14, 0x50($v0)
/* 3BA8F4 E00BC8C4 46000007 */  neg.s     $f0, $f0
/* 3BA8F8 E00BC8C8 44070000 */  mfc1      $a3, $f0
/* 3BA8FC E00BC8CC 0C080148 */  jal       shim_atan2
/* 3BA900 E00BC8D0 46007387 */   neg.s    $f14, $f14
/* 3BA904 E00BC8D4 2662FFFF */  addiu     $v0, $s3, -1
/* 3BA908 E00BC8D8 00021080 */  sll       $v0, $v0, 2
/* 3BA90C E00BC8DC 02A21021 */  addu      $v0, $s5, $v0
/* 3BA910 E00BC8E0 C64C0080 */  lwc1      $f12, 0x80($s2)
/* 3BA914 E00BC8E4 8C460080 */  lw        $a2, 0x80($v0)
/* 3BA918 E00BC8E8 46000507 */  neg.s     $f20, $f0
/* 3BA91C E00BC8EC C4400050 */  lwc1      $f0, 0x50($v0)
/* 3BA920 E00BC8F0 C64E0050 */  lwc1      $f14, 0x50($s2)
/* 3BA924 E00BC8F4 46000007 */  neg.s     $f0, $f0
/* 3BA928 E00BC8F8 44070000 */  mfc1      $a3, $f0
/* 3BA92C E00BC8FC 0C080148 */  jal       shim_atan2
/* 3BA930 E00BC900 46007387 */   neg.s    $f14, $f14
/* 3BA934 E00BC904 46000087 */  neg.s     $f2, $f0
/* 3BA938 E00BC908 46141101 */  sub.s     $f4, $f2, $f20
/* 3BA93C E00BC90C 3C014334 */  lui       $at, 0x4334
/* 3BA940 E00BC910 44810000 */  mtc1      $at, $f0
/* 3BA944 E00BC914 00000000 */  nop
/* 3BA948 E00BC918 4604003C */  c.lt.s    $f0, $f4
/* 3BA94C E00BC91C 00000000 */  nop
/* 3BA950 E00BC920 45000003 */  bc1f      .LE00BC930
/* 3BA954 E00BC924 00000000 */   nop
/* 3BA958 E00BC928 0802F253 */  j         .LE00BC94C
/* 3BA95C E00BC92C 461EA500 */   add.s    $f20, $f20, $f30
.LE00BC930:
/* 3BA960 E00BC930 3C01C334 */  lui       $at, 0xc334
/* 3BA964 E00BC934 44810000 */  mtc1      $at, $f0
/* 3BA968 E00BC938 00000000 */  nop
/* 3BA96C E00BC93C 4600203C */  c.lt.s    $f4, $f0
/* 3BA970 E00BC940 00000000 */  nop
/* 3BA974 E00BC944 45030001 */  bc1tl     .LE00BC94C
/* 3BA978 E00BC948 461E1080 */   add.s    $f2, $f2, $f30
.LE00BC94C:
/* 3BA97C E00BC94C 4602A580 */  add.s     $f22, $f20, $f2
/* 3BA980 E00BC950 3C013FE0 */  lui       $at, 0x3fe0
/* 3BA984 E00BC954 44810800 */  mtc1      $at, $f1
/* 3BA988 E00BC958 44800000 */  mtc1      $zero, $f0
/* 3BA98C E00BC95C 4600B0A1 */  cvt.d.s   $f2, $f22
/* 3BA990 E00BC960 46201082 */  mul.d     $f2, $f2, $f0
/* 3BA994 E00BC964 00000000 */  nop
/* 3BA998 E00BC968 462015A0 */  cvt.s.d   $f22, $f2
.LE00BC96C:
/* 3BA99C E00BC96C C64000E0 */  lwc1      $f0, 0xe0($s2)
/* 3BA9A0 E00BC970 C7B00094 */  lwc1      $f16, 0x94($sp)
/* 3BA9A4 E00BC974 46008002 */  mul.s     $f0, $f16, $f0
/* 3BA9A8 E00BC978 00000000 */  nop
/* 3BA9AC E00BC97C 4600B306 */  mov.s     $f12, $f22
/* 3BA9B0 E00BC980 8FAE0098 */  lw        $t6, 0x98($sp)
/* 3BA9B4 E00BC984 4600C602 */  mul.s     $f24, $f24, $f0
/* 3BA9B8 E00BC988 00000000 */  nop
/* 3BA9BC E00BC98C 24100080 */  addiu     $s0, $zero, 0x80
/* 3BA9C0 E00BC990 020E8023 */  subu      $s0, $s0, $t6
/* 3BA9C4 E00BC994 0C080140 */  jal       shim_sin_deg
/* 3BA9C8 E00BC998 00108140 */   sll      $s0, $s0, 5
/* 3BA9CC E00BC99C 4600C502 */  mul.s     $f20, $f24, $f0
/* 3BA9D0 E00BC9A0 00000000 */  nop
/* 3BA9D4 E00BC9A4 0C080144 */  jal       shim_cos_deg
/* 3BA9D8 E00BC9A8 4600B306 */   mov.s    $f12, $f22
/* 3BA9DC E00BC9AC C6420050 */  lwc1      $f2, 0x50($s2)
/* 3BA9E0 E00BC9B0 46141080 */  add.s     $f2, $f2, $f20
/* 3BA9E4 E00BC9B4 461A1082 */  mul.s     $f2, $f2, $f26
/* 3BA9E8 E00BC9B8 00000000 */  nop
/* 3BA9EC E00BC9BC 4600C002 */  mul.s     $f0, $f24, $f0
/* 3BA9F0 E00BC9C0 00000000 */  nop
/* 3BA9F4 E00BC9C4 4600140D */  trunc.w.s $f16, $f2
/* 3BA9F8 E00BC9C8 44028000 */  mfc1      $v0, $f16
/* 3BA9FC E00BC9CC 00000000 */  nop
/* 3BAA00 E00BC9D0 A6820000 */  sh        $v0, ($s4)
/* 3BAA04 E00BC9D4 C6420080 */  lwc1      $f2, 0x80($s2)
/* 3BAA08 E00BC9D8 46001080 */  add.s     $f2, $f2, $f0
/* 3BAA0C E00BC9DC 461A1082 */  mul.s     $f2, $f2, $f26
/* 3BAA10 E00BC9E0 00000000 */  nop
/* 3BAA14 E00BC9E4 4600140D */  trunc.w.s $f16, $f2
/* 3BAA18 E00BC9E8 44028000 */  mfc1      $v0, $f16
/* 3BAA1C E00BC9EC 00000000 */  nop
/* 3BAA20 E00BC9F0 A622FFF4 */  sh        $v0, -0xc($s1)
/* 3BAA24 E00BC9F4 C64200B0 */  lwc1      $f2, 0xb0($s2)
/* 3BAA28 E00BC9F8 461C1080 */  add.s     $f2, $f2, $f28
/* 3BAA2C E00BC9FC A630FFFA */  sh        $s0, -6($s1)
/* 3BAA30 E00BCA00 461A1082 */  mul.s     $f2, $f2, $f26
/* 3BAA34 E00BCA04 00000000 */  nop
/* 3BAA38 E00BCA08 A620FFFC */  sh        $zero, -4($s1)
/* 3BAA3C E00BCA0C A236FFFE */  sb        $s6, -2($s1)
/* 3BAA40 E00BCA10 A237FFFF */  sb        $s7, -1($s1)
/* 3BAA44 E00BCA14 A23E0000 */  sb        $fp, ($s1)
/* 3BAA48 E00BCA18 4600140D */  trunc.w.s $f16, $f2
/* 3BAA4C E00BCA1C 44028000 */  mfc1      $v0, $f16
/* 3BAA50 E00BCA20 00000000 */  nop
/* 3BAA54 E00BCA24 A622FFF6 */  sh        $v0, -0xa($s1)
/* 3BAA58 E00BCA28 C6420050 */  lwc1      $f2, 0x50($s2)
/* 3BAA5C E00BCA2C 46141081 */  sub.s     $f2, $f2, $f20
/* 3BAA60 E00BCA30 461A1082 */  mul.s     $f2, $f2, $f26
/* 3BAA64 E00BCA34 00000000 */  nop
/* 3BAA68 E00BCA38 26940010 */  addiu     $s4, $s4, 0x10
/* 3BAA6C E00BCA3C 4600140D */  trunc.w.s $f16, $f2
/* 3BAA70 E00BCA40 44028000 */  mfc1      $v0, $f16
/* 3BAA74 E00BCA44 00000000 */  nop
/* 3BAA78 E00BCA48 A6820000 */  sh        $v0, ($s4)
/* 3BAA7C E00BCA4C C6420080 */  lwc1      $f2, 0x80($s2)
/* 3BAA80 E00BCA50 46001081 */  sub.s     $f2, $f2, $f0
/* 3BAA84 E00BCA54 26730001 */  addiu     $s3, $s3, 1
/* 3BAA88 E00BCA58 461A1082 */  mul.s     $f2, $f2, $f26
/* 3BAA8C E00BCA5C 00000000 */  nop
/* 3BAA90 E00BCA60 8FAE0098 */  lw        $t6, 0x98($sp)
/* 3BAA94 E00BCA64 26310010 */  addiu     $s1, $s1, 0x10
/* 3BAA98 E00BCA68 25CE000C */  addiu     $t6, $t6, 0xc
/* 3BAA9C E00BCA6C AFAE0098 */  sw        $t6, 0x98($sp)
/* 3BAAA0 E00BCA70 4600140D */  trunc.w.s $f16, $f2
/* 3BAAA4 E00BCA74 44028000 */  mfc1      $v0, $f16
/* 3BAAA8 E00BCA78 00000000 */  nop
/* 3BAAAC E00BCA7C A622FFF4 */  sh        $v0, -0xc($s1)
/* 3BAAB0 E00BCA80 C64000B0 */  lwc1      $f0, 0xb0($s2)
/* 3BAAB4 E00BCA84 26940010 */  addiu     $s4, $s4, 0x10
/* 3BAAB8 E00BCA88 A23E0000 */  sb        $fp, ($s1)
/* 3BAABC E00BCA8C 27DE001E */  addiu     $fp, $fp, 0x1e
/* 3BAAC0 E00BCA90 A237FFFF */  sb        $s7, -1($s1)
/* 3BAAC4 E00BCA94 26F70078 */  addiu     $s7, $s7, 0x78
/* 3BAAC8 E00BCA98 461C0000 */  add.s     $f0, $f0, $f28
/* 3BAACC E00BCA9C A236FFFE */  sb        $s6, -2($s1)
/* 3BAAD0 E00BCAA0 26D60032 */  addiu     $s6, $s6, 0x32
/* 3BAAD4 E00BCAA4 461A0002 */  mul.s     $f0, $f0, $f26
/* 3BAAD8 E00BCAA8 00000000 */  nop
/* 3BAADC E00BCAAC 26520004 */  addiu     $s2, $s2, 4
/* 3BAAE0 E00BCAB0 24020400 */  addiu     $v0, $zero, 0x400
/* 3BAAE4 E00BCAB4 A630FFFA */  sh        $s0, -6($s1)
/* 3BAAE8 E00BCAB8 A622FFFC */  sh        $v0, -4($s1)
/* 3BAAEC E00BCABC 4600040D */  trunc.w.s $f16, $f0
/* 3BAAF0 E00BCAC0 44028000 */  mfc1      $v0, $f16
/* 3BAAF4 E00BCAC4 00000000 */  nop
/* 3BAAF8 E00BCAC8 A622FFF6 */  sh        $v0, -0xa($s1)
/* 3BAAFC E00BCACC 2A62000C */  slti      $v0, $s3, 0xc
/* 3BAB00 E00BCAD0 1440FF60 */  bnez      $v0, .LE00BC854
/* 3BAB04 E00BCAD4 26310010 */   addiu    $s1, $s1, 0x10
/* 3BAB08 E00BCAD8 0260382D */  daddu     $a3, $s3, $zero
/* 3BAB0C E00BCADC 3C08D9DF */  lui       $t0, 0xd9df
/* 3BAB10 E00BCAE0 3508FFFF */  ori       $t0, $t0, 0xffff
/* 3BAB14 E00BCAE4 3C09800A */  lui       $t1, %hi(gMasterGfxPos)
/* 3BAB18 E00BCAE8 2529A66C */  addiu     $t1, $t1, %lo(gMasterGfxPos)
/* 3BAB1C E00BCAEC 00071040 */  sll       $v0, $a3, 1
/* 3BAB20 E00BCAF0 0000982D */  daddu     $s3, $zero, $zero
/* 3BAB24 E00BCAF4 304400FF */  andi      $a0, $v0, 0xff
/* 3BAB28 E00BCAF8 00042300 */  sll       $a0, $a0, 0xc
/* 3BAB2C E00BCAFC 3042007F */  andi      $v0, $v0, 0x7f
/* 3BAB30 E00BCB00 00021040 */  sll       $v0, $v0, 1
/* 3BAB34 E00BCB04 3C030100 */  lui       $v1, 0x100
/* 3BAB38 E00BCB08 00431025 */  or        $v0, $v0, $v1
/* 3BAB3C E00BCB0C 00822025 */  or        $a0, $a0, $v0
/* 3BAB40 E00BCB10 8D250000 */  lw        $a1, ($t1)
/* 3BAB44 E00BCB14 24EBFFFF */  addiu     $t3, $a3, -1
/* 3BAB48 E00BCB18 00A0302D */  daddu     $a2, $a1, $zero
/* 3BAB4C E00BCB1C 24A50008 */  addiu     $a1, $a1, 8
/* 3BAB50 E00BCB20 AD250000 */  sw        $a1, ($t1)
/* 3BAB54 E00BCB24 ACC40000 */  sw        $a0, ($a2)
/* 3BAB58 E00BCB28 8FAE0090 */  lw        $t6, 0x90($sp)
/* 3BAB5C E00BCB2C 24A20008 */  addiu     $v0, $a1, 8
/* 3BAB60 E00BCB30 ACCE0004 */  sw        $t6, 4($a2)
/* 3BAB64 E00BCB34 AD220000 */  sw        $v0, ($t1)
/* 3BAB68 E00BCB38 ACA80000 */  sw        $t0, ($a1)
/* 3BAB6C E00BCB3C 1960001E */  blez      $t3, .LE00BCBB8
/* 3BAB70 E00BCB40 ACA00004 */   sw       $zero, 4($a1)
/* 3BAB74 E00BCB44 0120602D */  daddu     $t4, $t1, $zero
/* 3BAB78 E00BCB48 3C0D0600 */  lui       $t5, 0x600
/* 3BAB7C E00BCB4C 240A0006 */  addiu     $t2, $zero, 6
/* 3BAB80 E00BCB50 24090004 */  addiu     $t1, $zero, 4
/* 3BAB84 E00BCB54 24080002 */  addiu     $t0, $zero, 2
.LE00BCB58:
/* 3BAB88 E00BCB58 314700FF */  andi      $a3, $t2, 0xff
/* 3BAB8C E00BCB5C 254A0004 */  addiu     $t2, $t2, 4
/* 3BAB90 E00BCB60 312500FF */  andi      $a1, $t1, 0xff
/* 3BAB94 E00BCB64 25290004 */  addiu     $t1, $t1, 4
/* 3BAB98 E00BCB68 310400FF */  andi      $a0, $t0, 0xff
/* 3BAB9C E00BCB6C 25080004 */  addiu     $t0, $t0, 4
/* 3BABA0 E00BCB70 00131280 */  sll       $v0, $s3, 0xa
/* 3BABA4 E00BCB74 26730001 */  addiu     $s3, $s3, 1
/* 3BABA8 E00BCB78 00042400 */  sll       $a0, $a0, 0x10
/* 3BABAC E00BCB7C 3042FC00 */  andi      $v0, $v0, 0xfc00
/* 3BABB0 E00BCB80 00821025 */  or        $v0, $a0, $v0
/* 3BABB4 E00BCB84 00451025 */  or        $v0, $v0, $a1
/* 3BABB8 E00BCB88 004D1025 */  or        $v0, $v0, $t5
/* 3BABBC E00BCB8C 00052A00 */  sll       $a1, $a1, 8
/* 3BABC0 E00BCB90 00852025 */  or        $a0, $a0, $a1
/* 3BABC4 E00BCB94 8D830000 */  lw        $v1, ($t4)
/* 3BABC8 E00BCB98 00872025 */  or        $a0, $a0, $a3
/* 3BABCC E00BCB9C 0060302D */  daddu     $a2, $v1, $zero
/* 3BABD0 E00BCBA0 24630008 */  addiu     $v1, $v1, 8
/* 3BABD4 E00BCBA4 AD830000 */  sw        $v1, ($t4)
/* 3BABD8 E00BCBA8 ACC20000 */  sw        $v0, ($a2)
/* 3BABDC E00BCBAC 026B102A */  slt       $v0, $s3, $t3
/* 3BABE0 E00BCBB0 1440FFE9 */  bnez      $v0, .LE00BCB58
/* 3BABE4 E00BCBB4 ACC40004 */   sw       $a0, 4($a2)
.LE00BCBB8:
/* 3BABE8 E00BCBB8 3C05D838 */  lui       $a1, 0xd838
/* 3BABEC E00BCBBC 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* 3BABF0 E00BCBC0 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* 3BABF4 E00BCBC4 8C620000 */  lw        $v0, ($v1)
/* 3BABF8 E00BCBC8 34A50002 */  ori       $a1, $a1, 2
/* 3BABFC E00BCBCC 0040202D */  daddu     $a0, $v0, $zero
/* 3BAC00 E00BCBD0 24420008 */  addiu     $v0, $v0, 8
/* 3BAC04 E00BCBD4 AC620000 */  sw        $v0, ($v1)
/* 3BAC08 E00BCBD8 24020040 */  addiu     $v0, $zero, 0x40
/* 3BAC0C E00BCBDC AC850000 */  sw        $a1, ($a0)
/* 3BAC10 E00BCBE0 AC820004 */  sw        $v0, 4($a0)
/* 3BAC14 E00BCBE4 8FBF00C4 */  lw        $ra, 0xc4($sp)
/* 3BAC18 E00BCBE8 8FBE00C0 */  lw        $fp, 0xc0($sp)
/* 3BAC1C E00BCBEC 8FB700BC */  lw        $s7, 0xbc($sp)
/* 3BAC20 E00BCBF0 8FB600B8 */  lw        $s6, 0xb8($sp)
/* 3BAC24 E00BCBF4 8FB500B4 */  lw        $s5, 0xb4($sp)
/* 3BAC28 E00BCBF8 8FB400B0 */  lw        $s4, 0xb0($sp)
/* 3BAC2C E00BCBFC 8FB300AC */  lw        $s3, 0xac($sp)
/* 3BAC30 E00BCC00 8FB200A8 */  lw        $s2, 0xa8($sp)
/* 3BAC34 E00BCC04 8FB100A4 */  lw        $s1, 0xa4($sp)
/* 3BAC38 E00BCC08 8FB000A0 */  lw        $s0, 0xa0($sp)
/* 3BAC3C E00BCC0C D7BE00F0 */  ldc1      $f30, 0xf0($sp)
/* 3BAC40 E00BCC10 D7BC00E8 */  ldc1      $f28, 0xe8($sp)
/* 3BAC44 E00BCC14 D7BA00E0 */  ldc1      $f26, 0xe0($sp)
/* 3BAC48 E00BCC18 D7B800D8 */  ldc1      $f24, 0xd8($sp)
/* 3BAC4C E00BCC1C D7B600D0 */  ldc1      $f22, 0xd0($sp)
/* 3BAC50 E00BCC20 D7B400C8 */  ldc1      $f20, 0xc8($sp)
/* 3BAC54 E00BCC24 03E00008 */  jr        $ra
/* 3BAC58 E00BCC28 27BD00F8 */   addiu    $sp, $sp, 0xf8
/* 3BAC5C E00BCC2C 00000000 */  nop
