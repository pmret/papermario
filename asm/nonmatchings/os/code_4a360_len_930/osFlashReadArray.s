.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osFlashReadArray
/* 4AB5C 8006F75C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 4AB60 8006F760 AFBF0014 */  sw        $ra, 0x14($sp)
/* 4AB64 8006F764 AFA40020 */  sw        $a0, 0x20($sp)
/* 4AB68 8006F768 AFA50024 */  sw        $a1, 0x24($sp)
/* 4AB6C 8006F76C AFA60028 */  sw        $a2, 0x28($sp)
/* 4AB70 8006F770 AFA7002C */  sw        $a3, 0x2c($sp)
/* 4AB74 8006F774 3C04800B */  lui       $a0, 0x800b
/* 4AB78 8006F778 24840C70 */  addiu     $a0, $a0, 0xc70
/* 4AB7C 8006F77C 3C05800B */  lui       $a1, 0x800b
/* 4AB80 8006F780 8CA50C7C */  lw        $a1, 0xc7c($a1)
/* 4AB84 8006F784 3C010001 */  lui       $at, 1
/* 4AB88 8006F788 00A17025 */  or        $t6, $a1, $at
/* 4AB8C 8006F78C 01C02825 */  or        $a1, $t6, $zero
/* 4AB90 8006F790 3C06F000 */  lui       $a2, 0xf000
/* 4AB94 8006F794 0C018358 */  jal       osEPiWriteIo
/* 4AB98 8006F798 00000000 */   nop      
/* 4AB9C 8006F79C 3C04800B */  lui       $a0, 0x800b
/* 4ABA0 8006F7A0 24840C70 */  addiu     $a0, $a0, 0xc70
/* 4ABA4 8006F7A4 3C05800B */  lui       $a1, 0x800b
/* 4ABA8 8006F7A8 8CA50C7C */  lw        $a1, 0xc7c($a1)
/* 4ABAC 8006F7AC 27A60018 */  addiu     $a2, $sp, 0x18
/* 4ABB0 8006F7B0 0C018370 */  jal       osEPiReadIo
/* 4ABB4 8006F7B4 00000000 */   nop      
/* 4ABB8 8006F7B8 8FAF0024 */  lw        $t7, 0x24($sp)
/* 4ABBC 8006F7BC 8FB80020 */  lw        $t8, 0x20($sp)
/* 4ABC0 8006F7C0 00000000 */  nop       
/* 4ABC4 8006F7C4 A30F0002 */  sb        $t7, 2($t8)
/* 4ABC8 8006F7C8 8FB90034 */  lw        $t9, 0x34($sp)
/* 4ABCC 8006F7CC 8FA80020 */  lw        $t0, 0x20($sp)
/* 4ABD0 8006F7D0 00000000 */  nop       
/* 4ABD4 8006F7D4 AD190004 */  sw        $t9, 4($t0)
/* 4ABD8 8006F7D8 8FA9002C */  lw        $t1, 0x2c($sp)
/* 4ABDC 8006F7DC 8FAA0020 */  lw        $t2, 0x20($sp)
/* 4ABE0 8006F7E0 00000000 */  nop       
/* 4ABE4 8006F7E4 AD490008 */  sw        $t1, 8($t2)
/* 4ABE8 8006F7E8 8FAB0030 */  lw        $t3, 0x30($sp)
/* 4ABEC 8006F7EC 00000000 */  nop       
/* 4ABF0 8006F7F0 000B61C0 */  sll       $t4, $t3, 7
/* 4ABF4 8006F7F4 8FAD0020 */  lw        $t5, 0x20($sp)
/* 4ABF8 8006F7F8 00000000 */  nop       
/* 4ABFC 8006F7FC ADAC0010 */  sw        $t4, 0x10($t5)
/* 4AC00 8006F800 3C0E800B */  lui       $t6, 0x800b
/* 4AC04 8006F804 8DCE0CE8 */  lw        $t6, 0xce8($t6)
/* 4AC08 8006F808 00000000 */  nop       
/* 4AC0C 8006F80C 15C00009 */  bnez      $t6, .L8006F834
/* 4AC10 8006F810 00000000 */   nop      
/* 4AC14 8006F814 8FAF0028 */  lw        $t7, 0x28($sp)
/* 4AC18 8006F818 00000000 */  nop       
/* 4AC1C 8006F81C 000FC180 */  sll       $t8, $t7, 6
/* 4AC20 8006F820 8FB90020 */  lw        $t9, 0x20($sp)
/* 4AC24 8006F824 00000000 */  nop       
/* 4AC28 8006F828 AF38000C */  sw        $t8, 0xc($t9)
/* 4AC2C 8006F82C 10000007 */  b         .L8006F84C
/* 4AC30 8006F830 00000000 */   nop      
.L8006F834:
/* 4AC34 8006F834 8FA80028 */  lw        $t0, 0x28($sp)
/* 4AC38 8006F838 00000000 */  nop       
/* 4AC3C 8006F83C 000849C0 */  sll       $t1, $t0, 7
/* 4AC40 8006F840 8FAA0020 */  lw        $t2, 0x20($sp)
/* 4AC44 8006F844 00000000 */  nop       
/* 4AC48 8006F848 AD49000C */  sw        $t1, 0xc($t2)
.L8006F84C:
/* 4AC4C 8006F84C 3C04800B */  lui       $a0, 0x800b
/* 4AC50 8006F850 24840C70 */  addiu     $a0, $a0, 0xc70
/* 4AC54 8006F854 8FA50020 */  lw        $a1, 0x20($sp)
/* 4AC58 8006F858 00003025 */  or        $a2, $zero, $zero
/* 4AC5C 8006F85C 0C018388 */  jal       osEPiStartDma
/* 4AC60 8006F860 00000000 */   nop      
/* 4AC64 8006F864 AFA2001C */  sw        $v0, 0x1c($sp)
/* 4AC68 8006F868 8FA2001C */  lw        $v0, 0x1c($sp)
/* 4AC6C 8006F86C 10000003 */  b         .L8006F87C
/* 4AC70 8006F870 00000000 */   nop      
/* 4AC74 8006F874 10000001 */  b         .L8006F87C
/* 4AC78 8006F878 00000000 */   nop      
.L8006F87C:
/* 4AC7C 8006F87C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 4AC80 8006F880 27BD0020 */  addiu     $sp, $sp, 0x20
/* 4AC84 8006F884 03E00008 */  jr        $ra
/* 4AC88 8006F888 00000000 */   nop      
/* 4AC8C 8006F88C 00000000 */  nop       
