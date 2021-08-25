.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240564_DE5C14
/* DE5C14 80240564 3C038011 */  lui       $v1, %hi(gPartnerActionStatus)
/* DE5C18 80240568 2463EBB0 */  addiu     $v1, $v1, %lo(gPartnerActionStatus)
/* DE5C1C 8024056C 80620000 */  lb        $v0, ($v1)
/* DE5C20 80240570 10400004 */  beqz      $v0, .L80240584
/* DE5C24 80240574 2402FFFF */   addiu    $v0, $zero, -1
/* DE5C28 80240578 80620003 */  lb        $v0, 3($v1)
/* DE5C2C 8024057C 08090162 */  j         .L80240588
/* DE5C30 80240580 AC8200A8 */   sw       $v0, 0xa8($a0)
.L80240584:
/* DE5C34 80240584 AC8200A8 */  sw        $v0, 0xa8($a0)
.L80240588:
/* DE5C38 80240588 03E00008 */  jr        $ra
/* DE5C3C 8024058C 24020002 */   addiu    $v0, $zero, 2
