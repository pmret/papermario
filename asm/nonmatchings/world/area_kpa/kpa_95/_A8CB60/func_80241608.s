.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241608
/* A8E088 80241608 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A8E08C 8024160C AFBF0010 */  sw        $ra, 0x10($sp)
/* A8E090 80241610 0C03A625 */  jal       func_800E9894
/* A8E094 80241614 00000000 */   nop      
/* A8E098 80241618 8FBF0010 */  lw        $ra, 0x10($sp)
/* A8E09C 8024161C 24020002 */  addiu     $v0, $zero, 2
/* A8E0A0 80241620 03E00008 */  jr        $ra
/* A8E0A4 80241624 27BD0018 */   addiu    $sp, $sp, 0x18
