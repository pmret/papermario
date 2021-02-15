.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240310_A5A340
/* A5A340 80240310 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A5A344 80240314 AFBF0010 */  sw        $ra, 0x10($sp)
/* A5A348 80240318 8C82000C */  lw        $v0, 0xc($a0)
/* A5A34C 8024031C 0C0B1EAF */  jal       get_variable
/* A5A350 80240320 8C450000 */   lw       $a1, ($v0)
/* A5A354 80240324 44820000 */  mtc1      $v0, $f0
/* A5A358 80240328 00000000 */  nop
/* A5A35C 8024032C 46800020 */  cvt.s.w   $f0, $f0
/* A5A360 80240330 44050000 */  mfc1      $a1, $f0
/* A5A364 80240334 0C04DF62 */  jal       set_transition_stencil_zoom_0
/* A5A368 80240338 0000202D */   daddu    $a0, $zero, $zero
/* A5A36C 8024033C 8FBF0010 */  lw        $ra, 0x10($sp)
/* A5A370 80240340 24020002 */  addiu     $v0, $zero, 2
/* A5A374 80240344 03E00008 */  jr        $ra
/* A5A378 80240348 27BD0018 */   addiu    $sp, $sp, 0x18
