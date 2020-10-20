.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241368_B5F618
/* B5F618 80241368 3C038011 */  lui       $v1, %hi(D_8010EBB0)
/* B5F61C 8024136C 2463EBB0 */  addiu     $v1, $v1, %lo(D_8010EBB0)
/* B5F620 80241370 AC800084 */  sw        $zero, 0x84($a0)
/* B5F624 80241374 80620000 */  lb        $v0, ($v1)
/* B5F628 80241378 10400005 */  beqz      $v0, .L80241390
/* B5F62C 8024137C 24020003 */   addiu    $v0, $zero, 3
/* B5F630 80241380 80630003 */  lb        $v1, 3($v1)
/* B5F634 80241384 14620002 */  bne       $v1, $v0, .L80241390
/* B5F638 80241388 24020001 */   addiu    $v0, $zero, 1
/* B5F63C 8024138C AC820084 */  sw        $v0, 0x84($a0)
.L80241390:
/* B5F640 80241390 03E00008 */  jr        $ra
/* B5F644 80241394 24020002 */   addiu    $v0, $zero, 2
/* B5F648 80241398 00000000 */  nop       
/* B5F64C 8024139C 00000000 */  nop       
