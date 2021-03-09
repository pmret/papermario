.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240444_A56364
/* A56364 80240444 3C038011 */  lui       $v1, %hi(D_8010EBB0+0x3)
/* A56368 80240448 8063EBB3 */  lb        $v1, %lo(D_8010EBB0+0x3)($v1)
/* A5636C 8024044C 24020008 */  addiu     $v0, $zero, 8
/* A56370 80240450 54620003 */  bnel      $v1, $v0, .L80240460
/* A56374 80240454 AC8000A8 */   sw       $zero, 0xa8($a0)
/* A56378 80240458 24020001 */  addiu     $v0, $zero, 1
/* A5637C 8024045C AC8200A8 */  sw        $v0, 0xa8($a0)
.L80240460:
/* A56380 80240460 03E00008 */  jr        $ra
/* A56384 80240464 24020002 */   addiu    $v0, $zero, 2
/* A56388 80240468 00000000 */  nop
/* A5638C 8024046C 00000000 */  nop
