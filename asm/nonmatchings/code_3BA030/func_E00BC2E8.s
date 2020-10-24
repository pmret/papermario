.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00BC2E8
/* 3BA318 E00BC2E8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3BA31C E00BC2EC AFBF0020 */  sw        $ra, 0x20($sp)
/* 3BA320 E00BC2F0 8C85000C */  lw        $a1, 0xc($a0)
/* 3BA324 E00BC2F4 3C02E00C */  lui       $v0, 0xe00c
/* 3BA328 E00BC2F8 2442C374 */  addiu     $v0, $v0, -0x3c8c
/* 3BA32C E00BC2FC AFA2001C */  sw        $v0, 0x1c($sp)
/* 3BA330 E00BC300 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 3BA334 E00BC304 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 3BA338 E00BC308 AFA40018 */  sw        $a0, 0x18($sp)
/* 3BA33C E00BC30C 80430070 */  lb        $v1, 0x70($v0)
/* 3BA340 E00BC310 24020001 */  addiu     $v0, $zero, 1
/* 3BA344 E00BC314 1462000A */  bne       $v1, $v0, .LE00BC340
/* 3BA348 E00BC318 27A40010 */   addiu    $a0, $sp, 0x10
/* 3BA34C E00BC31C C4A0000C */  lwc1      $f0, 0xc($a1)
/* 3BA350 E00BC320 3C01447A */  lui       $at, 0x447a
/* 3BA354 E00BC324 44811000 */  mtc1      $at, $f2
/* 3BA358 E00BC328 00000000 */  nop       
/* 3BA35C E00BC32C 46020000 */  add.s     $f0, $f0, $f2
/* 3BA360 E00BC330 4600010D */  trunc.w.s $f4, $f0
/* 3BA364 E00BC334 E7A40014 */  swc1      $f4, 0x14($sp)
/* 3BA368 E00BC338 0802F0D3 */  j         .LE00BC34C
/* 3BA36C E00BC33C 2402002D */   addiu    $v0, $zero, 0x2d
.LE00BC340:
/* 3BA370 E00BC340 2402000A */  addiu     $v0, $zero, 0xa
/* 3BA374 E00BC344 AFA20014 */  sw        $v0, 0x14($sp)
/* 3BA378 E00BC348 2402002D */  addiu     $v0, $zero, 0x2d
.LE00BC34C:
/* 3BA37C E00BC34C 0C080120 */  jal       func_E0200480
/* 3BA380 E00BC350 AC820000 */   sw       $v0, ($a0)
/* 3BA384 E00BC354 8C430000 */  lw        $v1, ($v0)
/* 3BA388 E00BC358 34630002 */  ori       $v1, $v1, 2
/* 3BA38C E00BC35C AC430000 */  sw        $v1, ($v0)
/* 3BA390 E00BC360 8FBF0020 */  lw        $ra, 0x20($sp)
/* 3BA394 E00BC364 03E00008 */  jr        $ra
/* 3BA398 E00BC368 27BD0028 */   addiu    $sp, $sp, 0x28
