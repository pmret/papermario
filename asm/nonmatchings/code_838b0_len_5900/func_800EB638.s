.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_800EB638
/* 084AE8 800EB638 3C028011 */  lui   $v0, 0x8011
/* 084AEC 800EB63C 8C42CFEC */  lw    $v0, -0x3014($v0)
/* 084AF0 800EB640 10400003 */  beqz  $v0, .L800EB650
/* 084AF4 800EB644 00000000 */   nop   
/* 084AF8 800EB648 03E00008 */  jr    $ra
/* 084AFC 800EB64C 8C42003C */   lw    $v0, 0x3c($v0)

.L800EB650:
/* 084B00 800EB650 03E00008 */  jr    $ra
/* 084B04 800EB654 0000102D */   daddu $v0, $zero, $zero

