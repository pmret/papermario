.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800553C0
/* 0307C0 800553C0 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0307C4 800553C4 34858000 */  ori   $a1, $a0, 0x8000
/* 0307C8 800553C8 0000302D */  daddu $a2, $zero, $zero
/* 0307CC 800553CC 3C02800A */  lui   $v0, 0x800a
/* 0307D0 800553D0 8C42A640 */  lw    $v0, -0x59c0($v0)
/* 0307D4 800553D4 00C0382D */  daddu $a3, $a2, $zero
/* 0307D8 800553D8 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0307DC 800553DC AFA00010 */  sw    $zero, 0x10($sp)
/* 0307E0 800553E0 0C012DB6 */  jal   func_8004B6D8
/* 0307E4 800553E4 0040202D */   daddu $a0, $v0, $zero
/* 0307E8 800553E8 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0307EC 800553EC 03E00008 */  jr    $ra
/* 0307F0 800553F0 27BD0020 */   addiu $sp, $sp, 0x20

/* 0307F4 800553F4 3C03800A */  lui   $v1, 0x800a
/* 0307F8 800553F8 8C63A640 */  lw    $v1, -0x59c0($v1)
/* 0307FC 800553FC 24020001 */  addiu $v0, $zero, 1
/* 030800 80055400 03E00008 */  jr    $ra
/* 030804 80055404 AC620168 */   sw    $v0, 0x168($v1)

/* 030808 80055408 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 03080C 8005540C 0080182D */  daddu $v1, $a0, $zero
/* 030810 80055410 30E700FF */  andi  $a3, $a3, 0xff
/* 030814 80055414 00051400 */  sll   $v0, $a1, 0x10
/* 030818 80055418 AFA70010 */  sw    $a3, 0x10($sp)
/* 03081C 8005541C 00063C00 */  sll   $a3, $a2, 0x10
/* 030820 80055420 0060282D */  daddu $a1, $v1, $zero
/* 030824 80055424 00023403 */  sra   $a2, $v0, 0x10
/* 030828 80055428 3C04800A */  lui   $a0, 0x800a
/* 03082C 8005542C 8C84A640 */  lw    $a0, -0x59c0($a0)
/* 030830 80055430 AFBF0018 */  sw    $ra, 0x18($sp)
/* 030834 80055434 0C012DB6 */  jal   func_8004B6D8
/* 030838 80055438 00073C03 */   sra   $a3, $a3, 0x10
/* 03083C 8005543C 8FBF0018 */  lw    $ra, 0x18($sp)
/* 030840 80055440 03E00008 */  jr    $ra
/* 030844 80055444 27BD0020 */   addiu $sp, $sp, 0x20

