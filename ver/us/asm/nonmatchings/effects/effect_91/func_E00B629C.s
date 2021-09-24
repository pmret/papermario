.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00B629C
/* 3B73FC E00B629C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3B7400 E00B62A0 3C02E00B */  lui       $v0, %hi(func_E00B62E0)
/* 3B7404 E00B62A4 244262E0 */  addiu     $v0, $v0, %lo(func_E00B62E0)
/* 3B7408 E00B62A8 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3B740C E00B62AC 2402000A */  addiu     $v0, $zero, 0xa
/* 3B7410 E00B62B0 AFA20014 */  sw        $v0, 0x14($sp)
/* 3B7414 E00B62B4 2402002D */  addiu     $v0, $zero, 0x2d
/* 3B7418 E00B62B8 AFA40018 */  sw        $a0, 0x18($sp)
/* 3B741C E00B62BC 27A40010 */  addiu     $a0, $sp, 0x10
/* 3B7420 E00B62C0 AFBF0020 */  sw        $ra, 0x20($sp)
/* 3B7424 E00B62C4 0C080120 */  jal       shim_queue_render_task
/* 3B7428 E00B62C8 AFA20010 */   sw       $v0, 0x10($sp)
/* 3B742C E00B62CC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 3B7430 E00B62D0 03E00008 */  jr        $ra
/* 3B7434 E00B62D4 27BD0028 */   addiu    $sp, $sp, 0x28
