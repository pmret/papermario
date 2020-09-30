.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800DFEFC
/* 793AC 800DFEFC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 793B0 800DFF00 AFB00010 */  sw        $s0, 0x10($sp)
/* 793B4 800DFF04 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* 793B8 800DFF08 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* 793BC 800DFF0C AFBF0014 */  sw        $ra, 0x14($sp)
/* 793C0 800DFF10 0C037F52 */  jal       func_800DFD48
/* 793C4 800DFF14 00000000 */   nop      
/* 793C8 800DFF18 0040202D */  daddu     $a0, $v0, $zero
/* 793CC 800DFF1C 2402FFFF */  addiu     $v0, $zero, -1
/* 793D0 800DFF20 10820007 */  beq       $a0, $v0, .L800DFF40
/* 793D4 800DFF24 3C03EFFF */   lui      $v1, 0xefff
/* 793D8 800DFF28 8E020000 */  lw        $v0, ($s0)
/* 793DC 800DFF2C 3463FFFF */  ori       $v1, $v1, 0xffff
/* 793E0 800DFF30 AE0400B8 */  sw        $a0, 0xb8($s0)
/* 793E4 800DFF34 A60000BC */  sh        $zero, 0xbc($s0)
/* 793E8 800DFF38 00431024 */  and       $v0, $v0, $v1
/* 793EC 800DFF3C AE020000 */  sw        $v0, ($s0)
.L800DFF40:
/* 793F0 800DFF40 8FBF0014 */  lw        $ra, 0x14($sp)
/* 793F4 800DFF44 8FB00010 */  lw        $s0, 0x10($sp)
/* 793F8 800DFF48 03E00008 */  jr        $ra
/* 793FC 800DFF4C 27BD0018 */   addiu    $sp, $sp, 0x18
