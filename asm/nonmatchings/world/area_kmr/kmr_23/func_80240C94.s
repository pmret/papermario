.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C94
/* 9086C4 80240C94 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 9086C8 80240C98 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 9086CC 80240C9C 90420012 */  lbu       $v0, 0x12($v0)
/* 9086D0 80240CA0 03E00008 */  jr        $ra
/* 9086D4 80240CA4 000211C2 */   srl      $v0, $v0, 7
