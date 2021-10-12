.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_111_appendGfx
/* 3D89C8 E00DE2A8 27BDFF38 */  addiu     $sp, $sp, -0xc8
/* 3D89CC E00DE2AC 0080302D */  daddu     $a2, $a0, $zero
/* 3D89D0 E00DE2B0 3C07DB06 */  lui       $a3, 0xdb06
/* 3D89D4 E00DE2B4 34E70024 */  ori       $a3, $a3, 0x24
/* 3D89D8 E00DE2B8 27A40020 */  addiu     $a0, $sp, 0x20
/* 3D89DC E00DE2BC AFB400B0 */  sw        $s4, 0xb0($sp)
/* 3D89E0 E00DE2C0 3C140001 */  lui       $s4, 1
/* 3D89E4 E00DE2C4 AFB200A8 */  sw        $s2, 0xa8($sp)
/* 3D89E8 E00DE2C8 3C12800A */  lui       $s2, %hi(gMasterGfxPos)
/* 3D89EC E00DE2CC 2652A66C */  addiu     $s2, $s2, %lo(gMasterGfxPos)
/* 3D89F0 E00DE2D0 36941630 */  ori       $s4, $s4, 0x1630
/* 3D89F4 E00DE2D4 AFBF00C4 */  sw        $ra, 0xc4($sp)
/* 3D89F8 E00DE2D8 AFBE00C0 */  sw        $fp, 0xc0($sp)
/* 3D89FC E00DE2DC AFB700BC */  sw        $s7, 0xbc($sp)
/* 3D8A00 E00DE2E0 AFB600B8 */  sw        $s6, 0xb8($sp)
/* 3D8A04 E00DE2E4 AFB500B4 */  sw        $s5, 0xb4($sp)
/* 3D8A08 E00DE2E8 AFB300AC */  sw        $s3, 0xac($sp)
/* 3D8A0C E00DE2EC AFB100A4 */  sw        $s1, 0xa4($sp)
/* 3D8A10 E00DE2F0 AFB000A0 */  sw        $s0, 0xa0($sp)
/* 3D8A14 E00DE2F4 8E430000 */  lw        $v1, ($s2)
/* 3D8A18 E00DE2F8 8CD6000C */  lw        $s6, 0xc($a2)
/* 3D8A1C E00DE2FC 0060282D */  daddu     $a1, $v1, $zero
/* 3D8A20 E00DE300 24630008 */  addiu     $v1, $v1, 8
/* 3D8A24 E00DE304 AE430000 */  sw        $v1, ($s2)
/* 3D8A28 E00DE308 8EDE0014 */  lw        $fp, 0x14($s6)
/* 3D8A2C E00DE30C 8ED50024 */  lw        $s5, 0x24($s6)
/* 3D8A30 E00DE310 8ED70000 */  lw        $s7, ($s6)
/* 3D8A34 E00DE314 3C02E700 */  lui       $v0, 0xe700
/* 3D8A38 E00DE318 ACA20000 */  sw        $v0, ($a1)
/* 3D8A3C E00DE31C ACA00004 */  sw        $zero, 4($a1)
/* 3D8A40 E00DE320 AC670000 */  sw        $a3, ($v1)
/* 3D8A44 E00DE324 8CC50010 */  lw        $a1, 0x10($a2)
/* 3D8A48 E00DE328 24620008 */  addiu     $v0, $v1, 8
/* 3D8A4C E00DE32C AE420000 */  sw        $v0, ($s2)
/* 3D8A50 E00DE330 8CA2001C */  lw        $v0, 0x1c($a1)
/* 3D8A54 E00DE334 3C0A8000 */  lui       $t2, 0x8000
/* 3D8A58 E00DE338 004A1021 */  addu      $v0, $v0, $t2
/* 3D8A5C E00DE33C AC620004 */  sw        $v0, 4($v1)
/* 3D8A60 E00DE340 3C03800B */  lui       $v1, %hi(gCameras)
/* 3D8A64 E00DE344 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* 3D8A68 E00DE348 8EC50004 */  lw        $a1, 4($s6)
/* 3D8A6C E00DE34C 8EC60008 */  lw        $a2, 8($s6)
/* 3D8A70 E00DE350 3C028007 */  lui       $v0, %hi(gCurrentCameraID)
/* 3D8A74 E00DE354 8C427410 */  lw        $v0, %lo(gCurrentCameraID)($v0)
/* 3D8A78 E00DE358 8EC7000C */  lw        $a3, 0xc($s6)
/* 3D8A7C E00DE35C 00028080 */  sll       $s0, $v0, 2
/* 3D8A80 E00DE360 02028021 */  addu      $s0, $s0, $v0
/* 3D8A84 E00DE364 00108080 */  sll       $s0, $s0, 2
/* 3D8A88 E00DE368 02028023 */  subu      $s0, $s0, $v0
/* 3D8A8C E00DE36C 001010C0 */  sll       $v0, $s0, 3
/* 3D8A90 E00DE370 02028021 */  addu      $s0, $s0, $v0
/* 3D8A94 E00DE374 001080C0 */  sll       $s0, $s0, 3
/* 3D8A98 E00DE378 0C080108 */  jal       shim_guTranslateF
/* 3D8A9C E00DE37C 02038021 */   addu     $s0, $s0, $v1
/* 3D8AA0 E00DE380 27B10060 */  addiu     $s1, $sp, 0x60
/* 3D8AA4 E00DE384 8EC50040 */  lw        $a1, 0x40($s6)
/* 3D8AA8 E00DE388 0220202D */  daddu     $a0, $s1, $zero
/* 3D8AAC E00DE38C 00A0302D */  daddu     $a2, $a1, $zero
/* 3D8AB0 E00DE390 0C080110 */  jal       shim_guScaleF
/* 3D8AB4 E00DE394 00A0382D */   daddu    $a3, $a1, $zero
/* 3D8AB8 E00DE398 0220202D */  daddu     $a0, $s1, $zero
/* 3D8ABC E00DE39C 27A50020 */  addiu     $a1, $sp, 0x20
/* 3D8AC0 E00DE3A0 0C080114 */  jal       shim_guMtxCatF
/* 3D8AC4 E00DE3A4 00A0302D */   daddu    $a2, $a1, $zero
/* 3D8AC8 E00DE3A8 27A40020 */  addiu     $a0, $sp, 0x20
/* 3D8ACC E00DE3AC 3C118007 */  lui       $s1, %hi(gMatrixListPos)
/* 3D8AD0 E00DE3B0 263141F0 */  addiu     $s1, $s1, %lo(gMatrixListPos)
/* 3D8AD4 E00DE3B4 3C13800A */  lui       $s3, %hi(gDisplayContext)
/* 3D8AD8 E00DE3B8 2673A674 */  addiu     $s3, $s3, %lo(gDisplayContext)
/* 3D8ADC E00DE3BC 96250000 */  lhu       $a1, ($s1)
/* 3D8AE0 E00DE3C0 8E620000 */  lw        $v0, ($s3)
/* 3D8AE4 E00DE3C4 00052980 */  sll       $a1, $a1, 6
/* 3D8AE8 E00DE3C8 00B42821 */  addu      $a1, $a1, $s4
/* 3D8AEC E00DE3CC 0C080118 */  jal       shim_guMtxF2L
/* 3D8AF0 E00DE3D0 00452821 */   addu     $a1, $v0, $a1
/* 3D8AF4 E00DE3D4 3C03DA38 */  lui       $v1, 0xda38
/* 3D8AF8 E00DE3D8 34630002 */  ori       $v1, $v1, 2
/* 3D8AFC E00DE3DC 3C06DA38 */  lui       $a2, 0xda38
/* 3D8B00 E00DE3E0 34C60001 */  ori       $a2, $a2, 1
/* 3D8B04 E00DE3E4 44950000 */  mtc1      $s5, $f0
/* 3D8B08 E00DE3E8 00000000 */  nop
/* 3D8B0C E00DE3EC 46800021 */  cvt.d.w   $f0, $f0
/* 3D8B10 E00DE3F0 8E440000 */  lw        $a0, ($s2)
/* 3D8B14 E00DE3F4 96220000 */  lhu       $v0, ($s1)
/* 3D8B18 E00DE3F8 3C013FE0 */  lui       $at, 0x3fe0
/* 3D8B1C E00DE3FC 44811800 */  mtc1      $at, $f3
/* 3D8B20 E00DE400 44801000 */  mtc1      $zero, $f2
/* 3D8B24 E00DE404 0080282D */  daddu     $a1, $a0, $zero
/* 3D8B28 E00DE408 24840008 */  addiu     $a0, $a0, 8
/* 3D8B2C E00DE40C AE440000 */  sw        $a0, ($s2)
/* 3D8B30 E00DE410 ACA30000 */  sw        $v1, ($a1)
/* 3D8B34 E00DE414 24430001 */  addiu     $v1, $v0, 1
/* 3D8B38 E00DE418 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3D8B3C E00DE41C 00021180 */  sll       $v0, $v0, 6
/* 3D8B40 E00DE420 00541021 */  addu      $v0, $v0, $s4
/* 3D8B44 E00DE424 2487000C */  addiu     $a3, $a0, 0xc
/* 3D8B48 E00DE428 46220002 */  mul.d     $f0, $f0, $f2
/* 3D8B4C E00DE42C 00000000 */  nop
/* 3D8B50 E00DE430 A6230000 */  sh        $v1, ($s1)
/* 3D8B54 E00DE434 8E630000 */  lw        $v1, ($s3)
/* 3D8B58 E00DE438 3C0141E0 */  lui       $at, 0x41e0
/* 3D8B5C E00DE43C 44811800 */  mtc1      $at, $f3
/* 3D8B60 E00DE440 44801000 */  mtc1      $zero, $f2
/* 3D8B64 E00DE444 00621821 */  addu      $v1, $v1, $v0
/* 3D8B68 E00DE448 24820008 */  addiu     $v0, $a0, 8
/* 3D8B6C E00DE44C ACA30004 */  sw        $v1, 4($a1)
/* 3D8B70 E00DE450 AE420000 */  sw        $v0, ($s2)
/* 3D8B74 E00DE454 24820010 */  addiu     $v0, $a0, 0x10
/* 3D8B78 E00DE458 AC860000 */  sw        $a2, ($a0)
/* 3D8B7C E00DE45C AE420000 */  sw        $v0, ($s2)
/* 3D8B80 E00DE460 8E030204 */  lw        $v1, 0x204($s0)
/* 3D8B84 E00DE464 3C02FA00 */  lui       $v0, 0xfa00
/* 3D8B88 E00DE468 AC820008 */  sw        $v0, 8($a0)
/* 3D8B8C E00DE46C AC830004 */  sw        $v1, 4($a0)
/* 3D8B90 E00DE470 92C4001B */  lbu       $a0, 0x1b($s6)
/* 3D8B94 E00DE474 92C2001F */  lbu       $v0, 0x1f($s6)
/* 3D8B98 E00DE478 92C30023 */  lbu       $v1, 0x23($s6)
/* 3D8B9C E00DE47C 00042600 */  sll       $a0, $a0, 0x18
/* 3D8BA0 E00DE480 00021400 */  sll       $v0, $v0, 0x10
/* 3D8BA4 E00DE484 00822025 */  or        $a0, $a0, $v0
/* 3D8BA8 E00DE488 00031A00 */  sll       $v1, $v1, 8
/* 3D8BAC E00DE48C 4620103E */  c.le.d    $f2, $f0
/* 3D8BB0 E00DE490 00000000 */  nop
/* 3D8BB4 E00DE494 45010005 */  bc1t      .LE00DE4AC
/* 3D8BB8 E00DE498 00832025 */   or       $a0, $a0, $v1
/* 3D8BBC E00DE49C 4620010D */  trunc.w.d $f4, $f0
/* 3D8BC0 E00DE4A0 44022000 */  mfc1      $v0, $f4
/* 3D8BC4 E00DE4A4 08037931 */  j         .LE00DE4C4
/* 3D8BC8 E00DE4A8 3C05E300 */   lui      $a1, 0xe300
.LE00DE4AC:
/* 3D8BCC E00DE4AC 46220001 */  sub.d     $f0, $f0, $f2
/* 3D8BD0 E00DE4B0 4620010D */  trunc.w.d $f4, $f0
/* 3D8BD4 E00DE4B4 44022000 */  mfc1      $v0, $f4
/* 3D8BD8 E00DE4B8 3C0A8000 */  lui       $t2, 0x8000
/* 3D8BDC E00DE4BC 004A1025 */  or        $v0, $v0, $t2
/* 3D8BE0 E00DE4C0 3C05E300 */  lui       $a1, 0xe300
.LE00DE4C4:
/* 3D8BE4 E00DE4C4 34A51A01 */  ori       $a1, $a1, 0x1a01
/* 3D8BE8 E00DE4C8 03C0302D */  daddu     $a2, $fp, $zero
/* 3D8BEC E00DE4CC 3C14800A */  lui       $s4, %hi(gMasterGfxPos)
/* 3D8BF0 E00DE4D0 2694A66C */  addiu     $s4, $s4, %lo(gMasterGfxPos)
/* 3D8BF4 E00DE4D4 304200FF */  andi      $v0, $v0, 0xff
/* 3D8BF8 E00DE4D8 8E830000 */  lw        $v1, ($s4)
/* 3D8BFC E00DE4DC 00821025 */  or        $v0, $a0, $v0
/* 3D8C00 E00DE4E0 ACE20000 */  sw        $v0, ($a3)
/* 3D8C04 E00DE4E4 24020020 */  addiu     $v0, $zero, 0x20
/* 3D8C08 E00DE4E8 0060202D */  daddu     $a0, $v1, $zero
/* 3D8C0C E00DE4EC 24630008 */  addiu     $v1, $v1, 8
/* 3D8C10 E00DE4F0 AE830000 */  sw        $v1, ($s4)
/* 3D8C14 E00DE4F4 AC820004 */  sw        $v0, 4($a0)
/* 3D8C18 E00DE4F8 3C02DE00 */  lui       $v0, 0xde00
/* 3D8C1C E00DE4FC AC850000 */  sw        $a1, ($a0)
/* 3D8C20 E00DE500 AC620000 */  sw        $v0, ($v1)
/* 3D8C24 E00DE504 00171080 */  sll       $v0, $s7, 2
/* 3D8C28 E00DE508 3C04E00E */  lui       $a0, %hi(D_E00DE84C)
/* 3D8C2C E00DE50C 00822021 */  addu      $a0, $a0, $v0
/* 3D8C30 E00DE510 8C84E84C */  lw        $a0, %lo(D_E00DE84C)($a0)
/* 3D8C34 E00DE514 24620008 */  addiu     $v0, $v1, 8
/* 3D8C38 E00DE518 AE820000 */  sw        $v0, ($s4)
/* 3D8C3C E00DE51C 28C2001E */  slti      $v0, $a2, 0x1e
/* 3D8C40 E00DE520 14400002 */  bnez      $v0, .LE00DE52C
/* 3D8C44 E00DE524 AC640004 */   sw       $a0, 4($v1)
/* 3D8C48 E00DE528 2406001D */  addiu     $a2, $zero, 0x1d
.LE00DE52C:
/* 3D8C4C E00DE52C 27A40020 */  addiu     $a0, $sp, 0x20
/* 3D8C50 E00DE530 3C130001 */  lui       $s3, 1
/* 3D8C54 E00DE534 00178100 */  sll       $s0, $s7, 4
/* 3D8C58 E00DE538 02178023 */  subu      $s0, $s0, $s7
/* 3D8C5C E00DE53C 00108040 */  sll       $s0, $s0, 1
/* 3D8C60 E00DE540 00D08021 */  addu      $s0, $a2, $s0
/* 3D8C64 E00DE544 36731630 */  ori       $s3, $s3, 0x1630
/* 3D8C68 E00DE548 3C02E00E */  lui       $v0, %hi(D_E00DE96C)
/* 3D8C6C E00DE54C 00501021 */  addu      $v0, $v0, $s0
/* 3D8C70 E00DE550 9042E96C */  lbu       $v0, %lo(D_E00DE96C)($v0)
/* 3D8C74 E00DE554 44801000 */  mtc1      $zero, $f2
/* 3D8C78 E00DE558 44820000 */  mtc1      $v0, $f0
/* 3D8C7C E00DE55C 00000000 */  nop
/* 3D8C80 E00DE560 46800020 */  cvt.s.w   $f0, $f0
/* 3D8C84 E00DE564 46000007 */  neg.s     $f0, $f0
/* 3D8C88 E00DE568 44070000 */  mfc1      $a3, $f0
/* 3D8C8C E00DE56C 44051000 */  mfc1      $a1, $f2
/* 3D8C90 E00DE570 3C02E00E */  lui       $v0, %hi(D_E00DE8B4)
/* 3D8C94 E00DE574 00501021 */  addu      $v0, $v0, $s0
/* 3D8C98 E00DE578 9042E8B4 */  lbu       $v0, %lo(D_E00DE8B4)($v0)
/* 3D8C9C E00DE57C 3C013C23 */  lui       $at, 0x3c23
/* 3D8CA0 E00DE580 3421D70A */  ori       $at, $at, 0xd70a
/* 3D8CA4 E00DE584 44810000 */  mtc1      $at, $f0
/* 3D8CA8 E00DE588 00A0302D */  daddu     $a2, $a1, $zero
/* 3D8CAC E00DE58C 44821000 */  mtc1      $v0, $f2
/* 3D8CB0 E00DE590 00000000 */  nop
/* 3D8CB4 E00DE594 468010A0 */  cvt.s.w   $f2, $f2
/* 3D8CB8 E00DE598 3C02E00E */  lui       $v0, %hi(D_E00DE858)
/* 3D8CBC E00DE59C 00501021 */  addu      $v0, $v0, $s0
/* 3D8CC0 E00DE5A0 8042E858 */  lb        $v0, %lo(D_E00DE858)($v0)
/* 3D8CC4 E00DE5A4 46001082 */  mul.s     $f2, $f2, $f0
/* 3D8CC8 E00DE5A8 00000000 */  nop
/* 3D8CCC E00DE5AC AFA50018 */  sw        $a1, 0x18($sp)
/* 3D8CD0 E00DE5B0 AFA5001C */  sw        $a1, 0x1c($sp)
/* 3D8CD4 E00DE5B4 44820000 */  mtc1      $v0, $f0
/* 3D8CD8 E00DE5B8 00000000 */  nop
/* 3D8CDC E00DE5BC 46800020 */  cvt.s.w   $f0, $f0
/* 3D8CE0 E00DE5C0 E7A00014 */  swc1      $f0, 0x14($sp)
/* 3D8CE4 E00DE5C4 0C080180 */  jal       shim_guPositionF
/* 3D8CE8 E00DE5C8 E7A20010 */   swc1     $f2, 0x10($sp)
/* 3D8CEC E00DE5CC 27A40020 */  addiu     $a0, $sp, 0x20
/* 3D8CF0 E00DE5D0 3C118007 */  lui       $s1, %hi(gMatrixListPos)
/* 3D8CF4 E00DE5D4 263141F0 */  addiu     $s1, $s1, %lo(gMatrixListPos)
/* 3D8CF8 E00DE5D8 3C12800A */  lui       $s2, %hi(gDisplayContext)
/* 3D8CFC E00DE5DC 2652A674 */  addiu     $s2, $s2, %lo(gDisplayContext)
/* 3D8D00 E00DE5E0 96250000 */  lhu       $a1, ($s1)
/* 3D8D04 E00DE5E4 8E420000 */  lw        $v0, ($s2)
/* 3D8D08 E00DE5E8 00052980 */  sll       $a1, $a1, 6
/* 3D8D0C E00DE5EC 00B32821 */  addu      $a1, $a1, $s3
/* 3D8D10 E00DE5F0 0C080118 */  jal       shim_guMtxF2L
/* 3D8D14 E00DE5F4 00452821 */   addu     $a1, $v0, $a1
/* 3D8D18 E00DE5F8 8E850000 */  lw        $a1, ($s4)
/* 3D8D1C E00DE5FC 00A0202D */  daddu     $a0, $a1, $zero
/* 3D8D20 E00DE600 24A50008 */  addiu     $a1, $a1, 8
/* 3D8D24 E00DE604 AE850000 */  sw        $a1, ($s4)
/* 3D8D28 E00DE608 96220000 */  lhu       $v0, ($s1)
/* 3D8D2C E00DE60C 3C03DA38 */  lui       $v1, 0xda38
/* 3D8D30 E00DE610 AC830000 */  sw        $v1, ($a0)
/* 3D8D34 E00DE614 24430001 */  addiu     $v1, $v0, 1
/* 3D8D38 E00DE618 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3D8D3C E00DE61C 00021180 */  sll       $v0, $v0, 6
/* 3D8D40 E00DE620 A6230000 */  sh        $v1, ($s1)
/* 3D8D44 E00DE624 8E430000 */  lw        $v1, ($s2)
/* 3D8D48 E00DE628 00531021 */  addu      $v0, $v0, $s3
/* 3D8D4C E00DE62C 00621821 */  addu      $v1, $v1, $v0
/* 3D8D50 E00DE630 AC830004 */  sw        $v1, 4($a0)
/* 3D8D54 E00DE634 3C02E00E */  lui       $v0, %hi(D_E00DE910)
/* 3D8D58 E00DE638 00501021 */  addu      $v0, $v0, $s0
/* 3D8D5C E00DE63C 9042E910 */  lbu       $v0, %lo(D_E00DE910)($v0)
/* 3D8D60 E00DE640 3C0140A0 */  lui       $at, 0x40a0
/* 3D8D64 E00DE644 44811000 */  mtc1      $at, $f2
/* 3D8D68 E00DE648 44820000 */  mtc1      $v0, $f0
/* 3D8D6C E00DE64C 00000000 */  nop
/* 3D8D70 E00DE650 46800020 */  cvt.s.w   $f0, $f0
/* 3D8D74 E00DE654 46020002 */  mul.s     $f0, $f0, $f2
/* 3D8D78 E00DE658 00000000 */  nop
/* 3D8D7C E00DE65C 3C013B80 */  lui       $at, 0x3b80
/* 3D8D80 E00DE660 44811000 */  mtc1      $at, $f2
/* 3D8D84 E00DE664 00000000 */  nop
/* 3D8D88 E00DE668 46020002 */  mul.s     $f0, $f0, $f2
/* 3D8D8C E00DE66C 00000000 */  nop
/* 3D8D90 E00DE670 4600010D */  trunc.w.s $f4, $f0
/* 3D8D94 E00DE674 44082000 */  mfc1      $t0, $f4
/* 3D8D98 E00DE678 00000000 */  nop
/* 3D8D9C E00DE67C 44881000 */  mtc1      $t0, $f2
/* 3D8DA0 E00DE680 00000000 */  nop
/* 3D8DA4 E00DE684 468010A0 */  cvt.s.w   $f2, $f2
/* 3D8DA8 E00DE688 46020001 */  sub.s     $f0, $f0, $f2
/* 3D8DAC E00DE68C 3C014380 */  lui       $at, 0x4380
/* 3D8DB0 E00DE690 44811000 */  mtc1      $at, $f2
/* 3D8DB4 E00DE694 00000000 */  nop
/* 3D8DB8 E00DE698 46020002 */  mul.s     $f0, $f0, $f2
/* 3D8DBC E00DE69C 00000000 */  nop
/* 3D8DC0 E00DE6A0 29020004 */  slti      $v0, $t0, 4
/* 3D8DC4 E00DE6A4 38430001 */  xori      $v1, $v0, 1
/* 3D8DC8 E00DE6A8 29020005 */  slti      $v0, $t0, 5
/* 3D8DCC E00DE6AC 4600010D */  trunc.w.s $f4, $f0
/* 3D8DD0 E00DE6B0 44092000 */  mfc1      $t1, $f4
/* 3D8DD4 E00DE6B4 1040002F */  beqz      $v0, .LE00DE774
/* 3D8DD8 E00DE6B8 3C06D838 */   lui      $a2, 0xd838
/* 3D8DDC E00DE6BC 10600006 */  beqz      $v1, .LE00DE6D8
/* 3D8DE0 E00DE6C0 24A20008 */   addiu    $v0, $a1, 8
/* 3D8DE4 E00DE6C4 AE820000 */  sw        $v0, ($s4)
/* 3D8DE8 E00DE6C8 3C02F200 */  lui       $v0, 0xf200
/* 3D8DEC E00DE6CC ACA20000 */  sw        $v0, ($a1)
/* 3D8DF0 E00DE6D0 080379BC */  j         .LE00DE6F0
/* 3D8DF4 E00DE6D4 3C020100 */   lui      $v0, 0x100
.LE00DE6D8:
/* 3D8DF8 E00DE6D8 3C020107 */  lui       $v0, 0x107
/* 3D8DFC E00DE6DC 3442C1FC */  ori       $v0, $v0, 0xc1fc
/* 3D8E00 E00DE6E0 24A30008 */  addiu     $v1, $a1, 8
/* 3D8E04 E00DE6E4 AE830000 */  sw        $v1, ($s4)
/* 3D8E08 E00DE6E8 3C03F200 */  lui       $v1, 0xf200
/* 3D8E0C E00DE6EC ACA30000 */  sw        $v1, ($a1)
.LE00DE6F0:
/* 3D8E10 E00DE6F0 ACA20004 */  sw        $v0, 4($a1)
/* 3D8E14 E00DE6F4 3C06800A */  lui       $a2, %hi(gMasterGfxPos)
/* 3D8E18 E00DE6F8 24C6A66C */  addiu     $a2, $a2, %lo(gMasterGfxPos)
/* 3D8E1C E00DE6FC 8CC50000 */  lw        $a1, ($a2)
/* 3D8E20 E00DE700 3C02FB00 */  lui       $v0, 0xfb00
/* 3D8E24 E00DE704 00A0382D */  daddu     $a3, $a1, $zero
/* 3D8E28 E00DE708 24A50008 */  addiu     $a1, $a1, 8
/* 3D8E2C E00DE70C ACC50000 */  sw        $a1, ($a2)
/* 3D8E30 E00DE710 ACE20000 */  sw        $v0, ($a3)
/* 3D8E34 E00DE714 92C2002B */  lbu       $v0, 0x2b($s6)
/* 3D8E38 E00DE718 92C4002F */  lbu       $a0, 0x2f($s6)
/* 3D8E3C E00DE71C 92C30033 */  lbu       $v1, 0x33($s6)
/* 3D8E40 E00DE720 00021600 */  sll       $v0, $v0, 0x18
/* 3D8E44 E00DE724 00042400 */  sll       $a0, $a0, 0x10
/* 3D8E48 E00DE728 00441025 */  or        $v0, $v0, $a0
/* 3D8E4C E00DE72C 00031A00 */  sll       $v1, $v1, 8
/* 3D8E50 E00DE730 00431025 */  or        $v0, $v0, $v1
/* 3D8E54 E00DE734 312300FF */  andi      $v1, $t1, 0xff
/* 3D8E58 E00DE738 00431025 */  or        $v0, $v0, $v1
/* 3D8E5C E00DE73C ACE20004 */  sw        $v0, 4($a3)
/* 3D8E60 E00DE740 3C02DE00 */  lui       $v0, 0xde00
/* 3D8E64 E00DE744 ACA20000 */  sw        $v0, ($a1)
/* 3D8E68 E00DE748 00171080 */  sll       $v0, $s7, 2
/* 3D8E6C E00DE74C 00571021 */  addu      $v0, $v0, $s7
/* 3D8E70 E00DE750 00481021 */  addu      $v0, $v0, $t0
/* 3D8E74 E00DE754 00021080 */  sll       $v0, $v0, 2
/* 3D8E78 E00DE758 3C03E00E */  lui       $v1, %hi(D_E00DE810)
/* 3D8E7C E00DE75C 00621821 */  addu      $v1, $v1, $v0
/* 3D8E80 E00DE760 8C63E810 */  lw        $v1, %lo(D_E00DE810)($v1)
/* 3D8E84 E00DE764 24A20008 */  addiu     $v0, $a1, 8
/* 3D8E88 E00DE768 ACC20000 */  sw        $v0, ($a2)
/* 3D8E8C E00DE76C ACA30004 */  sw        $v1, 4($a1)
/* 3D8E90 E00DE770 3C06D838 */  lui       $a2, 0xd838
.LE00DE774:
/* 3D8E94 E00DE774 34C60002 */  ori       $a2, $a2, 2
/* 3D8E98 E00DE778 3C07E300 */  lui       $a3, 0xe300
/* 3D8E9C E00DE77C 3C04800A */  lui       $a0, %hi(gMasterGfxPos)
/* 3D8EA0 E00DE780 2484A66C */  addiu     $a0, $a0, %lo(gMasterGfxPos)
/* 3D8EA4 E00DE784 34E71A01 */  ori       $a3, $a3, 0x1a01
/* 3D8EA8 E00DE788 8C820000 */  lw        $v0, ($a0)
/* 3D8EAC E00DE78C 24050040 */  addiu     $a1, $zero, 0x40
/* 3D8EB0 E00DE790 0040182D */  daddu     $v1, $v0, $zero
/* 3D8EB4 E00DE794 24420008 */  addiu     $v0, $v0, 8
/* 3D8EB8 E00DE798 AC820000 */  sw        $v0, ($a0)
/* 3D8EBC E00DE79C AC660000 */  sw        $a2, ($v1)
/* 3D8EC0 E00DE7A0 AC650004 */  sw        $a1, 4($v1)
/* 3D8EC4 E00DE7A4 24430008 */  addiu     $v1, $v0, 8
/* 3D8EC8 E00DE7A8 AC830000 */  sw        $v1, ($a0)
/* 3D8ECC E00DE7AC 24430010 */  addiu     $v1, $v0, 0x10
/* 3D8ED0 E00DE7B0 AC460000 */  sw        $a2, ($v0)
/* 3D8ED4 E00DE7B4 AC450004 */  sw        $a1, 4($v0)
/* 3D8ED8 E00DE7B8 AC830000 */  sw        $v1, ($a0)
/* 3D8EDC E00DE7BC 24030030 */  addiu     $v1, $zero, 0x30
/* 3D8EE0 E00DE7C0 AC43000C */  sw        $v1, 0xc($v0)
/* 3D8EE4 E00DE7C4 24430018 */  addiu     $v1, $v0, 0x18
/* 3D8EE8 E00DE7C8 AC470008 */  sw        $a3, 8($v0)
/* 3D8EEC E00DE7CC AC830000 */  sw        $v1, ($a0)
/* 3D8EF0 E00DE7D0 3C03E700 */  lui       $v1, 0xe700
/* 3D8EF4 E00DE7D4 AC430010 */  sw        $v1, 0x10($v0)
/* 3D8EF8 E00DE7D8 AC400014 */  sw        $zero, 0x14($v0)
/* 3D8EFC E00DE7DC 8FBF00C4 */  lw        $ra, 0xc4($sp)
/* 3D8F00 E00DE7E0 8FBE00C0 */  lw        $fp, 0xc0($sp)
/* 3D8F04 E00DE7E4 8FB700BC */  lw        $s7, 0xbc($sp)
/* 3D8F08 E00DE7E8 8FB600B8 */  lw        $s6, 0xb8($sp)
/* 3D8F0C E00DE7EC 8FB500B4 */  lw        $s5, 0xb4($sp)
/* 3D8F10 E00DE7F0 8FB400B0 */  lw        $s4, 0xb0($sp)
/* 3D8F14 E00DE7F4 8FB300AC */  lw        $s3, 0xac($sp)
/* 3D8F18 E00DE7F8 8FB200A8 */  lw        $s2, 0xa8($sp)
/* 3D8F1C E00DE7FC 8FB100A4 */  lw        $s1, 0xa4($sp)
/* 3D8F20 E00DE800 8FB000A0 */  lw        $s0, 0xa0($sp)
/* 3D8F24 E00DE804 03E00008 */  jr        $ra
/* 3D8F28 E00DE808 27BD00C8 */   addiu    $sp, $sp, 0xc8
/* 3D8F2C E00DE80C 00000000 */  nop
