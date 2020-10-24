.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240434_8CAD34
/* 8CAD34 80240434 3C018011 */  lui       $at, 0x8011
/* 8CAD38 80240438 A020F291 */  sb        $zero, -0xd6f($at)
/* 8CAD3C 8024043C 03E00008 */  jr        $ra
/* 8CAD40 80240440 24020002 */   addiu    $v0, $zero, 2
