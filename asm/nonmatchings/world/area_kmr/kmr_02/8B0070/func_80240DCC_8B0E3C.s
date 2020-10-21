.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240DCC_8B0E3C
/* 8B0E3C 80240DCC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8B0E40 80240DD0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8B0E44 80240DD4 8C82000C */  lw        $v0, 0xc($a0)
/* 8B0E48 80240DD8 0C0B1EAF */  jal       get_variable
/* 8B0E4C 80240DDC 8C450000 */   lw       $a1, ($v0)
/* 8B0E50 80240DE0 3C038025 */  lui       $v1, 0x8025
/* 8B0E54 80240DE4 8C637F48 */  lw        $v1, 0x7f48($v1)
/* 8B0E58 80240DE8 8C63000C */  lw        $v1, 0xc($v1)
/* 8B0E5C 80240DEC AC620034 */  sw        $v0, 0x34($v1)
/* 8B0E60 80240DF0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8B0E64 80240DF4 24020002 */  addiu     $v0, $zero, 2
/* 8B0E68 80240DF8 03E00008 */  jr        $ra
/* 8B0E6C 80240DFC 27BD0018 */   addiu    $sp, $sp, 0x18
