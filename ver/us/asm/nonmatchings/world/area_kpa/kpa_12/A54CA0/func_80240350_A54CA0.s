.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel kpa_12_UnkFunc30
/* A54CA0 80240350 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A54CA4 80240354 AFBF0010 */  sw        $ra, 0x10($sp)
/* A54CA8 80240358 8C82000C */  lw        $v0, 0xc($a0)
/* A54CAC 8024035C 3C068016 */  lui       $a2, %hi(gCollisionStatus+0x6)
/* A54CB0 80240360 84C6A556 */  lh        $a2, %lo(gCollisionStatus+0x6)($a2)
/* A54CB4 80240364 0C0B2026 */  jal       set_variable
/* A54CB8 80240368 8C450000 */   lw       $a1, ($v0)
/* A54CBC 8024036C 8FBF0010 */  lw        $ra, 0x10($sp)
/* A54CC0 80240370 24020002 */  addiu     $v0, $zero, 2
/* A54CC4 80240374 03E00008 */  jr        $ra
/* A54CC8 80240378 27BD0018 */   addiu    $sp, $sp, 0x18
