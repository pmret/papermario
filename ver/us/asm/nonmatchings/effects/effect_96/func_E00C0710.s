.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00C0710
/* 3BD470 E00C0710 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3BD474 E00C0714 3C02E00C */  lui       $v0, %hi(func_E00C0760)
/* 3BD478 E00C0718 24420760 */  addiu     $v0, $v0, %lo(func_E00C0760)
/* 3BD47C E00C071C AFA2001C */  sw        $v0, 0x1c($sp)
/* 3BD480 E00C0720 2402FFF6 */  addiu     $v0, $zero, -0xa
/* 3BD484 E00C0724 AFA20014 */  sw        $v0, 0x14($sp)
/* 3BD488 E00C0728 24020028 */  addiu     $v0, $zero, 0x28
/* 3BD48C E00C072C AFA40018 */  sw        $a0, 0x18($sp)
/* 3BD490 E00C0730 27A40010 */  addiu     $a0, $sp, 0x10
/* 3BD494 E00C0734 AFBF0020 */  sw        $ra, 0x20($sp)
/* 3BD498 E00C0738 0C080120 */  jal       shim_queue_render_task
/* 3BD49C E00C073C AFA20010 */   sw       $v0, 0x10($sp)
/* 3BD4A0 E00C0740 8C430000 */  lw        $v1, ($v0)
/* 3BD4A4 E00C0744 34630002 */  ori       $v1, $v1, 2
/* 3BD4A8 E00C0748 AC430000 */  sw        $v1, ($v0)
/* 3BD4AC E00C074C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 3BD4B0 E00C0750 03E00008 */  jr        $ra
/* 3BD4B4 E00C0754 27BD0028 */   addiu    $sp, $sp, 0x28
