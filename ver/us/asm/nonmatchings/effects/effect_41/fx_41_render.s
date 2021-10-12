.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_41_render
/* 35CE9C E005241C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 35CEA0 E0052420 3C02E005 */  lui       $v0, %hi(fx_41_appendGfx)
/* 35CEA4 E0052424 24422460 */  addiu     $v0, $v0, %lo(fx_41_appendGfx)
/* 35CEA8 E0052428 AFA2001C */  sw        $v0, 0x1c($sp)
/* 35CEAC E005242C 2402002D */  addiu     $v0, $zero, 0x2d
/* 35CEB0 E0052430 AFA40018 */  sw        $a0, 0x18($sp)
/* 35CEB4 E0052434 27A40010 */  addiu     $a0, $sp, 0x10
/* 35CEB8 E0052438 AFBF0020 */  sw        $ra, 0x20($sp)
/* 35CEBC E005243C AFA00014 */  sw        $zero, 0x14($sp)
/* 35CEC0 E0052440 0C080120 */  jal       shim_queue_render_task
/* 35CEC4 E0052444 AFA20010 */   sw       $v0, 0x10($sp)
/* 35CEC8 E0052448 8C430000 */  lw        $v1, ($v0)
/* 35CECC E005244C 34630002 */  ori       $v1, $v1, 2
/* 35CED0 E0052450 AC430000 */  sw        $v1, ($v0)
/* 35CED4 E0052454 8FBF0020 */  lw        $ra, 0x20($sp)
/* 35CED8 E0052458 03E00008 */  jr        $ra
/* 35CEDC E005245C 27BD0028 */   addiu    $sp, $sp, 0x28
