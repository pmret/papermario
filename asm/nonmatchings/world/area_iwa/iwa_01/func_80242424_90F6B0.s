.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242424_911AD4
/* 911AD4 80242424 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 911AD8 80242428 AFB10014 */  sw        $s1, 0x14($sp)
/* 911ADC 8024242C 0080882D */  daddu     $s1, $a0, $zero
/* 911AE0 80242430 AFBF001C */  sw        $ra, 0x1c($sp)
/* 911AE4 80242434 AFB20018 */  sw        $s2, 0x18($sp)
/* 911AE8 80242438 AFB00010 */  sw        $s0, 0x10($sp)
/* 911AEC 8024243C 8E320148 */  lw        $s2, 0x148($s1)
/* 911AF0 80242440 0C00EABB */  jal       get_npc_unsafe
/* 911AF4 80242444 86440008 */   lh       $a0, 8($s2)
/* 911AF8 80242448 0040802D */  daddu     $s0, $v0, $zero
/* 911AFC 8024244C 0C00EAFF */  jal       disable_npc_shadow
/* 911B00 80242450 0200202D */   daddu    $a0, $s0, $zero
/* 911B04 80242454 24020016 */  addiu     $v0, $zero, 0x16
/* 911B08 80242458 A60200A8 */  sh        $v0, 0xa8($s0)
/* 911B0C 8024245C 24020018 */  addiu     $v0, $zero, 0x18
/* 911B10 80242460 A60200A6 */  sh        $v0, 0xa6($s0)
/* 911B14 80242464 AE200074 */  sw        $zero, 0x74($s1)
/* 911B18 80242468 A600008E */  sh        $zero, 0x8e($s0)
/* 911B1C 8024246C 8E4200CC */  lw        $v0, 0xcc($s2)
/* 911B20 80242470 8C420020 */  lw        $v0, 0x20($v0)
/* 911B24 80242474 AE020028 */  sw        $v0, 0x28($s0)
/* 911B28 80242478 24020001 */  addiu     $v0, $zero, 1
/* 911B2C 8024247C AE220070 */  sw        $v0, 0x70($s1)
/* 911B30 80242480 8FBF001C */  lw        $ra, 0x1c($sp)
/* 911B34 80242484 8FB20018 */  lw        $s2, 0x18($sp)
/* 911B38 80242488 8FB10014 */  lw        $s1, 0x14($sp)
/* 911B3C 8024248C 8FB00010 */  lw        $s0, 0x10($sp)
/* 911B40 80242490 03E00008 */  jr        $ra
/* 911B44 80242494 27BD0020 */   addiu    $sp, $sp, 0x20
