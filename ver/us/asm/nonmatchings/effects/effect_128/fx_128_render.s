.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_128_render
/* 406CBC E011C17C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 406CC0 E011C180 3C02E012 */  lui       $v0, %hi(func_E011C1C4)
/* 406CC4 E011C184 2442C1C4 */  addiu     $v0, $v0, %lo(func_E011C1C4)
/* 406CC8 E011C188 AFA2001C */  sw        $v0, 0x1c($sp)
/* 406CCC E011C18C 2402000A */  addiu     $v0, $zero, 0xa
/* 406CD0 E011C190 AFA20014 */  sw        $v0, 0x14($sp)
/* 406CD4 E011C194 2402002D */  addiu     $v0, $zero, 0x2d
/* 406CD8 E011C198 AFA40018 */  sw        $a0, 0x18($sp)
/* 406CDC E011C19C 27A40010 */  addiu     $a0, $sp, 0x10
/* 406CE0 E011C1A0 AFBF0020 */  sw        $ra, 0x20($sp)
/* 406CE4 E011C1A4 0C080120 */  jal       shim_queue_render_task
/* 406CE8 E011C1A8 AFA20010 */   sw       $v0, 0x10($sp)
/* 406CEC E011C1AC 8C430000 */  lw        $v1, ($v0)
/* 406CF0 E011C1B0 34630002 */  ori       $v1, $v1, 2
/* 406CF4 E011C1B4 AC430000 */  sw        $v1, ($v0)
/* 406CF8 E011C1B8 8FBF0020 */  lw        $ra, 0x20($sp)
/* 406CFC E011C1BC 03E00008 */  jr        $ra
/* 406D00 E011C1C0 27BD0028 */   addiu    $sp, $sp, 0x28
