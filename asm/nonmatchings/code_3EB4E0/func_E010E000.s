.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E010E000
/* 3EB4E0 E010E000 14A00004 */  bnez      $a1, .LE010E014
/* 3EB4E4 E010E004 8C83001C */   lw       $v1, 0x1c($a0)
/* 3EB4E8 E010E008 C4860004 */  lwc1      $f6, 4($a0)
/* 3EB4EC E010E00C 08043807 */  j         .LE010E01C
/* 3EB4F0 E010E010 C4840008 */   lwc1     $f4, 8($a0)
.LE010E014:
/* 3EB4F4 E010E014 C4860010 */  lwc1      $f6, 0x10($a0)
/* 3EB4F8 E010E018 C4840014 */  lwc1      $f4, 0x14($a0)
.LE010E01C:
/* 3EB4FC E010E01C 10C000C1 */  beqz      $a2, .LE010E324
/* 3EB500 E010E020 00000000 */   nop
/* 3EB504 E010E024 8CC20000 */  lw        $v0, ($a2)
/* 3EB508 E010E028 104000B5 */  beqz      $v0, .LE010E300
/* 3EB50C E010E02C 00035080 */   sll      $t2, $v1, 2
/* 3EB510 E010E030 3C08800A */  lui       $t0, %hi(gMasterGfxPos)
/* 3EB514 E010E034 2508A66C */  addiu     $t0, $t0, %lo(gMasterGfxPos)
/* 3EB518 E010E038 3C014080 */  lui       $at, 0x4080
/* 3EB51C E010E03C 44814000 */  mtc1      $at, $f8
/* 3EB520 E010E040 24C70006 */  addiu     $a3, $a2, 6
.LE010E044:
/* 3EB524 E010E044 8D040000 */  lw        $a0, ($t0)
/* 3EB528 E010E048 3C02DE00 */  lui       $v0, 0xde00
/* 3EB52C E010E04C 0080182D */  daddu     $v1, $a0, $zero
/* 3EB530 E010E050 AC620000 */  sw        $v0, ($v1)
/* 3EB534 E010E054 8CC20000 */  lw        $v0, ($a2)
/* 3EB538 E010E058 24840008 */  addiu     $a0, $a0, 8
/* 3EB53C E010E05C AC620004 */  sw        $v0, 4($v1)
/* 3EB540 E010E060 84E2FFFE */  lh        $v0, -2($a3)
/* 3EB544 E010E064 3C03F200 */  lui       $v1, 0xf200
/* 3EB548 E010E068 2442FE80 */  addiu     $v0, $v0, -0x180
/* 3EB54C E010E06C 01421023 */  subu      $v0, $t2, $v0
/* 3EB550 E010E070 00021080 */  sll       $v0, $v0, 2
/* 3EB554 E010E074 30420FFF */  andi      $v0, $v0, 0xfff
/* 3EB558 E010E078 00021300 */  sll       $v0, $v0, 0xc
/* 3EB55C E010E07C 00431025 */  or        $v0, $v0, $v1
/* 3EB560 E010E080 AC820000 */  sw        $v0, ($a0)
/* 3EB564 E010E084 84E2FFFE */  lh        $v0, -2($a3)
/* 3EB568 E010E088 3C030100 */  lui       $v1, 0x100
/* 3EB56C E010E08C 01421023 */  subu      $v0, $t2, $v0
/* 3EB570 E010E090 244201FF */  addiu     $v0, $v0, 0x1ff
/* 3EB574 E010E094 00021080 */  sll       $v0, $v0, 2
/* 3EB578 E010E098 30420FFF */  andi      $v0, $v0, 0xfff
/* 3EB57C E010E09C 00021300 */  sll       $v0, $v0, 0xc
/* 3EB580 E010E0A0 00431025 */  or        $v0, $v0, $v1
/* 3EB584 E010E0A4 AC820004 */  sw        $v0, 4($a0)
/* 3EB588 E010E0A8 84E2FFFE */  lh        $v0, -2($a3)
/* 3EB58C E010E0AC 44821000 */  mtc1      $v0, $f2
/* 3EB590 E010E0B0 00000000 */  nop
/* 3EB594 E010E0B4 468010A0 */  cvt.s.w   $f2, $f2
/* 3EB598 E010E0B8 46023080 */  add.s     $f2, $f6, $f2
/* 3EB59C E010E0BC 84E20002 */  lh        $v0, 2($a3)
/* 3EB5A0 E010E0C0 44820000 */  mtc1      $v0, $f0
/* 3EB5A4 E010E0C4 00000000 */  nop
/* 3EB5A8 E010E0C8 46800020 */  cvt.s.w   $f0, $f0
/* 3EB5AC E010E0CC 46001080 */  add.s     $f2, $f2, $f0
/* 3EB5B0 E010E0D0 AD040000 */  sw        $a0, ($t0)
/* 3EB5B4 E010E0D4 24820008 */  addiu     $v0, $a0, 8
/* 3EB5B8 E010E0D8 46081082 */  mul.s     $f2, $f2, $f8
/* 3EB5BC E010E0DC 00000000 */  nop
/* 3EB5C0 E010E0E0 24840010 */  addiu     $a0, $a0, 0x10
/* 3EB5C4 E010E0E4 AD020000 */  sw        $v0, ($t0)
/* 3EB5C8 E010E0E8 AD040000 */  sw        $a0, ($t0)
/* 3EB5CC E010E0EC 0040202D */  daddu     $a0, $v0, $zero
/* 3EB5D0 E010E0F0 4600128D */  trunc.w.s $f10, $f2
/* 3EB5D4 E010E0F4 44025000 */  mfc1      $v0, $f10
/* 3EB5D8 E010E0F8 00000000 */  nop
/* 3EB5DC E010E0FC 00021400 */  sll       $v0, $v0, 0x10
/* 3EB5E0 E010E100 00021403 */  sra       $v0, $v0, 0x10
/* 3EB5E4 E010E104 18400005 */  blez      $v0, .LE010E11C
/* 3EB5E8 E010E108 30420FFF */   andi     $v0, $v0, 0xfff
/* 3EB5EC E010E10C 00021300 */  sll       $v0, $v0, 0xc
/* 3EB5F0 E010E110 3C03E400 */  lui       $v1, 0xe400
/* 3EB5F4 E010E114 08043848 */  j         .LE010E120
/* 3EB5F8 E010E118 00431825 */   or       $v1, $v0, $v1
.LE010E11C:
/* 3EB5FC E010E11C 3C03E400 */  lui       $v1, 0xe400
.LE010E120:
/* 3EB600 E010E120 84E20000 */  lh        $v0, ($a3)
/* 3EB604 E010E124 44820000 */  mtc1      $v0, $f0
/* 3EB608 E010E128 00000000 */  nop
/* 3EB60C E010E12C 46800020 */  cvt.s.w   $f0, $f0
/* 3EB610 E010E130 84E20004 */  lh        $v0, 4($a3)
/* 3EB614 E010E134 46002000 */  add.s     $f0, $f4, $f0
/* 3EB618 E010E138 44821000 */  mtc1      $v0, $f2
/* 3EB61C E010E13C 00000000 */  nop
/* 3EB620 E010E140 468010A0 */  cvt.s.w   $f2, $f2
/* 3EB624 E010E144 46020000 */  add.s     $f0, $f0, $f2
/* 3EB628 E010E148 46080002 */  mul.s     $f0, $f0, $f8
/* 3EB62C E010E14C 00000000 */  nop
/* 3EB630 E010E150 4600028D */  trunc.w.s $f10, $f0
/* 3EB634 E010E154 44025000 */  mfc1      $v0, $f10
/* 3EB638 E010E158 00000000 */  nop
/* 3EB63C E010E15C 00021400 */  sll       $v0, $v0, 0x10
/* 3EB640 E010E160 00021403 */  sra       $v0, $v0, 0x10
/* 3EB644 E010E164 18400002 */  blez      $v0, .LE010E170
/* 3EB648 E010E168 30420FFF */   andi     $v0, $v0, 0xfff
/* 3EB64C E010E16C 00621825 */  or        $v1, $v1, $v0
.LE010E170:
/* 3EB650 E010E170 AC830000 */  sw        $v1, ($a0)
/* 3EB654 E010E174 84E2FFFE */  lh        $v0, -2($a3)
/* 3EB658 E010E178 44820000 */  mtc1      $v0, $f0
/* 3EB65C E010E17C 00000000 */  nop
/* 3EB660 E010E180 46800020 */  cvt.s.w   $f0, $f0
/* 3EB664 E010E184 46003000 */  add.s     $f0, $f6, $f0
/* 3EB668 E010E188 46080002 */  mul.s     $f0, $f0, $f8
/* 3EB66C E010E18C 00000000 */  nop
/* 3EB670 E010E190 4600028D */  trunc.w.s $f10, $f0
/* 3EB674 E010E194 44025000 */  mfc1      $v0, $f10
/* 3EB678 E010E198 00000000 */  nop
/* 3EB67C E010E19C 00021400 */  sll       $v0, $v0, 0x10
/* 3EB680 E010E1A0 00021403 */  sra       $v0, $v0, 0x10
/* 3EB684 E010E1A4 18400004 */  blez      $v0, .LE010E1B8
/* 3EB688 E010E1A8 24850004 */   addiu    $a1, $a0, 4
/* 3EB68C E010E1AC 30420FFF */  andi      $v0, $v0, 0xfff
/* 3EB690 E010E1B0 0804386F */  j         .LE010E1BC
/* 3EB694 E010E1B4 00021B00 */   sll      $v1, $v0, 0xc
.LE010E1B8:
/* 3EB698 E010E1B8 0000182D */  daddu     $v1, $zero, $zero
.LE010E1BC:
/* 3EB69C E010E1BC 84E20000 */  lh        $v0, ($a3)
/* 3EB6A0 E010E1C0 44820000 */  mtc1      $v0, $f0
/* 3EB6A4 E010E1C4 00000000 */  nop
/* 3EB6A8 E010E1C8 46800020 */  cvt.s.w   $f0, $f0
/* 3EB6AC E010E1CC 46002000 */  add.s     $f0, $f4, $f0
/* 3EB6B0 E010E1D0 46080002 */  mul.s     $f0, $f0, $f8
/* 3EB6B4 E010E1D4 00000000 */  nop
/* 3EB6B8 E010E1D8 4600028D */  trunc.w.s $f10, $f0
/* 3EB6BC E010E1DC 44025000 */  mfc1      $v0, $f10
/* 3EB6C0 E010E1E0 00000000 */  nop
/* 3EB6C4 E010E1E4 00021400 */  sll       $v0, $v0, 0x10
/* 3EB6C8 E010E1E8 00021403 */  sra       $v0, $v0, 0x10
/* 3EB6CC E010E1EC 18400003 */  blez      $v0, .LE010E1FC
/* 3EB6D0 E010E1F0 0060202D */   daddu    $a0, $v1, $zero
/* 3EB6D4 E010E1F4 30420FFF */  andi      $v0, $v0, 0xfff
/* 3EB6D8 E010E1F8 00822025 */  or        $a0, $a0, $v0
.LE010E1FC:
/* 3EB6DC E010E1FC 8D030000 */  lw        $v1, ($t0)
/* 3EB6E0 E010E200 3C02E100 */  lui       $v0, 0xe100
/* 3EB6E4 E010E204 ACA40000 */  sw        $a0, ($a1)
/* 3EB6E8 E010E208 0060202D */  daddu     $a0, $v1, $zero
/* 3EB6EC E010E20C AC820000 */  sw        $v0, ($a0)
/* 3EB6F0 E010E210 84E2FFFE */  lh        $v0, -2($a3)
/* 3EB6F4 E010E214 44820000 */  mtc1      $v0, $f0
/* 3EB6F8 E010E218 00000000 */  nop
/* 3EB6FC E010E21C 46800020 */  cvt.s.w   $f0, $f0
/* 3EB700 E010E220 46003000 */  add.s     $f0, $f6, $f0
/* 3EB704 E010E224 46080002 */  mul.s     $f0, $f0, $f8
/* 3EB708 E010E228 00000000 */  nop
/* 3EB70C E010E22C 24630008 */  addiu     $v1, $v1, 8
/* 3EB710 E010E230 24890004 */  addiu     $t1, $a0, 4
/* 3EB714 E010E234 4600028D */  trunc.w.s $f10, $f0
/* 3EB718 E010E238 44025000 */  mfc1      $v0, $f10
/* 3EB71C E010E23C 00000000 */  nop
/* 3EB720 E010E240 00021400 */  sll       $v0, $v0, 0x10
/* 3EB724 E010E244 00021403 */  sra       $v0, $v0, 0x10
/* 3EB728 E010E248 04410007 */  bgez      $v0, .LE010E268
/* 3EB72C E010E24C AD030000 */   sw       $v1, ($t0)
/* 3EB730 E010E250 000210C0 */  sll       $v0, $v0, 3
/* 3EB734 E010E254 5C400001 */  bgtzl     $v0, .LE010E25C
/* 3EB738 E010E258 0000102D */   daddu    $v0, $zero, $zero
.LE010E25C:
/* 3EB73C E010E25C 00021023 */  negu      $v0, $v0
/* 3EB740 E010E260 0804389B */  j         .LE010E26C
/* 3EB744 E010E264 00021C00 */   sll      $v1, $v0, 0x10
.LE010E268:
/* 3EB748 E010E268 0000182D */  daddu     $v1, $zero, $zero
.LE010E26C:
/* 3EB74C E010E26C 84E20000 */  lh        $v0, ($a3)
/* 3EB750 E010E270 44820000 */  mtc1      $v0, $f0
/* 3EB754 E010E274 00000000 */  nop
/* 3EB758 E010E278 46800020 */  cvt.s.w   $f0, $f0
/* 3EB75C E010E27C 46002000 */  add.s     $f0, $f4, $f0
/* 3EB760 E010E280 46080082 */  mul.s     $f2, $f0, $f8
/* 3EB764 E010E284 00000000 */  nop
/* 3EB768 E010E288 44800000 */  mtc1      $zero, $f0
/* 3EB76C E010E28C 00000000 */  nop
/* 3EB770 E010E290 4600103C */  c.lt.s    $f2, $f0
/* 3EB774 E010E294 00000000 */  nop
/* 3EB778 E010E298 4500000C */  bc1f      .LE010E2CC
/* 3EB77C E010E29C 3C050400 */   lui      $a1, 0x400
/* 3EB780 E010E2A0 4600128D */  trunc.w.s $f10, $f2
/* 3EB784 E010E2A4 44025000 */  mfc1      $v0, $f10
/* 3EB788 E010E2A8 00000000 */  nop
/* 3EB78C E010E2AC 00021400 */  sll       $v0, $v0, 0x10
/* 3EB790 E010E2B0 00021343 */  sra       $v0, $v0, 0xd
/* 3EB794 E010E2B4 5C400001 */  bgtzl     $v0, .LE010E2BC
/* 3EB798 E010E2B8 0000102D */   daddu    $v0, $zero, $zero
.LE010E2BC:
/* 3EB79C E010E2BC 00021023 */  negu      $v0, $v0
/* 3EB7A0 E010E2C0 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3EB7A4 E010E2C4 00621825 */  or        $v1, $v1, $v0
/* 3EB7A8 E010E2C8 3C050400 */  lui       $a1, 0x400
.LE010E2CC:
/* 3EB7AC E010E2CC 34A50400 */  ori       $a1, $a1, 0x400
/* 3EB7B0 E010E2D0 24E7000C */  addiu     $a3, $a3, 0xc
/* 3EB7B4 E010E2D4 24C6000C */  addiu     $a2, $a2, 0xc
/* 3EB7B8 E010E2D8 8D040000 */  lw        $a0, ($t0)
/* 3EB7BC E010E2DC 3C02F100 */  lui       $v0, 0xf100
/* 3EB7C0 E010E2E0 AD230000 */  sw        $v1, ($t1)
/* 3EB7C4 E010E2E4 0080182D */  daddu     $v1, $a0, $zero
/* 3EB7C8 E010E2E8 AC620000 */  sw        $v0, ($v1)
/* 3EB7CC E010E2EC AC650004 */  sw        $a1, 4($v1)
/* 3EB7D0 E010E2F0 8CC20000 */  lw        $v0, ($a2)
/* 3EB7D4 E010E2F4 24840008 */  addiu     $a0, $a0, 8
/* 3EB7D8 E010E2F8 1440FF52 */  bnez      $v0, .LE010E044
/* 3EB7DC E010E2FC AD040000 */   sw       $a0, ($t0)
.LE010E300:
/* 3EB7E0 E010E300 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* 3EB7E4 E010E304 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* 3EB7E8 E010E308 8C620000 */  lw        $v0, ($v1)
/* 3EB7EC E010E30C 0040202D */  daddu     $a0, $v0, $zero
/* 3EB7F0 E010E310 24420008 */  addiu     $v0, $v0, 8
/* 3EB7F4 E010E314 AC620000 */  sw        $v0, ($v1)
/* 3EB7F8 E010E318 3C02E700 */  lui       $v0, 0xe700
/* 3EB7FC E010E31C AC820000 */  sw        $v0, ($a0)
/* 3EB800 E010E320 AC800004 */  sw        $zero, 4($a0)
.LE010E324:
/* 3EB804 E010E324 03E00008 */  jr        $ra
/* 3EB808 E010E328 00000000 */   nop
