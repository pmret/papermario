.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800ED5D0
/* 86A80 800ED5D0 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 86A84 800ED5D4 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 86A88 800ED5D8 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 86A8C 800ED5DC AFB00030 */  sw        $s0, 0x30($sp)
/* 86A90 800ED5E0 AFB20038 */  sw        $s2, 0x38($sp)
/* 86A94 800ED5E4 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* 86A98 800ED5E8 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* 86A9C 800ED5EC AFBF004C */  sw        $ra, 0x4c($sp)
/* 86AA0 800ED5F0 AFB60048 */  sw        $s6, 0x48($sp)
/* 86AA4 800ED5F4 AFB50044 */  sw        $s5, 0x44($sp)
/* 86AA8 800ED5F8 AFB40040 */  sw        $s4, 0x40($sp)
/* 86AAC 800ED5FC AFB3003C */  sw        $s3, 0x3c($sp)
/* 86AB0 800ED600 AFB10034 */  sw        $s1, 0x34($sp)
/* 86AB4 800ED604 80420081 */  lb        $v0, 0x81($v0)
/* 86AB8 800ED608 3C118011 */  lui       $s1, %hi(D_8010EBB0)
/* 86ABC 800ED60C 2631EBB0 */  addiu     $s1, $s1, %lo(D_8010EBB0)
/* 86AC0 800ED610 1040000B */  beqz      $v0, .L800ED640
/* 86AC4 800ED614 0080802D */   daddu    $s0, $a0, $zero
/* 86AC8 800ED618 8E420000 */  lw        $v0, ($s2)
/* 86ACC 800ED61C 30423000 */  andi      $v0, $v0, 0x3000
/* 86AD0 800ED620 14400007 */  bnez      $v0, .L800ED640
/* 86AD4 800ED624 00000000 */   nop
/* 86AD8 800ED628 82220014 */  lb        $v0, 0x14($s1)
/* 86ADC 800ED62C 14400004 */  bnez      $v0, .L800ED640
/* 86AE0 800ED630 00000000 */   nop
/* 86AE4 800ED634 82220002 */  lb        $v0, 2($s1)
/* 86AE8 800ED638 1040000F */  beqz      $v0, .L800ED678
/* 86AEC 800ED63C 00000000 */   nop
.L800ED640:
/* 86AF0 800ED640 8E420004 */  lw        $v0, 4($s2)
/* 86AF4 800ED644 30420800 */  andi      $v0, $v0, 0x800
/* 86AF8 800ED648 10400005 */  beqz      $v0, .L800ED660
/* 86AFC 800ED64C 00000000 */   nop
/* 86B00 800ED650 3C028010 */  lui       $v0, %hi(D_800F8020)
/* 86B04 800ED654 8C428020 */  lw        $v0, %lo(D_800F8020)($v0)
/* 86B08 800ED658 14400003 */  bnez      $v0, .L800ED668
/* 86B0C 800ED65C 00000000 */   nop
.L800ED660:
/* 86B10 800ED660 0C03B67E */  jal       func_800ED9F8
/* 86B14 800ED664 0200202D */   daddu    $a0, $s0, $zero
.L800ED668:
/* 86B18 800ED668 8E22000C */  lw        $v0, 0xc($s1)
/* 86B1C 800ED66C 30426006 */  andi      $v0, $v0, 0x6006
/* 86B20 800ED670 54400001 */  bnel      $v0, $zero, .L800ED678
/* 86B24 800ED674 A2200002 */   sb       $zero, 2($s1)
.L800ED678:
/* 86B28 800ED678 3C038011 */  lui       $v1, %hi(D_8010CFC8)
/* 86B2C 800ED67C 8463CFC8 */  lh        $v1, %lo(D_8010CFC8)($v1)
/* 86B30 800ED680 24020032 */  addiu     $v0, $zero, 0x32
/* 86B34 800ED684 10620017 */  beq       $v1, $v0, .L800ED6E4
/* 86B38 800ED688 0000202D */   daddu    $a0, $zero, $zero
/* 86B3C 800ED68C C600003C */  lwc1      $f0, 0x3c($s0)
/* 86B40 800ED690 C642002C */  lwc1      $f2, 0x2c($s2)
/* 86B44 800ED694 46020001 */  sub.s     $f0, $f0, $f2
/* 86B48 800ED698 3C01447A */  lui       $at, 0x447a
/* 86B4C 800ED69C 44811000 */  mtc1      $at, $f2
/* 86B50 800ED6A0 46000005 */  abs.s     $f0, $f0
/* 86B54 800ED6A4 4600103C */  c.lt.s    $f2, $f0
/* 86B58 800ED6A8 00000000 */  nop
/* 86B5C 800ED6AC 4500000D */  bc1f      .L800ED6E4
/* 86B60 800ED6B0 2403F7FF */   addiu    $v1, $zero, -0x801
/* 86B64 800ED6B4 C6400028 */  lwc1      $f0, 0x28($s2)
/* 86B68 800ED6B8 8E020000 */  lw        $v0, ($s0)
/* 86B6C 800ED6BC E6000038 */  swc1      $f0, 0x38($s0)
/* 86B70 800ED6C0 C640002C */  lwc1      $f0, 0x2c($s2)
/* 86B74 800ED6C4 E600003C */  swc1      $f0, 0x3c($s0)
/* 86B78 800ED6C8 C6400030 */  lwc1      $f0, 0x30($s2)
/* 86B7C 800ED6CC 00431024 */  and       $v0, $v0, $v1
/* 86B80 800ED6D0 AE00001C */  sw        $zero, 0x1c($s0)
/* 86B84 800ED6D4 AE000014 */  sw        $zero, 0x14($s0)
/* 86B88 800ED6D8 AE020000 */  sw        $v0, ($s0)
/* 86B8C 800ED6DC E6000040 */  swc1      $f0, 0x40($s0)
/* 86B90 800ED6E0 0000202D */  daddu     $a0, $zero, $zero
.L800ED6E4:
/* 86B94 800ED6E4 27B30020 */  addiu     $s3, $sp, 0x20
/* 86B98 800ED6E8 0260282D */  daddu     $a1, $s3, $zero
/* 86B9C 800ED6EC 27B50024 */  addiu     $s5, $sp, 0x24
/* 86BA0 800ED6F0 02A0302D */  daddu     $a2, $s5, $zero
/* 86BA4 800ED6F4 27B60028 */  addiu     $s6, $sp, 0x28
/* 86BA8 800ED6F8 02C0382D */  daddu     $a3, $s6, $zero
/* 86BAC 800ED6FC 860200A8 */  lh        $v0, 0xa8($s0)
/* 86BB0 800ED700 3C013F00 */  lui       $at, 0x3f00
/* 86BB4 800ED704 44811000 */  mtc1      $at, $f2
/* 86BB8 800ED708 44823000 */  mtc1      $v0, $f6
/* 86BBC 800ED70C 00000000 */  nop
/* 86BC0 800ED710 468031A0 */  cvt.s.w   $f6, $f6
/* 86BC4 800ED714 46023182 */  mul.s     $f6, $f6, $f2
/* 86BC8 800ED718 00000000 */  nop
/* 86BCC 800ED71C 3C148010 */  lui       $s4, %hi(D_800F8020)
/* 86BD0 800ED720 26948020 */  addiu     $s4, $s4, %lo(D_800F8020)
/* 86BD4 800ED724 27B1002C */  addiu     $s1, $sp, 0x2c
/* 86BD8 800ED728 C6000038 */  lwc1      $f0, 0x38($s0)
/* 86BDC 800ED72C 44822000 */  mtc1      $v0, $f4
/* 86BE0 800ED730 00000000 */  nop
/* 86BE4 800ED734 46802120 */  cvt.s.w   $f4, $f4
/* 86BE8 800ED738 46022102 */  mul.s     $f4, $f4, $f2
/* 86BEC 800ED73C 00000000 */  nop
/* 86BF0 800ED740 AE800000 */  sw        $zero, ($s4)
/* 86BF4 800ED744 E7A00020 */  swc1      $f0, 0x20($sp)
/* 86BF8 800ED748 C600003C */  lwc1      $f0, 0x3c($s0)
/* 86BFC 800ED74C C6020040 */  lwc1      $f2, 0x40($s0)
/* 86C00 800ED750 46060000 */  add.s     $f0, $f0, $f6
/* 86C04 800ED754 E7A20028 */  swc1      $f2, 0x28($sp)
/* 86C08 800ED758 E7A4002C */  swc1      $f4, 0x2c($sp)
/* 86C0C 800ED75C E7A00024 */  swc1      $f0, 0x24($sp)
/* 86C10 800ED760 0C03739C */  jal       func_800DCE70
/* 86C14 800ED764 AFB10010 */   sw       $s1, 0x10($sp)
/* 86C18 800ED768 10400006 */  beqz      $v0, .L800ED784
/* 86C1C 800ED76C 24020001 */   addiu    $v0, $zero, 1
/* 86C20 800ED770 C6000038 */  lwc1      $f0, 0x38($s0)
/* 86C24 800ED774 C602003C */  lwc1      $f2, 0x3c($s0)
/* 86C28 800ED778 C6040040 */  lwc1      $f4, 0x40($s0)
/* 86C2C 800ED77C 0803B66E */  j         .L800ED9B8
/* 86C30 800ED780 AE820000 */   sw       $v0, ($s4)
.L800ED784:
/* 86C34 800ED784 0C03BD90 */  jal       func_800EF640
/* 86C38 800ED788 0200202D */   daddu    $a0, $s0, $zero
/* 86C3C 800ED78C 3C038011 */  lui       $v1, %hi(D_8010CFC8)
/* 86C40 800ED790 8463CFC8 */  lh        $v1, %lo(D_8010CFC8)($v1)
/* 86C44 800ED794 24020032 */  addiu     $v0, $zero, 0x32
/* 86C48 800ED798 10620084 */  beq       $v1, $v0, .L800ED9AC
/* 86C4C 800ED79C 3C040001 */   lui      $a0, 1
/* 86C50 800ED7A0 C6000038 */  lwc1      $f0, 0x38($s0)
/* 86C54 800ED7A4 C602003C */  lwc1      $f2, 0x3c($s0)
/* 86C58 800ED7A8 C6040040 */  lwc1      $f4, 0x40($s0)
/* 86C5C 800ED7AC 3C01447A */  lui       $at, 0x447a
/* 86C60 800ED7B0 44813000 */  mtc1      $at, $f6
/* 86C64 800ED7B4 0260282D */  daddu     $a1, $s3, $zero
/* 86C68 800ED7B8 E7A00020 */  swc1      $f0, 0x20($sp)
/* 86C6C 800ED7BC E7A20024 */  swc1      $f2, 0x24($sp)
/* 86C70 800ED7C0 E7A40028 */  swc1      $f4, 0x28($sp)
/* 86C74 800ED7C4 E7A6002C */  swc1      $f6, 0x2c($sp)
/* 86C78 800ED7C8 AFB10010 */  sw        $s1, 0x10($sp)
/* 86C7C 800ED7CC C600000C */  lwc1      $f0, 0xc($s0)
/* 86C80 800ED7D0 02A0302D */  daddu     $a2, $s5, $zero
/* 86C84 800ED7D4 E7A00014 */  swc1      $f0, 0x14($sp)
/* 86C88 800ED7D8 860200A6 */  lh        $v0, 0xa6($s0)
/* 86C8C 800ED7DC 02C0382D */  daddu     $a3, $s6, $zero
/* 86C90 800ED7E0 44820000 */  mtc1      $v0, $f0
/* 86C94 800ED7E4 00000000 */  nop
/* 86C98 800ED7E8 46800020 */  cvt.s.w   $f0, $f0
/* 86C9C 800ED7EC 0C0371DE */  jal       func_800DC778
/* 86CA0 800ED7F0 E7A00018 */   swc1     $f0, 0x18($sp)
/* 86CA4 800ED7F4 14400003 */  bnez      $v0, .L800ED804
/* 86CA8 800ED7F8 00000000 */   nop
/* 86CAC 800ED7FC C640002C */  lwc1      $f0, 0x2c($s2)
/* 86CB0 800ED800 E7A00024 */  swc1      $f0, 0x24($sp)
.L800ED804:
/* 86CB4 800ED804 960200A8 */  lhu       $v0, 0xa8($s0)
/* 86CB8 800ED808 C7A60024 */  lwc1      $f6, 0x24($sp)
/* 86CBC 800ED80C 00021400 */  sll       $v0, $v0, 0x10
/* 86CC0 800ED810 00021C03 */  sra       $v1, $v0, 0x10
/* 86CC4 800ED814 44830000 */  mtc1      $v1, $f0
/* 86CC8 800ED818 00000000 */  nop
/* 86CCC 800ED81C 46800020 */  cvt.s.w   $f0, $f0
/* 86CD0 800ED820 46003200 */  add.s     $f8, $f6, $f0
/* 86CD4 800ED824 3C014000 */  lui       $at, 0x4000
/* 86CD8 800ED828 44815000 */  mtc1      $at, $f10
/* 86CDC 800ED82C 00000000 */  nop
/* 86CE0 800ED830 460A4000 */  add.s     $f0, $f8, $f10
/* 86CE4 800ED834 C604003C */  lwc1      $f4, 0x3c($s0)
/* 86CE8 800ED838 4600203E */  c.le.s    $f4, $f0
/* 86CEC 800ED83C 00000000 */  nop
/* 86CF0 800ED840 45000024 */  bc1f      .L800ED8D4
/* 86CF4 800ED844 00000000 */   nop
/* 86CF8 800ED848 C6420054 */  lwc1      $f2, 0x54($s2)
/* 86CFC 800ED84C 44800000 */  mtc1      $zero, $f0
/* 86D00 800ED850 00000000 */  nop
/* 86D04 800ED854 46001032 */  c.eq.s    $f2, $f0
/* 86D08 800ED858 00000000 */  nop
/* 86D0C 800ED85C 4501000C */  bc1t      .L800ED890
/* 86D10 800ED860 000217C2 */   srl      $v0, $v0, 0x1f
/* 86D14 800ED864 00621021 */  addu      $v0, $v1, $v0
/* 86D18 800ED868 00021043 */  sra       $v0, $v0, 1
/* 86D1C 800ED86C 44820000 */  mtc1      $v0, $f0
/* 86D20 800ED870 00000000 */  nop
/* 86D24 800ED874 46800020 */  cvt.s.w   $f0, $f0
/* 86D28 800ED878 46003000 */  add.s     $f0, $f6, $f0
/* 86D2C 800ED87C 460A0000 */  add.s     $f0, $f0, $f10
/* 86D30 800ED880 3C013E00 */  lui       $at, 0x3e00
/* 86D34 800ED884 44811000 */  mtc1      $at, $f2
/* 86D38 800ED888 0803B662 */  j         .L800ED988
/* 86D3C 800ED88C 46040001 */   sub.s    $f0, $f0, $f4
.L800ED890:
/* 86D40 800ED890 C642002C */  lwc1      $f2, 0x2c($s2)
/* 86D44 800ED894 4602303C */  c.lt.s    $f6, $f2
/* 86D48 800ED898 00000000 */  nop
/* 86D4C 800ED89C 45000005 */  bc1f      .L800ED8B4
/* 86D50 800ED8A0 00000000 */   nop
/* 86D54 800ED8A4 3C014120 */  lui       $at, 0x4120
/* 86D58 800ED8A8 44810000 */  mtc1      $at, $f0
/* 86D5C 800ED8AC 0803B631 */  j         .L800ED8C4
/* 86D60 800ED8B0 46001000 */   add.s    $f0, $f2, $f0
.L800ED8B4:
/* 86D64 800ED8B4 3C014120 */  lui       $at, 0x4120
/* 86D68 800ED8B8 44810000 */  mtc1      $at, $f0
/* 86D6C 800ED8BC 00000000 */  nop
/* 86D70 800ED8C0 46003000 */  add.s     $f0, $f6, $f0
.L800ED8C4:
/* 86D74 800ED8C4 3C013E80 */  lui       $at, 0x3e80
/* 86D78 800ED8C8 44811000 */  mtc1      $at, $f2
/* 86D7C 800ED8CC 0803B662 */  j         .L800ED988
/* 86D80 800ED8D0 46040001 */   sub.s    $f0, $f0, $f4
.L800ED8D4:
/* 86D84 800ED8D4 864200B0 */  lh        $v0, 0xb0($s2)
/* 86D88 800ED8D8 C642002C */  lwc1      $f2, 0x2c($s2)
/* 86D8C 800ED8DC 44820000 */  mtc1      $v0, $f0
/* 86D90 800ED8E0 00000000 */  nop
/* 86D94 800ED8E4 46800020 */  cvt.s.w   $f0, $f0
/* 86D98 800ED8E8 46001080 */  add.s     $f2, $f2, $f0
/* 86D9C 800ED8EC 4606103C */  c.lt.s    $f2, $f6
/* 86DA0 800ED8F0 00000000 */  nop
/* 86DA4 800ED8F4 4500001C */  bc1f      .L800ED968
/* 86DA8 800ED8F8 00000000 */   nop
/* 86DAC 800ED8FC 46044081 */  sub.s     $f2, $f8, $f4
/* 86DB0 800ED900 3C013E00 */  lui       $at, 0x3e00
/* 86DB4 800ED904 44810000 */  mtc1      $at, $f0
/* 86DB8 800ED908 00000000 */  nop
/* 86DBC 800ED90C 46001082 */  mul.s     $f2, $f2, $f0
/* 86DC0 800ED910 00000000 */  nop
/* 86DC4 800ED914 860200A8 */  lh        $v0, 0xa8($s0)
/* 86DC8 800ED918 44820000 */  mtc1      $v0, $f0
/* 86DCC 800ED91C 00000000 */  nop
/* 86DD0 800ED920 46800020 */  cvt.s.w   $f0, $f0
/* 86DD4 800ED924 46003000 */  add.s     $f0, $f6, $f0
/* 86DD8 800ED928 C608003C */  lwc1      $f8, 0x3c($s0)
/* 86DDC 800ED92C 46024100 */  add.s     $f4, $f8, $f2
/* 86DE0 800ED930 3C028010 */  lui       $v0, %hi(D_800F84F8)
/* 86DE4 800ED934 244284F8 */  addiu     $v0, $v0, %lo(D_800F84F8)
/* 86DE8 800ED938 4600203E */  c.le.s    $f4, $f0
/* 86DEC 800ED93C 00000000 */  nop
/* 86DF0 800ED940 45000015 */  bc1f      .L800ED998
/* 86DF4 800ED944 E4420000 */   swc1     $f2, ($v0)
/* 86DF8 800ED948 46080001 */  sub.s     $f0, $f0, $f8
/* 86DFC 800ED94C 3C013E80 */  lui       $at, 0x3e80
/* 86E00 800ED950 44811000 */  mtc1      $at, $f2
/* 86E04 800ED954 00000000 */  nop
/* 86E08 800ED958 46020002 */  mul.s     $f0, $f0, $f2
/* 86E0C 800ED95C 00000000 */  nop
/* 86E10 800ED960 0803B666 */  j         .L800ED998
/* 86E14 800ED964 E4400000 */   swc1     $f0, ($v0)
.L800ED968:
/* 86E18 800ED968 3C0140A0 */  lui       $at, 0x40a0
/* 86E1C 800ED96C 44810000 */  mtc1      $at, $f0
/* 86E20 800ED970 00000000 */  nop
/* 86E24 800ED974 46001000 */  add.s     $f0, $f2, $f0
/* 86E28 800ED978 46040001 */  sub.s     $f0, $f0, $f4
/* 86E2C 800ED97C 3C013D80 */  lui       $at, 0x3d80
/* 86E30 800ED980 44811000 */  mtc1      $at, $f2
/* 86E34 800ED984 00000000 */  nop
.L800ED988:
/* 86E38 800ED988 46020002 */  mul.s     $f0, $f0, $f2
/* 86E3C 800ED98C 00000000 */  nop
/* 86E40 800ED990 3C018010 */  lui       $at, %hi(D_800F84F8)
/* 86E44 800ED994 E42084F8 */  swc1      $f0, %lo(D_800F84F8)($at)
.L800ED998:
/* 86E48 800ED998 C600003C */  lwc1      $f0, 0x3c($s0)
/* 86E4C 800ED99C 3C018010 */  lui       $at, %hi(D_800F84F8)
/* 86E50 800ED9A0 C42284F8 */  lwc1      $f2, %lo(D_800F84F8)($at)
/* 86E54 800ED9A4 46020000 */  add.s     $f0, $f0, $f2
/* 86E58 800ED9A8 E600003C */  swc1      $f0, 0x3c($s0)
.L800ED9AC:
/* 86E5C 800ED9AC C6000038 */  lwc1      $f0, 0x38($s0)
/* 86E60 800ED9B0 C602003C */  lwc1      $f2, 0x3c($s0)
/* 86E64 800ED9B4 C6040040 */  lwc1      $f4, 0x40($s0)
.L800ED9B8:
/* 86E68 800ED9B8 3C018010 */  lui       $at, %hi(D_800F833C)
/* 86E6C 800ED9BC E420833C */  swc1      $f0, %lo(D_800F833C)($at)
/* 86E70 800ED9C0 3C018010 */  lui       $at, %hi(D_800F8340)
/* 86E74 800ED9C4 E4228340 */  swc1      $f2, %lo(D_800F8340)($at)
/* 86E78 800ED9C8 3C018010 */  lui       $at, %hi(D_800F8344)
/* 86E7C 800ED9CC E4248344 */  swc1      $f4, %lo(D_800F8344)($at)
/* 86E80 800ED9D0 8FBF004C */  lw        $ra, 0x4c($sp)
/* 86E84 800ED9D4 8FB60048 */  lw        $s6, 0x48($sp)
/* 86E88 800ED9D8 8FB50044 */  lw        $s5, 0x44($sp)
/* 86E8C 800ED9DC 8FB40040 */  lw        $s4, 0x40($sp)
/* 86E90 800ED9E0 8FB3003C */  lw        $s3, 0x3c($sp)
/* 86E94 800ED9E4 8FB20038 */  lw        $s2, 0x38($sp)
/* 86E98 800ED9E8 8FB10034 */  lw        $s1, 0x34($sp)
/* 86E9C 800ED9EC 8FB00030 */  lw        $s0, 0x30($sp)
/* 86EA0 800ED9F0 03E00008 */  jr        $ra
/* 86EA4 800ED9F4 27BD0050 */   addiu    $sp, $sp, 0x50
