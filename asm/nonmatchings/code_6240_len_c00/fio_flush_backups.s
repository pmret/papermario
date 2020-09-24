.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fio_flush_backups
/* 644C 8002B04C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 6450 8002B050 AFB00010 */  sw        $s0, 0x10($sp)
/* 6454 8002B054 3C10800E */  lui       $s0, 0x800e
/* 6458 8002B058 261095E8 */  addiu     $s0, $s0, -0x6a18
/* 645C 8002B05C 3C058007 */  lui       $a1, 0x8007
/* 6460 8002B060 24A545D0 */  addiu     $a1, $a1, 0x45d0
/* 6464 8002B064 AFBF0014 */  sw        $ra, 0x14($sp)
/* 6468 8002B068 0C01BB50 */  jal       strcpy
/* 646C 8002B06C 0200202D */   daddu    $a0, $s0, $zero
/* 6470 8002B070 2402FFFF */  addiu     $v0, $zero, -1
/* 6474 8002B074 AE000030 */  sw        $zero, 0x30($s0)
/* 6478 8002B078 0C00ABD0 */  jal       fio_calc_header_checksum
/* 647C 8002B07C AE020034 */   sw       $v0, 0x34($s0)
/* 6480 8002B080 24040006 */  addiu     $a0, $zero, 6
/* 6484 8002B084 AE020030 */  sw        $v0, 0x30($s0)
/* 6488 8002B088 00021027 */  nor       $v0, $zero, $v0
/* 648C 8002B08C 0C00AE87 */  jal       fio_erase_flash
/* 6490 8002B090 AE020034 */   sw       $v0, 0x34($s0)
/* 6494 8002B094 24040006 */  addiu     $a0, $zero, 6
/* 6498 8002B098 0200282D */  daddu     $a1, $s0, $zero
/* 649C 8002B09C 0C00AE52 */  jal       fio_write_flash
/* 64A0 8002B0A0 24060080 */   addiu    $a2, $zero, 0x80
/* 64A4 8002B0A4 0C00AE87 */  jal       fio_erase_flash
/* 64A8 8002B0A8 24040007 */   addiu    $a0, $zero, 7
/* 64AC 8002B0AC 24040007 */  addiu     $a0, $zero, 7
/* 64B0 8002B0B0 0200282D */  daddu     $a1, $s0, $zero
/* 64B4 8002B0B4 0C00AE52 */  jal       fio_write_flash
/* 64B8 8002B0B8 24060080 */   addiu    $a2, $zero, 0x80
/* 64BC 8002B0BC 8FBF0014 */  lw        $ra, 0x14($sp)
/* 64C0 8002B0C0 8FB00010 */  lw        $s0, 0x10($sp)
/* 64C4 8002B0C4 24020001 */  addiu     $v0, $zero, 1
/* 64C8 8002B0C8 03E00008 */  jr        $ra
/* 64CC 8002B0CC 27BD0018 */   addiu    $sp, $sp, 0x18
