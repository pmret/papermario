.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005B6A4
/* 36AA4 8005B6A4 8CC60000 */  lw        $a2, ($a2)
/* 36AA8 8005B6A8 18C00008 */  blez      $a2, .L8005B6CC
/* 36AAC 8005B6AC 0000182D */   daddu    $v1, $zero, $zero
.L8005B6B0:
/* 36AB0 8005B6B0 8C820000 */  lw        $v0, ($a0)
/* 36AB4 8005B6B4 10450005 */  beq       $v0, $a1, .L8005B6CC
/* 36AB8 8005B6B8 00000000 */   nop
/* 36ABC 8005B6BC 24630001 */  addiu     $v1, $v1, 1
/* 36AC0 8005B6C0 0066102A */  slt       $v0, $v1, $a2
/* 36AC4 8005B6C4 1440FFFA */  bnez      $v0, .L8005B6B0
/* 36AC8 8005B6C8 24840004 */   addiu    $a0, $a0, 4
.L8005B6CC:
/* 36ACC 8005B6CC 03E00008 */  jr        $ra
/* 36AD0 8005B6D0 0060102D */   daddu    $v0, $v1, $zero
