.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240350_C7E4D0
/* C7E4D0 80240350 3C038011 */  lui       $v1, %hi(D_8010EBB0)
/* C7E4D4 80240354 2463EBB0 */  addiu     $v1, $v1, %lo(D_8010EBB0)
/* C7E4D8 80240358 80620000 */  lb        $v0, ($v1)
/* C7E4DC 8024035C 10400004 */  beqz      $v0, .L80240370
/* C7E4E0 80240360 2402FFFF */   addiu    $v0, $zero, -1
/* C7E4E4 80240364 80620003 */  lb        $v0, 3($v1)
/* C7E4E8 80240368 080900DD */  j         .L80240374
/* C7E4EC 8024036C AC820084 */   sw       $v0, 0x84($a0)
.L80240370:
/* C7E4F0 80240370 AC820084 */  sw        $v0, 0x84($a0)
.L80240374:
/* C7E4F4 80240374 03E00008 */  jr        $ra
/* C7E4F8 80240378 24020002 */   addiu    $v0, $zero, 2
