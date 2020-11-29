.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241064_889C34
/* 889C34 80241064 3C028011 */  lui       $v0, %hi(gPlayerData+0x12)
/* 889C38 80241068 8042F2A2 */  lb        $v0, %lo(gPlayerData+0x12)($v0)
/* 889C3C 8024106C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 889C40 80241070 AFBF0010 */  sw        $ra, 0x10($sp)
/* 889C44 80241074 00021100 */  sll       $v0, $v0, 4
/* 889C48 80241078 3C048009 */  lui       $a0, %hi(D_8008EF20)
/* 889C4C 8024107C 00822021 */  addu      $a0, $a0, $v0
/* 889C50 80241080 8C84EF20 */  lw        $a0, %lo(D_8008EF20)($a0)
/* 889C54 80241084 0C0496CF */  jal       set_message_string
/* 889C58 80241088 0000282D */   daddu    $a1, $zero, $zero
/* 889C5C 8024108C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 889C60 80241090 24020002 */  addiu     $v0, $zero, 2
/* 889C64 80241094 03E00008 */  jr        $ra
/* 889C68 80241098 27BD0018 */   addiu    $sp, $sp, 0x18
