.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80266B14
/* 1953F4 80266B14 0000302D */  daddu     $a2, $zero, $zero
/* 1953F8 80266B18 3C07FFF7 */  lui       $a3, 0xfff7
/* 1953FC 80266B1C 34E7FFFF */  ori       $a3, $a3, 0xffff
/* 195400 80266B20 3C05800E */  lui       $a1, %hi(gBattleStatus)
/* 195404 80266B24 24A5C070 */  addiu     $a1, $a1, %lo(gBattleStatus)
.L80266B28:
/* 195408 80266B28 8CA400E0 */  lw        $a0, 0xe0($a1)
/* 19540C 80266B2C 5080000D */  beql      $a0, $zero, .L80266B64
/* 195410 80266B30 24C60001 */   addiu    $a2, $a2, 1
/* 195414 80266B34 80820206 */  lb        $v0, 0x206($a0)
/* 195418 80266B38 90830206 */  lbu       $v1, 0x206($a0)
/* 19541C 80266B3C 18400009 */  blez      $v0, .L80266B64
/* 195420 80266B40 24C60001 */   addiu    $a2, $a2, 1
/* 195424 80266B44 2462FFFF */  addiu     $v0, $v1, -1
/* 195428 80266B48 A0820206 */  sb        $v0, 0x206($a0)
/* 19542C 80266B4C 00021600 */  sll       $v0, $v0, 0x18
/* 195430 80266B50 14400004 */  bnez      $v0, .L80266B64
/* 195434 80266B54 00000000 */   nop      
/* 195438 80266B58 8C820000 */  lw        $v0, ($a0)
/* 19543C 80266B5C 00471024 */  and       $v0, $v0, $a3
/* 195440 80266B60 AC820000 */  sw        $v0, ($a0)
.L80266B64:
/* 195444 80266B64 28C20018 */  slti      $v0, $a2, 0x18
/* 195448 80266B68 1440FFEF */  bnez      $v0, .L80266B28
/* 19544C 80266B6C 24A50004 */   addiu    $a1, $a1, 4
/* 195450 80266B70 03E00008 */  jr        $ra
/* 195454 80266B74 00000000 */   nop      
