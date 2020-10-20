.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E30_A2B070
/* A2B070 80240E30 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A2B074 80240E34 AFBF0010 */  sw        $ra, 0x10($sp)
/* A2B078 80240E38 0C04760B */  jal       func_8011D82C
/* A2B07C 80240E3C 24040003 */   addiu    $a0, $zero, 3
/* A2B080 80240E40 8FBF0010 */  lw        $ra, 0x10($sp)
/* A2B084 80240E44 24020002 */  addiu     $v0, $zero, 2
/* A2B088 80240E48 03E00008 */  jr        $ra
/* A2B08C 80240E4C 27BD0018 */   addiu    $sp, $sp, 0x18
