.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80122F24
/* 0B9624 80122F24 2402F7FF */  addiu $v0, $zero, -0x801
/* 0B9628 80122F28 00822024 */  and   $a0, $a0, $v0
/* 0B962C 80122F2C 3C028015 */  lui   $v0, 0x8015
/* 0B9630 80122F30 8C424370 */  lw    $v0, 0x4370($v0)
/* 0B9634 80122F34 00042080 */  sll   $a0, $a0, 2
/* 0B9638 80122F38 00822021 */  addu  $a0, $a0, $v0
/* 0B963C 80122F3C 8C840000 */  lw    $a0, ($a0)
/* 0B9640 80122F40 10800006 */  beqz  $a0, .L80122F5C
/* 0B9644 80122F44 00000000 */   nop   
/* 0B9648 80122F48 8C830000 */  lw    $v1, ($a0)
/* 0B964C 80122F4C 10600003 */  beqz  $v1, .L80122F5C
/* 0B9650 80122F50 00051027 */   nor   $v0, $zero, $a1
/* 0B9654 80122F54 00621024 */  and   $v0, $v1, $v0
/* 0B9658 80122F58 AC820000 */  sw    $v0, ($a0)
.L80122F5C:
/* 0B965C 80122F5C 03E00008 */  jr    $ra
/* 0B9660 80122F60 00000000 */   nop   

