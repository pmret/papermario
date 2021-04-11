.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024190C_96AACC
/* 96AACC 8024190C 27BDFF00 */  addiu     $sp, $sp, -0x100
/* 96AAD0 80241910 AFBF00EC */  sw        $ra, 0xec($sp)
/* 96AAD4 80241914 AFBE00E8 */  sw        $fp, 0xe8($sp)
/* 96AAD8 80241918 AFB700E4 */  sw        $s7, 0xe4($sp)
/* 96AADC 8024191C AFB600E0 */  sw        $s6, 0xe0($sp)
/* 96AAE0 80241920 AFB500DC */  sw        $s5, 0xdc($sp)
/* 96AAE4 80241924 AFB400D8 */  sw        $s4, 0xd8($sp)
/* 96AAE8 80241928 AFB300D4 */  sw        $s3, 0xd4($sp)
/* 96AAEC 8024192C AFB200D0 */  sw        $s2, 0xd0($sp)
/* 96AAF0 80241930 AFB100CC */  sw        $s1, 0xcc($sp)
/* 96AAF4 80241934 AFB000C8 */  sw        $s0, 0xc8($sp)
/* 96AAF8 80241938 F7B600F8 */  sdc1      $f22, 0xf8($sp)
/* 96AAFC 8024193C F7B400F0 */  sdc1      $f20, 0xf0($sp)
/* 96AB00 80241940 AFA40100 */  sw        $a0, 0x100($sp)
/* 96AB04 80241944 AFA50104 */  sw        $a1, 0x104($sp)
/* 96AB08 80241948 8C820000 */  lw        $v0, ($a0)
/* 96AB0C 8024194C 10400184 */  beqz      $v0, .L80241F60
/* 96AB10 80241950 3C02DE00 */   lui      $v0, 0xde00
/* 96AB14 80241954 3C1E800A */  lui       $fp, %hi(gMasterGfxPos)
/* 96AB18 80241958 27DEA66C */  addiu     $fp, $fp, %lo(gMasterGfxPos)
/* 96AB1C 8024195C 8FC80000 */  lw        $t0, ($fp)
/* 96AB20 80241960 0100182D */  daddu     $v1, $t0, $zero
/* 96AB24 80241964 25080008 */  addiu     $t0, $t0, 8
/* 96AB28 80241968 AFC80000 */  sw        $t0, ($fp)
/* 96AB2C 8024196C AC620000 */  sw        $v0, ($v1)
/* 96AB30 80241970 3C028024 */  lui       $v0, %hi(dro_02_D_802478C8_970A88)
/* 96AB34 80241974 244278C8 */  addiu     $v0, $v0, %lo(dro_02_D_802478C8_970A88)
/* 96AB38 80241978 AC620004 */  sw        $v0, 4($v1)
/* 96AB3C 8024197C 8FAD0100 */  lw        $t5, 0x100($sp)
/* 96AB40 80241980 8DA30000 */  lw        $v1, ($t5)
/* 96AB44 80241984 24020001 */  addiu     $v0, $zero, 1
/* 96AB48 80241988 10620006 */  beq       $v1, $v0, .L802419A4
/* 96AB4C 8024198C 24020004 */   addiu    $v0, $zero, 4
/* 96AB50 80241990 10620004 */  beq       $v1, $v0, .L802419A4
/* 96AB54 80241994 24020005 */   addiu    $v0, $zero, 5
/* 96AB58 80241998 14620126 */  bne       $v1, $v0, .L80241E34
/* 96AB5C 8024199C 24020002 */   addiu    $v0, $zero, 2
/* 96AB60 802419A0 8FAD0100 */  lw        $t5, 0x100($sp)
.L802419A4:
/* 96AB64 802419A4 27B00058 */  addiu     $s0, $sp, 0x58
/* 96AB68 802419A8 8DA50004 */  lw        $a1, 4($t5)
/* 96AB6C 802419AC 8DA60008 */  lw        $a2, 8($t5)
/* 96AB70 802419B0 8DA7000C */  lw        $a3, 0xc($t5)
/* 96AB74 802419B4 0C019E40 */  jal       guTranslateF
/* 96AB78 802419B8 0200202D */   daddu    $a0, $s0, $zero
/* 96AB7C 802419BC 0200202D */  daddu     $a0, $s0, $zero
/* 96AB80 802419C0 8FA50104 */  lw        $a1, 0x104($sp)
/* 96AB84 802419C4 4480A000 */  mtc1      $zero, $f20
/* 96AB88 802419C8 0C019D80 */  jal       guMtxCatF
/* 96AB8C 802419CC 27A60018 */   addiu    $a2, $sp, 0x18
/* 96AB90 802419D0 8FAD0100 */  lw        $t5, 0x100($sp)
/* 96AB94 802419D4 3C013F80 */  lui       $at, 0x3f80
/* 96AB98 802419D8 4481B000 */  mtc1      $at, $f22
/* 96AB9C 802419DC 4406A000 */  mfc1      $a2, $f20
/* 96ABA0 802419E0 3C120001 */  lui       $s2, 1
/* 96ABA4 802419E4 E7B40010 */  swc1      $f20, 0x10($sp)
/* 96ABA8 802419E8 8DA50010 */  lw        $a1, 0x10($t5)
/* 96ABAC 802419EC 4407B000 */  mfc1      $a3, $f22
/* 96ABB0 802419F0 0C019EC8 */  jal       guRotateF
/* 96ABB4 802419F4 0200202D */   daddu    $a0, $s0, $zero
/* 96ABB8 802419F8 0200202D */  daddu     $a0, $s0, $zero
/* 96ABBC 802419FC 27A50018 */  addiu     $a1, $sp, 0x18
/* 96ABC0 80241A00 0C019D80 */  jal       guMtxCatF
/* 96ABC4 80241A04 00A0302D */   daddu    $a2, $a1, $zero
/* 96ABC8 80241A08 8FAD0100 */  lw        $t5, 0x100($sp)
/* 96ABCC 80241A0C 4406B000 */  mfc1      $a2, $f22
/* 96ABD0 80241A10 4407A000 */  mfc1      $a3, $f20
/* 96ABD4 80241A14 36521630 */  ori       $s2, $s2, 0x1630
/* 96ABD8 80241A18 E7B40010 */  swc1      $f20, 0x10($sp)
/* 96ABDC 80241A1C 8DA50014 */  lw        $a1, 0x14($t5)
/* 96ABE0 80241A20 0C019EC8 */  jal       guRotateF
/* 96ABE4 80241A24 0200202D */   daddu    $a0, $s0, $zero
/* 96ABE8 80241A28 0200202D */  daddu     $a0, $s0, $zero
/* 96ABEC 80241A2C 27A50018 */  addiu     $a1, $sp, 0x18
/* 96ABF0 80241A30 0C019D80 */  jal       guMtxCatF
/* 96ABF4 80241A34 00A0302D */   daddu    $a2, $a1, $zero
/* 96ABF8 80241A38 27A40018 */  addiu     $a0, $sp, 0x18
/* 96ABFC 80241A3C 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* 96AC00 80241A40 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* 96AC04 80241A44 3C11800A */  lui       $s1, %hi(gDisplayContext)
/* 96AC08 80241A48 2631A674 */  addiu     $s1, $s1, %lo(gDisplayContext)
/* 96AC0C 80241A4C 96050000 */  lhu       $a1, ($s0)
/* 96AC10 80241A50 8E220000 */  lw        $v0, ($s1)
/* 96AC14 80241A54 00052980 */  sll       $a1, $a1, 6
/* 96AC18 80241A58 00B22821 */  addu      $a1, $a1, $s2
/* 96AC1C 80241A5C 0C019D40 */  jal       guMtxF2L
/* 96AC20 80241A60 00452821 */   addu     $a1, $v0, $a1
/* 96AC24 80241A64 3C03DA38 */  lui       $v1, 0xda38
/* 96AC28 80241A68 3C06800A */  lui       $a2, %hi(gMasterGfxPos)
/* 96AC2C 80241A6C 24C6A66C */  addiu     $a2, $a2, %lo(gMasterGfxPos)
/* 96AC30 80241A70 34630002 */  ori       $v1, $v1, 2
/* 96AC34 80241A74 8CC50000 */  lw        $a1, ($a2)
/* 96AC38 80241A78 96020000 */  lhu       $v0, ($s0)
/* 96AC3C 80241A7C 00A0202D */  daddu     $a0, $a1, $zero
/* 96AC40 80241A80 24A50008 */  addiu     $a1, $a1, 8
/* 96AC44 80241A84 ACC50000 */  sw        $a1, ($a2)
/* 96AC48 80241A88 AC830000 */  sw        $v1, ($a0)
/* 96AC4C 80241A8C 24430001 */  addiu     $v1, $v0, 1
/* 96AC50 80241A90 3042FFFF */  andi      $v0, $v0, 0xffff
/* 96AC54 80241A94 00021180 */  sll       $v0, $v0, 6
/* 96AC58 80241A98 A6030000 */  sh        $v1, ($s0)
/* 96AC5C 80241A9C 8E230000 */  lw        $v1, ($s1)
/* 96AC60 80241AA0 00521021 */  addu      $v0, $v0, $s2
/* 96AC64 80241AA4 00621821 */  addu      $v1, $v1, $v0
/* 96AC68 80241AA8 3C028000 */  lui       $v0, 0x8000
/* 96AC6C 80241AAC 00621821 */  addu      $v1, $v1, $v0
/* 96AC70 80241AB0 AC830004 */  sw        $v1, 4($a0)
/* 96AC74 80241AB4 8FAD0100 */  lw        $t5, 0x100($sp)
/* 96AC78 80241AB8 8DA30000 */  lw        $v1, ($t5)
/* 96AC7C 80241ABC 24020001 */  addiu     $v0, $zero, 1
/* 96AC80 80241AC0 10620003 */  beq       $v1, $v0, .L80241AD0
/* 96AC84 80241AC4 24020004 */   addiu    $v0, $zero, 4
/* 96AC88 80241AC8 1462000B */  bne       $v1, $v0, .L80241AF8
/* 96AC8C 80241ACC 24020001 */   addiu    $v0, $zero, 1
.L80241AD0:
/* 96AC90 80241AD0 24A20008 */  addiu     $v0, $a1, 8
/* 96AC94 80241AD4 ACC20000 */  sw        $v0, ($a2)
/* 96AC98 80241AD8 3C02DE00 */  lui       $v0, 0xde00
/* 96AC9C 80241ADC ACA20000 */  sw        $v0, ($a1)
/* 96ACA0 80241AE0 3C028024 */  lui       $v0, %hi(dro_02_D_802479B8_970B78)
/* 96ACA4 80241AE4 244279B8 */  addiu     $v0, $v0, %lo(dro_02_D_802479B8_970B78)
/* 96ACA8 80241AE8 ACA20004 */  sw        $v0, 4($a1)
/* 96ACAC 80241AEC 8FAD0100 */  lw        $t5, 0x100($sp)
/* 96ACB0 80241AF0 8DA30000 */  lw        $v1, ($t5)
/* 96ACB4 80241AF4 24020001 */  addiu     $v0, $zero, 1
.L80241AF8:
/* 96ACB8 80241AF8 10620003 */  beq       $v1, $v0, .L80241B08
/* 96ACBC 80241AFC 24020005 */   addiu    $v0, $zero, 5
/* 96ACC0 80241B00 146200C0 */  bne       $v1, $v0, .L80241E04
/* 96ACC4 80241B04 3C06D838 */   lui      $a2, 0xd838
.L80241B08:
/* 96ACC8 80241B08 27A400B0 */  addiu     $a0, $sp, 0xb0
/* 96ACCC 80241B0C 8FAD0100 */  lw        $t5, 0x100($sp)
/* 96ACD0 80241B10 3C130001 */  lui       $s3, 1
/* 96ACD4 80241B14 8DA50018 */  lw        $a1, 0x18($t5)
/* 96ACD8 80241B18 8DA6001C */  lw        $a2, 0x1c($t5)
/* 96ACDC 80241B1C 0C0B7811 */  jal       func_802DE044
/* 96ACE0 80241B20 36731630 */   ori      $s3, $s3, 0x1630
/* 96ACE4 80241B24 3C02E300 */  lui       $v0, 0xe300
/* 96ACE8 80241B28 34421001 */  ori       $v0, $v0, 0x1001
/* 96ACEC 80241B2C 3C08F500 */  lui       $t0, 0xf500
/* 96ACF0 80241B30 35080100 */  ori       $t0, $t0, 0x100
/* 96ACF4 80241B34 3C090703 */  lui       $t1, 0x703
/* 96ACF8 80241B38 3529C000 */  ori       $t1, $t1, 0xc000
/* 96ACFC 80241B3C 3C0B070A */  lui       $t3, 0x70a
/* 96AD00 80241B40 356B0280 */  ori       $t3, $t3, 0x280
/* 96AD04 80241B44 3C0C000A */  lui       $t4, 0xa
/* 96AD08 80241B48 358C0280 */  ori       $t4, $t4, 0x280
/* 96AD0C 80241B4C 27A40018 */  addiu     $a0, $sp, 0x18
/* 96AD10 80241B50 3C10800A */  lui       $s0, %hi(gMasterGfxPos)
/* 96AD14 80241B54 2610A66C */  addiu     $s0, $s0, %lo(gMasterGfxPos)
/* 96AD18 80241B58 3C0A0700 */  lui       $t2, 0x700
/* 96AD1C 80241B5C 8E050000 */  lw        $a1, ($s0)
/* 96AD20 80241B60 44800000 */  mtc1      $zero, $f0
/* 96AD24 80241B64 00A0182D */  daddu     $v1, $a1, $zero
/* 96AD28 80241B68 44060000 */  mfc1      $a2, $f0
/* 96AD2C 80241B6C 24A50008 */  addiu     $a1, $a1, 8
/* 96AD30 80241B70 AE050000 */  sw        $a1, ($s0)
/* 96AD34 80241B74 AC620000 */  sw        $v0, ($v1)
/* 96AD38 80241B78 34028000 */  ori       $v0, $zero, 0x8000
/* 96AD3C 80241B7C AC620004 */  sw        $v0, 4($v1)
/* 96AD40 80241B80 24A20008 */  addiu     $v0, $a1, 8
/* 96AD44 80241B84 AE020000 */  sw        $v0, ($s0)
/* 96AD48 80241B88 3C02FD10 */  lui       $v0, 0xfd10
/* 96AD4C 80241B8C ACA20000 */  sw        $v0, ($a1)
/* 96AD50 80241B90 24A20010 */  addiu     $v0, $a1, 0x10
/* 96AD54 80241B94 AE020000 */  sw        $v0, ($s0)
/* 96AD58 80241B98 8FA300B4 */  lw        $v1, 0xb4($sp)
/* 96AD5C 80241B9C 3C02E800 */  lui       $v0, 0xe800
/* 96AD60 80241BA0 ACA20008 */  sw        $v0, 8($a1)
/* 96AD64 80241BA4 24A20018 */  addiu     $v0, $a1, 0x18
/* 96AD68 80241BA8 ACA0000C */  sw        $zero, 0xc($a1)
/* 96AD6C 80241BAC AE020000 */  sw        $v0, ($s0)
/* 96AD70 80241BB0 24A20020 */  addiu     $v0, $a1, 0x20
/* 96AD74 80241BB4 ACA80010 */  sw        $t0, 0x10($a1)
/* 96AD78 80241BB8 3C08E600 */  lui       $t0, 0xe600
/* 96AD7C 80241BBC ACAA0014 */  sw        $t2, 0x14($a1)
/* 96AD80 80241BC0 AE020000 */  sw        $v0, ($s0)
/* 96AD84 80241BC4 24A20028 */  addiu     $v0, $a1, 0x28
/* 96AD88 80241BC8 ACA80018 */  sw        $t0, 0x18($a1)
/* 96AD8C 80241BCC ACA0001C */  sw        $zero, 0x1c($a1)
/* 96AD90 80241BD0 AE020000 */  sw        $v0, ($s0)
/* 96AD94 80241BD4 3C02F000 */  lui       $v0, 0xf000
/* 96AD98 80241BD8 ACA20020 */  sw        $v0, 0x20($a1)
/* 96AD9C 80241BDC 24A20030 */  addiu     $v0, $a1, 0x30
/* 96ADA0 80241BE0 ACA90024 */  sw        $t1, 0x24($a1)
/* 96ADA4 80241BE4 3C09E700 */  lui       $t1, 0xe700
/* 96ADA8 80241BE8 AE020000 */  sw        $v0, ($s0)
/* 96ADAC 80241BEC ACA90028 */  sw        $t1, 0x28($a1)
/* 96ADB0 80241BF0 ACA0002C */  sw        $zero, 0x2c($a1)
/* 96ADB4 80241BF4 ACA30004 */  sw        $v1, 4($a1)
/* 96ADB8 80241BF8 8FA200B8 */  lw        $v0, 0xb8($sp)
/* 96ADBC 80241BFC 24A30038 */  addiu     $v1, $a1, 0x38
/* 96ADC0 80241C00 AE030000 */  sw        $v1, ($s0)
/* 96ADC4 80241C04 3C03FD48 */  lui       $v1, 0xfd48
/* 96ADC8 80241C08 00021043 */  sra       $v0, $v0, 1
/* 96ADCC 80241C0C 2442FFFF */  addiu     $v0, $v0, -1
/* 96ADD0 80241C10 30420FFF */  andi      $v0, $v0, 0xfff
/* 96ADD4 80241C14 00431025 */  or        $v0, $v0, $v1
/* 96ADD8 80241C18 ACA20030 */  sw        $v0, 0x30($a1)
/* 96ADDC 80241C1C 8FA300B0 */  lw        $v1, 0xb0($sp)
/* 96ADE0 80241C20 24A20040 */  addiu     $v0, $a1, 0x40
/* 96ADE4 80241C24 AE020000 */  sw        $v0, ($s0)
/* 96ADE8 80241C28 ACA30034 */  sw        $v1, 0x34($a1)
/* 96ADEC 80241C2C 8FA200B8 */  lw        $v0, 0xb8($sp)
/* 96ADF0 80241C30 24A30048 */  addiu     $v1, $a1, 0x48
/* 96ADF4 80241C34 AE030000 */  sw        $v1, ($s0)
/* 96ADF8 80241C38 3C03F548 */  lui       $v1, 0xf548
/* 96ADFC 80241C3C ACAB003C */  sw        $t3, 0x3c($a1)
/* 96AE00 80241C40 00021043 */  sra       $v0, $v0, 1
/* 96AE04 80241C44 24420007 */  addiu     $v0, $v0, 7
/* 96AE08 80241C48 000210C3 */  sra       $v0, $v0, 3
/* 96AE0C 80241C4C 304201FF */  andi      $v0, $v0, 0x1ff
/* 96AE10 80241C50 00021240 */  sll       $v0, $v0, 9
/* 96AE14 80241C54 00431025 */  or        $v0, $v0, $v1
/* 96AE18 80241C58 ACA20038 */  sw        $v0, 0x38($a1)
/* 96AE1C 80241C5C 3C02F400 */  lui       $v0, 0xf400
/* 96AE20 80241C60 ACA80040 */  sw        $t0, 0x40($a1)
/* 96AE24 80241C64 ACA00044 */  sw        $zero, 0x44($a1)
/* 96AE28 80241C68 ACA20048 */  sw        $v0, 0x48($a1)
/* 96AE2C 80241C6C 8FA200B8 */  lw        $v0, 0xb8($sp)
/* 96AE30 80241C70 8FA300BC */  lw        $v1, 0xbc($sp)
/* 96AE34 80241C74 24A80050 */  addiu     $t0, $a1, 0x50
/* 96AE38 80241C78 AE080000 */  sw        $t0, ($s0)
/* 96AE3C 80241C7C ACA90050 */  sw        $t1, 0x50($a1)
/* 96AE40 80241C80 ACA00054 */  sw        $zero, 0x54($a1)
/* 96AE44 80241C84 2442FFFF */  addiu     $v0, $v0, -1
/* 96AE48 80241C88 00021040 */  sll       $v0, $v0, 1
/* 96AE4C 80241C8C 30420FFF */  andi      $v0, $v0, 0xfff
/* 96AE50 80241C90 00021300 */  sll       $v0, $v0, 0xc
/* 96AE54 80241C94 2463FFFF */  addiu     $v1, $v1, -1
/* 96AE58 80241C98 00031880 */  sll       $v1, $v1, 2
/* 96AE5C 80241C9C 30630FFF */  andi      $v1, $v1, 0xfff
/* 96AE60 80241CA0 006A1825 */  or        $v1, $v1, $t2
/* 96AE64 80241CA4 00431025 */  or        $v0, $v0, $v1
/* 96AE68 80241CA8 ACA2004C */  sw        $v0, 0x4c($a1)
/* 96AE6C 80241CAC 8FA200B8 */  lw        $v0, 0xb8($sp)
/* 96AE70 80241CB0 24A30058 */  addiu     $v1, $a1, 0x58
/* 96AE74 80241CB4 AE030000 */  sw        $v1, ($s0)
/* 96AE78 80241CB8 3C03F200 */  lui       $v1, 0xf200
/* 96AE7C 80241CBC ACA30060 */  sw        $v1, 0x60($a1)
/* 96AE80 80241CC0 3C03F540 */  lui       $v1, 0xf540
/* 96AE84 80241CC4 ACAC005C */  sw        $t4, 0x5c($a1)
/* 96AE88 80241CC8 00021043 */  sra       $v0, $v0, 1
/* 96AE8C 80241CCC 24420007 */  addiu     $v0, $v0, 7
/* 96AE90 80241CD0 000210C3 */  sra       $v0, $v0, 3
/* 96AE94 80241CD4 304201FF */  andi      $v0, $v0, 0x1ff
/* 96AE98 80241CD8 00021240 */  sll       $v0, $v0, 9
/* 96AE9C 80241CDC 00431025 */  or        $v0, $v0, $v1
/* 96AEA0 80241CE0 ACA20058 */  sw        $v0, 0x58($a1)
/* 96AEA4 80241CE4 8FA300B8 */  lw        $v1, 0xb8($sp)
/* 96AEA8 80241CE8 24A20060 */  addiu     $v0, $a1, 0x60
/* 96AEAC 80241CEC AE020000 */  sw        $v0, ($s0)
/* 96AEB0 80241CF0 8FA200BC */  lw        $v0, 0xbc($sp)
/* 96AEB4 80241CF4 2463FFFF */  addiu     $v1, $v1, -1
/* 96AEB8 80241CF8 00031880 */  sll       $v1, $v1, 2
/* 96AEBC 80241CFC 30630FFF */  andi      $v1, $v1, 0xfff
/* 96AEC0 80241D00 00031B00 */  sll       $v1, $v1, 0xc
/* 96AEC4 80241D04 2442FFFF */  addiu     $v0, $v0, -1
/* 96AEC8 80241D08 00021080 */  sll       $v0, $v0, 2
/* 96AECC 80241D0C 30420FFF */  andi      $v0, $v0, 0xfff
/* 96AED0 80241D10 00621825 */  or        $v1, $v1, $v0
/* 96AED4 80241D14 ACA30064 */  sw        $v1, 0x64($a1)
/* 96AED8 80241D18 8FA200B8 */  lw        $v0, 0xb8($sp)
/* 96AEDC 80241D1C 24A50068 */  addiu     $a1, $a1, 0x68
/* 96AEE0 80241D20 AE050000 */  sw        $a1, ($s0)
/* 96AEE4 80241D24 8FAD0100 */  lw        $t5, 0x100($sp)
/* 96AEE8 80241D28 00021FC2 */  srl       $v1, $v0, 0x1f
/* 96AEEC 80241D2C 00431021 */  addu      $v0, $v0, $v1
/* 96AEF0 80241D30 00021043 */  sra       $v0, $v0, 1
/* 96AEF4 80241D34 8DA30020 */  lw        $v1, 0x20($t5)
/* 96AEF8 80241D38 2442FFE2 */  addiu     $v0, $v0, -0x1e
/* 96AEFC 80241D3C 00621823 */  subu      $v1, $v1, $v0
/* 96AF00 80241D40 44831000 */  mtc1      $v1, $f2
/* 96AF04 80241D44 00000000 */  nop
/* 96AF08 80241D48 468010A0 */  cvt.s.w   $f2, $f2
/* 96AF0C 80241D4C 44051000 */  mfc1      $a1, $f2
/* 96AF10 80241D50 0C019E40 */  jal       guTranslateF
/* 96AF14 80241D54 00C0382D */   daddu    $a3, $a2, $zero
/* 96AF18 80241D58 27A40018 */  addiu     $a0, $sp, 0x18
/* 96AF1C 80241D5C 3C118007 */  lui       $s1, %hi(gMatrixListPos)
/* 96AF20 80241D60 263141F0 */  addiu     $s1, $s1, %lo(gMatrixListPos)
/* 96AF24 80241D64 3C12800A */  lui       $s2, %hi(gDisplayContext)
/* 96AF28 80241D68 2652A674 */  addiu     $s2, $s2, %lo(gDisplayContext)
/* 96AF2C 80241D6C 96250000 */  lhu       $a1, ($s1)
/* 96AF30 80241D70 8E420000 */  lw        $v0, ($s2)
/* 96AF34 80241D74 00052980 */  sll       $a1, $a1, 6
/* 96AF38 80241D78 00B32821 */  addu      $a1, $a1, $s3
/* 96AF3C 80241D7C 0C019D40 */  jal       guMtxF2L
/* 96AF40 80241D80 00452821 */   addu     $a1, $v0, $a1
/* 96AF44 80241D84 3C06D838 */  lui       $a2, 0xd838
/* 96AF48 80241D88 8E040000 */  lw        $a0, ($s0)
/* 96AF4C 80241D8C 34C60002 */  ori       $a2, $a2, 2
/* 96AF50 80241D90 0080282D */  daddu     $a1, $a0, $zero
/* 96AF54 80241D94 24840008 */  addiu     $a0, $a0, 8
/* 96AF58 80241D98 AE040000 */  sw        $a0, ($s0)
/* 96AF5C 80241D9C 96220000 */  lhu       $v0, ($s1)
/* 96AF60 80241DA0 3C03DA38 */  lui       $v1, 0xda38
/* 96AF64 80241DA4 ACA30000 */  sw        $v1, ($a1)
/* 96AF68 80241DA8 24430001 */  addiu     $v1, $v0, 1
/* 96AF6C 80241DAC 3042FFFF */  andi      $v0, $v0, 0xffff
/* 96AF70 80241DB0 00021180 */  sll       $v0, $v0, 6
/* 96AF74 80241DB4 A6230000 */  sh        $v1, ($s1)
/* 96AF78 80241DB8 8E430000 */  lw        $v1, ($s2)
/* 96AF7C 80241DBC 00531021 */  addu      $v0, $v0, $s3
/* 96AF80 80241DC0 00621821 */  addu      $v1, $v1, $v0
/* 96AF84 80241DC4 3C028000 */  lui       $v0, 0x8000
/* 96AF88 80241DC8 00621821 */  addu      $v1, $v1, $v0
/* 96AF8C 80241DCC 24820008 */  addiu     $v0, $a0, 8
/* 96AF90 80241DD0 ACA30004 */  sw        $v1, 4($a1)
/* 96AF94 80241DD4 AE020000 */  sw        $v0, ($s0)
/* 96AF98 80241DD8 3C02DE00 */  lui       $v0, 0xde00
/* 96AF9C 80241DDC AC820000 */  sw        $v0, ($a0)
/* 96AFA0 80241DE0 3C028024 */  lui       $v0, %hi(dro_02_D_80247A38_970BF8)
/* 96AFA4 80241DE4 24427A38 */  addiu     $v0, $v0, %lo(dro_02_D_80247A38_970BF8)
/* 96AFA8 80241DE8 AC820004 */  sw        $v0, 4($a0)
/* 96AFAC 80241DEC 24820010 */  addiu     $v0, $a0, 0x10
/* 96AFB0 80241DF0 AE020000 */  sw        $v0, ($s0)
/* 96AFB4 80241DF4 24020040 */  addiu     $v0, $zero, 0x40
/* 96AFB8 80241DF8 AC860008 */  sw        $a2, 8($a0)
/* 96AFBC 80241DFC AC82000C */  sw        $v0, 0xc($a0)
/* 96AFC0 80241E00 3C06D838 */  lui       $a2, 0xd838
.L80241E04:
/* 96AFC4 80241E04 34C60002 */  ori       $a2, $a2, 2
/* 96AFC8 80241E08 3C04800A */  lui       $a0, %hi(gMasterGfxPos)
/* 96AFCC 80241E0C 2484A66C */  addiu     $a0, $a0, %lo(gMasterGfxPos)
/* 96AFD0 80241E10 8C830000 */  lw        $v1, ($a0)
/* 96AFD4 80241E14 24020001 */  addiu     $v0, $zero, 1
/* 96AFD8 80241E18 0060282D */  daddu     $a1, $v1, $zero
/* 96AFDC 80241E1C 24630008 */  addiu     $v1, $v1, 8
/* 96AFE0 80241E20 AC830000 */  sw        $v1, ($a0)
/* 96AFE4 80241E24 24030040 */  addiu     $v1, $zero, 0x40
/* 96AFE8 80241E28 ACA60000 */  sw        $a2, ($a1)
/* 96AFEC 80241E2C 08090877 */  j         .L802421DC
/* 96AFF0 80241E30 ACA30004 */   sw       $v1, 4($a1)
.L80241E34:
/* 96AFF4 80241E34 14620048 */  bne       $v1, $v0, .L80241F58
/* 96AFF8 80241E38 24020003 */   addiu    $v0, $zero, 3
/* 96AFFC 80241E3C 3C03F240 */  lui       $v1, 0xf240
/* 96B000 80241E40 34630400 */  ori       $v1, $v1, 0x400
/* 96B004 80241E44 3C020047 */  lui       $v0, 0x47
/* 96B008 80241E48 3442C47C */  ori       $v0, $v0, 0xc47c
/* 96B00C 80241E4C 27B00058 */  addiu     $s0, $sp, 0x58
/* 96B010 80241E50 0200202D */  daddu     $a0, $s0, $zero
/* 96B014 80241E54 3C120001 */  lui       $s2, 1
/* 96B018 80241E58 36521630 */  ori       $s2, $s2, 0x1630
/* 96B01C 80241E5C AD020004 */  sw        $v0, 4($t0)
/* 96B020 80241E60 3C028025 */  lui       $v0, %hi(dro_02_D_8024F010)
/* 96B024 80241E64 2442F010 */  addiu     $v0, $v0, %lo(dro_02_D_8024F010)
/* 96B028 80241E68 AD030000 */  sw        $v1, ($t0)
/* 96B02C 80241E6C 8C450004 */  lw        $a1, 4($v0)
/* 96B030 80241E70 8C460008 */  lw        $a2, 8($v0)
/* 96B034 80241E74 8C47000C */  lw        $a3, 0xc($v0)
/* 96B038 80241E78 25020008 */  addiu     $v0, $t0, 8
/* 96B03C 80241E7C 0C019E40 */  jal       guTranslateF
/* 96B040 80241E80 AFC20000 */   sw       $v0, ($fp)
/* 96B044 80241E84 0200202D */  daddu     $a0, $s0, $zero
/* 96B048 80241E88 8FA50104 */  lw        $a1, 0x104($sp)
/* 96B04C 80241E8C 0C019D80 */  jal       guMtxCatF
/* 96B050 80241E90 27A60018 */   addiu    $a2, $sp, 0x18
/* 96B054 80241E94 27A40018 */  addiu     $a0, $sp, 0x18
/* 96B058 80241E98 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* 96B05C 80241E9C 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* 96B060 80241EA0 3C11800A */  lui       $s1, %hi(gDisplayContext)
/* 96B064 80241EA4 2631A674 */  addiu     $s1, $s1, %lo(gDisplayContext)
/* 96B068 80241EA8 96050000 */  lhu       $a1, ($s0)
/* 96B06C 80241EAC 8E220000 */  lw        $v0, ($s1)
/* 96B070 80241EB0 00052980 */  sll       $a1, $a1, 6
/* 96B074 80241EB4 00B22821 */  addu      $a1, $a1, $s2
/* 96B078 80241EB8 0C019D40 */  jal       guMtxF2L
/* 96B07C 80241EBC 00452821 */   addu     $a1, $v0, $a1
/* 96B080 80241EC0 3C07DA38 */  lui       $a3, 0xda38
/* 96B084 80241EC4 34E70002 */  ori       $a3, $a3, 2
/* 96B088 80241EC8 3C05F4AC */  lui       $a1, 0xf4ac
/* 96B08C 80241ECC 34A5D480 */  ori       $a1, $a1, 0xd480
/* 96B090 80241ED0 8FC30000 */  lw        $v1, ($fp)
/* 96B094 80241ED4 3C048025 */  lui       $a0, %hi(dro_02_D_8024EFCC)
/* 96B098 80241ED8 8C84EFCC */  lw        $a0, %lo(dro_02_D_8024EFCC)($a0)
/* 96B09C 80241EDC 96020000 */  lhu       $v0, ($s0)
/* 96B0A0 80241EE0 0060302D */  daddu     $a2, $v1, $zero
/* 96B0A4 80241EE4 24630008 */  addiu     $v1, $v1, 8
/* 96B0A8 80241EE8 AFC30000 */  sw        $v1, ($fp)
/* 96B0AC 80241EEC 24430001 */  addiu     $v1, $v0, 1
/* 96B0B0 80241EF0 3042FFFF */  andi      $v0, $v0, 0xffff
/* 96B0B4 80241EF4 00021180 */  sll       $v0, $v0, 6
/* 96B0B8 80241EF8 ACC70000 */  sw        $a3, ($a2)
/* 96B0BC 80241EFC A6030000 */  sh        $v1, ($s0)
/* 96B0C0 80241F00 8E230000 */  lw        $v1, ($s1)
/* 96B0C4 80241F04 00521021 */  addu      $v0, $v0, $s2
/* 96B0C8 80241F08 00621821 */  addu      $v1, $v1, $v0
/* 96B0CC 80241F0C 3C028000 */  lui       $v0, 0x8000
/* 96B0D0 80241F10 00621821 */  addu      $v1, $v1, $v0
/* 96B0D4 80241F14 0C0B1EAF */  jal       get_variable
/* 96B0D8 80241F18 ACC30004 */   sw       $v1, 4($a2)
/* 96B0DC 80241F1C 0040202D */  daddu     $a0, $v0, $zero
/* 96B0E0 80241F20 27A50098 */  addiu     $a1, $sp, 0x98
/* 96B0E4 80241F24 24060030 */  addiu     $a2, $zero, 0x30
/* 96B0E8 80241F28 0C04EBDC */  jal       func_8013AF70
/* 96B0EC 80241F2C 27A70018 */   addiu    $a3, $sp, 0x18
/* 96B0F0 80241F30 3C05D838 */  lui       $a1, 0xd838
/* 96B0F4 80241F34 8FC30000 */  lw        $v1, ($fp)
/* 96B0F8 80241F38 34A50002 */  ori       $a1, $a1, 2
/* 96B0FC 80241F3C 0060202D */  daddu     $a0, $v1, $zero
/* 96B100 80241F40 24630008 */  addiu     $v1, $v1, 8
/* 96B104 80241F44 AFC30000 */  sw        $v1, ($fp)
/* 96B108 80241F48 24030040 */  addiu     $v1, $zero, 0x40
/* 96B10C 80241F4C AC850000 */  sw        $a1, ($a0)
/* 96B110 80241F50 08090877 */  j         .L802421DC
/* 96B114 80241F54 AC830004 */   sw       $v1, 4($a0)
.L80241F58:
/* 96B118 80241F58 10620003 */  beq       $v1, $v0, .L80241F68
/* 96B11C 80241F5C 3C03F240 */   lui      $v1, 0xf240
.L80241F60:
/* 96B120 80241F60 08090877 */  j         .L802421DC
/* 96B124 80241F64 24020001 */   addiu    $v0, $zero, 1
.L80241F68:
/* 96B128 80241F68 34630400 */  ori       $v1, $v1, 0x400
/* 96B12C 80241F6C 3C020047 */  lui       $v0, 0x47
/* 96B130 80241F70 3442C47C */  ori       $v0, $v0, 0xc47c
/* 96B134 80241F74 27B30058 */  addiu     $s3, $sp, 0x58
/* 96B138 80241F78 0260202D */  daddu     $a0, $s3, $zero
/* 96B13C 80241F7C 3C140001 */  lui       $s4, 1
/* 96B140 80241F80 36941630 */  ori       $s4, $s4, 0x1630
/* 96B144 80241F84 3C17DA38 */  lui       $s7, 0xda38
/* 96B148 80241F88 36F70002 */  ori       $s7, $s7, 2
/* 96B14C 80241F8C 3C0DD838 */  lui       $t5, 0xd838
/* 96B150 80241F90 35AD0002 */  ori       $t5, $t5, 2
/* 96B154 80241F94 3C108025 */  lui       $s0, %hi(dro_02_D_8024F010)
/* 96B158 80241F98 2610F010 */  addiu     $s0, $s0, %lo(dro_02_D_8024F010)
/* 96B15C 80241F9C AFAD00C0 */  sw        $t5, 0xc0($sp)
/* 96B160 80241FA0 AD030000 */  sw        $v1, ($t0)
/* 96B164 80241FA4 AD020004 */  sw        $v0, 4($t0)
/* 96B168 80241FA8 8E050004 */  lw        $a1, 4($s0)
/* 96B16C 80241FAC 8E060008 */  lw        $a2, 8($s0)
/* 96B170 80241FB0 8E07000C */  lw        $a3, 0xc($s0)
/* 96B174 80241FB4 25020008 */  addiu     $v0, $t0, 8
/* 96B178 80241FB8 0C019E40 */  jal       guTranslateF
/* 96B17C 80241FBC AFC20000 */   sw       $v0, ($fp)
/* 96B180 80241FC0 0260202D */  daddu     $a0, $s3, $zero
/* 96B184 80241FC4 8FA50104 */  lw        $a1, 0x104($sp)
/* 96B188 80241FC8 0C019D80 */  jal       guMtxCatF
/* 96B18C 80241FCC 27A60018 */   addiu    $a2, $sp, 0x18
/* 96B190 80241FD0 27A40018 */  addiu     $a0, $sp, 0x18
/* 96B194 80241FD4 3C118007 */  lui       $s1, %hi(gMatrixListPos)
/* 96B198 80241FD8 263141F0 */  addiu     $s1, $s1, %lo(gMatrixListPos)
/* 96B19C 80241FDC 3C12800A */  lui       $s2, %hi(gDisplayContext)
/* 96B1A0 80241FE0 2652A674 */  addiu     $s2, $s2, %lo(gDisplayContext)
/* 96B1A4 80241FE4 96250000 */  lhu       $a1, ($s1)
/* 96B1A8 80241FE8 8E420000 */  lw        $v0, ($s2)
/* 96B1AC 80241FEC 00052980 */  sll       $a1, $a1, 6
/* 96B1B0 80241FF0 00B42821 */  addu      $a1, $a1, $s4
/* 96B1B4 80241FF4 0C019D40 */  jal       guMtxF2L
/* 96B1B8 80241FF8 00452821 */   addu     $a1, $v0, $a1
/* 96B1BC 80241FFC 3C05F4AC */  lui       $a1, 0xf4ac
/* 96B1C0 80242000 34A5D481 */  ori       $a1, $a1, 0xd481
/* 96B1C4 80242004 3C158025 */  lui       $s5, %hi(dro_02_D_8024EFCC)
/* 96B1C8 80242008 26B5EFCC */  addiu     $s5, $s5, %lo(dro_02_D_8024EFCC)
/* 96B1CC 8024200C 3C0D8000 */  lui       $t5, 0x8000
/* 96B1D0 80242010 8FC30000 */  lw        $v1, ($fp)
/* 96B1D4 80242014 8EA40000 */  lw        $a0, ($s5)
/* 96B1D8 80242018 96220000 */  lhu       $v0, ($s1)
/* 96B1DC 8024201C 0060302D */  daddu     $a2, $v1, $zero
/* 96B1E0 80242020 24630008 */  addiu     $v1, $v1, 8
/* 96B1E4 80242024 AFC30000 */  sw        $v1, ($fp)
/* 96B1E8 80242028 24430001 */  addiu     $v1, $v0, 1
/* 96B1EC 8024202C 3042FFFF */  andi      $v0, $v0, 0xffff
/* 96B1F0 80242030 00021180 */  sll       $v0, $v0, 6
/* 96B1F4 80242034 ACD70000 */  sw        $s7, ($a2)
/* 96B1F8 80242038 A6230000 */  sh        $v1, ($s1)
/* 96B1FC 8024203C 8E430000 */  lw        $v1, ($s2)
/* 96B200 80242040 00541021 */  addu      $v0, $v0, $s4
/* 96B204 80242044 00621821 */  addu      $v1, $v1, $v0
/* 96B208 80242048 006D1821 */  addu      $v1, $v1, $t5
/* 96B20C 8024204C 0C0B1EAF */  jal       get_variable
/* 96B210 80242050 ACC30004 */   sw       $v1, 4($a2)
/* 96B214 80242054 0040202D */  daddu     $a0, $v0, $zero
/* 96B218 80242058 27B60098 */  addiu     $s6, $sp, 0x98
/* 96B21C 8024205C 02C0282D */  daddu     $a1, $s6, $zero
/* 96B220 80242060 24060030 */  addiu     $a2, $zero, 0x30
/* 96B224 80242064 0C04EBDC */  jal       func_8013AF70
/* 96B228 80242068 27A70018 */   addiu    $a3, $sp, 0x18
/* 96B22C 8024206C 3C05F4AC */  lui       $a1, 0xf4ac
/* 96B230 80242070 8EA40000 */  lw        $a0, ($s5)
/* 96B234 80242074 0C0B1EAF */  jal       get_variable
/* 96B238 80242078 34A5D482 */   ori      $a1, $a1, 0xd482
/* 96B23C 8024207C 0040202D */  daddu     $a0, $v0, $zero
/* 96B240 80242080 02C0282D */  daddu     $a1, $s6, $zero
/* 96B244 80242084 24060030 */  addiu     $a2, $zero, 0x30
/* 96B248 80242088 0C04EBDC */  jal       func_8013AF70
/* 96B24C 8024208C 27A70018 */   addiu    $a3, $sp, 0x18
/* 96B250 80242090 0260202D */  daddu     $a0, $s3, $zero
/* 96B254 80242094 8FC20000 */  lw        $v0, ($fp)
/* 96B258 80242098 8FAD00C0 */  lw        $t5, 0xc0($sp)
/* 96B25C 8024209C 0040182D */  daddu     $v1, $v0, $zero
/* 96B260 802420A0 AC6D0000 */  sw        $t5, ($v1)
/* 96B264 802420A4 240D0040 */  addiu     $t5, $zero, 0x40
/* 96B268 802420A8 AC6D0004 */  sw        $t5, 4($v1)
/* 96B26C 802420AC 8E050004 */  lw        $a1, 4($s0)
/* 96B270 802420B0 8E060008 */  lw        $a2, 8($s0)
/* 96B274 802420B4 8E07000C */  lw        $a3, 0xc($s0)
/* 96B278 802420B8 24420008 */  addiu     $v0, $v0, 8
/* 96B27C 802420BC 0C019E40 */  jal       guTranslateF
/* 96B280 802420C0 AFC20000 */   sw       $v0, ($fp)
/* 96B284 802420C4 0260202D */  daddu     $a0, $s3, $zero
/* 96B288 802420C8 8FA50104 */  lw        $a1, 0x104($sp)
/* 96B28C 802420CC 0C019D80 */  jal       guMtxCatF
/* 96B290 802420D0 27A60018 */   addiu    $a2, $sp, 0x18
/* 96B294 802420D4 27A40018 */  addiu     $a0, $sp, 0x18
/* 96B298 802420D8 96250000 */  lhu       $a1, ($s1)
/* 96B29C 802420DC 8E420000 */  lw        $v0, ($s2)
/* 96B2A0 802420E0 00052980 */  sll       $a1, $a1, 6
/* 96B2A4 802420E4 00B42821 */  addu      $a1, $a1, $s4
/* 96B2A8 802420E8 0C019D40 */  jal       guMtxF2L
/* 96B2AC 802420EC 00452821 */   addu     $a1, $v0, $a1
/* 96B2B0 802420F0 27A400B0 */  addiu     $a0, $sp, 0xb0
/* 96B2B4 802420F4 3C0D8000 */  lui       $t5, 0x8000
/* 96B2B8 802420F8 8FC70000 */  lw        $a3, ($fp)
/* 96B2BC 802420FC 96280000 */  lhu       $t0, ($s1)
/* 96B2C0 80242100 00E0282D */  daddu     $a1, $a3, $zero
/* 96B2C4 80242104 3102FFFF */  andi      $v0, $t0, 0xffff
/* 96B2C8 80242108 00021180 */  sll       $v0, $v0, 6
/* 96B2CC 8024210C ACB70000 */  sw        $s7, ($a1)
/* 96B2D0 80242110 8E430000 */  lw        $v1, ($s2)
/* 96B2D4 80242114 00541021 */  addu      $v0, $v0, $s4
/* 96B2D8 80242118 00621821 */  addu      $v1, $v1, $v0
/* 96B2DC 8024211C 006D1821 */  addu      $v1, $v1, $t5
/* 96B2E0 80242120 ACA30004 */  sw        $v1, 4($a1)
/* 96B2E4 80242124 8FAD0100 */  lw        $t5, 0x100($sp)
/* 96B2E8 80242128 24E70008 */  addiu     $a3, $a3, 8
/* 96B2EC 8024212C 8DA50018 */  lw        $a1, 0x18($t5)
/* 96B2F0 80242130 8DA6001C */  lw        $a2, 0x1c($t5)
/* 96B2F4 80242134 25080001 */  addiu     $t0, $t0, 1
/* 96B2F8 80242138 AFC70000 */  sw        $a3, ($fp)
/* 96B2FC 8024213C 0C0B7811 */  jal       func_802DE044
/* 96B300 80242140 A6280000 */   sh       $t0, ($s1)
/* 96B304 80242144 3C05F4AC */  lui       $a1, 0xf4ac
/* 96B308 80242148 34A5D483 */  ori       $a1, $a1, 0xd483
/* 96B30C 8024214C 8EA40000 */  lw        $a0, ($s5)
/* 96B310 80242150 8FA600B0 */  lw        $a2, 0xb0($sp)
/* 96B314 80242154 8FA700B4 */  lw        $a3, 0xb4($sp)
/* 96B318 80242158 97A800BA */  lhu       $t0, 0xba($sp)
/* 96B31C 8024215C 97A900BE */  lhu       $t1, 0xbe($sp)
/* 96B320 80242160 8FA300B8 */  lw        $v1, 0xb8($sp)
/* 96B324 80242164 240200FF */  addiu     $v0, $zero, 0xff
/* 96B328 80242168 A3A200A8 */  sb        $v0, 0xa8($sp)
/* 96B32C 8024216C 000317C2 */  srl       $v0, $v1, 0x1f
/* 96B330 80242170 00621821 */  addu      $v1, $v1, $v0
/* 96B334 80242174 00031843 */  sra       $v1, $v1, 1
/* 96B338 80242178 8FA200BC */  lw        $v0, 0xbc($sp)
/* 96B33C 8024217C 00031823 */  negu      $v1, $v1
/* 96B340 80242180 AFA60098 */  sw        $a2, 0x98($sp)
/* 96B344 80242184 AFA7009C */  sw        $a3, 0x9c($sp)
/* 96B348 80242188 A7A800A0 */  sh        $t0, 0xa0($sp)
/* 96B34C 8024218C A7A900A2 */  sh        $t1, 0xa2($sp)
/* 96B350 80242190 A7A300A4 */  sh        $v1, 0xa4($sp)
/* 96B354 80242194 00021FC2 */  srl       $v1, $v0, 0x1f
/* 96B358 80242198 00431021 */  addu      $v0, $v0, $v1
/* 96B35C 8024219C 00021043 */  sra       $v0, $v0, 1
/* 96B360 802421A0 0C0B1EAF */  jal       get_variable
/* 96B364 802421A4 A7A200A6 */   sh       $v0, 0xa6($sp)
/* 96B368 802421A8 0040202D */  daddu     $a0, $v0, $zero
/* 96B36C 802421AC 02C0282D */  daddu     $a1, $s6, $zero
/* 96B370 802421B0 24060010 */  addiu     $a2, $zero, 0x10
/* 96B374 802421B4 0C04EBDC */  jal       func_8013AF70
/* 96B378 802421B8 27A70018 */   addiu    $a3, $sp, 0x18
/* 96B37C 802421BC 8FC30000 */  lw        $v1, ($fp)
/* 96B380 802421C0 0060202D */  daddu     $a0, $v1, $zero
/* 96B384 802421C4 24630008 */  addiu     $v1, $v1, 8
/* 96B388 802421C8 AFC30000 */  sw        $v1, ($fp)
/* 96B38C 802421CC 8FAD00C0 */  lw        $t5, 0xc0($sp)
/* 96B390 802421D0 AC8D0000 */  sw        $t5, ($a0)
/* 96B394 802421D4 240D0040 */  addiu     $t5, $zero, 0x40
/* 96B398 802421D8 AC8D0004 */  sw        $t5, 4($a0)
.L802421DC:
/* 96B39C 802421DC 8FBF00EC */  lw        $ra, 0xec($sp)
/* 96B3A0 802421E0 8FBE00E8 */  lw        $fp, 0xe8($sp)
/* 96B3A4 802421E4 8FB700E4 */  lw        $s7, 0xe4($sp)
/* 96B3A8 802421E8 8FB600E0 */  lw        $s6, 0xe0($sp)
/* 96B3AC 802421EC 8FB500DC */  lw        $s5, 0xdc($sp)
/* 96B3B0 802421F0 8FB400D8 */  lw        $s4, 0xd8($sp)
/* 96B3B4 802421F4 8FB300D4 */  lw        $s3, 0xd4($sp)
/* 96B3B8 802421F8 8FB200D0 */  lw        $s2, 0xd0($sp)
/* 96B3BC 802421FC 8FB100CC */  lw        $s1, 0xcc($sp)
/* 96B3C0 80242200 8FB000C8 */  lw        $s0, 0xc8($sp)
/* 96B3C4 80242204 D7B600F8 */  ldc1      $f22, 0xf8($sp)
/* 96B3C8 80242208 D7B400F0 */  ldc1      $f20, 0xf0($sp)
/* 96B3CC 8024220C 03E00008 */  jr        $ra
/* 96B3D0 80242210 27BD0100 */   addiu    $sp, $sp, 0x100
