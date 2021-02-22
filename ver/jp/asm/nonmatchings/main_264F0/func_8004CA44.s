.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004CA44
/* 27E44 8004CA44 94A300B8 */  lhu       $v1, 0xb8($a1)
/* 27E48 8004CA48 84C2005C */  lh        $v0, 0x5c($a2)
/* 27E4C 8004CA4C 00620018 */  mult      $v1, $v0
/* 27E50 8004CA50 00003812 */  mflo      $a3
/* 27E54 8004CA54 90C3009F */  lbu       $v1, 0x9f($a2)
/* 27E58 8004CA58 000713C3 */  sra       $v0, $a3, 0xf
/* 27E5C 8004CA5C 00430018 */  mult      $v0, $v1
/* 27E60 8004CA60 00003812 */  mflo      $a3
/* 27E64 8004CA64 84C3006C */  lh        $v1, 0x6c($a2)
/* 27E68 8004CA68 000711C3 */  sra       $v0, $a3, 7
/* 27E6C 8004CA6C 00430018 */  mult      $v0, $v1
/* 27E70 8004CA70 90C2009A */  lbu       $v0, 0x9a($a2)
/* 27E74 8004CA74 30420004 */  andi      $v0, $v0, 4
/* 27E78 8004CA78 00003812 */  mflo      $a3
/* 27E7C 8004CA7C 14400004 */  bnez      $v0, .L8004CA90
/* 27E80 8004CA80 00071BC3 */   sra      $v1, $a3, 0xf
/* 27E84 8004CA84 84C200A6 */  lh        $v0, 0xa6($a2)
/* 27E88 8004CA88 14400003 */  bnez      $v0, .L8004CA98
/* 27E8C 8004CA8C 00620018 */   mult     $v1, $v0
.L8004CA90:
/* 27E90 8004CA90 03E00008 */  jr        $ra
/* 27E94 8004CA94 A4830040 */   sh       $v1, 0x40($a0)
.L8004CA98:
/* 27E98 8004CA98 00003812 */  mflo      $a3
/* 27E9C 8004CA9C 000713C3 */  sra       $v0, $a3, 0xf
/* 27EA0 8004CAA0 03E00008 */  jr        $ra
/* 27EA4 8004CAA4 A4820040 */   sh       $v0, 0x40($a0)
