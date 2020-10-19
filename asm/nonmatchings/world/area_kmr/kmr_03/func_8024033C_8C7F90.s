.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024033C_8C82CC
/* 8C82CC 8024033C 3C03800B */  lui       $v1, %hi(gCameras)
/* 8C82D0 80240340 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* 8C82D4 80240344 94620002 */  lhu       $v0, 2($v1)
/* 8C82D8 80240348 34420001 */  ori       $v0, $v0, 1
/* 8C82DC 8024034C A4620002 */  sh        $v0, 2($v1)
/* 8C82E0 80240350 03E00008 */  jr        $ra
/* 8C82E4 80240354 24020002 */   addiu    $v0, $zero, 2
