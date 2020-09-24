.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80263230
/* 191B10 80263230 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 191B14 80263234 AFBF0010 */  sw        $ra, 0x10($sp)
/* 191B18 80263238 0C098C19 */  jal       func_80263064
/* 191B1C 8026323C 0000302D */   daddu    $a2, $zero, $zero
/* 191B20 80263240 8FBF0010 */  lw        $ra, 0x10($sp)
/* 191B24 80263244 03E00008 */  jr        $ra
/* 191B28 80263248 27BD0018 */   addiu    $sp, $sp, 0x18
