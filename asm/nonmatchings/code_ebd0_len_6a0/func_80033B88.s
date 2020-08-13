.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"
glabel func_80033B88
/* 00EF88 80033B88 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 00EF8C 80033B8C 3C02800A */  lui   $v0, 0x800a
/* 00EF90 80033B90 2442A650 */  addiu $v0, $v0, -0x59b0
/* 00EF94 80033B94 AFBF0010 */  sw    $ra, 0x10($sp)
/* 00EF98 80033B98 8C430000 */  lw    $v1, ($v0)
/* 00EF9C 80033B9C 34630008 */  ori   $v1, $v1, 8
/* 00EFA0 80033BA0 0C018028 */  jal   nuContRmbForceStop
/* 00EFA4 80033BA4 AC430000 */   sw    $v1, ($v0)
/* 00EFA8 80033BA8 8FBF0010 */  lw    $ra, 0x10($sp)
/* 00EFAC 80033BAC 24020005 */  addiu $v0, $zero, 5
/* 00EFB0 80033BB0 3C01800A */  lui   $at, 0x800a
/* 00EFB4 80033BB4 A0220900 */  sb    $v0, 0x900($at)
/* 00EFB8 80033BB8 03E00008 */  jr    $ra
/* 00EFBC 80033BBC 27BD0018 */   addiu $sp, $sp, 0x18