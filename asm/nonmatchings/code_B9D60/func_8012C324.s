.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8012C324
/* C2A24 8012C324 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C2A28 8012C328 00A0502D */  daddu     $t2, $a1, $zero
/* C2A2C 8012C32C AFB20008 */  sw        $s2, 8($sp)
/* C2A30 8012C330 00C0902D */  daddu     $s2, $a2, $zero
/* C2A34 8012C334 AFB10004 */  sw        $s1, 4($sp)
/* C2A38 8012C338 00E0882D */  daddu     $s1, $a3, $zero
/* C2A3C 8012C33C AFB40010 */  sw        $s4, 0x10($sp)
/* C2A40 8012C340 AFB3000C */  sw        $s3, 0xc($sp)
/* C2A44 8012C344 AFB00000 */  sw        $s0, ($sp)
/* C2A48 8012C348 9542003C */  lhu       $v0, 0x3c($t2)
/* C2A4C 8012C34C C5460018 */  lwc1      $f6, 0x18($t2)
/* C2A50 8012C350 C542001C */  lwc1      $f2, 0x1c($t2)
/* C2A54 8012C354 8FA60028 */  lw        $a2, 0x28($sp)
/* C2A58 8012C358 00021080 */  sll       $v0, $v0, 2
/* C2A5C 8012C35C 3C09802F */  lui       $t1, %hi(D_802EB5A8)
/* C2A60 8012C360 01224821 */  addu      $t1, $t1, $v0
/* C2A64 8012C364 8D29B5A8 */  lw        $t1, %lo(D_802EB5A8)($t1)
/* C2A68 8012C368 8FA3002C */  lw        $v1, 0x2c($sp)
/* C2A6C 8012C36C 91220000 */  lbu       $v0, ($t1)
/* C2A70 8012C370 8D4B0004 */  lw        $t3, 4($t2)
/* C2A74 8012C374 44822000 */  mtc1      $v0, $f4
/* C2A78 8012C378 00000000 */  nop
/* C2A7C 8012C37C 46802120 */  cvt.s.w   $f4, $f4
/* C2A80 8012C380 46043102 */  mul.s     $f4, $f6, $f4
/* C2A84 8012C384 00000000 */  nop
/* C2A88 8012C388 954C003E */  lhu       $t4, 0x3e($t2)
/* C2A8C 8012C38C 91220001 */  lbu       $v0, 1($t1)
/* C2A90 8012C390 8D470008 */  lw        $a3, 8($t2)
/* C2A94 8012C394 44820000 */  mtc1      $v0, $f0
/* C2A98 8012C398 00000000 */  nop
/* C2A9C 8012C39C 46800020 */  cvt.s.w   $f0, $f0
/* C2AA0 8012C3A0 46001082 */  mul.s     $f2, $f2, $f0
/* C2AA4 8012C3A4 00000000 */  nop
/* C2AA8 8012C3A8 8D48000C */  lw        $t0, 0xc($t2)
/* C2AAC 8012C3AC 8D450000 */  lw        $a1, ($t2)
/* C2AB0 8012C3B0 4600220D */  trunc.w.s $f8, $f4
/* C2AB4 8012C3B4 44024000 */  mfc1      $v0, $f8
/* C2AB8 8012C3B8 00000000 */  nop
/* C2ABC 8012C3BC 00C26821 */  addu      $t5, $a2, $v0
/* C2AC0 8012C3C0 4600120D */  trunc.w.s $f8, $f2
/* C2AC4 8012C3C4 44024000 */  mfc1      $v0, $f8
/* C2AC8 8012C3C8 00000000 */  nop
/* C2ACC 8012C3CC 00627021 */  addu      $t6, $v1, $v0
/* C2AD0 8012C3D0 00CB102A */  slt       $v0, $a2, $t3
/* C2AD4 8012C3D4 1040016D */  beqz      $v0, .L8012C98C
/* C2AD8 8012C3D8 0068102A */   slt      $v0, $v1, $t0
/* C2ADC 8012C3DC 1040016B */  beqz      $v0, .L8012C98C
/* C2AE0 8012C3E0 00AD102A */   slt      $v0, $a1, $t5
/* C2AE4 8012C3E4 10400169 */  beqz      $v0, .L8012C98C
/* C2AE8 8012C3E8 00EE102A */   slt      $v0, $a3, $t6
/* C2AEC 8012C3EC 10400167 */  beqz      $v0, .L8012C98C
/* C2AF0 8012C3F0 00C5102A */   slt      $v0, $a2, $a1
/* C2AF4 8012C3F4 10400017 */  beqz      $v0, .L8012C454
/* C2AF8 8012C3F8 00C51023 */   subu     $v0, $a2, $a1
/* C2AFC 8012C3FC 04420001 */  bltzl     $v0, .L8012C404
/* C2B00 8012C400 00021023 */   negu     $v0, $v0
.L8012C404:
/* C2B04 8012C404 44820000 */  mtc1      $v0, $f0
/* C2B08 8012C408 00000000 */  nop
/* C2B0C 8012C40C 46800020 */  cvt.s.w   $f0, $f0
/* C2B10 8012C410 46060103 */  div.s     $f4, $f0, $f6
/* C2B14 8012C414 3C013FE0 */  lui       $at, 0x3fe0
/* C2B18 8012C418 44811800 */  mtc1      $at, $f3
/* C2B1C 8012C41C 44801000 */  mtc1      $zero, $f2
/* C2B20 8012C420 46002021 */  cvt.d.s   $f0, $f4
/* C2B24 8012C424 46220000 */  add.d     $f0, $f0, $f2
/* C2B28 8012C428 3C014040 */  lui       $at, 0x4040
/* C2B2C 8012C42C 44811800 */  mtc1      $at, $f3
/* C2B30 8012C430 44801000 */  mtc1      $zero, $f2
/* C2B34 8012C434 00000000 */  nop
/* C2B38 8012C438 46220002 */  mul.d     $f0, $f0, $f2
/* C2B3C 8012C43C 00000000 */  nop
/* C2B40 8012C440 46200020 */  cvt.s.d   $f0, $f0
/* C2B44 8012C444 4600020D */  trunc.w.s $f8, $f0
/* C2B48 8012C448 44104000 */  mfc1      $s0, $f8
/* C2B4C 8012C44C 0804B117 */  j         .L8012C45C
/* C2B50 8012C450 00A0C82D */   daddu    $t9, $a1, $zero
.L8012C454:
/* C2B54 8012C454 0000802D */  daddu     $s0, $zero, $zero
/* C2B58 8012C458 00C0C82D */  daddu     $t9, $a2, $zero
.L8012C45C:
/* C2B5C 8012C45C 0067102A */  slt       $v0, $v1, $a3
/* C2B60 8012C460 10400017 */  beqz      $v0, .L8012C4C0
/* C2B64 8012C464 0000C02D */   daddu    $t8, $zero, $zero
/* C2B68 8012C468 8C8204FC */  lw        $v0, 0x4fc($a0)
/* C2B6C 8012C46C 30420400 */  andi      $v0, $v0, 0x400
/* C2B70 8012C470 10400004 */  beqz      $v0, .L8012C484
/* C2B74 8012C474 00671023 */   subu     $v0, $v1, $a3
/* C2B78 8012C478 04610012 */  bgez      $v1, .L8012C4C4
/* C2B7C 8012C47C 0060782D */   daddu    $t7, $v1, $zero
/* C2B80 8012C480 00671023 */  subu      $v0, $v1, $a3
.L8012C484:
/* C2B84 8012C484 04420001 */  bltzl     $v0, .L8012C48C
/* C2B88 8012C488 00021023 */   negu     $v0, $v0
.L8012C48C:
/* C2B8C 8012C48C 44822000 */  mtc1      $v0, $f4
/* C2B90 8012C490 00000000 */  nop
/* C2B94 8012C494 46802120 */  cvt.s.w   $f4, $f4
/* C2B98 8012C498 C542001C */  lwc1      $f2, 0x1c($t2)
/* C2B9C 8012C49C 3C014200 */  lui       $at, 0x4200
/* C2BA0 8012C4A0 44810000 */  mtc1      $at, $f0
/* C2BA4 8012C4A4 46022103 */  div.s     $f4, $f4, $f2
/* C2BA8 8012C4A8 46002002 */  mul.s     $f0, $f4, $f0
/* C2BAC 8012C4AC 00000000 */  nop
/* C2BB0 8012C4B0 4600020D */  trunc.w.s $f8, $f0
/* C2BB4 8012C4B4 44184000 */  mfc1      $t8, $f8
/* C2BB8 8012C4B8 0804B131 */  j         .L8012C4C4
/* C2BBC 8012C4BC 00E0782D */   daddu    $t7, $a3, $zero
.L8012C4C0:
/* C2BC0 8012C4C0 0060782D */  daddu     $t7, $v1, $zero
.L8012C4C4:
/* C2BC4 8012C4C4 01AB102A */  slt       $v0, $t5, $t3
/* C2BC8 8012C4C8 50400001 */  beql      $v0, $zero, .L8012C4D0
/* C2BCC 8012C4CC 0160682D */   daddu    $t5, $t3, $zero
.L8012C4D0:
/* C2BD0 8012C4D0 01C0582D */  daddu     $t3, $t6, $zero
/* C2BD4 8012C4D4 0168102A */  slt       $v0, $t3, $t0
/* C2BD8 8012C4D8 50400001 */  beql      $v0, $zero, .L8012C4E0
/* C2BDC 8012C4DC 0100582D */   daddu    $t3, $t0, $zero
.L8012C4E0:
/* C2BE0 8012C4E0 C5440018 */  lwc1      $f4, 0x18($t2)
/* C2BE4 8012C4E4 3C013F80 */  lui       $at, 0x3f80
/* C2BE8 8012C4E8 44811000 */  mtc1      $at, $f2
/* C2BEC 8012C4EC 3C014480 */  lui       $at, 0x4480
/* C2BF0 8012C4F0 44813000 */  mtc1      $at, $f6
/* C2BF4 8012C4F4 46041103 */  div.s     $f4, $f2, $f4
/* C2BF8 8012C4F8 46062102 */  mul.s     $f4, $f4, $f6
/* C2BFC 8012C4FC 00000000 */  nop
/* C2C00 8012C500 C540001C */  lwc1      $f0, 0x1c($t2)
/* C2C04 8012C504 46001083 */  div.s     $f2, $f2, $f0
/* C2C08 8012C508 46061082 */  mul.s     $f2, $f2, $f6
/* C2C0C 8012C50C 00000000 */  nop
/* C2C10 8012C510 95440034 */  lhu       $a0, 0x34($t2)
/* C2C14 8012C514 30820011 */  andi      $v0, $a0, 0x11
/* C2C18 8012C518 4600220D */  trunc.w.s $f8, $f4
/* C2C1C 8012C51C 440E4000 */  mfc1      $t6, $f8
/* C2C20 8012C520 4600120D */  trunc.w.s $f8, $f2
/* C2C24 8012C524 44134000 */  mfc1      $s3, $f8
/* C2C28 8012C528 1040002C */  beqz      $v0, .L8012C5DC
/* C2C2C 8012C52C 3082FFEE */   andi     $v0, $a0, 0xffee
/* C2C30 8012C530 3C07F500 */  lui       $a3, 0xf500
/* C2C34 8012C534 34E70100 */  ori       $a3, $a3, 0x100
/* C2C38 8012C538 3C080703 */  lui       $t0, 0x703
/* C2C3C 8012C53C 3508C000 */  ori       $t0, $t0, 0xc000
/* C2C40 8012C540 3C05800A */  lui       $a1, %hi(gMasterGfxPos)
/* C2C44 8012C544 24A5A66C */  addiu     $a1, $a1, %lo(gMasterGfxPos)
/* C2C48 8012C548 8CA30000 */  lw        $v1, ($a1)
/* C2C4C 8012C54C A5420034 */  sh        $v0, 0x34($t2)
/* C2C50 8012C550 3C02FD10 */  lui       $v0, 0xfd10
/* C2C54 8012C554 3C04802F */  lui       $a0, %hi(D_802F4560)
/* C2C58 8012C558 24844560 */  addiu     $a0, $a0, %lo(D_802F4560)
/* C2C5C 8012C55C 0060302D */  daddu     $a2, $v1, $zero
/* C2C60 8012C560 24630008 */  addiu     $v1, $v1, 8
/* C2C64 8012C564 ACA30000 */  sw        $v1, ($a1)
/* C2C68 8012C568 ACC20000 */  sw        $v0, ($a2)
/* C2C6C 8012C56C 00111100 */  sll       $v0, $s1, 4
/* C2C70 8012C570 00441021 */  addu      $v0, $v0, $a0
/* C2C74 8012C574 ACC20004 */  sw        $v0, 4($a2)
/* C2C78 8012C578 24620008 */  addiu     $v0, $v1, 8
/* C2C7C 8012C57C ACA20000 */  sw        $v0, ($a1)
/* C2C80 8012C580 3C02E800 */  lui       $v0, 0xe800
/* C2C84 8012C584 AC620000 */  sw        $v0, ($v1)
/* C2C88 8012C588 24620010 */  addiu     $v0, $v1, 0x10
/* C2C8C 8012C58C AC600004 */  sw        $zero, 4($v1)
/* C2C90 8012C590 ACA20000 */  sw        $v0, ($a1)
/* C2C94 8012C594 3C020700 */  lui       $v0, 0x700
/* C2C98 8012C598 AC62000C */  sw        $v0, 0xc($v1)
/* C2C9C 8012C59C 24620018 */  addiu     $v0, $v1, 0x18
/* C2CA0 8012C5A0 AC670008 */  sw        $a3, 8($v1)
/* C2CA4 8012C5A4 ACA20000 */  sw        $v0, ($a1)
/* C2CA8 8012C5A8 3C02E600 */  lui       $v0, 0xe600
/* C2CAC 8012C5AC AC620010 */  sw        $v0, 0x10($v1)
/* C2CB0 8012C5B0 24620020 */  addiu     $v0, $v1, 0x20
/* C2CB4 8012C5B4 AC600014 */  sw        $zero, 0x14($v1)
/* C2CB8 8012C5B8 ACA20000 */  sw        $v0, ($a1)
/* C2CBC 8012C5BC 3C02F000 */  lui       $v0, 0xf000
/* C2CC0 8012C5C0 AC620018 */  sw        $v0, 0x18($v1)
/* C2CC4 8012C5C4 24620028 */  addiu     $v0, $v1, 0x28
/* C2CC8 8012C5C8 AC68001C */  sw        $t0, 0x1c($v1)
/* C2CCC 8012C5CC ACA20000 */  sw        $v0, ($a1)
/* C2CD0 8012C5D0 3C02E700 */  lui       $v0, 0xe700
/* C2CD4 8012C5D4 AC620020 */  sw        $v0, 0x20($v1)
/* C2CD8 8012C5D8 AC600024 */  sw        $zero, 0x24($v1)
.L8012C5DC:
/* C2CDC 8012C5DC 91220000 */  lbu       $v0, ($t1)
/* C2CE0 8012C5E0 2C420010 */  sltiu     $v0, $v0, 0x10
/* C2CE4 8012C5E4 1440006B */  bnez      $v0, .L8012C794
/* C2CE8 8012C5E8 00000000 */   nop
/* C2CEC 8012C5EC 91220000 */  lbu       $v0, ($t1)
/* C2CF0 8012C5F0 3042000F */  andi      $v0, $v0, 0xf
/* C2CF4 8012C5F4 14400067 */  bnez      $v0, .L8012C794
/* C2CF8 8012C5F8 3C02FD50 */   lui      $v0, 0xfd50
/* C2CFC 8012C5FC 3C06800A */  lui       $a2, %hi(gMasterGfxPos)
/* C2D00 8012C600 24C6A66C */  addiu     $a2, $a2, %lo(gMasterGfxPos)
/* C2D04 8012C604 8CC40000 */  lw        $a0, ($a2)
/* C2D08 8012C608 0080382D */  daddu     $a3, $a0, $zero
/* C2D0C 8012C60C 24840008 */  addiu     $a0, $a0, 8
/* C2D10 8012C610 ACC40000 */  sw        $a0, ($a2)
/* C2D14 8012C614 ACE20000 */  sw        $v0, ($a3)
/* C2D18 8012C618 24820008 */  addiu     $v0, $a0, 8
/* C2D1C 8012C61C ACC20000 */  sw        $v0, ($a2)
/* C2D20 8012C620 24820010 */  addiu     $v0, $a0, 0x10
/* C2D24 8012C624 ACC20000 */  sw        $v0, ($a2)
/* C2D28 8012C628 000C1040 */  sll       $v0, $t4, 1
/* C2D2C 8012C62C 004C1021 */  addu      $v0, $v0, $t4
/* C2D30 8012C630 00021080 */  sll       $v0, $v0, 2
/* C2D34 8012C634 8D250008 */  lw        $a1, 8($t1)
/* C2D38 8012C638 95230004 */  lhu       $v1, 4($t1)
/* C2D3C 8012C63C 00451021 */  addu      $v0, $v0, $a1
/* C2D40 8012C640 00720018 */  mult      $v1, $s2
/* C2D44 8012C644 24830018 */  addiu     $v1, $a0, 0x18
/* C2D48 8012C648 8C420000 */  lw        $v0, ($v0)
/* C2D4C 8012C64C 3C050700 */  lui       $a1, 0x700
/* C2D50 8012C650 ACC30000 */  sw        $v1, ($a2)
/* C2D54 8012C654 0000A012 */  mflo      $s4
/* C2D58 8012C658 00541021 */  addu      $v0, $v0, $s4
/* C2D5C 8012C65C ACE20004 */  sw        $v0, 4($a3)
/* C2D60 8012C660 3C02F550 */  lui       $v0, 0xf550
/* C2D64 8012C664 AC820000 */  sw        $v0, ($a0)
/* C2D68 8012C668 3C02E600 */  lui       $v0, 0xe600
/* C2D6C 8012C66C AC820008 */  sw        $v0, 8($a0)
/* C2D70 8012C670 3C02F300 */  lui       $v0, 0xf300
/* C2D74 8012C674 AC850004 */  sw        $a1, 4($a0)
/* C2D78 8012C678 AC80000C */  sw        $zero, 0xc($a0)
/* C2D7C 8012C67C AC820010 */  sw        $v0, 0x10($a0)
/* C2D80 8012C680 91230000 */  lbu       $v1, ($t1)
/* C2D84 8012C684 24860014 */  addiu     $a2, $a0, 0x14
/* C2D88 8012C688 00032102 */  srl       $a0, $v1, 4
/* C2D8C 8012C68C 10800002 */  beqz      $a0, .L8012C698
/* C2D90 8012C690 24080800 */   addiu    $t0, $zero, 0x800
/* C2D94 8012C694 248807FF */  addiu     $t0, $a0, 0x7ff
.L8012C698:
/* C2D98 8012C698 91220001 */  lbu       $v0, 1($t1)
/* C2D9C 8012C69C 00620018 */  mult      $v1, $v0
/* C2DA0 8012C6A0 0000A012 */  mflo      $s4
/* C2DA4 8012C6A4 26820003 */  addiu     $v0, $s4, 3
/* C2DA8 8012C6A8 00021083 */  sra       $v0, $v0, 2
/* C2DAC 8012C6AC 2443FFFF */  addiu     $v1, $v0, -1
/* C2DB0 8012C6B0 28620800 */  slti      $v0, $v1, 0x800
/* C2DB4 8012C6B4 50400001 */  beql      $v0, $zero, .L8012C6BC
/* C2DB8 8012C6B8 240307FF */   addiu    $v1, $zero, 0x7ff
.L8012C6BC:
/* C2DBC 8012C6BC 30620FFF */  andi      $v0, $v1, 0xfff
/* C2DC0 8012C6C0 00021300 */  sll       $v0, $v0, 0xc
/* C2DC4 8012C6C4 1080000D */  beqz      $a0, .L8012C6FC
/* C2DC8 8012C6C8 00452825 */   or       $a1, $v0, $a1
/* C2DCC 8012C6CC 14800002 */  bnez      $a0, .L8012C6D8
/* C2DD0 8012C6D0 0104001A */   div      $zero, $t0, $a0
/* C2DD4 8012C6D4 0007000D */  break     7
.L8012C6D8:
/* C2DD8 8012C6D8 2401FFFF */   addiu    $at, $zero, -1
/* C2DDC 8012C6DC 14810004 */  bne       $a0, $at, .L8012C6F0
/* C2DE0 8012C6E0 3C018000 */   lui      $at, 0x8000
/* C2DE4 8012C6E4 15010002 */  bne       $t0, $at, .L8012C6F0
/* C2DE8 8012C6E8 00000000 */   nop
/* C2DEC 8012C6EC 0006000D */  break     6
.L8012C6F0:
/* C2DF0 8012C6F0 00001012 */   mflo     $v0
/* C2DF4 8012C6F4 0804B1C0 */  j         .L8012C700
/* C2DF8 8012C6F8 00A21025 */   or       $v0, $a1, $v0
.L8012C6FC:
/* C2DFC 8012C6FC 00A81025 */  or        $v0, $a1, $t0
.L8012C700:
/* C2E00 8012C700 3C05800A */  lui       $a1, %hi(gMasterGfxPos)
/* C2E04 8012C704 24A5A66C */  addiu     $a1, $a1, %lo(gMasterGfxPos)
/* C2E08 8012C708 8CA40000 */  lw        $a0, ($a1)
/* C2E0C 8012C70C ACC20000 */  sw        $v0, ($a2)
/* C2E10 8012C710 3C02E700 */  lui       $v0, 0xe700
/* C2E14 8012C714 0080182D */  daddu     $v1, $a0, $zero
/* C2E18 8012C718 24840008 */  addiu     $a0, $a0, 8
/* C2E1C 8012C71C ACA40000 */  sw        $a0, ($a1)
/* C2E20 8012C720 AC620000 */  sw        $v0, ($v1)
/* C2E24 8012C724 24820008 */  addiu     $v0, $a0, 8
/* C2E28 8012C728 AC600004 */  sw        $zero, 4($v1)
/* C2E2C 8012C72C ACA20000 */  sw        $v0, ($a1)
/* C2E30 8012C730 91220000 */  lbu       $v0, ($t1)
/* C2E34 8012C734 24830010 */  addiu     $v1, $a0, 0x10
/* C2E38 8012C738 AC800004 */  sw        $zero, 4($a0)
/* C2E3C 8012C73C ACA30000 */  sw        $v1, ($a1)
/* C2E40 8012C740 3C03F200 */  lui       $v1, 0xf200
/* C2E44 8012C744 AC830008 */  sw        $v1, 8($a0)
/* C2E48 8012C748 3C03F540 */  lui       $v1, 0xf540
/* C2E4C 8012C74C 00021042 */  srl       $v0, $v0, 1
/* C2E50 8012C750 24420007 */  addiu     $v0, $v0, 7
/* C2E54 8012C754 000210C2 */  srl       $v0, $v0, 3
/* C2E58 8012C758 00021240 */  sll       $v0, $v0, 9
/* C2E5C 8012C75C 00431025 */  or        $v0, $v0, $v1
/* C2E60 8012C760 AC820000 */  sw        $v0, ($a0)
/* C2E64 8012C764 91230000 */  lbu       $v1, ($t1)
/* C2E68 8012C768 91220001 */  lbu       $v0, 1($t1)
/* C2E6C 8012C76C 2463FFFF */  addiu     $v1, $v1, -1
/* C2E70 8012C770 00031880 */  sll       $v1, $v1, 2
/* C2E74 8012C774 30630FFF */  andi      $v1, $v1, 0xfff
/* C2E78 8012C778 00031B00 */  sll       $v1, $v1, 0xc
/* C2E7C 8012C77C 2442FFFF */  addiu     $v0, $v0, -1
/* C2E80 8012C780 00021080 */  sll       $v0, $v0, 2
/* C2E84 8012C784 30420FFF */  andi      $v0, $v0, 0xfff
/* C2E88 8012C788 00621825 */  or        $v1, $v1, $v0
/* C2E8C 8012C78C 0804B23D */  j         .L8012C8F4
/* C2E90 8012C790 AC83000C */   sw       $v1, 0xc($a0)
.L8012C794:
/* C2E94 8012C794 3C06800A */  lui       $a2, %hi(gMasterGfxPos)
/* C2E98 8012C798 24C6A66C */  addiu     $a2, $a2, %lo(gMasterGfxPos)
/* C2E9C 8012C79C 8CC50000 */  lw        $a1, ($a2)
/* C2EA0 8012C7A0 00A0382D */  daddu     $a3, $a1, $zero
/* C2EA4 8012C7A4 24A50008 */  addiu     $a1, $a1, 8
/* C2EA8 8012C7A8 ACC50000 */  sw        $a1, ($a2)
/* C2EAC 8012C7AC 91220000 */  lbu       $v0, ($t1)
/* C2EB0 8012C7B0 3C03FD48 */  lui       $v1, 0xfd48
/* C2EB4 8012C7B4 00021042 */  srl       $v0, $v0, 1
/* C2EB8 8012C7B8 2442FFFF */  addiu     $v0, $v0, -1
/* C2EBC 8012C7BC 30420FFF */  andi      $v0, $v0, 0xfff
/* C2EC0 8012C7C0 00431025 */  or        $v0, $v0, $v1
/* C2EC4 8012C7C4 ACE20000 */  sw        $v0, ($a3)
/* C2EC8 8012C7C8 000C1040 */  sll       $v0, $t4, 1
/* C2ECC 8012C7CC 004C1021 */  addu      $v0, $v0, $t4
/* C2ED0 8012C7D0 00021080 */  sll       $v0, $v0, 2
/* C2ED4 8012C7D4 8D240008 */  lw        $a0, 8($t1)
/* C2ED8 8012C7D8 95230004 */  lhu       $v1, 4($t1)
/* C2EDC 8012C7DC 00441021 */  addu      $v0, $v0, $a0
/* C2EE0 8012C7E0 00720018 */  mult      $v1, $s2
/* C2EE4 8012C7E4 8C420000 */  lw        $v0, ($v0)
/* C2EE8 8012C7E8 24A30008 */  addiu     $v1, $a1, 8
/* C2EEC 8012C7EC ACC30000 */  sw        $v1, ($a2)
/* C2EF0 8012C7F0 24A30010 */  addiu     $v1, $a1, 0x10
/* C2EF4 8012C7F4 0000A012 */  mflo      $s4
/* C2EF8 8012C7F8 00541021 */  addu      $v0, $v0, $s4
/* C2EFC 8012C7FC ACE20004 */  sw        $v0, 4($a3)
/* C2F00 8012C800 91220000 */  lbu       $v0, ($t1)
/* C2F04 8012C804 3C070700 */  lui       $a3, 0x700
/* C2F08 8012C808 ACA70004 */  sw        $a3, 4($a1)
/* C2F0C 8012C80C ACC30000 */  sw        $v1, ($a2)
/* C2F10 8012C810 3C03E600 */  lui       $v1, 0xe600
/* C2F14 8012C814 ACA30008 */  sw        $v1, 8($a1)
/* C2F18 8012C818 24A30018 */  addiu     $v1, $a1, 0x18
/* C2F1C 8012C81C ACA0000C */  sw        $zero, 0xc($a1)
/* C2F20 8012C820 ACC30000 */  sw        $v1, ($a2)
/* C2F24 8012C824 3C03F400 */  lui       $v1, 0xf400
/* C2F28 8012C828 ACA30010 */  sw        $v1, 0x10($a1)
/* C2F2C 8012C82C 3C03F548 */  lui       $v1, 0xf548
/* C2F30 8012C830 00021042 */  srl       $v0, $v0, 1
/* C2F34 8012C834 24420007 */  addiu     $v0, $v0, 7
/* C2F38 8012C838 000210C2 */  srl       $v0, $v0, 3
/* C2F3C 8012C83C 00021240 */  sll       $v0, $v0, 9
/* C2F40 8012C840 00431025 */  or        $v0, $v0, $v1
/* C2F44 8012C844 ACA20000 */  sw        $v0, ($a1)
/* C2F48 8012C848 91220000 */  lbu       $v0, ($t1)
/* C2F4C 8012C84C 91240001 */  lbu       $a0, 1($t1)
/* C2F50 8012C850 24A30020 */  addiu     $v1, $a1, 0x20
/* C2F54 8012C854 ACC30000 */  sw        $v1, ($a2)
/* C2F58 8012C858 3C03E700 */  lui       $v1, 0xe700
/* C2F5C 8012C85C ACA30018 */  sw        $v1, 0x18($a1)
/* C2F60 8012C860 24A30028 */  addiu     $v1, $a1, 0x28
/* C2F64 8012C864 ACA0001C */  sw        $zero, 0x1c($a1)
/* C2F68 8012C868 ACC30000 */  sw        $v1, ($a2)
/* C2F6C 8012C86C 2442FFFF */  addiu     $v0, $v0, -1
/* C2F70 8012C870 00021040 */  sll       $v0, $v0, 1
/* C2F74 8012C874 30420FFF */  andi      $v0, $v0, 0xfff
/* C2F78 8012C878 00021300 */  sll       $v0, $v0, 0xc
/* C2F7C 8012C87C 2484FFFF */  addiu     $a0, $a0, -1
/* C2F80 8012C880 00042080 */  sll       $a0, $a0, 2
/* C2F84 8012C884 30840FFF */  andi      $a0, $a0, 0xfff
/* C2F88 8012C888 00872025 */  or        $a0, $a0, $a3
/* C2F8C 8012C88C 00441025 */  or        $v0, $v0, $a0
/* C2F90 8012C890 ACA20014 */  sw        $v0, 0x14($a1)
/* C2F94 8012C894 91220000 */  lbu       $v0, ($t1)
/* C2F98 8012C898 24A30030 */  addiu     $v1, $a1, 0x30
/* C2F9C 8012C89C ACA00024 */  sw        $zero, 0x24($a1)
/* C2FA0 8012C8A0 ACC30000 */  sw        $v1, ($a2)
/* C2FA4 8012C8A4 3C03F200 */  lui       $v1, 0xf200
/* C2FA8 8012C8A8 ACA30028 */  sw        $v1, 0x28($a1)
/* C2FAC 8012C8AC 3C03F540 */  lui       $v1, 0xf540
/* C2FB0 8012C8B0 00021042 */  srl       $v0, $v0, 1
/* C2FB4 8012C8B4 24420007 */  addiu     $v0, $v0, 7
/* C2FB8 8012C8B8 000210C2 */  srl       $v0, $v0, 3
/* C2FBC 8012C8BC 00021240 */  sll       $v0, $v0, 9
/* C2FC0 8012C8C0 00431025 */  or        $v0, $v0, $v1
/* C2FC4 8012C8C4 ACA20020 */  sw        $v0, 0x20($a1)
/* C2FC8 8012C8C8 91230000 */  lbu       $v1, ($t1)
/* C2FCC 8012C8CC 91220001 */  lbu       $v0, 1($t1)
/* C2FD0 8012C8D0 2463FFFF */  addiu     $v1, $v1, -1
/* C2FD4 8012C8D4 00031880 */  sll       $v1, $v1, 2
/* C2FD8 8012C8D8 30630FFF */  andi      $v1, $v1, 0xfff
/* C2FDC 8012C8DC 00031B00 */  sll       $v1, $v1, 0xc
/* C2FE0 8012C8E0 2442FFFF */  addiu     $v0, $v0, -1
/* C2FE4 8012C8E4 00021080 */  sll       $v0, $v0, 2
/* C2FE8 8012C8E8 30420FFF */  andi      $v0, $v0, 0xfff
/* C2FEC 8012C8EC 00621825 */  or        $v1, $v1, $v0
/* C2FF0 8012C8F0 ACA3002C */  sw        $v1, 0x2c($a1)
.L8012C8F4:
/* C2FF4 8012C8F4 3C06800A */  lui       $a2, %hi(gMasterGfxPos)
/* C2FF8 8012C8F8 24C6A66C */  addiu     $a2, $a2, %lo(gMasterGfxPos)
/* C2FFC 8012C8FC 000D1080 */  sll       $v0, $t5, 2
/* C3000 8012C900 30420FFF */  andi      $v0, $v0, 0xfff
/* C3004 8012C904 00021300 */  sll       $v0, $v0, 0xc
/* C3008 8012C908 000B1880 */  sll       $v1, $t3, 2
/* C300C 8012C90C 30630FFF */  andi      $v1, $v1, 0xfff
/* C3010 8012C910 3C04E400 */  lui       $a0, 0xe400
/* C3014 8012C914 00641825 */  or        $v1, $v1, $a0
/* C3018 8012C918 00431025 */  or        $v0, $v0, $v1
/* C301C 8012C91C 000F1880 */  sll       $v1, $t7, 2
/* C3020 8012C920 8CC50000 */  lw        $a1, ($a2)
/* C3024 8012C924 30630FFF */  andi      $v1, $v1, 0xfff
/* C3028 8012C928 00A0382D */  daddu     $a3, $a1, $zero
/* C302C 8012C92C 24A50008 */  addiu     $a1, $a1, 8
/* C3030 8012C930 ACC50000 */  sw        $a1, ($a2)
/* C3034 8012C934 ACE20000 */  sw        $v0, ($a3)
/* C3038 8012C938 00191080 */  sll       $v0, $t9, 2
/* C303C 8012C93C 30420FFF */  andi      $v0, $v0, 0xfff
/* C3040 8012C940 00021300 */  sll       $v0, $v0, 0xc
/* C3044 8012C944 00431025 */  or        $v0, $v0, $v1
/* C3048 8012C948 ACE20004 */  sw        $v0, 4($a3)
/* C304C 8012C94C 24A20008 */  addiu     $v0, $a1, 8
/* C3050 8012C950 ACC20000 */  sw        $v0, ($a2)
/* C3054 8012C954 3C02E100 */  lui       $v0, 0xe100
/* C3058 8012C958 ACA20000 */  sw        $v0, ($a1)
/* C305C 8012C95C 00101400 */  sll       $v0, $s0, 0x10
/* C3060 8012C960 3303FFFF */  andi      $v1, $t8, 0xffff
/* C3064 8012C964 00431025 */  or        $v0, $v0, $v1
/* C3068 8012C968 ACA20004 */  sw        $v0, 4($a1)
/* C306C 8012C96C 24A20010 */  addiu     $v0, $a1, 0x10
/* C3070 8012C970 ACC20000 */  sw        $v0, ($a2)
/* C3074 8012C974 3C02F100 */  lui       $v0, 0xf100
/* C3078 8012C978 ACA20008 */  sw        $v0, 8($a1)
/* C307C 8012C97C 000E1400 */  sll       $v0, $t6, 0x10
/* C3080 8012C980 3263FFFF */  andi      $v1, $s3, 0xffff
/* C3084 8012C984 00431025 */  or        $v0, $v0, $v1
/* C3088 8012C988 ACA2000C */  sw        $v0, 0xc($a1)
.L8012C98C:
/* C308C 8012C98C 8FB40010 */  lw        $s4, 0x10($sp)
/* C3090 8012C990 8FB3000C */  lw        $s3, 0xc($sp)
/* C3094 8012C994 8FB20008 */  lw        $s2, 8($sp)
/* C3098 8012C998 8FB10004 */  lw        $s1, 4($sp)
/* C309C 8012C99C 8FB00000 */  lw        $s0, ($sp)
/* C30A0 8012C9A0 03E00008 */  jr        $ra
/* C30A4 8012C9A4 27BD0018 */   addiu    $sp, $sp, 0x18
