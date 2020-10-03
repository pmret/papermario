.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel dispatch_event_partner
/* 1AC760 8027DE80 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 1AC764 8027DE84 2405000A */  addiu     $a1, $zero, 0xa
/* 1AC768 8027DE88 AFB00010 */  sw        $s0, 0x10($sp)
/* 1AC76C 8027DE8C 3C10800E */  lui       $s0, 0x800e
/* 1AC770 8027DE90 8E10C14C */  lw        $s0, -0x3eb4($s0)
/* 1AC774 8027DE94 AFBF001C */  sw        $ra, 0x1c($sp)
/* 1AC778 8027DE98 AFB20018 */  sw        $s2, 0x18($sp)
/* 1AC77C 8027DE9C AFB10014 */  sw        $s1, 0x14($sp)
/* 1AC780 8027DEA0 A20401F0 */  sb        $a0, 0x1f0($s0)
/* 1AC784 8027DEA4 8E0401C8 */  lw        $a0, 0x1c8($s0)
/* 1AC788 8027DEA8 8E1101D8 */  lw        $s1, 0x1d8($s0)
/* 1AC78C 8027DEAC 8E1201E8 */  lw        $s2, 0x1e8($s0)
/* 1AC790 8027DEB0 0C0B0CF8 */  jal       start_script
/* 1AC794 8027DEB4 24060020 */   addiu    $a2, $zero, 0x20
/* 1AC798 8027DEB8 AE0201D8 */  sw        $v0, 0x1d8($s0)
/* 1AC79C 8027DEBC 8C430144 */  lw        $v1, 0x144($v0)
/* 1AC7A0 8027DEC0 AE0301E8 */  sw        $v1, 0x1e8($s0)
/* 1AC7A4 8027DEC4 24030100 */  addiu     $v1, $zero, 0x100
/* 1AC7A8 8027DEC8 AC430148 */  sw        $v1, 0x148($v0)
/* 1AC7AC 8027DECC 8E0201D4 */  lw        $v0, 0x1d4($s0)
/* 1AC7B0 8027DED0 10400004 */  beqz      $v0, .L8027DEE4
/* 1AC7B4 8027DED4 00000000 */   nop      
/* 1AC7B8 8027DED8 0C0B102B */  jal       kill_script_by_ID
/* 1AC7BC 8027DEDC 8E0401E4 */   lw       $a0, 0x1e4($s0)
/* 1AC7C0 8027DEE0 AE0001D4 */  sw        $zero, 0x1d4($s0)
.L8027DEE4:
/* 1AC7C4 8027DEE4 12200003 */  beqz      $s1, .L8027DEF4
/* 1AC7C8 8027DEE8 00000000 */   nop      
/* 1AC7CC 8027DEEC 0C0B102B */  jal       kill_script_by_ID
/* 1AC7D0 8027DEF0 0240202D */   daddu    $a0, $s2, $zero
.L8027DEF4:
/* 1AC7D4 8027DEF4 8FBF001C */  lw        $ra, 0x1c($sp)
/* 1AC7D8 8027DEF8 8FB20018 */  lw        $s2, 0x18($sp)
/* 1AC7DC 8027DEFC 8FB10014 */  lw        $s1, 0x14($sp)
/* 1AC7E0 8027DF00 8FB00010 */  lw        $s0, 0x10($sp)
/* 1AC7E4 8027DF04 03E00008 */  jr        $ra
/* 1AC7E8 8027DF08 27BD0020 */   addiu    $sp, $sp, 0x20
