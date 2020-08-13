.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel poll_rumble
/* 0042E0 80028EE0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0042E4 80028EE4 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0042E8 80028EE8 0C017FBC */  jal   nuContRmbCheck
/* 0042EC 80028EEC 0000202D */   daddu $a0, $zero, $zero
/* 0042F0 80028EF0 0000202D */  daddu $a0, $zero, $zero
/* 0042F4 80028EF4 0C017FE4 */  jal   nuContRmbModeSet
/* 0042F8 80028EF8 24050002 */   addiu $a1, $zero, 2
/* 0042FC 80028EFC 8FBF0010 */  lw    $ra, 0x10($sp)
/* 004300 80028F00 03E00008 */  jr    $ra
/* 004304 80028F04 27BD0018 */   addiu $sp, $sp, 0x18

