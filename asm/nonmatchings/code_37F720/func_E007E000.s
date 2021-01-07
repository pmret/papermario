.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E007E000
/* 37F720 E007E000 27BDFF98 */  addiu     $sp, $sp, -0x68
/* 37F724 E007E004 F7B40050 */  sdc1      $f20, 0x50($sp)
/* 37F728 E007E008 4485A000 */  mtc1      $a1, $f20
/* 37F72C E007E00C AFB00028 */  sw        $s0, 0x28($sp)
/* 37F730 E007E010 0080802D */  daddu     $s0, $a0, $zero
/* 37F734 E007E014 F7B60058 */  sdc1      $f22, 0x58($sp)
/* 37F738 E007E018 4486B000 */  mtc1      $a2, $f22
/* 37F73C E007E01C 27A40010 */  addiu     $a0, $sp, 0x10
/* 37F740 E007E020 F7B80060 */  sdc1      $f24, 0x60($sp)
/* 37F744 E007E024 4487C000 */  mtc1      $a3, $f24
/* 37F748 E007E028 3C02E008 */  lui       $v0, %hi(D_E007E1FC)
/* 37F74C E007E02C 2442E1FC */  addiu     $v0, $v0, %lo(D_E007E1FC)
/* 37F750 E007E030 AFA20018 */  sw        $v0, 0x18($sp)
/* 37F754 E007E034 3C02E008 */  lui       $v0, %hi(D_E007E204)
/* 37F758 E007E038 2442E204 */  addiu     $v0, $v0, %lo(D_E007E204)
/* 37F75C E007E03C AFA2001C */  sw        $v0, 0x1c($sp)
/* 37F760 E007E040 3C02E008 */  lui       $v0, %hi(D_E007E508)
/* 37F764 E007E044 2442E508 */  addiu     $v0, $v0, %lo(D_E007E508)
/* 37F768 E007E048 AFA20020 */  sw        $v0, 0x20($sp)
/* 37F76C E007E04C 2402003F */  addiu     $v0, $zero, 0x3f
/* 37F770 E007E050 AFBF0048 */  sw        $ra, 0x48($sp)
/* 37F774 E007E054 AFB70044 */  sw        $s7, 0x44($sp)
/* 37F778 E007E058 AFB60040 */  sw        $s6, 0x40($sp)
/* 37F77C E007E05C AFB5003C */  sw        $s5, 0x3c($sp)
/* 37F780 E007E060 AFB40038 */  sw        $s4, 0x38($sp)
/* 37F784 E007E064 AFB30034 */  sw        $s3, 0x34($sp)
/* 37F788 E007E068 AFB20030 */  sw        $s2, 0x30($sp)
/* 37F78C E007E06C AFB1002C */  sw        $s1, 0x2c($sp)
/* 37F790 E007E070 AFA00010 */  sw        $zero, 0x10($sp)
/* 37F794 E007E074 AFA00024 */  sw        $zero, 0x24($sp)
/* 37F798 E007E078 0C080124 */  jal       func_E0200490
/* 37F79C E007E07C AFA20014 */   sw       $v0, 0x14($sp)
/* 37F7A0 E007E080 24040934 */  addiu     $a0, $zero, 0x934
/* 37F7A4 E007E084 2414001F */  addiu     $s4, $zero, 0x1f
/* 37F7A8 E007E088 0040982D */  daddu     $s3, $v0, $zero
/* 37F7AC E007E08C 0C08012C */  jal       func_E02004B0
/* 37F7B0 E007E090 AE740008 */   sw       $s4, 8($s3)
/* 37F7B4 E007E094 0040882D */  daddu     $s1, $v0, $zero
/* 37F7B8 E007E098 16200003 */  bnez      $s1, .LE007E0A8
/* 37F7BC E007E09C AE71000C */   sw       $s1, 0xc($s3)
.LE007E0A0:
/* 37F7C0 E007E0A0 0801F828 */  j         .LE007E0A0
/* 37F7C4 E007E0A4 00000000 */   nop      
.LE007E0A8:
/* 37F7C8 E007E0A8 AE200004 */  sw        $zero, 4($s1)
/* 37F7CC E007E0AC AE300000 */  sw        $s0, ($s1)
/* 37F7D0 E007E0B0 E6340008 */  swc1      $f20, 8($s1)
/* 37F7D4 E007E0B4 E636000C */  swc1      $f22, 0xc($s1)
/* 37F7D8 E007E0B8 E6380010 */  swc1      $f24, 0x10($s1)
/* 37F7DC E007E0BC 8FA20078 */  lw        $v0, 0x78($sp)
/* 37F7E0 E007E0C0 3C013F00 */  lui       $at, 0x3f00
/* 37F7E4 E007E0C4 44810000 */  mtc1      $at, $f0
/* 37F7E8 E007E0C8 3C01C120 */  lui       $at, 0xc120
/* 37F7EC E007E0CC 44811000 */  mtc1      $at, $f2
/* 37F7F0 E007E0D0 24120001 */  addiu     $s2, $zero, 1
/* 37F7F4 E007E0D4 AE200044 */  sw        $zero, 0x44($s1)
/* 37F7F8 E007E0D8 AE200034 */  sw        $zero, 0x34($s1)
/* 37F7FC E007E0DC AE200038 */  sw        $zero, 0x38($s1)
/* 37F800 E007E0E0 AE200028 */  sw        $zero, 0x28($s1)
/* 37F804 E007E0E4 AE220040 */  sw        $v0, 0x40($s1)
/* 37F808 E007E0E8 240200FF */  addiu     $v0, $zero, 0xff
/* 37F80C E007E0EC AE22003C */  sw        $v0, 0x3c($s1)
/* 37F810 E007E0F0 E6200030 */  swc1      $f0, 0x30($s1)
/* 37F814 E007E0F4 E622002C */  swc1      $f2, 0x2c($s1)
/* 37F818 E007E0F8 0254102A */  slt       $v0, $s2, $s4
/* 37F81C E007E0FC 10400030 */  beqz      $v0, .LE007E1C0
/* 37F820 E007E100 2631004C */   addiu    $s1, $s1, 0x4c
/* 37F824 E007E104 0240B82D */  daddu     $s7, $s2, $zero
/* 37F828 E007E108 241600FF */  addiu     $s6, $zero, 0xff
/* 37F82C E007E10C 2415000A */  addiu     $s5, $zero, 0xa
/* 37F830 E007E110 26300040 */  addiu     $s0, $s1, 0x40
/* 37F834 E007E114 3C014100 */  lui       $at, 0x4100
/* 37F838 E007E118 4481B000 */  mtc1      $at, $f22
/* 37F83C E007E11C 3C01E008 */  lui       $at, %hi(D_E007EC40)
/* 37F840 E007E120 D434EC40 */  ldc1      $f20, %lo(D_E007EC40)($at)
.LE007E124:
/* 37F844 E007E124 24040014 */  addiu     $a0, $zero, 0x14
/* 37F848 E007E128 AE370000 */  sw        $s7, ($s1)
/* 37F84C E007E12C AE00FFC8 */  sw        $zero, -0x38($s0)
/* 37F850 E007E130 AE00FFCC */  sw        $zero, -0x34($s0)
/* 37F854 E007E134 AE00FFD0 */  sw        $zero, -0x30($s0)
/* 37F858 E007E138 E616FFD4 */  swc1      $f22, -0x2c($s0)
/* 37F85C E007E13C 0C080000 */  jal       func_E0200000
/* 37F860 E007E140 AE00FFD8 */   sw       $zero, -0x28($s0)
/* 37F864 E007E144 2404000A */  addiu     $a0, $zero, 0xa
/* 37F868 E007E148 2442FFF8 */  addiu     $v0, $v0, -8
/* 37F86C E007E14C 44820000 */  mtc1      $v0, $f0
/* 37F870 E007E150 00000000 */  nop       
/* 37F874 E007E154 46800020 */  cvt.s.w   $f0, $f0
/* 37F878 E007E158 0C080000 */  jal       func_E0200000
/* 37F87C E007E15C E600FFDC */   swc1     $f0, -0x24($s0)
/* 37F880 E007E160 2442FFFB */  addiu     $v0, $v0, -5
/* 37F884 E007E164 44820000 */  mtc1      $v0, $f0
/* 37F888 E007E168 00000000 */  nop       
/* 37F88C E007E16C 46800021 */  cvt.d.w   $f0, $f0
/* 37F890 E007E170 46340002 */  mul.d     $f0, $f0, $f20
/* 37F894 E007E174 00000000 */  nop       
/* 37F898 E007E178 24040050 */  addiu     $a0, $zero, 0x50
/* 37F89C E007E17C 2631004C */  addiu     $s1, $s1, 0x4c
/* 37F8A0 E007E180 46200020 */  cvt.s.d   $f0, $f0
/* 37F8A4 E007E184 0C080000 */  jal       func_E0200000
/* 37F8A8 E007E188 E600FFE0 */   swc1     $f0, -0x20($s0)
/* 37F8AC E007E18C 2643FFFF */  addiu     $v1, $s2, -1
/* 37F8B0 E007E190 26520001 */  addiu     $s2, $s2, 1
/* 37F8B4 E007E194 24420005 */  addiu     $v0, $v0, 5
/* 37F8B8 E007E198 44820000 */  mtc1      $v0, $f0
/* 37F8BC E007E19C 00000000 */  nop       
/* 37F8C0 E007E1A0 46800020 */  cvt.s.w   $f0, $f0
/* 37F8C4 E007E1A4 E600FFE4 */  swc1      $f0, -0x1c($s0)
/* 37F8C8 E007E1A8 AE16FFFC */  sw        $s6, -4($s0)
/* 37F8CC E007E1AC AE030008 */  sw        $v1, 8($s0)
/* 37F8D0 E007E1B0 AE150000 */  sw        $s5, ($s0)
/* 37F8D4 E007E1B4 0254102A */  slt       $v0, $s2, $s4
/* 37F8D8 E007E1B8 1440FFDA */  bnez      $v0, .LE007E124
/* 37F8DC E007E1BC 2610004C */   addiu    $s0, $s0, 0x4c
.LE007E1C0:
/* 37F8E0 E007E1C0 0260102D */  daddu     $v0, $s3, $zero
/* 37F8E4 E007E1C4 8FBF0048 */  lw        $ra, 0x48($sp)
/* 37F8E8 E007E1C8 8FB70044 */  lw        $s7, 0x44($sp)
/* 37F8EC E007E1CC 8FB60040 */  lw        $s6, 0x40($sp)
/* 37F8F0 E007E1D0 8FB5003C */  lw        $s5, 0x3c($sp)
/* 37F8F4 E007E1D4 8FB40038 */  lw        $s4, 0x38($sp)
/* 37F8F8 E007E1D8 8FB30034 */  lw        $s3, 0x34($sp)
/* 37F8FC E007E1DC 8FB20030 */  lw        $s2, 0x30($sp)
/* 37F900 E007E1E0 8FB1002C */  lw        $s1, 0x2c($sp)
/* 37F904 E007E1E4 8FB00028 */  lw        $s0, 0x28($sp)
/* 37F908 E007E1E8 D7B80060 */  ldc1      $f24, 0x60($sp)
/* 37F90C E007E1EC D7B60058 */  ldc1      $f22, 0x58($sp)
/* 37F910 E007E1F0 D7B40050 */  ldc1      $f20, 0x50($sp)
/* 37F914 E007E1F4 03E00008 */  jr        $ra
/* 37F918 E007E1F8 27BD0068 */   addiu    $sp, $sp, 0x68
