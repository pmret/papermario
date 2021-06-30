.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218980_4E30C0
/* 4E30C0 80218980 3C05C2B4 */  lui       $a1, 0xc2b4
/* 4E30C4 80218984 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 4E30C8 80218988 F7B60028 */  sdc1      $f22, 0x28($sp)
/* 4E30CC 8021898C 3C014234 */  lui       $at, 0x4234
/* 4E30D0 80218990 4481B000 */  mtc1      $at, $f22
/* 4E30D4 80218994 F7B80030 */  sdc1      $f24, 0x30($sp)
/* 4E30D8 80218998 3C01C312 */  lui       $at, 0xc312
/* 4E30DC 8021899C 4481C000 */  mtc1      $at, $f24
/* 4E30E0 802189A0 24040001 */  addiu     $a0, $zero, 1
/* 4E30E4 802189A4 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 4E30E8 802189A8 3C013E80 */  lui       $at, 0x3e80
/* 4E30EC 802189AC 4481A000 */  mtc1      $at, $f20
/* 4E30F0 802189B0 4406B000 */  mfc1      $a2, $f22
/* 4E30F4 802189B4 4407C000 */  mfc1      $a3, $f24
/* 4E30F8 802189B8 3C028022 */  lui       $v0, %hi(D_80224D70)
/* 4E30FC 802189BC 24424D70 */  addiu     $v0, $v0, %lo(D_80224D70)
/* 4E3100 802189C0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 4E3104 802189C4 AFA20014 */  sw        $v0, 0x14($sp)
/* 4E3108 802189C8 0C01C124 */  jal       playFX_20
/* 4E310C 802189CC E7B40010 */   swc1     $f20, 0x10($sp)
/* 4E3110 802189D0 24040001 */  addiu     $a0, $zero, 1
/* 4E3114 802189D4 3C0542A0 */  lui       $a1, 0x42a0
/* 4E3118 802189D8 4406B000 */  mfc1      $a2, $f22
/* 4E311C 802189DC 4407C000 */  mfc1      $a3, $f24
/* 4E3120 802189E0 3C028022 */  lui       $v0, %hi(D_80224D74)
/* 4E3124 802189E4 24424D74 */  addiu     $v0, $v0, %lo(D_80224D74)
/* 4E3128 802189E8 E7B40010 */  swc1      $f20, 0x10($sp)
/* 4E312C 802189EC 0C01C124 */  jal       playFX_20
/* 4E3130 802189F0 AFA20014 */   sw       $v0, 0x14($sp)
/* 4E3134 802189F4 8FBF0018 */  lw        $ra, 0x18($sp)
/* 4E3138 802189F8 D7B80030 */  ldc1      $f24, 0x30($sp)
/* 4E313C 802189FC D7B60028 */  ldc1      $f22, 0x28($sp)
/* 4E3140 80218A00 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 4E3144 80218A04 24020002 */  addiu     $v0, $zero, 2
/* 4E3148 80218A08 03E00008 */  jr        $ra
/* 4E314C 80218A0C 27BD0038 */   addiu    $sp, $sp, 0x38
