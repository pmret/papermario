.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8023102C_54840C
/* 54840C 8023102C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 548410 80231030 AFBF0010 */  sw        $ra, 0x10($sp)
/* 548414 80231034 0C09A75B */  jal       get_actor
/* 548418 80231038 8C840148 */   lw       $a0, 0x148($a0)
/* 54841C 8023103C 8C430008 */  lw        $v1, 8($v0)
/* 548420 80231040 A0600006 */  sb        $zero, 6($v1)
/* 548424 80231044 8FBF0010 */  lw        $ra, 0x10($sp)
/* 548428 80231048 24020002 */  addiu     $v0, $zero, 2
/* 54842C 8023104C 03E00008 */  jr        $ra
/* 548430 80231050 27BD0018 */   addiu    $sp, $sp, 0x18
