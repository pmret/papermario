.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002AC10
/* 6010 8002AC10 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 6014 8002AC14 0080282D */  daddu     $a1, $a0, $zero
/* 6018 8002AC18 3C048030 */  lui       $a0, %hi(D_802FB800)
/* 601C 8002AC1C 2484B800 */  addiu     $a0, $a0, %lo(D_802FB800)
/* 6020 8002AC20 AFBF0010 */  sw        $ra, 0x10($sp)
/* 6024 8002AC24 0C00A449 */  jal       func_80029124
/* 6028 8002AC28 00000000 */   nop
/* 602C 8002AC2C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 6030 8002AC30 03E00008 */  jr        $ra
/* 6034 8002AC34 27BD0018 */   addiu    $sp, $sp, 0x18
