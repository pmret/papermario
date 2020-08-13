.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_801363A0
/* 0CCAA0 801363A0 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 0CCAA4 801363A4 AFB40038 */  sw    $s4, 0x38($sp)
/* 0CCAA8 801363A8 0080A02D */  daddu $s4, $a0, $zero
/* 0CCAAC 801363AC AFBF003C */  sw    $ra, 0x3c($sp)
/* 0CCAB0 801363B0 AFB30034 */  sw    $s3, 0x34($sp)
/* 0CCAB4 801363B4 AFB20030 */  sw    $s2, 0x30($sp)
/* 0CCAB8 801363B8 AFB1002C */  sw    $s1, 0x2c($sp)
/* 0CCABC 801363BC AFB00028 */  sw    $s0, 0x28($sp)
/* 0CCAC0 801363C0 86820018 */  lh    $v0, 0x18($s4)
/* 0CCAC4 801363C4 3C038008 */  lui   $v1, 0x8008
/* 0CCAC8 801363C8 246378E0 */  addiu $v1, $v1, 0x78e0
/* 0CCACC 801363CC 00021140 */  sll   $v0, $v0, 5
/* 0CCAD0 801363D0 00432021 */  addu  $a0, $v0, $v1
/* 0CCAD4 801363D4 8283001A */  lb    $v1, 0x1a($s4)
/* 0CCAD8 801363D8 2402000A */  addiu $v0, $zero, 0xa
/* 0CCADC 801363DC 1062000C */  beq   $v1, $v0, .L80136410
/* 0CCAE0 801363E0 2862000B */   slti  $v0, $v1, 0xb
/* 0CCAE4 801363E4 10400005 */  beqz  $v0, .L801363FC
/* 0CCAE8 801363E8 24020002 */   addiu $v0, $zero, 2
/* 0CCAEC 801363EC 10620008 */  beq   $v1, $v0, .L80136410
/* 0CCAF0 801363F0 00000000 */   nop   
/* 0CCAF4 801363F4 0804D9C7 */  j     .L8013671C
/* 0CCAF8 801363F8 00000000 */   nop   

.L801363FC:
/* 0CCAFC 801363FC 2402000C */  addiu $v0, $zero, 0xc
/* 0CCB00 80136400 106200AC */  beq   $v1, $v0, .L801366B4
/* 0CCB04 80136404 00000000 */   nop   
/* 0CCB08 80136408 0804D9C7 */  j     .L8013671C
/* 0CCB0C 8013640C 00000000 */   nop   

.L80136410:
/* 0CCB10 80136410 94820018 */  lhu   $v0, 0x18($a0)
/* 0CCB14 80136414 30420040 */  andi  $v0, $v0, 0x40
/* 0CCB18 80136418 1440003B */  bnez  $v0, .L80136508
/* 0CCB1C 8013641C 3C030400 */   lui   $v1, 0x400
/* 0CCB20 80136420 8E820000 */  lw    $v0, ($s4)
/* 0CCB24 80136424 00431024 */  and   $v0, $v0, $v1
/* 0CCB28 80136428 10400005 */  beqz  $v0, .L80136440
/* 0CCB2C 8013642C 3C12001D */   lui   $s2, 0x1d
/* 0CCB30 80136430 96820006 */  lhu   $v0, 6($s4)
/* 0CCB34 80136434 30420004 */  andi  $v0, $v0, 4
/* 0CCB38 80136438 50400002 */  beql  $v0, $zero, .L80136444
/* 0CCB3C 8013643C 3652005A */   ori   $s2, $s2, 0x5a
.L80136440:
/* 0CCB40 80136440 36520058 */  ori   $s2, $s2, 0x58
.L80136444:
/* 0CCB44 80136444 96830006 */  lhu   $v1, 6($s4)
/* 0CCB48 80136448 30620010 */  andi  $v0, $v1, 0x10
/* 0CCB4C 8013644C 10400003 */  beqz  $v0, .L8013645C
/* 0CCB50 80136450 30620020 */   andi  $v0, $v1, 0x20
/* 0CCB54 80136454 3C12001D */  lui   $s2, 0x1d
/* 0CCB58 80136458 3652005D */  ori   $s2, $s2, 0x5d
.L8013645C:
/* 0CCB5C 8013645C 10400003 */  beqz  $v0, .L8013646C
/* 0CCB60 80136460 30620040 */   andi  $v0, $v1, 0x40
/* 0CCB64 80136464 3C12001D */  lui   $s2, 0x1d
/* 0CCB68 80136468 3652005E */  ori   $s2, $s2, 0x5e
.L8013646C:
/* 0CCB6C 8013646C 10400003 */  beqz  $v0, .L8013647C
/* 0CCB70 80136470 00000000 */   nop   
/* 0CCB74 80136474 3C12001D */  lui   $s2, 0x1d
/* 0CCB78 80136478 3652005C */  ori   $s2, $s2, 0x5c
.L8013647C:
/* 0CCB7C 8013647C 8C840000 */  lw    $a0, ($a0)
/* 0CCB80 80136480 0C0496CF */  jal   set_message_string
/* 0CCB84 80136484 0000282D */   daddu $a1, $zero, $zero
/* 0CCB88 80136488 86840018 */  lh    $a0, 0x18($s4)
/* 0CCB8C 8013648C 00041140 */  sll   $v0, $a0, 5
/* 0CCB90 80136490 3C038008 */  lui   $v1, 0x8008
/* 0CCB94 80136494 00621821 */  addu  $v1, $v1, $v0
/* 0CCB98 80136498 946378F8 */  lhu   $v1, 0x78f8($v1)
/* 0CCB9C 8013649C 30620008 */  andi  $v0, $v1, 8
/* 0CCBA0 801364A0 5440000F */  bnel  $v0, $zero, .L801364E0
/* 0CCBA4 801364A4 0240202D */   daddu $a0, $s2, $zero
/* 0CCBA8 801364A8 2402015C */  addiu $v0, $zero, 0x15c
/* 0CCBAC 801364AC 1082000B */  beq   $a0, $v0, .L801364DC
/* 0CCBB0 801364B0 30620020 */   andi  $v0, $v1, 0x20
/* 0CCBB4 801364B4 1440000A */  bnez  $v0, .L801364E0
/* 0CCBB8 801364B8 0240202D */   daddu $a0, $s2, $zero
/* 0CCBBC 801364BC 96820006 */  lhu   $v0, 6($s4)
/* 0CCBC0 801364C0 30420030 */  andi  $v0, $v0, 0x30
/* 0CCBC4 801364C4 14400006 */  bnez  $v0, .L801364E0
/* 0CCBC8 801364C8 00000000 */   nop   
/* 0CCBCC 801364CC 0C04991D */  jal   get_string_width
/* 0CCBD0 801364D0 0000282D */   daddu $a1, $zero, $zero
/* 0CCBD4 801364D4 0804D93B */  j     .L801364EC
/* 0CCBD8 801364D8 24500036 */   addiu $s0, $v0, 0x36

