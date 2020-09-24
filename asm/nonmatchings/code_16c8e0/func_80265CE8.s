.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80265CE8
/* 1945C8 80265CE8 14800006 */  bnez      $a0, .L80265D04
/* 1945CC 80265CEC 0000102D */   daddu    $v0, $zero, $zero
/* 1945D0 80265CF0 03E00008 */  jr        $ra
/* 1945D4 80265CF4 00000000 */   nop      
.L80265CF8:
/* 1945D8 80265CF8 8C830004 */  lw        $v1, 4($a0)
/* 1945DC 80265CFC 03E00008 */  jr        $ra
/* 1945E0 80265D00 0060102D */   daddu    $v0, $v1, $zero
.L80265D04:
/* 1945E4 80265D04 8C820000 */  lw        $v0, ($a0)
/* 1945E8 80265D08 1040000C */  beqz      $v0, .L80265D3C
/* 1945EC 80265D0C 0000182D */   daddu    $v1, $zero, $zero
/* 1945F0 80265D10 24060001 */  addiu     $a2, $zero, 1
/* 1945F4 80265D14 8C820000 */  lw        $v0, ($a0)
.L80265D18:
/* 1945F8 80265D18 14460002 */  bne       $v0, $a2, .L80265D24
/* 1945FC 80265D1C 00000000 */   nop      
/* 194600 80265D20 8C830004 */  lw        $v1, 4($a0)
.L80265D24:
/* 194604 80265D24 1045FFF4 */  beq       $v0, $a1, .L80265CF8
/* 194608 80265D28 00000000 */   nop      
/* 19460C 80265D2C 24840008 */  addiu     $a0, $a0, 8
/* 194610 80265D30 8C820000 */  lw        $v0, ($a0)
/* 194614 80265D34 1440FFF8 */  bnez      $v0, .L80265D18
/* 194618 80265D38 00000000 */   nop      
.L80265D3C:
/* 19461C 80265D3C 03E00008 */  jr        $ra
/* 194620 80265D40 0060102D */   daddu    $v0, $v1, $zero
