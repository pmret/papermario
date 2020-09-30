.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800EF414
/* 888C4 800EF414 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 888C8 800EF418 AFBF0010 */  sw        $ra, 0x10($sp)
/* 888CC 800EF41C 0C03BCF0 */  jal       func_800EF3C0
/* 888D0 800EF420 00000000 */   nop      
/* 888D4 800EF424 8FBF0010 */  lw        $ra, 0x10($sp)
/* 888D8 800EF428 24020014 */  addiu     $v0, $zero, 0x14
/* 888DC 800EF42C 3C018011 */  lui       $at, 0x8011
/* 888E0 800EF430 A422CFC8 */  sh        $v0, -0x3038($at)
/* 888E4 800EF434 03E00008 */  jr        $ra
/* 888E8 800EF438 27BD0018 */   addiu    $sp, $sp, 0x18
