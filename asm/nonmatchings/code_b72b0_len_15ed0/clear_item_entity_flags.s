.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel clear_item_entity_flags
/* 0CA888 80134188 3C028015 */  lui   $v0, 0x8015
/* 0CA88C 8013418C 8C4265A0 */  lw    $v0, 0x65a0($v0)
/* 0CA890 80134190 00042080 */  sll   $a0, $a0, 2
/* 0CA894 80134194 00822021 */  addu  $a0, $a0, $v0
/* 0CA898 80134198 8C830000 */  lw    $v1, ($a0)
/* 0CA89C 8013419C 8C620000 */  lw    $v0, ($v1)
/* 0CA8A0 801341A0 00052827 */  nor   $a1, $zero, $a1
/* 0CA8A4 801341A4 00451024 */  and   $v0, $v0, $a1
/* 0CA8A8 801341A8 03E00008 */  jr    $ra
/* 0CA8AC 801341AC AC620000 */   sw    $v0, ($v1)

/* 0CA8B0 801341B0 00042080 */  sll   $a0, $a0, 2
/* 0CA8B4 801341B4 3C028015 */  lui   $v0, 0x8015
/* 0CA8B8 801341B8 8C4265A0 */  lw    $v0, 0x65a0($v0)
/* 0CA8BC 801341BC 3C05800A */  lui   $a1, 0x800a
/* 0CA8C0 801341C0 24A5A650 */  addiu $a1, $a1, -0x59b0
/* 0CA8C4 801341C4 00822021 */  addu  $a0, $a0, $v0
/* 0CA8C8 801341C8 8C840000 */  lw    $a0, ($a0)
/* 0CA8CC 801341CC 8CA20000 */  lw    $v0, ($a1)
/* 0CA8D0 801341D0 8C830000 */  lw    $v1, ($a0)
/* 0CA8D4 801341D4 34420040 */  ori   $v0, $v0, 0x40
/* 0CA8D8 801341D8 ACA20000 */  sw    $v0, ($a1)
/* 0CA8DC 801341DC 34630100 */  ori   $v1, $v1, 0x100
/* 0CA8E0 801341E0 03E00008 */  jr    $ra
/* 0CA8E4 801341E4 AC830000 */   sw    $v1, ($a0)

