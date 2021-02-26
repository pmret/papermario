.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800348BC
/* FCBC 800348BC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* FCC0 800348C0 AFB00018 */  sw        $s0, 0x18($sp)
/* FCC4 800348C4 3C10800A */  lui       $s0, %hi(D_8009E731)
/* FCC8 800348C8 2610E731 */  addiu     $s0, $s0, %lo(D_8009E731)
/* FCCC 800348CC AFBF0024 */  sw        $ra, 0x24($sp)
/* FCD0 800348D0 AFB20020 */  sw        $s2, 0x20($sp)
/* FCD4 800348D4 AFB1001C */  sw        $s1, 0x1c($sp)
/* FCD8 800348D8 82030000 */  lb        $v1, ($s0)
/* FCDC 800348DC 24020003 */  addiu     $v0, $zero, 3
/* FCE0 800348E0 106200B8 */  beq       $v1, $v0, .L80034BC4
/* FCE4 800348E4 28620004 */   slti     $v0, $v1, 4
/* FCE8 800348E8 14400006 */  bnez      $v0, .L80034904
/* FCEC 800348EC 28620002 */   slti     $v0, $v1, 2
/* FCF0 800348F0 24020004 */  addiu     $v0, $zero, 4
/* FCF4 800348F4 106200CA */  beq       $v1, $v0, .L80034C20
/* FCF8 800348F8 00000000 */   nop
/* FCFC 800348FC 0800D316 */  j         .L80034C58
/* FD00 80034900 00000000 */   nop
.L80034904:
/* FD04 80034904 104000D4 */  beqz      $v0, .L80034C58
/* FD08 80034908 00000000 */   nop
/* FD0C 8003490C 046000D2 */  bltz      $v1, .L80034C58
/* FD10 80034910 24020004 */   addiu    $v0, $zero, 4
/* FD14 80034914 3C06800A */  lui       $a2, %hi(D_8009E730)
/* FD18 80034918 24C6E730 */  addiu     $a2, $a2, %lo(D_8009E730)
/* FD1C 8003491C 80C30000 */  lb        $v1, ($a2)
/* FD20 80034920 14620007 */  bne       $v1, $v0, .L80034940
/* FD24 80034924 00000000 */   nop
/* FD28 80034928 3C03800A */  lui       $v1, %hi(D_8009A630)
/* FD2C 8003492C 2463A630 */  addiu     $v1, $v1, %lo(D_8009A630)
/* FD30 80034930 8C620000 */  lw        $v0, ($v1)
/* FD34 80034934 34420008 */  ori       $v0, $v0, 8
/* FD38 80034938 AC620000 */  sw        $v0, ($v1)
/* FD3C 8003493C 80C30000 */  lb        $v1, ($a2)
.L80034940:
/* FD40 80034940 046000C5 */  bltz      $v1, .L80034C58
/* FD44 80034944 90C20000 */   lbu      $v0, ($a2)
/* FD48 80034948 10600005 */  beqz      $v1, .L80034960
/* FD4C 8003494C 2442FFFF */   addiu    $v0, $v0, -1
/* FD50 80034950 A0C20000 */  sb        $v0, ($a2)
/* FD54 80034954 00021600 */  sll       $v0, $v0, 0x18
/* FD58 80034958 144000BF */  bnez      $v0, .L80034C58
/* FD5C 8003495C 00000000 */   nop
.L80034960:
/* FD60 80034960 3C048007 */  lui       $a0, %hi(D_80077920)
/* FD64 80034964 24847920 */  addiu     $a0, $a0, %lo(D_80077920)
/* FD68 80034968 24050003 */  addiu     $a1, $zero, 3
/* FD6C 8003496C 2402FFFF */  addiu     $v0, $zero, -1
/* FD70 80034970 0C017BE8 */  jal       func_8005EFA0
/* FD74 80034974 A0C20000 */   sb       $v0, ($a2)
/* FD78 80034978 0C090FB1 */  jal       func_80243EC4
/* FD7C 8003497C 00000000 */   nop
/* FD80 80034980 3C04800A */  lui       $a0, %hi(D_8009A630)
/* FD84 80034984 2484A630 */  addiu     $a0, $a0, %lo(D_8009A630)
/* FD88 80034988 8C820000 */  lw        $v0, ($a0)
/* FD8C 8003498C 2403FFF7 */  addiu     $v1, $zero, -9
/* FD90 80034990 00431024 */  and       $v0, $v0, $v1
/* FD94 80034994 0C016A28 */  jal       func_8005A8A0
/* FD98 80034998 AC820000 */   sw       $v0, ($a0)
/* FD9C 8003499C 3C108007 */  lui       $s0, %hi(D_8007417C)
/* FDA0 800349A0 2610417C */  addiu     $s0, $s0, %lo(D_8007417C)
/* FDA4 800349A4 8E040000 */  lw        $a0, ($s0)
/* FDA8 800349A8 84830086 */  lh        $v1, 0x86($a0)
/* FDAC 800349AC 00031900 */  sll       $v1, $v1, 4
/* FDB0 800349B0 3C068009 */  lui       $a2, %hi(D_800934C4)
/* FDB4 800349B4 00C33021 */  addu      $a2, $a2, $v1
/* FDB8 800349B8 8CC634C4 */  lw        $a2, %lo(D_800934C4)($a2)
/* FDBC 800349BC 0040902D */  daddu     $s2, $v0, $zero
/* FDC0 800349C0 A0800070 */  sb        $zero, 0x70($a0)
/* FDC4 800349C4 8484008C */  lh        $a0, 0x8c($a0)
/* FDC8 800349C8 8E050000 */  lw        $a1, ($s0)
/* FDCC 800349CC 00042140 */  sll       $a0, $a0, 5
/* FDD0 800349D0 94A30148 */  lhu       $v1, 0x148($a1)
/* FDD4 800349D4 00C48821 */  addu      $s1, $a2, $a0
/* FDD8 800349D8 3063FF0F */  andi      $v1, $v1, 0xff0f
/* FDDC 800349DC 0C016B0D */  jal       func_8005AC34
/* FDE0 800349E0 A4A30148 */   sh       $v1, 0x148($a1)
/* FDE4 800349E4 0C00AB27 */  jal       func_8002AC9C
/* FDE8 800349E8 00000000 */   nop
/* FDEC 800349EC 0C017F5C */  jal       func_8005FD70
/* FDF0 800349F0 00000000 */   nop
/* FDF4 800349F4 0C0539C8 */  jal       func_8014E720
/* FDF8 800349F8 24040001 */   addiu    $a0, $zero, 1
/* FDFC 800349FC 8E020000 */  lw        $v0, ($s0)
/* FE00 80034A00 0C044512 */  jal       func_80111448
/* FE04 80034A04 80440084 */   lb       $a0, 0x84($v0)
/* FE08 80034A08 0C046C7E */  jal       func_8011B1F8
/* FE0C 80034A0C 00000000 */   nop
/* FE10 80034A10 0C053468 */  jal       func_8014D1A0
/* FE14 80034A14 00000000 */   nop
/* FE18 80034A18 0C04979A */  jal       func_80125E68
/* FE1C 80034A1C 00000000 */   nop
/* FE20 80034A20 0C048D48 */  jal       func_80123520
/* FE24 80034A24 00000000 */   nop
/* FE28 80034A28 0C04A0C9 */  jal       func_80128324
/* FE2C 80034A2C 00000000 */   nop
/* FE30 80034A30 0000202D */  daddu     $a0, $zero, $zero
/* FE34 80034A34 0C0528E6 */  jal       func_8014A398
/* FE38 80034A38 0080282D */   daddu    $a1, $a0, $zero
/* FE3C 80034A3C 0C0518EC */  jal       func_801463B0
/* FE40 80034A40 00000000 */   nop
/* FE44 80034A44 0C04D891 */  jal       func_80136244
/* FE48 80034A48 00000000 */   nop
/* FE4C 80034A4C 0C0B0CBB */  jal       func_802C32EC
/* FE50 80034A50 00000000 */   nop
/* FE54 80034A54 0C00E07B */  jal       func_800381EC
/* FE58 80034A58 00000000 */   nop
/* FE5C 80034A5C 0C04581A */  jal       func_80116068
/* FE60 80034A60 00000000 */   nop
/* FE64 80034A64 0C0529F6 */  jal       func_8014A7D8
/* FE68 80034A68 00000000 */   nop
/* FE6C 80034A6C 3C04800A */  lui       $a0, %hi(D_8009E734)
/* FE70 80034A70 8C84E734 */  lw        $a0, %lo(D_8009E734)($a0)
/* FE74 80034A74 0C053A2B */  jal       func_8014E8AC
/* FE78 80034A78 00000000 */   nop
/* FE7C 80034A7C 0C053F48 */  jal       func_8014FD20
/* FE80 80034A80 00000000 */   nop
/* FE84 80034A84 0C0168DC */  jal       func_8005A370
/* FE88 80034A88 00000000 */   nop
/* FE8C 80034A8C 3C04800E */  lui       $a0, %hi(D_800D9210)
/* FE90 80034A90 24849210 */  addiu     $a0, $a0, %lo(D_800D9210)
/* FE94 80034A94 0C016A68 */  jal       func_8005A9A0
/* FE98 80034A98 27A50010 */   addiu    $a1, $sp, 0x10
/* FE9C 80034A9C 0040802D */  daddu     $s0, $v0, $zero
/* FEA0 80034AA0 3C058021 */  lui       $a1, %hi(D_80210000)
/* FEA4 80034AA4 24A50000 */  addiu     $a1, $a1, %lo(D_80210000)
/* FEA8 80034AA8 0C01BB74 */  jal       func_8006EDD0
/* FEAC 80034AAC 0200202D */   daddu    $a0, $s0, $zero
/* FEB0 80034AB0 0C00AB0E */  jal       func_8002AC38
/* FEB4 80034AB4 0200202D */   daddu    $a0, $s0, $zero
/* FEB8 80034AB8 0C016B11 */  jal       func_8005AC44
/* FEBC 80034ABC 00000000 */   nop
/* FEC0 80034AC0 0C016B42 */  jal       func_8005AD08
/* FEC4 80034AC4 00000000 */   nop
/* FEC8 80034AC8 8E240008 */  lw        $a0, 8($s1)
/* FECC 80034ACC 10800004 */  beqz      $a0, .L80034AE0
/* FED0 80034AD0 00000000 */   nop
/* FED4 80034AD4 8E25000C */  lw        $a1, 0xc($s1)
/* FED8 80034AD8 0C00A5BF */  jal       func_800296FC
/* FEDC 80034ADC 8E260010 */   lw       $a2, 0x10($s1)
.L80034AE0:
/* FEE0 80034AE0 0C052B88 */  jal       func_8014AE20
/* FEE4 80034AE4 8E240014 */   lw       $a0, 0x14($s1)
/* FEE8 80034AE8 8E440038 */  lw        $a0, 0x38($s2)
/* FEEC 80034AEC 50800005 */  beql      $a0, $zero, .L80034B04
/* FEF0 80034AF0 24040128 */   addiu    $a0, $zero, 0x128
/* FEF4 80034AF4 0C052BB6 */  jal       func_8014AED8
/* FEF8 80034AF8 00000000 */   nop
/* FEFC 80034AFC 0800D2C5 */  j         .L80034B14
/* FF00 80034B00 00000000 */   nop
.L80034B04:
/* FF04 80034B04 240500C8 */  addiu     $a1, $zero, 0xc8
/* FF08 80034B08 2406000C */  addiu     $a2, $zero, 0xc
/* FF0C 80034B0C 0C052BC8 */  jal       func_8014AF20
/* FF10 80034B10 24070014 */   addiu    $a3, $zero, 0x14
.L80034B14:
/* FF14 80034B14 3C038007 */  lui       $v1, %hi(D_8007417C)
/* FF18 80034B18 8C63417C */  lw        $v1, %lo(D_8007417C)($v1)
/* FF1C 80034B1C 9462015E */  lhu       $v0, 0x15e($v1)
/* FF20 80034B20 0C046CCF */  jal       func_8011B33C
/* FF24 80034B24 A462015C */   sh       $v0, 0x15c($v1)
/* FF28 80034B28 0C00EB9C */  jal       func_8003AE70
/* FF2C 80034B2C 00000000 */   nop
/* FF30 80034B30 0C0533DD */  jal       func_8014CF74
/* FF34 80034B34 0000202D */   daddu    $a0, $zero, $zero
/* FF38 80034B38 0C03A619 */  jal       func_800E9864
/* FF3C 80034B3C 00000000 */   nop
/* FF40 80034B40 0C009C15 */  jal       func_80027054
/* FF44 80034B44 24040001 */   addiu    $a0, $zero, 1
/* FF48 80034B48 24020003 */  addiu     $v0, $zero, 3
/* FF4C 80034B4C 3C048011 */  lui       $a0, %hi(D_8010F188)
/* FF50 80034B50 2484F188 */  addiu     $a0, $a0, %lo(D_8010F188)
/* FF54 80034B54 3C01800A */  lui       $at, %hi(D_8009E731)
/* FF58 80034B58 A022E731 */  sb        $v0, %lo(D_8009E731)($at)
/* FF5C 80034B5C 9082000E */  lbu       $v0, 0xe($a0)
/* FF60 80034B60 3C03802E */  lui       $v1, %hi(D_802D9D70)
/* FF64 80034B64 90639D70 */  lbu       $v1, %lo(D_802D9D70)($v1)
/* FF68 80034B68 2442FFFF */  addiu     $v0, $v0, -1
/* FF6C 80034B6C 24630001 */  addiu     $v1, $v1, 1
/* FF70 80034B70 A082000F */  sb        $v0, 0xf($a0)
/* FF74 80034B74 3C01802E */  lui       $at, %hi(D_802D9D71)
/* FF78 80034B78 A0239D71 */  sb        $v1, %lo(D_802D9D71)($at)
/* FF7C 80034B7C 0C00F879 */  jal       func_8003E1E4
/* FF80 80034B80 00000000 */   nop
/* FF84 80034B84 0C00E57C */  jal       func_800395F0
/* FF88 80034B88 00000000 */   nop
/* FF8C 80034B8C 0C037DC8 */  jal       func_800DF720
/* FF90 80034B90 00000000 */   nop
/* FF94 80034B94 0C016680 */  jal       func_80059A00
/* FF98 80034B98 00000000 */   nop
/* FF9C 80034B9C 3C03800A */  lui       $v1, %hi(D_8009E732)
/* FFA0 80034BA0 2463E732 */  addiu     $v1, $v1, %lo(D_8009E732)
/* FFA4 80034BA4 94620000 */  lhu       $v0, ($v1)
/* FFA8 80034BA8 2442FFEC */  addiu     $v0, $v0, -0x14
/* FFAC 80034BAC A4620000 */  sh        $v0, ($v1)
/* FFB0 80034BB0 00021400 */  sll       $v0, $v0, 0x10
/* FFB4 80034BB4 04420028 */  bltzl     $v0, .L80034C58
/* FFB8 80034BB8 A4600000 */   sh       $zero, ($v1)
/* FFBC 80034BBC 0800D316 */  j         .L80034C58
/* FFC0 80034BC0 00000000 */   nop
.L80034BC4:
/* FFC4 80034BC4 0C00F879 */  jal       func_8003E1E4
/* FFC8 80034BC8 00000000 */   nop
/* FFCC 80034BCC 0C00E57C */  jal       func_800395F0
/* FFD0 80034BD0 00000000 */   nop
/* FFD4 80034BD4 0C037DC8 */  jal       func_800DF720
/* FFD8 80034BD8 00000000 */   nop
/* FFDC 80034BDC 0C016680 */  jal       func_80059A00
/* FFE0 80034BE0 00000000 */   nop
/* FFE4 80034BE4 3C04800A */  lui       $a0, %hi(D_8009E732)
/* FFE8 80034BE8 2484E732 */  addiu     $a0, $a0, %lo(D_8009E732)
/* FFEC 80034BEC 84820000 */  lh        $v0, ($a0)
/* FFF0 80034BF0 94830000 */  lhu       $v1, ($a0)
/* FFF4 80034BF4 14400004 */  bnez      $v0, .L80034C08
/* FFF8 80034BF8 2462FFEC */   addiu    $v0, $v1, -0x14
/* FFFC 80034BFC 24020004 */  addiu     $v0, $zero, 4
/* 10000 80034C00 0800D316 */  j         .L80034C58
/* 10004 80034C04 A2020000 */   sb       $v0, ($s0)
.L80034C08:
/* 10008 80034C08 A4820000 */  sh        $v0, ($a0)
/* 1000C 80034C0C 00021400 */  sll       $v0, $v0, 0x10
/* 10010 80034C10 04420011 */  bltzl     $v0, .L80034C58
/* 10014 80034C14 A4800000 */   sh       $zero, ($a0)
/* 10018 80034C18 0800D316 */  j         .L80034C58
/* 1001C 80034C1C 00000000 */   nop
.L80034C20:
/* 10020 80034C20 0C009C15 */  jal       func_80027054
/* 10024 80034C24 0000202D */   daddu    $a0, $zero, $zero
/* 10028 80034C28 0C00F879 */  jal       func_8003E1E4
/* 1002C 80034C2C 00000000 */   nop
/* 10030 80034C30 0C00E57C */  jal       func_800395F0
/* 10034 80034C34 00000000 */   nop
/* 10038 80034C38 0C037DC8 */  jal       func_800DF720
/* 1003C 80034C3C 00000000 */   nop
/* 10040 80034C40 0C016680 */  jal       func_80059A00
/* 10044 80034C44 00000000 */   nop
/* 10048 80034C48 0C038061 */  jal       func_800E0184
/* 1004C 80034C4C 00000000 */   nop
/* 10050 80034C50 0C00CC60 */  jal       func_80033180
/* 10054 80034C54 24040004 */   addiu    $a0, $zero, 4
.L80034C58:
/* 10058 80034C58 8FBF0024 */  lw        $ra, 0x24($sp)
/* 1005C 80034C5C 8FB20020 */  lw        $s2, 0x20($sp)
/* 10060 80034C60 8FB1001C */  lw        $s1, 0x1c($sp)
/* 10064 80034C64 8FB00018 */  lw        $s0, 0x18($sp)
/* 10068 80034C68 03E00008 */  jr        $ra
/* 1006C 80034C6C 27BD0028 */   addiu    $sp, $sp, 0x28
