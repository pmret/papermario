.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00C639C
/* 3CCD7C E00C639C 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 3CCD80 E00C63A0 AFB20030 */  sw        $s2, 0x30($sp)
/* 3CCD84 E00C63A4 0080902D */  daddu     $s2, $a0, $zero
/* 3CCD88 E00C63A8 AFBF0034 */  sw        $ra, 0x34($sp)
/* 3CCD8C E00C63AC AFB1002C */  sw        $s1, 0x2c($sp)
/* 3CCD90 E00C63B0 AFB00028 */  sw        $s0, 0x28($sp)
/* 3CCD94 E00C63B4 F7B60040 */  sdc1      $f22, 0x40($sp)
/* 3CCD98 E00C63B8 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 3CCD9C E00C63BC 8E430000 */  lw        $v1, ($s2)
/* 3CCDA0 E00C63C0 8E50000C */  lw        $s0, 0xc($s2)
/* 3CCDA4 E00C63C4 30620010 */  andi      $v0, $v1, 0x10
/* 3CCDA8 E00C63C8 8E110000 */  lw        $s1, ($s0)
/* 3CCDAC E00C63CC 10400005 */  beqz      $v0, .LE00C63E4
/* 3CCDB0 E00C63D0 2402FFEF */   addiu    $v0, $zero, -0x11
/* 3CCDB4 E00C63D4 00621024 */  and       $v0, $v1, $v0
/* 3CCDB8 E00C63D8 AE420000 */  sw        $v0, ($s2)
/* 3CCDBC E00C63DC 24020010 */  addiu     $v0, $zero, 0x10
/* 3CCDC0 E00C63E0 AE020020 */  sw        $v0, 0x20($s0)
.LE00C63E4:
/* 3CCDC4 E00C63E4 8E030020 */  lw        $v1, 0x20($s0)
/* 3CCDC8 E00C63E8 286203E8 */  slti      $v0, $v1, 0x3e8
/* 3CCDCC E00C63EC 10400002 */  beqz      $v0, .LE00C63F8
/* 3CCDD0 E00C63F0 2462FFFF */   addiu    $v0, $v1, -1
/* 3CCDD4 E00C63F4 AE020020 */  sw        $v0, 0x20($s0)
.LE00C63F8:
/* 3CCDD8 E00C63F8 8E020024 */  lw        $v0, 0x24($s0)
/* 3CCDDC E00C63FC 8E030020 */  lw        $v1, 0x20($s0)
/* 3CCDE0 E00C6400 24420001 */  addiu     $v0, $v0, 1
/* 3CCDE4 E00C6404 AE020024 */  sw        $v0, 0x24($s0)
/* 3CCDE8 E00C6408 24020001 */  addiu     $v0, $zero, 1
/* 3CCDEC E00C640C 14620016 */  bne       $v1, $v0, .LE00C6468
/* 3CCDF0 E00C6410 00000000 */   nop      
/* 3CCDF4 E00C6414 16230014 */  bne       $s1, $v1, .LE00C6468
/* 3CCDF8 E00C6418 00000000 */   nop      
/* 3CCDFC E00C641C 0C080150 */  jal       func_E0200540
/* 3CCE00 E00C6420 24040063 */   addiu    $a0, $zero, 0x63
/* 3CCE04 E00C6424 C6000010 */  lwc1      $f0, 0x10($s0)
/* 3CCE08 E00C6428 E7A00010 */  swc1      $f0, 0x10($sp)
/* 3CCE0C E00C642C C6000014 */  lwc1      $f0, 0x14($s0)
/* 3CCE10 E00C6430 E7A00014 */  swc1      $f0, 0x14($sp)
/* 3CCE14 E00C6434 3C013F80 */  lui       $at, 0x3f80
/* 3CCE18 E00C6438 44810000 */  mtc1      $at, $f0
/* 3CCE1C E00C643C C6020018 */  lwc1      $f2, 0x18($s0)
/* 3CCE20 E00C6440 24020020 */  addiu     $v0, $zero, 0x20
/* 3CCE24 E00C6444 AFA20020 */  sw        $v0, 0x20($sp)
/* 3CCE28 E00C6448 AFA20024 */  sw        $v0, 0x24($sp)
/* 3CCE2C E00C644C E7A0001C */  swc1      $f0, 0x1c($sp)
/* 3CCE30 E00C6450 E7A20018 */  swc1      $f2, 0x18($sp)
/* 3CCE34 E00C6454 8E050004 */  lw        $a1, 4($s0)
/* 3CCE38 E00C6458 8E060008 */  lw        $a2, 8($s0)
/* 3CCE3C E00C645C 8E07000C */  lw        $a3, 0xc($s0)
/* 3CCE40 E00C6460 0C031800 */  jal       func_E00C6000
/* 3CCE44 E00C6464 24040002 */   addiu    $a0, $zero, 2
.LE00C6468:
/* 3CCE48 E00C6468 8E020020 */  lw        $v0, 0x20($s0)
/* 3CCE4C E00C646C 04410005 */  bgez      $v0, .LE00C6484
/* 3CCE50 E00C6470 24020001 */   addiu    $v0, $zero, 1
/* 3CCE54 E00C6474 0C080128 */  jal       func_E02004A0
/* 3CCE58 E00C6478 0240202D */   daddu    $a0, $s2, $zero
/* 3CCE5C E00C647C 080319D2 */  j         .LE00C6748
/* 3CCE60 E00C6480 00000000 */   nop      
.LE00C6484:
/* 3CCE64 E00C6484 8E030024 */  lw        $v1, 0x24($s0)
/* 3CCE68 E00C6488 12220023 */  beq       $s1, $v0, .LE00C6518
/* 3CCE6C E00C648C 2A220002 */   slti     $v0, $s1, 2
/* 3CCE70 E00C6490 50400005 */  beql      $v0, $zero, .LE00C64A8
/* 3CCE74 E00C6494 24020002 */   addiu    $v0, $zero, 2
/* 3CCE78 E00C6498 12200007 */  beqz      $s1, .LE00C64B8
/* 3CCE7C E00C649C 30620003 */   andi     $v0, $v1, 3
/* 3CCE80 E00C64A0 080319D2 */  j         .LE00C6748
/* 3CCE84 E00C64A4 00000000 */   nop      
.LE00C64A8:
/* 3CCE88 E00C64A8 1222005F */  beq       $s1, $v0, .LE00C6628
/* 3CCE8C E00C64AC 00000000 */   nop      
/* 3CCE90 E00C64B0 080319D2 */  j         .LE00C6748
/* 3CCE94 E00C64B4 00000000 */   nop      
.LE00C64B8:
/* 3CCE98 E00C64B8 144000A3 */  bnez      $v0, .LE00C6748
/* 3CCE9C E00C64BC 00000000 */   nop      
/* 3CCEA0 E00C64C0 0C080150 */  jal       func_E0200540
/* 3CCEA4 E00C64C4 24040063 */   addiu    $a0, $zero, 0x63
/* 3CCEA8 E00C64C8 C6000010 */  lwc1      $f0, 0x10($s0)
/* 3CCEAC E00C64CC E7A00010 */  swc1      $f0, 0x10($sp)
/* 3CCEB0 E00C64D0 C6000014 */  lwc1      $f0, 0x14($s0)
/* 3CCEB4 E00C64D4 E7A00014 */  swc1      $f0, 0x14($sp)
/* 3CCEB8 E00C64D8 3C013F80 */  lui       $at, 0x3f80
/* 3CCEBC E00C64DC 44810000 */  mtc1      $at, $f0
/* 3CCEC0 E00C64E0 C6020018 */  lwc1      $f2, 0x18($s0)
/* 3CCEC4 E00C64E4 E7A0001C */  swc1      $f0, 0x1c($sp)
/* 3CCEC8 E00C64E8 E7A20018 */  swc1      $f2, 0x18($sp)
/* 3CCECC E00C64EC 8E02001C */  lw        $v0, 0x1c($s0)
/* 3CCED0 E00C64F0 AFA20020 */  sw        $v0, 0x20($sp)
/* 3CCED4 E00C64F4 8E02001C */  lw        $v0, 0x1c($s0)
/* 3CCED8 E00C64F8 AFA20024 */  sw        $v0, 0x24($sp)
/* 3CCEDC E00C64FC 8E050004 */  lw        $a1, 4($s0)
/* 3CCEE0 E00C6500 8E060008 */  lw        $a2, 8($s0)
/* 3CCEE4 E00C6504 8E07000C */  lw        $a3, 0xc($s0)
/* 3CCEE8 E00C6508 0C031800 */  jal       func_E00C6000
/* 3CCEEC E00C650C 24040001 */   addiu    $a0, $zero, 1
/* 3CCEF0 E00C6510 080319D2 */  j         .LE00C6748
/* 3CCEF4 E00C6514 00000000 */   nop      
.LE00C6518:
/* 3CCEF8 E00C6518 C6040060 */  lwc1      $f4, 0x60($s0)
/* 3CCEFC E00C651C 3C01E00C */  lui       $at, %hi(D_E00C6CB0)
/* 3CCF00 E00C6520 D4206CB0 */  ldc1      $f0, %lo(D_E00C6CB0)($at)
/* 3CCF04 E00C6524 46002121 */  cvt.d.s   $f4, $f4
/* 3CCF08 E00C6528 46202102 */  mul.d     $f4, $f4, $f0
/* 3CCF0C E00C652C 00000000 */  nop       
/* 3CCF10 E00C6530 C6020068 */  lwc1      $f2, 0x68($s0)
/* 3CCF14 E00C6534 460010A1 */  cvt.d.s   $f2, $f2
/* 3CCF18 E00C6538 46201082 */  mul.d     $f2, $f2, $f0
/* 3CCF1C E00C653C 00000000 */  nop       
/* 3CCF20 E00C6540 C60A0064 */  lwc1      $f10, 0x64($s0)
/* 3CCF24 E00C6544 3C013F80 */  lui       $at, 0x3f80
/* 3CCF28 E00C6548 44814000 */  mtc1      $at, $f8
/* 3CCF2C E00C654C 00000000 */  nop       
/* 3CCF30 E00C6550 460A4201 */  sub.s     $f8, $f8, $f10
/* 3CCF34 E00C6554 3C01E00C */  lui       $at, %hi(D_E00C6CB8)
/* 3CCF38 E00C6558 D4206CB8 */  ldc1      $f0, %lo(D_E00C6CB8)($at)
/* 3CCF3C E00C655C 46004221 */  cvt.d.s   $f8, $f8
/* 3CCF40 E00C6560 46204202 */  mul.d     $f8, $f8, $f0
/* 3CCF44 E00C6564 00000000 */  nop       
/* 3CCF48 E00C6568 C60C0070 */  lwc1      $f12, 0x70($s0)
/* 3CCF4C E00C656C 3C013FF0 */  lui       $at, 0x3ff0
/* 3CCF50 E00C6570 44817800 */  mtc1      $at, $f15
/* 3CCF54 E00C6574 44807000 */  mtc1      $zero, $f14
/* 3CCF58 E00C6578 46006321 */  cvt.d.s   $f12, $f12
/* 3CCF5C E00C657C 462C7481 */  sub.d     $f18, $f14, $f12
/* 3CCF60 E00C6580 3C01E00C */  lui       $at, %hi(D_E00C6CC0)
/* 3CCF64 E00C6584 D4206CC0 */  ldc1      $f0, %lo(D_E00C6CC0)($at)
/* 3CCF68 E00C6588 46209482 */  mul.d     $f18, $f18, $f0
/* 3CCF6C E00C658C 00000000 */  nop       
/* 3CCF70 E00C6590 C606006C */  lwc1      $f6, 0x6c($s0)
/* 3CCF74 E00C6594 460031A1 */  cvt.d.s   $f6, $f6
/* 3CCF78 E00C6598 46267381 */  sub.d     $f14, $f14, $f6
/* 3CCF7C E00C659C 3C01E00C */  lui       $at, %hi(D_E00C6CC8)
/* 3CCF80 E00C65A0 D4206CC8 */  ldc1      $f0, %lo(D_E00C6CC8)($at)
/* 3CCF84 E00C65A4 46207382 */  mul.d     $f14, $f14, $f0
/* 3CCF88 E00C65A8 00000000 */  nop       
/* 3CCF8C E00C65AC C6100004 */  lwc1      $f16, 4($s0)
/* 3CCF90 E00C65B0 46202120 */  cvt.s.d   $f4, $f4
/* 3CCF94 E00C65B4 462010A0 */  cvt.s.d   $f2, $f2
/* 3CCF98 E00C65B8 E6040060 */  swc1      $f4, 0x60($s0)
/* 3CCF9C E00C65BC 46002006 */  mov.s     $f0, $f4
/* 3CCFA0 E00C65C0 E6020068 */  swc1      $f2, 0x68($s0)
/* 3CCFA4 E00C65C4 C6020074 */  lwc1      $f2, 0x74($s0)
/* 3CCFA8 E00C65C8 46008400 */  add.s     $f16, $f16, $f0
/* 3CCFAC E00C65CC C6000078 */  lwc1      $f0, 0x78($s0)
/* 3CCFB0 E00C65D0 C604000C */  lwc1      $f4, 0xc($s0)
/* 3CCFB4 E00C65D4 46001080 */  add.s     $f2, $f2, $f0
/* 3CCFB8 E00C65D8 C6000068 */  lwc1      $f0, 0x68($s0)
/* 3CCFBC E00C65DC 46002100 */  add.s     $f4, $f4, $f0
/* 3CCFC0 E00C65E0 460052A1 */  cvt.d.s   $f10, $f10
/* 3CCFC4 E00C65E4 C6000008 */  lwc1      $f0, 8($s0)
/* 3CCFC8 E00C65E8 46285280 */  add.d     $f10, $f10, $f8
/* 3CCFCC E00C65EC E6100004 */  swc1      $f16, 4($s0)
/* 3CCFD0 E00C65F0 E6020074 */  swc1      $f2, 0x74($s0)
/* 3CCFD4 E00C65F4 46326300 */  add.d     $f12, $f12, $f18
/* 3CCFD8 E00C65F8 462052A0 */  cvt.s.d   $f10, $f10
/* 3CCFDC E00C65FC E60A0064 */  swc1      $f10, 0x64($s0)
/* 3CCFE0 E00C6600 462E3180 */  add.d     $f6, $f6, $f14
/* 3CCFE4 E00C6604 46005086 */  mov.s     $f2, $f10
/* 3CCFE8 E00C6608 E604000C */  swc1      $f4, 0xc($s0)
/* 3CCFEC E00C660C 46020000 */  add.s     $f0, $f0, $f2
/* 3CCFF0 E00C6610 46206320 */  cvt.s.d   $f12, $f12
/* 3CCFF4 E00C6614 E60C0070 */  swc1      $f12, 0x70($s0)
/* 3CCFF8 E00C6618 462031A0 */  cvt.s.d   $f6, $f6
/* 3CCFFC E00C661C E606006C */  swc1      $f6, 0x6c($s0)
/* 3CD000 E00C6620 080319D2 */  j         .LE00C6748
/* 3CD004 E00C6624 E6000008 */   swc1     $f0, 8($s0)
.LE00C6628:
/* 3CD008 E00C6628 8E420008 */  lw        $v0, 8($s2)
/* 3CD00C E00C662C 18400046 */  blez      $v0, .LE00C6748
/* 3CD010 E00C6630 0000202D */   daddu    $a0, $zero, $zero
/* 3CD014 E00C6634 26030074 */  addiu     $v1, $s0, 0x74
/* 3CD018 E00C6638 3C01E00C */  lui       $at, %hi(D_E00C6CD0)
/* 3CD01C E00C663C D4366CD0 */  ldc1      $f22, %lo(D_E00C6CD0)($at)
/* 3CD020 E00C6640 3C01E00C */  lui       $at, %hi(D_E00C6CD8)
/* 3CD024 E00C6644 D4346CD8 */  ldc1      $f20, %lo(D_E00C6CD8)($at)
/* 3CD028 E00C6648 44806000 */  mtc1      $zero, $f12
/* 3CD02C E00C664C 3C01E00C */  lui       $at, %hi(D_E00C6CE0)
/* 3CD030 E00C6650 D4326CE0 */  ldc1      $f18, %lo(D_E00C6CE0)($at)
/* 3CD034 E00C6654 3C01E00C */  lui       $at, %hi(D_E00C6CE8)
/* 3CD038 E00C6658 D4306CE8 */  ldc1      $f16, %lo(D_E00C6CE8)($at)
/* 3CD03C E00C665C 3C01E00C */  lui       $at, %hi(D_E00C6CF0)
/* 3CD040 E00C6660 D42E6CF0 */  ldc1      $f14, %lo(D_E00C6CF0)($at)
.LE00C6664:
/* 3CD044 E00C6664 C462FFEC */  lwc1      $f2, -0x14($v1)
/* 3CD048 E00C6668 460010A1 */  cvt.d.s   $f2, $f2
/* 3CD04C E00C666C 46361082 */  mul.d     $f2, $f2, $f22
/* 3CD050 E00C6670 00000000 */  nop       
/* 3CD054 E00C6674 C460FFF0 */  lwc1      $f0, -0x10($v1)
/* 3CD058 E00C6678 46000021 */  cvt.d.s   $f0, $f0
/* 3CD05C E00C667C 46340001 */  sub.d     $f0, $f0, $f20
/* 3CD060 E00C6680 C464FF94 */  lwc1      $f4, -0x6c($v1)
/* 3CD064 E00C6684 46200020 */  cvt.s.d   $f0, $f0
/* 3CD068 E00C6688 46002100 */  add.s     $f4, $f4, $f0
/* 3CD06C E00C668C E460FFF0 */  swc1      $f0, -0x10($v1)
/* 3CD070 E00C6690 462010A0 */  cvt.s.d   $f2, $f2
/* 3CD074 E00C6694 E462FFEC */  swc1      $f2, -0x14($v1)
/* 3CD078 E00C6698 C462FF90 */  lwc1      $f2, -0x70($v1)
/* 3CD07C E00C669C C460FFEC */  lwc1      $f0, -0x14($v1)
/* 3CD080 E00C66A0 46001080 */  add.s     $f2, $f2, $f0
/* 3CD084 E00C66A4 460C203C */  c.lt.s    $f4, $f12
/* 3CD088 E00C66A8 E464FF94 */  swc1      $f4, -0x6c($v1)
/* 3CD08C E00C66AC 4500000B */  bc1f      .LE00C66DC
/* 3CD090 E00C66B0 E462FF90 */   swc1     $f2, -0x70($v1)
/* 3CD094 E00C66B4 C460FFF0 */  lwc1      $f0, -0x10($v1)
/* 3CD098 E00C66B8 460C003C */  c.lt.s    $f0, $f12
/* 3CD09C E00C66BC 00000000 */  nop       
/* 3CD0A0 E00C66C0 45000006 */  bc1f      .LE00C66DC
/* 3CD0A4 E00C66C4 E46CFF94 */   swc1     $f12, -0x6c($v1)
/* 3CD0A8 E00C66C8 46000021 */  cvt.d.s   $f0, $f0
/* 3CD0AC E00C66CC 46320002 */  mul.d     $f0, $f0, $f18
/* 3CD0B0 E00C66D0 00000000 */  nop       
/* 3CD0B4 E00C66D4 46200020 */  cvt.s.d   $f0, $f0
/* 3CD0B8 E00C66D8 E460FFF0 */  swc1      $f0, -0x10($v1)
.LE00C66DC:
/* 3CD0BC E00C66DC C462FFFC */  lwc1      $f2, -4($v1)
/* 3CD0C0 E00C66E0 46026201 */  sub.s     $f8, $f12, $f2
/* 3CD0C4 E00C66E4 46004221 */  cvt.d.s   $f8, $f8
/* 3CD0C8 E00C66E8 46304202 */  mul.d     $f8, $f8, $f16
/* 3CD0CC E00C66EC 00000000 */  nop       
/* 3CD0D0 E00C66F0 C460FFF8 */  lwc1      $f0, -8($v1)
/* 3CD0D4 E00C66F4 46006181 */  sub.s     $f6, $f12, $f0
/* 3CD0D8 E00C66F8 460031A1 */  cvt.d.s   $f6, $f6
/* 3CD0DC E00C66FC 462E3182 */  mul.d     $f6, $f6, $f14
/* 3CD0E0 E00C6700 00000000 */  nop       
/* 3CD0E4 E00C6704 C46A0000 */  lwc1      $f10, ($v1)
/* 3CD0E8 E00C6708 C4640004 */  lwc1      $f4, 4($v1)
/* 3CD0EC E00C670C 46045280 */  add.s     $f10, $f10, $f4
/* 3CD0F0 E00C6710 460010A1 */  cvt.d.s   $f2, $f2
/* 3CD0F4 E00C6714 46281080 */  add.d     $f2, $f2, $f8
/* 3CD0F8 E00C6718 24840001 */  addiu     $a0, $a0, 1
/* 3CD0FC E00C671C 46000021 */  cvt.d.s   $f0, $f0
/* 3CD100 E00C6720 46260000 */  add.d     $f0, $f0, $f6
/* 3CD104 E00C6724 E46A0000 */  swc1      $f10, ($v1)
/* 3CD108 E00C6728 462010A0 */  cvt.s.d   $f2, $f2
/* 3CD10C E00C672C 46200020 */  cvt.s.d   $f0, $f0
/* 3CD110 E00C6730 E462FFFC */  swc1      $f2, -4($v1)
/* 3CD114 E00C6734 E460FFF8 */  swc1      $f0, -8($v1)
/* 3CD118 E00C6738 8E420008 */  lw        $v0, 8($s2)
/* 3CD11C E00C673C 0082102A */  slt       $v0, $a0, $v0
/* 3CD120 E00C6740 1440FFC8 */  bnez      $v0, .LE00C6664
/* 3CD124 E00C6744 2463007C */   addiu    $v1, $v1, 0x7c
.LE00C6748:
/* 3CD128 E00C6748 8FBF0034 */  lw        $ra, 0x34($sp)
/* 3CD12C E00C674C 8FB20030 */  lw        $s2, 0x30($sp)
/* 3CD130 E00C6750 8FB1002C */  lw        $s1, 0x2c($sp)
/* 3CD134 E00C6754 8FB00028 */  lw        $s0, 0x28($sp)
/* 3CD138 E00C6758 D7B60040 */  ldc1      $f22, 0x40($sp)
/* 3CD13C E00C675C D7B40038 */  ldc1      $f20, 0x38($sp)
/* 3CD140 E00C6760 03E00008 */  jr        $ra
/* 3CD144 E00C6764 27BD0048 */   addiu    $sp, $sp, 0x48
