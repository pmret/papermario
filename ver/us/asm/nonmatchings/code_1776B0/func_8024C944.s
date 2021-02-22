.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024C944
/* 17B224 8024C944 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 17B228 8024C948 AFB00030 */  sw        $s0, 0x30($sp)
/* 17B22C 8024C94C 3C10800B */  lui       $s0, %hi(gCameras+0x558)
/* 17B230 8024C950 261022D8 */  addiu     $s0, $s0, %lo(gCameras+0x558)
/* 17B234 8024C954 3C06800E */  lui       $a2, %hi(gBattleStatus)
/* 17B238 8024C958 24C6C070 */  addiu     $a2, $a2, %lo(gBattleStatus)
/* 17B23C 8024C95C AFBF0034 */  sw        $ra, 0x34($sp)
/* 17B240 8024C960 10A0001C */  beqz      $a1, .L8024C9D4
/* 17B244 8024C964 F7B40038 */   sdc1     $f20, 0x38($sp)
/* 17B248 8024C968 C6000054 */  lwc1      $f0, 0x54($s0)
/* 17B24C 8024C96C C6020058 */  lwc1      $f2, 0x58($s0)
/* 17B250 8024C970 C604005C */  lwc1      $f4, 0x5c($s0)
/* 17B254 8024C974 8602001E */  lh        $v0, 0x1e($s0)
/* 17B258 8024C978 86030022 */  lh        $v1, 0x22($s0)
/* 17B25C 8024C97C 3C01802A */  lui       $at, %hi(D_8029F270)
/* 17B260 8024C980 E420F270 */  swc1      $f0, %lo(D_8029F270)($at)
/* 17B264 8024C984 44820000 */  mtc1      $v0, $f0
/* 17B268 8024C988 00000000 */  nop
/* 17B26C 8024C98C 46800020 */  cvt.s.w   $f0, $f0
/* 17B270 8024C990 86020024 */  lh        $v0, 0x24($s0)
/* 17B274 8024C994 3C01802A */  lui       $at, %hi(D_8029F274)
/* 17B278 8024C998 E422F274 */  swc1      $f2, %lo(D_8029F274)($at)
/* 17B27C 8024C99C 3C01802A */  lui       $at, %hi(D_8029F278)
/* 17B280 8024C9A0 E424F278 */  swc1      $f4, %lo(D_8029F278)($at)
/* 17B284 8024C9A4 3C01802A */  lui       $at, %hi(D_8029F288)
/* 17B288 8024C9A8 E420F288 */  swc1      $f0, %lo(D_8029F288)($at)
/* 17B28C 8024C9AC 44820000 */  mtc1      $v0, $f0
/* 17B290 8024C9B0 00000000 */  nop
/* 17B294 8024C9B4 46800020 */  cvt.s.w   $f0, $f0
/* 17B298 8024C9B8 3C01802A */  lui       $at, %hi(D_8029F290)
/* 17B29C 8024C9BC E420F290 */  swc1      $f0, %lo(D_8029F290)($at)
/* 17B2A0 8024C9C0 44830000 */  mtc1      $v1, $f0
/* 17B2A4 8024C9C4 00000000 */  nop
/* 17B2A8 8024C9C8 46800020 */  cvt.s.w   $f0, $f0
/* 17B2AC 8024C9CC 3C01802A */  lui       $at, %hi(D_8029F294)
/* 17B2B0 8024C9D0 E420F294 */  swc1      $f0, %lo(D_8029F294)($at)
.L8024C9D4:
/* 17B2B4 8024C9D4 3C02802A */  lui       $v0, %hi(D_8029F27C)
/* 17B2B8 8024C9D8 9442F27C */  lhu       $v0, %lo(D_8029F27C)($v0)
/* 17B2BC 8024C9DC 4480A000 */  mtc1      $zero, $f20
/* 17B2C0 8024C9E0 30430700 */  andi      $v1, $v0, 0x700
/* 17B2C4 8024C9E4 304400FF */  andi      $a0, $v0, 0xff
/* 17B2C8 8024C9E8 24020100 */  addiu     $v0, $zero, 0x100
/* 17B2CC 8024C9EC 1062001C */  beq       $v1, $v0, .L8024CA60
/* 17B2D0 8024C9F0 28620101 */   slti     $v0, $v1, 0x101
/* 17B2D4 8024C9F4 50400005 */  beql      $v0, $zero, .L8024CA0C
/* 17B2D8 8024C9F8 24020200 */   addiu    $v0, $zero, 0x200
/* 17B2DC 8024C9FC 10600007 */  beqz      $v1, .L8024CA1C
/* 17B2E0 8024CA00 27A20020 */   addiu    $v0, $sp, 0x20
/* 17B2E4 8024CA04 080932A3 */  j         .L8024CA8C
/* 17B2E8 8024CA08 AFA20010 */   sw       $v0, 0x10($sp)
.L8024CA0C:
/* 17B2EC 8024CA0C 10620017 */  beq       $v1, $v0, .L8024CA6C
/* 17B2F0 8024CA10 27A20020 */   addiu    $v0, $sp, 0x20
/* 17B2F4 8024CA14 080932A3 */  j         .L8024CA8C
/* 17B2F8 8024CA18 AFA20010 */   sw       $v0, 0x10($sp)
.L8024CA1C:
/* 17B2FC 8024CA1C 8CC400D8 */  lw        $a0, 0xd8($a2)
/* 17B300 8024CA20 1080004C */  beqz      $a0, .L8024CB54
/* 17B304 8024CA24 0000102D */   daddu    $v0, $zero, $zero
/* 17B308 8024CA28 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* 17B30C 8024CA2C 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* 17B310 8024CA30 944200B0 */  lhu       $v0, 0xb0($v0)
/* 17B314 8024CA34 C4820148 */  lwc1      $f2, 0x148($a0)
/* 17B318 8024CA38 00021400 */  sll       $v0, $v0, 0x10
/* 17B31C 8024CA3C 00021C03 */  sra       $v1, $v0, 0x10
/* 17B320 8024CA40 000217C2 */  srl       $v0, $v0, 0x1f
/* 17B324 8024CA44 00621821 */  addu      $v1, $v1, $v0
/* 17B328 8024CA48 00031843 */  sra       $v1, $v1, 1
/* 17B32C 8024CA4C 44830000 */  mtc1      $v1, $f0
/* 17B330 8024CA50 00000000 */  nop
/* 17B334 8024CA54 46800020 */  cvt.s.w   $f0, $f0
/* 17B338 8024CA58 080932A1 */  j         .L8024CA84
/* 17B33C 8024CA5C 46001500 */   add.s    $f20, $f2, $f0
.L8024CA60:
/* 17B340 8024CA60 8CC600DC */  lw        $a2, 0xdc($a2)
/* 17B344 8024CA64 0809329E */  j         .L8024CA78
/* 17B348 8024CA68 00000000 */   nop
.L8024CA6C:
/* 17B34C 8024CA6C 00041080 */  sll       $v0, $a0, 2
/* 17B350 8024CA70 00461021 */  addu      $v0, $v0, $a2
/* 17B354 8024CA74 8C4600E0 */  lw        $a2, 0xe0($v0)
.L8024CA78:
/* 17B358 8024CA78 10C00036 */  beqz      $a2, .L8024CB54
/* 17B35C 8024CA7C 0000102D */   daddu    $v0, $zero, $zero
/* 17B360 8024CA80 C4D40148 */  lwc1      $f20, 0x148($a2)
.L8024CA84:
/* 17B364 8024CA84 27A20020 */  addiu     $v0, $sp, 0x20
/* 17B368 8024CA88 AFA20010 */  sw        $v0, 0x10($sp)
.L8024CA8C:
/* 17B36C 8024CA8C 27A20024 */  addiu     $v0, $sp, 0x24
/* 17B370 8024CA90 AFA20014 */  sw        $v0, 0x14($sp)
/* 17B374 8024CA94 27A20028 */  addiu     $v0, $sp, 0x28
/* 17B378 8024CA98 3C05802A */  lui       $a1, %hi(D_8029F270)
/* 17B37C 8024CA9C 8CA5F270 */  lw        $a1, %lo(D_8029F270)($a1)
/* 17B380 8024CAA0 4406A000 */  mfc1      $a2, $f20
/* 17B384 8024CAA4 3C07802A */  lui       $a3, %hi(D_8029F278)
/* 17B388 8024CAA8 8CE7F278 */  lw        $a3, %lo(D_8029F278)($a3)
/* 17B38C 8024CAAC 24040001 */  addiu     $a0, $zero, 1
/* 17B390 8024CAB0 0C00B94E */  jal       get_screen_coords
/* 17B394 8024CAB4 AFA20018 */   sw       $v0, 0x18($sp)
/* 17B398 8024CAB8 8FA20024 */  lw        $v0, 0x24($sp)
/* 17B39C 8024CABC 28420064 */  slti      $v0, $v0, 0x64
/* 17B3A0 8024CAC0 10400005 */  beqz      $v0, .L8024CAD8
/* 17B3A4 8024CAC4 00000000 */   nop
/* 17B3A8 8024CAC8 3C0141C8 */  lui       $at, 0x41c8
/* 17B3AC 8024CACC 44810000 */  mtc1      $at, $f0
/* 17B3B0 8024CAD0 00000000 */  nop
/* 17B3B4 8024CAD4 4600A500 */  add.s     $f20, $f20, $f0
.L8024CAD8:
/* 17B3B8 8024CAD8 3C01802A */  lui       $at, %hi(D_8029F274)
/* 17B3BC 8024CADC C420F274 */  lwc1      $f0, %lo(D_8029F274)($at)
/* 17B3C0 8024CAE0 4600A03C */  c.lt.s    $f20, $f0
/* 17B3C4 8024CAE4 00000000 */  nop
/* 17B3C8 8024CAE8 45030001 */  bc1tl     .L8024CAF0
/* 17B3CC 8024CAEC 46000506 */   mov.s    $f20, $f0
.L8024CAF0:
/* 17B3D0 8024CAF0 C6060058 */  lwc1      $f6, 0x58($s0)
/* 17B3D4 8024CAF4 4606A101 */  sub.s     $f4, $f20, $f6
/* 17B3D8 8024CAF8 3C01802A */  lui       $at, %hi(D_8029CC28)
/* 17B3DC 8024CAFC D422CC28 */  ldc1      $f2, %lo(D_8029CC28)($at)
/* 17B3E0 8024CB00 46002005 */  abs.s     $f0, $f4
/* 17B3E4 8024CB04 46000021 */  cvt.d.s   $f0, $f0
/* 17B3E8 8024CB08 4622003C */  c.lt.d    $f0, $f2
/* 17B3EC 8024CB0C 00000000 */  nop
/* 17B3F0 8024CB10 45000009 */  bc1f      .L8024CB38
/* 17B3F4 8024CB14 00000000 */   nop
/* 17B3F8 8024CB18 44800000 */  mtc1      $zero, $f0
/* 17B3FC 8024CB1C 00000000 */  nop
/* 17B400 8024CB20 46002032 */  c.eq.s    $f4, $f0
/* 17B404 8024CB24 00000000 */  nop
/* 17B408 8024CB28 45020009 */  bc1fl     .L8024CB50
/* 17B40C 8024CB2C E6140058 */   swc1     $f20, 0x58($s0)
/* 17B410 8024CB30 080932D5 */  j         .L8024CB54
/* 17B414 8024CB34 0000102D */   daddu    $v0, $zero, $zero
.L8024CB38:
/* 17B418 8024CB38 3C0140A0 */  lui       $at, 0x40a0
/* 17B41C 8024CB3C 44810000 */  mtc1      $at, $f0
/* 17B420 8024CB40 00000000 */  nop
/* 17B424 8024CB44 46002003 */  div.s     $f0, $f4, $f0
/* 17B428 8024CB48 46003000 */  add.s     $f0, $f6, $f0
/* 17B42C 8024CB4C E6000058 */  swc1      $f0, 0x58($s0)
.L8024CB50:
/* 17B430 8024CB50 0000102D */  daddu     $v0, $zero, $zero
.L8024CB54:
/* 17B434 8024CB54 8FBF0034 */  lw        $ra, 0x34($sp)
/* 17B438 8024CB58 8FB00030 */  lw        $s0, 0x30($sp)
/* 17B43C 8024CB5C D7B40038 */  ldc1      $f20, 0x38($sp)
/* 17B440 8024CB60 03E00008 */  jr        $ra
/* 17B444 8024CB64 27BD0040 */   addiu    $sp, $sp, 0x40
