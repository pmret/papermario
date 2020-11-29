.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242364_C5CAA4
/* C5CAA4 80242364 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C5CAA8 80242368 AFBF0010 */  sw        $ra, 0x10($sp)
/* C5CAAC 8024236C 8C82000C */  lw        $v0, 0xc($a0)
/* C5CAB0 80242370 0C0B1EAF */  jal       get_variable
/* C5CAB4 80242374 8C450000 */   lw       $a1, ($v0)
/* C5CAB8 80242378 3C018024 */  lui       $at, %hi(D_80244A78)
/* C5CABC 8024237C AC224A78 */  sw        $v0, %lo(D_80244A78)($at)
/* C5CAC0 80242380 24020002 */  addiu     $v0, $zero, 2
/* C5CAC4 80242384 8FBF0010 */  lw        $ra, 0x10($sp)
/* C5CAC8 80242388 24030001 */  addiu     $v1, $zero, 1
/* C5CACC 8024238C 3C018024 */  lui       $at, %hi(D_80244A74)
/* C5CAD0 80242390 AC234A74 */  sw        $v1, %lo(D_80244A74)($at)
/* C5CAD4 80242394 03E00008 */  jr        $ra
/* C5CAD8 80242398 27BD0018 */   addiu    $sp, $sp, 0x18
