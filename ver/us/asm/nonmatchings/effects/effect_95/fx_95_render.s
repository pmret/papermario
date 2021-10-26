.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_95_render
/* 3BC4D8 E00BE578 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3BC4DC E00BE57C 3C02E00C */  lui       $v0, %hi(fx_95_appendGfx)
/* 3BC4E0 E00BE580 2442E5BC */  addiu     $v0, $v0, %lo(fx_95_appendGfx)
/* 3BC4E4 E00BE584 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3BC4E8 E00BE588 2402000A */  addiu     $v0, $zero, 0xa
/* 3BC4EC E00BE58C AFA20014 */  sw        $v0, 0x14($sp)
/* 3BC4F0 E00BE590 2402002D */  addiu     $v0, $zero, 0x2d
/* 3BC4F4 E00BE594 AFA40018 */  sw        $a0, 0x18($sp)
/* 3BC4F8 E00BE598 27A40010 */  addiu     $a0, $sp, 0x10
/* 3BC4FC E00BE59C AFBF0020 */  sw        $ra, 0x20($sp)
/* 3BC500 E00BE5A0 0C080120 */  jal       shim_queue_render_task
/* 3BC504 E00BE5A4 AFA20010 */   sw       $v0, 0x10($sp)
/* 3BC508 E00BE5A8 8FBF0020 */  lw        $ra, 0x20($sp)
/* 3BC50C E00BE5AC 03E00008 */  jr        $ra
/* 3BC510 E00BE5B0 27BD0028 */   addiu    $sp, $sp, 0x28
