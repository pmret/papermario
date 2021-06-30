.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osCreateThread
/* 41260 80065E60 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 41264 80065E64 AFB00010 */  sw        $s0, 0x10($sp)
/* 41268 80065E68 00808021 */  addu      $s0, $a0, $zero
/* 4126C 80065E6C 00E04821 */  addu      $t1, $a3, $zero
/* 41270 80065E70 000747C3 */  sra       $t0, $a3, 0x1f
/* 41274 80065E74 3C048007 */  lui       $a0, %hi(osCleanupThread)
/* 41278 80065E78 2484B350 */  addiu     $a0, $a0, %lo(osCleanupThread)
/* 4127C 80065E7C 00801821 */  addu      $v1, $a0, $zero
/* 41280 80065E80 000417C3 */  sra       $v0, $a0, 0x1f
/* 41284 80065E84 8FA70028 */  lw        $a3, 0x28($sp)
/* 41288 80065E88 3C040100 */  lui       $a0, 0x100
/* 4128C 80065E8C 34840800 */  ori       $a0, $a0, 0x800
/* 41290 80065E90 AFBF0014 */  sw        $ra, 0x14($sp)
/* 41294 80065E94 AE020100 */  sw        $v0, 0x100($s0)
/* 41298 80065E98 AE030104 */  sw        $v1, 0x104($s0)
/* 4129C 80065E9C 3402FF03 */  ori       $v0, $zero, 0xff03
/* 412A0 80065EA0 AE020118 */  sw        $v0, 0x118($s0)
/* 412A4 80065EA4 2402003F */  addiu     $v0, $zero, 0x3f
/* 412A8 80065EA8 AE020128 */  sw        $v0, 0x128($s0)
/* 412AC 80065EAC 24020001 */  addiu     $v0, $zero, 1
/* 412B0 80065EB0 AE050014 */  sw        $a1, 0x14($s0)
/* 412B4 80065EB4 AE000000 */  sw        $zero, ($s0)
/* 412B8 80065EB8 AE000008 */  sw        $zero, 8($s0)
/* 412BC 80065EBC AE06011C */  sw        $a2, 0x11c($s0)
/* 412C0 80065EC0 AE080038 */  sw        $t0, 0x38($s0)
/* 412C4 80065EC4 AE09003C */  sw        $t1, 0x3c($s0)
/* 412C8 80065EC8 AE04012C */  sw        $a0, 0x12c($s0)
/* 412CC 80065ECC AE000018 */  sw        $zero, 0x18($s0)
/* 412D0 80065ED0 A6020010 */  sh        $v0, 0x10($s0)
/* 412D4 80065ED4 A6000012 */  sh        $zero, 0x12($s0)
/* 412D8 80065ED8 8FA2002C */  lw        $v0, 0x2c($sp)
/* 412DC 80065EDC 00E05821 */  addu      $t3, $a3, $zero
/* 412E0 80065EE0 000757C3 */  sra       $t2, $a3, 0x1f
/* 412E4 80065EE4 AE020004 */  sw        $v0, 4($s0)
/* 412E8 80065EE8 256BFFF0 */  addiu     $t3, $t3, -0x10
/* 412EC 80065EEC 2D62FFF0 */  sltiu     $v0, $t3, -0x10
/* 412F0 80065EF0 254AFFFF */  addiu     $t2, $t2, -1
/* 412F4 80065EF4 01425021 */  addu      $t2, $t2, $v0
/* 412F8 80065EF8 AE0A00F0 */  sw        $t2, 0xf0($s0)
/* 412FC 80065EFC 0C01ACD8 */  jal       osDisableInt
/* 41300 80065F00 AE0B00F4 */   sw       $t3, 0xf4($s0)
/* 41304 80065F04 3C038009 */  lui       $v1, %hi(__osActiveQueue)
/* 41308 80065F08 8C63465C */  lw        $v1, %lo(__osActiveQueue)($v1)
/* 4130C 80065F0C 00402021 */  addu      $a0, $v0, $zero
/* 41310 80065F10 3C018009 */  lui       $at, %hi(__osActiveQueue)
/* 41314 80065F14 AC30465C */  sw        $s0, %lo(__osActiveQueue)($at)
/* 41318 80065F18 0C01ACF4 */  jal       osRestoreInt
/* 4131C 80065F1C AE03000C */   sw       $v1, 0xc($s0)
/* 41320 80065F20 8FBF0014 */  lw        $ra, 0x14($sp)
/* 41324 80065F24 8FB00010 */  lw        $s0, 0x10($sp)
/* 41328 80065F28 03E00008 */  jr        $ra
/* 4132C 80065F2C 27BD0018 */   addiu    $sp, $sp, 0x18
