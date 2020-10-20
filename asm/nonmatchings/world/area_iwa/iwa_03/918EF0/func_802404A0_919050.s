.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802404A0_919050
/* 919050 802404A0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 919054 802404A4 AFB10014 */  sw        $s1, 0x14($sp)
/* 919058 802404A8 0080882D */  daddu     $s1, $a0, $zero
/* 91905C 802404AC AFBF001C */  sw        $ra, 0x1c($sp)
/* 919060 802404B0 AFB20018 */  sw        $s2, 0x18($sp)
/* 919064 802404B4 AFB00010 */  sw        $s0, 0x10($sp)
/* 919068 802404B8 8E320148 */  lw        $s2, 0x148($s1)
/* 91906C 802404BC 0C00EABB */  jal       get_npc_unsafe
/* 919070 802404C0 86440008 */   lh       $a0, 8($s2)
/* 919074 802404C4 0040802D */  daddu     $s0, $v0, $zero
/* 919078 802404C8 0C00EAFF */  jal       disable_npc_shadow
/* 91907C 802404CC 0200202D */   daddu    $a0, $s0, $zero
/* 919080 802404D0 24020016 */  addiu     $v0, $zero, 0x16
/* 919084 802404D4 A60200A8 */  sh        $v0, 0xa8($s0)
/* 919088 802404D8 24020018 */  addiu     $v0, $zero, 0x18
/* 91908C 802404DC A60200A6 */  sh        $v0, 0xa6($s0)
/* 919090 802404E0 AE200074 */  sw        $zero, 0x74($s1)
/* 919094 802404E4 A600008E */  sh        $zero, 0x8e($s0)
/* 919098 802404E8 8E4200CC */  lw        $v0, 0xcc($s2)
/* 91909C 802404EC 8C420020 */  lw        $v0, 0x20($v0)
/* 9190A0 802404F0 AE020028 */  sw        $v0, 0x28($s0)
/* 9190A4 802404F4 24020001 */  addiu     $v0, $zero, 1
/* 9190A8 802404F8 AE220070 */  sw        $v0, 0x70($s1)
/* 9190AC 802404FC 8FBF001C */  lw        $ra, 0x1c($sp)
/* 9190B0 80240500 8FB20018 */  lw        $s2, 0x18($sp)
/* 9190B4 80240504 8FB10014 */  lw        $s1, 0x14($sp)
/* 9190B8 80240508 8FB00010 */  lw        $s0, 0x10($sp)
/* 9190BC 8024050C 03E00008 */  jr        $ra
/* 9190C0 80240510 27BD0020 */   addiu    $sp, $sp, 0x20
