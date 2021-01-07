.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241DE0_D21C70
/* D21C70 80241DE0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D21C74 80241DE4 AFBF0010 */  sw        $ra, 0x10($sp)
/* D21C78 80241DE8 8C82000C */  lw        $v0, 0xc($a0)
/* D21C7C 80241DEC 0C0B1EAF */  jal       get_variable
/* D21C80 80241DF0 8C450000 */   lw       $a1, ($v0)
/* D21C84 80241DF4 3C018024 */  lui       $at, %hi(D_80244438)
/* D21C88 80241DF8 AC224438 */  sw        $v0, %lo(D_80244438)($at)
/* D21C8C 80241DFC 24020002 */  addiu     $v0, $zero, 2
/* D21C90 80241E00 8FBF0010 */  lw        $ra, 0x10($sp)
/* D21C94 80241E04 24030001 */  addiu     $v1, $zero, 1
/* D21C98 80241E08 3C018024 */  lui       $at, %hi(D_80244434)
/* D21C9C 80241E0C AC234434 */  sw        $v1, %lo(D_80244434)($at)
/* D21CA0 80241E10 03E00008 */  jr        $ra
/* D21CA4 80241E14 27BD0018 */   addiu    $sp, $sp, 0x18
