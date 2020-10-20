.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D88
/* 954D48 80240D88 3C038011 */  lui       $v1, %hi(D_8010EBB0)
/* 954D4C 80240D8C 2463EBB0 */  addiu     $v1, $v1, %lo(D_8010EBB0)
/* 954D50 80240D90 AC800084 */  sw        $zero, 0x84($a0)
/* 954D54 80240D94 80620000 */  lb        $v0, ($v1)
/* 954D58 80240D98 10400005 */  beqz      $v0, .L80240DB0
/* 954D5C 80240D9C 24020003 */   addiu    $v0, $zero, 3
/* 954D60 80240DA0 80630003 */  lb        $v1, 3($v1)
/* 954D64 80240DA4 14620002 */  bne       $v1, $v0, .L80240DB0
/* 954D68 80240DA8 24020001 */   addiu    $v0, $zero, 1
/* 954D6C 80240DAC AC820084 */  sw        $v0, 0x84($a0)
.L80240DB0:
/* 954D70 80240DB0 03E00008 */  jr        $ra
/* 954D74 80240DB4 24020002 */   addiu    $v0, $zero, 2
/* 954D78 80240DB8 00000000 */  nop       
/* 954D7C 80240DBC 00000000 */  nop       
