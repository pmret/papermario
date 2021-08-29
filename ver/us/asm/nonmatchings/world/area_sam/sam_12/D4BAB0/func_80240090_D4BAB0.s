.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240090_D4BAB0
/* D4BAB0 80240090 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D4BAB4 80240094 AFBF0010 */  sw        $ra, 0x10($sp)
/* D4BAB8 80240098 8C82000C */  lw        $v0, 0xc($a0)
/* D4BABC 8024009C 0C0B210B */  jal       evt_get_float_variable
/* D4BAC0 802400A0 8C450000 */   lw       $a1, ($v0)
/* D4BAC4 802400A4 44050000 */  mfc1      $a1, $f0
/* D4BAC8 802400A8 0C04DF62 */  jal       set_screen_overlay_params_front
/* D4BACC 802400AC 0000202D */   daddu    $a0, $zero, $zero
/* D4BAD0 802400B0 8FBF0010 */  lw        $ra, 0x10($sp)
/* D4BAD4 802400B4 24020002 */  addiu     $v0, $zero, 2
/* D4BAD8 802400B8 03E00008 */  jr        $ra
/* D4BADC 802400BC 27BD0018 */   addiu    $sp, $sp, 0x18
