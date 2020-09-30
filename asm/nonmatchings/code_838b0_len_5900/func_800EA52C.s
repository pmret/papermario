.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800EA52C
/* 839DC 800EA52C 3C038011 */  lui       $v1, %hi(gPlayerStatus)
/* 839E0 800EA530 2463EFC8 */  addiu     $v1, $v1, %lo(gPlayerStatus)
/* 839E4 800EA534 8C620000 */  lw        $v0, ($v1)
/* 839E8 800EA538 806300B4 */  lb        $v1, 0xb4($v1)
/* 839EC 800EA53C 30420800 */  andi      $v0, $v0, 0x800
/* 839F0 800EA540 10400003 */  beqz      $v0, .L800EA550
/* 839F4 800EA544 0000282D */   daddu    $a1, $zero, $zero
/* 839F8 800EA548 03E00008 */  jr        $ra
/* 839FC 800EA54C 00A0102D */   daddu    $v0, $a1, $zero
.L800EA550:
/* 83A00 800EA550 2C620003 */  sltiu     $v0, $v1, 3
/* 83A04 800EA554 54400001 */  bnel      $v0, $zero, .L800EA55C
/* 83A08 800EA558 24050001 */   addiu    $a1, $zero, 1
.L800EA55C:
/* 83A0C 800EA55C 24020009 */  addiu     $v0, $zero, 9
/* 83A10 800EA560 14820003 */  bne       $a0, $v0, .L800EA570
/* 83A14 800EA564 24020004 */   addiu    $v0, $zero, 4
/* 83A18 800EA568 0803A964 */  j         .L800EA590
/* 83A1C 800EA56C 24020021 */   addiu    $v0, $zero, 0x21
.L800EA570:
/* 83A20 800EA570 1482000A */  bne       $a0, $v0, .L800EA59C
/* 83A24 800EA574 24020021 */   addiu    $v0, $zero, 0x21
/* 83A28 800EA578 50620008 */  beql      $v1, $v0, .L800EA59C
/* 83A2C 800EA57C 24050001 */   addiu    $a1, $zero, 1
/* 83A30 800EA580 10600005 */  beqz      $v1, .L800EA598
/* 83A34 800EA584 24020001 */   addiu    $v0, $zero, 1
/* 83A38 800EA588 10620003 */  beq       $v1, $v0, .L800EA598
/* 83A3C 800EA58C 24020002 */   addiu    $v0, $zero, 2
.L800EA590:
/* 83A40 800EA590 14620002 */  bne       $v1, $v0, .L800EA59C
/* 83A44 800EA594 00000000 */   nop      
.L800EA598:
/* 83A48 800EA598 24050001 */  addiu     $a1, $zero, 1
.L800EA59C:
/* 83A4C 800EA59C 03E00008 */  jr        $ra
/* 83A50 800EA5A0 00A0102D */   daddu    $v0, $a1, $zero
