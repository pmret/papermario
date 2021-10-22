.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_92_render
/* 3B7D38 E00B81B8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3B7D3C E00B81BC 3C02E00C */  lui       $v0, %hi(fx_92_appendGfx)
/* 3B7D40 E00B81C0 24428208 */  addiu     $v0, $v0, %lo(fx_92_appendGfx)
/* 3B7D44 E00B81C4 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3B7D48 E00B81C8 2402000A */  addiu     $v0, $zero, 0xa
/* 3B7D4C E00B81CC AFA20014 */  sw        $v0, 0x14($sp)
/* 3B7D50 E00B81D0 2402002D */  addiu     $v0, $zero, 0x2d
/* 3B7D54 E00B81D4 AFA40018 */  sw        $a0, 0x18($sp)
/* 3B7D58 E00B81D8 27A40010 */  addiu     $a0, $sp, 0x10
/* 3B7D5C E00B81DC AFBF0020 */  sw        $ra, 0x20($sp)
/* 3B7D60 E00B81E0 0C080120 */  jal       shim_queue_render_task
/* 3B7D64 E00B81E4 AFA20010 */   sw       $v0, 0x10($sp)
/* 3B7D68 E00B81E8 8C430000 */  lw        $v1, ($v0)
/* 3B7D6C E00B81EC 34630002 */  ori       $v1, $v1, 2
/* 3B7D70 E00B81F0 AC430000 */  sw        $v1, ($v0)
/* 3B7D74 E00B81F4 8FBF0020 */  lw        $ra, 0x20($sp)
/* 3B7D78 E00B81F8 03E00008 */  jr        $ra
/* 3B7D7C E00B81FC 27BD0028 */   addiu    $sp, $sp, 0x28
