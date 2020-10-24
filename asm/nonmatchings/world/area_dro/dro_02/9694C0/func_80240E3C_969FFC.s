.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E3C_969FFC
/* 969FFC 80240E3C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 96A000 80240E40 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 96A004 80240E44 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 96A008 80240E48 3C05FE36 */  lui       $a1, 0xfe36
/* 96A00C 80240E4C AFBF0010 */  sw        $ra, 0x10($sp)
/* 96A010 80240E50 80460075 */  lb        $a2, 0x75($v0)
/* 96A014 80240E54 0C0B2026 */  jal       set_variable
/* 96A018 80240E58 34A53C80 */   ori      $a1, $a1, 0x3c80
/* 96A01C 80240E5C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 96A020 80240E60 24020002 */  addiu     $v0, $zero, 2
/* 96A024 80240E64 03E00008 */  jr        $ra
/* 96A028 80240E68 27BD0018 */   addiu    $sp, $sp, 0x18
