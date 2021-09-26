.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00A63A4
/* 3A58F4 E00A63A4 27BDFF50 */  addiu     $sp, $sp, -0xb0
/* 3A58F8 E00A63A8 0080182D */  daddu     $v1, $a0, $zero
/* 3A58FC E00A63AC 3C05DB06 */  lui       $a1, 0xdb06
/* 3A5900 E00A63B0 34A50024 */  ori       $a1, $a1, 0x24
/* 3A5904 E00A63B4 AFB10094 */  sw        $s1, 0x94($sp)
/* 3A5908 E00A63B8 3C11800A */  lui       $s1, %hi(gMasterGfxPos)
/* 3A590C E00A63BC 2631A66C */  addiu     $s1, $s1, %lo(gMasterGfxPos)
/* 3A5910 E00A63C0 27A40010 */  addiu     $a0, $sp, 0x10
/* 3A5914 E00A63C4 AFB600A8 */  sw        $s6, 0xa8($sp)
/* 3A5918 E00A63C8 3C16E700 */  lui       $s6, 0xe700
/* 3A591C E00A63CC AFBF00AC */  sw        $ra, 0xac($sp)
/* 3A5920 E00A63D0 AFB500A4 */  sw        $s5, 0xa4($sp)
/* 3A5924 E00A63D4 AFB400A0 */  sw        $s4, 0xa0($sp)
/* 3A5928 E00A63D8 AFB3009C */  sw        $s3, 0x9c($sp)
/* 3A592C E00A63DC AFB20098 */  sw        $s2, 0x98($sp)
/* 3A5930 E00A63E0 AFB00090 */  sw        $s0, 0x90($sp)
/* 3A5934 E00A63E4 8E280000 */  lw        $t0, ($s1)
/* 3A5938 E00A63E8 8C72000C */  lw        $s2, 0xc($v1)
/* 3A593C E00A63EC 0100102D */  daddu     $v0, $t0, $zero
/* 3A5940 E00A63F0 8E540018 */  lw        $s4, 0x18($s2)
/* 3A5944 E00A63F4 25080008 */  addiu     $t0, $t0, 8
/* 3A5948 E00A63F8 AC560000 */  sw        $s6, ($v0)
/* 3A594C E00A63FC AC400004 */  sw        $zero, 4($v0)
/* 3A5950 E00A6400 AD050000 */  sw        $a1, ($t0)
/* 3A5954 E00A6404 8C620010 */  lw        $v0, 0x10($v1)
/* 3A5958 E00A6408 3C150001 */  lui       $s5, 1
/* 3A595C E00A640C AE280000 */  sw        $t0, ($s1)
/* 3A5960 E00A6410 8C42001C */  lw        $v0, 0x1c($v0)
/* 3A5964 E00A6414 3C038000 */  lui       $v1, 0x8000
/* 3A5968 E00A6418 00431021 */  addu      $v0, $v0, $v1
/* 3A596C E00A641C AD020004 */  sw        $v0, 4($t0)
/* 3A5970 E00A6420 8E45000C */  lw        $a1, 0xc($s2)
/* 3A5974 E00A6424 8E460010 */  lw        $a2, 0x10($s2)
/* 3A5978 E00A6428 8E470014 */  lw        $a3, 0x14($s2)
/* 3A597C E00A642C 25080008 */  addiu     $t0, $t0, 8
/* 3A5980 E00A6430 0C080108 */  jal       shim_guTranslateF
/* 3A5984 E00A6434 AE280000 */   sw       $t0, ($s1)
/* 3A5988 E00A6438 36B51630 */  ori       $s5, $s5, 0x1630
/* 3A598C E00A643C 3C013F75 */  lui       $at, 0x3f75
/* 3A5990 E00A6440 3421C28F */  ori       $at, $at, 0xc28f
/* 3A5994 E00A6444 44810000 */  mtc1      $at, $f0
/* 3A5998 E00A6448 27B00050 */  addiu     $s0, $sp, 0x50
/* 3A599C E00A644C 44050000 */  mfc1      $a1, $f0
/* 3A59A0 E00A6450 0200202D */  daddu     $a0, $s0, $zero
/* 3A59A4 E00A6454 00A0302D */  daddu     $a2, $a1, $zero
/* 3A59A8 E00A6458 0C080110 */  jal       shim_guScaleF
/* 3A59AC E00A645C 00A0382D */   daddu    $a3, $a1, $zero
/* 3A59B0 E00A6460 0200202D */  daddu     $a0, $s0, $zero
/* 3A59B4 E00A6464 27A50010 */  addiu     $a1, $sp, 0x10
/* 3A59B8 E00A6468 0C080114 */  jal       shim_guMtxCatF
/* 3A59BC E00A646C 00A0302D */   daddu    $a2, $a1, $zero
/* 3A59C0 E00A6470 27A40010 */  addiu     $a0, $sp, 0x10
/* 3A59C4 E00A6474 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* 3A59C8 E00A6478 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* 3A59CC E00A647C 3C13800A */  lui       $s3, %hi(gDisplayContext)
/* 3A59D0 E00A6480 2673A674 */  addiu     $s3, $s3, %lo(gDisplayContext)
/* 3A59D4 E00A6484 96050000 */  lhu       $a1, ($s0)
/* 3A59D8 E00A6488 8E620000 */  lw        $v0, ($s3)
/* 3A59DC E00A648C 00052980 */  sll       $a1, $a1, 6
/* 3A59E0 E00A6490 00B52821 */  addu      $a1, $a1, $s5
/* 3A59E4 E00A6494 0C080118 */  jal       shim_guMtxF2L
/* 3A59E8 E00A6498 00452821 */   addu     $a1, $v0, $a1
/* 3A59EC E00A649C 3C03DA38 */  lui       $v1, 0xda38
/* 3A59F0 E00A64A0 34630002 */  ori       $v1, $v1, 2
/* 3A59F4 E00A64A4 3C07FCFF */  lui       $a3, 0xfcff
/* 3A59F8 E00A64A8 34E7A7FF */  ori       $a3, $a3, 0xa7ff
/* 3A59FC E00A64AC 3C06FF17 */  lui       $a2, 0xff17
/* 3A5A00 E00A64B0 34C6723F */  ori       $a2, $a2, 0x723f
/* 3A5A04 E00A64B4 3C08D838 */  lui       $t0, 0xd838
/* 3A5A08 E00A64B8 35080002 */  ori       $t0, $t0, 2
/* 3A5A0C E00A64BC 329400FF */  andi      $s4, $s4, 0xff
/* 3A5A10 E00A64C0 8E250000 */  lw        $a1, ($s1)
/* 3A5A14 E00A64C4 96020000 */  lhu       $v0, ($s0)
/* 3A5A18 E00A64C8 3C014080 */  lui       $at, 0x4080
/* 3A5A1C E00A64CC 44812000 */  mtc1      $at, $f4
/* 3A5A20 E00A64D0 00A0202D */  daddu     $a0, $a1, $zero
/* 3A5A24 E00A64D4 24A50008 */  addiu     $a1, $a1, 8
/* 3A5A28 E00A64D8 AE250000 */  sw        $a1, ($s1)
/* 3A5A2C E00A64DC AC830000 */  sw        $v1, ($a0)
/* 3A5A30 E00A64E0 24430001 */  addiu     $v1, $v0, 1
/* 3A5A34 E00A64E4 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3A5A38 E00A64E8 00021180 */  sll       $v0, $v0, 6
/* 3A5A3C E00A64EC A6030000 */  sh        $v1, ($s0)
/* 3A5A40 E00A64F0 8E630000 */  lw        $v1, ($s3)
/* 3A5A44 E00A64F4 00551021 */  addu      $v0, $v0, $s5
/* 3A5A48 E00A64F8 00621821 */  addu      $v1, $v1, $v0
/* 3A5A4C E00A64FC 24A20008 */  addiu     $v0, $a1, 8
/* 3A5A50 E00A6500 AC830004 */  sw        $v1, 4($a0)
/* 3A5A54 E00A6504 AE220000 */  sw        $v0, ($s1)
/* 3A5A58 E00A6508 3C02FA00 */  lui       $v0, 0xfa00
/* 3A5A5C E00A650C ACA20000 */  sw        $v0, ($a1)
/* 3A5A60 E00A6510 2402007F */  addiu     $v0, $zero, 0x7f
/* 3A5A64 E00A6514 ACA20004 */  sw        $v0, 4($a1)
/* 3A5A68 E00A6518 24A20010 */  addiu     $v0, $a1, 0x10
/* 3A5A6C E00A651C AE220000 */  sw        $v0, ($s1)
/* 3A5A70 E00A6520 3C02FB00 */  lui       $v0, 0xfb00
/* 3A5A74 E00A6524 ACA60014 */  sw        $a2, 0x14($a1)
/* 3A5A78 E00A6528 3C06DE00 */  lui       $a2, 0xde00
/* 3A5A7C E00A652C ACA20008 */  sw        $v0, 8($a1)
/* 3A5A80 E00A6530 3C020900 */  lui       $v0, 0x900
/* 3A5A84 E00A6534 24421000 */  addiu     $v0, $v0, 0x1000
/* 3A5A88 E00A6538 ACB4000C */  sw        $s4, 0xc($a1)
/* 3A5A8C E00A653C ACA70010 */  sw        $a3, 0x10($a1)
/* 3A5A90 E00A6540 ACA60018 */  sw        $a2, 0x18($a1)
/* 3A5A94 E00A6544 ACA2001C */  sw        $v0, 0x1c($a1)
/* 3A5A98 E00A6548 C642001C */  lwc1      $f2, 0x1c($s2)
/* 3A5A9C E00A654C 24A20018 */  addiu     $v0, $a1, 0x18
/* 3A5AA0 E00A6550 AE220000 */  sw        $v0, ($s1)
/* 3A5AA4 E00A6554 24A20020 */  addiu     $v0, $a1, 0x20
/* 3A5AA8 E00A6558 46041082 */  mul.s     $f2, $f2, $f4
/* 3A5AAC E00A655C 00000000 */  nop
/* 3A5AB0 E00A6560 AE220000 */  sw        $v0, ($s1)
/* 3A5AB4 E00A6564 C6400020 */  lwc1      $f0, 0x20($s2)
/* 3A5AB8 E00A6568 24A20028 */  addiu     $v0, $a1, 0x28
/* 3A5ABC E00A656C AE220000 */  sw        $v0, ($s1)
/* 3A5AC0 E00A6570 46040002 */  mul.s     $f0, $f0, $f4
/* 3A5AC4 E00A6574 00000000 */  nop
/* 3A5AC8 E00A6578 24A20030 */  addiu     $v0, $a1, 0x30
/* 3A5ACC E00A657C 3C04F200 */  lui       $a0, 0xf200
/* 3A5AD0 E00A6580 AE220000 */  sw        $v0, ($s1)
/* 3A5AD4 E00A6584 4600118D */  trunc.w.s $f6, $f2
/* 3A5AD8 E00A6588 44073000 */  mfc1      $a3, $f6
/* 3A5ADC E00A658C 4600018D */  trunc.w.s $f6, $f0
/* 3A5AE0 E00A6590 44093000 */  mfc1      $t1, $f6
/* 3A5AE4 E00A6594 30E30FFF */  andi      $v1, $a3, 0xfff
/* 3A5AE8 E00A6598 00031B00 */  sll       $v1, $v1, 0xc
/* 3A5AEC E00A659C 31220FFF */  andi      $v0, $t1, 0xfff
/* 3A5AF0 E00A65A0 00441025 */  or        $v0, $v0, $a0
/* 3A5AF4 E00A65A4 00621825 */  or        $v1, $v1, $v0
/* 3A5AF8 E00A65A8 24E200FC */  addiu     $v0, $a3, 0xfc
/* 3A5AFC E00A65AC 30420FFF */  andi      $v0, $v0, 0xfff
/* 3A5B00 E00A65B0 00021300 */  sll       $v0, $v0, 0xc
/* 3A5B04 E00A65B4 ACA30020 */  sw        $v1, 0x20($a1)
/* 3A5B08 E00A65B8 252300FC */  addiu     $v1, $t1, 0xfc
/* 3A5B0C E00A65BC 30630FFF */  andi      $v1, $v1, 0xfff
/* 3A5B10 E00A65C0 00431025 */  or        $v0, $v0, $v1
/* 3A5B14 E00A65C4 ACA20024 */  sw        $v0, 0x24($a1)
/* 3A5B18 E00A65C8 C6420024 */  lwc1      $f2, 0x24($s2)
/* 3A5B1C E00A65CC 24A20038 */  addiu     $v0, $a1, 0x38
/* 3A5B20 E00A65D0 46041082 */  mul.s     $f2, $f2, $f4
/* 3A5B24 E00A65D4 00000000 */  nop
/* 3A5B28 E00A65D8 AE220000 */  sw        $v0, ($s1)
/* 3A5B2C E00A65DC C6400028 */  lwc1      $f0, 0x28($s2)
/* 3A5B30 E00A65E0 24A20040 */  addiu     $v0, $a1, 0x40
/* 3A5B34 E00A65E4 AE220000 */  sw        $v0, ($s1)
/* 3A5B38 E00A65E8 46040002 */  mul.s     $f0, $f0, $f4
/* 3A5B3C E00A65EC 00000000 */  nop
/* 3A5B40 E00A65F0 3C020900 */  lui       $v0, 0x900
/* 3A5B44 E00A65F4 24421418 */  addiu     $v0, $v0, 0x1418
/* 3A5B48 E00A65F8 ACA60030 */  sw        $a2, 0x30($a1)
/* 3A5B4C E00A65FC ACA20034 */  sw        $v0, 0x34($a1)
/* 3A5B50 E00A6600 4600118D */  trunc.w.s $f6, $f2
/* 3A5B54 E00A6604 44073000 */  mfc1      $a3, $f6
/* 3A5B58 E00A6608 4600018D */  trunc.w.s $f6, $f0
/* 3A5B5C E00A660C 44093000 */  mfc1      $t1, $f6
/* 3A5B60 E00A6610 30E30FFF */  andi      $v1, $a3, 0xfff
/* 3A5B64 E00A6614 00031B00 */  sll       $v1, $v1, 0xc
/* 3A5B68 E00A6618 31220FFF */  andi      $v0, $t1, 0xfff
/* 3A5B6C E00A661C 00441025 */  or        $v0, $v0, $a0
/* 3A5B70 E00A6620 00621825 */  or        $v1, $v1, $v0
/* 3A5B74 E00A6624 24E200FC */  addiu     $v0, $a3, 0xfc
/* 3A5B78 E00A6628 30420FFF */  andi      $v0, $v0, 0xfff
/* 3A5B7C E00A662C 00021300 */  sll       $v0, $v0, 0xc
/* 3A5B80 E00A6630 ACA30028 */  sw        $v1, 0x28($a1)
/* 3A5B84 E00A6634 252300FC */  addiu     $v1, $t1, 0xfc
/* 3A5B88 E00A6638 30630FFF */  andi      $v1, $v1, 0xfff
/* 3A5B8C E00A663C 3C040100 */  lui       $a0, 0x100
/* 3A5B90 E00A6640 00641825 */  or        $v1, $v1, $a0
/* 3A5B94 E00A6644 00431025 */  or        $v0, $v0, $v1
/* 3A5B98 E00A6648 ACA2002C */  sw        $v0, 0x2c($a1)
/* 3A5B9C E00A664C 24020040 */  addiu     $v0, $zero, 0x40
/* 3A5BA0 E00A6650 ACA80038 */  sw        $t0, 0x38($a1)
/* 3A5BA4 E00A6654 ACA2003C */  sw        $v0, 0x3c($a1)
/* 3A5BA8 E00A6658 24A20048 */  addiu     $v0, $a1, 0x48
/* 3A5BAC E00A665C AE220000 */  sw        $v0, ($s1)
/* 3A5BB0 E00A6660 ACB60040 */  sw        $s6, 0x40($a1)
/* 3A5BB4 E00A6664 ACA00044 */  sw        $zero, 0x44($a1)
/* 3A5BB8 E00A6668 8FBF00AC */  lw        $ra, 0xac($sp)
/* 3A5BBC E00A666C 8FB600A8 */  lw        $s6, 0xa8($sp)
/* 3A5BC0 E00A6670 8FB500A4 */  lw        $s5, 0xa4($sp)
/* 3A5BC4 E00A6674 8FB400A0 */  lw        $s4, 0xa0($sp)
/* 3A5BC8 E00A6678 8FB3009C */  lw        $s3, 0x9c($sp)
/* 3A5BCC E00A667C 8FB20098 */  lw        $s2, 0x98($sp)
/* 3A5BD0 E00A6680 8FB10094 */  lw        $s1, 0x94($sp)
/* 3A5BD4 E00A6684 8FB00090 */  lw        $s0, 0x90($sp)
/* 3A5BD8 E00A6688 03E00008 */  jr        $ra
/* 3A5BDC E00A668C 27BD00B0 */   addiu    $sp, $sp, 0xb0
