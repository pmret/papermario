.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8024ADE0
/* 13E120 8024ADE0 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 13E124 8024ADE4 AFB20020 */  sw    $s2, 0x20($sp)
/* 13E128 8024ADE8 0080902D */  daddu $s2, $a0, $zero
/* 13E12C 8024ADEC 3C078025 */  lui   $a3, 0x8025
/* 13E130 8024ADF0 24E7F7C0 */  addiu $a3, $a3, -0x840
/* 13E134 8024ADF4 00121080 */  sll   $v0, $s2, 2
/* 13E138 8024ADF8 AFBF0024 */  sw    $ra, 0x24($sp)
/* 13E13C 8024ADFC AFB1001C */  sw    $s1, 0x1c($sp)
/* 13E140 8024AE00 AFB00018 */  sw    $s0, 0x18($sp)
/* 13E144 8024AE04 8CE30000 */  lw    $v1, ($a3)
/* 13E148 8024AE08 3C068027 */  lui   $a2, 0x8027
/* 13E14C 8024AE0C 00C23021 */  addu  $a2, $a2, $v0
/* 13E150 8024AE10 8CC60680 */  lw    $a2, 0x680($a2)
/* 13E154 8024AE14 3C118027 */  lui   $s1, 0x8027
/* 13E158 8024AE18 26310680 */  addiu $s1, $s1, 0x680
/* 13E15C 8024AE1C 1066000E */  beq   $v1, $a2, .L8024AE58
/* 13E160 8024AE20 00061080 */   sll   $v0, $a2, 2
/* 13E164 8024AE24 3C048025 */  lui   $a0, 0x8025
/* 13E168 8024AE28 00822021 */  addu  $a0, $a0, $v0
/* 13E16C 8024AE2C 8C84F718 */  lw    $a0, -0x8e8($a0)
/* 13E170 8024AE30 27A50010 */  addiu $a1, $sp, 0x10
/* 13E174 8024AE34 0C016B3A */  jal   load_asset_by_name
/* 13E178 8024AE38 ACE60000 */   sw    $a2, ($a3)
/* 13E17C 8024AE3C 0040802D */  daddu $s0, $v0, $zero
/* 13E180 8024AE40 3C058025 */  lui   $a1, 0x8025
/* 13E184 8024AE44 8CA5F744 */  lw    $a1, -0x8bc($a1)
/* 13E188 8024AE48 0C01BB7C */  jal   decode_yay0
/* 13E18C 8024AE4C 0200202D */   daddu $a0, $s0, $zero
/* 13E190 8024AE50 0C00AB1E */  jal   general_heap_free
/* 13E194 8024AE54 0200202D */   daddu $a0, $s0, $zero
.L8024AE58:
/* 13E198 8024AE58 3C038027 */  lui   $v1, 0x8027
/* 13E19C 8024AE5C 8C6306B0 */  lw    $v1, 0x6b0($v1)
/* 13E1A0 8024AE60 26420001 */  addiu $v0, $s2, 1
/* 13E1A4 8024AE64 14600002 */  bnez  $v1, .L8024AE70
/* 13E1A8 8024AE68 0043001A */   div   $zero, $v0, $v1
/* 13E1AC 8024AE6C 0007000D */  break 7
.L8024AE70:
/* 13E1B0 8024AE70 2401FFFF */  addiu $at, $zero, -1
/* 13E1B4 8024AE74 14610004 */  bne   $v1, $at, .L8024AE88
/* 13E1B8 8024AE78 3C018000 */   lui   $at, 0x8000
/* 13E1BC 8024AE7C 14410002 */  bne   $v0, $at, .L8024AE88
/* 13E1C0 8024AE80 00000000 */   nop   
/* 13E1C4 8024AE84 0006000D */  break 6
.L8024AE88:
/* 13E1C8 8024AE88 00001810 */  mfhi  $v1
/* 13E1CC 8024AE8C 3C068025 */  lui   $a2, 0x8025
/* 13E1D0 8024AE90 24C6F7C4 */  addiu $a2, $a2, -0x83c
/* 13E1D4 8024AE94 8CC20000 */  lw    $v0, ($a2)
/* 13E1D8 8024AE98 00031880 */  sll   $v1, $v1, 2
/* 13E1DC 8024AE9C 00711821 */  addu  $v1, $v1, $s1
/* 13E1E0 8024AEA0 8C630000 */  lw    $v1, ($v1)
/* 13E1E4 8024AEA4 1043000E */  beq   $v0, $v1, .L8024AEE0
/* 13E1E8 8024AEA8 00031080 */   sll   $v0, $v1, 2
/* 13E1EC 8024AEAC 3C048025 */  lui   $a0, 0x8025
/* 13E1F0 8024AEB0 00822021 */  addu  $a0, $a0, $v0
/* 13E1F4 8024AEB4 8C84F718 */  lw    $a0, -0x8e8($a0)
/* 13E1F8 8024AEB8 27A50010 */  addiu $a1, $sp, 0x10
/* 13E1FC 8024AEBC 0C016B3A */  jal   load_asset_by_name
/* 13E200 8024AEC0 ACC30000 */   sw    $v1, ($a2)
/* 13E204 8024AEC4 0040802D */  daddu $s0, $v0, $zero
/* 13E208 8024AEC8 3C058025 */  lui   $a1, 0x8025
/* 13E20C 8024AECC 8CA5F748 */  lw    $a1, -0x8b8($a1)
/* 13E210 8024AED0 0C01BB7C */  jal   decode_yay0
/* 13E214 8024AED4 0200202D */   daddu $a0, $s0, $zero
/* 13E218 8024AED8 0C00AB1E */  jal   general_heap_free
/* 13E21C 8024AEDC 0200202D */   daddu $a0, $s0, $zero
.L8024AEE0:
/* 13E220 8024AEE0 8FBF0024 */  lw    $ra, 0x24($sp)
/* 13E224 8024AEE4 8FB20020 */  lw    $s2, 0x20($sp)
/* 13E228 8024AEE8 8FB1001C */  lw    $s1, 0x1c($sp)
/* 13E22C 8024AEEC 8FB00018 */  lw    $s0, 0x18($sp)
/* 13E230 8024AEF0 03E00008 */  jr    $ra
/* 13E234 8024AEF4 27BD0028 */   addiu $sp, $sp, 0x28

