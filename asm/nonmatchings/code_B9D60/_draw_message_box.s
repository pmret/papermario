.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel _draw_message_box
/* C3308 8012CC08 27BDFF28 */  addiu     $sp, $sp, -0xd8
/* C330C 8012CC0C AFB600B8 */  sw        $s6, 0xb8($sp)
/* C3310 8012CC10 0080B02D */  daddu     $s6, $a0, $zero
/* C3314 8012CC14 8FA300E8 */  lw        $v1, 0xe8($sp)
/* C3318 8012CC18 8FAB00EC */  lw        $t3, 0xec($sp)
/* C331C 8012CC1C 00A0402D */  daddu     $t0, $a1, $zero
/* C3320 8012CC20 F7B600D0 */  sdc1      $f22, 0xd0($sp)
/* C3324 8012CC24 C7B600F0 */  lwc1      $f22, 0xf0($sp)
/* C3328 8012CC28 00C0482D */  daddu     $t1, $a2, $zero
/* C332C 8012CC2C AFB500B4 */  sw        $s5, 0xb4($sp)
/* C3330 8012CC30 93B500FB */  lbu       $s5, 0xfb($sp)
/* C3334 8012CC34 00E0502D */  daddu     $t2, $a3, $zero
/* C3338 8012CC38 AFB100A4 */  sw        $s1, 0xa4($sp)
/* C333C 8012CC3C 0100882D */  daddu     $s1, $t0, $zero
/* C3340 8012CC40 AFB200A8 */  sw        $s2, 0xa8($sp)
/* C3344 8012CC44 0120902D */  daddu     $s2, $t1, $zero
/* C3348 8012CC48 AFB400B0 */  sw        $s4, 0xb0($sp)
/* C334C 8012CC4C 0140A02D */  daddu     $s4, $t2, $zero
/* C3350 8012CC50 F7B400C8 */  sdc1      $f20, 0xc8($sp)
/* C3354 8012CC54 C7B400F4 */  lwc1      $f20, 0xf4($sp)
/* C3358 8012CC58 240200FF */  addiu     $v0, $zero, 0xff
/* C335C 8012CC5C AFBF00C0 */  sw        $ra, 0xc0($sp)
/* C3360 8012CC60 AFB700BC */  sw        $s7, 0xbc($sp)
/* C3364 8012CC64 AFB300AC */  sw        $s3, 0xac($sp)
/* C3368 8012CC68 AFB000A0 */  sw        $s0, 0xa0($sp)
/* C336C 8012CC6C 0060802D */  daddu     $s0, $v1, $zero
/* C3370 8012CC70 16A20020 */  bne       $s5, $v0, .L8012CCF4
/* C3374 8012CC74 0160982D */   daddu    $s3, $t3, $zero
/* C3378 8012CC78 3C013FF0 */  lui       $at, 0x3ff0
/* C337C 8012CC7C 44811800 */  mtc1      $at, $f3
/* C3380 8012CC80 44801000 */  mtc1      $zero, $f2
/* C3384 8012CC84 4600B021 */  cvt.d.s   $f0, $f22
/* C3388 8012CC88 46220032 */  c.eq.d    $f0, $f2
/* C338C 8012CC8C 00000000 */  nop
/* C3390 8012CC90 45000019 */  bc1f      .L8012CCF8
/* C3394 8012CC94 27A40020 */   addiu    $a0, $sp, 0x20
/* C3398 8012CC98 4600A021 */  cvt.d.s   $f0, $f20
/* C339C 8012CC9C 46220032 */  c.eq.d    $f0, $f2
/* C33A0 8012CCA0 00000000 */  nop
/* C33A4 8012CCA4 45000013 */  bc1f      .L8012CCF4
/* C33A8 8012CCA8 24040020 */   addiu    $a0, $zero, 0x20
/* C33AC 8012CCAC 24050080 */  addiu     $a1, $zero, 0x80
/* C33B0 8012CCB0 240600F0 */  addiu     $a2, $zero, 0xf0
/* C33B4 8012CCB4 0000382D */  daddu     $a3, $zero, $zero
/* C33B8 8012CCB8 2502FFFF */  addiu     $v0, $t0, -1
/* C33BC 8012CCBC 3042FFFF */  andi      $v0, $v0, 0xffff
/* C33C0 8012CCC0 AFA20010 */  sw        $v0, 0x10($sp)
/* C33C4 8012CCC4 25220001 */  addiu     $v0, $t1, 1
/* C33C8 8012CCC8 3042FFFF */  andi      $v0, $v0, 0xffff
/* C33CC 8012CCCC AFA20014 */  sw        $v0, 0x14($sp)
/* C33D0 8012CCD0 01431021 */  addu      $v0, $t2, $v1
/* C33D4 8012CCD4 00621021 */  addu      $v0, $v1, $v0
/* C33D8 8012CCD8 24420002 */  addiu     $v0, $v0, 2
/* C33DC 8012CCDC 3042FFFF */  andi      $v0, $v0, 0xffff
/* C33E0 8012CCE0 AFA20018 */  sw        $v0, 0x18($sp)
/* C33E4 8012CCE4 2562FFFE */  addiu     $v0, $t3, -2
/* C33E8 8012CCE8 3042FFFF */  andi      $v0, $v0, 0xffff
/* C33EC 8012CCEC 0C04B26A */  jal       func_8012C9A8
/* C33F0 8012CCF0 AFA2001C */   sw       $v0, 0x1c($sp)
.L8012CCF4:
/* C33F4 8012CCF4 27A40020 */  addiu     $a0, $sp, 0x20
.L8012CCF8:
/* C33F8 8012CCF8 00111400 */  sll       $v0, $s1, 0x10
/* C33FC 8012CCFC 00021403 */  sra       $v0, $v0, 0x10
/* C3400 8012CD00 44822000 */  mtc1      $v0, $f4
/* C3404 8012CD04 00000000 */  nop
/* C3408 8012CD08 46802120 */  cvt.s.w   $f4, $f4
/* C340C 8012CD0C 00121400 */  sll       $v0, $s2, 0x10
/* C3410 8012CD10 00021403 */  sra       $v0, $v0, 0x10
/* C3414 8012CD14 00021023 */  negu      $v0, $v0
/* C3418 8012CD18 44052000 */  mfc1      $a1, $f4
/* C341C 8012CD1C 44822000 */  mtc1      $v0, $f4
/* C3420 8012CD20 00000000 */  nop
/* C3424 8012CD24 46802120 */  cvt.s.w   $f4, $f4
/* C3428 8012CD28 0000382D */  daddu     $a3, $zero, $zero
/* C342C 8012CD2C 3C038015 */  lui       $v1, %hi(D_8014C3C0)
/* C3430 8012CD30 2463C3C0 */  addiu     $v1, $v1, %lo(D_8014C3C0)
/* C3434 8012CD34 24020001 */  addiu     $v0, $zero, 1
/* C3438 8012CD38 00134400 */  sll       $t0, $s3, 0x10
/* C343C 8012CD3C 00084403 */  sra       $t0, $t0, 0x10
/* C3440 8012CD40 00084023 */  negu      $t0, $t0
/* C3444 8012CD44 A4620000 */  sh        $v0, ($v1)
/* C3448 8012CD48 A4620020 */  sh        $v0, 0x20($v1)
/* C344C 8012CD4C A4700010 */  sh        $s0, 0x10($v1)
/* C3450 8012CD50 A4700030 */  sh        $s0, 0x30($v1)
/* C3454 8012CD54 A4680022 */  sh        $t0, 0x22($v1)
/* C3458 8012CD58 A4680032 */  sh        $t0, 0x32($v1)
/* C345C 8012CD5C 3C038015 */  lui       $v1, %hi(D_8014C400)
/* C3460 8012CD60 2463C400 */  addiu     $v1, $v1, %lo(D_8014C400)
/* C3464 8012CD64 44062000 */  mfc1      $a2, $f4
/* C3468 8012CD68 02141021 */  addu      $v0, $s0, $s4
/* C346C 8012CD6C A4700000 */  sh        $s0, ($v1)
/* C3470 8012CD70 A4700020 */  sh        $s0, 0x20($v1)
/* C3474 8012CD74 A4620010 */  sh        $v0, 0x10($v1)
/* C3478 8012CD78 A4620030 */  sh        $v0, 0x30($v1)
/* C347C 8012CD7C A4680022 */  sh        $t0, 0x22($v1)
/* C3480 8012CD80 A4680032 */  sh        $t0, 0x32($v1)
/* C3484 8012CD84 3C038015 */  lui       $v1, %hi(D_8014C440)
/* C3488 8012CD88 2463C440 */  addiu     $v1, $v1, %lo(D_8014C440)
/* C348C 8012CD8C A4620000 */  sh        $v0, ($v1)
/* C3490 8012CD90 A4620020 */  sh        $v0, 0x20($v1)
/* C3494 8012CD94 02021021 */  addu      $v0, $s0, $v0
/* C3498 8012CD98 A4620010 */  sh        $v0, 0x10($v1)
/* C349C 8012CD9C A4620030 */  sh        $v0, 0x30($v1)
/* C34A0 8012CDA0 A4680022 */  sh        $t0, 0x22($v1)
/* C34A4 8012CDA4 0C019E40 */  jal       guTranslateF
/* C34A8 8012CDA8 A4680032 */   sh       $t0, 0x32($v1)
/* C34AC 8012CDAC 3C013FF0 */  lui       $at, 0x3ff0
/* C34B0 8012CDB0 44811800 */  mtc1      $at, $f3
/* C34B4 8012CDB4 44801000 */  mtc1      $zero, $f2
/* C34B8 8012CDB8 4600B021 */  cvt.d.s   $f0, $f22
/* C34BC 8012CDBC 46220032 */  c.eq.d    $f0, $f2
/* C34C0 8012CDC0 00000000 */  nop
/* C34C4 8012CDC4 45000007 */  bc1f      .L8012CDE4
/* C34C8 8012CDC8 27B00060 */   addiu    $s0, $sp, 0x60
/* C34CC 8012CDCC 4600A021 */  cvt.d.s   $f0, $f20
/* C34D0 8012CDD0 46220032 */  c.eq.d    $f0, $f2
/* C34D4 8012CDD4 00000000 */  nop
/* C34D8 8012CDD8 4501000C */  bc1t      .L8012CE0C
/* C34DC 8012CDDC 3C120001 */   lui      $s2, 1
/* C34E0 8012CDE0 27B00060 */  addiu     $s0, $sp, 0x60
.L8012CDE4:
/* C34E4 8012CDE4 4405B000 */  mfc1      $a1, $f22
/* C34E8 8012CDE8 4406A000 */  mfc1      $a2, $f20
/* C34EC 8012CDEC 3C073F80 */  lui       $a3, 0x3f80
/* C34F0 8012CDF0 0C019DF0 */  jal       guScaleF
/* C34F4 8012CDF4 0200202D */   daddu    $a0, $s0, $zero
/* C34F8 8012CDF8 0200202D */  daddu     $a0, $s0, $zero
/* C34FC 8012CDFC 27A50020 */  addiu     $a1, $sp, 0x20
/* C3500 8012CE00 0C019D80 */  jal       guMtxCatF
/* C3504 8012CE04 00A0302D */   daddu    $a2, $a1, $zero
/* C3508 8012CE08 3C120001 */  lui       $s2, 1
.L8012CE0C:
/* C350C 8012CE0C 36521630 */  ori       $s2, $s2, 0x1630
/* C3510 8012CE10 27A40020 */  addiu     $a0, $sp, 0x20
/* C3514 8012CE14 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* C3518 8012CE18 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* C351C 8012CE1C 3C11800A */  lui       $s1, %hi(gDisplayContext)
/* C3520 8012CE20 2631A674 */  addiu     $s1, $s1, %lo(gDisplayContext)
/* C3524 8012CE24 96050000 */  lhu       $a1, ($s0)
/* C3528 8012CE28 8E220000 */  lw        $v0, ($s1)
/* C352C 8012CE2C 00052980 */  sll       $a1, $a1, 6
/* C3530 8012CE30 00B22821 */  addu      $a1, $a1, $s2
/* C3534 8012CE34 0C019D40 */  jal       guMtxF2L
/* C3538 8012CE38 00452821 */   addu     $a1, $v0, $a1
/* C353C 8012CE3C 3C03DA38 */  lui       $v1, 0xda38
/* C3540 8012CE40 34630002 */  ori       $v1, $v1, 2
/* C3544 8012CE44 3C05E300 */  lui       $a1, 0xe300
/* C3548 8012CE48 34A50A01 */  ori       $a1, $a1, 0xa01
/* C354C 8012CE4C 3C06D9FD */  lui       $a2, 0xd9fd
/* C3550 8012CE50 34C6F9FF */  ori       $a2, $a2, 0xf9ff
/* C3554 8012CE54 3C08D9FF */  lui       $t0, 0xd9ff
/* C3558 8012CE58 3508FFFF */  ori       $t0, $t0, 0xffff
/* C355C 8012CE5C 3C070020 */  lui       $a3, 0x20
/* C3560 8012CE60 34E70004 */  ori       $a3, $a3, 4
/* C3564 8012CE64 3C09E300 */  lui       $t1, 0xe300
/* C3568 8012CE68 35291801 */  ori       $t1, $t1, 0x1801
/* C356C 8012CE6C 3C0AD700 */  lui       $t2, 0xd700
/* C3570 8012CE70 354A0002 */  ori       $t2, $t2, 2
/* C3574 8012CE74 3C0BE300 */  lui       $t3, 0xe300
/* C3578 8012CE78 3C0D800A */  lui       $t5, %hi(gMasterGfxPos)
/* C357C 8012CE7C 25ADA66C */  addiu     $t5, $t5, %lo(gMasterGfxPos)
/* C3580 8012CE80 356B0C00 */  ori       $t3, $t3, 0xc00
/* C3584 8012CE84 8DAC0000 */  lw        $t4, ($t5)
/* C3588 8012CE88 96020000 */  lhu       $v0, ($s0)
/* C358C 8012CE8C 0180202D */  daddu     $a0, $t4, $zero
/* C3590 8012CE90 258C0008 */  addiu     $t4, $t4, 8
/* C3594 8012CE94 ADAC0000 */  sw        $t4, ($t5)
/* C3598 8012CE98 AC830000 */  sw        $v1, ($a0)
/* C359C 8012CE9C 24430001 */  addiu     $v1, $v0, 1
/* C35A0 8012CEA0 3042FFFF */  andi      $v0, $v0, 0xffff
/* C35A4 8012CEA4 00021180 */  sll       $v0, $v0, 6
/* C35A8 8012CEA8 A6030000 */  sh        $v1, ($s0)
/* C35AC 8012CEAC 8E230000 */  lw        $v1, ($s1)
/* C35B0 8012CEB0 00521021 */  addu      $v0, $v0, $s2
/* C35B4 8012CEB4 00621821 */  addu      $v1, $v1, $v0
/* C35B8 8012CEB8 3C028000 */  lui       $v0, 0x8000
/* C35BC 8012CEBC 00621821 */  addu      $v1, $v1, $v0
/* C35C0 8012CEC0 25820008 */  addiu     $v0, $t4, 8
/* C35C4 8012CEC4 AC830004 */  sw        $v1, 4($a0)
/* C35C8 8012CEC8 ADA20000 */  sw        $v0, ($t5)
/* C35CC 8012CECC 3C02E700 */  lui       $v0, 0xe700
/* C35D0 8012CED0 AD820000 */  sw        $v0, ($t4)
/* C35D4 8012CED4 25820010 */  addiu     $v0, $t4, 0x10
/* C35D8 8012CED8 AD800004 */  sw        $zero, 4($t4)
/* C35DC 8012CEDC ADA20000 */  sw        $v0, ($t5)
/* C35E0 8012CEE0 25820018 */  addiu     $v0, $t4, 0x18
/* C35E4 8012CEE4 AD850008 */  sw        $a1, 8($t4)
/* C35E8 8012CEE8 AD80000C */  sw        $zero, 0xc($t4)
/* C35EC 8012CEEC ADA20000 */  sw        $v0, ($t5)
/* C35F0 8012CEF0 25820020 */  addiu     $v0, $t4, 0x20
/* C35F4 8012CEF4 AD860010 */  sw        $a2, 0x10($t4)
/* C35F8 8012CEF8 AD800014 */  sw        $zero, 0x14($t4)
/* C35FC 8012CEFC ADA20000 */  sw        $v0, ($t5)
/* C3600 8012CF00 25820028 */  addiu     $v0, $t4, 0x28
/* C3604 8012CF04 AD880018 */  sw        $t0, 0x18($t4)
/* C3608 8012CF08 AD87001C */  sw        $a3, 0x1c($t4)
/* C360C 8012CF0C ADA20000 */  sw        $v0, ($t5)
/* C3610 8012CF10 240200C0 */  addiu     $v0, $zero, 0xc0
/* C3614 8012CF14 AD820024 */  sw        $v0, 0x24($t4)
/* C3618 8012CF18 25820030 */  addiu     $v0, $t4, 0x30
/* C361C 8012CF1C AD890020 */  sw        $t1, 0x20($t4)
/* C3620 8012CF20 ADA20000 */  sw        $v0, ($t5)
/* C3624 8012CF24 2402FFFF */  addiu     $v0, $zero, -1
/* C3628 8012CF28 AD82002C */  sw        $v0, 0x2c($t4)
/* C362C 8012CF2C 25820038 */  addiu     $v0, $t4, 0x38
/* C3630 8012CF30 AD8A0028 */  sw        $t2, 0x28($t4)
/* C3634 8012CF34 ADA20000 */  sw        $v0, ($t5)
/* C3638 8012CF38 3C020008 */  lui       $v0, 8
/* C363C 8012CF3C AD8B0030 */  sw        $t3, 0x30($t4)
/* C3640 8012CF40 AD820034 */  sw        $v0, 0x34($t4)
/* C3644 8012CF44 92C3053C */  lbu       $v1, 0x53c($s6)
/* C3648 8012CF48 24020003 */  addiu     $v0, $zero, 3
/* C364C 8012CF4C 14620008 */  bne       $v1, $v0, .L8012CF70
/* C3650 8012CF50 3C02E300 */   lui      $v0, 0xe300
/* C3654 8012CF54 3C03E300 */  lui       $v1, 0xe300
/* C3658 8012CF58 34631201 */  ori       $v1, $v1, 0x1201
/* C365C 8012CF5C 25820040 */  addiu     $v0, $t4, 0x40
/* C3660 8012CF60 ADA20000 */  sw        $v0, ($t5)
/* C3664 8012CF64 AD830038 */  sw        $v1, 0x38($t4)
/* C3668 8012CF68 0804B3E2 */  j         .L8012CF88
/* C366C 8012CF6C AD80003C */   sw       $zero, 0x3c($t4)
.L8012CF70:
/* C3670 8012CF70 34421201 */  ori       $v0, $v0, 0x1201
/* C3674 8012CF74 25830040 */  addiu     $v1, $t4, 0x40
/* C3678 8012CF78 ADA30000 */  sw        $v1, ($t5)
/* C367C 8012CF7C AD820038 */  sw        $v0, 0x38($t4)
/* C3680 8012CF80 24022000 */  addiu     $v0, $zero, 0x2000
/* C3684 8012CF84 AD82003C */  sw        $v0, 0x3c($t4)
.L8012CF88:
/* C3688 8012CF88 32AA00FF */  andi      $t2, $s5, 0xff
/* C368C 8012CF8C 2D4200FF */  sltiu     $v0, $t2, 0xff
/* C3690 8012CF90 14400016 */  bnez      $v0, .L8012CFEC
/* C3694 8012CF94 3C08E200 */   lui      $t0, 0xe200
/* C3698 8012CF98 3C07E200 */  lui       $a3, 0xe200
/* C369C 8012CF9C 34E7001C */  ori       $a3, $a3, 0x1c
/* C36A0 8012CFA0 3C050055 */  lui       $a1, 0x55
/* C36A4 8012CFA4 34A51208 */  ori       $a1, $a1, 0x1208
/* C36A8 8012CFA8 3C08FCFF */  lui       $t0, 0xfcff
/* C36AC 8012CFAC 3508FFFF */  ori       $t0, $t0, 0xffff
/* C36B0 8012CFB0 3C06FFFC */  lui       $a2, 0xfffc
/* C36B4 8012CFB4 3C04800A */  lui       $a0, %hi(gMasterGfxPos)
/* C36B8 8012CFB8 2484A66C */  addiu     $a0, $a0, %lo(gMasterGfxPos)
/* C36BC 8012CFBC 8C820000 */  lw        $v0, ($a0)
/* C36C0 8012CFC0 34C6F279 */  ori       $a2, $a2, 0xf279
/* C36C4 8012CFC4 0040182D */  daddu     $v1, $v0, $zero
/* C36C8 8012CFC8 24420008 */  addiu     $v0, $v0, 8
/* C36CC 8012CFCC AC820000 */  sw        $v0, ($a0)
/* C36D0 8012CFD0 AC670000 */  sw        $a3, ($v1)
/* C36D4 8012CFD4 AC650004 */  sw        $a1, 4($v1)
/* C36D8 8012CFD8 24430008 */  addiu     $v1, $v0, 8
/* C36DC 8012CFDC AC830000 */  sw        $v1, ($a0)
/* C36E0 8012CFE0 AC480000 */  sw        $t0, ($v0)
/* C36E4 8012CFE4 0804B416 */  j         .L8012D058
/* C36E8 8012CFE8 AC460004 */   sw       $a2, 4($v0)
.L8012CFEC:
/* C36EC 8012CFEC 3508001C */  ori       $t0, $t0, 0x1c
/* C36F0 8012CFF0 3C060050 */  lui       $a2, 0x50
/* C36F4 8012CFF4 34C64B40 */  ori       $a2, $a2, 0x4b40
/* C36F8 8012CFF8 3C09FCFF */  lui       $t1, 0xfcff
/* C36FC 8012CFFC 352997FF */  ori       $t1, $t1, 0x97ff
/* C3700 8012D000 3C07FF2C */  lui       $a3, 0xff2c
/* C3704 8012D004 34E7FE7F */  ori       $a3, $a3, 0xfe7f
/* C3708 8012D008 3C052020 */  lui       $a1, 0x2020
/* C370C 8012D00C 3C04800A */  lui       $a0, %hi(gMasterGfxPos)
/* C3710 8012D010 2484A66C */  addiu     $a0, $a0, %lo(gMasterGfxPos)
/* C3714 8012D014 34A52000 */  ori       $a1, $a1, 0x2000
/* C3718 8012D018 8C820000 */  lw        $v0, ($a0)
/* C371C 8012D01C 01452825 */  or        $a1, $t2, $a1
/* C3720 8012D020 0040182D */  daddu     $v1, $v0, $zero
/* C3724 8012D024 24420008 */  addiu     $v0, $v0, 8
/* C3728 8012D028 AC820000 */  sw        $v0, ($a0)
/* C372C 8012D02C AC680000 */  sw        $t0, ($v1)
/* C3730 8012D030 AC660004 */  sw        $a2, 4($v1)
/* C3734 8012D034 24430008 */  addiu     $v1, $v0, 8
/* C3738 8012D038 AC830000 */  sw        $v1, ($a0)
/* C373C 8012D03C 24430010 */  addiu     $v1, $v0, 0x10
/* C3740 8012D040 AC490000 */  sw        $t1, ($v0)
/* C3744 8012D044 AC470004 */  sw        $a3, 4($v0)
/* C3748 8012D048 AC830000 */  sw        $v1, ($a0)
/* C374C 8012D04C 3C03FA00 */  lui       $v1, 0xfa00
/* C3750 8012D050 AC430008 */  sw        $v1, 8($v0)
/* C3754 8012D054 AC45000C */  sw        $a1, 0xc($v0)
.L8012D058:
/* C3758 8012D058 3C03E300 */  lui       $v1, 0xe300
/* C375C 8012D05C 34631001 */  ori       $v1, $v1, 0x1001
/* C3760 8012D060 3C06F500 */  lui       $a2, 0xf500
/* C3764 8012D064 34C60100 */  ori       $a2, $a2, 0x100
/* C3768 8012D068 3C070703 */  lui       $a3, 0x703
/* C376C 8012D06C 34E7C000 */  ori       $a3, $a3, 0xc000
/* C3770 8012D070 3C0FFD48 */  lui       $t7, 0xfd48
/* C3774 8012D074 35EF000F */  ori       $t7, $t7, 0xf
/* C3778 8012D078 3C11F548 */  lui       $s1, 0xf548
/* C377C 8012D07C 36310400 */  ori       $s1, $s1, 0x400
/* C3780 8012D080 3C100709 */  lui       $s0, 0x709
/* C3784 8012D084 36108250 */  ori       $s0, $s0, 0x8250
/* C3788 8012D088 3C130703 */  lui       $s3, 0x703
/* C378C 8012D08C 3673E0FC */  ori       $s3, $s3, 0xe0fc
/* C3790 8012D090 3C16F540 */  lui       $s6, 0xf540
/* C3794 8012D094 36D60400 */  ori       $s6, $s6, 0x400
/* C3798 8012D098 3C170009 */  lui       $s7, 9
/* C379C 8012D09C 36F78250 */  ori       $s7, $s7, 0x8250
/* C37A0 8012D0A0 3C190007 */  lui       $t9, 7
/* C37A4 8012D0A4 3739C0FC */  ori       $t9, $t9, 0xc0fc
/* C37A8 8012D0A8 3C090100 */  lui       $t1, 0x100
/* C37AC 8012D0AC 35294008 */  ori       $t1, $t1, 0x4008
/* C37B0 8012D0B0 3C0B0600 */  lui       $t3, 0x600
/* C37B4 8012D0B4 356B0402 */  ori       $t3, $t3, 0x402
/* C37B8 8012D0B8 3C0A0002 */  lui       $t2, 2
/* C37BC 8012D0BC 354A0406 */  ori       $t2, $t2, 0x406
/* C37C0 8012D0C0 3C0CFD48 */  lui       $t4, 0xfd48
/* C37C4 8012D0C4 358C0003 */  ori       $t4, $t4, 3
/* C37C8 8012D0C8 3C0EF548 */  lui       $t6, 0xf548
/* C37CC 8012D0CC 35CE0200 */  ori       $t6, $t6, 0x200
/* C37D0 8012D0D0 3C0D0701 */  lui       $t5, 0x701
/* C37D4 8012D0D4 35AD8030 */  ori       $t5, $t5, 0x8030
/* C37D8 8012D0D8 3C120700 */  lui       $s2, 0x700
/* C37DC 8012D0DC 3652E0FC */  ori       $s2, $s2, 0xe0fc
/* C37E0 8012D0E0 3C15F540 */  lui       $s5, 0xf540
/* C37E4 8012D0E4 36B50200 */  ori       $s5, $s5, 0x200
/* C37E8 8012D0E8 3C140001 */  lui       $s4, 1
/* C37EC 8012D0EC 36948030 */  ori       $s4, $s4, 0x8030
/* C37F0 8012D0F0 3C180001 */  lui       $t8, 1
/* C37F4 8012D0F4 3C04800A */  lui       $a0, %hi(gMasterGfxPos)
/* C37F8 8012D0F8 2484A66C */  addiu     $a0, $a0, %lo(gMasterGfxPos)
/* C37FC 8012D0FC 3718C0FC */  ori       $t8, $t8, 0xc0fc
/* C3800 8012D100 8C820000 */  lw        $v0, ($a0)
/* C3804 8012D104 3C08E600 */  lui       $t0, 0xe600
/* C3808 8012D108 0040282D */  daddu     $a1, $v0, $zero
/* C380C 8012D10C 24420008 */  addiu     $v0, $v0, 8
/* C3810 8012D110 AC820000 */  sw        $v0, ($a0)
/* C3814 8012D114 ACA30000 */  sw        $v1, ($a1)
/* C3818 8012D118 34038000 */  ori       $v1, $zero, 0x8000
/* C381C 8012D11C ACA30004 */  sw        $v1, 4($a1)
/* C3820 8012D120 24430008 */  addiu     $v1, $v0, 8
/* C3824 8012D124 AC830000 */  sw        $v1, ($a0)
/* C3828 8012D128 3C058015 */  lui       $a1, %hi(D_80155D74)
/* C382C 8012D12C 8CA55D74 */  lw        $a1, %lo(D_80155D74)($a1)
/* C3830 8012D130 3C03FD10 */  lui       $v1, 0xfd10
/* C3834 8012D134 AC430000 */  sw        $v1, ($v0)
/* C3838 8012D138 90A5002B */  lbu       $a1, 0x2b($a1)
/* C383C 8012D13C 24430010 */  addiu     $v1, $v0, 0x10
/* C3840 8012D140 AC830000 */  sw        $v1, ($a0)
/* C3844 8012D144 3C03E800 */  lui       $v1, 0xe800
/* C3848 8012D148 AC430008 */  sw        $v1, 8($v0)
/* C384C 8012D14C 24430018 */  addiu     $v1, $v0, 0x18
/* C3850 8012D150 AC40000C */  sw        $zero, 0xc($v0)
/* C3854 8012D154 AC830000 */  sw        $v1, ($a0)
/* C3858 8012D158 3C030700 */  lui       $v1, 0x700
/* C385C 8012D15C AC430014 */  sw        $v1, 0x14($v0)
/* C3860 8012D160 24430020 */  addiu     $v1, $v0, 0x20
/* C3864 8012D164 AC460010 */  sw        $a2, 0x10($v0)
/* C3868 8012D168 AC830000 */  sw        $v1, ($a0)
/* C386C 8012D16C 24430028 */  addiu     $v1, $v0, 0x28
/* C3870 8012D170 AC480018 */  sw        $t0, 0x18($v0)
/* C3874 8012D174 AC40001C */  sw        $zero, 0x1c($v0)
/* C3878 8012D178 AC830000 */  sw        $v1, ($a0)
/* C387C 8012D17C 3C03F000 */  lui       $v1, 0xf000
/* C3880 8012D180 AC430020 */  sw        $v1, 0x20($v0)
/* C3884 8012D184 24430030 */  addiu     $v1, $v0, 0x30
/* C3888 8012D188 AC470024 */  sw        $a3, 0x24($v0)
/* C388C 8012D18C 3C07E700 */  lui       $a3, 0xe700
/* C3890 8012D190 AC830000 */  sw        $v1, ($a0)
/* C3894 8012D194 24430038 */  addiu     $v1, $v0, 0x38
/* C3898 8012D198 AC470028 */  sw        $a3, 0x28($v0)
/* C389C 8012D19C AC40002C */  sw        $zero, 0x2c($v0)
/* C38A0 8012D1A0 AC830000 */  sw        $v1, ($a0)
/* C38A4 8012D1A4 3C03802F */  lui       $v1, %hi(D_802EB670)
/* C38A8 8012D1A8 2463B670 */  addiu     $v1, $v1, %lo(D_802EB670)
/* C38AC 8012D1AC AC430034 */  sw        $v1, 0x34($v0)
/* C38B0 8012D1B0 24430040 */  addiu     $v1, $v0, 0x40
/* C38B4 8012D1B4 AC4F0030 */  sw        $t7, 0x30($v0)
/* C38B8 8012D1B8 AC830000 */  sw        $v1, ($a0)
/* C38BC 8012D1BC 24430048 */  addiu     $v1, $v0, 0x48
/* C38C0 8012D1C0 AC510038 */  sw        $s1, 0x38($v0)
/* C38C4 8012D1C4 AC50003C */  sw        $s0, 0x3c($v0)
/* C38C8 8012D1C8 AC830000 */  sw        $v1, ($a0)
/* C38CC 8012D1CC 3C03802F */  lui       $v1, %hi(D_802EC3F0)
/* C38D0 8012D1D0 2463C3F0 */  addiu     $v1, $v1, %lo(D_802EC3F0)
/* C38D4 8012D1D4 3C06F400 */  lui       $a2, 0xf400
/* C38D8 8012D1D8 AC480040 */  sw        $t0, 0x40($v0)
/* C38DC 8012D1DC AC400044 */  sw        $zero, 0x44($v0)
/* C38E0 8012D1E0 00052940 */  sll       $a1, $a1, 5
/* C38E4 8012D1E4 00A32821 */  addu      $a1, $a1, $v1
/* C38E8 8012D1E8 24430050 */  addiu     $v1, $v0, 0x50
/* C38EC 8012D1EC AC450004 */  sw        $a1, 4($v0)
/* C38F0 8012D1F0 AC830000 */  sw        $v1, ($a0)
/* C38F4 8012D1F4 24430058 */  addiu     $v1, $v0, 0x58
/* C38F8 8012D1F8 AC460048 */  sw        $a2, 0x48($v0)
/* C38FC 8012D1FC AC53004C */  sw        $s3, 0x4c($v0)
/* C3900 8012D200 AC830000 */  sw        $v1, ($a0)
/* C3904 8012D204 24430060 */  addiu     $v1, $v0, 0x60
/* C3908 8012D208 AC470050 */  sw        $a3, 0x50($v0)
/* C390C 8012D20C AC400054 */  sw        $zero, 0x54($v0)
/* C3910 8012D210 AC830000 */  sw        $v1, ($a0)
/* C3914 8012D214 24430068 */  addiu     $v1, $v0, 0x68
/* C3918 8012D218 3C05F200 */  lui       $a1, 0xf200
/* C391C 8012D21C AC560058 */  sw        $s6, 0x58($v0)
/* C3920 8012D220 AC57005C */  sw        $s7, 0x5c($v0)
/* C3924 8012D224 AC830000 */  sw        $v1, ($a0)
/* C3928 8012D228 24430070 */  addiu     $v1, $v0, 0x70
/* C392C 8012D22C AC450060 */  sw        $a1, 0x60($v0)
/* C3930 8012D230 AC590064 */  sw        $t9, 0x64($v0)
/* C3934 8012D234 AC830000 */  sw        $v1, ($a0)
/* C3938 8012D238 3C038015 */  lui       $v1, %hi(D_8014C3C0)
/* C393C 8012D23C 2463C3C0 */  addiu     $v1, $v1, %lo(D_8014C3C0)
/* C3940 8012D240 AC43006C */  sw        $v1, 0x6c($v0)
/* C3944 8012D244 24430078 */  addiu     $v1, $v0, 0x78
/* C3948 8012D248 AC490068 */  sw        $t1, 0x68($v0)
/* C394C 8012D24C AC830000 */  sw        $v1, ($a0)
/* C3950 8012D250 24430080 */  addiu     $v1, $v0, 0x80
/* C3954 8012D254 AC4B0070 */  sw        $t3, 0x70($v0)
/* C3958 8012D258 AC4A0074 */  sw        $t2, 0x74($v0)
/* C395C 8012D25C AC830000 */  sw        $v1, ($a0)
/* C3960 8012D260 3C03802F */  lui       $v1, %hi(D_802EBA70)
/* C3964 8012D264 2463BA70 */  addiu     $v1, $v1, %lo(D_802EBA70)
/* C3968 8012D268 AC43007C */  sw        $v1, 0x7c($v0)
/* C396C 8012D26C 24430088 */  addiu     $v1, $v0, 0x88
/* C3970 8012D270 AC4C0078 */  sw        $t4, 0x78($v0)
/* C3974 8012D274 AC830000 */  sw        $v1, ($a0)
/* C3978 8012D278 24430090 */  addiu     $v1, $v0, 0x90
/* C397C 8012D27C AC4E0080 */  sw        $t6, 0x80($v0)
/* C3980 8012D280 AC4D0084 */  sw        $t5, 0x84($v0)
/* C3984 8012D284 AC830000 */  sw        $v1, ($a0)
/* C3988 8012D288 24430098 */  addiu     $v1, $v0, 0x98
/* C398C 8012D28C AC480088 */  sw        $t0, 0x88($v0)
/* C3990 8012D290 AC40008C */  sw        $zero, 0x8c($v0)
/* C3994 8012D294 AC830000 */  sw        $v1, ($a0)
/* C3998 8012D298 244300A0 */  addiu     $v1, $v0, 0xa0
/* C399C 8012D29C AC460090 */  sw        $a2, 0x90($v0)
/* C39A0 8012D2A0 AC520094 */  sw        $s2, 0x94($v0)
/* C39A4 8012D2A4 AC830000 */  sw        $v1, ($a0)
/* C39A8 8012D2A8 244300A8 */  addiu     $v1, $v0, 0xa8
/* C39AC 8012D2AC AC470098 */  sw        $a3, 0x98($v0)
/* C39B0 8012D2B0 AC40009C */  sw        $zero, 0x9c($v0)
/* C39B4 8012D2B4 AC830000 */  sw        $v1, ($a0)
/* C39B8 8012D2B8 244300B0 */  addiu     $v1, $v0, 0xb0
/* C39BC 8012D2BC AC5500A0 */  sw        $s5, 0xa0($v0)
/* C39C0 8012D2C0 AC5400A4 */  sw        $s4, 0xa4($v0)
/* C39C4 8012D2C4 AC830000 */  sw        $v1, ($a0)
/* C39C8 8012D2C8 244300B8 */  addiu     $v1, $v0, 0xb8
/* C39CC 8012D2CC AC4500A8 */  sw        $a1, 0xa8($v0)
/* C39D0 8012D2D0 AC5800AC */  sw        $t8, 0xac($v0)
/* C39D4 8012D2D4 AC830000 */  sw        $v1, ($a0)
/* C39D8 8012D2D8 3C038015 */  lui       $v1, %hi(D_8014C400)
/* C39DC 8012D2DC 2463C400 */  addiu     $v1, $v1, %lo(D_8014C400)
/* C39E0 8012D2E0 AC4300B4 */  sw        $v1, 0xb4($v0)
/* C39E4 8012D2E4 244300C0 */  addiu     $v1, $v0, 0xc0
/* C39E8 8012D2E8 AC4900B0 */  sw        $t1, 0xb0($v0)
/* C39EC 8012D2EC AC830000 */  sw        $v1, ($a0)
/* C39F0 8012D2F0 244300C8 */  addiu     $v1, $v0, 0xc8
/* C39F4 8012D2F4 AC4B00B8 */  sw        $t3, 0xb8($v0)
/* C39F8 8012D2F8 AC4A00BC */  sw        $t2, 0xbc($v0)
/* C39FC 8012D2FC AC830000 */  sw        $v1, ($a0)
/* C3A00 8012D300 3C03802F */  lui       $v1, %hi(D_802EBB70)
/* C3A04 8012D304 2463BB70 */  addiu     $v1, $v1, %lo(D_802EBB70)
/* C3A08 8012D308 AC4300C4 */  sw        $v1, 0xc4($v0)
/* C3A0C 8012D30C 244300D0 */  addiu     $v1, $v0, 0xd0
/* C3A10 8012D310 AC4F00C0 */  sw        $t7, 0xc0($v0)
/* C3A14 8012D314 AC830000 */  sw        $v1, ($a0)
/* C3A18 8012D318 244300D8 */  addiu     $v1, $v0, 0xd8
/* C3A1C 8012D31C AC5100C8 */  sw        $s1, 0xc8($v0)
/* C3A20 8012D320 AC5000CC */  sw        $s0, 0xcc($v0)
/* C3A24 8012D324 AC830000 */  sw        $v1, ($a0)
/* C3A28 8012D328 244300E0 */  addiu     $v1, $v0, 0xe0
/* C3A2C 8012D32C AC4800D0 */  sw        $t0, 0xd0($v0)
/* C3A30 8012D330 AC4000D4 */  sw        $zero, 0xd4($v0)
/* C3A34 8012D334 AC830000 */  sw        $v1, ($a0)
/* C3A38 8012D338 244300E8 */  addiu     $v1, $v0, 0xe8
/* C3A3C 8012D33C AC4600D8 */  sw        $a2, 0xd8($v0)
/* C3A40 8012D340 AC5300DC */  sw        $s3, 0xdc($v0)
/* C3A44 8012D344 AC830000 */  sw        $v1, ($a0)
/* C3A48 8012D348 244300F0 */  addiu     $v1, $v0, 0xf0
/* C3A4C 8012D34C AC4700E0 */  sw        $a3, 0xe0($v0)
/* C3A50 8012D350 AC4000E4 */  sw        $zero, 0xe4($v0)
/* C3A54 8012D354 AC830000 */  sw        $v1, ($a0)
/* C3A58 8012D358 244300F8 */  addiu     $v1, $v0, 0xf8
/* C3A5C 8012D35C AC5600E8 */  sw        $s6, 0xe8($v0)
/* C3A60 8012D360 AC5700EC */  sw        $s7, 0xec($v0)
/* C3A64 8012D364 AC830000 */  sw        $v1, ($a0)
/* C3A68 8012D368 24430100 */  addiu     $v1, $v0, 0x100
/* C3A6C 8012D36C AC4500F0 */  sw        $a1, 0xf0($v0)
/* C3A70 8012D370 AC5900F4 */  sw        $t9, 0xf4($v0)
/* C3A74 8012D374 AC830000 */  sw        $v1, ($a0)
/* C3A78 8012D378 3C038015 */  lui       $v1, %hi(D_8014C440)
/* C3A7C 8012D37C 2463C440 */  addiu     $v1, $v1, %lo(D_8014C440)
/* C3A80 8012D380 AC4900F8 */  sw        $t1, 0xf8($v0)
/* C3A84 8012D384 AC4300FC */  sw        $v1, 0xfc($v0)
/* C3A88 8012D388 24430108 */  addiu     $v1, $v0, 0x108
/* C3A8C 8012D38C AC830000 */  sw        $v1, ($a0)
/* C3A90 8012D390 24430110 */  addiu     $v1, $v0, 0x110
/* C3A94 8012D394 AC4B0100 */  sw        $t3, 0x100($v0)
/* C3A98 8012D398 AC4A0104 */  sw        $t2, 0x104($v0)
/* C3A9C 8012D39C AC830000 */  sw        $v1, ($a0)
/* C3AA0 8012D3A0 AC470108 */  sw        $a3, 0x108($v0)
/* C3AA4 8012D3A4 AC40010C */  sw        $zero, 0x10c($v0)
/* C3AA8 8012D3A8 8FBF00C0 */  lw        $ra, 0xc0($sp)
/* C3AAC 8012D3AC 8FB700BC */  lw        $s7, 0xbc($sp)
/* C3AB0 8012D3B0 8FB600B8 */  lw        $s6, 0xb8($sp)
/* C3AB4 8012D3B4 8FB500B4 */  lw        $s5, 0xb4($sp)
/* C3AB8 8012D3B8 8FB400B0 */  lw        $s4, 0xb0($sp)
/* C3ABC 8012D3BC 8FB300AC */  lw        $s3, 0xac($sp)
/* C3AC0 8012D3C0 8FB200A8 */  lw        $s2, 0xa8($sp)
/* C3AC4 8012D3C4 8FB100A4 */  lw        $s1, 0xa4($sp)
/* C3AC8 8012D3C8 8FB000A0 */  lw        $s0, 0xa0($sp)
/* C3ACC 8012D3CC D7B600D0 */  ldc1      $f22, 0xd0($sp)
/* C3AD0 8012D3D0 D7B400C8 */  ldc1      $f20, 0xc8($sp)
/* C3AD4 8012D3D4 03E00008 */  jr        $ra
/* C3AD8 8012D3D8 27BD00D8 */   addiu    $sp, $sp, 0xd8
