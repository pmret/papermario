.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8024BF9C
/* 13F2DC 8024BF9C 3C048027 */  lui   $a0, 0x8027
/* 13F2E0 8024BFA0 8C840640 */  lw    $a0, 0x640($a0)
/* 13F2E4 8024BFA4 0C0511F8 */  jal   func_801447E0
/* 13F2E8 8024BFA8 00000000 */   nop   
.L8024BFAC:
/* 13F2EC 8024BFAC 26F7000D */  addiu $s7, $s7, 0xd
/* 13F2F0 8024BFB0 2694000D */  addiu $s4, $s4, 0xd
/* 13F2F4 8024BFB4 26D6000D */  addiu $s6, $s6, 0xd
/* 13F2F8 8024BFB8 26520001 */  addiu $s2, $s2, 1
/* 13F2FC 8024BFBC 2A420004 */  slti  $v0, $s2, 4
/* 13F300 8024BFC0 1440FF8B */  bnez  $v0, .L8024BDF0
/* 13F304 8024BFC4 26730001 */   addiu $s3, $s3, 1
/* 13F308 8024BFC8 3C038027 */  lui   $v1, 0x8027
/* 13F30C 8024BFCC 806300D4 */  lb    $v1, 0xd4($v1)
/* 13F310 8024BFD0 24020004 */  addiu $v0, $zero, 4
/* 13F314 8024BFD4 14620010 */  bne   $v1, $v0, .L8024C018
/* 13F318 8024BFD8 24020001 */   addiu $v0, $zero, 1
/* 13F31C 8024BFDC 3C038027 */  lui   $v1, 0x8027
/* 13F320 8024BFE0 8C6306AC */  lw    $v1, 0x6ac($v1)
/* 13F324 8024BFE4 1462000C */  bne   $v1, $v0, .L8024C018
/* 13F328 8024BFE8 24040024 */   addiu $a0, $zero, 0x24
/* 13F32C 8024BFEC 8FA80054 */  lw    $t0, 0x54($sp)
/* 13F330 8024BFF0 3C028027 */  lui   $v0, 0x8027
/* 13F334 8024BFF4 8C4206A4 */  lw    $v0, 0x6a4($v0)
/* 13F338 8024BFF8 2505FFFE */  addiu $a1, $t0, -2
/* 13F33C 8024BFFC 00023040 */  sll   $a2, $v0, 1
/* 13F340 8024C000 00C23021 */  addu  $a2, $a2, $v0
/* 13F344 8024C004 00063080 */  sll   $a2, $a2, 2
/* 13F348 8024C008 00C23021 */  addu  $a2, $a2, $v0
/* 13F34C 8024C00C 24C6001C */  addiu $a2, $a2, 0x1c
/* 13F350 8024C010 0C090B41 */  jal   func_80242D04
/* 13F354 8024C014 03C63021 */   addu  $a2, $fp, $a2
.L8024C018:
/* 13F358 8024C018 8FBF004C */  lw    $ra, 0x4c($sp)
/* 13F35C 8024C01C 8FBE0048 */  lw    $fp, 0x48($sp)
/* 13F360 8024C020 8FB70044 */  lw    $s7, 0x44($sp)
/* 13F364 8024C024 8FB60040 */  lw    $s6, 0x40($sp)
/* 13F368 8024C028 8FB5003C */  lw    $s5, 0x3c($sp)
/* 13F36C 8024C02C 8FB40038 */  lw    $s4, 0x38($sp)
/* 13F370 8024C030 8FB30034 */  lw    $s3, 0x34($sp)
/* 13F374 8024C034 8FB20030 */  lw    $s2, 0x30($sp)
/* 13F378 8024C038 8FB1002C */  lw    $s1, 0x2c($sp)
/* 13F37C 8024C03C 8FB00028 */  lw    $s0, 0x28($sp)
/* 13F380 8024C040 03E00008 */  jr    $ra
/* 13F384 8024C044 27BD0050 */   addiu $sp, $sp, 0x50

