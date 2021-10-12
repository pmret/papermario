.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_122_render
/* 3F8794 E01103A4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3F8798 E01103A8 3C02E011 */  lui       $v0, %hi(func_E01103EC)
/* 3F879C E01103AC 244203EC */  addiu     $v0, $v0, %lo(func_E01103EC)
/* 3F87A0 E01103B0 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3F87A4 E01103B4 2402000A */  addiu     $v0, $zero, 0xa
/* 3F87A8 E01103B8 AFA20014 */  sw        $v0, 0x14($sp)
/* 3F87AC E01103BC 2402002D */  addiu     $v0, $zero, 0x2d
/* 3F87B0 E01103C0 AFA40018 */  sw        $a0, 0x18($sp)
/* 3F87B4 E01103C4 27A40010 */  addiu     $a0, $sp, 0x10
/* 3F87B8 E01103C8 AFBF0020 */  sw        $ra, 0x20($sp)
/* 3F87BC E01103CC 0C080120 */  jal       shim_queue_render_task
/* 3F87C0 E01103D0 AFA20010 */   sw       $v0, 0x10($sp)
/* 3F87C4 E01103D4 8C430000 */  lw        $v1, ($v0)
/* 3F87C8 E01103D8 34630002 */  ori       $v1, $v1, 2
/* 3F87CC E01103DC AC430000 */  sw        $v1, ($v0)
/* 3F87D0 E01103E0 8FBF0020 */  lw        $ra, 0x20($sp)
/* 3F87D4 E01103E4 03E00008 */  jr        $ra
/* 3F87D8 E01103E8 27BD0028 */   addiu    $sp, $sp, 0x28
