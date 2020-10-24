.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024244C_9D946C
/* 9D946C 8024244C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9D9470 80242450 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 9D9474 80242454 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 9D9478 80242458 3C05FE36 */  lui       $a1, 0xfe36
/* 9D947C 8024245C AFBF0010 */  sw        $ra, 0x10($sp)
/* 9D9480 80242460 80460075 */  lb        $a2, 0x75($v0)
/* 9D9484 80242464 0C0B2026 */  jal       set_variable
/* 9D9488 80242468 34A53C80 */   ori      $a1, $a1, 0x3c80
/* 9D948C 8024246C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 9D9490 80242470 24020002 */  addiu     $v0, $zero, 2
/* 9D9494 80242474 03E00008 */  jr        $ra
/* 9D9498 80242478 27BD0018 */   addiu    $sp, $sp, 0x18
