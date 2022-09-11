.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel D_E0124C18
.double 0.01

dlabel D_E0124C20
.double 0.4

dlabel D_E0124C28
.double 0.1

.section .text

glabel pink_sparkles_update
/* 412A34 E0124304 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 412A38 E0124308 0000302D */  daddu     $a2, $zero, $zero
/* 412A3C E012430C AFBF0010 */  sw        $ra, 0x10($sp)
/* 412A40 E0124310 8C85000C */  lw        $a1, 0xc($a0)
/* 412A44 E0124314 00C0402D */  daddu     $t0, $a2, $zero
/* 412A48 E0124318 8CA20020 */  lw        $v0, 0x20($a1)
/* 412A4C E012431C 8CA3001C */  lw        $v1, 0x1c($a1)
/* 412A50 E0124320 24420001 */  addiu     $v0, $v0, 1
/* 412A54 E0124324 0040382D */  daddu     $a3, $v0, $zero
/* 412A58 E0124328 2463FFFF */  addiu     $v1, $v1, -1
/* 412A5C E012432C ACA3001C */  sw        $v1, 0x1c($a1)
/* 412A60 E0124330 ACA70020 */  sw        $a3, 0x20($a1)
/* 412A64 E0124334 8C820008 */  lw        $v0, 8($a0)
/* 412A68 E0124338 2442FFFF */  addiu     $v0, $v0, -1
/* 412A6C E012433C 1840004E */  blez      $v0, .LE0124478
/* 412A70 E0124340 24A5002C */   addiu    $a1, $a1, 0x2c
/* 412A74 E0124344 240AFFFF */  addiu     $t2, $zero, -1
/* 412A78 E0124348 3C09E012 */  lui       $t1, %hi(D_E0124BE4)
/* 412A7C E012434C 25294BE4 */  addiu     $t1, $t1, %lo(D_E0124BE4)
/* 412A80 E0124350 24A3000C */  addiu     $v1, $a1, 0xc
/* 412A84 E0124354 3C01E012 */  lui       $at, %hi(D_E0124C18)
/* 412A88 E0124358 D42E4C18 */  ldc1      $f14, %lo(D_E0124C18)($at)
/* 412A8C E012435C 3C01E012 */  lui       $at, %hi(D_E0124C20)
/* 412A90 E0124360 D42C4C20 */  ldc1      $f12, %lo(D_E0124C20)($at)
/* 412A94 E0124364 3C01E012 */  lui       $at, %hi(D_E0124C28)
/* 412A98 E0124368 D42A4C28 */  ldc1      $f10, %lo(D_E0124C28)($at)
.LE012436C:
/* 412A9C E012436C 00E61021 */  addu      $v0, $a3, $a2
/* 412AA0 E0124370 00461021 */  addu      $v0, $v0, $a2
/* 412AA4 E0124374 8C650010 */  lw        $a1, 0x10($v1)
/* 412AA8 E0124378 30420007 */  andi      $v0, $v0, 7
/* 412AAC E012437C 04A10002 */  bgez      $a1, .LE0124388
/* 412AB0 E0124380 AC62001C */   sw       $v0, 0x1c($v1)
/* 412AB4 E0124384 25080001 */  addiu     $t0, $t0, 1
.LE0124388:
/* 412AB8 E0124388 24A2FFFF */  addiu     $v0, $a1, -1
/* 412ABC E012438C AC620010 */  sw        $v0, 0x10($v1)
/* 412AC0 E0124390 2C42001F */  sltiu     $v0, $v0, 0x1f
/* 412AC4 E0124394 14400003 */  bnez      $v0, .LE01243A4
/* 412AC8 E0124398 00000000 */   nop
/* 412ACC E012439C 08049113 */  j         .LE012444C
/* 412AD0 E01243A0 AC6A001C */   sw       $t2, 0x1c($v1)
.LE01243A4:
/* 412AD4 E01243A4 8C650014 */  lw        $a1, 0x14($v1)
/* 412AD8 E01243A8 24A20001 */  addiu     $v0, $a1, 1
/* 412ADC E01243AC 0040382D */  daddu     $a3, $v0, $zero
/* 412AE0 E01243B0 28A20019 */  slti      $v0, $a1, 0x19
/* 412AE4 E01243B4 1040000D */  beqz      $v0, .LE01243EC
/* 412AE8 E01243B8 AC670014 */   sw       $a3, 0x14($v1)
/* 412AEC E01243BC 00A91021 */  addu      $v0, $a1, $t1
/* 412AF0 E01243C0 90420000 */  lbu       $v0, ($v0)
/* 412AF4 E01243C4 44820000 */  mtc1      $v0, $f0
/* 412AF8 E01243C8 00000000 */  nop
/* 412AFC E01243CC 46800020 */  cvt.s.w   $f0, $f0
/* 412B00 E01243D0 46000021 */  cvt.d.s   $f0, $f0
/* 412B04 E01243D4 462E0002 */  mul.d     $f0, $f0, $f14
/* 412B08 E01243D8 00000000 */  nop
/* 412B0C E01243DC 462C0002 */  mul.d     $f0, $f0, $f12
/* 412B10 E01243E0 00000000 */  nop
/* 412B14 E01243E4 08049102 */  j         .LE0124408
/* 412B18 E01243E8 46200020 */   cvt.s.d  $f0, $f0
.LE01243EC:
/* 412B1C E01243EC C4600018 */  lwc1      $f0, 0x18($v1)
/* 412B20 E01243F0 46000021 */  cvt.d.s   $f0, $f0
/* 412B24 E01243F4 46205081 */  sub.d     $f2, $f10, $f0
/* 412B28 E01243F8 462A1082 */  mul.d     $f2, $f2, $f10
/* 412B2C E01243FC 00000000 */  nop
/* 412B30 E0124400 46220000 */  add.d     $f0, $f0, $f2
/* 412B34 E0124404 46200020 */  cvt.s.d   $f0, $f0
.LE0124408:
/* 412B38 E0124408 E4600018 */  swc1      $f0, 0x18($v1)
/* 412B3C E012440C C468FFF8 */  lwc1      $f8, -8($v1)
/* 412B40 E0124410 C4600004 */  lwc1      $f0, 4($v1)
/* 412B44 E0124414 46004200 */  add.s     $f8, $f8, $f0
/* 412B48 E0124418 C4600008 */  lwc1      $f0, 8($v1)
/* 412B4C E012441C C466FFFC */  lwc1      $f6, -4($v1)
/* 412B50 E0124420 46000106 */  mov.s     $f4, $f0
/* 412B54 E0124424 46003180 */  add.s     $f6, $f6, $f0
/* 412B58 E0124428 C460000C */  lwc1      $f0, 0xc($v1)
/* 412B5C E012442C C4620004 */  lwc1      $f2, 4($v1)
/* 412B60 E0124430 46002100 */  add.s     $f4, $f4, $f0
/* 412B64 E0124434 C4600000 */  lwc1      $f0, ($v1)
/* 412B68 E0124438 E468FFF8 */  swc1      $f8, -8($v1)
/* 412B6C E012443C 46020000 */  add.s     $f0, $f0, $f2
/* 412B70 E0124440 E466FFFC */  swc1      $f6, -4($v1)
/* 412B74 E0124444 E4640008 */  swc1      $f4, 8($v1)
/* 412B78 E0124448 E4600000 */  swc1      $f0, ($v1)
.LE012444C:
/* 412B7C E012444C 24C60001 */  addiu     $a2, $a2, 1
/* 412B80 E0124450 8C820008 */  lw        $v0, 8($a0)
/* 412B84 E0124454 2442FFFF */  addiu     $v0, $v0, -1
/* 412B88 E0124458 00C2102A */  slt       $v0, $a2, $v0
/* 412B8C E012445C 1440FFC3 */  bnez      $v0, .LE012436C
/* 412B90 E0124460 2463002C */   addiu    $v1, $v1, 0x2c
/* 412B94 E0124464 8C820008 */  lw        $v0, 8($a0)
/* 412B98 E0124468 2442FFFF */  addiu     $v0, $v0, -1
/* 412B9C E012446C 0102102A */  slt       $v0, $t0, $v0
/* 412BA0 E0124470 14400003 */  bnez      $v0, .LE0124480
/* 412BA4 E0124474 00000000 */   nop
.LE0124478:
/* 412BA8 E0124478 0C080128 */  jal       shim_remove_effect
/* 412BAC E012447C 00000000 */   nop
.LE0124480:
/* 412BB0 E0124480 8FBF0010 */  lw        $ra, 0x10($sp)
/* 412BB4 E0124484 03E00008 */  jr        $ra
/* 412BB8 E0124488 27BD0018 */   addiu    $sp, $sp, 0x18
