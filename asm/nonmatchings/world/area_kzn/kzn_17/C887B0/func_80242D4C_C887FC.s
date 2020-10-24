.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242D4C_C887FC
/* C887FC 80242D4C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* C88800 80242D50 AFB00028 */  sw        $s0, 0x28($sp)
/* C88804 80242D54 0080802D */  daddu     $s0, $a0, $zero
/* C88808 80242D58 AFBF002C */  sw        $ra, 0x2c($sp)
/* C8880C 80242D5C C6000084 */  lwc1      $f0, 0x84($s0)
/* C88810 80242D60 46800020 */  cvt.s.w   $f0, $f0
/* C88814 80242D64 E7A00018 */  swc1      $f0, 0x18($sp)
/* C88818 80242D68 C600008C */  lwc1      $f0, 0x8c($s0)
/* C8881C 80242D6C 46800020 */  cvt.s.w   $f0, $f0
/* C88820 80242D70 27A20024 */  addiu     $v0, $sp, 0x24
/* C88824 80242D74 3C040001 */  lui       $a0, 1
/* C88828 80242D78 27A50018 */  addiu     $a1, $sp, 0x18
/* C8882C 80242D7C 27A6001C */  addiu     $a2, $sp, 0x1c
/* C88830 80242D80 3C0144FA */  lui       $at, 0x44fa
/* C88834 80242D84 44811000 */  mtc1      $at, $f2
/* C88838 80242D88 27A70020 */  addiu     $a3, $sp, 0x20
/* C8883C 80242D8C E7A0001C */  swc1      $f0, 0x1c($sp)
/* C88840 80242D90 AFA00020 */  sw        $zero, 0x20($sp)
/* C88844 80242D94 E7A20024 */  swc1      $f2, 0x24($sp)
/* C88848 80242D98 0C0372DF */  jal       func_800DCB7C
/* C8884C 80242D9C AFA20010 */   sw       $v0, 0x10($sp)
/* C88850 80242DA0 1040000B */  beqz      $v0, .L80242DD0
/* C88854 80242DA4 00000000 */   nop      
/* C88858 80242DA8 C7A2001C */  lwc1      $f2, 0x1c($sp)
/* C8885C 80242DAC 3C01425C */  lui       $at, 0x425c
/* C88860 80242DB0 44810000 */  mtc1      $at, $f0
/* C88864 80242DB4 00000000 */  nop       
/* C88868 80242DB8 46001080 */  add.s     $f2, $f2, $f0
/* C8886C 80242DBC C7A00018 */  lwc1      $f0, 0x18($sp)
/* C88870 80242DC0 4600010D */  trunc.w.s $f4, $f0
/* C88874 80242DC4 E6040084 */  swc1      $f4, 0x84($s0)
/* C88878 80242DC8 4600110D */  trunc.w.s $f4, $f2
/* C8887C 80242DCC E604008C */  swc1      $f4, 0x8c($s0)
.L80242DD0:
/* C88880 80242DD0 8FBF002C */  lw        $ra, 0x2c($sp)
/* C88884 80242DD4 8FB00028 */  lw        $s0, 0x28($sp)
/* C88888 80242DD8 24020002 */  addiu     $v0, $zero, 2
/* C8888C 80242DDC 03E00008 */  jr        $ra
/* C88890 80242DE0 27BD0030 */   addiu    $sp, $sp, 0x30
