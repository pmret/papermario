.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E12F8
/* 102B78 802E12F8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 102B7C 802E12FC 3C04001D */  lui       $a0, 0x1d
/* 102B80 802E1300 3C05802F */  lui       $a1, 0x802f
/* 102B84 802E1304 8CA5B39C */  lw        $a1, -0x4c64($a1)
/* 102B88 802E1308 AFBF0010 */  sw        $ra, 0x10($sp)
/* 102B8C 802E130C 0C04969A */  jal       load_message_to_printer
/* 102B90 802E1310 34840005 */   ori      $a0, $a0, 5
/* 102B94 802E1314 0C05272D */  jal       play_sound
/* 102B98 802E1318 24040010 */   addiu    $a0, $zero, 0x10
/* 102B9C 802E131C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 102BA0 802E1320 03E00008 */  jr        $ra
/* 102BA4 802E1324 27BD0018 */   addiu    $sp, $sp, 0x18
