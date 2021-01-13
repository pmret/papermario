.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240CF0_8898C0
/* 8898C0 80240CF0 3C028011 */  lui       $v0, %hi(gPlayerData)
/* 8898C4 80240CF4 2442F290 */  addiu     $v0, $v0, %lo(gPlayerData)
/* 8898C8 80240CF8 000420C0 */  sll       $a0, $a0, 3
/* 8898CC 80240CFC 00822021 */  addu      $a0, $a0, $v0
/* 8898D0 80240D00 90820014 */  lbu       $v0, 0x14($a0)
/* 8898D4 80240D04 10400009 */  beqz      $v0, .L80240D2C
/* 8898D8 80240D08 00000000 */   nop
/* 8898DC 80240D0C 90820015 */  lbu       $v0, 0x15($a0)
/* 8898E0 80240D10 00022600 */  sll       $a0, $v0, 0x18
/* 8898E4 80240D14 00041E03 */  sra       $v1, $a0, 0x18
/* 8898E8 80240D18 00051400 */  sll       $v0, $a1, 0x10
/* 8898EC 80240D1C 00021403 */  sra       $v0, $v0, 0x10
/* 8898F0 80240D20 0043102A */  slt       $v0, $v0, $v1
/* 8898F4 80240D24 10400003 */  beqz      $v0, .L80240D34
/* 8898F8 80240D28 00000000 */   nop
.L80240D2C:
/* 8898FC 80240D2C 03E00008 */  jr        $ra
/* 889900 80240D30 2402FFFF */   addiu    $v0, $zero, -1
.L80240D34:
/* 889904 80240D34 03E00008 */  jr        $ra
/* 889908 80240D38 00041603 */   sra      $v0, $a0, 0x18
