.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E89B0
/* 10A230 802E89B0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 10A234 802E89B4 AFB10014 */  sw        $s1, 0x14($sp)
/* 10A238 802E89B8 0080882D */  daddu     $s1, $a0, $zero
/* 10A23C 802E89BC AFBF0018 */  sw        $ra, 0x18($sp)
/* 10A240 802E89C0 AFB00010 */  sw        $s0, 0x10($sp)
/* 10A244 802E89C4 8E300040 */  lw        $s0, 0x40($s1)
/* 10A248 802E89C8 0C05152F */  jal       get_global_flag
/* 10A24C 802E89CC 8E040014 */   lw       $a0, 0x14($s0)
/* 10A250 802E89D0 10400004 */  beqz      $v0, .L802E89E4
/* 10A254 802E89D4 24020010 */   addiu    $v0, $zero, 0x10
/* 10A258 802E89D8 AE020004 */  sw        $v0, 4($s0)
/* 10A25C 802E89DC 0C043F5A */  jal       func_8010FD68
/* 10A260 802E89E0 0220202D */   daddu    $a0, $s1, $zero
.L802E89E4:
/* 10A264 802E89E4 8FBF0018 */  lw        $ra, 0x18($sp)
/* 10A268 802E89E8 8FB10014 */  lw        $s1, 0x14($sp)
/* 10A26C 802E89EC 8FB00010 */  lw        $s0, 0x10($sp)
/* 10A270 802E89F0 03E00008 */  jr        $ra
/* 10A274 802E89F4 27BD0020 */   addiu    $sp, $sp, 0x20
