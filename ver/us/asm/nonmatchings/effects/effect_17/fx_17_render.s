.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_17_render
/* 337BA0 E0022960 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 337BA4 E0022964 3C02E002 */  lui       $v0, %hi(func_E0022998)
/* 337BA8 E0022968 24422998 */  addiu     $v0, $v0, %lo(func_E0022998)
/* 337BAC E002296C AFA2001C */  sw        $v0, 0x1c($sp)
/* 337BB0 E0022970 2402002D */  addiu     $v0, $zero, 0x2d
/* 337BB4 E0022974 AFA40018 */  sw        $a0, 0x18($sp)
/* 337BB8 E0022978 27A40010 */  addiu     $a0, $sp, 0x10
/* 337BBC E002297C AFBF0020 */  sw        $ra, 0x20($sp)
/* 337BC0 E0022980 AFA00014 */  sw        $zero, 0x14($sp)
/* 337BC4 E0022984 0C080120 */  jal       shim_queue_render_task
/* 337BC8 E0022988 AFA20010 */   sw       $v0, 0x10($sp)
/* 337BCC E002298C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 337BD0 E0022990 03E00008 */  jr        $ra
/* 337BD4 E0022994 27BD0028 */   addiu    $sp, $sp, 0x28
