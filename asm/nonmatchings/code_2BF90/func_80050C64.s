.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80050C64
/* 2C064 80050C64 3C03800A */  lui       $v1, %hi(D_8009A628)
/* 2C068 80050C68 8C63A628 */  lw        $v1, %lo(D_8009A628)($v1)
/* 2C06C 80050C6C 00041100 */  sll       $v0, $a0, 4
/* 2C070 80050C70 00441023 */  subu      $v0, $v0, $a0
/* 2C074 80050C74 000210C0 */  sll       $v0, $v0, 3
/* 2C078 80050C78 00441021 */  addu      $v0, $v0, $a0
/* 2C07C 80050C7C 00021080 */  sll       $v0, $v0, 2
/* 2C080 80050C80 24420024 */  addiu     $v0, $v0, 0x24
/* 2C084 80050C84 14A00003 */  bnez      $a1, .L80050C94
/* 2C088 80050C88 00621821 */   addu     $v1, $v1, $v0
/* 2C08C 80050C8C 03E00008 */  jr        $ra
/* 2C090 80050C90 A0600025 */   sb       $zero, 0x25($v1)
.L80050C94:
/* 2C094 80050C94 24020002 */  addiu     $v0, $zero, 2
/* 2C098 80050C98 03E00008 */  jr        $ra
/* 2C09C 80050C9C A0620025 */   sb       $v0, 0x25($v1)
