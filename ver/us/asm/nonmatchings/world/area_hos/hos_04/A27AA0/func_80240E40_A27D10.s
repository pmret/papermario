.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E40_A27D10
/* A27D10 80240E40 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A27D14 80240E44 AFBF0010 */  sw        $ra, 0x10($sp)
/* A27D18 80240E48 8C82000C */  lw        $v0, 0xc($a0)
/* A27D1C 80240E4C 0C0B1EAF */  jal       evt_get_variable
/* A27D20 80240E50 8C450000 */   lw       $a1, ($v0)
/* A27D24 80240E54 0C00AFC1 */  jal       set_curtain_draw_callback
/* A27D28 80240E58 0040202D */   daddu    $a0, $v0, $zero
/* A27D2C 80240E5C 8FBF0010 */  lw        $ra, 0x10($sp)
/* A27D30 80240E60 24020002 */  addiu     $v0, $zero, 2
/* A27D34 80240E64 03E00008 */  jr        $ra
/* A27D38 80240E68 27BD0018 */   addiu    $sp, $sp, 0x18
