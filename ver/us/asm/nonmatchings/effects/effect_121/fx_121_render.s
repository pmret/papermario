.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_121_render
/* 3EB9F0 E010E510 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3EB9F4 E010E514 3C02E011 */  lui       $v0, %hi(func_E010E558)
/* 3EB9F8 E010E518 2442E558 */  addiu     $v0, $v0, %lo(func_E010E558)
/* 3EB9FC E010E51C AFA2001C */  sw        $v0, 0x1c($sp)
/* 3EBA00 E010E520 2402000A */  addiu     $v0, $zero, 0xa
/* 3EBA04 E010E524 AFA20014 */  sw        $v0, 0x14($sp)
/* 3EBA08 E010E528 2402002D */  addiu     $v0, $zero, 0x2d
/* 3EBA0C E010E52C AFA40018 */  sw        $a0, 0x18($sp)
/* 3EBA10 E010E530 27A40010 */  addiu     $a0, $sp, 0x10
/* 3EBA14 E010E534 AFBF0020 */  sw        $ra, 0x20($sp)
/* 3EBA18 E010E538 0C080120 */  jal       shim_queue_render_task
/* 3EBA1C E010E53C AFA20010 */   sw       $v0, 0x10($sp)
/* 3EBA20 E010E540 8C430000 */  lw        $v1, ($v0)
/* 3EBA24 E010E544 34630002 */  ori       $v1, $v1, 2
/* 3EBA28 E010E548 AC430000 */  sw        $v1, ($v0)
/* 3EBA2C E010E54C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 3EBA30 E010E550 03E00008 */  jr        $ra
/* 3EBA34 E010E554 27BD0028 */   addiu    $sp, $sp, 0x28