.L801364DC:
/* 0CCBDC 801364DC 0240202D */  daddu $a0, $s2, $zero
.L801364E0:
/* 0CCBE0 801364E0 0C04991D */  jal   get_string_width
/* 0CCBE4 801364E4 0000282D */   daddu $a1, $zero, $zero
/* 0CCBE8 801364E8 2450001E */  addiu $s0, $v0, 0x1e
.L801364EC:
/* 0CCBEC 801364EC 001017C2 */  srl   $v0, $s0, 0x1f
/* 0CCBF0 801364F0 02021021 */  addu  $v0, $s0, $v0
/* 0CCBF4 801364F4 00021043 */  sra   $v0, $v0, 1
/* 0CCBF8 801364F8 240300A0 */  addiu $v1, $zero, 0xa0
/* 0CCBFC 801364FC 00628823 */  subu  $s1, $v1, $v0
/* 0CCC00 80136500 0804D966 */  j     .L80136598
/* 0CCC04 80136504 2413004C */   addiu $s3, $zero, 0x4c

.L80136508:
/* 0CCC08 80136508 8E820000 */  lw    $v0, ($s4)
/* 0CCC0C 8013650C 00431024 */  and   $v0, $v0, $v1
/* 0CCC10 80136510 10400005 */  beqz  $v0, .L80136528
/* 0CCC14 80136514 3C12001D */   lui   $s2, 0x1d
/* 0CCC18 80136518 96820006 */  lhu   $v0, 6($s4)
/* 0CCC1C 8013651C 30420004 */  andi  $v0, $v0, 4
/* 0CCC20 80136520 50400002 */  beql  $v0, $zero, .L8013652C
/* 0CCC24 80136524 3652005B */   ori   $s2, $s2, 0x5b
.L80136528:
/* 0CCC28 80136528 36520059 */  ori   $s2, $s2, 0x59
.L8013652C:
/* 0CCC2C 8013652C 96830006 */  lhu   $v1, 6($s4)
/* 0CCC30 80136530 30620010 */  andi  $v0, $v1, 0x10
/* 0CCC34 80136534 10400003 */  beqz  $v0, .L80136544
/* 0CCC38 80136538 30620020 */   andi  $v0, $v1, 0x20
/* 0CCC3C 8013653C 3C12001D */  lui   $s2, 0x1d
/* 0CCC40 80136540 3652005D */  ori   $s2, $s2, 0x5d
.L80136544:
/* 0CCC44 80136544 10400003 */  beqz  $v0, .L80136554
/* 0CCC48 80136548 30620040 */   andi  $v0, $v1, 0x40
/* 0CCC4C 8013654C 3C12001D */  lui   $s2, 0x1d
/* 0CCC50 80136550 3652005E */  ori   $s2, $s2, 0x5e
.L80136554:
/* 0CCC54 80136554 10400003 */  beqz  $v0, .L80136564
/* 0CCC58 80136558 00000000 */   nop   
/* 0CCC5C 8013655C 3C12001D */  lui   $s2, 0x1d
/* 0CCC60 80136560 3652005C */  ori   $s2, $s2, 0x5c
.L80136564:
/* 0CCC64 80136564 8C840000 */  lw    $a0, ($a0)
/* 0CCC68 80136568 0000282D */  daddu $a1, $zero, $zero
/* 0CCC6C 8013656C 0C0496CF */  jal   set_message_string
/* 0CCC70 80136570 2413004C */   addiu $s3, $zero, 0x4c
/* 0CCC74 80136574 0240202D */  daddu $a0, $s2, $zero
/* 0CCC78 80136578 0C04991D */  jal   get_string_width
/* 0CCC7C 8013657C 0000282D */   daddu $a1, $zero, $zero
/* 0CCC80 80136580 2450001E */  addiu $s0, $v0, 0x1e
/* 0CCC84 80136584 001017C2 */  srl   $v0, $s0, 0x1f
/* 0CCC88 80136588 02021021 */  addu  $v0, $s0, $v0
/* 0CCC8C 8013658C 00021043 */  sra   $v0, $v0, 1
/* 0CCC90 80136590 240300A0 */  addiu $v1, $zero, 0xa0
/* 0CCC94 80136594 00628823 */  subu  $s1, $v1, $v0
.L80136598:
/* 0CCC98 80136598 0C04992C */  jal   func_801264B0
/* 0CCC9C 8013659C 0240202D */   daddu $a0, $s2, $zero
/* 0CCCA0 801365A0 2442FFFF */  addiu $v0, $v0, -1
/* 0CCCA4 801365A4 00021040 */  sll   $v0, $v0, 1
/* 0CCCA8 801365A8 24040002 */  addiu $a0, $zero, 2
/* 0CCCAC 801365AC 8283001A */  lb    $v1, 0x1a($s4)
/* 0CCCB0 801365B0 3C088015 */  lui   $t0, 0x8015
/* 0CCCB4 801365B4 01024021 */  addu  $t0, $t0, $v0
/* 0CCCB8 801365B8 8508C6E0 */  lh    $t0, -0x3920($t0)
/* 0CCCBC 801365BC 10640002 */  beq   $v1, $a0, .L801365C8
/* 0CCCC0 801365C0 0000302D */   daddu $a2, $zero, $zero
/* 0CCCC4 801365C4 2406001C */  addiu $a2, $zero, 0x1c
.L801365C8:
/* 0CCCC8 801365C8 86840018 */  lh    $a0, 0x18($s4)
/* 0CCCCC 801365CC 00041140 */  sll   $v0, $a0, 5
/* 0CCCD0 801365D0 3C038008 */  lui   $v1, 0x8008
/* 0CCCD4 801365D4 00621821 */  addu  $v1, $v1, $v0
/* 0CCCD8 801365D8 946378F8 */  lhu   $v1, 0x78f8($v1)
/* 0CCCDC 801365DC 2404000C */  addiu $a0, $zero, 0xc
/* 0CCCE0 801365E0 0220282D */  daddu $a1, $s1, $zero
/* 0CCCE4 801365E4 24C6FFE8 */  addiu $a2, $a2, -0x18
/* 0CCCE8 801365E8 02663021 */  addu  $a2, $s3, $a2
/* 0CCCEC 801365EC 0200382D */  daddu $a3, $s0, $zero
/* 0CCCF0 801365F0 3C028013 */  lui   $v0, 0x8013
/* 0CCCF4 801365F4 2442673C */  addiu $v0, $v0, 0x673c
/* 0CCCF8 801365F8 AFA20018 */  sw    $v0, 0x18($sp)
/* 0CCCFC 801365FC 2402FFFF */  addiu $v0, $zero, -1
/* 0CCD00 80136600 AFA80010 */  sw    $t0, 0x10($sp)
/* 0CCD04 80136604 AFA00014 */  sw    $zero, 0x14($sp)
/* 0CCD08 80136608 AFB4001C */  sw    $s4, 0x1c($sp)
/* 0CCD0C 8013660C 0C051F32 */  jal   func_80147CC8
/* 0CCD10 80136610 AFA20020 */   sw    $v0, 0x20($sp)
/* 0CCD14 80136614 86830018 */  lh    $v1, 0x18($s4)
/* 0CCD18 80136618 2402015C */  addiu $v0, $zero, 0x15c
/* 0CCD1C 8013661C 10620010 */  beq   $v1, $v0, .L80136660
/* 0CCD20 80136620 24020157 */   addiu $v0, $zero, 0x157
/* 0CCD24 80136624 1062000E */  beq   $v1, $v0, .L80136660
/* 0CCD28 80136628 24040013 */   addiu $a0, $zero, 0x13
/* 0CCD2C 8013662C 24050014 */  addiu $a1, $zero, 0x14
/* 0CCD30 80136630 240600BA */  addiu $a2, $zero, 0xba
/* 0CCD34 80136634 24070118 */  addiu $a3, $zero, 0x118
/* 0CCD38 80136638 24020020 */  addiu $v0, $zero, 0x20
/* 0CCD3C 8013663C AFA20010 */  sw    $v0, 0x10($sp)
/* 0CCD40 80136640 3C028013 */  lui   $v0, 0x8013
/* 0CCD44 80136644 24426A08 */  addiu $v0, $v0, 0x6a08
/* 0CCD48 80136648 AFA20018 */  sw    $v0, 0x18($sp)
/* 0CCD4C 8013664C 2402FFFF */  addiu $v0, $zero, -1
/* 0CCD50 80136650 AFA00014 */  sw    $zero, 0x14($sp)
/* 0CCD54 80136654 AFB4001C */  sw    $s4, 0x1c($sp)
/* 0CCD58 80136658 0C051F32 */  jal   func_80147CC8
/* 0CCD5C 8013665C AFA20020 */   sw    $v0, 0x20($sp)
.L80136660:
/* 0CCD60 80136660 8283001A */  lb    $v1, 0x1a($s4)
/* 0CCD64 80136664 24020002 */  addiu $v0, $zero, 2
/* 0CCD68 80136668 1062002C */  beq   $v1, $v0, .L8013671C
/* 0CCD6C 8013666C 3C04001D */   lui   $a0, 0x1d
/* 0CCD70 80136670 34840060 */  ori   $a0, $a0, 0x60
/* 0CCD74 80136674 0C04991D */  jal   get_string_width
/* 0CCD78 80136678 0000282D */   daddu $a1, $zero, $zero
/* 0CCD7C 8013667C 24500018 */  addiu $s0, $v0, 0x18
/* 0CCD80 80136680 24040011 */  addiu $a0, $zero, 0x11
/* 0CCD84 80136684 00102FC2 */  srl   $a1, $s0, 0x1f
/* 0CCD88 80136688 02052821 */  addu  $a1, $s0, $a1
/* 0CCD8C 8013668C 00052843 */  sra   $a1, $a1, 1
/* 0CCD90 80136690 240200A0 */  addiu $v0, $zero, 0xa0
/* 0CCD94 80136694 00452823 */  subu  $a1, $v0, $a1
/* 0CCD98 80136698 24060024 */  addiu $a2, $zero, 0x24
/* 0CCD9C 8013669C 24020028 */  addiu $v0, $zero, 0x28
/* 0CCDA0 801366A0 AFA20010 */  sw    $v0, 0x10($sp)
/* 0CCDA4 801366A4 3C028013 */  lui   $v0, 0x8013
/* 0CCDA8 801366A8 244269D0 */  addiu $v0, $v0, 0x69d0
/* 0CCDAC 801366AC 0804D9C1 */  j     .L80136704
/* 0CCDB0 801366B0 0200382D */   daddu $a3, $s0, $zero

