.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel jan_08_UnkFunc19
/* B5ED58 80240AA8 3C028011 */  lui       $v0, %hi(gPlayerData+0x12)
/* B5ED5C 80240AAC 8042F2A2 */  lb        $v0, %lo(gPlayerData+0x12)($v0)
/* B5ED60 80240AB0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B5ED64 80240AB4 AFBF0010 */  sw        $ra, 0x10($sp)
/* B5ED68 80240AB8 00021100 */  sll       $v0, $v0, 4
/* B5ED6C 80240ABC 3C048009 */  lui       $a0, %hi(D_8008EF20)
/* B5ED70 80240AC0 00822021 */  addu      $a0, $a0, $v0
/* B5ED74 80240AC4 8C84EF20 */  lw        $a0, %lo(D_8008EF20)($a0)
/* B5ED78 80240AC8 0C0496CF */  jal       set_message_string
/* B5ED7C 80240ACC 0000282D */   daddu    $a1, $zero, $zero
/* B5ED80 80240AD0 8FBF0010 */  lw        $ra, 0x10($sp)
/* B5ED84 80240AD4 24020002 */  addiu     $v0, $zero, 2
/* B5ED88 80240AD8 03E00008 */  jr        $ra
/* B5ED8C 80240ADC 27BD0018 */   addiu    $sp, $sp, 0x18
