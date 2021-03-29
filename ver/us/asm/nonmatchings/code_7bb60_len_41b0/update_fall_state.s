.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_8010BD98
.word L800E2D8C_7C23C, L800E2DFC_7C2AC, L800E2D6C_7C21C, L800E2D7C_7C22C, L800E2E68_7C318, L800E2E68_7C318, L800E2E68_7C318, L800E2E68_7C318, L800E2E68_7C318, L800E2E68_7C318, L800E2E68_7C318, L800E2E68_7C318, L800E2E68_7C318, L800E2E68_7C318, L800E2E68_7C318, L800E2E68_7C318, L800E2E68_7C318, L800E2F4C_7C3FC, L800E2E68_7C318, L800E2F4C_7C3FC

.section .text

glabel update_fall_state
/* 7C1C8 800E2D18 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 7C1CC 800E2D1C AFB00010 */  sw        $s0, 0x10($sp)
/* 7C1D0 800E2D20 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* 7C1D4 800E2D24 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* 7C1D8 800E2D28 AFBF0014 */  sw        $ra, 0x14($sp)
/* 7C1DC 800E2D2C F7B40018 */  sdc1      $f20, 0x18($sp)
/* 7C1E0 800E2D30 860200C0 */  lh        $v0, 0xc0($s0)
/* 7C1E4 800E2D34 1040006A */  beqz      $v0, .L800E2EE0
/* 7C1E8 800E2D38 00000000 */   nop
/* 7C1EC 800E2D3C 920200B4 */  lbu       $v0, 0xb4($s0)
/* 7C1F0 800E2D40 2442FFFC */  addiu     $v0, $v0, -4
/* 7C1F4 800E2D44 00021600 */  sll       $v0, $v0, 0x18
/* 7C1F8 800E2D48 00021E03 */  sra       $v1, $v0, 0x18
/* 7C1FC 800E2D4C 2C620014 */  sltiu     $v0, $v1, 0x14
/* 7C200 800E2D50 10400045 */  beqz      $v0, L800E2E68_7C318
/* 7C204 800E2D54 00031080 */   sll      $v0, $v1, 2
/* 7C208 800E2D58 3C018011 */  lui       $at, %hi(jtbl_8010BD98)
/* 7C20C 800E2D5C 00220821 */  addu      $at, $at, $v0
/* 7C210 800E2D60 8C22BD98 */  lw        $v0, %lo(jtbl_8010BD98)($at)
/* 7C214 800E2D64 00400008 */  jr        $v0
/* 7C218 800E2D68 00000000 */   nop
glabel L800E2D6C_7C21C
/* 7C21C 800E2D6C 0C038AEC */  jal       func_800E2BB0
/* 7C220 800E2D70 00000000 */   nop
/* 7C224 800E2D74 08038BD3 */  j         L800E2F4C_7C3FC
/* 7C228 800E2D78 00000000 */   nop
glabel L800E2D7C_7C22C
/* 7C22C 800E2D7C 0C038A72 */  jal       func_800E29C8
/* 7C230 800E2D80 00000000 */   nop
/* 7C234 800E2D84 08038BD3 */  j         L800E2F4C_7C3FC
/* 7C238 800E2D88 00000000 */   nop
glabel L800E2D8C_7C23C
/* 7C23C 800E2D8C 0C038D12 */  jal       integrate_gravity
/* 7C240 800E2D90 00000000 */   nop
/* 7C244 800E2D94 C600002C */  lwc1      $f0, 0x2c($s0)
/* 7C248 800E2D98 C6020070 */  lwc1      $f2, 0x70($s0)
/* 7C24C 800E2D9C 46020000 */  add.s     $f0, $f0, $f2
/* 7C250 800E2DA0 4480A000 */  mtc1      $zero, $f20
/* 7C254 800E2DA4 00000000 */  nop
/* 7C258 800E2DA8 4614103E */  c.le.s    $f2, $f20
/* 7C25C 800E2DAC 00000000 */  nop
/* 7C260 800E2DB0 45000066 */  bc1f      L800E2F4C_7C3FC
/* 7C264 800E2DB4 E600002C */   swc1     $f0, 0x2c($s0)
/* 7C268 800E2DB8 0C0389AC */  jal       func_800E26B0
/* 7C26C 800E2DBC 00000000 */   nop
/* 7C270 800E2DC0 0C011052 */  jal       is_starting_conversation
/* 7C274 800E2DC4 00000000 */   nop
/* 7C278 800E2DC8 1040001F */  beqz      $v0, .L800E2E48
/* 7C27C 800E2DCC 00000000 */   nop
/* 7C280 800E2DD0 3C013E1E */  lui       $at, 0x3e1e
/* 7C284 800E2DD4 34210C17 */  ori       $at, $at, 0xc17
/* 7C288 800E2DD8 44810000 */  mtc1      $at, $f0
/* 7C28C 800E2DDC 3C01BEB3 */  lui       $at, 0xbeb3
/* 7C290 800E2DE0 34213DB0 */  ori       $at, $at, 0x3db0
/* 7C294 800E2DE4 44811000 */  mtc1      $at, $f2
/* 7C298 800E2DE8 E6140078 */  swc1      $f20, 0x78($s0)
/* 7C29C 800E2DEC E614007C */  swc1      $f20, 0x7c($s0)
/* 7C2A0 800E2DF0 E6000070 */  swc1      $f0, 0x70($s0)
/* 7C2A4 800E2DF4 08038B94 */  j         .L800E2E50
/* 7C2A8 800E2DF8 E6020074 */   swc1     $f2, 0x74($s0)
glabel L800E2DFC_7C2AC
/* 7C2AC 800E2DFC C6000070 */  lwc1      $f0, 0x70($s0)
/* 7C2B0 800E2E00 3C014012 */  lui       $at, 0x4012
/* 7C2B4 800E2E04 44811800 */  mtc1      $at, $f3
/* 7C2B8 800E2E08 44801000 */  mtc1      $zero, $f2
/* 7C2BC 800E2E0C 46000021 */  cvt.d.s   $f0, $f0
/* 7C2C0 800E2E10 46220001 */  sub.d     $f0, $f0, $f2
/* 7C2C4 800E2E14 C602002C */  lwc1      $f2, 0x2c($s0)
/* 7C2C8 800E2E18 46200020 */  cvt.s.d   $f0, $f0
/* 7C2CC 800E2E1C E6000070 */  swc1      $f0, 0x70($s0)
/* 7C2D0 800E2E20 46000106 */  mov.s     $f4, $f0
/* 7C2D4 800E2E24 46001080 */  add.s     $f2, $f2, $f0
/* 7C2D8 800E2E28 44800000 */  mtc1      $zero, $f0
/* 7C2DC 800E2E2C 00000000 */  nop
/* 7C2E0 800E2E30 4600203E */  c.le.s    $f4, $f0
/* 7C2E4 800E2E34 00000000 */  nop
/* 7C2E8 800E2E38 45000044 */  bc1f      L800E2F4C_7C3FC
/* 7C2EC 800E2E3C E602002C */   swc1     $f2, 0x2c($s0)
/* 7C2F0 800E2E40 0C0389AC */  jal       func_800E26B0
/* 7C2F4 800E2E44 00000000 */   nop
.L800E2E48:
/* 7C2F8 800E2E48 0C038C1B */  jal       gravity_use_fall_params
/* 7C2FC 800E2E4C 00000000 */   nop
.L800E2E50:
/* 7C300 800E2E50 0C038D12 */  jal       integrate_gravity
/* 7C304 800E2E54 00000000 */   nop
/* 7C308 800E2E58 0C039769 */  jal       set_action_state
/* 7C30C 800E2E5C 24040008 */   addiu    $a0, $zero, 8
/* 7C310 800E2E60 08038BD3 */  j         L800E2F4C_7C3FC
/* 7C314 800E2E64 00000000 */   nop
glabel L800E2E68_7C318
/* 7C318 800E2E68 8E0200DC */  lw        $v0, 0xdc($s0)
/* 7C31C 800E2E6C 30428000 */  andi      $v0, $v0, 0x8000
/* 7C320 800E2E70 1440001B */  bnez      $v0, .L800E2EE0
/* 7C324 800E2E74 00000000 */   nop
/* 7C328 800E2E78 0C0389AC */  jal       func_800E26B0
/* 7C32C 800E2E7C 00000000 */   nop
/* 7C330 800E2E80 0C039769 */  jal       set_action_state
/* 7C334 800E2E84 24040005 */   addiu    $a0, $zero, 5
/* 7C338 800E2E88 0C038D12 */  jal       integrate_gravity
/* 7C33C 800E2E8C 00000000 */   nop
/* 7C340 800E2E90 8E020000 */  lw        $v0, ($s0)
/* 7C344 800E2E94 3C030004 */  lui       $v1, 4
/* 7C348 800E2E98 00431024 */  and       $v0, $v0, $v1
/* 7C34C 800E2E9C 10400010 */  beqz      $v0, .L800E2EE0
/* 7C350 800E2EA0 00000000 */   nop
/* 7C354 800E2EA4 C6060074 */  lwc1      $f6, 0x74($s0)
/* 7C358 800E2EA8 3C013F00 */  lui       $at, 0x3f00
/* 7C35C 800E2EAC 44811000 */  mtc1      $at, $f2
/* 7C360 800E2EB0 00000000 */  nop
/* 7C364 800E2EB4 46023182 */  mul.s     $f6, $f6, $f2
/* 7C368 800E2EB8 00000000 */  nop
/* 7C36C 800E2EBC C6040078 */  lwc1      $f4, 0x78($s0)
/* 7C370 800E2EC0 46022102 */  mul.s     $f4, $f4, $f2
/* 7C374 800E2EC4 00000000 */  nop
/* 7C378 800E2EC8 C600007C */  lwc1      $f0, 0x7c($s0)
/* 7C37C 800E2ECC 46020002 */  mul.s     $f0, $f0, $f2
/* 7C380 800E2ED0 00000000 */  nop
/* 7C384 800E2ED4 E6060074 */  swc1      $f6, 0x74($s0)
/* 7C388 800E2ED8 E6040078 */  swc1      $f4, 0x78($s0)
/* 7C38C 800E2EDC E600007C */  swc1      $f0, 0x7c($s0)
.L800E2EE0:
/* 7C390 800E2EE0 0C038D12 */  jal       integrate_gravity
/* 7C394 800E2EE4 00000000 */   nop
/* 7C398 800E2EE8 C6020070 */  lwc1      $f2, 0x70($s0)
/* 7C39C 800E2EEC 44800000 */  mtc1      $zero, $f0
/* 7C3A0 800E2EF0 00000000 */  nop
/* 7C3A4 800E2EF4 4600103E */  c.le.s    $f2, $f0
/* 7C3A8 800E2EF8 00000000 */  nop
/* 7C3AC 800E2EFC 45000009 */  bc1f      .L800E2F24
/* 7C3B0 800E2F00 00000000 */   nop
/* 7C3B4 800E2F04 0C0389AC */  jal       func_800E26B0
/* 7C3B8 800E2F08 00000000 */   nop
/* 7C3BC 800E2F0C 0C038C1B */  jal       gravity_use_fall_params
/* 7C3C0 800E2F10 00000000 */   nop
/* 7C3C4 800E2F14 0C038D12 */  jal       integrate_gravity
/* 7C3C8 800E2F18 00000000 */   nop
/* 7C3CC 800E2F1C 0C039769 */  jal       set_action_state
/* 7C3D0 800E2F20 24040008 */   addiu    $a0, $zero, 8
.L800E2F24:
/* 7C3D4 800E2F24 C6000070 */  lwc1      $f0, 0x70($s0)
/* 7C3D8 800E2F28 C602006C */  lwc1      $f2, 0x6c($s0)
/* 7C3DC 800E2F2C 4600103C */  c.lt.s    $f2, $f0
/* 7C3E0 800E2F30 00000000 */  nop
/* 7C3E4 800E2F34 45030001 */  bc1tl     .L800E2F3C
/* 7C3E8 800E2F38 E6020070 */   swc1     $f2, 0x70($s0)
.L800E2F3C:
/* 7C3EC 800E2F3C C600002C */  lwc1      $f0, 0x2c($s0)
/* 7C3F0 800E2F40 C6020070 */  lwc1      $f2, 0x70($s0)
/* 7C3F4 800E2F44 46020000 */  add.s     $f0, $f0, $f2
/* 7C3F8 800E2F48 E600002C */  swc1      $f0, 0x2c($s0)
glabel L800E2F4C_7C3FC
/* 7C3FC 800E2F4C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 7C400 800E2F50 8FB00010 */  lw        $s0, 0x10($sp)
/* 7C404 800E2F54 D7B40018 */  ldc1      $f20, 0x18($sp)
/* 7C408 800E2F58 03E00008 */  jr        $ra
/* 7C40C 800E2F5C 27BD0020 */   addiu    $sp, $sp, 0x20
