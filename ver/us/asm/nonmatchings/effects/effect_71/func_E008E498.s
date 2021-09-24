.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E008E498
/* 38F2F8 E008E498 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 38F2FC E008E49C 3C02E009 */  lui       $v0, %hi(func_E008E4E0)
/* 38F300 E008E4A0 2442E4E0 */  addiu     $v0, $v0, %lo(func_E008E4E0)
/* 38F304 E008E4A4 AFA2001C */  sw        $v0, 0x1c($sp)
/* 38F308 E008E4A8 2402000A */  addiu     $v0, $zero, 0xa
/* 38F30C E008E4AC AFA20014 */  sw        $v0, 0x14($sp)
/* 38F310 E008E4B0 24020022 */  addiu     $v0, $zero, 0x22
/* 38F314 E008E4B4 AFA40018 */  sw        $a0, 0x18($sp)
/* 38F318 E008E4B8 27A40010 */  addiu     $a0, $sp, 0x10
/* 38F31C E008E4BC AFBF0020 */  sw        $ra, 0x20($sp)
/* 38F320 E008E4C0 0C080120 */  jal       shim_queue_render_task
/* 38F324 E008E4C4 AFA20010 */   sw       $v0, 0x10($sp)
/* 38F328 E008E4C8 8C430000 */  lw        $v1, ($v0)
/* 38F32C E008E4CC 34630002 */  ori       $v1, $v1, 2
/* 38F330 E008E4D0 AC430000 */  sw        $v1, ($v0)
/* 38F334 E008E4D4 8FBF0020 */  lw        $ra, 0x20($sp)
/* 38F338 E008E4D8 03E00008 */  jr        $ra
/* 38F33C E008E4DC 27BD0028 */   addiu    $sp, $sp, 0x28
