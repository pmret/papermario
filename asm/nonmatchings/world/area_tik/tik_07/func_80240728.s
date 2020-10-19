.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240728
/* 87A308 80240728 3C028011 */  lui       $v0, 0x8011
/* 87A30C 8024072C 8042F2A2 */  lb        $v0, -0xd5e($v0)
/* 87A310 80240730 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 87A314 80240734 AFBF0010 */  sw        $ra, 0x10($sp)
/* 87A318 80240738 00021100 */  sll       $v0, $v0, 4
/* 87A31C 8024073C 3C048009 */  lui       $a0, 0x8009
/* 87A320 80240740 00822021 */  addu      $a0, $a0, $v0
/* 87A324 80240744 8C84EF20 */  lw        $a0, -0x10e0($a0)
/* 87A328 80240748 0C0496CF */  jal       set_message_string
/* 87A32C 8024074C 0000282D */   daddu    $a1, $zero, $zero
/* 87A330 80240750 8FBF0010 */  lw        $ra, 0x10($sp)
/* 87A334 80240754 24020002 */  addiu     $v0, $zero, 2
/* 87A338 80240758 03E00008 */  jr        $ra
/* 87A33C 8024075C 27BD0018 */   addiu    $sp, $sp, 0x18
