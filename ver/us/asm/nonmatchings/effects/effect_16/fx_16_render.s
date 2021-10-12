.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_16_render
/* 33444C E002058C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 334450 E0020590 3C02E002 */  lui       $v0, %hi(fx_16_appendGfx)
/* 334454 E0020594 244205D0 */  addiu     $v0, $v0, %lo(fx_16_appendGfx)
/* 334458 E0020598 AFA2001C */  sw        $v0, 0x1c($sp)
/* 33445C E002059C 2402002D */  addiu     $v0, $zero, 0x2d
/* 334460 E00205A0 AFA40018 */  sw        $a0, 0x18($sp)
/* 334464 E00205A4 27A40010 */  addiu     $a0, $sp, 0x10
/* 334468 E00205A8 AFBF0020 */  sw        $ra, 0x20($sp)
/* 33446C E00205AC AFA00014 */  sw        $zero, 0x14($sp)
/* 334470 E00205B0 0C080120 */  jal       shim_queue_render_task
/* 334474 E00205B4 AFA20010 */   sw       $v0, 0x10($sp)
/* 334478 E00205B8 8C430000 */  lw        $v1, ($v0)
/* 33447C E00205BC 34630002 */  ori       $v1, $v1, 2
/* 334480 E00205C0 AC430000 */  sw        $v1, ($v0)
/* 334484 E00205C4 8FBF0020 */  lw        $ra, 0x20($sp)
/* 334488 E00205C8 03E00008 */  jr        $ra
/* 33448C E00205CC 27BD0028 */   addiu    $sp, $sp, 0x28
