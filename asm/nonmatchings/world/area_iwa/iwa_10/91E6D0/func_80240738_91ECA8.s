.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240738_91ECA8
/* 91ECA8 80240738 3C028011 */  lui       $v0, 0x8011
/* 91ECAC 8024073C 8042F2A2 */  lb        $v0, -0xd5e($v0)
/* 91ECB0 80240740 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 91ECB4 80240744 AFBF0010 */  sw        $ra, 0x10($sp)
/* 91ECB8 80240748 00021100 */  sll       $v0, $v0, 4
/* 91ECBC 8024074C 3C048009 */  lui       $a0, 0x8009
/* 91ECC0 80240750 00822021 */  addu      $a0, $a0, $v0
/* 91ECC4 80240754 8C84EF20 */  lw        $a0, -0x10e0($a0)
/* 91ECC8 80240758 0C0496CF */  jal       set_message_string
/* 91ECCC 8024075C 0000282D */   daddu    $a1, $zero, $zero
/* 91ECD0 80240760 8FBF0010 */  lw        $ra, 0x10($sp)
/* 91ECD4 80240764 24020002 */  addiu     $v0, $zero, 2
/* 91ECD8 80240768 03E00008 */  jr        $ra
/* 91ECDC 8024076C 27BD0018 */   addiu    $sp, $sp, 0x18
