.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_800479A0
/* 022DA0 800479A0 00041040 */  sll   $v0, $a0, 1
/* 022DA4 800479A4 00441021 */  addu  $v0, $v0, $a0
/* 022DA8 800479A8 00021080 */  sll   $v0, $v0, 2
/* 022DAC 800479AC 00441023 */  subu  $v0, $v0, $a0
/* 022DB0 800479B0 3C03800A */  lui   $v1, 0x800a
/* 022DB4 800479B4 8C630F44 */  lw    $v1, 0xf44($v1)
/* 022DB8 800479B8 00021100 */  sll   $v0, $v0, 4
/* 022DBC 800479BC 00622021 */  addu  $a0, $v1, $v0
/* 022DC0 800479C0 80820048 */  lb    $v0, 0x48($a0)
/* 022DC4 800479C4 1040000C */  beqz  $v0, .L800479F8
/* 022DC8 800479C8 90830048 */   lbu   $v1, 0x48($a0)
/* 022DCC 800479CC 80820049 */  lb    $v0, 0x49($a0)
/* 022DD0 800479D0 14400009 */  bnez  $v0, .L800479F8
/* 022DD4 800479D4 24020001 */   addiu $v0, $zero, 1
/* 022DD8 800479D8 A0830049 */  sb    $v1, 0x49($a0)
/* 022DDC 800479DC 8C830050 */  lw    $v1, 0x50($a0)
/* 022DE0 800479E0 A082004B */  sb    $v0, 0x4b($a0)
/* 022DE4 800479E4 2402000A */  addiu $v0, $zero, 0xa
/* 022DE8 800479E8 A0800048 */  sb    $zero, 0x48($a0)
/* 022DEC 800479EC A080004A */  sb    $zero, 0x4a($a0)
/* 022DF0 800479F0 A082004D */  sb    $v0, 0x4d($a0)
/* 022DF4 800479F4 AC830054 */  sw    $v1, 0x54($a0)
.L800479F8:
/* 022DF8 800479F8 03E00008 */  jr    $ra
/* 022DFC 800479FC 00000000 */   nop   

