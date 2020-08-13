.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80138740
/* 0CEE40 80138740 27BDFFB8 */  addiu $sp, $sp, -0x48
/* 0CEE44 80138744 AFB50034 */  sw    $s5, 0x34($sp)
/* 0CEE48 80138748 0080A82D */  daddu $s5, $a0, $zero
/* 0CEE4C 8013874C AFB40030 */  sw    $s4, 0x30($sp)
/* 0CEE50 80138750 00C0A02D */  daddu $s4, $a2, $zero
/* 0CEE54 80138754 0000C02D */  daddu $t8, $zero, $zero
/* 0CEE58 80138758 C7A00058 */  lwc1  $f0, 0x58($sp)
/* 0CEE5C 8013875C 02A0102D */  daddu $v0, $s5, $zero
/* 0CEE60 80138760 AFBF0044 */  sw    $ra, 0x44($sp)
/* 0CEE64 80138764 AFBE0040 */  sw    $fp, 0x40($sp)
/* 0CEE68 80138768 AFB7003C */  sw    $s7, 0x3c($sp)
/* 0CEE6C 8013876C AFB60038 */  sw    $s6, 0x38($sp)
/* 0CEE70 80138770 AFB3002C */  sw    $s3, 0x2c($sp)
/* 0CEE74 80138774 AFB20028 */  sw    $s2, 0x28($sp)
/* 0CEE78 80138778 AFB10024 */  sw    $s1, 0x24($sp)
/* 0CEE7C 8013877C AFB00020 */  sw    $s0, 0x20($sp)
/* 0CEE80 80138780 06A10002 */  bgez  $s5, .L8013878C
/* 0CEE84 80138784 AFA5004C */   sw    $a1, 0x4c($sp)
/* 0CEE88 80138788 26A20003 */  addiu $v0, $s5, 3
.L8013878C:
/* 0CEE8C 8013878C 00021083 */  sra   $v0, $v0, 2
/* 0CEE90 80138790 0002A880 */  sll   $s5, $v0, 2
/* 0CEE94 80138794 06810002 */  bgez  $s4, .L801387A0
/* 0CEE98 80138798 0280102D */   daddu $v0, $s4, $zero
/* 0CEE9C 8013879C 26820003 */  addiu $v0, $s4, 3
.L801387A0:
/* 0CEEA0 801387A0 3C032AAA */  lui   $v1, 0x2aaa
/* 0CEEA4 801387A4 3463AAAB */  ori   $v1, $v1, 0xaaab
/* 0CEEA8 801387A8 00021083 */  sra   $v0, $v0, 2
/* 0CEEAC 801387AC 8FB9004C */  lw    $t9, 0x4c($sp)
/* 0CEEB0 801387B0 00021080 */  sll   $v0, $v0, 2
/* 0CEEB4 801387B4 00F92023 */  subu  $a0, $a3, $t9
/* 0CEEB8 801387B8 00830018 */  mult  $a0, $v1
/* 0CEEBC 801387BC 24540004 */  addiu $s4, $v0, 4
/* 0CEEC0 801387C0 0000902D */  daddu $s2, $zero, $zero
/* 0CEEC4 801387C4 3C058007 */  lui   $a1, 0x8007
/* 0CEEC8 801387C8 24A573F0 */  addiu $a1, $a1, 0x73f0
/* 0CEECC 801387CC 000417C3 */  sra   $v0, $a0, 0x1f
/* 0CEED0 801387D0 0000C810 */  mfhi  $t9
/* 0CEED4 801387D4 0322C823 */  subu  $t9, $t9, $v0
/* 0CEED8 801387D8 AFB90010 */  sw    $t9, 0x10($sp)
/* 0CEEDC 801387DC 0320B82D */  daddu $s7, $t9, $zero
/* 0CEEE0 801387E0 00171040 */  sll   $v0, $s7, 1
/* 0CEEE4 801387E4 00571021 */  addu  $v0, $v0, $s7
/* 0CEEE8 801387E8 00021040 */  sll   $v0, $v0, 1
/* 0CEEEC 801387EC 8CA30000 */  lw    $v1, ($a1)
/* 0CEEF0 801387F0 00822023 */  subu  $a0, $a0, $v0
/* 0CEEF4 801387F4 1060001A */  beqz  $v1, .L80138860
/* 0CEEF8 801387F8 AFA40010 */   sw    $a0, 0x10($sp)
/* 0CEEFC 801387FC 00A0382D */  daddu $a3, $a1, $zero
/* 0CEF00 80138800 3C05800A */  lui   $a1, 0x800a
/* 0CEF04 80138804 8CA5A658 */  lw    $a1, -0x59a8($a1)
/* 0CEF08 80138808 3C06800A */  lui   $a2, 0x800a
/* 0CEF0C 8013880C 8CC6A64C */  lw    $a2, -0x59b4($a2)
/* 0CEF10 80138810 00A0202D */  daddu $a0, $a1, $zero
.L80138814:
/* 0CEF14 80138814 8C820000 */  lw    $v0, ($a0)
/* 0CEF18 80138818 1446000B */  bne   $v0, $a2, .L80138848
/* 0CEF1C 8013881C 00000000 */   nop   
/* 0CEF20 80138820 8CE30000 */  lw    $v1, ($a3)
/* 0CEF24 80138824 02431021 */  addu  $v0, $s2, $v1
/* 0CEF28 80138828 2442FFFF */  addiu $v0, $v0, -1
/* 0CEF2C 8013882C 14600002 */  bnez  $v1, .L80138838
/* 0CEF30 80138830 0043001B */   divu  $zero, $v0, $v1
/* 0CEF34 80138834 0007000D */  break 7
.L80138838:
/* 0CEF38 80138838 00001810 */  mfhi  $v1
/* 0CEF3C 8013883C 00031880 */  sll   $v1, $v1, 2
/* 0CEF40 80138840 00651821 */  addu  $v1, $v1, $a1
/* 0CEF44 80138844 8C780000 */  lw    $t8, ($v1)
.L80138848:
/* 0CEF48 80138848 3C028007 */  lui   $v0, 0x8007
/* 0CEF4C 8013884C 8C4273F0 */  lw    $v0, 0x73f0($v0)
/* 0CEF50 80138850 26520001 */  addiu $s2, $s2, 1
/* 0CEF54 80138854 0242102B */  sltu  $v0, $s2, $v0
/* 0CEF58 80138858 1440FFEE */  bnez  $v0, .L80138814
/* 0CEF5C 8013885C 24840004 */   addiu $a0, $a0, 4
.L80138860:
/* 0CEF60 80138860 3C05E300 */  lui   $a1, 0xe300
/* 0CEF64 80138864 34A50A01 */  ori   $a1, $a1, 0xa01
/* 0CEF68 80138868 3C08FCFF */  lui   $t0, 0xfcff
/* 0CEF6C 8013886C 3508FFFF */  ori   $t0, $t0, 0xffff
/* 0CEF70 80138870 3C06FFFC */  lui   $a2, 0xfffc
/* 0CEF74 80138874 34C6F67B */  ori   $a2, $a2, 0xf67b
/* 0CEF78 80138878 3C09E200 */  lui   $t1, 0xe200
/* 0CEF7C 8013887C 3529001C */  ori   $t1, $t1, 0x1c
/* 0CEF80 80138880 3C070050 */  lui   $a3, 0x50
/* 0CEF84 80138884 34E74340 */  ori   $a3, $a3, 0x4340
/* 0CEF88 80138888 3C0AE300 */  lui   $t2, 0xe300
/* 0CEF8C 8013888C 354A1801 */  ori   $t2, $t2, 0x1801
/* 0CEF90 80138890 3C0BE300 */  lui   $t3, 0xe300
/* 0CEF94 80138894 356B1A01 */  ori   $t3, $t3, 0x1a01
/* 0CEF98 80138898 3C0CE300 */  lui   $t4, 0xe300
/* 0CEF9C 8013889C 358C1201 */  ori   $t4, $t4, 0x1201
/* 0CEFA0 801388A0 3C0DE300 */  lui   $t5, 0xe300
/* 0CEFA4 801388A4 35AD0C00 */  ori   $t5, $t5, 0xc00
/* 0CEFA8 801388A8 3C0ED700 */  lui   $t6, 0xd700
/* 0CEFAC 801388AC 35CE0002 */  ori   $t6, $t6, 2
/* 0CEFB0 801388B0 3C0FE300 */  lui   $t7, 0xe300
/* 0CEFB4 801388B4 35EF1001 */  ori   $t7, $t7, 0x1001
/* 0CEFB8 801388B8 3C10E300 */  lui   $s0, 0xe300
/* 0CEFBC 801388BC 36100D01 */  ori   $s0, $s0, 0xd01
/* 0CEFC0 801388C0 3C11E300 */  lui   $s1, 0xe300
/* 0CEFC4 801388C4 3C04800A */  lui   $a0, 0x800a
/* 0CEFC8 801388C8 2484A66C */  addiu $a0, $a0, -0x5994
/* 0CEFCC 801388CC 36310F00 */  ori   $s1, $s1, 0xf00
/* 0CEFD0 801388D0 8C820000 */  lw    $v0, ($a0)
/* 0CEFD4 801388D4 3C014F00 */  lui   $at, 0x4f00
/* 0CEFD8 801388D8 44811000 */  mtc1  $at, $f2
/* 0CEFDC 801388DC 0040182D */  daddu $v1, $v0, $zero
/* 0CEFE0 801388E0 24420008 */  addiu $v0, $v0, 8
/* 0CEFE4 801388E4 AC820000 */  sw    $v0, ($a0)
/* 0CEFE8 801388E8 AC650000 */  sw    $a1, ($v1)
/* 0CEFEC 801388EC AC600004 */  sw    $zero, 4($v1)
/* 0CEFF0 801388F0 24430008 */  addiu $v1, $v0, 8
/* 0CEFF4 801388F4 AC830000 */  sw    $v1, ($a0)
/* 0CEFF8 801388F8 24430010 */  addiu $v1, $v0, 0x10
/* 0CEFFC 801388FC AC480000 */  sw    $t0, ($v0)
/* 0CF000 80138900 AC460004 */  sw    $a2, 4($v0)
/* 0CF004 80138904 AC830000 */  sw    $v1, ($a0)
/* 0CF008 80138908 24430018 */  addiu $v1, $v0, 0x18
/* 0CF00C 8013890C AC490008 */  sw    $t1, 8($v0)
/* 0CF010 80138910 AC47000C */  sw    $a3, 0xc($v0)
/* 0CF014 80138914 AC830000 */  sw    $v1, ($a0)
/* 0CF018 80138918 240300C0 */  addiu $v1, $zero, 0xc0
/* 0CF01C 8013891C AC430014 */  sw    $v1, 0x14($v0)
/* 0CF020 80138920 24430020 */  addiu $v1, $v0, 0x20
/* 0CF024 80138924 AC4A0010 */  sw    $t2, 0x10($v0)
/* 0CF028 80138928 AC830000 */  sw    $v1, ($a0)
/* 0CF02C 8013892C 24030020 */  addiu $v1, $zero, 0x20
/* 0CF030 80138930 AC43001C */  sw    $v1, 0x1c($v0)
/* 0CF034 80138934 24430028 */  addiu $v1, $v0, 0x28
/* 0CF038 80138938 AC4B0018 */  sw    $t3, 0x18($v0)
/* 0CF03C 8013893C AC830000 */  sw    $v1, ($a0)
/* 0CF040 80138940 24430030 */  addiu $v1, $v0, 0x30
/* 0CF044 80138944 AC4C0020 */  sw    $t4, 0x20($v0)
/* 0CF048 80138948 AC400024 */  sw    $zero, 0x24($v0)
/* 0CF04C 8013894C AC830000 */  sw    $v1, ($a0)
/* 0CF050 80138950 24430038 */  addiu $v1, $v0, 0x38
/* 0CF054 80138954 AC4D0028 */  sw    $t5, 0x28($v0)
/* 0CF058 80138958 AC40002C */  sw    $zero, 0x2c($v0)
/* 0CF05C 8013895C AC830000 */  sw    $v1, ($a0)
/* 0CF060 80138960 2403FFFF */  addiu $v1, $zero, -1
/* 0CF064 80138964 AC430034 */  sw    $v1, 0x34($v0)
/* 0CF068 80138968 24430040 */  addiu $v1, $v0, 0x40
/* 0CF06C 8013896C AC4E0030 */  sw    $t6, 0x30($v0)
/* 0CF070 80138970 AC830000 */  sw    $v1, ($a0)
/* 0CF074 80138974 24430048 */  addiu $v1, $v0, 0x48
/* 0CF078 80138978 AC4F0038 */  sw    $t7, 0x38($v0)
/* 0CF07C 8013897C AC40003C */  sw    $zero, 0x3c($v0)
/* 0CF080 80138980 AC830000 */  sw    $v1, ($a0)
/* 0CF084 80138984 24430050 */  addiu $v1, $v0, 0x50
/* 0CF088 80138988 AC500040 */  sw    $s0, 0x40($v0)
/* 0CF08C 8013898C AC400044 */  sw    $zero, 0x44($v0)
/* 0CF090 80138990 AC830000 */  sw    $v1, ($a0)
/* 0CF094 80138994 24430058 */  addiu $v1, $v0, 0x58
/* 0CF098 80138998 AC510048 */  sw    $s1, 0x48($v0)
/* 0CF09C 8013899C AC40004C */  sw    $zero, 0x4c($v0)
/* 0CF0A0 801389A0 AC830000 */  sw    $v1, ($a0)
/* 0CF0A4 801389A4 3C03FA00 */  lui   $v1, 0xfa00
/* 0CF0A8 801389A8 24440054 */  addiu $a0, $v0, 0x54
/* 0CF0AC 801389AC 4600103E */  c.le.s $f2, $f0
/* 0CF0B0 801389B0 00000000 */  nop   
/* 0CF0B4 801389B4 45010005 */  bc1t  .L801389CC
/* 0CF0B8 801389B8 AC430050 */   sw    $v1, 0x50($v0)
/* 0CF0BC 801389BC 4600010D */  trunc.w.s $f4, $f0
/* 0CF0C0 801389C0 44032000 */  mfc1  $v1, $f4
/* 0CF0C4 801389C4 0804E27A */  j     .L801389E8
/* 0CF0C8 801389C8 2402FF00 */   addiu $v0, $zero, -0x100

