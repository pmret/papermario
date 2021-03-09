.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel start_rumble_type
/* 1966D4 80267DF4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1966D8 80267DF8 AFB00010 */  sw        $s0, 0x10($sp)
/* 1966DC 80267DFC 0080802D */  daddu     $s0, $a0, $zero
/* 1966E0 80267E00 3C048029 */  lui       $a0, %hi(D_802939C0)
/* 1966E4 80267E04 8C8439C0 */  lw        $a0, %lo(D_802939C0)($a0)
/* 1966E8 80267E08 10800003 */  beqz      $a0, .L80267E18
/* 1966EC 80267E0C AFBF0014 */   sw       $ra, 0x14($sp)
/* 1966F0 80267E10 0C0B102B */  jal       kill_script_by_ID
/* 1966F4 80267E14 00000000 */   nop
.L80267E18:
/* 1966F8 80267E18 2E02000C */  sltiu     $v0, $s0, 0xc
/* 1966FC 80267E1C 10400026 */  beqz      $v0, L80267EB8_196798
/* 196700 80267E20 00101080 */   sll      $v0, $s0, 2
/* 196704 80267E24 3C01802A */  lui       $at, %hi(jtbl_8029D670)
/* 196708 80267E28 00220821 */  addu      $at, $at, $v0
/* 19670C 80267E2C 8C22D670 */  lw        $v0, %lo(jtbl_8029D670)($at)
/* 196710 80267E30 00400008 */  jr        $v0
/* 196714 80267E34 00000000 */   nop
glabel L80267E38_196718
/* 196718 80267E38 3C048029 */  lui       $a0, %hi(D_802939C4)
/* 19671C 80267E3C 248439C4 */  addiu     $a0, $a0, %lo(D_802939C4)
/* 196720 80267E40 08099FA9 */  j         .L80267EA4
/* 196724 80267E44 2405000A */   addiu    $a1, $zero, 0xa
glabel L80267E48_196728
/* 196728 80267E48 3C048029 */  lui       $a0, %hi(D_80293A10)
/* 19672C 80267E4C 24843A10 */  addiu     $a0, $a0, %lo(D_80293A10)
/* 196730 80267E50 08099FA9 */  j         .L80267EA4
/* 196734 80267E54 2405000A */   addiu    $a1, $zero, 0xa
glabel L80267E58_196738
/* 196738 80267E58 3C048029 */  lui       $a0, %hi(D_80293A34)
/* 19673C 80267E5C 24843A34 */  addiu     $a0, $a0, %lo(D_80293A34)
/* 196740 80267E60 08099FA9 */  j         .L80267EA4
/* 196744 80267E64 2405000A */   addiu    $a1, $zero, 0xa
glabel L80267E68_196748
/* 196748 80267E68 3C048029 */  lui       $a0, %hi(D_80293A58)
/* 19674C 80267E6C 24843A58 */  addiu     $a0, $a0, %lo(D_80293A58)
/* 196750 80267E70 08099FA9 */  j         .L80267EA4
/* 196754 80267E74 2405000A */   addiu    $a1, $zero, 0xa
glabel L80267E78_196758
/* 196758 80267E78 3C048029 */  lui       $a0, %hi(D_80293A7C)
/* 19675C 80267E7C 24843A7C */  addiu     $a0, $a0, %lo(D_80293A7C)
/* 196760 80267E80 08099FA9 */  j         .L80267EA4
/* 196764 80267E84 2405000A */   addiu    $a1, $zero, 0xa
glabel L80267E88_196768
/* 196768 80267E88 3C048029 */  lui       $a0, %hi(D_80293AA0)
/* 19676C 80267E8C 24843AA0 */  addiu     $a0, $a0, %lo(D_80293AA0)
/* 196770 80267E90 08099FA9 */  j         .L80267EA4
/* 196774 80267E94 2405000A */   addiu    $a1, $zero, 0xa
glabel L80267E98_196778
/* 196778 80267E98 3C048029 */  lui       $a0, %hi(D_80293AC4)
/* 19677C 80267E9C 24843AC4 */  addiu     $a0, $a0, %lo(D_80293AC4)
/* 196780 80267EA0 2405000A */  addiu     $a1, $zero, 0xa
.L80267EA4:
/* 196784 80267EA4 0C0B0CF8 */  jal       start_script
/* 196788 80267EA8 24060020 */   addiu    $a2, $zero, 0x20
/* 19678C 80267EAC 8C420144 */  lw        $v0, 0x144($v0)
/* 196790 80267EB0 3C018029 */  lui       $at, %hi(D_802939C0)
/* 196794 80267EB4 AC2239C0 */  sw        $v0, %lo(D_802939C0)($at)
glabel L80267EB8_196798
/* 196798 80267EB8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 19679C 80267EBC 8FB00010 */  lw        $s0, 0x10($sp)
/* 1967A0 80267EC0 03E00008 */  jr        $ra
/* 1967A4 80267EC4 27BD0018 */   addiu    $sp, $sp, 0x18
/* 1967A8 80267EC8 00000000 */  nop
/* 1967AC 80267ECC 00000000 */  nop
