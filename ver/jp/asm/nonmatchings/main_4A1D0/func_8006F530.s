.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006F530
/* 4A930 8006F530 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 4A934 8006F534 AFBF0014 */  sw        $ra, 0x14($sp)
/* 4A938 8006F538 AFA40020 */  sw        $a0, 0x20($sp)
/* 4A93C 8006F53C AFA50024 */  sw        $a1, 0x24($sp)
/* 4A940 8006F540 AFA60028 */  sw        $a2, 0x28($sp)
/* 4A944 8006F544 AFA7002C */  sw        $a3, 0x2c($sp)
/* 4A948 8006F548 3C04800B */  lui       $a0, %hi(D_800B0C50)
/* 4A94C 8006F54C 24840C50 */  addiu     $a0, $a0, %lo(D_800B0C50)
/* 4A950 8006F550 3C05800B */  lui       $a1, %hi(D_800B0C5C)
/* 4A954 8006F554 8CA50C5C */  lw        $a1, %lo(D_800B0C5C)($a1)
/* 4A958 8006F558 3C010001 */  lui       $at, 1
/* 4A95C 8006F55C 00A17025 */  or        $t6, $a1, $at
/* 4A960 8006F560 01C02825 */  or        $a1, $t6, $zero
/* 4A964 8006F564 3C06B400 */  lui       $a2, 0xb400
/* 4A968 8006F568 0C01834C */  jal       func_80060D30
/* 4A96C 8006F56C 00000000 */   nop
/* 4A970 8006F570 8FAF0024 */  lw        $t7, 0x24($sp)
/* 4A974 8006F574 8FB80020 */  lw        $t8, 0x20($sp)
/* 4A978 8006F578 00000000 */  nop
/* 4A97C 8006F57C A30F0002 */  sb        $t7, 2($t8)
/* 4A980 8006F580 8FB9002C */  lw        $t9, 0x2c($sp)
/* 4A984 8006F584 8FA80020 */  lw        $t0, 0x20($sp)
/* 4A988 8006F588 00000000 */  nop
/* 4A98C 8006F58C AD190004 */  sw        $t9, 4($t0)
/* 4A990 8006F590 8FA90028 */  lw        $t1, 0x28($sp)
/* 4A994 8006F594 8FAA0020 */  lw        $t2, 0x20($sp)
/* 4A998 8006F598 00000000 */  nop
/* 4A99C 8006F59C AD490008 */  sw        $t1, 8($t2)
/* 4A9A0 8006F5A0 8FAB0020 */  lw        $t3, 0x20($sp)
/* 4A9A4 8006F5A4 00000000 */  nop
/* 4A9A8 8006F5A8 AD60000C */  sw        $zero, 0xc($t3)
/* 4A9AC 8006F5AC 240C0080 */  addiu     $t4, $zero, 0x80
/* 4A9B0 8006F5B0 8FAD0020 */  lw        $t5, 0x20($sp)
/* 4A9B4 8006F5B4 00000000 */  nop
/* 4A9B8 8006F5B8 ADAC0010 */  sw        $t4, 0x10($t5)
/* 4A9BC 8006F5BC 3C04800B */  lui       $a0, %hi(D_800B0C50)
/* 4A9C0 8006F5C0 24840C50 */  addiu     $a0, $a0, %lo(D_800B0C50)
/* 4A9C4 8006F5C4 8FA50020 */  lw        $a1, 0x20($sp)
/* 4A9C8 8006F5C8 24060001 */  addiu     $a2, $zero, 1
/* 4A9CC 8006F5CC 0C01837C */  jal       func_80060DF0
/* 4A9D0 8006F5D0 00000000 */   nop
/* 4A9D4 8006F5D4 AFA2001C */  sw        $v0, 0x1c($sp)
/* 4A9D8 8006F5D8 8FA2001C */  lw        $v0, 0x1c($sp)
/* 4A9DC 8006F5DC 10000003 */  b         .L8006F5EC
/* 4A9E0 8006F5E0 00000000 */   nop
/* 4A9E4 8006F5E4 10000001 */  b         .L8006F5EC
/* 4A9E8 8006F5E8 00000000 */   nop
.L8006F5EC:
/* 4A9EC 8006F5EC 8FBF0014 */  lw        $ra, 0x14($sp)
/* 4A9F0 8006F5F0 27BD0020 */  addiu     $sp, $sp, 0x20
/* 4A9F4 8006F5F4 03E00008 */  jr        $ra
/* 4A9F8 8006F5F8 00000000 */   nop
