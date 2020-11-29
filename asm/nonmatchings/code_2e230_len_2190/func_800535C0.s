.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800535C0
/* 2E9C0 800535C0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 2E9C4 800535C4 AFB10014 */  sw        $s1, 0x14($sp)
/* 2E9C8 800535C8 3C11800A */  lui       $s1, %hi(D_8009A5C0)
/* 2E9CC 800535CC 8E31A5C0 */  lw        $s1, %lo(D_8009A5C0)($s1)
/* 2E9D0 800535D0 AFB00010 */  sw        $s0, 0x10($sp)
/* 2E9D4 800535D4 3C10800A */  lui       $s0, %hi(D_8009A664)
/* 2E9D8 800535D8 8E10A664 */  lw        $s0, %lo(D_8009A664)($s0)
/* 2E9DC 800535DC AFBF001C */  sw        $ra, 0x1c($sp)
/* 2E9E0 800535E0 AFB20018 */  sw        $s2, 0x18($sp)
/* 2E9E4 800535E4 8E22009C */  lw        $v0, 0x9c($s1)
/* 2E9E8 800535E8 3C12800A */  lui       $s2, %hi(D_8009A640)
/* 2E9EC 800535EC 8E52A640 */  lw        $s2, %lo(D_8009A640)($s2)
/* 2E9F0 800535F0 10400003 */  beqz      $v0, .L80053600
/* 2E9F4 800535F4 00000000 */   nop      
/* 2E9F8 800535F8 0C015843 */  jal       func_8005610C
/* 2E9FC 800535FC 00000000 */   nop      
.L80053600:
/* 2EA00 80053600 8E2200A4 */  lw        $v0, 0xa4($s1)
/* 2EA04 80053604 3C01800A */  lui       $at, %hi(D_8009A5E8)
/* 2EA08 80053608 AC22A5E8 */  sw        $v0, %lo(D_8009A5E8)($at)
/* 2EA0C 8005360C 10400003 */  beqz      $v0, .L8005361C
/* 2EA10 80053610 00000000 */   nop      
/* 2EA14 80053614 0040F809 */  jalr      $v0
/* 2EA18 80053618 00000000 */   nop      
.L8005361C:
/* 2EA1C 8005361C 0C013544 */  jal       func_8004D510
/* 2EA20 80053620 0200202D */   daddu    $a0, $s0, $zero
/* 2EA24 80053624 3C04800A */  lui       $a0, %hi(D_8009A5FC)
/* 2EA28 80053628 8C84A5FC */  lw        $a0, %lo(D_8009A5FC)($a0)
/* 2EA2C 8005362C 0C013544 */  jal       func_8004D510
/* 2EA30 80053630 00000000 */   nop      
/* 2EA34 80053634 0C012DD2 */  jal       func_8004B748
/* 2EA38 80053638 0240202D */   daddu    $a0, $s2, $zero
/* 2EA3C 8005363C 8FBF001C */  lw        $ra, 0x1c($sp)
/* 2EA40 80053640 8FB20018 */  lw        $s2, 0x18($sp)
/* 2EA44 80053644 8FB10014 */  lw        $s1, 0x14($sp)
/* 2EA48 80053648 8FB00010 */  lw        $s0, 0x10($sp)
/* 2EA4C 8005364C 03E00008 */  jr        $ra
/* 2EA50 80053650 27BD0020 */   addiu    $sp, $sp, 0x20
