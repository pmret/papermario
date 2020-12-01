.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel BattleCamTargetActor
/* 17D404 8024EB24 3C028028 */  lui       $v0, %hi(D_80280CE0)
/* 17D408 8024EB28 80420CE0 */  lb        $v0, %lo(D_80280CE0)($v0)
/* 17D40C 8024EB2C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 17D410 8024EB30 AFB00010 */  sw        $s0, 0x10($sp)
/* 17D414 8024EB34 0080802D */  daddu     $s0, $a0, $zero
/* 17D418 8024EB38 AFBF0014 */  sw        $ra, 0x14($sp)
/* 17D41C 8024EB3C 8E05000C */  lw        $a1, 0xc($s0)
/* 17D420 8024EB40 1440000C */  bnez      $v0, .L8024EB74
/* 17D424 8024EB44 24020002 */   addiu    $v0, $zero, 2
/* 17D428 8024EB48 8CA50000 */  lw        $a1, ($a1)
/* 17D42C 8024EB4C 0C0B1EAF */  jal       get_variable
/* 17D430 8024EB50 0200202D */   daddu    $a0, $s0, $zero
/* 17D434 8024EB54 0040202D */  daddu     $a0, $v0, $zero
/* 17D438 8024EB58 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 17D43C 8024EB5C 14820002 */  bne       $a0, $v0, .L8024EB68
/* 17D440 8024EB60 00000000 */   nop      
/* 17D444 8024EB64 8E040148 */  lw        $a0, 0x148($s0)
.L8024EB68:
/* 17D448 8024EB68 0C09390F */  jal       cam_target_actor
/* 17D44C 8024EB6C 00000000 */   nop      
/* 17D450 8024EB70 24020002 */  addiu     $v0, $zero, 2
.L8024EB74:
/* 17D454 8024EB74 8FBF0014 */  lw        $ra, 0x14($sp)
/* 17D458 8024EB78 8FB00010 */  lw        $s0, 0x10($sp)
/* 17D45C 8024EB7C 03E00008 */  jr        $ra
/* 17D460 8024EB80 27BD0018 */   addiu    $sp, $sp, 0x18
