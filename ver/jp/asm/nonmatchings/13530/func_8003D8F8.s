.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003D8F8
/* 18CF8 8003D8F8 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 18CFC 8003D8FC 3C028007 */  lui       $v0, %hi(D_80077BFC)
/* 18D00 8003D900 24427BFC */  addiu     $v0, $v0, %lo(D_80077BFC)
/* 18D04 8003D904 AFBF0020 */  sw        $ra, 0x20($sp)
/* 18D08 8003D908 AFB3001C */  sw        $s3, 0x1c($sp)
/* 18D0C 8003D90C AFB20018 */  sw        $s2, 0x18($sp)
/* 18D10 8003D910 AFB10014 */  sw        $s1, 0x14($sp)
/* 18D14 8003D914 AFB00010 */  sw        $s0, 0x10($sp)
/* 18D18 8003D918 F7BE0050 */  sdc1      $f30, 0x50($sp)
/* 18D1C 8003D91C F7BC0048 */  sdc1      $f28, 0x48($sp)
/* 18D20 8003D920 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* 18D24 8003D924 F7B80038 */  sdc1      $f24, 0x38($sp)
/* 18D28 8003D928 F7B60030 */  sdc1      $f22, 0x30($sp)
/* 18D2C 8003D92C F7B40028 */  sdc1      $f20, 0x28($sp)
/* 18D30 8003D930 C4400000 */  lwc1      $f0, ($v0)
/* 18D34 8003D934 3C013DCC */  lui       $at, 0x3dcc
/* 18D38 8003D938 3421CCCD */  ori       $at, $at, 0xcccd
/* 18D3C 8003D93C 44811000 */  mtc1      $at, $f2
/* 18D40 8003D940 00000000 */  nop
/* 18D44 8003D944 46020000 */  add.s     $f0, $f0, $f2
/* 18D48 8003D948 E4400000 */  swc1      $f0, ($v0)
/* 18D4C 8003D94C 24020002 */  addiu     $v0, $zero, 2
/* 18D50 8003D950 14A2006B */  bne       $a1, $v0, .L8003DB00
/* 18D54 8003D954 0080882D */   daddu    $s1, $a0, $zero
/* 18D58 8003D958 3C108007 */  lui       $s0, %hi(D_80077BF4)
/* 18D5C 8003D95C 26107BF4 */  addiu     $s0, $s0, %lo(D_80077BF4)
/* 18D60 8003D960 C62E003C */  lwc1      $f14, 0x3c($s1)
/* 18D64 8003D964 3C014160 */  lui       $at, 0x4160
/* 18D68 8003D968 44810000 */  mtc1      $at, $f0
/* 18D6C 8003D96C C62C0038 */  lwc1      $f12, 0x38($s1)
/* 18D70 8003D970 46007380 */  add.s     $f14, $f14, $f0
/* 18D74 8003D974 3C0140A0 */  lui       $at, 0x40a0
/* 18D78 8003D978 44810000 */  mtc1      $at, $f0
/* 18D7C 8003D97C 8E260040 */  lw        $a2, 0x40($s1)
/* 18D80 8003D980 8E070000 */  lw        $a3, ($s0)
/* 18D84 8003D984 0C01BF0C */  jal       func_8006FC30
/* 18D88 8003D988 46007381 */   sub.s    $f14, $f14, $f0
/* 18D8C 8003D98C C6000000 */  lwc1      $f0, ($s0)
/* 18D90 8003D990 3C01420C */  lui       $at, 0x420c
/* 18D94 8003D994 44816000 */  mtc1      $at, $f12
/* 18D98 8003D998 0000982D */  daddu     $s3, $zero, $zero
/* 18D9C 8003D99C 460C0300 */  add.s     $f12, $f0, $f12
/* 18DA0 8003D9A0 3C01BE99 */  lui       $at, 0xbe99
/* 18DA4 8003D9A4 3421999A */  ori       $at, $at, 0x999a
/* 18DA8 8003D9A8 4481F000 */  mtc1      $at, $f30
/* 18DAC 8003D9AC 0C00A6B9 */  jal       func_80029AE4
/* 18DB0 8003D9B0 0260902D */   daddu    $s2, $s3, $zero
/* 18DB4 8003D9B4 E6000000 */  swc1      $f0, ($s0)
.L8003D9B8:
/* 18DB8 8003D9B8 0C00A66F */  jal       func_800299BC
/* 18DBC 8003D9BC 2404000A */   addiu    $a0, $zero, 0xa
/* 18DC0 8003D9C0 2442FFFB */  addiu     $v0, $v0, -5
/* 18DC4 8003D9C4 4482B000 */  mtc1      $v0, $f22
/* 18DC8 8003D9C8 00000000 */  nop
/* 18DCC 8003D9CC 4680B5A0 */  cvt.s.w   $f22, $f22
/* 18DD0 8003D9D0 0C00A66F */  jal       func_800299BC
/* 18DD4 8003D9D4 2404000A */   addiu    $a0, $zero, 0xa
/* 18DD8 8003D9D8 4616B082 */  mul.s     $f2, $f22, $f22
/* 18DDC 8003D9DC 00000000 */  nop
/* 18DE0 8003D9E0 2442FFFB */  addiu     $v0, $v0, -5
/* 18DE4 8003D9E4 4482C000 */  mtc1      $v0, $f24
/* 18DE8 8003D9E8 00000000 */  nop
/* 18DEC 8003D9EC 4680C620 */  cvt.s.w   $f24, $f24
/* 18DF0 8003D9F0 4618C102 */  mul.s     $f4, $f24, $f24
/* 18DF4 8003D9F4 00000000 */  nop
/* 18DF8 8003D9F8 C62C000C */  lwc1      $f12, 0xc($s1)
/* 18DFC 8003D9FC 44920000 */  mtc1      $s2, $f0
/* 18E00 8003DA00 00000000 */  nop
/* 18E04 8003DA04 46800020 */  cvt.s.w   $f0, $f0
/* 18E08 8003DA08 46006307 */  neg.s     $f12, $f12
/* 18E0C 8003DA0C 46006300 */  add.s     $f12, $f12, $f0
/* 18E10 8003DA10 3C01C000 */  lui       $at, 0xc000
/* 18E14 8003DA14 4481A000 */  mtc1      $at, $f20
/* 18E18 8003DA18 3C0140A0 */  lui       $at, 0x40a0
/* 18E1C 8003DA1C 44810000 */  mtc1      $at, $f0
/* 18E20 8003DA20 46041080 */  add.s     $f2, $f2, $f4
/* 18E24 8003DA24 3C018007 */  lui       $at, %hi(D_80077BF8)
/* 18E28 8003DA28 A4207BF8 */  sh        $zero, %lo(D_80077BF8)($at)
/* 18E2C 8003DA2C 46001083 */  div.s     $f2, $f2, $f0
/* 18E30 8003DA30 0C00A6B9 */  jal       func_80029AE4
/* 18E34 8003DA34 4602A501 */   sub.s    $f20, $f20, $f2
/* 18E38 8003DA38 3C0140C9 */  lui       $at, 0x40c9
/* 18E3C 8003DA3C 34210FD0 */  ori       $at, $at, 0xfd0
/* 18E40 8003DA40 44811000 */  mtc1      $at, $f2
/* 18E44 8003DA44 00000000 */  nop
/* 18E48 8003DA48 46020002 */  mul.s     $f0, $f0, $f2
/* 18E4C 8003DA4C 00000000 */  nop
/* 18E50 8003DA50 3C0143B4 */  lui       $at, 0x43b4
/* 18E54 8003DA54 44811000 */  mtc1      $at, $f2
/* 18E58 8003DA58 00000000 */  nop
/* 18E5C 8003DA5C 46020683 */  div.s     $f26, $f0, $f2
/* 18E60 8003DA60 0C00A84B */  jal       func_8002A12C
/* 18E64 8003DA64 4600D306 */   mov.s    $f12, $f26
/* 18E68 8003DA68 46000706 */  mov.s     $f28, $f0
/* 18E6C 8003DA6C 0C00A864 */  jal       func_8002A190
/* 18E70 8003DA70 4600D306 */   mov.s    $f12, $f26
/* 18E74 8003DA74 862200A6 */  lh        $v0, 0xa6($s1)
/* 18E78 8003DA78 44822000 */  mtc1      $v0, $f4
/* 18E7C 8003DA7C 00000000 */  nop
/* 18E80 8003DA80 46802120 */  cvt.s.w   $f4, $f4
/* 18E84 8003DA84 461C2182 */  mul.s     $f6, $f4, $f28
/* 18E88 8003DA88 00000000 */  nop
/* 18E8C 8003DA8C 46002102 */  mul.s     $f4, $f4, $f0
/* 18E90 8003DA90 00000000 */  nop
/* 18E94 8003DA94 3C014178 */  lui       $at, 0x4178
/* 18E98 8003DA98 44811000 */  mtc1      $at, $f2
/* 18E9C 8003DA9C C620003C */  lwc1      $f0, 0x3c($s1)
/* 18EA0 8003DAA0 46020000 */  add.s     $f0, $f0, $f2
/* 18EA4 8003DAA4 46140000 */  add.s     $f0, $f0, $f20
/* 18EA8 8003DAA8 461E3182 */  mul.s     $f6, $f6, $f30
/* 18EAC 8003DAAC 00000000 */  nop
/* 18EB0 8003DAB0 44060000 */  mfc1      $a2, $f0
/* 18EB4 8003DAB4 C6200038 */  lwc1      $f0, 0x38($s1)
/* 18EB8 8003DAB8 46060000 */  add.s     $f0, $f0, $f6
/* 18EBC 8003DABC 46160000 */  add.s     $f0, $f0, $f22
/* 18EC0 8003DAC0 461E2102 */  mul.s     $f4, $f4, $f30
/* 18EC4 8003DAC4 00000000 */  nop
/* 18EC8 8003DAC8 44050000 */  mfc1      $a1, $f0
/* 18ECC 8003DACC C6200040 */  lwc1      $f0, 0x40($s1)
/* 18ED0 8003DAD0 46040000 */  add.s     $f0, $f0, $f4
/* 18ED4 8003DAD4 46180000 */  add.s     $f0, $f0, $f24
/* 18ED8 8003DAD8 2652005A */  addiu     $s2, $s2, 0x5a
/* 18EDC 8003DADC 26730001 */  addiu     $s3, $s3, 1
/* 18EE0 8003DAE0 44070000 */  mfc1      $a3, $f0
/* 18EE4 8003DAE4 0C01BF24 */  jal       func_8006FC90
/* 18EE8 8003DAE8 24040001 */   addiu    $a0, $zero, 1
/* 18EEC 8003DAEC 2A620004 */  slti      $v0, $s3, 4
/* 18EF0 8003DAF0 1040004E */  beqz      $v0, .L8003DC2C
/* 18EF4 8003DAF4 00000000 */   nop
/* 18EF8 8003DAF8 0800F66E */  j         .L8003D9B8
/* 18EFC 8003DAFC 00000000 */   nop
.L8003DB00:
/* 18F00 8003DB00 0C00A66F */  jal       func_800299BC
/* 18F04 8003DB04 2404000A */   addiu    $a0, $zero, 0xa
/* 18F08 8003DB08 2442FFFB */  addiu     $v0, $v0, -5
/* 18F0C 8003DB0C 4482C000 */  mtc1      $v0, $f24
/* 18F10 8003DB10 00000000 */  nop
/* 18F14 8003DB14 4680C620 */  cvt.s.w   $f24, $f24
/* 18F18 8003DB18 0C00A66F */  jal       func_800299BC
/* 18F1C 8003DB1C 2404000A */   addiu    $a0, $zero, 0xa
/* 18F20 8003DB20 4618C002 */  mul.s     $f0, $f24, $f24
/* 18F24 8003DB24 00000000 */  nop
/* 18F28 8003DB28 2442FFFB */  addiu     $v0, $v0, -5
/* 18F2C 8003DB2C 4482B000 */  mtc1      $v0, $f22
/* 18F30 8003DB30 00000000 */  nop
/* 18F34 8003DB34 4680B5A0 */  cvt.s.w   $f22, $f22
/* 18F38 8003DB38 4616B082 */  mul.s     $f2, $f22, $f22
/* 18F3C 8003DB3C 00000000 */  nop
/* 18F40 8003DB40 C62C000C */  lwc1      $f12, 0xc($s1)
/* 18F44 8003DB44 3C01C000 */  lui       $at, 0xc000
/* 18F48 8003DB48 4481A000 */  mtc1      $at, $f20
/* 18F4C 8003DB4C 46020000 */  add.s     $f0, $f0, $f2
/* 18F50 8003DB50 3C018007 */  lui       $at, %hi(D_80077BF8)
/* 18F54 8003DB54 A4207BF8 */  sh        $zero, %lo(D_80077BF8)($at)
/* 18F58 8003DB58 3C0140A0 */  lui       $at, 0x40a0
/* 18F5C 8003DB5C 44811000 */  mtc1      $at, $f2
/* 18F60 8003DB60 46006307 */  neg.s     $f12, $f12
/* 18F64 8003DB64 46020003 */  div.s     $f0, $f0, $f2
/* 18F68 8003DB68 0C00A6B9 */  jal       func_80029AE4
/* 18F6C 8003DB6C 4600A501 */   sub.s    $f20, $f20, $f0
/* 18F70 8003DB70 3C0140C9 */  lui       $at, 0x40c9
/* 18F74 8003DB74 34210FD0 */  ori       $at, $at, 0xfd0
/* 18F78 8003DB78 44811000 */  mtc1      $at, $f2
/* 18F7C 8003DB7C 00000000 */  nop
/* 18F80 8003DB80 46020002 */  mul.s     $f0, $f0, $f2
/* 18F84 8003DB84 00000000 */  nop
/* 18F88 8003DB88 3C0143B4 */  lui       $at, 0x43b4
/* 18F8C 8003DB8C 44811000 */  mtc1      $at, $f2
/* 18F90 8003DB90 00000000 */  nop
/* 18F94 8003DB94 46020683 */  div.s     $f26, $f0, $f2
/* 18F98 8003DB98 0C00A84B */  jal       func_8002A12C
/* 18F9C 8003DB9C 4600D306 */   mov.s    $f12, $f26
/* 18FA0 8003DBA0 46000706 */  mov.s     $f28, $f0
/* 18FA4 8003DBA4 0C00A864 */  jal       func_8002A190
/* 18FA8 8003DBA8 4600D306 */   mov.s    $f12, $f26
/* 18FAC 8003DBAC 862200A6 */  lh        $v0, 0xa6($s1)
/* 18FB0 8003DBB0 44822000 */  mtc1      $v0, $f4
/* 18FB4 8003DBB4 00000000 */  nop
/* 18FB8 8003DBB8 46802120 */  cvt.s.w   $f4, $f4
/* 18FBC 8003DBBC 461C2182 */  mul.s     $f6, $f4, $f28
/* 18FC0 8003DBC0 00000000 */  nop
/* 18FC4 8003DBC4 46002102 */  mul.s     $f4, $f4, $f0
/* 18FC8 8003DBC8 00000000 */  nop
/* 18FCC 8003DBCC 3C01BE99 */  lui       $at, 0xbe99
/* 18FD0 8003DBD0 3421999A */  ori       $at, $at, 0x999a
/* 18FD4 8003DBD4 44810000 */  mtc1      $at, $f0
/* 18FD8 8003DBD8 00000000 */  nop
/* 18FDC 8003DBDC 46003182 */  mul.s     $f6, $f6, $f0
/* 18FE0 8003DBE0 00000000 */  nop
/* 18FE4 8003DBE4 46002102 */  mul.s     $f4, $f4, $f0
/* 18FE8 8003DBE8 00000000 */  nop
/* 18FEC 8003DBEC 3C014178 */  lui       $at, 0x4178
/* 18FF0 8003DBF0 44811000 */  mtc1      $at, $f2
/* 18FF4 8003DBF4 C620003C */  lwc1      $f0, 0x3c($s1)
/* 18FF8 8003DBF8 46020000 */  add.s     $f0, $f0, $f2
/* 18FFC 8003DBFC 46140000 */  add.s     $f0, $f0, $f20
/* 19000 8003DC00 44060000 */  mfc1      $a2, $f0
/* 19004 8003DC04 C6200038 */  lwc1      $f0, 0x38($s1)
/* 19008 8003DC08 46060000 */  add.s     $f0, $f0, $f6
/* 1900C 8003DC0C 46180000 */  add.s     $f0, $f0, $f24
/* 19010 8003DC10 44050000 */  mfc1      $a1, $f0
/* 19014 8003DC14 C6200040 */  lwc1      $f0, 0x40($s1)
/* 19018 8003DC18 46040000 */  add.s     $f0, $f0, $f4
/* 1901C 8003DC1C 46160000 */  add.s     $f0, $f0, $f22
/* 19020 8003DC20 44070000 */  mfc1      $a3, $f0
/* 19024 8003DC24 0C01BF24 */  jal       func_8006FC90
/* 19028 8003DC28 24040001 */   addiu    $a0, $zero, 1
.L8003DC2C:
/* 1902C 8003DC2C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 19030 8003DC30 8FB3001C */  lw        $s3, 0x1c($sp)
/* 19034 8003DC34 8FB20018 */  lw        $s2, 0x18($sp)
/* 19038 8003DC38 8FB10014 */  lw        $s1, 0x14($sp)
/* 1903C 8003DC3C 8FB00010 */  lw        $s0, 0x10($sp)
/* 19040 8003DC40 D7BE0050 */  ldc1      $f30, 0x50($sp)
/* 19044 8003DC44 D7BC0048 */  ldc1      $f28, 0x48($sp)
/* 19048 8003DC48 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* 1904C 8003DC4C D7B80038 */  ldc1      $f24, 0x38($sp)
/* 19050 8003DC50 D7B60030 */  ldc1      $f22, 0x30($sp)
/* 19054 8003DC54 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 19058 8003DC58 03E00008 */  jr        $ra
/* 1905C 8003DC5C 27BD0058 */   addiu    $sp, $sp, 0x58
