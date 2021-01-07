.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021833C_6DC0DC
/* 6DC0DC 8021833C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 6DC0E0 80218340 AFB00010 */  sw        $s0, 0x10($sp)
/* 6DC0E4 80218344 0080802D */  daddu     $s0, $a0, $zero
/* 6DC0E8 80218348 10A00010 */  beqz      $a1, .L8021838C
/* 6DC0EC 8021834C AFBF0014 */   sw       $ra, 0x14($sp)
/* 6DC0F0 80218350 24040001 */  addiu     $a0, $zero, 1
/* 6DC0F4 80218354 0000282D */  daddu     $a1, $zero, $zero
/* 6DC0F8 80218358 00A0302D */  daddu     $a2, $a1, $zero
/* 6DC0FC 8021835C 00A0382D */  daddu     $a3, $a1, $zero
/* 6DC100 80218360 24020014 */  addiu     $v0, $zero, 0x14
/* 6DC104 80218364 0C04DF93 */  jal       func_80137E4C
/* 6DC108 80218368 AE020070 */   sw       $v0, 0x70($s0)
/* 6DC10C 8021836C 24040001 */  addiu     $a0, $zero, 1
/* 6DC110 80218370 0080282D */  daddu     $a1, $a0, $zero
/* 6DC114 80218374 24060140 */  addiu     $a2, $zero, 0x140
/* 6DC118 80218378 0C04DF93 */  jal       func_80137E4C
/* 6DC11C 8021837C 240700F0 */   addiu    $a3, $zero, 0xf0
/* 6DC120 80218380 3C054316 */  lui       $a1, 0x4316
/* 6DC124 80218384 0C04DF69 */  jal       func_80137DA4
/* 6DC128 80218388 2404000C */   addiu    $a0, $zero, 0xc
.L8021838C:
/* 6DC12C 8021838C 8E020070 */  lw        $v0, 0x70($s0)
/* 6DC130 80218390 14400010 */  bnez      $v0, .L802183D4
/* 6DC134 80218394 2442FFFF */   addiu    $v0, $v0, -1
/* 6DC138 80218398 24040001 */  addiu     $a0, $zero, 1
/* 6DC13C 8021839C 0000282D */  daddu     $a1, $zero, $zero
/* 6DC140 802183A0 00A0302D */  daddu     $a2, $a1, $zero
/* 6DC144 802183A4 0C04DF93 */  jal       func_80137E4C
/* 6DC148 802183A8 00A0382D */   daddu    $a3, $a1, $zero
/* 6DC14C 802183AC 24040001 */  addiu     $a0, $zero, 1
/* 6DC150 802183B0 0080282D */  daddu     $a1, $a0, $zero
/* 6DC154 802183B4 24060140 */  addiu     $a2, $zero, 0x140
/* 6DC158 802183B8 0C04DF93 */  jal       func_80137E4C
/* 6DC15C 802183BC 240700F0 */   addiu    $a3, $zero, 0xf0
/* 6DC160 802183C0 3C05BF80 */  lui       $a1, 0xbf80
/* 6DC164 802183C4 0C04DF69 */  jal       func_80137DA4
/* 6DC168 802183C8 240400FF */   addiu    $a0, $zero, 0xff
/* 6DC16C 802183CC 080860F7 */  j         .L802183DC
/* 6DC170 802183D0 24020002 */   addiu    $v0, $zero, 2
.L802183D4:
/* 6DC174 802183D4 AE020070 */  sw        $v0, 0x70($s0)
/* 6DC178 802183D8 0000102D */  daddu     $v0, $zero, $zero
.L802183DC:
/* 6DC17C 802183DC 8FBF0014 */  lw        $ra, 0x14($sp)
/* 6DC180 802183E0 8FB00010 */  lw        $s0, 0x10($sp)
/* 6DC184 802183E4 03E00008 */  jr        $ra
/* 6DC188 802183E8 27BD0018 */   addiu    $sp, $sp, 0x18
