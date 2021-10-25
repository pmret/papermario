.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_53_render
/* 36D834 E006A814 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 36D838 E006A818 3C02E007 */  lui       $v0, %hi(fx_53_appendGfx)
/* 36D83C E006A81C 2442A94C */  addiu     $v0, $v0, %lo(fx_53_appendGfx)
/* 36D840 E006A820 AFA2001C */  sw        $v0, 0x1c($sp)
/* 36D844 E006A824 2402000A */  addiu     $v0, $zero, 0xa
/* 36D848 E006A828 AFA20014 */  sw        $v0, 0x14($sp)
/* 36D84C E006A82C 2402002D */  addiu     $v0, $zero, 0x2d
/* 36D850 E006A830 AFA40018 */  sw        $a0, 0x18($sp)
/* 36D854 E006A834 27A40010 */  addiu     $a0, $sp, 0x10
/* 36D858 E006A838 AFBF0020 */  sw        $ra, 0x20($sp)
/* 36D85C E006A83C 0C080120 */  jal       shim_queue_render_task
/* 36D860 E006A840 AFA20010 */   sw       $v0, 0x10($sp)
/* 36D864 E006A844 8C430000 */  lw        $v1, ($v0)
/* 36D868 E006A848 34630002 */  ori       $v1, $v1, 2
/* 36D86C E006A84C AC430000 */  sw        $v1, ($v0)
/* 36D870 E006A850 8FBF0020 */  lw        $ra, 0x20($sp)
/* 36D874 E006A854 03E00008 */  jr        $ra
/* 36D878 E006A858 27BD0028 */   addiu    $sp, $sp, 0x28
