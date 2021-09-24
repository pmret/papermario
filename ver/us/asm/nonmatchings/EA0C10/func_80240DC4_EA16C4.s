.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80246618_EA6F18
.double 380.0

glabel D_80246620_EA6F20
.double -380.0

glabel D_80246628_EA6F28
.double 305.0

glabel D_80246630_EA6F30
.double 375.0

glabel D_80246638_EA6F38
.double 45.0

glabel D_80246640_EA6F40
.double 150.0

.section .text

glabel func_80240DC4_EA16C4
/* EA16C4 80240DC4 27BDFF80 */  addiu     $sp, $sp, -0x80
/* EA16C8 80240DC8 AFBF0064 */  sw        $ra, 0x64($sp)
/* EA16CC 80240DCC AFBE0060 */  sw        $fp, 0x60($sp)
/* EA16D0 80240DD0 AFB7005C */  sw        $s7, 0x5c($sp)
/* EA16D4 80240DD4 AFB60058 */  sw        $s6, 0x58($sp)
/* EA16D8 80240DD8 AFB50054 */  sw        $s5, 0x54($sp)
/* EA16DC 80240DDC AFB40050 */  sw        $s4, 0x50($sp)
/* EA16E0 80240DE0 AFB3004C */  sw        $s3, 0x4c($sp)
/* EA16E4 80240DE4 AFB20048 */  sw        $s2, 0x48($sp)
/* EA16E8 80240DE8 AFB10044 */  sw        $s1, 0x44($sp)
/* EA16EC 80240DEC AFB00040 */  sw        $s0, 0x40($sp)
/* EA16F0 80240DF0 F7B80078 */  sdc1      $f24, 0x78($sp)
/* EA16F4 80240DF4 F7B60070 */  sdc1      $f22, 0x70($sp)
/* EA16F8 80240DF8 F7B40068 */  sdc1      $f20, 0x68($sp)
/* EA16FC 80240DFC AFA40080 */  sw        $a0, 0x80($sp)
/* EA1700 80240E00 8C960148 */  lw        $s6, 0x148($a0)
/* EA1704 80240E04 00C0902D */  daddu     $s2, $a2, $zero
/* EA1708 80240E08 86C40008 */  lh        $a0, 8($s6)
/* EA170C 80240E0C 0C00F92F */  jal       dead_get_npc_unsafe
/* EA1710 80240E10 0000B82D */   daddu    $s7, $zero, $zero
/* EA1714 80240E14 0040882D */  daddu     $s1, $v0, $zero
/* EA1718 80240E18 9622008E */  lhu       $v0, 0x8e($s1)
/* EA171C 80240E1C 2442FFFF */  addiu     $v0, $v0, -1
/* EA1720 80240E20 A622008E */  sh        $v0, 0x8e($s1)
/* EA1724 80240E24 00021400 */  sll       $v0, $v0, 0x10
/* EA1728 80240E28 8EC30090 */  lw        $v1, 0x90($s6)
/* EA172C 80240E2C 00021403 */  sra       $v0, $v0, 0x10
/* EA1730 80240E30 0062182A */  slt       $v1, $v1, $v0
/* EA1734 80240E34 14600005 */  bnez      $v1, .L80240E4C
/* EA1738 80240E38 02E0F02D */   daddu    $fp, $s7, $zero
/* EA173C 80240E3C 8EC20000 */  lw        $v0, ($s6)
/* EA1740 80240E40 3C031F10 */  lui       $v1, 0x1f10
/* EA1744 80240E44 00431025 */  or        $v0, $v0, $v1
/* EA1748 80240E48 AEC20000 */  sw        $v0, ($s6)
.L80240E4C:
/* EA174C 80240E4C 8622008E */  lh        $v0, 0x8e($s1)
/* EA1750 80240E50 1440025D */  bnez      $v0, .L802417C8
/* EA1754 80240E54 00000000 */   nop
/* EA1758 80240E58 3C028010 */  lui       $v0, %hi(dead_gPlayerStatusPtr)
/* EA175C 80240E5C 8C42FC90 */  lw        $v0, %lo(dead_gPlayerStatusPtr)($v0)
/* EA1760 80240E60 0C00AB85 */  jal       dead_clamp_angle
/* EA1764 80240E64 C44C00A8 */   lwc1     $f12, 0xa8($v0)
/* EA1768 80240E68 3C014334 */  lui       $at, 0x4334
/* EA176C 80240E6C 44811000 */  mtc1      $at, $f2
/* EA1770 80240E70 00000000 */  nop
/* EA1774 80240E74 4602003C */  c.lt.s    $f0, $f2
/* EA1778 80240E78 00000000 */  nop
/* EA177C 80240E7C 45000011 */  bc1f      .L80240EC4
/* EA1780 80240E80 00000000 */   nop
/* EA1784 80240E84 3C038008 */  lui       $v1, %hi(dead_gCurrentCameraID)
/* EA1788 80240E88 8C63C760 */  lw        $v1, %lo(dead_gCurrentCameraID)($v1)
/* EA178C 80240E8C 3C0142B4 */  lui       $at, 0x42b4
/* EA1790 80240E90 44816000 */  mtc1      $at, $f12
/* EA1794 80240E94 00031080 */  sll       $v0, $v1, 2
/* EA1798 80240E98 00431021 */  addu      $v0, $v0, $v1
/* EA179C 80240E9C 00021080 */  sll       $v0, $v0, 2
/* EA17A0 80240EA0 00431023 */  subu      $v0, $v0, $v1
/* EA17A4 80240EA4 000218C0 */  sll       $v1, $v0, 3
/* EA17A8 80240EA8 00431021 */  addu      $v0, $v0, $v1
/* EA17AC 80240EAC 000210C0 */  sll       $v0, $v0, 3
/* EA17B0 80240EB0 3C01800C */  lui       $at, %hi(D_800B8DEC)
/* EA17B4 80240EB4 00220821 */  addu      $at, $at, $v0
/* EA17B8 80240EB8 C4208DEC */  lwc1      $f0, %lo(D_800B8DEC)($at)
/* EA17BC 80240EBC 080903C0 */  j         .L80240F00
/* EA17C0 80240EC0 460C0301 */   sub.s    $f12, $f0, $f12
.L80240EC4:
/* EA17C4 80240EC4 3C038008 */  lui       $v1, %hi(dead_gCurrentCameraID)
/* EA17C8 80240EC8 8C63C760 */  lw        $v1, %lo(dead_gCurrentCameraID)($v1)
/* EA17CC 80240ECC 3C0142B4 */  lui       $at, 0x42b4
/* EA17D0 80240ED0 44816000 */  mtc1      $at, $f12
/* EA17D4 80240ED4 00031080 */  sll       $v0, $v1, 2
/* EA17D8 80240ED8 00431021 */  addu      $v0, $v0, $v1
/* EA17DC 80240EDC 00021080 */  sll       $v0, $v0, 2
/* EA17E0 80240EE0 00431023 */  subu      $v0, $v0, $v1
/* EA17E4 80240EE4 000218C0 */  sll       $v1, $v0, 3
/* EA17E8 80240EE8 00431021 */  addu      $v0, $v0, $v1
/* EA17EC 80240EEC 000210C0 */  sll       $v0, $v0, 3
/* EA17F0 80240EF0 3C01800C */  lui       $at, %hi(D_800B8DEC)
/* EA17F4 80240EF4 00220821 */  addu      $at, $at, $v0
/* EA17F8 80240EF8 C4208DEC */  lwc1      $f0, %lo(D_800B8DEC)($at)
/* EA17FC 80240EFC 460C0300 */  add.s     $f12, $f0, $f12
.L80240F00:
/* EA1800 80240F00 0C00AB85 */  jal       dead_clamp_angle
/* EA1804 80240F04 00000000 */   nop
/* EA1808 80240F08 46000586 */  mov.s     $f22, $f0
/* EA180C 80240F0C 3C014334 */  lui       $at, 0x4334
/* EA1810 80240F10 44816000 */  mtc1      $at, $f12
/* EA1814 80240F14 0C00AB85 */  jal       dead_clamp_angle
/* EA1818 80240F18 460CB300 */   add.s    $f12, $f22, $f12
/* EA181C 80240F1C 8EC20088 */  lw        $v0, 0x88($s6)
/* EA1820 80240F20 14400010 */  bnez      $v0, .L80240F64
/* EA1824 80240F24 46000606 */   mov.s    $f24, $f0
/* EA1828 80240F28 3C028010 */  lui       $v0, %hi(dead_gPlayerStatusPtr)
/* EA182C 80240F2C 8C42FC90 */  lw        $v0, %lo(dead_gPlayerStatusPtr)($v0)
/* EA1830 80240F30 804300B4 */  lb        $v1, 0xb4($v0)
/* EA1834 80240F34 3C014200 */  lui       $at, 0x4200
/* EA1838 80240F38 4481A000 */  mtc1      $at, $f20
/* EA183C 80240F3C 10600016 */  beqz      $v1, .L80240F98
/* EA1840 80240F40 24020001 */   addiu    $v0, $zero, 1
/* EA1844 80240F44 3C0142C8 */  lui       $at, 0x42c8
/* EA1848 80240F48 4481A000 */  mtc1      $at, $f20
/* EA184C 80240F4C 14620013 */  bne       $v1, $v0, .L80240F9C
/* EA1850 80240F50 26300038 */   addiu    $s0, $s1, 0x38
/* EA1854 80240F54 3C0142B4 */  lui       $at, 0x42b4
/* EA1858 80240F58 4481A000 */  mtc1      $at, $f20
/* EA185C 80240F5C 080903E8 */  j         .L80240FA0
/* EA1860 80240F60 0200202D */   daddu    $a0, $s0, $zero
.L80240F64:
/* EA1864 80240F64 3C028010 */  lui       $v0, %hi(dead_gPlayerStatusPtr)
/* EA1868 80240F68 8C42FC90 */  lw        $v0, %lo(dead_gPlayerStatusPtr)($v0)
/* EA186C 80240F6C 804300B4 */  lb        $v1, 0xb4($v0)
/* EA1870 80240F70 3C014218 */  lui       $at, 0x4218
/* EA1874 80240F74 4481A000 */  mtc1      $at, $f20
/* EA1878 80240F78 10600007 */  beqz      $v1, .L80240F98
/* EA187C 80240F7C 24020001 */   addiu    $v0, $zero, 1
/* EA1880 80240F80 3C0142B4 */  lui       $at, 0x42b4
/* EA1884 80240F84 4481A000 */  mtc1      $at, $f20
/* EA1888 80240F88 14620004 */  bne       $v1, $v0, .L80240F9C
/* EA188C 80240F8C 26300038 */   addiu    $s0, $s1, 0x38
/* EA1890 80240F90 3C014296 */  lui       $at, 0x4296
/* EA1894 80240F94 4481A000 */  mtc1      $at, $f20
.L80240F98:
/* EA1898 80240F98 26300038 */  addiu     $s0, $s1, 0x38
.L80240F9C:
/* EA189C 80240F9C 0200202D */  daddu     $a0, $s0, $zero
.L80240FA0:
/* EA18A0 80240FA0 3C158010 */  lui       $s5, %hi(dead_gPlayerStatusPtr)
/* EA18A4 80240FA4 26B5FC90 */  addiu     $s5, $s5, %lo(dead_gPlayerStatusPtr)
/* EA18A8 80240FA8 4407C000 */  mfc1      $a3, $f24
/* EA18AC 80240FAC 862200A6 */  lh        $v0, 0xa6($s1)
/* EA18B0 80240FB0 8EA30000 */  lw        $v1, ($s5)
/* EA18B4 80240FB4 44824000 */  mtc1      $v0, $f8
/* EA18B8 80240FB8 00000000 */  nop
/* EA18BC 80240FBC 46804220 */  cvt.s.w   $f8, $f8
/* EA18C0 80240FC0 C4600028 */  lwc1      $f0, 0x28($v1)
/* EA18C4 80240FC4 44064000 */  mfc1      $a2, $f8
/* EA18C8 80240FC8 26330040 */  addiu     $s3, $s1, 0x40
/* EA18CC 80240FCC E6200038 */  swc1      $f0, 0x38($s1)
/* EA18D0 80240FD0 C4600030 */  lwc1      $f0, 0x30($v1)
/* EA18D4 80240FD4 0260282D */  daddu     $a1, $s3, $zero
/* EA18D8 80240FD8 0C00ACA3 */  jal       dead_add_vec2D_polar
/* EA18DC 80240FDC E6200040 */   swc1     $f0, 0x40($s1)
/* EA18E0 80240FE0 862200A6 */  lh        $v0, 0xa6($s1)
/* EA18E4 80240FE4 44820000 */  mtc1      $v0, $f0
/* EA18E8 80240FE8 00000000 */  nop
/* EA18EC 80240FEC 46800020 */  cvt.s.w   $f0, $f0
/* EA18F0 80240FF0 4600A000 */  add.s     $f0, $f20, $f0
/* EA18F4 80240FF4 4406B000 */  mfc1      $a2, $f22
/* EA18F8 80240FF8 44050000 */  mfc1      $a1, $f0
/* EA18FC 80240FFC 0C00F909 */  jal       dead_npc_move_heading
/* EA1900 80241000 0220202D */   daddu    $a0, $s1, $zero
/* EA1904 80241004 8EC20088 */  lw        $v0, 0x88($s6)
/* EA1908 80241008 1440005D */  bnez      $v0, .L80241180
/* EA190C 8024100C 00000000 */   nop
/* EA1910 80241010 C6200038 */  lwc1      $f0, 0x38($s1)
/* EA1914 80241014 3C018024 */  lui       $at, %hi(D_80246618_EA6F18)
/* EA1918 80241018 D4246618 */  ldc1      $f4, %lo(D_80246618_EA6F18)($at)
/* EA191C 8024101C 46000021 */  cvt.d.s   $f0, $f0
/* EA1920 80241020 4620203C */  c.lt.d    $f4, $f0
/* EA1924 80241024 00000000 */  nop
/* EA1928 80241028 45000005 */  bc1f      .L80241040
/* EA192C 8024102C 00000000 */   nop
/* EA1930 80241030 3C0143BE */  lui       $at, 0x43be
/* EA1934 80241034 44810000 */  mtc1      $at, $f0
/* EA1938 80241038 00000000 */  nop
/* EA193C 8024103C E6200038 */  swc1      $f0, 0x38($s1)
.L80241040:
/* EA1940 80241040 C6200038 */  lwc1      $f0, 0x38($s1)
/* EA1944 80241044 3C018024 */  lui       $at, %hi(D_80246620_EA6F20)
/* EA1948 80241048 D4226620 */  ldc1      $f2, %lo(D_80246620_EA6F20)($at)
/* EA194C 8024104C 46000021 */  cvt.d.s   $f0, $f0
/* EA1950 80241050 4622003C */  c.lt.d    $f0, $f2
/* EA1954 80241054 00000000 */  nop
/* EA1958 80241058 45000005 */  bc1f      .L80241070
/* EA195C 8024105C 00000000 */   nop
/* EA1960 80241060 3C01C3BE */  lui       $at, 0xc3be
/* EA1964 80241064 44810000 */  mtc1      $at, $f0
/* EA1968 80241068 00000000 */  nop
/* EA196C 8024106C E6200038 */  swc1      $f0, 0x38($s1)
.L80241070:
/* EA1970 80241070 C6200040 */  lwc1      $f0, 0x40($s1)
/* EA1974 80241074 46000021 */  cvt.d.s   $f0, $f0
/* EA1978 80241078 4620203C */  c.lt.d    $f4, $f0
/* EA197C 8024107C 00000000 */  nop
/* EA1980 80241080 45000005 */  bc1f      .L80241098
/* EA1984 80241084 00000000 */   nop
/* EA1988 80241088 3C0143BE */  lui       $at, 0x43be
/* EA198C 8024108C 44810000 */  mtc1      $at, $f0
/* EA1990 80241090 00000000 */  nop
/* EA1994 80241094 E6200040 */  swc1      $f0, 0x40($s1)
.L80241098:
/* EA1998 80241098 C6200040 */  lwc1      $f0, 0x40($s1)
/* EA199C 8024109C 46000021 */  cvt.d.s   $f0, $f0
/* EA19A0 802410A0 4622003C */  c.lt.d    $f0, $f2
/* EA19A4 802410A4 00000000 */  nop
/* EA19A8 802410A8 45000005 */  bc1f      .L802410C0
/* EA19AC 802410AC 00000000 */   nop
/* EA19B0 802410B0 3C01C3BE */  lui       $at, 0xc3be
/* EA19B4 802410B4 44810000 */  mtc1      $at, $f0
/* EA19B8 802410B8 00000000 */  nop
/* EA19BC 802410BC E6200040 */  swc1      $f0, 0x40($s1)
.L802410C0:
/* EA19C0 802410C0 C6220038 */  lwc1      $f2, 0x38($s1)
/* EA19C4 802410C4 46021082 */  mul.s     $f2, $f2, $f2
/* EA19C8 802410C8 00000000 */  nop
/* EA19CC 802410CC C6200040 */  lwc1      $f0, 0x40($s1)
/* EA19D0 802410D0 46000002 */  mul.s     $f0, $f0, $f0
/* EA19D4 802410D4 00000000 */  nop
/* EA19D8 802410D8 46001300 */  add.s     $f12, $f2, $f0
/* EA19DC 802410DC 46006004 */  sqrt.s    $f0, $f12
/* EA19E0 802410E0 46000032 */  c.eq.s    $f0, $f0
/* EA19E4 802410E4 00000000 */  nop
/* EA19E8 802410E8 45010003 */  bc1t      .L802410F8
/* EA19EC 802410EC 00000000 */   nop
/* EA19F0 802410F0 0C019C10 */  jal       func_80067040
/* EA19F4 802410F4 00000000 */   nop
.L802410F8:
/* EA19F8 802410F8 8E260038 */  lw        $a2, 0x38($s1)
/* EA19FC 802410FC 8E270040 */  lw        $a3, 0x40($s1)
/* EA1A00 80241100 4480A000 */  mtc1      $zero, $f20
/* EA1A04 80241104 E7A00038 */  swc1      $f0, 0x38($sp)
/* EA1A08 80241108 4600A306 */  mov.s     $f12, $f20
/* EA1A0C 8024110C 0C00ABDC */  jal       fio_validate_header_checksums
/* EA1A10 80241110 4600A386 */   mov.s    $f14, $f20
/* EA1A14 80241114 46000586 */  mov.s     $f22, $f0
/* EA1A18 80241118 C7A20038 */  lwc1      $f2, 0x38($sp)
/* EA1A1C 8024111C 3C018024 */  lui       $at, %hi(D_80246628_EA6F28)
/* EA1A20 80241120 D4206628 */  ldc1      $f0, %lo(D_80246628_EA6F28)($at)
/* EA1A24 80241124 460010A1 */  cvt.d.s   $f2, $f2
/* EA1A28 80241128 4620103C */  c.lt.d    $f2, $f0
/* EA1A2C 8024112C 00000000 */  nop
/* EA1A30 80241130 45000004 */  bc1f      .L80241144
/* EA1A34 80241134 0200202D */   daddu    $a0, $s0, $zero
/* EA1A38 80241138 3C064398 */  lui       $a2, 0x4398
/* EA1A3C 8024113C 08090459 */  j         .L80241164
/* EA1A40 80241140 34C68000 */   ori      $a2, $a2, 0x8000
.L80241144:
/* EA1A44 80241144 3C018024 */  lui       $at, %hi(D_80246630_EA6F30)
/* EA1A48 80241148 D4206630 */  ldc1      $f0, %lo(D_80246630_EA6F30)($at)
/* EA1A4C 8024114C 4622003C */  c.lt.d    $f0, $f2
/* EA1A50 80241150 00000000 */  nop
/* EA1A54 80241154 450000FA */  bc1f      .L80241540
/* EA1A58 80241158 00000000 */   nop
/* EA1A5C 8024115C 3C0643BB */  lui       $a2, 0x43bb
/* EA1A60 80241160 34C68000 */  ori       $a2, $a2, 0x8000
.L80241164:
/* EA1A64 80241164 4407B000 */  mfc1      $a3, $f22
/* EA1A68 80241168 0260282D */  daddu     $a1, $s3, $zero
/* EA1A6C 8024116C E6340038 */  swc1      $f20, 0x38($s1)
/* EA1A70 80241170 0C00ACA3 */  jal       dead_add_vec2D_polar
/* EA1A74 80241174 E6340040 */   swc1     $f20, 0x40($s1)
/* EA1A78 80241178 08090550 */  j         .L80241540
/* EA1A7C 8024117C 00000000 */   nop
.L80241180:
/* EA1A80 80241180 8E220000 */  lw        $v0, ($s1)
/* EA1A84 80241184 30420040 */  andi      $v0, $v0, 0x40
/* EA1A88 80241188 144000B0 */  bnez      $v0, .L8024144C
/* EA1A8C 8024118C 27A50020 */   addiu    $a1, $sp, 0x20
/* EA1A90 80241190 27B40020 */  addiu     $s4, $sp, 0x20
/* EA1A94 80241194 0280282D */  daddu     $a1, $s4, $zero
/* EA1A98 80241198 27B30024 */  addiu     $s3, $sp, 0x24
/* EA1A9C 8024119C 8EA20000 */  lw        $v0, ($s5)
/* EA1AA0 802411A0 3C014032 */  lui       $at, 0x4032
/* EA1AA4 802411A4 44811800 */  mtc1      $at, $f3
/* EA1AA8 802411A8 44801000 */  mtc1      $zero, $f2
/* EA1AAC 802411AC C440002C */  lwc1      $f0, 0x2c($v0)
/* EA1AB0 802411B0 C4460028 */  lwc1      $f6, 0x28($v0)
/* EA1AB4 802411B4 C4440030 */  lwc1      $f4, 0x30($v0)
/* EA1AB8 802411B8 46000021 */  cvt.d.s   $f0, $f0
/* EA1ABC 802411BC 46220000 */  add.d     $f0, $f0, $f2
/* EA1AC0 802411C0 E7A60020 */  swc1      $f6, 0x20($sp)
/* EA1AC4 802411C4 E7A40028 */  swc1      $f4, 0x28($sp)
/* EA1AC8 802411C8 46200020 */  cvt.s.d   $f0, $f0
/* EA1ACC 802411CC E7A00024 */  swc1      $f0, 0x24($sp)
/* EA1AD0 802411D0 E7B40010 */  swc1      $f20, 0x10($sp)
/* EA1AD4 802411D4 E7B60014 */  swc1      $f22, 0x14($sp)
/* EA1AD8 802411D8 862200A8 */  lh        $v0, 0xa8($s1)
/* EA1ADC 802411DC 0260302D */  daddu     $a2, $s3, $zero
/* EA1AE0 802411E0 44820000 */  mtc1      $v0, $f0
/* EA1AE4 802411E4 00000000 */  nop
/* EA1AE8 802411E8 46800020 */  cvt.s.w   $f0, $f0
/* EA1AEC 802411EC E7A00018 */  swc1      $f0, 0x18($sp)
/* EA1AF0 802411F0 862200A6 */  lh        $v0, 0xa6($s1)
/* EA1AF4 802411F4 27B00028 */  addiu     $s0, $sp, 0x28
/* EA1AF8 802411F8 44820000 */  mtc1      $v0, $f0
/* EA1AFC 802411FC 00000000 */  nop
/* EA1B00 80241200 46800020 */  cvt.s.w   $f0, $f0
/* EA1B04 80241204 E7A0001C */  swc1      $f0, 0x1c($sp)
/* EA1B08 80241208 8E240080 */  lw        $a0, 0x80($s1)
/* EA1B0C 8024120C 0C0394C1 */  jal       dead_npc_test_move_simple_with_slipping
/* EA1B10 80241210 0200382D */   daddu    $a3, $s0, $zero
/* EA1B14 80241214 104000CA */  beqz      $v0, .L80241540
/* EA1B18 80241218 0280282D */   daddu    $a1, $s4, $zero
/* EA1B1C 8024121C 8EA20000 */  lw        $v0, ($s5)
/* EA1B20 80241220 3C018024 */  lui       $at, %hi(D_80246638_EA6F38)
/* EA1B24 80241224 D4226638 */  ldc1      $f2, %lo(D_80246638_EA6F38)($at)
/* EA1B28 80241228 C440002C */  lwc1      $f0, 0x2c($v0)
/* EA1B2C 8024122C C4460028 */  lwc1      $f6, 0x28($v0)
/* EA1B30 80241230 C4440030 */  lwc1      $f4, 0x30($v0)
/* EA1B34 80241234 46000021 */  cvt.d.s   $f0, $f0
/* EA1B38 80241238 46220000 */  add.d     $f0, $f0, $f2
/* EA1B3C 8024123C E7A60020 */  swc1      $f6, 0x20($sp)
/* EA1B40 80241240 E7A40028 */  swc1      $f4, 0x28($sp)
/* EA1B44 80241244 46200020 */  cvt.s.d   $f0, $f0
/* EA1B48 80241248 E7A00024 */  swc1      $f0, 0x24($sp)
/* EA1B4C 8024124C E7B40010 */  swc1      $f20, 0x10($sp)
/* EA1B50 80241250 E7B60014 */  swc1      $f22, 0x14($sp)
/* EA1B54 80241254 862200A8 */  lh        $v0, 0xa8($s1)
/* EA1B58 80241258 44820000 */  mtc1      $v0, $f0
/* EA1B5C 8024125C 00000000 */  nop
/* EA1B60 80241260 46800020 */  cvt.s.w   $f0, $f0
/* EA1B64 80241264 E7A00018 */  swc1      $f0, 0x18($sp)
/* EA1B68 80241268 862200A6 */  lh        $v0, 0xa6($s1)
/* EA1B6C 8024126C 0260302D */  daddu     $a2, $s3, $zero
/* EA1B70 80241270 44820000 */  mtc1      $v0, $f0
/* EA1B74 80241274 00000000 */  nop
/* EA1B78 80241278 46800020 */  cvt.s.w   $f0, $f0
/* EA1B7C 8024127C E7A0001C */  swc1      $f0, 0x1c($sp)
/* EA1B80 80241280 8E240080 */  lw        $a0, 0x80($s1)
/* EA1B84 80241284 0C0394C1 */  jal       dead_npc_test_move_simple_with_slipping
/* EA1B88 80241288 0200382D */   daddu    $a3, $s0, $zero
/* EA1B8C 8024128C 27A5002C */  addiu     $a1, $sp, 0x2c
/* EA1B90 80241290 27A60030 */  addiu     $a2, $sp, 0x30
/* EA1B94 80241294 27A70034 */  addiu     $a3, $sp, 0x34
/* EA1B98 80241298 27A30038 */  addiu     $v1, $sp, 0x38
/* EA1B9C 8024129C C6220038 */  lwc1      $f2, 0x38($s1)
/* EA1BA0 802412A0 C620003C */  lwc1      $f0, 0x3c($s1)
/* EA1BA4 802412A4 3C014348 */  lui       $at, 0x4348
/* EA1BA8 802412A8 44813000 */  mtc1      $at, $f6
/* EA1BAC 802412AC 46000021 */  cvt.d.s   $f0, $f0
/* EA1BB0 802412B0 E7A2002C */  swc1      $f2, 0x2c($sp)
/* EA1BB4 802412B4 3C014059 */  lui       $at, 0x4059
/* EA1BB8 802412B8 44811800 */  mtc1      $at, $f3
/* EA1BBC 802412BC 44801000 */  mtc1      $zero, $f2
/* EA1BC0 802412C0 C6240040 */  lwc1      $f4, 0x40($s1)
/* EA1BC4 802412C4 46220000 */  add.d     $f0, $f0, $f2
/* EA1BC8 802412C8 E7A60038 */  swc1      $f6, 0x38($sp)
/* EA1BCC 802412CC E7A40034 */  swc1      $f4, 0x34($sp)
/* EA1BD0 802412D0 46200020 */  cvt.s.d   $f0, $f0
/* EA1BD4 802412D4 E7A00030 */  swc1      $f0, 0x30($sp)
/* EA1BD8 802412D8 AFA30010 */  sw        $v1, 0x10($sp)
/* EA1BDC 802412DC 8E240080 */  lw        $a0, 0x80($s1)
/* EA1BE0 802412E0 0C03908F */  jal       dead_npc_raycast_down_sides
/* EA1BE4 802412E4 0040802D */   daddu    $s0, $v0, $zero
/* EA1BE8 802412E8 1600001C */  bnez      $s0, .L8024135C
/* EA1BEC 802412EC 00000000 */   nop
/* EA1BF0 802412F0 1040001A */  beqz      $v0, .L8024135C
/* EA1BF4 802412F4 00000000 */   nop
/* EA1BF8 802412F8 C7A20038 */  lwc1      $f2, 0x38($sp)
/* EA1BFC 802412FC 3C014054 */  lui       $at, 0x4054
/* EA1C00 80241300 44810800 */  mtc1      $at, $f1
/* EA1C04 80241304 44800000 */  mtc1      $zero, $f0
/* EA1C08 80241308 460010A1 */  cvt.d.s   $f2, $f2
/* EA1C0C 8024130C 4622003C */  c.lt.d    $f0, $f2
/* EA1C10 80241310 00000000 */  nop
/* EA1C14 80241314 45000011 */  bc1f      .L8024135C
/* EA1C18 80241318 00000000 */   nop
/* EA1C1C 8024131C 3C01405E */  lui       $at, 0x405e
/* EA1C20 80241320 44810800 */  mtc1      $at, $f1
/* EA1C24 80241324 44800000 */  mtc1      $zero, $f0
/* EA1C28 80241328 00000000 */  nop
/* EA1C2C 8024132C 4620103C */  c.lt.d    $f2, $f0
/* EA1C30 80241330 00000000 */  nop
/* EA1C34 80241334 45000009 */  bc1f      .L8024135C
/* EA1C38 80241338 00000000 */   nop
/* EA1C3C 8024133C C622003C */  lwc1      $f2, 0x3c($s1)
/* EA1C40 80241340 C7A00030 */  lwc1      $f0, 0x30($sp)
/* EA1C44 80241344 46001032 */  c.eq.s    $f2, $f0
/* EA1C48 80241348 00000000 */  nop
/* EA1C4C 8024134C 45010003 */  bc1t      .L8024135C
/* EA1C50 80241350 00000000 */   nop
/* EA1C54 80241354 08090550 */  j         .L80241540
/* EA1C58 80241358 241E0001 */   addiu    $fp, $zero, 1
.L8024135C:
/* EA1C5C 8024135C 3C108010 */  lui       $s0, %hi(dead_gPlayerStatusPtr)
/* EA1C60 80241360 2610FC90 */  addiu     $s0, $s0, %lo(dead_gPlayerStatusPtr)
/* EA1C64 80241364 8E020000 */  lw        $v0, ($s0)
/* EA1C68 80241368 3C014024 */  lui       $at, 0x4024
/* EA1C6C 8024136C 44811800 */  mtc1      $at, $f3
/* EA1C70 80241370 44801000 */  mtc1      $zero, $f2
/* EA1C74 80241374 C440002C */  lwc1      $f0, 0x2c($v0)
/* EA1C78 80241378 C4460028 */  lwc1      $f6, 0x28($v0)
/* EA1C7C 8024137C C4440030 */  lwc1      $f4, 0x30($v0)
/* EA1C80 80241380 46000021 */  cvt.d.s   $f0, $f0
/* EA1C84 80241384 46220000 */  add.d     $f0, $f0, $f2
/* EA1C88 80241388 E7A60020 */  swc1      $f6, 0x20($sp)
/* EA1C8C 8024138C E7A40028 */  swc1      $f4, 0x28($sp)
/* EA1C90 80241390 46200020 */  cvt.s.d   $f0, $f0
/* EA1C94 80241394 E7A00024 */  swc1      $f0, 0x24($sp)
/* EA1C98 80241398 E7B40010 */  swc1      $f20, 0x10($sp)
/* EA1C9C 8024139C E7B60014 */  swc1      $f22, 0x14($sp)
/* EA1CA0 802413A0 862200A8 */  lh        $v0, 0xa8($s1)
/* EA1CA4 802413A4 27A50020 */  addiu     $a1, $sp, 0x20
/* EA1CA8 802413A8 44820000 */  mtc1      $v0, $f0
/* EA1CAC 802413AC 00000000 */  nop
/* EA1CB0 802413B0 46800020 */  cvt.s.w   $f0, $f0
/* EA1CB4 802413B4 E7A00018 */  swc1      $f0, 0x18($sp)
/* EA1CB8 802413B8 862200A6 */  lh        $v0, 0xa6($s1)
/* EA1CBC 802413BC 27A60024 */  addiu     $a2, $sp, 0x24
/* EA1CC0 802413C0 44820000 */  mtc1      $v0, $f0
/* EA1CC4 802413C4 00000000 */  nop
/* EA1CC8 802413C8 46800020 */  cvt.s.w   $f0, $f0
/* EA1CCC 802413CC E7A0001C */  swc1      $f0, 0x1c($sp)
/* EA1CD0 802413D0 8E240080 */  lw        $a0, 0x80($s1)
/* EA1CD4 802413D4 0C0394C1 */  jal       dead_npc_test_move_simple_with_slipping
/* EA1CD8 802413D8 27A70028 */   addiu    $a3, $sp, 0x28
/* EA1CDC 802413DC 8FA60020 */  lw        $a2, 0x20($sp)
/* EA1CE0 802413E0 8E020000 */  lw        $v0, ($s0)
/* EA1CE4 802413E4 8FA70028 */  lw        $a3, 0x28($sp)
/* EA1CE8 802413E8 C44C0028 */  lwc1      $f12, 0x28($v0)
/* EA1CEC 802413EC C44E0030 */  lwc1      $f14, 0x30($v0)
/* EA1CF0 802413F0 0C00AC71 */  jal       dead_dist2D
/* EA1CF4 802413F4 24170001 */   addiu    $s7, $zero, 1
/* EA1CF8 802413F8 46000506 */  mov.s     $f20, $f0
/* EA1CFC 802413FC 8E030000 */  lw        $v1, ($s0)
/* EA1D00 80241400 862200A6 */  lh        $v0, 0xa6($s1)
/* EA1D04 80241404 4407C000 */  mfc1      $a3, $f24
/* EA1D08 80241408 44824000 */  mtc1      $v0, $f8
/* EA1D0C 8024140C 00000000 */  nop
/* EA1D10 80241410 46804220 */  cvt.s.w   $f8, $f8
/* EA1D14 80241414 C4600028 */  lwc1      $f0, 0x28($v1)
/* EA1D18 80241418 44064000 */  mfc1      $a2, $f8
/* EA1D1C 8024141C 26240038 */  addiu     $a0, $s1, 0x38
/* EA1D20 80241420 E6200038 */  swc1      $f0, 0x38($s1)
/* EA1D24 80241424 C4600030 */  lwc1      $f0, 0x30($v1)
/* EA1D28 80241428 26250040 */  addiu     $a1, $s1, 0x40
/* EA1D2C 8024142C 0C00ACA3 */  jal       dead_add_vec2D_polar
/* EA1D30 80241430 E6200040 */   swc1     $f0, 0x40($s1)
/* EA1D34 80241434 862200A6 */  lh        $v0, 0xa6($s1)
/* EA1D38 80241438 44820000 */  mtc1      $v0, $f0
/* EA1D3C 8024143C 00000000 */  nop
/* EA1D40 80241440 46800020 */  cvt.s.w   $f0, $f0
/* EA1D44 80241444 0809054C */  j         .L80241530
/* EA1D48 80241448 4600A500 */   add.s    $f20, $f20, $f0
.L8024144C:
/* EA1D4C 8024144C 8EA20000 */  lw        $v0, ($s5)
/* EA1D50 80241450 3C014032 */  lui       $at, 0x4032
/* EA1D54 80241454 44811800 */  mtc1      $at, $f3
/* EA1D58 80241458 44801000 */  mtc1      $zero, $f2
/* EA1D5C 8024145C C440002C */  lwc1      $f0, 0x2c($v0)
/* EA1D60 80241460 C4460028 */  lwc1      $f6, 0x28($v0)
/* EA1D64 80241464 C4440030 */  lwc1      $f4, 0x30($v0)
/* EA1D68 80241468 46000021 */  cvt.d.s   $f0, $f0
/* EA1D6C 8024146C 46220000 */  add.d     $f0, $f0, $f2
/* EA1D70 80241470 E7A60020 */  swc1      $f6, 0x20($sp)
/* EA1D74 80241474 E7A40028 */  swc1      $f4, 0x28($sp)
/* EA1D78 80241478 46200020 */  cvt.s.d   $f0, $f0
/* EA1D7C 8024147C E7A00024 */  swc1      $f0, 0x24($sp)
/* EA1D80 80241480 E7B40010 */  swc1      $f20, 0x10($sp)
/* EA1D84 80241484 E7B60014 */  swc1      $f22, 0x14($sp)
/* EA1D88 80241488 862200A8 */  lh        $v0, 0xa8($s1)
/* EA1D8C 8024148C 44820000 */  mtc1      $v0, $f0
/* EA1D90 80241490 00000000 */  nop
/* EA1D94 80241494 46800020 */  cvt.s.w   $f0, $f0
/* EA1D98 80241498 E7A00018 */  swc1      $f0, 0x18($sp)
/* EA1D9C 8024149C 862200A6 */  lh        $v0, 0xa6($s1)
/* EA1DA0 802414A0 27A60024 */  addiu     $a2, $sp, 0x24
/* EA1DA4 802414A4 44820000 */  mtc1      $v0, $f0
/* EA1DA8 802414A8 00000000 */  nop
/* EA1DAC 802414AC 46800020 */  cvt.s.w   $f0, $f0
/* EA1DB0 802414B0 E7A0001C */  swc1      $f0, 0x1c($sp)
/* EA1DB4 802414B4 8E240080 */  lw        $a0, 0x80($s1)
/* EA1DB8 802414B8 0C0394C1 */  jal       dead_npc_test_move_simple_with_slipping
/* EA1DBC 802414BC 27A70028 */   addiu    $a3, $sp, 0x28
/* EA1DC0 802414C0 1040001F */  beqz      $v0, .L80241540
/* EA1DC4 802414C4 00000000 */   nop
/* EA1DC8 802414C8 8FA60020 */  lw        $a2, 0x20($sp)
/* EA1DCC 802414CC 8EA20000 */  lw        $v0, ($s5)
/* EA1DD0 802414D0 8FA70028 */  lw        $a3, 0x28($sp)
/* EA1DD4 802414D4 C44C0028 */  lwc1      $f12, 0x28($v0)
/* EA1DD8 802414D8 0C00AC71 */  jal       dead_dist2D
/* EA1DDC 802414DC C44E0030 */   lwc1     $f14, 0x30($v0)
/* EA1DE0 802414E0 46000506 */  mov.s     $f20, $f0
/* EA1DE4 802414E4 8EA30000 */  lw        $v1, ($s5)
/* EA1DE8 802414E8 862200A6 */  lh        $v0, 0xa6($s1)
/* EA1DEC 802414EC 4407C000 */  mfc1      $a3, $f24
/* EA1DF0 802414F0 44824000 */  mtc1      $v0, $f8
/* EA1DF4 802414F4 00000000 */  nop
/* EA1DF8 802414F8 46804220 */  cvt.s.w   $f8, $f8
/* EA1DFC 802414FC C4600028 */  lwc1      $f0, 0x28($v1)
/* EA1E00 80241500 44064000 */  mfc1      $a2, $f8
/* EA1E04 80241504 0200202D */  daddu     $a0, $s0, $zero
/* EA1E08 80241508 E6200038 */  swc1      $f0, 0x38($s1)
/* EA1E0C 8024150C C4600030 */  lwc1      $f0, 0x30($v1)
/* EA1E10 80241510 0260282D */  daddu     $a1, $s3, $zero
/* EA1E14 80241514 0C00ACA3 */  jal       dead_add_vec2D_polar
/* EA1E18 80241518 E6200040 */   swc1     $f0, 0x40($s1)
/* EA1E1C 8024151C 862200A6 */  lh        $v0, 0xa6($s1)
/* EA1E20 80241520 44820000 */  mtc1      $v0, $f0
/* EA1E24 80241524 00000000 */  nop
/* EA1E28 80241528 46800020 */  cvt.s.w   $f0, $f0
/* EA1E2C 8024152C 4600A500 */  add.s     $f20, $f20, $f0
.L80241530:
/* EA1E30 80241530 4406B000 */  mfc1      $a2, $f22
/* EA1E34 80241534 4405A000 */  mfc1      $a1, $f20
/* EA1E38 80241538 0C00F909 */  jal       dead_npc_move_heading
/* EA1E3C 8024153C 0220202D */   daddu    $a0, $s1, $zero
.L80241540:
/* EA1E40 80241540 C6400008 */  lwc1      $f0, 8($s2)
/* EA1E44 80241544 46800020 */  cvt.s.w   $f0, $f0
/* EA1E48 80241548 44050000 */  mfc1      $a1, $f0
/* EA1E4C 8024154C C640000C */  lwc1      $f0, 0xc($s2)
/* EA1E50 80241550 46800020 */  cvt.s.w   $f0, $f0
/* EA1E54 80241554 44060000 */  mfc1      $a2, $f0
/* EA1E58 80241558 C6200040 */  lwc1      $f0, 0x40($s1)
/* EA1E5C 8024155C 26300038 */  addiu     $s0, $s1, 0x38
/* EA1E60 80241560 E7A00010 */  swc1      $f0, 0x10($sp)
/* EA1E64 80241564 C6400010 */  lwc1      $f0, 0x10($s2)
/* EA1E68 80241568 46800020 */  cvt.s.w   $f0, $f0
/* EA1E6C 8024156C E7A00014 */  swc1      $f0, 0x14($sp)
/* EA1E70 80241570 C6400014 */  lwc1      $f0, 0x14($s2)
/* EA1E74 80241574 46800020 */  cvt.s.w   $f0, $f0
/* EA1E78 80241578 E7A00018 */  swc1      $f0, 0x18($sp)
/* EA1E7C 8024157C 8E440004 */  lw        $a0, 4($s2)
/* EA1E80 80241580 8E270038 */  lw        $a3, 0x38($s1)
/* EA1E84 80241584 0C013431 */  jal       dead_is_point_within_region
/* EA1E88 80241588 26330040 */   addiu    $s3, $s1, 0x40
/* EA1E8C 8024158C 1040005A */  beqz      $v0, .L802416F8
/* EA1E90 80241590 00000000 */   nop
/* EA1E94 80241594 8E430004 */  lw        $v1, 4($s2)
/* EA1E98 80241598 10600005 */  beqz      $v1, .L802415B0
/* EA1E9C 8024159C 24020001 */   addiu    $v0, $zero, 1
/* EA1EA0 802415A0 10620029 */  beq       $v1, $v0, .L80241648
/* EA1EA4 802415A4 00000000 */   nop
/* EA1EA8 802415A8 080905BE */  j         .L802416F8
/* EA1EAC 802415AC 00000000 */   nop
.L802415B0:
/* EA1EB0 802415B0 C6480008 */  lwc1      $f8, 8($s2)
/* EA1EB4 802415B4 46804220 */  cvt.s.w   $f8, $f8
/* EA1EB8 802415B8 44064000 */  mfc1      $a2, $f8
/* EA1EBC 802415BC C648000C */  lwc1      $f8, 0xc($s2)
/* EA1EC0 802415C0 46804220 */  cvt.s.w   $f8, $f8
/* EA1EC4 802415C4 C62C0038 */  lwc1      $f12, 0x38($s1)
/* EA1EC8 802415C8 C62E0040 */  lwc1      $f14, 0x40($s1)
/* EA1ECC 802415CC 44074000 */  mfc1      $a3, $f8
/* EA1ED0 802415D0 0C00AC71 */  jal       dead_dist2D
/* EA1ED4 802415D4 00000000 */   nop
/* EA1ED8 802415D8 C6420010 */  lwc1      $f2, 0x10($s2)
/* EA1EDC 802415DC 468010A0 */  cvt.s.w   $f2, $f2
/* EA1EE0 802415E0 4600103C */  c.lt.s    $f2, $f0
/* EA1EE4 802415E4 00000000 */  nop
/* EA1EE8 802415E8 45000043 */  bc1f      .L802416F8
/* EA1EEC 802415EC E7A00038 */   swc1     $f0, 0x38($sp)
/* EA1EF0 802415F0 C64C0008 */  lwc1      $f12, 8($s2)
/* EA1EF4 802415F4 46806320 */  cvt.s.w   $f12, $f12
/* EA1EF8 802415F8 8E260038 */  lw        $a2, 0x38($s1)
/* EA1EFC 802415FC 8E270040 */  lw        $a3, 0x40($s1)
/* EA1F00 80241600 C64E000C */  lwc1      $f14, 0xc($s2)
/* EA1F04 80241604 0C00ABDC */  jal       fio_validate_header_checksums
/* EA1F08 80241608 468073A0 */   cvt.s.w  $f14, $f14
/* EA1F0C 8024160C 0200202D */  daddu     $a0, $s0, $zero
/* EA1F10 80241610 44070000 */  mfc1      $a3, $f0
/* EA1F14 80241614 C6400008 */  lwc1      $f0, 8($s2)
/* EA1F18 80241618 46800020 */  cvt.s.w   $f0, $f0
/* EA1F1C 8024161C E6200038 */  swc1      $f0, 0x38($s1)
/* EA1F20 80241620 C640000C */  lwc1      $f0, 0xc($s2)
/* EA1F24 80241624 46800020 */  cvt.s.w   $f0, $f0
/* EA1F28 80241628 E6200040 */  swc1      $f0, 0x40($s1)
/* EA1F2C 8024162C C6480010 */  lwc1      $f8, 0x10($s2)
/* EA1F30 80241630 46804220 */  cvt.s.w   $f8, $f8
/* EA1F34 80241634 44064000 */  mfc1      $a2, $f8
/* EA1F38 80241638 0C00ACA3 */  jal       dead_add_vec2D_polar
/* EA1F3C 8024163C 0260282D */   daddu    $a1, $s3, $zero
/* EA1F40 80241640 080905BE */  j         .L802416F8
/* EA1F44 80241644 00000000 */   nop
.L80241648:
/* EA1F48 80241648 8E420008 */  lw        $v0, 8($s2)
/* EA1F4C 8024164C 8E430010 */  lw        $v1, 0x10($s2)
/* EA1F50 80241650 C6200038 */  lwc1      $f0, 0x38($s1)
/* EA1F54 80241654 00431021 */  addu      $v0, $v0, $v1
/* EA1F58 80241658 44821000 */  mtc1      $v0, $f2
/* EA1F5C 8024165C 00000000 */  nop
/* EA1F60 80241660 468010A0 */  cvt.s.w   $f2, $f2
/* EA1F64 80241664 4600103C */  c.lt.s    $f2, $f0
/* EA1F68 80241668 00000000 */  nop
/* EA1F6C 8024166C 45030001 */  bc1tl     .L80241674
/* EA1F70 80241670 E6220038 */   swc1     $f2, 0x38($s1)
.L80241674:
/* EA1F74 80241674 8E420008 */  lw        $v0, 8($s2)
/* EA1F78 80241678 8E430010 */  lw        $v1, 0x10($s2)
/* EA1F7C 8024167C C6200038 */  lwc1      $f0, 0x38($s1)
/* EA1F80 80241680 00431023 */  subu      $v0, $v0, $v1
/* EA1F84 80241684 44821000 */  mtc1      $v0, $f2
/* EA1F88 80241688 00000000 */  nop
/* EA1F8C 8024168C 468010A0 */  cvt.s.w   $f2, $f2
/* EA1F90 80241690 4602003C */  c.lt.s    $f0, $f2
/* EA1F94 80241694 00000000 */  nop
/* EA1F98 80241698 45030001 */  bc1tl     .L802416A0
/* EA1F9C 8024169C E6220038 */   swc1     $f2, 0x38($s1)
.L802416A0:
/* EA1FA0 802416A0 8E42000C */  lw        $v0, 0xc($s2)
/* EA1FA4 802416A4 8E430014 */  lw        $v1, 0x14($s2)
/* EA1FA8 802416A8 C6200040 */  lwc1      $f0, 0x40($s1)
/* EA1FAC 802416AC 00431021 */  addu      $v0, $v0, $v1
/* EA1FB0 802416B0 44821000 */  mtc1      $v0, $f2
/* EA1FB4 802416B4 00000000 */  nop
/* EA1FB8 802416B8 468010A0 */  cvt.s.w   $f2, $f2
/* EA1FBC 802416BC 4600103C */  c.lt.s    $f2, $f0
/* EA1FC0 802416C0 00000000 */  nop
/* EA1FC4 802416C4 45030001 */  bc1tl     .L802416CC
/* EA1FC8 802416C8 E6220040 */   swc1     $f2, 0x40($s1)
.L802416CC:
/* EA1FCC 802416CC 8E42000C */  lw        $v0, 0xc($s2)
/* EA1FD0 802416D0 8E430014 */  lw        $v1, 0x14($s2)
/* EA1FD4 802416D4 C6200040 */  lwc1      $f0, 0x40($s1)
/* EA1FD8 802416D8 00431023 */  subu      $v0, $v0, $v1
/* EA1FDC 802416DC 44821000 */  mtc1      $v0, $f2
/* EA1FE0 802416E0 00000000 */  nop
/* EA1FE4 802416E4 468010A0 */  cvt.s.w   $f2, $f2
/* EA1FE8 802416E8 4602003C */  c.lt.s    $f0, $f2
/* EA1FEC 802416EC 00000000 */  nop
/* EA1FF0 802416F0 45030001 */  bc1tl     .L802416F8
/* EA1FF4 802416F4 E6220040 */   swc1     $f2, 0x40($s1)
.L802416F8:
/* EA1FF8 802416F8 16E0001F */  bnez      $s7, .L80241778
/* EA1FFC 802416FC 00000000 */   nop
/* EA2000 80241700 8E220000 */  lw        $v0, ($s1)
/* EA2004 80241704 30420008 */  andi      $v0, $v0, 8
/* EA2008 80241708 10400003 */  beqz      $v0, .L80241718
/* EA200C 8024170C 27A50020 */   addiu    $a1, $sp, 0x20
/* EA2010 80241710 13C00019 */  beqz      $fp, .L80241778
/* EA2014 80241714 00000000 */   nop
.L80241718:
/* EA2018 80241718 27A60024 */  addiu     $a2, $sp, 0x24
/* EA201C 8024171C 27A20038 */  addiu     $v0, $sp, 0x38
/* EA2020 80241720 C6220038 */  lwc1      $f2, 0x38($s1)
/* EA2024 80241724 C620003C */  lwc1      $f0, 0x3c($s1)
/* EA2028 80241728 3C0143C8 */  lui       $at, 0x43c8
/* EA202C 8024172C 44813000 */  mtc1      $at, $f6
/* EA2030 80241730 46000021 */  cvt.d.s   $f0, $f0
/* EA2034 80241734 E7A20020 */  swc1      $f2, 0x20($sp)
/* EA2038 80241738 3C018024 */  lui       $at, %hi(D_80246640_EA6F40)
/* EA203C 8024173C D4226640 */  ldc1      $f2, %lo(D_80246640_EA6F40)($at)
/* EA2040 80241740 C6240040 */  lwc1      $f4, 0x40($s1)
/* EA2044 80241744 46220000 */  add.d     $f0, $f0, $f2
/* EA2048 80241748 E7A60038 */  swc1      $f6, 0x38($sp)
/* EA204C 8024174C E7A40028 */  swc1      $f4, 0x28($sp)
/* EA2050 80241750 46200020 */  cvt.s.d   $f0, $f0
/* EA2054 80241754 E7A00024 */  swc1      $f0, 0x24($sp)
/* EA2058 80241758 AFA20010 */  sw        $v0, 0x10($sp)
/* EA205C 8024175C 8E240080 */  lw        $a0, 0x80($s1)
/* EA2060 80241760 0C03908F */  jal       dead_npc_raycast_down_sides
/* EA2064 80241764 27A70028 */   addiu    $a3, $sp, 0x28
/* EA2068 80241768 10400003 */  beqz      $v0, .L80241778
/* EA206C 8024176C 00000000 */   nop
/* EA2070 80241770 C7A00024 */  lwc1      $f0, 0x24($sp)
/* EA2074 80241774 E620003C */  swc1      $f0, 0x3c($s1)
.L80241778:
/* EA2078 80241778 C62C0038 */  lwc1      $f12, 0x38($s1)
/* EA207C 8024177C 3C028010 */  lui       $v0, %hi(dead_gPlayerStatusPtr)
/* EA2080 80241780 8C42FC90 */  lw        $v0, %lo(dead_gPlayerStatusPtr)($v0)
/* EA2084 80241784 C62E0040 */  lwc1      $f14, 0x40($s1)
/* EA2088 80241788 8C460028 */  lw        $a2, 0x28($v0)
/* EA208C 8024178C 0C00ABDC */  jal       fio_validate_header_checksums
/* EA2090 80241790 8C470030 */   lw       $a3, 0x30($v0)
/* EA2094 80241794 0220202D */  daddu     $a0, $s1, $zero
/* EA2098 80241798 24050321 */  addiu     $a1, $zero, 0x321
/* EA209C 8024179C 0000302D */  daddu     $a2, $zero, $zero
/* EA20A0 802417A0 0C013600 */  jal       dead_ai_enemy_play_sound
/* EA20A4 802417A4 E620000C */   swc1     $f0, 0xc($s1)
/* EA20A8 802417A8 8EC200CC */  lw        $v0, 0xcc($s6)
/* EA20AC 802417AC 8C420024 */  lw        $v0, 0x24($v0)
/* EA20B0 802417B0 AE220028 */  sw        $v0, 0x28($s1)
/* EA20B4 802417B4 96C20096 */  lhu       $v0, 0x96($s6)
/* EA20B8 802417B8 A622008E */  sh        $v0, 0x8e($s1)
/* EA20BC 802417BC 8FA80080 */  lw        $t0, 0x80($sp)
/* EA20C0 802417C0 2402000B */  addiu     $v0, $zero, 0xb
/* EA20C4 802417C4 AD020070 */  sw        $v0, 0x70($t0)
.L802417C8:
/* EA20C8 802417C8 8FBF0064 */  lw        $ra, 0x64($sp)
/* EA20CC 802417CC 8FBE0060 */  lw        $fp, 0x60($sp)
/* EA20D0 802417D0 8FB7005C */  lw        $s7, 0x5c($sp)
/* EA20D4 802417D4 8FB60058 */  lw        $s6, 0x58($sp)
/* EA20D8 802417D8 8FB50054 */  lw        $s5, 0x54($sp)
/* EA20DC 802417DC 8FB40050 */  lw        $s4, 0x50($sp)
/* EA20E0 802417E0 8FB3004C */  lw        $s3, 0x4c($sp)
/* EA20E4 802417E4 8FB20048 */  lw        $s2, 0x48($sp)
/* EA20E8 802417E8 8FB10044 */  lw        $s1, 0x44($sp)
/* EA20EC 802417EC 8FB00040 */  lw        $s0, 0x40($sp)
/* EA20F0 802417F0 D7B80078 */  ldc1      $f24, 0x78($sp)
/* EA20F4 802417F4 D7B60070 */  ldc1      $f22, 0x70($sp)
/* EA20F8 802417F8 D7B40068 */  ldc1      $f20, 0x68($sp)
/* EA20FC 802417FC 03E00008 */  jr        $ra
/* EA2100 80241800 27BD0080 */   addiu    $sp, $sp, 0x80
