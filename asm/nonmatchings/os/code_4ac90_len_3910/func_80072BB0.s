.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80072BB0
/* 4DFB0 80072BB0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4DFB4 80072BB4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 4DFB8 80072BB8 0C01CACC */  jal       func_80072B30
/* 4DFBC 80072BBC 00000000 */   nop      
/* 4DFC0 80072BC0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 4DFC4 80072BC4 03E00008 */  jr        $ra
/* 4DFC8 80072BC8 27BD0018 */   addiu    $sp, $sp, 0x18
