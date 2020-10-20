.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240ECC
/* 8B0F3C 80240ECC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8B0F40 80240ED0 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 8B0F44 80240ED4 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 8B0F48 80240ED8 3C05FE36 */  lui       $a1, 0xfe36
/* 8B0F4C 80240EDC AFBF0010 */  sw        $ra, 0x10($sp)
/* 8B0F50 80240EE0 80460075 */  lb        $a2, 0x75($v0)
/* 8B0F54 80240EE4 0C0B2026 */  jal       set_variable
/* 8B0F58 80240EE8 34A53C80 */   ori      $a1, $a1, 0x3c80
/* 8B0F5C 80240EEC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8B0F60 80240EF0 24020002 */  addiu     $v0, $zero, 2
/* 8B0F64 80240EF4 03E00008 */  jr        $ra
/* 8B0F68 80240EF8 27BD0018 */   addiu    $sp, $sp, 0x18
