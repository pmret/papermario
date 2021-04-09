.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel kpa_14_UnkFunc30
/* A57BC0 80240710 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A57BC4 80240714 AFBF0010 */  sw        $ra, 0x10($sp)
/* A57BC8 80240718 8C82000C */  lw        $v0, 0xc($a0)
/* A57BCC 8024071C 3C068016 */  lui       $a2, %hi(gCollisionStatus+0x6)
/* A57BD0 80240720 84C6A556 */  lh        $a2, %lo(gCollisionStatus+0x6)($a2)
/* A57BD4 80240724 0C0B2026 */  jal       set_variable
/* A57BD8 80240728 8C450000 */   lw       $a1, ($v0)
/* A57BDC 8024072C 8FBF0010 */  lw        $ra, 0x10($sp)
/* A57BE0 80240730 24020002 */  addiu     $v0, $zero, 2
/* A57BE4 80240734 03E00008 */  jr        $ra
/* A57BE8 80240738 27BD0018 */   addiu    $sp, $sp, 0x18
