.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055A18
/* 30E18 80055A18 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 30E1C 80055A1C AFB00030 */  sw        $s0, 0x30($sp)
/* 30E20 80055A20 3C108008 */  lui       $s0, 0x8008
/* 30E24 80055A24 26108DB0 */  addiu     $s0, $s0, -0x7250
/* 30E28 80055A28 8FA30048 */  lw        $v1, 0x48($sp)
/* 30E2C 80055A2C 24020001 */  addiu     $v0, $zero, 1
/* 30E30 80055A30 AFBF0034 */  sw        $ra, 0x34($sp)
/* 30E34 80055A34 AE020000 */  sw        $v0, ($s0)
/* 30E38 80055A38 AFA40010 */  sw        $a0, 0x10($sp)
/* 30E3C 80055A3C 27A40010 */  addiu     $a0, $sp, 0x10
/* 30E40 80055A40 AFA60014 */  sw        $a2, 0x14($sp)
/* 30E44 80055A44 AFA70018 */  sw        $a3, 0x18($sp)
/* 30E48 80055A48 AFA50020 */  sw        $a1, 0x20($sp)
/* 30E4C 80055A4C AFA00024 */  sw        $zero, 0x24($sp)
/* 30E50 80055A50 0C0135F8 */  jal       func_8004D7E0
/* 30E54 80055A54 AFA3001C */   sw       $v1, 0x1c($sp)
/* 30E58 80055A58 AE000000 */  sw        $zero, ($s0)
/* 30E5C 80055A5C 8FBF0034 */  lw        $ra, 0x34($sp)
/* 30E60 80055A60 8FB00030 */  lw        $s0, 0x30($sp)
/* 30E64 80055A64 03E00008 */  jr        $ra
/* 30E68 80055A68 27BD0038 */   addiu    $sp, $sp, 0x38
