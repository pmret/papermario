.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218850_4EFCF0
/* 4EFCF0 80218850 3C05C305 */  lui       $a1, 0xc305
/* 4EFCF4 80218854 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 4EFCF8 80218858 F7B60028 */  sdc1      $f22, 0x28($sp)
/* 4EFCFC 8021885C 3C014290 */  lui       $at, 0x4290
/* 4EFD00 80218860 4481B000 */  mtc1      $at, $f22
/* 4EFD04 80218864 F7B80030 */  sdc1      $f24, 0x30($sp)
/* 4EFD08 80218868 3C01C30F */  lui       $at, 0xc30f
/* 4EFD0C 8021886C 4481C000 */  mtc1      $at, $f24
/* 4EFD10 80218870 24040001 */  addiu     $a0, $zero, 1
/* 4EFD14 80218874 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 4EFD18 80218878 3C013E99 */  lui       $at, 0x3e99
/* 4EFD1C 8021887C 3421999A */  ori       $at, $at, 0x999a
/* 4EFD20 80218880 4481A000 */  mtc1      $at, $f20
/* 4EFD24 80218884 4406B000 */  mfc1      $a2, $f22
/* 4EFD28 80218888 4407C000 */  mfc1      $a3, $f24
/* 4EFD2C 8021888C 3C028022 */  lui       $v0, %hi(D_80220740)
/* 4EFD30 80218890 24420740 */  addiu     $v0, $v0, %lo(D_80220740)
/* 4EFD34 80218894 AFBF0018 */  sw        $ra, 0x18($sp)
/* 4EFD38 80218898 AFA20014 */  sw        $v0, 0x14($sp)
/* 4EFD3C 8021889C 0C01C124 */  jal       func_80070490
/* 4EFD40 802188A0 E7B40010 */   swc1     $f20, 0x10($sp)
/* 4EFD44 802188A4 24040001 */  addiu     $a0, $zero, 1
/* 4EFD48 802188A8 3C054301 */  lui       $a1, 0x4301
/* 4EFD4C 802188AC 4406B000 */  mfc1      $a2, $f22
/* 4EFD50 802188B0 4407C000 */  mfc1      $a3, $f24
/* 4EFD54 802188B4 3C028022 */  lui       $v0, %hi(D_80220744)
/* 4EFD58 802188B8 24420744 */  addiu     $v0, $v0, %lo(D_80220744)
/* 4EFD5C 802188BC E7B40010 */  swc1      $f20, 0x10($sp)
/* 4EFD60 802188C0 0C01C124 */  jal       func_80070490
/* 4EFD64 802188C4 AFA20014 */   sw       $v0, 0x14($sp)
/* 4EFD68 802188C8 8FBF0018 */  lw        $ra, 0x18($sp)
/* 4EFD6C 802188CC D7B80030 */  ldc1      $f24, 0x30($sp)
/* 4EFD70 802188D0 D7B60028 */  ldc1      $f22, 0x28($sp)
/* 4EFD74 802188D4 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 4EFD78 802188D8 24020002 */  addiu     $v0, $zero, 2
/* 4EFD7C 802188DC 03E00008 */  jr        $ra
/* 4EFD80 802188E0 27BD0038 */   addiu    $sp, $sp, 0x38
