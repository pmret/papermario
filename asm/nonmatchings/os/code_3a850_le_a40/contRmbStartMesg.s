.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel contRmbStartMesg
/* 03B158 8005FD58 8C84000C */  lw    $a0, 0xc($a0)
/* 03B15C 8005FD5C 90830000 */  lbu   $v1, ($a0)
/* 03B160 8005FD60 8C850008 */  lw    $a1, 8($a0)
/* 03B164 8005FD64 00031080 */  sll   $v0, $v1, 2
/* 03B168 8005FD68 00431021 */  addu  $v0, $v0, $v1
/* 03B16C 8005FD6C 90A30006 */  lbu   $v1, 6($a1)
/* 03B170 8005FD70 00021040 */  sll   $v0, $v0, 1
/* 03B174 8005FD74 3C01800B */  lui   $at, 0x800b
/* 03B178 8005FD78 00220821 */  addu  $at, $at, $v0
/* 03B17C 8005FD7C A0231D46 */  sb    $v1, 0x1d46($at)
/* 03B180 8005FD80 90830000 */  lbu   $v1, ($a0)
/* 03B184 8005FD84 00031080 */  sll   $v0, $v1, 2
/* 03B188 8005FD88 00431021 */  addu  $v0, $v0, $v1
/* 03B18C 8005FD8C 94A30002 */  lhu   $v1, 2($a1)
/* 03B190 8005FD90 00021040 */  sll   $v0, $v0, 1
/* 03B194 8005FD94 3C01800B */  lui   $at, 0x800b
/* 03B198 8005FD98 00220821 */  addu  $at, $at, $v0
/* 03B19C 8005FD9C A4231D42 */  sh    $v1, 0x1d42($at)
/* 03B1A0 8005FDA0 90830000 */  lbu   $v1, ($a0)
/* 03B1A4 8005FDA4 00031080 */  sll   $v0, $v1, 2
/* 03B1A8 8005FDA8 00431021 */  addu  $v0, $v0, $v1
/* 03B1AC 8005FDAC 94A30000 */  lhu   $v1, ($a1)
/* 03B1B0 8005FDB0 00021040 */  sll   $v0, $v0, 1
/* 03B1B4 8005FDB4 3C01800B */  lui   $at, 0x800b
/* 03B1B8 8005FDB8 00220821 */  addu  $at, $at, $v0
/* 03B1BC 8005FDBC A4231D40 */  sh    $v1, 0x1d40($at)
/* 03B1C0 8005FDC0 90830000 */  lbu   $v1, ($a0)
/* 03B1C4 8005FDC4 00031080 */  sll   $v0, $v1, 2
/* 03B1C8 8005FDC8 00431021 */  addu  $v0, $v0, $v1
/* 03B1CC 8005FDCC 00021040 */  sll   $v0, $v0, 1
/* 03B1D0 8005FDD0 3C01800B */  lui   $at, 0x800b
/* 03B1D4 8005FDD4 00220821 */  addu  $at, $at, $v0
/* 03B1D8 8005FDD8 A4201D44 */  sh    $zero, 0x1d44($at)
/* 03B1DC 8005FDDC 03E00008 */  jr    $ra
/* 03B1E0 8005FDE0 0000102D */   daddu $v0, $zero, $zero

/* 03B1E4 8005FDE4 8C82000C */  lw    $v0, 0xc($a0)
/* 03B1E8 8005FDE8 90430000 */  lbu   $v1, ($v0)
/* 03B1EC 8005FDEC 00031080 */  sll   $v0, $v1, 2
/* 03B1F0 8005FDF0 00431021 */  addu  $v0, $v0, $v1
/* 03B1F4 8005FDF4 00021040 */  sll   $v0, $v0, 1
/* 03B1F8 8005FDF8 3C01800B */  lui   $at, 0x800b
/* 03B1FC 8005FDFC 00220821 */  addu  $at, $at, $v0
/* 03B200 8005FE00 A4201D42 */  sh    $zero, 0x1d42($at)
/* 03B204 8005FE04 03E00008 */  jr    $ra
/* 03B208 8005FE08 0000102D */   daddu $v0, $zero, $zero

/* 03B20C 8005FE0C 0000282D */  daddu $a1, $zero, $zero
/* 03B210 8005FE10 24060004 */  addiu $a2, $zero, 4
/* 03B214 8005FE14 3C03800B */  lui   $v1, 0x800b
/* 03B218 8005FE18 24631D47 */  addiu $v1, $v1, 0x1d47
/* 03B21C 8005FE1C 00A0202D */  daddu $a0, $a1, $zero
.L8005FE20:
/* 03B220 8005FE20 3C01800B */  lui   $at, 0x800b
/* 03B224 8005FE24 00240821 */  addu  $at, $at, $a0
/* 03B228 8005FE28 A0261D46 */  sb    $a2, 0x1d46($at)
/* 03B22C 8005FE2C 2484000A */  addiu $a0, $a0, 0xa
/* 03B230 8005FE30 90620000 */  lbu   $v0, ($v1)
/* 03B234 8005FE34 24A50001 */  addiu $a1, $a1, 1
/* 03B238 8005FE38 34420080 */  ori   $v0, $v0, 0x80
/* 03B23C 8005FE3C A0620000 */  sb    $v0, ($v1)
/* 03B240 8005FE40 2CA20004 */  sltiu $v0, $a1, 4
/* 03B244 8005FE44 1440FFF6 */  bnez  $v0, .L8005FE20
/* 03B248 8005FE48 2463000A */   addiu $v1, $v1, 0xa
/* 03B24C 8005FE4C 03E00008 */  jr    $ra
/* 03B250 8005FE50 0000102D */   daddu $v0, $zero, $zero

/* 03B254 8005FE54 0000202D */  daddu $a0, $zero, $zero
/* 03B258 8005FE58 3C03800B */  lui   $v1, 0x800b
/* 03B25C 8005FE5C 24631D47 */  addiu $v1, $v1, 0x1d47
.L8005FE60:
/* 03B260 8005FE60 90620000 */  lbu   $v0, ($v1)
/* 03B264 8005FE64 24840001 */  addiu $a0, $a0, 1
/* 03B268 8005FE68 3042007F */  andi  $v0, $v0, 0x7f
/* 03B26C 8005FE6C A0620000 */  sb    $v0, ($v1)
/* 03B270 8005FE70 2C820004 */  sltiu $v0, $a0, 4
/* 03B274 8005FE74 1440FFFA */  bnez  $v0, .L8005FE60
/* 03B278 8005FE78 2463000A */   addiu $v1, $v1, 0xa
/* 03B27C 8005FE7C 03E00008 */  jr    $ra
/* 03B280 8005FE80 0000102D */   daddu $v0, $zero, $zero

/* 03B284 8005FE84 00000000 */  nop   
/* 03B288 8005FE88 00000000 */  nop   
/* 03B28C 8005FE8C 00000000 */  nop   


