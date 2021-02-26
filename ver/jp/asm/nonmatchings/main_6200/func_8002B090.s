.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002B090
/* 6490 8002B090 0000282D */  daddu     $a1, $zero, $zero
/* 6494 8002B094 00A0182D */  daddu     $v1, $a1, $zero
.L8002B098:
/* 6498 8002B098 24630001 */  addiu     $v1, $v1, 1
/* 649C 8002B09C 8C820000 */  lw        $v0, ($a0)
/* 64A0 8002B0A0 00A22821 */  addu      $a1, $a1, $v0
/* 64A4 8002B0A4 2C6204E0 */  sltiu     $v0, $v1, 0x4e0
/* 64A8 8002B0A8 1440FFFB */  bnez      $v0, .L8002B098
/* 64AC 8002B0AC 24840004 */   addiu    $a0, $a0, 4
/* 64B0 8002B0B0 03E00008 */  jr        $ra
/* 64B4 8002B0B4 00A0102D */   daddu    $v0, $a1, $zero
