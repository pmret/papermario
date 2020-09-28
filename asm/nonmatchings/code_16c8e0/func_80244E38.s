.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80244E38
/* 173718 80244E38 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 17371C 80244E3C AFB10014 */  sw        $s1, 0x14($sp)
/* 173720 80244E40 3C11800E */  lui       $s1, %hi(gBattleStatus)
/* 173724 80244E44 2631C070 */  addiu     $s1, $s1, %lo(gBattleStatus)
/* 173728 80244E48 AFB20018 */  sw        $s2, 0x18($sp)
/* 17372C 80244E4C 3C12800E */  lui       $s2, 0x800e
/* 173730 80244E50 2652C4DC */  addiu     $s2, $s2, -0x3b24
/* 173734 80244E54 AFBF001C */  sw        $ra, 0x1c($sp)
/* 173738 80244E58 AFB00010 */  sw        $s0, 0x10($sp)
/* 17373C 80244E5C 8E430000 */  lw        $v1, ($s2)
/* 173740 80244E60 8E3000D8 */  lw        $s0, 0xd8($s1)
/* 173744 80244E64 10600005 */  beqz      $v1, .L80244E7C
/* 173748 80244E68 24020001 */   addiu    $v0, $zero, 1
/* 17374C 80244E6C 10620012 */  beq       $v1, $v0, .L80244EB8
/* 173750 80244E70 00000000 */   nop      
/* 173754 80244E74 080913B8 */  j         .L80244EE0
/* 173758 80244E78 00000000 */   nop      
.L80244E7C:
/* 17375C 80244E7C 3C048028 */  lui       $a0, 0x8028
/* 173760 80244E80 24844EBC */  addiu     $a0, $a0, 0x4ebc
/* 173764 80244E84 24020006 */  addiu     $v0, $zero, 6
/* 173768 80244E88 2405000A */  addiu     $a1, $zero, 0xa
/* 17376C 80244E8C 0000302D */  daddu     $a2, $zero, $zero
/* 173770 80244E90 A220008C */  sb        $zero, 0x8c($s1)
/* 173774 80244E94 0C0B0CF8 */  jal       start_script
/* 173778 80244E98 A22201A7 */   sb       $v0, 0x1a7($s1)
/* 17377C 80244E9C AE0201D4 */  sw        $v0, 0x1d4($s0)
/* 173780 80244EA0 8C440144 */  lw        $a0, 0x144($v0)
/* 173784 80244EA4 24030001 */  addiu     $v1, $zero, 1
/* 173788 80244EA8 AE430000 */  sw        $v1, ($s2)
/* 17378C 80244EAC AE0401E4 */  sw        $a0, 0x1e4($s0)
/* 173790 80244EB0 080913B8 */  j         .L80244EE0
/* 173794 80244EB4 AC400148 */   sw       $zero, 0x148($v0)
.L80244EB8:
/* 173798 80244EB8 8E0401E4 */  lw        $a0, 0x1e4($s0)
/* 17379C 80244EBC 0C0B1059 */  jal       does_script_exist
/* 1737A0 80244EC0 00000000 */   nop      
/* 1737A4 80244EC4 14400006 */  bnez      $v0, .L80244EE0
/* 1737A8 80244EC8 00000000 */   nop      
/* 1737AC 80244ECC 8222008C */  lb        $v0, 0x8c($s1)
/* 1737B0 80244ED0 14400003 */  bnez      $v0, .L80244EE0
/* 1737B4 80244ED4 00000000 */   nop      
/* 1737B8 80244ED8 0C090464 */  jal       func_80241190
/* 1737BC 80244EDC 24040016 */   addiu    $a0, $zero, 0x16
.L80244EE0:
/* 1737C0 80244EE0 8FBF001C */  lw        $ra, 0x1c($sp)
/* 1737C4 80244EE4 8FB20018 */  lw        $s2, 0x18($sp)
/* 1737C8 80244EE8 8FB10014 */  lw        $s1, 0x14($sp)
/* 1737CC 80244EEC 8FB00010 */  lw        $s0, 0x10($sp)
/* 1737D0 80244EF0 03E00008 */  jr        $ra
/* 1737D4 80244EF4 27BD0020 */   addiu    $sp, $sp, 0x20
