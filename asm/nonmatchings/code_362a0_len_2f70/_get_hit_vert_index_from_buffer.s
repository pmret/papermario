.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel _get_hit_vert_index_from_buffer
/* 36DF4 8005B9F4 8CC60000 */  lw        $a2, ($a2)
/* 36DF8 8005B9F8 18C00008 */  blez      $a2, .L8005BA1C
/* 36DFC 8005B9FC 0000182D */   daddu    $v1, $zero, $zero
.L8005BA00:
/* 36E00 8005BA00 8C820000 */  lw        $v0, ($a0)
/* 36E04 8005BA04 10450005 */  beq       $v0, $a1, .L8005BA1C
/* 36E08 8005BA08 00000000 */   nop      
/* 36E0C 8005BA0C 24630001 */  addiu     $v1, $v1, 1
/* 36E10 8005BA10 0066102A */  slt       $v0, $v1, $a2
/* 36E14 8005BA14 1440FFFA */  bnez      $v0, .L8005BA00
/* 36E18 8005BA18 24840004 */   addiu    $a0, $a0, 4
.L8005BA1C:
/* 36E1C 8005BA1C 03E00008 */  jr        $ra
/* 36E20 8005BA20 0060102D */   daddu    $v0, $v1, $zero
