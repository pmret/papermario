.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0128198
/* 414D38 E0128198 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 414D3C E012819C 3C02E013 */  lui       $v0, %hi(func_E01281E0)
/* 414D40 E01281A0 244281E0 */  addiu     $v0, $v0, %lo(func_E01281E0)
/* 414D44 E01281A4 AFA2001C */  sw        $v0, 0x1c($sp)
/* 414D48 E01281A8 2402000A */  addiu     $v0, $zero, 0xa
/* 414D4C E01281AC AFA20014 */  sw        $v0, 0x14($sp)
/* 414D50 E01281B0 2402002D */  addiu     $v0, $zero, 0x2d
/* 414D54 E01281B4 AFA40018 */  sw        $a0, 0x18($sp)
/* 414D58 E01281B8 27A40010 */  addiu     $a0, $sp, 0x10
/* 414D5C E01281BC AFBF0020 */  sw        $ra, 0x20($sp)
/* 414D60 E01281C0 0C080120 */  jal       shim_queue_render_task
/* 414D64 E01281C4 AFA20010 */   sw       $v0, 0x10($sp)
/* 414D68 E01281C8 8C430000 */  lw        $v1, ($v0)
/* 414D6C E01281CC 34630002 */  ori       $v1, $v1, 2
/* 414D70 E01281D0 AC430000 */  sw        $v1, ($v0)
/* 414D74 E01281D4 8FBF0020 */  lw        $ra, 0x20($sp)
/* 414D78 E01281D8 03E00008 */  jr        $ra
/* 414D7C E01281DC 27BD0028 */   addiu    $sp, $sp, 0x28
