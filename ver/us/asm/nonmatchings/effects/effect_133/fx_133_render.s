.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_133_render
/* 413804 E01264A4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 413808 E01264A8 3C02E012 */  lui       $v0, %hi(fx_133_appendGfx)
/* 41380C E01264AC 244264EC */  addiu     $v0, $v0, %lo(fx_133_appendGfx)
/* 413810 E01264B0 AFA2001C */  sw        $v0, 0x1c($sp)
/* 413814 E01264B4 2402000A */  addiu     $v0, $zero, 0xa
/* 413818 E01264B8 AFA20014 */  sw        $v0, 0x14($sp)
/* 41381C E01264BC 2402002D */  addiu     $v0, $zero, 0x2d
/* 413820 E01264C0 AFA40018 */  sw        $a0, 0x18($sp)
/* 413824 E01264C4 27A40010 */  addiu     $a0, $sp, 0x10
/* 413828 E01264C8 AFBF0020 */  sw        $ra, 0x20($sp)
/* 41382C E01264CC 0C080120 */  jal       shim_queue_render_task
/* 413830 E01264D0 AFA20010 */   sw       $v0, 0x10($sp)
/* 413834 E01264D4 8C430000 */  lw        $v1, ($v0)
/* 413838 E01264D8 34630002 */  ori       $v1, $v1, 2
/* 41383C E01264DC AC430000 */  sw        $v1, ($v0)
/* 413840 E01264E0 8FBF0020 */  lw        $ra, 0x20($sp)
/* 413844 E01264E4 03E00008 */  jr        $ra
/* 413848 E01264E8 27BD0028 */   addiu    $sp, $sp, 0x28
