.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241528_A87F78
/* A87F78 80241528 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A87F7C 8024152C AFBF0010 */  sw        $ra, 0x10($sp)
/* A87F80 80241530 0C03A625 */  jal       func_800E9894
/* A87F84 80241534 00000000 */   nop      
/* A87F88 80241538 8FBF0010 */  lw        $ra, 0x10($sp)
/* A87F8C 8024153C 24020002 */  addiu     $v0, $zero, 2
/* A87F90 80241540 03E00008 */  jr        $ra
/* A87F94 80241544 27BD0018 */   addiu    $sp, $sp, 0x18