/* 13E238 8024AEF8 27BDFE78 */  addiu $sp, $sp, -0x188
/* 13E23C 8024AEFC 3C08DC08 */  lui   $t0, 0xdc08
/* 13E240 8024AF00 35080008 */  ori   $t0, $t0, 8
/* 13E244 8024AF04 27A40050 */  addiu $a0, $sp, 0x50
/* 13E248 8024AF08 AFB30144 */  sw    $s3, 0x144($sp)
/* 13E24C 8024AF0C 3C130001 */  lui   $s3, 1
/* 13E250 8024AF10 36731630 */  ori   $s3, $s3, 0x1630
/* 13E254 8024AF14 AFB1013C */  sw    $s1, 0x13c($sp)
/* 13E258 8024AF18 3C11800A */  lui   $s1, 0x800a
/* 13E25C 8024AF1C 2631A66C */  addiu $s1, $s1, -0x5994
/* 13E260 8024AF20 AFBF015C */  sw    $ra, 0x15c($sp)
/* 13E264 8024AF24 AFBE0158 */  sw    $fp, 0x158($sp)
/* 13E268 8024AF28 AFB70154 */  sw    $s7, 0x154($sp)
/* 13E26C 8024AF2C AFB60150 */  sw    $s6, 0x150($sp)
/* 13E270 8024AF30 AFB5014C */  sw    $s5, 0x14c($sp)
/* 13E274 8024AF34 AFB40148 */  sw    $s4, 0x148($sp)
/* 13E278 8024AF38 AFB20140 */  sw    $s2, 0x140($sp)
/* 13E27C 8024AF3C AFB00138 */  sw    $s0, 0x138($sp)
/* 13E280 8024AF40 F7BC0180 */  sdc1  $f28, 0x180($sp)
/* 13E284 8024AF44 F7BA0178 */  sdc1  $f26, 0x178($sp)
/* 13E288 8024AF48 F7B80170 */  sdc1  $f24, 0x170($sp)
/* 13E28C 8024AF4C F7B60168 */  sdc1  $f22, 0x168($sp)
/* 13E290 8024AF50 F7B40160 */  sdc1  $f20, 0x160($sp)
/* 13E294 8024AF54 AFA5018C */  sw    $a1, 0x18c($sp)
/* 13E298 8024AF58 AFA60190 */  sw    $a2, 0x190($sp)
/* 13E29C 8024AF5C AFA70194 */  sw    $a3, 0x194($sp)
/* 13E2A0 8024AF60 8E220000 */  lw    $v0, ($s1)
/* 13E2A4 8024AF64 3C0643A0 */  lui   $a2, 0x43a0
/* 13E2A8 8024AF68 4480A000 */  mtc1  $zero, $f20
/* 13E2AC 8024AF6C 3C074370 */  lui   $a3, 0x4370
/* 13E2B0 8024AF70 3C01C2C8 */  lui   $at, 0xc2c8
/* 13E2B4 8024AF74 44810000 */  mtc1  $at, $f0
/* 13E2B8 8024AF78 3C0142C8 */  lui   $at, 0x42c8
/* 13E2BC 8024AF7C 44811000 */  mtc1  $at, $f2
/* 13E2C0 8024AF80 3C013F80 */  lui   $at, 0x3f80
/* 13E2C4 8024AF84 44812000 */  mtc1  $at, $f4
/* 13E2C8 8024AF88 0040182D */  daddu $v1, $v0, $zero
/* 13E2CC 8024AF8C 4405A000 */  mfc1  $a1, $f20
/* 13E2D0 8024AF90 24420008 */  addiu $v0, $v0, 8
/* 13E2D4 8024AF94 AE220000 */  sw    $v0, ($s1)
/* 13E2D8 8024AF98 3C028025 */  lui   $v0, 0x8025
/* 13E2DC 8024AF9C 2442F620 */  addiu $v0, $v0, -0x9e0
/* 13E2E0 8024AFA0 AC680000 */  sw    $t0, ($v1)
/* 13E2E4 8024AFA4 AC620004 */  sw    $v0, 4($v1)
/* 13E2E8 8024AFA8 E7B40010 */  swc1  $f20, 0x10($sp)
/* 13E2EC 8024AFAC E7A00014 */  swc1  $f0, 0x14($sp)
/* 13E2F0 8024AFB0 E7A20018 */  swc1  $f2, 0x18($sp)
/* 13E2F4 8024AFB4 0C018E44 */  jal   guOrthoF
/* 13E2F8 8024AFB8 E7A4001C */   swc1  $f4, 0x1c($sp)
