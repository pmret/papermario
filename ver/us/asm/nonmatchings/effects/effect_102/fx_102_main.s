.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_102_main
/* 3D1690 E00CC000 27BDFF90 */  addiu     $sp, $sp, -0x70
/* 3D1694 E00CC004 F7B40048 */  sdc1      $f20, 0x48($sp)
/* 3D1698 E00CC008 4485A000 */  mtc1      $a1, $f20
/* 3D169C E00CC00C F7B60050 */  sdc1      $f22, 0x50($sp)
/* 3D16A0 E00CC010 4486B000 */  mtc1      $a2, $f22
/* 3D16A4 E00CC014 AFB1002C */  sw        $s1, 0x2c($sp)
/* 3D16A8 E00CC018 0080882D */  daddu     $s1, $a0, $zero
/* 3D16AC E00CC01C F7BC0068 */  sdc1      $f28, 0x68($sp)
/* 3D16B0 E00CC020 4487E000 */  mtc1      $a3, $f28
/* 3D16B4 E00CC024 27A40010 */  addiu     $a0, $sp, 0x10
/* 3D16B8 E00CC028 AFB00028 */  sw        $s0, 0x28($sp)
/* 3D16BC E00CC02C 8FB00084 */  lw        $s0, 0x84($sp)
/* 3D16C0 E00CC030 3C02E00D */  lui       $v0, %hi(fx_102_init)
/* 3D16C4 E00CC034 2442C250 */  addiu     $v0, $v0, %lo(fx_102_init)
/* 3D16C8 E00CC038 AFA20018 */  sw        $v0, 0x18($sp)
/* 3D16CC E00CC03C 3C02E00D */  lui       $v0, %hi(fx_102_update)
/* 3D16D0 E00CC040 2442C258 */  addiu     $v0, $v0, %lo(fx_102_update)
/* 3D16D4 E00CC044 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3D16D8 E00CC048 3C02E00D */  lui       $v0, %hi(fx_102_render)
/* 3D16DC E00CC04C 2442C980 */  addiu     $v0, $v0, %lo(fx_102_render)
/* 3D16E0 E00CC050 AFA20020 */  sw        $v0, 0x20($sp)
/* 3D16E4 E00CC054 24020066 */  addiu     $v0, $zero, 0x66
/* 3D16E8 E00CC058 AFBF0040 */  sw        $ra, 0x40($sp)
/* 3D16EC E00CC05C AFB5003C */  sw        $s5, 0x3c($sp)
/* 3D16F0 E00CC060 AFB40038 */  sw        $s4, 0x38($sp)
/* 3D16F4 E00CC064 AFB30034 */  sw        $s3, 0x34($sp)
/* 3D16F8 E00CC068 AFB20030 */  sw        $s2, 0x30($sp)
/* 3D16FC E00CC06C F7BA0060 */  sdc1      $f26, 0x60($sp)
/* 3D1700 E00CC070 F7B80058 */  sdc1      $f24, 0x58($sp)
/* 3D1704 E00CC074 AFA00010 */  sw        $zero, 0x10($sp)
/* 3D1708 E00CC078 AFA00024 */  sw        $zero, 0x24($sp)
/* 3D170C E00CC07C 0C080124 */  jal       shim_create_effect_instance
/* 3D1710 E00CC080 AFA20014 */   sw       $v0, 0x14($sp)
/* 3D1714 E00CC084 24040798 */  addiu     $a0, $zero, 0x798
/* 3D1718 E00CC088 24030001 */  addiu     $v1, $zero, 1
/* 3D171C E00CC08C 0040A02D */  daddu     $s4, $v0, $zero
/* 3D1720 E00CC090 0C08012C */  jal       shim_general_heap_malloc
/* 3D1724 E00CC094 AE830008 */   sw       $v1, 8($s4)
/* 3D1728 E00CC098 0040182D */  daddu     $v1, $v0, $zero
/* 3D172C E00CC09C 14600003 */  bnez      $v1, .LE00CC0AC
/* 3D1730 E00CC0A0 AE82000C */   sw       $v0, 0xc($s4)
.LE00CC0A4:
/* 3D1734 E00CC0A4 08033029 */  j         .LE00CC0A4
/* 3D1738 E00CC0A8 00000000 */   nop
.LE00CC0AC:
/* 3D173C E00CC0AC AC710000 */  sw        $s1, ($v1)
/* 3D1740 E00CC0B0 1E000004 */  bgtz      $s0, .LE00CC0C4
/* 3D1744 E00CC0B4 AC600014 */   sw       $zero, 0x14($v1)
/* 3D1748 E00CC0B8 240203E8 */  addiu     $v0, $zero, 0x3e8
/* 3D174C E00CC0BC 08033032 */  j         .LE00CC0C8
/* 3D1750 E00CC0C0 AC620010 */   sw       $v0, 0x10($v1)
.LE00CC0C4:
/* 3D1754 E00CC0C4 AC700010 */  sw        $s0, 0x10($v1)
.LE00CC0C8:
/* 3D1758 E00CC0C8 0000902D */  daddu     $s2, $zero, $zero
/* 3D175C E00CC0CC 3C1551EB */  lui       $s5, 0x51eb
/* 3D1760 E00CC0D0 36B5851F */  ori       $s5, $s5, 0x851f
/* 3D1764 E00CC0D4 24130001 */  addiu     $s3, $zero, 1
/* 3D1768 E00CC0D8 0060802D */  daddu     $s0, $v1, $zero
/* 3D176C E00CC0DC 0240882D */  daddu     $s1, $s2, $zero
/* 3D1770 E00CC0E0 3C014170 */  lui       $at, 0x4170
/* 3D1774 E00CC0E4 4481D000 */  mtc1      $at, $f26
/* 3D1778 E00CC0E8 3C0142F0 */  lui       $at, 0x42f0
/* 3D177C E00CC0EC 4481C000 */  mtc1      $at, $f24
/* 3D1780 E00CC0F0 240200FF */  addiu     $v0, $zero, 0xff
/* 3D1784 E00CC0F4 AE020024 */  sw        $v0, 0x24($s0)
/* 3D1788 E00CC0F8 E6140004 */  swc1      $f20, 4($s0)
/* 3D178C E00CC0FC E6160008 */  swc1      $f22, 8($s0)
/* 3D1790 E00CC100 E61C000C */  swc1      $f28, 0xc($s0)
/* 3D1794 E00CC104 C7A00080 */  lwc1      $f0, 0x80($sp)
/* 3D1798 E00CC108 24020046 */  addiu     $v0, $zero, 0x46
/* 3D179C E00CC10C AE020018 */  sw        $v0, 0x18($s0)
/* 3D17A0 E00CC110 240200B4 */  addiu     $v0, $zero, 0xb4
/* 3D17A4 E00CC114 AE02001C */  sw        $v0, 0x1c($s0)
/* 3D17A8 E00CC118 24020078 */  addiu     $v0, $zero, 0x78
/* 3D17AC E00CC11C AE020020 */  sw        $v0, 0x20($s0)
/* 3D17B0 E00CC120 E6000028 */  swc1      $f0, 0x28($s0)
.LE00CC124:
/* 3D17B4 E00CC124 02350018 */  mult      $s1, $s5
/* 3D17B8 E00CC128 00111FC3 */  sra       $v1, $s1, 0x1f
/* 3D17BC E00CC12C 00004010 */  mfhi      $t0
/* 3D17C0 E00CC130 000810C3 */  sra       $v0, $t0, 3
/* 3D17C4 E00CC134 00431023 */  subu      $v0, $v0, $v1
/* 3D17C8 E00CC138 4482A000 */  mtc1      $v0, $f20
/* 3D17CC E00CC13C 00000000 */  nop
/* 3D17D0 E00CC140 4680A520 */  cvt.s.w   $f20, $f20
/* 3D17D4 E00CC144 0C080140 */  jal       shim_sin_deg
/* 3D17D8 E00CC148 4600A306 */   mov.s    $f12, $f20
/* 3D17DC E00CC14C 4600A306 */  mov.s     $f12, $f20
/* 3D17E0 E00CC150 0C080144 */  jal       shim_cos_deg
/* 3D17E4 E00CC154 46000506 */   mov.s    $f20, $f0
/* 3D17E8 E00CC158 24040167 */  addiu     $a0, $zero, 0x167
/* 3D17EC E00CC15C 0C080138 */  jal       shim_rand_int
/* 3D17F0 E00CC160 46000586 */   mov.s    $f22, $f0
/* 3D17F4 E00CC164 461AA082 */  mul.s     $f2, $f20, $f26
/* 3D17F8 E00CC168 00000000 */  nop
/* 3D17FC E00CC16C 461AB102 */  mul.s     $f4, $f22, $f26
/* 3D1800 E00CC170 00000000 */  nop
/* 3D1804 E00CC174 2442FF4C */  addiu     $v0, $v0, -0xb4
/* 3D1808 E00CC178 44820000 */  mtc1      $v0, $f0
/* 3D180C E00CC17C 00000000 */  nop
/* 3D1810 E00CC180 46800020 */  cvt.s.w   $f0, $f0
/* 3D1814 E00CC184 3C03E00D */  lui       $v1, %hi(D_E00CCE4C)
/* 3D1818 E00CC188 2463CE4C */  addiu     $v1, $v1, %lo(D_E00CCE4C)
/* 3D181C E00CC18C 02431821 */  addu      $v1, $s2, $v1
/* 3D1820 E00CC190 4618A502 */  mul.s     $f20, $f20, $f24
/* 3D1824 E00CC194 00000000 */  nop
/* 3D1828 E00CC198 26310438 */  addiu     $s1, $s1, 0x438
/* 3D182C E00CC19C E6000478 */  swc1      $f0, 0x478($s0)
/* 3D1830 E00CC1A0 E6020284 */  swc1      $f2, 0x284($s0)
/* 3D1834 E00CC1A4 80620000 */  lb        $v0, ($v1)
/* 3D1838 E00CC1A8 4618B582 */  mul.s     $f22, $f22, $f24
/* 3D183C E00CC1AC 00000000 */  nop
/* 3D1840 E00CC1B0 E604034C */  swc1      $f4, 0x34c($s0)
/* 3D1844 E00CC1B4 E6140158 */  swc1      $f20, 0x158($s0)
/* 3D1848 E00CC1B8 2442000A */  addiu     $v0, $v0, 0xa
/* 3D184C E00CC1BC 44820000 */  mtc1      $v0, $f0
/* 3D1850 E00CC1C0 00000000 */  nop
/* 3D1854 E00CC1C4 46800020 */  cvt.s.w   $f0, $f0
/* 3D1858 E00CC1C8 E60002E8 */  swc1      $f0, 0x2e8($s0)
/* 3D185C E00CC1CC 80620000 */  lb        $v0, ($v1)
/* 3D1860 E00CC1D0 26520001 */  addiu     $s2, $s2, 1
/* 3D1864 E00CC1D4 AE13066C */  sw        $s3, 0x66c($s0)
/* 3D1868 E00CC1D8 26730002 */  addiu     $s3, $s3, 2
/* 3D186C E00CC1DC E6160220 */  swc1      $f22, 0x220($s0)
/* 3D1870 E00CC1E0 AE0005A4 */  sw        $zero, 0x5a4($s0)
/* 3D1874 E00CC1E4 AE0006D0 */  sw        $zero, 0x6d0($s0)
/* 3D1878 E00CC1E8 AE000734 */  sw        $zero, 0x734($s0)
/* 3D187C E00CC1EC AE0004DC */  sw        $zero, 0x4dc($s0)
/* 3D1880 E00CC1F0 000210C0 */  sll       $v0, $v0, 3
/* 3D1884 E00CC1F4 24420028 */  addiu     $v0, $v0, 0x28
/* 3D1888 E00CC1F8 44820000 */  mtc1      $v0, $f0
/* 3D188C E00CC1FC 00000000 */  nop
/* 3D1890 E00CC200 46800020 */  cvt.s.w   $f0, $f0
/* 3D1894 E00CC204 E60001BC */  swc1      $f0, 0x1bc($s0)
/* 3D1898 E00CC208 2A420019 */  slti      $v0, $s2, 0x19
/* 3D189C E00CC20C 1440FFC5 */  bnez      $v0, .LE00CC124
/* 3D18A0 E00CC210 26100004 */   addiu    $s0, $s0, 4
/* 3D18A4 E00CC214 0280102D */  daddu     $v0, $s4, $zero
/* 3D18A8 E00CC218 8FBF0040 */  lw        $ra, 0x40($sp)
/* 3D18AC E00CC21C 8FB5003C */  lw        $s5, 0x3c($sp)
/* 3D18B0 E00CC220 8FB40038 */  lw        $s4, 0x38($sp)
/* 3D18B4 E00CC224 8FB30034 */  lw        $s3, 0x34($sp)
/* 3D18B8 E00CC228 8FB20030 */  lw        $s2, 0x30($sp)
/* 3D18BC E00CC22C 8FB1002C */  lw        $s1, 0x2c($sp)
/* 3D18C0 E00CC230 8FB00028 */  lw        $s0, 0x28($sp)
/* 3D18C4 E00CC234 D7BC0068 */  ldc1      $f28, 0x68($sp)
/* 3D18C8 E00CC238 D7BA0060 */  ldc1      $f26, 0x60($sp)
/* 3D18CC E00CC23C D7B80058 */  ldc1      $f24, 0x58($sp)
/* 3D18D0 E00CC240 D7B60050 */  ldc1      $f22, 0x50($sp)
/* 3D18D4 E00CC244 D7B40048 */  ldc1      $f20, 0x48($sp)
/* 3D18D8 E00CC248 03E00008 */  jr        $ra
/* 3D18DC E00CC24C 27BD0070 */   addiu    $sp, $sp, 0x70
