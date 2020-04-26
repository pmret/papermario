
.section .text80060510, "ax"

nuContMgrInit:
/* 03B910 80060510 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 03B914 80060514 AFBF0010 */  sw    $ra, 0x10($sp)
/* 03B918 80060518 0C01823C */  jal   nuContDataUnLock
/* 03B91C 8006051C 00000000 */   nop   
/* 03B920 80060520 3C04800B */  lui   $a0, 0x800b
/* 03B924 80060524 24840EB8 */  addiu $a0, $a0, 0xeb8
/* 03B928 80060528 3C05800B */  lui   $a1, 0x800b
/* 03B92C 8006052C 24A5E6D0 */  addiu $a1, $a1, -0x1930
/* 03B930 80060530 0C019560 */  jal   osCreateMesgQueue
/* 03B934 80060534 24060001 */   addiu $a2, $zero, 1
/* 03B938 80060538 3C04800E */  lui   $a0, 0x800e
/* 03B93C 8006053C 2484C040 */  addiu $a0, $a0, -0x3fc0
/* 03B940 80060540 3C05800B */  lui   $a1, 0x800b
/* 03B944 80060544 24A5E6D4 */  addiu $a1, $a1, -0x192c
/* 03B948 80060548 0C019560 */  jal   osCreateMesgQueue
/* 03B94C 8006054C 24060001 */   addiu $a2, $zero, 1
/* 03B950 80060550 3C048009 */  lui   $a0, 0x8009
/* 03B954 80060554 0C0180FC */  jal   nuSiCallBackAdd
/* 03B958 80060558 24843D38 */   addiu $a0, $a0, 0x3d38
/* 03B95C 8006055C 0C018248 */  jal   nuContQueryRead
/* 03B960 80060560 00000000 */   nop   
/* 03B964 80060564 24050001 */  addiu $a1, $zero, 1
/* 03B968 80060568 0000302D */  daddu $a2, $zero, $zero
/* 03B96C 8006056C 0000202D */  daddu $a0, $zero, $zero
/* 03B970 80060570 24070005 */  addiu $a3, $zero, 5
/* 03B974 80060574 3C01800A */  lui   $at, 0x800a
/* 03B978 80060578 AC20A614 */  sw    $zero, -0x59ec($at)
/* 03B97C 8006057C 00041880 */  sll   $v1, $a0, 2
.L80060580:
/* 03B980 80060580 3C02800B */  lui   $v0, 0x800b
/* 03B984 80060584 00431021 */  addu  $v0, $v0, $v1
/* 03B988 80060588 90421B7F */  lbu   $v0, 0x1b7f($v0)
/* 03B98C 8006058C 5440000F */  bnezl $v0, .L800605CC
/* 03B990 80060590 24840001 */   addiu $a0, $a0, 1
/* 03B994 80060594 3C02800B */  lui   $v0, 0x800b
/* 03B998 80060598 00431021 */  addu  $v0, $v0, $v1
/* 03B99C 8006059C 94421B7C */  lhu   $v0, 0x1b7c($v0)
/* 03B9A0 800605A0 30421F07 */  andi  $v0, $v0, 0x1f07
/* 03B9A4 800605A4 54470008 */  bnel  $v0, $a3, .L800605C8
/* 03B9A8 800605A8 00052840 */   sll   $a1, $a1, 1
/* 03B9AC 800605AC 3C02800A */  lui   $v0, 0x800a
/* 03B9B0 800605B0 8C42A614 */  lw    $v0, -0x59ec($v0)
/* 03B9B4 800605B4 00C53025 */  or    $a2, $a2, $a1
/* 03B9B8 800605B8 24420001 */  addiu $v0, $v0, 1
/* 03B9BC 800605BC 3C01800A */  lui   $at, 0x800a
/* 03B9C0 800605C0 AC22A614 */  sw    $v0, -0x59ec($at)
/* 03B9C4 800605C4 00052840 */  sll   $a1, $a1, 1
.L800605C8:
/* 03B9C8 800605C8 24840001 */  addiu $a0, $a0, 1
.L800605CC:
/* 03B9CC 800605CC 28820004 */  slti  $v0, $a0, 4
/* 03B9D0 800605D0 1440FFEB */  bnez  $v0, .L80060580
/* 03B9D4 800605D4 00041880 */   sll   $v1, $a0, 2
/* 03B9D8 800605D8 8FBF0010 */  lw    $ra, 0x10($sp)
/* 03B9DC 800605DC 30C200FF */  andi  $v0, $a2, 0xff
/* 03B9E0 800605E0 03E00008 */  jr    $ra
/* 03B9E4 800605E4 27BD0018 */   addiu $sp, $sp, 0x18

