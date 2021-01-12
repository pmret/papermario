.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802463E0_806C60
/* 806C60 802463E0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 806C64 802463E4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 806C68 802463E8 0000202D */  daddu     $a0, $zero, $zero
/* 806C6C 802463EC 3C05F840 */  lui       $a1, 0xf840
/* 806C70 802463F0 0C0B1EAF */  jal       get_variable
/* 806C74 802463F4 34A55C84 */   ori      $a1, $a1, 0x5c84
/* 806C78 802463F8 14400008 */  bnez      $v0, .L8024641C
/* 806C7C 802463FC 0000202D */   daddu    $a0, $zero, $zero
/* 806C80 80246400 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 806C84 80246404 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 806C88 80246408 8C420140 */  lw        $v0, 0x140($v0)
/* 806C8C 8024640C 8C440000 */  lw        $a0, ($v0)
/* 806C90 80246410 0C04D052 */  jal       set_item_entity_flags
/* 806C94 80246414 24050040 */   addiu    $a1, $zero, 0x40
/* 806C98 80246418 0000202D */  daddu     $a0, $zero, $zero
.L8024641C:
/* 806C9C 8024641C 3C05F840 */  lui       $a1, 0xf840
/* 806CA0 80246420 0C0B1EAF */  jal       get_variable
/* 806CA4 80246424 34A55C85 */   ori      $a1, $a1, 0x5c85
/* 806CA8 80246428 14400008 */  bnez      $v0, .L8024644C
/* 806CAC 8024642C 0000202D */   daddu    $a0, $zero, $zero
/* 806CB0 80246430 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 806CB4 80246434 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 806CB8 80246438 8C420140 */  lw        $v0, 0x140($v0)
/* 806CBC 8024643C 8C440010 */  lw        $a0, 0x10($v0)
/* 806CC0 80246440 0C04D052 */  jal       set_item_entity_flags
/* 806CC4 80246444 24050040 */   addiu    $a1, $zero, 0x40
/* 806CC8 80246448 0000202D */  daddu     $a0, $zero, $zero
.L8024644C:
/* 806CCC 8024644C 3C05F840 */  lui       $a1, 0xf840
/* 806CD0 80246450 0C0B1EAF */  jal       get_variable
/* 806CD4 80246454 34A55C86 */   ori      $a1, $a1, 0x5c86
/* 806CD8 80246458 14400007 */  bnez      $v0, .L80246478
/* 806CDC 8024645C 00000000 */   nop
/* 806CE0 80246460 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 806CE4 80246464 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 806CE8 80246468 8C420140 */  lw        $v0, 0x140($v0)
/* 806CEC 8024646C 8C440020 */  lw        $a0, 0x20($v0)
/* 806CF0 80246470 0C04D052 */  jal       set_item_entity_flags
/* 806CF4 80246474 24050040 */   addiu    $a1, $zero, 0x40
.L80246478:
/* 806CF8 80246478 8FBF0010 */  lw        $ra, 0x10($sp)
/* 806CFC 8024647C 24020002 */  addiu     $v0, $zero, 2
/* 806D00 80246480 03E00008 */  jr        $ra
/* 806D04 80246484 27BD0018 */   addiu    $sp, $sp, 0x18
/* 806D08 80246488 00000000 */  nop
/* 806D0C 8024648C 00000000 */  nop
