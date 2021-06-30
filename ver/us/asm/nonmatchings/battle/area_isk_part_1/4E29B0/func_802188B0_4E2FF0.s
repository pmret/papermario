.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802188B0_4E2FF0
/* 4E2FF0 802188B0 3C05C305 */  lui       $a1, 0xc305
/* 4E2FF4 802188B4 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 4E2FF8 802188B8 F7B60028 */  sdc1      $f22, 0x28($sp)
/* 4E2FFC 802188BC 3C014290 */  lui       $at, 0x4290
/* 4E3000 802188C0 4481B000 */  mtc1      $at, $f22
/* 4E3004 802188C4 F7B80030 */  sdc1      $f24, 0x30($sp)
/* 4E3008 802188C8 3C01C30F */  lui       $at, 0xc30f
/* 4E300C 802188CC 4481C000 */  mtc1      $at, $f24
/* 4E3010 802188D0 24040001 */  addiu     $a0, $zero, 1
/* 4E3014 802188D4 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 4E3018 802188D8 3C013E99 */  lui       $at, 0x3e99
/* 4E301C 802188DC 3421999A */  ori       $at, $at, 0x999a
/* 4E3020 802188E0 4481A000 */  mtc1      $at, $f20
/* 4E3024 802188E4 4406B000 */  mfc1      $a2, $f22
/* 4E3028 802188E8 4407C000 */  mfc1      $a3, $f24
/* 4E302C 802188EC 3C028022 */  lui       $v0, %hi(D_80224D60)
/* 4E3030 802188F0 24424D60 */  addiu     $v0, $v0, %lo(D_80224D60)
/* 4E3034 802188F4 AFBF0018 */  sw        $ra, 0x18($sp)
/* 4E3038 802188F8 AFA20014 */  sw        $v0, 0x14($sp)
/* 4E303C 802188FC 0C01C124 */  jal       playFX_20
/* 4E3040 80218900 E7B40010 */   swc1     $f20, 0x10($sp)
/* 4E3044 80218904 24040001 */  addiu     $a0, $zero, 1
/* 4E3048 80218908 3C054301 */  lui       $a1, 0x4301
/* 4E304C 8021890C 4406B000 */  mfc1      $a2, $f22
/* 4E3050 80218910 4407C000 */  mfc1      $a3, $f24
/* 4E3054 80218914 3C028022 */  lui       $v0, %hi(D_80224D64)
/* 4E3058 80218918 24424D64 */  addiu     $v0, $v0, %lo(D_80224D64)
/* 4E305C 8021891C E7B40010 */  swc1      $f20, 0x10($sp)
/* 4E3060 80218920 0C01C124 */  jal       playFX_20
/* 4E3064 80218924 AFA20014 */   sw       $v0, 0x14($sp)
/* 4E3068 80218928 8FBF0018 */  lw        $ra, 0x18($sp)
/* 4E306C 8021892C D7B80030 */  ldc1      $f24, 0x30($sp)
/* 4E3070 80218930 D7B60028 */  ldc1      $f22, 0x28($sp)
/* 4E3074 80218934 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 4E3078 80218938 24020002 */  addiu     $v0, $zero, 2
/* 4E307C 8021893C 03E00008 */  jr        $ra
/* 4E3080 80218940 27BD0038 */   addiu    $sp, $sp, 0x38
