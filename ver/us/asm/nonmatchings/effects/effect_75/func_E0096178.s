.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0096178
/* 3943F8 E0096178 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3943FC E009617C 3C02E009 */  lui       $v0, %hi(func_E00961BC)
/* 394400 E0096180 244261BC */  addiu     $v0, $v0, %lo(func_E00961BC)
/* 394404 E0096184 AFA2001C */  sw        $v0, 0x1c($sp)
/* 394408 E0096188 24020001 */  addiu     $v0, $zero, 1
/* 39440C E009618C AFA40018 */  sw        $a0, 0x18($sp)
/* 394410 E0096190 27A40010 */  addiu     $a0, $sp, 0x10
/* 394414 E0096194 AFBF0020 */  sw        $ra, 0x20($sp)
/* 394418 E0096198 AFA00014 */  sw        $zero, 0x14($sp)
/* 39441C E009619C 0C080120 */  jal       shim_queue_render_task
/* 394420 E00961A0 AFA20010 */   sw       $v0, 0x10($sp)
/* 394424 E00961A4 8C430000 */  lw        $v1, ($v0)
/* 394428 E00961A8 34630002 */  ori       $v1, $v1, 2
/* 39442C E00961AC AC430000 */  sw        $v1, ($v0)
/* 394430 E00961B0 8FBF0020 */  lw        $ra, 0x20($sp)
/* 394434 E00961B4 03E00008 */  jr        $ra
/* 394438 E00961B8 27BD0028 */   addiu    $sp, $sp, 0x28
