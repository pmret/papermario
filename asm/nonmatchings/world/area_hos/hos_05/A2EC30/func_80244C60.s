.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80244C60
/* A2EEA0 80244C60 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A2EEA4 80244C64 AFBF0010 */  sw        $ra, 0x10($sp)
/* A2EEA8 80244C68 8C82000C */  lw        $v0, 0xc($a0)
/* A2EEAC 80244C6C 0C0B1EAF */  jal       get_variable
/* A2EEB0 80244C70 8C450000 */   lw       $a1, ($v0)
/* A2EEB4 80244C74 0C00AFC1 */  jal       set_curtain_draw_callback
/* A2EEB8 80244C78 0040202D */   daddu    $a0, $v0, $zero
/* A2EEBC 80244C7C 8FBF0010 */  lw        $ra, 0x10($sp)
/* A2EEC0 80244C80 24020002 */  addiu     $v0, $zero, 2
/* A2EEC4 80244C84 03E00008 */  jr        $ra
/* A2EEC8 80244C88 27BD0018 */   addiu    $sp, $sp, 0x18
