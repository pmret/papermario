.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fio_has_valid_backup
/* 63D8 8002AFD8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 63DC 8002AFDC 24040006 */  addiu     $a0, $zero, 6
/* 63E0 8002AFE0 AFB00010 */  sw        $s0, 0x10($sp)
/* 63E4 8002AFE4 3C10800E */  lui       $s0, %hi(D_800D95E8)
/* 63E8 8002AFE8 261095E8 */  addiu     $s0, $s0, %lo(D_800D95E8)
/* 63EC 8002AFEC 0200282D */  daddu     $a1, $s0, $zero
/* 63F0 8002AFF0 AFBF0014 */  sw        $ra, 0x14($sp)
/* 63F4 8002AFF4 0C00AE1A */  jal       fio_read_flash
/* 63F8 8002AFF8 24060080 */   addiu    $a2, $zero, 0x80
/* 63FC 8002AFFC 0C00ABDC */  jal       fio_validate_header_checksums
/* 6400 8002B000 00000000 */   nop      
/* 6404 8002B004 1440000D */  bnez      $v0, .L8002B03C
/* 6408 8002B008 24020001 */   addiu    $v0, $zero, 1
/* 640C 8002B00C 24040007 */  addiu     $a0, $zero, 7
/* 6410 8002B010 0200282D */  daddu     $a1, $s0, $zero
/* 6414 8002B014 0C00AE1A */  jal       fio_read_flash
/* 6418 8002B018 24060080 */   addiu    $a2, $zero, 0x80
/* 641C 8002B01C 0C00ABDC */  jal       fio_validate_header_checksums
/* 6420 8002B020 00000000 */   nop      
/* 6424 8002B024 14400005 */  bnez      $v0, .L8002B03C
/* 6428 8002B028 24020001 */   addiu    $v0, $zero, 1
/* 642C 8002B02C 0200202D */  daddu     $a0, $s0, $zero
/* 6430 8002B030 0C01925C */  jal       bzero
/* 6434 8002B034 24050080 */   addiu    $a1, $zero, 0x80
/* 6438 8002B038 0000102D */  daddu     $v0, $zero, $zero
.L8002B03C:
/* 643C 8002B03C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 6440 8002B040 8FB00010 */  lw        $s0, 0x10($sp)
/* 6444 8002B044 03E00008 */  jr        $ra
/* 6448 8002B048 27BD0018 */   addiu    $sp, $sp, 0x18
