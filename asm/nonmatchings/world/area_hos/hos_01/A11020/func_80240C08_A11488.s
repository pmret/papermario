.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C08_A11488
/* A11488 80240C08 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A1148C 80240C0C AFBF0010 */  sw        $ra, 0x10($sp)
/* A11490 80240C10 8C82000C */  lw        $v0, 0xc($a0)
/* A11494 80240C14 0C0B1EAF */  jal       get_variable
/* A11498 80240C18 8C450000 */   lw       $a1, ($v0)
/* A1149C 80240C1C 8FBF0010 */  lw        $ra, 0x10($sp)
/* A114A0 80240C20 3C018024 */  lui       $at, %hi(D_80241C2C)
/* A114A4 80240C24 AC221C2C */  sw        $v0, %lo(D_80241C2C)($at)
/* A114A8 80240C28 24020002 */  addiu     $v0, $zero, 2
/* A114AC 80240C2C 03E00008 */  jr        $ra
/* A114B0 80240C30 27BD0018 */   addiu    $sp, $sp, 0x18