/* 13F388 8024C048 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 13F38C 8024C04C AFB00018 */  sw    $s0, 0x18($sp)
/* 13F390 8024C050 00A0802D */  daddu $s0, $a1, $zero
/* 13F394 8024C054 AFB1001C */  sw    $s1, 0x1c($sp)
/* 13F398 8024C058 00C0882D */  daddu $s1, $a2, $zero
/* 13F39C 8024C05C AFBF0020 */  sw    $ra, 0x20($sp)
/* 13F3A0 8024C060 0C093BA0 */  jal   func_8024EE80
/* 13F3A4 8024C064 24040055 */   addiu $a0, $zero, 0x55
/* 13F3A8 8024C068 0040202D */  daddu $a0, $v0, $zero
/* 13F3AC 8024C06C 2402FFFF */  addiu $v0, $zero, -1
/* 13F3B0 8024C070 AFA20010 */  sw    $v0, 0x10($sp)
/* 13F3B4 8024C074 24020001 */  addiu $v0, $zero, 1
/* 13F3B8 8024C078 2605000C */  addiu $a1, $s0, 0xc
/* 13F3BC 8024C07C 02223021 */  addu  $a2, $s1, $v0
/* 13F3C0 8024C080 240700FF */  addiu $a3, $zero, 0xff
/* 13F3C4 8024C084 0C04993B */  jal   draw_string
/* 13F3C8 8024C088 AFA20014 */   sw    $v0, 0x14($sp)
/* 13F3CC 8024C08C 8FBF0020 */  lw    $ra, 0x20($sp)
/* 13F3D0 8024C090 8FB1001C */  lw    $s1, 0x1c($sp)
/* 13F3D4 8024C094 8FB00018 */  lw    $s0, 0x18($sp)
/* 13F3D8 8024C098 03E00008 */  jr    $ra
/* 13F3DC 8024C09C 27BD0028 */   addiu $sp, $sp, 0x28

/* 13F3E0 8024C0A0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 13F3E4 8024C0A4 AFB00010 */  sw    $s0, 0x10($sp)
/* 13F3E8 8024C0A8 3C108027 */  lui   $s0, 0x8027
/* 13F3EC 8024C0AC 26100640 */  addiu $s0, $s0, 0x640
/* 13F3F0 8024C0B0 24A50011 */  addiu $a1, $a1, 0x11
/* 13F3F4 8024C0B4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 13F3F8 8024C0B8 8E040004 */  lw    $a0, 4($s0)
/* 13F3FC 8024C0BC 0C051261 */  jal   set_icon_render_pos
/* 13F400 8024C0C0 24C60010 */   addiu $a2, $a2, 0x10
/* 13F404 8024C0C4 8E040004 */  lw    $a0, 4($s0)
/* 13F408 8024C0C8 0C0511F8 */  jal   func_801447E0
/* 13F40C 8024C0CC 00000000 */   nop   
/* 13F410 8024C0D0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 13F414 8024C0D4 8FB00010 */  lw    $s0, 0x10($sp)
/* 13F418 8024C0D8 03E00008 */  jr    $ra
/* 13F41C 8024C0DC 27BD0018 */   addiu $sp, $sp, 0x18

/* 13F420 8024C0E0 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 13F424 8024C0E4 AFB40020 */  sw    $s4, 0x20($sp)
/* 13F428 8024C0E8 0080A02D */  daddu $s4, $a0, $zero
/* 13F42C 8024C0EC AFBF0024 */  sw    $ra, 0x24($sp)
/* 13F430 8024C0F0 AFB3001C */  sw    $s3, 0x1c($sp)
/* 13F434 8024C0F4 AFB20018 */  sw    $s2, 0x18($sp)
/* 13F438 8024C0F8 AFB10014 */  sw    $s1, 0x14($sp)
/* 13F43C 8024C0FC 0C039D59 */  jal   get_player_data
/* 13F440 8024C100 AFB00010 */   sw    $s0, 0x10($sp)
/* 13F444 8024C104 0040982D */  daddu $s3, $v0, $zero
/* 13F448 8024C108 3C028027 */  lui   $v0, 0x8027
/* 13F44C 8024C10C 244206B0 */  addiu $v0, $v0, 0x6b0
/* 13F450 8024C110 0000802D */  daddu $s0, $zero, $zero
/* 13F454 8024C114 3C068027 */  lui   $a2, 0x8027
/* 13F458 8024C118 24C60680 */  addiu $a2, $a2, 0x680
/* 13F45C 8024C11C 0040282D */  daddu $a1, $v0, $zero
/* 13F460 8024C120 3C048025 */  lui   $a0, 0x8025
/* 13F464 8024C124 2484F6B0 */  addiu $a0, $a0, -0x950
/* 13F468 8024C128 AC400000 */  sw    $zero, ($v0)
.L8024C12C:
/* 13F46C 8024C12C 8C820000 */  lw    $v0, ($a0)
/* 13F470 8024C130 000210C0 */  sll   $v0, $v0, 3
/* 13F474 8024C134 02621021 */  addu  $v0, $s3, $v0
/* 13F478 8024C138 90420014 */  lbu   $v0, 0x14($v0)
/* 13F47C 8024C13C 50400008 */  beql  $v0, $zero, .L8024C160
/* 13F480 8024C140 26100001 */   addiu $s0, $s0, 1
/* 13F484 8024C144 8CA30000 */  lw    $v1, ($a1)
/* 13F488 8024C148 00031080 */  sll   $v0, $v1, 2
/* 13F48C 8024C14C 00461021 */  addu  $v0, $v0, $a2
/* 13F490 8024C150 24630001 */  addiu $v1, $v1, 1