.L801366B4:
/* 0CCDB4 801366B4 8C840000 */  lw    $a0, ($a0)
/* 0CCDB8 801366B8 0C0496CF */  jal   set_message_string
/* 0CCDBC 801366BC 0000282D */   daddu $a1, $zero, $zero
/* 0CCDC0 801366C0 3C04001D */  lui   $a0, 0x1d
/* 0CCDC4 801366C4 3484005F */  ori   $a0, $a0, 0x5f
/* 0CCDC8 801366C8 0C04991D */  jal   get_string_width
/* 0CCDCC 801366CC 0000282D */   daddu $a1, $zero, $zero
/* 0CCDD0 801366D0 24500036 */  addiu $s0, $v0, 0x36
/* 0CCDD4 801366D4 2404000C */  addiu $a0, $zero, 0xc
/* 0CCDD8 801366D8 00102FC2 */  srl   $a1, $s0, 0x1f
/* 0CCDDC 801366DC 02052821 */  addu  $a1, $s0, $a1
/* 0CCDE0 801366E0 00052843 */  sra   $a1, $a1, 1
/* 0CCDE4 801366E4 240200A0 */  addiu $v0, $zero, 0xa0
/* 0CCDE8 801366E8 00452823 */  subu  $a1, $v0, $a1
/* 0CCDEC 801366EC 2406004C */  addiu $a2, $zero, 0x4c
/* 0CCDF0 801366F0 0200382D */  daddu $a3, $s0, $zero
/* 0CCDF4 801366F4 24020028 */  addiu $v0, $zero, 0x28
/* 0CCDF8 801366F8 AFA20010 */  sw    $v0, 0x10($sp)
/* 0CCDFC 801366FC 3C028013 */  lui   $v0, 0x8013
/* 0CCE00 80136700 2442673C */  addiu $v0, $v0, 0x673c
.L80136704:
/* 0CCE04 80136704 AFA20018 */  sw    $v0, 0x18($sp)
/* 0CCE08 80136708 2402FFFF */  addiu $v0, $zero, -1
/* 0CCE0C 8013670C AFA00014 */  sw    $zero, 0x14($sp)
/* 0CCE10 80136710 AFB4001C */  sw    $s4, 0x1c($sp)
/* 0CCE14 80136714 0C051F32 */  jal   func_80147CC8
/* 0CCE18 80136718 AFA20020 */   sw    $v0, 0x20($sp)
.L8013671C:
/* 0CCE1C 8013671C 8FBF003C */  lw    $ra, 0x3c($sp)
/* 0CCE20 80136720 8FB40038 */  lw    $s4, 0x38($sp)
/* 0CCE24 80136724 8FB30034 */  lw    $s3, 0x34($sp)
/* 0CCE28 80136728 8FB20030 */  lw    $s2, 0x30($sp)
/* 0CCE2C 8013672C 8FB1002C */  lw    $s1, 0x2c($sp)
/* 0CCE30 80136730 8FB00028 */  lw    $s0, 0x28($sp)
/* 0CCE34 80136734 03E00008 */  jr    $ra
/* 0CCE38 80136738 27BD0040 */   addiu $sp, $sp, 0x40

