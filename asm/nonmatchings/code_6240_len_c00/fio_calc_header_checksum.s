.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel fio_calc_header_checksum
/* 006340 8002AF40 0000282D */  daddu $a1, $zero, $zero
/* 006344 8002AF44 3C04800E */  lui   $a0, 0x800e
/* 006348 8002AF48 248495E8 */  addiu $a0, $a0, -0x6a18
/* 00634C 8002AF4C 00A0182D */  daddu $v1, $a1, $zero
.L8002AF50:
/* 006350 8002AF50 24630001 */  addiu $v1, $v1, 1
/* 006354 8002AF54 8C820000 */  lw    $v0, ($a0)
/* 006358 8002AF58 00A22821 */  addu  $a1, $a1, $v0
/* 00635C 8002AF5C 2C620020 */  sltiu $v0, $v1, 0x20
/* 006360 8002AF60 1440FFFB */  bnez  $v0, .L8002AF50
/* 006364 8002AF64 24840004 */   addiu $a0, $a0, 4
/* 006368 8002AF68 03E00008 */  jr    $ra
/* 00636C 8002AF6C 00A0102D */   daddu $v0, $a1, $zero

