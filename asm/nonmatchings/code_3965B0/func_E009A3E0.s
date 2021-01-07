.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E009A3E0
/* 396990 E009A3E0 27BDFF20 */  addiu     $sp, $sp, -0xe0
/* 396994 E009A3E4 0080482D */  daddu     $t1, $a0, $zero
/* 396998 E009A3E8 3C0ADB06 */  lui       $t2, 0xdb06
/* 39699C E009A3EC 354A0024 */  ori       $t2, $t2, 0x24
/* 3969A0 E009A3F0 27A40020 */  addiu     $a0, $sp, 0x20
/* 3969A4 E009A3F4 AFB200B0 */  sw        $s2, 0xb0($sp)
/* 3969A8 E009A3F8 3C12800A */  lui       $s2, %hi(D_8009A66C)
/* 3969AC E009A3FC 2652A66C */  addiu     $s2, $s2, %lo(D_8009A66C)
/* 3969B0 E009A400 3C013C23 */  lui       $at, 0x3c23
/* 3969B4 E009A404 3421D70A */  ori       $at, $at, 0xd70a
/* 3969B8 E009A408 44810000 */  mtc1      $at, $f0
/* 3969BC E009A40C 3C02E700 */  lui       $v0, 0xe700
/* 3969C0 E009A410 AFBF00CC */  sw        $ra, 0xcc($sp)
/* 3969C4 E009A414 AFBE00C8 */  sw        $fp, 0xc8($sp)
/* 3969C8 E009A418 AFB700C4 */  sw        $s7, 0xc4($sp)
/* 3969CC E009A41C AFB600C0 */  sw        $s6, 0xc0($sp)
/* 3969D0 E009A420 AFB500BC */  sw        $s5, 0xbc($sp)
/* 3969D4 E009A424 AFB400B8 */  sw        $s4, 0xb8($sp)
/* 3969D8 E009A428 AFB300B4 */  sw        $s3, 0xb4($sp)
/* 3969DC E009A42C AFB100AC */  sw        $s1, 0xac($sp)
/* 3969E0 E009A430 AFB000A8 */  sw        $s0, 0xa8($sp)
/* 3969E4 E009A434 F7B600D8 */  sdc1      $f22, 0xd8($sp)
/* 3969E8 E009A438 F7B400D0 */  sdc1      $f20, 0xd0($sp)
/* 3969EC E009A43C 8E430000 */  lw        $v1, ($s2)
/* 3969F0 E009A440 8D35000C */  lw        $s5, 0xc($t1)
/* 3969F4 E009A444 0060402D */  daddu     $t0, $v1, $zero
/* 3969F8 E009A448 44050000 */  mfc1      $a1, $f0
/* 3969FC E009A44C 24630008 */  addiu     $v1, $v1, 8
/* 396A00 E009A450 AE430000 */  sw        $v1, ($s2)
/* 396A04 E009A454 C6B60034 */  lwc1      $f22, 0x34($s5)
/* 396A08 E009A458 8EB70038 */  lw        $s7, 0x38($s5)
/* 396A0C E009A45C 8EAF003C */  lw        $t7, 0x3c($s5)
/* 396A10 E009A460 3C1E8000 */  lui       $fp, 0x8000
/* 396A14 E009A464 AFAF00A0 */  sw        $t7, 0xa0($sp)
/* 396A18 E009A468 8EB60044 */  lw        $s6, 0x44($s5)
/* 396A1C E009A46C 00A0302D */  daddu     $a2, $a1, $zero
/* 396A20 E009A470 AD020000 */  sw        $v0, ($t0)
/* 396A24 E009A474 AD000004 */  sw        $zero, 4($t0)
/* 396A28 E009A478 AC6A0000 */  sw        $t2, ($v1)
/* 396A2C E009A47C 8D280010 */  lw        $t0, 0x10($t1)
/* 396A30 E009A480 24620008 */  addiu     $v0, $v1, 8
/* 396A34 E009A484 AE420000 */  sw        $v0, ($s2)
/* 396A38 E009A488 8D02001C */  lw        $v0, 0x1c($t0)
/* 396A3C E009A48C 00A0382D */  daddu     $a3, $a1, $zero
/* 396A40 E009A490 005E1021 */  addu      $v0, $v0, $fp
/* 396A44 E009A494 0C080110 */  jal       func_E0200440
/* 396A48 E009A498 AC620004 */   sw       $v0, 4($v1)
/* 396A4C E009A49C C6A00024 */  lwc1      $f0, 0x24($s5)
/* 396A50 E009A4A0 3C0142C8 */  lui       $at, 0x42c8
/* 396A54 E009A4A4 44812000 */  mtc1      $at, $f4
/* 396A58 E009A4A8 E7A00010 */  swc1      $f0, 0x10($sp)
/* 396A5C E009A4AC C6A00004 */  lwc1      $f0, 4($s5)
/* 396A60 E009A4B0 46040002 */  mul.s     $f0, $f0, $f4
/* 396A64 E009A4B4 00000000 */  nop       
/* 396A68 E009A4B8 E7A00014 */  swc1      $f0, 0x14($sp)
/* 396A6C E009A4BC C6A00008 */  lwc1      $f0, 8($s5)
/* 396A70 E009A4C0 46040002 */  mul.s     $f0, $f0, $f4
/* 396A74 E009A4C4 00000000 */  nop       
/* 396A78 E009A4C8 3C140001 */  lui       $s4, 1
/* 396A7C E009A4CC 36941630 */  ori       $s4, $s4, 0x1630
/* 396A80 E009A4D0 27B00060 */  addiu     $s0, $sp, 0x60
/* 396A84 E009A4D4 E7A00018 */  swc1      $f0, 0x18($sp)
/* 396A88 E009A4D8 C6A0000C */  lwc1      $f0, 0xc($s5)
/* 396A8C E009A4DC 44801000 */  mtc1      $zero, $f2
/* 396A90 E009A4E0 46040002 */  mul.s     $f0, $f0, $f4
/* 396A94 E009A4E4 00000000 */  nop       
/* 396A98 E009A4E8 44051000 */  mfc1      $a1, $f2
/* 396A9C E009A4EC 0200202D */  daddu     $a0, $s0, $zero
/* 396AA0 E009A4F0 00A0302D */  daddu     $a2, $a1, $zero
/* 396AA4 E009A4F4 00A0382D */  daddu     $a3, $a1, $zero
/* 396AA8 E009A4F8 0C080180 */  jal       func_E0200600
/* 396AAC E009A4FC E7A0001C */   swc1     $f0, 0x1c($sp)
/* 396AB0 E009A500 0200202D */  daddu     $a0, $s0, $zero
/* 396AB4 E009A504 27A50020 */  addiu     $a1, $sp, 0x20
/* 396AB8 E009A508 0C080114 */  jal       func_E0200450
/* 396ABC E009A50C 00A0302D */   daddu    $a2, $a1, $zero
/* 396AC0 E009A510 27A40020 */  addiu     $a0, $sp, 0x20
/* 396AC4 E009A514 3C118007 */  lui       $s1, %hi(D_800741F0)
/* 396AC8 E009A518 263141F0 */  addiu     $s1, $s1, %lo(D_800741F0)
/* 396ACC E009A51C 3C13800A */  lui       $s3, %hi(D_8009A674)
/* 396AD0 E009A520 2673A674 */  addiu     $s3, $s3, %lo(D_8009A674)
/* 396AD4 E009A524 96250000 */  lhu       $a1, ($s1)
/* 396AD8 E009A528 8E620000 */  lw        $v0, ($s3)
/* 396ADC E009A52C 00052980 */  sll       $a1, $a1, 6
/* 396AE0 E009A530 00B42821 */  addu      $a1, $a1, $s4
/* 396AE4 E009A534 0C080118 */  jal       func_E0200460
/* 396AE8 E009A538 00452821 */   addu     $a1, $v0, $a1
/* 396AEC E009A53C 3C03DA38 */  lui       $v1, 0xda38
/* 396AF0 E009A540 34630002 */  ori       $v1, $v1, 2
/* 396AF4 E009A544 00161100 */  sll       $v0, $s6, 4
/* 396AF8 E009A548 00561023 */  subu      $v0, $v0, $s6
/* 396AFC E009A54C 00021040 */  sll       $v0, $v0, 1
/* 396B00 E009A550 4482A000 */  mtc1      $v0, $f20
/* 396B04 E009A554 00000000 */  nop       
/* 396B08 E009A558 4680A520 */  cvt.s.w   $f20, $f20
/* 396B0C E009A55C 4600A306 */  mov.s     $f12, $f20
/* 396B10 E009A560 8E500000 */  lw        $s0, ($s2)
/* 396B14 E009A564 96220000 */  lhu       $v0, ($s1)
/* 396B18 E009A568 0200202D */  daddu     $a0, $s0, $zero
/* 396B1C E009A56C 26100008 */  addiu     $s0, $s0, 8
/* 396B20 E009A570 AE500000 */  sw        $s0, ($s2)
/* 396B24 E009A574 AC830000 */  sw        $v1, ($a0)
/* 396B28 E009A578 24430001 */  addiu     $v1, $v0, 1
/* 396B2C E009A57C 3042FFFF */  andi      $v0, $v0, 0xffff
/* 396B30 E009A580 00021180 */  sll       $v0, $v0, 6
/* 396B34 E009A584 A6230000 */  sh        $v1, ($s1)
/* 396B38 E009A588 8E630000 */  lw        $v1, ($s3)
/* 396B3C E009A58C 00541021 */  addu      $v0, $v0, $s4
/* 396B40 E009A590 00621821 */  addu      $v1, $v1, $v0
/* 396B44 E009A594 26020008 */  addiu     $v0, $s0, 8
/* 396B48 E009A598 AC830004 */  sw        $v1, 4($a0)
/* 396B4C E009A59C AE420000 */  sw        $v0, ($s2)
/* 396B50 E009A5A0 3C02FA00 */  lui       $v0, 0xfa00
/* 396B54 E009A5A4 0C080140 */  jal       func_E0200500
/* 396B58 E009A5A8 AE020000 */   sw       $v0, ($s0)
/* 396B5C E009A5AC 4600A306 */  mov.s     $f12, $f20
/* 396B60 E009A5B0 0C080140 */  jal       func_E0200500
/* 396B64 E009A5B4 46000506 */   mov.s    $f20, $f0
/* 396B68 E009A5B8 3C0141C8 */  lui       $at, 0x41c8
/* 396B6C E009A5BC 44811000 */  mtc1      $at, $f2
/* 396B70 E009A5C0 00000000 */  nop       
/* 396B74 E009A5C4 4602A502 */  mul.s     $f20, $f20, $f2
/* 396B78 E009A5C8 00000000 */  nop       
/* 396B7C E009A5CC 3C014361 */  lui       $at, 0x4361
/* 396B80 E009A5D0 44811000 */  mtc1      $at, $f2
/* 396B84 E009A5D4 46000106 */  mov.s     $f4, $f0
/* 396B88 E009A5D8 4602A500 */  add.s     $f20, $f20, $f2
/* 396B8C E009A5DC 3C014F00 */  lui       $at, 0x4f00
/* 396B90 E009A5E0 44811000 */  mtc1      $at, $f2
/* 396B94 E009A5E4 00000000 */  nop       
/* 396B98 E009A5E8 4614103E */  c.le.s    $f2, $f20
/* 396B9C E009A5EC 00000000 */  nop       
/* 396BA0 E009A5F0 45010005 */  bc1t      .LE009A608
/* 396BA4 E009A5F4 26100004 */   addiu    $s0, $s0, 4
/* 396BA8 E009A5F8 4600A18D */  trunc.w.s $f6, $f20
/* 396BAC E009A5FC 44023000 */  mfc1      $v0, $f6
/* 396BB0 E009A600 08026987 */  j         .LE009A61C
/* 396BB4 E009A604 00000000 */   nop      
.LE009A608:
/* 396BB8 E009A608 4602A001 */  sub.s     $f0, $f20, $f2
/* 396BBC E009A60C 4600018D */  trunc.w.s $f6, $f0
/* 396BC0 E009A610 44023000 */  mfc1      $v0, $f6
/* 396BC4 E009A614 00000000 */  nop       
/* 396BC8 E009A618 005E1025 */  or        $v0, $v0, $fp
.LE009A61C:
/* 396BCC E009A61C 3C0141C8 */  lui       $at, 0x41c8
/* 396BD0 E009A620 44810000 */  mtc1      $at, $f0
/* 396BD4 E009A624 00000000 */  nop       
/* 396BD8 E009A628 46002002 */  mul.s     $f0, $f4, $f0
/* 396BDC E009A62C 00000000 */  nop       
/* 396BE0 E009A630 3C014361 */  lui       $at, 0x4361
/* 396BE4 E009A634 44811000 */  mtc1      $at, $f2
/* 396BE8 E009A638 00000000 */  nop       
/* 396BEC E009A63C 46020000 */  add.s     $f0, $f0, $f2
/* 396BF0 E009A640 3C014F00 */  lui       $at, 0x4f00
/* 396BF4 E009A644 44811000 */  mtc1      $at, $f2
/* 396BF8 E009A648 00000000 */  nop       
/* 396BFC E009A64C 4600103E */  c.le.s    $f2, $f0
/* 396C00 E009A650 00000000 */  nop       
/* 396C04 E009A654 45010005 */  bc1t      .LE009A66C
/* 396C08 E009A658 00022600 */   sll      $a0, $v0, 0x18
/* 396C0C E009A65C 4600018D */  trunc.w.s $f6, $f0
/* 396C10 E009A660 44033000 */  mfc1      $v1, $f6
/* 396C14 E009A664 080269A2 */  j         .LE009A688
/* 396C18 E009A668 306200FF */   andi     $v0, $v1, 0xff
.LE009A66C:
/* 396C1C E009A66C 46020001 */  sub.s     $f0, $f0, $f2
/* 396C20 E009A670 3C028000 */  lui       $v0, 0x8000
/* 396C24 E009A674 4600018D */  trunc.w.s $f6, $f0
/* 396C28 E009A678 44033000 */  mfc1      $v1, $f6
/* 396C2C E009A67C 00000000 */  nop       
/* 396C30 E009A680 00621825 */  or        $v1, $v1, $v0
/* 396C34 E009A684 306200FF */  andi      $v0, $v1, 0xff
.LE009A688:
/* 396C38 E009A688 00021400 */  sll       $v0, $v0, 0x10
/* 396C3C E009A68C 8FAF00A0 */  lw        $t7, 0xa0($sp)
/* 396C40 E009A690 00821025 */  or        $v0, $a0, $v0
/* 396C44 E009A694 31E300FF */  andi      $v1, $t7, 0xff
/* 396C48 E009A698 3463FF00 */  ori       $v1, $v1, 0xff00
/* 396C4C E009A69C 00431025 */  or        $v0, $v0, $v1
/* 396C50 E009A6A0 AE020000 */  sw        $v0, ($s0)
/* 396C54 E009A6A4 8EA3002C */  lw        $v1, 0x2c($s5)
/* 396C58 E009A6A8 24020001 */  addiu     $v0, $zero, 1
/* 396C5C E009A6AC 1462002F */  bne       $v1, $v0, .LE009A76C
/* 396C60 E009A6B0 3C088888 */   lui      $t0, 0x8888
/* 396C64 E009A6B4 3C05800A */  lui       $a1, %hi(D_8009A66C)
/* 396C68 E009A6B8 24A5A66C */  addiu     $a1, $a1, %lo(D_8009A66C)
/* 396C6C E009A6BC 35088889 */  ori       $t0, $t0, 0x8889
/* 396C70 E009A6C0 3C06DE00 */  lui       $a2, 0xde00
/* 396C74 E009A6C4 3C020900 */  lui       $v0, 0x900
/* 396C78 E009A6C8 24421040 */  addiu     $v0, $v0, 0x1040
/* 396C7C E009A6CC 8CA40000 */  lw        $a0, ($a1)
/* 396C80 E009A6D0 3C070900 */  lui       $a3, 0x900
/* 396C84 E009A6D4 24E71190 */  addiu     $a3, $a3, 0x1190
/* 396C88 E009A6D8 0080182D */  daddu     $v1, $a0, $zero
/* 396C8C E009A6DC 24840008 */  addiu     $a0, $a0, 8
/* 396C90 E009A6E0 ACA40000 */  sw        $a0, ($a1)
/* 396C94 E009A6E4 AC620004 */  sw        $v0, 4($v1)
/* 396C98 E009A6E8 24820008 */  addiu     $v0, $a0, 8
/* 396C9C E009A6EC AC660000 */  sw        $a2, ($v1)
/* 396CA0 E009A6F0 ACA20000 */  sw        $v0, ($a1)
/* 396CA4 E009A6F4 24820010 */  addiu     $v0, $a0, 0x10
/* 396CA8 E009A6F8 AC860000 */  sw        $a2, ($a0)
/* 396CAC E009A6FC AC870004 */  sw        $a3, 4($a0)
/* 396CB0 E009A700 ACA20000 */  sw        $v0, ($a1)
/* 396CB4 E009A704 3C02FA00 */  lui       $v0, 0xfa00
/* 396CB8 E009A708 AC820008 */  sw        $v0, 8($a0)
/* 396CBC E009A70C 8EA30030 */  lw        $v1, 0x30($s5)
/* 396CC0 E009A710 24820018 */  addiu     $v0, $a0, 0x18
/* 396CC4 E009A714 ACA20000 */  sw        $v0, ($a1)
/* 396CC8 E009A718 3C020900 */  lui       $v0, 0x900
/* 396CCC E009A71C 244210E8 */  addiu     $v0, $v0, 0x10e8
/* 396CD0 E009A720 AC820014 */  sw        $v0, 0x14($a0)
/* 396CD4 E009A724 2402001E */  addiu     $v0, $zero, 0x1e
/* 396CD8 E009A728 AC860010 */  sw        $a2, 0x10($a0)
/* 396CDC E009A72C 00431023 */  subu      $v0, $v0, $v1
/* 396CE0 E009A730 00021A00 */  sll       $v1, $v0, 8
/* 396CE4 E009A734 00621823 */  subu      $v1, $v1, $v0
/* 396CE8 E009A738 00680018 */  mult      $v1, $t0
/* 396CEC E009A73C 24820020 */  addiu     $v0, $a0, 0x20
/* 396CF0 E009A740 ACA20000 */  sw        $v0, ($a1)
/* 396CF4 E009A744 AC860018 */  sw        $a2, 0x18($a0)
/* 396CF8 E009A748 AC87001C */  sw        $a3, 0x1c($a0)
/* 396CFC E009A74C 00007810 */  mfhi      $t7
/* 396D00 E009A750 01E31021 */  addu      $v0, $t7, $v1
/* 396D04 E009A754 00021103 */  sra       $v0, $v0, 4
/* 396D08 E009A758 00031FC3 */  sra       $v1, $v1, 0x1f
/* 396D0C E009A75C 00431023 */  subu      $v0, $v0, $v1
/* 396D10 E009A760 304200FF */  andi      $v0, $v0, 0xff
/* 396D14 E009A764 08026A77 */  j         .LE009A9DC
/* 396D18 E009A768 AC82000C */   sw       $v0, 0xc($a0)
.LE009A76C:
/* 396D1C E009A76C 1860000D */  blez      $v1, .LE009A7A4
/* 396D20 E009A770 00000000 */   nop      
/* 396D24 E009A774 3C03800A */  lui       $v1, %hi(D_8009A66C)
/* 396D28 E009A778 2463A66C */  addiu     $v1, $v1, %lo(D_8009A66C)
/* 396D2C E009A77C 8C620000 */  lw        $v0, ($v1)
/* 396D30 E009A780 0040202D */  daddu     $a0, $v0, $zero
/* 396D34 E009A784 24420008 */  addiu     $v0, $v0, 8
/* 396D38 E009A788 AC620000 */  sw        $v0, ($v1)
/* 396D3C E009A78C 3C02DE00 */  lui       $v0, 0xde00
/* 396D40 E009A790 AC820000 */  sw        $v0, ($a0)
/* 396D44 E009A794 3C020900 */  lui       $v0, 0x900
/* 396D48 E009A798 244210E8 */  addiu     $v0, $v0, 0x10e8
/* 396D4C E009A79C 080269F4 */  j         .LE009A7D0
/* 396D50 E009A7A0 AC820004 */   sw       $v0, 4($a0)
.LE009A7A4:
/* 396D54 E009A7A4 3C03800A */  lui       $v1, %hi(D_8009A66C)
/* 396D58 E009A7A8 2463A66C */  addiu     $v1, $v1, %lo(D_8009A66C)
/* 396D5C E009A7AC 8C620000 */  lw        $v0, ($v1)
/* 396D60 E009A7B0 0040202D */  daddu     $a0, $v0, $zero
/* 396D64 E009A7B4 24420008 */  addiu     $v0, $v0, 8
/* 396D68 E009A7B8 AC620000 */  sw        $v0, ($v1)
/* 396D6C E009A7BC 3C02DE00 */  lui       $v0, 0xde00
/* 396D70 E009A7C0 AC820000 */  sw        $v0, ($a0)
/* 396D74 E009A7C4 3C020900 */  lui       $v0, 0x900
/* 396D78 E009A7C8 24421040 */  addiu     $v0, $v0, 0x1040
/* 396D7C E009A7CC AC820004 */  sw        $v0, 4($a0)
.LE009A7D0:
/* 396D80 E009A7D0 0000902D */  daddu     $s2, $zero, $zero
/* 396D84 E009A7D4 0240A82D */  daddu     $s5, $s2, $zero
/* 396D88 E009A7D8 00161080 */  sll       $v0, $s6, 2
/* 396D8C E009A7DC 00561021 */  addu      $v0, $v0, $s6
/* 396D90 E009A7E0 00029840 */  sll       $s3, $v0, 1
/* 396D94 E009A7E4 3C04800A */  lui       $a0, %hi(D_8009A66C)
/* 396D98 E009A7E8 2484A66C */  addiu     $a0, $a0, %lo(D_8009A66C)
/* 396D9C E009A7EC 8C830000 */  lw        $v1, ($a0)
/* 396DA0 E009A7F0 0260A02D */  daddu     $s4, $s3, $zero
/* 396DA4 E009A7F4 24620008 */  addiu     $v0, $v1, 8
/* 396DA8 E009A7F8 0040B02D */  daddu     $s6, $v0, $zero
/* 396DAC E009A7FC 3C02DE01 */  lui       $v0, 0xde01
/* 396DB0 E009A800 AC620000 */  sw        $v0, ($v1)
/* 396DB4 E009A804 24620208 */  addiu     $v0, $v1, 0x208
/* 396DB8 E009A808 AC620004 */  sw        $v0, 4($v1)
/* 396DBC E009A80C AC960000 */  sw        $s6, ($a0)
.LE009A810:
/* 396DC0 E009A810 00128140 */  sll       $s0, $s2, 5
/* 396DC4 E009A814 02971021 */  addu      $v0, $s4, $s7
/* 396DC8 E009A818 44826000 */  mtc1      $v0, $f12
/* 396DCC E009A81C 00000000 */  nop       
/* 396DD0 E009A820 46806320 */  cvt.s.w   $f12, $f12
/* 396DD4 E009A824 0C080140 */  jal       func_E0200500
/* 396DD8 E009A828 02D08021 */   addu     $s0, $s6, $s0
/* 396DDC E009A82C 3C0143FA */  lui       $at, 0x43fa
/* 396DE0 E009A830 44811000 */  mtc1      $at, $f2
/* 396DE4 E009A834 00000000 */  nop       
/* 396DE8 E009A838 46020002 */  mul.s     $f0, $f0, $f2
/* 396DEC E009A83C 00000000 */  nop       
/* 396DF0 E009A840 46160002 */  mul.s     $f0, $f0, $f22
/* 396DF4 E009A844 00000000 */  nop       
/* 396DF8 E009A848 02771021 */  addu      $v0, $s3, $s7
/* 396DFC E009A84C 44826000 */  mtc1      $v0, $f12
/* 396E00 E009A850 00000000 */  nop       
/* 396E04 E009A854 46806320 */  cvt.s.w   $f12, $f12
/* 396E08 E009A858 4600018D */  trunc.w.s $f6, $f0
/* 396E0C E009A85C 44113000 */  mfc1      $s1, $f6
/* 396E10 E009A860 0C080140 */  jal       func_E0200500
/* 396E14 E009A864 26730006 */   addiu    $s3, $s3, 6
/* 396E18 E009A868 3C014348 */  lui       $at, 0x4348
/* 396E1C E009A86C 44811000 */  mtc1      $at, $f2
/* 396E20 E009A870 2694003C */  addiu     $s4, $s4, 0x3c
/* 396E24 E009A874 46020002 */  mul.s     $f0, $f0, $f2
/* 396E28 E009A878 00000000 */  nop       
/* 396E2C E009A87C 001219C0 */  sll       $v1, $s2, 7
/* 396E30 E009A880 26520001 */  addiu     $s2, $s2, 1
/* 396E34 E009A884 2622F380 */  addiu     $v0, $s1, -0xc80
/* 396E38 E009A888 26310C80 */  addiu     $s1, $s1, 0xc80
/* 396E3C E009A88C 46160002 */  mul.s     $f0, $f0, $f22
/* 396E40 E009A890 00000000 */  nop       
/* 396E44 E009A894 A6020000 */  sh        $v0, ($s0)
/* 396E48 E009A898 A6000004 */  sh        $zero, 4($s0)
/* 396E4C E009A89C A6000008 */  sh        $zero, 8($s0)
/* 396E50 E009A8A0 A603000A */  sh        $v1, 0xa($s0)
/* 396E54 E009A8A4 4600018D */  trunc.w.s $f6, $f0
/* 396E58 E009A8A8 44023000 */  mfc1      $v0, $f6
/* 396E5C E009A8AC 00000000 */  nop       
/* 396E60 E009A8B0 02A21021 */  addu      $v0, $s5, $v0
/* 396E64 E009A8B4 A6020002 */  sh        $v0, 2($s0)
/* 396E68 E009A8B8 26100010 */  addiu     $s0, $s0, 0x10
/* 396E6C E009A8BC 26B50190 */  addiu     $s5, $s5, 0x190
/* 396E70 E009A8C0 A6020002 */  sh        $v0, 2($s0)
/* 396E74 E009A8C4 24020800 */  addiu     $v0, $zero, 0x800
/* 396E78 E009A8C8 A6020008 */  sh        $v0, 8($s0)
/* 396E7C E009A8CC 2A420010 */  slti      $v0, $s2, 0x10
/* 396E80 E009A8D0 A6110000 */  sh        $s1, ($s0)
/* 396E84 E009A8D4 A6000004 */  sh        $zero, 4($s0)
/* 396E88 E009A8D8 1440FFCD */  bnez      $v0, .LE009A810
/* 396E8C E009A8DC A603000A */   sh       $v1, 0xa($s0)
/* 396E90 E009A8E0 3C040102 */  lui       $a0, 0x102
/* 396E94 E009A8E4 34840040 */  ori       $a0, $a0, 0x40
/* 396E98 E009A8E8 0000902D */  daddu     $s2, $zero, $zero
/* 396E9C E009A8EC 3C02800A */  lui       $v0, %hi(D_8009A66C)
/* 396EA0 E009A8F0 2442A66C */  addiu     $v0, $v0, %lo(D_8009A66C)
/* 396EA4 E009A8F4 0040482D */  daddu     $t1, $v0, $zero
/* 396EA8 E009A8F8 3C0B0600 */  lui       $t3, 0x600
/* 396EAC E009A8FC 240A0001 */  addiu     $t2, $zero, 1
/* 396EB0 E009A900 3C0E0606 */  lui       $t6, 0x606
/* 396EB4 E009A904 35CE0402 */  ori       $t6, $t6, 0x402
/* 396EB8 E009A908 3C0D0002 */  lui       $t5, 2
/* 396EBC E009A90C 35AD0406 */  ori       $t5, $t5, 0x406
/* 396EC0 E009A910 3C0C0006 */  lui       $t4, 6
/* 396EC4 E009A914 358C0804 */  ori       $t4, $t4, 0x804
/* 396EC8 E009A918 24070004 */  addiu     $a3, $zero, 4
/* 396ECC E009A91C 24060002 */  addiu     $a2, $zero, 2
/* 396ED0 E009A920 8D230000 */  lw        $v1, ($t1)
/* 396ED4 E009A924 24080006 */  addiu     $t0, $zero, 6
/* 396ED8 E009A928 24620208 */  addiu     $v0, $v1, 0x208
/* 396EDC E009A92C AD220000 */  sw        $v0, ($t1)
/* 396EE0 E009A930 AC640200 */  sw        $a0, 0x200($v1)
/* 396EE4 E009A934 AC760204 */  sw        $s6, 0x204($v1)
.LE009A938:
/* 396EE8 E009A938 8D240000 */  lw        $a0, ($t1)
/* 396EEC E009A93C 00122840 */  sll       $a1, $s2, 1
/* 396EF0 E009A940 24820008 */  addiu     $v0, $a0, 8
/* 396EF4 E009A944 14A00004 */  bnez      $a1, .LE009A958
/* 396EF8 E009A948 AD220000 */   sw       $v0, ($t1)
/* 396EFC E009A94C 00121440 */  sll       $v0, $s2, 0x11
/* 396F00 E009A950 08026A60 */  j         .LE009A980
/* 396F04 E009A954 34420402 */   ori      $v0, $v0, 0x402
.LE009A958:
/* 396F08 E009A958 14AA0003 */  bne       $a1, $t2, .LE009A968
/* 396F0C E009A95C 30C200FF */   andi     $v0, $a2, 0xff
/* 396F10 E009A960 08026A62 */  j         .LE009A988
/* 396F14 E009A964 AC8E0000 */   sw       $t6, ($a0)
.LE009A968:
/* 396F18 E009A968 00021400 */  sll       $v0, $v0, 0x10
/* 396F1C E009A96C 00121A80 */  sll       $v1, $s2, 0xa
/* 396F20 E009A970 3063FC00 */  andi      $v1, $v1, 0xfc00
/* 396F24 E009A974 00431025 */  or        $v0, $v0, $v1
/* 396F28 E009A978 30E300FF */  andi      $v1, $a3, 0xff
/* 396F2C E009A97C 00431025 */  or        $v0, $v0, $v1
.LE009A980:
/* 396F30 E009A980 004B1025 */  or        $v0, $v0, $t3
/* 396F34 E009A984 AC820000 */  sw        $v0, ($a0)
.LE009A988:
/* 396F38 E009A988 14A00003 */  bnez      $a1, .LE009A998
/* 396F3C E009A98C 00000000 */   nop      
/* 396F40 E009A990 08026A71 */  j         .LE009A9C4
/* 396F44 E009A994 AC8D0004 */   sw       $t5, 4($a0)
.LE009A998:
/* 396F48 E009A998 14AA0003 */  bne       $a1, $t2, .LE009A9A8
/* 396F4C E009A99C 310200FF */   andi     $v0, $t0, 0xff
/* 396F50 E009A9A0 08026A71 */  j         .LE009A9C4
/* 396F54 E009A9A4 AC8C0004 */   sw       $t4, 4($a0)
.LE009A9A8:
/* 396F58 E009A9A8 00021400 */  sll       $v0, $v0, 0x10
/* 396F5C E009A9AC 30C300FF */  andi      $v1, $a2, 0xff
/* 396F60 E009A9B0 00031A00 */  sll       $v1, $v1, 8
/* 396F64 E009A9B4 00431025 */  or        $v0, $v0, $v1
/* 396F68 E009A9B8 30E300FF */  andi      $v1, $a3, 0xff
/* 396F6C E009A9BC 00431025 */  or        $v0, $v0, $v1
/* 396F70 E009A9C0 AC820004 */  sw        $v0, 4($a0)
.LE009A9C4:
/* 396F74 E009A9C4 24E70004 */  addiu     $a3, $a3, 4
/* 396F78 E009A9C8 24C60004 */  addiu     $a2, $a2, 4
/* 396F7C E009A9CC 26520001 */  addiu     $s2, $s2, 1
/* 396F80 E009A9D0 2A42000F */  slti      $v0, $s2, 0xf
/* 396F84 E009A9D4 1440FFD8 */  bnez      $v0, .LE009A938
/* 396F88 E009A9D8 25080004 */   addiu    $t0, $t0, 4
.LE009A9DC:
/* 396F8C E009A9DC 3C03D838 */  lui       $v1, 0xd838
/* 396F90 E009A9E0 3C04800A */  lui       $a0, %hi(D_8009A66C)
/* 396F94 E009A9E4 2484A66C */  addiu     $a0, $a0, %lo(D_8009A66C)
/* 396F98 E009A9E8 8C820000 */  lw        $v0, ($a0)
/* 396F9C E009A9EC 34630002 */  ori       $v1, $v1, 2
/* 396FA0 E009A9F0 0040282D */  daddu     $a1, $v0, $zero
/* 396FA4 E009A9F4 24420008 */  addiu     $v0, $v0, 8
/* 396FA8 E009A9F8 AC820000 */  sw        $v0, ($a0)
/* 396FAC E009A9FC ACA30000 */  sw        $v1, ($a1)
/* 396FB0 E009AA00 24030040 */  addiu     $v1, $zero, 0x40
/* 396FB4 E009AA04 ACA30004 */  sw        $v1, 4($a1)
/* 396FB8 E009AA08 24430008 */  addiu     $v1, $v0, 8
/* 396FBC E009AA0C AC830000 */  sw        $v1, ($a0)
/* 396FC0 E009AA10 3C03E700 */  lui       $v1, 0xe700
/* 396FC4 E009AA14 AC430000 */  sw        $v1, ($v0)
/* 396FC8 E009AA18 AC400004 */  sw        $zero, 4($v0)
/* 396FCC E009AA1C 8FBF00CC */  lw        $ra, 0xcc($sp)
/* 396FD0 E009AA20 8FBE00C8 */  lw        $fp, 0xc8($sp)
/* 396FD4 E009AA24 8FB700C4 */  lw        $s7, 0xc4($sp)
/* 396FD8 E009AA28 8FB600C0 */  lw        $s6, 0xc0($sp)
/* 396FDC E009AA2C 8FB500BC */  lw        $s5, 0xbc($sp)
/* 396FE0 E009AA30 8FB400B8 */  lw        $s4, 0xb8($sp)
/* 396FE4 E009AA34 8FB300B4 */  lw        $s3, 0xb4($sp)
/* 396FE8 E009AA38 8FB200B0 */  lw        $s2, 0xb0($sp)
/* 396FEC E009AA3C 8FB100AC */  lw        $s1, 0xac($sp)
/* 396FF0 E009AA40 8FB000A8 */  lw        $s0, 0xa8($sp)
/* 396FF4 E009AA44 D7B600D8 */  ldc1      $f22, 0xd8($sp)
/* 396FF8 E009AA48 D7B400D0 */  ldc1      $f20, 0xd0($sp)
/* 396FFC E009AA4C 03E00008 */  jr        $ra
/* 397000 E009AA50 27BD00E0 */   addiu    $sp, $sp, 0xe0
/* 397004 E009AA54 00000000 */  nop       
/* 397008 E009AA58 00000000 */  nop       
/* 39700C E009AA5C 00000000 */  nop       
