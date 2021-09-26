.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021A7D4_6A19D4
/* 6A19D4 8021A7D4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 6A19D8 8021A7D8 AFBF0010 */  sw        $ra, 0x10($sp)
/* 6A19DC 8021A7DC 0C09A75B */  jal       get_actor
/* 6A19E0 8021A7E0 8C840148 */   lw       $a0, 0x148($a0)
/* 6A19E4 8021A7E4 84440436 */  lh        $a0, 0x436($v0)
/* 6A19E8 8021A7E8 A0400224 */  sb        $zero, 0x224($v0)
/* 6A19EC 8021A7EC 0C011EE1 */  jal       remove_status_icon_chillout
/* 6A19F0 8021A7F0 A0400223 */   sb       $zero, 0x223($v0)
/* 6A19F4 8021A7F4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 6A19F8 8021A7F8 24020002 */  addiu     $v0, $zero, 2
/* 6A19FC 8021A7FC 03E00008 */  jr        $ra
/* 6A1A00 8021A800 27BD0018 */   addiu    $sp, $sp, 0x18
