.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802180CC_584A0C
/* 584A0C 802180CC 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 584A10 802180D0 AFB1001C */  sw        $s1, 0x1c($sp)
/* 584A14 802180D4 0080882D */  daddu     $s1, $a0, $zero
/* 584A18 802180D8 AFBF0034 */  sw        $ra, 0x34($sp)
/* 584A1C 802180DC AFB60030 */  sw        $s6, 0x30($sp)
/* 584A20 802180E0 AFB5002C */  sw        $s5, 0x2c($sp)
/* 584A24 802180E4 AFB40028 */  sw        $s4, 0x28($sp)
/* 584A28 802180E8 AFB30024 */  sw        $s3, 0x24($sp)
/* 584A2C 802180EC AFB20020 */  sw        $s2, 0x20($sp)
/* 584A30 802180F0 AFB00018 */  sw        $s0, 0x18($sp)
/* 584A34 802180F4 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 584A38 802180F8 8E30000C */  lw        $s0, 0xc($s1)
/* 584A3C 802180FC 8E050000 */  lw        $a1, ($s0)
/* 584A40 80218100 0C0B1EAF */  jal       evt_get_variable
/* 584A44 80218104 26100004 */   addiu    $s0, $s0, 4
/* 584A48 80218108 8E050000 */  lw        $a1, ($s0)
/* 584A4C 8021810C 26100004 */  addiu     $s0, $s0, 4
/* 584A50 80218110 0C0B1EAF */  jal       evt_get_variable
/* 584A54 80218114 0220202D */   daddu    $a0, $s1, $zero
/* 584A58 80218118 8E050000 */  lw        $a1, ($s0)
/* 584A5C 8021811C 26100004 */  addiu     $s0, $s0, 4
/* 584A60 80218120 0220202D */  daddu     $a0, $s1, $zero
/* 584A64 80218124 0C0B1EAF */  jal       evt_get_variable
/* 584A68 80218128 0040B02D */   daddu    $s6, $v0, $zero
/* 584A6C 8021812C 8E050000 */  lw        $a1, ($s0)
/* 584A70 80218130 26100004 */  addiu     $s0, $s0, 4
/* 584A74 80218134 0220202D */  daddu     $a0, $s1, $zero
/* 584A78 80218138 0C0B1EAF */  jal       evt_get_variable
/* 584A7C 8021813C 0040A82D */   daddu    $s5, $v0, $zero
/* 584A80 80218140 8E050000 */  lw        $a1, ($s0)
/* 584A84 80218144 26100004 */  addiu     $s0, $s0, 4
/* 584A88 80218148 0220202D */  daddu     $a0, $s1, $zero
/* 584A8C 8021814C 0C0B210B */  jal       evt_get_float_variable
/* 584A90 80218150 0040A02D */   daddu    $s4, $v0, $zero
/* 584A94 80218154 8E050000 */  lw        $a1, ($s0)
/* 584A98 80218158 26100004 */  addiu     $s0, $s0, 4
/* 584A9C 8021815C 0220202D */  daddu     $a0, $s1, $zero
/* 584AA0 80218160 0C0B1EAF */  jal       evt_get_variable
/* 584AA4 80218164 46000506 */   mov.s    $f20, $f0
/* 584AA8 80218168 8E050000 */  lw        $a1, ($s0)
/* 584AAC 8021816C 26100004 */  addiu     $s0, $s0, 4
/* 584AB0 80218170 0220202D */  daddu     $a0, $s1, $zero
/* 584AB4 80218174 0C0B1EAF */  jal       evt_get_variable
/* 584AB8 80218178 0040902D */   daddu    $s2, $v0, $zero
/* 584ABC 8021817C 8E050000 */  lw        $a1, ($s0)
/* 584AC0 80218180 26100004 */  addiu     $s0, $s0, 4
/* 584AC4 80218184 0220202D */  daddu     $a0, $s1, $zero
/* 584AC8 80218188 0C0B1EAF */  jal       evt_get_variable
/* 584ACC 8021818C 0040982D */   daddu    $s3, $v0, $zero
/* 584AD0 80218190 0220202D */  daddu     $a0, $s1, $zero
/* 584AD4 80218194 8E050000 */  lw        $a1, ($s0)
/* 584AD8 80218198 0C0B1EAF */  jal       evt_get_variable
/* 584ADC 8021819C 0040882D */   daddu    $s1, $v0, $zero
/* 584AE0 802181A0 24040001 */  addiu     $a0, $zero, 1
/* 584AE4 802181A4 44961000 */  mtc1      $s6, $f2
/* 584AE8 802181A8 00000000 */  nop
/* 584AEC 802181AC 468010A0 */  cvt.s.w   $f2, $f2
/* 584AF0 802181B0 44051000 */  mfc1      $a1, $f2
/* 584AF4 802181B4 44951000 */  mtc1      $s5, $f2
/* 584AF8 802181B8 00000000 */  nop
/* 584AFC 802181BC 468010A0 */  cvt.s.w   $f2, $f2
/* 584B00 802181C0 44061000 */  mfc1      $a2, $f2
/* 584B04 802181C4 44941000 */  mtc1      $s4, $f2
/* 584B08 802181C8 00000000 */  nop
/* 584B0C 802181CC 468010A0 */  cvt.s.w   $f2, $f2
/* 584B10 802181D0 44071000 */  mfc1      $a3, $f2
/* 584B14 802181D4 0040802D */  daddu     $s0, $v0, $zero
/* 584B18 802181D8 E7B40010 */  swc1      $f20, 0x10($sp)
/* 584B1C 802181DC 0C01C88C */  jal       playFX_6F
/* 584B20 802181E0 AFB20014 */   sw       $s2, 0x14($sp)
/* 584B24 802181E4 8C43000C */  lw        $v1, 0xc($v0)
/* 584B28 802181E8 AC730018 */  sw        $s3, 0x18($v1)
/* 584B2C 802181EC 8C43000C */  lw        $v1, 0xc($v0)
/* 584B30 802181F0 AC71001C */  sw        $s1, 0x1c($v1)
/* 584B34 802181F4 8C43000C */  lw        $v1, 0xc($v0)
/* 584B38 802181F8 AC700020 */  sw        $s0, 0x20($v1)
/* 584B3C 802181FC 8C43000C */  lw        $v1, 0xc($v0)
/* 584B40 80218200 240400FF */  addiu     $a0, $zero, 0xff
/* 584B44 80218204 AC640028 */  sw        $a0, 0x28($v1)
/* 584B48 80218208 8C43000C */  lw        $v1, 0xc($v0)
/* 584B4C 8021820C AC64002C */  sw        $a0, 0x2c($v1)
/* 584B50 80218210 8C43000C */  lw        $v1, 0xc($v0)
/* 584B54 80218214 AC640030 */  sw        $a0, 0x30($v1)
/* 584B58 80218218 8FBF0034 */  lw        $ra, 0x34($sp)
/* 584B5C 8021821C 8FB60030 */  lw        $s6, 0x30($sp)
/* 584B60 80218220 8FB5002C */  lw        $s5, 0x2c($sp)
/* 584B64 80218224 8FB40028 */  lw        $s4, 0x28($sp)
/* 584B68 80218228 8FB30024 */  lw        $s3, 0x24($sp)
/* 584B6C 8021822C 8FB20020 */  lw        $s2, 0x20($sp)
/* 584B70 80218230 8FB1001C */  lw        $s1, 0x1c($sp)
/* 584B74 80218234 8FB00018 */  lw        $s0, 0x18($sp)
/* 584B78 80218238 D7B40038 */  ldc1      $f20, 0x38($sp)
/* 584B7C 8021823C 24020002 */  addiu     $v0, $zero, 2
/* 584B80 80218240 03E00008 */  jr        $ra
/* 584B84 80218244 27BD0040 */   addiu    $sp, $sp, 0x40
/* 584B88 80218248 00000000 */  nop
/* 584B8C 8021824C 00000000 */  nop
