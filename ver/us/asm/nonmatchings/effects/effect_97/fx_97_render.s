.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_97_render
/* 3C139C E00C21CC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3C13A0 E00C21D0 3C02E00C */  lui       $v0, %hi(func_E00C221C)
/* 3C13A4 E00C21D4 2442221C */  addiu     $v0, $v0, %lo(func_E00C221C)
/* 3C13A8 E00C21D8 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3C13AC E00C21DC 2402000A */  addiu     $v0, $zero, 0xa
/* 3C13B0 E00C21E0 AFA20014 */  sw        $v0, 0x14($sp)
/* 3C13B4 E00C21E4 2402002D */  addiu     $v0, $zero, 0x2d
/* 3C13B8 E00C21E8 AFA40018 */  sw        $a0, 0x18($sp)
/* 3C13BC E00C21EC 27A40010 */  addiu     $a0, $sp, 0x10
/* 3C13C0 E00C21F0 AFBF0020 */  sw        $ra, 0x20($sp)
/* 3C13C4 E00C21F4 0C080120 */  jal       shim_queue_render_task
/* 3C13C8 E00C21F8 AFA20010 */   sw       $v0, 0x10($sp)
/* 3C13CC E00C21FC 8C430000 */  lw        $v1, ($v0)
/* 3C13D0 E00C2200 34630002 */  ori       $v1, $v1, 2
/* 3C13D4 E00C2204 AC430000 */  sw        $v1, ($v0)
/* 3C13D8 E00C2208 8FBF0020 */  lw        $ra, 0x20($sp)
/* 3C13DC E00C220C 03E00008 */  jr        $ra
/* 3C13E0 E00C2210 27BD0028 */   addiu    $sp, $sp, 0x28
