.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_120_render
/* 3E5814 E010C354 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3E5818 E010C358 3C02E011 */  lui       $v0, %hi(fx_120_appendGfx)
/* 3E581C E010C35C 2442C39C */  addiu     $v0, $v0, %lo(fx_120_appendGfx)
/* 3E5820 E010C360 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3E5824 E010C364 2402000A */  addiu     $v0, $zero, 0xa
/* 3E5828 E010C368 AFA20014 */  sw        $v0, 0x14($sp)
/* 3E582C E010C36C 2402002D */  addiu     $v0, $zero, 0x2d
/* 3E5830 E010C370 AFA40018 */  sw        $a0, 0x18($sp)
/* 3E5834 E010C374 27A40010 */  addiu     $a0, $sp, 0x10
/* 3E5838 E010C378 AFBF0020 */  sw        $ra, 0x20($sp)
/* 3E583C E010C37C 0C080120 */  jal       shim_queue_render_task
/* 3E5840 E010C380 AFA20010 */   sw       $v0, 0x10($sp)
/* 3E5844 E010C384 8C430000 */  lw        $v1, ($v0)
/* 3E5848 E010C388 34630002 */  ori       $v1, $v1, 2
/* 3E584C E010C38C AC430000 */  sw        $v1, ($v0)
/* 3E5850 E010C390 8FBF0020 */  lw        $ra, 0x20($sp)
/* 3E5854 E010C394 03E00008 */  jr        $ra
/* 3E5858 E010C398 27BD0028 */   addiu    $sp, $sp, 0x28
