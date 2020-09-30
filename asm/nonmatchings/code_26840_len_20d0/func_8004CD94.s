.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004CD94
/* 28194 8004CD94 94A300B8 */  lhu       $v1, 0xb8($a1)
/* 28198 8004CD98 84C2005C */  lh        $v0, 0x5c($a2)
/* 2819C 8004CD9C 00620018 */  mult      $v1, $v0
/* 281A0 8004CDA0 00003812 */  mflo      $a3
/* 281A4 8004CDA4 90C3009F */  lbu       $v1, 0x9f($a2)
/* 281A8 8004CDA8 000713C3 */  sra       $v0, $a3, 0xf
/* 281AC 8004CDAC 00430018 */  mult      $v0, $v1
/* 281B0 8004CDB0 00003812 */  mflo      $a3
/* 281B4 8004CDB4 84C3006C */  lh        $v1, 0x6c($a2)
/* 281B8 8004CDB8 000711C3 */  sra       $v0, $a3, 7
/* 281BC 8004CDBC 00430018 */  mult      $v0, $v1
/* 281C0 8004CDC0 90C2009A */  lbu       $v0, 0x9a($a2)
/* 281C4 8004CDC4 30420004 */  andi      $v0, $v0, 4
/* 281C8 8004CDC8 00003812 */  mflo      $a3
/* 281CC 8004CDCC 14400004 */  bnez      $v0, .L8004CDE0
/* 281D0 8004CDD0 00071BC3 */   sra      $v1, $a3, 0xf
/* 281D4 8004CDD4 84C200A6 */  lh        $v0, 0xa6($a2)
/* 281D8 8004CDD8 14400003 */  bnez      $v0, .L8004CDE8
/* 281DC 8004CDDC 00620018 */   mult     $v1, $v0
.L8004CDE0:
/* 281E0 8004CDE0 03E00008 */  jr        $ra
/* 281E4 8004CDE4 A4830040 */   sh       $v1, 0x40($a0)
.L8004CDE8:
/* 281E8 8004CDE8 00003812 */  mflo      $a3
/* 281EC 8004CDEC 000713C3 */  sra       $v0, $a3, 0xf
/* 281F0 8004CDF0 03E00008 */  jr        $ra
/* 281F4 8004CDF4 A4820040 */   sh       $v0, 0x40($a0)
