.set noat      /* allow manual use of $at */
.set noreorder /* don't insert nops after branches */

glabel update_camera_mode_1
/* A9B0 8002F5B0 27BDFF90 */  addiu     $sp, $sp, -0x70
/* A9B4 8002F5B4 AFB10034 */  sw        $s1, 0x34($sp)
/* A9B8 8002F5B8 0080882D */  daddu     $s1, $a0, $zero
/* A9BC 8002F5BC AFBF0038 */  sw        $ra, 0x38($sp)
/* A9C0 8002F5C0 AFB00030 */  sw        $s0, 0x30($sp)
/* A9C4 8002F5C4 F7BE0068 */  sdc1      $f30, 0x68($sp)
/* A9C8 8002F5C8 F7BC0060 */  sdc1      $f28, 0x60($sp)
/* A9CC 8002F5CC F7BA0058 */  sdc1      $f26, 0x58($sp)
/* A9D0 8002F5D0 F7B80050 */  sdc1      $f24, 0x50($sp)
/* A9D4 8002F5D4 F7B60048 */  sdc1      $f22, 0x48($sp)
/* A9D8 8002F5D8 F7B40040 */  sdc1      $f20, 0x40($sp)
/* A9DC 8002F5DC 86220006 */  lh        $v0, 0x6($s1)
/* A9E0 8002F5E0 10400089 */  beqz      $v0, .LPAL_8002F808
/* A9E4 8002F5E4 00000000 */   nop
/* A9E8 8002F5E8 C63E0054 */  lwc1      $f30, 0x54($s1)
/* A9EC 8002F5EC C63C005C */  lwc1      $f28, 0x5C($s1)
/* A9F0 8002F5F0 C6380060 */  lwc1      $f24, 0x60($s1)
/* A9F4 8002F5F4 C6360068 */  lwc1      $f22, 0x68($s1)
/* A9F8 8002F5F8 8622001C */  lh        $v0, 0x1C($s1)
/* A9FC 8002F5FC 86230020 */  lh        $v1, 0x20($s1)
/* AA00 8002F600 3C108009 */  lui       $s0, %hi(D_8009A5EC)
/* AA04 8002F604 261069C0 */  addiu     $s0, $s0, %lo(D_8009A5EC)
/* AA08 8002F608 A6200006 */  sh        $zero, 0x6($s1)
/* AA0C 8002F60C 4600F306 */  mov.s     $f12, $f30
/* AA10 8002F610 4600E386 */  mov.s     $f14, $f28
/* AA14 8002F614 44820000 */  mtc1      $v0, $f0
/* AA18 8002F618 00000000 */  nop
/* AA1C 8002F61C 46800020 */  cvt.s.w   $f0, $f0
/* AA20 8002F620 00031040 */  sll       $v0, $v1, 1
/* AA24 8002F624 00431021 */  addu      $v0, $v0, $v1
/* AA28 8002F628 000210C0 */  sll       $v0, $v0, 3
/* AA2C 8002F62C 00431021 */  addu      $v0, $v0, $v1
/* AA30 8002F630 00021080 */  sll       $v0, $v0, 2
/* AA34 8002F634 E6200074 */  swc1      $f0, 0x74($s1)
/* AA38 8002F638 44820000 */  mtc1      $v0, $f0
/* AA3C 8002F63C 00000000 */  nop
/* AA40 8002F640 46800020 */  cvt.s.w   $f0, $f0
/* AA44 8002F644 4406C000 */  mfc1      $a2, $f24
/* AA48 8002F648 4407B000 */  mfc1      $a3, $f22
/* AA4C 8002F64C C6020000 */  lwc1      $f2, 0x0($s0)
/* AA50 8002F650 86230022 */  lh        $v1, 0x22($s1)
/* AA54 8002F654 46020003 */  div.s     $f0, $f0, $f2
/* AA58 8002F658 00031080 */  sll       $v0, $v1, 2
/* AA5C 8002F65C 00431021 */  addu      $v0, $v0, $v1
/* AA60 8002F660 00021080 */  sll       $v0, $v0, 2
/* AA64 8002F664 E6200078 */  swc1      $f0, 0x78($s1)
/* AA68 8002F668 44820000 */  mtc1      $v0, $f0
/* AA6C 8002F66C 00000000 */  nop
/* AA70 8002F670 46800020 */  cvt.s.w   $f0, $f0
/* AA74 8002F674 46020003 */  div.s     $f0, $f0, $f2
/* AA78 8002F678 0C00A700 */  jal       atan2
/* AA7C 8002F67C E620007C */   swc1     $f0, 0x7C($s1)
/* AA80 8002F680 46000506 */  mov.s     $f20, $f0
/* AA84 8002F684 4600F306 */  mov.s     $f12, $f30
/* AA88 8002F688 4406C000 */  mfc1      $a2, $f24
/* AA8C 8002F68C 4407B000 */  mfc1      $a3, $f22
/* AA90 8002F690 0C00A795 */  jal       dist2D
/* AA94 8002F694 4600E386 */   mov.s    $f14, $f28
/* AA98 8002F698 8623001E */  lh        $v1, 0x1E($s1)
/* AA9C 8002F69C C6040000 */  lwc1      $f4, 0x0($s0)
/* AAA0 8002F6A0 00031040 */  sll       $v0, $v1, 1
/* AAA4 8002F6A4 00431021 */  addu      $v0, $v0, $v1
/* AAA8 8002F6A8 000210C0 */  sll       $v0, $v0, 3
/* AAAC 8002F6AC 00431021 */  addu      $v0, $v0, $v1
/* AAB0 8002F6B0 00021080 */  sll       $v0, $v0, 2
/* AAB4 8002F6B4 44821000 */  mtc1      $v0, $f2
/* AAB8 8002F6B8 00000000 */  nop
/* AABC 8002F6BC 468010A0 */  cvt.s.w   $f2, $f2
/* AAC0 8002F6C0 46041083 */  div.s     $f2, $f2, $f4
/* AAC4 8002F6C4 4602003C */  c.lt.s    $f0, $f2
/* AAC8 8002F6C8 00000000 */  nop
/* AACC 8002F6CC 45020004 */  bc1fl     .LPAL_8002F6E0
/* AAD0 8002F6D0 E6340084 */   swc1     $f20, 0x84($s1)
/* AAD4 8002F6D4 C6340084 */  lwc1      $f20, 0x84($s1)
/* AAD8 8002F6D8 0800BDB9 */  j         .LPAL_8002F6E4
/* AADC 8002F6DC AFA00010 */   sw       $zero, 0x10($sp)
.LPAL_8002F6E0:
/* AAE0 8002F6E0 AFA00010 */  sw        $zero, 0x10($sp)
.LPAL_8002F6E4:
/* AAE4 8002F6E4 C6220074 */  lwc1      $f2, 0x74($s1)
/* AAE8 8002F6E8 C6280054 */  lwc1      $f8, 0x54($s1)
/* AAEC 8002F6EC 3C0140C9 */  lui       $at, (0x40C90FD0 >> 16)
/* AAF0 8002F6F0 34210FD0 */  ori       $at, $at, (0x40C90FD0 & 0xFFFF)
/* AAF4 8002F6F4 44815000 */  mtc1      $at, $f10
/* AAF8 8002F6F8 C6200058 */  lwc1      $f0, 0x58($s1)
/* AAFC 8002F6FC C624007C */  lwc1      $f4, 0x7C($s1)
/* AB00 8002F700 460A1082 */  mul.s     $f2, $f2, $f10
/* AB04 8002F704 00000000 */  nop
/* AB08 8002F708 C626005C */  lwc1      $f6, 0x5C($s1)
/* AB0C 8002F70C 3C0143B4 */  lui       $at, (0x43B40000 >> 16)
/* AB10 8002F710 4481B000 */  mtc1      $at, $f22
/* AB14 8002F714 E6340088 */  swc1      $f20, 0x88($s1)
/* AB18 8002F718 46040000 */  add.s     $f0, $f0, $f4
/* AB1C 8002F71C E6280048 */  swc1      $f8, 0x48($s1)
/* AB20 8002F720 E6260050 */  swc1      $f6, 0x50($s1)
/* AB24 8002F724 E620004C */  swc1      $f0, 0x4C($s1)
/* AB28 8002F728 46161603 */  div.s     $f24, $f2, $f22
/* AB2C 8002F72C 0C00A83B */  jal       sin_rad
/* AB30 8002F730 4600C306 */   mov.s    $f12, $f24
/* AB34 8002F734 46000686 */  mov.s     $f26, $f0
/* AB38 8002F738 0C00A854 */  jal       cos_rad
/* AB3C 8002F73C 4600C306 */   mov.s    $f12, $f24
/* AB40 8002F740 C7B00010 */  lwc1      $f16, 0x10($sp)
/* AB44 8002F744 46000206 */  mov.s     $f8, $f0
/* AB48 8002F748 46104182 */  mul.s     $f6, $f8, $f16
/* AB4C 8002F74C 00000000 */  nop
/* AB50 8002F750 C63C0078 */  lwc1      $f28, 0x78($s1)
/* AB54 8002F754 461AE082 */  mul.s     $f2, $f28, $f26
/* AB58 8002F758 00000000 */  nop
/* AB5C 8002F75C 46008007 */  neg.s     $f0, $f16
/* AB60 8002F760 4600D002 */  mul.s     $f0, $f26, $f0
/* AB64 8002F764 00000000 */  nop
/* AB68 8002F768 4608E102 */  mul.s     $f4, $f28, $f8
/* AB6C 8002F76C 00000000 */  nop
/* AB70 8002F770 3C0140C9 */  lui       $at, (0x40C90FD0 >> 16)
/* AB74 8002F774 34210FD0 */  ori       $at, $at, (0x40C90FD0 & 0xFFFF)
/* AB78 8002F778 44815000 */  mtc1      $at, $f10
/* AB7C 8002F77C 00000000 */  nop
/* AB80 8002F780 460AA282 */  mul.s     $f10, $f20, $f10
/* AB84 8002F784 00000000 */  nop
/* AB88 8002F788 46008606 */  mov.s     $f24, $f16
/* AB8C 8002F78C 4600C786 */  mov.s     $f30, $f24
/* AB90 8002F790 46023180 */  add.s     $f6, $f6, $f2
/* AB94 8002F794 46165603 */  div.s     $f24, $f10, $f22
/* AB98 8002F798 4600C306 */  mov.s     $f12, $f24
/* AB9C 8002F79C 46040700 */  add.s     $f28, $f0, $f4
/* ABA0 8002F7A0 0C00A83B */  jal       sin_rad
/* ABA4 8002F7A4 E7A60010 */   swc1     $f6, 0x10($sp)
/* ABA8 8002F7A8 46000686 */  mov.s     $f26, $f0
/* ABAC 8002F7AC 0C00A854 */  jal       cos_rad
/* ABB0 8002F7B0 4600C306 */   mov.s    $f12, $f24
/* ABB4 8002F7B4 46000206 */  mov.s     $f8, $f0
/* ABB8 8002F7B8 461E4182 */  mul.s     $f6, $f8, $f30
/* ABBC 8002F7BC 00000000 */  nop
/* ABC0 8002F7C0 461AE082 */  mul.s     $f2, $f28, $f26
/* ABC4 8002F7C4 00000000 */  nop
/* ABC8 8002F7C8 461ED102 */  mul.s     $f4, $f26, $f30
/* ABCC 8002F7CC 00000000 */  nop
/* ABD0 8002F7D0 4608E002 */  mul.s     $f0, $f28, $f8
/* ABD4 8002F7D4 00000000 */  nop
/* ABD8 8002F7D8 46023601 */  sub.s     $f24, $f6, $f2
/* ABDC 8002F7DC C7B00010 */  lwc1      $f16, 0x10($sp)
/* ABE0 8002F7E0 46002580 */  add.s     $f22, $f4, $f0
/* ABE4 8002F7E4 C620004C */  lwc1      $f0, 0x4C($s1)
/* ABE8 8002F7E8 46100000 */  add.s     $f0, $f0, $f16
/* ABEC 8002F7EC C6240048 */  lwc1      $f4, 0x48($s1)
/* ABF0 8002F7F0 46182100 */  add.s     $f4, $f4, $f24
/* ABF4 8002F7F4 C6220050 */  lwc1      $f2, 0x50($s1)
/* ABF8 8002F7F8 46161080 */  add.s     $f2, $f2, $f22
/* ABFC 8002F7FC E6200040 */  swc1      $f0, 0x40($s1)
/* AC00 8002F800 E624003C */  swc1      $f4, 0x3C($s1)
/* AC04 8002F804 E6220044 */  swc1      $f2, 0x44($s1)
.LPAL_8002F808:
/* AC08 8002F808 C62A0054 */  lwc1      $f10, 0x54($s1)
/* AC0C 8002F80C 3C108009 */  lui       $s0, %hi(D_8009A5EC)
/* AC10 8002F810 261069C0 */  addiu     $s0, $s0, %lo(D_8009A5EC)
/* AC14 8002F814 E7AA0028 */  swc1      $f10, 0x28($sp)
/* AC18 8002F818 C632005C */  lwc1      $f18, 0x5C($s1)
/* AC1C 8002F81C C63E0054 */  lwc1      $f30, 0x54($s1)
/* AC20 8002F820 C6380060 */  lwc1      $f24, 0x60($s1)
/* AC24 8002F824 C6360068 */  lwc1      $f22, 0x68($s1)
/* AC28 8002F828 86230022 */  lh        $v1, 0x22($s1)
/* AC2C 8002F82C C6260058 */  lwc1      $f6, 0x58($s1)
/* AC30 8002F830 C60A0000 */  lwc1      $f10, 0x0($s0)
/* AC34 8002F834 C6280048 */  lwc1      $f8, 0x48($s1)
/* AC38 8002F838 46009706 */  mov.s     $f28, $f18
/* AC3C 8002F83C 00031080 */  sll       $v0, $v1, 2
/* AC40 8002F840 00431021 */  addu      $v0, $v0, $v1
/* AC44 8002F844 00021080 */  sll       $v0, $v0, 2
/* AC48 8002F848 44828000 */  mtc1      $v0, $f16
/* AC4C 8002F84C 00000000 */  nop
/* AC50 8002F850 46808420 */  cvt.s.w   $f16, $f16
/* AC54 8002F854 460A8283 */  div.s     $f10, $f16, $f10
/* AC58 8002F858 4600F306 */  mov.s     $f12, $f30
/* AC5C 8002F85C E62A007C */  swc1      $f10, 0x7C($s1)
/* AC60 8002F860 C7B00028 */  lwc1      $f16, 0x28($sp)
/* AC64 8002F864 4600E386 */  mov.s     $f14, $f28
/* AC68 8002F868 46088401 */  sub.s     $f16, $f16, $f8
/* AC6C 8002F86C 4406C000 */  mfc1      $a2, $f24
/* AC70 8002F870 4407B000 */  mfc1      $a3, $f22
/* AC74 8002F874 460A3180 */  add.s     $f6, $f6, $f10
/* AC78 8002F878 E7B00028 */  swc1      $f16, 0x28($sp)
/* AC7C 8002F87C C6200050 */  lwc1      $f0, 0x50($s1)
/* AC80 8002F880 8622001C */  lh        $v0, 0x1C($s1)
/* AC84 8002F884 46009481 */  sub.s     $f18, $f18, $f0
/* AC88 8002F888 44820000 */  mtc1      $v0, $f0
/* AC8C 8002F88C 00000000 */  nop
/* AC90 8002F890 46800020 */  cvt.s.w   $f0, $f0
/* AC94 8002F894 E6200074 */  swc1      $f0, 0x74($s1)
/* AC98 8002F898 3C013F00 */  lui       $at, (0x3F000000 >> 16)
/* AC9C 8002F89C 44810000 */  mtc1      $at, $f0
/* ACA0 8002F8A0 86230020 */  lh        $v1, 0x20($s1)
/* ACA4 8002F8A4 46008282 */  mul.s     $f10, $f16, $f0
/* ACA8 8002F8A8 00000000 */  nop
/* ACAC 8002F8AC C622004C */  lwc1      $f2, 0x4C($s1)
/* ACB0 8002F8B0 00031040 */  sll       $v0, $v1, 1
/* ACB4 8002F8B4 00431021 */  addu      $v0, $v0, $v1
/* ACB8 8002F8B8 000210C0 */  sll       $v0, $v0, 3
/* ACBC 8002F8BC 46023181 */  sub.s     $f6, $f6, $f2
/* ACC0 8002F8C0 00431021 */  addu      $v0, $v0, $v1
/* ACC4 8002F8C4 00021080 */  sll       $v0, $v0, 2
/* ACC8 8002F8C8 46009482 */  mul.s     $f18, $f18, $f0
/* ACCC 8002F8CC 00000000 */  nop
/* ACD0 8002F8D0 3C014120 */  lui       $at, (0x41200000 >> 16)
/* ACD4 8002F8D4 44810000 */  mtc1      $at, $f0
/* ACD8 8002F8D8 44822000 */  mtc1      $v0, $f4
/* ACDC 8002F8DC 00000000 */  nop
/* ACE0 8002F8E0 46802120 */  cvt.s.w   $f4, $f4
/* ACE4 8002F8E4 46003183 */  div.s     $f6, $f6, $f0
/* ACE8 8002F8E8 46001006 */  mov.s     $f0, $f2
/* ACEC 8002F8EC 46060000 */  add.s     $f0, $f0, $f6
/* ACF0 8002F8F0 C6100000 */  lwc1      $f16, 0x0($s0)
/* ACF4 8002F8F4 C6220050 */  lwc1      $f2, 0x50($s1)
/* ACF8 8002F8F8 460A4200 */  add.s     $f8, $f8, $f10
/* ACFC 8002F8FC 46102103 */  div.s     $f4, $f4, $f16
/* AD00 8002F900 E6240078 */  swc1      $f4, 0x78($s1)
/* AD04 8002F904 46121080 */  add.s     $f2, $f2, $f18
/* AD08 8002F908 E620004C */  swc1      $f0, 0x4C($s1)
/* AD0C 8002F90C E6280048 */  swc1      $f8, 0x48($s1)
/* AD10 8002F910 0C00A700 */  jal       atan2
/* AD14 8002F914 E6220050 */   swc1     $f2, 0x50($s1)
/* AD18 8002F918 46000506 */  mov.s     $f20, $f0
/* AD1C 8002F91C 4600F306 */  mov.s     $f12, $f30
/* AD20 8002F920 4406C000 */  mfc1      $a2, $f24
/* AD24 8002F924 4407B000 */  mfc1      $a3, $f22
/* AD28 8002F928 0C00A795 */  jal       dist2D
/* AD2C 8002F92C 4600E386 */   mov.s    $f14, $f28
/* AD30 8002F930 8623001E */  lh        $v1, 0x1E($s1)
/* AD34 8002F934 C6040000 */  lwc1      $f4, 0x0($s0)
/* AD38 8002F938 00031040 */  sll       $v0, $v1, 1
/* AD3C 8002F93C 00431021 */  addu      $v0, $v0, $v1
/* AD40 8002F940 000210C0 */  sll       $v0, $v0, 3
/* AD44 8002F944 00431021 */  addu      $v0, $v0, $v1
/* AD48 8002F948 00021080 */  sll       $v0, $v0, 2
/* AD4C 8002F94C 44821000 */  mtc1      $v0, $f2
/* AD50 8002F950 00000000 */  nop
/* AD54 8002F954 468010A0 */  cvt.s.w   $f2, $f2
/* AD58 8002F958 46041083 */  div.s     $f2, $f2, $f4
/* AD5C 8002F95C 4602003C */  c.lt.s    $f0, $f2
/* AD60 8002F960 00000000 */  nop
/* AD64 8002F964 45020002 */  bc1fl     .LPAL_8002F970
/* AD68 8002F968 E6340084 */   swc1     $f20, 0x84($s1)
/* AD6C 8002F96C C6340084 */  lwc1      $f20, 0x84($s1)
.LPAL_8002F970:
/* AD70 8002F970 C62E0088 */  lwc1      $f14, 0x88($s1)
/* AD74 8002F974 0C00A6EA */  jal       get_clamped_angle_diff
/* AD78 8002F978 4600A306 */   mov.s    $f12, $f20
/* AD7C 8002F97C C6240074 */  lwc1      $f4, 0x74($s1)
/* AD80 8002F980 3C0140C9 */  lui       $at, (0x40C90FD0 >> 16)
/* AD84 8002F984 34210FD0 */  ori       $at, $at, (0x40C90FD0 & 0xFFFF)
/* AD88 8002F988 44815000 */  mtc1      $at, $f10
/* AD8C 8002F98C 3C014120 */  lui       $at, (0x41200000 >> 16)
/* AD90 8002F990 44811000 */  mtc1      $at, $f2
/* AD94 8002F994 460A2102 */  mul.s     $f4, $f4, $f10
/* AD98 8002F998 00000000 */  nop
/* AD9C 8002F99C 46020003 */  div.s     $f0, $f0, $f2
/* ADA0 8002F9A0 C6220088 */  lwc1      $f2, 0x88($s1)
/* ADA4 8002F9A4 3C0143B4 */  lui       $at, (0x43B40000 >> 16)
/* ADA8 8002F9A8 4481B000 */  mtc1      $at, $f22
/* ADAC 8002F9AC 46001081 */  sub.s     $f2, $f2, $f0
/* ADB0 8002F9B0 AFA00010 */  sw        $zero, 0x10($sp)
/* ADB4 8002F9B4 46001506 */  mov.s     $f20, $f2
/* ADB8 8002F9B8 E6340088 */  swc1      $f20, 0x88($s1)
/* ADBC 8002F9BC 46162603 */  div.s     $f24, $f4, $f22
/* ADC0 8002F9C0 0C00A83B */  jal       sin_rad
/* ADC4 8002F9C4 4600C306 */   mov.s    $f12, $f24
/* ADC8 8002F9C8 46000686 */  mov.s     $f26, $f0
/* ADCC 8002F9CC 0C00A854 */  jal       cos_rad
/* ADD0 8002F9D0 4600C306 */   mov.s    $f12, $f24
/* ADD4 8002F9D4 C7B00010 */  lwc1      $f16, 0x10($sp)
/* ADD8 8002F9D8 46000206 */  mov.s     $f8, $f0
/* ADDC 8002F9DC 46104182 */  mul.s     $f6, $f8, $f16
/* ADE0 8002F9E0 00000000 */  nop
/* ADE4 8002F9E4 C63C0078 */  lwc1      $f28, 0x78($s1)
/* ADE8 8002F9E8 461AE082 */  mul.s     $f2, $f28, $f26
/* ADEC 8002F9EC 00000000 */  nop
/* ADF0 8002F9F0 46008007 */  neg.s     $f0, $f16
/* ADF4 8002F9F4 4600D002 */  mul.s     $f0, $f26, $f0
/* ADF8 8002F9F8 00000000 */  nop
/* ADFC 8002F9FC 4608E102 */  mul.s     $f4, $f28, $f8
/* AE00 8002FA00 00000000 */  nop
/* AE04 8002FA04 3C0140C9 */  lui       $at, (0x40C90FD0 >> 16)
/* AE08 8002FA08 34210FD0 */  ori       $at, $at, (0x40C90FD0 & 0xFFFF)
/* AE0C 8002FA0C 44815000 */  mtc1      $at, $f10
/* AE10 8002FA10 00000000 */  nop
/* AE14 8002FA14 460AA282 */  mul.s     $f10, $f20, $f10
/* AE18 8002FA18 00000000 */  nop
/* AE1C 8002FA1C 46008606 */  mov.s     $f24, $f16
/* AE20 8002FA20 4600C786 */  mov.s     $f30, $f24
/* AE24 8002FA24 46023180 */  add.s     $f6, $f6, $f2
/* AE28 8002FA28 46165603 */  div.s     $f24, $f10, $f22
/* AE2C 8002FA2C 4600C306 */  mov.s     $f12, $f24
/* AE30 8002FA30 46040700 */  add.s     $f28, $f0, $f4
/* AE34 8002FA34 0C00A83B */  jal       sin_rad
/* AE38 8002FA38 E7A60010 */   swc1     $f6, 0x10($sp)
/* AE3C 8002FA3C 46000686 */  mov.s     $f26, $f0
/* AE40 8002FA40 0C00A854 */  jal       cos_rad
/* AE44 8002FA44 4600C306 */   mov.s    $f12, $f24
/* AE48 8002FA48 46000206 */  mov.s     $f8, $f0
/* AE4C 8002FA4C 461E4102 */  mul.s     $f4, $f8, $f30
/* AE50 8002FA50 00000000 */  nop
/* AE54 8002FA54 461AE002 */  mul.s     $f0, $f28, $f26
/* AE58 8002FA58 00000000 */  nop
/* AE5C 8002FA5C 461ED182 */  mul.s     $f6, $f26, $f30
/* AE60 8002FA60 00000000 */  nop
/* AE64 8002FA64 4608E082 */  mul.s     $f2, $f28, $f8
/* AE68 8002FA68 00000000 */  nop
/* AE6C 8002FA6C 46002601 */  sub.s     $f24, $f4, $f0
/* AE70 8002FA70 C7B00010 */  lwc1      $f16, 0x10($sp)
/* AE74 8002FA74 46023580 */  add.s     $f22, $f6, $f2
/* AE78 8002FA78 C622004C */  lwc1      $f2, 0x4C($s1)
/* AE7C 8002FA7C 46101080 */  add.s     $f2, $f2, $f16
/* AE80 8002FA80 C6200048 */  lwc1      $f0, 0x48($s1)
/* AE84 8002FA84 8E260048 */  lw        $a2, 0x48($s1)
/* AE88 8002FA88 46180000 */  add.s     $f0, $f0, $f24
/* AE8C 8002FA8C C62E0050 */  lwc1      $f14, 0x50($s1)
/* AE90 8002FA90 8E270050 */  lw        $a3, 0x50($s1)
/* AE94 8002FA94 46167380 */  add.s     $f14, $f14, $f22
/* AE98 8002FA98 E6220040 */  swc1      $f2, 0x40($s1)
/* AE9C 8002FA9C E620003C */  swc1      $f0, 0x3C($s1)
/* AEA0 8002FAA0 46000306 */  mov.s     $f12, $f0
/* AEA4 8002FAA4 0C00A700 */  jal       atan2
/* AEA8 8002FAA8 E62E0044 */   swc1     $f14, 0x44($s1)
/* AEAC 8002FAAC C6240048 */  lwc1      $f4, 0x48($s1)
/* AEB0 8002FAB0 C622003C */  lwc1      $f2, 0x3C($s1)
/* AEB4 8002FAB4 4480A000 */  mtc1      $zero, $f20
/* AEB8 8002FAB8 46022781 */  sub.s     $f30, $f4, $f2
/* AEBC 8002FABC C6240050 */  lwc1      $f4, 0x50($s1)
/* AEC0 8002FAC0 C6220044 */  lwc1      $f2, 0x44($s1)
/* AEC4 8002FAC4 4600A306 */  mov.s     $f12, $f20
/* AEC8 8002FAC8 46022701 */  sub.s     $f28, $f4, $f2
/* AECC 8002FACC C624004C */  lwc1      $f4, 0x4C($s1)
/* AED0 8002FAD0 C6220040 */  lwc1      $f2, 0x40($s1)
/* AED4 8002FAD4 4406F000 */  mfc1      $a2, $f30
/* AED8 8002FAD8 46022101 */  sub.s     $f4, $f4, $f2
/* AEDC 8002FADC 4407E000 */  mfc1      $a3, $f28
/* AEE0 8002FAE0 4600A386 */  mov.s     $f14, $f20
/* AEE4 8002FAE4 E7A40010 */  swc1      $f4, 0x10($sp)
/* AEE8 8002FAE8 0C00A700 */  jal       atan2
/* AEEC 8002FAEC E620006C */   swc1     $f0, 0x6C($s1)
/* AEF0 8002FAF0 461EF102 */  mul.s     $f4, $f30, $f30
/* AEF4 8002FAF4 00000000 */  nop
/* AEF8 8002FAF8 461CE082 */  mul.s     $f2, $f28, $f28
/* AEFC 8002FAFC 00000000 */  nop
/* AF00 8002FB00 46022300 */  add.s     $f12, $f4, $f2
/* AF04 8002FB04 46000007 */  neg.s     $f0, $f0
/* AF08 8002FB08 E6200090 */  swc1      $f0, 0x90($s1)
/* AF0C 8002FB0C 46006004 */  sqrt.s    $f0, $f12
/* AF10 8002FB10 46000032 */  c.eq.s    $f0, $f0
/* AF14 8002FB14 00000000 */  nop
/* AF18 8002FB18 45030004 */  bc1tl     .LPAL_8002FB2C
/* AF1C 8002FB1C 4600A306 */   mov.s    $f12, $f20
/* AF20 8002FB20 0C018B58 */  jal       sqrtf
/* AF24 8002FB24 00000000 */   nop
/* AF28 8002FB28 4600A306 */  mov.s     $f12, $f20
.LPAL_8002FB2C:
/* AF2C 8002FB2C 46000007 */  neg.s     $f0, $f0
/* AF30 8002FB30 8FA60010 */  lw        $a2, 0x10($sp)
/* AF34 8002FB34 44070000 */  mfc1      $a3, $f0
/* AF38 8002FB38 0C00A700 */  jal       atan2
/* AF3C 8002FB3C 46006386 */   mov.s    $f14, $f12
/* AF40 8002FB40 E6200094 */  swc1      $f0, 0x94($s1)
/* AF44 8002FB44 8FBF0038 */  lw        $ra, 0x38($sp)
/* AF48 8002FB48 8FB10034 */  lw        $s1, 0x34($sp)
/* AF4C 8002FB4C 8FB00030 */  lw        $s0, 0x30($sp)
/* AF50 8002FB50 D7BE0068 */  ldc1      $f30, 0x68($sp)
/* AF54 8002FB54 D7BC0060 */  ldc1      $f28, 0x60($sp)
/* AF58 8002FB58 D7BA0058 */  ldc1      $f26, 0x58($sp)
/* AF5C 8002FB5C D7B80050 */  ldc1      $f24, 0x50($sp)
/* AF60 8002FB60 D7B60048 */  ldc1      $f22, 0x48($sp)
/* AF64 8002FB64 D7B40040 */  ldc1      $f20, 0x40($sp)
/* AF68 8002FB68 03E00008 */  jr        $ra
/* AF6C 8002FB6C 27BD0070 */   addiu    $sp, $sp, 0x70