/* 0CCE3C 8013673C 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0CCE40 80136740 AFB1001C */  sw    $s1, 0x1c($sp)
/* 0CCE44 80136744 0080882D */  daddu $s1, $a0, $zero
/* 0CCE48 80136748 AFB20020 */  sw    $s2, 0x20($sp)
/* 0CCE4C 8013674C 00A0902D */  daddu $s2, $a1, $zero
/* 0CCE50 80136750 AFB30024 */  sw    $s3, 0x24($sp)
/* 0CCE54 80136754 3C048008 */  lui   $a0, 0x8008
/* 0CCE58 80136758 248478E0 */  addiu $a0, $a0, 0x78e0
/* 0CCE5C 8013675C AFBF0028 */  sw    $ra, 0x28($sp)
/* 0CCE60 80136760 AFB00018 */  sw    $s0, 0x18($sp)
/* 0CCE64 80136764 86230018 */  lh    $v1, 0x18($s1)
/* 0CCE68 80136768 9222001A */  lbu   $v0, 0x1a($s1)
/* 0CCE6C 8013676C 00031940 */  sll   $v1, $v1, 5
/* 0CCE70 80136770 00642021 */  addu  $a0, $v1, $a0
/* 0CCE74 80136774 2442FFFE */  addiu $v0, $v0, -2
/* 0CCE78 80136778 00021600 */  sll   $v0, $v0, 0x18
/* 0CCE7C 8013677C 00021E03 */  sra   $v1, $v0, 0x18
/* 0CCE80 80136780 2C62000D */  sltiu $v0, $v1, 0xd
/* 0CCE84 80136784 1040008B */  beqz  $v0, .L801369B4
/* 0CCE88 80136788 00C0982D */   daddu $s3, $a2, $zero
/* 0CCE8C 8013678C 00031080 */  sll   $v0, $v1, 2
/* 0CCE90 80136790 3C018015 */  lui   $at, 0x8015
/* 0CCE94 80136794 00220821 */  addu  $at, $at, $v0
/* 0CCE98 80136798 8C220E60 */  lw    $v0, 0xe60($at)
/* 0CCE9C 8013679C 00400008 */  jr    $v0
/* 0CCEA0 801367A0 00000000 */   nop   
/* 0CCEA4 801367A4 94820018 */  lhu   $v0, 0x18($a0)
/* 0CCEA8 801367A8 30420040 */  andi  $v0, $v0, 0x40
/* 0CCEAC 801367AC 1440001C */  bnez  $v0, .L80136820
/* 0CCEB0 801367B0 3C030400 */   lui   $v1, 0x400
/* 0CCEB4 801367B4 8E220000 */  lw    $v0, ($s1)
/* 0CCEB8 801367B8 00431024 */  and   $v0, $v0, $v1
/* 0CCEBC 801367BC 10400005 */  beqz  $v0, .L801367D4
/* 0CCEC0 801367C0 3C10001D */   lui   $s0, 0x1d
/* 0CCEC4 801367C4 96220006 */  lhu   $v0, 6($s1)
/* 0CCEC8 801367C8 30420004 */  andi  $v0, $v0, 4
/* 0CCECC 801367CC 50400002 */  beql  $v0, $zero, .L801367D8
/* 0CCED0 801367D0 3610005A */   ori   $s0, $s0, 0x5a
.L801367D4:
/* 0CCED4 801367D4 36100058 */  ori   $s0, $s0, 0x58
.L801367D8:
/* 0CCED8 801367D8 8C840000 */  lw    $a0, ($a0)
/* 0CCEDC 801367DC 0C0496CF */  jal   set_message_string
/* 0CCEE0 801367E0 0000282D */   daddu $a1, $zero, $zero
/* 0CCEE4 801367E4 96230006 */  lhu   $v1, 6($s1)
/* 0CCEE8 801367E8 30620010 */  andi  $v0, $v1, 0x10
/* 0CCEEC 801367EC 10400003 */  beqz  $v0, .L801367FC
/* 0CCEF0 801367F0 30620020 */   andi  $v0, $v1, 0x20
/* 0CCEF4 801367F4 3C10001D */  lui   $s0, 0x1d
/* 0CCEF8 801367F8 3610005D */  ori   $s0, $s0, 0x5d
.L801367FC:
/* 0CCEFC 801367FC 10400003 */  beqz  $v0, .L8013680C
/* 0CCF00 80136800 30620040 */   andi  $v0, $v1, 0x40
/* 0CCF04 80136804 3C10001D */  lui   $s0, 0x1d
/* 0CCF08 80136808 3610005E */  ori   $s0, $s0, 0x5e
.L8013680C:
/* 0CCF0C 8013680C 1040001E */  beqz  $v0, .L80136888
/* 0CCF10 80136810 00000000 */   nop   
/* 0CCF14 80136814 3C10001D */  lui   $s0, 0x1d
/* 0CCF18 80136818 0804DA22 */  j     .L80136888
/* 0CCF1C 8013681C 3610005C */   ori   $s0, $s0, 0x5c

