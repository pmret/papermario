.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0012504
/* 32E214 E0012504 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 32E218 E0012508 3C02E001 */  lui       $v0, %hi(func_E0012564)
/* 32E21C E001250C 24422564 */  addiu     $v0, $v0, %lo(func_E0012564)
/* 32E220 E0012510 AFA2001C */  sw        $v0, 0x1c($sp)
/* 32E224 E0012514 24020028 */  addiu     $v0, $zero, 0x28
/* 32E228 E0012518 AFA40018 */  sw        $a0, 0x18($sp)
/* 32E22C E001251C 27A40010 */  addiu     $a0, $sp, 0x10
/* 32E230 E0012520 AFBF0020 */  sw        $ra, 0x20($sp)
/* 32E234 E0012524 AFA00014 */  sw        $zero, 0x14($sp)
/* 32E238 E0012528 0C080120 */  jal       shim_queue_render_task
/* 32E23C E001252C AFA20010 */   sw       $v0, 0x10($sp)
/* 32E240 E0012530 8C430000 */  lw        $v1, ($v0)
/* 32E244 E0012534 34630002 */  ori       $v1, $v1, 2
/* 32E248 E0012538 AC430000 */  sw        $v1, ($v0)
/* 32E24C E001253C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 32E250 E0012540 03E00008 */  jr        $ra
/* 32E254 E0012544 27BD0028 */   addiu    $sp, $sp, 0x28
