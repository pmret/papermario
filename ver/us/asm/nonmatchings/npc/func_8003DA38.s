.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003DA38
/* 18E38 8003DA38 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 18E3C 8003DA3C AFB00018 */  sw        $s0, 0x18($sp)
/* 18E40 8003DA40 24020002 */  addiu     $v0, $zero, 2
/* 18E44 8003DA44 AFBF0020 */  sw        $ra, 0x20($sp)
/* 18E48 8003DA48 AFB1001C */  sw        $s1, 0x1c($sp)
/* 18E4C 8003DA4C F7B80038 */  sdc1      $f24, 0x38($sp)
/* 18E50 8003DA50 F7B60030 */  sdc1      $f22, 0x30($sp)
/* 18E54 8003DA54 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 18E58 8003DA58 14A20019 */  bne       $a1, $v0, .L8003DAC0
/* 18E5C 8003DA5C 0080802D */   daddu    $s0, $a0, $zero
/* 18E60 8003DA60 3C118007 */  lui       $s1, %hi(D_80077C1E)
/* 18E64 8003DA64 26317C1E */  addiu     $s1, $s1, %lo(D_80077C1E)
/* 18E68 8003DA68 86230000 */  lh        $v1, ($s1)
/* 18E6C 8003DA6C 24020005 */  addiu     $v0, $zero, 5
/* 18E70 8003DA70 14620013 */  bne       $v1, $v0, .L8003DAC0
/* 18E74 8003DA74 00000000 */   nop
/* 18E78 8003DA78 C60C0038 */  lwc1      $f12, 0x38($s0)
/* 18E7C 8003DA7C 8E060040 */  lw        $a2, 0x40($s0)
/* 18E80 8003DA80 C600003C */  lwc1      $f0, 0x3c($s0)
/* 18E84 8003DA84 3C014160 */  lui       $at, 0x4160
/* 18E88 8003DA88 44817000 */  mtc1      $at, $f14
/* 18E8C 8003DA8C 3C108007 */  lui       $s0, %hi(D_80077C18)
/* 18E90 8003DA90 26107C18 */  addiu     $s0, $s0, %lo(D_80077C18)
/* 18E94 8003DA94 8E070000 */  lw        $a3, ($s0)
/* 18E98 8003DA98 0C01BEE4 */  jal       playFX_08
/* 18E9C 8003DA9C 460E0380 */   add.s    $f14, $f0, $f14
/* 18EA0 8003DAA0 C6000000 */  lwc1      $f0, ($s0)
/* 18EA4 8003DAA4 3C01420C */  lui       $at, 0x420c
/* 18EA8 8003DAA8 44816000 */  mtc1      $at, $f12
/* 18EAC 8003DAAC 0C00A6C9 */  jal       clamp_angle
/* 18EB0 8003DAB0 460C0300 */   add.s    $f12, $f0, $f12
/* 18EB4 8003DAB4 E6000000 */  swc1      $f0, ($s0)
/* 18EB8 8003DAB8 0800F706 */  j         .L8003DC18
/* 18EBC 8003DABC A6200000 */   sh       $zero, ($s1)
.L8003DAC0:
/* 18EC0 8003DAC0 3C038007 */  lui       $v1, %hi(D_80077C1E)
/* 18EC4 8003DAC4 24637C1E */  addiu     $v1, $v1, %lo(D_80077C1E)
/* 18EC8 8003DAC8 94620000 */  lhu       $v0, ($v1)
/* 18ECC 8003DACC 24420001 */  addiu     $v0, $v0, 1
/* 18ED0 8003DAD0 A4620000 */  sh        $v0, ($v1)
/* 18ED4 8003DAD4 00021400 */  sll       $v0, $v0, 0x10
/* 18ED8 8003DAD8 00021403 */  sra       $v0, $v0, 0x10
/* 18EDC 8003DADC 28420006 */  slti      $v0, $v0, 6
/* 18EE0 8003DAE0 14400002 */  bnez      $v0, .L8003DAEC
/* 18EE4 8003DAE4 24020005 */   addiu    $v0, $zero, 5
/* 18EE8 8003DAE8 A4620000 */  sh        $v0, ($v1)
.L8003DAEC:
/* 18EEC 8003DAEC 3C048007 */  lui       $a0, %hi(D_80077C1C)
/* 18EF0 8003DAF0 24847C1C */  addiu     $a0, $a0, %lo(D_80077C1C)
/* 18EF4 8003DAF4 94820000 */  lhu       $v0, ($a0)
/* 18EF8 8003DAF8 24430001 */  addiu     $v1, $v0, 1
/* 18EFC 8003DAFC 00021400 */  sll       $v0, $v0, 0x10
/* 18F00 8003DB00 18400045 */  blez      $v0, .L8003DC18
/* 18F04 8003DB04 A4830000 */   sh       $v1, ($a0)
/* 18F08 8003DB08 C60C000C */  lwc1      $f12, 0xc($s0)
/* 18F0C 8003DB0C A4800000 */  sh        $zero, ($a0)
/* 18F10 8003DB10 0C00A6C9 */  jal       clamp_angle
/* 18F14 8003DB14 46006307 */   neg.s    $f12, $f12
/* 18F18 8003DB18 3C0140C9 */  lui       $at, 0x40c9
/* 18F1C 8003DB1C 34210FD0 */  ori       $at, $at, 0xfd0
/* 18F20 8003DB20 44811000 */  mtc1      $at, $f2
/* 18F24 8003DB24 00000000 */  nop
/* 18F28 8003DB28 46020502 */  mul.s     $f20, $f0, $f2
/* 18F2C 8003DB2C 00000000 */  nop
/* 18F30 8003DB30 3C0143B4 */  lui       $at, 0x43b4
/* 18F34 8003DB34 44810000 */  mtc1      $at, $f0
/* 18F38 8003DB38 00000000 */  nop
/* 18F3C 8003DB3C 4600A503 */  div.s     $f20, $f20, $f0
/* 18F40 8003DB40 0C00A85B */  jal       sin_rad
/* 18F44 8003DB44 4600A306 */   mov.s    $f12, $f20
/* 18F48 8003DB48 4600A306 */  mov.s     $f12, $f20
/* 18F4C 8003DB4C 0C00A874 */  jal       cos_rad
/* 18F50 8003DB50 46000506 */   mov.s    $f20, $f0
/* 18F54 8003DB54 860200A6 */  lh        $v0, 0xa6($s0)
/* 18F58 8003DB58 44821000 */  mtc1      $v0, $f2
/* 18F5C 8003DB5C 00000000 */  nop
/* 18F60 8003DB60 468010A0 */  cvt.s.w   $f2, $f2
/* 18F64 8003DB64 46141502 */  mul.s     $f20, $f2, $f20
/* 18F68 8003DB68 00000000 */  nop
/* 18F6C 8003DB6C 46001082 */  mul.s     $f2, $f2, $f0
/* 18F70 8003DB70 00000000 */  nop
/* 18F74 8003DB74 3C01BECC */  lui       $at, 0xbecc
/* 18F78 8003DB78 3421CCCD */  ori       $at, $at, 0xcccd
/* 18F7C 8003DB7C 44810000 */  mtc1      $at, $f0
/* 18F80 8003DB80 00000000 */  nop
/* 18F84 8003DB84 4600A502 */  mul.s     $f20, $f20, $f0
/* 18F88 8003DB88 00000000 */  nop
/* 18F8C 8003DB8C 46001082 */  mul.s     $f2, $f2, $f0
/* 18F90 8003DB90 00000000 */  nop
/* 18F94 8003DB94 C6000038 */  lwc1      $f0, 0x38($s0)
/* 18F98 8003DB98 46140600 */  add.s     $f24, $f0, $f20
/* 18F9C 8003DB9C C6000040 */  lwc1      $f0, 0x40($s0)
/* 18FA0 8003DBA0 C604003C */  lwc1      $f4, 0x3c($s0)
/* 18FA4 8003DBA4 46020580 */  add.s     $f22, $f0, $f2
/* 18FA8 8003DBA8 3C014178 */  lui       $at, 0x4178
/* 18FAC 8003DBAC 44810000 */  mtc1      $at, $f0
/* 18FB0 8003DBB0 2404000A */  addiu     $a0, $zero, 0xa
/* 18FB4 8003DBB4 0C00A67F */  jal       rand_int
/* 18FB8 8003DBB8 46002500 */   add.s    $f20, $f4, $f0
/* 18FBC 8003DBBC 24040001 */  addiu     $a0, $zero, 1
/* 18FC0 8003DBC0 44821000 */  mtc1      $v0, $f2
/* 18FC4 8003DBC4 00000000 */  nop
/* 18FC8 8003DBC8 468010A0 */  cvt.s.w   $f2, $f2
/* 18FCC 8003DBCC C600000C */  lwc1      $f0, 0xc($s0)
/* 18FD0 8003DBD0 3C108007 */  lui       $s0, %hi(D_80077C20)
/* 18FD4 8003DBD4 26107C20 */  addiu     $s0, $s0, %lo(D_80077C20)
/* 18FD8 8003DBD8 4405C000 */  mfc1      $a1, $f24
/* 18FDC 8003DBDC 4407B000 */  mfc1      $a3, $f22
/* 18FE0 8003DBE0 46000007 */  neg.s     $f0, $f0
/* 18FE4 8003DBE4 46020000 */  add.s     $f0, $f0, $f2
/* 18FE8 8003DBE8 3C0140A0 */  lui       $at, 0x40a0
/* 18FEC 8003DBEC 44811000 */  mtc1      $at, $f2
/* 18FF0 8003DBF0 4406A000 */  mfc1      $a2, $f20
/* 18FF4 8003DBF4 46020001 */  sub.s     $f0, $f0, $f2
/* 18FF8 8003DBF8 C6020000 */  lwc1      $f2, ($s0)
/* 18FFC 8003DBFC 468010A0 */  cvt.s.w   $f2, $f2
/* 19000 8003DC00 E7A20014 */  swc1      $f2, 0x14($sp)
/* 19004 8003DC04 0C01BEFC */  jal       playFX_09
/* 19008 8003DC08 E7A00010 */   swc1     $f0, 0x10($sp)
/* 1900C 8003DC0C 8E020000 */  lw        $v0, ($s0)
/* 19010 8003DC10 2C420001 */  sltiu     $v0, $v0, 1
/* 19014 8003DC14 AE020000 */  sw        $v0, ($s0)
.L8003DC18:
/* 19018 8003DC18 8FBF0020 */  lw        $ra, 0x20($sp)
/* 1901C 8003DC1C 8FB1001C */  lw        $s1, 0x1c($sp)
/* 19020 8003DC20 8FB00018 */  lw        $s0, 0x18($sp)
/* 19024 8003DC24 D7B80038 */  ldc1      $f24, 0x38($sp)
/* 19028 8003DC28 D7B60030 */  ldc1      $f22, 0x30($sp)
/* 1902C 8003DC2C D7B40028 */  ldc1      $f20, 0x28($sp)
/* 19030 8003DC30 03E00008 */  jr        $ra
/* 19034 8003DC34 27BD0040 */   addiu    $sp, $sp, 0x40
