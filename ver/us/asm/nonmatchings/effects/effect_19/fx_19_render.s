.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_19_render
/* 33B630 E00264B0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 33B634 E00264B4 3C02E002 */  lui       $v0, %hi(fx_19_appendGfx)
/* 33B638 E00264B8 244264F4 */  addiu     $v0, $v0, %lo(fx_19_appendGfx)
/* 33B63C E00264BC AFA2001C */  sw        $v0, 0x1c($sp)
/* 33B640 E00264C0 2402002D */  addiu     $v0, $zero, 0x2d
/* 33B644 E00264C4 AFA40018 */  sw        $a0, 0x18($sp)
/* 33B648 E00264C8 27A40010 */  addiu     $a0, $sp, 0x10
/* 33B64C E00264CC AFBF0020 */  sw        $ra, 0x20($sp)
/* 33B650 E00264D0 AFA00014 */  sw        $zero, 0x14($sp)
/* 33B654 E00264D4 0C080120 */  jal       shim_queue_render_task
/* 33B658 E00264D8 AFA20010 */   sw       $v0, 0x10($sp)
/* 33B65C E00264DC 8C430000 */  lw        $v1, ($v0)
/* 33B660 E00264E0 34630002 */  ori       $v1, $v1, 2
/* 33B664 E00264E4 AC430000 */  sw        $v1, ($v0)
/* 33B668 E00264E8 8FBF0020 */  lw        $ra, 0x20($sp)
/* 33B66C E00264EC 03E00008 */  jr        $ra
/* 33B670 E00264F0 27BD0028 */   addiu    $sp, $sp, 0x28
