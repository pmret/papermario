.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80047BE4
/* 022FE4 80047BE4 00041040 */  sll   $v0, $a0, 1
/* 022FE8 80047BE8 00441021 */  addu  $v0, $v0, $a0
/* 022FEC 80047BEC 00021080 */  sll   $v0, $v0, 2
/* 022FF0 80047BF0 00441023 */  subu  $v0, $v0, $a0
/* 022FF4 80047BF4 3C03800A */  lui   $v1, 0x800a
/* 022FF8 80047BF8 8C630F44 */  lw    $v1, 0xf44($v1)
/* 022FFC 80047BFC 00021100 */  sll   $v0, $v0, 4
/* 023000 80047C00 00621821 */  addu  $v1, $v1, $v0
/* 023004 80047C04 8C620000 */  lw    $v0, ($v1)
/* 023008 80047C08 34420020 */  ori   $v0, $v0, 0x20
/* 02300C 80047C0C 03E00008 */  jr    $ra
/* 023010 80047C10 AC620000 */   sw    $v0, ($v1)

