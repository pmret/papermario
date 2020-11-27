.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80254950
/* 183230 80254950 3C04800E */  lui       $a0, %hi(gBattleStatus+0xD8)
/* 183234 80254954 8C84C148 */  lw        $a0, %lo(gBattleStatus+0xD8)($a0)
/* 183238 80254958 8C8201F4 */  lw        $v0, 0x1f4($a0)
/* 18323C 8025495C 8C4500C0 */  lw        $a1, 0xc0($v0)
/* 183240 80254960 80A207DB */  lb        $v0, 0x7db($a1)
/* 183244 80254964 90A307DB */  lbu       $v1, 0x7db($a1)
/* 183248 80254968 1040000B */  beqz      $v0, .L80254998
/* 18324C 8025496C 2462FFFF */   addiu    $v0, $v1, -1
/* 183250 80254970 A0A207DB */  sb        $v0, 0x7db($a1)
/* 183254 80254974 00021600 */  sll       $v0, $v0, 0x18
/* 183258 80254978 14400007 */  bnez      $v0, .L80254998
/* 18325C 8025497C 3C02EFFF */   lui      $v0, 0xefff
/* 183260 80254980 8C830000 */  lw        $v1, ($a0)
/* 183264 80254984 3442FFFF */  ori       $v0, $v0, 0xffff
/* 183268 80254988 00621824 */  and       $v1, $v1, $v0
/* 18326C 8025498C 24020001 */  addiu     $v0, $zero, 1
/* 183270 80254990 AC830000 */  sw        $v1, ($a0)
/* 183274 80254994 A0A208AC */  sb        $v0, 0x8ac($a1)
.L80254998:
/* 183278 80254998 03E00008 */  jr        $ra
/* 18327C 8025499C 00000000 */   nop      
