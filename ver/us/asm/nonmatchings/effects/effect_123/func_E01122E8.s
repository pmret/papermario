.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E01122E8
/* 3FA138 E01122E8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3FA13C E01122EC 3C02E011 */  lui       $v0, %hi(func_E01124CC)
/* 3FA140 E01122F0 244224CC */  addiu     $v0, $v0, %lo(func_E01124CC)
/* 3FA144 E01122F4 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3FA148 E01122F8 2402000A */  addiu     $v0, $zero, 0xa
/* 3FA14C E01122FC AFA20014 */  sw        $v0, 0x14($sp)
/* 3FA150 E0112300 24020011 */  addiu     $v0, $zero, 0x11
/* 3FA154 E0112304 AFA40018 */  sw        $a0, 0x18($sp)
/* 3FA158 E0112308 27A40010 */  addiu     $a0, $sp, 0x10
/* 3FA15C E011230C AFBF0020 */  sw        $ra, 0x20($sp)
/* 3FA160 E0112310 0C080120 */  jal       shim_queue_render_task
/* 3FA164 E0112314 AFA20010 */   sw       $v0, 0x10($sp)
/* 3FA168 E0112318 8C430000 */  lw        $v1, ($v0)
/* 3FA16C E011231C 34630002 */  ori       $v1, $v1, 2
/* 3FA170 E0112320 AC430000 */  sw        $v1, ($v0)
/* 3FA174 E0112324 8FBF0020 */  lw        $ra, 0x20($sp)
/* 3FA178 E0112328 03E00008 */  jr        $ra
/* 3FA17C E011232C 27BD0028 */   addiu    $sp, $sp, 0x28
