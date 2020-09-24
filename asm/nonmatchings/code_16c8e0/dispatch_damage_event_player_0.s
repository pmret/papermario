.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel dispatch_damage_event_player_0
/* 1A1C5C 8027337C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1A1C60 80273380 3C02800E */  lui       $v0, 0x800e
/* 1A1C64 80273384 2442C070 */  addiu     $v0, $v0, -0x3f90
/* 1A1C68 80273388 0000302D */  daddu     $a2, $zero, $zero
/* 1A1C6C 8027338C AFBF0010 */  sw        $ra, 0x10($sp)
/* 1A1C70 80273390 AC400188 */  sw        $zero, 0x188($v0)
/* 1A1C74 80273394 0C09CC6F */  jal       dispatch_damage_event_player
/* 1A1C78 80273398 A040019A */   sb       $zero, 0x19a($v0)
/* 1A1C7C 8027339C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 1A1C80 802733A0 03E00008 */  jr        $ra
/* 1A1C84 802733A4 27BD0018 */   addiu    $sp, $sp, 0x18
