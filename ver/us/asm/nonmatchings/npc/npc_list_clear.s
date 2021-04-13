.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel npc_list_clear
/* 138BC 800384BC 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 138C0 800384C0 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 138C4 800384C4 80420070 */  lb        $v0, 0x70($v0)
/* 138C8 800384C8 14400005 */  bnez      $v0, .L800384E0
/* 138CC 800384CC 00000000 */   nop
/* 138D0 800384D0 3C02800A */  lui       $v0, %hi(gWorldNpcList)
/* 138D4 800384D4 24420990 */  addiu     $v0, $v0, %lo(gWorldNpcList)
/* 138D8 800384D8 0800E13A */  j         .L800384E8
/* 138DC 800384DC 00000000 */   nop
.L800384E0:
/* 138E0 800384E0 3C02800A */  lui       $v0, %hi(gBattleNpcList)
/* 138E4 800384E4 24420A90 */  addiu     $v0, $v0, %lo(gBattleNpcList)
.L800384E8:
/* 138E8 800384E8 3C01800A */  lui       $at, %hi(gCurrentNpcListPtr)
/* 138EC 800384EC AC220B90 */  sw        $v0, %lo(gCurrentNpcListPtr)($at)
/* 138F0 800384F0 3C02800A */  lui       $v0, %hi(gCurrentNpcListPtr)
/* 138F4 800384F4 8C420B90 */  lw        $v0, %lo(gCurrentNpcListPtr)($v0)
/* 138F8 800384F8 2403003F */  addiu     $v1, $zero, 0x3f
/* 138FC 800384FC 244200FC */  addiu     $v0, $v0, 0xfc
.L80038500:
/* 13900 80038500 AC400000 */  sw        $zero, ($v0)
/* 13904 80038504 2463FFFF */  addiu     $v1, $v1, -1
/* 13908 80038508 0461FFFD */  bgez      $v1, .L80038500
/* 1390C 8003850C 2442FFFC */   addiu    $v0, $v0, -4
/* 13910 80038510 24020001 */  addiu     $v0, $zero, 1
/* 13914 80038514 3C01800A */  lui       $at, %hi(D_8009A604)
/* 13918 80038518 A420A604 */  sh        $zero, %lo(D_8009A604)($at)
/* 1391C 8003851C 3C01800A */  lui       $at, %hi(D_800A0B94)
/* 13920 80038520 A0220B94 */  sb        $v0, %lo(D_800A0B94)($at)
/* 13924 80038524 03E00008 */  jr        $ra
/* 13928 80038528 00000000 */   nop
