.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel btl_cam_set_target_pos
/* 17CE00 8024E520 3C028028 */  lui       $v0, %hi(D_80280CE0)
/* 17CE04 8024E524 80420CE0 */  lb        $v0, %lo(D_80280CE0)($v0)
/* 17CE08 8024E528 44860000 */  mtc1      $a2, $f0
/* 17CE0C 8024E52C 14400007 */  bnez      $v0, .L8024E54C
/* 17CE10 8024E530 00000000 */   nop
/* 17CE14 8024E534 3C01802A */  lui       $at, %hi(D_8029F270)
/* 17CE18 8024E538 E42CF270 */  swc1      $f12, %lo(D_8029F270)($at)
/* 17CE1C 8024E53C 3C01802A */  lui       $at, %hi(D_8029F274)
/* 17CE20 8024E540 E42EF274 */  swc1      $f14, %lo(D_8029F274)($at)
/* 17CE24 8024E544 3C01802A */  lui       $at, %hi(D_8029F278)
/* 17CE28 8024E548 E420F278 */  swc1      $f0, %lo(D_8029F278)($at)
.L8024E54C:
/* 17CE2C 8024E54C 03E00008 */  jr        $ra
/* 17CE30 8024E550 00000000 */   nop