.L80136820:
/* 0CCF20 80136820 8E220000 */  lw    $v0, ($s1)
/* 0CCF24 80136824 00431024 */  and   $v0, $v0, $v1
/* 0CCF28 80136828 10400005 */  beqz  $v0, .L80136840
/* 0CCF2C 8013682C 3C10001D */   lui   $s0, 0x1d
/* 0CCF30 80136830 96220006 */  lhu   $v0, 6($s1)
/* 0CCF34 80136834 30420004 */  andi  $v0, $v0, 4
/* 0CCF38 80136838 50400002 */  beql  $v0, $zero, .L80136844
/* 0CCF3C 8013683C 3610005B */   ori   $s0, $s0, 0x5b
.L80136840:
/* 0CCF40 80136840 36100059 */  ori   $s0, $s0, 0x59
.L80136844:
/* 0CCF44 80136844 96230006 */  lhu   $v1, 6($s1)
/* 0CCF48 80136848 30620010 */  andi  $v0, $v1, 0x10
/* 0CCF4C 8013684C 10400003 */  beqz  $v0, .L8013685C
/* 0CCF50 80136850 30620020 */   andi  $v0, $v1, 0x20
/* 0CCF54 80136854 3C10001D */  lui   $s0, 0x1d
/* 0CCF58 80136858 3610005D */  ori   $s0, $s0, 0x5d
.L8013685C:
/* 0CCF5C 8013685C 10400003 */  beqz  $v0, .L8013686C
/* 0CCF60 80136860 30620040 */   andi  $v0, $v1, 0x40
/* 0CCF64 80136864 3C10001D */  lui   $s0, 0x1d
/* 0CCF68 80136868 3610005E */  ori   $s0, $s0, 0x5e
.L8013686C:
/* 0CCF6C 8013686C 10400003 */  beqz  $v0, .L8013687C
/* 0CCF70 80136870 00000000 */   nop   
/* 0CCF74 80136874 3C10001D */  lui   $s0, 0x1d
/* 0CCF78 80136878 3610005C */  ori   $s0, $s0, 0x5c
.L8013687C:
/* 0CCF7C 8013687C 8C840000 */  lw    $a0, ($a0)
/* 0CCF80 80136880 0C0496CF */  jal   set_message_string
/* 0CCF84 80136884 0000282D */   daddu $a1, $zero, $zero
.L80136888:
/* 0CCF88 80136888 0C04992C */  jal   func_801264B0
/* 0CCF8C 8013688C 0200202D */   daddu $a0, $s0, $zero
/* 0CCF90 80136890 2442FFFF */  addiu $v0, $v0, -1
/* 0CCF94 80136894 86250018 */  lh    $a1, 0x18($s1)
/* 0CCF98 80136898 00021040 */  sll   $v0, $v0, 1
/* 0CCF9C 8013689C 00051940 */  sll   $v1, $a1, 5
/* 0CCFA0 801368A0 3C048008 */  lui   $a0, 0x8008
/* 0CCFA4 801368A4 00832021 */  addu  $a0, $a0, $v1
/* 0CCFA8 801368A8 948478F8 */  lhu   $a0, 0x78f8($a0)
/* 0CCFAC 801368AC 3C068015 */  lui   $a2, 0x8015
/* 0CCFB0 801368B0 00C23021 */  addu  $a2, $a2, $v0
/* 0CCFB4 801368B4 84C6C6E4 */  lh    $a2, -0x391c($a2)
/* 0CCFB8 801368B8 30830040 */  andi  $v1, $a0, 0x40
/* 0CCFBC 801368BC 5460000E */  bnel  $v1, $zero, .L801368F8
/* 0CCFC0 801368C0 0200202D */   daddu $a0, $s0, $zero
/* 0CCFC4 801368C4 30820008 */  andi  $v0, $a0, 8
/* 0CCFC8 801368C8 5440000B */  bnel  $v0, $zero, .L801368F8
/* 0CCFCC 801368CC 0200202D */   daddu $a0, $s0, $zero
/* 0CCFD0 801368D0 2402015C */  addiu $v0, $zero, 0x15c
/* 0CCFD4 801368D4 10A20007 */  beq   $a1, $v0, .L801368F4
/* 0CCFD8 801368D8 30820020 */   andi  $v0, $a0, 0x20
/* 0CCFDC 801368DC 14400006 */  bnez  $v0, .L801368F8
/* 0CCFE0 801368E0 0200202D */   daddu $a0, $s0, $zero
/* 0CCFE4 801368E4 96220006 */  lhu   $v0, 6($s1)
/* 0CCFE8 801368E8 30420030 */  andi  $v0, $v0, 0x30
/* 0CCFEC 801368EC 1040000B */  beqz  $v0, .L8013691C
/* 0CCFF0 801368F0 26450028 */   addiu $a1, $s2, 0x28
.L801368F4:
/* 0CCFF4 801368F4 0200202D */  daddu $a0, $s0, $zero
.L801368F8:
/* 0CCFF8 801368F8 2645000F */  addiu $a1, $s2, 0xf
/* 0CCFFC 801368FC 02663021 */  addu  $a2, $s3, $a2
/* 0CD000 80136900 240700FF */  addiu $a3, $zero, 0xff
/* 0CD004 80136904 2402002F */  addiu $v0, $zero, 0x2f
/* 0CD008 80136908 AFA20010 */  sw    $v0, 0x10($sp)
/* 0CD00C 8013690C 0C04993B */  jal   draw_string
/* 0CD010 80136910 AFA00014 */   sw    $zero, 0x14($sp)
/* 0CD014 80136914 0804DA6D */  j     .L801369B4
/* 0CD018 80136918 00000000 */   nop   

