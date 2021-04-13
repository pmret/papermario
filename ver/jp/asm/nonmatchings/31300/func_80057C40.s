.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80057C40
/* 33040 80057C40 0080382D */  daddu     $a3, $a0, $zero
/* 33044 80057C44 00A60018 */  mult      $a1, $a2
/* 33048 80057C48 2402FFF0 */  addiu     $v0, $zero, -0x10
/* 3304C 80057C4C 8CE50004 */  lw        $a1, 4($a3)
/* 33050 80057C50 8CE40008 */  lw        $a0, 8($a3)
/* 33054 80057C54 00004012 */  mflo      $t0
/* 33058 80057C58 2503000F */  addiu     $v1, $t0, 0xf
/* 3305C 80057C5C 00621824 */  and       $v1, $v1, $v0
/* 33060 80057C60 8CE20000 */  lw        $v0, ($a3)
/* 33064 80057C64 00A31821 */  addu      $v1, $a1, $v1
/* 33068 80057C68 00441021 */  addu      $v0, $v0, $a0
/* 3306C 80057C6C 0043102B */  sltu      $v0, $v0, $v1
/* 33070 80057C70 14400003 */  bnez      $v0, .L80057C80
/* 33074 80057C74 0000302D */   daddu    $a2, $zero, $zero
/* 33078 80057C78 00A0302D */  daddu     $a2, $a1, $zero
/* 3307C 80057C7C ACE30004 */  sw        $v1, 4($a3)
.L80057C80:
/* 33080 80057C80 03E00008 */  jr        $ra
/* 33084 80057C84 00C0102D */   daddu    $v0, $a2, $zero
