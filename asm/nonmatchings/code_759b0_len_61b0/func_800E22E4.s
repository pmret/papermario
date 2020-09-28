.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800E22E4
/* 7B794 800E22E4 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* 7B798 800E22E8 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* 7B79C 800E22EC 8C4300E0 */  lw        $v1, 0xe0($v0)
/* 7B7A0 800E22F0 944200DE */  lhu       $v0, 0xde($v0)
/* 7B7A4 800E22F4 00031C00 */  sll       $v1, $v1, 0x10
/* 7B7A8 800E22F8 00431025 */  or        $v0, $v0, $v1
/* 7B7AC 800E22FC 03E00008 */  jr        $ra
/* 7B7B0 800E2300 AC820000 */   sw       $v0, ($a0)
