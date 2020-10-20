.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242EE0
/* A1DFE0 80242EE0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A1DFE4 80242EE4 AFBF0010 */  sw        $ra, 0x10($sp)
/* A1DFE8 80242EE8 8C82000C */  lw        $v0, 0xc($a0)
/* A1DFEC 80242EEC 0C0B1EAF */  jal       get_variable
/* A1DFF0 80242EF0 8C450000 */   lw       $a1, ($v0)
/* A1DFF4 80242EF4 3C038025 */  lui       $v1, 0x8025
/* A1DFF8 80242EF8 8C63BDF0 */  lw        $v1, -0x4210($v1)
/* A1DFFC 80242EFC 8C63000C */  lw        $v1, 0xc($v1)
/* A1E000 80242F00 AC620034 */  sw        $v0, 0x34($v1)
/* A1E004 80242F04 8FBF0010 */  lw        $ra, 0x10($sp)
/* A1E008 80242F08 24020002 */  addiu     $v0, $zero, 2
/* A1E00C 80242F0C 03E00008 */  jr        $ra
/* A1E010 80242F10 27BD0018 */   addiu    $sp, $sp, 0x18
