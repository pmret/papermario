.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E011E530
/* 409EC0 E011E530 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 409EC4 E011E534 3C02E012 */  lui       $v0, %hi(func_E011E578)
/* 409EC8 E011E538 2442E578 */  addiu     $v0, $v0, %lo(func_E011E578)
/* 409ECC E011E53C AFA2001C */  sw        $v0, 0x1c($sp)
/* 409ED0 E011E540 24020005 */  addiu     $v0, $zero, 5
/* 409ED4 E011E544 AFA20014 */  sw        $v0, 0x14($sp)
/* 409ED8 E011E548 2402002D */  addiu     $v0, $zero, 0x2d
/* 409EDC E011E54C AFA40018 */  sw        $a0, 0x18($sp)
/* 409EE0 E011E550 27A40010 */  addiu     $a0, $sp, 0x10
/* 409EE4 E011E554 AFBF0020 */  sw        $ra, 0x20($sp)
/* 409EE8 E011E558 0C080120 */  jal       shim_queue_render_task
/* 409EEC E011E55C AFA20010 */   sw       $v0, 0x10($sp)
/* 409EF0 E011E560 8C430000 */  lw        $v1, ($v0)
/* 409EF4 E011E564 34630002 */  ori       $v1, $v1, 2
/* 409EF8 E011E568 AC430000 */  sw        $v1, ($v0)
/* 409EFC E011E56C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 409F00 E011E570 03E00008 */  jr        $ra
/* 409F04 E011E574 27BD0028 */   addiu    $sp, $sp, 0x28
