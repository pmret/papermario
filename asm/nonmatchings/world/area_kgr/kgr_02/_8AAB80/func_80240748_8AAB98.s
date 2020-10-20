.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240748_8AAB98
/* 8AAB98 80240748 3C028011 */  lui       $v0, 0x8011
/* 8AAB9C 8024074C 8042EBB3 */  lb        $v0, -0x144d($v0)
/* 8AABA0 80240750 38420006 */  xori      $v0, $v0, 6
/* 8AABA4 80240754 0002102B */  sltu      $v0, $zero, $v0
/* 8AABA8 80240758 03E00008 */  jr        $ra
/* 8AABAC 8024075C 00021040 */   sll      $v0, $v0, 1
