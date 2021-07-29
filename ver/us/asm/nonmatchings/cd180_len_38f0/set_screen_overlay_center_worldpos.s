.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel set_screen_overlay_center_worldpos
/* CE5C0 80137EC0 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* CE5C4 80137EC4 AFB1003C */  sw        $s1, 0x3c($sp)
/* CE5C8 80137EC8 0080882D */  daddu     $s1, $a0, $zero
/* CE5CC 80137ECC AFB20040 */  sw        $s2, 0x40($sp)
/* CE5D0 80137ED0 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* CE5D4 80137ED4 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* CE5D8 80137ED8 3C04800B */  lui       $a0, %hi(gCameras)
/* CE5DC 80137EDC 24841D80 */  addiu     $a0, $a0, %lo(gCameras)
/* CE5E0 80137EE0 AFBF0044 */  sw        $ra, 0x44($sp)
/* CE5E4 80137EE4 AFB00038 */  sw        $s0, 0x38($sp)
/* CE5E8 80137EE8 F7B40048 */  sdc1      $f20, 0x48($sp)
/* CE5EC 80137EEC 00031080 */  sll       $v0, $v1, 2
/* CE5F0 80137EF0 00431021 */  addu      $v0, $v0, $v1
/* CE5F4 80137EF4 00021080 */  sll       $v0, $v0, 2
/* CE5F8 80137EF8 00431023 */  subu      $v0, $v0, $v1
/* CE5FC 80137EFC 000218C0 */  sll       $v1, $v0, 3
/* CE600 80137F00 00431021 */  addu      $v0, $v0, $v1
/* CE604 80137F04 000210C0 */  sll       $v0, $v0, 3
/* CE608 80137F08 00448021 */  addu      $s0, $v0, $a0
/* CE60C 80137F0C 2A220002 */  slti      $v0, $s1, 2
/* CE610 80137F10 10400069 */  beqz      $v0, .L801380B8
/* CE614 80137F14 00A0902D */   daddu    $s2, $a1, $zero
/* CE618 80137F18 06200067 */  bltz      $s1, .L801380B8
/* CE61C 80137F1C 27A20028 */   addiu    $v0, $sp, 0x28
/* CE620 80137F20 AFA20014 */  sw        $v0, 0x14($sp)
/* CE624 80137F24 27A2002C */  addiu     $v0, $sp, 0x2c
/* CE628 80137F28 AFA20018 */  sw        $v0, 0x18($sp)
/* CE62C 80137F2C 27A20030 */  addiu     $v0, $sp, 0x30
/* CE630 80137F30 AFA2001C */  sw        $v0, 0x1c($sp)
/* CE634 80137F34 27A20034 */  addiu     $v0, $sp, 0x34
/* CE638 80137F38 44866000 */  mtc1      $a2, $f12
/* CE63C 80137F3C 00000000 */  nop
/* CE640 80137F40 46806320 */  cvt.s.w   $f12, $f12
/* CE644 80137F44 44056000 */  mfc1      $a1, $f12
/* CE648 80137F48 44876000 */  mtc1      $a3, $f12
/* CE64C 80137F4C 00000000 */  nop
/* CE650 80137F50 46806320 */  cvt.s.w   $f12, $f12
/* CE654 80137F54 44066000 */  mfc1      $a2, $f12
/* CE658 80137F58 C7AC0060 */  lwc1      $f12, 0x60($sp)
/* CE65C 80137F5C 46806320 */  cvt.s.w   $f12, $f12
/* CE660 80137F60 3C013F80 */  lui       $at, 0x3f80
/* CE664 80137F64 4481A000 */  mtc1      $at, $f20
/* CE668 80137F68 44076000 */  mfc1      $a3, $f12
/* CE66C 80137F6C 260400D4 */  addiu     $a0, $s0, 0xd4
/* CE670 80137F70 AFA20020 */  sw        $v0, 0x20($sp)
/* CE674 80137F74 0C00A588 */  jal       transform_point
/* CE678 80137F78 E7B40010 */   swc1     $f20, 0x10($sp)
/* CE67C 80137F7C C7A00034 */  lwc1      $f0, 0x34($sp)
/* CE680 80137F80 C7AA0028 */  lwc1      $f10, 0x28($sp)
/* CE684 80137F84 4600A503 */  div.s     $f20, $f20, $f0
/* CE688 80137F88 46145282 */  mul.s     $f10, $f10, $f20
/* CE68C 80137F8C 00000000 */  nop
/* CE690 80137F90 8602000A */  lh        $v0, 0xa($s0)
/* CE694 80137F94 44820000 */  mtc1      $v0, $f0
/* CE698 80137F98 00000000 */  nop
/* CE69C 80137F9C 46800020 */  cvt.s.w   $f0, $f0
/* CE6A0 80137FA0 46005102 */  mul.s     $f4, $f10, $f0
/* CE6A4 80137FA4 00000000 */  nop
/* CE6A8 80137FA8 46002100 */  add.s     $f4, $f4, $f0
/* CE6AC 80137FAC 3C013FE0 */  lui       $at, 0x3fe0
/* CE6B0 80137FB0 44813800 */  mtc1      $at, $f7
/* CE6B4 80137FB4 44803000 */  mtc1      $zero, $f6
/* CE6B8 80137FB8 46002121 */  cvt.d.s   $f4, $f4
/* CE6BC 80137FBC 46262102 */  mul.d     $f4, $f4, $f6
/* CE6C0 80137FC0 00000000 */  nop
/* CE6C4 80137FC4 C7A8002C */  lwc1      $f8, 0x2c($sp)
/* CE6C8 80137FC8 4600A007 */  neg.s     $f0, $f20
/* CE6CC 80137FCC 46004202 */  mul.s     $f8, $f8, $f0
/* CE6D0 80137FD0 00000000 */  nop
/* CE6D4 80137FD4 8602000C */  lh        $v0, 0xc($s0)
/* CE6D8 80137FD8 44820000 */  mtc1      $v0, $f0
/* CE6DC 80137FDC 00000000 */  nop
/* CE6E0 80137FE0 46800020 */  cvt.s.w   $f0, $f0
/* CE6E4 80137FE4 46004082 */  mul.s     $f2, $f8, $f0
/* CE6E8 80137FE8 00000000 */  nop
/* CE6EC 80137FEC 46001080 */  add.s     $f2, $f2, $f0
/* CE6F0 80137FF0 460010A1 */  cvt.d.s   $f2, $f2
/* CE6F4 80137FF4 46261082 */  mul.d     $f2, $f2, $f6
/* CE6F8 80137FF8 00000000 */  nop
/* CE6FC 80137FFC E7B40034 */  swc1      $f20, 0x34($sp)
/* CE700 80138000 C7A60030 */  lwc1      $f6, 0x30($sp)
/* CE704 80138004 8602000E */  lh        $v0, 0xe($s0)
/* CE708 80138008 46143182 */  mul.s     $f6, $f6, $f20
/* CE70C 8013800C 00000000 */  nop
/* CE710 80138010 E7AA0028 */  swc1      $f10, 0x28($sp)
/* CE714 80138014 E7A8002C */  swc1      $f8, 0x2c($sp)
/* CE718 80138018 44820000 */  mtc1      $v0, $f0
/* CE71C 8013801C 00000000 */  nop
/* CE720 80138020 46800021 */  cvt.d.w   $f0, $f0
/* CE724 80138024 86020010 */  lh        $v0, 0x10($s0)
/* CE728 80138028 46202100 */  add.d     $f4, $f4, $f0
/* CE72C 8013802C 44820000 */  mtc1      $v0, $f0
/* CE730 80138030 00000000 */  nop
/* CE734 80138034 46800021 */  cvt.d.w   $f0, $f0
/* CE738 80138038 46202120 */  cvt.s.d   $f4, $f4
/* CE73C 8013803C 46201080 */  add.d     $f2, $f2, $f0
/* CE740 80138040 E7A40028 */  swc1      $f4, 0x28($sp)
/* CE744 80138044 E7A60030 */  swc1      $f6, 0x30($sp)
/* CE748 80138048 462010A0 */  cvt.s.d   $f2, $f2
/* CE74C 8013804C 12400006 */  beqz      $s2, .L80138068
/* CE750 80138050 E7A2002C */   swc1     $f2, 0x2c($sp)
/* CE754 80138054 24020001 */  addiu     $v0, $zero, 1
/* CE758 80138058 1242000E */  beq       $s2, $v0, .L80138094
/* CE75C 8013805C 00111040 */   sll      $v0, $s1, 1
/* CE760 80138060 0804E02E */  j         .L801380B8
/* CE764 80138064 00000000 */   nop
.L80138068:
/* CE768 80138068 3C038016 */  lui       $v1, %hi(D_8015C790)
/* CE76C 8013806C 2463C790 */  addiu     $v1, $v1, %lo(D_8015C790)
/* CE770 80138070 00111040 */  sll       $v0, $s1, 1
/* CE774 80138074 00511021 */  addu      $v0, $v0, $s1
/* CE778 80138078 000210C0 */  sll       $v0, $v0, 3
/* CE77C 8013807C 00431021 */  addu      $v0, $v0, $v1
/* CE780 80138080 4600230D */  trunc.w.s $f12, $f4
/* CE784 80138084 E44C0004 */  swc1      $f12, 4($v0)
/* CE788 80138088 4600130D */  trunc.w.s $f12, $f2
/* CE78C 8013808C 0804E02E */  j         .L801380B8
/* CE790 80138090 E44C0008 */   swc1     $f12, 8($v0)
.L80138094:
/* CE794 80138094 3C038016 */  lui       $v1, %hi(D_8015C790)
/* CE798 80138098 2463C790 */  addiu     $v1, $v1, %lo(D_8015C790)
/* CE79C 8013809C 00511021 */  addu      $v0, $v0, $s1
/* CE7A0 801380A0 000210C0 */  sll       $v0, $v0, 3
/* CE7A4 801380A4 00431021 */  addu      $v0, $v0, $v1
/* CE7A8 801380A8 4600230D */  trunc.w.s $f12, $f4
/* CE7AC 801380AC E44C000C */  swc1      $f12, 0xc($v0)
/* CE7B0 801380B0 4600130D */  trunc.w.s $f12, $f2
/* CE7B4 801380B4 E44C0010 */  swc1      $f12, 0x10($v0)
.L801380B8:
/* CE7B8 801380B8 8FBF0044 */  lw        $ra, 0x44($sp)
/* CE7BC 801380BC 8FB20040 */  lw        $s2, 0x40($sp)
/* CE7C0 801380C0 8FB1003C */  lw        $s1, 0x3c($sp)
/* CE7C4 801380C4 8FB00038 */  lw        $s0, 0x38($sp)
/* CE7C8 801380C8 D7B40048 */  ldc1      $f20, 0x48($sp)
/* CE7CC 801380CC 03E00008 */  jr        $ra
/* CE7D0 801380D0 27BD0050 */   addiu    $sp, $sp, 0x50
