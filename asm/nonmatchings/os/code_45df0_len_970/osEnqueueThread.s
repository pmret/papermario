.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel osEnqueueThread
/* 046574 8006B174 0080C821 */  addu  $t9, $a0, $zero
/* 046578 8006B178 8C980000 */  lw    $t8, ($a0)
/* 04657C 8006B17C 8CAF0004 */  lw    $t7, 4($a1)
/* 046580 8006B180 8F0E0004 */  lw    $t6, 4($t8)
/* 046584 8006B184 01CF082A */  slt   $at, $t6, $t7
/* 046588 8006B188 14200007 */  bnez  $at, .L8006B1A8
/* 04658C 8006B18C 00000000 */   nop   
.L8006B190:
/* 046590 8006B190 0300C821 */  addu  $t9, $t8, $zero
/* 046594 8006B194 8F180000 */  lw    $t8, ($t8)
/* 046598 8006B198 8F0E0004 */  lw    $t6, 4($t8)
/* 04659C 8006B19C 01CF082A */  slt   $at, $t6, $t7
/* 0465A0 8006B1A0 1020FFFB */  beqz  $at, .L8006B190
/* 0465A4 8006B1A4 00000000 */   nop   
.L8006B1A8:
/* 0465A8 8006B1A8 8F380000 */  lw    $t8, ($t9)
/* 0465AC 8006B1AC ACB80000 */  sw    $t8, ($a1)
/* 0465B0 8006B1B0 AF250000 */  sw    $a1, ($t9)
/* 0465B4 8006B1B4 03E00008 */  jr    $ra
/* 0465B8 8006B1B8 ACA40008 */   sw    $a0, 8($a1)

