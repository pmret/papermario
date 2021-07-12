.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241D28_A70108
/* A70108 80241D28 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* A7010C 80241D2C AFB3003C */  sw        $s3, 0x3c($sp)
/* A70110 80241D30 0080982D */  daddu     $s3, $a0, $zero
/* A70114 80241D34 AFBF0044 */  sw        $ra, 0x44($sp)
/* A70118 80241D38 AFB40040 */  sw        $s4, 0x40($sp)
/* A7011C 80241D3C AFB20038 */  sw        $s2, 0x38($sp)
/* A70120 80241D40 AFB10034 */  sw        $s1, 0x34($sp)
/* A70124 80241D44 AFB00030 */  sw        $s0, 0x30($sp)
/* A70128 80241D48 8E720148 */  lw        $s2, 0x148($s3)
/* A7012C 80241D4C 00A0882D */  daddu     $s1, $a1, $zero
/* A70130 80241D50 86440008 */  lh        $a0, 8($s2)
/* A70134 80241D54 0C00EABB */  jal       get_npc_unsafe
/* A70138 80241D58 00C0A02D */   daddu    $s4, $a2, $zero
/* A7013C 80241D5C 0040802D */  daddu     $s0, $v0, $zero
/* A70140 80241D60 9602008E */  lhu       $v0, 0x8e($s0)
/* A70144 80241D64 2442FFFF */  addiu     $v0, $v0, -1
/* A70148 80241D68 A602008E */  sh        $v0, 0x8e($s0)
/* A7014C 80241D6C 00021400 */  sll       $v0, $v0, 0x10
/* A70150 80241D70 1C400032 */  bgtz      $v0, .L80241E3C
/* A70154 80241D74 00000000 */   nop
/* A70158 80241D78 0260202D */  daddu     $a0, $s3, $zero
/* A7015C 80241D7C 8E250024 */  lw        $a1, 0x24($s1)
/* A70160 80241D80 8E260028 */  lw        $a2, 0x28($s1)
/* A70164 80241D84 0C0902B9 */  jal       func_80240AE4_A6EEC4
/* A70168 80241D88 0280382D */   daddu    $a3, $s4, $zero
/* A7016C 80241D8C 0040882D */  daddu     $s1, $v0, $zero
/* A70170 80241D90 24020001 */  addiu     $v0, $zero, 1
/* A70174 80241D94 1222001D */  beq       $s1, $v0, .L80241E0C
/* A70178 80241D98 0200282D */   daddu    $a1, $s0, $zero
/* A7017C 80241D9C 24040002 */  addiu     $a0, $zero, 2
/* A70180 80241DA0 0000302D */  daddu     $a2, $zero, $zero
/* A70184 80241DA4 860300A8 */  lh        $v1, 0xa8($s0)
/* A70188 80241DA8 3C013F80 */  lui       $at, 0x3f80
/* A7018C 80241DAC 44810000 */  mtc1      $at, $f0
/* A70190 80241DB0 3C014000 */  lui       $at, 0x4000
/* A70194 80241DB4 44811000 */  mtc1      $at, $f2
/* A70198 80241DB8 3C01C1A0 */  lui       $at, 0xc1a0
/* A7019C 80241DBC 44812000 */  mtc1      $at, $f4
/* A701A0 80241DC0 2402000C */  addiu     $v0, $zero, 0xc
/* A701A4 80241DC4 AFA2001C */  sw        $v0, 0x1c($sp)
/* A701A8 80241DC8 44833000 */  mtc1      $v1, $f6
/* A701AC 80241DCC 00000000 */  nop
/* A701B0 80241DD0 468031A0 */  cvt.s.w   $f6, $f6
/* A701B4 80241DD4 44073000 */  mfc1      $a3, $f6
/* A701B8 80241DD8 27A20028 */  addiu     $v0, $sp, 0x28
/* A701BC 80241DDC AFA20020 */  sw        $v0, 0x20($sp)
/* A701C0 80241DE0 E7A00010 */  swc1      $f0, 0x10($sp)
/* A701C4 80241DE4 E7A20014 */  swc1      $f2, 0x14($sp)
/* A701C8 80241DE8 0C01BFA4 */  jal       fx_emote
/* A701CC 80241DEC E7A40018 */   swc1     $f4, 0x18($sp)
/* A701D0 80241DF0 8E4200CC */  lw        $v0, 0xcc($s2)
/* A701D4 80241DF4 8C430000 */  lw        $v1, ($v0)
/* A701D8 80241DF8 2402000F */  addiu     $v0, $zero, 0xf
/* A701DC 80241DFC A602008E */  sh        $v0, 0x8e($s0)
/* A701E0 80241E00 24020032 */  addiu     $v0, $zero, 0x32
/* A701E4 80241E04 0809078E */  j         .L80241E38
/* A701E8 80241E08 AE030028 */   sw       $v1, 0x28($s0)
.L80241E0C:
/* A701EC 80241E0C 0200202D */  daddu     $a0, $s0, $zero
/* A701F0 80241E10 240520D5 */  addiu     $a1, $zero, 0x20d5
/* A701F4 80241E14 0C012530 */  jal       ai_enemy_play_sound
/* A701F8 80241E18 0000302D */   daddu    $a2, $zero, $zero
/* A701FC 80241E1C 86440008 */  lh        $a0, 8($s2)
/* A70200 80241E20 0C00FB3A */  jal       get_enemy
/* A70204 80241E24 24840001 */   addiu    $a0, $a0, 1
/* A70208 80241E28 AC51006C */  sw        $s1, 0x6c($v0)
/* A7020C 80241E2C 24020014 */  addiu     $v0, $zero, 0x14
/* A70210 80241E30 A602008E */  sh        $v0, 0x8e($s0)
/* A70214 80241E34 24020018 */  addiu     $v0, $zero, 0x18
.L80241E38:
/* A70218 80241E38 AE620070 */  sw        $v0, 0x70($s3)
.L80241E3C:
/* A7021C 80241E3C 8FBF0044 */  lw        $ra, 0x44($sp)
/* A70220 80241E40 8FB40040 */  lw        $s4, 0x40($sp)
/* A70224 80241E44 8FB3003C */  lw        $s3, 0x3c($sp)
/* A70228 80241E48 8FB20038 */  lw        $s2, 0x38($sp)
/* A7022C 80241E4C 8FB10034 */  lw        $s1, 0x34($sp)
/* A70230 80241E50 8FB00030 */  lw        $s0, 0x30($sp)
/* A70234 80241E54 03E00008 */  jr        $ra
/* A70238 80241E58 27BD0048 */   addiu    $sp, $sp, 0x48
