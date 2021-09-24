.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_11_main
/* 32EE30 E0016000 27BDFF90 */  addiu     $sp, $sp, -0x70
/* 32EE34 E0016004 F7B80058 */  sdc1      $f24, 0x58($sp)
/* 32EE38 E0016008 4485C000 */  mtc1      $a1, $f24
/* 32EE3C E001600C AFB5003C */  sw        $s5, 0x3c($sp)
/* 32EE40 E0016010 0080A82D */  daddu     $s5, $a0, $zero
/* 32EE44 E0016014 F7BA0060 */  sdc1      $f26, 0x60($sp)
/* 32EE48 E0016018 4486D000 */  mtc1      $a2, $f26
/* 32EE4C E001601C 27A40010 */  addiu     $a0, $sp, 0x10
/* 32EE50 E0016020 F7BC0068 */  sdc1      $f28, 0x68($sp)
/* 32EE54 E0016024 4487E000 */  mtc1      $a3, $f28
/* 32EE58 E0016028 3C02E001 */  lui       $v0, %hi(func_E0016220)
/* 32EE5C E001602C 24426220 */  addiu     $v0, $v0, %lo(func_E0016220)
/* 32EE60 E0016030 AFA20018 */  sw        $v0, 0x18($sp)
/* 32EE64 E0016034 3C02E001 */  lui       $v0, %hi(func_E0016228)
/* 32EE68 E0016038 24426228 */  addiu     $v0, $v0, %lo(func_E0016228)
/* 32EE6C E001603C AFA2001C */  sw        $v0, 0x1c($sp)
/* 32EE70 E0016040 3C02E001 */  lui       $v0, %hi(func_E0016410)
/* 32EE74 E0016044 24426410 */  addiu     $v0, $v0, %lo(func_E0016410)
/* 32EE78 E0016048 AFA20020 */  sw        $v0, 0x20($sp)
/* 32EE7C E001604C 2402000B */  addiu     $v0, $zero, 0xb
/* 32EE80 E0016050 AFBF0044 */  sw        $ra, 0x44($sp)
/* 32EE84 E0016054 AFB60040 */  sw        $s6, 0x40($sp)
/* 32EE88 E0016058 AFB40038 */  sw        $s4, 0x38($sp)
/* 32EE8C E001605C AFB30034 */  sw        $s3, 0x34($sp)
/* 32EE90 E0016060 AFB20030 */  sw        $s2, 0x30($sp)
/* 32EE94 E0016064 AFB1002C */  sw        $s1, 0x2c($sp)
/* 32EE98 E0016068 AFB00028 */  sw        $s0, 0x28($sp)
/* 32EE9C E001606C F7B60050 */  sdc1      $f22, 0x50($sp)
/* 32EEA0 E0016070 F7B40048 */  sdc1      $f20, 0x48($sp)
/* 32EEA4 E0016074 AFA00010 */  sw        $zero, 0x10($sp)
/* 32EEA8 E0016078 AFA00024 */  sw        $zero, 0x24($sp)
/* 32EEAC E001607C 0C080124 */  jal       shim_create_effect_instance
/* 32EEB0 E0016080 AFA20014 */   sw       $v0, 0x14($sp)
/* 32EEB4 E0016084 24040050 */  addiu     $a0, $zero, 0x50
/* 32EEB8 E0016088 24130001 */  addiu     $s3, $zero, 1
/* 32EEBC E001608C 0040802D */  daddu     $s0, $v0, $zero
/* 32EEC0 E0016090 0C08012C */  jal       shim_general_heap_malloc
/* 32EEC4 E0016094 AE130008 */   sw       $s3, 8($s0)
/* 32EEC8 E0016098 0040882D */  daddu     $s1, $v0, $zero
/* 32EECC E001609C 16200003 */  bnez      $s1, .LE00160AC
/* 32EED0 E00160A0 AE11000C */   sw       $s1, 0xc($s0)
.LE00160A4:
/* 32EED4 E00160A4 08005829 */  j         .LE00160A4
/* 32EED8 E00160A8 00000000 */   nop
.LE00160AC:
/* 32EEDC E00160AC 0220202D */  daddu     $a0, $s1, $zero
/* 32EEE0 E00160B0 00132880 */  sll       $a1, $s3, 2
/* 32EEE4 E00160B4 00B32821 */  addu      $a1, $a1, $s3
/* 32EEE8 E00160B8 0C080130 */  jal       shim_mem_clear
/* 32EEEC E00160BC 00052900 */   sll      $a1, $a1, 4
/* 32EEF0 E00160C0 0000902D */  daddu     $s2, $zero, $zero
/* 32EEF4 E00160C4 0253102A */  slt       $v0, $s2, $s3
/* 32EEF8 E00160C8 10400046 */  beqz      $v0, .LE00161E4
/* 32EEFC E00160CC 24160001 */   addiu    $s6, $zero, 1
/* 32EF00 E00160D0 241400FF */  addiu     $s4, $zero, 0xff
/* 32EF04 E00160D4 26300008 */  addiu     $s0, $s1, 8
/* 32EF08 E00160D8 3C013F80 */  lui       $at, 0x3f80
/* 32EF0C E00160DC 4481B000 */  mtc1      $at, $f22
/* 32EF10 E00160E0 3C01E001 */  lui       $at, %hi(D_E0016720)
/* 32EF14 E00160E4 D4346720 */  ldc1      $f20, %lo(D_E0016720)($at)
.LE00160E8:
/* 32EF18 E00160E8 2404000A */  addiu     $a0, $zero, 0xa
/* 32EF1C E00160EC AE360000 */  sw        $s6, ($s1)
/* 32EF20 E00160F0 A615FFFC */  sh        $s5, -4($s0)
/* 32EF24 E00160F4 AE000038 */  sw        $zero, 0x38($s0)
/* 32EF28 E00160F8 AE00003C */  sw        $zero, 0x3c($s0)
/* 32EF2C E00160FC E6180004 */  swc1      $f24, 4($s0)
/* 32EF30 E0016100 E61A0008 */  swc1      $f26, 8($s0)
/* 32EF34 E0016104 E61C000C */  swc1      $f28, 0xc($s0)
/* 32EF38 E0016108 E6160014 */  swc1      $f22, 0x14($s0)
/* 32EF3C E001610C E6160018 */  swc1      $f22, 0x18($s0)
/* 32EF40 E0016110 E616001C */  swc1      $f22, 0x1c($s0)
/* 32EF44 E0016114 0C080138 */  jal       shim_rand_int
/* 32EF48 E0016118 A2140000 */   sb       $s4, ($s0)
/* 32EF4C E001611C 44820000 */  mtc1      $v0, $f0
/* 32EF50 E0016120 00000000 */  nop
/* 32EF54 E0016124 46800021 */  cvt.d.w   $f0, $f0
/* 32EF58 E0016128 46340002 */  mul.d     $f0, $f0, $f20
/* 32EF5C E001612C 00000000 */  nop
/* 32EF60 E0016130 3C01E001 */  lui       $at, %hi(D_E0016728)
/* 32EF64 E0016134 D4226728 */  ldc1      $f2, %lo(D_E0016728)($at)
/* 32EF68 E0016138 46220000 */  add.d     $f0, $f0, $f2
/* 32EF6C E001613C 2404000A */  addiu     $a0, $zero, 0xa
/* 32EF70 E0016140 46200020 */  cvt.s.d   $f0, $f0
/* 32EF74 E0016144 0C080138 */  jal       shim_rand_int
/* 32EF78 E0016148 E6000020 */   swc1     $f0, 0x20($s0)
/* 32EF7C E001614C 44820000 */  mtc1      $v0, $f0
/* 32EF80 E0016150 00000000 */  nop
/* 32EF84 E0016154 46800021 */  cvt.d.w   $f0, $f0
/* 32EF88 E0016158 46340002 */  mul.d     $f0, $f0, $f20
/* 32EF8C E001615C 00000000 */  nop
/* 32EF90 E0016160 3C013FF8 */  lui       $at, 0x3ff8
/* 32EF94 E0016164 44811800 */  mtc1      $at, $f3
/* 32EF98 E0016168 44801000 */  mtc1      $zero, $f2
/* 32EF9C E001616C 26520001 */  addiu     $s2, $s2, 1
/* 32EFA0 E0016170 46220000 */  add.d     $f0, $f0, $f2
/* 32EFA4 E0016174 26310050 */  addiu     $s1, $s1, 0x50
/* 32EFA8 E0016178 2404003C */  addiu     $a0, $zero, 0x3c
/* 32EFAC E001617C 46200020 */  cvt.s.d   $f0, $f0
/* 32EFB0 E0016180 0C080000 */  jal       func_E0200000
/* 32EFB4 E0016184 E6000024 */   swc1     $f0, 0x24($s0)
/* 32EFB8 E0016188 24040168 */  addiu     $a0, $zero, 0x168
/* 32EFBC E001618C 44820000 */  mtc1      $v0, $f0
/* 32EFC0 E0016190 00000000 */  nop
/* 32EFC4 E0016194 46800020 */  cvt.s.w   $f0, $f0
/* 32EFC8 E0016198 E6000028 */  swc1      $f0, 0x28($s0)
/* 32EFCC E001619C 3C014000 */  lui       $at, 0x4000
/* 32EFD0 E00161A0 44810000 */  mtc1      $at, $f0
/* 32EFD4 E00161A4 3C01BF00 */  lui       $at, 0xbf00
/* 32EFD8 E00161A8 44811000 */  mtc1      $at, $f2
/* 32EFDC E00161AC 2402000F */  addiu     $v0, $zero, 0xf
/* 32EFE0 E00161B0 A615FFFC */  sh        $s5, -4($s0)
/* 32EFE4 E00161B4 A602FFFE */  sh        $v0, -2($s0)
/* 32EFE8 E00161B8 E6000030 */  swc1      $f0, 0x30($s0)
/* 32EFEC E00161BC 0C080000 */  jal       func_E0200000
/* 32EFF0 E00161C0 E6020034 */   swc1     $f2, 0x34($s0)
/* 32EFF4 E00161C4 44820000 */  mtc1      $v0, $f0
/* 32EFF8 E00161C8 00000000 */  nop
/* 32EFFC E00161CC 46800020 */  cvt.s.w   $f0, $f0
/* 32F000 E00161D0 E6000010 */  swc1      $f0, 0x10($s0)
/* 32F004 E00161D4 A2140000 */  sb        $s4, ($s0)
/* 32F008 E00161D8 0253102A */  slt       $v0, $s2, $s3
/* 32F00C E00161DC 1440FFC2 */  bnez      $v0, .LE00160E8
/* 32F010 E00161E0 26100050 */   addiu    $s0, $s0, 0x50
.LE00161E4:
/* 32F014 E00161E4 8FBF0044 */  lw        $ra, 0x44($sp)
/* 32F018 E00161E8 8FB60040 */  lw        $s6, 0x40($sp)
/* 32F01C E00161EC 8FB5003C */  lw        $s5, 0x3c($sp)
/* 32F020 E00161F0 8FB40038 */  lw        $s4, 0x38($sp)
/* 32F024 E00161F4 8FB30034 */  lw        $s3, 0x34($sp)
/* 32F028 E00161F8 8FB20030 */  lw        $s2, 0x30($sp)
/* 32F02C E00161FC 8FB1002C */  lw        $s1, 0x2c($sp)
/* 32F030 E0016200 8FB00028 */  lw        $s0, 0x28($sp)
/* 32F034 E0016204 D7BC0068 */  ldc1      $f28, 0x68($sp)
/* 32F038 E0016208 D7BA0060 */  ldc1      $f26, 0x60($sp)
/* 32F03C E001620C D7B80058 */  ldc1      $f24, 0x58($sp)
/* 32F040 E0016210 D7B60050 */  ldc1      $f22, 0x50($sp)
/* 32F044 E0016214 D7B40048 */  ldc1      $f20, 0x48($sp)
/* 32F048 E0016218 03E00008 */  jr        $ra
/* 32F04C E001621C 27BD0070 */   addiu    $sp, $sp, 0x70
