.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_112_render
/* 3DBA10 E00E05B0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3DBA14 E00E05B4 3C02E00E */  lui       $v0, %hi(fx_112_appendGfx)
/* 3DBA18 E00E05B8 24420600 */  addiu     $v0, $v0, %lo(fx_112_appendGfx)
/* 3DBA1C E00E05BC AFA2001C */  sw        $v0, 0x1c($sp)
/* 3DBA20 E00E05C0 2402000A */  addiu     $v0, $zero, 0xa
/* 3DBA24 E00E05C4 AFA20014 */  sw        $v0, 0x14($sp)
/* 3DBA28 E00E05C8 2402002D */  addiu     $v0, $zero, 0x2d
/* 3DBA2C E00E05CC AFA40018 */  sw        $a0, 0x18($sp)
/* 3DBA30 E00E05D0 27A40010 */  addiu     $a0, $sp, 0x10
/* 3DBA34 E00E05D4 AFBF0020 */  sw        $ra, 0x20($sp)
/* 3DBA38 E00E05D8 0C080120 */  jal       shim_queue_render_task
/* 3DBA3C E00E05DC AFA20010 */   sw       $v0, 0x10($sp)
/* 3DBA40 E00E05E0 8C430000 */  lw        $v1, ($v0)
/* 3DBA44 E00E05E4 34630002 */  ori       $v1, $v1, 2
/* 3DBA48 E00E05E8 AC430000 */  sw        $v1, ($v0)
/* 3DBA4C E00E05EC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 3DBA50 E00E05F0 03E00008 */  jr        $ra
/* 3DBA54 E00E05F4 27BD0028 */   addiu    $sp, $sp, 0x28
