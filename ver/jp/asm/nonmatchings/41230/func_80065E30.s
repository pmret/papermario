.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80065E30
/* 41230 80065E30 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 41234 80065E34 AFB00010 */  sw        $s0, 0x10($sp)
/* 41238 80065E38 00808021 */  addu      $s0, $a0, $zero
/* 4123C 80065E3C 00E04821 */  addu      $t1, $a3, $zero
/* 41240 80065E40 000747C3 */  sra       $t0, $a3, 0x1f
/* 41244 80065E44 3C048007 */  lui       $a0, %hi(D_8006B330)
/* 41248 80065E48 2484B330 */  addiu     $a0, $a0, %lo(D_8006B330)
/* 4124C 80065E4C 00801821 */  addu      $v1, $a0, $zero
/* 41250 80065E50 000417C3 */  sra       $v0, $a0, 0x1f
/* 41254 80065E54 8FA70028 */  lw        $a3, 0x28($sp)
/* 41258 80065E58 3C040100 */  lui       $a0, 0x100
/* 4125C 80065E5C 34840800 */  ori       $a0, $a0, 0x800
/* 41260 80065E60 AFBF0014 */  sw        $ra, 0x14($sp)
/* 41264 80065E64 AE020100 */  sw        $v0, 0x100($s0)
/* 41268 80065E68 AE030104 */  sw        $v1, 0x104($s0)
/* 4126C 80065E6C 3402FF03 */  ori       $v0, $zero, 0xff03
/* 41270 80065E70 AE020118 */  sw        $v0, 0x118($s0)
/* 41274 80065E74 2402003F */  addiu     $v0, $zero, 0x3f
/* 41278 80065E78 AE020128 */  sw        $v0, 0x128($s0)
/* 4127C 80065E7C 24020001 */  addiu     $v0, $zero, 1
/* 41280 80065E80 AE050014 */  sw        $a1, 0x14($s0)
/* 41284 80065E84 AE000000 */  sw        $zero, ($s0)
/* 41288 80065E88 AE000008 */  sw        $zero, 8($s0)
/* 4128C 80065E8C AE06011C */  sw        $a2, 0x11c($s0)
/* 41290 80065E90 AE080038 */  sw        $t0, 0x38($s0)
/* 41294 80065E94 AE09003C */  sw        $t1, 0x3c($s0)
/* 41298 80065E98 AE04012C */  sw        $a0, 0x12c($s0)
/* 4129C 80065E9C AE000018 */  sw        $zero, 0x18($s0)
/* 412A0 80065EA0 A6020010 */  sh        $v0, 0x10($s0)
/* 412A4 80065EA4 A6000012 */  sh        $zero, 0x12($s0)
/* 412A8 80065EA8 8FA2002C */  lw        $v0, 0x2c($sp)
/* 412AC 80065EAC 00E05821 */  addu      $t3, $a3, $zero
/* 412B0 80065EB0 000757C3 */  sra       $t2, $a3, 0x1f
/* 412B4 80065EB4 AE020004 */  sw        $v0, 4($s0)
/* 412B8 80065EB8 256BFFF0 */  addiu     $t3, $t3, -0x10
/* 412BC 80065EBC 2D62FFF0 */  sltiu     $v0, $t3, -0x10
/* 412C0 80065EC0 254AFFFF */  addiu     $t2, $t2, -1
/* 412C4 80065EC4 01425021 */  addu      $t2, $t2, $v0
/* 412C8 80065EC8 AE0A00F0 */  sw        $t2, 0xf0($s0)
/* 412CC 80065ECC 0C01ACD0 */  jal       func_8006B340
/* 412D0 80065ED0 AE0B00F4 */   sw       $t3, 0xf4($s0)
/* 412D4 80065ED4 3C038009 */  lui       $v1, %hi(D_8009463C)
/* 412D8 80065ED8 8C63463C */  lw        $v1, %lo(D_8009463C)($v1)
/* 412DC 80065EDC 00402021 */  addu      $a0, $v0, $zero
/* 412E0 80065EE0 3C018009 */  lui       $at, %hi(D_8009463C)
/* 412E4 80065EE4 AC30463C */  sw        $s0, %lo(D_8009463C)($at)
/* 412E8 80065EE8 0C01ACEC */  jal       func_8006B3B0
/* 412EC 80065EEC AE03000C */   sw       $v1, 0xc($s0)
/* 412F0 80065EF0 8FBF0014 */  lw        $ra, 0x14($sp)
/* 412F4 80065EF4 8FB00010 */  lw        $s0, 0x10($sp)
/* 412F8 80065EF8 03E00008 */  jr        $ra
/* 412FC 80065EFC 27BD0018 */   addiu    $sp, $sp, 0x18
