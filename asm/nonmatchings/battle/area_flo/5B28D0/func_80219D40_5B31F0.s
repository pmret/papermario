.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219D40_5B31F0
/* 5B31F0 80219D40 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 5B31F4 80219D44 AFB20020 */  sw        $s2, 0x20($sp)
/* 5B31F8 80219D48 0000902D */  daddu     $s2, $zero, $zero
/* 5B31FC 80219D4C AFB1001C */  sw        $s1, 0x1c($sp)
/* 5B3200 80219D50 0240882D */  daddu     $s1, $s2, $zero
/* 5B3204 80219D54 AFB30024 */  sw        $s3, 0x24($sp)
/* 5B3208 80219D58 3C138009 */  lui       $s3, %hi(gAreas)
/* 5B320C 80219D5C 267334F0 */  addiu     $s3, $s3, %lo(gAreas)
/* 5B3210 80219D60 AFB00018 */  sw        $s0, 0x18($sp)
/* 5B3214 80219D64 3C108023 */  lui       $s0, %hi(D_80233870)
/* 5B3218 80219D68 26103870 */  addiu     $s0, $s0, %lo(D_80233870)
/* 5B321C 80219D6C AFBF0028 */  sw        $ra, 0x28($sp)
.L80219D70:
/* 5B3220 80219D70 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 5B3224 80219D74 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 5B3228 80219D78 8E050000 */  lw        $a1, ($s0)
/* 5B322C 80219D7C 84430086 */  lh        $v1, 0x86($v0)
/* 5B3230 80219D80 8442008C */  lh        $v0, 0x8c($v0)
/* 5B3234 80219D84 00031900 */  sll       $v1, $v1, 4
/* 5B3238 80219D88 00731821 */  addu      $v1, $v1, $s3
/* 5B323C 80219D8C 8C630004 */  lw        $v1, 4($v1)
/* 5B3240 80219D90 00021140 */  sll       $v0, $v0, 5
/* 5B3244 80219D94 00431021 */  addu      $v0, $v0, $v1
/* 5B3248 80219D98 0C01BB5C */  jal       strcmp
/* 5B324C 80219D9C 8C440000 */   lw       $a0, ($v0)
/* 5B3250 80219DA0 14400003 */  bnez      $v0, .L80219DB0
/* 5B3254 80219DA4 26310001 */   addiu    $s1, $s1, 1
/* 5B3258 80219DA8 0808676F */  j         .L80219DBC
/* 5B325C 80219DAC 24120001 */   addiu    $s2, $zero, 1
.L80219DB0:
/* 5B3260 80219DB0 2E22000B */  sltiu     $v0, $s1, 0xb
/* 5B3264 80219DB4 1440FFEE */  bnez      $v0, .L80219D70
/* 5B3268 80219DB8 26100004 */   addiu    $s0, $s0, 4
.L80219DBC:
/* 5B326C 80219DBC 44800000 */  mtc1      $zero, $f0
/* 5B3270 80219DC0 00000000 */  nop
/* 5B3274 80219DC4 44050000 */  mfc1      $a1, $f0
/* 5B3278 80219DC8 0240202D */  daddu     $a0, $s2, $zero
/* 5B327C 80219DCC AFA00014 */  sw        $zero, 0x14($sp)
/* 5B3280 80219DD0 00A0302D */  daddu     $a2, $a1, $zero
/* 5B3284 80219DD4 00A0382D */  daddu     $a3, $a1, $zero
/* 5B3288 80219DD8 0C01CA54 */  jal       func_80072950
/* 5B328C 80219DDC AFA50010 */   sw       $a1, 0x10($sp)
/* 5B3290 80219DE0 8FBF0028 */  lw        $ra, 0x28($sp)
/* 5B3294 80219DE4 8FB30024 */  lw        $s3, 0x24($sp)
/* 5B3298 80219DE8 8FB20020 */  lw        $s2, 0x20($sp)
/* 5B329C 80219DEC 8FB1001C */  lw        $s1, 0x1c($sp)
/* 5B32A0 80219DF0 8FB00018 */  lw        $s0, 0x18($sp)
/* 5B32A4 80219DF4 24020002 */  addiu     $v0, $zero, 2
/* 5B32A8 80219DF8 03E00008 */  jr        $ra
/* 5B32AC 80219DFC 27BD0030 */   addiu    $sp, $sp, 0x30
