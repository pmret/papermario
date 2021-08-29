.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802194C0_6BD050
/* 6BD050 802194C0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 6BD054 802194C4 AFB00010 */  sw        $s0, 0x10($sp)
/* 6BD058 802194C8 0080802D */  daddu     $s0, $a0, $zero
/* 6BD05C 802194CC AFBF0018 */  sw        $ra, 0x18($sp)
/* 6BD060 802194D0 AFB10014 */  sw        $s1, 0x14($sp)
/* 6BD064 802194D4 8E040148 */  lw        $a0, 0x148($s0)
/* 6BD068 802194D8 0C09A75B */  jal       get_actor
/* 6BD06C 802194DC 8E11000C */   lw       $s1, 0xc($s0)
/* 6BD070 802194E0 0200202D */  daddu     $a0, $s0, $zero
/* 6BD074 802194E4 8E250000 */  lw        $a1, ($s1)
/* 6BD078 802194E8 0C0B1EAF */  jal       evt_get_variable
/* 6BD07C 802194EC 8C500090 */   lw       $s0, 0x90($v0)
/* 6BD080 802194F0 AE020010 */  sw        $v0, 0x10($s0)
/* 6BD084 802194F4 8FBF0018 */  lw        $ra, 0x18($sp)
/* 6BD088 802194F8 8FB10014 */  lw        $s1, 0x14($sp)
/* 6BD08C 802194FC 8FB00010 */  lw        $s0, 0x10($sp)
/* 6BD090 80219500 24020002 */  addiu     $v0, $zero, 2
/* 6BD094 80219504 03E00008 */  jr        $ra
/* 6BD098 80219508 27BD0020 */   addiu    $sp, $sp, 0x20
