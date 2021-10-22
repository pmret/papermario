.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_119_render
/* 3E4840 E010A4A0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3E4844 E010A4A4 3C02E011 */  lui       $v0, %hi(fx_119_appendGfx)
/* 3E4848 E010A4A8 2442A4E8 */  addiu     $v0, $v0, %lo(fx_119_appendGfx)
/* 3E484C E010A4AC AFA2001C */  sw        $v0, 0x1c($sp)
/* 3E4850 E010A4B0 240202BC */  addiu     $v0, $zero, 0x2bc
/* 3E4854 E010A4B4 AFA20014 */  sw        $v0, 0x14($sp)
/* 3E4858 E010A4B8 24020001 */  addiu     $v0, $zero, 1
/* 3E485C E010A4BC AFA40018 */  sw        $a0, 0x18($sp)
/* 3E4860 E010A4C0 27A40010 */  addiu     $a0, $sp, 0x10
/* 3E4864 E010A4C4 AFBF0020 */  sw        $ra, 0x20($sp)
/* 3E4868 E010A4C8 0C080120 */  jal       shim_queue_render_task
/* 3E486C E010A4CC AFA20010 */   sw       $v0, 0x10($sp)
/* 3E4870 E010A4D0 8C430000 */  lw        $v1, ($v0)
/* 3E4874 E010A4D4 34630002 */  ori       $v1, $v1, 2
/* 3E4878 E010A4D8 AC430000 */  sw        $v1, ($v0)
/* 3E487C E010A4DC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 3E4880 E010A4E0 03E00008 */  jr        $ra
/* 3E4884 E010A4E4 27BD0028 */   addiu    $sp, $sp, 0x28
