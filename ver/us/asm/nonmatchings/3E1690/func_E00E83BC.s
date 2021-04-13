.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00E83BC
/* 3E1A4C E00E83BC 27BDFF50 */  addiu     $sp, $sp, -0xb0
/* 3E1A50 E00E83C0 0080302D */  daddu     $a2, $a0, $zero
/* 3E1A54 E00E83C4 3C07DB06 */  lui       $a3, 0xdb06
/* 3E1A58 E00E83C8 34E70024 */  ori       $a3, $a3, 0x24
/* 3E1A5C E00E83CC 27A40010 */  addiu     $a0, $sp, 0x10
/* 3E1A60 E00E83D0 AFB600A8 */  sw        $s6, 0xa8($sp)
/* 3E1A64 E00E83D4 3C160001 */  lui       $s6, 1
/* 3E1A68 E00E83D8 AFB3009C */  sw        $s3, 0x9c($sp)
/* 3E1A6C E00E83DC 3C13800A */  lui       $s3, %hi(gMasterGfxPos)
/* 3E1A70 E00E83E0 2673A66C */  addiu     $s3, $s3, %lo(gMasterGfxPos)
/* 3E1A74 E00E83E4 36D61630 */  ori       $s6, $s6, 0x1630
/* 3E1A78 E00E83E8 AFBF00AC */  sw        $ra, 0xac($sp)
/* 3E1A7C E00E83EC AFB500A4 */  sw        $s5, 0xa4($sp)
/* 3E1A80 E00E83F0 AFB400A0 */  sw        $s4, 0xa0($sp)
/* 3E1A84 E00E83F4 AFB20098 */  sw        $s2, 0x98($sp)
/* 3E1A88 E00E83F8 AFB10094 */  sw        $s1, 0x94($sp)
/* 3E1A8C E00E83FC AFB00090 */  sw        $s0, 0x90($sp)
/* 3E1A90 E00E8400 8E650000 */  lw        $a1, ($s3)
/* 3E1A94 E00E8404 8CD2000C */  lw        $s2, 0xc($a2)
/* 3E1A98 E00E8408 00A0182D */  daddu     $v1, $a1, $zero
/* 3E1A9C E00E840C 24A50008 */  addiu     $a1, $a1, 8
/* 3E1AA0 E00E8410 AE650000 */  sw        $a1, ($s3)
/* 3E1AA4 E00E8414 8E550030 */  lw        $s5, 0x30($s2)
/* 3E1AA8 E00E8418 3C02E700 */  lui       $v0, 0xe700
/* 3E1AAC E00E841C AC620000 */  sw        $v0, ($v1)
/* 3E1AB0 E00E8420 AC600004 */  sw        $zero, 4($v1)
/* 3E1AB4 E00E8424 ACA70000 */  sw        $a3, ($a1)
/* 3E1AB8 E00E8428 8CC30010 */  lw        $v1, 0x10($a2)
/* 3E1ABC E00E842C 24A20008 */  addiu     $v0, $a1, 8
/* 3E1AC0 E00E8430 AE620000 */  sw        $v0, ($s3)
/* 3E1AC4 E00E8434 8C62001C */  lw        $v0, 0x1c($v1)
/* 3E1AC8 E00E8438 3C038000 */  lui       $v1, 0x8000
/* 3E1ACC E00E843C 00431021 */  addu      $v0, $v0, $v1
/* 3E1AD0 E00E8440 3C03800B */  lui       $v1, %hi(gCameras)
/* 3E1AD4 E00E8444 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* 3E1AD8 E00E8448 ACA20004 */  sw        $v0, 4($a1)
/* 3E1ADC E00E844C 8E450004 */  lw        $a1, 4($s2)
/* 3E1AE0 E00E8450 8E460008 */  lw        $a2, 8($s2)
/* 3E1AE4 E00E8454 3C028007 */  lui       $v0, %hi(gCurrentCameraID)
/* 3E1AE8 E00E8458 8C427410 */  lw        $v0, %lo(gCurrentCameraID)($v0)
/* 3E1AEC E00E845C 8E47000C */  lw        $a3, 0xc($s2)
/* 3E1AF0 E00E8460 00028080 */  sll       $s0, $v0, 2
/* 3E1AF4 E00E8464 02028021 */  addu      $s0, $s0, $v0
/* 3E1AF8 E00E8468 00108080 */  sll       $s0, $s0, 2
/* 3E1AFC E00E846C 02028023 */  subu      $s0, $s0, $v0
/* 3E1B00 E00E8470 001010C0 */  sll       $v0, $s0, 3
/* 3E1B04 E00E8474 02028021 */  addu      $s0, $s0, $v0
/* 3E1B08 E00E8478 001080C0 */  sll       $s0, $s0, 3
/* 3E1B0C E00E847C 0C080108 */  jal       func_E0200420
/* 3E1B10 E00E8480 02038021 */   addu     $s0, $s0, $v1
/* 3E1B14 E00E8484 27B10050 */  addiu     $s1, $sp, 0x50
/* 3E1B18 E00E8488 8E450044 */  lw        $a1, 0x44($s2)
/* 3E1B1C E00E848C 0220202D */  daddu     $a0, $s1, $zero
/* 3E1B20 E00E8490 00A0302D */  daddu     $a2, $a1, $zero
/* 3E1B24 E00E8494 0C080110 */  jal       func_E0200440
/* 3E1B28 E00E8498 00A0382D */   daddu    $a3, $a1, $zero
/* 3E1B2C E00E849C 0220202D */  daddu     $a0, $s1, $zero
/* 3E1B30 E00E84A0 27A50010 */  addiu     $a1, $sp, 0x10
/* 3E1B34 E00E84A4 0C080114 */  jal       func_E0200450
/* 3E1B38 E00E84A8 00A0302D */   daddu    $a2, $a1, $zero
/* 3E1B3C E00E84AC 27A40010 */  addiu     $a0, $sp, 0x10
/* 3E1B40 E00E84B0 3C118007 */  lui       $s1, %hi(gMatrixListPos)
/* 3E1B44 E00E84B4 263141F0 */  addiu     $s1, $s1, %lo(gMatrixListPos)
/* 3E1B48 E00E84B8 3C14800A */  lui       $s4, %hi(gDisplayContext)
/* 3E1B4C E00E84BC 2694A674 */  addiu     $s4, $s4, %lo(gDisplayContext)
/* 3E1B50 E00E84C0 96250000 */  lhu       $a1, ($s1)
/* 3E1B54 E00E84C4 8E820000 */  lw        $v0, ($s4)
/* 3E1B58 E00E84C8 00052980 */  sll       $a1, $a1, 6
/* 3E1B5C E00E84CC 00B62821 */  addu      $a1, $a1, $s6
/* 3E1B60 E00E84D0 0C080118 */  jal       func_E0200460
/* 3E1B64 E00E84D4 00452821 */   addu     $a1, $v0, $a1
/* 3E1B68 E00E84D8 3C03DA38 */  lui       $v1, 0xda38
/* 3E1B6C E00E84DC 34630002 */  ori       $v1, $v1, 2
/* 3E1B70 E00E84E0 3C06DA38 */  lui       $a2, 0xda38
/* 3E1B74 E00E84E4 34C60001 */  ori       $a2, $a2, 1
/* 3E1B78 E00E84E8 3C09D838 */  lui       $t1, 0xd838
/* 3E1B7C E00E84EC 35290002 */  ori       $t1, $t1, 2
/* 3E1B80 E00E84F0 32B500FF */  andi      $s5, $s5, 0xff
/* 3E1B84 E00E84F4 3C07DE00 */  lui       $a3, 0xde00
/* 3E1B88 E00E84F8 8E640000 */  lw        $a0, ($s3)
/* 3E1B8C E00E84FC 96220000 */  lhu       $v0, ($s1)
/* 3E1B90 E00E8500 0080282D */  daddu     $a1, $a0, $zero
/* 3E1B94 E00E8504 24840008 */  addiu     $a0, $a0, 8
/* 3E1B98 E00E8508 AE640000 */  sw        $a0, ($s3)
/* 3E1B9C E00E850C ACA30000 */  sw        $v1, ($a1)
/* 3E1BA0 E00E8510 24430001 */  addiu     $v1, $v0, 1
/* 3E1BA4 E00E8514 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3E1BA8 E00E8518 00021180 */  sll       $v0, $v0, 6
/* 3E1BAC E00E851C A6230000 */  sh        $v1, ($s1)
/* 3E1BB0 E00E8520 8E830000 */  lw        $v1, ($s4)
/* 3E1BB4 E00E8524 00561021 */  addu      $v0, $v0, $s6
/* 3E1BB8 E00E8528 00621821 */  addu      $v1, $v1, $v0
/* 3E1BBC E00E852C 24820008 */  addiu     $v0, $a0, 8
/* 3E1BC0 E00E8530 ACA30004 */  sw        $v1, 4($a1)
/* 3E1BC4 E00E8534 AE620000 */  sw        $v0, ($s3)
/* 3E1BC8 E00E8538 24820010 */  addiu     $v0, $a0, 0x10
/* 3E1BCC E00E853C AC860000 */  sw        $a2, ($a0)
/* 3E1BD0 E00E8540 AE620000 */  sw        $v0, ($s3)
/* 3E1BD4 E00E8544 8E030204 */  lw        $v1, 0x204($s0)
/* 3E1BD8 E00E8548 3C02FA00 */  lui       $v0, 0xfa00
/* 3E1BDC E00E854C AC820008 */  sw        $v0, 8($a0)
/* 3E1BE0 E00E8550 AC830004 */  sw        $v1, 4($a0)
/* 3E1BE4 E00E8554 92420027 */  lbu       $v0, 0x27($s2)
/* 3E1BE8 E00E8558 9245002B */  lbu       $a1, 0x2b($s2)
/* 3E1BEC E00E855C 9246002F */  lbu       $a2, 0x2f($s2)
/* 3E1BF0 E00E8560 24830018 */  addiu     $v1, $a0, 0x18
/* 3E1BF4 E00E8564 AE630000 */  sw        $v1, ($s3)
/* 3E1BF8 E00E8568 3C03FB00 */  lui       $v1, 0xfb00
/* 3E1BFC E00E856C AC830010 */  sw        $v1, 0x10($a0)
/* 3E1C00 E00E8570 00021600 */  sll       $v0, $v0, 0x18
/* 3E1C04 E00E8574 00052C00 */  sll       $a1, $a1, 0x10
/* 3E1C08 E00E8578 00451025 */  or        $v0, $v0, $a1
/* 3E1C0C E00E857C 00063200 */  sll       $a2, $a2, 8
/* 3E1C10 E00E8580 00461025 */  or        $v0, $v0, $a2
/* 3E1C14 E00E8584 00551025 */  or        $v0, $v0, $s5
/* 3E1C18 E00E8588 AC82000C */  sw        $v0, 0xc($a0)
/* 3E1C1C E00E858C 92420037 */  lbu       $v0, 0x37($s2)
/* 3E1C20 E00E8590 9245003B */  lbu       $a1, 0x3b($s2)
/* 3E1C24 E00E8594 9246003F */  lbu       $a2, 0x3f($s2)
/* 3E1C28 E00E8598 92480043 */  lbu       $t0, 0x43($s2)
/* 3E1C2C E00E859C 24830020 */  addiu     $v1, $a0, 0x20
/* 3E1C30 E00E85A0 AE630000 */  sw        $v1, ($s3)
/* 3E1C34 E00E85A4 AC870018 */  sw        $a3, 0x18($a0)
/* 3E1C38 E00E85A8 00021600 */  sll       $v0, $v0, 0x18
/* 3E1C3C E00E85AC 00052C00 */  sll       $a1, $a1, 0x10
/* 3E1C40 E00E85B0 00451025 */  or        $v0, $v0, $a1
/* 3E1C44 E00E85B4 00063200 */  sll       $a2, $a2, 8
/* 3E1C48 E00E85B8 00461025 */  or        $v0, $v0, $a2
/* 3E1C4C E00E85BC 00481025 */  or        $v0, $v0, $t0
/* 3E1C50 E00E85C0 AC820014 */  sw        $v0, 0x14($a0)
/* 3E1C54 E00E85C4 3C03E00F */  lui       $v1, %hi(D_E00E8634)
/* 3E1C58 E00E85C8 8C638634 */  lw        $v1, %lo(D_E00E8634)($v1)
/* 3E1C5C E00E85CC 24820028 */  addiu     $v0, $a0, 0x28
/* 3E1C60 E00E85D0 AE620000 */  sw        $v0, ($s3)
/* 3E1C64 E00E85D4 AC870020 */  sw        $a3, 0x20($a0)
/* 3E1C68 E00E85D8 AC83001C */  sw        $v1, 0x1c($a0)
/* 3E1C6C E00E85DC 3C03E00F */  lui       $v1, %hi(D_E00E8630)
/* 3E1C70 E00E85E0 8C638630 */  lw        $v1, %lo(D_E00E8630)($v1)
/* 3E1C74 E00E85E4 24820030 */  addiu     $v0, $a0, 0x30
/* 3E1C78 E00E85E8 AE620000 */  sw        $v0, ($s3)
/* 3E1C7C E00E85EC 24020040 */  addiu     $v0, $zero, 0x40
/* 3E1C80 E00E85F0 AC830024 */  sw        $v1, 0x24($a0)
/* 3E1C84 E00E85F4 AC890028 */  sw        $t1, 0x28($a0)
/* 3E1C88 E00E85F8 AC82002C */  sw        $v0, 0x2c($a0)
/* 3E1C8C E00E85FC 8FBF00AC */  lw        $ra, 0xac($sp)
/* 3E1C90 E00E8600 8FB600A8 */  lw        $s6, 0xa8($sp)
/* 3E1C94 E00E8604 8FB500A4 */  lw        $s5, 0xa4($sp)
/* 3E1C98 E00E8608 8FB400A0 */  lw        $s4, 0xa0($sp)
/* 3E1C9C E00E860C 8FB3009C */  lw        $s3, 0x9c($sp)
/* 3E1CA0 E00E8610 8FB20098 */  lw        $s2, 0x98($sp)
/* 3E1CA4 E00E8614 8FB10094 */  lw        $s1, 0x94($sp)
/* 3E1CA8 E00E8618 8FB00090 */  lw        $s0, 0x90($sp)
/* 3E1CAC E00E861C 03E00008 */  jr        $ra
/* 3E1CB0 E00E8620 27BD00B0 */   addiu    $sp, $sp, 0xb0
/* 3E1CB4 E00E8624 00000000 */  nop
/* 3E1CB8 E00E8628 00000000 */  nop
/* 3E1CBC E00E862C 00000000 */  nop