.L8013691C:
/* 0CD01C 8013691C 02663021 */  addu  $a2, $s3, $a2
/* 0CD020 80136920 240700FF */  addiu $a3, $zero, 0xff
/* 0CD024 80136924 2402002F */  addiu $v0, $zero, 0x2f
/* 0CD028 80136928 AFA20010 */  sw    $v0, 0x10($sp)
/* 0CD02C 8013692C 0C04993B */  jal   draw_string
/* 0CD030 80136930 AFA00014 */   sw    $zero, 0x14($sp)
/* 0CD034 80136934 96220006 */  lhu   $v0, 6($s1)
/* 0CD038 80136938 30420030 */  andi  $v0, $v0, 0x30
/* 0CD03C 8013693C 1440001D */  bnez  $v0, .L801369B4
/* 0CD040 80136940 26450014 */   addiu $a1, $s2, 0x14
/* 0CD044 80136944 0804DA65 */  j     .L80136994
/* 0CD048 80136948 00000000 */   nop   

/* 0CD04C 8013694C 3C028015 */  lui   $v0, 0x8015
/* 0CD050 80136950 8C4268EC */  lw    $v0, 0x68ec($v0)
/* 0CD054 80136954 00021140 */  sll   $v0, $v0, 5
/* 0CD058 80136958 3C048008 */  lui   $a0, 0x8008
/* 0CD05C 8013695C 00822021 */  addu  $a0, $a0, $v0
/* 0CD060 80136960 8C8478E0 */  lw    $a0, 0x78e0($a0)
/* 0CD064 80136964 0C0496CF */  jal   set_message_string
/* 0CD068 80136968 0000282D */   daddu $a1, $zero, $zero
/* 0CD06C 8013696C 3C04001D */  lui   $a0, 0x1d
/* 0CD070 80136970 3484005F */  ori   $a0, $a0, 0x5f
/* 0CD074 80136974 26450028 */  addiu $a1, $s2, 0x28
/* 0CD078 80136978 26660004 */  addiu $a2, $s3, 4
/* 0CD07C 8013697C 240700FF */  addiu $a3, $zero, 0xff
/* 0CD080 80136980 2402002F */  addiu $v0, $zero, 0x2f
/* 0CD084 80136984 AFA20010 */  sw    $v0, 0x10($sp)
/* 0CD088 80136988 0C04993B */  jal   draw_string
/* 0CD08C 8013698C AFA00014 */   sw    $zero, 0x14($sp)
/* 0CD090 80136990 26450014 */  addiu $a1, $s2, 0x14
.L80136994:
/* 0CD094 80136994 3C108015 */  lui   $s0, 0x8015
/* 0CD098 80136998 261068E0 */  addiu $s0, $s0, 0x68e0
/* 0CD09C 8013699C 8E040000 */  lw    $a0, ($s0)
/* 0CD0A0 801369A0 0C051261 */  jal   set_icon_render_pos
/* 0CD0A4 801369A4 26660014 */   addiu $a2, $s3, 0x14
/* 0CD0A8 801369A8 8E040000 */  lw    $a0, ($s0)
/* 0CD0AC 801369AC 0C0511F1 */  jal   draw_icon_1
/* 0CD0B0 801369B0 00000000 */   nop   
.L801369B4:
/* 0CD0B4 801369B4 8FBF0028 */  lw    $ra, 0x28($sp)
/* 0CD0B8 801369B8 8FB30024 */  lw    $s3, 0x24($sp)
/* 0CD0BC 801369BC 8FB20020 */  lw    $s2, 0x20($sp)
/* 0CD0C0 801369C0 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0CD0C4 801369C4 8FB00018 */  lw    $s0, 0x18($sp)
/* 0CD0C8 801369C8 03E00008 */  jr    $ra
/* 0CD0CC 801369CC 27BD0030 */   addiu $sp, $sp, 0x30

