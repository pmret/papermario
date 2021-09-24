.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00C8404
/* 3CF7A4 E00C8404 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3CF7A8 E00C8408 3C02E00D */  lui       $v0, %hi(func_E00C8454)
/* 3CF7AC E00C840C 24428454 */  addiu     $v0, $v0, %lo(func_E00C8454)
/* 3CF7B0 E00C8410 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3CF7B4 E00C8414 2402000A */  addiu     $v0, $zero, 0xa
/* 3CF7B8 E00C8418 AFA20014 */  sw        $v0, 0x14($sp)
/* 3CF7BC E00C841C 2402002D */  addiu     $v0, $zero, 0x2d
/* 3CF7C0 E00C8420 AFA40018 */  sw        $a0, 0x18($sp)
/* 3CF7C4 E00C8424 27A40010 */  addiu     $a0, $sp, 0x10
/* 3CF7C8 E00C8428 AFBF0020 */  sw        $ra, 0x20($sp)
/* 3CF7CC E00C842C 0C080120 */  jal       shim_queue_render_task
/* 3CF7D0 E00C8430 AFA20010 */   sw       $v0, 0x10($sp)
/* 3CF7D4 E00C8434 8C430000 */  lw        $v1, ($v0)
/* 3CF7D8 E00C8438 34630002 */  ori       $v1, $v1, 2
/* 3CF7DC E00C843C AC430000 */  sw        $v1, ($v0)
/* 3CF7E0 E00C8440 8FBF0020 */  lw        $ra, 0x20($sp)
/* 3CF7E4 E00C8444 03E00008 */  jr        $ra
/* 3CF7E8 E00C8448 27BD0028 */   addiu    $sp, $sp, 0x28