.L801389CC:
/* 0CF0CC 801389CC 46020001 */  sub.s $f0, $f0, $f2
/* 0CF0D0 801389D0 3C028000 */  lui   $v0, 0x8000
/* 0CF0D4 801389D4 4600010D */  trunc.w.s $f4, $f0
/* 0CF0D8 801389D8 44032000 */  mfc1  $v1, $f4
/* 0CF0DC 801389DC 00000000 */  nop   
/* 0CF0E0 801389E0 00621825 */  or    $v1, $v1, $v0
/* 0CF0E4 801389E4 2402FF00 */  addiu $v0, $zero, -0x100
.L801389E8:
/* 0CF0E8 801389E8 00621025 */  or    $v0, $v1, $v0
/* 0CF0EC 801389EC AC820000 */  sw    $v0, ($a0)
/* 0CF0F0 801389F0 1AE0006D */  blez  $s7, .L80138BA8
/* 0CF0F4 801389F4 0000902D */   daddu $s2, $zero, $zero
/* 0CF0F8 801389F8 3C11800A */  lui   $s1, 0x800a
/* 0CF0FC 801389FC 2631A66C */  addiu $s1, $s1, -0x5994
/* 0CF100 80138A00 02951023 */  subu  $v0, $s4, $s5
/* 0CF104 80138A04 00021040 */  sll   $v0, $v0, 1
/* 0CF108 80138A08 24420007 */  addiu $v0, $v0, 7
/* 0CF10C 80138A0C 000210C3 */  sra   $v0, $v0, 3
/* 0CF110 80138A10 304201FF */  andi  $v0, $v0, 0x1ff
/* 0CF114 80138A14 00021240 */  sll   $v0, $v0, 9
/* 0CF118 80138A18 3C03F510 */  lui   $v1, 0xf510
/* 0CF11C 80138A1C 0043B025 */  or    $s6, $v0, $v1
/* 0CF120 80138A20 3C1E0700 */  lui   $fp, 0x700
/* 0CF124 80138A24 8FB3004C */  lw    $s3, 0x4c($sp)
/* 0CF128 80138A28 3C03FD10 */  lui   $v1, 0xfd10
.L80138A2C:
/* 0CF12C 80138A2C 3463013F */  ori   $v1, $v1, 0x13f
/* 0CF130 80138A30 0300202D */  daddu $a0, $t8, $zero
/* 0CF134 80138A34 8E220000 */  lw    $v0, ($s1)
/* 0CF138 80138A38 26520001 */  addiu $s2, $s2, 1
/* 0CF13C 80138A3C 0040802D */  daddu $s0, $v0, $zero
/* 0CF140 80138A40 24420008 */  addiu $v0, $v0, 8
/* 0CF144 80138A44 AE220000 */  sw    $v0, ($s1)
/* 0CF148 80138A48 AE030000 */  sw    $v1, ($s0)
/* 0CF14C 80138A4C 0C0187A4 */  jal   osVirtualToPhysical
/* 0CF150 80138A50 AFB80018 */   sw    $t8, 0x18($sp)
/* 0CF154 80138A54 3C090400 */  lui   $t1, 0x400
/* 0CF158 80138A58 35290400 */  ori   $t1, $t1, 0x400
/* 0CF15C 80138A5C 00133880 */  sll   $a3, $s3, 2
/* 0CF160 80138A60 26640005 */  addiu $a0, $s3, 5
/* 0CF164 80138A64 26630006 */  addiu $v1, $s3, 6
/* 0CF168 80138A68 00134140 */  sll   $t0, $s3, 5
/* 0CF16C 80138A6C 0060982D */  daddu $s3, $v1, $zero
/* 0CF170 80138A70 00153080 */  sll   $a2, $s5, 2
/* 0CF174 80138A74 30C60FFF */  andi  $a2, $a2, 0xfff
/* 0CF178 80138A78 00063300 */  sll   $a2, $a2, 0xc
/* 0CF17C 80138A7C 30E70FFF */  andi  $a3, $a3, 0xfff
/* 0CF180 80138A80 2683FFFF */  addiu $v1, $s4, -1
/* 0CF184 80138A84 00031880 */  sll   $v1, $v1, 2
/* 0CF188 80138A88 30630FFF */  andi  $v1, $v1, 0xfff
/* 0CF18C 80138A8C 00031B00 */  sll   $v1, $v1, 0xc
/* 0CF190 80138A90 00042080 */  sll   $a0, $a0, 2
/* 0CF194 80138A94 30840FFF */  andi  $a0, $a0, 0xfff
/* 0CF198 80138A98 8E250000 */  lw    $a1, ($s1)
/* 0CF19C 80138A9C 3108FFFF */  andi  $t0, $t0, 0xffff
/* 0CF1A0 80138AA0 AE020004 */  sw    $v0, 4($s0)
/* 0CF1A4 80138AA4 00A0102D */  daddu $v0, $a1, $zero
/* 0CF1A8 80138AA8 24A50008 */  addiu $a1, $a1, 8
/* 0CF1AC 80138AAC AE250000 */  sw    $a1, ($s1)
/* 0CF1B0 80138AB0 AC560000 */  sw    $s6, ($v0)
/* 0CF1B4 80138AB4 AC5E0004 */  sw    $fp, 4($v0)
/* 0CF1B8 80138AB8 24A20008 */  addiu $v0, $a1, 8
/* 0CF1BC 80138ABC AE220000 */  sw    $v0, ($s1)
/* 0CF1C0 80138AC0 3C02E600 */  lui   $v0, 0xe600
/* 0CF1C4 80138AC4 ACA20000 */  sw    $v0, ($a1)
/* 0CF1C8 80138AC8 24A20010 */  addiu $v0, $a1, 0x10
/* 0CF1CC 80138ACC ACA00004 */  sw    $zero, 4($a1)
/* 0CF1D0 80138AD0 AE220000 */  sw    $v0, ($s1)
/* 0CF1D4 80138AD4 3C02F400 */  lui   $v0, 0xf400
/* 0CF1D8 80138AD8 00E21025 */  or    $v0, $a3, $v0
/* 0CF1DC 80138ADC 00C21025 */  or    $v0, $a2, $v0
/* 0CF1E0 80138AE0 ACA20008 */  sw    $v0, 8($a1)
/* 0CF1E4 80138AE4 009E1025 */  or    $v0, $a0, $fp
/* 0CF1E8 80138AE8 00621025 */  or    $v0, $v1, $v0
/* 0CF1EC 80138AEC ACA2000C */  sw    $v0, 0xc($a1)
/* 0CF1F0 80138AF0 24A20018 */  addiu $v0, $a1, 0x18
/* 0CF1F4 80138AF4 AE220000 */  sw    $v0, ($s1)
/* 0CF1F8 80138AF8 3C02E700 */  lui   $v0, 0xe700
/* 0CF1FC 80138AFC ACA20010 */  sw    $v0, 0x10($a1)
/* 0CF200 80138B00 24A20020 */  addiu $v0, $a1, 0x20
/* 0CF204 80138B04 ACA00014 */  sw    $zero, 0x14($a1)
/* 0CF208 80138B08 AE220000 */  sw    $v0, ($s1)
/* 0CF20C 80138B0C 24A20028 */  addiu $v0, $a1, 0x28
/* 0CF210 80138B10 ACB60018 */  sw    $s6, 0x18($a1)
/* 0CF214 80138B14 ACA0001C */  sw    $zero, 0x1c($a1)
/* 0CF218 80138B18 AE220000 */  sw    $v0, ($s1)
/* 0CF21C 80138B1C 3C02F200 */  lui   $v0, 0xf200
/* 0CF220 80138B20 00E21025 */  or    $v0, $a3, $v0
/* 0CF224 80138B24 00C21025 */  or    $v0, $a2, $v0
/* 0CF228 80138B28 00641825 */  or    $v1, $v1, $a0
/* 0CF22C 80138B2C ACA20020 */  sw    $v0, 0x20($a1)
/* 0CF230 80138B30 24A20030 */  addiu $v0, $a1, 0x30
/* 0CF234 80138B34 ACA30024 */  sw    $v1, 0x24($a1)
/* 0CF238 80138B38 00141880 */  sll   $v1, $s4, 2
/* 0CF23C 80138B3C 30630FFF */  andi  $v1, $v1, 0xfff
/* 0CF240 80138B40 00031B00 */  sll   $v1, $v1, 0xc
/* 0CF244 80138B44 AE220000 */  sw    $v0, ($s1)
/* 0CF248 80138B48 00131080 */  sll   $v0, $s3, 2
/* 0CF24C 80138B4C 30420FFF */  andi  $v0, $v0, 0xfff
/* 0CF250 80138B50 3C04E400 */  lui   $a0, 0xe400
/* 0CF254 80138B54 00441025 */  or    $v0, $v0, $a0
/* 0CF258 80138B58 00621825 */  or    $v1, $v1, $v0
/* 0CF25C 80138B5C 00C73025 */  or    $a2, $a2, $a3
/* 0CF260 80138B60 24A20038 */  addiu $v0, $a1, 0x38
/* 0CF264 80138B64 ACA30028 */  sw    $v1, 0x28($a1)
/* 0CF268 80138B68 ACA6002C */  sw    $a2, 0x2c($a1)
/* 0CF26C 80138B6C AE220000 */  sw    $v0, ($s1)
/* 0CF270 80138B70 3C02E100 */  lui   $v0, 0xe100
/* 0CF274 80138B74 ACA20030 */  sw    $v0, 0x30($a1)
/* 0CF278 80138B78 00151540 */  sll   $v0, $s5, 0x15
/* 0CF27C 80138B7C 00481025 */  or    $v0, $v0, $t0
/* 0CF280 80138B80 ACA20034 */  sw    $v0, 0x34($a1)
/* 0CF284 80138B84 24A20040 */  addiu $v0, $a1, 0x40
/* 0CF288 80138B88 AE220000 */  sw    $v0, ($s1)
/* 0CF28C 80138B8C 3C02F100 */  lui   $v0, 0xf100
/* 0CF290 80138B90 ACA20038 */  sw    $v0, 0x38($a1)
/* 0CF294 80138B94 0257102A */  slt   $v0, $s2, $s7
/* 0CF298 80138B98 ACA9003C */  sw    $t1, 0x3c($a1)
/* 0CF29C 80138B9C 8FB80018 */  lw    $t8, 0x18($sp)
/* 0CF2A0 80138BA0 1440FFA2 */  bnez  $v0, .L80138A2C
/* 0CF2A4 80138BA4 3C03FD10 */   lui   $v1, 0xfd10
.L80138BA8:
/* 0CF2A8 80138BA8 8FB90010 */  lw    $t9, 0x10($sp)
/* 0CF2AC 80138BAC 1320006A */  beqz  $t9, .L80138D58
/* 0CF2B0 80138BB0 3C03FD10 */   lui   $v1, 0xfd10
/* 0CF2B4 80138BB4 3463013F */  ori   $v1, $v1, 0x13f
/* 0CF2B8 80138BB8 3C10800A */  lui   $s0, 0x800a
/* 0CF2BC 80138BBC 2610A66C */  addiu $s0, $s0, -0x5994
/* 0CF2C0 80138BC0 8E020000 */  lw    $v0, ($s0)
/* 0CF2C4 80138BC4 0300202D */  daddu $a0, $t8, $zero
/* 0CF2C8 80138BC8 0040882D */  daddu $s1, $v0, $zero
/* 0CF2CC 80138BCC 24420008 */  addiu $v0, $v0, 8
/* 0CF2D0 80138BD0 AE020000 */  sw    $v0, ($s0)
/* 0CF2D4 80138BD4 0C0187A4 */  jal   osVirtualToPhysical
/* 0CF2D8 80138BD8 AE230000 */   sw    $v1, ($s1)
/* 0CF2DC 80138BDC 3C0C0400 */  lui   $t4, 0x400
/* 0CF2E0 80138BE0 358C0400 */  ori   $t4, $t4, 0x400
/* 0CF2E4 80138BE4 02952823 */  subu  $a1, $s4, $s5
/* 0CF2E8 80138BE8 00052840 */  sll   $a1, $a1, 1
/* 0CF2EC 80138BEC 24A50007 */  addiu $a1, $a1, 7
/* 0CF2F0 80138BF0 000528C3 */  sra   $a1, $a1, 3
/* 0CF2F4 80138BF4 30A501FF */  andi  $a1, $a1, 0x1ff
/* 0CF2F8 80138BF8 8E040000 */  lw    $a0, ($s0)
/* 0CF2FC 80138BFC 00052A40 */  sll   $a1, $a1, 9
/* 0CF300 80138C00 AE220004 */  sw    $v0, 4($s1)
/* 0CF304 80138C04 3C02F510 */  lui   $v0, 0xf510
/* 0CF308 80138C08 00A22825 */  or    $a1, $a1, $v0
/* 0CF30C 80138C0C 3C0A0700 */  lui   $t2, 0x700
/* 0CF310 80138C10 00154880 */  sll   $t1, $s5, 2
/* 0CF314 80138C14 31290FFF */  andi  $t1, $t1, 0xfff
/* 0CF318 80138C18 00094B00 */  sll   $t1, $t1, 0xc
/* 0CF31C 80138C1C 00123840 */  sll   $a3, $s2, 1
/* 0CF320 80138C20 00F23821 */  addu  $a3, $a3, $s2
/* 0CF324 80138C24 00073840 */  sll   $a3, $a3, 1
/* 0CF328 80138C28 0080182D */  daddu $v1, $a0, $zero
/* 0CF32C 80138C2C 24840008 */  addiu $a0, $a0, 8
/* 0CF330 80138C30 24820008 */  addiu $v0, $a0, 8
/* 0CF334 80138C34 AE040000 */  sw    $a0, ($s0)
/* 0CF338 80138C38 AC650000 */  sw    $a1, ($v1)
/* 0CF33C 80138C3C AC6A0004 */  sw    $t2, 4($v1)
/* 0CF340 80138C40 AE020000 */  sw    $v0, ($s0)
/* 0CF344 80138C44 3C02E600 */  lui   $v0, 0xe600
/* 0CF348 80138C48 AC820000 */  sw    $v0, ($a0)
/* 0CF34C 80138C4C 24820010 */  addiu $v0, $a0, 0x10
/* 0CF350 80138C50 AC800004 */  sw    $zero, 4($a0)
/* 0CF354 80138C54 AE020000 */  sw    $v0, ($s0)
/* 0CF358 80138C58 3C02F400 */  lui   $v0, 0xf400
/* 0CF35C 80138C5C 2683FFFF */  addiu $v1, $s4, -1
/* 0CF360 80138C60 00031880 */  sll   $v1, $v1, 2
/* 0CF364 80138C64 30630FFF */  andi  $v1, $v1, 0xfff
/* 0CF368 80138C68 8FB9004C */  lw    $t9, 0x4c($sp)
/* 0CF36C 80138C6C 00031B00 */  sll   $v1, $v1, 0xc
/* 0CF370 80138C70 03273821 */  addu  $a3, $t9, $a3
/* 0CF374 80138C74 00075880 */  sll   $t3, $a3, 2
/* 0CF378 80138C78 316B0FFF */  andi  $t3, $t3, 0xfff
/* 0CF37C 80138C7C 01621025 */  or    $v0, $t3, $v0
/* 0CF380 80138C80 01221025 */  or    $v0, $t1, $v0
/* 0CF384 80138C84 AC820008 */  sw    $v0, 8($a0)
/* 0CF388 80138C88 8FB90010 */  lw    $t9, 0x10($sp)
/* 0CF38C 80138C8C 24820018 */  addiu $v0, $a0, 0x18
/* 0CF390 80138C90 00F93021 */  addu  $a2, $a3, $t9
/* 0CF394 80138C94 24C8FFFF */  addiu $t0, $a2, -1
/* 0CF398 80138C98 00084080 */  sll   $t0, $t0, 2
/* 0CF39C 80138C9C 31080FFF */  andi  $t0, $t0, 0xfff
/* 0CF3A0 80138CA0 010A5025 */  or    $t2, $t0, $t2
/* 0CF3A4 80138CA4 006A5025 */  or    $t2, $v1, $t2
/* 0CF3A8 80138CA8 AC8A000C */  sw    $t2, 0xc($a0)
/* 0CF3AC 80138CAC AE020000 */  sw    $v0, ($s0)
/* 0CF3B0 80138CB0 3C02E700 */  lui   $v0, 0xe700
/* 0CF3B4 80138CB4 AC820010 */  sw    $v0, 0x10($a0)
/* 0CF3B8 80138CB8 24820020 */  addiu $v0, $a0, 0x20
/* 0CF3BC 80138CBC AC800014 */  sw    $zero, 0x14($a0)
/* 0CF3C0 80138CC0 AE020000 */  sw    $v0, ($s0)
/* 0CF3C4 80138CC4 24820028 */  addiu $v0, $a0, 0x28
/* 0CF3C8 80138CC8 AC850018 */  sw    $a1, 0x18($a0)
/* 0CF3CC 80138CCC AC80001C */  sw    $zero, 0x1c($a0)
/* 0CF3D0 80138CD0 AE020000 */  sw    $v0, ($s0)
/* 0CF3D4 80138CD4 3C02F200 */  lui   $v0, 0xf200
/* 0CF3D8 80138CD8 01621025 */  or    $v0, $t3, $v0
/* 0CF3DC 80138CDC 01221025 */  or    $v0, $t1, $v0
/* 0CF3E0 80138CE0 00681825 */  or    $v1, $v1, $t0
/* 0CF3E4 80138CE4 AC820020 */  sw    $v0, 0x20($a0)
/* 0CF3E8 80138CE8 24820030 */  addiu $v0, $a0, 0x30
/* 0CF3EC 80138CEC AC830024 */  sw    $v1, 0x24($a0)
/* 0CF3F0 80138CF0 AE020000 */  sw    $v0, ($s0)
/* 0CF3F4 80138CF4 00141080 */  sll   $v0, $s4, 2
/* 0CF3F8 80138CF8 30420FFF */  andi  $v0, $v0, 0xfff
/* 0CF3FC 80138CFC 00021300 */  sll   $v0, $v0, 0xc
/* 0CF400 80138D00 00063080 */  sll   $a2, $a2, 2
/* 0CF404 80138D04 30C60FFF */  andi  $a2, $a2, 0xfff
/* 0CF408 80138D08 3C03E400 */  lui   $v1, 0xe400
/* 0CF40C 80138D0C 00C33025 */  or    $a2, $a2, $v1
/* 0CF410 80138D10 00461025 */  or    $v0, $v0, $a2
/* 0CF414 80138D14 012B4825 */  or    $t1, $t1, $t3
/* 0CF418 80138D18 AC820028 */  sw    $v0, 0x28($a0)
/* 0CF41C 80138D1C 24820038 */  addiu $v0, $a0, 0x38
/* 0CF420 80138D20 AC89002C */  sw    $t1, 0x2c($a0)
/* 0CF424 80138D24 AE020000 */  sw    $v0, ($s0)
/* 0CF428 80138D28 3C02E100 */  lui   $v0, 0xe100
/* 0CF42C 80138D2C AC820030 */  sw    $v0, 0x30($a0)
/* 0CF430 80138D30 00151540 */  sll   $v0, $s5, 0x15
/* 0CF434 80138D34 00073940 */  sll   $a3, $a3, 5
/* 0CF438 80138D38 30E7FFFF */  andi  $a3, $a3, 0xffff
/* 0CF43C 80138D3C 00471025 */  or    $v0, $v0, $a3
/* 0CF440 80138D40 AC820034 */  sw    $v0, 0x34($a0)
/* 0CF444 80138D44 24820040 */  addiu $v0, $a0, 0x40
/* 0CF448 80138D48 AE020000 */  sw    $v0, ($s0)
/* 0CF44C 80138D4C 3C02F100 */  lui   $v0, 0xf100
/* 0CF450 80138D50 AC820038 */  sw    $v0, 0x38($a0)
/* 0CF454 80138D54 AC8C003C */  sw    $t4, 0x3c($a0)
.L80138D58:
/* 0CF458 80138D58 8FBF0044 */  lw    $ra, 0x44($sp)
/* 0CF45C 80138D5C 8FBE0040 */  lw    $fp, 0x40($sp)
/* 0CF460 80138D60 8FB7003C */  lw    $s7, 0x3c($sp)
/* 0CF464 80138D64 8FB60038 */  lw    $s6, 0x38($sp)
/* 0CF468 80138D68 8FB50034 */  lw    $s5, 0x34($sp)
/* 0CF46C 80138D6C 8FB40030 */  lw    $s4, 0x30($sp)
/* 0CF470 80138D70 8FB3002C */  lw    $s3, 0x2c($sp)
/* 0CF474 80138D74 8FB20028 */  lw    $s2, 0x28($sp)
/* 0CF478 80138D78 8FB10024 */  lw    $s1, 0x24($sp)
/* 0CF47C 80138D7C 8FB00020 */  lw    $s0, 0x20($sp)
/* 0CF480 80138D80 03E00008 */  jr    $ra
/* 0CF484 80138D84 27BD0048 */   addiu $sp, $sp, 0x48

