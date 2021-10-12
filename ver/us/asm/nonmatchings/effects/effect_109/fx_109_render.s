.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_109_render
/* 3D7420 E00DA1E0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3D7424 E00DA1E4 3C02E00E */  lui       $v0, %hi(func_E00DA230)
/* 3D7428 E00DA1E8 2442A230 */  addiu     $v0, $v0, %lo(func_E00DA230)
/* 3D742C E00DA1EC AFA2001C */  sw        $v0, 0x1c($sp)
/* 3D7430 E00DA1F0 2402000A */  addiu     $v0, $zero, 0xa
/* 3D7434 E00DA1F4 AFA20014 */  sw        $v0, 0x14($sp)
/* 3D7438 E00DA1F8 2402002D */  addiu     $v0, $zero, 0x2d
/* 3D743C E00DA1FC AFA40018 */  sw        $a0, 0x18($sp)
/* 3D7440 E00DA200 27A40010 */  addiu     $a0, $sp, 0x10
/* 3D7444 E00DA204 AFBF0020 */  sw        $ra, 0x20($sp)
/* 3D7448 E00DA208 0C080120 */  jal       shim_queue_render_task
/* 3D744C E00DA20C AFA20010 */   sw       $v0, 0x10($sp)
/* 3D7450 E00DA210 8C430000 */  lw        $v1, ($v0)
/* 3D7454 E00DA214 34630002 */  ori       $v1, $v1, 2
/* 3D7458 E00DA218 AC430000 */  sw        $v1, ($v0)
/* 3D745C E00DA21C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 3D7460 E00DA220 03E00008 */  jr        $ra
/* 3D7464 E00DA224 27BD0028 */   addiu    $sp, $sp, 0x28