nuContMgrRemove:
/* 03B9E8 800605E8 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 03B9EC 800605EC 3C048009 */  lui   $a0, 0x8009
/* 03B9F0 800605F0 24843D38 */  addiu $a0, $a0, 0x3d38
/* 03B9F4 800605F4 AFBF0010 */  sw    $ra, 0x10($sp)
/* 03B9F8 800605F8 0C018124 */  jal   nuSiCallBackRemove
/* 03B9FC 800605FC 00000000 */   nop   
/* 03BA00 80060600 8FBF0010 */  lw    $ra, 0x10($sp)
/* 03BA04 80060604 03E00008 */  jr    $ra
/* 03BA08 80060608 27BD0018 */   addiu $sp, $sp, 0x18

nuContDataClose:
/* 03BA0C 8006060C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 03BA10 80060610 3C04800E */  lui   $a0, 0x800e
/* 03BA14 80060614 2484C040 */  addiu $a0, $a0, -0x3fc0
/* 03BA18 80060618 0000282D */  daddu $a1, $zero, $zero
/* 03BA1C 8006061C AFBF0010 */  sw    $ra, 0x10($sp)
/* 03BA20 80060620 0C019608 */  jal   osSendMesg
/* 03BA24 80060624 24060001 */   addiu $a2, $zero, 1
/* 03BA28 80060628 8FBF0010 */  lw    $ra, 0x10($sp)
/* 03BA2C 8006062C 03E00008 */  jr    $ra
/* 03BA30 80060630 27BD0018 */   addiu $sp, $sp, 0x18

nuContDataOpen:
/* 03BA34 80060634 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 03BA38 80060638 3C04800E */  lui   $a0, 0x800e
/* 03BA3C 8006063C 2484C040 */  addiu $a0, $a0, -0x3fc0
/* 03BA40 80060640 0000282D */  daddu $a1, $zero, $zero
/* 03BA44 80060644 AFBF0010 */  sw    $ra, 0x10($sp)
/* 03BA48 80060648 0C0195BC */  jal   osRecvMesg
/* 03BA4C 8006064C 24060001 */   addiu $a2, $zero, 1
/* 03BA50 80060650 8FBF0010 */  lw    $ra, 0x10($sp)
/* 03BA54 80060654 03E00008 */  jr    $ra
/* 03BA58 80060658 27BD0018 */   addiu $sp, $sp, 0x18

