.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004F964
/* 2AD64 8004F964 908200D4 */  lbu       $v0, 0xd4($a0)
/* 2AD68 8004F968 3042007F */  andi      $v0, $v0, 0x7f
/* 2AD6C 8004F96C 54400001 */  bnel      $v0, $zero, .L8004F974
/* 2AD70 8004F970 00021600 */   sll      $v0, $v0, 0x18
.L8004F974:
/* 2AD74 8004F974 AC8200C0 */  sw        $v0, 0xc0($a0)
/* 2AD78 8004F978 24020001 */  addiu     $v0, $zero, 1
/* 2AD7C 8004F97C AC8000CC */  sw        $zero, 0xcc($a0)
/* 2AD80 8004F980 AC8000C8 */  sw        $zero, 0xc8($a0)
/* 2AD84 8004F984 AC8000C4 */  sw        $zero, 0xc4($a0)
/* 2AD88 8004F988 A082021A */  sb        $v0, 0x21a($a0)
/* 2AD8C 8004F98C 03E00008 */  jr        $ra
/* 2AD90 8004F990 A0A20041 */   sb       $v0, 0x41($a1)
