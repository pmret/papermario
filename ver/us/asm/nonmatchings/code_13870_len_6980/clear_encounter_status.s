.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel clear_encounter_status
/* 19800 8003E400 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 19804 8003E404 AFBF0010 */  sw        $ra, 0x10($sp)
/* 19808 8003E408 24050017 */  addiu     $a1, $zero, 0x17
/* 1980C 8003E40C 3C07800B */  lui       $a3, %hi(gCurrentEncounter)
/* 19810 8003E410 24E70F10 */  addiu     $a3, $a3, %lo(gCurrentEncounter)
/* 19814 8003E414 24E2005C */  addiu     $v0, $a3, 0x5c
.L8003E418:
/* 19818 8003E418 AC400028 */  sw        $zero, 0x28($v0)
/* 1981C 8003E41C 24A5FFFF */  addiu     $a1, $a1, -1
/* 19820 8003E420 04A1FFFD */  bgez      $a1, .L8003E418
/* 19824 8003E424 2442FFFC */   addiu    $v0, $v0, -4
/* 19828 8003E428 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 1982C 8003E42C 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 19830 8003E430 8442008A */  lh        $v0, 0x8a($v0)
/* 19834 8003E434 10400019 */  beqz      $v0, .L8003E49C
/* 19838 8003E438 0000282D */   daddu    $a1, $zero, $zero
/* 1983C 8003E43C 00A0302D */  daddu     $a2, $a1, $zero
.L8003E440:
/* 19840 8003E440 0000202D */  daddu     $a0, $zero, $zero
/* 19844 8003E444 00C0182D */  daddu     $v1, $a2, $zero
.L8003E448:
/* 19848 8003E448 00E31021 */  addu      $v0, $a3, $v1
/* 1984C 8003E44C AC4000B0 */  sw        $zero, 0xb0($v0)
/* 19850 8003E450 24840001 */  addiu     $a0, $a0, 1
/* 19854 8003E454 2882000C */  slti      $v0, $a0, 0xc
/* 19858 8003E458 1440FFFB */  bnez      $v0, .L8003E448
/* 1985C 8003E45C 24630004 */   addiu    $v1, $v1, 4
/* 19860 8003E460 24A50001 */  addiu     $a1, $a1, 1
/* 19864 8003E464 28A2003C */  slti      $v0, $a1, 0x3c
/* 19868 8003E468 1440FFF5 */  bnez      $v0, .L8003E440
/* 1986C 8003E46C 24C60030 */   addiu    $a2, $a2, 0x30
/* 19870 8003E470 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 19874 8003E474 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 19878 8003E478 8442008A */  lh        $v0, 0x8a($v0)
/* 1987C 8003E47C 10400007 */  beqz      $v0, .L8003E49C
/* 19880 8003E480 2403FFFF */   addiu    $v1, $zero, -1
/* 19884 8003E484 24050001 */  addiu     $a1, $zero, 1
/* 19888 8003E488 24E20002 */  addiu     $v0, $a3, 2
.L8003E48C:
/* 1988C 8003E48C A4430BF0 */  sh        $v1, 0xbf0($v0)
/* 19890 8003E490 24A5FFFF */  addiu     $a1, $a1, -1
/* 19894 8003E494 04A1FFFD */  bgez      $a1, .L8003E48C
/* 19898 8003E498 2442FFFE */   addiu    $v0, $v0, -2
.L8003E49C:
/* 1989C 8003E49C 3C048007 */  lui       $a0, %hi(gGameStatusPtr)
/* 198A0 8003E4A0 2484419C */  addiu     $a0, $a0, %lo(gGameStatusPtr)
/* 198A4 8003E4A4 8C820000 */  lw        $v0, ($a0)
/* 198A8 8003E4A8 A0E0001C */  sb        $zero, 0x1c($a3)
/* 198AC 8003E4AC A0E00004 */  sb        $zero, 4($a3)
/* 198B0 8003E4B0 A0E00005 */  sb        $zero, 5($a3)
/* 198B4 8003E4B4 A0E0000A */  sb        $zero, 0xa($a3)
/* 198B8 8003E4B8 8C830000 */  lw        $v1, ($a0)
/* 198BC 8003E4BC 90420087 */  lbu       $v0, 0x87($v0)
/* 198C0 8003E4C0 A0E2001D */  sb        $v0, 0x1d($a3)
/* 198C4 8003E4C4 9062008D */  lbu       $v0, 0x8d($v1)
/* 198C8 8003E4C8 8C830000 */  lw        $v1, ($a0)
/* 198CC 8003E4CC A0E2001E */  sb        $v0, 0x1e($a3)
/* 198D0 8003E4D0 9062008F */  lbu       $v0, 0x8f($v1)
/* 198D4 8003E4D4 ACE00024 */  sw        $zero, 0x24($a3)
/* 198D8 8003E4D8 A0E00008 */  sb        $zero, 8($a3)
/* 198DC 8003E4DC A0E00012 */  sb        $zero, 0x12($a3)
/* 198E0 8003E4E0 0C0116B0 */  jal       func_80045AC0
/* 198E4 8003E4E4 A0E2001F */   sb       $v0, 0x1f($a3)
/* 198E8 8003E4E8 3C058004 */  lui       $a1, %hi(func_8003E670)
/* 198EC 8003E4EC 24A5E670 */  addiu     $a1, $a1, %lo(func_8003E670)
/* 198F0 8003E4F0 3C01800A */  lui       $at, %hi(gGameState)
/* 198F4 8003E4F4 AC20A600 */  sw        $zero, %lo(gGameState)($at)
/* 198F8 8003E4F8 0C048C56 */  jal       bind_dynamic_entity_3
/* 198FC 8003E4FC 0000202D */   daddu    $a0, $zero, $zero
/* 19900 8003E500 8FBF0010 */  lw        $ra, 0x10($sp)
/* 19904 8003E504 03E00008 */  jr        $ra
/* 19908 8003E508 27BD0018 */   addiu    $sp, $sp, 0x18
