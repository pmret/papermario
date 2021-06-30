.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802419F8_DF83F8
/* DF83F8 802419F8 27BDFF90 */  addiu     $sp, $sp, -0x70
/* DF83FC 802419FC AFB00048 */  sw        $s0, 0x48($sp)
/* DF8400 80241A00 00A0802D */  daddu     $s0, $a1, $zero
/* DF8404 80241A04 AFBF0050 */  sw        $ra, 0x50($sp)
/* DF8408 80241A08 AFB1004C */  sw        $s1, 0x4c($sp)
/* DF840C 80241A0C F7B80068 */  sdc1      $f24, 0x68($sp)
/* DF8410 80241A10 F7B60060 */  sdc1      $f22, 0x60($sp)
/* DF8414 80241A14 F7B40058 */  sdc1      $f20, 0x58($sp)
/* DF8418 80241A18 8C820050 */  lw        $v0, 0x50($a0)
/* DF841C 80241A1C 2404000B */  addiu     $a0, $zero, 0xb
/* DF8420 80241A20 0000302D */  daddu     $a2, $zero, $zero
/* DF8424 80241A24 C6140010 */  lwc1      $f20, 0x10($s0)
/* DF8428 80241A28 4680A520 */  cvt.s.w   $f20, $f20
/* DF842C 80241A2C 3C05437F */  lui       $a1, 0x437f
/* DF8430 80241A30 C6160014 */  lwc1      $f22, 0x14($s0)
/* DF8434 80241A34 4680B5A0 */  cvt.s.w   $f22, $f22
/* DF8438 80241A38 AFA20010 */  sw        $v0, 0x10($sp)
/* DF843C 80241A3C 8E070018 */  lw        $a3, 0x18($s0)
/* DF8440 80241A40 0C00A8ED */  jal       update_lerp
/* DF8444 80241A44 27B10038 */   addiu    $s1, $sp, 0x38
/* DF8448 80241A48 AFB10010 */  sw        $s1, 0x10($sp)
/* DF844C 80241A4C 8E040004 */  lw        $a0, 4($s0)
/* DF8450 80241A50 8E050008 */  lw        $a1, 8($s0)
/* DF8454 80241A54 8E060000 */  lw        $a2, ($s0)
/* DF8458 80241A58 8E07000C */  lw        $a3, 0xc($s0)
/* DF845C 80241A5C 0C04BA38 */  jal       msg_get_glyph
/* DF8460 80241A60 46000606 */   mov.s    $f24, $f0
/* DF8464 80241A64 4600A08D */  trunc.w.s $f2, $f20
/* DF8468 80241A68 44021000 */  mfc1      $v0, $f2
/* DF846C 80241A6C 93A50040 */  lbu       $a1, 0x40($sp)
/* DF8470 80241A70 93A60041 */  lbu       $a2, 0x41($sp)
/* DF8474 80241A74 00021400 */  sll       $v0, $v0, 0x10
/* DF8478 80241A78 AFA00010 */  sw        $zero, 0x10($sp)
/* DF847C 80241A7C 8FA3003C */  lw        $v1, 0x3c($sp)
/* DF8480 80241A80 00021403 */  sra       $v0, $v0, 0x10
/* DF8484 80241A84 AFA20018 */  sw        $v0, 0x18($sp)
/* DF8488 80241A88 4600B08D */  trunc.w.s $f2, $f22
/* DF848C 80241A8C 44021000 */  mfc1      $v0, $f2
/* DF8490 80241A90 00000000 */  nop
/* DF8494 80241A94 00021400 */  sll       $v0, $v0, 0x10
/* DF8498 80241A98 3C014F00 */  lui       $at, 0x4f00
/* DF849C 80241A9C 44810000 */  mtc1      $at, $f0
/* DF84A0 80241AA0 00021403 */  sra       $v0, $v0, 0x10
/* DF84A4 80241AA4 AFA2001C */  sw        $v0, 0x1c($sp)
/* DF84A8 80241AA8 2402000A */  addiu     $v0, $zero, 0xa
/* DF84AC 80241AAC AFA20020 */  sw        $v0, 0x20($sp)
/* DF84B0 80241AB0 24020014 */  addiu     $v0, $zero, 0x14
/* DF84B4 80241AB4 AFA20024 */  sw        $v0, 0x24($sp)
/* DF84B8 80241AB8 2402012C */  addiu     $v0, $zero, 0x12c
/* DF84BC 80241ABC AFA20028 */  sw        $v0, 0x28($sp)
/* DF84C0 80241AC0 240200C8 */  addiu     $v0, $zero, 0xc8
/* DF84C4 80241AC4 AFA2002C */  sw        $v0, 0x2c($sp)
/* DF84C8 80241AC8 4618003E */  c.le.s    $f0, $f24
/* DF84CC 80241ACC 00000000 */  nop
/* DF84D0 80241AD0 45010005 */  bc1t      .L80241AE8
/* DF84D4 80241AD4 AFA30014 */   sw       $v1, 0x14($sp)
/* DF84D8 80241AD8 4600C08D */  trunc.w.s $f2, $f24
/* DF84DC 80241ADC 44031000 */  mfc1      $v1, $f2
/* DF84E0 80241AE0 080906C1 */  j         .L80241B04
/* DF84E4 80241AE4 306200FF */   andi     $v0, $v1, 0xff
.L80241AE8:
/* DF84E8 80241AE8 4600C001 */  sub.s     $f0, $f24, $f0
/* DF84EC 80241AEC 3C028000 */  lui       $v0, 0x8000
/* DF84F0 80241AF0 4600008D */  trunc.w.s $f2, $f0
/* DF84F4 80241AF4 44031000 */  mfc1      $v1, $f2
/* DF84F8 80241AF8 00000000 */  nop
/* DF84FC 80241AFC 00621825 */  or        $v1, $v1, $v0
/* DF8500 80241B00 306200FF */  andi      $v0, $v1, 0xff
.L80241B04:
/* DF8504 80241B04 AFA20030 */  sw        $v0, 0x30($sp)
/* DF8508 80241B08 8E240000 */  lw        $a0, ($s1)
/* DF850C 80241B0C 0C04BA68 */  jal       draw_ci_image_with_clipping
/* DF8510 80241B10 24070002 */   addiu    $a3, $zero, 2
/* DF8514 80241B14 8FBF0050 */  lw        $ra, 0x50($sp)
/* DF8518 80241B18 8FB1004C */  lw        $s1, 0x4c($sp)
/* DF851C 80241B1C 8FB00048 */  lw        $s0, 0x48($sp)
/* DF8520 80241B20 D7B80068 */  ldc1      $f24, 0x68($sp)
/* DF8524 80241B24 D7B60060 */  ldc1      $f22, 0x60($sp)
/* DF8528 80241B28 D7B40058 */  ldc1      $f20, 0x58($sp)
/* DF852C 80241B2C 03E00008 */  jr        $ra
/* DF8530 80241B30 27BD0070 */   addiu    $sp, $sp, 0x70
