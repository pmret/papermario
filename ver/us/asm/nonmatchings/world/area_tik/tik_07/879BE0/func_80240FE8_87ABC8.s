.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240FE8_87ABC8
/* 87ABC8 80240FE8 3C038011 */  lui       $v1, %hi(D_8010EBB0)
/* 87ABCC 80240FEC 2463EBB0 */  addiu     $v1, $v1, %lo(D_8010EBB0)
/* 87ABD0 80240FF0 AC800084 */  sw        $zero, 0x84($a0)
/* 87ABD4 80240FF4 80620000 */  lb        $v0, ($v1)
/* 87ABD8 80240FF8 10400005 */  beqz      $v0, .L80241010
/* 87ABDC 80240FFC 24020003 */   addiu    $v0, $zero, 3
/* 87ABE0 80241000 80630003 */  lb        $v1, 3($v1)
/* 87ABE4 80241004 14620002 */  bne       $v1, $v0, .L80241010
/* 87ABE8 80241008 24020001 */   addiu    $v0, $zero, 1
/* 87ABEC 8024100C AC820084 */  sw        $v0, 0x84($a0)
.L80241010:
/* 87ABF0 80241010 03E00008 */  jr        $ra
/* 87ABF4 80241014 24020002 */   addiu    $v0, $zero, 2
/* 87ABF8 80241018 00000000 */  nop
/* 87ABFC 8024101C 00000000 */  nop
