.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_79_render
/* 3A02FC E009E3DC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3A0300 E009E3E0 3C02E00A */  lui       $v0, %hi(func_E009E424)
/* 3A0304 E009E3E4 2442E424 */  addiu     $v0, $v0, %lo(func_E009E424)
/* 3A0308 E009E3E8 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3A030C E009E3EC 2402000A */  addiu     $v0, $zero, 0xa
/* 3A0310 E009E3F0 AFA20014 */  sw        $v0, 0x14($sp)
/* 3A0314 E009E3F4 24020022 */  addiu     $v0, $zero, 0x22
/* 3A0318 E009E3F8 AFA40018 */  sw        $a0, 0x18($sp)
/* 3A031C E009E3FC 27A40010 */  addiu     $a0, $sp, 0x10
/* 3A0320 E009E400 AFBF0020 */  sw        $ra, 0x20($sp)
/* 3A0324 E009E404 0C080120 */  jal       shim_queue_render_task
/* 3A0328 E009E408 AFA20010 */   sw       $v0, 0x10($sp)
/* 3A032C E009E40C 8C430000 */  lw        $v1, ($v0)
/* 3A0330 E009E410 34630002 */  ori       $v1, $v1, 2
/* 3A0334 E009E414 AC430000 */  sw        $v1, ($v0)
/* 3A0338 E009E418 8FBF0020 */  lw        $ra, 0x20($sp)
/* 3A033C E009E41C 03E00008 */  jr        $ra
/* 3A0340 E009E420 27BD0028 */   addiu    $sp, $sp, 0x28
