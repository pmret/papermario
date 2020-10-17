.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel dispatch_event_player_continue_turn
/* 19FFC4 802716E4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 19FFC8 802716E8 2405000A */  addiu     $a1, $zero, 0xa
/* 19FFCC 802716EC AFB00010 */  sw        $s0, 0x10($sp)
/* 19FFD0 802716F0 3C10800E */  lui       $s0, 0x800e
/* 19FFD4 802716F4 8E10C148 */  lw        $s0, -0x3eb8($s0)
/* 19FFD8 802716F8 AFBF001C */  sw        $ra, 0x1c($sp)
/* 19FFDC 802716FC AFB20018 */  sw        $s2, 0x18($sp)
/* 19FFE0 80271700 AFB10014 */  sw        $s1, 0x14($sp)
/* 19FFE4 80271704 A20401F0 */  sb        $a0, 0x1f0($s0)
/* 19FFE8 80271708 3C048028 */  lui       $a0, %hi(HandleEvent_Player)
/* 19FFEC 8027170C 248452D4 */  addiu     $a0, $a0, %lo(HandleEvent_Player)
/* 19FFF0 80271710 8E1101D8 */  lw        $s1, 0x1d8($s0)
/* 19FFF4 80271714 8E1201E8 */  lw        $s2, 0x1e8($s0)
/* 19FFF8 80271718 0C0B0CF8 */  jal       start_script
/* 19FFFC 8027171C 24060020 */   addiu    $a2, $zero, 0x20
/* 1A0000 80271720 AE0201D8 */  sw        $v0, 0x1d8($s0)
/* 1A0004 80271724 8C430144 */  lw        $v1, 0x144($v0)
/* 1A0008 80271728 AE0301E8 */  sw        $v1, 0x1e8($s0)
/* 1A000C 8027172C 12200003 */  beqz      $s1, .L8027173C
/* 1A0010 80271730 AC400148 */   sw       $zero, 0x148($v0)
/* 1A0014 80271734 0C0B102B */  jal       kill_script_by_ID
/* 1A0018 80271738 0240202D */   daddu    $a0, $s2, $zero
.L8027173C:
/* 1A001C 8027173C 8FBF001C */  lw        $ra, 0x1c($sp)
/* 1A0020 80271740 8FB20018 */  lw        $s2, 0x18($sp)
/* 1A0024 80271744 8FB10014 */  lw        $s1, 0x14($sp)
/* 1A0028 80271748 8FB00010 */  lw        $s0, 0x10($sp)
/* 1A002C 8027174C 03E00008 */  jr        $ra
/* 1A0030 80271750 27BD0020 */   addiu    $sp, $sp, 0x20
