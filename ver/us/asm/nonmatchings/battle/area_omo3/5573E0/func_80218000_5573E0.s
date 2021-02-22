.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218000_5573E0
/* 5573E0 80218000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 5573E4 80218004 AFBF0010 */  sw        $ra, 0x10($sp)
/* 5573E8 80218008 0C09A75B */  jal       get_actor
/* 5573EC 8021800C 8C840148 */   lw       $a0, 0x148($a0)
/* 5573F0 80218010 3C05435C */  lui       $a1, 0x435c
/* 5573F4 80218014 0C04DF69 */  jal       set_transition_stencil_zoom_1
/* 5573F8 80218018 2404000D */   addiu    $a0, $zero, 0xd
/* 5573FC 8021801C 3C054348 */  lui       $a1, 0x4348
/* 557400 80218020 0C04E035 */  jal       set_transition_stencil_alpha
/* 557404 80218024 24040001 */   addiu    $a0, $zero, 1
/* 557408 80218028 8FBF0010 */  lw        $ra, 0x10($sp)
/* 55740C 8021802C 24020002 */  addiu     $v0, $zero, 2
/* 557410 80218030 03E00008 */  jr        $ra
/* 557414 80218034 27BD0018 */   addiu    $sp, $sp, 0x18
