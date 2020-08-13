.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel get_script_by_id
/* 0E9158 802C47A8 0000302D */  daddu $a2, $zero, $zero
/* 0E915C 802C47AC 3C05802E */  lui   $a1, 0x802e
/* 0E9160 802C47B0 8CA5A890 */  lw    $a1, -0x5770($a1)
.L802C47B4:
/* 0E9164 802C47B4 8CA30000 */  lw    $v1, ($a1)
/* 0E9168 802C47B8 10600006 */  beqz  $v1, .L802C47D4
/* 0E916C 802C47BC 24C60001 */   addiu $a2, $a2, 1
/* 0E9170 802C47C0 8C620144 */  lw    $v0, 0x144($v1)
/* 0E9174 802C47C4 14440004 */  bne   $v0, $a0, .L802C47D8
/* 0E9178 802C47C8 28C20080 */   slti  $v0, $a2, 0x80
/* 0E917C 802C47CC 03E00008 */  jr    $ra
/* 0E9180 802C47D0 0060102D */   daddu $v0, $v1, $zero

.L802C47D4:
/* 0E9184 802C47D4 28C20080 */  slti  $v0, $a2, 0x80
.L802C47D8:
/* 0E9188 802C47D8 1440FFF6 */  bnez  $v0, .L802C47B4
/* 0E918C 802C47DC 24A50004 */   addiu $a1, $a1, 4
/* 0E9190 802C47E0 03E00008 */  jr    $ra
/* 0E9194 802C47E4 0000102D */   daddu $v0, $zero, $zero

