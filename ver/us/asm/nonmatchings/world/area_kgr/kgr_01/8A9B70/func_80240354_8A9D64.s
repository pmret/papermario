.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240354_8A9D64
/* 8A9D64 80240354 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 8A9D68 80240358 24040001 */  addiu     $a0, $zero, 1
/* 8A9D6C 8024035C 27A50010 */  addiu     $a1, $sp, 0x10
/* 8A9D70 80240360 27A60014 */  addiu     $a2, $sp, 0x14
/* 8A9D74 80240364 27A70018 */  addiu     $a3, $sp, 0x18
/* 8A9D78 80240368 AFBF0028 */  sw        $ra, 0x28($sp)
/* 8A9D7C 8024036C AFB10024 */  sw        $s1, 0x24($sp)
/* 8A9D80 80240370 0C0470AC */  jal       func_8011C2B0
/* 8A9D84 80240374 AFB00020 */   sw       $s0, 0x20($sp)
/* 8A9D88 80240378 3C108024 */  lui       $s0, %hi(D_802407C0_8AA1D0)
/* 8A9D8C 8024037C 261007C0 */  addiu     $s0, $s0, %lo(D_802407C0_8AA1D0)
/* 8A9D90 80240380 8FA40010 */  lw        $a0, 0x10($sp)
/* 8A9D94 80240384 8FA50014 */  lw        $a1, 0x14($sp)
/* 8A9D98 80240388 8FA60018 */  lw        $a2, 0x18($sp)
/* 8A9D9C 8024038C 0C090058 */  jal       func_80240160_8A9B70
/* 8A9DA0 80240390 96070000 */   lhu      $a3, ($s0)
/* 8A9DA4 80240394 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* 8A9DA8 80240398 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* 8A9DAC 8024039C 8C620000 */  lw        $v0, ($v1)
/* 8A9DB0 802403A0 24040001 */  addiu     $a0, $zero, 1
/* 8A9DB4 802403A4 0040882D */  daddu     $s1, $v0, $zero
/* 8A9DB8 802403A8 24420008 */  addiu     $v0, $v0, 8
/* 8A9DBC 802403AC AC620000 */  sw        $v0, ($v1)
/* 8A9DC0 802403B0 3C02DE00 */  lui       $v0, 0xde00
/* 8A9DC4 802403B4 0C0470BB */  jal       func_8011C2EC
/* 8A9DC8 802403B8 AE220000 */   sw       $v0, ($s1)
/* 8A9DCC 802403BC 96030000 */  lhu       $v1, ($s0)
/* 8A9DD0 802403C0 AE220004 */  sw        $v0, 4($s1)
/* 8A9DD4 802403C4 2463000A */  addiu     $v1, $v1, 0xa
/* 8A9DD8 802403C8 A6030000 */  sh        $v1, ($s0)
/* 8A9DDC 802403CC 8FBF0028 */  lw        $ra, 0x28($sp)
/* 8A9DE0 802403D0 8FB10024 */  lw        $s1, 0x24($sp)
/* 8A9DE4 802403D4 8FB00020 */  lw        $s0, 0x20($sp)
/* 8A9DE8 802403D8 03E00008 */  jr        $ra
/* 8A9DEC 802403DC 27BD0030 */   addiu    $sp, $sp, 0x30
