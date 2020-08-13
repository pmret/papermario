.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel enable_partner_ai
/* 0887D8 800EF328 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0887DC 800EF32C AFB00010 */  sw    $s0, 0x10($sp)
/* 0887E0 800EF330 3C108011 */  lui   $s0, 0x8011
/* 0887E4 800EF334 2610C930 */  addiu $s0, $s0, -0x36d0
/* 0887E8 800EF338 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0887EC 800EF33C 8E040000 */  lw    $a0, ($s0)
/* 0887F0 800EF340 3C018011 */  lui   $at, 0x8011
/* 0887F4 800EF344 A420CFC8 */  sh    $zero, -0x3038($at)
/* 0887F8 800EF348 0C03BD17 */  jal   clear_partner_move_history
/* 0887FC 800EF34C 00000000 */   nop   
/* 088800 800EF350 3C028011 */  lui   $v0, 0x8011
/* 088804 800EF354 8C42CFEC */  lw    $v0, -0x3014($v0)
/* 088808 800EF358 8C42000C */  lw    $v0, 0xc($v0)
/* 08880C 800EF35C 14400006 */  bnez  $v0, .L800EF378
/* 088810 800EF360 00000000 */   nop   
/* 088814 800EF364 8E040000 */  lw    $a0, ($s0)
/* 088818 800EF368 0C03AE2A */  jal   enable_partner_walking
/* 08881C 800EF36C 0000282D */   daddu $a1, $zero, $zero
/* 088820 800EF370 0803BCE1 */  j     .L800EF384
/* 088824 800EF374 00000000 */   nop   

.L800EF378:
/* 088828 800EF378 8E040000 */  lw    $a0, ($s0)
/* 08882C 800EF37C 0C03B4C4 */  jal   enable_partner_flying
/* 088830 800EF380 0000282D */   daddu $a1, $zero, $zero
.L800EF384:
/* 088834 800EF384 8FBF0014 */  lw    $ra, 0x14($sp)
/* 088838 800EF388 8FB00010 */  lw    $s0, 0x10($sp)
/* 08883C 800EF38C 03E00008 */  jr    $ra
/* 088840 800EF390 27BD0018 */   addiu $sp, $sp, 0x18