contRetrace:
/* 03BA5C 8006065C 3C02800A */  lui   $v0, 0x800a
/* 03BA60 80060660 8C42A5E0 */  lw    $v0, -0x5a20($v0)
/* 03BA64 80060664 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 03BA68 80060668 AFB00010 */  sw    $s0, 0x10($sp)
/* 03BA6C 8006066C 0080802D */  daddu $s0, $a0, $zero
/* 03BA70 80060670 1440002C */  bnez  $v0, .L80060724
/* 03BA74 80060674 AFBF0014 */   sw    $ra, 0x14($sp)
/* 03BA78 80060678 3C04800B */  lui   $a0, 0x800b
/* 03BA7C 8006067C 24840EB8 */  addiu $a0, $a0, 0xeb8
/* 03BA80 80060680 0000282D */  daddu $a1, $zero, $zero
/* 03BA84 80060684 0C0195BC */  jal   osRecvMesg
/* 03BA88 80060688 00A0302D */   daddu $a2, $a1, $zero
/* 03BA8C 8006068C 3C04800E */  lui   $a0, 0x800e
/* 03BA90 80060690 2484AC78 */  addiu $a0, $a0, -0x5388
/* 03BA94 80060694 0C018668 */  jal   osContStartReadData
/* 03BA98 80060698 00000000 */   nop   
/* 03BA9C 8006069C 14400016 */  bnez  $v0, .L800606F8
/* 03BAA0 800606A0 0000282D */   daddu $a1, $zero, $zero
/* 03BAA4 800606A4 3C04800E */  lui   $a0, 0x800e
/* 03BAA8 800606A8 2484AC78 */  addiu $a0, $a0, -0x5388
/* 03BAAC 800606AC 0C0195BC */  jal   osRecvMesg
/* 03BAB0 800606B0 24060001 */   addiu $a2, $zero, 1
/* 03BAB4 800606B4 3C02800A */  lui   $v0, 0x800a
/* 03BAB8 800606B8 8C42A5E0 */  lw    $v0, -0x5a20($v0)
/* 03BABC 800606BC 30420001 */  andi  $v0, $v0, 1
/* 03BAC0 800606C0 1440000D */  bnez  $v0, .L800606F8
/* 03BAC4 800606C4 0000282D */   daddu $a1, $zero, $zero
/* 03BAC8 800606C8 3C04800E */  lui   $a0, 0x800e
/* 03BACC 800606CC 2484C040 */  addiu $a0, $a0, -0x3fc0
/* 03BAD0 800606D0 0C019608 */  jal   osSendMesg
/* 03BAD4 800606D4 24060001 */   addiu $a2, $zero, 1
/* 03BAD8 800606D8 3C04800B */  lui   $a0, 0x800b
/* 03BADC 800606DC 0C01868A */  jal   osContGetReadData
/* 03BAE0 800606E0 24841D68 */   addiu $a0, $a0, 0x1d68
/* 03BAE4 800606E4 3C04800E */  lui   $a0, 0x800e
/* 03BAE8 800606E8 2484C040 */  addiu $a0, $a0, -0x3fc0
/* 03BAEC 800606EC 0000282D */  daddu $a1, $zero, $zero
/* 03BAF0 800606F0 0C0195BC */  jal   osRecvMesg
/* 03BAF4 800606F4 24060001 */   addiu $a2, $zero, 1
.L800606F8:
/* 03BAF8 800606F8 3C028009 */  lui   $v0, 0x8009
/* 03BAFC 800606FC 8C423D20 */  lw    $v0, 0x3d20($v0)
/* 03BB00 80060700 10400003 */  beqz  $v0, .L80060710
/* 03BB04 80060704 00000000 */   nop   
/* 03BB08 80060708 0040F809 */  jalr  $v0
/* 03BB0C 8006070C 86040000 */  lh    $a0, ($s0)
.L80060710:
/* 03BB10 80060710 3C04800B */  lui   $a0, 0x800b
/* 03BB14 80060714 24840EB8 */  addiu $a0, $a0, 0xeb8
/* 03BB18 80060718 0000282D */  daddu $a1, $zero, $zero
/* 03BB1C 8006071C 0C019608 */  jal   osSendMesg
/* 03BB20 80060720 00A0302D */   daddu $a2, $a1, $zero
.L80060724:
/* 03BB24 80060724 0000102D */  daddu $v0, $zero, $zero
/* 03BB28 80060728 8FBF0014 */  lw    $ra, 0x14($sp)
/* 03BB2C 8006072C 8FB00010 */  lw    $s0, 0x10($sp)
/* 03BB30 80060730 03E00008 */  jr    $ra
/* 03BB34 80060734 27BD0018 */   addiu $sp, $sp, 0x18

contReadData:
/* 03BB38 80060738 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 03BB3C 8006073C AFBF0014 */  sw    $ra, 0x14($sp)
/* 03BB40 80060740 AFB00010 */  sw    $s0, 0x10($sp)
/* 03BB44 80060744 8C90000C */  lw    $s0, 0xc($a0)
/* 03BB48 80060748 3C04800E */  lui   $a0, 0x800e
/* 03BB4C 8006074C 2484AC78 */  addiu $a0, $a0, -0x5388
/* 03BB50 80060750 0C018668 */  jal   osContStartReadData
/* 03BB54 80060754 00000000 */   nop   
/* 03BB58 80060758 14400012 */  bnez  $v0, .L800607A4
/* 03BB5C 8006075C 0000282D */   daddu $a1, $zero, $zero
/* 03BB60 80060760 3C04800E */  lui   $a0, 0x800e
/* 03BB64 80060764 2484AC78 */  addiu $a0, $a0, -0x5388
/* 03BB68 80060768 0C0195BC */  jal   osRecvMesg
/* 03BB6C 8006076C 24060001 */   addiu $a2, $zero, 1
/* 03BB70 80060770 3C04800E */  lui   $a0, 0x800e
/* 03BB74 80060774 2484C040 */  addiu $a0, $a0, -0x3fc0
/* 03BB78 80060778 0000282D */  daddu $a1, $zero, $zero
/* 03BB7C 8006077C 0C019608 */  jal   osSendMesg
/* 03BB80 80060780 24060001 */   addiu $a2, $zero, 1
/* 03BB84 80060784 0C01868A */  jal   osContGetReadData
/* 03BB88 80060788 0200202D */   daddu $a0, $s0, $zero
/* 03BB8C 8006078C 3C04800E */  lui   $a0, 0x800e
/* 03BB90 80060790 2484C040 */  addiu $a0, $a0, -0x3fc0
/* 03BB94 80060794 0000282D */  daddu $a1, $zero, $zero
/* 03BB98 80060798 0C0195BC */  jal   osRecvMesg
/* 03BB9C 8006079C 24060001 */   addiu $a2, $zero, 1
/* 03BBA0 800607A0 0000102D */  daddu $v0, $zero, $zero
.L800607A4:
/* 03BBA4 800607A4 8FBF0014 */  lw    $ra, 0x14($sp)
/* 03BBA8 800607A8 8FB00010 */  lw    $s0, 0x10($sp)
/* 03BBAC 800607AC 03E00008 */  jr    $ra
/* 03BBB0 800607B0 27BD0018 */   addiu $sp, $sp, 0x18

