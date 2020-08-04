.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel bzero
/* 03FD70 80064970 00041823 */  negu  $v1, $a0
/* 03FD74 80064974 28A1000C */  slti  $at, $a1, 0xc
/* 03FD78 80064978 1420001D */  bnez  $at, .L800649F0
/* 03FD7C 8006497C 00000000 */   nop   
/* 03FD80 80064980 30630003 */  andi  $v1, $v1, 3
/* 03FD84 80064984 10600003 */  beqz  $v1, .L80064994
/* 03FD88 80064988 00A32823 */   subu  $a1, $a1, $v1
/* 03FD8C 8006498C A8800000 */  swl   $zero, ($a0)
/* 03FD90 80064990 00832021 */  addu  $a0, $a0, $v1
.L80064994:
/* 03FD94 80064994 2401FFE0 */  addiu $at, $zero, -0x20
/* 03FD98 80064998 00A13824 */  and   $a3, $a1, $at
/* 03FD9C 8006499C 10E0000C */  beqz  $a3, .L800649D0
/* 03FDA0 800649A0 00A72823 */   subu  $a1, $a1, $a3
/* 03FDA4 800649A4 00E43821 */  addu  $a3, $a3, $a0
.L800649A8:
/* 03FDA8 800649A8 AC800000 */  sw    $zero, ($a0)
/* 03FDAC 800649AC AC800004 */  sw    $zero, 4($a0)
/* 03FDB0 800649B0 AC800008 */  sw    $zero, 8($a0)
/* 03FDB4 800649B4 AC80000C */  sw    $zero, 0xc($a0)
/* 03FDB8 800649B8 24840020 */  addiu $a0, $a0, 0x20
/* 03FDBC 800649BC AC80FFF0 */  sw    $zero, -0x10($a0)
/* 03FDC0 800649C0 AC80FFF4 */  sw    $zero, -0xc($a0)
/* 03FDC4 800649C4 AC80FFF8 */  sw    $zero, -8($a0)
/* 03FDC8 800649C8 1487FFF7 */  bne   $a0, $a3, .L800649A8
/* 03FDCC 800649CC AC80FFFC */   sw    $zero, -4($a0)
.L800649D0:
/* 03FDD0 800649D0 2401FFFC */  addiu $at, $zero, -4
/* 03FDD4 800649D4 00A13824 */  and   $a3, $a1, $at
/* 03FDD8 800649D8 10E00005 */  beqz  $a3, .L800649F0
/* 03FDDC 800649DC 00A72823 */   subu  $a1, $a1, $a3
/* 03FDE0 800649E0 00E43821 */  addu  $a3, $a3, $a0
.L800649E4:
/* 03FDE4 800649E4 24840004 */  addiu $a0, $a0, 4
/* 03FDE8 800649E8 1487FFFE */  bne   $a0, $a3, .L800649E4
/* 03FDEC 800649EC AC80FFFC */   sw    $zero, -4($a0)
.L800649F0:
/* 03FDF0 800649F0 18A00005 */  blez  $a1, .L80064A08
/* 03FDF4 800649F4 00000000 */   nop   
/* 03FDF8 800649F8 00A42821 */  addu  $a1, $a1, $a0
.L800649FC:
/* 03FDFC 800649FC 24840001 */  addiu $a0, $a0, 1
/* 03FE00 80064A00 1485FFFE */  bne   $a0, $a1, .L800649FC
/* 03FE04 80064A04 A080FFFF */   sb    $zero, -1($a0)
.L80064A08:
/* 03FE08 80064A08 03E00008 */  jr    $ra
/* 03FE0C 80064A0C 00000000 */   nop   

