.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219E00_5B32B0
/* 5B32B0 80219E00 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 5B32B4 80219E04 AFB20020 */  sw        $s2, 0x20($sp)
/* 5B32B8 80219E08 0000902D */  daddu     $s2, $zero, $zero
/* 5B32BC 80219E0C AFB1001C */  sw        $s1, 0x1c($sp)
/* 5B32C0 80219E10 0240882D */  daddu     $s1, $s2, $zero
/* 5B32C4 80219E14 AFB30024 */  sw        $s3, 0x24($sp)
/* 5B32C8 80219E18 3C138009 */  lui       $s3, %hi(gAreas)
/* 5B32CC 80219E1C 267334F0 */  addiu     $s3, $s3, %lo(gAreas)
/* 5B32D0 80219E20 AFB00018 */  sw        $s0, 0x18($sp)
/* 5B32D4 80219E24 3C108023 */  lui       $s0, %hi(D_80233950)
/* 5B32D8 80219E28 26103950 */  addiu     $s0, $s0, %lo(D_80233950)
/* 5B32DC 80219E2C AFBF0028 */  sw        $ra, 0x28($sp)
.L80219E30:
/* 5B32E0 80219E30 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 5B32E4 80219E34 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 5B32E8 80219E38 8E050000 */  lw        $a1, ($s0)
/* 5B32EC 80219E3C 84430086 */  lh        $v1, 0x86($v0)
/* 5B32F0 80219E40 8442008C */  lh        $v0, 0x8c($v0)
/* 5B32F4 80219E44 00031900 */  sll       $v1, $v1, 4
/* 5B32F8 80219E48 00731821 */  addu      $v1, $v1, $s3
/* 5B32FC 80219E4C 8C630004 */  lw        $v1, 4($v1)
/* 5B3300 80219E50 00021140 */  sll       $v0, $v0, 5
/* 5B3304 80219E54 00431021 */  addu      $v0, $v0, $v1
/* 5B3308 80219E58 0C01BB5C */  jal       strcmp
/* 5B330C 80219E5C 8C440000 */   lw       $a0, ($v0)
/* 5B3310 80219E60 14400003 */  bnez      $v0, .L80219E70
/* 5B3314 80219E64 26310001 */   addiu    $s1, $s1, 1
/* 5B3318 80219E68 0808679F */  j         .L80219E7C
/* 5B331C 80219E6C 24120001 */   addiu    $s2, $zero, 1
.L80219E70:
/* 5B3320 80219E70 2E22000B */  sltiu     $v0, $s1, 0xb
/* 5B3324 80219E74 1440FFEE */  bnez      $v0, .L80219E30
/* 5B3328 80219E78 26100004 */   addiu    $s0, $s0, 4
.L80219E7C:
/* 5B332C 80219E7C 44800000 */  mtc1      $zero, $f0
/* 5B3330 80219E80 00000000 */  nop
/* 5B3334 80219E84 44050000 */  mfc1      $a1, $f0
/* 5B3338 80219E88 0240202D */  daddu     $a0, $s2, $zero
/* 5B333C 80219E8C AFA00014 */  sw        $zero, 0x14($sp)
/* 5B3340 80219E90 00A0302D */  daddu     $a2, $a1, $zero
/* 5B3344 80219E94 00A0382D */  daddu     $a3, $a1, $zero
/* 5B3348 80219E98 0C01CA54 */  jal       func_80072950
/* 5B334C 80219E9C AFA50010 */   sw       $a1, 0x10($sp)
/* 5B3350 80219EA0 8FBF0028 */  lw        $ra, 0x28($sp)
/* 5B3354 80219EA4 8FB30024 */  lw        $s3, 0x24($sp)
/* 5B3358 80219EA8 8FB20020 */  lw        $s2, 0x20($sp)
/* 5B335C 80219EAC 8FB1001C */  lw        $s1, 0x1c($sp)
/* 5B3360 80219EB0 8FB00018 */  lw        $s0, 0x18($sp)
/* 5B3364 80219EB4 24020002 */  addiu     $v0, $zero, 2
/* 5B3368 80219EB8 03E00008 */  jr        $ra
/* 5B336C 80219EBC 27BD0030 */   addiu    $sp, $sp, 0x30
