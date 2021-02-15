.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel state_init_language_select
/* 10400 80035000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 10404 80035004 AFB00010 */  sw        $s0, 0x10($sp)
/* 10408 80035008 3C10800A */  lui       $s0, %hi(D_800A0932)
/* 1040C 8003500C 26100932 */  addiu     $s0, $s0, %lo(D_800A0932)
/* 10410 80035010 AFBF0014 */  sw        $ra, 0x14($sp)
/* 10414 80035014 3C01800A */  lui       $at, %hi(D_800A0931)
/* 10418 80035018 A0200931 */  sb        $zero, %lo(D_800A0931)($at)
/* 1041C 8003501C 0C03805E */  jal       disable_player_input
/* 10420 80035020 A6000000 */   sh       $zero, ($s0)
/* 10424 80035024 0C009C22 */  jal       func_80027088
/* 10428 80035028 24040002 */   addiu    $a0, $zero, 2
/* 1042C 8003502C 86020000 */  lh        $v0, ($s0)
/* 10430 80035030 44820000 */  mtc1      $v0, $f0
/* 10434 80035034 00000000 */  nop
/* 10438 80035038 46800020 */  cvt.s.w   $f0, $f0
/* 1043C 8003503C 44050000 */  mfc1      $a1, $f0
/* 10440 80035040 0C04DF62 */  jal       set_transition_stencil_zoom_0
/* 10444 80035044 0000202D */   daddu    $a0, $zero, $zero
/* 10448 80035048 8FBF0014 */  lw        $ra, 0x14($sp)
/* 1044C 8003504C 8FB00010 */  lw        $s0, 0x10($sp)
/* 10450 80035050 03E00008 */  jr        $ra
/* 10454 80035054 27BD0018 */   addiu    $sp, $sp, 0x18
