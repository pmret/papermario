.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240240_8FF8B0
/* 8FF8B0 80240240 27BDFE60 */  addiu     $sp, $sp, -0x1a0
/* 8FF8B4 80240244 AFB30194 */  sw        $s3, 0x194($sp)
/* 8FF8B8 80240248 0080982D */  daddu     $s3, $a0, $zero
/* 8FF8BC 8024024C AFB1018C */  sw        $s1, 0x18c($sp)
/* 8FF8C0 80240250 27B10010 */  addiu     $s1, $sp, 0x10
/* 8FF8C4 80240254 0220202D */  daddu     $a0, $s1, $zero
/* 8FF8C8 80240258 24050001 */  addiu     $a1, $zero, 1
/* 8FF8CC 8024025C AFBF0198 */  sw        $ra, 0x198($sp)
/* 8FF8D0 80240260 AFB20190 */  sw        $s2, 0x190($sp)
/* 8FF8D4 80240264 AFB00188 */  sw        $s0, 0x188($sp)
/* 8FF8D8 80240268 8E630090 */  lw        $v1, 0x90($s3)
/* 8FF8DC 8024026C 0000902D */  daddu     $s2, $zero, $zero
/* 8FF8E0 80240270 AFB3017C */  sw        $s3, 0x17c($sp)
/* 8FF8E4 80240274 00A31004 */  sllv      $v0, $v1, $a1
/* 8FF8E8 80240278 00431021 */  addu      $v0, $v0, $v1
/* 8FF8EC 8024027C AFA20178 */  sw        $v0, 0x178($sp)
/* 8FF8F0 80240280 8E630090 */  lw        $v1, 0x90($s3)
/* 8FF8F4 80240284 27A20178 */  addiu     $v0, $sp, 0x178
/* 8FF8F8 80240288 AFA00184 */  sw        $zero, 0x184($sp)
/* 8FF8FC 8024028C AFA2001C */  sw        $v0, 0x1c($sp)
/* 8FF900 80240290 0C0B550C */  jal       LoadPath
/* 8FF904 80240294 AFA30180 */   sw       $v1, 0x180($sp)
/* 8FF908 80240298 0260802D */  daddu     $s0, $s3, $zero
.L8024029C:
/* 8FF90C 8024029C 0220202D */  daddu     $a0, $s1, $zero
/* 8FF910 802402A0 0C0B5549 */  jal       GetNextPathPos
/* 8FF914 802402A4 24050001 */   addiu    $a1, $zero, 1
/* 8FF918 802402A8 0220202D */  daddu     $a0, $s1, $zero
/* 8FF91C 802402AC 3C05FE36 */  lui       $a1, 0xfe36
/* 8FF920 802402B0 0C0B210B */  jal       evt_get_float_variable
/* 8FF924 802402B4 34A53C81 */   ori      $a1, $a1, 0x3c81
/* 8FF928 802402B8 0220202D */  daddu     $a0, $s1, $zero
/* 8FF92C 802402BC 3C05FE36 */  lui       $a1, 0xfe36
/* 8FF930 802402C0 34A53C82 */  ori       $a1, $a1, 0x3c82
/* 8FF934 802402C4 0C0B210B */  jal       evt_get_float_variable
/* 8FF938 802402C8 E6000098 */   swc1     $f0, 0x98($s0)
/* 8FF93C 802402CC 0220202D */  daddu     $a0, $s1, $zero
/* 8FF940 802402D0 3C05FE36 */  lui       $a1, 0xfe36
/* 8FF944 802402D4 34A53C83 */  ori       $a1, $a1, 0x3c83
/* 8FF948 802402D8 0C0B210B */  jal       evt_get_float_variable
/* 8FF94C 802402DC E600009C */   swc1     $f0, 0x9c($s0)
/* 8FF950 802402E0 E60000A0 */  swc1      $f0, 0xa0($s0)
/* 8FF954 802402E4 2610000C */  addiu     $s0, $s0, 0xc
/* 8FF958 802402E8 8E220084 */  lw        $v0, 0x84($s1)
/* 8FF95C 802402EC 1440FFEB */  bnez      $v0, .L8024029C
/* 8FF960 802402F0 26520001 */   addiu    $s2, $s2, 1
/* 8FF964 802402F4 AE7201DC */  sw        $s2, 0x1dc($s3)
/* 8FF968 802402F8 8FBF0198 */  lw        $ra, 0x198($sp)
/* 8FF96C 802402FC 8FB30194 */  lw        $s3, 0x194($sp)
/* 8FF970 80240300 8FB20190 */  lw        $s2, 0x190($sp)
/* 8FF974 80240304 8FB1018C */  lw        $s1, 0x18c($sp)
/* 8FF978 80240308 8FB00188 */  lw        $s0, 0x188($sp)
/* 8FF97C 8024030C 03E00008 */  jr        $ra
/* 8FF980 80240310 27BD01A0 */   addiu    $sp, $sp, 0x1a0
