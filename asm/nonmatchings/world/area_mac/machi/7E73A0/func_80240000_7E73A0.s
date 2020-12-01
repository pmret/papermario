.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_7E73A0
/* 7E73A0 80240000 3C038024 */  lui       $v1, %hi(D_802407E0)
/* 7E73A4 80240004 246307E0 */  addiu     $v1, $v1, %lo(D_802407E0)
.L80240008:
/* 7E73A8 80240008 8C620000 */  lw        $v0, ($v1)
/* 7E73AC 8024000C 1440FFFE */  bnez      $v0, .L80240008
/* 7E73B0 80240010 24630010 */   addiu    $v1, $v1, 0x10
/* 7E73B4 80240014 3C038024 */  lui       $v1, %hi(D_802409F0)
/* 7E73B8 80240018 246309F0 */  addiu     $v1, $v1, %lo(D_802409F0)
.L8024001C:
/* 7E73BC 8024001C 8C620000 */  lw        $v0, ($v1)
/* 7E73C0 80240020 1440FFFE */  bnez      $v0, .L8024001C
/* 7E73C4 80240024 24630010 */   addiu    $v1, $v1, 0x10
/* 7E73C8 80240028 03E00008 */  jr        $ra
/* 7E73CC 8024002C 24020002 */   addiu    $v0, $zero, 2