contReadNW:
/* 03BBB4 800607B4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 03BBB8 800607B8 AFB00010 */  sw    $s0, 0x10($sp)
/* 03BBBC 800607BC 0080802D */  daddu $s0, $a0, $zero
/* 03BBC0 800607C0 3C04800B */  lui   $a0, 0x800b
/* 03BBC4 800607C4 24840EB8 */  addiu $a0, $a0, 0xeb8
/* 03BBC8 800607C8 0000282D */  daddu $a1, $zero, $zero
/* 03BBCC 800607CC AFBF0014 */  sw    $ra, 0x14($sp)
/* 03BBD0 800607D0 0C0195BC */  jal   osRecvMesg
/* 03BBD4 800607D4 00A0302D */   daddu $a2, $a1, $zero
/* 03BBD8 800607D8 3C04800E */  lui   $a0, 0x800e
/* 03BBDC 800607DC 2484AC78 */  addiu $a0, $a0, -0x5388
/* 03BBE0 800607E0 0C018668 */  jal   osContStartReadData
/* 03BBE4 800607E4 00000000 */   nop   
/* 03BBE8 800607E8 14400013 */  bnez  $v0, .L80060838
/* 03BBEC 800607EC 0000282D */   daddu $a1, $zero, $zero
/* 03BBF0 800607F0 3C04800E */  lui   $a0, 0x800e
/* 03BBF4 800607F4 2484AC78 */  addiu $a0, $a0, -0x5388
/* 03BBF8 800607F8 0C0195BC */  jal   osRecvMesg
/* 03BBFC 800607FC 24060001 */   addiu $a2, $zero, 1
/* 03BC00 80060800 3C04800E */  lui   $a0, 0x800e
/* 03BC04 80060804 2484C040 */  addiu $a0, $a0, -0x3fc0
/* 03BC08 80060808 0000282D */  daddu $a1, $zero, $zero
/* 03BC0C 8006080C 0C019608 */  jal   osSendMesg
/* 03BC10 80060810 24060001 */   addiu $a2, $zero, 1
/* 03BC14 80060814 3C04800B */  lui   $a0, 0x800b
/* 03BC18 80060818 0C01868A */  jal   osContGetReadData
/* 03BC1C 8006081C 24841D68 */   addiu $a0, $a0, 0x1d68
/* 03BC20 80060820 3C04800E */  lui   $a0, 0x800e
/* 03BC24 80060824 2484C040 */  addiu $a0, $a0, -0x3fc0
/* 03BC28 80060828 0000282D */  daddu $a1, $zero, $zero
/* 03BC2C 8006082C 0C0195BC */  jal   osRecvMesg
/* 03BC30 80060830 24060001 */   addiu $a2, $zero, 1
/* 03BC34 80060834 0000102D */  daddu $v0, $zero, $zero
.L80060838:
/* 03BC38 80060838 14400009 */  bnez  $v0, .L80060860
/* 03BC3C 8006083C 00000000 */   nop   
/* 03BC40 80060840 3C028009 */  lui   $v0, 0x8009
/* 03BC44 80060844 8C423D20 */  lw    $v0, 0x3d20($v0)
/* 03BC48 80060848 50400005 */  beql  $v0, $zero, .L80060860
/* 03BC4C 8006084C 0000102D */   daddu $v0, $zero, $zero
/* 03BC50 80060850 86040000 */  lh    $a0, ($s0)
/* 03BC54 80060854 0040F809 */  jalr  $v0
/* 03BC58 80060858 00000000 */  nop   
/* 03BC5C 8006085C 0000102D */  daddu $v0, $zero, $zero
.L80060860:
/* 03BC60 80060860 8FBF0014 */  lw    $ra, 0x14($sp)
/* 03BC64 80060864 8FB00010 */  lw    $s0, 0x10($sp)
/* 03BC68 80060868 03E00008 */  jr    $ra
/* 03BC6C 8006086C 27BD0018 */   addiu $sp, $sp, 0x18

