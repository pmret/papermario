.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802415EC_8ED40C
/* 8ED40C 802415EC 3C038011 */  lui       $v1, %hi(D_8010EBB0)
/* 8ED410 802415F0 2463EBB0 */  addiu     $v1, $v1, %lo(D_8010EBB0)
/* 8ED414 802415F4 AC800084 */  sw        $zero, 0x84($a0)
/* 8ED418 802415F8 80620000 */  lb        $v0, ($v1)
/* 8ED41C 802415FC 10400005 */  beqz      $v0, .L80241614
/* 8ED420 80241600 24020003 */   addiu    $v0, $zero, 3
/* 8ED424 80241604 80630003 */  lb        $v1, 3($v1)
/* 8ED428 80241608 14620002 */  bne       $v1, $v0, .L80241614
/* 8ED42C 8024160C 24020001 */   addiu    $v0, $zero, 1
/* 8ED430 80241610 AC820084 */  sw        $v0, 0x84($a0)
.L80241614:
/* 8ED434 80241614 03E00008 */  jr        $ra
/* 8ED438 80241618 24020002 */   addiu    $v0, $zero, 2
/* 8ED43C 8024161C 00000000 */  nop
