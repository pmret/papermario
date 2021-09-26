.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel remove_all_status_icons
/* 22AF4 800476F4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 22AF8 800476F8 AFB00010 */  sw        $s0, 0x10($sp)
/* 22AFC 800476FC 0080802D */  daddu     $s0, $a0, $zero
/* 22B00 80047700 00101040 */  sll       $v0, $s0, 1
/* 22B04 80047704 00501021 */  addu      $v0, $v0, $s0
/* 22B08 80047708 00021080 */  sll       $v0, $v0, 2
/* 22B0C 8004770C 00501023 */  subu      $v0, $v0, $s0
/* 22B10 80047710 AFB10014 */  sw        $s1, 0x14($sp)
/* 22B14 80047714 3C11800A */  lui       $s1, %hi(D_800A0F44)
/* 22B18 80047718 8E310F44 */  lw        $s1, %lo(D_800A0F44)($s1)
/* 22B1C 8004771C 00021100 */  sll       $v0, $v0, 4
/* 22B20 80047720 AFBF0018 */  sw        $ra, 0x18($sp)
/* 22B24 80047724 0C011E26 */  jal       remove_status_icon_debuff
/* 22B28 80047728 02228821 */   addu     $s1, $s1, $v0
/* 22B2C 8004772C 0C011E68 */  jal       remove_status_icon_static
/* 22B30 80047730 0200202D */   daddu    $a0, $s0, $zero
/* 22B34 80047734 0C011EAA */  jal       remove_status_icon_transparent
/* 22B38 80047738 0200202D */   daddu    $a0, $s0, $zero
/* 22B3C 8004773C 0C011EE1 */  jal       remove_status_icon_chillout
/* 22B40 80047740 0200202D */   daddu    $a0, $s0, $zero
/* 22B44 80047744 0C011F29 */  jal       remove_status_icon_boost_jump
/* 22B48 80047748 0200202D */   daddu    $a0, $s0, $zero
/* 22B4C 8004774C 0C011F70 */  jal       remove_status_icon_boost_hammer
/* 22B50 80047750 0200202D */   daddu    $a0, $s0, $zero
/* 22B54 80047754 0C011FB7 */  jal       remove_status_icon_boost_partner
/* 22B58 80047758 0200202D */   daddu    $a0, $s0, $zero
/* 22B5C 8004775C 0C011FFA */  jal       remove_status_icon_surprise
/* 22B60 80047760 0200202D */   daddu    $a0, $s0, $zero
/* 22B64 80047764 0C01203D */  jal       remove_status_icon_peril
/* 22B68 80047768 0200202D */   daddu    $a0, $s0, $zero
/* 22B6C 8004776C 0C012080 */  jal       remove_status_icon_danger
/* 22B70 80047770 0200202D */   daddu    $a0, $s0, $zero
/* 22B74 80047774 AE200000 */  sw        $zero, ($s1)
/* 22B78 80047778 8FBF0018 */  lw        $ra, 0x18($sp)
/* 22B7C 8004777C 8FB10014 */  lw        $s1, 0x14($sp)
/* 22B80 80047780 8FB00010 */  lw        $s0, 0x10($sp)
/* 22B84 80047784 03E00008 */  jr        $ra
/* 22B88 80047788 27BD0020 */   addiu    $sp, $sp, 0x20
