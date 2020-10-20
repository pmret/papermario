.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802413F4
/* 8B1464 802413F4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8B1468 802413F8 3C058024 */  lui       $a1, 0x8024
/* 8B146C 802413FC 24A51388 */  addiu     $a1, $a1, 0x1388
/* 8B1470 80241400 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8B1474 80241404 0C048C8F */  jal       bind_dynamic_entity_7
/* 8B1478 80241408 0000202D */   daddu    $a0, $zero, $zero
/* 8B147C 8024140C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8B1480 80241410 3C018025 */  lui       $at, 0x8025
/* 8B1484 80241414 AC227F2C */  sw        $v0, 0x7f2c($at)
/* 8B1488 80241418 24020002 */  addiu     $v0, $zero, 2
/* 8B148C 8024141C 03E00008 */  jr        $ra
/* 8B1490 80241420 27BD0018 */   addiu    $sp, $sp, 0x18
