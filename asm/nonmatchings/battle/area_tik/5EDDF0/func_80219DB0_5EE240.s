.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219DB0_5EE240
/* 5EE240 80219DB0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 5EE244 80219DB4 AFB00010 */  sw        $s0, 0x10($sp)
/* 5EE248 80219DB8 0080802D */  daddu     $s0, $a0, $zero
/* 5EE24C 80219DBC AFBF0014 */  sw        $ra, 0x14($sp)
/* 5EE250 80219DC0 8E0300A8 */  lw        $v1, 0xa8($s0)
/* 5EE254 80219DC4 8E020088 */  lw        $v0, 0x88($s0)
/* 5EE258 80219DC8 00621821 */  addu      $v1, $v1, $v0
/* 5EE25C 80219DCC 04610004 */  bgez      $v1, .L80219DE0
/* 5EE260 80219DD0 AE0300A8 */   sw       $v1, 0xa8($s0)
/* 5EE264 80219DD4 3C020002 */  lui       $v0, 2
/* 5EE268 80219DD8 0808677C */  j         .L80219DF0
/* 5EE26C 80219DDC 00621021 */   addu     $v0, $v1, $v0
.L80219DE0:
/* 5EE270 80219DE0 3C040002 */  lui       $a0, 2
/* 5EE274 80219DE4 0083102A */  slt       $v0, $a0, $v1
/* 5EE278 80219DE8 10400002 */  beqz      $v0, .L80219DF4
/* 5EE27C 80219DEC 00641023 */   subu     $v0, $v1, $a0
.L80219DF0:
/* 5EE280 80219DF0 AE0200A8 */  sw        $v0, 0xa8($s0)
.L80219DF4:
/* 5EE284 80219DF4 8E0300AC */  lw        $v1, 0xac($s0)
/* 5EE288 80219DF8 8E02008C */  lw        $v0, 0x8c($s0)
/* 5EE28C 80219DFC 00621821 */  addu      $v1, $v1, $v0
/* 5EE290 80219E00 04610004 */  bgez      $v1, .L80219E14
/* 5EE294 80219E04 AE0300AC */   sw       $v1, 0xac($s0)
/* 5EE298 80219E08 3C020002 */  lui       $v0, 2
/* 5EE29C 80219E0C 08086789 */  j         .L80219E24
/* 5EE2A0 80219E10 00621021 */   addu     $v0, $v1, $v0
.L80219E14:
/* 5EE2A4 80219E14 3C040002 */  lui       $a0, 2
/* 5EE2A8 80219E18 0083102A */  slt       $v0, $a0, $v1
/* 5EE2AC 80219E1C 10400002 */  beqz      $v0, .L80219E28
/* 5EE2B0 80219E20 00641023 */   subu     $v0, $v1, $a0
.L80219E24:
/* 5EE2B4 80219E24 AE0200AC */  sw        $v0, 0xac($s0)
.L80219E28:
/* 5EE2B8 80219E28 8E0300B0 */  lw        $v1, 0xb0($s0)
/* 5EE2BC 80219E2C 8E020090 */  lw        $v0, 0x90($s0)
/* 5EE2C0 80219E30 00621821 */  addu      $v1, $v1, $v0
/* 5EE2C4 80219E34 04610004 */  bgez      $v1, .L80219E48
/* 5EE2C8 80219E38 AE0300B0 */   sw       $v1, 0xb0($s0)
/* 5EE2CC 80219E3C 3C020002 */  lui       $v0, 2
/* 5EE2D0 80219E40 08086796 */  j         .L80219E58
/* 5EE2D4 80219E44 00621021 */   addu     $v0, $v1, $v0
.L80219E48:
/* 5EE2D8 80219E48 3C040002 */  lui       $a0, 2
/* 5EE2DC 80219E4C 0083102A */  slt       $v0, $a0, $v1
/* 5EE2E0 80219E50 10400002 */  beqz      $v0, .L80219E5C
/* 5EE2E4 80219E54 00641023 */   subu     $v0, $v1, $a0
.L80219E58:
/* 5EE2E8 80219E58 AE0200B0 */  sw        $v0, 0xb0($s0)
.L80219E5C:
/* 5EE2EC 80219E5C 8E0300B4 */  lw        $v1, 0xb4($s0)
/* 5EE2F0 80219E60 8E020094 */  lw        $v0, 0x94($s0)
/* 5EE2F4 80219E64 00621821 */  addu      $v1, $v1, $v0
/* 5EE2F8 80219E68 04610004 */  bgez      $v1, .L80219E7C
/* 5EE2FC 80219E6C AE0300B4 */   sw       $v1, 0xb4($s0)
/* 5EE300 80219E70 3C020002 */  lui       $v0, 2
/* 5EE304 80219E74 080867A3 */  j         .L80219E8C
/* 5EE308 80219E78 00621021 */   addu     $v0, $v1, $v0
.L80219E7C:
/* 5EE30C 80219E7C 3C040002 */  lui       $a0, 2
/* 5EE310 80219E80 0083102A */  slt       $v0, $a0, $v1
/* 5EE314 80219E84 10400002 */  beqz      $v0, .L80219E90
/* 5EE318 80219E88 00641023 */   subu     $v0, $v1, $a0
.L80219E8C:
/* 5EE31C 80219E8C AE0200B4 */  sw        $v0, 0xb4($s0)
.L80219E90:
/* 5EE320 80219E90 8E040084 */  lw        $a0, 0x84($s0)
/* 5EE324 80219E94 0C046F07 */  jal       set_main_pan_u
/* 5EE328 80219E98 8E0500A8 */   lw       $a1, 0xa8($s0)
/* 5EE32C 80219E9C 8E040084 */  lw        $a0, 0x84($s0)
/* 5EE330 80219EA0 0C046F0D */  jal       set_main_pan_v
/* 5EE334 80219EA4 8E0500AC */   lw       $a1, 0xac($s0)
/* 5EE338 80219EA8 8E040084 */  lw        $a0, 0x84($s0)
/* 5EE33C 80219EAC 0C046F13 */  jal       set_aux_pan_u
/* 5EE340 80219EB0 8E0500B0 */   lw       $a1, 0xb0($s0)
/* 5EE344 80219EB4 8E040084 */  lw        $a0, 0x84($s0)
/* 5EE348 80219EB8 0C046F19 */  jal       set_aux_pan_v
/* 5EE34C 80219EBC 8E0500B4 */   lw       $a1, 0xb4($s0)
/* 5EE350 80219EC0 8FBF0014 */  lw        $ra, 0x14($sp)
/* 5EE354 80219EC4 8FB00010 */  lw        $s0, 0x10($sp)
/* 5EE358 80219EC8 0000102D */  daddu     $v0, $zero, $zero
/* 5EE35C 80219ECC 03E00008 */  jr        $ra
/* 5EE360 80219ED0 27BD0018 */   addiu    $sp, $sp, 0x18
