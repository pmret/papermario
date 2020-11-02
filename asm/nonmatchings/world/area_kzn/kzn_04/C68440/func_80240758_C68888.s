.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240758_C68888
/* C68888 80240758 3C028011 */  lui       $v0, %hi(gPlayerData+0x12)
/* C6888C 8024075C 8042F2A2 */  lb        $v0, %lo(gPlayerData+0x12)($v0)
/* C68890 80240760 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C68894 80240764 AFBF0010 */  sw        $ra, 0x10($sp)
/* C68898 80240768 00021100 */  sll       $v0, $v0, 4
/* C6889C 8024076C 3C048009 */  lui       $a0, 0x8009
/* C688A0 80240770 00822021 */  addu      $a0, $a0, $v0
/* C688A4 80240774 8C84EF20 */  lw        $a0, -0x10e0($a0)
/* C688A8 80240778 0C0496CF */  jal       set_message_string
/* C688AC 8024077C 0000282D */   daddu    $a1, $zero, $zero
/* C688B0 80240780 8FBF0010 */  lw        $ra, 0x10($sp)
/* C688B4 80240784 24020002 */  addiu     $v0, $zero, 2
/* C688B8 80240788 03E00008 */  jr        $ra
/* C688BC 8024078C 27BD0018 */   addiu    $sp, $sp, 0x18
