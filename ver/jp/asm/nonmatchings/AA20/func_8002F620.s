.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002F620
/* AA20 8002F620 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* AA24 8002F624 AFB00010 */  sw        $s0, 0x10($sp)
/* AA28 8002F628 0080802D */  daddu     $s0, $a0, $zero
/* AA2C 8002F62C AFBF0014 */  sw        $ra, 0x14($sp)
/* AA30 8002F630 F7BE0040 */  sdc1      $f30, 0x40($sp)
/* AA34 8002F634 F7BC0038 */  sdc1      $f28, 0x38($sp)
/* AA38 8002F638 F7BA0030 */  sdc1      $f26, 0x30($sp)
/* AA3C 8002F63C F7B80028 */  sdc1      $f24, 0x28($sp)
/* AA40 8002F640 F7B60020 */  sdc1      $f22, 0x20($sp)
/* AA44 8002F644 F7B40018 */  sdc1      $f20, 0x18($sp)
/* AA48 8002F648 86020006 */  lh        $v0, 6($s0)
/* AA4C 8002F64C 14400004 */  bnez      $v0, .L8002F660
/* AA50 8002F650 00000000 */   nop
/* AA54 8002F654 86020008 */  lh        $v0, 8($s0)
/* AA58 8002F658 10400013 */  beqz      $v0, .L8002F6A8
/* AA5C 8002F65C 00000000 */   nop
.L8002F660:
/* AA60 8002F660 C6000054 */  lwc1      $f0, 0x54($s0)
/* AA64 8002F664 C6020058 */  lwc1      $f2, 0x58($s0)
/* AA68 8002F668 C604005C */  lwc1      $f4, 0x5c($s0)
/* AA6C 8002F66C 24020064 */  addiu     $v0, $zero, 0x64
/* AA70 8002F670 A6000006 */  sh        $zero, 6($s0)
/* AA74 8002F674 A6000008 */  sh        $zero, 8($s0)
/* AA78 8002F678 A600001C */  sh        $zero, 0x1c($s0)
/* AA7C 8002F67C A602001E */  sh        $v0, 0x1e($s0)
/* AA80 8002F680 A6020020 */  sh        $v0, 0x20($s0)
/* AA84 8002F684 A6000022 */  sh        $zero, 0x22($s0)
/* AA88 8002F688 A6000024 */  sh        $zero, 0x24($s0)
/* AA8C 8002F68C A6000026 */  sh        $zero, 0x26($s0)
/* AA90 8002F690 AE000060 */  sw        $zero, 0x60($s0)
/* AA94 8002F694 AE000064 */  sw        $zero, 0x64($s0)
/* AA98 8002F698 AE000068 */  sw        $zero, 0x68($s0)
/* AA9C 8002F69C E6000048 */  swc1      $f0, 0x48($s0)
/* AAA0 8002F6A0 E602004C */  swc1      $f2, 0x4c($s0)
/* AAA4 8002F6A4 E6040050 */  swc1      $f4, 0x50($s0)
.L8002F6A8:
/* AAA8 8002F6A8 8602001C */  lh        $v0, 0x1c($s0)
/* AAAC 8002F6AC 14400073 */  bnez      $v0, .L8002F87C
/* AAB0 8002F6B0 24022710 */   addiu    $v0, $zero, 0x2710
/* AAB4 8002F6B4 86030020 */  lh        $v1, 0x20($s0)
/* AAB8 8002F6B8 14600002 */  bnez      $v1, .L8002F6C4
/* AABC 8002F6BC 0043001A */   div      $zero, $v0, $v1
/* AAC0 8002F6C0 0007000D */  break     7
.L8002F6C4:
/* AAC4 8002F6C4 2401FFFF */   addiu    $at, $zero, -1
/* AAC8 8002F6C8 14610004 */  bne       $v1, $at, .L8002F6DC
/* AACC 8002F6CC 3C018000 */   lui      $at, 0x8000
/* AAD0 8002F6D0 14410002 */  bne       $v0, $at, .L8002F6DC
/* AAD4 8002F6D4 00000000 */   nop
/* AAD8 8002F6D8 0006000D */  break     6
.L8002F6DC:
/* AADC 8002F6DC 00001812 */   mflo     $v1
/* AAE0 8002F6E0 3C013F70 */  lui       $at, 0x3f70
/* AAE4 8002F6E4 44810800 */  mtc1      $at, $f1
/* AAE8 8002F6E8 44800000 */  mtc1      $zero, $f0
/* AAEC 8002F6EC C60A0054 */  lwc1      $f10, 0x54($s0)
/* AAF0 8002F6F0 C6020060 */  lwc1      $f2, 0x60($s0)
/* AAF4 8002F6F4 C6040064 */  lwc1      $f4, 0x64($s0)
/* AAF8 8002F6F8 C606005C */  lwc1      $f6, 0x5c($s0)
/* AAFC 8002F6FC 86020026 */  lh        $v0, 0x26($s0)
/* AB00 8002F700 46025280 */  add.s     $f10, $f10, $f2
/* AB04 8002F704 44824000 */  mtc1      $v0, $f8
/* AB08 8002F708 00000000 */  nop
/* AB0C 8002F70C 46804221 */  cvt.d.w   $f8, $f8
/* AB10 8002F710 86020024 */  lh        $v0, 0x24($s0)
/* AB14 8002F714 46204202 */  mul.d     $f8, $f8, $f0
/* AB18 8002F718 00000000 */  nop
/* AB1C 8002F71C 44820000 */  mtc1      $v0, $f0
/* AB20 8002F720 00000000 */  nop
/* AB24 8002F724 46800020 */  cvt.s.w   $f0, $f0
/* AB28 8002F728 E6000084 */  swc1      $f0, 0x84($s0)
/* AB2C 8002F72C C6000058 */  lwc1      $f0, 0x58($s0)
/* AB30 8002F730 86020022 */  lh        $v0, 0x22($s0)
/* AB34 8002F734 E60A0048 */  swc1      $f10, 0x48($s0)
/* AB38 8002F738 44821000 */  mtc1      $v0, $f2
/* AB3C 8002F73C 00000000 */  nop
/* AB40 8002F740 468010A0 */  cvt.s.w   $f2, $f2
/* AB44 8002F744 46040000 */  add.s     $f0, $f0, $f4
/* AB48 8002F748 E6020074 */  swc1      $f2, 0x74($s0)
/* AB4C 8002F74C C6020068 */  lwc1      $f2, 0x68($s0)
/* AB50 8002F750 8602001E */  lh        $v0, 0x1e($s0)
/* AB54 8002F754 46023180 */  add.s     $f6, $f6, $f2
/* AB58 8002F758 44822000 */  mtc1      $v0, $f4
/* AB5C 8002F75C 00000000 */  nop
/* AB60 8002F760 46802120 */  cvt.s.w   $f4, $f4
/* AB64 8002F764 46000021 */  cvt.d.s   $f0, $f0
/* AB68 8002F768 46280000 */  add.d     $f0, $f0, $f8
/* AB6C 8002F76C E6040078 */  swc1      $f4, 0x78($s0)
/* AB70 8002F770 E6060050 */  swc1      $f6, 0x50($s0)
/* AB74 8002F774 46200020 */  cvt.s.d   $f0, $f0
/* AB78 8002F778 04610002 */  bgez      $v1, .L8002F784
/* AB7C 8002F77C E600004C */   swc1     $f0, 0x4c($s0)
/* AB80 8002F780 24630003 */  addiu     $v1, $v1, 3
.L8002F784:
/* AB84 8002F784 C6020074 */  lwc1      $f2, 0x74($s0)
/* AB88 8002F788 3C0140C9 */  lui       $at, 0x40c9
/* AB8C 8002F78C 34210FD0 */  ori       $at, $at, 0xfd0
/* AB90 8002F790 4481A000 */  mtc1      $at, $f20
/* AB94 8002F794 00031083 */  sra       $v0, $v1, 2
/* AB98 8002F798 46141082 */  mul.s     $f2, $f2, $f20
/* AB9C 8002F79C 00000000 */  nop
/* ABA0 8002F7A0 4480F000 */  mtc1      $zero, $f30
/* ABA4 8002F7A4 3C0143B4 */  lui       $at, 0x43b4
/* ABA8 8002F7A8 4481B000 */  mtc1      $at, $f22
/* ABAC 8002F7AC 44820000 */  mtc1      $v0, $f0
/* ABB0 8002F7B0 00000000 */  nop
/* ABB4 8002F7B4 46800020 */  cvt.s.w   $f0, $f0
/* ABB8 8002F7B8 E6000018 */  swc1      $f0, 0x18($s0)
/* ABBC 8002F7BC 46161683 */  div.s     $f26, $f2, $f22
/* ABC0 8002F7C0 0C00A84B */  jal       func_8002A12C
/* ABC4 8002F7C4 4600D306 */   mov.s    $f12, $f26
/* ABC8 8002F7C8 46000706 */  mov.s     $f28, $f0
/* ABCC 8002F7CC 0C00A864 */  jal       func_8002A190
/* ABD0 8002F7D0 4600D306 */   mov.s    $f12, $f26
/* ABD4 8002F7D4 461E0202 */  mul.s     $f8, $f0, $f30
/* ABD8 8002F7D8 00000000 */  nop
/* ABDC 8002F7DC 4600F087 */  neg.s     $f2, $f30
/* ABE0 8002F7E0 4602E082 */  mul.s     $f2, $f28, $f2
/* ABE4 8002F7E4 00000000 */  nop
/* ABE8 8002F7E8 C6180078 */  lwc1      $f24, 0x78($s0)
/* ABEC 8002F7EC 461CC102 */  mul.s     $f4, $f24, $f28
/* ABF0 8002F7F0 00000000 */  nop
/* ABF4 8002F7F4 4600C182 */  mul.s     $f6, $f24, $f0
/* ABF8 8002F7F8 00000000 */  nop
/* ABFC 8002F7FC C6000084 */  lwc1      $f0, 0x84($s0)
/* AC00 8002F800 46140002 */  mul.s     $f0, $f0, $f20
/* AC04 8002F804 00000000 */  nop
/* AC08 8002F808 4600F286 */  mov.s     $f10, $f30
/* AC0C 8002F80C 46005506 */  mov.s     $f20, $f10
/* AC10 8002F810 46044780 */  add.s     $f30, $f8, $f4
/* AC14 8002F814 46061600 */  add.s     $f24, $f2, $f6
/* AC18 8002F818 46160683 */  div.s     $f26, $f0, $f22
/* AC1C 8002F81C 0C00A84B */  jal       func_8002A12C
/* AC20 8002F820 4600D306 */   mov.s    $f12, $f26
/* AC24 8002F824 46000706 */  mov.s     $f28, $f0
/* AC28 8002F828 0C00A864 */  jal       func_8002A190
/* AC2C 8002F82C 4600D306 */   mov.s    $f12, $f26
/* AC30 8002F830 46140182 */  mul.s     $f6, $f0, $f20
/* AC34 8002F834 00000000 */  nop
/* AC38 8002F838 4614E102 */  mul.s     $f4, $f28, $f20
/* AC3C 8002F83C 00000000 */  nop
/* AC40 8002F840 461CC082 */  mul.s     $f2, $f24, $f28
/* AC44 8002F844 00000000 */  nop
/* AC48 8002F848 4600C002 */  mul.s     $f0, $f24, $f0
/* AC4C 8002F84C 00000000 */  nop
/* AC50 8002F850 46023281 */  sub.s     $f10, $f6, $f2
/* AC54 8002F854 46002100 */  add.s     $f4, $f4, $f0
/* AC58 8002F858 C600004C */  lwc1      $f0, 0x4c($s0)
/* AC5C 8002F85C 461E0000 */  add.s     $f0, $f0, $f30
/* AC60 8002F860 C6060048 */  lwc1      $f6, 0x48($s0)
/* AC64 8002F864 460A3180 */  add.s     $f6, $f6, $f10
/* AC68 8002F868 C6020050 */  lwc1      $f2, 0x50($s0)
/* AC6C 8002F86C 46041080 */  add.s     $f2, $f2, $f4
/* AC70 8002F870 E6000040 */  swc1      $f0, 0x40($s0)
/* AC74 8002F874 E606003C */  swc1      $f6, 0x3c($s0)
/* AC78 8002F878 E6020044 */  swc1      $f2, 0x44($s0)
.L8002F87C:
/* AC7C 8002F87C C60C003C */  lwc1      $f12, 0x3c($s0)
/* AC80 8002F880 C60E0044 */  lwc1      $f14, 0x44($s0)
/* AC84 8002F884 8E060048 */  lw        $a2, 0x48($s0)
/* AC88 8002F888 0C00A710 */  jal       func_80029C40
/* AC8C 8002F88C 8E070050 */   lw       $a3, 0x50($s0)
/* AC90 8002F890 C6040048 */  lwc1      $f4, 0x48($s0)
/* AC94 8002F894 4480B000 */  mtc1      $zero, $f22
/* AC98 8002F898 C602003C */  lwc1      $f2, 0x3c($s0)
/* AC9C 8002F89C E600006C */  swc1      $f0, 0x6c($s0)
/* ACA0 8002F8A0 46022501 */  sub.s     $f20, $f4, $f2
/* ACA4 8002F8A4 C6040050 */  lwc1      $f4, 0x50($s0)
/* ACA8 8002F8A8 C6020044 */  lwc1      $f2, 0x44($s0)
/* ACAC 8002F8AC 4600B306 */  mov.s     $f12, $f22
/* ACB0 8002F8B0 46022601 */  sub.s     $f24, $f4, $f2
/* ACB4 8002F8B4 C604004C */  lwc1      $f4, 0x4c($s0)
/* ACB8 8002F8B8 C6020040 */  lwc1      $f2, 0x40($s0)
/* ACBC 8002F8BC 4406A000 */  mfc1      $a2, $f20
/* ACC0 8002F8C0 46022781 */  sub.s     $f30, $f4, $f2
/* ACC4 8002F8C4 4407C000 */  mfc1      $a3, $f24
/* ACC8 8002F8C8 0C00A710 */  jal       func_80029C40
/* ACCC 8002F8CC 4600B386 */   mov.s    $f14, $f22
/* ACD0 8002F8D0 4614A102 */  mul.s     $f4, $f20, $f20
/* ACD4 8002F8D4 00000000 */  nop
/* ACD8 8002F8D8 4618C082 */  mul.s     $f2, $f24, $f24
/* ACDC 8002F8DC 00000000 */  nop
/* ACE0 8002F8E0 46022300 */  add.s     $f12, $f4, $f2
/* ACE4 8002F8E4 46000007 */  neg.s     $f0, $f0
/* ACE8 8002F8E8 E6000090 */  swc1      $f0, 0x90($s0)
/* ACEC 8002F8EC 46006004 */  sqrt.s    $f0, $f12
/* ACF0 8002F8F0 46000032 */  c.eq.s    $f0, $f0
/* ACF4 8002F8F4 00000000 */  nop
/* ACF8 8002F8F8 45030004 */  bc1tl     .L8002F90C
/* ACFC 8002F8FC 4600B306 */   mov.s    $f12, $f22
/* AD00 8002F900 0C0187B0 */  jal       func_80061EC0
/* AD04 8002F904 00000000 */   nop
/* AD08 8002F908 4600B306 */  mov.s     $f12, $f22
.L8002F90C:
/* AD0C 8002F90C 46000007 */  neg.s     $f0, $f0
/* AD10 8002F910 4406F000 */  mfc1      $a2, $f30
/* AD14 8002F914 44070000 */  mfc1      $a3, $f0
/* AD18 8002F918 0C00A710 */  jal       func_80029C40
/* AD1C 8002F91C 46006386 */   mov.s    $f14, $f12
/* AD20 8002F920 E6000094 */  swc1      $f0, 0x94($s0)
/* AD24 8002F924 C6000048 */  lwc1      $f0, 0x48($s0)
/* AD28 8002F928 3C02800E */  lui       $v0, %hi(D_800DC050)
/* AD2C 8002F92C 2442C050 */  addiu     $v0, $v0, %lo(D_800DC050)
/* AD30 8002F930 E44000CC */  swc1      $f0, 0xcc($v0)
/* AD34 8002F934 C600004C */  lwc1      $f0, 0x4c($s0)
/* AD38 8002F938 E44000D0 */  swc1      $f0, 0xd0($v0)
/* AD3C 8002F93C C6000050 */  lwc1      $f0, 0x50($s0)
/* AD40 8002F940 E44000D4 */  swc1      $f0, 0xd4($v0)
/* AD44 8002F944 8FBF0014 */  lw        $ra, 0x14($sp)
/* AD48 8002F948 8FB00010 */  lw        $s0, 0x10($sp)
/* AD4C 8002F94C D7BE0040 */  ldc1      $f30, 0x40($sp)
/* AD50 8002F950 D7BC0038 */  ldc1      $f28, 0x38($sp)
/* AD54 8002F954 D7BA0030 */  ldc1      $f26, 0x30($sp)
/* AD58 8002F958 D7B80028 */  ldc1      $f24, 0x28($sp)
/* AD5C 8002F95C D7B60020 */  ldc1      $f22, 0x20($sp)
/* AD60 8002F960 D7B40018 */  ldc1      $f20, 0x18($sp)
/* AD64 8002F964 03E00008 */  jr        $ra
/* AD68 8002F968 27BD0048 */   addiu    $sp, $sp, 0x48
/* AD6C 8002F96C 00000000 */  nop
