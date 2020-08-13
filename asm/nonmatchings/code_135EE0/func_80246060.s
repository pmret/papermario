.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80246060
/* 1393A0 80246060 AFA20014 */  sw    $v0, 0x14($sp)
/* 1393A4 80246064 24040004 */  addiu $a0, $zero, 4
/* 1393A8 80246068 3C058027 */  lui   $a1, 0x8027
/* 1393AC 8024606C 24A5FB30 */  addiu $a1, $a1, -0x4d0
/* 1393B0 80246070 24020011 */  addiu $v0, $zero, 0x11
/* 1393B4 80246074 241100FF */  addiu $s1, $zero, 0xff
/* 1393B8 80246078 AFA20018 */  sw    $v0, 0x18($sp)
/* 1393BC 8024607C 24020140 */  addiu $v0, $zero, 0x140
/* 1393C0 80246080 AFA20044 */  sw    $v0, 0x44($sp)
/* 1393C4 80246084 240200F0 */  addiu $v0, $zero, 0xf0
/* 1393C8 80246088 AFB1001C */  sw    $s1, 0x1c($sp)
/* 1393CC 8024608C AFA00020 */  sw    $zero, 0x20($sp)
/* 1393D0 80246090 AFA00024 */  sw    $zero, 0x24($sp)
/* 1393D4 80246094 AFA00028 */  sw    $zero, 0x28($sp)
/* 1393D8 80246098 AFA0002C */  sw    $zero, 0x2c($sp)
/* 1393DC 8024609C AFA00030 */  sw    $zero, 0x30($sp)
/* 1393E0 802460A0 AFA00034 */  sw    $zero, 0x34($sp)
/* 1393E4 802460A4 AFA00038 */  sw    $zero, 0x38($sp)
/* 1393E8 802460A8 AFA0003C */  sw    $zero, 0x3c($sp)
/* 1393EC 802460AC AFA00040 */  sw    $zero, 0x40($sp)
/* 1393F0 802460B0 AFA20048 */  sw    $v0, 0x48($sp)
/* 1393F4 802460B4 0C03D4B8 */  jal   draw_box
/* 1393F8 802460B8 AFA0004C */   sw    $zero, 0x4c($sp)
/* 1393FC 802460BC 3C168027 */  lui   $s6, 0x8027
/* 139400 802460C0 26D60150 */  addiu $s6, $s6, 0x150
/* 139404 802460C4 27C60015 */  addiu $a2, $fp, 0x15
/* 139408 802460C8 8FA80084 */  lw    $t0, 0x84($sp)
/* 13940C 802460CC 8EC40000 */  lw    $a0, ($s6)
/* 139410 802460D0 0C051261 */  jal   set_icon_render_pos
/* 139414 802460D4 2505003D */   addiu $a1, $t0, 0x3d
/* 139418 802460D8 8EC40000 */  lw    $a0, ($s6)
/* 13941C 802460DC 0C0511F8 */  jal   func_801447E0
/* 139420 802460E0 27D0000E */   addiu $s0, $fp, 0xe
/* 139424 802460E4 0C093BA0 */  jal   func_8024EE80
/* 139428 802460E8 24040043 */   addiu $a0, $zero, 0x43
/* 13942C 802460EC 0040202D */  daddu $a0, $v0, $zero
/* 139430 802460F0 0200302D */  daddu $a2, $s0, $zero
/* 139434 802460F4 0220382D */  daddu $a3, $s1, $zero
/* 139438 802460F8 8FA80084 */  lw    $t0, 0x84($sp)
/* 13943C 802460FC 24170001 */  addiu $s7, $zero, 1
/* 139440 80246100 AFA00010 */  sw    $zero, 0x10($sp)
/* 139444 80246104 AFB70014 */  sw    $s7, 0x14($sp)
/* 139448 80246108 0C04993B */  jal   draw_string
/* 13944C 8024610C 25050010 */   addiu $a1, $t0, 0x10
/* 139450 80246110 0C093BA0 */  jal   func_8024EE80
/* 139454 80246114 24040044 */   addiu $a0, $zero, 0x44
/* 139458 80246118 0040202D */  daddu $a0, $v0, $zero
/* 13945C 8024611C 0200302D */  daddu $a2, $s0, $zero
/* 139460 80246120 8FA80084 */  lw    $t0, 0x84($sp)
/* 139464 80246124 0220382D */  daddu $a3, $s1, $zero
/* 139468 80246128 AFA00010 */  sw    $zero, 0x10($sp)
/* 13946C 8024612C AFB70014 */  sw    $s7, 0x14($sp)
/* 139470 80246130 0C04993B */  jal   draw_string
/* 139474 80246134 25050043 */   addiu $a1, $t0, 0x43
/* 139478 80246138 00142400 */  sll   $a0, $s4, 0x10
/* 13947C 8024613C 00042403 */  sra   $a0, $a0, 0x10
/* 139480 80246140 0200302D */  daddu $a2, $s0, $zero
/* 139484 80246144 02E0382D */  daddu $a3, $s7, $zero
/* 139488 80246148 8FA80084 */  lw    $t0, 0x84($sp)
/* 13948C 8024614C 24020002 */  addiu $v0, $zero, 2
/* 139490 80246150 AFA00010 */  sw    $zero, 0x10($sp)
/* 139494 80246154 AFB10014 */  sw    $s1, 0x14($sp)
/* 139498 80246158 AFA20018 */  sw    $v0, 0x18($sp)
/* 13949C 8024615C 0C049DA7 */  jal   draw_number
/* 1394A0 80246160 2505006A */   addiu $a1, $t0, 0x6a
/* 1394A4 80246164 02571021 */  addu  $v0, $s2, $s7
