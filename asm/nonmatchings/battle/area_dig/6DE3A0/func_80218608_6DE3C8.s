.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218608_6DE3C8
/* 6DE3C8 80218608 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 6DE3CC 8021860C AFBF0010 */  sw        $ra, 0x10($sp)
/* 6DE3D0 80218610 0C03A830 */  jal       add_coins
/* 6DE3D4 80218614 24040001 */   addiu    $a0, $zero, 1
/* 6DE3D8 80218618 8FBF0010 */  lw        $ra, 0x10($sp)
/* 6DE3DC 8021861C 24020002 */  addiu     $v0, $zero, 2
/* 6DE3E0 80218620 03E00008 */  jr        $ra
/* 6DE3E4 80218624 27BD0018 */   addiu    $sp, $sp, 0x18
/* 6DE3E8 80218628 00000000 */  nop       
/* 6DE3EC 8021862C 00000000 */  nop       
