.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_43_main
/* 35DA00 E0056000 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* 35DA04 E0056004 F7B40048 */  sdc1      $f20, 0x48($sp)
/* 35DA08 E0056008 4485A000 */  mtc1      $a1, $f20
/* 35DA0C E005600C AFB5003C */  sw        $s5, 0x3c($sp)
/* 35DA10 E0056010 0080A82D */  daddu     $s5, $a0, $zero
/* 35DA14 E0056014 F7B60050 */  sdc1      $f22, 0x50($sp)
/* 35DA18 E0056018 4486B000 */  mtc1      $a2, $f22
/* 35DA1C E005601C 27A40010 */  addiu     $a0, $sp, 0x10
/* 35DA20 E0056020 F7B80058 */  sdc1      $f24, 0x58($sp)
/* 35DA24 E0056024 4487C000 */  mtc1      $a3, $f24
/* 35DA28 E0056028 3C02E005 */  lui       $v0, %hi(fx_43_init)
/* 35DA2C E005602C 24426304 */  addiu     $v0, $v0, %lo(fx_43_init)
/* 35DA30 E0056030 AFA20018 */  sw        $v0, 0x18($sp)
/* 35DA34 E0056034 3C02E005 */  lui       $v0, %hi(fx_43_update)
/* 35DA38 E0056038 2442630C */  addiu     $v0, $v0, %lo(fx_43_update)
/* 35DA3C E005603C AFA2001C */  sw        $v0, 0x1c($sp)
/* 35DA40 E0056040 3C02E005 */  lui       $v0, %hi(fx_43_render)
/* 35DA44 E0056044 24426B8C */  addiu     $v0, $v0, %lo(fx_43_render)
/* 35DA48 E0056048 AFA20020 */  sw        $v0, 0x20($sp)
/* 35DA4C E005604C 2402002B */  addiu     $v0, $zero, 0x2b
/* 35DA50 E0056050 AFBF0044 */  sw        $ra, 0x44($sp)
/* 35DA54 E0056054 AFB60040 */  sw        $s6, 0x40($sp)
/* 35DA58 E0056058 AFB40038 */  sw        $s4, 0x38($sp)
/* 35DA5C E005605C AFB30034 */  sw        $s3, 0x34($sp)
/* 35DA60 E0056060 AFB20030 */  sw        $s2, 0x30($sp)
/* 35DA64 E0056064 AFB1002C */  sw        $s1, 0x2c($sp)
/* 35DA68 E0056068 AFB00028 */  sw        $s0, 0x28($sp)
/* 35DA6C E005606C AFA00010 */  sw        $zero, 0x10($sp)
/* 35DA70 E0056070 AFA00024 */  sw        $zero, 0x24($sp)
/* 35DA74 E0056074 0C080124 */  jal       shim_create_effect_instance
/* 35DA78 E0056078 AFA20014 */   sw       $v0, 0x14($sp)
/* 35DA7C E005607C 2404012C */  addiu     $a0, $zero, 0x12c
/* 35DA80 E0056080 24160005 */  addiu     $s6, $zero, 5
/* 35DA84 E0056084 0040802D */  daddu     $s0, $v0, $zero
/* 35DA88 E0056088 0C08012C */  jal       shim_general_heap_malloc
/* 35DA8C E005608C AE160008 */   sw       $s6, 8($s0)
/* 35DA90 E0056090 0040182D */  daddu     $v1, $v0, $zero
/* 35DA94 E0056094 14600003 */  bnez      $v1, .LE00560A4
/* 35DA98 E0056098 AE03000C */   sw       $v1, 0xc($s0)
.LE005609C:
/* 35DA9C E005609C 08015827 */  j         .LE005609C
/* 35DAA0 E00560A0 00000000 */   nop
.LE00560A4:
/* 35DAA4 E00560A4 24020064 */  addiu     $v0, $zero, 0x64
/* 35DAA8 E00560A8 AC750000 */  sw        $s5, ($v1)
/* 35DAAC E00560AC E4740004 */  swc1      $f20, 4($v1)
/* 35DAB0 E00560B0 E4760008 */  swc1      $f22, 8($v1)
/* 35DAB4 E00560B4 E478000C */  swc1      $f24, 0xc($v1)
/* 35DAB8 E00560B8 AC620028 */  sw        $v0, 0x28($v1)
/* 35DABC E00560BC AC60002C */  sw        $zero, 0x2c($v1)
/* 35DAC0 E00560C0 AC600024 */  sw        $zero, 0x24($v1)
/* 35DAC4 E00560C4 24140001 */  addiu     $s4, $zero, 1
/* 35DAC8 E00560C8 0296102A */  slt       $v0, $s4, $s6
/* 35DACC E00560CC 10400080 */  beqz      $v0, .LE00562D0
/* 35DAD0 E00560D0 2463003C */   addiu    $v1, $v1, 0x3c
/* 35DAD4 E00560D4 24730014 */  addiu     $s3, $v1, 0x14
/* 35DAD8 E00560D8 3C01E005 */  lui       $at, %hi(D_E0056EA0)
/* 35DADC E00560DC D4346EA0 */  ldc1      $f20, %lo(D_E0056EA0)($at)
/* 35DAE0 E00560E0 3C01E005 */  lui       $at, %hi(D_E0056EA8)
/* 35DAE4 E00560E4 D4386EA8 */  ldc1      $f24, %lo(D_E0056EA8)($at)
/* 35DAE8 E00560E8 3C01E005 */  lui       $at, %hi(D_E0056EB0)
/* 35DAEC E00560EC D4366EB0 */  ldc1      $f22, %lo(D_E0056EB0)($at)
.LE00560F0:
/* 35DAF0 E00560F0 0C080000 */  jal       func_E0200000
/* 35DAF4 E00560F4 24040032 */   addiu    $a0, $zero, 0x32
/* 35DAF8 E00560F8 24040014 */  addiu     $a0, $zero, 0x14
/* 35DAFC E00560FC 0C080000 */  jal       func_E0200000
/* 35DB00 E0056100 0040802D */   daddu    $s0, $v0, $zero
/* 35DB04 E0056104 24040168 */  addiu     $a0, $zero, 0x168
/* 35DB08 E0056108 0C080000 */  jal       func_E0200000
/* 35DB0C E005610C 0040882D */   daddu    $s1, $v0, $zero
/* 35DB10 E0056110 24040064 */  addiu     $a0, $zero, 0x64
/* 35DB14 E0056114 0C080000 */  jal       func_E0200000
/* 35DB18 E0056118 0040902D */   daddu    $s2, $v0, $zero
/* 35DB1C E005611C 2610004B */  addiu     $s0, $s0, 0x4b
/* 35DB20 E0056120 44900000 */  mtc1      $s0, $f0
/* 35DB24 E0056124 00000000 */  nop
/* 35DB28 E0056128 46800020 */  cvt.s.w   $f0, $f0
/* 35DB2C E005612C 26310046 */  addiu     $s1, $s1, 0x46
/* 35DB30 E0056130 E660FFF0 */  swc1      $f0, -0x10($s3)
/* 35DB34 E0056134 44910000 */  mtc1      $s1, $f0
/* 35DB38 E0056138 00000000 */  nop
/* 35DB3C E005613C 46800020 */  cvt.s.w   $f0, $f0
/* 35DB40 E0056140 E660FFF4 */  swc1      $f0, -0xc($s3)
/* 35DB44 E0056144 44920000 */  mtc1      $s2, $f0
/* 35DB48 E0056148 00000000 */  nop
/* 35DB4C E005614C 46800020 */  cvt.s.w   $f0, $f0
/* 35DB50 E0056150 24030168 */  addiu     $v1, $zero, 0x168
/* 35DB54 E0056154 00721823 */  subu      $v1, $v1, $s2
/* 35DB58 E0056158 E6600004 */  swc1      $f0, 4($s3)
/* 35DB5C E005615C 44830000 */  mtc1      $v1, $f0
/* 35DB60 E0056160 00000000 */  nop
/* 35DB64 E0056164 46800020 */  cvt.s.w   $f0, $f0
/* 35DB68 E0056168 0040182D */  daddu     $v1, $v0, $zero
/* 35DB6C E005616C 24020001 */  addiu     $v0, $zero, 1
/* 35DB70 E0056170 AE60FFF8 */  sw        $zero, -8($s3)
/* 35DB74 E0056174 12A20019 */  beq       $s5, $v0, .LE00561DC
/* 35DB78 E0056178 E660000C */   swc1     $f0, 0xc($s3)
/* 35DB7C E005617C 2AA20002 */  slti      $v0, $s5, 2
/* 35DB80 E0056180 10400005 */  beqz      $v0, .LE0056198
/* 35DB84 E0056184 24020002 */   addiu    $v0, $zero, 2
/* 35DB88 E0056188 52A00007 */  beql      $s5, $zero, .LE00561A8
/* 35DB8C E005618C AE60FFFC */   sw       $zero, -4($s3)
/* 35DB90 E0056190 080158B1 */  j         .LE00562C4
/* 35DB94 E0056194 26940001 */   addiu    $s4, $s4, 1
.LE0056198:
/* 35DB98 E0056198 12A20023 */  beq       $s5, $v0, .LE0056228
/* 35DB9C E005619C 2404000A */   addiu    $a0, $zero, 0xa
/* 35DBA0 E00561A0 080158B1 */  j         .LE00562C4
/* 35DBA4 E00561A4 26940001 */   addiu    $s4, $s4, 1
.LE00561A8:
/* 35DBA8 E00561A8 44830000 */  mtc1      $v1, $f0
/* 35DBAC E00561AC 00000000 */  nop
/* 35DBB0 E00561B0 46800020 */  cvt.s.w   $f0, $f0
/* 35DBB4 E00561B4 46000021 */  cvt.d.s   $f0, $f0
/* 35DBB8 E00561B8 46340002 */  mul.d     $f0, $f0, $f20
/* 35DBBC E00561BC 00000000 */  nop
/* 35DBC0 E00561C0 3C01C040 */  lui       $at, 0xc040
/* 35DBC4 E00561C4 44811000 */  mtc1      $at, $f2
/* 35DBC8 E00561C8 3C014040 */  lui       $at, 0x4040
/* 35DBCC E00561CC 44812000 */  mtc1      $at, $f4
/* 35DBD0 E00561D0 AE600000 */  sw        $zero, ($s3)
/* 35DBD4 E00561D4 08015885 */  j         .LE0056214
/* 35DBD8 E00561D8 AE600020 */   sw       $zero, 0x20($s3)
.LE00561DC:
/* 35DBDC E00561DC 44830000 */  mtc1      $v1, $f0
/* 35DBE0 E00561E0 00000000 */  nop
/* 35DBE4 E00561E4 46800020 */  cvt.s.w   $f0, $f0
/* 35DBE8 E00561E8 46000021 */  cvt.d.s   $f0, $f0
/* 35DBEC E00561EC 46340002 */  mul.d     $f0, $f0, $f20
/* 35DBF0 E00561F0 00000000 */  nop
/* 35DBF4 E00561F4 3C01C0C0 */  lui       $at, 0xc0c0
/* 35DBF8 E00561F8 44811000 */  mtc1      $at, $f2
/* 35DBFC E00561FC 3C0140C0 */  lui       $at, 0x40c0
/* 35DC00 E0056200 44812000 */  mtc1      $at, $f4
/* 35DC04 E0056204 AE60FFFC */  sw        $zero, -4($s3)
/* 35DC08 E0056208 AE600000 */  sw        $zero, ($s3)
/* 35DC0C E005620C AE600020 */  sw        $zero, 0x20($s3)
/* 35DC10 E0056210 46200000 */  add.d     $f0, $f0, $f0
.LE0056214:
/* 35DC14 E0056214 E662001C */  swc1      $f2, 0x1c($s3)
/* 35DC18 E0056218 E6640024 */  swc1      $f4, 0x24($s3)
/* 35DC1C E005621C 46200020 */  cvt.s.d   $f0, $f0
/* 35DC20 E0056220 080158B0 */  j         .LE00562C0
/* 35DC24 E0056224 E6600008 */   swc1     $f0, 8($s3)
.LE0056228:
/* 35DC28 E0056228 44830000 */  mtc1      $v1, $f0
/* 35DC2C E005622C 00000000 */  nop
/* 35DC30 E0056230 46800020 */  cvt.s.w   $f0, $f0
/* 35DC34 E0056234 46000021 */  cvt.d.s   $f0, $f0
/* 35DC38 E0056238 46340002 */  mul.d     $f0, $f0, $f20
/* 35DC3C E005623C 00000000 */  nop
/* 35DC40 E0056240 46200000 */  add.d     $f0, $f0, $f0
/* 35DC44 E0056244 46200020 */  cvt.s.d   $f0, $f0
/* 35DC48 E0056248 0C080138 */  jal       shim_rand_int
/* 35DC4C E005624C E6600008 */   swc1     $f0, 8($s3)
/* 35DC50 E0056250 44821000 */  mtc1      $v0, $f2
/* 35DC54 E0056254 00000000 */  nop
/* 35DC58 E0056258 468010A1 */  cvt.d.w   $f2, $f2
/* 35DC5C E005625C 46381082 */  mul.d     $f2, $f2, $f24
/* 35DC60 E0056260 00000000 */  nop
/* 35DC64 E0056264 46361080 */  add.d     $f2, $f2, $f22
/* 35DC68 E0056268 C660FFF0 */  lwc1      $f0, -0x10($s3)
/* 35DC6C E005626C 46000007 */  neg.s     $f0, $f0
/* 35DC70 E0056270 46000021 */  cvt.d.s   $f0, $f0
/* 35DC74 E0056274 46220002 */  mul.d     $f0, $f0, $f2
/* 35DC78 E0056278 00000000 */  nop
/* 35DC7C E005627C 2404000A */  addiu     $a0, $zero, 0xa
/* 35DC80 E0056280 46200020 */  cvt.s.d   $f0, $f0
/* 35DC84 E0056284 0C080138 */  jal       shim_rand_int
/* 35DC88 E0056288 E660FFFC */   swc1     $f0, -4($s3)
/* 35DC8C E005628C 44821000 */  mtc1      $v0, $f2
/* 35DC90 E0056290 00000000 */  nop
/* 35DC94 E0056294 468010A1 */  cvt.d.w   $f2, $f2
/* 35DC98 E0056298 46381082 */  mul.d     $f2, $f2, $f24
/* 35DC9C E005629C 00000000 */  nop
/* 35DCA0 E00562A0 46361080 */  add.d     $f2, $f2, $f22
/* 35DCA4 E00562A4 C660FFF4 */  lwc1      $f0, -0xc($s3)
/* 35DCA8 E00562A8 46000007 */  neg.s     $f0, $f0
/* 35DCAC E00562AC 46000021 */  cvt.d.s   $f0, $f0
/* 35DCB0 E00562B0 46220002 */  mul.d     $f0, $f0, $f2
/* 35DCB4 E00562B4 00000000 */  nop
/* 35DCB8 E00562B8 46200020 */  cvt.s.d   $f0, $f0
/* 35DCBC E00562BC E6600000 */  swc1      $f0, ($s3)
.LE00562C0:
/* 35DCC0 E00562C0 26940001 */  addiu     $s4, $s4, 1
.LE00562C4:
/* 35DCC4 E00562C4 0296102A */  slt       $v0, $s4, $s6
/* 35DCC8 E00562C8 1440FF89 */  bnez      $v0, .LE00560F0
/* 35DCCC E00562CC 2673003C */   addiu    $s3, $s3, 0x3c
.LE00562D0:
/* 35DCD0 E00562D0 8FBF0044 */  lw        $ra, 0x44($sp)
/* 35DCD4 E00562D4 8FB60040 */  lw        $s6, 0x40($sp)
/* 35DCD8 E00562D8 8FB5003C */  lw        $s5, 0x3c($sp)
/* 35DCDC E00562DC 8FB40038 */  lw        $s4, 0x38($sp)
/* 35DCE0 E00562E0 8FB30034 */  lw        $s3, 0x34($sp)
/* 35DCE4 E00562E4 8FB20030 */  lw        $s2, 0x30($sp)
/* 35DCE8 E00562E8 8FB1002C */  lw        $s1, 0x2c($sp)
/* 35DCEC E00562EC 8FB00028 */  lw        $s0, 0x28($sp)
/* 35DCF0 E00562F0 D7B80058 */  ldc1      $f24, 0x58($sp)
/* 35DCF4 E00562F4 D7B60050 */  ldc1      $f22, 0x50($sp)
/* 35DCF8 E00562F8 D7B40048 */  ldc1      $f20, 0x48($sp)
/* 35DCFC E00562FC 03E00008 */  jr        $ra
/* 35DD00 E0056300 27BD0060 */   addiu    $sp, $sp, 0x60
