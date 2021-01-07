.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel update_messages
/* B9ED8 801237D8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B9EDC 801237DC 3C038015 */  lui       $v1, %hi(D_801512E4)
/* B9EE0 801237E0 246312E4 */  addiu     $v1, $v1, %lo(D_801512E4)
/* B9EE4 801237E4 AFBF0018 */  sw        $ra, 0x18($sp)
/* B9EE8 801237E8 AFB10014 */  sw        $s1, 0x14($sp)
/* B9EEC 801237EC AFB00010 */  sw        $s0, 0x10($sp)
/* B9EF0 801237F0 94620000 */  lhu       $v0, ($v1)
/* B9EF4 801237F4 24420001 */  addiu     $v0, $v0, 1
/* B9EF8 801237F8 A4620000 */  sh        $v0, ($v1)
/* B9EFC 801237FC 3042FFFF */  andi      $v0, $v0, 0xffff
/* B9F00 80123800 2C420168 */  sltiu     $v0, $v0, 0x168
/* B9F04 80123804 50400001 */  beql      $v0, $zero, .L8012380C
/* B9F08 80123808 A4600000 */   sh       $zero, ($v1)
.L8012380C:
/* B9F0C 8012380C 0000882D */  daddu     $s1, $zero, $zero
/* B9F10 80123810 3C108015 */  lui       $s0, %hi(D_80154C30)
/* B9F14 80123814 26104C30 */  addiu     $s0, $s0, %lo(D_80154C30)
.L80123818:
/* B9F18 80123818 8E0204FC */  lw        $v0, 0x4fc($s0)
/* B9F1C 8012381C 30420002 */  andi      $v0, $v0, 2
/* B9F20 80123820 50400004 */  beql      $v0, $zero, .L80123834
/* B9F24 80123824 26310001 */   addiu    $s1, $s1, 1
/* B9F28 80123828 0C048E26 */  jal       _update_message
/* B9F2C 8012382C 0200202D */   daddu    $a0, $s0, $zero
/* B9F30 80123830 26310001 */  addiu     $s1, $s1, 1
.L80123834:
/* B9F34 80123834 2A220003 */  slti      $v0, $s1, 3
/* B9F38 80123838 1440FFF7 */  bnez      $v0, .L80123818
/* B9F3C 8012383C 26100558 */   addiu    $s0, $s0, 0x558
/* B9F40 80123840 3C048015 */  lui       $a0, %hi(D_801512D8)
/* B9F44 80123844 248412D8 */  addiu     $a0, $a0, %lo(D_801512D8)
/* B9F48 80123848 3C068015 */  lui       $a2, %hi(D_8015130C)
/* B9F4C 8012384C 24C6130C */  addiu     $a2, $a2, %lo(D_8015130C)
/* B9F50 80123850 8C850000 */  lw        $a1, ($a0)
/* B9F54 80123854 8CC70000 */  lw        $a3, ($a2)
/* B9F58 80123858 24A2000C */  addiu     $v0, $a1, 0xc
/* B9F5C 8012385C 24E3FFF4 */  addiu     $v1, $a3, -0xc
/* B9F60 80123860 AC820000 */  sw        $v0, ($a0)
/* B9F64 80123864 28420800 */  slti      $v0, $v0, 0x800
/* B9F68 80123868 14400003 */  bnez      $v0, .L80123878
/* B9F6C 8012386C ACC30000 */   sw       $v1, ($a2)
/* B9F70 80123870 24A2F80C */  addiu     $v0, $a1, -0x7f4
/* B9F74 80123874 AC820000 */  sw        $v0, ($a0)
.L80123878:
/* B9F78 80123878 04610002 */  bgez      $v1, .L80123884
/* B9F7C 8012387C 24E207F4 */   addiu    $v0, $a3, 0x7f4
/* B9F80 80123880 ACC20000 */  sw        $v0, ($a2)
.L80123884:
/* B9F84 80123884 8FBF0018 */  lw        $ra, 0x18($sp)
/* B9F88 80123888 8FB10014 */  lw        $s1, 0x14($sp)
/* B9F8C 8012388C 8FB00010 */  lw        $s0, 0x10($sp)
/* B9F90 80123890 03E00008 */  jr        $ra
/* B9F94 80123894 27BD0020 */   addiu    $sp, $sp, 0x20
