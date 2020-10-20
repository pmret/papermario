.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024130C_BCFEFC
/* BCFEFC 8024130C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BCFF00 80241310 3C05F5DE */  lui       $a1, 0xf5de
/* BCFF04 80241314 AFBF0018 */  sw        $ra, 0x18($sp)
/* BCFF08 80241318 0C0B1EAF */  jal       get_variable
/* BCFF0C 8024131C 34A50236 */   ori      $a1, $a1, 0x236
/* BCFF10 80241320 0000202D */  daddu     $a0, $zero, $zero
/* BCFF14 80241324 24030008 */  addiu     $v1, $zero, 8
/* BCFF18 80241328 00021080 */  sll       $v0, $v0, 2
/* BCFF1C 8024132C 0080302D */  daddu     $a2, $a0, $zero
/* BCFF20 80241330 AFA30010 */  sw        $v1, 0x10($sp)
/* BCFF24 80241334 3C058024 */  lui       $a1, 0x8024
/* BCFF28 80241338 00A22821 */  addu      $a1, $a1, $v0
/* BCFF2C 8024133C 8CA53098 */  lw        $a1, 0x3098($a1)
/* BCFF30 80241340 0C052A46 */  jal       set_music_track
/* BCFF34 80241344 240701F4 */   addiu    $a3, $zero, 0x1f4
/* BCFF38 80241348 8FBF0018 */  lw        $ra, 0x18($sp)
/* BCFF3C 8024134C 24020002 */  addiu     $v0, $zero, 2
/* BCFF40 80241350 03E00008 */  jr        $ra
/* BCFF44 80241354 27BD0020 */   addiu    $sp, $sp, 0x20
