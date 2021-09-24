.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_6_renderWorld
/* 328864 E000C754 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 328868 E000C758 3C02E001 */  lui       $v0, %hi(func_E000C798)
/* 32886C E000C75C 2442C798 */  addiu     $v0, $v0, %lo(func_E000C798)
/* 328870 E000C760 AFA2001C */  sw        $v0, 0x1c($sp)
/* 328874 E000C764 24020028 */  addiu     $v0, $zero, 0x28
/* 328878 E000C768 AFA40018 */  sw        $a0, 0x18($sp)
/* 32887C E000C76C 27A40010 */  addiu     $a0, $sp, 0x10
/* 328880 E000C770 AFBF0020 */  sw        $ra, 0x20($sp)
/* 328884 E000C774 AFA00014 */  sw        $zero, 0x14($sp)
/* 328888 E000C778 0C080120 */  jal       shim_queue_render_task
/* 32888C E000C77C AFA20010 */   sw       $v0, 0x10($sp)
/* 328890 E000C780 8C430000 */  lw        $v1, ($v0)
/* 328894 E000C784 34630002 */  ori       $v1, $v1, 2
/* 328898 E000C788 AC430000 */  sw        $v1, ($v0)
/* 32889C E000C78C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 3288A0 E000C790 03E00008 */  jr        $ra
/* 3288A4 E000C794 27BD0028 */   addiu    $sp, $sp, 0x28
