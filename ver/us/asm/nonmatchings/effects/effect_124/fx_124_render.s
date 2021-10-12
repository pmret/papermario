.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_124_render
/* 3FEE20 E0114340 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3FEE24 E0114344 3C02E011 */  lui       $v0, %hi(fx_124_appendGfx)
/* 3FEE28 E0114348 24424388 */  addiu     $v0, $v0, %lo(fx_124_appendGfx)
/* 3FEE2C E011434C AFA2001C */  sw        $v0, 0x1c($sp)
/* 3FEE30 E0114350 2402000A */  addiu     $v0, $zero, 0xa
/* 3FEE34 E0114354 AFA20014 */  sw        $v0, 0x14($sp)
/* 3FEE38 E0114358 2402002D */  addiu     $v0, $zero, 0x2d
/* 3FEE3C E011435C AFA40018 */  sw        $a0, 0x18($sp)
/* 3FEE40 E0114360 27A40010 */  addiu     $a0, $sp, 0x10
/* 3FEE44 E0114364 AFBF0020 */  sw        $ra, 0x20($sp)
/* 3FEE48 E0114368 0C080120 */  jal       shim_queue_render_task
/* 3FEE4C E011436C AFA20010 */   sw       $v0, 0x10($sp)
/* 3FEE50 E0114370 8C430000 */  lw        $v1, ($v0)
/* 3FEE54 E0114374 34630002 */  ori       $v1, $v1, 2
/* 3FEE58 E0114378 AC430000 */  sw        $v1, ($v0)
/* 3FEE5C E011437C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 3FEE60 E0114380 03E00008 */  jr        $ra
/* 3FEE64 E0114384 27BD0028 */   addiu    $sp, $sp, 0x28
