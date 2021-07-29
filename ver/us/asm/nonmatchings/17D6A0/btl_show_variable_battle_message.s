.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel btl_show_variable_battle_message
/* 17E2E4 8024FA04 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 17E2E8 8024FA08 AFB00010 */  sw        $s0, 0x10($sp)
/* 17E2EC 8024FA0C 0080802D */  daddu     $s0, $a0, $zero
/* 17E2F0 8024FA10 AFB10014 */  sw        $s1, 0x14($sp)
/* 17E2F4 8024FA14 00A0882D */  daddu     $s1, $a1, $zero
/* 17E2F8 8024FA18 AFB20018 */  sw        $s2, 0x18($sp)
/* 17E2FC 8024FA1C AFBF001C */  sw        $ra, 0x1c($sp)
/* 17E300 8024FA20 0C093BDA */  jal       btl_create_popup
/* 17E304 8024FA24 00C0902D */   daddu    $s2, $a2, $zero
/* 17E308 8024FA28 0040182D */  daddu     $v1, $v0, $zero
/* 17E30C 8024FA2C 1060001B */  beqz      $v1, .L8024FA9C
/* 17E310 8024FA30 00000000 */   nop
/* 17E314 8024FA34 3C028025 */  lui       $v0, %hi(func_8024FB3C)
/* 17E318 8024FA38 2442FB3C */  addiu     $v0, $v0, %lo(func_8024FB3C)
/* 17E31C 8024FA3C AC620004 */  sw        $v0, 4($v1)
/* 17E320 8024FA40 3C028025 */  lui       $v0, %hi(btl_show_message_popup)
/* 17E324 8024FA44 24420EA4 */  addiu     $v0, $v0, %lo(btl_show_message_popup)
/* 17E328 8024FA48 AC62000C */  sw        $v0, 0xc($v1)
/* 17E32C 8024FA4C 24020001 */  addiu     $v0, $zero, 1
/* 17E330 8024FA50 AC600000 */  sw        $zero, ($v1)
/* 17E334 8024FA54 AC600008 */  sw        $zero, 8($v1)
/* 17E338 8024FA58 A4700012 */  sh        $s0, 0x12($v1)
/* 17E33C 8024FA5C A4710014 */  sh        $s1, 0x14($v1)
/* 17E340 8024FA60 A0600016 */  sb        $zero, 0x16($v1)
/* 17E344 8024FA64 A0620017 */  sb        $v0, 0x17($v1)
/* 17E348 8024FA68 AC600018 */  sw        $zero, 0x18($v1)
/* 17E34C 8024FA6C 3C01802A */  lui       $at, %hi(D_8029F640)
/* 17E350 8024FA70 A432F640 */  sh        $s2, %lo(D_8029F640)($at)
/* 17E354 8024FA74 3C018028 */  lui       $at, %hi(D_802838F8)
/* 17E358 8024FA78 AC2338F8 */  sw        $v1, %lo(D_802838F8)($at)
/* 17E35C 8024FA7C 3C01802A */  lui       $at, %hi(D_8029F64A)
/* 17E360 8024FA80 A420F64A */  sh        $zero, %lo(D_8029F64A)($at)
/* 17E364 8024FA84 3C01802A */  lui       $at, %hi(D_8029F64C)
/* 17E368 8024FA88 A420F64C */  sh        $zero, %lo(D_8029F64C)($at)
/* 17E36C 8024FA8C 3C01802A */  lui       $at, %hi(D_8029F64E)
/* 17E370 8024FA90 A420F64E */  sh        $zero, %lo(D_8029F64E)($at)
/* 17E374 8024FA94 3C01802A */  lui       $at, %hi(D_8029F650)
/* 17E378 8024FA98 A420F650 */  sh        $zero, %lo(D_8029F650)($at)
.L8024FA9C:
/* 17E37C 8024FA9C 8FBF001C */  lw        $ra, 0x1c($sp)
/* 17E380 8024FAA0 8FB20018 */  lw        $s2, 0x18($sp)
/* 17E384 8024FAA4 8FB10014 */  lw        $s1, 0x14($sp)
/* 17E388 8024FAA8 8FB00010 */  lw        $s0, 0x10($sp)
/* 17E38C 8024FAAC 03E00008 */  jr        $ra
/* 17E390 8024FAB0 27BD0020 */   addiu    $sp, $sp, 0x20
