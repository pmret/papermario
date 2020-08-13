.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel _get_hit_vert_index_from_buffer
/* 036DF4 8005B9F4 8CC60000 */  lw    $a2, ($a2)
/* 036DF8 8005B9F8 18C00008 */  blez  $a2, .L8005BA1C
/* 036DFC 8005B9FC 0000182D */   daddu $v1, $zero, $zero
.L8005BA00:
/* 036E00 8005BA00 8C820000 */  lw    $v0, ($a0)
/* 036E04 8005BA04 10450005 */  beq   $v0, $a1, .L8005BA1C
/* 036E08 8005BA08 00000000 */   nop   
/* 036E0C 8005BA0C 24630001 */  addiu $v1, $v1, 1
/* 036E10 8005BA10 0066102A */  slt   $v0, $v1, $a2
/* 036E14 8005BA14 1440FFFA */  bnez  $v0, .L8005BA00
/* 036E18 8005BA18 24840004 */   addiu $a0, $a0, 4
.L8005BA1C:
/* 036E1C 8005BA1C 03E00008 */  jr    $ra
/* 036E20 8005BA20 0060102D */   daddu $v0, $v1, $zero

