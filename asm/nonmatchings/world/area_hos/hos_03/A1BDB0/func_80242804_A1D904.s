.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242804_A1D904
/* A1D904 80242804 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A1D908 80242808 AFBF0014 */  sw        $ra, 0x14($sp)
/* A1D90C 8024280C AFB00010 */  sw        $s0, 0x10($sp)
/* A1D910 80242810 0C00EABB */  jal       get_npc_unsafe
/* A1D914 80242814 8C84014C */   lw       $a0, 0x14c($a0)
/* A1D918 80242818 24040008 */  addiu     $a0, $zero, 8
/* A1D91C 8024281C 0040802D */  daddu     $s0, $v0, $zero
/* A1D920 80242820 3C028024 */  lui       $v0, %hi(func_80242870_A1D970)
/* A1D924 80242824 24422870 */  addiu     $v0, $v0, %lo(func_80242870_A1D970)
/* A1D928 80242828 0C00AB39 */  jal       heap_malloc
/* A1D92C 8024282C AE020008 */   sw       $v0, 8($s0)
/* A1D930 80242830 0040182D */  daddu     $v1, $v0, $zero
/* A1D934 80242834 AE030020 */  sw        $v1, 0x20($s0)
/* A1D938 80242838 AC600000 */  sw        $zero, ($v1)
/* A1D93C 8024283C 8FBF0014 */  lw        $ra, 0x14($sp)
/* A1D940 80242840 8FB00010 */  lw        $s0, 0x10($sp)
/* A1D944 80242844 24020001 */  addiu     $v0, $zero, 1
/* A1D948 80242848 03E00008 */  jr        $ra
/* A1D94C 8024284C 27BD0018 */   addiu    $sp, $sp, 0x18
