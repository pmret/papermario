.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024034C_A577FC
/* A577FC 8024034C 3C038011 */  lui       $v1, %hi(D_8010EBB0)
/* A57800 80240350 2463EBB0 */  addiu     $v1, $v1, %lo(D_8010EBB0)
/* A57804 80240354 80620000 */  lb        $v0, ($v1)
/* A57808 80240358 10400004 */  beqz      $v0, .L8024036C
/* A5780C 8024035C 2402FFFF */   addiu    $v0, $zero, -1
/* A57810 80240360 80620003 */  lb        $v0, 3($v1)
/* A57814 80240364 080900DC */  j         .L80240370
/* A57818 80240368 AC8200A8 */   sw       $v0, 0xa8($a0)
.L8024036C:
/* A5781C 8024036C AC8200A8 */  sw        $v0, 0xa8($a0)
.L80240370:
/* A57820 80240370 03E00008 */  jr        $ra
/* A57824 80240374 24020002 */   addiu    $v0, $zero, 2
/* A57828 80240378 00000000 */  nop       
/* A5782C 8024037C 00000000 */  nop       
