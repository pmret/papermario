.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006F73C
/* 4AB3C 8006F73C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 4AB40 8006F740 AFBF0014 */  sw        $ra, 0x14($sp)
/* 4AB44 8006F744 AFA40020 */  sw        $a0, 0x20($sp)
/* 4AB48 8006F748 AFA50024 */  sw        $a1, 0x24($sp)
/* 4AB4C 8006F74C AFA60028 */  sw        $a2, 0x28($sp)
/* 4AB50 8006F750 AFA7002C */  sw        $a3, 0x2c($sp)
/* 4AB54 8006F754 3C04800B */  lui       $a0, %hi(D_800B0C50)
/* 4AB58 8006F758 24840C50 */  addiu     $a0, $a0, %lo(D_800B0C50)
/* 4AB5C 8006F75C 3C05800B */  lui       $a1, %hi(D_800B0C5C)
/* 4AB60 8006F760 8CA50C5C */  lw        $a1, %lo(D_800B0C5C)($a1)
/* 4AB64 8006F764 3C010001 */  lui       $at, 1
/* 4AB68 8006F768 00A17025 */  or        $t6, $a1, $at
/* 4AB6C 8006F76C 01C02825 */  or        $a1, $t6, $zero
/* 4AB70 8006F770 3C06F000 */  lui       $a2, 0xf000
/* 4AB74 8006F774 0C01834C */  jal       osEPiWriteIo
/* 4AB78 8006F778 00000000 */   nop
/* 4AB7C 8006F77C 3C04800B */  lui       $a0, %hi(D_800B0C50)
/* 4AB80 8006F780 24840C50 */  addiu     $a0, $a0, %lo(D_800B0C50)
/* 4AB84 8006F784 3C05800B */  lui       $a1, %hi(D_800B0C5C)
/* 4AB88 8006F788 8CA50C5C */  lw        $a1, %lo(D_800B0C5C)($a1)
/* 4AB8C 8006F78C 27A60018 */  addiu     $a2, $sp, 0x18
/* 4AB90 8006F790 0C018364 */  jal       osEPiReadIo
/* 4AB94 8006F794 00000000 */   nop
/* 4AB98 8006F798 8FAF0024 */  lw        $t7, 0x24($sp)
/* 4AB9C 8006F79C 8FB80020 */  lw        $t8, 0x20($sp)
/* 4ABA0 8006F7A0 00000000 */  nop
/* 4ABA4 8006F7A4 A30F0002 */  sb        $t7, 2($t8)
/* 4ABA8 8006F7A8 8FB90034 */  lw        $t9, 0x34($sp)
/* 4ABAC 8006F7AC 8FA80020 */  lw        $t0, 0x20($sp)
/* 4ABB0 8006F7B0 00000000 */  nop
/* 4ABB4 8006F7B4 AD190004 */  sw        $t9, 4($t0)
/* 4ABB8 8006F7B8 8FA9002C */  lw        $t1, 0x2c($sp)
/* 4ABBC 8006F7BC 8FAA0020 */  lw        $t2, 0x20($sp)
/* 4ABC0 8006F7C0 00000000 */  nop
/* 4ABC4 8006F7C4 AD490008 */  sw        $t1, 8($t2)
/* 4ABC8 8006F7C8 8FAB0030 */  lw        $t3, 0x30($sp)
/* 4ABCC 8006F7CC 00000000 */  nop
/* 4ABD0 8006F7D0 000B61C0 */  sll       $t4, $t3, 7
/* 4ABD4 8006F7D4 8FAD0020 */  lw        $t5, 0x20($sp)
/* 4ABD8 8006F7D8 00000000 */  nop
/* 4ABDC 8006F7DC ADAC0010 */  sw        $t4, 0x10($t5)
/* 4ABE0 8006F7E0 3C0E800B */  lui       $t6, %hi(D_800B0CC8)
/* 4ABE4 8006F7E4 8DCE0CC8 */  lw        $t6, %lo(D_800B0CC8)($t6)
/* 4ABE8 8006F7E8 00000000 */  nop
/* 4ABEC 8006F7EC 15C00009 */  bnez      $t6, .L8006F814
/* 4ABF0 8006F7F0 00000000 */   nop
/* 4ABF4 8006F7F4 8FAF0028 */  lw        $t7, 0x28($sp)
/* 4ABF8 8006F7F8 00000000 */  nop
/* 4ABFC 8006F7FC 000FC180 */  sll       $t8, $t7, 6
/* 4AC00 8006F800 8FB90020 */  lw        $t9, 0x20($sp)
/* 4AC04 8006F804 00000000 */  nop
/* 4AC08 8006F808 AF38000C */  sw        $t8, 0xc($t9)
/* 4AC0C 8006F80C 10000007 */  b         .L8006F82C
/* 4AC10 8006F810 00000000 */   nop
.L8006F814:
/* 4AC14 8006F814 8FA80028 */  lw        $t0, 0x28($sp)
/* 4AC18 8006F818 00000000 */  nop
/* 4AC1C 8006F81C 000849C0 */  sll       $t1, $t0, 7
/* 4AC20 8006F820 8FAA0020 */  lw        $t2, 0x20($sp)
/* 4AC24 8006F824 00000000 */  nop
/* 4AC28 8006F828 AD49000C */  sw        $t1, 0xc($t2)
.L8006F82C:
/* 4AC2C 8006F82C 3C04800B */  lui       $a0, %hi(D_800B0C50)
/* 4AC30 8006F830 24840C50 */  addiu     $a0, $a0, %lo(D_800B0C50)
/* 4AC34 8006F834 8FA50020 */  lw        $a1, 0x20($sp)
/* 4AC38 8006F838 00003025 */  or        $a2, $zero, $zero
/* 4AC3C 8006F83C 0C01837C */  jal       func_80060DF0
/* 4AC40 8006F840 00000000 */   nop
/* 4AC44 8006F844 AFA2001C */  sw        $v0, 0x1c($sp)
/* 4AC48 8006F848 8FA2001C */  lw        $v0, 0x1c($sp)
/* 4AC4C 8006F84C 10000003 */  b         .L8006F85C
/* 4AC50 8006F850 00000000 */   nop
/* 4AC54 8006F854 10000001 */  b         .L8006F85C
/* 4AC58 8006F858 00000000 */   nop
.L8006F85C:
/* 4AC5C 8006F85C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 4AC60 8006F860 27BD0020 */  addiu     $sp, $sp, 0x20
/* 4AC64 8006F864 03E00008 */  jr        $ra
/* 4AC68 8006F868 00000000 */   nop
/* 4AC6C 8006F86C 00000000 */  nop
