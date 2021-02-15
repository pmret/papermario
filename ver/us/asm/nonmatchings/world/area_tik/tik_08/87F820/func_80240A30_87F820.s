.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A30_87F820
/* 87F820 80240A30 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 87F824 80240A34 AFBF0010 */  sw        $ra, 0x10($sp)
/* 87F828 80240A38 8C82000C */  lw        $v0, 0xc($a0)
/* 87F82C 80240A3C 3C068016 */  lui       $a2, %hi(gCollisionStatus+0x2)
/* 87F830 80240A40 84C6A552 */  lh        $a2, %lo(gCollisionStatus+0x2)($a2)
/* 87F834 80240A44 0C0B2026 */  jal       set_variable
/* 87F838 80240A48 8C450000 */   lw       $a1, ($v0)
/* 87F83C 80240A4C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 87F840 80240A50 24020002 */  addiu     $v0, $zero, 2
/* 87F844 80240A54 03E00008 */  jr        $ra
/* 87F848 80240A58 27BD0018 */   addiu    $sp, $sp, 0x18
