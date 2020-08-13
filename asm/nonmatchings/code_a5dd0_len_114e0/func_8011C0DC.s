.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8011C0DC
/* 0B27DC 8011C0DC 0080482D */  daddu $t1, $a0, $zero
/* 0B27E0 8011C0E0 240D0001 */  addiu $t5, $zero, 1
/* 0B27E4 8011C0E4 240C00DF */  addiu $t4, $zero, 0xdf
.L8011C0E8:
/* 0B27E8 8011C0E8 8D220000 */  lw    $v0, ($t1)
/* 0B27EC 8011C0EC 8D230004 */  lw    $v1, 4($t1)
/* 0B27F0 8011C0F0 8D280004 */  lw    $t0, 4($t1)
/* 0B27F4 8011C0F4 00025802 */  srl   $t3, $v0, 0
/* 0B27F8 8011C0F8 0000502D */  daddu $t2, $zero, $zero
/* 0B27FC 8011C0FC 000B1E02 */  srl   $v1, $t3, 0x18
/* 0B2800 8011C100 146D0005 */  bne   $v1, $t5, .L8011C118
/* 0B2804 8011C104 25290008 */   addiu $t1, $t1, 8
/* 0B2808 8011C108 01051023 */  subu  $v0, $t0, $a1
/* 0B280C 8011C10C 00021103 */  sra   $v0, $v0, 4
/* 0B2810 8011C110 00021100 */  sll   $v0, $v0, 4
/* 0B2814 8011C114 00E24021 */  addu  $t0, $a3, $v0
.L8011C118:
/* 0B2818 8011C118 ACCB0000 */  sw    $t3, ($a2)
/* 0B281C 8011C11C ACC80004 */  sw    $t0, 4($a2)
/* 0B2820 8011C120 146CFFF1 */  bne   $v1, $t4, .L8011C0E8
/* 0B2824 8011C124 24C60008 */   addiu $a2, $a2, 8
/* 0B2828 8011C128 03E00008 */  jr    $ra
/* 0B282C 8011C12C 00000000 */   nop   

