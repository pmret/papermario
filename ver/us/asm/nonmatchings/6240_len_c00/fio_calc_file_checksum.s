.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fio_calc_file_checksum
/* 64D0 8002B0D0 0000282D */  daddu     $a1, $zero, $zero
/* 64D4 8002B0D4 00A0182D */  daddu     $v1, $a1, $zero
.L8002B0D8:
/* 64D8 8002B0D8 24630001 */  addiu     $v1, $v1, 1
/* 64DC 8002B0DC 8C820000 */  lw        $v0, ($a0)
/* 64E0 8002B0E0 00A22821 */  addu      $a1, $a1, $v0
/* 64E4 8002B0E4 2C6204E0 */  sltiu     $v0, $v1, 0x4e0
/* 64E8 8002B0E8 1440FFFB */  bnez      $v0, .L8002B0D8
/* 64EC 8002B0EC 24840004 */   addiu    $a0, $a0, 4
/* 64F0 8002B0F0 03E00008 */  jr        $ra
/* 64F4 8002B0F4 00A0102D */   daddu    $v0, $a1, $zero
