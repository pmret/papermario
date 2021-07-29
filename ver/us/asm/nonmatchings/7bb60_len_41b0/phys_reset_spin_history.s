.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel phys_reset_spin_history
/* 7EE50 800E59A0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7EE54 800E59A4 3C048011 */  lui       $a0, %hi(D_8010F250)
/* 7EE58 800E59A8 2484F250 */  addiu     $a0, $a0, %lo(D_8010F250)
/* 7EE5C 800E59AC AFBF0010 */  sw        $ra, 0x10($sp)
/* 7EE60 800E59B0 0C00A580 */  jal       mem_clear
/* 7EE64 800E59B4 24050034 */   addiu    $a1, $zero, 0x34
/* 7EE68 800E59B8 0000382D */  daddu     $a3, $zero, $zero
/* 7EE6C 800E59BC 3C068011 */  lui       $a2, %hi(D_8010EF40)
/* 7EE70 800E59C0 24C6EF40 */  addiu     $a2, $a2, %lo(D_8010EF40)
/* 7EE74 800E59C4 3C058011 */  lui       $a1, %hi(D_8010EF10)
/* 7EE78 800E59C8 24A5EF10 */  addiu     $a1, $a1, %lo(D_8010EF10)
/* 7EE7C 800E59CC 3C048011 */  lui       $a0, %hi(D_8010EF28)
/* 7EE80 800E59D0 2484EF28 */  addiu     $a0, $a0, %lo(D_8010EF28)
/* 7EE84 800E59D4 3C038011 */  lui       $v1, %hi(D_8010F6B8)
/* 7EE88 800E59D8 2463F6B8 */  addiu     $v1, $v1, %lo(D_8010F6B8)
/* 7EE8C 800E59DC 3C018011 */  lui       $at, %hi(D_8010C944)
/* 7EE90 800E59E0 AC20C944 */  sw        $zero, %lo(D_8010C944)($at)
.L800E59E4:
/* 7EE94 800E59E4 A4600000 */  sh        $zero, ($v1)
/* 7EE98 800E59E8 AC800000 */  sw        $zero, ($a0)
/* 7EE9C 800E59EC ACA00000 */  sw        $zero, ($a1)
/* 7EEA0 800E59F0 ACC00000 */  sw        $zero, ($a2)
/* 7EEA4 800E59F4 24C60004 */  addiu     $a2, $a2, 4
/* 7EEA8 800E59F8 24A50004 */  addiu     $a1, $a1, 4
/* 7EEAC 800E59FC 24840004 */  addiu     $a0, $a0, 4
/* 7EEB0 800E5A00 24E70001 */  addiu     $a3, $a3, 1
/* 7EEB4 800E5A04 28E20005 */  slti      $v0, $a3, 5
/* 7EEB8 800E5A08 1440FFF6 */  bnez      $v0, .L800E59E4
/* 7EEBC 800E5A0C 24630002 */   addiu    $v1, $v1, 2
/* 7EEC0 800E5A10 8FBF0010 */  lw        $ra, 0x10($sp)
/* 7EEC4 800E5A14 3C018011 */  lui       $at, %hi(D_8010C964)
/* 7EEC8 800E5A18 AC20C964 */  sw        $zero, %lo(D_8010C964)($at)
/* 7EECC 800E5A1C 3C018011 */  lui       $at, %hi(D_8010C924)
/* 7EED0 800E5A20 AC20C924 */  sw        $zero, %lo(D_8010C924)($at)
/* 7EED4 800E5A24 03E00008 */  jr        $ra
/* 7EED8 800E5A28 27BD0018 */   addiu    $sp, $sp, 0x18
