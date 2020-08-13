.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8004D484
/* 028884 8004D484 308200CC */  andi  $v0, $a0, 0xcc
/* 028888 8004D488 00021083 */  sra   $v0, $v0, 2
/* 02888C 8004D48C 30840013 */  andi  $a0, $a0, 0x13
/* 028890 8004D490 00042080 */  sll   $a0, $a0, 2
/* 028894 8004D494 00441021 */  addu  $v0, $v0, $a0
/* 028898 8004D498 00A20018 */  mult  $a1, $v0
/* 02889C 8004D49C 00001812 */  mflo  $v1
/* 0288A0 8004D4A0 34028000 */  ori   $v0, $zero, 0x8000
/* 0288A4 8004D4A4 00431023 */  subu  $v0, $v0, $v1
/* 0288A8 8004D4A8 00C20018 */  mult  $a2, $v0
/* 0288AC 8004D4AC 00001812 */  mflo  $v1
/* 0288B0 8004D4B0 000313C3 */  sra   $v0, $v1, 0xf
/* 0288B4 8004D4B4 03E00008 */  jr    $ra
/* 0288B8 8004D4B8 304200FF */   andi  $v0, $v0, 0xff

