.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218920_4EFDC0
/* 4EFDC0 80218920 3C05C2B4 */  lui       $a1, 0xc2b4
/* 4EFDC4 80218924 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 4EFDC8 80218928 F7B60028 */  sdc1      $f22, 0x28($sp)
/* 4EFDCC 8021892C 3C014234 */  lui       $at, 0x4234
/* 4EFDD0 80218930 4481B000 */  mtc1      $at, $f22
/* 4EFDD4 80218934 F7B80030 */  sdc1      $f24, 0x30($sp)
/* 4EFDD8 80218938 3C01C312 */  lui       $at, 0xc312
/* 4EFDDC 8021893C 4481C000 */  mtc1      $at, $f24
/* 4EFDE0 80218940 24040001 */  addiu     $a0, $zero, 1
/* 4EFDE4 80218944 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 4EFDE8 80218948 3C013E80 */  lui       $at, 0x3e80
/* 4EFDEC 8021894C 4481A000 */  mtc1      $at, $f20
/* 4EFDF0 80218950 4406B000 */  mfc1      $a2, $f22
/* 4EFDF4 80218954 4407C000 */  mfc1      $a3, $f24
/* 4EFDF8 80218958 3C028022 */  lui       $v0, %hi(D_80220750)
/* 4EFDFC 8021895C 24420750 */  addiu     $v0, $v0, %lo(D_80220750)
/* 4EFE00 80218960 AFBF0018 */  sw        $ra, 0x18($sp)
/* 4EFE04 80218964 AFA20014 */  sw        $v0, 0x14($sp)
/* 4EFE08 80218968 0C01C124 */  jal       func_80070490
/* 4EFE0C 8021896C E7B40010 */   swc1     $f20, 0x10($sp)
/* 4EFE10 80218970 24040001 */  addiu     $a0, $zero, 1
/* 4EFE14 80218974 3C0542A0 */  lui       $a1, 0x42a0
/* 4EFE18 80218978 4406B000 */  mfc1      $a2, $f22
/* 4EFE1C 8021897C 4407C000 */  mfc1      $a3, $f24
/* 4EFE20 80218980 3C028022 */  lui       $v0, %hi(D_80220754)
/* 4EFE24 80218984 24420754 */  addiu     $v0, $v0, %lo(D_80220754)
/* 4EFE28 80218988 E7B40010 */  swc1      $f20, 0x10($sp)
/* 4EFE2C 8021898C 0C01C124 */  jal       func_80070490
/* 4EFE30 80218990 AFA20014 */   sw       $v0, 0x14($sp)
/* 4EFE34 80218994 8FBF0018 */  lw        $ra, 0x18($sp)
/* 4EFE38 80218998 D7B80030 */  ldc1      $f24, 0x30($sp)
/* 4EFE3C 8021899C D7B60028 */  ldc1      $f22, 0x28($sp)
/* 4EFE40 802189A0 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 4EFE44 802189A4 24020002 */  addiu     $v0, $zero, 2
/* 4EFE48 802189A8 03E00008 */  jr        $ra
/* 4EFE4C 802189AC 27BD0038 */   addiu    $sp, $sp, 0x38
