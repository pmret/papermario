.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel fio_flush_backups
/* 00644C 8002B04C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 006450 8002B050 AFB00010 */  sw    $s0, 0x10($sp)
/* 006454 8002B054 3C10800E */  lui   $s0, 0x800e
/* 006458 8002B058 261095E8 */  addiu $s0, $s0, -0x6a18
/* 00645C 8002B05C 3C058007 */  lui   $a1, 0x8007
/* 006460 8002B060 24A545D0 */  addiu $a1, $a1, 0x45d0
/* 006464 8002B064 AFBF0014 */  sw    $ra, 0x14($sp)
/* 006468 8002B068 0C01BB50 */  jal   strcpy
/* 00646C 8002B06C 0200202D */   daddu $a0, $s0, $zero
/* 006470 8002B070 2402FFFF */  addiu $v0, $zero, -1
/* 006474 8002B074 AE000030 */  sw    $zero, 0x30($s0)
/* 006478 8002B078 0C00ABD0 */  jal   fio_calc_header_checksum
/* 00647C 8002B07C AE020034 */   sw    $v0, 0x34($s0)
/* 006480 8002B080 24040006 */  addiu $a0, $zero, 6
/* 006484 8002B084 AE020030 */  sw    $v0, 0x30($s0)
/* 006488 8002B088 00021027 */  nor   $v0, $zero, $v0
/* 00648C 8002B08C 0C00AE87 */  jal   fio_erase_flash
/* 006490 8002B090 AE020034 */   sw    $v0, 0x34($s0)
/* 006494 8002B094 24040006 */  addiu $a0, $zero, 6
/* 006498 8002B098 0200282D */  daddu $a1, $s0, $zero
/* 00649C 8002B09C 0C00AE52 */  jal   fio_write_flash
/* 0064A0 8002B0A0 24060080 */   addiu $a2, $zero, 0x80
/* 0064A4 8002B0A4 0C00AE87 */  jal   fio_erase_flash
/* 0064A8 8002B0A8 24040007 */   addiu $a0, $zero, 7
/* 0064AC 8002B0AC 24040007 */  addiu $a0, $zero, 7
/* 0064B0 8002B0B0 0200282D */  daddu $a1, $s0, $zero
/* 0064B4 8002B0B4 0C00AE52 */  jal   fio_write_flash
/* 0064B8 8002B0B8 24060080 */   addiu $a2, $zero, 0x80
/* 0064BC 8002B0BC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0064C0 8002B0C0 8FB00010 */  lw    $s0, 0x10($sp)
/* 0064C4 8002B0C4 24020001 */  addiu $v0, $zero, 1
/* 0064C8 8002B0C8 03E00008 */  jr    $ra
/* 0064CC 8002B0CC 27BD0018 */   addiu $sp, $sp, 0x18

