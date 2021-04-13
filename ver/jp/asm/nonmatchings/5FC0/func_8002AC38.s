.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002AC38
/* 6038 8002AC38 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 603C 8002AC3C 0080282D */  daddu     $a1, $a0, $zero
/* 6040 8002AC40 3C048030 */  lui       $a0, %hi(D_802FB800)
/* 6044 8002AC44 2484B800 */  addiu     $a0, $a0, %lo(D_802FB800)
/* 6048 8002AC48 AFBF0010 */  sw        $ra, 0x10($sp)
/* 604C 8002AC4C 0C00A477 */  jal       func_800291DC
/* 6050 8002AC50 00000000 */   nop
/* 6054 8002AC54 8FBF0010 */  lw        $ra, 0x10($sp)
/* 6058 8002AC58 03E00008 */  jr        $ra
/* 605C 8002AC5C 27BD0018 */   addiu    $sp, $sp, 0x18
