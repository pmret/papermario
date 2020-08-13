.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel get_npc_by_index
/* 013EDC 80038ADC 2402F7FF */  addiu $v0, $zero, -0x801
/* 013EE0 80038AE0 00822024 */  and   $a0, $a0, $v0
/* 013EE4 80038AE4 3C02800A */  lui   $v0, 0x800a
/* 013EE8 80038AE8 8C420B90 */  lw    $v0, 0xb90($v0)
/* 013EEC 80038AEC 00042080 */  sll   $a0, $a0, 2
/* 013EF0 80038AF0 00822021 */  addu  $a0, $a0, $v0
/* 013EF4 80038AF4 03E00008 */  jr    $ra
/* 013EF8 80038AF8 8C820000 */   lw    $v0, ($a0)

