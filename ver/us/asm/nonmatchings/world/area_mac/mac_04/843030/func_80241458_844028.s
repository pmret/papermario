.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241458_844028
/* 844028 80241458 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 84402C 8024145C 3C058025 */  lui       $a1, %hi(D_8024F5B8_C0CE38)
/* 844030 80241460 8CA5F5B8 */  lw        $a1, %lo(D_8024F5B8_C0CE38)($a1)
/* 844034 80241464 AFBF0010 */  sw        $ra, 0x10($sp)
/* 844038 80241468 0C0B1EAF */  jal       evt_get_variable
/* 84403C 8024146C 0000202D */   daddu    $a0, $zero, $zero
/* 844040 80241470 0040182D */  daddu     $v1, $v0, $zero
/* 844044 80241474 24020001 */  addiu     $v0, $zero, 1
/* 844048 80241478 14620006 */  bne       $v1, $v0, .L80241494
/* 84404C 8024147C 24020002 */   addiu    $v0, $zero, 2
/* 844050 80241480 44800000 */  mtc1      $zero, $f0
/* 844054 80241484 00000000 */  nop
/* 844058 80241488 44050000 */  mfc1      $a1, $f0
/* 84405C 8024148C 0809052B */  j         .L802414AC
/* 844060 80241490 0000202D */   daddu    $a0, $zero, $zero
.L80241494:
/* 844064 80241494 14620008 */  bne       $v1, $v0, .L802414B8
/* 844068 80241498 24040001 */   addiu    $a0, $zero, 1
/* 84406C 8024149C 44800000 */  mtc1      $zero, $f0
/* 844070 802414A0 00000000 */  nop
/* 844074 802414A4 44050000 */  mfc1      $a1, $f0
/* 844078 802414A8 00000000 */  nop
.L802414AC:
/* 84407C 802414AC 00A0302D */  daddu     $a2, $a1, $zero
/* 844080 802414B0 0C01C5A4 */  jal       fx_quizmo_answer
/* 844084 802414B4 00A0382D */   daddu    $a3, $a1, $zero
.L802414B8:
/* 844088 802414B8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 84408C 802414BC 03E00008 */  jr        $ra
/* 844090 802414C0 27BD0018 */   addiu    $sp, $sp, 0x18
