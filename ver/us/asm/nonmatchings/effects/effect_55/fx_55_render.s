.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_55_render
/* 372E74 E006E6E4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 372E78 E006E6E8 AFBF0020 */  sw        $ra, 0x20($sp)
/* 372E7C E006E6EC 8C85000C */  lw        $a1, 0xc($a0)
/* 372E80 E006E6F0 3C02E007 */  lui       $v0, %hi(fx_55_appendGfx)
/* 372E84 E006E6F4 2442E764 */  addiu     $v0, $v0, %lo(fx_55_appendGfx)
/* 372E88 E006E6F8 AFA2001C */  sw        $v0, 0x1c($sp)
/* 372E8C E006E6FC 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 372E90 E006E700 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 372E94 E006E704 AFA40018 */  sw        $a0, 0x18($sp)
/* 372E98 E006E708 80430070 */  lb        $v1, 0x70($v0)
/* 372E9C E006E70C 24020001 */  addiu     $v0, $zero, 1
/* 372EA0 E006E710 1462000A */  bne       $v1, $v0, .LE006E73C
/* 372EA4 E006E714 27A40010 */   addiu    $a0, $sp, 0x10
/* 372EA8 E006E718 C4A00014 */  lwc1      $f0, 0x14($a1)
/* 372EAC E006E71C 3C01447A */  lui       $at, 0x447a
/* 372EB0 E006E720 44811000 */  mtc1      $at, $f2
/* 372EB4 E006E724 00000000 */  nop
/* 372EB8 E006E728 46020000 */  add.s     $f0, $f0, $f2
/* 372EBC E006E72C 4600010D */  trunc.w.s $f4, $f0
/* 372EC0 E006E730 E7A40014 */  swc1      $f4, 0x14($sp)
/* 372EC4 E006E734 0801B9D1 */  j         .LE006E744
/* 372EC8 E006E738 2402002D */   addiu    $v0, $zero, 0x2d
.LE006E73C:
/* 372ECC E006E73C AFA00014 */  sw        $zero, 0x14($sp)
/* 372ED0 E006E740 2402002D */  addiu     $v0, $zero, 0x2d
.LE006E744:
/* 372ED4 E006E744 0C080120 */  jal       shim_queue_render_task
/* 372ED8 E006E748 AC820000 */   sw       $v0, ($a0)
/* 372EDC E006E74C 8C430000 */  lw        $v1, ($v0)
/* 372EE0 E006E750 34630002 */  ori       $v1, $v1, 2
/* 372EE4 E006E754 AC430000 */  sw        $v1, ($v0)
/* 372EE8 E006E758 8FBF0020 */  lw        $ra, 0x20($sp)
/* 372EEC E006E75C 03E00008 */  jr        $ra
/* 372EF0 E006E760 27BD0028 */   addiu    $sp, $sp, 0x28
