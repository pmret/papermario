.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_130_render
/* 40B78C E012039C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 40B790 E01203A0 3C02E012 */  lui       $v0, %hi(fx_130_appendGfx)
/* 40B794 E01203A4 244203E4 */  addiu     $v0, $v0, %lo(fx_130_appendGfx)
/* 40B798 E01203A8 AFA2001C */  sw        $v0, 0x1c($sp)
/* 40B79C E01203AC 2402000A */  addiu     $v0, $zero, 0xa
/* 40B7A0 E01203B0 AFA20014 */  sw        $v0, 0x14($sp)
/* 40B7A4 E01203B4 2402002D */  addiu     $v0, $zero, 0x2d
/* 40B7A8 E01203B8 AFA40018 */  sw        $a0, 0x18($sp)
/* 40B7AC E01203BC 27A40010 */  addiu     $a0, $sp, 0x10
/* 40B7B0 E01203C0 AFBF0020 */  sw        $ra, 0x20($sp)
/* 40B7B4 E01203C4 0C080120 */  jal       shim_queue_render_task
/* 40B7B8 E01203C8 AFA20010 */   sw       $v0, 0x10($sp)
/* 40B7BC E01203CC 8C430000 */  lw        $v1, ($v0)
/* 40B7C0 E01203D0 34630002 */  ori       $v1, $v1, 2
/* 40B7C4 E01203D4 AC430000 */  sw        $v1, ($v0)
/* 40B7C8 E01203D8 8FBF0020 */  lw        $ra, 0x20($sp)
/* 40B7CC E01203DC 03E00008 */  jr        $ra
/* 40B7D0 E01203E0 27BD0028 */   addiu    $sp, $sp, 0x28
