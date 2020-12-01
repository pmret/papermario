.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E002A3C4
/* 33EC84 E002A3C4 27BDFEF8 */  addiu     $sp, $sp, -0x108
/* 33EC88 E002A3C8 3C02DB06 */  lui       $v0, 0xdb06
/* 33EC8C E002A3CC 34420024 */  ori       $v0, $v0, 0x24
/* 33EC90 E002A3D0 AFB200E8 */  sw        $s2, 0xe8($sp)
/* 33EC94 E002A3D4 3C12800A */  lui       $s2, %hi(D_8009A66C)
/* 33EC98 E002A3D8 2652A66C */  addiu     $s2, $s2, %lo(D_8009A66C)
/* 33EC9C E002A3DC AFBF0104 */  sw        $ra, 0x104($sp)
/* 33ECA0 E002A3E0 AFBE0100 */  sw        $fp, 0x100($sp)
/* 33ECA4 E002A3E4 AFB700FC */  sw        $s7, 0xfc($sp)
/* 33ECA8 E002A3E8 AFB600F8 */  sw        $s6, 0xf8($sp)
/* 33ECAC E002A3EC AFB500F4 */  sw        $s5, 0xf4($sp)
/* 33ECB0 E002A3F0 AFB400F0 */  sw        $s4, 0xf0($sp)
/* 33ECB4 E002A3F4 AFB300EC */  sw        $s3, 0xec($sp)
/* 33ECB8 E002A3F8 AFB100E4 */  sw        $s1, 0xe4($sp)
/* 33ECBC E002A3FC AFB000E0 */  sw        $s0, 0xe0($sp)
/* 33ECC0 E002A400 AFA40108 */  sw        $a0, 0x108($sp)
/* 33ECC4 E002A404 8E490000 */  lw        $t1, ($s2)
/* 33ECC8 E002A408 8C90000C */  lw        $s0, 0xc($a0)
/* 33ECCC E002A40C 0120202D */  daddu     $a0, $t1, $zero
/* 33ECD0 E002A410 AC820000 */  sw        $v0, ($a0)
/* 33ECD4 E002A414 8FAB0108 */  lw        $t3, 0x108($sp)
/* 33ECD8 E002A418 3C050900 */  lui       $a1, 0x900
/* 33ECDC E002A41C 24A50D68 */  addiu     $a1, $a1, 0xd68
/* 33ECE0 E002A420 8D620010 */  lw        $v0, 0x10($t3)
/* 33ECE4 E002A424 25290008 */  addiu     $t1, $t1, 8
/* 33ECE8 E002A428 AE490000 */  sw        $t1, ($s2)
/* 33ECEC E002A42C 8C42001C */  lw        $v0, 0x1c($v0)
/* 33ECF0 E002A430 3C038000 */  lui       $v1, 0x8000
/* 33ECF4 E002A434 00431021 */  addu      $v0, $v0, $v1
/* 33ECF8 E002A438 AC820004 */  sw        $v0, 4($a0)
/* 33ECFC E002A43C 3C02DE00 */  lui       $v0, 0xde00
/* 33ED00 E002A440 AD220000 */  sw        $v0, ($t1)
/* 33ED04 E002A444 8E020000 */  lw        $v0, ($s0)
/* 33ED08 E002A448 252A0008 */  addiu     $t2, $t1, 8
/* 33ED0C E002A44C 14400003 */  bnez      $v0, .LE002A45C
/* 33ED10 E002A450 AE4A0000 */   sw       $t2, ($s2)
/* 33ED14 E002A454 3C050900 */  lui       $a1, 0x900
/* 33ED18 E002A458 24A50CC0 */  addiu     $a1, $a1, 0xcc0
.LE002A45C:
/* 33ED1C E002A45C 25280010 */  addiu     $t0, $t1, 0x10
/* 33ED20 E002A460 3C02FA00 */  lui       $v0, 0xfa00
/* 33ED24 E002A464 AD250004 */  sw        $a1, 4($t1)
/* 33ED28 E002A468 AE480000 */  sw        $t0, ($s2)
/* 33ED2C E002A46C AD220008 */  sw        $v0, 8($t1)
/* 33ED30 E002A470 92020033 */  lbu       $v0, 0x33($s0)
/* 33ED34 E002A474 92050037 */  lbu       $a1, 0x37($s0)
/* 33ED38 E002A478 9206003B */  lbu       $a2, 0x3b($s0)
/* 33ED3C E002A47C 9207001B */  lbu       $a3, 0x1b($s0)
/* 33ED40 E002A480 25230018 */  addiu     $v1, $t1, 0x18
/* 33ED44 E002A484 AE430000 */  sw        $v1, ($s2)
/* 33ED48 E002A488 00021600 */  sll       $v0, $v0, 0x18
/* 33ED4C E002A48C 00052C00 */  sll       $a1, $a1, 0x10
/* 33ED50 E002A490 00451025 */  or        $v0, $v0, $a1
/* 33ED54 E002A494 00063200 */  sll       $a2, $a2, 8
/* 33ED58 E002A498 00461025 */  or        $v0, $v0, $a2
/* 33ED5C E002A49C 00471025 */  or        $v0, $v0, $a3
/* 33ED60 E002A4A0 AD420004 */  sw        $v0, 4($t2)
/* 33ED64 E002A4A4 3C02FB00 */  lui       $v0, 0xfb00
/* 33ED68 E002A4A8 AD220010 */  sw        $v0, 0x10($t1)
/* 33ED6C E002A4AC 9202003F */  lbu       $v0, 0x3f($s0)
/* 33ED70 E002A4B0 92050043 */  lbu       $a1, 0x43($s0)
/* 33ED74 E002A4B4 92030047 */  lbu       $v1, 0x47($s0)
/* 33ED78 E002A4B8 00021600 */  sll       $v0, $v0, 0x18
/* 33ED7C E002A4BC 00052C00 */  sll       $a1, $a1, 0x10
/* 33ED80 E002A4C0 00451025 */  or        $v0, $v0, $a1
/* 33ED84 E002A4C4 00031A00 */  sll       $v1, $v1, 8
/* 33ED88 E002A4C8 00431025 */  or        $v0, $v0, $v1
/* 33ED8C E002A4CC AD020004 */  sw        $v0, 4($t0)
/* 33ED90 E002A4D0 8E050004 */  lw        $a1, 4($s0)
/* 33ED94 E002A4D4 8E060008 */  lw        $a2, 8($s0)
/* 33ED98 E002A4D8 8E07000C */  lw        $a3, 0xc($s0)
/* 33ED9C E002A4DC 0C080108 */  jal       func_E0200420
/* 33EDA0 E002A4E0 27A40018 */   addiu    $a0, $sp, 0x18
/* 33EDA4 E002A4E4 27B10058 */  addiu     $s1, $sp, 0x58
/* 33EDA8 E002A4E8 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 33EDAC E002A4EC 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 33EDB0 E002A4F0 44800000 */  mtc1      $zero, $f0
/* 33EDB4 E002A4F4 00031080 */  sll       $v0, $v1, 2
/* 33EDB8 E002A4F8 00431021 */  addu      $v0, $v0, $v1
/* 33EDBC E002A4FC 00021080 */  sll       $v0, $v0, 2
/* 33EDC0 E002A500 00431023 */  subu      $v0, $v0, $v1
/* 33EDC4 E002A504 000218C0 */  sll       $v1, $v0, 3
/* 33EDC8 E002A508 00431021 */  addu      $v0, $v0, $v1
/* 33EDCC E002A50C 000210C0 */  sll       $v0, $v0, 3
/* 33EDD0 E002A510 44060000 */  mfc1      $a2, $f0
/* 33EDD4 E002A514 3C01800B */  lui       $at, %hi(D_800B1DEC)
/* 33EDD8 E002A518 00220821 */  addu      $at, $at, $v0
/* 33EDDC E002A51C C4201DEC */  lwc1      $f0, %lo(D_800B1DEC)($at)
/* 33EDE0 E002A520 3C073F80 */  lui       $a3, 0x3f80
/* 33EDE4 E002A524 46000007 */  neg.s     $f0, $f0
/* 33EDE8 E002A528 44050000 */  mfc1      $a1, $f0
/* 33EDEC E002A52C 0220202D */  daddu     $a0, $s1, $zero
/* 33EDF0 E002A530 0C080104 */  jal       func_E0200410
/* 33EDF4 E002A534 AFA60010 */   sw       $a2, 0x10($sp)
/* 33EDF8 E002A538 0220202D */  daddu     $a0, $s1, $zero
/* 33EDFC E002A53C 27A50018 */  addiu     $a1, $sp, 0x18
/* 33EE00 E002A540 0C080114 */  jal       func_E0200450
/* 33EE04 E002A544 27A60098 */   addiu    $a2, $sp, 0x98
/* 33EE08 E002A548 8E0B0000 */  lw        $t3, ($s0)
/* 33EE0C E002A54C AFAB00D8 */  sw        $t3, 0xd8($sp)
/* 33EE10 E002A550 8FAB0108 */  lw        $t3, 0x108($sp)
/* 33EE14 E002A554 24130001 */  addiu     $s3, $zero, 1
/* 33EE18 E002A558 8D620008 */  lw        $v0, 8($t3)
/* 33EE1C E002A55C 0262102A */  slt       $v0, $s3, $v0
/* 33EE20 E002A560 10400061 */  beqz      $v0, .LE002A6E8
/* 33EE24 E002A564 26100048 */   addiu    $s0, $s0, 0x48
/* 33EE28 E002A568 3C17800A */  lui       $s7, %hi(D_8009A674)
/* 33EE2C E002A56C 26F7A674 */  addiu     $s7, $s7, %lo(D_8009A674)
/* 33EE30 E002A570 3C148007 */  lui       $s4, %hi(D_800741F0)
/* 33EE34 E002A574 269441F0 */  addiu     $s4, $s4, %lo(D_800741F0)
/* 33EE38 E002A578 3C150001 */  lui       $s5, 1
/* 33EE3C E002A57C 36B51630 */  ori       $s5, $s5, 0x1630
/* 33EE40 E002A580 0220B02D */  daddu     $s6, $s1, $zero
/* 33EE44 E002A584 3C1EDE00 */  lui       $fp, 0xde00
/* 33EE48 E002A588 2611000C */  addiu     $s1, $s0, 0xc
.LE002A58C:
/* 33EE4C E002A58C 27A40018 */  addiu     $a0, $sp, 0x18
/* 33EE50 E002A590 8E250014 */  lw        $a1, 0x14($s1)
/* 33EE54 E002A594 8E260010 */  lw        $a2, 0x10($s1)
/* 33EE58 E002A598 96820000 */  lhu       $v0, ($s4)
/* 33EE5C E002A59C 00A0382D */  daddu     $a3, $a1, $zero
/* 33EE60 E002A5A0 24430001 */  addiu     $v1, $v0, 1
/* 33EE64 E002A5A4 3042FFFF */  andi      $v0, $v0, 0xffff
/* 33EE68 E002A5A8 00021180 */  sll       $v0, $v0, 6
/* 33EE6C E002A5AC A6830000 */  sh        $v1, ($s4)
/* 33EE70 E002A5B0 8EF00000 */  lw        $s0, ($s7)
/* 33EE74 E002A5B4 00551021 */  addu      $v0, $v0, $s5
/* 33EE78 E002A5B8 0C080110 */  jal       func_E0200440
/* 33EE7C E002A5BC 02028021 */   addu     $s0, $s0, $v0
/* 33EE80 E002A5C0 27A40018 */  addiu     $a0, $sp, 0x18
/* 33EE84 E002A5C4 0C080118 */  jal       func_E0200460
/* 33EE88 E002A5C8 0200282D */   daddu    $a1, $s0, $zero
/* 33EE8C E002A5CC 8E25FFF8 */  lw        $a1, -8($s1)
/* 33EE90 E002A5D0 8E26FFFC */  lw        $a2, -4($s1)
/* 33EE94 E002A5D4 8E270000 */  lw        $a3, ($s1)
/* 33EE98 E002A5D8 0C080108 */  jal       func_E0200420
/* 33EE9C E002A5DC 02C0202D */   daddu    $a0, $s6, $zero
/* 33EEA0 E002A5E0 02C0202D */  daddu     $a0, $s6, $zero
/* 33EEA4 E002A5E4 27A50098 */  addiu     $a1, $sp, 0x98
/* 33EEA8 E002A5E8 0C080114 */  jal       func_E0200450
/* 33EEAC E002A5EC 27A60018 */   addiu    $a2, $sp, 0x18
/* 33EEB0 E002A5F0 27A40018 */  addiu     $a0, $sp, 0x18
/* 33EEB4 E002A5F4 96850000 */  lhu       $a1, ($s4)
/* 33EEB8 E002A5F8 8EE20000 */  lw        $v0, ($s7)
/* 33EEBC E002A5FC 00052980 */  sll       $a1, $a1, 6
/* 33EEC0 E002A600 00B52821 */  addu      $a1, $a1, $s5
/* 33EEC4 E002A604 0C080118 */  jal       func_E0200460
/* 33EEC8 E002A608 00452821 */   addu     $a1, $v0, $a1
/* 33EECC E002A60C 3C05DA38 */  lui       $a1, 0xda38
/* 33EED0 E002A610 8E460000 */  lw        $a2, ($s2)
/* 33EED4 E002A614 34A50001 */  ori       $a1, $a1, 1
/* 33EED8 E002A618 00C0202D */  daddu     $a0, $a2, $zero
/* 33EEDC E002A61C 24C60008 */  addiu     $a2, $a2, 8
/* 33EEE0 E002A620 AE460000 */  sw        $a2, ($s2)
/* 33EEE4 E002A624 96820000 */  lhu       $v0, ($s4)
/* 33EEE8 E002A628 3C03DA38 */  lui       $v1, 0xda38
/* 33EEEC E002A62C AC830000 */  sw        $v1, ($a0)
/* 33EEF0 E002A630 24430001 */  addiu     $v1, $v0, 1
/* 33EEF4 E002A634 3042FFFF */  andi      $v0, $v0, 0xffff
/* 33EEF8 E002A638 00021180 */  sll       $v0, $v0, 6
/* 33EEFC E002A63C A6830000 */  sh        $v1, ($s4)
/* 33EF00 E002A640 8EE30000 */  lw        $v1, ($s7)
/* 33EF04 E002A644 00551021 */  addu      $v0, $v0, $s5
/* 33EF08 E002A648 00621821 */  addu      $v1, $v1, $v0
/* 33EF0C E002A64C 24C20008 */  addiu     $v0, $a2, 8
/* 33EF10 E002A650 AC830004 */  sw        $v1, 4($a0)
/* 33EF14 E002A654 AE420000 */  sw        $v0, ($s2)
/* 33EF18 E002A658 ACC50000 */  sw        $a1, ($a2)
/* 33EF1C E002A65C ACD00004 */  sw        $s0, 4($a2)
/* 33EF20 E002A660 8FAB00D8 */  lw        $t3, 0xd8($sp)
/* 33EF24 E002A664 29620002 */  slti      $v0, $t3, 2
/* 33EF28 E002A668 1040000B */  beqz      $v0, .LE002A698
/* 33EF2C E002A66C 24C20010 */   addiu    $v0, $a2, 0x10
/* 33EF30 E002A670 3C030900 */  lui       $v1, 0x900
/* 33EF34 E002A674 24630E38 */  addiu     $v1, $v1, 0xe38
/* 33EF38 E002A678 AE420000 */  sw        $v0, ($s2)
/* 33EF3C E002A67C 32620001 */  andi      $v0, $s3, 1
/* 33EF40 E002A680 10400003 */  beqz      $v0, .LE002A690
/* 33EF44 E002A684 ACDE0008 */   sw       $fp, 8($a2)
/* 33EF48 E002A688 3C030900 */  lui       $v1, 0x900
/* 33EF4C E002A68C 24630E18 */  addiu     $v1, $v1, 0xe18
.LE002A690:
/* 33EF50 E002A690 0800A9AB */  j         .LE002A6AC
/* 33EF54 E002A694 ACC3000C */   sw       $v1, 0xc($a2)
.LE002A698:
/* 33EF58 E002A698 AE420000 */  sw        $v0, ($s2)
/* 33EF5C E002A69C 3C020900 */  lui       $v0, 0x900
/* 33EF60 E002A6A0 24420E58 */  addiu     $v0, $v0, 0xe58
/* 33EF64 E002A6A4 ACDE0008 */  sw        $fp, 8($a2)
/* 33EF68 E002A6A8 ACC2000C */  sw        $v0, 0xc($a2)
.LE002A6AC:
/* 33EF6C E002A6AC 3C02D838 */  lui       $v0, 0xd838
/* 33EF70 E002A6B0 34420002 */  ori       $v0, $v0, 2
/* 33EF74 E002A6B4 8E440000 */  lw        $a0, ($s2)
/* 33EF78 E002A6B8 26730001 */  addiu     $s3, $s3, 1
/* 33EF7C E002A6BC 0080182D */  daddu     $v1, $a0, $zero
/* 33EF80 E002A6C0 AC620000 */  sw        $v0, ($v1)
/* 33EF84 E002A6C4 24020040 */  addiu     $v0, $zero, 0x40
/* 33EF88 E002A6C8 AC620004 */  sw        $v0, 4($v1)
/* 33EF8C E002A6CC 8FAB0108 */  lw        $t3, 0x108($sp)
/* 33EF90 E002A6D0 26310048 */  addiu     $s1, $s1, 0x48
/* 33EF94 E002A6D4 8D620008 */  lw        $v0, 8($t3)
/* 33EF98 E002A6D8 24840008 */  addiu     $a0, $a0, 8
/* 33EF9C E002A6DC 0262102A */  slt       $v0, $s3, $v0
/* 33EFA0 E002A6E0 1440FFAA */  bnez      $v0, .LE002A58C
/* 33EFA4 E002A6E4 AE440000 */   sw       $a0, ($s2)
.LE002A6E8:
/* 33EFA8 E002A6E8 8FBF0104 */  lw        $ra, 0x104($sp)
/* 33EFAC E002A6EC 8FBE0100 */  lw        $fp, 0x100($sp)
/* 33EFB0 E002A6F0 8FB700FC */  lw        $s7, 0xfc($sp)
/* 33EFB4 E002A6F4 8FB600F8 */  lw        $s6, 0xf8($sp)
/* 33EFB8 E002A6F8 8FB500F4 */  lw        $s5, 0xf4($sp)
/* 33EFBC E002A6FC 8FB400F0 */  lw        $s4, 0xf0($sp)
/* 33EFC0 E002A700 8FB300EC */  lw        $s3, 0xec($sp)
/* 33EFC4 E002A704 8FB200E8 */  lw        $s2, 0xe8($sp)
/* 33EFC8 E002A708 8FB100E4 */  lw        $s1, 0xe4($sp)
/* 33EFCC E002A70C 8FB000E0 */  lw        $s0, 0xe0($sp)
/* 33EFD0 E002A710 03E00008 */  jr        $ra
/* 33EFD4 E002A714 27BD0108 */   addiu    $sp, $sp, 0x108
/* 33EFD8 E002A718 00000000 */  nop       
/* 33EFDC E002A71C 00000000 */  nop       
