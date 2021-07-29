.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel mdl_project_tex_coords
/* B2A2C 8011C32C 27BDFF68 */  addiu     $sp, $sp, -0x98
/* B2A30 8011C330 AFB40058 */  sw        $s4, 0x58($sp)
/* B2A34 8011C334 00A0A02D */  daddu     $s4, $a1, $zero
/* B2A38 8011C338 AFB00048 */  sw        $s0, 0x48($sp)
/* B2A3C 8011C33C 00C0802D */  daddu     $s0, $a2, $zero
/* B2A40 8011C340 AFB5005C */  sw        $s5, 0x5c($sp)
/* B2A44 8011C344 00E0A82D */  daddu     $s5, $a3, $zero
/* B2A48 8011C348 AFBF0060 */  sw        $ra, 0x60($sp)
/* B2A4C 8011C34C AFB30054 */  sw        $s3, 0x54($sp)
/* B2A50 8011C350 AFB20050 */  sw        $s2, 0x50($sp)
/* B2A54 8011C354 AFB1004C */  sw        $s1, 0x4c($sp)
/* B2A58 8011C358 F7BE0090 */  sdc1      $f30, 0x90($sp)
/* B2A5C 8011C35C F7BC0088 */  sdc1      $f28, 0x88($sp)
/* B2A60 8011C360 F7BA0080 */  sdc1      $f26, 0x80($sp)
/* B2A64 8011C364 F7B80078 */  sdc1      $f24, 0x78($sp)
/* B2A68 8011C368 F7B60070 */  sdc1      $f22, 0x70($sp)
/* B2A6C 8011C36C F7B40068 */  sdc1      $f20, 0x68($sp)
/* B2A70 8011C370 0C046C04 */  jal       get_model_list_index_from_tree_index
/* B2A74 8011C374 3084FFFF */   andi     $a0, $a0, 0xffff
/* B2A78 8011C378 0C046B4C */  jal       get_model_from_list_index
/* B2A7C 8011C37C 0040202D */   daddu    $a0, $v0, $zero
/* B2A80 8011C380 8C420008 */  lw        $v0, 8($v0)
/* B2A84 8011C384 240600DF */  addiu     $a2, $zero, 0xdf
/* B2A88 8011C388 8C420004 */  lw        $v0, 4($v0)
/* B2A8C 8011C38C 24050001 */  addiu     $a1, $zero, 1
/* B2A90 8011C390 8C420000 */  lw        $v0, ($v0)
.L8011C394:
/* B2A94 8011C394 90430000 */  lbu       $v1, ($v0)
/* B2A98 8011C398 10660004 */  beq       $v1, $a2, .L8011C3AC
/* B2A9C 8011C39C 8C440004 */   lw       $a0, 4($v0)
/* B2AA0 8011C3A0 1465FFFC */  bne       $v1, $a1, .L8011C394
/* B2AA4 8011C3A4 24420008 */   addiu    $v0, $v0, 8
/* B2AA8 8011C3A8 AFA4001C */  sw        $a0, 0x1c($sp)
.L8011C3AC:
/* B2AAC 8011C3AC 8FA2001C */  lw        $v0, 0x1c($sp)
/* B2AB0 8011C3B0 84430000 */  lh        $v1, ($v0)
/* B2AB4 8011C3B4 84440010 */  lh        $a0, 0x10($v0)
/* B2AB8 8011C3B8 44838000 */  mtc1      $v1, $f16
/* B2ABC 8011C3BC 00000000 */  nop
/* B2AC0 8011C3C0 46808420 */  cvt.s.w   $f16, $f16
/* B2AC4 8011C3C4 44842000 */  mtc1      $a0, $f4
/* B2AC8 8011C3C8 00000000 */  nop
/* B2ACC 8011C3CC 46802120 */  cvt.s.w   $f4, $f4
/* B2AD0 8011C3D0 46048032 */  c.eq.s    $f16, $f4
/* B2AD4 8011C3D4 84430004 */  lh        $v1, 4($v0)
/* B2AD8 8011C3D8 84440008 */  lh        $a0, 8($v0)
/* B2ADC 8011C3DC 44839000 */  mtc1      $v1, $f18
/* B2AE0 8011C3E0 00000000 */  nop
/* B2AE4 8011C3E4 468094A0 */  cvt.s.w   $f18, $f18
/* B2AE8 8011C3E8 4484A000 */  mtc1      $a0, $f20
/* B2AEC 8011C3EC 00000000 */  nop
/* B2AF0 8011C3F0 4680A520 */  cvt.s.w   $f20, $f20
/* B2AF4 8011C3F4 8443000A */  lh        $v1, 0xa($v0)
/* B2AF8 8011C3F8 84440014 */  lh        $a0, 0x14($v0)
/* B2AFC 8011C3FC 4483B000 */  mtc1      $v1, $f22
/* B2B00 8011C400 00000000 */  nop
/* B2B04 8011C404 4680B5A0 */  cvt.s.w   $f22, $f22
/* B2B08 8011C408 44845000 */  mtc1      $a0, $f10
/* B2B0C 8011C40C 00000000 */  nop
/* B2B10 8011C410 468052A0 */  cvt.s.w   $f10, $f10
/* B2B14 8011C414 E7B60038 */  swc1      $f22, 0x38($sp)
/* B2B18 8011C418 84430018 */  lh        $v1, 0x18($v0)
/* B2B1C 8011C41C 8444001A */  lh        $a0, 0x1a($v0)
/* B2B20 8011C420 44830000 */  mtc1      $v1, $f0
/* B2B24 8011C424 00000000 */  nop
/* B2B28 8011C428 46800020 */  cvt.s.w   $f0, $f0
/* B2B2C 8011C42C 4484E000 */  mtc1      $a0, $f28
/* B2B30 8011C430 00000000 */  nop
/* B2B34 8011C434 4680E720 */  cvt.s.w   $f28, $f28
/* B2B38 8011C438 E7BC0024 */  swc1      $f28, 0x24($sp)
/* B2B3C 8011C43C 84430020 */  lh        $v1, 0x20($v0)
/* B2B40 8011C440 84440024 */  lh        $a0, 0x24($v0)
/* B2B44 8011C444 4483C000 */  mtc1      $v1, $f24
/* B2B48 8011C448 00000000 */  nop
/* B2B4C 8011C44C 4680C620 */  cvt.s.w   $f24, $f24
/* B2B50 8011C450 44843000 */  mtc1      $a0, $f6
/* B2B54 8011C454 00000000 */  nop
/* B2B58 8011C458 468031A0 */  cvt.s.w   $f6, $f6
/* B2B5C 8011C45C 84430028 */  lh        $v1, 0x28($v0)
/* B2B60 8011C460 8444002A */  lh        $a0, 0x2a($v0)
/* B2B64 8011C464 4483D000 */  mtc1      $v1, $f26
/* B2B68 8011C468 00000000 */  nop
/* B2B6C 8011C46C 4680D6A0 */  cvt.s.w   $f26, $f26
/* B2B70 8011C470 4484B000 */  mtc1      $a0, $f22
/* B2B74 8011C474 00000000 */  nop
/* B2B78 8011C478 4680B5A0 */  cvt.s.w   $f22, $f22
/* B2B7C 8011C47C E7B60028 */  swc1      $f22, 0x28($sp)
/* B2B80 8011C480 9053000C */  lbu       $s3, 0xc($v0)
/* B2B84 8011C484 9052000D */  lbu       $s2, 0xd($v0)
/* B2B88 8011C488 9051000E */  lbu       $s1, 0xe($v0)
/* B2B8C 8011C48C 4503002E */  bc1tl     .L8011C548
/* B2B90 8011C490 46069081 */   sub.s    $f2, $f18, $f6
/* B2B94 8011C494 46188081 */  sub.s     $f2, $f16, $f24
/* B2B98 8011C498 46048381 */  sub.s     $f14, $f16, $f4
/* B2B9C 8011C49C 4600A201 */  sub.s     $f8, $f20, $f0
/* B2BA0 8011C4A0 460E1083 */  div.s     $f2, $f2, $f14
/* B2BA4 8011C4A4 46081002 */  mul.s     $f0, $f2, $f8
/* B2BA8 8011C4A8 00000000 */  nop
/* B2BAC 8011C4AC 460A9301 */  sub.s     $f12, $f18, $f10
/* B2BB0 8011C4B0 460C1282 */  mul.s     $f10, $f2, $f12
/* B2BB4 8011C4B4 00000000 */  nop
/* B2BB8 8011C4B8 461AA101 */  sub.s     $f4, $f20, $f26
/* B2BBC 8011C4BC 46069181 */  sub.s     $f6, $f18, $f6
/* B2BC0 8011C4C0 46040001 */  sub.s     $f0, $f0, $f4
/* B2BC4 8011C4C4 46065281 */  sub.s     $f10, $f10, $f6
/* B2BC8 8011C4C8 460A0003 */  div.s     $f0, $f0, $f10
/* B2BCC 8011C4CC E7A00040 */  swc1      $f0, 0x40($sp)
/* B2BD0 8011C4D0 46006002 */  mul.s     $f0, $f12, $f0
/* B2BD4 8011C4D4 00000000 */  nop
/* B2BD8 8011C4D8 C7B60038 */  lwc1      $f22, 0x38($sp)
/* B2BDC 8011C4DC 461CB101 */  sub.s     $f4, $f22, $f28
/* B2BE0 8011C4E0 46041082 */  mul.s     $f2, $f2, $f4
/* B2BE4 8011C4E4 00000000 */  nop
/* B2BE8 8011C4E8 46004201 */  sub.s     $f8, $f8, $f0
/* B2BEC 8011C4EC 460E4783 */  div.s     $f30, $f8, $f14
/* B2BF0 8011C4F0 4610F182 */  mul.s     $f6, $f30, $f16
/* B2BF4 8011C4F4 00000000 */  nop
/* B2BF8 8011C4F8 C7BC0028 */  lwc1      $f28, 0x28($sp)
/* B2BFC 8011C4FC 461CB001 */  sub.s     $f0, $f22, $f28
/* B2C00 8011C500 C7B60040 */  lwc1      $f22, 0x40($sp)
/* B2C04 8011C504 4612B202 */  mul.s     $f8, $f22, $f18
/* B2C08 8011C508 00000000 */  nop
/* B2C0C 8011C50C 46001081 */  sub.s     $f2, $f2, $f0
/* B2C10 8011C510 460A1683 */  div.s     $f26, $f2, $f10
/* B2C14 8011C514 461A6302 */  mul.s     $f12, $f12, $f26
/* B2C18 8011C518 00000000 */  nop
/* B2C1C 8011C51C 4612D082 */  mul.s     $f2, $f26, $f18
/* B2C20 8011C520 00000000 */  nop
/* B2C24 8011C524 460C2101 */  sub.s     $f4, $f4, $f12
/* B2C28 8011C528 460E2603 */  div.s     $f24, $f4, $f14
/* B2C2C 8011C52C 4610C002 */  mul.s     $f0, $f24, $f16
/* B2C30 8011C530 00000000 */  nop
/* B2C34 8011C534 4606A181 */  sub.s     $f6, $f20, $f6
/* B2C38 8011C538 46083181 */  sub.s     $f6, $f6, $f8
/* B2C3C 8011C53C C7BC0038 */  lwc1      $f28, 0x38($sp)
/* B2C40 8011C540 0804717C */  j         .L8011C5F0
/* B2C44 8011C544 4600E001 */   sub.s    $f0, $f28, $f0
.L8011C548:
/* B2C48 8011C548 460A9381 */  sub.s     $f14, $f18, $f10
/* B2C4C 8011C54C 4600A201 */  sub.s     $f8, $f20, $f0
/* B2C50 8011C550 460E1083 */  div.s     $f2, $f2, $f14
/* B2C54 8011C554 46081002 */  mul.s     $f0, $f2, $f8
/* B2C58 8011C558 00000000 */  nop
/* B2C5C 8011C55C 46048301 */  sub.s     $f12, $f16, $f4
/* B2C60 8011C560 460C1282 */  mul.s     $f10, $f2, $f12
/* B2C64 8011C564 00000000 */  nop
/* B2C68 8011C568 461AA101 */  sub.s     $f4, $f20, $f26
/* B2C6C 8011C56C 46188181 */  sub.s     $f6, $f16, $f24
/* B2C70 8011C570 46040001 */  sub.s     $f0, $f0, $f4
/* B2C74 8011C574 46065281 */  sub.s     $f10, $f10, $f6
/* B2C78 8011C578 460A0783 */  div.s     $f30, $f0, $f10
/* B2C7C 8011C57C 461E6002 */  mul.s     $f0, $f12, $f30
/* B2C80 8011C580 00000000 */  nop
/* B2C84 8011C584 4610F182 */  mul.s     $f6, $f30, $f16
/* B2C88 8011C588 00000000 */  nop
/* B2C8C 8011C58C C7B60038 */  lwc1      $f22, 0x38($sp)
/* B2C90 8011C590 C7BC0024 */  lwc1      $f28, 0x24($sp)
/* B2C94 8011C594 461CB101 */  sub.s     $f4, $f22, $f28
/* B2C98 8011C598 46041082 */  mul.s     $f2, $f2, $f4
/* B2C9C 8011C59C 00000000 */  nop
/* B2CA0 8011C5A0 46004201 */  sub.s     $f8, $f8, $f0
/* B2CA4 8011C5A4 460E4203 */  div.s     $f8, $f8, $f14
/* B2CA8 8011C5A8 E7A80040 */  swc1      $f8, 0x40($sp)
/* B2CAC 8011C5AC 46124202 */  mul.s     $f8, $f8, $f18
/* B2CB0 8011C5B0 00000000 */  nop
/* B2CB4 8011C5B4 C7BC0028 */  lwc1      $f28, 0x28($sp)
/* B2CB8 8011C5B8 461CB001 */  sub.s     $f0, $f22, $f28
/* B2CBC 8011C5BC 46001081 */  sub.s     $f2, $f2, $f0
/* B2CC0 8011C5C0 460A1603 */  div.s     $f24, $f2, $f10
/* B2CC4 8011C5C4 46186302 */  mul.s     $f12, $f12, $f24
/* B2CC8 8011C5C8 00000000 */  nop
/* B2CCC 8011C5CC 4610C002 */  mul.s     $f0, $f24, $f16
/* B2CD0 8011C5D0 00000000 */  nop
/* B2CD4 8011C5D4 460C2101 */  sub.s     $f4, $f4, $f12
/* B2CD8 8011C5D8 460E2683 */  div.s     $f26, $f4, $f14
/* B2CDC 8011C5DC 4612D082 */  mul.s     $f2, $f26, $f18
/* B2CE0 8011C5E0 00000000 */  nop
/* B2CE4 8011C5E4 4606A181 */  sub.s     $f6, $f20, $f6
/* B2CE8 8011C5E8 46083181 */  sub.s     $f6, $f6, $f8
/* B2CEC 8011C5EC 4600B001 */  sub.s     $f0, $f22, $f0
.L8011C5F0:
/* B2CF0 8011C5F0 E7A6002C */  swc1      $f6, 0x2c($sp)
/* B2CF4 8011C5F4 46020501 */  sub.s     $f20, $f0, $f2
/* B2CF8 8011C5F8 0280202D */  daddu     $a0, $s4, $zero
/* B2CFC 8011C5FC 27A50018 */  addiu     $a1, $sp, 0x18
/* B2D00 8011C600 27A6001C */  addiu     $a2, $sp, 0x1c
/* B2D04 8011C604 27A70020 */  addiu     $a3, $sp, 0x20
/* B2D08 8011C608 0C04700A */  jal       mdl_get_vertex_count
/* B2D0C 8011C60C AFB50010 */   sw       $s5, 0x10($sp)
/* B2D10 8011C610 8FA20018 */  lw        $v0, 0x18($sp)
/* B2D14 8011C614 1840006E */  blez      $v0, .L8011C7D0
/* B2D18 8011C618 0000282D */   daddu    $a1, $zero, $zero
/* B2D1C 8011C61C 44809000 */  mtc1      $zero, $f18
/* B2D20 8011C620 3C013FE0 */  lui       $at, 0x3fe0
/* B2D24 8011C624 44818800 */  mtc1      $at, $f17
/* B2D28 8011C628 44808000 */  mtc1      $zero, $f16
.L8011C62C:
/* B2D2C 8011C62C 8FA3001C */  lw        $v1, 0x1c($sp)
/* B2D30 8011C630 84620000 */  lh        $v0, ($v1)
/* B2D34 8011C634 44823000 */  mtc1      $v0, $f6
/* B2D38 8011C638 00000000 */  nop
/* B2D3C 8011C63C 468031A0 */  cvt.s.w   $f6, $f6
/* B2D40 8011C640 84620002 */  lh        $v0, 2($v1)
/* B2D44 8011C644 84630004 */  lh        $v1, 4($v1)
/* B2D48 8011C648 44827000 */  mtc1      $v0, $f14
/* B2D4C 8011C64C 00000000 */  nop
/* B2D50 8011C650 468073A0 */  cvt.s.w   $f14, $f14
/* B2D54 8011C654 44836000 */  mtc1      $v1, $f12
/* B2D58 8011C658 00000000 */  nop
/* B2D5C 8011C65C 46806320 */  cvt.s.w   $f12, $f12
/* B2D60 8011C660 1200001C */  beqz      $s0, .L8011C6D4
/* B2D64 8011C664 46003286 */   mov.s    $f10, $f6
/* B2D68 8011C668 C6040000 */  lwc1      $f4, ($s0)
/* B2D6C 8011C66C 46062102 */  mul.s     $f4, $f4, $f6
/* B2D70 8011C670 00000000 */  nop
/* B2D74 8011C674 C60A0010 */  lwc1      $f10, 0x10($s0)
/* B2D78 8011C678 460E5282 */  mul.s     $f10, $f10, $f14
/* B2D7C 8011C67C 00000000 */  nop
/* B2D80 8011C680 C6000020 */  lwc1      $f0, 0x20($s0)
/* B2D84 8011C684 460C0002 */  mul.s     $f0, $f0, $f12
/* B2D88 8011C688 00000000 */  nop
/* B2D8C 8011C68C C6020008 */  lwc1      $f2, 8($s0)
/* B2D90 8011C690 46061082 */  mul.s     $f2, $f2, $f6
/* B2D94 8011C694 00000000 */  nop
/* B2D98 8011C698 C6080018 */  lwc1      $f8, 0x18($s0)
/* B2D9C 8011C69C 460E4202 */  mul.s     $f8, $f8, $f14
/* B2DA0 8011C6A0 00000000 */  nop
/* B2DA4 8011C6A4 C6060028 */  lwc1      $f6, 0x28($s0)
/* B2DA8 8011C6A8 460C3182 */  mul.s     $f6, $f6, $f12
/* B2DAC 8011C6AC 00000000 */  nop
/* B2DB0 8011C6B0 460A2100 */  add.s     $f4, $f4, $f10
/* B2DB4 8011C6B4 46081080 */  add.s     $f2, $f2, $f8
/* B2DB8 8011C6B8 46002100 */  add.s     $f4, $f4, $f0
/* B2DBC 8011C6BC 46061080 */  add.s     $f2, $f2, $f6
/* B2DC0 8011C6C0 C6000030 */  lwc1      $f0, 0x30($s0)
/* B2DC4 8011C6C4 46002280 */  add.s     $f10, $f4, $f0
/* B2DC8 8011C6C8 C6000038 */  lwc1      $f0, 0x38($s0)
/* B2DCC 8011C6CC 080471B6 */  j         .L8011C6D8
/* B2DD0 8011C6D0 46001180 */   add.s    $f6, $f2, $f0
.L8011C6D4:
/* B2DD4 8011C6D4 46006186 */  mov.s     $f6, $f12
.L8011C6D8:
/* B2DD8 8011C6D8 460AF002 */  mul.s     $f0, $f30, $f10
/* B2DDC 8011C6DC 00000000 */  nop
/* B2DE0 8011C6E0 460AC082 */  mul.s     $f2, $f24, $f10
/* B2DE4 8011C6E4 00000000 */  nop
/* B2DE8 8011C6E8 C7B60040 */  lwc1      $f22, 0x40($sp)
/* B2DEC 8011C6EC 4606B102 */  mul.s     $f4, $f22, $f6
/* B2DF0 8011C6F0 00000000 */  nop
/* B2DF4 8011C6F4 4606D182 */  mul.s     $f6, $f26, $f6
/* B2DF8 8011C6F8 00000000 */  nop
/* B2DFC 8011C6FC 46040000 */  add.s     $f0, $f0, $f4
/* B2E00 8011C700 46061080 */  add.s     $f2, $f2, $f6
/* B2E04 8011C704 C7BC002C */  lwc1      $f28, 0x2c($sp)
/* B2E08 8011C708 461C0100 */  add.s     $f4, $f0, $f28
/* B2E0C 8011C70C 4612203C */  c.lt.s    $f4, $f18
/* B2E10 8011C710 00000000 */  nop
/* B2E14 8011C714 45000004 */  bc1f      .L8011C728
/* B2E18 8011C718 46141080 */   add.s    $f2, $f2, $f20
/* B2E1C 8011C71C 46002021 */  cvt.d.s   $f0, $f4
/* B2E20 8011C720 080471D0 */  j         .L8011C740
/* B2E24 8011C724 46300001 */   sub.d    $f0, $f0, $f16
.L8011C728:
/* B2E28 8011C728 4604903C */  c.lt.s    $f18, $f4
/* B2E2C 8011C72C 00000000 */  nop
/* B2E30 8011C730 45000004 */  bc1f      .L8011C744
/* B2E34 8011C734 00000000 */   nop
/* B2E38 8011C738 46002021 */  cvt.d.s   $f0, $f4
/* B2E3C 8011C73C 46300000 */  add.d     $f0, $f0, $f16
.L8011C740:
/* B2E40 8011C740 46200120 */  cvt.s.d   $f4, $f0
.L8011C744:
/* B2E44 8011C744 4612103C */  c.lt.s    $f2, $f18
/* B2E48 8011C748 00000000 */  nop
/* B2E4C 8011C74C 45000004 */  bc1f      .L8011C760
/* B2E50 8011C750 00000000 */   nop
/* B2E54 8011C754 46001021 */  cvt.d.s   $f0, $f2
/* B2E58 8011C758 080471DE */  j         .L8011C778
/* B2E5C 8011C75C 46300001 */   sub.d    $f0, $f0, $f16
.L8011C760:
/* B2E60 8011C760 4602903C */  c.lt.s    $f18, $f2
/* B2E64 8011C764 00000000 */  nop
/* B2E68 8011C768 45000004 */  bc1f      .L8011C77C
/* B2E6C 8011C76C 00000000 */   nop
/* B2E70 8011C770 46001021 */  cvt.d.s   $f0, $f2
/* B2E74 8011C774 46300000 */  add.d     $f0, $f0, $f16
.L8011C778:
/* B2E78 8011C778 462000A0 */  cvt.s.d   $f2, $f0
.L8011C77C:
/* B2E7C 8011C77C 8FA3001C */  lw        $v1, 0x1c($sp)
/* B2E80 8011C780 4600258D */  trunc.w.s $f22, $f4
/* B2E84 8011C784 4402B000 */  mfc1      $v0, $f22
/* B2E88 8011C788 00000000 */  nop
/* B2E8C 8011C78C A4620008 */  sh        $v0, 8($v1)
/* B2E90 8011C790 A073000C */  sb        $s3, 0xc($v1)
/* B2E94 8011C794 8FA4001C */  lw        $a0, 0x1c($sp)
/* B2E98 8011C798 4600158D */  trunc.w.s $f22, $f2
/* B2E9C 8011C79C 4402B000 */  mfc1      $v0, $f22
/* B2EA0 8011C7A0 00000000 */  nop
/* B2EA4 8011C7A4 A462000A */  sh        $v0, 0xa($v1)
/* B2EA8 8011C7A8 A092000D */  sb        $s2, 0xd($a0)
/* B2EAC 8011C7AC 8FA2001C */  lw        $v0, 0x1c($sp)
/* B2EB0 8011C7B0 24A50001 */  addiu     $a1, $a1, 1
/* B2EB4 8011C7B4 A051000E */  sb        $s1, 0xe($v0)
/* B2EB8 8011C7B8 8FA2001C */  lw        $v0, 0x1c($sp)
/* B2EBC 8011C7BC 8FA30018 */  lw        $v1, 0x18($sp)
/* B2EC0 8011C7C0 24420010 */  addiu     $v0, $v0, 0x10
/* B2EC4 8011C7C4 00A3182A */  slt       $v1, $a1, $v1
/* B2EC8 8011C7C8 1460FF98 */  bnez      $v1, .L8011C62C
/* B2ECC 8011C7CC AFA2001C */   sw       $v0, 0x1c($sp)
.L8011C7D0:
/* B2ED0 8011C7D0 8FBF0060 */  lw        $ra, 0x60($sp)
/* B2ED4 8011C7D4 8FB5005C */  lw        $s5, 0x5c($sp)
/* B2ED8 8011C7D8 8FB40058 */  lw        $s4, 0x58($sp)
/* B2EDC 8011C7DC 8FB30054 */  lw        $s3, 0x54($sp)
/* B2EE0 8011C7E0 8FB20050 */  lw        $s2, 0x50($sp)
/* B2EE4 8011C7E4 8FB1004C */  lw        $s1, 0x4c($sp)
/* B2EE8 8011C7E8 8FB00048 */  lw        $s0, 0x48($sp)
/* B2EEC 8011C7EC D7BE0090 */  ldc1      $f30, 0x90($sp)
/* B2EF0 8011C7F0 D7BC0088 */  ldc1      $f28, 0x88($sp)
/* B2EF4 8011C7F4 D7BA0080 */  ldc1      $f26, 0x80($sp)
/* B2EF8 8011C7F8 D7B80078 */  ldc1      $f24, 0x78($sp)
/* B2EFC 8011C7FC D7B60070 */  ldc1      $f22, 0x70($sp)
/* B2F00 8011C800 D7B40068 */  ldc1      $f20, 0x68($sp)
/* B2F04 8011C804 03E00008 */  jr        $ra
/* B2F08 8011C808 27BD0098 */   addiu    $sp, $sp, 0x98
