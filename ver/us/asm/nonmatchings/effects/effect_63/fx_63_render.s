.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_63_render
/* 37FC28 E007E508 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 37FC2C E007E50C 3C02E008 */  lui       $v0, %hi(fx_63_appendGfx)
/* 37FC30 E007E510 2442E54C */  addiu     $v0, $v0, %lo(fx_63_appendGfx)
/* 37FC34 E007E514 AFA2001C */  sw        $v0, 0x1c($sp)
/* 37FC38 E007E518 2402002D */  addiu     $v0, $zero, 0x2d
/* 37FC3C E007E51C AFA40018 */  sw        $a0, 0x18($sp)
/* 37FC40 E007E520 27A40010 */  addiu     $a0, $sp, 0x10
/* 37FC44 E007E524 AFBF0020 */  sw        $ra, 0x20($sp)
/* 37FC48 E007E528 AFA00014 */  sw        $zero, 0x14($sp)
/* 37FC4C E007E52C 0C080120 */  jal       shim_queue_render_task
/* 37FC50 E007E530 AFA20010 */   sw       $v0, 0x10($sp)
/* 37FC54 E007E534 8C430000 */  lw        $v1, ($v0)
/* 37FC58 E007E538 34630002 */  ori       $v1, $v1, 2
/* 37FC5C E007E53C AC430000 */  sw        $v1, ($v0)
/* 37FC60 E007E540 8FBF0020 */  lw        $ra, 0x20($sp)
/* 37FC64 E007E544 03E00008 */  jr        $ra
/* 37FC68 E007E548 27BD0028 */   addiu    $sp, $sp, 0x28
