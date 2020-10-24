.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240410_7E77B0
/* 7E77B0 80240410 24050001 */  addiu     $a1, $zero, 1
/* 7E77B4 80240414 3C028011 */  lui       $v0, %hi(gPlayerData)
/* 7E77B8 80240418 2442F290 */  addiu     $v0, $v0, %lo(gPlayerData)
/* 7E77BC 8024041C 24440008 */  addiu     $a0, $v0, 8
/* 7E77C0 80240420 24030008 */  addiu     $v1, $zero, 8
/* 7E77C4 80240424 A0430002 */  sb        $v1, 2($v0)
/* 7E77C8 80240428 A0430003 */  sb        $v1, 3($v0)
/* 7E77CC 8024042C 00A0182D */  daddu     $v1, $a1, $zero
/* 7E77D0 80240430 A0400000 */  sb        $zero, ($v0)
/* 7E77D4 80240434 A0400001 */  sb        $zero, 1($v0)
/* 7E77D8 80240438 A040000E */  sb        $zero, 0xe($v0)
/* 7E77DC 8024043C A0430014 */  sb        $v1, 0x14($v0)
.L80240440:
/* 7E77E0 80240440 A0800014 */  sb        $zero, 0x14($a0)
/* 7E77E4 80240444 24A50001 */  addiu     $a1, $a1, 1
/* 7E77E8 80240448 28A2000C */  slti      $v0, $a1, 0xc
/* 7E77EC 8024044C 1440FFFC */  bnez      $v0, .L80240440
/* 7E77F0 80240450 24840008 */   addiu    $a0, $a0, 8
/* 7E77F4 80240454 03E00008 */  jr        $ra
/* 7E77F8 80240458 24020002 */   addiu    $v0, $zero, 2