/* 0CD0D0 801369D0 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0CD0D4 801369D4 3C04001D */  lui   $a0, 0x1d
/* 0CD0D8 801369D8 34840060 */  ori   $a0, $a0, 0x60
/* 0CD0DC 801369DC 24020034 */  addiu $v0, $zero, 0x34
/* 0CD0E0 801369E0 24A5000C */  addiu $a1, $a1, 0xc
/* 0CD0E4 801369E4 24C60004 */  addiu $a2, $a2, 4
/* 0CD0E8 801369E8 240700FF */  addiu $a3, $zero, 0xff
/* 0CD0EC 801369EC AFBF0018 */  sw    $ra, 0x18($sp)
/* 0CD0F0 801369F0 AFA20010 */  sw    $v0, 0x10($sp)
/* 0CD0F4 801369F4 0C04993B */  jal   draw_string
/* 0CD0F8 801369F8 AFA00014 */   sw    $zero, 0x14($sp)
/* 0CD0FC 801369FC 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0CD100 80136A00 03E00008 */  jr    $ra
/* 0CD104 80136A04 27BD0020 */   addiu $sp, $sp, 0x20

/* 0CD108 80136A08 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0CD10C 80136A0C 3C038008 */  lui   $v1, 0x8008
/* 0CD110 80136A10 246378E0 */  addiu $v1, $v1, 0x78e0
/* 0CD114 80136A14 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0CD118 80136A18 84820018 */  lh    $v0, 0x18($a0)
/* 0CD11C 80136A1C 8084001A */  lb    $a0, 0x1a($a0)
/* 0CD120 80136A20 00021140 */  sll   $v0, $v0, 5
/* 0CD124 80136A24 00431821 */  addu  $v1, $v0, $v1
/* 0CD128 80136A28 28820002 */  slti  $v0, $a0, 2
/* 0CD12C 80136A2C 1440000E */  bnez  $v0, .L80136A68
/* 0CD130 80136A30 28820004 */   slti  $v0, $a0, 4
/* 0CD134 80136A34 14400006 */  bnez  $v0, .L80136A50
/* 0CD138 80136A38 2402000A */   addiu $v0, $zero, 0xa
/* 0CD13C 80136A3C 2882000C */  slti  $v0, $a0, 0xc
/* 0CD140 80136A40 10400009 */  beqz  $v0, .L80136A68
/* 0CD144 80136A44 2882000A */   slti  $v0, $a0, 0xa
/* 0CD148 80136A48 14400007 */  bnez  $v0, .L80136A68
/* 0CD14C 80136A4C 2402000A */   addiu $v0, $zero, 0xa
.L80136A50:
/* 0CD150 80136A50 24A50008 */  addiu $a1, $a1, 8
/* 0CD154 80136A54 8C640014 */  lw    $a0, 0x14($v1)
/* 0CD158 80136A58 240700FF */  addiu $a3, $zero, 0xff
/* 0CD15C 80136A5C AFA20010 */  sw    $v0, 0x10($sp)
/* 0CD160 80136A60 0C04993B */  jal   draw_string
/* 0CD164 80136A64 AFA00014 */   sw    $zero, 0x14($sp)
.L80136A68:
/* 0CD168 80136A68 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0CD16C 80136A6C 03E00008 */  jr    $ra
/* 0CD170 80136A70 27BD0020 */   addiu $sp, $sp, 0x20

/* 0CD174 80136A74 00000000 */  nop   
/* 0CD178 80136A78 00000000 */  nop   
/* 0CD17C 80136A7C 00000000 */  nop   


