.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel get_trigger_by_id
/* 0DC3D0 80145CD0 3C028016 */  lui   $v0, 0x8016
/* 0DC3D4 80145CD4 8C429390 */  lw    $v0, -0x6c70($v0)
/* 0DC3D8 80145CD8 00042080 */  sll   $a0, $a0, 2
/* 0DC3DC 80145CDC 00822021 */  addu  $a0, $a0, $v0
/* 0DC3E0 80145CE0 03E00008 */  jr    $ra
/* 0DC3E4 80145CE4 8C820000 */   lw    $v0, ($a0)

