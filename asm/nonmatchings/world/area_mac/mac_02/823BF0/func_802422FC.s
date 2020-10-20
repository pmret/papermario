.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802422FC
/* 8255BC 802422FC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8255C0 80242300 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 8255C4 80242304 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 8255C8 80242308 3C05FE36 */  lui       $a1, 0xfe36
/* 8255CC 8024230C AFBF0010 */  sw        $ra, 0x10($sp)
/* 8255D0 80242310 80460075 */  lb        $a2, 0x75($v0)
/* 8255D4 80242314 0C0B2026 */  jal       set_variable
/* 8255D8 80242318 34A53C80 */   ori      $a1, $a1, 0x3c80
/* 8255DC 8024231C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8255E0 80242320 24020002 */  addiu     $v0, $zero, 2
/* 8255E4 80242324 03E00008 */  jr        $ra
/* 8255E8 80242328 27BD0018 */   addiu    $sp, $sp, 0x18
