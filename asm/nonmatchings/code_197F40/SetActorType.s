.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel SetActorType
/* 19E400 8026FB20 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 19E404 8026FB24 AFB20018 */  sw        $s2, 0x18($sp)
/* 19E408 8026FB28 0080902D */  daddu     $s2, $a0, $zero
/* 19E40C 8026FB2C AFBF001C */  sw        $ra, 0x1c($sp)
/* 19E410 8026FB30 AFB10014 */  sw        $s1, 0x14($sp)
/* 19E414 8026FB34 AFB00010 */  sw        $s0, 0x10($sp)
/* 19E418 8026FB38 8E51000C */  lw        $s1, 0xc($s2)
/* 19E41C 8026FB3C 8E250000 */  lw        $a1, ($s1)
/* 19E420 8026FB40 0C0B1EAF */  jal       get_variable
/* 19E424 8026FB44 26310004 */   addiu    $s1, $s1, 4
/* 19E428 8026FB48 0040802D */  daddu     $s0, $v0, $zero
/* 19E42C 8026FB4C 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 19E430 8026FB50 16020002 */  bne       $s0, $v0, .L8026FB5C
/* 19E434 8026FB54 00000000 */   nop
/* 19E438 8026FB58 8E500148 */  lw        $s0, 0x148($s2)
.L8026FB5C:
/* 19E43C 8026FB5C 8E250000 */  lw        $a1, ($s1)
/* 19E440 8026FB60 0C0B1EAF */  jal       get_variable
/* 19E444 8026FB64 0240202D */   daddu    $a0, $s2, $zero
/* 19E448 8026FB68 0200202D */  daddu     $a0, $s0, $zero
/* 19E44C 8026FB6C 0C09A75B */  jal       get_actor
/* 19E450 8026FB70 0040882D */   daddu    $s1, $v0, $zero
/* 19E454 8026FB74 0040802D */  daddu     $s0, $v0, $zero
/* 19E458 8026FB78 0C094F08 */  jal       is_actor_hp_bar_visible
/* 19E45C 8026FB7C 0200202D */   daddu    $a0, $s0, $zero
/* 19E460 8026FB80 50400004 */  beql      $v0, $zero, .L8026FB94
/* 19E464 8026FB84 A2110136 */   sb       $s1, 0x136($s0)
/* 19E468 8026FB88 0C094F9E */  jal       load_tattle_flags
/* 19E46C 8026FB8C 0220202D */   daddu    $a0, $s1, $zero
/* 19E470 8026FB90 A2110136 */  sb        $s1, 0x136($s0)
.L8026FB94:
/* 19E474 8026FB94 8FBF001C */  lw        $ra, 0x1c($sp)
/* 19E478 8026FB98 8FB20018 */  lw        $s2, 0x18($sp)
/* 19E47C 8026FB9C 8FB10014 */  lw        $s1, 0x14($sp)
/* 19E480 8026FBA0 8FB00010 */  lw        $s0, 0x10($sp)
/* 19E484 8026FBA4 24020002 */  addiu     $v0, $zero, 2
/* 19E488 8026FBA8 03E00008 */  jr        $ra
/* 19E48C 8026FBAC 27BD0020 */   addiu    $sp, $sp, 0x20
