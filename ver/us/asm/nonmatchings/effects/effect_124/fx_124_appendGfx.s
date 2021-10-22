.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_124_appendGfx
/* 3FEE68 E0114388 27BDFF70 */  addiu     $sp, $sp, -0x90
/* 3FEE6C E011438C 3C07DB06 */  lui       $a3, 0xdb06
/* 3FEE70 E0114390 34E70024 */  ori       $a3, $a3, 0x24
/* 3FEE74 E0114394 3C08DC08 */  lui       $t0, 0xdc08
/* 3FEE78 E0114398 3508000A */  ori       $t0, $t0, 0xa
/* 3FEE7C E011439C 3C09DC08 */  lui       $t1, 0xdc08
/* 3FEE80 E01143A0 3529030A */  ori       $t1, $t1, 0x30a
/* 3FEE84 E01143A4 AFB3006C */  sw        $s3, 0x6c($sp)
/* 3FEE88 E01143A8 0000982D */  daddu     $s3, $zero, $zero
/* 3FEE8C E01143AC 3C02800A */  lui       $v0, %hi(gDisplayContext)
/* 3FEE90 E01143B0 2442A674 */  addiu     $v0, $v0, %lo(gDisplayContext)
/* 3FEE94 E01143B4 AFBE0080 */  sw        $fp, 0x80($sp)
/* 3FEE98 E01143B8 0040F02D */  daddu     $fp, $v0, $zero
/* 3FEE9C E01143BC AFB7007C */  sw        $s7, 0x7c($sp)
/* 3FEEA0 E01143C0 3C178007 */  lui       $s7, %hi(gMatrixListPos)
/* 3FEEA4 E01143C4 26F741F0 */  addiu     $s7, $s7, %lo(gMatrixListPos)
/* 3FEEA8 E01143C8 AFB60078 */  sw        $s6, 0x78($sp)
/* 3FEEAC E01143CC 3C160001 */  lui       $s6, 1
/* 3FEEB0 E01143D0 36D61630 */  ori       $s6, $s6, 0x1630
/* 3FEEB4 E01143D4 3C02800A */  lui       $v0, %hi(gMasterGfxPos)
/* 3FEEB8 E01143D8 2442A66C */  addiu     $v0, $v0, %lo(gMasterGfxPos)
/* 3FEEBC E01143DC AFB20068 */  sw        $s2, 0x68($sp)
/* 3FEEC0 E01143E0 0040902D */  daddu     $s2, $v0, $zero
/* 3FEEC4 E01143E4 3C02E700 */  lui       $v0, 0xe700
/* 3FEEC8 E01143E8 AFBF0084 */  sw        $ra, 0x84($sp)
/* 3FEECC E01143EC AFB50074 */  sw        $s5, 0x74($sp)
/* 3FEED0 E01143F0 AFB40070 */  sw        $s4, 0x70($sp)
/* 3FEED4 E01143F4 AFB10064 */  sw        $s1, 0x64($sp)
/* 3FEED8 E01143F8 AFB00060 */  sw        $s0, 0x60($sp)
/* 3FEEDC E01143FC F7B40088 */  sdc1      $f20, 0x88($sp)
/* 3FEEE0 E0114400 8E430000 */  lw        $v1, ($s2)
/* 3FEEE4 E0114404 4480A000 */  mtc1      $zero, $f20
/* 3FEEE8 E0114408 8C95000C */  lw        $s5, 0xc($a0)
/* 3FEEEC E011440C 0060282D */  daddu     $a1, $v1, $zero
/* 3FEEF0 E0114410 24630008 */  addiu     $v1, $v1, 8
/* 3FEEF4 E0114414 AE430000 */  sw        $v1, ($s2)
/* 3FEEF8 E0114418 8EA60004 */  lw        $a2, 4($s5)
/* 3FEEFC E011441C 02A0882D */  daddu     $s1, $s5, $zero
/* 3FEF00 E0114420 ACA20000 */  sw        $v0, ($a1)
/* 3FEF04 E0114424 24620008 */  addiu     $v0, $v1, 8
/* 3FEF08 E0114428 ACA00004 */  sw        $zero, 4($a1)
/* 3FEF0C E011442C AE420000 */  sw        $v0, ($s2)
/* 3FEF10 E0114430 24620010 */  addiu     $v0, $v1, 0x10
/* 3FEF14 E0114434 AC670000 */  sw        $a3, ($v1)
/* 3FEF18 E0114438 AE420000 */  sw        $v0, ($s2)
/* 3FEF1C E011443C 24620018 */  addiu     $v0, $v1, 0x18
/* 3FEF20 E0114440 AE420000 */  sw        $v0, ($s2)
/* 3FEF24 E0114444 24620020 */  addiu     $v0, $v1, 0x20
/* 3FEF28 E0114448 AE420000 */  sw        $v0, ($s2)
/* 3FEF2C E011444C 8C840010 */  lw        $a0, 0x10($a0)
/* 3FEF30 E0114450 00061100 */  sll       $v0, $a2, 4
/* 3FEF34 E0114454 00461023 */  subu      $v0, $v0, $a2
/* 3FEF38 E0114458 0002A040 */  sll       $s4, $v0, 1
/* 3FEF3C E011445C 8C85001C */  lw        $a1, 0x1c($a0)
/* 3FEF40 E0114460 3C02DE00 */  lui       $v0, 0xde00
/* 3FEF44 E0114464 AC620008 */  sw        $v0, 8($v1)
/* 3FEF48 E0114468 8FC40000 */  lw        $a0, ($fp)
/* 3FEF4C E011446C 3C020900 */  lui       $v0, 0x900
/* 3FEF50 E0114470 24422D70 */  addiu     $v0, $v0, 0x2d70
/* 3FEF54 E0114474 AC62000C */  sw        $v0, 0xc($v1)
/* 3FEF58 E0114478 3C028000 */  lui       $v0, 0x8000
/* 3FEF5C E011447C AC680010 */  sw        $t0, 0x10($v1)
/* 3FEF60 E0114480 AC690018 */  sw        $t1, 0x18($v1)
/* 3FEF64 E0114484 AC640014 */  sw        $a0, 0x14($v1)
/* 3FEF68 E0114488 24840010 */  addiu     $a0, $a0, 0x10
/* 3FEF6C E011448C 00A22821 */  addu      $a1, $a1, $v0
/* 3FEF70 E0114490 AC64001C */  sw        $a0, 0x1c($v1)
/* 3FEF74 E0114494 AC650004 */  sw        $a1, 4($v1)
.LE0114498:
/* 3FEF78 E0114498 8E220008 */  lw        $v0, 8($s1)
/* 3FEF7C E011449C 30420001 */  andi      $v0, $v0, 1
/* 3FEF80 E01144A0 1040006D */  beqz      $v0, .LE0114658
/* 3FEF84 E01144A4 27A40020 */   addiu    $a0, $sp, 0x20
/* 3FEF88 E01144A8 3C013F80 */  lui       $at, 0x3f80
/* 3FEF8C E01144AC 44810000 */  mtc1      $at, $f0
/* 3FEF90 E01144B0 C62400B8 */  lwc1      $f4, 0xb8($s1)
/* 3FEF94 E01144B4 E7A00010 */  swc1      $f0, 0x10($sp)
/* 3FEF98 E01144B8 C6200034 */  lwc1      $f0, 0x34($s1)
/* 3FEF9C E01144BC E7A00014 */  swc1      $f0, 0x14($sp)
/* 3FEFA0 E01144C0 C6200060 */  lwc1      $f0, 0x60($s1)
/* 3FEFA4 E01144C4 C6220110 */  lwc1      $f2, 0x110($s1)
/* 3FEFA8 E01144C8 4405A000 */  mfc1      $a1, $f20
/* 3FEFAC E01144CC 46020000 */  add.s     $f0, $f0, $f2
/* 3FEFB0 E01144D0 3C014334 */  lui       $at, 0x4334
/* 3FEFB4 E01144D4 44811000 */  mtc1      $at, $f2
/* 3FEFB8 E01144D8 4407A000 */  mfc1      $a3, $f20
/* 3FEFBC E01144DC 46041081 */  sub.s     $f2, $f2, $f4
/* 3FEFC0 E01144E0 E7A00018 */  swc1      $f0, 0x18($sp)
/* 3FEFC4 E01144E4 C620008C */  lwc1      $f0, 0x8c($s1)
/* 3FEFC8 E01144E8 44061000 */  mfc1      $a2, $f2
/* 3FEFCC E01144EC 0C080180 */  jal       shim_guPositionF
/* 3FEFD0 E01144F0 E7A0001C */   swc1     $f0, 0x1c($sp)
/* 3FEFD4 E01144F4 27A40020 */  addiu     $a0, $sp, 0x20
/* 3FEFD8 E01144F8 96E50000 */  lhu       $a1, ($s7)
/* 3FEFDC E01144FC 8FC20000 */  lw        $v0, ($fp)
/* 3FEFE0 E0114500 00052980 */  sll       $a1, $a1, 6
/* 3FEFE4 E0114504 00B62821 */  addu      $a1, $a1, $s6
/* 3FEFE8 E0114508 0C080118 */  jal       shim_guMtxF2L
/* 3FEFEC E011450C 00452821 */   addu     $a1, $v0, $a1
/* 3FEFF0 E0114510 3C02DA38 */  lui       $v0, 0xda38
/* 3FEFF4 E0114514 34420002 */  ori       $v0, $v0, 2
/* 3FEFF8 E0114518 02B38021 */  addu      $s0, $s5, $s3
/* 3FEFFC E011451C 8E440000 */  lw        $a0, ($s2)
/* 3FF000 E0114520 96E30000 */  lhu       $v1, ($s7)
/* 3FF004 E0114524 0080282D */  daddu     $a1, $a0, $zero
/* 3FF008 E0114528 24840008 */  addiu     $a0, $a0, 8
/* 3FF00C E011452C AE440000 */  sw        $a0, ($s2)
/* 3FF010 E0114530 ACA20000 */  sw        $v0, ($a1)
/* 3FF014 E0114534 24620001 */  addiu     $v0, $v1, 1
/* 3FF018 E0114538 3063FFFF */  andi      $v1, $v1, 0xffff
/* 3FF01C E011453C 00031980 */  sll       $v1, $v1, 6
/* 3FF020 E0114540 A6E20000 */  sh        $v0, ($s7)
/* 3FF024 E0114544 8FC20000 */  lw        $v0, ($fp)
/* 3FF028 E0114548 00761821 */  addu      $v1, $v1, $s6
/* 3FF02C E011454C 00431021 */  addu      $v0, $v0, $v1
/* 3FF030 E0114550 ACA20004 */  sw        $v0, 4($a1)
/* 3FF034 E0114554 24820008 */  addiu     $v0, $a0, 8
/* 3FF038 E0114558 3C0ADE00 */  lui       $t2, 0xde00
/* 3FF03C E011455C AE420000 */  sw        $v0, ($s2)
/* 3FF040 E0114560 AC8A0000 */  sw        $t2, ($a0)
/* 3FF044 E0114564 920200E4 */  lbu       $v0, 0xe4($s0)
/* 3FF048 E0114568 3C0AE011 */  lui       $t2, %hi(D_E0114718)
/* 3FF04C E011456C 254A4718 */  addiu     $t2, $t2, %lo(D_E0114718)
/* 3FF050 E0114570 00021080 */  sll       $v0, $v0, 2
/* 3FF054 E0114574 004A1021 */  addu      $v0, $v0, $t2
/* 3FF058 E0114578 8C420000 */  lw        $v0, ($v0)
/* 3FF05C E011457C AC820004 */  sw        $v0, 4($a0)
/* 3FF060 E0114580 920200E4 */  lbu       $v0, 0xe4($s0)
/* 3FF064 E0114584 2442FFF8 */  addiu     $v0, $v0, -8
/* 3FF068 E0114588 2C420002 */  sltiu     $v0, $v0, 2
/* 3FF06C E011458C 1040001B */  beqz      $v0, .LE01145FC
/* 3FF070 E0114590 3C07D838 */   lui      $a3, 0xd838
/* 3FF074 E0114594 44946000 */  mtc1      $s4, $f12
/* 3FF078 E0114598 00000000 */  nop
/* 3FF07C E011459C 0C080140 */  jal       shim_sin_deg
/* 3FF080 E01145A0 46806320 */   cvt.s.w  $f12, $f12
/* 3FF084 E01145A4 3C01427C */  lui       $at, 0x427c
/* 3FF088 E01145A8 44811000 */  mtc1      $at, $f2
/* 3FF08C E01145AC 8E420000 */  lw        $v0, ($s2)
/* 3FF090 E01145B0 46020002 */  mul.s     $f0, $f0, $f2
/* 3FF094 E01145B4 00000000 */  nop
/* 3FF098 E01145B8 0040282D */  daddu     $a1, $v0, $zero
/* 3FF09C E01145BC 24420008 */  addiu     $v0, $v0, 8
/* 3FF0A0 E01145C0 AE420000 */  sw        $v0, ($s2)
/* 3FF0A4 E01145C4 46020000 */  add.s     $f0, $f0, $f2
/* 3FF0A8 E01145C8 3C02FA00 */  lui       $v0, 0xfa00
/* 3FF0AC E01145CC ACA20000 */  sw        $v0, ($a1)
/* 3FF0B0 E01145D0 4600018D */  trunc.w.s $f6, $f0
/* 3FF0B4 E01145D4 44023000 */  mfc1      $v0, $f6
/* 3FF0B8 E01145D8 00000000 */  nop
/* 3FF0BC E01145DC 304200FF */  andi      $v0, $v0, 0xff
/* 3FF0C0 E01145E0 00022600 */  sll       $a0, $v0, 0x18
/* 3FF0C4 E01145E4 00021C00 */  sll       $v1, $v0, 0x10
/* 3FF0C8 E01145E8 00832025 */  or        $a0, $a0, $v1
/* 3FF0CC E01145EC 00021200 */  sll       $v0, $v0, 8
/* 3FF0D0 E01145F0 00822025 */  or        $a0, $a0, $v0
/* 3FF0D4 E01145F4 ACA40004 */  sw        $a0, 4($a1)
/* 3FF0D8 E01145F8 3C07D838 */  lui       $a3, 0xd838
.LE01145FC:
/* 3FF0DC E01145FC 8E440000 */  lw        $a0, ($s2)
/* 3FF0E0 E0114600 34E70002 */  ori       $a3, $a3, 2
/* 3FF0E4 E0114604 0080302D */  daddu     $a2, $a0, $zero
/* 3FF0E8 E0114608 24840008 */  addiu     $a0, $a0, 8
/* 3FF0EC E011460C 3C0ADE00 */  lui       $t2, 0xde00
/* 3FF0F0 E0114610 AE440000 */  sw        $a0, ($s2)
/* 3FF0F4 E0114614 ACCA0000 */  sw        $t2, ($a2)
/* 3FF0F8 E0114618 3C0AE011 */  lui       $t2, %hi(D_E01146A0)
/* 3FF0FC E011461C 254A46A0 */  addiu     $t2, $t2, %lo(D_E01146A0)
/* 3FF100 E0114620 920500E4 */  lbu       $a1, 0xe4($s0)
/* 3FF104 E0114624 92030105 */  lbu       $v1, 0x105($s0)
/* 3FF108 E0114628 00051040 */  sll       $v0, $a1, 1
/* 3FF10C E011462C 00451021 */  addu      $v0, $v0, $a1
/* 3FF110 E0114630 00431021 */  addu      $v0, $v0, $v1
/* 3FF114 E0114634 00021080 */  sll       $v0, $v0, 2
/* 3FF118 E0114638 004A1021 */  addu      $v0, $v0, $t2
/* 3FF11C E011463C 8C430000 */  lw        $v1, ($v0)
/* 3FF120 E0114640 24820008 */  addiu     $v0, $a0, 8
/* 3FF124 E0114644 AE420000 */  sw        $v0, ($s2)
/* 3FF128 E0114648 24020040 */  addiu     $v0, $zero, 0x40
/* 3FF12C E011464C ACC30004 */  sw        $v1, 4($a2)
/* 3FF130 E0114650 AC870000 */  sw        $a3, ($a0)
/* 3FF134 E0114654 AC820004 */  sw        $v0, 4($a0)
.LE0114658:
/* 3FF138 E0114658 26940014 */  addiu     $s4, $s4, 0x14
/* 3FF13C E011465C 26730001 */  addiu     $s3, $s3, 1
/* 3FF140 E0114660 2A62000B */  slti      $v0, $s3, 0xb
/* 3FF144 E0114664 1440FF8C */  bnez      $v0, .LE0114498
/* 3FF148 E0114668 26310004 */   addiu    $s1, $s1, 4
/* 3FF14C E011466C 8FBF0084 */  lw        $ra, 0x84($sp)
/* 3FF150 E0114670 8FBE0080 */  lw        $fp, 0x80($sp)
/* 3FF154 E0114674 8FB7007C */  lw        $s7, 0x7c($sp)
/* 3FF158 E0114678 8FB60078 */  lw        $s6, 0x78($sp)
/* 3FF15C E011467C 8FB50074 */  lw        $s5, 0x74($sp)
/* 3FF160 E0114680 8FB40070 */  lw        $s4, 0x70($sp)
/* 3FF164 E0114684 8FB3006C */  lw        $s3, 0x6c($sp)
/* 3FF168 E0114688 8FB20068 */  lw        $s2, 0x68($sp)
/* 3FF16C E011468C 8FB10064 */  lw        $s1, 0x64($sp)
/* 3FF170 E0114690 8FB00060 */  lw        $s0, 0x60($sp)
/* 3FF174 E0114694 D7B40088 */  ldc1      $f20, 0x88($sp)
/* 3FF178 E0114698 03E00008 */  jr        $ra
/* 3FF17C E011469C 27BD0090 */   addiu    $sp, $sp, 0x90
