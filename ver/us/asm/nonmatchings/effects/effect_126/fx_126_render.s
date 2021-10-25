.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_126_render
/* 403854 E0118454 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 403858 E0118458 3C02E012 */  lui       $v0, %hi(fx_126_appendGfx)
/* 40385C E011845C 2442849C */  addiu     $v0, $v0, %lo(fx_126_appendGfx)
/* 403860 E0118460 AFA2001C */  sw        $v0, 0x1c($sp)
/* 403864 E0118464 2402000A */  addiu     $v0, $zero, 0xa
/* 403868 E0118468 AFA20014 */  sw        $v0, 0x14($sp)
/* 40386C E011846C 2402002D */  addiu     $v0, $zero, 0x2d
/* 403870 E0118470 AFA40018 */  sw        $a0, 0x18($sp)
/* 403874 E0118474 27A40010 */  addiu     $a0, $sp, 0x10
/* 403878 E0118478 AFBF0020 */  sw        $ra, 0x20($sp)
/* 40387C E011847C 0C080120 */  jal       shim_queue_render_task
/* 403880 E0118480 AFA20010 */   sw       $v0, 0x10($sp)
/* 403884 E0118484 8C430000 */  lw        $v1, ($v0)
/* 403888 E0118488 34630002 */  ori       $v1, $v1, 2
/* 40388C E011848C AC430000 */  sw        $v1, ($v0)
/* 403890 E0118490 8FBF0020 */  lw        $ra, 0x20($sp)
/* 403894 E0118494 03E00008 */  jr        $ra
/* 403898 E0118498 27BD0028 */   addiu    $sp, $sp, 0x28
