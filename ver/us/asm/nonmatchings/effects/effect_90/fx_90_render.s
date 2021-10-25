.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_90_render
/* 3B621C E00B452C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3B6220 E00B4530 3C02E00B */  lui       $v0, %hi(fx_90_appendGfx)
/* 3B6224 E00B4534 2442457C */  addiu     $v0, $v0, %lo(fx_90_appendGfx)
/* 3B6228 E00B4538 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3B622C E00B453C 24020014 */  addiu     $v0, $zero, 0x14
/* 3B6230 E00B4540 AFA20014 */  sw        $v0, 0x14($sp)
/* 3B6234 E00B4544 2402002D */  addiu     $v0, $zero, 0x2d
/* 3B6238 E00B4548 AFA40018 */  sw        $a0, 0x18($sp)
/* 3B623C E00B454C 27A40010 */  addiu     $a0, $sp, 0x10
/* 3B6240 E00B4550 AFBF0020 */  sw        $ra, 0x20($sp)
/* 3B6244 E00B4554 0C080120 */  jal       shim_queue_render_task
/* 3B6248 E00B4558 AFA20010 */   sw       $v0, 0x10($sp)
/* 3B624C E00B455C 8C430000 */  lw        $v1, ($v0)
/* 3B6250 E00B4560 34630002 */  ori       $v1, $v1, 2
/* 3B6254 E00B4564 AC430000 */  sw        $v1, ($v0)
/* 3B6258 E00B4568 8FBF0020 */  lw        $ra, 0x20($sp)
/* 3B625C E00B456C 03E00008 */  jr        $ra
/* 3B6260 E00B4570 27BD0028 */   addiu    $sp, $sp, 0x28
