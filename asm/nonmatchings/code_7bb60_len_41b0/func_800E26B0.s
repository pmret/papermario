.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800E26B0
/* 7BB60 800E26B0 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* 7BB64 800E26B4 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* 7BB68 800E26B8 C440002C */  lwc1      $f0, 0x2c($v0)
/* 7BB6C 800E26BC 03E00008 */  jr        $ra
/* 7BB70 800E26C0 E4400050 */   swc1     $f0, 0x50($v0)