contQuery:
/* 03BC70 80060870 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 03BC74 80060874 AFB00010 */  sw    $s0, 0x10($sp)
/* 03BC78 80060878 3C10800E */  lui   $s0, 0x800e
/* 03BC7C 8006087C 2610AC78 */  addiu $s0, $s0, -0x5388
/* 03BC80 80060880 AFBF0014 */  sw    $ra, 0x14($sp)
/* 03BC84 80060884 0C018640 */  jal   osContStartQuery
/* 03BC88 80060888 0200202D */   daddu $a0, $s0, $zero
/* 03BC8C 8006088C 14400008 */  bnez  $v0, .L800608B0
/* 03BC90 80060890 0200202D */   daddu $a0, $s0, $zero
/* 03BC94 80060894 0000282D */  daddu $a1, $zero, $zero
/* 03BC98 80060898 0C0195BC */  jal   osRecvMesg
/* 03BC9C 8006089C 24060001 */   addiu $a2, $zero, 1
/* 03BCA0 800608A0 3C04800B */  lui   $a0, 0x800b
/* 03BCA4 800608A4 0C018660 */  jal   osContGetQuery
/* 03BCA8 800608A8 24841B7C */   addiu $a0, $a0, 0x1b7c
/* 03BCAC 800608AC 0000102D */  daddu $v0, $zero, $zero
.L800608B0:
/* 03BCB0 800608B0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 03BCB4 800608B4 8FB00010 */  lw    $s0, 0x10($sp)
/* 03BCB8 800608B8 03E00008 */  jr    $ra
/* 03BCBC 800608BC 27BD0018 */   addiu $sp, $sp, 0x18

nuContDataLock:
/* 03BCC0 800608C0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 03BCC4 800608C4 AFBF0010 */  sw    $ra, 0x10($sp)
/* 03BCC8 800608C8 0C018250 */  jal   osSetIntMask
/* 03BCCC 800608CC 24040001 */   addiu $a0, $zero, 1
/* 03BCD0 800608D0 24030001 */  addiu $v1, $zero, 1
/* 03BCD4 800608D4 3C01800A */  lui   $at, 0x800a
/* 03BCD8 800608D8 AC23A5E0 */  sw    $v1, -0x5a20($at)
/* 03BCDC 800608DC 0C018250 */  jal   osSetIntMask
/* 03BCE0 800608E0 0040202D */   daddu $a0, $v0, $zero
/* 03BCE4 800608E4 8FBF0010 */  lw    $ra, 0x10($sp)
/* 03BCE8 800608E8 03E00008 */  jr    $ra
/* 03BCEC 800608EC 27BD0018 */   addiu $sp, $sp, 0x18

nuContDataUnLock:
/* 03BCF0 800608F0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 03BCF4 800608F4 AFBF0010 */  sw    $ra, 0x10($sp)
/* 03BCF8 800608F8 0C018250 */  jal   osSetIntMask
/* 03BCFC 800608FC 24040001 */   addiu $a0, $zero, 1
/* 03BD00 80060900 3C01800A */  lui   $at, 0x800a
/* 03BD04 80060904 AC20A5E0 */  sw    $zero, -0x5a20($at)
/* 03BD08 80060908 0C018250 */  jal   osSetIntMask
/* 03BD0C 8006090C 0040202D */   daddu $a0, $v0, $zero
/* 03BD10 80060910 8FBF0010 */  lw    $ra, 0x10($sp)
/* 03BD14 80060914 03E00008 */  jr    $ra
/* 03BD18 80060918 27BD0018 */   addiu $sp, $sp, 0x18

/* 03BD1C 8006091C 00000000 */  nop   
