.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240AC8_886E88
/* 886E88 80240AC8 3C028011 */  lui       $v0, 0x8011
/* 886E8C 80240ACC 8042F2A2 */  lb        $v0, -0xd5e($v0)
/* 886E90 80240AD0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 886E94 80240AD4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 886E98 80240AD8 00021100 */  sll       $v0, $v0, 4
/* 886E9C 80240ADC 3C048009 */  lui       $a0, 0x8009
/* 886EA0 80240AE0 00822021 */  addu      $a0, $a0, $v0
/* 886EA4 80240AE4 8C84EF20 */  lw        $a0, -0x10e0($a0)
/* 886EA8 80240AE8 0C0496CF */  jal       set_message_string
/* 886EAC 80240AEC 0000282D */   daddu    $a1, $zero, $zero
/* 886EB0 80240AF0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 886EB4 80240AF4 24020002 */  addiu     $v0, $zero, 2
/* 886EB8 80240AF8 03E00008 */  jr        $ra
/* 886EBC 80240AFC 27BD0018 */   addiu    $sp, $sp, 0x18
