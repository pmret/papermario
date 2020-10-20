.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802401E0_91BAC0
/* 91BAC0 802401E0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 91BAC4 802401E4 AFB10014 */  sw        $s1, 0x14($sp)
/* 91BAC8 802401E8 0080882D */  daddu     $s1, $a0, $zero
/* 91BACC 802401EC AFBF001C */  sw        $ra, 0x1c($sp)
/* 91BAD0 802401F0 AFB20018 */  sw        $s2, 0x18($sp)
/* 91BAD4 802401F4 AFB00010 */  sw        $s0, 0x10($sp)
/* 91BAD8 802401F8 8E320148 */  lw        $s2, 0x148($s1)
/* 91BADC 802401FC 0C00EABB */  jal       get_npc_unsafe
/* 91BAE0 80240200 86440008 */   lh       $a0, 8($s2)
/* 91BAE4 80240204 0040802D */  daddu     $s0, $v0, $zero
/* 91BAE8 80240208 0C00EAFF */  jal       disable_npc_shadow
/* 91BAEC 8024020C 0200202D */   daddu    $a0, $s0, $zero
/* 91BAF0 80240210 24020016 */  addiu     $v0, $zero, 0x16
/* 91BAF4 80240214 A60200A8 */  sh        $v0, 0xa8($s0)
/* 91BAF8 80240218 24020018 */  addiu     $v0, $zero, 0x18
/* 91BAFC 8024021C A60200A6 */  sh        $v0, 0xa6($s0)
/* 91BB00 80240220 AE200074 */  sw        $zero, 0x74($s1)
/* 91BB04 80240224 A600008E */  sh        $zero, 0x8e($s0)
/* 91BB08 80240228 8E4200CC */  lw        $v0, 0xcc($s2)
/* 91BB0C 8024022C 8C420020 */  lw        $v0, 0x20($v0)
/* 91BB10 80240230 AE020028 */  sw        $v0, 0x28($s0)
/* 91BB14 80240234 24020001 */  addiu     $v0, $zero, 1
/* 91BB18 80240238 AE220070 */  sw        $v0, 0x70($s1)
/* 91BB1C 8024023C 8FBF001C */  lw        $ra, 0x1c($sp)
/* 91BB20 80240240 8FB20018 */  lw        $s2, 0x18($sp)
/* 91BB24 80240244 8FB10014 */  lw        $s1, 0x14($sp)
/* 91BB28 80240248 8FB00010 */  lw        $s0, 0x10($sp)
/* 91BB2C 8024024C 03E00008 */  jr        $ra
/* 91BB30 80240250 27BD0020 */   addiu    $sp, $sp, 0x20
