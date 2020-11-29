.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80045FB4
/* 213B4 80045FB4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 213B8 80045FB8 AFBF0014 */  sw        $ra, 0x14($sp)
/* 213BC 80045FBC 0C011722 */  jal       func_80045C88
/* 213C0 80045FC0 AFB00010 */   sw       $s0, 0x10($sp)
/* 213C4 80045FC4 0040802D */  daddu     $s0, $v0, $zero
/* 213C8 80045FC8 12000015 */  beqz      $s0, .L80046020
/* 213CC 80045FCC 24042C00 */   addiu    $a0, $zero, 0x2c00
/* 213D0 80045FD0 3C028004 */  lui       $v0, %hi(D_80046030)
/* 213D4 80045FD4 24426030 */  addiu     $v0, $v0, %lo(D_80046030)
/* 213D8 80045FD8 AE020004 */  sw        $v0, 4($s0)
/* 213DC 80045FDC 3C028004 */  lui       $v0, %hi(D_800465E0)
/* 213E0 80045FE0 244265E0 */  addiu     $v0, $v0, %lo(D_800465E0)
/* 213E4 80045FE4 AE000000 */  sw        $zero, ($s0)
/* 213E8 80045FE8 AE000008 */  sw        $zero, 8($s0)
/* 213EC 80045FEC 0C00AB0A */  jal       general_heap_malloc
/* 213F0 80045FF0 AE02000C */   sw       $v0, 0xc($s0)
/* 213F4 80045FF4 AE020018 */  sw        $v0, 0x18($s0)
/* 213F8 80045FF8 3C01800A */  lui       $at, %hi(D_800A0F44)
/* 213FC 80045FFC AC220F44 */  sw        $v0, %lo(D_800A0F44)($at)
/* 21400 80046000 14400003 */  bnez      $v0, .L80046010
/* 21404 80046004 2403003F */   addiu    $v1, $zero, 0x3f
.L80046008:
/* 21408 80046008 08011802 */  j         .L80046008
/* 2140C 8004600C 00000000 */   nop      
.L80046010:
/* 21410 80046010 AC400000 */  sw        $zero, ($v0)
/* 21414 80046014 2463FFFF */  addiu     $v1, $v1, -1
/* 21418 80046018 0461FFFD */  bgez      $v1, .L80046010
/* 2141C 8004601C 244200B0 */   addiu    $v0, $v0, 0xb0
.L80046020:
/* 21420 80046020 8FBF0014 */  lw        $ra, 0x14($sp)
/* 21424 80046024 8FB00010 */  lw        $s0, 0x10($sp)
/* 21428 80046028 03E00008 */  jr        $ra
/* 2142C 8004602C 27BD0018 */   addiu    $sp, $sp, 0x18
