.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021A254_6A1454
/* 6A1454 8021A254 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 6A1458 8021A258 AFBF0010 */  sw        $ra, 0x10($sp)
/* 6A145C 8021A25C 8C82000C */  lw        $v0, 0xc($a0)
/* 6A1460 8021A260 0C0B1EAF */  jal       get_variable
/* 6A1464 8021A264 8C450000 */   lw       $a1, ($v0)
/* 6A1468 8021A268 8C43000C */  lw        $v1, 0xc($v0)
/* 6A146C 8021A26C 3C013D23 */  lui       $at, 0x3d23
/* 6A1470 8021A270 3421D70A */  ori       $at, $at, 0xd70a
/* 6A1474 8021A274 44810000 */  mtc1      $at, $f0
/* 6A1478 8021A278 00000000 */  nop       
/* 6A147C 8021A27C E4600038 */  swc1      $f0, 0x38($v1)
/* 6A1480 8021A280 E4600030 */  swc1      $f0, 0x30($v1)
/* 6A1484 8021A284 8C43000C */  lw        $v1, 0xc($v0)
/* 6A1488 8021A288 3C013FF0 */  lui       $at, 0x3ff0
/* 6A148C 8021A28C 44810000 */  mtc1      $at, $f0
/* 6A1490 8021A290 00000000 */  nop       
/* 6A1494 8021A294 E4600034 */  swc1      $f0, 0x34($v1)
/* 6A1498 8021A298 8C43000C */  lw        $v1, 0xc($v0)
/* 6A149C 8021A29C 3C013D4C */  lui       $at, 0x3d4c
/* 6A14A0 8021A2A0 3421CCCD */  ori       $at, $at, 0xcccd
/* 6A14A4 8021A2A4 44810000 */  mtc1      $at, $f0
/* 6A14A8 8021A2A8 00000000 */  nop       
/* 6A14AC 8021A2AC E460003C */  swc1      $f0, 0x3c($v1)
/* 6A14B0 8021A2B0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 6A14B4 8021A2B4 24020002 */  addiu     $v0, $zero, 2
/* 6A14B8 8021A2B8 03E00008 */  jr        $ra
/* 6A14BC 8021A2BC 27BD0018 */   addiu    $sp, $sp, 0x18
