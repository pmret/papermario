.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_69_render
/* 38CCD4 E008A6E4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 38CCD8 E008A6E8 3C02E009 */  lui       $v0, %hi(func_E008A728)
/* 38CCDC E008A6EC 2442A728 */  addiu     $v0, $v0, %lo(func_E008A728)
/* 38CCE0 E008A6F0 AFA2001C */  sw        $v0, 0x1c($sp)
/* 38CCE4 E008A6F4 2402002D */  addiu     $v0, $zero, 0x2d
/* 38CCE8 E008A6F8 AFA40018 */  sw        $a0, 0x18($sp)
/* 38CCEC E008A6FC 27A40010 */  addiu     $a0, $sp, 0x10
/* 38CCF0 E008A700 AFBF0020 */  sw        $ra, 0x20($sp)
/* 38CCF4 E008A704 AFA00014 */  sw        $zero, 0x14($sp)
/* 38CCF8 E008A708 0C080120 */  jal       shim_queue_render_task
/* 38CCFC E008A70C AFA20010 */   sw       $v0, 0x10($sp)
/* 38CD00 E008A710 8C430000 */  lw        $v1, ($v0)
/* 38CD04 E008A714 34630002 */  ori       $v1, $v1, 2
/* 38CD08 E008A718 AC430000 */  sw        $v1, ($v0)
/* 38CD0C E008A71C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 38CD10 E008A720 03E00008 */  jr        $ra
/* 38CD14 E008A724 27BD0028 */   addiu    $sp, $sp, 0x28
