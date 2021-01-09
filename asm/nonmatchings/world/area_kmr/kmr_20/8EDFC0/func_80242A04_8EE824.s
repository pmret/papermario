.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242A04_8EE824
/* 8EE824 80242A04 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 8EE828 80242A08 2402002D */  addiu     $v0, $zero, 0x2d
/* 8EE82C 80242A0C AFA20010 */  sw        $v0, 0x10($sp)
/* 8EE830 80242A10 3C028024 */  lui       $v0, %hi(func_80242870_8EDE2C)
/* 8EE834 80242A14 24422870 */  addiu     $v0, $v0, %lo(func_80242870_8EDE2C)
/* 8EE838 80242A18 27A40010 */  addiu     $a0, $sp, 0x10
/* 8EE83C 80242A1C AFBF0020 */  sw        $ra, 0x20($sp)
/* 8EE840 80242A20 AFA00018 */  sw        $zero, 0x18($sp)
/* 8EE844 80242A24 AFA2001C */  sw        $v0, 0x1c($sp)
/* 8EE848 80242A28 0C047644 */  jal       queue_render_task
/* 8EE84C 80242A2C AFA00014 */   sw       $zero, 0x14($sp)
/* 8EE850 80242A30 8FBF0020 */  lw        $ra, 0x20($sp)
/* 8EE854 80242A34 03E00008 */  jr        $ra
/* 8EE858 80242A38 27BD0028 */   addiu    $sp, $sp, 0x28
