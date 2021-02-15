.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242D20_C887D0
/* C887D0 80242D20 3C038011 */  lui       $v1, %hi(D_8010EBB0)
/* C887D4 80242D24 2463EBB0 */  addiu     $v1, $v1, %lo(D_8010EBB0)
/* C887D8 80242D28 80620000 */  lb        $v0, ($v1)
/* C887DC 80242D2C 10400004 */  beqz      $v0, .L80242D40
/* C887E0 80242D30 2402FFFF */   addiu    $v0, $zero, -1
/* C887E4 80242D34 80620003 */  lb        $v0, 3($v1)
/* C887E8 80242D38 08090B51 */  j         .L80242D44
/* C887EC 80242D3C AC820084 */   sw       $v0, 0x84($a0)
.L80242D40:
/* C887F0 80242D40 AC820084 */  sw        $v0, 0x84($a0)
.L80242D44:
/* C887F4 80242D44 03E00008 */  jr        $ra
/* C887F8 80242D48 24020002 */   addiu    $v0, $zero, 2
