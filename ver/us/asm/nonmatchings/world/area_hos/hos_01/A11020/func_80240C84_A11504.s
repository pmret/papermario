.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C84_A11504
/* A11504 80240C84 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A11508 80240C88 AFBF0010 */  sw        $ra, 0x10($sp)
/* A1150C 80240C8C 8C82000C */  lw        $v0, 0xc($a0)
/* A11510 80240C90 0C0B1EAF */  jal       evt_get_variable
/* A11514 80240C94 8C450000 */   lw       $a1, ($v0)
/* A11518 80240C98 8FBF0010 */  lw        $ra, 0x10($sp)
/* A1151C 80240C9C 3C018024 */  lui       $at, %hi(D_80241C30_A124B0)
/* A11520 80240CA0 AC221C30 */  sw        $v0, %lo(D_80241C30_A124B0)($at)
/* A11524 80240CA4 24020002 */  addiu     $v0, $zero, 2
/* A11528 80240CA8 03E00008 */  jr        $ra
/* A1152C 80240CAC 27BD0018 */   addiu    $sp, $sp, 0x18
