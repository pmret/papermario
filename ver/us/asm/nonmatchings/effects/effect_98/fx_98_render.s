.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_98_render
/* 3CB0B4 E00C42C4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3CB0B8 E00C42C8 3C02E00C */  lui       $v0, %hi(fx_98_appendGfx)
/* 3CB0BC E00C42CC 24424308 */  addiu     $v0, $v0, %lo(fx_98_appendGfx)
/* 3CB0C0 E00C42D0 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3CB0C4 E00C42D4 2402000A */  addiu     $v0, $zero, 0xa
/* 3CB0C8 E00C42D8 AFA20014 */  sw        $v0, 0x14($sp)
/* 3CB0CC E00C42DC 2402002D */  addiu     $v0, $zero, 0x2d
/* 3CB0D0 E00C42E0 AFA40018 */  sw        $a0, 0x18($sp)
/* 3CB0D4 E00C42E4 27A40010 */  addiu     $a0, $sp, 0x10
/* 3CB0D8 E00C42E8 AFBF0020 */  sw        $ra, 0x20($sp)
/* 3CB0DC E00C42EC 0C080120 */  jal       shim_queue_render_task
/* 3CB0E0 E00C42F0 AFA20010 */   sw       $v0, 0x10($sp)
/* 3CB0E4 E00C42F4 8FBF0020 */  lw        $ra, 0x20($sp)
/* 3CB0E8 E00C42F8 03E00008 */  jr        $ra
/* 3CB0EC E00C42FC 27BD0028 */   addiu    $sp, $sp, 0x28
