.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E006C5A0
/* 36E770 E006C5A0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 36E774 E006C5A4 3C02E007 */  lui       $v0, %hi(func_E006C5E8)
/* 36E778 E006C5A8 2442C5E8 */  addiu     $v0, $v0, %lo(func_E006C5E8)
/* 36E77C E006C5AC AFA2001C */  sw        $v0, 0x1c($sp)
/* 36E780 E006C5B0 2402000A */  addiu     $v0, $zero, 0xa
/* 36E784 E006C5B4 AFA20014 */  sw        $v0, 0x14($sp)
/* 36E788 E006C5B8 24020022 */  addiu     $v0, $zero, 0x22
/* 36E78C E006C5BC AFA40018 */  sw        $a0, 0x18($sp)
/* 36E790 E006C5C0 27A40010 */  addiu     $a0, $sp, 0x10
/* 36E794 E006C5C4 AFBF0020 */  sw        $ra, 0x20($sp)
/* 36E798 E006C5C8 0C080120 */  jal       shim_queue_render_task
/* 36E79C E006C5CC AFA20010 */   sw       $v0, 0x10($sp)
/* 36E7A0 E006C5D0 8C430000 */  lw        $v1, ($v0)
/* 36E7A4 E006C5D4 34630002 */  ori       $v1, $v1, 2
/* 36E7A8 E006C5D8 AC430000 */  sw        $v1, ($v0)
/* 36E7AC E006C5DC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 36E7B0 E006C5E0 03E00008 */  jr        $ra
/* 36E7B4 E006C5E4 27BD0028 */   addiu    $sp, $sp, 0x28
