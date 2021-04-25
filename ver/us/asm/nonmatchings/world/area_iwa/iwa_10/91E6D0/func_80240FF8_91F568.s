.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel iwa_10_UnkFunc40
/* 91F568 80240FF8 3C038011 */  lui       $v1, %hi(D_8010EBB0)
/* 91F56C 80240FFC 2463EBB0 */  addiu     $v1, $v1, %lo(D_8010EBB0)
/* 91F570 80241000 AC800084 */  sw        $zero, 0x84($a0)
/* 91F574 80241004 80620000 */  lb        $v0, ($v1)
/* 91F578 80241008 10400005 */  beqz      $v0, .L80241020
/* 91F57C 8024100C 24020003 */   addiu    $v0, $zero, 3
/* 91F580 80241010 80630003 */  lb        $v1, 3($v1)
/* 91F584 80241014 14620002 */  bne       $v1, $v0, .L80241020
/* 91F588 80241018 24020001 */   addiu    $v0, $zero, 1
/* 91F58C 8024101C AC820084 */  sw        $v0, 0x84($a0)
.L80241020:
/* 91F590 80241020 03E00008 */  jr        $ra
/* 91F594 80241024 24020002 */   addiu    $v0, $zero, 2
/* 91F598 80241028 00000000 */  nop
/* 91F59C 8024102C 00000000 */  nop
