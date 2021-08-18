.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel render_hud_elements_frontUI
/* D8E1C 8014271C 27BDFAB0 */  addiu     $sp, $sp, -0x550
/* D8E20 80142720 AFBE0548 */  sw        $fp, 0x548($sp)
/* D8E24 80142724 0000F02D */  daddu     $fp, $zero, $zero
/* D8E28 80142728 AFB70544 */  sw        $s7, 0x544($sp)
/* D8E2C 8014272C 03C0B82D */  daddu     $s7, $fp, $zero
/* D8E30 80142730 3C071021 */  lui       $a3, 0x1021
/* D8E34 80142734 34E70080 */  ori       $a3, $a3, 0x80
/* D8E38 80142738 27A60028 */  addiu     $a2, $sp, 0x28
/* D8E3C 8014273C 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* D8E40 80142740 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* D8E44 80142744 AFBF054C */  sw        $ra, 0x54c($sp)
/* D8E48 80142748 AFB60540 */  sw        $s6, 0x540($sp)
/* D8E4C 8014274C AFB5053C */  sw        $s5, 0x53c($sp)
/* D8E50 80142750 AFB40538 */  sw        $s4, 0x538($sp)
/* D8E54 80142754 AFB30534 */  sw        $s3, 0x534($sp)
/* D8E58 80142758 AFB20530 */  sw        $s2, 0x530($sp)
/* D8E5C 8014275C AFB1052C */  sw        $s1, 0x52c($sp)
/* D8E60 80142760 AFB00528 */  sw        $s0, 0x528($sp)
/* D8E64 80142764 8C620000 */  lw        $v0, ($v1)
/* D8E68 80142768 3C058015 */  lui       $a1, %hi(hudElements)
/* D8E6C 8014276C 8CA57960 */  lw        $a1, %lo(hudElements)($a1)
/* D8E70 80142770 0040202D */  daddu     $a0, $v0, $zero
/* D8E74 80142774 24420008 */  addiu     $v0, $v0, 8
/* D8E78 80142778 AC620000 */  sw        $v0, ($v1)
/* D8E7C 8014277C 3C02DE00 */  lui       $v0, 0xde00
/* D8E80 80142780 AC820000 */  sw        $v0, ($a0)
/* D8E84 80142784 3C020015 */  lui       $v0, 0x15
/* D8E88 80142788 2442F0A0 */  addiu     $v0, $v0, -0xf60
/* D8E8C 8014278C AC820004 */  sw        $v0, 4($a0)
.L80142790:
/* D8E90 80142790 8CB00000 */  lw        $s0, ($a1)
/* D8E94 80142794 52000014 */  beql      $s0, $zero, .L801427E8
/* D8E98 80142798 26F70001 */   addiu    $s7, $s7, 1
/* D8E9C 8014279C 8E030000 */  lw        $v1, ($s0)
/* D8EA0 801427A0 50600011 */  beql      $v1, $zero, .L801427E8
/* D8EA4 801427A4 26F70001 */   addiu    $s7, $s7, 1
/* D8EA8 801427A8 30620002 */  andi      $v0, $v1, 2
/* D8EAC 801427AC 5440000E */  bnel      $v0, $zero, .L801427E8
/* D8EB0 801427B0 26F70001 */   addiu    $s7, $s7, 1
/* D8EB4 801427B4 00671024 */  and       $v0, $v1, $a3
/* D8EB8 801427B8 5440000B */  bnel      $v0, $zero, .L801427E8
/* D8EBC 801427BC 26F70001 */   addiu    $s7, $s7, 1
/* D8EC0 801427C0 30620040 */  andi      $v0, $v1, 0x40
/* D8EC4 801427C4 50400008 */  beql      $v0, $zero, .L801427E8
/* D8EC8 801427C8 26F70001 */   addiu    $s7, $s7, 1
/* D8ECC 801427CC 82020045 */  lb        $v0, 0x45($s0)
/* D8ED0 801427D0 04420005 */  bltzl     $v0, .L801427E8
/* D8ED4 801427D4 26F70001 */   addiu    $s7, $s7, 1
/* D8ED8 801427D8 ACD70000 */  sw        $s7, ($a2)
/* D8EDC 801427DC 24C60004 */  addiu     $a2, $a2, 4
/* D8EE0 801427E0 27DE0001 */  addiu     $fp, $fp, 1
/* D8EE4 801427E4 26F70001 */  addiu     $s7, $s7, 1
.L801427E8:
/* D8EE8 801427E8 2AE20140 */  slti      $v0, $s7, 0x140
/* D8EEC 801427EC 1440FFE8 */  bnez      $v0, .L80142790
/* D8EF0 801427F0 24A50004 */   addiu    $a1, $a1, 4
/* D8EF4 801427F4 27C2FFFF */  addiu     $v0, $fp, -1
/* D8EF8 801427F8 18400024 */  blez      $v0, .L8014288C
/* D8EFC 801427FC 0000B82D */   daddu    $s7, $zero, $zero
/* D8F00 80142800 3C0D8015 */  lui       $t5, %hi(hudElements)
/* D8F04 80142804 25AD7960 */  addiu     $t5, $t5, %lo(hudElements)
/* D8F08 80142808 27AC0028 */  addiu     $t4, $sp, 0x28
/* D8F0C 8014280C 0180582D */  daddu     $t3, $t4, $zero
.L80142810:
/* D8F10 80142810 26E80001 */  addiu     $t0, $s7, 1
/* D8F14 80142814 011E102A */  slt       $v0, $t0, $fp
/* D8F18 80142818 50400018 */  beql      $v0, $zero, .L8014287C
/* D8F1C 8014281C 26F70001 */   addiu    $s7, $s7, 1
/* D8F20 80142820 0160502D */  daddu     $t2, $t3, $zero
/* D8F24 80142824 8DA90000 */  lw        $t1, ($t5)
/* D8F28 80142828 00081080 */  sll       $v0, $t0, 2
/* D8F2C 8014282C 004C3021 */  addu      $a2, $v0, $t4
.L80142830:
/* D8F30 80142830 8D470000 */  lw        $a3, ($t2)
/* D8F34 80142834 8CC50000 */  lw        $a1, ($a2)
/* D8F38 80142838 00071880 */  sll       $v1, $a3, 2
/* D8F3C 8014283C 00691821 */  addu      $v1, $v1, $t1
/* D8F40 80142840 00051080 */  sll       $v0, $a1, 2
/* D8F44 80142844 00491021 */  addu      $v0, $v0, $t1
/* D8F48 80142848 8C630000 */  lw        $v1, ($v1)
/* D8F4C 8014284C 8C440000 */  lw        $a0, ($v0)
/* D8F50 80142850 80620044 */  lb        $v0, 0x44($v1)
/* D8F54 80142854 80830044 */  lb        $v1, 0x44($a0)
/* D8F58 80142858 0043102A */  slt       $v0, $v0, $v1
/* D8F5C 8014285C 10400003 */  beqz      $v0, .L8014286C
/* D8F60 80142860 25080001 */   addiu    $t0, $t0, 1
/* D8F64 80142864 AD450000 */  sw        $a1, ($t2)
/* D8F68 80142868 ACC70000 */  sw        $a3, ($a2)
.L8014286C:
/* D8F6C 8014286C 011E102A */  slt       $v0, $t0, $fp
/* D8F70 80142870 1440FFEF */  bnez      $v0, .L80142830
/* D8F74 80142874 24C60004 */   addiu    $a2, $a2, 4
/* D8F78 80142878 26F70001 */  addiu     $s7, $s7, 1
.L8014287C:
/* D8F7C 8014287C 27C2FFFF */  addiu     $v0, $fp, -1
/* D8F80 80142880 02E2102A */  slt       $v0, $s7, $v0
/* D8F84 80142884 1440FFE2 */  bnez      $v0, .L80142810
/* D8F88 80142888 256B0004 */   addiu    $t3, $t3, 4
.L8014288C:
/* D8F8C 8014288C 1BC000CF */  blez      $fp, .L80142BCC
/* D8F90 80142890 0000B82D */   daddu    $s7, $zero, $zero
/* D8F94 80142894 00171080 */  sll       $v0, $s7, 2
.L80142898:
/* D8F98 80142898 03A21021 */  addu      $v0, $sp, $v0
/* D8F9C 8014289C 8C420028 */  lw        $v0, 0x28($v0)
/* D8FA0 801428A0 3C038015 */  lui       $v1, %hi(hudElements)
/* D8FA4 801428A4 8C637960 */  lw        $v1, %lo(hudElements)($v1)
/* D8FA8 801428A8 00021080 */  sll       $v0, $v0, 2
/* D8FAC 801428AC 00431021 */  addu      $v0, $v0, $v1
/* D8FB0 801428B0 8C500000 */  lw        $s0, ($v0)
/* D8FB4 801428B4 8E030000 */  lw        $v1, ($s0)
/* D8FB8 801428B8 30620100 */  andi      $v0, $v1, 0x100
/* D8FBC 801428BC 1440005B */  bnez      $v0, .L80142A2C
/* D8FC0 801428C0 3C0E0010 */   lui      $t6, 0x10
/* D8FC4 801428C4 006E1024 */  and       $v0, $v1, $t6
/* D8FC8 801428C8 1440000B */  bnez      $v0, .L801428F8
/* D8FCC 801428CC 00000000 */   nop
/* D8FD0 801428D0 82030046 */  lb        $v1, 0x46($s0)
/* D8FD4 801428D4 3C0E8015 */  lui       $t6, %hi(D_8014EFCC)
/* D8FD8 801428D8 25CEEFCC */  addiu     $t6, $t6, %lo(D_8014EFCC)
/* D8FDC 801428DC 00031040 */  sll       $v0, $v1, 1
/* D8FE0 801428E0 00431021 */  addu      $v0, $v0, $v1
/* D8FE4 801428E4 00021040 */  sll       $v0, $v0, 1
/* D8FE8 801428E8 004E1021 */  addu      $v0, $v0, $t6
/* D8FEC 801428EC 84560000 */  lh        $s6, ($v0)
/* D8FF0 801428F0 08050A40 */  j         .L80142900
/* D8FF4 801428F4 84550002 */   lh       $s5, 2($v0)
.L801428F8:
/* D8FF8 801428F8 9216004E */  lbu       $s6, 0x4e($s0)
/* D8FFC 801428FC 9215004F */  lbu       $s5, 0x4f($s0)
.L80142900:
/* D9000 80142900 8E030000 */  lw        $v1, ($s0)
/* D9004 80142904 30620010 */  andi      $v0, $v1, 0x10
/* D9008 80142908 14400013 */  bnez      $v0, .L80142958
/* D900C 8014290C 3C0E0010 */   lui      $t6, 0x10
/* D9010 80142910 006E1024 */  and       $v0, $v1, $t6
/* D9014 80142914 1440000C */  bnez      $v0, .L80142948
/* D9018 80142918 00000000 */   nop
/* D901C 8014291C 82030045 */  lb        $v1, 0x45($s0)
/* D9020 80142920 3C0E8015 */  lui       $t6, %hi(D_8014EFCC)
/* D9024 80142924 25CEEFCC */  addiu     $t6, $t6, %lo(D_8014EFCC)
/* D9028 80142928 00031040 */  sll       $v0, $v1, 1
/* D902C 8014292C 00431021 */  addu      $v0, $v0, $v1
/* D9030 80142930 00021040 */  sll       $v0, $v0, 1
/* D9034 80142934 004E1021 */  addu      $v0, $v0, $t6
/* D9038 80142938 84510000 */  lh        $s1, ($v0)
/* D903C 8014293C 84520002 */  lh        $s2, 2($v0)
/* D9040 80142940 08050A59 */  j         .L80142964
/* D9044 80142944 00111023 */   negu     $v0, $s1
.L80142948:
/* D9048 80142948 92110050 */  lbu       $s1, 0x50($s0)
/* D904C 8014294C 92120051 */  lbu       $s2, 0x51($s0)
/* D9050 80142950 08050A59 */  j         .L80142964
/* D9054 80142954 00111023 */   negu     $v0, $s1
.L80142958:
/* D9058 80142958 92110048 */  lbu       $s1, 0x48($s0)
/* D905C 8014295C 92120049 */  lbu       $s2, 0x49($s0)
/* D9060 80142960 00111023 */  negu      $v0, $s1
.L80142964:
/* D9064 80142964 00021FC2 */  srl       $v1, $v0, 0x1f
/* D9068 80142968 00431021 */  addu      $v0, $v0, $v1
/* D906C 8014296C 00029843 */  sra       $s3, $v0, 1
/* D9070 80142970 00121023 */  negu      $v0, $s2
/* D9074 80142974 00021FC2 */  srl       $v1, $v0, 0x1f
/* D9078 80142978 00431021 */  addu      $v0, $v0, $v1
/* D907C 8014297C 0002A043 */  sra       $s4, $v0, 1
/* D9080 80142980 8E030000 */  lw        $v1, ($s0)
/* D9084 80142984 30620800 */  andi      $v0, $v1, 0x800
/* D9088 80142988 14400026 */  bnez      $v0, .L80142A24
/* D908C 8014298C 3C0E2000 */   lui      $t6, 0x2000
/* D9090 80142990 006E1024 */  and       $v0, $v1, $t6
/* D9094 80142994 10400012 */  beqz      $v0, .L801429E0
/* D9098 80142998 0200202D */   daddu    $a0, $s0, $zero
/* D909C 8014299C 02C0282D */  daddu     $a1, $s6, $zero
/* D90A0 801429A0 02A0302D */  daddu     $a2, $s5, $zero
/* D90A4 801429A4 00113C00 */  sll       $a3, $s1, 0x10
/* D90A8 801429A8 00073C03 */  sra       $a3, $a3, 0x10
/* D90AC 801429AC 00121400 */  sll       $v0, $s2, 0x10
/* D90B0 801429B0 00021403 */  sra       $v0, $v0, 0x10
/* D90B4 801429B4 AFA20010 */  sw        $v0, 0x10($sp)
/* D90B8 801429B8 00131400 */  sll       $v0, $s3, 0x10
/* D90BC 801429BC 00021403 */  sra       $v0, $v0, 0x10
/* D90C0 801429C0 AFA20014 */  sw        $v0, 0x14($sp)
/* D90C4 801429C4 00141400 */  sll       $v0, $s4, 0x10
/* D90C8 801429C8 00021403 */  sra       $v0, $v0, 0x10
/* D90CC 801429CC 240E0001 */  addiu     $t6, $zero, 1
/* D90D0 801429D0 AFA20018 */  sw        $v0, 0x18($sp)
/* D90D4 801429D4 AFAE001C */  sw        $t6, 0x1c($sp)
/* D90D8 801429D8 0C04FDC1 */  jal       draw_rect_hud_element
/* D90DC 801429DC AFAE0020 */   sw       $t6, 0x20($sp)
.L801429E0:
/* D90E0 801429E0 0200202D */  daddu     $a0, $s0, $zero
/* D90E4 801429E4 02C0282D */  daddu     $a1, $s6, $zero
/* D90E8 801429E8 02A0302D */  daddu     $a2, $s5, $zero
/* D90EC 801429EC 00113C00 */  sll       $a3, $s1, 0x10
/* D90F0 801429F0 00073C03 */  sra       $a3, $a3, 0x10
/* D90F4 801429F4 00121400 */  sll       $v0, $s2, 0x10
/* D90F8 801429F8 00021403 */  sra       $v0, $v0, 0x10
/* D90FC 801429FC AFA20010 */  sw        $v0, 0x10($sp)
/* D9100 80142A00 00131400 */  sll       $v0, $s3, 0x10
/* D9104 80142A04 00021403 */  sra       $v0, $v0, 0x10
/* D9108 80142A08 AFA20014 */  sw        $v0, 0x14($sp)
/* D910C 80142A0C 00141400 */  sll       $v0, $s4, 0x10
/* D9110 80142A10 00021403 */  sra       $v0, $v0, 0x10
/* D9114 80142A14 240E0001 */  addiu     $t6, $zero, 1
/* D9118 80142A18 AFA20018 */  sw        $v0, 0x18($sp)
/* D911C 80142A1C 08050AED */  j         .L80142BB4
/* D9120 80142A20 AFAE001C */   sw       $t6, 0x1c($sp)
.L80142A24:
/* D9124 80142A24 08050ACB */  j         .L80142B2C
/* D9128 80142A28 006E1024 */   and      $v0, $v1, $t6
.L80142A2C:
/* D912C 80142A2C 006E1024 */  and       $v0, $v1, $t6
/* D9130 80142A30 1440000B */  bnez      $v0, .L80142A60
/* D9134 80142A34 00000000 */   nop
/* D9138 80142A38 82030045 */  lb        $v1, 0x45($s0)
/* D913C 80142A3C 3C0E8015 */  lui       $t6, %hi(D_8014EFCC)
/* D9140 80142A40 25CEEFCC */  addiu     $t6, $t6, %lo(D_8014EFCC)
/* D9144 80142A44 00031040 */  sll       $v0, $v1, 1
/* D9148 80142A48 00431021 */  addu      $v0, $v0, $v1
/* D914C 80142A4C 00021040 */  sll       $v0, $v0, 1
/* D9150 80142A50 004E1021 */  addu      $v0, $v0, $t6
/* D9154 80142A54 84560000 */  lh        $s6, ($v0)
/* D9158 80142A58 08050A9A */  j         .L80142A68
/* D915C 80142A5C 84550002 */   lh       $s5, 2($v0)
.L80142A60:
/* D9160 80142A60 9216004E */  lbu       $s6, 0x4e($s0)
/* D9164 80142A64 9215004F */  lbu       $s5, 0x4f($s0)
.L80142A68:
/* D9168 80142A68 C6000028 */  lwc1      $f0, 0x28($s0)
/* D916C 80142A6C C606002C */  lwc1      $f6, 0x2c($s0)
/* D9170 80142A70 3C013F00 */  lui       $at, 0x3f00
/* D9174 80142A74 44811000 */  mtc1      $at, $f2
/* D9178 80142A78 46000307 */  neg.s     $f12, $f0
/* D917C 80142A7C 46026302 */  mul.s     $f12, $f12, $f2
/* D9180 80142A80 00000000 */  nop
/* D9184 80142A84 3C013F80 */  lui       $at, 0x3f80
/* D9188 80142A88 44814000 */  mtc1      $at, $f8
/* D918C 80142A8C 3C014480 */  lui       $at, 0x4480
/* D9190 80142A90 44815000 */  mtc1      $at, $f10
/* D9194 80142A94 4600038D */  trunc.w.s $f14, $f0
/* D9198 80142A98 44117000 */  mfc1      $s1, $f14
/* D919C 80142A9C 4600338D */  trunc.w.s $f14, $f6
/* D91A0 80142AA0 44127000 */  mfc1      $s2, $f14
/* D91A4 80142AA4 46003187 */  neg.s     $f6, $f6
/* D91A8 80142AA8 46023182 */  mul.s     $f6, $f6, $f2
/* D91AC 80142AAC 00000000 */  nop
/* D91B0 80142AB0 44912000 */  mtc1      $s1, $f4
/* D91B4 80142AB4 00000000 */  nop
/* D91B8 80142AB8 46802120 */  cvt.s.w   $f4, $f4
/* D91BC 80142ABC 44960000 */  mtc1      $s6, $f0
/* D91C0 80142AC0 00000000 */  nop
/* D91C4 80142AC4 46800020 */  cvt.s.w   $f0, $f0
/* D91C8 80142AC8 46002103 */  div.s     $f4, $f4, $f0
/* D91CC 80142ACC 46044103 */  div.s     $f4, $f8, $f4
/* D91D0 80142AD0 460A2102 */  mul.s     $f4, $f4, $f10
/* D91D4 80142AD4 00000000 */  nop
/* D91D8 80142AD8 44921000 */  mtc1      $s2, $f2
/* D91DC 80142ADC 00000000 */  nop
/* D91E0 80142AE0 468010A0 */  cvt.s.w   $f2, $f2
/* D91E4 80142AE4 44950000 */  mtc1      $s5, $f0
/* D91E8 80142AE8 00000000 */  nop
/* D91EC 80142AEC 46800020 */  cvt.s.w   $f0, $f0
/* D91F0 80142AF0 46001083 */  div.s     $f2, $f2, $f0
/* D91F4 80142AF4 46024083 */  div.s     $f2, $f8, $f2
/* D91F8 80142AF8 460A1082 */  mul.s     $f2, $f2, $f10
/* D91FC 80142AFC 00000000 */  nop
/* D9200 80142B00 8E020000 */  lw        $v0, ($s0)
/* D9204 80142B04 4600638D */  trunc.w.s $f14, $f12
/* D9208 80142B08 44137000 */  mfc1      $s3, $f14
/* D920C 80142B0C 4600338D */  trunc.w.s $f14, $f6
/* D9210 80142B10 44147000 */  mfc1      $s4, $f14
/* D9214 80142B14 4600238D */  trunc.w.s $f14, $f4
/* D9218 80142B18 E60E0034 */  swc1      $f14, 0x34($s0)
/* D921C 80142B1C 4600138D */  trunc.w.s $f14, $f2
/* D9220 80142B20 E60E0038 */  swc1      $f14, 0x38($s0)
/* D9224 80142B24 3C0E2000 */  lui       $t6, 0x2000
/* D9228 80142B28 004E1024 */  and       $v0, $v0, $t6
.L80142B2C:
/* D922C 80142B2C 10400012 */  beqz      $v0, .L80142B78
/* D9230 80142B30 0200202D */   daddu    $a0, $s0, $zero
/* D9234 80142B34 02C0282D */  daddu     $a1, $s6, $zero
/* D9238 80142B38 02A0302D */  daddu     $a2, $s5, $zero
/* D923C 80142B3C 00113C00 */  sll       $a3, $s1, 0x10
/* D9240 80142B40 00073C03 */  sra       $a3, $a3, 0x10
/* D9244 80142B44 00121400 */  sll       $v0, $s2, 0x10
/* D9248 80142B48 00021403 */  sra       $v0, $v0, 0x10
/* D924C 80142B4C AFA20010 */  sw        $v0, 0x10($sp)
/* D9250 80142B50 00131400 */  sll       $v0, $s3, 0x10
/* D9254 80142B54 00021403 */  sra       $v0, $v0, 0x10
/* D9258 80142B58 AFA20014 */  sw        $v0, 0x14($sp)
/* D925C 80142B5C 00141400 */  sll       $v0, $s4, 0x10
/* D9260 80142B60 00021403 */  sra       $v0, $v0, 0x10
/* D9264 80142B64 240E0001 */  addiu     $t6, $zero, 1
/* D9268 80142B68 AFA20018 */  sw        $v0, 0x18($sp)
/* D926C 80142B6C AFA0001C */  sw        $zero, 0x1c($sp)
/* D9270 80142B70 0C04FDC1 */  jal       draw_rect_hud_element
/* D9274 80142B74 AFAE0020 */   sw       $t6, 0x20($sp)
.L80142B78:
/* D9278 80142B78 0200202D */  daddu     $a0, $s0, $zero
/* D927C 80142B7C 02C0282D */  daddu     $a1, $s6, $zero
/* D9280 80142B80 02A0302D */  daddu     $a2, $s5, $zero
/* D9284 80142B84 00113C00 */  sll       $a3, $s1, 0x10
/* D9288 80142B88 00073C03 */  sra       $a3, $a3, 0x10
/* D928C 80142B8C 00121400 */  sll       $v0, $s2, 0x10
/* D9290 80142B90 00021403 */  sra       $v0, $v0, 0x10
/* D9294 80142B94 AFA20010 */  sw        $v0, 0x10($sp)
/* D9298 80142B98 00131400 */  sll       $v0, $s3, 0x10
/* D929C 80142B9C 00021403 */  sra       $v0, $v0, 0x10
/* D92A0 80142BA0 AFA20014 */  sw        $v0, 0x14($sp)
/* D92A4 80142BA4 00141400 */  sll       $v0, $s4, 0x10
/* D92A8 80142BA8 00021403 */  sra       $v0, $v0, 0x10
/* D92AC 80142BAC AFA20018 */  sw        $v0, 0x18($sp)
/* D92B0 80142BB0 AFA0001C */  sw        $zero, 0x1c($sp)
.L80142BB4:
/* D92B4 80142BB4 0C04FDC1 */  jal       draw_rect_hud_element
/* D92B8 80142BB8 AFA00020 */   sw       $zero, 0x20($sp)
/* D92BC 80142BBC 26F70001 */  addiu     $s7, $s7, 1
/* D92C0 80142BC0 02FE102A */  slt       $v0, $s7, $fp
/* D92C4 80142BC4 1440FF34 */  bnez      $v0, .L80142898
/* D92C8 80142BC8 00171080 */   sll      $v0, $s7, 2
.L80142BCC:
/* D92CC 80142BCC 8FBF054C */  lw        $ra, 0x54c($sp)
/* D92D0 80142BD0 8FBE0548 */  lw        $fp, 0x548($sp)
/* D92D4 80142BD4 8FB70544 */  lw        $s7, 0x544($sp)
/* D92D8 80142BD8 8FB60540 */  lw        $s6, 0x540($sp)
/* D92DC 80142BDC 8FB5053C */  lw        $s5, 0x53c($sp)
/* D92E0 80142BE0 8FB40538 */  lw        $s4, 0x538($sp)
/* D92E4 80142BE4 8FB30534 */  lw        $s3, 0x534($sp)
/* D92E8 80142BE8 8FB20530 */  lw        $s2, 0x530($sp)
/* D92EC 80142BEC 8FB1052C */  lw        $s1, 0x52c($sp)
/* D92F0 80142BF0 8FB00528 */  lw        $s0, 0x528($sp)
/* D92F4 80142BF4 03E00008 */  jr        $ra
/* D92F8 80142BF8 27BD0550 */   addiu    $sp, $sp, 0x550
