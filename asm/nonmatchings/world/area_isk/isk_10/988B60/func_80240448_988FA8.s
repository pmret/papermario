.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240448_988FA8
/* 988FA8 80240448 3C028011 */  lui       $v0, %hi(gPlayerData+0x12)
/* 988FAC 8024044C 8042F2A2 */  lb        $v0, %lo(gPlayerData+0x12)($v0)
/* 988FB0 80240450 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 988FB4 80240454 AFBF0010 */  sw        $ra, 0x10($sp)
/* 988FB8 80240458 00021100 */  sll       $v0, $v0, 4
/* 988FBC 8024045C 3C048009 */  lui       $a0, %hi(D_8008EF20)
/* 988FC0 80240460 00822021 */  addu      $a0, $a0, $v0
/* 988FC4 80240464 8C84EF20 */  lw        $a0, %lo(D_8008EF20)($a0)
/* 988FC8 80240468 0C0496CF */  jal       set_message_string
/* 988FCC 8024046C 0000282D */   daddu    $a1, $zero, $zero
/* 988FD0 80240470 8FBF0010 */  lw        $ra, 0x10($sp)
/* 988FD4 80240474 24020002 */  addiu     $v0, $zero, 2
/* 988FD8 80240478 03E00008 */  jr        $ra
/* 988FDC 8024047C 27BD0018 */   addiu    $sp, $sp, 0x18
