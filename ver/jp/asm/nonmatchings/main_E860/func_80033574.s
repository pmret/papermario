.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80033574
/* E974 80033574 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E978 80033578 AFB00010 */  sw        $s0, 0x10($sp)
/* E97C 8003357C 3C10800A */  lui       $s0, %hi(D_8009E710)
/* E980 80033580 2610E710 */  addiu     $s0, $s0, %lo(D_8009E710)
/* E984 80033584 24030005 */  addiu     $v1, $zero, 5
/* E988 80033588 AFBF0014 */  sw        $ra, 0x14($sp)
/* E98C 8003358C 82020000 */  lb        $v0, ($s0)
/* E990 80033590 1443000F */  bne       $v0, $v1, .L800335D0
/* E994 80033594 92040000 */   lbu      $a0, ($s0)
/* E998 80033598 3C02800A */  lui       $v0, %hi(D_8009A638)
/* E99C 8003359C 8C42A638 */  lw        $v0, %lo(D_8009A638)($v0)
/* E9A0 800335A0 8C430004 */  lw        $v1, 4($v0)
/* E9A4 800335A4 3C02800A */  lui       $v0, %hi(D_8009A62C)
/* E9A8 800335A8 8C42A62C */  lw        $v0, %lo(D_8009A62C)($v0)
/* E9AC 800335AC 14620089 */  bne       $v1, $v0, .L800337D4
/* E9B0 800335B0 2484FFFF */   addiu    $a0, $a0, -1
/* E9B4 800335B4 3C02800A */  lui       $v0, %hi(D_8009A630)
/* E9B8 800335B8 2442A630 */  addiu     $v0, $v0, %lo(D_8009A630)
/* E9BC 800335BC 8C430000 */  lw        $v1, ($v0)
/* E9C0 800335C0 A2040000 */  sb        $a0, ($s0)
/* E9C4 800335C4 34630008 */  ori       $v1, $v1, 8
/* E9C8 800335C8 0C017F54 */  jal       func_8005FD50
/* E9CC 800335CC AC430000 */   sw       $v1, ($v0)
.L800335D0:
/* E9D0 800335D0 82030000 */  lb        $v1, ($s0)
/* E9D4 800335D4 04600071 */  bltz      $v1, .L8003379C
/* E9D8 800335D8 92020000 */   lbu      $v0, ($s0)
/* E9DC 800335DC 18600003 */  blez      $v1, .L800335EC
/* E9E0 800335E0 2442FFFF */   addiu    $v0, $v0, -1
/* E9E4 800335E4 0800CDF5 */  j         .L800337D4
/* E9E8 800335E8 A2020000 */   sb       $v0, ($s0)
.L800335EC:
/* E9EC 800335EC 3C048007 */  lui       $a0, %hi(D_80077870)
/* E9F0 800335F0 24847870 */  addiu     $a0, $a0, %lo(D_80077870)
/* E9F4 800335F4 24050002 */  addiu     $a1, $zero, 2
/* E9F8 800335F8 2402FFFF */  addiu     $v0, $zero, -1
/* E9FC 800335FC 0C017BE8 */  jal       func_8005EFA0
/* EA00 80033600 A2020000 */   sb       $v0, ($s0)
/* EA04 80033604 0C017F5C */  jal       func_8005FD70
/* EA08 80033608 00000000 */   nop
/* EA0C 8003360C 0C053A3A */  jal       func_8014E8E8
/* EA10 80033610 00000000 */   nop
/* EA14 80033614 0C00EB9A */  jal       func_8003AE68
/* EA18 80033618 00000000 */   nop
/* EA1C 8003361C 3C108007 */  lui       $s0, %hi(D_8007417C)
/* EA20 80033620 2610417C */  addiu     $s0, $s0, %lo(D_8007417C)
/* EA24 80033624 8E030000 */  lw        $v1, ($s0)
/* EA28 80033628 24020001 */  addiu     $v0, $zero, 1
/* EA2C 8003362C 0C016AD4 */  jal       func_8005AB50
/* EA30 80033630 A0620070 */   sb       $v0, 0x70($v1)
/* EA34 80033634 0C00B280 */  jal       func_8002CA00
/* EA38 80033638 00000000 */   nop
/* EA3C 8003363C 0C0AC82D */  jal       func_802B20B4
/* EA40 80033640 00000000 */   nop
/* EA44 80033644 0C0539C8 */  jal       func_8014E720
/* EA48 80033648 0000202D */   daddu    $a0, $zero, $zero
/* EA4C 8003364C 8E100000 */  lw        $s0, ($s0)
/* EA50 80033650 3C03800E */  lui       $v1, %hi(D_800DC4CA)
/* EA54 80033654 9063C4CA */  lbu       $v1, %lo(D_800DC4CA)($v1)
/* EA58 80033658 9205007E */  lbu       $a1, 0x7e($s0)
/* EA5C 8003365C 3C04800E */  lui       $a0, %hi(D_800DC4CB)
/* EA60 80033660 9084C4CB */  lbu       $a0, %lo(D_800DC4CB)($a0)
/* EA64 80033664 30A20001 */  andi      $v0, $a1, 1
/* EA68 80033668 14400007 */  bnez      $v0, .L80033688
/* EA6C 8003366C 34A20001 */   ori      $v0, $a1, 1
/* EA70 80033670 24020026 */  addiu     $v0, $zero, 0x26
/* EA74 80033674 54620006 */  bnel      $v1, $v0, .L80033690
/* EA78 80033678 24040005 */   addiu    $a0, $zero, 5
/* EA7C 8003367C 54800004 */  bnel      $a0, $zero, .L80033690
/* EA80 80033680 24040005 */   addiu    $a0, $zero, 5
/* EA84 80033684 34A20001 */  ori       $v0, $a1, 1
.L80033688:
/* EA88 80033688 A202007E */  sb        $v0, 0x7e($s0)
/* EA8C 8003368C 24040006 */  addiu     $a0, $zero, 6
.L80033690:
/* EA90 80033690 0C044512 */  jal       func_80111448
/* EA94 80033694 00000000 */   nop
/* EA98 80033698 0C046BD5 */  jal       func_8011AF54
/* EA9C 8003369C 00000000 */   nop
/* EAA0 800336A0 0C05343C */  jal       func_8014D0F0
/* EAA4 800336A4 00000000 */   nop
/* EAA8 800336A8 0C052BAA */  jal       func_8014AEA8
/* EAAC 800336AC 00000000 */   nop
/* EAB0 800336B0 0C049770 */  jal       func_80125DC0
/* EAB4 800336B4 00000000 */   nop
/* EAB8 800336B8 0C048D0D */  jal       func_80123434
/* EABC 800336BC 00000000 */   nop
/* EAC0 800336C0 0C04A0B2 */  jal       func_801282C8
/* EAC4 800336C4 00000000 */   nop
/* EAC8 800336C8 0000202D */  daddu     $a0, $zero, $zero
/* EACC 800336CC 0C0528E6 */  jal       func_8014A398
/* EAD0 800336D0 0080282D */   daddu    $a1, $a0, $zero
/* EAD4 800336D4 0C05186C */  jal       func_801461B0
/* EAD8 800336D8 00000000 */   nop
/* EADC 800336DC 0C03A6D4 */  jal       func_800E9B50
/* EAE0 800336E0 00000000 */   nop
/* EAE4 800336E4 0C04D85C */  jal       func_80136170
/* EAE8 800336E8 00000000 */   nop
/* EAEC 800336EC 0C0B0C77 */  jal       func_802C31DC
/* EAF0 800336F0 00000000 */   nop
/* EAF4 800336F4 0C00E05F */  jal       func_8003817C
/* EAF8 800336F8 00000000 */   nop
/* EAFC 800336FC 0C0457B2 */  jal       func_80115EC8
/* EB00 80033700 24040001 */   addiu    $a0, $zero, 1
/* EB04 80033704 0C0529CC */  jal       func_8014A730
/* EB08 80033708 00000000 */   nop
/* EB0C 8003370C 3C040017 */  lui       $a0, 0x17
/* EB10 80033710 248449F0 */  addiu     $a0, $a0, 0x49f0
/* EB14 80033714 3C05001D */  lui       $a1, 0x1d
/* EB18 80033718 24A54720 */  addiu     $a1, $a1, 0x4720
/* EB1C 8003371C 3C068024 */  lui       $a2, %hi(D_8023E000)
/* EB20 80033720 24C6E000 */  addiu     $a2, $a2, %lo(D_8023E000)
/* EB24 80033724 0C00A5BF */  jal       func_800296FC
/* EB28 80033728 00000000 */   nop
/* EB2C 8003372C 0C08F84C */  jal       func_8023E130
/* EB30 80033730 00000000 */   nop
/* EB34 80033734 0C09027D */  jal       func_802409F4
/* EB38 80033738 00000000 */   nop
/* EB3C 8003373C 0C01CAEF */  jal       func_80072BBC
/* EB40 80033740 00000000 */   nop
/* EB44 80033744 3C04800F */  lui       $a0, %hi(D_800F7CC0)
/* EB48 80033748 8C847CC0 */  lw        $a0, %lo(D_800F7CC0)($a0)
/* EB4C 8003374C 8C820004 */  lw        $v0, 4($a0)
/* EB50 80033750 2403FFBF */  addiu     $v1, $zero, -0x41
/* EB54 80033754 3C01800A */  lui       $at, %hi(D_8009E714)
/* EB58 80033758 AC22E714 */  sw        $v0, %lo(D_8009E714)($at)
/* EB5C 8003375C 00431024 */  and       $v0, $v0, $v1
/* EB60 80033760 0C009C57 */  jal       func_8002715C
/* EB64 80033764 AC820004 */   sw       $v0, 4($a0)
/* EB68 80033768 3C01800A */  lui       $at, %hi(D_8009E718)
/* EB6C 8003376C AC22E718 */  sw        $v0, %lo(D_8009E718)($at)
/* EB70 80033770 0C009C15 */  jal       func_80027054
/* EB74 80033774 0000202D */   daddu    $a0, $zero, $zero
/* EB78 80033778 3C05800A */  lui       $a1, %hi(D_8009A630)
/* EB7C 8003377C 24A5A630 */  addiu     $a1, $a1, %lo(D_8009A630)
/* EB80 80033780 2403FFF7 */  addiu     $v1, $zero, -9
/* EB84 80033784 8CA20000 */  lw        $v0, ($a1)
/* EB88 80033788 3C04800A */  lui       $a0, %hi(D_8009E710)
/* EB8C 8003378C 8084E710 */  lb        $a0, %lo(D_8009E710)($a0)
/* EB90 80033790 00431024 */  and       $v0, $v0, $v1
/* EB94 80033794 0481000F */  bgez      $a0, .L800337D4
/* EB98 80033798 ACA20000 */   sw       $v0, ($a1)
.L8003379C:
/* EB9C 8003379C 0C00F879 */  jal       func_8003E1E4
/* EBA0 800337A0 00000000 */   nop
/* EBA4 800337A4 0C08F90E */  jal       func_8023E438
/* EBA8 800337A8 00000000 */   nop
/* EBAC 800337AC 0C00E57C */  jal       func_800395F0
/* EBB0 800337B0 00000000 */   nop
/* EBB4 800337B4 0C04DC17 */  jal       func_8013705C
/* EBB8 800337B8 00000000 */   nop
/* EBBC 800337BC 0C016680 */  jal       func_80059A00
/* EBC0 800337C0 00000000 */   nop
/* EBC4 800337C4 0C046E21 */  jal       func_8011B884
/* EBC8 800337C8 00000000 */   nop
/* EBCC 800337CC 0C00B424 */  jal       func_8002D090
/* EBD0 800337D0 00000000 */   nop
.L800337D4:
/* EBD4 800337D4 8FBF0014 */  lw        $ra, 0x14($sp)
/* EBD8 800337D8 8FB00010 */  lw        $s0, 0x10($sp)
/* EBDC 800337DC 03E00008 */  jr        $ra
/* EBE0 800337E0 27BD0018 */   addiu    $sp, $sp, 0x18
