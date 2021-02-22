.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403C4_91E934
/* 91E934 802403C4 3C028011 */  lui       $v0, %hi(gPlayerData)
/* 91E938 802403C8 2442F290 */  addiu     $v0, $v0, %lo(gPlayerData)
/* 91E93C 802403CC 000420C0 */  sll       $a0, $a0, 3
/* 91E940 802403D0 00822021 */  addu      $a0, $a0, $v0
/* 91E944 802403D4 90820014 */  lbu       $v0, 0x14($a0)
/* 91E948 802403D8 10400009 */  beqz      $v0, .L80240400
/* 91E94C 802403DC 00000000 */   nop
/* 91E950 802403E0 90820015 */  lbu       $v0, 0x15($a0)
/* 91E954 802403E4 00022600 */  sll       $a0, $v0, 0x18
/* 91E958 802403E8 00041E03 */  sra       $v1, $a0, 0x18
/* 91E95C 802403EC 00051400 */  sll       $v0, $a1, 0x10
/* 91E960 802403F0 00021403 */  sra       $v0, $v0, 0x10
/* 91E964 802403F4 0043102A */  slt       $v0, $v0, $v1
/* 91E968 802403F8 10400003 */  beqz      $v0, .L80240408
/* 91E96C 802403FC 00000000 */   nop
.L80240400:
/* 91E970 80240400 03E00008 */  jr        $ra
/* 91E974 80240404 2402FFFF */   addiu    $v0, $zero, -1
.L80240408:
/* 91E978 80240408 03E00008 */  jr        $ra
/* 91E97C 8024040C 00041603 */   sra      $v0, $a0, 0x18
