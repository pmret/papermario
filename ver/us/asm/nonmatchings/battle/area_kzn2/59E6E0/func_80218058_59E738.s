.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218058_59E738
/* 59E738 80218058 27BDFE60 */  addiu     $sp, $sp, -0x1a0
/* 59E73C 8021805C AFB30194 */  sw        $s3, 0x194($sp)
/* 59E740 80218060 0080982D */  daddu     $s3, $a0, $zero
/* 59E744 80218064 AFB1018C */  sw        $s1, 0x18c($sp)
/* 59E748 80218068 27B10010 */  addiu     $s1, $sp, 0x10
/* 59E74C 8021806C 0220202D */  daddu     $a0, $s1, $zero
/* 59E750 80218070 24050001 */  addiu     $a1, $zero, 1
/* 59E754 80218074 AFBF0198 */  sw        $ra, 0x198($sp)
/* 59E758 80218078 AFB20190 */  sw        $s2, 0x190($sp)
/* 59E75C 8021807C AFB00188 */  sw        $s0, 0x188($sp)
/* 59E760 80218080 8E630090 */  lw        $v1, 0x90($s3)
/* 59E764 80218084 0000902D */  daddu     $s2, $zero, $zero
/* 59E768 80218088 AFB3017C */  sw        $s3, 0x17c($sp)
/* 59E76C 8021808C 00A31004 */  sllv      $v0, $v1, $a1
/* 59E770 80218090 00431021 */  addu      $v0, $v0, $v1
/* 59E774 80218094 AFA20178 */  sw        $v0, 0x178($sp)
/* 59E778 80218098 8E630090 */  lw        $v1, 0x90($s3)
/* 59E77C 8021809C 27A20178 */  addiu     $v0, $sp, 0x178
/* 59E780 802180A0 AFA00184 */  sw        $zero, 0x184($sp)
/* 59E784 802180A4 AFA2001C */  sw        $v0, 0x1c($sp)
/* 59E788 802180A8 0C0B550C */  jal       LoadPath
/* 59E78C 802180AC AFA30180 */   sw       $v1, 0x180($sp)
/* 59E790 802180B0 0260802D */  daddu     $s0, $s3, $zero
.L802180B4:
/* 59E794 802180B4 0220202D */  daddu     $a0, $s1, $zero
/* 59E798 802180B8 0C0B5549 */  jal       GetNextPathPos
/* 59E79C 802180BC 24050001 */   addiu    $a1, $zero, 1
/* 59E7A0 802180C0 0220202D */  daddu     $a0, $s1, $zero
/* 59E7A4 802180C4 3C05FE36 */  lui       $a1, 0xfe36
/* 59E7A8 802180C8 0C0B210B */  jal       get_float_variable
/* 59E7AC 802180CC 34A53C81 */   ori      $a1, $a1, 0x3c81
/* 59E7B0 802180D0 0220202D */  daddu     $a0, $s1, $zero
/* 59E7B4 802180D4 3C05FE36 */  lui       $a1, 0xfe36
/* 59E7B8 802180D8 34A53C82 */  ori       $a1, $a1, 0x3c82
/* 59E7BC 802180DC 0C0B210B */  jal       get_float_variable
/* 59E7C0 802180E0 E6000098 */   swc1     $f0, 0x98($s0)
/* 59E7C4 802180E4 0220202D */  daddu     $a0, $s1, $zero
/* 59E7C8 802180E8 3C05FE36 */  lui       $a1, 0xfe36
/* 59E7CC 802180EC 34A53C83 */  ori       $a1, $a1, 0x3c83
/* 59E7D0 802180F0 0C0B210B */  jal       get_float_variable
/* 59E7D4 802180F4 E600009C */   swc1     $f0, 0x9c($s0)
/* 59E7D8 802180F8 E60000A0 */  swc1      $f0, 0xa0($s0)
/* 59E7DC 802180FC 2610000C */  addiu     $s0, $s0, 0xc
/* 59E7E0 80218100 8E220084 */  lw        $v0, 0x84($s1)
/* 59E7E4 80218104 1440FFEB */  bnez      $v0, .L802180B4
/* 59E7E8 80218108 26520001 */   addiu    $s2, $s2, 1
/* 59E7EC 8021810C AE7201DC */  sw        $s2, 0x1dc($s3)
/* 59E7F0 80218110 8FBF0198 */  lw        $ra, 0x198($sp)
/* 59E7F4 80218114 8FB30194 */  lw        $s3, 0x194($sp)
/* 59E7F8 80218118 8FB20190 */  lw        $s2, 0x190($sp)
/* 59E7FC 8021811C 8FB1018C */  lw        $s1, 0x18c($sp)
/* 59E800 80218120 8FB00188 */  lw        $s0, 0x188($sp)
/* 59E804 80218124 03E00008 */  jr        $ra
/* 59E808 80218128 27BD01A0 */   addiu    $sp, $sp, 0x1a0
