.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80281C84
/* 7E2B04 80281C84 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7E2B08 80281C88 AFBF0010 */  sw        $ra, 0x10($sp)
/* 7E2B0C 80281C8C 0C03BCF9 */  jal       func_800EF3E4
/* 7E2B10 80281C90 00000000 */   nop      
/* 7E2B14 80281C94 0C03BCE9 */  jal       func_800EF3A4
/* 7E2B18 80281C98 00000000 */   nop      
/* 7E2B1C 80281C9C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 7E2B20 80281CA0 24020002 */  addiu     $v0, $zero, 2
/* 7E2B24 80281CA4 03E00008 */  jr        $ra
/* 7E2B28 80281CA8 27BD0018 */   addiu    $sp, $sp, 0x18
