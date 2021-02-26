.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80042D5C
/* 1E15C 80042D5C 3C03800A */  lui       $v1, %hi(D_8009A5B0)
/* 1E160 80042D60 8C63A5B0 */  lw        $v1, %lo(D_8009A5B0)($v1)
/* 1E164 80042D64 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 1E168 80042D68 AFB10014 */  sw        $s1, 0x14($sp)
/* 1E16C 80042D6C 3C11800B */  lui       $s1, %hi(D_800B0EF0)
/* 1E170 80042D70 26310EF0 */  addiu     $s1, $s1, %lo(D_800B0EF0)
/* 1E174 80042D74 AFBF0018 */  sw        $ra, 0x18($sp)
/* 1E178 80042D78 10600006 */  beqz      $v1, .L80042D94
/* 1E17C 80042D7C AFB00010 */   sw       $s0, 0x10($sp)
/* 1E180 80042D80 24020001 */  addiu     $v0, $zero, 1
/* 1E184 80042D84 1062001B */  beq       $v1, $v0, .L80042DF4
/* 1E188 80042D88 00000000 */   nop
/* 1E18C 80042D8C 08010BA0 */  j         .L80042E80
/* 1E190 80042D90 00000000 */   nop
.L80042D94:
/* 1E194 80042D94 8E30008C */  lw        $s0, 0x8c($s1)
/* 1E198 80042D98 8E020038 */  lw        $v0, 0x38($s0)
/* 1E19C 80042D9C 10400007 */  beqz      $v0, .L80042DBC
/* 1E1A0 80042DA0 0000882D */   daddu    $s1, $zero, $zero
/* 1E1A4 80042DA4 8E040050 */  lw        $a0, 0x50($s0)
/* 1E1A8 80042DA8 0C0B1059 */  jal       func_802C4164
/* 1E1AC 80042DAC 00000000 */   nop
/* 1E1B0 80042DB0 50400002 */  beql      $v0, $zero, .L80042DBC
/* 1E1B4 80042DB4 AE000038 */   sw       $zero, 0x38($s0)
/* 1E1B8 80042DB8 24110001 */  addiu     $s1, $zero, 1
.L80042DBC:
/* 1E1BC 80042DBC 8E020040 */  lw        $v0, 0x40($s0)
/* 1E1C0 80042DC0 10400006 */  beqz      $v0, .L80042DDC
/* 1E1C4 80042DC4 00000000 */   nop
/* 1E1C8 80042DC8 0C0B1059 */  jal       func_802C4164
/* 1E1CC 80042DCC 8E040058 */   lw       $a0, 0x58($s0)
/* 1E1D0 80042DD0 50400002 */  beql      $v0, $zero, .L80042DDC
/* 1E1D4 80042DD4 AE000040 */   sw       $zero, 0x40($s0)
/* 1E1D8 80042DD8 24110001 */  addiu     $s1, $zero, 1
.L80042DDC:
/* 1E1DC 80042DDC 16200028 */  bnez      $s1, .L80042E80
/* 1E1E0 80042DE0 24020001 */   addiu    $v0, $zero, 1
/* 1E1E4 80042DE4 3C01800A */  lui       $at, %hi(D_8009A5B0)
/* 1E1E8 80042DE8 AC22A5B0 */  sw        $v0, %lo(D_8009A5B0)($at)
/* 1E1EC 80042DEC 08010BA0 */  j         .L80042E80
/* 1E1F0 80042DF0 00000000 */   nop
.L80042DF4:
/* 1E1F4 80042DF4 0C0B1192 */  jal       func_802C4648
/* 1E1F8 80042DF8 24040001 */   addiu    $a0, $zero, 1
/* 1E1FC 80042DFC 8E30008C */  lw        $s0, 0x8c($s1)
/* 1E200 80042E00 12000006 */  beqz      $s0, .L80042E1C
/* 1E204 80042E04 00000000 */   nop
/* 1E208 80042E08 8E02003C */  lw        $v0, 0x3c($s0)
/* 1E20C 80042E0C 10400003 */  beqz      $v0, .L80042E1C
/* 1E210 80042E10 00000000 */   nop
/* 1E214 80042E14 0C0B1123 */  jal       func_802C448C
/* 1E218 80042E18 8E040054 */   lw       $a0, 0x54($s0)
.L80042E1C:
/* 1E21C 80042E1C 0C038061 */  jal       func_800E0184
/* 1E220 80042E20 00000000 */   nop
/* 1E224 80042E24 0C03BD65 */  jal       func_800EF594
/* 1E228 80042E28 00000000 */   nop
/* 1E22C 80042E2C 3C028011 */  lui       $v0, %hi(D_8010F188)
/* 1E230 80042E30 2442F188 */  addiu     $v0, $v0, %lo(D_8010F188)
/* 1E234 80042E34 804300B4 */  lb        $v1, 0xb4($v0)
/* 1E238 80042E38 2402000C */  addiu     $v0, $zero, 0xc
/* 1E23C 80042E3C 14620003 */  bne       $v1, $v0, .L80042E4C
/* 1E240 80042E40 00000000 */   nop
/* 1E244 80042E44 0C039761 */  jal       func_800E5D84
/* 1E248 80042E48 0000202D */   daddu    $a0, $zero, $zero
.L80042E4C:
/* 1E24C 80042E4C 0C03BCDA */  jal       func_800EF368
/* 1E250 80042E50 0000202D */   daddu    $a0, $zero, $zero
/* 1E254 80042E54 24040010 */  addiu     $a0, $zero, 0x10
/* 1E258 80042E58 0C0B1192 */  jal       func_802C4648
/* 1E25C 80042E5C A2200005 */   sb       $zero, 5($s1)
/* 1E260 80042E60 24020002 */  addiu     $v0, $zero, 2
/* 1E264 80042E64 3C01800A */  lui       $at, %hi(D_8009A5E0)
/* 1E268 80042E68 AC22A5E0 */  sw        $v0, %lo(D_8009A5E0)($at)
/* 1E26C 80042E6C 24020001 */  addiu     $v0, $zero, 1
/* 1E270 80042E70 3C01800A */  lui       $at, %hi(D_8009A658)
/* 1E274 80042E74 AC22A658 */  sw        $v0, %lo(D_8009A658)($at)
/* 1E278 80042E78 3C01800A */  lui       $at, %hi(D_8009A5B0)
/* 1E27C 80042E7C AC20A5B0 */  sw        $zero, %lo(D_8009A5B0)($at)
.L80042E80:
/* 1E280 80042E80 8FBF0018 */  lw        $ra, 0x18($sp)
/* 1E284 80042E84 8FB10014 */  lw        $s1, 0x14($sp)
/* 1E288 80042E88 8FB00010 */  lw        $s0, 0x10($sp)
/* 1E28C 80042E8C 03E00008 */  jr        $ra
/* 1E290 80042E90 27BD0020 */   addiu    $sp, $sp, 0x20
