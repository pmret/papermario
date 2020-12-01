.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel draw_menu_icon
/* DA998 80144298 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* DA99C 8014429C 2402F7FF */  addiu     $v0, $zero, -0x801
/* DA9A0 801442A0 00822024 */  and       $a0, $a0, $v0
/* DA9A4 801442A4 3C028015 */  lui       $v0, %hi(D_80157960)
/* DA9A8 801442A8 8C427960 */  lw        $v0, %lo(D_80157960)($v0)
/* DA9AC 801442AC 00042080 */  sll       $a0, $a0, 2
/* DA9B0 801442B0 AFBF0044 */  sw        $ra, 0x44($sp)
/* DA9B4 801442B4 AFB60040 */  sw        $s6, 0x40($sp)
/* DA9B8 801442B8 AFB5003C */  sw        $s5, 0x3c($sp)
/* DA9BC 801442BC AFB40038 */  sw        $s4, 0x38($sp)
/* DA9C0 801442C0 AFB30034 */  sw        $s3, 0x34($sp)
/* DA9C4 801442C4 AFB20030 */  sw        $s2, 0x30($sp)
/* DA9C8 801442C8 AFB1002C */  sw        $s1, 0x2c($sp)
/* DA9CC 801442CC AFB00028 */  sw        $s0, 0x28($sp)
/* DA9D0 801442D0 00822021 */  addu      $a0, $a0, $v0
/* DA9D4 801442D4 8C900000 */  lw        $s0, ($a0)
/* DA9D8 801442D8 8E030000 */  lw        $v1, ($s0)
/* DA9DC 801442DC 10600128 */  beqz      $v1, .L80144780
/* DA9E0 801442E0 30620002 */   andi     $v0, $v1, 2
/* DA9E4 801442E4 14400126 */  bnez      $v0, .L80144780
/* DA9E8 801442E8 3C021020 */   lui      $v0, 0x1020
/* DA9EC 801442EC 00621024 */  and       $v0, $v1, $v0
/* DA9F0 801442F0 14400123 */  bnez      $v0, .L80144780
/* DA9F4 801442F4 00000000 */   nop      
/* DA9F8 801442F8 82020045 */  lb        $v0, 0x45($s0)
/* DA9FC 801442FC 04400120 */  bltz      $v0, .L80144780
/* DAA00 80144300 24020001 */   addiu    $v0, $zero, 1
/* DAA04 80144304 10A2005E */  beq       $a1, $v0, .L80144480
/* DAA08 80144308 30620100 */   andi     $v0, $v1, 0x100
/* DAA0C 8014430C 14A0000E */  bnez      $a1, .L80144348
/* DAA10 80144310 3C06E300 */   lui      $a2, 0xe300
/* DAA14 80144314 3C06ED03 */  lui       $a2, 0xed03
/* DAA18 80144318 34C60050 */  ori       $a2, $a2, 0x50
/* DAA1C 8014431C 3C05004D */  lui       $a1, 0x4d
/* DAA20 80144320 3C04800A */  lui       $a0, %hi(D_8009A66C)
/* DAA24 80144324 2484A66C */  addiu     $a0, $a0, %lo(D_8009A66C)
/* DAA28 80144328 8C820000 */  lw        $v0, ($a0)
/* DAA2C 8014432C 34A50370 */  ori       $a1, $a1, 0x370
/* DAA30 80144330 0040182D */  daddu     $v1, $v0, $zero
/* DAA34 80144334 24420008 */  addiu     $v0, $v0, 8
/* DAA38 80144338 AC820000 */  sw        $v0, ($a0)
/* DAA3C 8014433C AC660000 */  sw        $a2, ($v1)
/* DAA40 80144340 AC650004 */  sw        $a1, 4($v1)
/* DAA44 80144344 3C06E300 */  lui       $a2, 0xe300
.L80144348:
/* DAA48 80144348 34C60A01 */  ori       $a2, $a2, 0xa01
/* DAA4C 8014434C 3C07E300 */  lui       $a3, 0xe300
/* DAA50 80144350 34E70C00 */  ori       $a3, $a3, 0xc00
/* DAA54 80144354 3C08E300 */  lui       $t0, 0xe300
/* DAA58 80144358 35080F00 */  ori       $t0, $t0, 0xf00
/* DAA5C 8014435C 3C09E300 */  lui       $t1, 0xe300
/* DAA60 80144360 35290D01 */  ori       $t1, $t1, 0xd01
/* DAA64 80144364 3C0AE300 */  lui       $t2, 0xe300
/* DAA68 80144368 354A1402 */  ori       $t2, $t2, 0x1402
/* DAA6C 8014436C 3C0BE300 */  lui       $t3, 0xe300
/* DAA70 80144370 356B1700 */  ori       $t3, $t3, 0x1700
/* DAA74 80144374 3C0CE200 */  lui       $t4, 0xe200
/* DAA78 80144378 358C1E01 */  ori       $t4, $t4, 0x1e01
/* DAA7C 8014437C 3C0DE300 */  lui       $t5, 0xe300
/* DAA80 80144380 35AD1801 */  ori       $t5, $t5, 0x1801
/* DAA84 80144384 3C0EE300 */  lui       $t6, 0xe300
/* DAA88 80144388 35CE1A01 */  ori       $t6, $t6, 0x1a01
/* DAA8C 8014438C 3C0FD700 */  lui       $t7, 0xd700
/* DAA90 80144390 3C04800A */  lui       $a0, %hi(D_8009A66C)
/* DAA94 80144394 2484A66C */  addiu     $a0, $a0, %lo(D_8009A66C)
/* DAA98 80144398 35EF0002 */  ori       $t7, $t7, 2
/* DAA9C 8014439C 8C820000 */  lw        $v0, ($a0)
/* DAAA0 801443A0 3C03E700 */  lui       $v1, 0xe700
/* DAAA4 801443A4 0040282D */  daddu     $a1, $v0, $zero
/* DAAA8 801443A8 24420008 */  addiu     $v0, $v0, 8
/* DAAAC 801443AC AC820000 */  sw        $v0, ($a0)
/* DAAB0 801443B0 ACA30000 */  sw        $v1, ($a1)
/* DAAB4 801443B4 24430008 */  addiu     $v1, $v0, 8
/* DAAB8 801443B8 ACA00004 */  sw        $zero, 4($a1)
/* DAABC 801443BC AC830000 */  sw        $v1, ($a0)
/* DAAC0 801443C0 24430010 */  addiu     $v1, $v0, 0x10
/* DAAC4 801443C4 AC460000 */  sw        $a2, ($v0)
/* DAAC8 801443C8 AC400004 */  sw        $zero, 4($v0)
/* DAACC 801443CC AC830000 */  sw        $v1, ($a0)
/* DAAD0 801443D0 24430018 */  addiu     $v1, $v0, 0x18
/* DAAD4 801443D4 AC470008 */  sw        $a3, 8($v0)
/* DAAD8 801443D8 AC40000C */  sw        $zero, 0xc($v0)
/* DAADC 801443DC AC830000 */  sw        $v1, ($a0)
/* DAAE0 801443E0 24430020 */  addiu     $v1, $v0, 0x20
/* DAAE4 801443E4 AC480010 */  sw        $t0, 0x10($v0)
/* DAAE8 801443E8 AC400014 */  sw        $zero, 0x14($v0)
/* DAAEC 801443EC AC830000 */  sw        $v1, ($a0)
/* DAAF0 801443F0 24430028 */  addiu     $v1, $v0, 0x28
/* DAAF4 801443F4 AC490018 */  sw        $t1, 0x18($v0)
/* DAAF8 801443F8 AC40001C */  sw        $zero, 0x1c($v0)
/* DAAFC 801443FC AC830000 */  sw        $v1, ($a0)
/* DAB00 80144400 24030C00 */  addiu     $v1, $zero, 0xc00
/* DAB04 80144404 AC430024 */  sw        $v1, 0x24($v0)
/* DAB08 80144408 24430030 */  addiu     $v1, $v0, 0x30
/* DAB0C 8014440C AC4A0020 */  sw        $t2, 0x20($v0)
/* DAB10 80144410 AC830000 */  sw        $v1, ($a0)
/* DAB14 80144414 24430038 */  addiu     $v1, $v0, 0x38
/* DAB18 80144418 AC4B0028 */  sw        $t3, 0x28($v0)
/* DAB1C 8014441C AC40002C */  sw        $zero, 0x2c($v0)
/* DAB20 80144420 AC830000 */  sw        $v1, ($a0)
/* DAB24 80144424 24430040 */  addiu     $v1, $v0, 0x40
/* DAB28 80144428 AC4C0030 */  sw        $t4, 0x30($v0)
/* DAB2C 8014442C AC400034 */  sw        $zero, 0x34($v0)
/* DAB30 80144430 AC830000 */  sw        $v1, ($a0)
/* DAB34 80144434 24430048 */  addiu     $v1, $v0, 0x48
/* DAB38 80144438 AC400038 */  sw        $zero, 0x38($v0)
/* DAB3C 8014443C AC40003C */  sw        $zero, 0x3c($v0)
/* DAB40 80144440 AC830000 */  sw        $v1, ($a0)
/* DAB44 80144444 240300C0 */  addiu     $v1, $zero, 0xc0
/* DAB48 80144448 AC430044 */  sw        $v1, 0x44($v0)
/* DAB4C 8014444C 24430050 */  addiu     $v1, $v0, 0x50
/* DAB50 80144450 AC4D0040 */  sw        $t5, 0x40($v0)
/* DAB54 80144454 AC830000 */  sw        $v1, ($a0)
/* DAB58 80144458 24030030 */  addiu     $v1, $zero, 0x30
/* DAB5C 8014445C AC4E0048 */  sw        $t6, 0x48($v0)
/* DAB60 80144460 AC43004C */  sw        $v1, 0x4c($v0)
/* DAB64 80144464 24430058 */  addiu     $v1, $v0, 0x58
/* DAB68 80144468 AC830000 */  sw        $v1, ($a0)
/* DAB6C 8014446C 2403FFFF */  addiu     $v1, $zero, -1
/* DAB70 80144470 AC4F0050 */  sw        $t7, 0x50($v0)
/* DAB74 80144474 AC430054 */  sw        $v1, 0x54($v0)
/* DAB78 80144478 8E030000 */  lw        $v1, ($s0)
/* DAB7C 8014447C 30620100 */  andi      $v0, $v1, 0x100
.L80144480:
/* DAB80 80144480 1440005B */  bnez      $v0, .L801445F0
/* DAB84 80144484 3C020010 */   lui      $v0, 0x10
/* DAB88 80144488 00621024 */  and       $v0, $v1, $v0
/* DAB8C 8014448C 1440000B */  bnez      $v0, .L801444BC
/* DAB90 80144490 00000000 */   nop      
/* DAB94 80144494 82040046 */  lb        $a0, 0x46($s0)
/* DAB98 80144498 3C038015 */  lui       $v1, %hi(D_8014EFCC)
/* DAB9C 8014449C 2463EFCC */  addiu     $v1, $v1, %lo(D_8014EFCC)
/* DABA0 801444A0 00041040 */  sll       $v0, $a0, 1
/* DABA4 801444A4 00441021 */  addu      $v0, $v0, $a0
/* DABA8 801444A8 00021040 */  sll       $v0, $v0, 1
/* DABAC 801444AC 00431021 */  addu      $v0, $v0, $v1
/* DABB0 801444B0 84560000 */  lh        $s6, ($v0)
/* DABB4 801444B4 08051131 */  j         .L801444C4
/* DABB8 801444B8 84550002 */   lh       $s5, 2($v0)
.L801444BC:
/* DABBC 801444BC 9216004E */  lbu       $s6, 0x4e($s0)
/* DABC0 801444C0 9215004F */  lbu       $s5, 0x4f($s0)
.L801444C4:
/* DABC4 801444C4 8E030000 */  lw        $v1, ($s0)
/* DABC8 801444C8 30620010 */  andi      $v0, $v1, 0x10
/* DABCC 801444CC 14400013 */  bnez      $v0, .L8014451C
/* DABD0 801444D0 3C020010 */   lui      $v0, 0x10
/* DABD4 801444D4 00621024 */  and       $v0, $v1, $v0
/* DABD8 801444D8 1440000C */  bnez      $v0, .L8014450C
/* DABDC 801444DC 00000000 */   nop      
/* DABE0 801444E0 82020045 */  lb        $v0, 0x45($s0)
/* DABE4 801444E4 3C048015 */  lui       $a0, %hi(D_8014EFCC)
/* DABE8 801444E8 2484EFCC */  addiu     $a0, $a0, %lo(D_8014EFCC)
/* DABEC 801444EC 00021840 */  sll       $v1, $v0, 1
/* DABF0 801444F0 00621821 */  addu      $v1, $v1, $v0
/* DABF4 801444F4 00031840 */  sll       $v1, $v1, 1
/* DABF8 801444F8 00641821 */  addu      $v1, $v1, $a0
/* DABFC 801444FC 84710000 */  lh        $s1, ($v1)
/* DAC00 80144500 84720002 */  lh        $s2, 2($v1)
/* DAC04 80144504 0805114A */  j         .L80144528
/* DAC08 80144508 00111023 */   negu     $v0, $s1
.L8014450C:
/* DAC0C 8014450C 92110050 */  lbu       $s1, 0x50($s0)
/* DAC10 80144510 92120051 */  lbu       $s2, 0x51($s0)
/* DAC14 80144514 0805114A */  j         .L80144528
/* DAC18 80144518 00111023 */   negu     $v0, $s1
.L8014451C:
/* DAC1C 8014451C 92110048 */  lbu       $s1, 0x48($s0)
/* DAC20 80144520 92120049 */  lbu       $s2, 0x49($s0)
/* DAC24 80144524 00111023 */  negu      $v0, $s1
.L80144528:
/* DAC28 80144528 00021FC2 */  srl       $v1, $v0, 0x1f
/* DAC2C 8014452C 00431021 */  addu      $v0, $v0, $v1
/* DAC30 80144530 00029843 */  sra       $s3, $v0, 1
/* DAC34 80144534 00121023 */  negu      $v0, $s2
/* DAC38 80144538 00021FC2 */  srl       $v1, $v0, 0x1f
/* DAC3C 8014453C 00431021 */  addu      $v0, $v0, $v1
/* DAC40 80144540 0002A043 */  sra       $s4, $v0, 1
/* DAC44 80144544 8E030000 */  lw        $v1, ($s0)
/* DAC48 80144548 30620800 */  andi      $v0, $v1, 0x800
/* DAC4C 8014454C 14400026 */  bnez      $v0, .L801445E8
/* DAC50 80144550 3C022000 */   lui      $v0, 0x2000
/* DAC54 80144554 00621024 */  and       $v0, $v1, $v0
/* DAC58 80144558 10400012 */  beqz      $v0, .L801445A4
/* DAC5C 8014455C 0200202D */   daddu    $a0, $s0, $zero
/* DAC60 80144560 02C0282D */  daddu     $a1, $s6, $zero
/* DAC64 80144564 02A0302D */  daddu     $a2, $s5, $zero
/* DAC68 80144568 00113C00 */  sll       $a3, $s1, 0x10
/* DAC6C 8014456C 00073C03 */  sra       $a3, $a3, 0x10
/* DAC70 80144570 00121400 */  sll       $v0, $s2, 0x10
/* DAC74 80144574 00021403 */  sra       $v0, $v0, 0x10
/* DAC78 80144578 AFA20010 */  sw        $v0, 0x10($sp)
/* DAC7C 8014457C 00131400 */  sll       $v0, $s3, 0x10
/* DAC80 80144580 00021403 */  sra       $v0, $v0, 0x10
/* DAC84 80144584 AFA20014 */  sw        $v0, 0x14($sp)
/* DAC88 80144588 00141400 */  sll       $v0, $s4, 0x10
/* DAC8C 8014458C 00021403 */  sra       $v0, $v0, 0x10
/* DAC90 80144590 AFA20018 */  sw        $v0, 0x18($sp)
/* DAC94 80144594 24020001 */  addiu     $v0, $zero, 1
/* DAC98 80144598 AFA2001C */  sw        $v0, 0x1c($sp)
/* DAC9C 8014459C 0C04FDC1 */  jal       func_8013F704
/* DACA0 801445A0 AFA20020 */   sw       $v0, 0x20($sp)
.L801445A4:
/* DACA4 801445A4 0200202D */  daddu     $a0, $s0, $zero
/* DACA8 801445A8 02C0282D */  daddu     $a1, $s6, $zero
/* DACAC 801445AC 02A0302D */  daddu     $a2, $s5, $zero
/* DACB0 801445B0 00113C00 */  sll       $a3, $s1, 0x10
/* DACB4 801445B4 00073C03 */  sra       $a3, $a3, 0x10
/* DACB8 801445B8 00121400 */  sll       $v0, $s2, 0x10
/* DACBC 801445BC 00021403 */  sra       $v0, $v0, 0x10
/* DACC0 801445C0 AFA20010 */  sw        $v0, 0x10($sp)
/* DACC4 801445C4 00131400 */  sll       $v0, $s3, 0x10
/* DACC8 801445C8 00021403 */  sra       $v0, $v0, 0x10
/* DACCC 801445CC AFA20014 */  sw        $v0, 0x14($sp)
/* DACD0 801445D0 00141400 */  sll       $v0, $s4, 0x10
/* DACD4 801445D4 00021403 */  sra       $v0, $v0, 0x10
/* DACD8 801445D8 AFA20018 */  sw        $v0, 0x18($sp)
/* DACDC 801445DC 24020001 */  addiu     $v0, $zero, 1
/* DACE0 801445E0 080511DE */  j         .L80144778
/* DACE4 801445E4 AFA2001C */   sw       $v0, 0x1c($sp)
.L801445E8:
/* DACE8 801445E8 080511BC */  j         .L801446F0
/* DACEC 801445EC 00621024 */   and      $v0, $v1, $v0
.L801445F0:
/* DACF0 801445F0 00621024 */  and       $v0, $v1, $v0
/* DACF4 801445F4 1440000C */  bnez      $v0, .L80144628
/* DACF8 801445F8 3C032000 */   lui      $v1, 0x2000
/* DACFC 801445FC 82040046 */  lb        $a0, 0x46($s0)
/* DAD00 80144600 3C038015 */  lui       $v1, %hi(D_8014EFCC)
/* DAD04 80144604 2463EFCC */  addiu     $v1, $v1, %lo(D_8014EFCC)
/* DAD08 80144608 00041040 */  sll       $v0, $a0, 1
/* DAD0C 8014460C 00441021 */  addu      $v0, $v0, $a0
/* DAD10 80144610 00021040 */  sll       $v0, $v0, 1
/* DAD14 80144614 00431021 */  addu      $v0, $v0, $v1
/* DAD18 80144618 84560000 */  lh        $s6, ($v0)
/* DAD1C 8014461C 84550002 */  lh        $s5, 2($v0)
/* DAD20 80144620 0805118C */  j         .L80144630
/* DAD24 80144624 3C032000 */   lui      $v1, 0x2000
.L80144628:
/* DAD28 80144628 9216004E */  lbu       $s6, 0x4e($s0)
/* DAD2C 8014462C 9215004F */  lbu       $s5, 0x4f($s0)
.L80144630:
/* DAD30 80144630 C6000028 */  lwc1      $f0, 0x28($s0)
/* DAD34 80144634 C606002C */  lwc1      $f6, 0x2c($s0)
/* DAD38 80144638 3C013F00 */  lui       $at, 0x3f00
/* DAD3C 8014463C 44811000 */  mtc1      $at, $f2
/* DAD40 80144640 3C013F80 */  lui       $at, 0x3f80
/* DAD44 80144644 44815000 */  mtc1      $at, $f10
/* DAD48 80144648 46000207 */  neg.s     $f8, $f0
/* DAD4C 8014464C 46024202 */  mul.s     $f8, $f8, $f2
/* DAD50 80144650 00000000 */  nop       
/* DAD54 80144654 3C014480 */  lui       $at, 0x4480
/* DAD58 80144658 44816000 */  mtc1      $at, $f12
/* DAD5C 8014465C 8E020000 */  lw        $v0, ($s0)
/* DAD60 80144660 4600038D */  trunc.w.s $f14, $f0
/* DAD64 80144664 44117000 */  mfc1      $s1, $f14
/* DAD68 80144668 4600338D */  trunc.w.s $f14, $f6
/* DAD6C 8014466C 44127000 */  mfc1      $s2, $f14
/* DAD70 80144670 46003187 */  neg.s     $f6, $f6
/* DAD74 80144674 46023182 */  mul.s     $f6, $f6, $f2
/* DAD78 80144678 00000000 */  nop       
/* DAD7C 8014467C 44912000 */  mtc1      $s1, $f4
/* DAD80 80144680 00000000 */  nop       
/* DAD84 80144684 46802120 */  cvt.s.w   $f4, $f4
/* DAD88 80144688 44960000 */  mtc1      $s6, $f0
/* DAD8C 8014468C 00000000 */  nop       
/* DAD90 80144690 46800020 */  cvt.s.w   $f0, $f0
/* DAD94 80144694 46002103 */  div.s     $f4, $f4, $f0
/* DAD98 80144698 46045103 */  div.s     $f4, $f10, $f4
/* DAD9C 8014469C 460C2102 */  mul.s     $f4, $f4, $f12
/* DADA0 801446A0 00000000 */  nop       
/* DADA4 801446A4 44920000 */  mtc1      $s2, $f0
/* DADA8 801446A8 00000000 */  nop       
/* DADAC 801446AC 46800020 */  cvt.s.w   $f0, $f0
/* DADB0 801446B0 44951000 */  mtc1      $s5, $f2
/* DADB4 801446B4 00000000 */  nop       
/* DADB8 801446B8 468010A0 */  cvt.s.w   $f2, $f2
/* DADBC 801446BC 46020003 */  div.s     $f0, $f0, $f2
/* DADC0 801446C0 46005003 */  div.s     $f0, $f10, $f0
/* DADC4 801446C4 460C0002 */  mul.s     $f0, $f0, $f12
/* DADC8 801446C8 00000000 */  nop       
/* DADCC 801446CC 00431024 */  and       $v0, $v0, $v1
/* DADD0 801446D0 4600438D */  trunc.w.s $f14, $f8
/* DADD4 801446D4 44137000 */  mfc1      $s3, $f14
/* DADD8 801446D8 4600338D */  trunc.w.s $f14, $f6
/* DADDC 801446DC 44147000 */  mfc1      $s4, $f14
/* DADE0 801446E0 4600238D */  trunc.w.s $f14, $f4
/* DADE4 801446E4 E60E0034 */  swc1      $f14, 0x34($s0)
/* DADE8 801446E8 4600038D */  trunc.w.s $f14, $f0
/* DADEC 801446EC E60E0038 */  swc1      $f14, 0x38($s0)
.L801446F0:
/* DADF0 801446F0 10400012 */  beqz      $v0, .L8014473C
/* DADF4 801446F4 0200202D */   daddu    $a0, $s0, $zero
/* DADF8 801446F8 02C0282D */  daddu     $a1, $s6, $zero
/* DADFC 801446FC 02A0302D */  daddu     $a2, $s5, $zero
/* DAE00 80144700 00113C00 */  sll       $a3, $s1, 0x10
/* DAE04 80144704 00073C03 */  sra       $a3, $a3, 0x10
/* DAE08 80144708 00121400 */  sll       $v0, $s2, 0x10
/* DAE0C 8014470C 00021403 */  sra       $v0, $v0, 0x10
/* DAE10 80144710 AFA20010 */  sw        $v0, 0x10($sp)
/* DAE14 80144714 00131400 */  sll       $v0, $s3, 0x10
/* DAE18 80144718 00021403 */  sra       $v0, $v0, 0x10
/* DAE1C 8014471C AFA20014 */  sw        $v0, 0x14($sp)
/* DAE20 80144720 00141400 */  sll       $v0, $s4, 0x10
/* DAE24 80144724 00021403 */  sra       $v0, $v0, 0x10
/* DAE28 80144728 AFA20018 */  sw        $v0, 0x18($sp)
/* DAE2C 8014472C 24020001 */  addiu     $v0, $zero, 1
/* DAE30 80144730 AFA0001C */  sw        $zero, 0x1c($sp)
/* DAE34 80144734 0C04FDC1 */  jal       func_8013F704
/* DAE38 80144738 AFA20020 */   sw       $v0, 0x20($sp)
.L8014473C:
/* DAE3C 8014473C 0200202D */  daddu     $a0, $s0, $zero
/* DAE40 80144740 02C0282D */  daddu     $a1, $s6, $zero
/* DAE44 80144744 02A0302D */  daddu     $a2, $s5, $zero
/* DAE48 80144748 00113C00 */  sll       $a3, $s1, 0x10
/* DAE4C 8014474C 00073C03 */  sra       $a3, $a3, 0x10
/* DAE50 80144750 00121400 */  sll       $v0, $s2, 0x10
/* DAE54 80144754 00021403 */  sra       $v0, $v0, 0x10
/* DAE58 80144758 AFA20010 */  sw        $v0, 0x10($sp)
/* DAE5C 8014475C 00131400 */  sll       $v0, $s3, 0x10
/* DAE60 80144760 00021403 */  sra       $v0, $v0, 0x10
/* DAE64 80144764 AFA20014 */  sw        $v0, 0x14($sp)
/* DAE68 80144768 00141400 */  sll       $v0, $s4, 0x10
/* DAE6C 8014476C 00021403 */  sra       $v0, $v0, 0x10
/* DAE70 80144770 AFA20018 */  sw        $v0, 0x18($sp)
/* DAE74 80144774 AFA0001C */  sw        $zero, 0x1c($sp)
.L80144778:
/* DAE78 80144778 0C04FDC1 */  jal       func_8013F704
/* DAE7C 8014477C AFA00020 */   sw       $zero, 0x20($sp)
.L80144780:
/* DAE80 80144780 8FBF0044 */  lw        $ra, 0x44($sp)
/* DAE84 80144784 8FB60040 */  lw        $s6, 0x40($sp)
/* DAE88 80144788 8FB5003C */  lw        $s5, 0x3c($sp)
/* DAE8C 8014478C 8FB40038 */  lw        $s4, 0x38($sp)
/* DAE90 80144790 8FB30034 */  lw        $s3, 0x34($sp)
/* DAE94 80144794 8FB20030 */  lw        $s2, 0x30($sp)
/* DAE98 80144798 8FB1002C */  lw        $s1, 0x2c($sp)
/* DAE9C 8014479C 8FB00028 */  lw        $s0, 0x28($sp)
/* DAEA0 801447A0 03E00008 */  jr        $ra
/* DAEA4 801447A4 27BD0048 */   addiu    $sp, $sp, 0x48
