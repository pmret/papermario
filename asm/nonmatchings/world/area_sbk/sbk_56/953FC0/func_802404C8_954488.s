.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802404C8_954488
/* 954488 802404C8 3C028011 */  lui       $v0, %hi(gPlayerData+0x12)
/* 95448C 802404CC 8042F2A2 */  lb        $v0, %lo(gPlayerData+0x12)($v0)
/* 954490 802404D0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 954494 802404D4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 954498 802404D8 00021100 */  sll       $v0, $v0, 4
/* 95449C 802404DC 3C048009 */  lui       $a0, %hi(D_8008EF20)
/* 9544A0 802404E0 00822021 */  addu      $a0, $a0, $v0
/* 9544A4 802404E4 8C84EF20 */  lw        $a0, %lo(D_8008EF20)($a0)
/* 9544A8 802404E8 0C0496CF */  jal       set_message_string
/* 9544AC 802404EC 0000282D */   daddu    $a1, $zero, $zero
/* 9544B0 802404F0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 9544B4 802404F4 24020002 */  addiu     $v0, $zero, 2
/* 9544B8 802404F8 03E00008 */  jr        $ra
/* 9544BC 802404FC 27BD0018 */   addiu    $sp, $sp, 0x18
