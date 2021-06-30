.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel filemenu_draw_contents_file_1_title_A2F958
/* A2F958 80245718 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A2F95C 8024571C AFBF0010 */  sw        $ra, 0x10($sp)
/* A2F960 80245720 8C82000C */  lw        $v0, 0xc($a0)
/* A2F964 80245724 0C0B1EAF */  jal       get_variable
/* A2F968 80245728 8C450000 */   lw       $a1, ($v0)
/* A2F96C 8024572C 8FBF0010 */  lw        $ra, 0x10($sp)
/* A2F970 80245730 3C018025 */  lui       $at, %hi(D_8024DCCC_A37F0C)
/* A2F974 80245734 AC22DCCC */  sw        $v0, %lo(D_8024DCCC_A37F0C)($at)
/* A2F978 80245738 24020002 */  addiu     $v0, $zero, 2
/* A2F97C 8024573C 03E00008 */  jr        $ra
/* A2F980 80245740 27BD0018 */   addiu    $sp, $sp, 0x18
