.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219C80_5B3130
/* 5B3130 80219C80 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 5B3134 80219C84 AFB20020 */  sw        $s2, 0x20($sp)
/* 5B3138 80219C88 0000902D */  daddu     $s2, $zero, $zero
/* 5B313C 80219C8C AFB1001C */  sw        $s1, 0x1c($sp)
/* 5B3140 80219C90 0240882D */  daddu     $s1, $s2, $zero
/* 5B3144 80219C94 AFB30024 */  sw        $s3, 0x24($sp)
/* 5B3148 80219C98 3C138009 */  lui       $s3, %hi(gAreas)
/* 5B314C 80219C9C 267334F0 */  addiu     $s3, $s3, %lo(gAreas)
/* 5B3150 80219CA0 AFB00018 */  sw        $s0, 0x18($sp)
/* 5B3154 80219CA4 3C108023 */  lui       $s0, %hi(D_80233564_5CCA14)
/* 5B3158 80219CA8 26103564 */  addiu     $s0, $s0, %lo(D_80233564_5CCA14)
/* 5B315C 80219CAC AFBF0028 */  sw        $ra, 0x28($sp)
.L80219CB0:
/* 5B3160 80219CB0 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 5B3164 80219CB4 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 5B3168 80219CB8 8E050000 */  lw        $a1, ($s0)
/* 5B316C 80219CBC 84430086 */  lh        $v1, 0x86($v0)
/* 5B3170 80219CC0 8442008C */  lh        $v0, 0x8c($v0)
/* 5B3174 80219CC4 00031900 */  sll       $v1, $v1, 4
/* 5B3178 80219CC8 00731821 */  addu      $v1, $v1, $s3
/* 5B317C 80219CCC 8C630004 */  lw        $v1, 4($v1)
/* 5B3180 80219CD0 00021140 */  sll       $v0, $v0, 5
/* 5B3184 80219CD4 00431021 */  addu      $v0, $v0, $v1
/* 5B3188 80219CD8 0C01BB5C */  jal       strcmp
/* 5B318C 80219CDC 8C440000 */   lw       $a0, ($v0)
/* 5B3190 80219CE0 14400003 */  bnez      $v0, .L80219CF0
/* 5B3194 80219CE4 26310001 */   addiu    $s1, $s1, 1
/* 5B3198 80219CE8 0808673F */  j         .L80219CFC
/* 5B319C 80219CEC 24120001 */   addiu    $s2, $zero, 1
.L80219CF0:
/* 5B31A0 80219CF0 2E22000B */  sltiu     $v0, $s1, 0xb
/* 5B31A4 80219CF4 1440FFEE */  bnez      $v0, .L80219CB0
/* 5B31A8 80219CF8 26100004 */   addiu    $s0, $s0, 4
.L80219CFC:
/* 5B31AC 80219CFC 44800000 */  mtc1      $zero, $f0
/* 5B31B0 80219D00 00000000 */  nop
/* 5B31B4 80219D04 44050000 */  mfc1      $a1, $f0
/* 5B31B8 80219D08 0240202D */  daddu     $a0, $s2, $zero
/* 5B31BC 80219D0C AFA00014 */  sw        $zero, 0x14($sp)
/* 5B31C0 80219D10 00A0302D */  daddu     $a2, $a1, $zero
/* 5B31C4 80219D14 00A0382D */  daddu     $a3, $a1, $zero
/* 5B31C8 80219D18 0C01CA54 */  jal       playFX_82
/* 5B31CC 80219D1C AFA50010 */   sw       $a1, 0x10($sp)
/* 5B31D0 80219D20 8FBF0028 */  lw        $ra, 0x28($sp)
/* 5B31D4 80219D24 8FB30024 */  lw        $s3, 0x24($sp)
/* 5B31D8 80219D28 8FB20020 */  lw        $s2, 0x20($sp)
/* 5B31DC 80219D2C 8FB1001C */  lw        $s1, 0x1c($sp)
/* 5B31E0 80219D30 8FB00018 */  lw        $s0, 0x18($sp)
/* 5B31E4 80219D34 24020002 */  addiu     $v0, $zero, 2
/* 5B31E8 80219D38 03E00008 */  jr        $ra
/* 5B31EC 80219D3C 27BD0030 */   addiu    $sp, $sp, 0x30
