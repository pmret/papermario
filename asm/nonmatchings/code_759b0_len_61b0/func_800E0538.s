.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800E0538
/* 799E8 800E0538 3C058011 */  lui       $a1, %hi(gPlayerStatus)
/* 799EC 800E053C 24A5EFC8 */  addiu     $a1, $a1, %lo(gPlayerStatus)
/* 799F0 800E0540 8CA200C8 */  lw        $v0, 0xc8($a1)
/* 799F4 800E0544 1040000C */  beqz      $v0, .L800E0578
/* 799F8 800E0548 0000202D */   daddu    $a0, $zero, $zero
/* 799FC 800E054C 8C420000 */  lw        $v0, ($v0)
/* 79A00 800E0550 3C031000 */  lui       $v1, 0x1000
/* 79A04 800E0554 00431024 */  and       $v0, $v0, $v1
/* 79A08 800E0558 14400007 */  bnez      $v0, .L800E0578
/* 79A0C 800E055C 3C020200 */   lui      $v0, 0x200
/* 79A10 800E0560 8CA30000 */  lw        $v1, ($a1)
/* 79A14 800E0564 34422000 */  ori       $v0, $v0, 0x2000
/* 79A18 800E0568 00621824 */  and       $v1, $v1, $v0
/* 79A1C 800E056C 3C020200 */  lui       $v0, 0x200
/* 79A20 800E0570 00621826 */  xor       $v1, $v1, $v0
/* 79A24 800E0574 2C640001 */  sltiu     $a0, $v1, 1
.L800E0578:
/* 79A28 800E0578 03E00008 */  jr        $ra
/* 79A2C 800E057C 0080102D */   daddu    $v0, $a0, $zero
