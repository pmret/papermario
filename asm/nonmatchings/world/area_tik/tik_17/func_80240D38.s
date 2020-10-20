.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D38
/* 893758 80240D38 3C038011 */  lui       $v1, %hi(D_8010EBB0)
/* 89375C 80240D3C 2463EBB0 */  addiu     $v1, $v1, %lo(D_8010EBB0)
/* 893760 80240D40 AC800084 */  sw        $zero, 0x84($a0)
/* 893764 80240D44 80620000 */  lb        $v0, ($v1)
/* 893768 80240D48 10400005 */  beqz      $v0, .L80240D60
/* 89376C 80240D4C 24020003 */   addiu    $v0, $zero, 3
/* 893770 80240D50 80630003 */  lb        $v1, 3($v1)
/* 893774 80240D54 14620002 */  bne       $v1, $v0, .L80240D60
/* 893778 80240D58 24020001 */   addiu    $v0, $zero, 1
/* 89377C 80240D5C AC820084 */  sw        $v0, 0x84($a0)
.L80240D60:
/* 893780 80240D60 03E00008 */  jr        $ra
/* 893784 80240D64 24020002 */   addiu    $v0, $zero, 2
/* 893788 80240D68 00000000 */  nop       
/* 89378C 80240D6C 00000000 */  nop       
