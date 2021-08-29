.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B00_C8E6B0
/* C8E6B0 80240B00 27BDFE60 */  addiu     $sp, $sp, -0x1a0
/* C8E6B4 80240B04 AFB30194 */  sw        $s3, 0x194($sp)
/* C8E6B8 80240B08 0080982D */  daddu     $s3, $a0, $zero
/* C8E6BC 80240B0C AFB1018C */  sw        $s1, 0x18c($sp)
/* C8E6C0 80240B10 27B10010 */  addiu     $s1, $sp, 0x10
/* C8E6C4 80240B14 0220202D */  daddu     $a0, $s1, $zero
/* C8E6C8 80240B18 24050001 */  addiu     $a1, $zero, 1
/* C8E6CC 80240B1C AFBF0198 */  sw        $ra, 0x198($sp)
/* C8E6D0 80240B20 AFB20190 */  sw        $s2, 0x190($sp)
/* C8E6D4 80240B24 AFB00188 */  sw        $s0, 0x188($sp)
/* C8E6D8 80240B28 8E630090 */  lw        $v1, 0x90($s3)
/* C8E6DC 80240B2C 0000902D */  daddu     $s2, $zero, $zero
/* C8E6E0 80240B30 AFB3017C */  sw        $s3, 0x17c($sp)
/* C8E6E4 80240B34 00A31004 */  sllv      $v0, $v1, $a1
/* C8E6E8 80240B38 00431021 */  addu      $v0, $v0, $v1
/* C8E6EC 80240B3C AFA20178 */  sw        $v0, 0x178($sp)
/* C8E6F0 80240B40 8E630090 */  lw        $v1, 0x90($s3)
/* C8E6F4 80240B44 27A20178 */  addiu     $v0, $sp, 0x178
/* C8E6F8 80240B48 AFA00184 */  sw        $zero, 0x184($sp)
/* C8E6FC 80240B4C AFA2001C */  sw        $v0, 0x1c($sp)
/* C8E700 80240B50 0C0B550C */  jal       LoadPath
/* C8E704 80240B54 AFA30180 */   sw       $v1, 0x180($sp)
/* C8E708 80240B58 0260802D */  daddu     $s0, $s3, $zero
.L80240B5C:
/* C8E70C 80240B5C 0220202D */  daddu     $a0, $s1, $zero
/* C8E710 80240B60 0C0B5549 */  jal       GetNextPathPos
/* C8E714 80240B64 24050001 */   addiu    $a1, $zero, 1
/* C8E718 80240B68 0220202D */  daddu     $a0, $s1, $zero
/* C8E71C 80240B6C 3C05FE36 */  lui       $a1, 0xfe36
/* C8E720 80240B70 0C0B210B */  jal       evt_get_float_variable
/* C8E724 80240B74 34A53C81 */   ori      $a1, $a1, 0x3c81
/* C8E728 80240B78 0220202D */  daddu     $a0, $s1, $zero
/* C8E72C 80240B7C 3C05FE36 */  lui       $a1, 0xfe36
/* C8E730 80240B80 34A53C82 */  ori       $a1, $a1, 0x3c82
/* C8E734 80240B84 0C0B210B */  jal       evt_get_float_variable
/* C8E738 80240B88 E6000098 */   swc1     $f0, 0x98($s0)
/* C8E73C 80240B8C 0220202D */  daddu     $a0, $s1, $zero
/* C8E740 80240B90 3C05FE36 */  lui       $a1, 0xfe36
/* C8E744 80240B94 34A53C83 */  ori       $a1, $a1, 0x3c83
/* C8E748 80240B98 0C0B210B */  jal       evt_get_float_variable
/* C8E74C 80240B9C E600009C */   swc1     $f0, 0x9c($s0)
/* C8E750 80240BA0 E60000A0 */  swc1      $f0, 0xa0($s0)
/* C8E754 80240BA4 2610000C */  addiu     $s0, $s0, 0xc
/* C8E758 80240BA8 8E220084 */  lw        $v0, 0x84($s1)
/* C8E75C 80240BAC 1440FFEB */  bnez      $v0, .L80240B5C
/* C8E760 80240BB0 26520001 */   addiu    $s2, $s2, 1
/* C8E764 80240BB4 AE7201DC */  sw        $s2, 0x1dc($s3)
/* C8E768 80240BB8 8FBF0198 */  lw        $ra, 0x198($sp)
/* C8E76C 80240BBC 8FB30194 */  lw        $s3, 0x194($sp)
/* C8E770 80240BC0 8FB20190 */  lw        $s2, 0x190($sp)
/* C8E774 80240BC4 8FB1018C */  lw        $s1, 0x18c($sp)
/* C8E778 80240BC8 8FB00188 */  lw        $s0, 0x188($sp)
/* C8E77C 80240BCC 03E00008 */  jr        $ra
/* C8E780 80240BD0 27BD01A0 */   addiu    $sp, $sp, 0x1a0
