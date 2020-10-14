.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005FE0C
/* 3B20C 8005FE0C 0000282D */  daddu     $a1, $zero, $zero
/* 3B210 8005FE10 24060004 */  addiu     $a2, $zero, 4
/* 3B214 8005FE14 3C03800B */  lui       $v1, 0x800b
/* 3B218 8005FE18 24631D47 */  addiu     $v1, $v1, 0x1d47
/* 3B21C 8005FE1C 00A0202D */  daddu     $a0, $a1, $zero
.L8005FE20:
/* 3B220 8005FE20 3C01800B */  lui       $at, 0x800b
/* 3B224 8005FE24 00240821 */  addu      $at, $at, $a0
/* 3B228 8005FE28 A0261D46 */  sb        $a2, 0x1d46($at)
/* 3B22C 8005FE2C 2484000A */  addiu     $a0, $a0, 0xa
/* 3B230 8005FE30 90620000 */  lbu       $v0, ($v1)
/* 3B234 8005FE34 24A50001 */  addiu     $a1, $a1, 1
/* 3B238 8005FE38 34420080 */  ori       $v0, $v0, 0x80
/* 3B23C 8005FE3C A0620000 */  sb        $v0, ($v1)
/* 3B240 8005FE40 2CA20004 */  sltiu     $v0, $a1, 4
/* 3B244 8005FE44 1440FFF6 */  bnez      $v0, .L8005FE20
/* 3B248 8005FE48 2463000A */   addiu    $v1, $v1, 0xa
/* 3B24C 8005FE4C 03E00008 */  jr        $ra
/* 3B250 8005FE50 0000102D */   daddu    $v0, $zero, $zero
