.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel lookup_status_duration_mod
/* 1947CC 80265EEC 0080182D */  daddu     $v1, $a0, $zero
/* 1947D0 80265EF0 8C620000 */  lw        $v0, ($v1)
/* 1947D4 80265EF4 1040000F */  beqz      $v0, .L80265F34
/* 1947D8 80265EF8 0000302D */   daddu    $a2, $zero, $zero
/* 1947DC 80265EFC 2407001F */  addiu     $a3, $zero, 0x1f
/* 1947E0 80265F00 24840004 */  addiu     $a0, $a0, 4
/* 1947E4 80265F04 8C620000 */  lw        $v0, ($v1)
.L80265F08:
/* 1947E8 80265F08 14470002 */  bne       $v0, $a3, .L80265F14
/* 1947EC 80265F0C 00000000 */   nop
/* 1947F0 80265F10 8C860000 */  lw        $a2, ($a0)
.L80265F14:
/* 1947F4 80265F14 14450004 */  bne       $v0, $a1, .L80265F28
/* 1947F8 80265F18 24630008 */   addiu    $v1, $v1, 8
/* 1947FC 80265F1C 8C860000 */  lw        $a2, ($a0)
/* 194800 80265F20 03E00008 */  jr        $ra
/* 194804 80265F24 00C0102D */   daddu    $v0, $a2, $zero
.L80265F28:
/* 194808 80265F28 8C620000 */  lw        $v0, ($v1)
/* 19480C 80265F2C 1440FFF6 */  bnez      $v0, .L80265F08
/* 194810 80265F30 24840008 */   addiu    $a0, $a0, 8
.L80265F34:
/* 194814 80265F34 00C0102D */  daddu     $v0, $a2, $zero
/* 194818 80265F38 03E00008 */  jr        $ra
/* 19481C 80265F3C 00000000 */   nop
