.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241874_96AA34
/* 96AA34 80241874 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 96AA38 80241878 AFB00010 */  sw        $s0, 0x10($sp)
/* 96AA3C 8024187C 0080802D */  daddu     $s0, $a0, $zero
/* 96AA40 80241880 3C05F4AC */  lui       $a1, 0xf4ac
/* 96AA44 80241884 AFBF0014 */  sw        $ra, 0x14($sp)
/* 96AA48 80241888 0C0B1EAF */  jal       get_variable
/* 96AA4C 8024188C 34A5D480 */   ori      $a1, $a1, 0xd480
/* 96AA50 80241890 0C04EA15 */  jal       func_8013A854
/* 96AA54 80241894 0040202D */   daddu    $a0, $v0, $zero
/* 96AA58 80241898 0200202D */  daddu     $a0, $s0, $zero
/* 96AA5C 8024189C 3C05F4AC */  lui       $a1, 0xf4ac
/* 96AA60 802418A0 0C0B1EAF */  jal       get_variable
/* 96AA64 802418A4 34A5D481 */   ori      $a1, $a1, 0xd481
/* 96AA68 802418A8 0C04EA15 */  jal       func_8013A854
/* 96AA6C 802418AC 0040202D */   daddu    $a0, $v0, $zero
/* 96AA70 802418B0 0200202D */  daddu     $a0, $s0, $zero
/* 96AA74 802418B4 3C05F4AC */  lui       $a1, 0xf4ac
/* 96AA78 802418B8 0C0B1EAF */  jal       get_variable
/* 96AA7C 802418BC 34A5D482 */   ori      $a1, $a1, 0xd482
/* 96AA80 802418C0 0C04EA15 */  jal       func_8013A854
/* 96AA84 802418C4 0040202D */   daddu    $a0, $v0, $zero
/* 96AA88 802418C8 0200202D */  daddu     $a0, $s0, $zero
/* 96AA8C 802418CC 3C05F4AC */  lui       $a1, 0xf4ac
/* 96AA90 802418D0 0C0B1EAF */  jal       get_variable
/* 96AA94 802418D4 34A5D483 */   ori      $a1, $a1, 0xd483
/* 96AA98 802418D8 0C04EA15 */  jal       func_8013A854
/* 96AA9C 802418DC 0040202D */   daddu    $a0, $v0, $zero
/* 96AAA0 802418E0 0200202D */  daddu     $a0, $s0, $zero
/* 96AAA4 802418E4 3C05F4AC */  lui       $a1, 0xf4ac
/* 96AAA8 802418E8 0C0B1EAF */  jal       get_variable
/* 96AAAC 802418EC 34A5D487 */   ori      $a1, $a1, 0xd487
/* 96AAB0 802418F0 0C048D70 */  jal       free_dynamic_entity
/* 96AAB4 802418F4 0040202D */   daddu    $a0, $v0, $zero
/* 96AAB8 802418F8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 96AABC 802418FC 8FB00010 */  lw        $s0, 0x10($sp)
/* 96AAC0 80241900 24020002 */  addiu     $v0, $zero, 2
/* 96AAC4 80241904 03E00008 */  jr        $ra
/* 96AAC8 80241908 27BD0018 */   addiu    $sp, $sp, 0x18
