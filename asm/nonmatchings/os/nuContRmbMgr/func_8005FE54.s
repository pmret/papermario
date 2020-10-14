.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005FE54
/* 3B254 8005FE54 0000202D */  daddu     $a0, $zero, $zero
/* 3B258 8005FE58 3C03800B */  lui       $v1, 0x800b
/* 3B25C 8005FE5C 24631D47 */  addiu     $v1, $v1, 0x1d47
.L8005FE60:
/* 3B260 8005FE60 90620000 */  lbu       $v0, ($v1)
/* 3B264 8005FE64 24840001 */  addiu     $a0, $a0, 1
/* 3B268 8005FE68 3042007F */  andi      $v0, $v0, 0x7f
/* 3B26C 8005FE6C A0620000 */  sb        $v0, ($v1)
/* 3B270 8005FE70 2C820004 */  sltiu     $v0, $a0, 4
/* 3B274 8005FE74 1440FFFA */  bnez      $v0, .L8005FE60
/* 3B278 8005FE78 2463000A */   addiu    $v1, $v1, 0xa
/* 3B27C 8005FE7C 03E00008 */  jr        $ra
/* 3B280 8005FE80 0000102D */   daddu    $v0, $zero, $zero
/* 3B284 8005FE84 00000000 */  nop       
/* 3B288 8005FE88 00000000 */  nop       
/* 3B28C 8005FE8C 00000000 */  nop       
