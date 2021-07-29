.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel create_status_icon_set
/* 22A08 80047608 3C04800A */  lui       $a0, %hi(D_800A0F44)
/* 22A0C 8004760C 8C840F44 */  lw        $a0, %lo(D_800A0F44)($a0)
/* 22A10 80047610 0000282D */  daddu     $a1, $zero, $zero
.L80047614:
/* 22A14 80047614 8C820000 */  lw        $v0, ($a0)
/* 22A18 80047618 10400006 */  beqz      $v0, .L80047634
/* 22A1C 8004761C 28A20040 */   slti     $v0, $a1, 0x40
/* 22A20 80047620 24A50001 */  addiu     $a1, $a1, 1
/* 22A24 80047624 28A20040 */  slti      $v0, $a1, 0x40
/* 22A28 80047628 1440FFFA */  bnez      $v0, .L80047614
/* 22A2C 8004762C 248400B0 */   addiu    $a0, $a0, 0xb0
/* 22A30 80047630 28A20040 */  slti      $v0, $a1, 0x40
.L80047634:
/* 22A34 80047634 14400003 */  bnez      $v0, .L80047644
/* 22A38 80047638 24030001 */   addiu    $v1, $zero, 1
.L8004763C:
/* 22A3C 8004763C 08011D8F */  j         .L8004763C
/* 22A40 80047640 00000000 */   nop
.L80047644:
/* 22A44 80047644 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 22A48 80047648 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 22A4C 8004764C AC830000 */  sw        $v1, ($a0)
/* 22A50 80047650 80420070 */  lb        $v0, 0x70($v0)
/* 22A54 80047654 10400002 */  beqz      $v0, .L80047660
/* 22A58 80047658 24020003 */   addiu    $v0, $zero, 3
/* 22A5C 8004765C AC820000 */  sw        $v0, ($a0)
.L80047660:
/* 22A60 80047660 00A0102D */  daddu     $v0, $a1, $zero
/* 22A64 80047664 AC800004 */  sw        $zero, 4($a0)
/* 22A68 80047668 AC800008 */  sw        $zero, 8($a0)
/* 22A6C 8004766C AC80000C */  sw        $zero, 0xc($a0)
/* 22A70 80047670 AC800010 */  sw        $zero, 0x10($a0)
/* 22A74 80047674 AC800014 */  sw        $zero, 0x14($a0)
/* 22A78 80047678 AC800018 */  sw        $zero, 0x18($a0)
/* 22A7C 8004767C AC80001C */  sw        $zero, 0x1c($a0)
/* 22A80 80047680 AC800020 */  sw        $zero, 0x20($a0)
/* 22A84 80047684 AC800024 */  sw        $zero, 0x24($a0)
/* 22A88 80047688 AC800028 */  sw        $zero, 0x28($a0)
/* 22A8C 8004768C AC80002C */  sw        $zero, 0x2c($a0)
/* 22A90 80047690 A0800038 */  sb        $zero, 0x38($a0)
/* 22A94 80047694 A0800039 */  sb        $zero, 0x39($a0)
/* 22A98 80047698 A080003A */  sb        $zero, 0x3a($a0)
/* 22A9C 8004769C A080003B */  sb        $zero, 0x3b($a0)
/* 22AA0 800476A0 A0800048 */  sb        $zero, 0x48($a0)
/* 22AA4 800476A4 A0800049 */  sb        $zero, 0x49($a0)
/* 22AA8 800476A8 A080004A */  sb        $zero, 0x4a($a0)
/* 22AAC 800476AC A080004B */  sb        $zero, 0x4b($a0)
/* 22AB0 800476B0 A0800058 */  sb        $zero, 0x58($a0)
/* 22AB4 800476B4 A0800059 */  sb        $zero, 0x59($a0)
/* 22AB8 800476B8 A080005A */  sb        $zero, 0x5a($a0)
/* 22ABC 800476BC A080005B */  sb        $zero, 0x5b($a0)
/* 22AC0 800476C0 A0800068 */  sb        $zero, 0x68($a0)
/* 22AC4 800476C4 A0800069 */  sb        $zero, 0x69($a0)
/* 22AC8 800476C8 A080006A */  sb        $zero, 0x6a($a0)
/* 22ACC 800476CC A080006B */  sb        $zero, 0x6b($a0)
/* 22AD0 800476D0 A0800078 */  sb        $zero, 0x78($a0)
/* 22AD4 800476D4 A0800079 */  sb        $zero, 0x79($a0)
/* 22AD8 800476D8 A0800084 */  sb        $zero, 0x84($a0)
/* 22ADC 800476DC A0800085 */  sb        $zero, 0x85($a0)
/* 22AE0 800476E0 A0800090 */  sb        $zero, 0x90($a0)
/* 22AE4 800476E4 A0800098 */  sb        $zero, 0x98($a0)
/* 22AE8 800476E8 A08000A0 */  sb        $zero, 0xa0($a0)
/* 22AEC 800476EC 03E00008 */  jr        $ra
/* 22AF0 800476F0 A08000A8 */   sb       $zero, 0xa8($a0)
