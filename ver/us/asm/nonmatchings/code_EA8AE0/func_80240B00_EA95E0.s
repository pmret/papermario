.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B00_EA95E0
/* EA95E0 80240B00 27BDFE60 */  addiu     $sp, $sp, -0x1a0
/* EA95E4 80240B04 AFB30194 */  sw        $s3, 0x194($sp)
/* EA95E8 80240B08 0080982D */  daddu     $s3, $a0, $zero
/* EA95EC 80240B0C AFB1018C */  sw        $s1, 0x18c($sp)
/* EA95F0 80240B10 27B10010 */  addiu     $s1, $sp, 0x10
/* EA95F4 80240B14 0220202D */  daddu     $a0, $s1, $zero
/* EA95F8 80240B18 24050001 */  addiu     $a1, $zero, 1
/* EA95FC 80240B1C AFBF0198 */  sw        $ra, 0x198($sp)
/* EA9600 80240B20 AFB20190 */  sw        $s2, 0x190($sp)
/* EA9604 80240B24 AFB00188 */  sw        $s0, 0x188($sp)
/* EA9608 80240B28 8E630090 */  lw        $v1, 0x90($s3)
/* EA960C 80240B2C 0000902D */  daddu     $s2, $zero, $zero
/* EA9610 80240B30 AFB3017C */  sw        $s3, 0x17c($sp)
/* EA9614 80240B34 00A31004 */  sllv      $v0, $v1, $a1
/* EA9618 80240B38 00431021 */  addu      $v0, $v0, $v1
/* EA961C 80240B3C AFA20178 */  sw        $v0, 0x178($sp)
/* EA9620 80240B40 8E630090 */  lw        $v1, 0x90($s3)
/* EA9624 80240B44 27A20178 */  addiu     $v0, $sp, 0x178
/* EA9628 80240B48 AFA00184 */  sw        $zero, 0x184($sp)
/* EA962C 80240B4C AFA2001C */  sw        $v0, 0x1c($sp)
/* EA9630 80240B50 0C0B8AA0 */  jal       func_802E2A80
/* EA9634 80240B54 AFA30180 */   sw       $v1, 0x180($sp)
/* EA9638 80240B58 0260802D */  daddu     $s0, $s3, $zero
.L80240B5C:
/* EA963C 80240B5C 0220202D */  daddu     $a0, $s1, $zero
/* EA9640 80240B60 0C0B8ADD */  jal       func_802E2B74
/* EA9644 80240B64 24050001 */   addiu    $a1, $zero, 1
/* EA9648 80240B68 0220202D */  daddu     $a0, $s1, $zero
/* EA964C 80240B6C 3C05FE36 */  lui       $a1, 0xfe36
/* EA9650 80240B70 0C0B55FF */  jal       dead_get_float_variable
/* EA9654 80240B74 34A53C81 */   ori      $a1, $a1, 0x3c81
/* EA9658 80240B78 0220202D */  daddu     $a0, $s1, $zero
/* EA965C 80240B7C 3C05FE36 */  lui       $a1, 0xfe36
/* EA9660 80240B80 34A53C82 */  ori       $a1, $a1, 0x3c82
/* EA9664 80240B84 0C0B55FF */  jal       dead_get_float_variable
/* EA9668 80240B88 E6000098 */   swc1     $f0, 0x98($s0)
/* EA966C 80240B8C 0220202D */  daddu     $a0, $s1, $zero
/* EA9670 80240B90 3C05FE36 */  lui       $a1, 0xfe36
/* EA9674 80240B94 34A53C83 */  ori       $a1, $a1, 0x3c83
/* EA9678 80240B98 0C0B55FF */  jal       dead_get_float_variable
/* EA967C 80240B9C E600009C */   swc1     $f0, 0x9c($s0)
/* EA9680 80240BA0 E60000A0 */  swc1      $f0, 0xa0($s0)
/* EA9684 80240BA4 2610000C */  addiu     $s0, $s0, 0xc
/* EA9688 80240BA8 8E220084 */  lw        $v0, 0x84($s1)
/* EA968C 80240BAC 1440FFEB */  bnez      $v0, .L80240B5C
/* EA9690 80240BB0 26520001 */   addiu    $s2, $s2, 1
/* EA9694 80240BB4 AE7201DC */  sw        $s2, 0x1dc($s3)
/* EA9698 80240BB8 8FBF0198 */  lw        $ra, 0x198($sp)
/* EA969C 80240BBC 8FB30194 */  lw        $s3, 0x194($sp)
/* EA96A0 80240BC0 8FB20190 */  lw        $s2, 0x190($sp)
/* EA96A4 80240BC4 8FB1018C */  lw        $s1, 0x18c($sp)
/* EA96A8 80240BC8 8FB00188 */  lw        $s0, 0x188($sp)
/* EA96AC 80240BCC 03E00008 */  jr        $ra
/* EA96B0 80240BD0 27BD01A0 */   addiu    $sp, $sp, 0x1a0
