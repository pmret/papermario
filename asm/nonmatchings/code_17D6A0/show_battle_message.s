.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel show_battle_message
/* 17E240 8024F960 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 17E244 8024F964 AFB00010 */  sw        $s0, 0x10($sp)
/* 17E248 8024F968 0080802D */  daddu     $s0, $a0, $zero
/* 17E24C 8024F96C AFB10014 */  sw        $s1, 0x14($sp)
/* 17E250 8024F970 AFBF0018 */  sw        $ra, 0x18($sp)
/* 17E254 8024F974 0C093BDA */  jal       create_popup
/* 17E258 8024F978 00A0882D */   daddu    $s1, $a1, $zero
/* 17E25C 8024F97C 0040182D */  daddu     $v1, $v0, $zero
/* 17E260 8024F980 1060001B */  beqz      $v1, .L8024F9F0
/* 17E264 8024F984 00000000 */   nop      
/* 17E268 8024F988 3C028025 */  lui       $v0, %hi(D_8024FB3C)
/* 17E26C 8024F98C 2442FB3C */  addiu     $v0, $v0, %lo(D_8024FB3C)
/* 17E270 8024F990 AC620004 */  sw        $v0, 4($v1)
/* 17E274 8024F994 3C028025 */  lui       $v0, %hi(show_message_popup)
/* 17E278 8024F998 24420EA4 */  addiu     $v0, $v0, %lo(show_message_popup)
/* 17E27C 8024F99C AC62000C */  sw        $v0, 0xc($v1)
/* 17E280 8024F9A0 24020001 */  addiu     $v0, $zero, 1
/* 17E284 8024F9A4 AC600000 */  sw        $zero, ($v1)
/* 17E288 8024F9A8 AC600008 */  sw        $zero, 8($v1)
/* 17E28C 8024F9AC A4700012 */  sh        $s0, 0x12($v1)
/* 17E290 8024F9B0 A4710014 */  sh        $s1, 0x14($v1)
/* 17E294 8024F9B4 A0600016 */  sb        $zero, 0x16($v1)
/* 17E298 8024F9B8 A0620017 */  sb        $v0, 0x17($v1)
/* 17E29C 8024F9BC AC600018 */  sw        $zero, 0x18($v1)
/* 17E2A0 8024F9C0 3C01802A */  lui       $at, %hi(D_8029F640)
/* 17E2A4 8024F9C4 A420F640 */  sh        $zero, %lo(D_8029F640)($at)
/* 17E2A8 8024F9C8 3C018028 */  lui       $at, %hi(D_802838F8)
/* 17E2AC 8024F9CC AC2338F8 */  sw        $v1, %lo(D_802838F8)($at)
/* 17E2B0 8024F9D0 3C01802A */  lui       $at, %hi(D_8029F64A)
/* 17E2B4 8024F9D4 A420F64A */  sh        $zero, %lo(D_8029F64A)($at)
/* 17E2B8 8024F9D8 3C01802A */  lui       $at, %hi(D_8029F64C)
/* 17E2BC 8024F9DC A420F64C */  sh        $zero, %lo(D_8029F64C)($at)
/* 17E2C0 8024F9E0 3C01802A */  lui       $at, %hi(D_8029F64E)
/* 17E2C4 8024F9E4 A420F64E */  sh        $zero, %lo(D_8029F64E)($at)
/* 17E2C8 8024F9E8 3C01802A */  lui       $at, %hi(D_8029F650)
/* 17E2CC 8024F9EC A420F650 */  sh        $zero, %lo(D_8029F650)($at)
.L8024F9F0:
/* 17E2D0 8024F9F0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 17E2D4 8024F9F4 8FB10014 */  lw        $s1, 0x14($sp)
/* 17E2D8 8024F9F8 8FB00010 */  lw        $s0, 0x10($sp)
/* 17E2DC 8024F9FC 03E00008 */  jr        $ra
/* 17E2E0 8024FA00 27BD0020 */   addiu    $sp, $sp, 0x20
