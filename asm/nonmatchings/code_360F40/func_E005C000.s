.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E005C000
/* 360F40 E005C000 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* 360F44 E005C004 F7B40048 */  sdc1      $f20, 0x48($sp)
/* 360F48 E005C008 4485A000 */  mtc1      $a1, $f20
/* 360F4C E005C00C F7B60050 */  sdc1      $f22, 0x50($sp)
/* 360F50 E005C010 4486B000 */  mtc1      $a2, $f22
/* 360F54 E005C014 AFB5003C */  sw        $s5, 0x3c($sp)
/* 360F58 E005C018 0080A82D */  daddu     $s5, $a0, $zero
/* 360F5C E005C01C F7B80058 */  sdc1      $f24, 0x58($sp)
/* 360F60 E005C020 4487C000 */  mtc1      $a3, $f24
/* 360F64 E005C024 27A40010 */  addiu     $a0, $sp, 0x10
/* 360F68 E005C028 AFB40038 */  sw        $s4, 0x38($sp)
/* 360F6C E005C02C 8FB40074 */  lw        $s4, 0x74($sp)
/* 360F70 E005C030 3C02E006 */  lui       $v0, %hi(D_E005C178)
/* 360F74 E005C034 2442C178 */  addiu     $v0, $v0, %lo(D_E005C178)
/* 360F78 E005C038 AFA20018 */  sw        $v0, 0x18($sp)
/* 360F7C E005C03C 3C02E006 */  lui       $v0, %hi(D_E005C180)
/* 360F80 E005C040 2442C180 */  addiu     $v0, $v0, %lo(D_E005C180)
/* 360F84 E005C044 AFA2001C */  sw        $v0, 0x1c($sp)
/* 360F88 E005C048 3C02E006 */  lui       $v0, %hi(D_E005C2B4)
/* 360F8C E005C04C 2442C2B4 */  addiu     $v0, $v0, %lo(D_E005C2B4)
/* 360F90 E005C050 AFA20020 */  sw        $v0, 0x20($sp)
/* 360F94 E005C054 2402002E */  addiu     $v0, $zero, 0x2e
/* 360F98 E005C058 AFBF0040 */  sw        $ra, 0x40($sp)
/* 360F9C E005C05C AFB30034 */  sw        $s3, 0x34($sp)
/* 360FA0 E005C060 AFB20030 */  sw        $s2, 0x30($sp)
/* 360FA4 E005C064 AFB1002C */  sw        $s1, 0x2c($sp)
/* 360FA8 E005C068 AFB00028 */  sw        $s0, 0x28($sp)
/* 360FAC E005C06C AFA00010 */  sw        $zero, 0x10($sp)
/* 360FB0 E005C070 AFA00024 */  sw        $zero, 0x24($sp)
/* 360FB4 E005C074 0C080124 */  jal       func_E0200490
/* 360FB8 E005C078 AFA20014 */   sw       $v0, 0x14($sp)
/* 360FBC E005C07C 24040068 */  addiu     $a0, $zero, 0x68
/* 360FC0 E005C080 24130002 */  addiu     $s3, $zero, 2
/* 360FC4 E005C084 0040802D */  daddu     $s0, $v0, $zero
/* 360FC8 E005C088 0C08012C */  jal       func_E02004B0
/* 360FCC E005C08C AE130008 */   sw       $s3, 8($s0)
/* 360FD0 E005C090 0040882D */  daddu     $s1, $v0, $zero
/* 360FD4 E005C094 16200003 */  bnez      $s1, .LE005C0A4
/* 360FD8 E005C098 AE11000C */   sw       $s1, 0xc($s0)
.LE005C09C:
/* 360FDC E005C09C 08017027 */  j         .LE005C09C
/* 360FE0 E005C0A0 00000000 */   nop      
.LE005C0A4:
/* 360FE4 E005C0A4 0220202D */  daddu     $a0, $s1, $zero
/* 360FE8 E005C0A8 00132840 */  sll       $a1, $s3, 1
/* 360FEC E005C0AC 00B32821 */  addu      $a1, $a1, $s3
/* 360FF0 E005C0B0 00052880 */  sll       $a1, $a1, 2
/* 360FF4 E005C0B4 00B32821 */  addu      $a1, $a1, $s3
/* 360FF8 E005C0B8 0C080130 */  jal       func_E02004C0
/* 360FFC E005C0BC 00052880 */   sll      $a1, $a1, 2
/* 361000 E005C0C0 24120001 */  addiu     $s2, $zero, 1
/* 361004 E005C0C4 3C014120 */  lui       $at, 0x4120
/* 361008 E005C0C8 44810000 */  mtc1      $at, $f0
/* 36100C E005C0CC 3C0141F0 */  lui       $at, 0x41f0
/* 361010 E005C0D0 44811000 */  mtc1      $at, $f2
/* 361014 E005C0D4 0253102A */  slt       $v0, $s2, $s3
/* 361018 E005C0D8 AE340024 */  sw        $s4, 0x24($s1)
/* 36101C E005C0DC AE200028 */  sw        $zero, 0x28($s1)
/* 361020 E005C0E0 AE34002C */  sw        $s4, 0x2c($s1)
/* 361024 E005C0E4 AE200030 */  sw        $zero, 0x30($s1)
/* 361028 E005C0E8 A6350000 */  sh        $s5, ($s1)
/* 36102C E005C0EC E6340004 */  swc1      $f20, 4($s1)
/* 361030 E005C0F0 E6360008 */  swc1      $f22, 8($s1)
/* 361034 E005C0F4 E638000C */  swc1      $f24, 0xc($s1)
/* 361038 E005C0F8 E620001C */  swc1      $f0, 0x1c($s1)
/* 36103C E005C0FC E6220020 */  swc1      $f2, 0x20($s1)
/* 361040 E005C100 10400011 */  beqz      $v0, .LE005C148
/* 361044 E005C104 26310034 */   addiu    $s1, $s1, 0x34
/* 361048 E005C108 4480A000 */  mtc1      $zero, $f20
/* 36104C E005C10C 26300018 */  addiu     $s0, $s1, 0x18
.LE005C110:
/* 361050 E005C110 4600A306 */  mov.s     $f12, $f20
/* 361054 E005C114 E614FFEC */  swc1      $f20, -0x14($s0)
/* 361058 E005C118 E614FFF0 */  swc1      $f20, -0x10($s0)
/* 36105C E005C11C 0C080140 */  jal       func_E0200500
/* 361060 E005C120 E614FFF4 */   swc1     $f20, -0xc($s0)
/* 361064 E005C124 4600A306 */  mov.s     $f12, $f20
/* 361068 E005C128 E600FFF8 */  swc1      $f0, -8($s0)
/* 36106C E005C12C 0C080144 */  jal       func_E0200510
/* 361070 E005C130 E614FFFC */   swc1     $f20, -4($s0)
/* 361074 E005C134 26520001 */  addiu     $s2, $s2, 1
/* 361078 E005C138 E6000000 */  swc1      $f0, ($s0)
/* 36107C E005C13C 0253102A */  slt       $v0, $s2, $s3
/* 361080 E005C140 1440FFF3 */  bnez      $v0, .LE005C110
/* 361084 E005C144 26100034 */   addiu    $s0, $s0, 0x34
.LE005C148:
/* 361088 E005C148 8FBF0040 */  lw        $ra, 0x40($sp)
/* 36108C E005C14C 8FB5003C */  lw        $s5, 0x3c($sp)
/* 361090 E005C150 8FB40038 */  lw        $s4, 0x38($sp)
/* 361094 E005C154 8FB30034 */  lw        $s3, 0x34($sp)
/* 361098 E005C158 8FB20030 */  lw        $s2, 0x30($sp)
/* 36109C E005C15C 8FB1002C */  lw        $s1, 0x2c($sp)
/* 3610A0 E005C160 8FB00028 */  lw        $s0, 0x28($sp)
/* 3610A4 E005C164 D7B80058 */  ldc1      $f24, 0x58($sp)
/* 3610A8 E005C168 D7B60050 */  ldc1      $f22, 0x50($sp)
/* 3610AC E005C16C D7B40048 */  ldc1      $f20, 0x48($sp)
/* 3610B0 E005C170 03E00008 */  jr        $ra
/* 3610B4 E005C174 27BD0060 */   addiu    $sp, $sp, 0x60
