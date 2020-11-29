.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E4C_9EEA3C
/* 9EEA3C 80240E4C 10A00003 */  beqz      $a1, .L80240E5C
/* 9EEA40 80240E50 00000000 */   nop      
/* 9EEA44 80240E54 3C018024 */  lui       $at, %hi(D_80243254)
/* 9EEA48 80240E58 AC203254 */  sw        $zero, %lo(D_80243254)($at)
.L80240E5C:
/* 9EEA4C 80240E5C 3C028024 */  lui       $v0, %hi(D_80243254)
/* 9EEA50 80240E60 8C423254 */  lw        $v0, %lo(D_80243254)($v0)
/* 9EEA54 80240E64 0002102B */  sltu      $v0, $zero, $v0
/* 9EEA58 80240E68 03E00008 */  jr        $ra
/* 9EEA5C 80240E6C 00021040 */   sll      $v0, $v0, 1
