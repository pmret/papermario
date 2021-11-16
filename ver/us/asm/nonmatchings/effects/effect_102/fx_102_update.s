.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_102_update
/* 3D18E8 E00CC258 27BDFF10 */  addiu     $sp, $sp, -0xf0
/* 3D18EC E00CC25C AFBF00BC */  sw        $ra, 0xbc($sp)
/* 3D18F0 E00CC260 AFBE00B8 */  sw        $fp, 0xb8($sp)
/* 3D18F4 E00CC264 AFB700B4 */  sw        $s7, 0xb4($sp)
/* 3D18F8 E00CC268 AFB600B0 */  sw        $s6, 0xb0($sp)
/* 3D18FC E00CC26C AFB500AC */  sw        $s5, 0xac($sp)
/* 3D1900 E00CC270 AFB400A8 */  sw        $s4, 0xa8($sp)
/* 3D1904 E00CC274 AFB300A4 */  sw        $s3, 0xa4($sp)
/* 3D1908 E00CC278 AFB200A0 */  sw        $s2, 0xa0($sp)
/* 3D190C E00CC27C AFB1009C */  sw        $s1, 0x9c($sp)
/* 3D1910 E00CC280 AFB00098 */  sw        $s0, 0x98($sp)
/* 3D1914 E00CC284 F7BE00E8 */  sdc1      $f30, 0xe8($sp)
/* 3D1918 E00CC288 F7BC00E0 */  sdc1      $f28, 0xe0($sp)
/* 3D191C E00CC28C F7BA00D8 */  sdc1      $f26, 0xd8($sp)
/* 3D1920 E00CC290 F7B800D0 */  sdc1      $f24, 0xd0($sp)
/* 3D1924 E00CC294 F7B600C8 */  sdc1      $f22, 0xc8($sp)
/* 3D1928 E00CC298 F7B400C0 */  sdc1      $f20, 0xc0($sp)
/* 3D192C E00CC29C 8C830000 */  lw        $v1, ($a0)
/* 3D1930 E00CC2A0 8C92000C */  lw        $s2, 0xc($a0)
/* 3D1934 E00CC2A4 30620010 */  andi      $v0, $v1, 0x10
/* 3D1938 E00CC2A8 8E5E0000 */  lw        $fp, ($s2)
/* 3D193C E00CC2AC 10400005 */  beqz      $v0, .LE00CC2C4
/* 3D1940 E00CC2B0 2402FFEF */   addiu    $v0, $zero, -0x11
/* 3D1944 E00CC2B4 00621024 */  and       $v0, $v1, $v0
/* 3D1948 E00CC2B8 AC820000 */  sw        $v0, ($a0)
/* 3D194C E00CC2BC 24020040 */  addiu     $v0, $zero, 0x40
/* 3D1950 E00CC2C0 AE420010 */  sw        $v0, 0x10($s2)
.LE00CC2C4:
/* 3D1954 E00CC2C4 8E430010 */  lw        $v1, 0x10($s2)
/* 3D1958 E00CC2C8 286203E8 */  slti      $v0, $v1, 0x3e8
/* 3D195C E00CC2CC 10400002 */  beqz      $v0, .LE00CC2D8
/* 3D1960 E00CC2D0 2462FFFF */   addiu    $v0, $v1, -1
/* 3D1964 E00CC2D4 AE420010 */  sw        $v0, 0x10($s2)
.LE00CC2D8:
/* 3D1968 E00CC2D8 8E420014 */  lw        $v0, 0x14($s2)
/* 3D196C E00CC2DC 8E430010 */  lw        $v1, 0x10($s2)
/* 3D1970 E00CC2E0 24420001 */  addiu     $v0, $v0, 1
/* 3D1974 E00CC2E4 04610005 */  bgez      $v1, .LE00CC2FC
/* 3D1978 E00CC2E8 AE420014 */   sw       $v0, 0x14($s2)
/* 3D197C E00CC2EC 0C080128 */  jal       shim_remove_effect
/* 3D1980 E00CC2F0 00000000 */   nop
/* 3D1984 E00CC2F4 0803324E */  j         .LE00CC938
/* 3D1988 E00CC2F8 00000000 */   nop
.LE00CC2FC:
/* 3D198C E00CC2FC 0040B02D */  daddu     $s6, $v0, $zero
/* 3D1990 E00CC300 0000982D */  daddu     $s3, $zero, $zero
/* 3D1994 E00CC304 3C17E00D */  lui       $s7, %hi(D_E00CCDD8)
/* 3D1998 E00CC308 26F7CDD8 */  addiu     $s7, $s7, %lo(D_E00CCDD8)
/* 3D199C E00CC30C 0240882D */  daddu     $s1, $s2, $zero
/* 3D19A0 E00CC310 0260A82D */  daddu     $s5, $s3, $zero
/* 3D19A4 E00CC314 0260A02D */  daddu     $s4, $s3, $zero
/* 3D19A8 E00CC318 4480F000 */  mtc1      $zero, $f30
/* 3D19AC E00CC31C 3C01E00D */  lui       $at, %hi(D_E00CCE70)
/* 3D19B0 E00CC320 D43ACE70 */  ldc1      $f26, %lo(D_E00CCE70)($at)
/* 3D19B4 E00CC324 3C013F80 */  lui       $at, 0x3f80
/* 3D19B8 E00CC328 4481E000 */  mtc1      $at, $f28
/* 3D19BC E00CC32C 3C013FE0 */  lui       $at, 0x3fe0
/* 3D19C0 E00CC330 4481C800 */  mtc1      $at, $f25
/* 3D19C4 E00CC334 4480C000 */  mtc1      $zero, $f24
.LE00CC338:
/* 3D19C8 E00CC338 3C029249 */  lui       $v0, 0x9249
/* 3D19CC E00CC33C 34422493 */  ori       $v0, $v0, 0x2493
/* 3D19D0 E00CC340 02C20018 */  mult      $s6, $v0
/* 3D19D4 E00CC344 001617C3 */  sra       $v0, $s6, 0x1f
/* 3D19D8 E00CC348 3C013C23 */  lui       $at, 0x3c23
/* 3D19DC E00CC34C 3421D70A */  ori       $at, $at, 0xd70a
/* 3D19E0 E00CC350 44811000 */  mtc1      $at, $f2
/* 3D19E4 E00CC354 00004010 */  mfhi      $t0
/* 3D19E8 E00CC358 01161821 */  addu      $v1, $t0, $s6
/* 3D19EC E00CC35C 00031883 */  sra       $v1, $v1, 2
/* 3D19F0 E00CC360 00621823 */  subu      $v1, $v1, $v0
/* 3D19F4 E00CC364 000310C0 */  sll       $v0, $v1, 3
/* 3D19F8 E00CC368 00431023 */  subu      $v0, $v0, $v1
/* 3D19FC E00CC36C 02C21023 */  subu      $v0, $s6, $v0
/* 3D1A00 E00CC370 3C08E00D */  lui       $t0, %hi(D_E00CCDD0)
/* 3D1A04 E00CC374 2508CDD0 */  addiu     $t0, $t0, %lo(D_E00CCDD0)
/* 3D1A08 E00CC378 00481021 */  addu      $v0, $v0, $t0
/* 3D1A0C E00CC37C 90420000 */  lbu       $v0, ($v0)
/* 3D1A10 E00CC380 C6260158 */  lwc1      $f6, 0x158($s1)
/* 3D1A14 E00CC384 44820000 */  mtc1      $v0, $f0
/* 3D1A18 E00CC388 00000000 */  nop
/* 3D1A1C E00CC38C 46800020 */  cvt.s.w   $f0, $f0
/* 3D1A20 E00CC390 46020002 */  mul.s     $f0, $f0, $f2
/* 3D1A24 E00CC394 00000000 */  nop
/* 3D1A28 E00CC398 C62801BC */  lwc1      $f8, 0x1bc($s1)
/* 3D1A2C E00CC39C C62A0220 */  lwc1      $f10, 0x220($s1)
/* 3D1A30 E00CC3A0 3C014000 */  lui       $at, 0x4000
/* 3D1A34 E00CC3A4 44811000 */  mtc1      $at, $f2
/* 3D1A38 E00CC3A8 8E2306D0 */  lw        $v1, 0x6d0($s1)
/* 3D1A3C E00CC3AC 46001081 */  sub.s     $f2, $f2, $f0
/* 3D1A40 E00CC3B0 2C620015 */  sltiu     $v0, $v1, 0x15
/* 3D1A44 E00CC3B4 E6200414 */  swc1      $f0, 0x414($s1)
/* 3D1A48 E00CC3B8 10400159 */  beqz      $v0, LE00CC920_3D1FB0
/* 3D1A4C E00CC3BC E62203B0 */   swc1     $f2, 0x3b0($s1)
/* 3D1A50 E00CC3C0 00031080 */  sll       $v0, $v1, 2
/* 3D1A54 E00CC3C4 3C01E00D */  lui       $at, %hi(jtbl_E00CCE78)
/* 3D1A58 E00CC3C8 00220821 */  addu      $at, $at, $v0
/* 3D1A5C E00CC3CC 8C22CE78 */  lw        $v0, %lo(jtbl_E00CCE78)($at)
/* 3D1A60 E00CC3D0 00400008 */  jr        $v0
/* 3D1A64 E00CC3D4 00000000 */   nop
dlabel LE00CC3D8_3D1A68
/* 3D1A68 E00CC3D8 C62004DC */  lwc1      $f0, 0x4dc($s1)
/* 3D1A6C E00CC3DC 8E22066C */  lw        $v0, 0x66c($s1)
/* 3D1A70 E00CC3E0 E626002C */  swc1      $f6, 0x2c($s1)
/* 3D1A74 E00CC3E4 461E0000 */  add.s     $f0, $f0, $f30
/* 3D1A78 E00CC3E8 E6280090 */  swc1      $f8, 0x90($s1)
/* 3D1A7C E00CC3EC E62A00F4 */  swc1      $f10, 0xf4($s1)
/* 3D1A80 E00CC3F0 10400004 */  beqz      $v0, .LE00CC404
/* 3D1A84 E00CC3F4 E62004DC */   swc1     $f0, 0x4dc($s1)
/* 3D1A88 E00CC3F8 2442FFFF */  addiu     $v0, $v0, -1
/* 3D1A8C E00CC3FC 08033248 */  j         LE00CC920_3D1FB0
/* 3D1A90 E00CC400 AE22066C */   sw       $v0, 0x66c($s1)
.LE00CC404:
/* 3D1A94 E00CC404 8E230734 */  lw        $v1, 0x734($s1)
/* 3D1A98 E00CC408 24020001 */  addiu     $v0, $zero, 1
/* 3D1A9C E00CC40C AE2206D0 */  sw        $v0, 0x6d0($s1)
/* 3D1AA0 E00CC410 00771821 */  addu      $v1, $v1, $s7
/* 3D1AA4 E00CC414 90620000 */  lbu       $v0, ($v1)
/* 3D1AA8 E00CC418 44820000 */  mtc1      $v0, $f0
/* 3D1AAC E00CC41C 00000000 */  nop
/* 3D1AB0 E00CC420 46800021 */  cvt.d.w   $f0, $f0
/* 3D1AB4 E00CC424 463A0002 */  mul.d     $f0, $f0, $f26
/* 3D1AB8 E00CC428 00000000 */  nop
/* 3D1ABC E00CC42C 8E220734 */  lw        $v0, 0x734($s1)
/* 3D1AC0 E00CC430 24420001 */  addiu     $v0, $v0, 1
/* 3D1AC4 E00CC434 AE220734 */  sw        $v0, 0x734($s1)
/* 3D1AC8 E00CC438 46200020 */  cvt.s.d   $f0, $f0
/* 3D1ACC E00CC43C E6200414 */  swc1      $f0, 0x414($s1)
/* 3D1AD0 E00CC440 08033248 */  j         LE00CC920_3D1FB0
/* 3D1AD4 E00CC444 E62003B0 */   swc1     $f0, 0x3b0($s1)
dlabel LE00CC448_3D1AD8
/* 3D1AD8 E00CC448 8E220734 */  lw        $v0, 0x734($s1)
/* 3D1ADC E00CC44C 00571021 */  addu      $v0, $v0, $s7
/* 3D1AE0 E00CC450 90420000 */  lbu       $v0, ($v0)
/* 3D1AE4 E00CC454 44820000 */  mtc1      $v0, $f0
/* 3D1AE8 E00CC458 00000000 */  nop
/* 3D1AEC E00CC45C 46800021 */  cvt.d.w   $f0, $f0
/* 3D1AF0 E00CC460 463A0002 */  mul.d     $f0, $f0, $f26
/* 3D1AF4 E00CC464 00000000 */  nop
/* 3D1AF8 E00CC468 C62204DC */  lwc1      $f2, 0x4dc($s1)
/* 3D1AFC E00CC46C 8E220734 */  lw        $v0, 0x734($s1)
/* 3D1B00 E00CC470 461E1080 */  add.s     $f2, $f2, $f30
/* 3D1B04 E00CC474 24420001 */  addiu     $v0, $v0, 1
/* 3D1B08 E00CC478 AE220734 */  sw        $v0, 0x734($s1)
/* 3D1B0C E00CC47C 28420008 */  slti      $v0, $v0, 8
/* 3D1B10 E00CC480 E62204DC */  swc1      $f2, 0x4dc($s1)
/* 3D1B14 E00CC484 46200020 */  cvt.s.d   $f0, $f0
/* 3D1B18 E00CC488 E6200414 */  swc1      $f0, 0x414($s1)
/* 3D1B1C E00CC48C 14400124 */  bnez      $v0, LE00CC920_3D1FB0
/* 3D1B20 E00CC490 E62003B0 */   swc1     $f0, 0x3b0($s1)
/* 3D1B24 E00CC494 17C00050 */  bnez      $fp, .LE00CC5D8
/* 3D1B28 E00CC498 24020014 */   addiu    $v0, $zero, 0x14
/* 3D1B2C E00CC49C 08033176 */  j         .LE00CC5D8
/* 3D1B30 E00CC4A0 24020002 */   addiu    $v0, $zero, 2
dlabel LE00CC4A4_3D1B34
/* 3D1B34 E00CC4A4 C62004DC */  lwc1      $f0, 0x4dc($s1)
/* 3D1B38 E00CC4A8 461E0000 */  add.s     $f0, $f0, $f30
/* 3D1B3C E00CC4AC 8E220734 */  lw        $v0, 0x734($s1)
/* 3D1B40 E00CC4B0 E62004DC */  swc1      $f0, 0x4dc($s1)
/* 3D1B44 E00CC4B4 3C01E00D */  lui       $at, %hi(D_E00CCDF0)
/* 3D1B48 E00CC4B8 00220821 */  addu      $at, $at, $v0
/* 3D1B4C E00CC4BC 9022CDF0 */  lbu       $v0, %lo(D_E00CCDF0)($at)
/* 3D1B50 E00CC4C0 44820000 */  mtc1      $v0, $f0
/* 3D1B54 E00CC4C4 00000000 */  nop
/* 3D1B58 E00CC4C8 46800021 */  cvt.d.w   $f0, $f0
/* 3D1B5C E00CC4CC 463A0002 */  mul.d     $f0, $f0, $f26
/* 3D1B60 E00CC4D0 00000000 */  nop
/* 3D1B64 E00CC4D4 C6240284 */  lwc1      $f4, 0x284($s1)
/* 3D1B68 E00CC4D8 46062101 */  sub.s     $f4, $f4, $f6
/* 3D1B6C E00CC4DC 462005A0 */  cvt.s.d   $f22, $f0
/* 3D1B70 E00CC4E0 46162102 */  mul.s     $f4, $f4, $f22
/* 3D1B74 E00CC4E4 00000000 */  nop
/* 3D1B78 E00CC4E8 C62202E8 */  lwc1      $f2, 0x2e8($s1)
/* 3D1B7C E00CC4EC 46081081 */  sub.s     $f2, $f2, $f8
/* 3D1B80 E00CC4F0 46161082 */  mul.s     $f2, $f2, $f22
/* 3D1B84 E00CC4F4 00000000 */  nop
/* 3D1B88 E00CC4F8 C620034C */  lwc1      $f0, 0x34c($s1)
/* 3D1B8C E00CC4FC 460A0001 */  sub.s     $f0, $f0, $f10
/* 3D1B90 E00CC500 46160002 */  mul.s     $f0, $f0, $f22
/* 3D1B94 E00CC504 00000000 */  nop
/* 3D1B98 E00CC508 E63C0414 */  swc1      $f28, 0x414($s1)
/* 3D1B9C E00CC50C 8E220734 */  lw        $v0, 0x734($s1)
/* 3D1BA0 E00CC510 46043100 */  add.s     $f4, $f6, $f4
/* 3D1BA4 E00CC514 E63C03B0 */  swc1      $f28, 0x3b0($s1)
/* 3D1BA8 E00CC518 24420001 */  addiu     $v0, $v0, 1
/* 3D1BAC E00CC51C 46024080 */  add.s     $f2, $f8, $f2
/* 3D1BB0 E00CC520 AE220734 */  sw        $v0, 0x734($s1)
/* 3D1BB4 E00CC524 28420014 */  slti      $v0, $v0, 0x14
/* 3D1BB8 E00CC528 46005000 */  add.s     $f0, $f10, $f0
/* 3D1BBC E00CC52C E624002C */  swc1      $f4, 0x2c($s1)
/* 3D1BC0 E00CC530 E6220090 */  swc1      $f2, 0x90($s1)
/* 3D1BC4 E00CC534 080331CC */  j         .LE00CC730
/* 3D1BC8 E00CC538 E62000F4 */   swc1     $f0, 0xf4($s1)
dlabel LE00CC53C_3D1BCC
/* 3D1BCC E00CC53C C62004DC */  lwc1      $f0, 0x4dc($s1)
/* 3D1BD0 E00CC540 461E0000 */  add.s     $f0, $f0, $f30
/* 3D1BD4 E00CC544 8E220734 */  lw        $v0, 0x734($s1)
/* 3D1BD8 E00CC548 E62004DC */  swc1      $f0, 0x4dc($s1)
/* 3D1BDC E00CC54C 3C01E00D */  lui       $at, %hi(D_E00CCDE0)
/* 3D1BE0 E00CC550 00220821 */  addu      $at, $at, $v0
/* 3D1BE4 E00CC554 9022CDE0 */  lbu       $v0, %lo(D_E00CCDE0)($at)
/* 3D1BE8 E00CC558 44820000 */  mtc1      $v0, $f0
/* 3D1BEC E00CC55C 00000000 */  nop
/* 3D1BF0 E00CC560 46800021 */  cvt.d.w   $f0, $f0
/* 3D1BF4 E00CC564 463A0002 */  mul.d     $f0, $f0, $f26
/* 3D1BF8 E00CC568 00000000 */  nop
/* 3D1BFC E00CC56C C6240284 */  lwc1      $f4, 0x284($s1)
/* 3D1C00 E00CC570 46062101 */  sub.s     $f4, $f4, $f6
/* 3D1C04 E00CC574 462005A0 */  cvt.s.d   $f22, $f0
/* 3D1C08 E00CC578 46162102 */  mul.s     $f4, $f4, $f22
/* 3D1C0C E00CC57C 00000000 */  nop
/* 3D1C10 E00CC580 C62202E8 */  lwc1      $f2, 0x2e8($s1)
/* 3D1C14 E00CC584 46081081 */  sub.s     $f2, $f2, $f8
/* 3D1C18 E00CC588 46161082 */  mul.s     $f2, $f2, $f22
/* 3D1C1C E00CC58C 00000000 */  nop
/* 3D1C20 E00CC590 C620034C */  lwc1      $f0, 0x34c($s1)
/* 3D1C24 E00CC594 460A0001 */  sub.s     $f0, $f0, $f10
/* 3D1C28 E00CC598 46160002 */  mul.s     $f0, $f0, $f22
/* 3D1C2C E00CC59C 00000000 */  nop
/* 3D1C30 E00CC5A0 E63C0414 */  swc1      $f28, 0x414($s1)
/* 3D1C34 E00CC5A4 8E220734 */  lw        $v0, 0x734($s1)
/* 3D1C38 E00CC5A8 46043100 */  add.s     $f4, $f6, $f4
/* 3D1C3C E00CC5AC E63C03B0 */  swc1      $f28, 0x3b0($s1)
/* 3D1C40 E00CC5B0 24420001 */  addiu     $v0, $v0, 1
/* 3D1C44 E00CC5B4 46024080 */  add.s     $f2, $f8, $f2
/* 3D1C48 E00CC5B8 AE220734 */  sw        $v0, 0x734($s1)
/* 3D1C4C E00CC5BC 2842000F */  slti      $v0, $v0, 0xf
/* 3D1C50 E00CC5C0 46005000 */  add.s     $f0, $f10, $f0
/* 3D1C54 E00CC5C4 E624002C */  swc1      $f4, 0x2c($s1)
/* 3D1C58 E00CC5C8 E6220090 */  swc1      $f2, 0x90($s1)
/* 3D1C5C E00CC5CC 144000D4 */  bnez      $v0, LE00CC920_3D1FB0
/* 3D1C60 E00CC5D0 E62000F4 */   swc1     $f0, 0xf4($s1)
/* 3D1C64 E00CC5D4 24020003 */  addiu     $v0, $zero, 3
.LE00CC5D8:
/* 3D1C68 E00CC5D8 AE2206D0 */  sw        $v0, 0x6d0($s1)
/* 3D1C6C E00CC5DC 08033248 */  j         LE00CC920_3D1FB0
/* 3D1C70 E00CC5E0 AE200734 */   sw       $zero, 0x734($s1)
dlabel LE00CC5E4_3D1C74
/* 3D1C74 E00CC5E4 24020018 */  addiu     $v0, $zero, 0x18
/* 3D1C78 E00CC5E8 566200CE */  bnel      $s3, $v0, .LE00CC924
/* 3D1C7C E00CC5EC 26310004 */   addiu    $s1, $s1, 4
/* 3D1C80 E00CC5F0 24040004 */  addiu     $a0, $zero, 4
/* 3D1C84 E00CC5F4 0040182D */  daddu     $v1, $v0, $zero
/* 3D1C88 E00CC5F8 26420060 */  addiu     $v0, $s2, 0x60
.LE00CC5FC:
/* 3D1C8C E00CC5FC AC4406D0 */  sw        $a0, 0x6d0($v0)
/* 3D1C90 E00CC600 2463FFFF */  addiu     $v1, $v1, -1
/* 3D1C94 E00CC604 0461FFFD */  bgez      $v1, .LE00CC5FC
/* 3D1C98 E00CC608 2442FFFC */   addiu    $v0, $v0, -4
/* 3D1C9C E00CC60C 08033249 */  j         .LE00CC924
/* 3D1CA0 E00CC610 26310004 */   addiu    $s1, $s1, 4
dlabel LE00CC614_3D1CA4
/* 3D1CA4 E00CC614 8E220734 */  lw        $v0, 0x734($s1)
/* 3D1CA8 E00CC618 3C01E00D */  lui       $at, %hi(D_E00CCE04)
/* 3D1CAC E00CC61C 00220821 */  addu      $at, $at, $v0
/* 3D1CB0 E00CC620 9022CE04 */  lbu       $v0, %lo(D_E00CCE04)($at)
/* 3D1CB4 E00CC624 44820000 */  mtc1      $v0, $f0
/* 3D1CB8 E00CC628 00000000 */  nop
/* 3D1CBC E00CC62C 46800021 */  cvt.d.w   $f0, $f0
/* 3D1CC0 E00CC630 463A0002 */  mul.d     $f0, $f0, $f26
/* 3D1CC4 E00CC634 00000000 */  nop
/* 3D1CC8 E00CC638 3C1051EB */  lui       $s0, 0x51eb
/* 3D1CCC E00CC63C 3610851F */  ori       $s0, $s0, 0x851f
/* 3D1CD0 E00CC640 02900018 */  mult      $s4, $s0
/* 3D1CD4 E00CC644 00141FC3 */  sra       $v1, $s4, 0x1f
/* 3D1CD8 E00CC648 00004010 */  mfhi      $t0
/* 3D1CDC E00CC64C 000810C3 */  sra       $v0, $t0, 3
/* 3D1CE0 E00CC650 00431023 */  subu      $v0, $v0, $v1
/* 3D1CE4 E00CC654 44826000 */  mtc1      $v0, $f12
/* 3D1CE8 E00CC658 00000000 */  nop
/* 3D1CEC E00CC65C 46806320 */  cvt.s.w   $f12, $f12
/* 3D1CF0 E00CC660 0C080144 */  jal       shim_cos_deg
/* 3D1CF4 E00CC664 462005A0 */   cvt.s.d  $f22, $f0
/* 3D1CF8 E00CC668 4616E081 */  sub.s     $f2, $f28, $f22
/* 3D1CFC E00CC66C 3C014487 */  lui       $at, 0x4487
/* 3D1D00 E00CC670 44812000 */  mtc1      $at, $f4
/* 3D1D04 E00CC674 00000000 */  nop
/* 3D1D08 E00CC678 46041082 */  mul.s     $f2, $f2, $f4
/* 3D1D0C E00CC67C 00000000 */  nop
/* 3D1D10 E00CC680 460010A1 */  cvt.d.s   $f2, $f2
/* 3D1D14 E00CC684 46381082 */  mul.d     $f2, $f2, $f24
/* 3D1D18 E00CC688 00000000 */  nop
/* 3D1D1C E00CC68C 46000021 */  cvt.d.s   $f0, $f0
/* 3D1D20 E00CC690 46201082 */  mul.d     $f2, $f2, $f0
/* 3D1D24 E00CC694 00000000 */  nop
/* 3D1D28 E00CC698 02B00018 */  mult      $s5, $s0
/* 3D1D2C E00CC69C 00151FC3 */  sra       $v1, $s5, 0x1f
/* 3D1D30 E00CC6A0 00004010 */  mfhi      $t0
/* 3D1D34 E00CC6A4 000810C3 */  sra       $v0, $t0, 3
/* 3D1D38 E00CC6A8 00431023 */  subu      $v0, $v0, $v1
/* 3D1D3C E00CC6AC 4482A000 */  mtc1      $v0, $f20
/* 3D1D40 E00CC6B0 00000000 */  nop
/* 3D1D44 E00CC6B4 4680A521 */  cvt.d.w   $f20, $f20
/* 3D1D48 E00CC6B8 4622A500 */  add.d     $f20, $f20, $f2
/* 3D1D4C E00CC6BC 4620A520 */  cvt.s.d   $f20, $f20
/* 3D1D50 E00CC6C0 0C080140 */  jal       shim_sin_deg
/* 3D1D54 E00CC6C4 4600A306 */   mov.s    $f12, $f20
/* 3D1D58 E00CC6C8 4600A306 */  mov.s     $f12, $f20
/* 3D1D5C E00CC6CC 0C080144 */  jal       shim_cos_deg
/* 3D1D60 E00CC6D0 46000506 */   mov.s    $f20, $f0
/* 3D1D64 E00CC6D4 3C014170 */  lui       $at, 0x4170
/* 3D1D68 E00CC6D8 44811000 */  mtc1      $at, $f2
/* 3D1D6C E00CC6DC 00000000 */  nop
/* 3D1D70 E00CC6E0 46161083 */  div.s     $f2, $f2, $f22
/* 3D1D74 E00CC6E4 46161083 */  div.s     $f2, $f2, $f22
/* 3D1D78 E00CC6E8 46141502 */  mul.s     $f20, $f2, $f20
/* 3D1D7C E00CC6EC 00000000 */  nop
/* 3D1D80 E00CC6F0 8E220734 */  lw        $v0, 0x734($s1)
/* 3D1D84 E00CC6F4 46001082 */  mul.s     $f2, $f2, $f0
/* 3D1D88 E00CC6F8 00000000 */  nop
/* 3D1D8C E00CC6FC E634002C */  swc1      $f20, 0x2c($s1)
/* 3D1D90 E00CC700 3C03E00D */  lui       $v1, %hi(D_E00CCE4C)
/* 3D1D94 E00CC704 00731821 */  addu      $v1, $v1, $s3
/* 3D1D98 E00CC708 8063CE4C */  lb        $v1, %lo(D_E00CCE4C)($v1)
/* 3D1D9C E00CC70C 24420001 */  addiu     $v0, $v0, 1
/* 3D1DA0 E00CC710 AE220734 */  sw        $v0, 0x734($s1)
/* 3D1DA4 E00CC714 28420046 */  slti      $v0, $v0, 0x46
/* 3D1DA8 E00CC718 E62200F4 */  swc1      $f2, 0xf4($s1)
/* 3D1DAC E00CC71C 2463000A */  addiu     $v1, $v1, 0xa
/* 3D1DB0 E00CC720 44830000 */  mtc1      $v1, $f0
/* 3D1DB4 E00CC724 00000000 */  nop
/* 3D1DB8 E00CC728 46800020 */  cvt.s.w   $f0, $f0
/* 3D1DBC E00CC72C E6200090 */  swc1      $f0, 0x90($s1)
.LE00CC730:
/* 3D1DC0 E00CC730 5440007C */  bnel      $v0, $zero, .LE00CC924
/* 3D1DC4 E00CC734 26310004 */   addiu    $s1, $s1, 4
/* 3D1DC8 E00CC738 C6240284 */  lwc1      $f4, 0x284($s1)
/* 3D1DCC E00CC73C 46002121 */  cvt.d.s   $f4, $f4
/* 3D1DD0 E00CC740 46382102 */  mul.d     $f4, $f4, $f24
/* 3D1DD4 E00CC744 00000000 */  nop
/* 3D1DD8 E00CC748 C62202E8 */  lwc1      $f2, 0x2e8($s1)
/* 3D1DDC E00CC74C 460010A1 */  cvt.d.s   $f2, $f2
/* 3D1DE0 E00CC750 46381082 */  mul.d     $f2, $f2, $f24
/* 3D1DE4 E00CC754 00000000 */  nop
/* 3D1DE8 E00CC758 C620034C */  lwc1      $f0, 0x34c($s1)
/* 3D1DEC E00CC75C 46000021 */  cvt.d.s   $f0, $f0
/* 3D1DF0 E00CC760 46380002 */  mul.d     $f0, $f0, $f24
/* 3D1DF4 E00CC764 00000000 */  nop
/* 3D1DF8 E00CC768 24020005 */  addiu     $v0, $zero, 5
/* 3D1DFC E00CC76C AE2206D0 */  sw        $v0, 0x6d0($s1)
/* 3D1E00 E00CC770 AE200734 */  sw        $zero, 0x734($s1)
/* 3D1E04 E00CC774 46202120 */  cvt.s.d   $f4, $f4
/* 3D1E08 E00CC778 462010A0 */  cvt.s.d   $f2, $f2
/* 3D1E0C E00CC77C 46200020 */  cvt.s.d   $f0, $f0
/* 3D1E10 E00CC780 E6240540 */  swc1      $f4, 0x540($s1)
/* 3D1E14 E00CC784 E62205A4 */  swc1      $f2, 0x5a4($s1)
/* 3D1E18 E00CC788 08033248 */  j         LE00CC920_3D1FB0
/* 3D1E1C E00CC78C E6200608 */   swc1     $f0, 0x608($s1)
dlabel LE00CC790_3D1E20
/* 3D1E20 E00CC790 C6260540 */  lwc1      $f6, 0x540($s1)
/* 3D1E24 E00CC794 3C01E00D */  lui       $at, %hi(D_E00CCED0)
/* 3D1E28 E00CC798 D42CCED0 */  ldc1      $f12, %lo(D_E00CCED0)($at)
/* 3D1E2C E00CC79C 460031A1 */  cvt.d.s   $f6, $f6
/* 3D1E30 E00CC7A0 462C3182 */  mul.d     $f6, $f6, $f12
/* 3D1E34 E00CC7A4 00000000 */  nop
/* 3D1E38 E00CC7A8 C62405A4 */  lwc1      $f4, 0x5a4($s1)
/* 3D1E3C E00CC7AC 46002121 */  cvt.d.s   $f4, $f4
/* 3D1E40 E00CC7B0 462C2102 */  mul.d     $f4, $f4, $f12
/* 3D1E44 E00CC7B4 00000000 */  nop
/* 3D1E48 E00CC7B8 C6280608 */  lwc1      $f8, 0x608($s1)
/* 3D1E4C E00CC7BC 46004086 */  mov.s     $f2, $f8
/* 3D1E50 E00CC7C0 460010A1 */  cvt.d.s   $f2, $f2
/* 3D1E54 E00CC7C4 462C1082 */  mul.d     $f2, $f2, $f12
/* 3D1E58 E00CC7C8 00000000 */  nop
/* 3D1E5C E00CC7CC C62E002C */  lwc1      $f14, 0x2c($s1)
/* 3D1E60 E00CC7D0 C6200540 */  lwc1      $f0, 0x540($s1)
/* 3D1E64 E00CC7D4 C62A0090 */  lwc1      $f10, 0x90($s1)
/* 3D1E68 E00CC7D8 8E220734 */  lw        $v0, 0x734($s1)
/* 3D1E6C E00CC7DC 46007380 */  add.s     $f14, $f14, $f0
/* 3D1E70 E00CC7E0 C62005A4 */  lwc1      $f0, 0x5a4($s1)
/* 3D1E74 E00CC7E4 24420001 */  addiu     $v0, $v0, 1
/* 3D1E78 E00CC7E8 AE220734 */  sw        $v0, 0x734($s1)
/* 3D1E7C E00CC7EC 46005280 */  add.s     $f10, $f10, $f0
/* 3D1E80 E00CC7F0 C62000F4 */  lwc1      $f0, 0xf4($s1)
/* 3D1E84 E00CC7F4 28420011 */  slti      $v0, $v0, 0x11
/* 3D1E88 E00CC7F8 46080000 */  add.s     $f0, $f0, $f8
/* 3D1E8C E00CC7FC E62E002C */  swc1      $f14, 0x2c($s1)
/* 3D1E90 E00CC800 E62A0090 */  swc1      $f10, 0x90($s1)
/* 3D1E94 E00CC804 E62000F4 */  swc1      $f0, 0xf4($s1)
/* 3D1E98 E00CC808 462031A0 */  cvt.s.d   $f6, $f6
/* 3D1E9C E00CC80C 46202120 */  cvt.s.d   $f4, $f4
/* 3D1EA0 E00CC810 E62405A4 */  swc1      $f4, 0x5a4($s1)
/* 3D1EA4 E00CC814 46002006 */  mov.s     $f0, $f4
/* 3D1EA8 E00CC818 46000021 */  cvt.d.s   $f0, $f0
/* 3D1EAC E00CC81C 3C01E00D */  lui       $at, %hi(D_E00CCED8)
/* 3D1EB0 E00CC820 D424CED8 */  ldc1      $f4, %lo(D_E00CCED8)($at)
/* 3D1EB4 E00CC824 462010A0 */  cvt.s.d   $f2, $f2
/* 3D1EB8 E00CC828 46240000 */  add.d     $f0, $f0, $f4
/* 3D1EBC E00CC82C E6260540 */  swc1      $f6, 0x540($s1)
/* 3D1EC0 E00CC830 E6220608 */  swc1      $f2, 0x608($s1)
/* 3D1EC4 E00CC834 46200020 */  cvt.s.d   $f0, $f0
/* 3D1EC8 E00CC838 14400004 */  bnez      $v0, .LE00CC84C
/* 3D1ECC E00CC83C E62005A4 */   swc1     $f0, 0x5a4($s1)
/* 3D1ED0 E00CC840 24020006 */  addiu     $v0, $zero, 6
/* 3D1ED4 E00CC844 AE200734 */  sw        $zero, 0x734($s1)
/* 3D1ED8 E00CC848 AE2206D0 */  sw        $v0, 0x6d0($s1)
.LE00CC84C:
/* 3D1EDC E00CC84C C6200478 */  lwc1      $f0, 0x478($s1)
/* 3D1EE0 E00CC850 3C01E00D */  lui       $at, %hi(D_E00CCEE0)
/* 3D1EE4 E00CC854 D422CEE0 */  ldc1      $f2, %lo(D_E00CCEE0)($at)
/* 3D1EE8 E00CC858 46000021 */  cvt.d.s   $f0, $f0
/* 3D1EEC E00CC85C 46220002 */  mul.d     $f0, $f0, $f2
/* 3D1EF0 E00CC860 00000000 */  nop
/* 3D1EF4 E00CC864 46200020 */  cvt.s.d   $f0, $f0
/* 3D1EF8 E00CC868 08033248 */  j         LE00CC920_3D1FB0
/* 3D1EFC E00CC86C E6200478 */   swc1     $f0, 0x478($s1)
dlabel LE00CC870_3D1F00
/* 3D1F00 E00CC870 0C080150 */  jal       shim_load_effect
/* 3D1F04 E00CC874 24040069 */   addiu    $a0, $zero, 0x69
/* 3D1F08 E00CC878 E7BE0010 */  swc1      $f30, 0x10($sp)
/* 3D1F0C E00CC87C 8E2504DC */  lw        $a1, 0x4dc($s1)
/* 3D1F10 E00CC880 4406F000 */  mfc1      $a2, $f30
/* 3D1F14 E00CC884 4407E000 */  mfc1      $a3, $f28
/* 3D1F18 E00CC888 0C080104 */  jal       shim_guRotateF
/* 3D1F1C E00CC88C 27A40018 */   addiu    $a0, $sp, 0x18
/* 3D1F20 E00CC890 27B00058 */  addiu     $s0, $sp, 0x58
/* 3D1F24 E00CC894 8E25002C */  lw        $a1, 0x2c($s1)
/* 3D1F28 E00CC898 8E260090 */  lw        $a2, 0x90($s1)
/* 3D1F2C E00CC89C 8E2700F4 */  lw        $a3, 0xf4($s1)
/* 3D1F30 E00CC8A0 0C080108 */  jal       shim_guTranslateF
/* 3D1F34 E00CC8A4 0200202D */   daddu    $a0, $s0, $zero
/* 3D1F38 E00CC8A8 0200202D */  daddu     $a0, $s0, $zero
/* 3D1F3C E00CC8AC 27A50018 */  addiu     $a1, $sp, 0x18
/* 3D1F40 E00CC8B0 0C080114 */  jal       shim_guMtxCatF
/* 3D1F44 E00CC8B4 00A0302D */   daddu    $a2, $a1, $zero
/* 3D1F48 E00CC8B8 C6420004 */  lwc1      $f2, 4($s2)
/* 3D1F4C E00CC8BC C7A00048 */  lwc1      $f0, 0x48($sp)
/* 3D1F50 E00CC8C0 46001080 */  add.s     $f2, $f2, $f0
/* 3D1F54 E00CC8C4 C7A0004C */  lwc1      $f0, 0x4c($sp)
/* 3D1F58 E00CC8C8 44051000 */  mfc1      $a1, $f2
/* 3D1F5C E00CC8CC C6420008 */  lwc1      $f2, 8($s2)
/* 3D1F60 E00CC8D0 46001080 */  add.s     $f2, $f2, $f0
/* 3D1F64 E00CC8D4 C7A00050 */  lwc1      $f0, 0x50($sp)
/* 3D1F68 E00CC8D8 44061000 */  mfc1      $a2, $f2
/* 3D1F6C E00CC8DC C642000C */  lwc1      $f2, 0xc($s2)
/* 3D1F70 E00CC8E0 46001080 */  add.s     $f2, $f2, $f0
/* 3D1F74 E00CC8E4 0000202D */  daddu     $a0, $zero, $zero
/* 3D1F78 E00CC8E8 44071000 */  mfc1      $a3, $f2
/* 3D1F7C E00CC8EC 24020010 */  addiu     $v0, $zero, 0x10
/* 3D1F80 E00CC8F0 E7BC0010 */  swc1      $f28, 0x10($sp)
/* 3D1F84 E00CC8F4 0C034800 */  jal       fx_105_main
/* 3D1F88 E00CC8F8 AFA20014 */   sw       $v0, 0x14($sp)
/* 3D1F8C E00CC8FC 8C44000C */  lw        $a0, 0xc($v0)
/* 3D1F90 E00CC900 24030064 */  addiu     $v1, $zero, 0x64
/* 3D1F94 E00CC904 AC830028 */  sw        $v1, 0x28($a0)
/* 3D1F98 E00CC908 8C43000C */  lw        $v1, 0xc($v0)
/* 3D1F9C E00CC90C AC60002C */  sw        $zero, 0x2c($v1)
/* 3D1FA0 E00CC910 8C42000C */  lw        $v0, 0xc($v0)
/* 3D1FA4 E00CC914 AC400030 */  sw        $zero, 0x30($v0)
/* 3D1FA8 E00CC918 24020007 */  addiu     $v0, $zero, 7
/* 3D1FAC E00CC91C AE2206D0 */  sw        $v0, 0x6d0($s1)
dlabel LE00CC920_3D1FB0
/* 3D1FB0 E00CC920 26310004 */  addiu     $s1, $s1, 4
.LE00CC924:
/* 3D1FB4 E00CC924 26B50438 */  addiu     $s5, $s5, 0x438
/* 3D1FB8 E00CC928 26730001 */  addiu     $s3, $s3, 1
/* 3D1FBC E00CC92C 2A620019 */  slti      $v0, $s3, 0x19
/* 3D1FC0 E00CC930 1440FE81 */  bnez      $v0, .LE00CC338
/* 3D1FC4 E00CC934 269400B4 */   addiu    $s4, $s4, 0xb4
.LE00CC938:
/* 3D1FC8 E00CC938 8FBF00BC */  lw        $ra, 0xbc($sp)
/* 3D1FCC E00CC93C 8FBE00B8 */  lw        $fp, 0xb8($sp)
/* 3D1FD0 E00CC940 8FB700B4 */  lw        $s7, 0xb4($sp)
/* 3D1FD4 E00CC944 8FB600B0 */  lw        $s6, 0xb0($sp)
/* 3D1FD8 E00CC948 8FB500AC */  lw        $s5, 0xac($sp)
/* 3D1FDC E00CC94C 8FB400A8 */  lw        $s4, 0xa8($sp)
/* 3D1FE0 E00CC950 8FB300A4 */  lw        $s3, 0xa4($sp)
/* 3D1FE4 E00CC954 8FB200A0 */  lw        $s2, 0xa0($sp)
/* 3D1FE8 E00CC958 8FB1009C */  lw        $s1, 0x9c($sp)
/* 3D1FEC E00CC95C 8FB00098 */  lw        $s0, 0x98($sp)
/* 3D1FF0 E00CC960 D7BE00E8 */  ldc1      $f30, 0xe8($sp)
/* 3D1FF4 E00CC964 D7BC00E0 */  ldc1      $f28, 0xe0($sp)
/* 3D1FF8 E00CC968 D7BA00D8 */  ldc1      $f26, 0xd8($sp)
/* 3D1FFC E00CC96C D7B800D0 */  ldc1      $f24, 0xd0($sp)
/* 3D2000 E00CC970 D7B600C8 */  ldc1      $f22, 0xc8($sp)
/* 3D2004 E00CC974 D7B400C0 */  ldc1      $f20, 0xc0($sp)
/* 3D2008 E00CC978 03E00008 */  jr        $ra
/* 3D200C E00CC97C 27BD00F0 */   addiu    $sp, $sp, 0xf0
