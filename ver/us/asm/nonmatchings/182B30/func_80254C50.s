.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel D_8029D350
.double 0.7142857142857143

.section .text

glabel func_80254C50
/* 183530 80254C50 27BDFCE8 */  addiu     $sp, $sp, -0x318
/* 183534 80254C54 AFBF02E4 */  sw        $ra, 0x2e4($sp)
/* 183538 80254C58 AFBE02E0 */  sw        $fp, 0x2e0($sp)
/* 18353C 80254C5C AFB702DC */  sw        $s7, 0x2dc($sp)
/* 183540 80254C60 AFB602D8 */  sw        $s6, 0x2d8($sp)
/* 183544 80254C64 AFB502D4 */  sw        $s5, 0x2d4($sp)
/* 183548 80254C68 AFB402D0 */  sw        $s4, 0x2d0($sp)
/* 18354C 80254C6C AFB302CC */  sw        $s3, 0x2cc($sp)
/* 183550 80254C70 AFB202C8 */  sw        $s2, 0x2c8($sp)
/* 183554 80254C74 AFB102C4 */  sw        $s1, 0x2c4($sp)
/* 183558 80254C78 AFB002C0 */  sw        $s0, 0x2c0($sp)
/* 18355C 80254C7C F7BE0310 */  sdc1      $f30, 0x310($sp)
/* 183560 80254C80 F7BC0308 */  sdc1      $f28, 0x308($sp)
/* 183564 80254C84 F7BA0300 */  sdc1      $f26, 0x300($sp)
/* 183568 80254C88 F7B802F8 */  sdc1      $f24, 0x2f8($sp)
/* 18356C 80254C8C F7B602F0 */  sdc1      $f22, 0x2f0($sp)
/* 183570 80254C90 F7B402E8 */  sdc1      $f20, 0x2e8($sp)
/* 183574 80254C94 AFA40318 */  sw        $a0, 0x318($sp)
/* 183578 80254C98 8C9201F4 */  lw        $s2, 0x1f4($a0)
/* 18357C 80254C9C 8E5700C0 */  lw        $s7, 0xc0($s2)
/* 183580 80254CA0 82E208AC */  lb        $v0, 0x8ac($s7)
/* 183584 80254CA4 92E308AC */  lbu       $v1, 0x8ac($s7)
/* 183588 80254CA8 1040000B */  beqz      $v0, .L80254CD8
/* 18358C 80254CAC 2462FFFF */   addiu    $v0, $v1, -1
/* 183590 80254CB0 A2E208AC */  sb        $v0, 0x8ac($s7)
/* 183594 80254CB4 00021600 */  sll       $v0, $v0, 0x18
/* 183598 80254CB8 14400007 */  bnez      $v0, .L80254CD8
/* 18359C 80254CBC 3C03EFFF */   lui      $v1, 0xefff
/* 1835A0 80254CC0 8FA80318 */  lw        $t0, 0x318($sp)
/* 1835A4 80254CC4 8D020000 */  lw        $v0, ($t0)
/* 1835A8 80254CC8 3463FFFF */  ori       $v1, $v1, 0xffff
/* 1835AC 80254CCC 00431024 */  and       $v0, $v0, $v1
/* 1835B0 80254CD0 0809541D */  j         .L80255074
/* 1835B4 80254CD4 AD020000 */   sw       $v0, ($t0)
.L80254CD8:
/* 1835B8 80254CD8 8E420000 */  lw        $v0, ($s2)
/* 1835BC 80254CDC 30420001 */  andi      $v0, $v0, 1
/* 1835C0 80254CE0 144000E4 */  bnez      $v0, .L80255074
/* 1835C4 80254CE4 00000000 */   nop
/* 1835C8 80254CE8 8E420094 */  lw        $v0, 0x94($s2)
/* 1835CC 80254CEC 104000E1 */  beqz      $v0, .L80255074
/* 1835D0 80254CF0 27A801D8 */   addiu    $t0, $sp, 0x1d8
/* 1835D4 80254CF4 AFA802A4 */  sw        $t0, 0x2a4($sp)
/* 1835D8 80254CF8 27A80158 */  addiu     $t0, $sp, 0x158
/* 1835DC 80254CFC AFA802A8 */  sw        $t0, 0x2a8($sp)
/* 1835E0 80254D00 27A80198 */  addiu     $t0, $sp, 0x198
/* 1835E4 80254D04 AFA802AC */  sw        $t0, 0x2ac($sp)
/* 1835E8 80254D08 27A80058 */  addiu     $t0, $sp, 0x58
/* 1835EC 80254D0C AFA802B0 */  sw        $t0, 0x2b0($sp)
/* 1835F0 80254D10 27A80098 */  addiu     $t0, $sp, 0x98
/* 1835F4 80254D14 27B50218 */  addiu     $s5, $sp, 0x218
/* 1835F8 80254D18 AFA802B4 */  sw        $t0, 0x2b4($sp)
/* 1835FC 80254D1C 27A800D8 */  addiu     $t0, $sp, 0xd8
/* 183600 80254D20 AFA802B8 */  sw        $t0, 0x2b8($sp)
/* 183604 80254D24 27A80118 */  addiu     $t0, $sp, 0x118
/* 183608 80254D28 27BE0258 */  addiu     $fp, $sp, 0x258
/* 18360C 80254D2C AFA00298 */  sw        $zero, 0x298($sp)
/* 183610 80254D30 AFA0029C */  sw        $zero, 0x29c($sp)
/* 183614 80254D34 AFA802BC */  sw        $t0, 0x2bc($sp)
/* 183618 80254D38 82F307D9 */  lb        $s3, 0x7d9($s7)
/* 18361C 80254D3C 4480A000 */  mtc1      $zero, $f20
/* 183620 80254D40 3C013F80 */  lui       $at, 0x3f80
/* 183624 80254D44 4481F000 */  mtc1      $at, $f30
/* 183628 80254D48 3C01802A */  lui       $at, %hi(D_8029D350)
/* 18362C 80254D4C D43CD350 */  ldc1      $f28, %lo(D_8029D350)($at)
.L80254D50:
/* 183630 80254D50 8FA80298 */  lw        $t0, 0x298($sp)
/* 183634 80254D54 2673FFFF */  addiu     $s3, $s3, -1
.L80254D58:
/* 183638 80254D58 25080001 */  addiu     $t0, $t0, 1
/* 18363C 80254D5C 06610002 */  bgez      $s3, .L80254D68
/* 183640 80254D60 AFA80298 */   sw       $t0, 0x298($sp)
/* 183644 80254D64 2413000F */  addiu     $s3, $zero, 0xf
.L80254D68:
/* 183648 80254D68 82E207D9 */  lb        $v0, 0x7d9($s7)
/* 18364C 80254D6C 126200C1 */  beq       $s3, $v0, .L80255074
/* 183650 80254D70 00000000 */   nop
/* 183654 80254D74 8FA80298 */  lw        $t0, 0x298($sp)
/* 183658 80254D78 29020003 */  slti      $v0, $t0, 3
/* 18365C 80254D7C 5440FFF6 */  bnel      $v0, $zero, .L80254D58
/* 183660 80254D80 2673FFFF */   addiu    $s3, $s3, -1
/* 183664 80254D84 8FA8029C */  lw        $t0, 0x29c($sp)
/* 183668 80254D88 AFA00298 */  sw        $zero, 0x298($sp)
/* 18366C 80254D8C 82E207DA */  lb        $v0, 0x7da($s7)
/* 183670 80254D90 25080001 */  addiu     $t0, $t0, 1
/* 183674 80254D94 0048102A */  slt       $v0, $v0, $t0
/* 183678 80254D98 144000B6 */  bnez      $v0, .L80255074
/* 18367C 80254D9C AFA8029C */   sw       $t0, 0x29c($sp)
/* 183680 80254DA0 24160078 */  addiu     $s6, $zero, 0x78
/* 183684 80254DA4 00132840 */  sll       $a1, $s3, 1
/* 183688 80254DA8 02E52821 */  addu      $a1, $s7, $a1
/* 18368C 80254DAC 02F32021 */  addu      $a0, $s7, $s3
/* 183690 80254DB0 84A207FC */  lh        $v0, 0x7fc($a1)
/* 183694 80254DB4 84A3081C */  lh        $v1, 0x81c($a1)
/* 183698 80254DB8 44821000 */  mtc1      $v0, $f2
/* 18369C 80254DBC 00000000 */  nop
/* 1836A0 80254DC0 468010A0 */  cvt.s.w   $f2, $f2
/* 1836A4 80254DC4 44832000 */  mtc1      $v1, $f4
/* 1836A8 80254DC8 00000000 */  nop
/* 1836AC 80254DCC 46802120 */  cvt.s.w   $f4, $f4
/* 1836B0 80254DD0 84A3083C */  lh        $v1, 0x83c($a1)
/* 1836B4 80254DD4 9082087C */  lbu       $v0, 0x87c($a0)
/* 1836B8 80254DD8 84A507DC */  lh        $a1, 0x7dc($a1)
/* 1836BC 80254DDC 44830000 */  mtc1      $v1, $f0
/* 1836C0 80254DE0 00000000 */  nop
/* 1836C4 80254DE4 46800020 */  cvt.s.w   $f0, $f0
/* 1836C8 80254DE8 00021040 */  sll       $v0, $v0, 1
/* 1836CC 80254DEC 4482B000 */  mtc1      $v0, $f22
/* 1836D0 80254DF0 00000000 */  nop
/* 1836D4 80254DF4 4680B5A0 */  cvt.s.w   $f22, $f22
/* 1836D8 80254DF8 9083088C */  lbu       $v1, 0x88c($a0)
/* 1836DC 80254DFC 9082089C */  lbu       $v0, 0x89c($a0)
/* 1836E0 80254E00 00031840 */  sll       $v1, $v1, 1
/* 1836E4 80254E04 4483C000 */  mtc1      $v1, $f24
/* 1836E8 80254E08 00000000 */  nop
/* 1836EC 80254E0C 4680C620 */  cvt.s.w   $f24, $f24
/* 1836F0 80254E10 00021040 */  sll       $v0, $v0, 1
/* 1836F4 80254E14 86430098 */  lh        $v1, 0x98($s2)
/* 1836F8 80254E18 4482D000 */  mtc1      $v0, $f26
/* 1836FC 80254E1C 00000000 */  nop
/* 183700 80254E20 4680D6A0 */  cvt.s.w   $f26, $f26
/* 183704 80254E24 AFA502A0 */  sw        $a1, 0x2a0($sp)
/* 183708 80254E28 8090085C */  lb        $s0, 0x85c($a0)
/* 18370C 80254E2C 8091086C */  lb        $s1, 0x86c($a0)
/* 183710 80254E30 28620032 */  slti      $v0, $v1, 0x32
/* 183714 80254E34 10400004 */  beqz      $v0, .L80254E48
/* 183718 80254E38 24140014 */   addiu    $s4, $zero, 0x14
/* 18371C 80254E3C 24160032 */  addiu     $s6, $zero, 0x32
/* 183720 80254E40 0809539C */  j         .L80254E70
/* 183724 80254E44 24140008 */   addiu    $s4, $zero, 8
.L80254E48:
/* 183728 80254E48 28620064 */  slti      $v0, $v1, 0x64
/* 18372C 80254E4C 10400004 */  beqz      $v0, .L80254E60
/* 183730 80254E50 28620096 */   slti     $v0, $v1, 0x96
/* 183734 80254E54 24160046 */  addiu     $s6, $zero, 0x46
/* 183738 80254E58 0809539C */  j         .L80254E70
/* 18373C 80254E5C 2414000A */   addiu    $s4, $zero, 0xa
.L80254E60:
/* 183740 80254E60 10400003 */  beqz      $v0, .L80254E70
/* 183744 80254E64 00000000 */   nop
/* 183748 80254E68 24160064 */  addiu     $s6, $zero, 0x64
/* 18374C 80254E6C 2414000F */  addiu     $s4, $zero, 0xf
.L80254E70:
/* 183750 80254E70 44051000 */  mfc1      $a1, $f2
/* 183754 80254E74 44062000 */  mfc1      $a2, $f4
/* 183758 80254E78 44070000 */  mfc1      $a3, $f0
/* 18375C 80254E7C 0C019E40 */  jal       guTranslateF
/* 183760 80254E80 8FA402A4 */   lw       $a0, 0x2a4($sp)
/* 183764 80254E84 00101023 */  negu      $v0, $s0
/* 183768 80254E88 44824000 */  mtc1      $v0, $f8
/* 18376C 80254E8C 00000000 */  nop
/* 183770 80254E90 46804220 */  cvt.s.w   $f8, $f8
/* 183774 80254E94 00111023 */  negu      $v0, $s1
/* 183778 80254E98 44054000 */  mfc1      $a1, $f8
/* 18377C 80254E9C 44824000 */  mtc1      $v0, $f8
/* 183780 80254EA0 00000000 */  nop
/* 183784 80254EA4 46804220 */  cvt.s.w   $f8, $f8
/* 183788 80254EA8 8FA402A8 */  lw        $a0, 0x2a8($sp)
/* 18378C 80254EAC 4407A000 */  mfc1      $a3, $f20
/* 183790 80254EB0 44064000 */  mfc1      $a2, $f8
/* 183794 80254EB4 0C019E40 */  jal       guTranslateF
/* 183798 80254EB8 00000000 */   nop
/* 18379C 80254EBC 44904000 */  mtc1      $s0, $f8
/* 1837A0 80254EC0 00000000 */  nop
/* 1837A4 80254EC4 46804220 */  cvt.s.w   $f8, $f8
/* 1837A8 80254EC8 44054000 */  mfc1      $a1, $f8
/* 1837AC 80254ECC 44914000 */  mtc1      $s1, $f8
/* 1837B0 80254ED0 00000000 */  nop
/* 1837B4 80254ED4 46804220 */  cvt.s.w   $f8, $f8
/* 1837B8 80254ED8 8FA402AC */  lw        $a0, 0x2ac($sp)
/* 1837BC 80254EDC 4407A000 */  mfc1      $a3, $f20
/* 1837C0 80254EE0 44064000 */  mfc1      $a2, $f8
/* 1837C4 80254EE4 0C019E40 */  jal       guTranslateF
/* 1837C8 80254EE8 00000000 */   nop
/* 1837CC 80254EEC 4405B000 */  mfc1      $a1, $f22
/* 1837D0 80254EF0 4406F000 */  mfc1      $a2, $f30
/* 1837D4 80254EF4 4407A000 */  mfc1      $a3, $f20
/* 1837D8 80254EF8 27A40018 */  addiu     $a0, $sp, 0x18
/* 1837DC 80254EFC 0C019EC8 */  jal       guRotateF
/* 1837E0 80254F00 E7B40010 */   swc1     $f20, 0x10($sp)
/* 1837E4 80254F04 4405C000 */  mfc1      $a1, $f24
/* 1837E8 80254F08 4406A000 */  mfc1      $a2, $f20
/* 1837EC 80254F0C 4407F000 */  mfc1      $a3, $f30
/* 1837F0 80254F10 8FA402B0 */  lw        $a0, 0x2b0($sp)
/* 1837F4 80254F14 0C019EC8 */  jal       guRotateF
/* 1837F8 80254F18 E7B40010 */   swc1     $f20, 0x10($sp)
/* 1837FC 80254F1C 4405D000 */  mfc1      $a1, $f26
/* 183800 80254F20 4406A000 */  mfc1      $a2, $f20
/* 183804 80254F24 4407A000 */  mfc1      $a3, $f20
/* 183808 80254F28 8FA402B4 */  lw        $a0, 0x2b4($sp)
/* 18380C 80254F2C 0C019EC8 */  jal       guRotateF
/* 183810 80254F30 E7BE0010 */   swc1     $f30, 0x10($sp)
/* 183814 80254F34 27A40018 */  addiu     $a0, $sp, 0x18
/* 183818 80254F38 8FA502B0 */  lw        $a1, 0x2b0($sp)
/* 18381C 80254F3C 0C019D80 */  jal       guMtxCatF
/* 183820 80254F40 02A0302D */   daddu    $a2, $s5, $zero
/* 183824 80254F44 8FA502B4 */  lw        $a1, 0x2b4($sp)
/* 183828 80254F48 8FA602B8 */  lw        $a2, 0x2b8($sp)
/* 18382C 80254F4C 0C019D80 */  jal       guMtxCatF
/* 183830 80254F50 02A0202D */   daddu    $a0, $s5, $zero
/* 183834 80254F54 8FA80318 */  lw        $t0, 0x318($sp)
/* 183838 80254F58 C5060170 */  lwc1      $f6, 0x170($t0)
/* 18383C 80254F5C 460031A1 */  cvt.d.s   $f6, $f6
/* 183840 80254F60 463C3182 */  mul.d     $f6, $f6, $f28
/* 183844 80254F64 00000000 */  nop
/* 183848 80254F68 C5040174 */  lwc1      $f4, 0x174($t0)
/* 18384C 80254F6C 46002121 */  cvt.d.s   $f4, $f4
/* 183850 80254F70 463C2102 */  mul.d     $f4, $f4, $f28
/* 183854 80254F74 00000000 */  nop
/* 183858 80254F78 C5020178 */  lwc1      $f2, 0x178($t0)
/* 18385C 80254F7C 460010A1 */  cvt.d.s   $f2, $f2
/* 183860 80254F80 463C1082 */  mul.d     $f2, $f2, $f28
/* 183864 80254F84 00000000 */  nop
/* 183868 80254F88 C5000188 */  lwc1      $f0, 0x188($t0)
/* 18386C 80254F8C 46000021 */  cvt.d.s   $f0, $f0
/* 183870 80254F90 46203182 */  mul.d     $f6, $f6, $f0
/* 183874 80254F94 00000000 */  nop
/* 183878 80254F98 46202102 */  mul.d     $f4, $f4, $f0
/* 18387C 80254F9C 00000000 */  nop
/* 183880 80254FA0 82420074 */  lb        $v0, 0x74($s2)
/* 183884 80254FA4 44820000 */  mtc1      $v0, $f0
/* 183888 80254FA8 00000000 */  nop
/* 18388C 80254FAC 46800021 */  cvt.d.w   $f0, $f0
/* 183890 80254FB0 46202102 */  mul.d     $f4, $f4, $f0
/* 183894 80254FB4 00000000 */  nop
/* 183898 80254FB8 8FA402BC */  lw        $a0, 0x2bc($sp)
/* 18389C 80254FBC 462010A0 */  cvt.s.d   $f2, $f2
/* 1838A0 80254FC0 44071000 */  mfc1      $a3, $f2
/* 1838A4 80254FC4 462031A0 */  cvt.s.d   $f6, $f6
/* 1838A8 80254FC8 44053000 */  mfc1      $a1, $f6
/* 1838AC 80254FCC 46202120 */  cvt.s.d   $f4, $f4
/* 1838B0 80254FD0 44062000 */  mfc1      $a2, $f4
/* 1838B4 80254FD4 0C019DF0 */  jal       guScaleF
/* 1838B8 80254FD8 00000000 */   nop
/* 1838BC 80254FDC 8FA402BC */  lw        $a0, 0x2bc($sp)
/* 1838C0 80254FE0 8FA502A8 */  lw        $a1, 0x2a8($sp)
/* 1838C4 80254FE4 0C019D80 */  jal       guMtxCatF
/* 1838C8 80254FE8 03C0302D */   daddu    $a2, $fp, $zero
/* 1838CC 80254FEC 03C0202D */  daddu     $a0, $fp, $zero
/* 1838D0 80254FF0 8FA502B8 */  lw        $a1, 0x2b8($sp)
/* 1838D4 80254FF4 0C019D80 */  jal       guMtxCatF
/* 1838D8 80254FF8 02A0302D */   daddu    $a2, $s5, $zero
/* 1838DC 80254FFC 02A0202D */  daddu     $a0, $s5, $zero
/* 1838E0 80255000 8FA502AC */  lw        $a1, 0x2ac($sp)
/* 1838E4 80255004 0C019D80 */  jal       guMtxCatF
/* 1838E8 80255008 03C0302D */   daddu    $a2, $fp, $zero
/* 1838EC 8025500C 03C0202D */  daddu     $a0, $fp, $zero
/* 1838F0 80255010 8FA502A4 */  lw        $a1, 0x2a4($sp)
/* 1838F4 80255014 0C019D80 */  jal       guMtxCatF
/* 1838F8 80255018 02A0302D */   daddu    $a2, $s5, $zero
/* 1838FC 8025501C 8FA8029C */  lw        $t0, 0x29c($sp)
/* 183900 80255020 01140018 */  mult      $t0, $s4
/* 183904 80255024 86500098 */  lh        $s0, 0x98($s2)
/* 183908 80255028 00004012 */  mflo      $t0
/* 18390C 8025502C 02C81023 */  subu      $v0, $s6, $t0
/* 183910 80255030 A6420098 */  sh        $v0, 0x98($s2)
/* 183914 80255034 8FA802A0 */  lw        $t0, 0x2a0($sp)
/* 183918 80255038 250200B4 */  addiu     $v0, $t0, 0xb4
/* 18391C 8025503C 44826000 */  mtc1      $v0, $f12
/* 183920 80255040 00000000 */  nop
/* 183924 80255044 0C00A6C9 */  jal       clamp_angle
/* 183928 80255048 46806320 */   cvt.s.w  $f12, $f12
/* 18392C 8025504C 0000202D */  daddu     $a0, $zero, $zero
/* 183930 80255050 0240282D */  daddu     $a1, $s2, $zero
/* 183934 80255054 4600020D */  trunc.w.s $f8, $f0
/* 183938 80255058 44064000 */  mfc1      $a2, $f8
/* 18393C 8025505C 02A0382D */  daddu     $a3, $s5, $zero
/* 183940 80255060 24020001 */  addiu     $v0, $zero, 1
/* 183944 80255064 0C09647B */  jal       func_802591EC
/* 183948 80255068 AFA20010 */   sw       $v0, 0x10($sp)
/* 18394C 8025506C 08095354 */  j         .L80254D50
/* 183950 80255070 A6500098 */   sh       $s0, 0x98($s2)
.L80255074:
/* 183954 80255074 8FBF02E4 */  lw        $ra, 0x2e4($sp)
/* 183958 80255078 8FBE02E0 */  lw        $fp, 0x2e0($sp)
/* 18395C 8025507C 8FB702DC */  lw        $s7, 0x2dc($sp)
/* 183960 80255080 8FB602D8 */  lw        $s6, 0x2d8($sp)
/* 183964 80255084 8FB502D4 */  lw        $s5, 0x2d4($sp)
/* 183968 80255088 8FB402D0 */  lw        $s4, 0x2d0($sp)
/* 18396C 8025508C 8FB302CC */  lw        $s3, 0x2cc($sp)
/* 183970 80255090 8FB202C8 */  lw        $s2, 0x2c8($sp)
/* 183974 80255094 8FB102C4 */  lw        $s1, 0x2c4($sp)
/* 183978 80255098 8FB002C0 */  lw        $s0, 0x2c0($sp)
/* 18397C 8025509C D7BE0310 */  ldc1      $f30, 0x310($sp)
/* 183980 802550A0 D7BC0308 */  ldc1      $f28, 0x308($sp)
/* 183984 802550A4 D7BA0300 */  ldc1      $f26, 0x300($sp)
/* 183988 802550A8 D7B802F8 */  ldc1      $f24, 0x2f8($sp)
/* 18398C 802550AC D7B602F0 */  ldc1      $f22, 0x2f0($sp)
/* 183990 802550B0 D7B402E8 */  ldc1      $f20, 0x2e8($sp)
/* 183994 802550B4 03E00008 */  jr        $ra
/* 183998 802550B8 27BD0318 */   addiu    $sp, $sp, 0x318
