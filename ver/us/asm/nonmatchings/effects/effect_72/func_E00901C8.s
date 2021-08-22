.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00901C8
/* 38FAC8 E00901C8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 38FACC E00901CC AFBF0010 */  sw        $ra, 0x10($sp)
/* 38FAD0 E00901D0 8C85000C */  lw        $a1, 0xc($a0)
/* 38FAD4 E00901D4 8CA30018 */  lw        $v1, 0x18($a1)
/* 38FAD8 E00901D8 8CA70000 */  lw        $a3, ($a1)
/* 38FADC E00901DC 28620064 */  slti      $v0, $v1, 0x64
/* 38FAE0 E00901E0 10400002 */  beqz      $v0, .LE00901EC
/* 38FAE4 E00901E4 2462FFFF */   addiu    $v0, $v1, -1
/* 38FAE8 E00901E8 ACA20018 */  sw        $v0, 0x18($a1)
.LE00901EC:
/* 38FAEC E00901EC 8CA3001C */  lw        $v1, 0x1c($a1)
/* 38FAF0 E00901F0 8CA80018 */  lw        $t0, 0x18($a1)
/* 38FAF4 E00901F4 24660001 */  addiu     $a2, $v1, 1
/* 38FAF8 E00901F8 05010007 */  bgez      $t0, .LE0090218
/* 38FAFC E00901FC ACA6001C */   sw       $a2, 0x1c($a1)
/* 38FB00 E0090200 2402FFFF */  addiu     $v0, $zero, -1
/* 38FB04 E0090204 ACA00024 */  sw        $zero, 0x24($a1)
/* 38FB08 E0090208 0C080128 */  jal       func_E02004A0
/* 38FB0C E009020C ACA20018 */   sw       $v0, 0x18($a1)
/* 38FB10 E0090210 08024105 */  j         .LE0090414
/* 38FB14 E0090214 00000000 */   nop
.LE0090218:
/* 38FB18 E0090218 28E20005 */  slti      $v0, $a3, 5
/* 38FB1C E009021C 10400048 */  beqz      $v0, .LE0090340
/* 38FB20 E0090220 28C20009 */   slti     $v0, $a2, 9
/* 38FB24 E0090224 1040000F */  beqz      $v0, .LE0090264
/* 38FB28 E0090228 2402000A */   addiu    $v0, $zero, 0xa
/* 38FB2C E009022C 3C02E009 */  lui       $v0, %hi(D_E0090A68)
/* 38FB30 E0090230 00431021 */  addu      $v0, $v0, $v1
/* 38FB34 E0090234 90420A68 */  lbu       $v0, %lo(D_E0090A68)($v0)
/* 38FB38 E0090238 3C01E009 */  lui       $at, %hi(D_E0090AA0)
/* 38FB3C E009023C D4220AA0 */  ldc1      $f2, %lo(D_E0090AA0)($at)
/* 38FB40 E0090240 44820000 */  mtc1      $v0, $f0
/* 38FB44 E0090244 00000000 */  nop
/* 38FB48 E0090248 46800020 */  cvt.s.w   $f0, $f0
/* 38FB4C E009024C 46000021 */  cvt.d.s   $f0, $f0
/* 38FB50 E0090250 46220002 */  mul.d     $f0, $f0, $f2
/* 38FB54 E0090254 00000000 */  nop
/* 38FB58 E0090258 46200020 */  cvt.s.d   $f0, $f0
/* 38FB5C E009025C E4A00028 */  swc1      $f0, 0x28($a1)
/* 38FB60 E0090260 2402000A */  addiu     $v0, $zero, 0xa
.LE0090264:
/* 38FB64 E0090264 14C20003 */  bne       $a2, $v0, .LE0090274
/* 38FB68 E0090268 2463FF9C */   addiu    $v1, $v1, -0x64
/* 38FB6C E009026C 24020009 */  addiu     $v0, $zero, 9
/* 38FB70 E0090270 ACA2001C */  sw        $v0, 0x1c($a1)
.LE0090274:
/* 38FB74 E0090274 2C620007 */  sltiu     $v0, $v1, 7
/* 38FB78 E0090278 1040000F */  beqz      $v0, .LE00902B8
/* 38FB7C E009027C 2402006D */   addiu    $v0, $zero, 0x6d
/* 38FB80 E0090280 3C02E009 */  lui       $v0, %hi(D_E0090A70)
/* 38FB84 E0090284 00431021 */  addu      $v0, $v0, $v1
/* 38FB88 E0090288 90420A70 */  lbu       $v0, %lo(D_E0090A70)($v0)
/* 38FB8C E009028C 3C01E009 */  lui       $at, %hi(D_E0090AA8)
/* 38FB90 E0090290 D4220AA8 */  ldc1      $f2, %lo(D_E0090AA8)($at)
/* 38FB94 E0090294 44820000 */  mtc1      $v0, $f0
/* 38FB98 E0090298 00000000 */  nop
/* 38FB9C E009029C 46800020 */  cvt.s.w   $f0, $f0
/* 38FBA0 E00902A0 46000021 */  cvt.d.s   $f0, $f0
/* 38FBA4 E00902A4 46220002 */  mul.d     $f0, $f0, $f2
/* 38FBA8 E00902A8 00000000 */  nop
/* 38FBAC E00902AC 46200020 */  cvt.s.d   $f0, $f0
/* 38FBB0 E00902B0 E4A00028 */  swc1      $f0, 0x28($a1)
/* 38FBB4 E00902B4 2402006D */  addiu     $v0, $zero, 0x6d
.LE00902B8:
/* 38FBB8 E00902B8 14C20004 */  bne       $a2, $v0, .LE00902CC
/* 38FBBC E00902BC 28C203E9 */   slti     $v0, $a2, 0x3e9
/* 38FBC0 E00902C0 2402006C */  addiu     $v0, $zero, 0x6c
/* 38FBC4 E00902C4 ACA2001C */  sw        $v0, 0x1c($a1)
/* 38FBC8 E00902C8 28C203E9 */  slti      $v0, $a2, 0x3e9
.LE00902CC:
/* 38FBCC E00902CC 14400004 */  bnez      $v0, .LE00902E0
/* 38FBD0 E00902D0 29020006 */   slti     $v0, $t0, 6
/* 38FBD4 E00902D4 240203E8 */  addiu     $v0, $zero, 0x3e8
/* 38FBD8 E00902D8 ACA2001C */  sw        $v0, 0x1c($a1)
/* 38FBDC E00902DC 29020006 */  slti      $v0, $t0, 6
.LE00902E0:
/* 38FBE0 E00902E0 14400010 */  bnez      $v0, .LE0090324
/* 38FBE4 E00902E4 29020005 */   slti     $v0, $t0, 5
/* 38FBE8 E00902E8 C4A00030 */  lwc1      $f0, 0x30($a1)
/* 38FBEC E00902EC 3C013FE8 */  lui       $at, 0x3fe8
/* 38FBF0 E00902F0 44812800 */  mtc1      $at, $f5
/* 38FBF4 E00902F4 44802000 */  mtc1      $zero, $f4
/* 38FBF8 E00902F8 46000021 */  cvt.d.s   $f0, $f0
/* 38FBFC E00902FC 46240002 */  mul.d     $f0, $f0, $f4
/* 38FC00 E0090300 00000000 */  nop
/* 38FC04 E0090304 C4A20034 */  lwc1      $f2, 0x34($a1)
/* 38FC08 E0090308 460010A1 */  cvt.d.s   $f2, $f2
/* 38FC0C E009030C 46241082 */  mul.d     $f2, $f2, $f4
/* 38FC10 E0090310 00000000 */  nop
/* 38FC14 E0090314 46200020 */  cvt.s.d   $f0, $f0
/* 38FC18 E0090318 462010A0 */  cvt.s.d   $f2, $f2
/* 38FC1C E009031C E4A00030 */  swc1      $f0, 0x30($a1)
/* 38FC20 E0090320 E4A20034 */  swc1      $f2, 0x34($a1)
.LE0090324:
/* 38FC24 E0090324 10400027 */  beqz      $v0, .LE00903C4
/* 38FC28 E0090328 00000000 */   nop
/* 38FC2C E009032C C4A00030 */  lwc1      $f0, 0x30($a1)
/* 38FC30 E0090330 3C01E009 */  lui       $at, %hi(D_E0090AB0)
/* 38FC34 E0090334 D4240AB0 */  ldc1      $f4, %lo(D_E0090AB0)($at)
/* 38FC38 E0090338 080240E7 */  j         .LE009039C
/* 38FC3C E009033C 46000021 */   cvt.d.s  $f0, $f0
.LE0090340:
/* 38FC40 E0090340 29020006 */  slti      $v0, $t0, 6
/* 38FC44 E0090344 1440000F */  bnez      $v0, .LE0090384
/* 38FC48 E0090348 29020005 */   slti     $v0, $t0, 5
/* 38FC4C E009034C C4A00030 */  lwc1      $f0, 0x30($a1)
/* 38FC50 E0090350 3C01E009 */  lui       $at, %hi(D_E0090AB8)
/* 38FC54 E0090354 D4240AB8 */  ldc1      $f4, %lo(D_E0090AB8)($at)
/* 38FC58 E0090358 46000021 */  cvt.d.s   $f0, $f0
/* 38FC5C E009035C 46240002 */  mul.d     $f0, $f0, $f4
/* 38FC60 E0090360 00000000 */  nop
/* 38FC64 E0090364 C4A20034 */  lwc1      $f2, 0x34($a1)
/* 38FC68 E0090368 460010A1 */  cvt.d.s   $f2, $f2
/* 38FC6C E009036C 46241082 */  mul.d     $f2, $f2, $f4
/* 38FC70 E0090370 00000000 */  nop
/* 38FC74 E0090374 46200020 */  cvt.s.d   $f0, $f0
/* 38FC78 E0090378 462010A0 */  cvt.s.d   $f2, $f2
/* 38FC7C E009037C E4A00030 */  swc1      $f0, 0x30($a1)
/* 38FC80 E0090380 E4A20034 */  swc1      $f2, 0x34($a1)
.LE0090384:
/* 38FC84 E0090384 1040000F */  beqz      $v0, .LE00903C4
/* 38FC88 E0090388 00000000 */   nop
/* 38FC8C E009038C C4A00030 */  lwc1      $f0, 0x30($a1)
/* 38FC90 E0090390 3C01E009 */  lui       $at, %hi(D_E0090AC0)
/* 38FC94 E0090394 D4240AC0 */  ldc1      $f4, %lo(D_E0090AC0)($at)
/* 38FC98 E0090398 46000021 */  cvt.d.s   $f0, $f0
.LE009039C:
/* 38FC9C E009039C 46240002 */  mul.d     $f0, $f0, $f4
/* 38FCA0 E00903A0 00000000 */  nop
/* 38FCA4 E00903A4 C4A20034 */  lwc1      $f2, 0x34($a1)
/* 38FCA8 E00903A8 460010A1 */  cvt.d.s   $f2, $f2
/* 38FCAC E00903AC 46241082 */  mul.d     $f2, $f2, $f4
/* 38FCB0 E00903B0 00000000 */  nop
/* 38FCB4 E00903B4 46200020 */  cvt.s.d   $f0, $f0
/* 38FCB8 E00903B8 462010A0 */  cvt.s.d   $f2, $f2
/* 38FCBC E00903BC E4A00030 */  swc1      $f0, 0x30($a1)
/* 38FCC0 E00903C0 E4A20034 */  swc1      $f2, 0x34($a1)
.LE00903C4:
/* 38FCC4 E00903C4 C4A40008 */  lwc1      $f4, 8($a1)
/* 38FCC8 E00903C8 C4A00030 */  lwc1      $f0, 0x30($a1)
/* 38FCCC E00903CC C4A2000C */  lwc1      $f2, 0xc($a1)
/* 38FCD0 E00903D0 46002100 */  add.s     $f4, $f4, $f0
/* 38FCD4 E00903D4 C4A00034 */  lwc1      $f0, 0x34($a1)
/* 38FCD8 E00903D8 8CA20020 */  lw        $v0, 0x20($a1)
/* 38FCDC E00903DC 46001080 */  add.s     $f2, $f2, $f0
/* 38FCE0 E00903E0 E4A40008 */  swc1      $f4, 8($a1)
/* 38FCE4 E00903E4 1040000B */  beqz      $v0, .LE0090414
/* 38FCE8 E00903E8 E4A2000C */   swc1     $f2, 0xc($a1)
/* 38FCEC E00903EC 8CA20004 */  lw        $v0, 4($a1)
/* 38FCF0 E00903F0 24030064 */  addiu     $v1, $zero, 0x64
/* 38FCF4 E00903F4 ACA00020 */  sw        $zero, 0x20($a1)
/* 38FCF8 E00903F8 ACA3001C */  sw        $v1, 0x1c($a1)
/* 38FCFC E00903FC 24420001 */  addiu     $v0, $v0, 1
/* 38FD00 E0090400 ACA20004 */  sw        $v0, 4($a1)
/* 38FD04 E0090404 28420003 */  slti      $v0, $v0, 3
/* 38FD08 E0090408 14400002 */  bnez      $v0, .LE0090414
/* 38FD0C E009040C 24020002 */   addiu    $v0, $zero, 2
/* 38FD10 E0090410 ACA20004 */  sw        $v0, 4($a1)
.LE0090414:
/* 38FD14 E0090414 8FBF0010 */  lw        $ra, 0x10($sp)
/* 38FD18 E0090418 03E00008 */  jr        $ra
/* 38FD1C E009041C 27BD0018 */   addiu    $sp, $sp, 0x18
