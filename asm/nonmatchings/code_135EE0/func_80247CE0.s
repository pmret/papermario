.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80247CE0
/* 13B020 80247CE0 004B1021 */  addu  $v0, $v0, $t3
/* 13B024 80247CE4 84420004 */  lh    $v0, 4($v0)
/* 13B028 80247CE8 3C0A8009 */  lui   $t2, 0x8009
/* 13B02C 80247CEC 254AA680 */  addiu $t2, $t2, -0x5980
/* 13B030 80247CF0 000210C0 */  sll   $v0, $v0, 3
