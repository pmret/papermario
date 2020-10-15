.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80266DAC
/* 19568C 80266DAC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 195690 80266DB0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 195694 80266DB4 AFB10014 */  sw        $s1, 0x14($sp)
/* 195698 80266DB8 AFB00010 */  sw        $s0, 0x10($sp)
/* 19569C 80266DBC 8C9001F4 */  lw        $s0, 0x1f4($a0)
/* 1956A0 80266DC0 1200000F */  beqz      $s0, .L80266E00
/* 1956A4 80266DC4 00A0882D */   daddu    $s1, $a1, $zero
.L80266DC8:
/* 1956A8 80266DC8 8E030000 */  lw        $v1, ($s0)
/* 1956AC 80266DCC 30620001 */  andi      $v0, $v1, 1
/* 1956B0 80266DD0 14400008 */  bnez      $v0, .L80266DF4
/* 1956B4 80266DD4 00000000 */   nop      
/* 1956B8 80266DD8 8E020094 */  lw        $v0, 0x94($s0)
/* 1956BC 80266DDC 10400005 */  beqz      $v0, .L80266DF4
/* 1956C0 80266DE0 30620002 */   andi     $v0, $v1, 2
/* 1956C4 80266DE4 14400003 */  bnez      $v0, .L80266DF4
/* 1956C8 80266DE8 0200202D */   daddu    $a0, $s0, $zero
/* 1956CC 80266DEC 0C099B5B */  jal       func_80266D6C
/* 1956D0 80266DF0 0220282D */   daddu    $a1, $s1, $zero
.L80266DF4:
/* 1956D4 80266DF4 8E10000C */  lw        $s0, 0xc($s0)
/* 1956D8 80266DF8 1600FFF3 */  bnez      $s0, .L80266DC8
/* 1956DC 80266DFC 00000000 */   nop      
.L80266E00:
/* 1956E0 80266E00 8FBF0018 */  lw        $ra, 0x18($sp)
/* 1956E4 80266E04 8FB10014 */  lw        $s1, 0x14($sp)
/* 1956E8 80266E08 8FB00010 */  lw        $s0, 0x10($sp)
/* 1956EC 80266E0C 03E00008 */  jr        $ra
/* 1956F0 80266E10 27BD0020 */   addiu    $sp, $sp, 0x20
